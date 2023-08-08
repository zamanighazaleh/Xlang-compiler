/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stddef.h>
	#include <vector>
	
	using namespace std;
	
	extern FILE* yyin;
	extern FILE* yyout;
	extern int line;
	extern int yylex();

	int yyerror(const char* message);
	
	
	
	vector <string> tree;
	int count = 0;
	int arg_count = 0;
	bool main_flag = false;
	FILE* syntax_tree;
	
	struct Node{
	char* name;
	char* value;
	struct Node *sister = NULL;
	struct Node *child = NULL;
	
	};
	struct Node* root=new Node();
	struct Node* child1;
	struct Node* child2;
	struct Node* child3;
	struct Node* child4;
	struct Node* child5;
	struct Node* child6;
	struct Node* child7;
	
	void printtree(struct Node* , int ,int );
	

#line 118 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_PROGRAMCLASS = 3,         /* TOKEN_PROGRAMCLASS  */
  YYSYMBOL_TOKEN_CLASS = 4,                /* TOKEN_CLASS  */
  YYSYMBOL_TOKEN_MAINFUNC = 5,             /* TOKEN_MAINFUNC  */
  YYSYMBOL_TOKEN_IFCONDITION = 6,          /* TOKEN_IFCONDITION  */
  YYSYMBOL_TOKEN_ELSECONDITION = 7,        /* TOKEN_ELSECONDITION  */
  YYSYMBOL_TOKEN_LOOP = 8,                 /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_BREAKSTMT = 9,            /* TOKEN_BREAKSTMT  */
  YYSYMBOL_TOKEN_CONTINUESTMT = 10,        /* TOKEN_CONTINUESTMT  */
  YYSYMBOL_TOKEN_INTTYPE = 11,             /* TOKEN_INTTYPE  */
  YYSYMBOL_TOKEN_BOOLEANTYPE = 12,         /* TOKEN_BOOLEANTYPE  */
  YYSYMBOL_TOKEN_VOIDTYPE = 13,            /* TOKEN_VOIDTYPE  */
  YYSYMBOL_TOKEN_CALLOUT = 14,             /* TOKEN_CALLOUT  */
  YYSYMBOL_TOKEN_RETURN = 15,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_BOOLEANCONST = 16,        /* TOKEN_BOOLEANCONST  */
  YYSYMBOL_TOKEN_ARITHMATICOP = 17,        /* TOKEN_ARITHMATICOP  */
  YYSYMBOL_TOKEN_RELATIONOP = 18,          /* TOKEN_RELATIONOP  */
  YYSYMBOL_TOKEN_EQUALITYOP = 19,          /* TOKEN_EQUALITYOP  */
  YYSYMBOL_TOKEN_CONDITIONOP = 20,         /* TOKEN_CONDITIONOP  */
  YYSYMBOL_TOKEN_ASSIGNOP = 21,            /* TOKEN_ASSIGNOP  */
  YYSYMBOL_TOKEN_LOGICOP = 22,             /* TOKEN_LOGICOP  */
  YYSYMBOL_TOKEN_LP = 23,                  /* TOKEN_LP  */
  YYSYMBOL_TOKEN_RP = 24,                  /* TOKEN_RP  */
  YYSYMBOL_TOKEN_LCB = 25,                 /* TOKEN_LCB  */
  YYSYMBOL_TOKEN_RCB = 26,                 /* TOKEN_RCB  */
  YYSYMBOL_TOKEN_LB = 27,                  /* TOKEN_LB  */
  YYSYMBOL_TOKEN_RB = 28,                  /* TOKEN_RB  */
  YYSYMBOL_TOKEN_COMMA = 29,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SEMICOLON = 30,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_IDENTIFIER = 31,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_DECIMALCONST = 32,        /* TOKEN_DECIMALCONST  */
  YYSYMBOL_TOKEN_HEXADECIMALCONST = 33,    /* TOKEN_HEXADECIMALCONST  */
  YYSYMBOL_TOKEN_CHARCONST = 34,           /* TOKEN_CHARCONST  */
  YYSYMBOL_TOKEN_STRINGCONST = 35,         /* TOKEN_STRINGCONST  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_field_method = 38,              /* field_method  */
  YYSYMBOL_field_decl = 39,                /* field_decl  */
  YYSYMBOL_variable_star = 40,             /* variable_star  */
  YYSYMBOL_variable = 41,                  /* variable  */
  YYSYMBOL_method_decl_star = 42,          /* method_decl_star  */
  YYSYMBOL_method_decl = 43,               /* method_decl  */
  YYSYMBOL_id_main = 44,                   /* id_main  */
  YYSYMBOL_argument_plus_ = 45,            /* argument_plus_  */
  YYSYMBOL_argument_plus = 46,             /* argument_plus  */
  YYSYMBOL_argument = 47,                  /* argument  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_var_decl_star = 49,             /* var_decl_star  */
  YYSYMBOL_var_decl = 50,                  /* var_decl  */
  YYSYMBOL_id_plus = 51,                   /* id_plus  */
  YYSYMBOL_statement_star = 52,            /* statement_star  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_else_block_ = 55,               /* else_block_  */
  YYSYMBOL_expr_ = 56,                     /* expr_  */
  YYSYMBOL_assign_op = 57,                 /* assign_op  */
  YYSYMBOL_method_call = 58,               /* method_call  */
  YYSYMBOL_expr_plus_ = 59,                /* expr_plus_  */
  YYSYMBOL_expr_plus = 60,                 /* expr_plus  */
  YYSYMBOL_callout_arg_plus_ = 61,         /* callout_arg_plus_  */
  YYSYMBOL_callout_arg_plus = 62,          /* callout_arg_plus  */
  YYSYMBOL_method_name = 63,               /* method_name  */
  YYSYMBOL_location = 64,                  /* location  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_callout_arg = 66,               /* callout_arg  */
  YYSYMBOL_literal = 67,                   /* literal  */
  YYSYMBOL_int_literal = 68                /* int_literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   140,   147,   157,   175,   189,   196,   207,
     232,   240,   247,   267,   294,   305,   320,   327,   334,   347,
     357,   380,   400,   408,   414,   430,   447,   461,   469,   476,
     487,   501,   515,   527,   551,   580,   597,   613,   629,   639,
     652,   658,   666,   672,   685,   703,   732,   741,   747,   760,
     771,   784,   791,   804,   815,   829,   840,   864,   873,   882,
     890,   903,   916,   929,   942,   954,   966,   985,   993,  1006,
    1014,  1025,  1039,  1050
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_PROGRAMCLASS",
  "TOKEN_CLASS", "TOKEN_MAINFUNC", "TOKEN_IFCONDITION",
  "TOKEN_ELSECONDITION", "TOKEN_LOOP", "TOKEN_BREAKSTMT",
  "TOKEN_CONTINUESTMT", "TOKEN_INTTYPE", "TOKEN_BOOLEANTYPE",
  "TOKEN_VOIDTYPE", "TOKEN_CALLOUT", "TOKEN_RETURN", "TOKEN_BOOLEANCONST",
  "TOKEN_ARITHMATICOP", "TOKEN_RELATIONOP", "TOKEN_EQUALITYOP",
  "TOKEN_CONDITIONOP", "TOKEN_ASSIGNOP", "TOKEN_LOGICOP", "TOKEN_LP",
  "TOKEN_RP", "TOKEN_LCB", "TOKEN_RCB", "TOKEN_LB", "TOKEN_RB",
  "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_IDENTIFIER",
  "TOKEN_DECIMALCONST", "TOKEN_HEXADECIMALCONST", "TOKEN_CHARCONST",
  "TOKEN_STRINGCONST", "$accept", "program", "field_method", "field_decl",
  "variable_star", "variable", "method_decl_star", "method_decl",
  "id_main", "argument_plus_", "argument_plus", "argument", "block",
  "var_decl_star", "var_decl", "id_plus", "statement_star", "type",
  "statement", "else_block_", "expr_", "assign_op", "method_call",
  "expr_plus_", "expr_plus", "callout_arg_plus_", "callout_arg_plus",
  "method_name", "location", "expr", "callout_arg", "literal",
  "int_literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    19,    40,    24,   -58,    90,   -58,   -58,    -2,    31,
      90,   -58,    90,    -1,   -58,   -58,    46,   -58,   -58,   -58,
      -2,   -17,    34,    56,    13,    22,    49,    35,    13,    64,
     -58,    62,    77,   -58,   -58,    65,    92,    34,   -58,    96,
     101,    13,   -58,   -58,   -58,   101,    13,   -58,   -58,   -58,
      27,    13,   103,   104,   106,    98,   108,   112,    73,    -6,
     -58,   110,    27,   109,   117,   120,   -58,   114,   115,    73,
     121,   -58,   -58,   111,   -58,    73,    73,    73,   -58,   118,
     -58,   -58,   113,   -58,   -58,    73,   -58,   -58,   -58,    73,
     -58,    73,   103,   -58,    97,    73,   122,   -58,   -58,   105,
     -58,    73,    73,    73,    73,    42,   123,   -58,    57,    -4,
     -58,   101,    80,    50,   125,   -58,   -58,   127,    33,    14,
     -58,   -58,    73,   -58,   143,    73,   -58,   -58,   113,   124,
     -58,   -58,   101,   -58,    93,    50,   -58,   -58,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,    11,    29,    30,     0,     0,
      11,     4,    11,     0,    15,    14,     0,     2,     3,    10,
       0,     8,     7,     0,    17,     0,     0,     0,    17,     0,
      16,    19,     0,    72,    73,     0,     8,     7,     5,     0,
       0,     0,    20,     9,     6,     0,    23,    13,    18,    12,
      28,    23,     0,     0,     0,     0,     0,     0,    42,    55,
      38,     0,    28,     0,     0,     0,    22,    26,     0,     0,
       0,    36,    37,     0,    71,     0,     0,     0,    70,     0,
      58,    57,    41,    59,    69,     0,    21,    27,    32,    47,
      43,     0,     0,    24,     0,     0,    51,    64,    65,     0,
      35,     0,     0,     0,     0,     0,     0,    46,    49,     0,
      25,     0,     0,     0,     0,    66,    60,    61,    62,    63,
      56,    44,     0,    31,    40,     0,    68,    50,    67,    53,
      45,    48,     0,    33,     0,     0,    39,    34,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   142,   -58,   119,   128,   145,   -58,   147,   130,
     126,   -58,   -40,   129,   -58,    67,    99,    -3,   -58,   -58,
     -58,   -58,   -39,   -58,    38,   -58,    28,   -58,   -23,   -57,
     -58,   -58,   137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    27,    22,    11,    12,    23,    29,
      30,    31,    60,    50,    51,    68,    61,    32,    62,   133,
      79,    91,    80,   106,   107,   114,   127,    64,    81,   108,
     129,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    82,    13,    14,    14,    49,   -14,    13,     1,    20,
      25,    63,    94,   101,   102,   103,   104,   -54,    97,    98,
      99,    85,     3,    63,     6,     7,   123,    65,   105,    15,
      21,   101,   102,    53,   109,    54,    55,    56,   112,    65,
       4,    57,    58,    52,   116,   117,   118,   119,    52,     5,
     101,   102,    46,   104,    33,    34,   128,    17,    59,   101,
     102,   103,   104,    26,    57,    38,    74,    75,   134,    24,
     120,   124,    76,    77,   101,   102,   103,   104,   128,    28,
      36,    59,    33,    34,    78,   126,   122,    57,    40,    74,
      75,    41,   136,    43,   137,    76,    77,   101,   102,   103,
     104,     6,     7,     8,    59,    33,    34,    78,    42,   125,
     101,   102,   103,   104,   101,   102,   103,   104,    46,    25,
      45,   111,   101,   102,   103,   104,    46,    69,    71,   115,
     101,   102,   103,   104,    67,    73,    86,    70,    72,    88,
      89,    90,    95,    92,   101,    93,    96,   121,   100,   130,
     132,   113,    18,   135,    37,    16,    44,    19,    39,   110,
     131,    87,    35,   138,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66
};

static const yytype_int16 yycheck[] =
{
      40,    58,     5,     5,     5,    45,    23,    10,     4,    12,
      27,    50,    69,    17,    18,    19,    20,    23,    75,    76,
      77,    27,     3,    62,    11,    12,    30,    50,    85,    31,
      31,    17,    18,     6,    91,     8,     9,    10,    95,    62,
       0,    14,    15,    46,   101,   102,   103,   104,    51,    25,
      17,    18,    25,    20,    32,    33,   113,    26,    31,    17,
      18,    19,    20,    29,    14,    30,    16,    17,   125,    23,
      28,   111,    22,    23,    17,    18,    19,    20,   135,    23,
      31,    31,    32,    33,    34,    35,    29,    14,    24,    16,
      17,    29,   132,    28,   134,    22,    23,    17,    18,    19,
      20,    11,    12,    13,    31,    32,    33,    34,    31,    29,
      17,    18,    19,    20,    17,    18,    19,    20,    25,    27,
      24,    24,    17,    18,    19,    20,    25,    23,    30,    24,
      17,    18,    19,    20,    31,    23,    26,    31,    30,    30,
      23,    21,    21,    29,    17,    30,    35,    24,    30,    24,
       7,    29,    10,    29,    26,     8,    37,    12,    28,    92,
     122,    62,    25,   135,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    37,     3,     0,    25,    11,    12,    13,    38,
      39,    42,    43,    53,     5,    31,    44,    26,    38,    42,
      53,    31,    41,    44,    23,    27,    29,    40,    23,    45,
      46,    47,    53,    32,    33,    68,    31,    41,    30,    45,
      24,    29,    31,    28,    40,    24,    25,    48,    46,    48,
      49,    50,    53,     6,     8,     9,    10,    14,    15,    31,
      48,    52,    54,    58,    63,    64,    49,    31,    51,    23,
      31,    30,    30,    23,    16,    17,    22,    23,    34,    56,
      58,    64,    65,    67,    68,    27,    26,    52,    30,    23,
      21,    57,    29,    30,    65,    21,    35,    65,    65,    65,
      30,    17,    18,    19,    20,    65,    59,    60,    65,    65,
      51,    24,    65,    29,    61,    24,    65,    65,    65,    65,
      28,    24,    29,    30,    48,    29,    35,    62,    65,    66,
      24,    60,     7,    55,    65,    29,    48,    48,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      47,    48,    49,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     1,     4,     3,     0,     1,     4,
       2,     0,     6,     6,     1,     1,     1,     0,     3,     1,
       2,     4,     2,     0,     3,     3,     1,     2,     0,     1,
       1,     4,     2,     6,     7,     3,     2,     2,     1,     2,
       0,     1,     0,     1,     4,     5,     1,     0,     3,     1,
       2,     0,     3,     1,     1,     1,     4,     1,     1,     1,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: TOKEN_CLASS TOKEN_PROGRAMCLASS TOKEN_LCB field_method TOKEN_RCB  */
