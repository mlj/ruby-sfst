
/*******************************************************************/
/*                                                                 */
/*  FILE     operators.C                                           */
/*  MODULE   operators                                             */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*******************************************************************/


#include "fst.h"

using std::pair;
using std::cerr;

static void compose_nodes( Node*, Node*, Node*, Transducer*, PairMapping& );


/*******************************************************************/
/*                                                                 */
/*  check_cyclicity                                                */
/*                                                                 */
/*******************************************************************/

static bool check_cyclicity( Node *node, NodeHashSet &visited, 
			     const Alphabet &alphabet)
{ 
 
  if (!visited.insert(node).second)
    return true; // node was visited before

  for( ArcsIter p(node->arcs()); p; p++ ) {
    Arc *arc=p;
    if (arc->label().upper_is_epsilon())
      if (check_cyclicity(arc->target_node(), visited, alphabet)) {
	cerr << alphabet.write_label(arc->label()) << "\n";
	return true;
      }
  }
  visited.erase(node);
  return false;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::infinitely_ambiguous_node                          */
/*                                                                 */
/*******************************************************************/

bool Transducer::infinitely_ambiguous_node( Node *node )

{
  if (!node->was_visited( vmark )) {
    NodeHashSet visited;
    if (check_cyclicity(node, visited, alphabet))
      return true;

    // iterate over all outgoing arcs
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      if (infinitely_ambiguous_node( arc->target_node() ))
	return true;
    }
  }
  return false;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::is_infinitely_ambiguous                            */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_infinitely_ambiguous()

{
  incr_vmark();
  return infinitely_ambiguous_node(root_node());
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::is_cyclic_node                                     */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_cyclic_node( Node *node, NodeHashSet &previous )

{
  if (!node->was_visited( vmark )) {
    NodeHashSet visited;
    
    NodeHashSet::iterator it=previous.insert(node).first;

    // iterate over all outgoing arcs
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      if (previous.find(arc->target_node()) != previous.end() || 
	  is_cyclic_node( arc->target_node(), previous ))
	return true;
    }

    previous.erase(it);
  }
  return false;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::is_cyclic                                          */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_cyclic()

{
  incr_vmark();
  NodeHashSet previous;
  return is_cyclic_node(root_node(), previous);
}



/*******************************************************************/
/*                                                                 */
/*  Transducer::is_automaton_node                                  */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_automaton_node( Node *node )

{
  if (!node->was_visited( vmark )) {
    // iterate over all outgoing arcs
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      Label l=arc->label();
      if (l.upper_char() != l.lower_char())
	return false;
      if (!is_automaton_node( arc->target_node()))
	return false;
    }
  }
  return true;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::is_automaton                                       */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_automaton()

{
  incr_vmark();
  return is_automaton_node(root_node());
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::is_empty                                           */
/*                                                                 */
/*******************************************************************/

bool Transducer::is_empty()

{
  if (!minimised) {
    Transducer *tmp=&minimise();
    bool result=tmp->is_empty();
    delete tmp;
    return result;
  }
  if (root_node()->is_final())
    return false;
  return root_node()->arcs()->is_empty();
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::generates_empty_string                             */
/*                                                                 */
/*******************************************************************/

bool Transducer::generates_empty_string()

{
  if (!minimised) {
    Transducer *tmp=&minimise();
    bool result=tmp->root_node()->is_final();
    delete tmp;
    return result;
  }
  return root_node()->is_final();
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::reverse_node                                       */
/*                                                                 */
/*******************************************************************/

void Transducer::reverse_node( Node *node, Transducer *na )

{
  if (!node->was_visited( vmark )) {

    // create a new node
    node->set_forward( na->new_node() );

    if (node->is_final())
      // add epsilon transition from new root to this node
      na->root_node()->add_arc( Label(), node->forward(), na );
    
    // iterate over all outgoing arcs
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      
      // reverse the subgraph headed by the target node
      reverse_node( arc->target_node(), na );
      Node *n = arc->target_node()->forward();

      // create the reverse arc
      n->add_arc( arc->label(), node->forward(), na );
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::reverse                                            */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::reverse()

{
  Transducer *na = new Transducer();
  na->alphabet.copy(alphabet);

  incr_vmark();
  reverse_node(root_node(), na);
  root_node()->forward()->set_final(1);
  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::recode_label                                       */
/*                                                                 */
/*******************************************************************/

Label Transducer::recode_label( Label l, bool lswitch, bool recode, 
			       Alphabet &al )
{
  if (lswitch)
    l = Label(l.upper_char(), l.lower_char());

  if (recode) {
    Character lc = al.add_symbol(alphabet.code2symbol(l.lower_char()));
    Character uc = al.add_symbol(alphabet.code2symbol(l.upper_char()));
    l = Label(lc, uc);
    al.insert(l);
  }

  return l;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::copy_nodes                                         */
/*                                                                 */
/*******************************************************************/

Node *Transducer::copy_nodes( Node *node, Transducer *a, 
			     bool lswitch, bool recode )
{
  if (!node->was_visited(vmark)) {

    node->set_forward(a->new_node());

    // define final nodes
    if (node->is_final())
      node->forward()->set_final(1);

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      Node *tn = copy_nodes( arc->target_node(), a, lswitch, recode );

      // Add a link to the new node
      Label l=recode_label(arc->label(), lswitch, recode, a->alphabet);
      node->forward()->add_arc( l, tn, a );
    }
  }

  return node->forward();
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::copy                                               */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::copy( bool lswitch, const Alphabet *al )

{
  bool recode = false;
  Transducer *na = new Transducer();
  if (al == NULL)
    al = &alphabet;
  else
    recode = true;

  na->alphabet.utf8 = al->utf8;
  if (lswitch) {
    na->alphabet.insert_symbols(*al);
    for( Alphabet::iterator it=al->begin(); it!=al->end(); it++ ) {
      Character lc=it->lower_char();
      Character uc=it->upper_char();
      na->alphabet.insert(Label(uc,lc));
    }
  }
  else
    na->alphabet.copy(*al);

  na->deterministic = deterministic;
  na->minimised = minimised;
  na->root_node()->set_final(root_node()->is_final());
  incr_vmark();

  root_node()->set_forward(na->root_node());
  root_node()->was_visited(vmark);

  for( ArcsIter p(root_node()->arcs()); p; p++ ) {
    Arc *arc=p;
    Node *target_node=copy_nodes(arc->target_node(), na, lswitch, recode);
    Label l = recode_label(arc->label(), lswitch, recode, na->alphabet);
    na->root_node()->add_arc( l, target_node, na);
  }

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator |                                         */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator|( Transducer &a )

{
  Transducer *na = new Transducer();
  na->alphabet.copy(alphabet);
  na->alphabet.copy(a.alphabet);

  incr_vmark();
  na->root_node()->add_arc( Label(), copy_nodes(root_node(), na), na);
  a.incr_vmark();
  na->root_node()->add_arc( Label(), a.copy_nodes(a.root_node(), na), na);

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::rec_cat_nodes                                      */
/*                                                                 */
/*******************************************************************/

void Transducer::rec_cat_nodes( Node *node, Node *node2 )

{
  if (!node->was_visited( vmark )) {

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      rec_cat_nodes( arc->target_node(), node2 );
    }
    
    if (node->is_final()) {
      // link this node to node2
      node->set_final(0);
      node->add_arc( Label(), node2, this );
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator+                                          */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator+( Transducer &a )

{
  Transducer *na = new Transducer();
  na->alphabet.copy(alphabet);
  na->alphabet.copy(a.alphabet);

  // copy Transducer1 to the new Transducer
  incr_vmark();
  Node *node=copy_nodes(root_node(), na);
  na->root_node()->add_arc( Label(), node, na);

  // copy Transducer2 to the new Transducer
  a.incr_vmark();
  node=a.copy_nodes(a.root_node(), na);

  // catenate the two automata
  na->incr_vmark();
  na->rec_cat_nodes(na->root_node(), node);

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::kleene_star                                        */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::kleene_star()

{
  Transducer *na = &copy();
  na->alphabet.copy(alphabet);

  // link back to the start node
  na->incr_vmark();
  na->rec_cat_nodes(na->root_node(), na->root_node());
  na->root_node()->set_final(1);

  na->deterministic = na->minimised = false;

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::negate_nodes                                       */
/*                                                                 */
/*******************************************************************/

void Transducer::negate_nodes( Node *node, Node *accept )

{
  if (!node->was_visited(vmark)) {
    node->set_final( !node->is_final() );

    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      negate_nodes( arc->target_node(), accept );
    }

    for( Alphabet::iterator it=alphabet.begin(); it!=alphabet.end(); it++)
      if (!node->target_node(*it))
	node->add_arc( *it, accept, this );
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::productive_node                                    */
/*                                                                 */
/*******************************************************************/

bool Transducer::productive_node( Node *node )

{
  if (node->was_visited(vmark))
    return (node->forward() != NULL);

  bool productive;
  if (node->is_final()) {
    productive = true;
    node->set_forward( node );
  }
  else {
    productive = false;
    node->set_forward( NULL );
  }

  for( ArcsIter p(node->arcs()); p; p++ ) {
    Arc *arc=p;
    if (productive_node( arc->target_node() ))
      productive = true;
  }

  if (productive)
    // use forwardp to indicate whether the node is productive
    node->set_forward(node);
  return productive;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::prune_nodes                                        */
/*                                                                 */
/*******************************************************************/

bool Transducer::prune_nodes( Node *node )

{
  if (!node->was_visited(vmark)) {
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      if (prune_nodes( arc->target_node() ))
	node->arcs()->remove_arc(arc);
    }
    if (!node->arcs()->is_empty())
      node->set_forward(node);
  }
  return (node->forward() == NULL);
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::prune                                              */
/*                                                                 */
/*******************************************************************/

void Transducer::prune()

{
  incr_vmark();
  productive_node( root_node() );
  incr_vmark();
  prune_nodes( root_node() );
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator!                                          */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator!()

{
  Transducer *na;

  if (alphabet.size() == 0)
    throw "Negation of Transducer with undefined alphabet attempted!";

  if (minimised)
    na = &copy();
  else
    na = &minimise();
  na->alphabet.copy(alphabet);

  Node *accept_node=na->new_node();
  accept_node->set_final(1);
  for( Alphabet::iterator it=alphabet.begin(); it!=alphabet.end(); it++)
    accept_node->add_arc( *it, accept_node, na );

  na->incr_vmark();
  na->negate_nodes( na->root_node(), accept_node );
  //na->prune();
  na->minimised = na->deterministic = false;

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  conjoin_nodes                                                  */
/*                                                                 */
/*******************************************************************/

static void conjoin_nodes( Node *n1, Node *n2, Node *node, 
			   Transducer *a, PairMapping &map )
  
{
  // if both input nodes are final, so is the new one
  if (n1->is_final() && n2->is_final())
    node->set_final(1);

  // iterate over all outgoing arcs of the first node
  for( ArcsIter i(n1->arcs()); i; i++ ) {
    Arc *arc=i;
    Label l=arc->label();
    Node *t1 = arc->target_node();
    Node *t2 = n2->target_node(l);

    // Does the second node have an outgoing arc with the same label?
    if (t2) {
      // Check whether this node pair has been encountered before
      PairMapping::iterator it=map.find(t1, t2);
      
      if (it == map.end()) {
	// new node pair
	// create a new node in the conjunction Transducer
	Node *target_node = a->new_node();
	// map the target node pair to the new node
	map[pair<Node*,Node*>(t1,t2)] = target_node;
	// add an arc to the new node
	node->add_arc( l, target_node, a );
	// recursion
	conjoin_nodes( t1, t2, target_node, a, map );
      }
      else {
	// add an arc to the already existing target node 
	node->add_arc( l, it->second, a );
      }
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator &                                         */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator&( Transducer &a )

{
  Transducer *tmp1=NULL;
  Transducer *tmp2=NULL;
  Node *r1, *r2;

  if (deterministic)
    r1 = root_node();
  else {
    tmp1 = &determinise();
    r1 = tmp1->root_node();
  }

  if (a.deterministic)
    r2 = a.root_node();
  else {
    tmp2 = &a.determinise();
    r2 = tmp2->root_node();
  }

  PairMapping map;

  Transducer *na = new Transducer();
  na->alphabet.copy(alphabet);
  na->alphabet.copy(a.alphabet);

  // map the two root nodes to the new root node
  map[pair<Node*,Node*>(r1, r2)] = na->root_node();

  // recursively conjoin the two automata
  conjoin_nodes( r1, r2, na->root_node(), na, map);

  na->deterministic = 1;
  delete tmp1;
  delete tmp2;

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  add_composed_node                                              */
/*                                                                 */
/*******************************************************************/

static void add_composed_node( Label l, Node *n1, Node *n2, Node *node, 
			       Transducer *a, PairMapping &map )
  
{
  // Check whether this node pair has been encountered before
  PairMapping::iterator it=map.find(n1, n2);
  
  if (it != map.end()) {
    // add an arc to the already existing target node 
    node->add_arc( l, it->second, a );
    return;
  }

  // create a new node in the composed Transducer
  Node *target_node = a->new_node();
  
  // map the target node pair to the new node
  map[pair<Node*,Node*>(n1,n2)] = target_node;
  
  // add an arc to the new node
  node->add_arc( l, target_node, a );
  
  // recursion
  compose_nodes( n1, n2, target_node, a, map );
}


/*******************************************************************/
/*                                                                 */
/*  compose_nodes                                                  */
/*                                                                 */
/*******************************************************************/

static void compose_nodes( Node *n1, Node *n2, Node *node, 
			   Transducer *a, PairMapping &map )
{
  // if both input nodes are final, so is the new one
  if (n1->is_final() && n2->is_final())
    node->set_final(1);

  // iterate over all outgoing arcs of the first node
  for( ArcsIter i(n1->arcs()); i; i++ ) {
    Arc *arc1=i;
    Node *t1 = arc1->target_node();
    Label l1=arc1->label();
    Character uc1=l1.upper_char();
    Character lc1=l1.lower_char();

    if (uc1 == Label::epsilon)
      add_composed_node( l1, t1, n2, node, a, map );

    else {
      for( ArcsIter k(n2->arcs()); k; k++ ) {
	Arc *arc2=k;
	Node *t2 = arc2->target_node();
	Label l2=arc2->label();
	Character lc2=l2.lower_char();
	Character uc2=l2.upper_char();
	
	if (uc1 == lc2)
	  add_composed_node( Label(lc1,uc2), t1, t2, node, a, map );
      }
    }
  }

  // epsilon input characters of the second Transducer
  for( ArcsIter i(n2->arcs()); i; i++ ) {
    Arc *arc=i;
    Node *t = arc->target_node();
    Label l=arc->label();
    Character lc=l.lower_char();
	
    if (lc == Label::epsilon)
      add_composed_node( l, n1, t, node, a, map );
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator ||                                        */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator||( Transducer &a )

{
  PairMapping map;

  Transducer *na = new Transducer();
  na->alphabet.compose(alphabet, a.alphabet);

  // map the two root nodes to the new root node
  map[pair<Node*,Node*>(root_node(), a.root_node())] = na->root_node();

  // recursively compose the two automata
  compose_nodes( root_node(), a.root_node(), na->root_node(), na, map );

  return *na;
}



/*******************************************************************/
/*                                                                 */
/*  Transducer::operator /                                         */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::operator/( Transducer &a )

{
  complete_alphabet();
  a.alphabet.copy(alphabet);
  Transducer *a1 = &(!a);
  Transducer *a2 = &(*this & *a1);
  delete a1;
  return *a2;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::compare_nodes                                      */
/*                                                                 */
/*******************************************************************/

bool Transducer::compare_nodes( Node *node, Node *node2, Transducer &a2 )

{
  if (node->was_visited( vmark )) {
    if (node2->was_visited( a2.vmark ))
      return (node->forward() == node2 && node2->forward() == node);
    else
      return false;
  }
  else if (node2->was_visited( a2.vmark ))
    return false;

  node->set_forward( node2 );
  node2->set_forward( node );
    
  if (node->is_final() != node2->is_final())
    return false;

  // iterate over all outgoing arcs
  for( ArcsIter p(node->arcs()); p; p++ ) {
    Arc *arc=p;
    Node *t2=node2->target_node(arc->label());

    if (t2 == NULL)
      return false;
    else if (!compare_nodes(arc->target_node(), t2, a2))
      return false;
  }
  for( ArcsIter p(node2->arcs()); p; p++ ) {
    Arc *arc=p;
    if (node->target_node(arc->label()) == NULL)
      return false;
  }

  return true;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::operator ==                                        */
/*                                                                 */
/*******************************************************************/

bool Transducer::operator==( Transducer &a )

{
  Transducer *p1 = (minimised)? this: &minimise();
  Transducer *p2 = (a.minimised)? &a: &a.minimise();

  p1->incr_vmark();
  p2->incr_vmark();
  bool result = p1->compare_nodes(p1->root_node(), p2->root_node(), *p2 );

  if (p1 != this)  delete p1;
  if (p2 != &a)    delete p2;

  return result;
}



/*******************************************************************/
/*                                                                 */
/*  Transducer::map_nodes                                          */
/*                                                                 */
/*******************************************************************/

void Transducer::map_nodes( Node *node, Node *node2, Transducer *a, Level level)

{
  if (!node->was_visited(vmark)) {

    node->set_forward(node2);

    // define final nodes
    if (node->is_final())
      node2->set_final(1);

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      Label l(arc->label().get_char(level));
      Node *t2=NULL, *t=arc->target_node();

      if (t->check_visited(vmark))
	t2 = t->forward();
      else
	t2 = a->new_node(); // create a new node
      
      node2->add_arc(l, t2, a); // add a link to the node

      map_nodes( t, t2, a, level );
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::level                                              */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::level( Level level )

{
  Transducer *na = new Transducer();

  for( Alphabet::iterator it=alphabet.begin(); it!=alphabet.end(); it++ ) {
    Character c = it->get_char(level);
    if (alphabet.code2symbol(c) != NULL)
      na->alphabet.add_symbol( alphabet.code2symbol(c), c );
    na->alphabet.insert(Label(c));
  }

  incr_vmark();
  map_nodes(root_node(), na->root_node(), na, level );

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::freely_insert_at_node                              */
/*                                                                 */
/*******************************************************************/

void Transducer::freely_insert_at_node( Node *node, Label l )

{
  if (!node->was_visited(vmark)) {
    node->add_arc(l, node, this); // add a recursive link labelled with l

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      freely_insert_at_node(arc->target_node(), l );
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::freely_insert                                      */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::freely_insert( Label l )

{
  Transducer *na = &copy();

  na->incr_vmark();
  na->freely_insert_at_node(na->root_node(), l );

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::splice_arc                                         */
/*                                                                 */
/*******************************************************************/

void Transducer::splice_arc( Node *node, Node *node2, Node *next_node,
			    Transducer *a )
{
  if (node->is_final()) {
    // link final node to the next node
    node2->add_arc( Label(), next_node, a );
    return;
  }

  // iterate over the outgoing arcs
  for( ArcsIter p(node->arcs()); p; p++ ) {
    Arc *arc=p;
    Node *tn=a->new_node();

    node2->add_arc( arc->label(), tn, a );
    splice_arc( arc->target_node(), tn, next_node, a );
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::splice_nodes                                       */
/*                                                                 */
/*******************************************************************/

void Transducer::splice_nodes(Node *node, Node *node2, Label sl, 
			     Transducer *sa, Transducer *a)
{
  if (!node->was_visited(vmark)) {

    node->set_forward(node2);

    // define final nodes
    if (node->is_final())
      node2->set_final(1);

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      Node *t2=NULL, *t=arc->target_node();

      if (t->check_visited(vmark))
	t2 = t->forward();
      else
	t2 = a->new_node(); // create a new node

      if (arc->label() == sl)
	// insert the transducer
	splice_arc(sa->root_node(), node2, t2, a);
      else
	// add a link to the node
	node2->add_arc(arc->label(), t2, a);

      splice_nodes( t, t2, sl, sa, a );
    }
  }
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::splice                                             */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::splice( Label sl, Transducer *sa )

{
  Alphabet::iterator it;

  Transducer *na = new Transducer();

  for( it=alphabet.begin(); it!=alphabet.end(); it++ ) {
    Label l = *it;
    if (l != sl)
      na->alphabet.insert(l);
  }
  for( it=sa->alphabet.begin(); it!=sa->alphabet.end(); it++ )
    na->alphabet.insert(*it);

  incr_vmark();
  splice_nodes(root_node(), na->root_node(), sl, sa, na );

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::replace_char                                       */
/*                                                                 */
/*******************************************************************/

Transducer &Transducer::replace_char( Character c, Character nc )

{
  Alphabet::iterator it;

  Transducer *na = new Transducer();

  for( it=alphabet.begin(); it!=alphabet.end(); it++ ) {
    Label l = *it;
    na->alphabet.insert(l.replace_char(c,nc));
  }

  incr_vmark();
  replace_char2(root_node(), na->root_node(), c, nc, na );

  return *na;
}


/*******************************************************************/
/*                                                                 */
/*  Transducer::replace_char2                                      */
/*                                                                 */
/*******************************************************************/

void Transducer::replace_char2(Node *node, Node *node2, Character c, 
			     Character nc, Transducer *a)
{
  if (!node->was_visited(vmark)) {

    node->set_forward(node2);

    // define final nodes
    if (node->is_final())
      node2->set_final(1);

    // iterate over all outgoing arcs of node
    for( ArcsIter p(node->arcs()); p; p++ ) {
      Arc *arc=p;
      Node *t2=NULL, *t=arc->target_node();

      if (t->check_visited(vmark))
	t2 = t->forward();
      else
	t2 = a->new_node(); // create a new node

      node2->add_arc(arc->label().replace_char(c, nc), t2, a);
      replace_char2( t, t2, c, nc, a );
    }
  }
}
