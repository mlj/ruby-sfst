/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */
#line 106 "fst-compiler.H"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