#line 104 "parser.y"
                {
			if (!main_flag) {
				yyerror("syntax error, the main function is not defined,");
			}


			root->name=strdup("<program>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CLASS");
			child1->value = strdup("class");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_PROGRAMCLASS");
			child2->value = strdup("Program");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_LCB");
			child3->value = strdup("{");
			
			child4 = new Node();
			child4->name = strdup("TOKEN_RCB");
			child4->value = strdup("}");
			
			root->child = child1;
			child1->sister = child2;
			child2->sister = child3;
			child3->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))->sister = child4;
			return 0;
		}
#line 1698 "parser.tab.c"
    break;

  case 3: /* field_method: field_decl field_method  */
#line 141 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<field_method>");	
			((yyval.node))->child = (yyvsp[-1].node);
			((yyvsp[-1].node))->sister = (yyvsp[0].node);
		}
#line 1709 "parser.tab.c"
    break;

  case 4: /* field_method: method_decl_star  */
#line 148 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<field_method>");	
			((yyval.node))->child = (yyvsp[0].node);
		}
#line 1719 "parser.tab.c"
    break;

  case 5: /* field_decl: type variable variable_star TOKEN_SEMICOLON  */
#line 158 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<field_decl>");	
			
			((yyval.node))->child = (yyvsp[-3].node);
			((yyvsp[-3].node))->sister = (yyvsp[-2].node);
			((yyvsp[-2].node))->sister = (yyvsp[-1].node);
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			((yyvsp[-1].node))->sister = child1;
		}
