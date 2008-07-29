/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NEWLINE = 258,
     ALPHA = 259,
     COMPOSE = 260,
     PRINT = 261,
     POS = 262,
     INSERT = 263,
     REV = 264,
     ARROW = 265,
     REPLACE = 266,
     SYMBOL = 267,
     VAR = 268,
     SVAR = 269,
     RVAR = 270,
     RSVAR = 271,
     STRING = 272,
     STRING2 = 273,
     UTF8CHAR = 274,
     CHARACTER = 275,
     SEQ = 276
   };
#endif
/* Tokens.  */
#define NEWLINE 258
#define ALPHA 259
#define COMPOSE 260
#define PRINT 261
#define POS 262
#define INSERT 263
#define REV 264
#define ARROW 265
#define REPLACE 266
#define SYMBOL 267
#define VAR 268
#define SVAR 269
#define RVAR 270
#define RSVAR 271
#define STRING 272
#define STRING2 273
#define UTF8CHAR 274
#define CHARACTER 275
#define SEQ 276




/* Copy the first part of user declarations.  */
#line 1 "fst-compiler.yy"

/*******************************************************************/
/*                                                                 */
/*  FILE     fst-compiler.yy                                       */
/*  MODULE   fst-compiler                                          */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*******************************************************************/

#include <stdio.h>

#include "make-compact.h"
#include "interface.h"

using std::cerr;

extern int  yylineno;
extern char *yytext;

void yyerror(char *text);
void warn(char *text);
void warn2(char *text, char *text2);
int yylex( void );
int yyparse( void );

