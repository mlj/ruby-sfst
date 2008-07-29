/*******************************************************************/
/*                                                                 */
/*  FILE     interface.h                                           */
/*  MODULE   interface                                             */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*******************************************************************/

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "utf8.h"
#include "fst.h"

typedef enum {twol_left,twol_right,twol_both} Twol_Type;

typedef enum {repl_left,repl_right,repl_up,repl_down} Repl_Type;

typedef struct range_t {
  Character character;
  struct range_t *next;
} Range;

typedef struct ranges_t {
  Range  *range;
  struct ranges_t *next;
} Ranges;


typedef struct contexts_t {
  Transducer *left, *right;
  struct contexts_t *next;
} Contexts;


extern bool Verbose;
extern bool UTF8;
extern char *FileName;
extern Alphabet TheAlphabet;

void error2( char *message, char *input );
Transducer *new_transducer( Range*, Range* );
Transducer *read_words( char *filename );
Transducer *read_transducer( char *filename );
Transducer *var_value( char *name );
Transducer *rvar_value( char *name );
Range *svar_value( char *name );
Range *complement_range( Range* );
Range *rsvar_value( char *name );
Character character_code( unsigned int uc );
Character symbol_code( char *s );

Range *add_value( Character, Range*);
Range *add_var_values( char *name, Range*);
Range *add_values( unsigned int, unsigned int, Range*);
Range *append_values( Range *r2, Range *r );
void add_alphabet( Transducer* );
void store_transducer( Transducer *a, char *filename );

// These functions delete their argument automata

void def_alphabet( Transducer *a );
bool def_var( char *name, Transducer *a );
bool def_rvar( char *name, Transducer *a );
bool def_svar( char *name, Range *r );
Transducer *explode( Transducer *a );
Transducer *catenate( Transducer *a1, Transducer *a2 );
Transducer *disjunction( Transducer *a1, Transducer *a2 );
Transducer *conjunction( Transducer *a1, Transducer *a2 );
Transducer *subtraction( Transducer *a1, Transducer *a2 );
Transducer *composition( Transducer *a1, Transducer *a2 );
Transducer *restriction( Transducer *a, Twol_Type type, Contexts *c, int );
Transducer *replace( Transducer *a, Repl_Type type, bool optional );
Transducer *replace_in_context( Transducer *a, Repl_Type type, Contexts *c, bool optional );
Transducer *negation( Transducer *a );
Transducer *upper_level( Transducer *a );
Transducer *lower_level( Transducer *a );
Transducer *minimise( Transducer *a );
Transducer *switch_levels( Transducer *a );
Transducer *repetition( Transducer *a );
Transducer *repetition2( Transducer *a );
Transducer *optional( Transducer *a );
Transducer *make_rule( Transducer *lc, Range *r1, Twol_Type type,
		      Range *r2, Transducer *rc );
Transducer *freely_insert( Transducer *a, Character c, Character c );
Transducer *make_mapping( Ranges*, Ranges* );
Ranges *add_range( Range*, Ranges* );
Contexts *make_context( Transducer *l, Transducer *r );
Contexts *add_context( Contexts *nc, Contexts *c );
Transducer *result( Transducer*, bool );
void write_to_file( Transducer*, char *filename);

#endif