#line 1738 "parser.tab.c"
    break;

  case 6: /* variable_star: TOKEN_COMMA variable variable_star  */
#line 176 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<variable_star>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
				
			((yyval.node))->child = child1;
			child1->sister = (yyvsp[-1].node);
			((yyvsp[-1].node))->child = (yyvsp[0].node);
		}
#line 1755 "parser.tab.c"
    break;

  case 7: /* variable_star: %empty  */
#line 189 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<variable_star>");
		}
#line 1764 "parser.tab.c"
    break;

  case 8: /* variable: TOKEN_IDENTIFIER  */
#line 197 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<variable>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 1779 "parser.tab.c"
    break;

  case 9: /* variable: TOKEN_IDENTIFIER TOKEN_LB int_literal TOKEN_RB  */
#line 208 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<variable>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[-3].sval);
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LB");
			child2->value = strdup("[");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RB");
			child3->value = strdup("]");
			
			((yyval.node))->child = child1;
			child1->sister = child2;
			child2 -> sister = (yyvsp[-1].node);
			(yyvsp[-1].node) -> sister = child3;
		}
#line 1805 "parser.tab.c"
    break;

  case 10: /* method_decl_star: method_decl method_decl_star  */
#line 233 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_decl_star>");	
			((yyval.node))->child = (yyvsp[-1].node);
			((yyvsp[-1].node))->sister = (yyvsp[0].node);
		}