static int Switch=0;
Transducer *Result;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "fst-compiler.yy"
{
  int        number;
  Twol_Type  type;
  Repl_Type  rtype;
  char       *name;
  char       *value;
  unsigned char uchar;
  unsigned int  longchar;
  Character  character;
  Transducer  *expression;
  Range      *range;
  Ranges     *ranges;
  Contexts   *contexts;
}
/* Line 187 of yacc.c.  */
#line 183 "fst-compiler.C"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 196 "fst-compiler.C"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,     2,    23,     2,
      32,    33,    28,    29,    40,    22,    39,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    26,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,    21,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    14,    18,    22,    26,
      30,    34,    37,    41,    46,    51,    55,    60,    65,    71,
      77,    82,    87,    91,    95,   103,   109,   115,   121,   125,
     129,   131,   133,   135,   138,   141,   144,   147,   150,   153,
     156,   159,   163,   167,   171,   175,   177,   179,   182,   183,
     187,   192,   196,   198,   200,   202,   206,   210,   212,   214,
     218,   222,   225,   228,   231,   233,   237,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    45,    57,    -1,    43,    44,    -1,
      43,     3,    -1,    -1,    13,    30,    45,    -1,    15,    30,
      45,    -1,    14,    30,    52,    -1,    16,    30,    52,    -1,
      45,     6,    17,    -1,     4,    45,    -1,    45,    10,    48,
      -1,    45,    26,    10,    48,    -1,    45,    27,    10,    48,
      -1,    45,    11,    50,    -1,    45,    11,    31,    50,    -1,
      45,    11,    32,    33,    -1,    45,    11,    31,    32,    33,
      -1,    45,    47,    10,    47,    45,    -1,    45,    47,    10,
      47,    -1,    47,    10,    47,    45,    -1,    47,    10,    47,
      -1,    45,     5,    45,    -1,    34,    46,    35,    36,    34,
      46,    35,    -1,    47,    36,    34,    46,    35,    -1,    34,
      46,    35,    36,    47,    -1,    45,     8,    55,    36,    55,
      -1,    45,     8,    55,    -1,    47,    36,    47,    -1,    47,
      -1,    13,    -1,    15,    -1,    45,    28,    -1,    45,    29,
      -1,    45,    31,    -1,    45,    45,    -1,    25,    45,    -1,
       9,    45,    -1,    26,    45,    -1,    27,    45,    -1,    45,
      23,    45,    -1,    45,    22,    45,    -1,    45,    21,    45,
      -1,    32,    45,    33,    -1,    17,    -1,    18,    -1,    47,
      46,    -1,    -1,    37,    52,    38,    -1,    37,    26,    52,
      38,    -1,    37,    16,    38,    -1,    39,    -1,    55,    -1,
      49,    -1,    32,    49,    33,    -1,    51,    40,    49,    -1,
      51,    -1,    51,    -1,    32,    51,    33,    -1,    45,     7,
      45,    -1,     7,    45,    -1,    45,     7,    -1,    53,    52,
      -1,    53,    -1,    54,    22,    54,    -1,    14,    -1,    54,
      -1,    55,    -1,    56,    -1,    20,    -1,    19,    -1,    56,
      -1,    20,    -1,    19,    -1,    12,    -1,    39,    -1,    25,
      -1,    31,    -1,    34,    -1,    35,    -1,    33,    -1,    32,
      -1,    23,    -1,    21,    -1,    28,    -1,    29,    -1,    36,
      -1,    40,    -1,    30,    -1,    27,    -1,    26,    -1,    22,
      -1,     3,    57,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    75,    76,    77,    80,    81,    82,    83,
      84,    85,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   125,   126,   129,
     130,   131,   132,   133,   136,   137,   140,   141,   144,   145,
     148,   149,   150,   153,   154,   157,   158,   159,   160,   161,
     164,   165,   166,   169,   170,   171,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   193,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEWLINE", "ALPHA", "COMPOSE", "PRINT",
  "POS", "INSERT", "REV", "ARROW", "REPLACE", "SYMBOL", "VAR", "SVAR",
  "RVAR", "RSVAR", "STRING", "STRING2", "UTF8CHAR", "CHARACTER", "'|'",
  "'-'", "'&'", "SEQ", "'!'", "'^'", "'_'", "'*'", "'+'", "'='", "'?'",
  "'('", "')'", "'{'", "'}'", "':'", "'['", "']'", "'.'", "','", "$accept",
  "ALL", "ASSIGNMENTS", "ASSIGNMENT", "RE", "RANGES", "RANGE", "CONTEXTS2",
  "CONTEXTS", "CONTEXT2", "CONTEXT", "VALUES", "VALUE", "LCHAR", "CODE",
  "SCHAR", "NEWLINES", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   124,    45,    38,   276,    33,    94,    95,    42,    43,
      61,    63,    40,    41,   123,   125,    58,    91,    93,    46,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    44,    44,    44,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     0,     3,     3,     3,     3,
       3,     2,     3,     4,     4,     3,     4,     4,     5,     5,
       4,     4,     3,     3,     7,     5,     5,     5,     3,     3,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     1,     1,     2,     0,     3,
       4,     3,     1,     1,     1,     3,     3,     1,     1,     3,
       3,     2,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     4,     0,     0,    75,    31,     0,
      32,     0,    45,    46,    74,    73,     0,     0,     0,     0,
      48,     0,    52,     3,    94,    30,    53,    31,    32,    11,
      38,     0,     0,     0,     0,    37,    39,    40,     0,     0,
      48,    66,     0,    71,    70,    84,    92,    83,    77,    91,
      90,    85,    86,    89,    78,    82,    81,    79,    80,    87,
      76,    88,     0,    64,    67,    68,    69,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    30,     2,     0,     0,     6,    91,     8,     7,
       9,    44,     0,    47,    51,     0,    49,    63,     0,    93,
      23,    10,    28,     0,     0,     0,    12,    54,    57,     0,
       0,    15,    58,    43,    42,    41,     0,     0,     0,    22,
      48,    29,     0,    50,    71,    70,    65,    72,     0,    61,
       0,     0,    62,     0,     0,    16,    17,     0,    13,    14,
      20,    21,     0,    48,    26,    27,    55,    60,    56,    18,
      59,    19,    25,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    23,    81,    39,    25,   106,   107,   111,
     108,    62,    63,    64,    26,    66,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int16 yypact[] =
{
    -105,     8,   185,  -105,  -105,   729,   729,  -105,   -20,    -6,
      -5,    15,  -105,  -105,  -105,  -105,   729,   729,   729,   729,
     195,   782,  -105,  -105,   153,    -4,  -105,  -105,  -105,   317,
     317,   729,   811,   729,   811,   758,   758,   758,   251,    -8,
     195,  -105,   -10,  -105,  -105,  -105,  -105,  -105,  -105,   840,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     9,   811,    26,  -105,  -105,    46,   729,    33,
      -1,   464,   377,   729,   729,   729,   669,   700,  -105,  -105,
    -105,   638,    -3,  -105,   195,    43,   317,  -105,  -105,   317,
    -105,  -105,    17,  -105,  -105,    16,  -105,  -105,   862,  -105,
     551,  -105,    20,   729,   493,   284,  -105,  -105,    19,   522,
     406,  -105,  -105,   580,   609,   638,   464,   464,   195,   729,
     195,  -105,    66,  -105,  -105,  -105,  -105,  -105,    -1,   317,
     218,    24,   729,   493,   435,  -105,  -105,    27,  -105,  -105,
     729,   348,    30,   195,  -105,  -105,  -105,   317,  -105,  -105,
    -105,   348,  -105,    32,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,  -105,  -105,    -2,   -39,     6,  -104,   -99,   -48,
     -70,   -11,  -105,   -30,   -12,   -22,    12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      24,    93,   112,    29,    30,   131,    84,   118,     3,    65,
      31,     7,   138,   139,    35,    36,    37,    38,    14,    15,
      65,    88,    65,    90,    32,    33,    40,    92,    94,    86,
      82,    89,    85,    85,   148,    82,    82,    65,    95,   112,
     137,    82,    82,    82,    82,    34,    40,    96,    98,    67,
     101,    65,    97,   122,   123,     7,   128,   146,   102,   133,
     150,   135,    14,    15,   137,   152,   100,   154,   126,   105,
     105,   113,   114,   115,    36,    37,   127,   120,     7,    99,
      21,   142,    22,     0,     0,    14,    15,    82,     0,     0,
     119,   121,    82,     0,     0,    82,     0,     0,     0,     0,
     143,   129,   130,    21,   153,    22,    82,   105,   130,     0,
       0,    82,     0,     0,   105,   105,   145,   141,     0,    82,
      82,    82,     0,     0,   140,     0,    40,     0,   144,     0,
     147,   105,   130,     0,     0,    82,    82,     0,   151,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    40,
       0,     0,     0,    82,     0,     0,    67,    82,    68,    69,
       0,    70,     6,    71,    72,     7,    27,     0,    28,     0,
      12,    13,    14,    15,    73,    74,    75,     0,    16,    76,
      77,    78,    79,     0,    80,    19,     0,    20,     4,     5,
      21,     0,    22,     0,     6,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     7,     0,     0,
      16,    17,    18,     0,    14,    15,     0,    19,     0,    20,
       0,     0,    21,    68,    22,   132,    70,     6,    71,    72,
       7,    27,    21,    28,    22,    12,    13,    14,    15,    73,
      74,    75,     0,    16,    76,    77,    78,    79,     0,    80,
      19,    91,    20,     0,     0,    21,    68,    22,     0,    70,
       6,    71,    72,     7,    27,     0,    28,     0,    12,    13,
      14,    15,    73,    74,    75,     0,    16,    76,    77,    78,
      79,     0,    80,    19,    91,    20,     0,     0,    21,    68,
      22,   132,    70,     6,    71,    72,     7,    27,     0,    28,
       0,    12,    13,    14,    15,    73,    74,    75,     0,    16,
      76,    77,    78,    79,     0,    80,    19,     0,    20,     0,
       0,    21,    68,    22,     0,    70,     6,    71,    72,     7,
      27,     0,    28,     0,    12,    13,    14,    15,    73,    74,
      75,     0,    16,    76,    77,    78,    79,     0,    80,    19,
       0,    20,     0,    68,    21,     0,    22,     6,     0,     0,
       7,    27,     0,    28,     0,    12,    13,    14,    15,    73,
      74,    75,     0,    16,    76,    77,    78,    79,     0,    80,
      19,     0,    20,     0,   103,    21,     6,    22,     0,     7,
      27,     0,    28,     0,    12,    13,    14,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,   109,   110,
       0,    20,     0,   103,    21,     6,    22,     0,     7,    27,
       0,    28,     0,    12,    13,    14,    15,     0,     0,     0,
       0,    16,    17,    18,     0,     0,     0,     0,    19,   136,
      20,     0,   103,    21,     6,    22,     0,     7,    27,     0,
      28,     0,    12,    13,    14,    15,     0,     0,     0,     0,
      16,    17,    18,     0,     0,     0,     0,    19,   149,    20,
       0,   103,    21,     6,    22,     0,     7,    27,     0,    28,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
      17,    18,     0,     0,     0,     0,   104,     0,    20,     0,
     103,    21,     6,    22,     0,     7,    27,     0,    28,     0,
      12,    13,    14,    15,     0,     0,     0,     0,    16,    17,
      18,     0,     0,     0,     0,    19,     0,    20,     0,   103,
      21,     6,    22,     0,     7,    27,     0,    28,     0,    12,
      13,    14,    15,     0,     0,     0,     0,    16,    17,    18,
       0,     0,     0,     0,   134,     0,    20,     0,     0,    21,
       6,    22,     0,     7,    27,     0,    28,     0,    12,    13,
      14,    15,    73,    74,    75,     0,    16,    76,    77,    78,
      79,     0,    80,    19,     0,    20,     0,     0,    21,     6,
      22,     0,     7,    27,     0,    28,     0,    12,    13,    14,
      15,     0,    74,    75,     0,    16,    76,    77,    78,    79,
       0,    80,    19,     0,    20,     0,     0,    21,     6,    22,
       0,     7,    27,     0,    28,     0,    12,    13,    14,    15,
       0,     0,    75,     0,    16,    76,    77,    78,    79,     0,
      80,    19,     0,    20,     0,     0,    21,     6,    22,     0,
       7,    27,     0,    28,     0,    12,    13,    14,    15,     0,
       0,     0,     0,    16,    76,    77,    78,    79,     0,    80,
      19,     0,    20,     0,     0,    21,     0,    22,     6,   116,
       0,     7,    27,     0,    28,     0,    12,    13,    14,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,    19,     0,    20,     0,     0,    21,     0,    22,     6,
     117,     0,     7,    27,     0,    28,     0,    12,    13,    14,
      15,     0,     0,     0,     0,    16,    17,    18,     0,     0,
       0,     0,    19,     0,    20,     0,     0,    21,     6,    22,
       0,     7,    27,     0,    28,     0,    12,    13,    14,    15,
       0,     0,     0,     0,    16,    17,    18,     0,     0,     0,
       0,    19,     0,    20,     0,     0,    21,     6,    22,     0,
       7,    27,     0,    28,     0,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,    78,    79,     0,    80,
      19,     0,    20,     0,     7,    21,    41,    22,    42,     0,
       0,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,     7,     0,    41,     0,     0,     0,     0,
      43,    44,    45,    46,    47,     0,    48,    87,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     7,     0,    41,     0,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,   124,   125,    45,    46,    47,     0,    48,    87,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61
};

