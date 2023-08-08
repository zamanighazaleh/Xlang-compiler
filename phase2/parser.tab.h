/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PROGRAMCLASS = 258,      /* TOKEN_PROGRAMCLASS  */
    TOKEN_CLASS = 259,             /* TOKEN_CLASS  */
    TOKEN_MAINFUNC = 260,          /* TOKEN_MAINFUNC  */
    TOKEN_IFCONDITION = 261,       /* TOKEN_IFCONDITION  */
    TOKEN_ELSECONDITION = 262,     /* TOKEN_ELSECONDITION  */
    TOKEN_LOOP = 263,              /* TOKEN_LOOP  */
    TOKEN_BREAKSTMT = 264,         /* TOKEN_BREAKSTMT  */
    TOKEN_CONTINUESTMT = 265,      /* TOKEN_CONTINUESTMT  */
    TOKEN_INTTYPE = 266,           /* TOKEN_INTTYPE  */
    TOKEN_BOOLEANTYPE = 267,       /* TOKEN_BOOLEANTYPE  */
    TOKEN_VOIDTYPE = 268,          /* TOKEN_VOIDTYPE  */
    TOKEN_CALLOUT = 269,           /* TOKEN_CALLOUT  */
    TOKEN_RETURN = 270,            /* TOKEN_RETURN  */
    TOKEN_BOOLEANCONST = 271,      /* TOKEN_BOOLEANCONST  */
    TOKEN_ARITHMATICOP = 272,      /* TOKEN_ARITHMATICOP  */
    TOKEN_RELATIONOP = 273,        /* TOKEN_RELATIONOP  */
    TOKEN_EQUALITYOP = 274,        /* TOKEN_EQUALITYOP  */
    TOKEN_CONDITIONOP = 275,       /* TOKEN_CONDITIONOP  */
    TOKEN_ASSIGNOP = 276,          /* TOKEN_ASSIGNOP  */
    TOKEN_LOGICOP = 277,           /* TOKEN_LOGICOP  */
    TOKEN_LP = 278,                /* TOKEN_LP  */
    TOKEN_RP = 279,                /* TOKEN_RP  */
    TOKEN_LCB = 280,               /* TOKEN_LCB  */
    TOKEN_RCB = 281,               /* TOKEN_RCB  */
    TOKEN_LB = 282,                /* TOKEN_LB  */
    TOKEN_RB = 283,                /* TOKEN_RB  */
    TOKEN_COMMA = 284,             /* TOKEN_COMMA  */
    TOKEN_SEMICOLON = 285,         /* TOKEN_SEMICOLON  */
    TOKEN_IDENTIFIER = 286,        /* TOKEN_IDENTIFIER  */
    TOKEN_DECIMALCONST = 287,      /* TOKEN_DECIMALCONST  */
    TOKEN_HEXADECIMALCONST = 288,  /* TOKEN_HEXADECIMALCONST  */
    TOKEN_CHARCONST = 289,         /* TOKEN_CHARCONST  */
    TOKEN_STRINGCONST = 290        /* TOKEN_STRINGCONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "parser.y"

	int ival;
	char* sval;
	struct Node* node;

#line 105 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