#line 1816 "parser.tab.c"
    break;

  case 11: /* method_decl_star: %empty  */
#line 240 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_decl_star>");
		}
#line 1825 "parser.tab.c"
    break;

  case 12: /* method_decl: type id_main TOKEN_LP argument_plus_ TOKEN_RP block  */
#line 248 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			((yyval.node))->child = ((yyvsp[-5].node));
			((yyvsp[-5].node))->sister = ((yyvsp[-4].node));
			((yyvsp[-4].node)) -> sister = child1;
			child1 -> sister = ((yyvsp[-2].node));
			((yyvsp[-2].node))->sister = child2;
			child2 ->sister = ((yyvsp[0].node));
		}
#line 1849 "parser.tab.c"
    break;

  case 13: /* method_decl: TOKEN_VOIDTYPE id_main TOKEN_LP argument_plus_ TOKEN_RP block  */
#line 268 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_VOIDTYPE");
			child1->value = strdup("void");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RP");
			child3->value = strdup(")");
			
			((yyval.node))->child = child1;
			child1->sister = ((yyvsp[-4].node));
			((yyvsp[-4].node)) -> sister = child2;
			child2 -> sister = ((yyvsp[-2].node));
			((yyvsp[-2].node))->sister = child3;
			child3 ->sister = ((yyvsp[0].node));
		}