static const yytype_int16 yycheck[] =
{
       2,    40,    72,     5,     6,   104,    10,    10,     0,    21,
      30,    12,   116,   117,    16,    17,    18,    19,    19,    20,
      32,    32,    34,    34,    30,    30,    20,    35,    38,    31,
      24,    33,    36,    36,   133,    29,    30,    49,    49,   109,
     110,    35,    36,    37,    38,    30,    40,    38,    22,     3,
      17,    63,    63,    36,    38,    12,    36,    33,    70,    40,
      33,   109,    19,    20,   134,    35,    68,    35,    98,    71,
      72,    73,    74,    75,    76,    77,    98,    34,    12,    67,
      37,   120,    39,    -1,    -1,    19,    20,    81,    -1,    -1,
      84,    85,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      34,   103,   104,    37,   143,    39,   100,   109,   110,    -1,
      -1,   105,    -1,    -1,   116,   117,   128,   119,    -1,   113,
     114,   115,    -1,    -1,   118,    -1,   120,    -1,   122,    -1,
     132,   133,   134,    -1,    -1,   129,   130,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,   143,
      -1,    -1,    -1,   147,    -1,    -1,     3,   151,     5,     6,
      -1,     8,     9,    10,    11,    12,    13,    -1,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    -1,    31,    32,    -1,    34,     3,     4,
      37,    -1,    39,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    12,    -1,    -1,
      25,    26,    27,    -1,    19,    20,    -1,    32,    -1,    34,
      -1,    -1,    37,     5,    39,     7,     8,     9,    10,    11,
      12,    13,    37,    15,    39,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    -1,    -1,    37,     5,    39,    -1,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    -1,    -1,    37,     5,
      39,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    -1,
      -1,    37,     5,    39,    -1,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,     5,    37,    -1,    39,     9,    -1,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    -1,     7,    37,     9,    39,    -1,    12,
      13,    -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    -1,     7,    37,     9,    39,    -1,    12,    13,
      -1,    15,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    -1,     7,    37,     9,    39,    -1,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,     7,    37,     9,    39,    -1,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
       7,    37,     9,    39,    -1,    12,    13,    -1,    15,    -1,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,     7,
      37,     9,    39,    -1,    12,    13,    -1,    15,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    37,
       9,    39,    -1,    12,    13,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    -1,    31,    32,    -1,    34,    -1,    -1,    37,     9,
      39,    -1,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,    -1,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    32,    -1,    34,    -1,    -1,    37,     9,    39,
      -1,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    37,     9,    39,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    -1,    -1,    37,    -1,    39,     9,    10,
      -1,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    -1,    37,    -1,    39,     9,
      10,    -1,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    37,     9,    39,
      -1,    12,    13,    -1,    15,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    -1,    37,     9,    39,    -1,
      12,    13,    -1,    15,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      32,    -1,    34,    -1,    12,    37,    14,    39,    16,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    12,    -1,    14,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    12,    -1,    14,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     3,     4,     9,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    25,    26,    27,    32,
      34,    37,    39,    44,    45,    47,    55,    13,    15,    45,
      45,    30,    30,    30,    30,    45,    45,    45,    45,    46,
      47,    14,    16,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      39,    40,    52,    53,    54,    55,    56,     3,     5,     6,
       8,    10,    11,    21,    22,    23,    26,    27,    28,    29,
      31,    45,    47,    57,    10,    36,    45,    26,    52,    45,
      52,    33,    35,    46,    38,    52,    38,    52,    22,    57,
      45,    17,    55,     7,    32,    45,    48,    49,    51,    31,
      32,    50,    51,    45,    45,    45,    10,    10,    10,    47,
      34,    47,    36,    38,    19,    20,    54,    56,    36,    45,
      45,    49,     7,    40,    32,    50,    33,    51,    48,    48,
      47,    45,    46,    34,    47,    55,    33,    45,    49,    33,
      33,    45,    35,    46,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "fst-compiler.yy"
    { Result=result((yyvsp[(2) - (3)].expression), Switch); ;}
    break;

  case 3:
#line 75 "fst-compiler.yy"
    {;}
    break;

  case 4:
#line 76 "fst-compiler.yy"
    {;}
    break;

  case 5:
#line 77 "fst-compiler.yy"
    {;}
    break;

  case 6:
#line 80 "fst-compiler.yy"
    { if (def_var((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].expression))) warn2("assignment of empty transducer to",(yyvsp[(1) - (3)].name)); ;}
    break;

  case 7:
#line 81 "fst-compiler.yy"
    { if (def_rvar((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].expression))) warn2("assignment of empty transducer to",(yyvsp[(1) - (3)].name)); ;}
    break;

  case 8:
#line 82 "fst-compiler.yy"
    { if (def_svar((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].range))) warn2("assignment of empty symbol range to",(yyvsp[(1) - (3)].name)); ;}
    break;

  case 9:
#line 83 "fst-compiler.yy"
    { if (def_svar((yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].range))) warn2("assignment of empty symbol range to",(yyvsp[(1) - (3)].name)); ;}
    break;

  case 10:
#line 84 "fst-compiler.yy"
    { write_to_file((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].value)); ;}
    break;

  case 11:
#line 85 "fst-compiler.yy"
    { def_alphabet((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 12:
#line 88 "fst-compiler.yy"
    { (yyval.expression) = restriction((yyvsp[(1) - (3)].expression),(yyvsp[(2) - (3)].type),(yyvsp[(3) - (3)].contexts),0); ;}
    break;

  case 13:
#line 89 "fst-compiler.yy"
    { (yyval.expression) = restriction((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].type),(yyvsp[(4) - (4)].contexts),1); ;}
    break;

  case 14:
#line 90 "fst-compiler.yy"
    { (yyval.expression) = restriction((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].type),(yyvsp[(4) - (4)].contexts),-1); ;}
    break;

  case 15:
#line 91 "fst-compiler.yy"
    { (yyval.expression) = replace_in_context(minimise(explode((yyvsp[(1) - (3)].expression))),(yyvsp[(2) - (3)].rtype),(yyvsp[(3) - (3)].contexts),false); ;}
    break;

  case 16:
#line 92 "fst-compiler.yy"
    { (yyval.expression) = replace_in_context(minimise(explode((yyvsp[(1) - (4)].expression))),(yyvsp[(2) - (4)].rtype),(yyvsp[(4) - (4)].contexts),true);;}
    break;

  case 17:
#line 93 "fst-compiler.yy"
    { (yyval.expression) = replace(minimise(explode((yyvsp[(1) - (4)].expression))), (yyvsp[(2) - (4)].rtype), false); ;}
    break;

  case 18:
#line 94 "fst-compiler.yy"
    { (yyval.expression) = replace(minimise(explode((yyvsp[(1) - (5)].expression))), (yyvsp[(2) - (5)].rtype), true); ;}
    break;

  case 19:
#line 95 "fst-compiler.yy"
    { (yyval.expression) = make_rule((yyvsp[(1) - (5)].expression),(yyvsp[(2) - (5)].range),(yyvsp[(3) - (5)].type),(yyvsp[(4) - (5)].range),(yyvsp[(5) - (5)].expression)); ;}
    break;

  case 20:
#line 96 "fst-compiler.yy"
    { (yyval.expression) = make_rule((yyvsp[(1) - (4)].expression),(yyvsp[(2) - (4)].range),(yyvsp[(3) - (4)].type),(yyvsp[(4) - (4)].range),NULL); ;}
    break;

  case 21:
#line 97 "fst-compiler.yy"
    { (yyval.expression) = make_rule(NULL,(yyvsp[(1) - (4)].range),(yyvsp[(2) - (4)].type),(yyvsp[(3) - (4)].range),(yyvsp[(4) - (4)].expression)); ;}
    break;

  case 22:
#line 98 "fst-compiler.yy"
    { (yyval.expression) = make_rule(NULL,(yyvsp[(1) - (3)].range),(yyvsp[(2) - (3)].type),(yyvsp[(3) - (3)].range),NULL); ;}
    break;

  case 23:
#line 99 "fst-compiler.yy"
    { (yyval.expression) = composition((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 24:
#line 100 "fst-compiler.yy"
    { (yyval.expression) = make_mapping((yyvsp[(2) - (7)].ranges),(yyvsp[(6) - (7)].ranges)); ;}
    break;

  case 25:
#line 101 "fst-compiler.yy"
    { (yyval.expression) = make_mapping(add_range((yyvsp[(1) - (5)].range),NULL),(yyvsp[(4) - (5)].ranges)); ;}
    break;

  case 26:
#line 102 "fst-compiler.yy"
    { (yyval.expression) = make_mapping((yyvsp[(2) - (5)].ranges),add_range((yyvsp[(5) - (5)].range),NULL)); ;}
    break;

  case 27:
#line 103 "fst-compiler.yy"
    { (yyval.expression) = freely_insert((yyvsp[(1) - (5)].expression), (yyvsp[(3) - (5)].character), (yyvsp[(5) - (5)].character)); ;}
    break;

  case 28:
#line 104 "fst-compiler.yy"
    { (yyval.expression) = freely_insert((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].character), (yyvsp[(3) - (3)].character)); ;}
    break;

  case 29:
#line 105 "fst-compiler.yy"
    { (yyval.expression) = new_transducer((yyvsp[(1) - (3)].range),(yyvsp[(3) - (3)].range)); ;}
    break;

  case 30:
#line 106 "fst-compiler.yy"
    { (yyval.expression) = new_transducer((yyvsp[(1) - (1)].range),(yyvsp[(1) - (1)].range)); ;}
    break;

  case 31:
#line 107 "fst-compiler.yy"
    { (yyval.expression) = var_value((yyvsp[(1) - (1)].name)); ;}
    break;

  case 32:
#line 108 "fst-compiler.yy"
    { (yyval.expression) = rvar_value((yyvsp[(1) - (1)].name)); ;}
    break;

  case 33:
#line 109 "fst-compiler.yy"
    { (yyval.expression) = repetition((yyvsp[(1) - (2)].expression)); ;}
    break;

  case 34:
#line 110 "fst-compiler.yy"
    { (yyval.expression) = repetition2((yyvsp[(1) - (2)].expression)); ;}
    break;

  case 35:
#line 111 "fst-compiler.yy"
    { (yyval.expression) = optional((yyvsp[(1) - (2)].expression)); ;}
    break;

  case 36:
#line 112 "fst-compiler.yy"
    { (yyval.expression) = catenate((yyvsp[(1) - (2)].expression), (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 37:
#line 113 "fst-compiler.yy"
    { (yyval.expression) = negation((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 38:
#line 114 "fst-compiler.yy"
    { (yyval.expression) = switch_levels((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 39:
#line 115 "fst-compiler.yy"
    { (yyval.expression) = upper_level((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 40:
#line 116 "fst-compiler.yy"
    { (yyval.expression) = lower_level((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 41:
#line 117 "fst-compiler.yy"
    { (yyval.expression) = conjunction((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 42:
#line 118 "fst-compiler.yy"
    { (yyval.expression) = subtraction((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 43:
#line 119 "fst-compiler.yy"
    { (yyval.expression) = disjunction((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 44:
#line 120 "fst-compiler.yy"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); ;}
    break;

  case 45:
#line 121 "fst-compiler.yy"
    { (yyval.expression) = read_words((yyvsp[(1) - (1)].value)); ;}
    break;

  case 46:
#line 122 "fst-compiler.yy"
    { (yyval.expression) = read_transducer((yyvsp[(1) - (1)].value)); ;}
    break;

  case 47:
#line 125 "fst-compiler.yy"
    { (yyval.ranges) = add_range((yyvsp[(1) - (2)].range),(yyvsp[(2) - (2)].ranges)); ;}
    break;

  case 48:
#line 126 "fst-compiler.yy"
    { (yyval.ranges) = NULL; ;}
    break;

  case 49:
#line 129 "fst-compiler.yy"
    { (yyval.range)=(yyvsp[(2) - (3)].range); ;}
    break;

  case 50:
#line 130 "fst-compiler.yy"
    { (yyval.range)=complement_range((yyvsp[(3) - (4)].range)); ;}
    break;

  case 51:
#line 131 "fst-compiler.yy"
    { (yyval.range)=rsvar_value((yyvsp[(2) - (3)].name)); ;}
    break;

  case 52:
#line 132 "fst-compiler.yy"
    { (yyval.range)=NULL; ;}
    break;

  case 53:
#line 133 "fst-compiler.yy"
    { (yyval.range)=add_value((yyvsp[(1) - (1)].character),NULL); ;}
    break;

  case 54:
#line 136 "fst-compiler.yy"
    { (yyval.contexts) = (yyvsp[(1) - (1)].contexts); ;}
    break;

  case 55:
#line 137 "fst-compiler.yy"
    { (yyval.contexts) = (yyvsp[(2) - (3)].contexts); ;}
    break;

  case 56:
#line 140 "fst-compiler.yy"
    { (yyval.contexts) = add_context((yyvsp[(1) - (3)].contexts),(yyvsp[(3) - (3)].contexts)); ;}
    break;

  case 57:
#line 141 "fst-compiler.yy"
    { (yyval.contexts) = (yyvsp[(1) - (1)].contexts); ;}
    break;

  case 58:
#line 144 "fst-compiler.yy"
    { (yyval.contexts) = (yyvsp[(1) - (1)].contexts); ;}
    break;

  case 59:
#line 145 "fst-compiler.yy"
    { (yyval.contexts) = (yyvsp[(2) - (3)].contexts); ;}
    break;

  case 60:
#line 148 "fst-compiler.yy"
    { (yyval.contexts) = make_context((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 61:
#line 149 "fst-compiler.yy"
    { (yyval.contexts) = make_context(NULL, (yyvsp[(2) - (2)].expression)); ;}
    break;

  case 62:
#line 150 "fst-compiler.yy"
    { (yyval.contexts) = make_context((yyvsp[(1) - (2)].expression), NULL); ;}
    break;

  case 63:
#line 153 "fst-compiler.yy"
    { (yyval.range)=append_values((yyvsp[(1) - (2)].range),(yyvsp[(2) - (2)].range)); ;}
    break;

  case 64:
#line 154 "fst-compiler.yy"
    { (yyval.range) = (yyvsp[(1) - (1)].range); ;}
    break;

  case 65:
#line 157 "fst-compiler.yy"
    { (yyval.range)=add_values((yyvsp[(1) - (3)].longchar),(yyvsp[(3) - (3)].longchar),NULL); ;}
    break;

  case 66:
#line 158 "fst-compiler.yy"
    { (yyval.range)=svar_value((yyvsp[(1) - (1)].name)); ;}
    break;

  case 67:
#line 159 "fst-compiler.yy"
    { (yyval.range)=add_value(character_code((yyvsp[(1) - (1)].longchar)),NULL); ;}
    break;

  case 68:
#line 160 "fst-compiler.yy"
    { (yyval.range)=add_value((yyvsp[(1) - (1)].character),NULL); ;}
    break;

  case 69:
#line 161 "fst-compiler.yy"
    { (yyval.range)=add_value((yyvsp[(1) - (1)].uchar),NULL); ;}
    break;

  case 70:
#line 164 "fst-compiler.yy"
    { (yyval.longchar)=(yyvsp[(1) - (1)].uchar); ;}
    break;

  case 71:
#line 165 "fst-compiler.yy"
    { (yyval.longchar)=utf8toint((yyvsp[(1) - (1)].value)); ;}
    break;

  case 72:
#line 166 "fst-compiler.yy"
    { (yyval.longchar)=(yyvsp[(1) - (1)].uchar); ;}
    break;

  case 73:
#line 169 "fst-compiler.yy"
    { (yyval.character)=character_code((yyvsp[(1) - (1)].uchar)); ;}
    break;

  case 74:
#line 170 "fst-compiler.yy"
    { (yyval.character)=symbol_code((yyvsp[(1) - (1)].value)); ;}
    break;

  case 75:
#line 171 "fst-compiler.yy"
    { (yyval.character)=symbol_code((yyvsp[(1) - (1)].name)); ;}
    break;

  case 76:
#line 174 "fst-compiler.yy"
    { (yyval.uchar)=character_code('.'); ;}
    break;

  case 77:
#line 175 "fst-compiler.yy"
    { (yyval.uchar)=character_code('!'); ;}
    break;

  case 78:
#line 176 "fst-compiler.yy"
    { (yyval.uchar)=character_code('?'); ;}
    break;

  case 79:
#line 177 "fst-compiler.yy"
    { (yyval.uchar)=character_code('{'); ;}
    break;

  case 80:
#line 178 "fst-compiler.yy"
    { (yyval.uchar)=character_code('}'); ;}
    break;

  case 81:
#line 179 "fst-compiler.yy"
    { (yyval.uchar)=character_code(')'); ;}
    break;

  case 82:
#line 180 "fst-compiler.yy"
    { (yyval.uchar)=character_code('('); ;}
    break;

  case 83:
#line 181 "fst-compiler.yy"
    { (yyval.uchar)=character_code('&'); ;}
    break;

  case 84:
#line 182 "fst-compiler.yy"
    { (yyval.uchar)=character_code('|'); ;}
    break;

  case 85:
#line 183 "fst-compiler.yy"
    { (yyval.uchar)=character_code('*'); ;}
    break;

  case 86:
#line 184 "fst-compiler.yy"
    { (yyval.uchar)=character_code('+'); ;}
    break;

  case 87:
#line 185 "fst-compiler.yy"
    { (yyval.uchar)=character_code(':'); ;}
    break;

  case 88:
#line 186 "fst-compiler.yy"
    { (yyval.uchar)=character_code(','); ;}
    break;

  case 89:
#line 187 "fst-compiler.yy"
    { (yyval.uchar)=character_code('='); ;}
    break;

  case 90:
#line 188 "fst-compiler.yy"
    { (yyval.uchar)=character_code('_'); ;}
    break;

  case 91:
#line 189 "fst-compiler.yy"
    { (yyval.uchar)=character_code('^'); ;}
    break;

  case 92:
#line 190 "fst-compiler.yy"
    { (yyval.uchar)=character_code('-'); ;}
    break;

  case 93:
#line 193 "fst-compiler.yy"
    {;}
    break;

  case 94:
#line 194 "fst-compiler.yy"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 2144 "fst-compiler.C"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 197 "fst-compiler.yy"


extern FILE  *yyin;

/*******************************************************************/
/*                                                                 */
/*  yyerror                                                        */
/*                                                                 */
/*******************************************************************/

void yyerror(char *text)

{
  cerr << "\n" << FileName << ":" << yylineno << ": " << text << " at: ";
  cerr << yytext << "\naborted.\n";
  exit(1);
}

