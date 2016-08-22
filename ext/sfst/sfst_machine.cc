#include "ruby.h"
#include "compact.h"
#include "fst.h"
#include "interface.h"
#include "make-compact.h"

/*:enddoc:*/

#ifndef RSTRING_PTR /* Ruby 1.8 compatibility */
#define RSTRING_PTR(ptr) RSTRING(ptr)->ptr
#endif

VALUE mSFST = Qnil;
VALUE mCompactTransducer = Qnil;
VALUE mRegularTransducer = Qnil;

static void compact_transducer_free(CompactTransducer *t)
{
  if (t)
    delete t;
}

static void compact_transducer_mark(CompactTransducer *t)
{
}

static VALUE compact_transducer_alloc(VALUE klass)
{
  CompactTransducer *t = NULL;

  return Data_Wrap_Struct(klass, compact_transducer_mark, compact_transducer_free, t);
}

static VALUE compact_transducer_init(VALUE obj, VALUE filename)
{
  FILE *file;
  CompactTransducer *t;

  file = fopen(RSTRING_PTR(filename), "rb");

  if (!file) {
    rb_raise(rb_eRuntimeError, "Unable to open SFST file %s", RSTRING_PTR(filename));
  }

  try {
    t = new CompactTransducer(file);
    fclose(file);
  }
  catch (const char *p) {
    rb_raise(rb_eRuntimeError, "Unable to open SFST file %s: %s", RSTRING_PTR(filename), p);
  }

  DATA_PTR(obj) = t;
  return Qnil;
}

static VALUE compact_transducer_analyze(VALUE self, VALUE string)
{
  VALUE accepted = Qfalse;
  CompactTransducer *t;

  Check_Type(string, T_STRING);

  Data_Get_Struct(self, CompactTransducer, t);

  std::vector<CAnalysis> analyses;
  t->analyze_string(RSTRING_PTR(string), analyses);

  for (size_t k = 0; k < analyses.size(); k++) {
    accepted = Qtrue;

    if (rb_block_given_p()) {
      rb_yield(rb_str_new2(t->print_analysis(analyses[k])));
    } else
      // We might as well return early if there is no block.
      break;
  }

  return accepted;
}

static void regular_transducer_free(Transducer *t)
{
  if (t)
    delete t;
}

static void regular_transducer_mark(Transducer *t)
{
}

static VALUE regular_transducer_alloc(VALUE klass)
{
  Transducer *t = NULL;

  return Data_Wrap_Struct(klass, regular_transducer_mark, regular_transducer_free, t);
}

static VALUE regular_transducer_init(VALUE obj, VALUE filename)
{
  FILE *file;
  Transducer *t;

  file = fopen(RSTRING_PTR(filename), "rb");

  if (!file) {
    rb_raise(rb_eRuntimeError, "Unable to open SFST file %s", RSTRING_PTR(filename));
  }

  try {
    t = new Transducer(file);
    fclose(file);
  }
  catch (const char *p) {
    rb_raise(rb_eRuntimeError, "Unable to open SFST file %s: %s", RSTRING_PTR(filename), p);
  }

  DATA_PTR(obj) = t;
  return Qnil;
}

using std::vector;

enum { BOTH, LOWER, UPPER };

static VALUE _alphabet_to_rb_str(Alphabet *a, Character c)
{
  const char *s = a->code2symbol(c);

  if (s)
    return rb_str_new2(s);

  unsigned int uc = c;
  char buf[32];

  if (uc >= 32 && uc < 256) {
    buf[0] = (char)c;
    buf[1] = '\0';
  } else {
    sprintf(buf, "\\%u", uc);
  }
  return rb_str_new2(buf);
}

static VALUE rb_ary_push_pair(VALUE ary, VALUE a, VALUE b)
{
  VALUE pair = rb_ary_new();
  rb_ary_push(pair, a);
  rb_ary_push(pair, b);
  rb_ary_push(ary, pair);
  return ary;
}

static void _regular_transducer_generate(Transducer *t, Node *node,
    Node2Int &visitations, VALUE a, int mode, bool epsilons)
{
  if (node->is_final())
    rb_yield(a);

  visitations[node]++;

  vector<Arc*> arc;
  for (ArcsIter p(node->arcs()); p; p++) {
    Arc *a = p;
    Node *n = a->target_node();
    size_t i;
    for (i = 0; i < arc.size(); i++)
      if (visitations[n] < visitations[arc[i]->target_node()])
        break;
    arc.push_back(NULL);
    for (size_t k = arc.size() - 1; k > i; k--)
      arc[k] = arc[k - 1];
    arc[i] = a;
  }

  for (size_t i = 0; i < arc.size(); i++) {
    Label l = arc[i]->label();
    VALUE lower, upper;

    Character lc = l.lower_char();
    if ((mode == BOTH || mode == LOWER) && (epsilons || lc != Label::epsilon)) {
      lower = _alphabet_to_rb_str(&(t->alphabet), lc);
    } else
      lower = Qnil;

    Character uc = l.upper_char();
    if ((mode == BOTH || mode == UPPER) && (epsilons || uc != Label::epsilon)) {
      upper = _alphabet_to_rb_str(&(t->alphabet), uc);
    } else
      upper = Qnil;

    switch (mode) {
      case BOTH:
        rb_ary_push_pair(a, lower, upper);
        break;

      case UPPER:
        rb_ary_push(a, upper);
        break;

      case LOWER:
        rb_ary_push(a, lower);
        break;
    }

    _regular_transducer_generate(t, arc[i]->target_node(), visitations, a, mode, epsilons);

    rb_ary_pop(a);
  }
}