#line 1877 "parser.tab.c"
    break;

  case 14: /* id_main: TOKEN_IDENTIFIER  */
#line 295 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<id_main>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 1892 "parser.tab.c"
    break;

  case 15: /* id_main: TOKEN_MAINFUNC  */
#line 306 "parser.y"
                {
			main_flag = true;
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<id_main>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_MAINFUNC");
			child1->value = strdup("main");
			
			((yyval.node))->child = child1;
		}
#line 1908 "parser.tab.c"
    break;

  case 16: /* argument_plus_: argument_plus  */
#line 321 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<argument_plus_>");	
			((yyval.node))->child = (yyvsp[0].node);
		}
#line 1918 "parser.tab.c"
    break;

  case 17: /* argument_plus_: %empty  */
#line 327 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<argument_plus_>");
		}
#line 1927 "parser.tab.c"
    break;

  case 18: /* argument_plus: argument TOKEN_COMMA argument_plus  */
#line 335 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<argument_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node))->sister = child1;
			child1 -> sister = (yyvsp[0].node);
		}
#line 1944 "parser.tab.c"
    break;

  case 19: /* argument_plus: argument  */
#line 348 "parser.y"
                {
			arg_count = 0;
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<argument_plus>");	
			((yyval.node))->child = (yyvsp[0].node);
		}
#line 1955 "parser.tab.c"
    break;

  case 20: /* argument: type TOKEN_IDENTIFIER  */
#line 358 "parser.y"
                {
			arg_count += 1;
			if (arg_count > 4) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}
			
			if (main_flag) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}

			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<argument_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = ((yyvsp[-1].node));
			((yyvsp[-1].node))->sister = child1;
		}
#line 1980 "parser.tab.c"
    break;

  case 21: /* block: TOKEN_LCB var_decl_star statement_star TOKEN_RCB  */
#line 381 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<block>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LCB");
			child1->value = strdup("{");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RCB");
			child2->value = strdup("}");
			
			((yyval.node))->child = child1;
			child1->sister = ((yyvsp[-2].node));
			((yyvsp[-2].node)) -> sister = ((yyvsp[-1].node));
			((yyvsp[-1].node)) -> sister = child2;
		}
#line 2002 "parser.tab.c"
    break;

  case 22: /* var_decl_star: var_decl var_decl_star  */
#line 401 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<var_decl_star>");	
			((yyval.node))->child = (yyvsp[-1].node);
			((yyvsp[-1].node))->sister = (yyvsp[0].node);
		}
#line 2013 "parser.tab.c"
    break;

  case 23: /* var_decl_star: %empty  */
#line 408 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<var_decl_star>");
		}
#line 2022 "parser.tab.c"
    break;

  case 24: /* var_decl: type id_plus TOKEN_SEMICOLON  */
#line 415 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<var_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node))->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child1;
		}
#line 2039 "parser.tab.c"
    break;

  case 25: /* id_plus: TOKEN_IDENTIFIER TOKEN_COMMA id_plus  */
#line 431 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<id_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[-2].sval);
			
			child2 = new Node();
			child2->name = strdup("TOKEN_COMMA");
			child2->value = strdup(",");
			
			((yyval.node))->child = child1;
			child1->sister = child2;
			child2 -> sister = (yyvsp[0].node);
		}
#line 2060 "parser.tab.c"
    break;

  case 26: /* id_plus: TOKEN_IDENTIFIER  */
#line 448 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<id_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2075 "parser.tab.c"
    break;

  case 27: /* statement_star: statement statement_star  */
#line 462 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement_star>");	
			((yyval.node))->child = (yyvsp[-1].node);
			((yyvsp[-1].node))->sister = (yyvsp[0].node);
		}
#line 2086 "parser.tab.c"
    break;

  case 28: /* statement_star: %empty  */
#line 469 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement_star>");
		}
#line 2095 "parser.tab.c"
    break;

  case 29: /* type: TOKEN_INTTYPE  */
#line 477 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<type>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_INTTYPE");
			child1->value = strdup("int");;
			
			((yyval.node))->child = child1;
		}
#line 2110 "parser.tab.c"
    break;

  case 30: /* type: TOKEN_BOOLEANTYPE  */
#line 488 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<type>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BOOLEANTYPE");
			child1->value = strdup("boolean");;
			
			((yyval.node))->child = child1;
		}
#line 2125 "parser.tab.c"
    break;

  case 31: /* statement: location assign_op expr TOKEN_SEMICOLON  */
#line 502 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			((yyval.node))->child = ((yyvsp[-3].node));
			((yyvsp[-3].node))->sister = ((yyvsp[-2].node));
			((yyvsp[-2].node))->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child1;
		}
#line 2143 "parser.tab.c"
    break;

  case 32: /* statement: method_call TOKEN_SEMICOLON  */
#line 516 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			((yyval.node))->child = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child1;
		}
#line 2159 "parser.tab.c"
    break;

  case 33: /* statement: TOKEN_IFCONDITION TOKEN_LP expr TOKEN_RP block else_block_  */
#line 528 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IFCONDITION");
			child1->value = strdup("if");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RP");
			child3->value = strdup(")");
			
			((yyval.node))->child = child1;
			child1-> sister = child2;
			child2-> sister = ((yyvsp[-3].node));
			((yyvsp[-3].node))-> sister = child3;
			child3->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node)) ->sister = ((yyvsp[0].node));
		}
#line 2187 "parser.tab.c"
    break;

  case 34: /* statement: TOKEN_LOOP TOKEN_IDENTIFIER TOKEN_ASSIGNOP expr TOKEN_COMMA expr block  */
#line 552 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LOOP");
			child1->value = strdup("for");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_IDENTIFIER");
			child2->value = (yyvsp[-5].sval);
			
			child3 = new Node();
			child3->name = strdup("TOKEN_ASSIGNOP");
			child3->value = (yyvsp[-4].sval);
			
			child4 = new Node();
			child4->name = strdup("TOKEN_COMMA");
			child4->value = strdup(",");
			
			((yyval.node))->child = child1;
			child1-> sister = child2;
			child2-> sister = child3;
			child3-> sister = ((yyvsp[-3].node));
			((yyvsp[-3].node))->sister = child4;
			child4 ->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node)) -> sister = ((yyvsp[0].node));
		}
#line 2220 "parser.tab.c"
    break;

  case 35: /* statement: TOKEN_RETURN expr_ TOKEN_SEMICOLON  */
#line 581 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_RETURN");
			child1->value = strdup("return");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			((yyval.node))->child = child1;
			child1->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node)) -> sister = child2;
		}
#line 2241 "parser.tab.c"
    break;

  case 36: /* statement: TOKEN_BREAKSTMT TOKEN_SEMICOLON  */
#line 598 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BREAKSTMT");
			child1->value = strdup("break");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			((yyval.node))->child = child1;
			child1->sister = child2;
		}
#line 2261 "parser.tab.c"
    break;

  case 37: /* statement: TOKEN_CONTINUESTMT TOKEN_SEMICOLON  */
#line 614 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CONTINUESTMT");
			child1->value = strdup("continue");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			((yyval.node))->child = child1;
			child1->sister = child2;
		}
#line 2281 "parser.tab.c"
    break;

  case 38: /* statement: block  */