static VALUE regular_transducer_generate_language(VALUE self, VALUE levels_arg, VALUE mode_arg)
{
  Transducer *t;
  Data_Get_Struct(self, Transducer, t);

  static ID id_upper = rb_intern("upper");
  static ID id_lower = rb_intern("lower");
  static ID id_both = rb_intern("both");
  static ID id_noepsilons = rb_intern("noepsilons");
  static ID id_all = rb_intern("all");

  int levels;
  bool epsilons;

  Check_Type(levels_arg, T_SYMBOL);

  if (SYM2ID(levels_arg) == id_upper)
    levels = UPPER;
  else if (SYM2ID(levels_arg) == id_lower)
    levels = LOWER;
  else if (SYM2ID(levels_arg) == id_both)
    levels = BOTH;
  else
    rb_raise(rb_eRuntimeError, "invalid levels");

  Check_Type(mode_arg, T_SYMBOL);

  if (SYM2ID(mode_arg) == id_noepsilons)
    epsilons = false;
  else if (SYM2ID(mode_arg) == id_all)
    epsilons = true;
  else
    rb_raise(rb_eRuntimeError, "invalid mode");

  if (!rb_block_given_p())
    rb_raise(rb_eRuntimeError, "block expected");

  Node2Int visitations;
  Transducer *a2;
  switch (levels) {
    case UPPER:
      a2 = &(t->upper_level().minimise());
      break;
    case LOWER:
      a2 = &(t->lower_level().minimise());
      break;
    default:
      a2 = t;
      break;
  }
  _regular_transducer_generate(a2, a2->root_node(), visitations, rb_ary_new(),
      levels, epsilons);

  return Qnil;
}

static bool _regular_transducer_yield(Transducer *t, Node *node, VALUE result_array)
{
  int accepted = 0;

  if (node->was_visited(t->vmark)) {
    if (node->forward() != NULL) { // cycle detected
      // FIXME: How is this best handled?
      //cerr << "Warning: cyclic analyses (cycle aborted)\n";
    }
    node->set_forward(node);  // used like a flag for loop detection
  }

  if (node->is_final()) {
    if (rb_block_given_p())
      rb_yield(result_array);

    accepted = 1;
  }

  for (ArcsIter i(node->arcs()); i; i++) {
    Arc *arc = i;
    Label l = arc->label();

    rb_ary_push(result_array, rb_str_new2(t->alphabet.write_label(l)));

    accepted |= _regular_transducer_yield(t, arc->target_node(), result_array);

    rb_ary_pop(result_array);
  }

  node->set_forward(NULL);

  return accepted == 1 ? true : false;
}

static VALUE _regular_transducer_analyze_or_generate(Transducer *t, VALUE string, bool generate)
{
  Transducer *a2, *a3;
  Transducer a1(RSTRING_PTR(string), &(t->alphabet), false);
  if (generate) {
    a2 = &(a1 || *t);
    a3 = &(a2->upper_level());
  } else {
    a2 = &(*t || a1);
    a3 = &(a2->lower_level());
  }
  delete a2;
  a2 = &a3->minimise();
  delete a3;

  a2->alphabet.copy(t->alphabet);
  bool accepted = _regular_transducer_yield(a2, a2->root_node(), rb_ary_new());
  delete a2;

  return accepted ? Qtrue : Qfalse;
}

static VALUE regular_transducer_generate(VALUE self, VALUE string)
{
  Transducer *t;
  Check_Type(string, T_STRING);
  Data_Get_Struct(self, Transducer, t);
  return _regular_transducer_analyze_or_generate(t, string, true);
}

static VALUE regular_transducer_analyze(VALUE self, VALUE string)
{
  Transducer *t;
  Check_Type(string, T_STRING);
  Data_Get_Struct(self, Transducer, t);
  return _regular_transducer_analyze_or_generate(t, string, false);
}

extern "C"

void Init_sfst(void)
{
  mSFST = rb_define_module("SFST");

  mCompactTransducer = rb_define_class_under(mSFST, "CompactTransducerMachine", rb_cObject);
  rb_define_alloc_func(mCompactTransducer, compact_transducer_alloc);
  rb_define_method(mCompactTransducer, "initialize", (VALUE (*)(...))compact_transducer_init, 1);
  rb_define_method(mCompactTransducer, "_analyze", (VALUE (*)(...))compact_transducer_analyze, 1);

  mRegularTransducer = rb_define_class_under(mSFST, "RegularTransducerMachine", rb_cObject);
  rb_define_alloc_func(mRegularTransducer, regular_transducer_alloc);
  rb_define_method(mRegularTransducer, "initialize", (VALUE (*)(...))regular_transducer_init, 1);
  rb_define_method(mRegularTransducer, "_generate_language", (VALUE (*)(...))regular_transducer_generate_language, 2);
  rb_define_method(mRegularTransducer, "_analyze", (VALUE (*)(...))regular_transducer_analyze, 1);
  rb_define_method(mRegularTransducer, "_generate", (VALUE (*)(...))regular_transducer_generate, 1);
}