#line 630 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<statement>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2293 "parser.tab.c"
    break;

  case 39: /* else_block_: TOKEN_ELSECONDITION block  */
#line 640 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<else_block_>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ELSECONDITION");
			child1->value = strdup("else");
			
			((yyval.node))->child = child1;
			child1->sister = ((yyvsp[0].node));
		}
#line 2309 "parser.tab.c"
    break;

  case 40: /* else_block_: %empty  */
#line 652 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<else_block_>");
		}
#line 2318 "parser.tab.c"
    break;

  case 41: /* expr_: expr  */
#line 659 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_>");
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2329 "parser.tab.c"
    break;

  case 42: /* expr_: %empty  */
#line 666 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_>");
		}
#line 2338 "parser.tab.c"
    break;

  case 43: /* assign_op: TOKEN_ASSIGNOP  */
#line 673 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<assign_op>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ASSIGNOP");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2353 "parser.tab.c"
    break;

  case 44: /* method_call: method_name TOKEN_LP expr_plus_ TOKEN_RP  */
#line 686 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_call>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			((yyval.node))->child = ((yyvsp[-3].node));
			((yyvsp[-3].node))-> sister = child1;
			child1-> sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child2;
		}
#line 2375 "parser.tab.c"
    break;

  case 45: /* method_call: TOKEN_CALLOUT TOKEN_LP TOKEN_STRINGCONST callout_arg_plus_ TOKEN_RP  */
#line 704 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_call>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CALLOUT");
			child1->value = strdup("callout");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_STRINGCONST");
			child3->value = (yyvsp[-2].sval);
			
			child4 = new Node();
			child4->name = strdup("TOKEN_RP");
			child4->value = strdup(")");
			
			((yyval.node))->child = child1;
			child1-> sister = child2;
			child2-> sister = child3;
			child3-> sister = ((yyvsp[-1].node));
			((yyvsp[-1].node)) -> sister = child4;
		}
#line 2406 "parser.tab.c"
    break;

  case 46: /* expr_plus_: expr_plus  */
#line 733 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_plus_>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2418 "parser.tab.c"
    break;

  case 47: /* expr_plus_: %empty  */
#line 741 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_plus_>");
		}
#line 2427 "parser.tab.c"
    break;

  case 48: /* expr_plus: expr TOKEN_COMMA expr_plus  */
#line 748 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) -> sister = child1;
			child1->sister = ((yyvsp[0].node));
		}
#line 2444 "parser.tab.c"
    break;

  case 49: /* expr_plus: expr  */
#line 761 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr_plus>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2456 "parser.tab.c"
    break;

  case 50: /* callout_arg_plus_: TOKEN_COMMA callout_arg_plus  */
#line 772 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg_plus_>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			((yyval.node))->child = child1;
			child1 -> sister = ((yyvsp[0].node));
		}
#line 2472 "parser.tab.c"
    break;

  case 51: /* callout_arg_plus_: %empty  */
#line 784 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg_plus_>");
		}
#line 2481 "parser.tab.c"
    break;

  case 52: /* callout_arg_plus: callout_arg TOKEN_COMMA callout_arg_plus  */
#line 792 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) -> sister = child1;
			child1->sister = ((yyvsp[0].node));
		}
#line 2498 "parser.tab.c"
    break;

  case 53: /* callout_arg_plus: callout_arg  */
#line 805 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg_plus>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2510 "parser.tab.c"
    break;

  case 54: /* method_name: TOKEN_IDENTIFIER  */
#line 816 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<method_name>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2525 "parser.tab.c"
    break;

  case 55: /* location: TOKEN_IDENTIFIER  */
#line 830 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<location>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2540 "parser.tab.c"
    break;

  case 56: /* location: TOKEN_IDENTIFIER TOKEN_LB expr TOKEN_RB  */
#line 841 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<location>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = ((yyvsp[-3].sval));
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LB");
			child2->value = strdup("[");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RB");
			child3->value = strdup("]");
			
			((yyval.node))->child = child1;
			child1-> sister = child2;
			child2-> sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child3;
		}
#line 2566 "parser.tab.c"
    break;

  case 57: /* expr: location  */
#line 865 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2578 "parser.tab.c"
    break;

  case 58: /* expr: method_call  */
#line 874 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2590 "parser.tab.c"
    break;

  case 59: /* expr: literal  */
#line 883 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2602 "parser.tab.c"
    break;

  case 60: /* expr: expr TOKEN_ARITHMATICOP expr  */
#line 891 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ARITHMATICOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) ->sister = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2619 "parser.tab.c"
    break;

  case 61: /* expr: expr TOKEN_RELATIONOP expr  */
#line 904 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_RELATIONOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) ->sister = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2636 "parser.tab.c"
    break;

  case 62: /* expr: expr TOKEN_EQUALITYOP expr  */
#line 917 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_EQUALITYOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) ->sister = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2653 "parser.tab.c"
    break;

  case 63: /* expr: expr TOKEN_CONDITIONOP expr  */
#line 930 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CONDITIONOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = ((yyvsp[-2].node));
			((yyvsp[-2].node)) ->sister = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2670 "parser.tab.c"
    break;

  case 64: /* expr: TOKEN_ARITHMATICOP expr  */
#line 943 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ARITHMATICOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2686 "parser.tab.c"
    break;

  case 65: /* expr: TOKEN_LOGICOP expr  */
#line 955 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LOGICOP");
			child1->value = (yyvsp[-1].sval);
			
			((yyval.node))->child = child1;
			child1 ->sister = ((yyvsp[0].node));
		}
#line 2702 "parser.tab.c"
    break;

  case 66: /* expr: TOKEN_LP expr TOKEN_RP  */
#line 967 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			((yyval.node))->child = child1;
			child1->sister = ((yyvsp[-1].node));
			((yyvsp[-1].node))-> sister = child2;
		}
#line 2723 "parser.tab.c"
    break;

  case 67: /* callout_arg: expr  */
#line 986 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2735 "parser.tab.c"
    break;

  case 68: /* callout_arg: TOKEN_STRINGCONST  */
#line 994 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<callout_arg>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_STRINGCONST");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2750 "parser.tab.c"
    break;

  case 69: /* literal: int_literal  */
#line 1007 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<literal>");
			
			
			((yyval.node))->child = ((yyvsp[0].node));
		}
#line 2762 "parser.tab.c"
    break;

  case 70: /* literal: TOKEN_CHARCONST  */
#line 1015 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CHARCONST");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2777 "parser.tab.c"
    break;

  case 71: /* literal: TOKEN_BOOLEANCONST  */
#line 1026 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BOOLEANCONST");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2792 "parser.tab.c"
    break;

  case 72: /* int_literal: TOKEN_DECIMALCONST  */
#line 1040 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<int_literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_DECIMALCONST");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2807 "parser.tab.c"
    break;

  case 73: /* int_literal: TOKEN_HEXADECIMALCONST  */
#line 1051 "parser.y"
                {
			(yyval.node) = new Node();
			((yyval.node))->name = strdup("<int_literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_HEXADECIMALCONST");
			child1->value = (yyvsp[0].sval);
			
			((yyval.node))->child = child1;
		}
#line 2822 "parser.tab.c"
    break;


#line 2826 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1063 "parser.y"



int main(int argc,char* argv[]) {
	yyin = fopen("Input_Code.txt", "r");
	syntax_tree = fopen("Analyzer_Output (Syntax Tree).txt", "w");
	//yyout = fopen("Analyzer_Output.txt", "w");
	
	yyparse();

	if (atoi(argv[1]) == 0) {
		printf("Analyzer Output (print by Token_Value):\n");
	}
	else if (atoi(argv[1]) == 1) {
		printf("Analyzer Output (print by Token_Name):\n");
	}

	printtree(root,atoi(argv[1]),0);
	fprintf(syntax_tree, "\n");
	printf("\n");
	return 0;
}

int yyerror(const char* message) {
	printf("Analyzer Output :\n");
	printf("%s in line %d !!", message, line);
	exit(-1);
}

void printtree(struct Node* node, int printmode,int count) {
	int i;
	
	for(int i=0;i<count;i++) fprintf(syntax_tree, "\t");

	if(printmode==1) {
		fprintf(syntax_tree, "%s ", node->name);
		printf("%s ", node->name);
	}
	else {
		if(strstr(node->name,"TOKEN")) {
			fprintf(syntax_tree, "%s ", node->value);
			printf("%s ", node->value);
		}
		else {
			fprintf(syntax_tree, "%s ", node->name);
			printf("%s ", node->name);
		}
	}
	fprintf(syntax_tree, "\n");
	
	
	if(node->child!=NULL) printtree(node->child,printmode,count+1);
	if(node->sister!=NULL) printtree(node->sister,printmode,count);
	return;
	
}
