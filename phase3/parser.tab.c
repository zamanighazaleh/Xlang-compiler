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
	#include <stack>
	#include <sstream>
	

	using namespace std;


	extern FILE* yyin;
	extern FILE* yyout;
	extern int line;
	extern int yylex();

	
	FILE* ASM;

	int Error = 0;
	int count = 0, var_count = 0;
	int arg_count = 0, call_arg_count = 0;
	int Label = 0, Loop = 0, break_label, continue_label;

	char arg_t[4], var_type, expType = 'i';

	bool main_flag = false, call_flag = false, in_func = false, in_loop = false, see_return = false;

	string current_scope= "global";
	string here;
	string array_index, backup;
	

	vector <struct Variable*> variables;
  	vector <struct Function*> functions;
	vector <char*> var_list;

	stack <string> value_stack; 
	stack <char> type_stack;
	stack <int> scope_var_count;


	int yyerror(const char* message);

	struct Variable* search_variable (char* name, string scope);
  	void add_variable (char *name, string scope, string reg, char type, int range);

  	struct Function* search_function(char* name);
  	void add_function(char* name, char out_type, int args, char arg_type[4]);

  	string assign_register(char register_type);
  	void free_register(string reg);

	bool find_var (char* name);
  

	struct Variable {
		char* name;
		char type;
		string scope;
		string reg;
		int range;
  	};

  	struct Function {
		char* name;
		char out_type;
		int args;
		char* arg_type;
  	};


	/*Temporary Registers*/
	string t_registers[10] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
	bool t_registers_state[10] = {0};

	/*Saved Values Registers*/
	string s_registers[8] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};
	bool s_registers_state[8] = {0};

	/*Function Argument Registers*/
	string a_registers[4] = {"$a0", "$a1", "$a2", "$a3"};
	bool a_registers_state[4] = {0};

	/*Return Values Registers*/
	string v_registers[2] = {"$v0", "$v1"};

#line 164 "parser.tab.c"

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
  YYSYMBOL_TOKEN_IFCONDITION = 3,          /* TOKEN_IFCONDITION  */
  YYSYMBOL_TOKEN_ELSECONDITION = 4,        /* TOKEN_ELSECONDITION  */
  YYSYMBOL_TOKEN_LOOP = 5,                 /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_INTTYPE = 6,              /* TOKEN_INTTYPE  */
  YYSYMBOL_TOKEN_BOOLEANTYPE = 7,          /* TOKEN_BOOLEANTYPE  */
  YYSYMBOL_TOKEN_VOIDTYPE = 8,             /* TOKEN_VOIDTYPE  */
  YYSYMBOL_TOKEN_PROGRAMCLASS = 9,         /* TOKEN_PROGRAMCLASS  */
  YYSYMBOL_TOKEN_CLASS = 10,               /* TOKEN_CLASS  */
  YYSYMBOL_TOKEN_MAINFUNC = 11,            /* TOKEN_MAINFUNC  */
  YYSYMBOL_TOKEN_BREAKSTMT = 12,           /* TOKEN_BREAKSTMT  */
  YYSYMBOL_TOKEN_CONTINUESTMT = 13,        /* TOKEN_CONTINUESTMT  */
  YYSYMBOL_TOKEN_CALLOUT = 14,             /* TOKEN_CALLOUT  */
  YYSYMBOL_TOKEN_RETURN = 15,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_BOOLEANCONST = 16,        /* TOKEN_BOOLEANCONST  */
  YYSYMBOL_TOKEN_ARITHMATICOP_MUL = 17,    /* TOKEN_ARITHMATICOP_MUL  */
  YYSYMBOL_TOKEN_ARITHMATICOP_DIV = 18,    /* TOKEN_ARITHMATICOP_DIV  */
  YYSYMBOL_TOKEN_ARITHMATICOP = 19,        /* TOKEN_ARITHMATICOP  */
  YYSYMBOL_TOKEN_ARITHMATICOP_ADD = 20,    /* TOKEN_ARITHMATICOP_ADD  */
  YYSYMBOL_TOKEN_ARITHMATICOP_SUB = 21,    /* TOKEN_ARITHMATICOP_SUB  */
  YYSYMBOL_TOKEN_RELATIONOP = 22,          /* TOKEN_RELATIONOP  */
  YYSYMBOL_TOKEN_EQUALITYOP = 23,          /* TOKEN_EQUALITYOP  */
  YYSYMBOL_TOKEN_CONDITIONOP = 24,         /* TOKEN_CONDITIONOP  */
  YYSYMBOL_TOKEN_ASSIGNOP = 25,            /* TOKEN_ASSIGNOP  */
  YYSYMBOL_TOKEN_LOGICOP = 26,             /* TOKEN_LOGICOP  */
  YYSYMBOL_TOKEN_COMMA = 27,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SEMICOLON = 28,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_LCB = 29,                 /* TOKEN_LCB  */
  YYSYMBOL_TOKEN_RCB = 30,                 /* TOKEN_RCB  */
  YYSYMBOL_TOKEN_LP = 31,                  /* TOKEN_LP  */
  YYSYMBOL_TOKEN_RP = 32,                  /* TOKEN_RP  */
  YYSYMBOL_TOKEN_LB = 33,                  /* TOKEN_LB  */
  YYSYMBOL_TOKEN_RB = 34,                  /* TOKEN_RB  */
  YYSYMBOL_TOKEN_CHARCONST = 35,           /* TOKEN_CHARCONST  */
  YYSYMBOL_TOKEN_STRINGCONST = 36,         /* TOKEN_STRINGCONST  */
  YYSYMBOL_TOKEN_HEXADECIMALCONST = 37,    /* TOKEN_HEXADECIMALCONST  */
  YYSYMBOL_TOKEN_DECIMALCONST = 38,        /* TOKEN_DECIMALCONST  */
  YYSYMBOL_TOKEN_IDENTIFIER = 39,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_field_method = 43,              /* field_method  */
  YYSYMBOL_field_decl = 44,                /* field_decl  */
  YYSYMBOL_variable_star = 45,             /* variable_star  */
  YYSYMBOL_variable = 46,                  /* variable  */
  YYSYMBOL_method_decl_star = 47,          /* method_decl_star  */
  YYSYMBOL_method_decl = 48,               /* method_decl  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_id_main = 53,                   /* id_main  */
  YYSYMBOL_argument_plus_ = 54,            /* argument_plus_  */
  YYSYMBOL_argument_plus = 55,             /* argument_plus  */
  YYSYMBOL_argument = 56,                  /* argument  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_var_decl_star = 60,             /* var_decl_star  */
  YYSYMBOL_var_decl = 61,                  /* var_decl  */
  YYSYMBOL_id_plus = 62,                   /* id_plus  */
  YYSYMBOL_statement_star = 63,            /* statement_star  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_67_9 = 67,                      /* $@9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_else_block_ = 70,               /* else_block_  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_expr_ = 72,                     /* expr_  */
  YYSYMBOL_assign_op = 73,                 /* assign_op  */
  YYSYMBOL_method_call = 74,               /* method_call  */
  YYSYMBOL_75_13 = 75,                     /* $@13  */
  YYSYMBOL_76_14 = 76,                     /* $@14  */
  YYSYMBOL_expr_plus_ = 77,                /* expr_plus_  */
  YYSYMBOL_expr_plus = 78,                 /* expr_plus  */
  YYSYMBOL_callout_arg_plus_ = 79,         /* callout_arg_plus_  */
  YYSYMBOL_callout_arg_plus = 80,          /* callout_arg_plus  */
  YYSYMBOL_method_name = 81,               /* method_name  */
  YYSYMBOL_location = 82,                  /* location  */
  YYSYMBOL_expr = 83,                      /* expr  */
  YYSYMBOL_callout_arg = 84,               /* callout_arg  */
  YYSYMBOL_literal = 85,                   /* literal  */
  YYSYMBOL_int_literal = 86                /* int_literal  */
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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   157,   179,   180,   184,   188,   190,   194,
     208,   232,   234,   239,   253,   238,   286,   300,   285,   332,
     336,   345,   347,   351,   352,   356,   379,   386,   378,   400,
     402,   406,   410,   424,   441,   443,   447,   452,   461,   460,
     598,   603,   602,   620,   629,   619,   682,   712,   722,   731,
     736,   735,   755,   765,   767,   771,   779,   778,   828,   827,
     863,   865,   869,   874,   882,   884,   888,   893,   901,   908,
     926,   950,   980,   984,   988,  1027,  1066,  1107,  1151,  1199,
    1330,  1429,  1568,  1596,  1636,  1643,  1644,  1648,  1652,  1656,
    1674,  1683
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_IFCONDITION",
  "TOKEN_ELSECONDITION", "TOKEN_LOOP", "TOKEN_INTTYPE",
  "TOKEN_BOOLEANTYPE", "TOKEN_VOIDTYPE", "TOKEN_PROGRAMCLASS",
  "TOKEN_CLASS", "TOKEN_MAINFUNC", "TOKEN_BREAKSTMT", "TOKEN_CONTINUESTMT",
  "TOKEN_CALLOUT", "TOKEN_RETURN", "TOKEN_BOOLEANCONST",
  "TOKEN_ARITHMATICOP_MUL", "TOKEN_ARITHMATICOP_DIV", "TOKEN_ARITHMATICOP",
  "TOKEN_ARITHMATICOP_ADD", "TOKEN_ARITHMATICOP_SUB", "TOKEN_RELATIONOP",
  "TOKEN_EQUALITYOP", "TOKEN_CONDITIONOP", "TOKEN_ASSIGNOP",
  "TOKEN_LOGICOP", "TOKEN_COMMA", "TOKEN_SEMICOLON", "TOKEN_LCB",
  "TOKEN_RCB", "TOKEN_LP", "TOKEN_RP", "TOKEN_LB", "TOKEN_RB",
  "TOKEN_CHARCONST", "TOKEN_STRINGCONST", "TOKEN_HEXADECIMALCONST",
  "TOKEN_DECIMALCONST", "TOKEN_IDENTIFIER", "$accept", "program", "$@1",
  "field_method", "field_decl", "variable_star", "variable",
  "method_decl_star", "method_decl", "$@2", "$@3", "$@4", "$@5", "id_main",
  "argument_plus_", "argument_plus", "argument", "block", "$@6", "$@7",
  "var_decl_star", "var_decl", "id_plus", "statement_star", "type",
  "statement", "$@8", "$@9", "$@10", "$@11", "else_block_", "$@12",
  "expr_", "assign_op", "method_call", "$@13", "$@14", "expr_plus_",
  "expr_plus", "callout_arg_plus_", "callout_arg_plus", "method_name",
  "location", "expr", "callout_arg", "literal", "int_literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,     1,    18,     4,   -66,   -66,    20,   -66,   -66,    -5,
       7,    20,   -66,    20,    -3,   -66,   -66,    27,   -66,   -66,
     -66,    -5,    -1,    25,    30,   -66,   -14,    24,    37,   -66,
      36,   -66,   -66,    32,    31,    25,   -66,    36,    38,   -66,
      41,    34,   -66,   -66,    39,   -66,    36,   -66,   -66,    40,
     -66,    40,   -66,   -66,   -66,    36,   -66,    36,    47,     2,
     -66,    48,    50,    45,    53,    51,    59,    62,    75,    26,
     -66,    64,     2,    67,    66,    73,    47,   -66,    75,   -66,
     -66,   -66,    63,   -66,    75,    75,    75,   -66,    72,   -66,
     -66,   172,   -66,   -66,    75,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   106,    77,   -66,    21,   -66,   122,   -66,    75,
      75,    75,    75,    75,    75,    75,    75,    98,    75,    75,
     -66,    75,    76,   -66,   -66,   -66,   -66,    21,    21,   116,
     180,   130,   -66,    79,   -66,   150,   138,    40,   161,    46,
      99,   -66,    75,   -66,   100,    75,   -66,   -66,   172,    78,
     -66,   -66,   -66,   -66,   172,    46,    40,    40,   -66,   -66,
     -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,    12,    36,    37,     0,
       0,    12,     5,    12,     0,    20,    19,     0,     3,     4,
      11,     0,     9,     8,     0,    16,     0,     0,     0,    13,
      22,    91,    90,     0,     9,     8,     6,    22,     0,    21,
      24,     0,    10,     7,     0,    17,     0,    25,    14,     0,
      23,     0,    26,    18,    15,    30,    27,    30,     0,    35,
      29,    33,     0,     0,     0,     0,     0,     0,    54,    69,
      49,     0,    35,     0,     0,     0,     0,    31,     0,    43,
      47,    48,     0,    89,     0,     0,     0,    88,     0,    72,
      71,    53,    73,    87,     0,    28,    34,    40,    56,    55,
      38,    32,     0,     0,    58,    82,    83,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
      41,     0,    65,    84,    76,    77,    78,    74,    75,    79,
      80,    81,    70,     0,    60,    63,     0,     0,     0,     0,
       0,    57,     0,    39,    52,     0,    86,    64,    85,    67,
      59,    62,    50,    42,    44,     0,     0,     0,    66,    51,
      45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   152,   -66,    74,   137,   162,   -66,   -66,
     -66,   -66,   -66,   156,   139,   140,   -66,   -49,   -66,   -66,
     146,   -66,   111,   132,    -2,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -47,   -66,   -66,   -66,    65,   -66,
      54,   -66,   -37,   -65,   -66,   -66,   179
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,    10,    11,    28,    23,    12,    13,    37,
      51,    30,    49,    24,    38,    39,    40,    70,    55,    59,
      56,    57,    62,    71,    41,    72,   119,   137,   103,   157,
     153,   156,    88,   100,    89,   118,   122,   133,   134,   140,
     147,    74,    90,   135,   149,    92,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,     1,    54,    91,    14,    63,    15,    64,    15,    14,
       3,    21,    73,   102,    65,    66,    67,    68,     4,   105,
     106,   107,    75,    31,    32,    73,     7,     8,     9,   117,
     -19,    52,    26,     5,    16,    75,    22,    18,   109,   110,
     111,    69,     7,     8,   124,   125,   126,   127,   128,   129,
     130,   131,    27,    58,   136,    58,   138,   -68,    25,    94,
      67,    29,    83,    34,    26,    36,    42,    84,    46,    52,
      45,    48,    85,    47,   148,    76,    78,    86,    77,    80,
     154,    87,   146,    31,    32,    69,    61,    81,   144,    67,
     148,    83,    79,    82,    95,    97,    84,    98,    99,   104,
     108,    85,   121,   139,   152,   155,    86,   159,   160,    43,
      87,   141,    31,    32,    69,   109,   110,   111,   112,   113,
     114,   115,   116,   109,   110,   111,   112,   113,   114,   115,
     116,   150,   132,   109,   110,   111,   112,   113,   120,   109,
     110,   111,   112,   113,   114,   115,   116,   109,   110,   111,
     112,   113,   114,   115,   123,   109,   110,   111,   112,   113,
     114,   115,   116,    19,    35,    17,   143,   109,   110,   111,
     112,   113,   114,   115,   116,    20,    44,   142,   109,   110,
     111,   112,   113,   114,   115,   116,    50,   101,   145,   109,
     110,   111,   112,   113,   114,   115,   116,   109,   110,   111,
     112,   113,   114,    60,    96,    33,     0,   151,     0,   158
};

static const yytype_int16 yycheck[] =
{
      49,    10,    51,    68,     6,     3,    11,     5,    11,    11,
       9,    13,    59,    78,    12,    13,    14,    15,     0,    84,
      85,    86,    59,    37,    38,    72,     6,     7,     8,    94,
      31,    29,    33,    29,    39,    72,    39,    30,    17,    18,
      19,    39,     6,     7,   109,   110,   111,   112,   113,   114,
     115,   116,    27,    55,   119,    57,   121,    31,    31,    33,
      14,    31,    16,    39,    33,    28,    34,    21,    27,    29,
      32,    32,    26,    39,   139,    27,    31,    31,    28,    28,
     145,    35,    36,    37,    38,    39,    39,    28,   137,    14,
     155,    16,    39,    31,    30,    28,    21,    31,    25,    36,
      28,    26,    25,    27,     4,    27,    31,   156,   157,    35,
      35,    32,    37,    38,    39,    17,    18,    19,    20,    21,
      22,    23,    24,    17,    18,    19,    20,    21,    22,    23,
      24,    32,    34,    17,    18,    19,    20,    21,    32,    17,
      18,    19,    20,    21,    22,    23,    24,    17,    18,    19,
      20,    21,    22,    23,    32,    17,    18,    19,    20,    21,
      22,    23,    24,    11,    27,     9,    28,    17,    18,    19,
      20,    21,    22,    23,    24,    13,    37,    27,    17,    18,
      19,    20,    21,    22,    23,    24,    46,    76,    27,    17,
      18,    19,    20,    21,    22,    23,    24,    17,    18,    19,
      20,    21,    22,    57,    72,    26,    -1,   142,    -1,   155
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    41,     9,     0,    29,    42,     6,     7,     8,
      43,    44,    47,    48,    64,    11,    39,    53,    30,    43,
      47,    64,    39,    46,    53,    31,    33,    27,    45,    31,
      51,    37,    38,    86,    39,    46,    28,    49,    54,    55,
      56,    64,    34,    45,    54,    32,    27,    39,    32,    52,
      55,    50,    29,    57,    57,    58,    60,    61,    64,    59,
      60,    39,    62,     3,     5,    12,    13,    14,    15,    39,
      57,    63,    65,    74,    81,    82,    27,    28,    31,    39,
      28,    28,    31,    16,    21,    26,    31,    35,    72,    74,
      82,    83,    85,    86,    33,    30,    63,    28,    31,    25,
      73,    62,    83,    68,    36,    83,    83,    83,    28,    17,
      18,    19,    20,    21,    22,    23,    24,    83,    75,    66,
      32,    25,    76,    32,    83,    83,    83,    83,    83,    83,
      83,    83,    34,    77,    78,    83,    83,    67,    83,    27,
      79,    32,    27,    28,    57,    27,    36,    80,    83,    84,
      32,    78,     4,    70,    83,    27,    71,    69,    80,    57,
      57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    45,    45,    46,
      46,    47,    47,    49,    50,    48,    51,    52,    48,    53,
      53,    54,    54,    55,    55,    56,    58,    59,    57,    60,
      60,    61,    62,    62,    63,    63,    64,    64,    66,    65,
      65,    67,    65,    68,    69,    65,    65,    65,    65,    65,
      71,    70,    70,    72,    72,    73,    75,    74,    76,    74,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     1,     4,     3,     0,     1,
       4,     2,     0,     0,     0,     8,     0,     0,     8,     1,
       1,     1,     0,     3,     1,     2,     0,     0,     6,     2,
       0,     3,     3,     1,     2,     0,     1,     1,     0,     5,
       2,     0,     7,     0,     0,     9,     3,     2,     2,     1,
       0,     3,     0,     1,     0,     1,     0,     5,     0,     6,
       1,     0,     3,     1,     2,     0,     3,     1,     1,     1,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1
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
  case 2: /* $@1: %empty  */
#line 158 "parser.y"
                {
			scope_var_count.push(var_count);
			var_count = 0;
		}
#line 1758 "parser.tab.c"
    break;

  case 3: /* program: TOKEN_CLASS TOKEN_PROGRAMCLASS TOKEN_LCB $@1 field_method TOKEN_RCB  */
#line 163 "parser.y"
                {
			if (!main_flag) {
				yyerror("syntax error, the main function is not defined,");
			}

			for (int i = 0; i < var_count; i++)
				var_list.pop_back();
			
			var_count = scope_var_count.top();
			scope_var_count.pop();

			return 0;
		}
#line 1776 "parser.tab.c"
    break;

  case 8: /* variable_star: %empty  */
#line 190 "parser.y"
                {}
#line 1782 "parser.tab.c"
    break;

  case 9: /* variable: TOKEN_IDENTIFIER  */
#line 195 "parser.y"
                {
			if (find_var((yyvsp[0].sval)))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back((yyvsp[0].sval));
			var_count += 1;

			add_variable ((yyvsp[0].sval), current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable((yyvsp[0].sval),current_scope)->reg).c_str());
                
            fclose(ASM);
		}
#line 1800 "parser.tab.c"
    break;

  case 10: /* variable: TOKEN_IDENTIFIER TOKEN_LB int_literal TOKEN_RB  */
#line 209 "parser.y"
                {
			if (find_var((yyvsp[-3].sval)))
				yyerror("semantic error, array has been defined,");
			var_list.push_back((yyvsp[-3].sval));
			var_count += 1;

			if ((yyvsp[-1].ival) <= 0)
				yyerror("semantic error, wrong range array,");

			add_variable ((yyvsp[-3].sval), current_scope, assign_register('s'), var_type, (yyvsp[-1].ival));

            ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi $a0, $zero, %d\n", int((yyvsp[-1].ival)) * 4);
                
            fprintf(ASM,"\tli $v0, 9\n\tsyscall\n");
            fprintf(ASM,"\tmove %s, $v0\n", (search_variable((yyvsp[-3].sval),current_scope)->reg).c_str());
                
            fclose(ASM);
		}
#line 1825 "parser.tab.c"
    break;

  case 12: /* method_decl_star: %empty  */
#line 234 "parser.y"
                {}
#line 1831 "parser.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 239 "parser.y"
                {
			here=string((yyvsp[-1].sval));
        	ASM = fopen("Output.asm", "a+");
        	fprintf(ASM, "%s:\n",(yyvsp[-1].sval));
        	fclose(ASM);

			if (string((yyvsp[-1].sval)) != "main") {
				in_func = true;

				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
#line 1849 "parser.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 253 "parser.y"
                {
			current_scope= current_scope+ " " + string((yyvsp[-4].sval));
        	add_function((yyvsp[-4].sval), (yyvsp[-5].cval), arg_count, arg_t);
			
			arg_count = 0;
		}
#line 1860 "parser.tab.c"
    break;

  case 15: /* method_decl: type id_main TOKEN_LP $@2 argument_plus_ TOKEN_RP $@3 block  */
#line 260 "parser.y"
                {
			current_scope.erase(current_scope.size() - (string((yyvsp[-6].sval)).size() + 1), string((yyvsp[-6].sval)).size() + 1);

			if (string((yyvsp[-6].sval)) == "main") {
				ASM = fopen("Output.asm", "a+");
				fprintf(ASM,"\tli %s, 10\n\tsyscall\n", v_registers[0].c_str());
				fclose(ASM);
        	}
			else {
				
				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM,"\tjr $ra\n");
				fclose(ASM);
				here = "";

				free_register("$a0");
				free_register("$a1");
				free_register("$a2");
				free_register("$a3");
			}

			if (!see_return)
				yyerror("semantic error, wrong return,");
		}
#line 1890 "parser.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 286 "parser.y"
                {
			ASM = fopen("Output.asm", "a+");
        	fprintf(ASM, "%s:\n",(yyvsp[-1].sval));
        	fclose(ASM);
        	here=string((yyvsp[-1].sval));

			if (string((yyvsp[-1].sval)) != "main") {
				in_func = true;

				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
#line 1908 "parser.tab.c"
    break;

  case 17: /* $@5: %empty  */
#line 300 "parser.y"
                {
			current_scope= current_scope+ " " + string((yyvsp[-4].sval));
			add_function((yyvsp[-4].sval), 'v', arg_count, arg_t);

			arg_count = 0;
		}
#line 1919 "parser.tab.c"
    break;

  case 18: /* method_decl: TOKEN_VOIDTYPE id_main TOKEN_LP $@4 argument_plus_ TOKEN_RP $@5 block  */
#line 307 "parser.y"
                {
			current_scope.erase(current_scope.size() - (string((yyvsp[-6].sval)).size() + 1), string((yyvsp[-6].sval)).size() + 1);

        	if (string((yyvsp[-6].sval)) == "main") {
				ASM = fopen("Output.asm", "a+");
				fprintf(ASM,"\tli %s, 10\n\tsyscall\n", v_registers[0].c_str());
				fclose(ASM);
        	}
			else {
				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM,"\tjr $ra\n");
				fclose(ASM);
				here = "";

				free_register("$a0");
				free_register("$a1");
				free_register("$a2");
				free_register("$a3");

			}
		}
#line 1946 "parser.tab.c"
    break;

  case 19: /* id_main: TOKEN_IDENTIFIER  */
#line 333 "parser.y"
                {
			((yyval.sval)) = (yyvsp[0].sval);
		}
#line 1954 "parser.tab.c"
    break;

  case 20: /* id_main: TOKEN_MAINFUNC  */
#line 337 "parser.y"
                {
			main_flag = true;
			
			((yyval.sval)) = (char*)"main";
		}
#line 1964 "parser.tab.c"
    break;

  case 22: /* argument_plus_: %empty  */
#line 347 "parser.y"
                {}
#line 1970 "parser.tab.c"
    break;

  case 25: /* argument: type TOKEN_IDENTIFIER  */
#line 357 "parser.y"
                {
			arg_count += 1;
			if (arg_count > 4) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}
			
			if (main_flag) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}
			
			if (find_var((yyvsp[0].sval)))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back((yyvsp[0].sval));
			var_count += 1;
			
			add_variable ((yyvsp[0].sval), current_scope, assign_register('a'), (yyvsp[-1].cval), 0);
			arg_t[arg_count - 1] = (yyvsp[-1].cval);
		}
#line 1993 "parser.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 379 "parser.y"
                {
			if (!in_func) {
				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
#line 2004 "parser.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 386 "parser.y"
                {
			in_func = false;
		}
#line 2012 "parser.tab.c"
    break;

  case 28: /* block: TOKEN_LCB $@6 var_decl_star $@7 statement_star TOKEN_RCB  */
#line 390 "parser.y"
                {
			for (int i = 0; i < var_count; i++)
				var_list.pop_back();
			
			var_count = scope_var_count.top();
			scope_var_count.pop();
		}
#line 2024 "parser.tab.c"
    break;

  case 30: /* var_decl_star: %empty  */
#line 402 "parser.y"
                {}
#line 2030 "parser.tab.c"
    break;

  case 32: /* id_plus: TOKEN_IDENTIFIER TOKEN_COMMA id_plus  */
#line 411 "parser.y"
                {
			if (find_var((yyvsp[-2].sval)))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back((yyvsp[-2].sval));
			var_count += 1;

			add_variable ((yyvsp[-2].sval), current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable((yyvsp[-2].sval), current_scope)->reg).c_str());
                
            fclose(ASM);
		}
#line 2048 "parser.tab.c"
    break;

  case 33: /* id_plus: TOKEN_IDENTIFIER  */
#line 425 "parser.y"
                {
			if (find_var((yyvsp[0].sval)))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back((yyvsp[0].sval));
			var_count += 1;

			add_variable ((yyvsp[0].sval), current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable((yyvsp[0].sval),current_scope)->reg).c_str());
                
            fclose(ASM);
		}
#line 2066 "parser.tab.c"
    break;

  case 35: /* statement_star: %empty  */
#line 443 "parser.y"
                {}
#line 2072 "parser.tab.c"
    break;

  case 36: /* type: TOKEN_INTTYPE  */
#line 448 "parser.y"
                {
			((yyval.cval)) = 'i';
			var_type = 'i';
		}
#line 2081 "parser.tab.c"
    break;

  case 37: /* type: TOKEN_BOOLEANTYPE  */
#line 453 "parser.y"
                {
			((yyval.cval)) = 'b';
			var_type = 'b';
		}
#line 2090 "parser.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 461 "parser.y"
                {
			backup = array_index;
		}
#line 2098 "parser.tab.c"
    break;

  case 39: /* statement: location assign_op $@8 expr TOKEN_SEMICOLON  */
#line 465 "parser.y"
                {
			if (!find_var((yyvsp[-4].sval)))
				yyerror("semantic error, this variable has not been defined,");

			if (string((yyvsp[-3].sval)) == "=") {
				struct Variable* Rt = search_variable((yyvsp[-4].sval), current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				if (Rt->range == 0) {
					char t = type_stack.top();
					type_stack.pop();
					if (t != Rt->type)
						yyerror("semantic error, type of values used is not correct,");

					string Rs = value_stack.top();
					value_stack.pop();

					ASM = fopen("Output.asm", "a+");

					if(Rs[0] != '$')
						fprintf(ASM, "\taddi %s, $zero, %s \n", (Rt->reg).c_str(), Rs.c_str());
					else {
						fprintf(ASM, "\tmove %s, %s\n", (Rt->reg).c_str(), Rs.c_str());
						
						if(Rs[1] == 't')
							free_register(Rs);
					}

					fclose(ASM);
				}
				else {
					char t = type_stack.top();
					type_stack.pop();
					if (t != Rt->type)
						yyerror("semantic error, type of values used is not correct,");

					string Rs = value_stack.top();
					value_stack.pop();

					ASM = fopen("Output.asm", "a+");
					
              		string Rd1 = assign_register('t');
                    string Rd2 = assign_register('t');

              		if (backup[0] != '$' && Rs[0] != '$') {
              			fprintf(ASM, "\taddi %s, $zero , %s\n", Rd1.c_str(), Rs.c_str());
              			fprintf(ASM, "\tsw %s, %d(%s)\n", Rd1.c_str(), stoi(backup) * 4, Rt->reg.c_str() );
              		}
              		else if (backup[0] != '$') {
              			fprintf(ASM, "\tsw %s, %d(%s)\n", Rs.c_str(), stoi(backup) * 4, Rt->reg.c_str());

						if(Rs[1] == 't')
							free_register(Rs);
              		}
              		else if (Rs[0] != '$') {
              			fprintf(ASM, "\tsll %s, %s, 2\n", Rd1.c_str(), backup.c_str());
              			fprintf(ASM, "\tadd %s, %s, %s\n", Rd1.c_str(), Rd1.c_str(), Rt->reg.c_str());
              			fprintf(ASM, "\taddi %s, $zero, %s\n", Rd2.c_str(), Rs.c_str());
              			fprintf(ASM, "\tsw %s, 0(%s)\n", Rd2.c_str(), Rd1.c_str());

						if(backup[1] == 't')
							free_register(backup);
              		}
              		else{
              			fprintf(ASM, "\tsll %s, %s, 2\n", Rd1.c_str(), backup.c_str());
              			fprintf(ASM, "\tadd %s, %s, %s\n", Rd1.c_str(), Rd1.c_str(), Rt->reg.c_str());
              			fprintf(ASM, "\tsw %s, 0(%s)\n", Rs.c_str(), Rd1.c_str());

						if(Rs[1] == 't')
							free_register(Rs);
						if(backup[1] == 't')
							free_register(backup);
              		}
              				
					free_register(Rd1);
              		free_register(Rd2);
              		fclose(ASM);
				}
			}
			else if (string((yyvsp[-3].sval)) == "+=") {
				struct Variable* Rt = search_variable((yyvsp[-4].sval), current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				char t = type_stack.top();
				type_stack.pop();
				if (t != Rt->type)
					yyerror("semantic error, type of values used is not correct,");

				string Rs = value_stack.top();
				value_stack.pop();

				ASM = fopen("Output.asm", "a+");

				if(Rs[0] != '$')
					fprintf(ASM, "\taddi %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
				else {
					fprintf(ASM, "\tadd %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
					
					if(Rs[1] == 't')
						free_register(Rs);
				}

                fclose(ASM);
			}
			else if (string((yyvsp[-3].sval)) == "-=") {
				struct Variable* Rt = search_variable((yyvsp[-4].sval), current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				char t = type_stack.top();
				type_stack.pop();
				if (t != Rt->type)
					yyerror("semantic error, type of values used is not correct,");

				string Rs = value_stack.top();
				value_stack.pop();

				ASM = fopen("Output.asm", "a+");

				if(Rs[0] != '$')
					fprintf(ASM, "\taddi %s, %s, -%s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
				else {
					fprintf(ASM, "\tsub %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
					
					if(Rs[1] == 't')
						free_register(Rs);
				}

                fclose(ASM);
			} 
		}
#line 2236 "parser.tab.c"
    break;

  case 40: /* statement: method_call TOKEN_SEMICOLON  */
#line 599 "parser.y"
                {
			
		}
#line 2244 "parser.tab.c"
    break;

  case 41: /* $@9: %empty  */
#line 603 "parser.y"
                {
			current_scope = current_scope + " " + "if";

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'b')
				yyerror("semantic error, type of values used is not correct,");

            string Rd = value_stack.top();
            value_stack.pop();
            Label++;
            ASM = fopen("Output.asm", "a+");
        	fprintf(ASM,"\tbeq %s, $zero, L%d\n", Rd.c_str(), Label);
            fclose(ASM);
		}
#line 2264 "parser.tab.c"
    break;

  case 43: /* $@10: %empty  */
#line 620 "parser.y"
                {
			in_loop = true;

			current_scope = current_scope + " " + "loop";

			if (!find_var((yyvsp[0].sval)))
				yyerror("semantic error, this variable has not been defined,");
		}
#line 2277 "parser.tab.c"
    break;

  case 44: /* $@11: %empty  */
#line 629 "parser.y"
                {
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
	 		if(search_variable((yyvsp[-5].sval), current_scope) == NULL) yyerror("semantic error, this variable has not been defined,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\taddi %s,$zero,%s\n", (search_variable((yyvsp[-5].sval),current_scope)->reg).c_str(), Rs.c_str());
			
			Loop++;
			continue_label = Loop;
			fprintf(ASM,"LOOP%d:\n", Loop);

			string Rd = assign_register('t');
			fprintf(ASM,"\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
			fprintf(ASM,"\tslt %s,%s,%s\n", Rd.c_str(), (search_variable((yyvsp[-5].sval),current_scope)->reg).c_str(), Rd.c_str());
			fprintf(ASM,"\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
			Label++;
			break_label = Label;
	   		fprintf(ASM,"\tbeq %s,$zero,L%d\n", Rd.c_str(), Label);
		 
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
         
		}
#line 2316 "parser.tab.c"
    break;

  case 45: /* statement: TOKEN_LOOP TOKEN_IDENTIFIER $@10 TOKEN_ASSIGNOP expr TOKEN_COMMA expr $@11 block  */
#line 664 "parser.y"
                {
			current_scope.erase(current_scope.size()-(string("loop").size()+1),string("loop").size()+1);
			
			ASM = fopen("Output.asm", "a+");
			
			type_stack.pop();

			string Rd = value_stack.top();
			value_stack.pop();
			//search for loop-counter in symbol-table
			fprintf(ASM,"\taddi %s,%s,1\n", Rd.c_str(), (search_variable((yyvsp[-7].sval),current_scope)->reg).c_str());
			fprintf(ASM,"\tmove %s,%s\n", (search_variable((yyvsp[-7].sval),current_scope)->reg).c_str(), Rd.c_str());
			fprintf(ASM,"\tj LOOP%d\n", Loop);
	  	    fprintf(ASM,"L%d:\n", Label);
			fclose(ASM);

			in_loop = false;
		}
#line 2339 "parser.tab.c"
    break;

  case 46: /* statement: TOKEN_RETURN expr_ TOKEN_SEMICOLON  */
#line 683 "parser.y"
                {
			if (search_function(strdup(here.c_str()))->out_type == 'v')
				yyerror("semantic error, wrong return,");
	
			char t = type_stack.top();
			type_stack.pop();
			if (t != search_function(strdup(here.c_str()))->out_type)
				yyerror("semantic error, type of values used is not correct,");

			string Rs=value_stack.top();
            value_stack.pop();
            // if(search_function(strdup(here.c_str()))->out_type!=expType) yyerror("semantic error, wrong return type,");

            string Rv = "$v0";


            ASM = fopen("Output.asm", "a+");

            if(Rs[0]!='$')
            	fprintf(ASM, "\taddi %s, $zero, %s \n",Rv.c_str() , Rs.c_str());
            else{
                fprintf(ASM, "\tmove %s, %s \n",Rv.c_str(), Rs.c_str());
                if(Rs[1] == 't')
                free_register(Rs);
            }
            fclose(ASM);

			see_return = true;
		}
#line 2373 "parser.tab.c"
    break;

  case 47: /* statement: TOKEN_BREAKSTMT TOKEN_SEMICOLON  */
#line 713 "parser.y"
                {
			if (!in_loop)
				yyerror("semantic error, wrong break,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj L%d\n", break_label);
			fclose(ASM);
	  	    
		}
#line 2387 "parser.tab.c"
    break;

  case 48: /* statement: TOKEN_CONTINUESTMT TOKEN_SEMICOLON  */
#line 723 "parser.y"
                {
			if (!in_loop)
				yyerror("semantic error, wrong continue,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj Loop%d\n", continue_label);
			fclose(ASM);
		}
#line 2400 "parser.tab.c"
    break;

  case 50: /* $@12: %empty  */
#line 736 "parser.y"
                {
			current_scope.erase(current_scope.size()-(string("if").size()+1),string("if").size()+1);
			current_scope=current_scope+" "+"else";
			
			Label++;
			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj L%d\n", Label);
			fprintf(ASM,"L%d:\n", Label-1);
			fclose(ASM);
        }
#line 2415 "parser.tab.c"
    break;

  case 51: /* else_block_: TOKEN_ELSECONDITION $@12 block  */
#line 747 "parser.y"
                {
			current_scope.erase(current_scope.size()-(string("else").size()+1),string("else").size()+1);
			
			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"L%d : \n", Label);
			fclose(ASM);
		}
#line 2427 "parser.tab.c"
    break;

  case 52: /* else_block_: %empty  */
#line 755 "parser.y"
                {
			ASM = fopen("Output.asm", "a+");
          	fprintf(ASM,"L%d:\n", Label);
          	fclose(ASM);
			
			current_scope.erase(current_scope.size()-(string("if").size()+1),string("if").size()+1);
		}
#line 2439 "parser.tab.c"
    break;

  case 54: /* expr_: %empty  */
#line 767 "parser.y"
                {}
#line 2445 "parser.tab.c"
    break;

  case 55: /* assign_op: TOKEN_ASSIGNOP  */
#line 772 "parser.y"
                {
			((yyval.sval)) = (yyvsp[0].sval);
		}
#line 2453 "parser.tab.c"
    break;

  case 56: /* $@13: %empty  */
#line 779 "parser.y"
                {
			call_flag = true;
		}
#line 2461 "parser.tab.c"
    break;

  case 57: /* method_call: method_name TOKEN_LP $@13 expr_plus_ TOKEN_RP  */
#line 783 "parser.y"
                {
			struct Function* func = search_function((yyvsp[-4].sval));
			if (func == NULL) 
				yyerror("semantic error, this function has not been defined,");
			else {
				if(func->args != call_arg_count) 
					yyerror("semantic error, the number of arguments does not match,");
				else {
					ASM = fopen("Output.asm", "a+");

					string arguments[4];
					for (int i = call_arg_count - 1; i >= 0; i--) {
						char t = type_stack.top();
						type_stack.pop();
						if (t != func->arg_type[i])
							yyerror("semantic error, type of values used is not correct,");

						arguments[i] = value_stack.top();
						value_stack.pop();
					}

					for (int i = 0; i < call_arg_count; i++) {
						if(arguments[i][0] != '$')
							fprintf(ASM, "\taddi $a%d,$zero,%s\n", i, arguments[i].c_str());
						else
							fprintf(ASM, "\tmove $a%d,%s\n", i, arguments[i].c_str());
					}
					fprintf(ASM,"\tjal %s\n", (yyvsp[-4].sval));
					
					fclose(ASM);

					if (func->out_type == 'i' || func->out_type == 'b') {
						value_stack.push("$v0");
						if (func->out_type == 'i')
							type_stack.push('i');
						else if (func->out_type == 'b')
							type_stack.push('b');
					}
				}
			}

			call_flag = false;
			call_arg_count = 0;
		}
#line 2510 "parser.tab.c"
    break;

  case 58: /* $@14: %empty  */
#line 828 "parser.y"
                {
			call_flag = true;
		}
#line 2518 "parser.tab.c"
    break;

  case 59: /* method_call: TOKEN_CALLOUT TOKEN_LP TOKEN_STRINGCONST $@14 callout_arg_plus_ TOKEN_RP  */
#line 832 "parser.y"
                {
			if(call_arg_count > 4) 
				yyerror("semantic error, the number of arguments does not match,");
			else {
				ASM = fopen("Output.asm", "a+");

				string arguments[4];
				for (int i = call_arg_count - 1; i >= 0; i--) {
					type_stack.pop();

					arguments[i] = value_stack.top();
					value_stack.pop();
				}

				for (int i = 0; i < call_arg_count; i++) {
					if(arguments[i][0] != '$')
						fprintf(ASM, "\taddi $a%d,$zero,%s\n", i, arguments[i].c_str());
					else
						fprintf(ASM, "\tmove $a%d,%s\n", i, arguments[i].c_str());
				}
				fprintf(ASM,"\tcall %s\n", (yyvsp[-3].sval));
					
				fclose(ASM);
			}

			call_flag = false;
			call_arg_count = 0;
		}
#line 2551 "parser.tab.c"
    break;

  case 61: /* expr_plus_: %empty  */
#line 865 "parser.y"
                {}
#line 2557 "parser.tab.c"
    break;

  case 62: /* expr_plus: expr TOKEN_COMMA expr_plus  */
#line 870 "parser.y"
                {
			if (call_flag)
				call_arg_count += 1;
		}
#line 2566 "parser.tab.c"
    break;

  case 63: /* expr_plus: expr  */
#line 875 "parser.y"
                {
			if (call_flag)
				call_arg_count += 1;
		}
#line 2575 "parser.tab.c"
    break;

  case 65: /* callout_arg_plus_: %empty  */
#line 884 "parser.y"
                {}
#line 2581 "parser.tab.c"
    break;

  case 66: /* callout_arg_plus: callout_arg TOKEN_COMMA callout_arg_plus  */
#line 889 "parser.y"
                {
			if (call_flag)
				call_arg_count += 1;
		}
#line 2590 "parser.tab.c"
    break;

  case 67: /* callout_arg_plus: callout_arg  */
#line 894 "parser.y"
                {
			if (call_flag)
				call_arg_count += 1;
		}
#line 2599 "parser.tab.c"
    break;

  case 68: /* method_name: TOKEN_IDENTIFIER  */
#line 902 "parser.y"
                {
			((yyval.sval)) = (yyvsp[0].sval);
		}
#line 2607 "parser.tab.c"
    break;

  case 69: /* location: TOKEN_IDENTIFIER  */
#line 909 "parser.y"
                {
			((yyval.sval)) = (yyvsp[0].sval);
			
			if (!find_var((yyvsp[0].sval)))
				yyerror("semantic error, this variable has not been defined,");

			struct Variable* Rs = search_variable((yyvsp[0].sval), current_scope);
			
			if(Rs != NULL);
			else {
				yyerror("semantic error, this variable has not been defined,");
			}
			
			value_stack.push(Rs->reg);
			type_stack.push(Rs->type);
			expType = Rs->type;
		}
#line 2629 "parser.tab.c"
    break;

  case 70: /* location: TOKEN_IDENTIFIER TOKEN_LB expr TOKEN_RB  */
#line 927 "parser.y"
                {
			((yyval.sval)) = (yyvsp[-3].sval);

			if (!find_var((yyvsp[-3].sval)))
				yyerror("semantic error, this array has not been defined,");
			if (search_variable((yyvsp[-3].sval),current_scope)->range == 0)
				yyerror("semantic error, this array has not been defined,");

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'i')
				yyerror("semantic error, type of values used is not correct,");

			if (0 > (yyvsp[-1].ival) || (yyvsp[-1].ival) >= search_variable((yyvsp[-3].sval),current_scope)->range)
				yyerror("semantic error, wrong range array,");
			
			string Rs = value_stack.top();
        	value_stack.pop();
			array_index = Rs;
		}
#line 2654 "parser.tab.c"
    break;

  case 71: /* expr: location  */
#line 951 "parser.y"
                {
			((yyval.ival)) = 1;
			
			struct Variable* Rt=search_variable((yyvsp[0].sval),current_scope);//search $1 in lookup table and assign int to variable Struct Symbol *Rt
			if (Rt->range != 0) {
				string Rd = assign_register('t');
				
				ASM = fopen("Output.asm", "a+");

				if(array_index[0]!='$') {
					fprintf(ASM,"\tlw %s,%d(%s)\n", Rd.c_str(), stoi(array_index)*4, (Rt->reg).c_str());
				}
				else {
					fprintf(ASM,"\tsll %s,%s,2\n", Rd.c_str(), array_index.c_str());
					fprintf(ASM,"\tadd %s,%s,%s\n", Rd.c_str(), Rd.c_str(), (Rt->reg).c_str());
					fprintf(ASM,"\tlw %s,0(%s)\n", Rd.c_str(), Rd.c_str());

					if(array_index[1] == 't')
						free_register(array_index);
				}

				fclose(ASM);
				value_stack.push(Rd);
				if (Rt->type == 'i')
					type_stack.push('i');
				else if (Rt->type == 'b')
					type_stack.push('b');
			}
		}
#line 2688 "parser.tab.c"
    break;

  case 72: /* expr: method_call  */
#line 981 "parser.y"
                {
			((yyval.ival)) = 2;
		}
#line 2696 "parser.tab.c"
    break;

  case 73: /* expr: literal  */
#line 985 "parser.y"
                {
			((yyval.ival)) = (yyvsp[0].ival);
		}
#line 2704 "parser.tab.c"
    break;

  case 74: /* expr: expr TOKEN_ARITHMATICOP_ADD expr  */
#line 989 "parser.y"
                {
			ASM = fopen("Output.asm", "a+");

			((yyval.ival))= (yyvsp[-2].ival) + (yyvsp[0].ival);

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			//cout<<Rt<<endl;
			string Rs = value_stack.top();
			value_stack.pop();
			//cout<<Rt<<endl;
			string Rd = assign_register('t');

			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) + stoi(Rt));
			else if(Rs[0] != '$')
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
			else if(Rt[0] != '$')
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			else
				fprintf(ASM, "\tadd %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			
			if(Rs[1] == 't')
						free_register(Rs);
			if(Rt[1] == 't')
						free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
		}
#line 2747 "parser.tab.c"
    break;

  case 75: /* expr: expr TOKEN_ARITHMATICOP_SUB expr  */
#line 1028 "parser.y"
                {
			ASM = fopen("Output.asm", "a+");

			((yyval.ival)) = (yyvsp[-2].ival) - (yyvsp[0].ival);

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
			string Rd = assign_register('t');

			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) - stoi(Rt));
			else if(Rs[0] != '$') {
				fprintf(ASM, "\tsub %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rs.c_str());
			}
			else if(Rt[0] != '$')
				fprintf(ASM, "\taddi %s,%s,-%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			else
				fprintf(ASM, "\tsub %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());

			if(Rs[1] == 't')
				free_register(Rs);
			if(Rt[1] == 't')
				free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
		}
#line 2790 "parser.tab.c"
    break;

  case 76: /* expr: expr TOKEN_ARITHMATICOP_MUL expr  */
#line 1067 "parser.y"
                {
			ASM = fopen("Output.asm", "a+");

			((yyval.ival)) = (yyvsp[-2].ival) * (yyvsp[0].ival);

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");
				
			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
			string Rd = assign_register('t');
				
			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) * stoi(Rt));
			else if(Rs[0] != '$') {
				fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
			}
			else if(Rt[0] != '$') {
				fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			}
			else
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			
			if(Rs[1] == 't')
				free_register(Rs);
			if(Rt[1] == 't')
				free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);	
			type_stack.push('i');
		}
#line 2835 "parser.tab.c"
    break;

  case 77: /* expr: expr TOKEN_ARITHMATICOP_DIV expr  */
#line 1108 "parser.y"
                {
			if ((yyvsp[0].ival) == 0)
				yyerror("semantic error, divide by zero,");

        	ASM = fopen("Output.asm", "a+");
        
			((yyval.ival))= (yyvsp[-2].ival) / (yyvsp[0].ival);
  			
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
        	value_stack.pop();
  			string Rs = value_stack.top();
        	value_stack.pop();
        	string Rd = assign_register('t');
  			
			if(Rs[0] != '$' && Rt[0] != '$')
  				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) / stoi(Rt));
  			else if(Rs[0] != '$') {
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
        	}
        	else if(Rt[0] != '$'){
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rd.c_str());
        	}
  			else
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());

        	if(Rs[1] == 't')
  				free_register(Rs);
  			if(Rt[1] == 't')
  				free_register(Rt);
  			
			fclose(ASM);
  			value_stack.push(Rd);
			type_stack.push('i');
		}
#line 2883 "parser.tab.c"
    break;

  case 78: /* expr: expr TOKEN_ARITHMATICOP expr  */
#line 1152 "parser.y"
                {
			if((yyvsp[0].ival) == 0)
				yyerror("semantic error, divide by zero,");

        	ASM = fopen("Output.asm", "a+");
        
			((yyval.ival))= (yyvsp[-2].ival) % (yyvsp[0].ival);
  			
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
        	value_stack.pop();
  			string Rs = value_stack.top();
        	value_stack.pop();
        	string Rd = assign_register('t');
  			
			if(Rs[0] != '$' && Rt[0] != '$')
  				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) % stoi(Rt));
  			else if(Rs[0] != '$') {
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
          		fprintf(ASM, "\tdiv %s,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
        	}
        	else if(Rt[0] != '$'){
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
          		fprintf(ASM, "\tdiv %s,%s\n", Rs.c_str(), Rd.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
        	}
  			else {
          		fprintf(ASM, "\tdiv %s,%s\n", Rs.c_str(), Rt.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
			}

        	if(Rs[1] == 't')
  				free_register(Rs);
  			if(Rt[1] == 't')
  				free_register(Rt);
  			
			fclose(ASM);
  			value_stack.push(Rd);
			type_stack.push('i');
		}
#line 2935 "parser.tab.c"
    break;

  case 79: /* expr: expr TOKEN_RELATIONOP expr  */
#line 1200 "parser.y"
                {
        	ASM = fopen("Output.asm", "a+");

			if (string((yyvsp[-1].sval)) == "<") {
				((yyval.ival)) = (yyvsp[-2].ival) < (yyvsp[0].ival) ? 1 : 0;
  			
			  	char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) < stoi(Rt));
  				else if(Rs[0] != '$') {
  					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
  				}
  				else if(Rt[0] != '$')
  					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				type_stack.push('b');
			}
			else if (string((yyvsp[-1].sval)) == "<=") {
				((yyval.ival)) = (yyvsp[-2].ival) <= (yyvsp[0].ival) ? 1 : 0;
  			
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

			  	string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) <= stoi(Rt));
  				else if(Rs[0] != '$') {
  					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
  				}
  				else if(Rt[0] != '$')
  					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
        		fprintf(ASM, "\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				type_stack.push('b');
			}
			else if (string((yyvsp[-1].sval)) == ">") {
				((yyval.ival)) = (yyvsp[-2].ival) > (yyvsp[0].ival) ? 1 : 0;
  			
			  	char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

			  	string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) > stoi(Rt));
  				else if(Rs[0] != '$')
          			fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
  				else if(Rt[0] != '$') {
          			fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rs.c_str());
        		}
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				  type_stack.push('b');
			}
			else if (string((yyvsp[-1].sval)) == ">=") {
				((yyval.ival)) = (yyvsp[-2].ival) >= (yyvsp[0].ival) ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) >= stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
				}
				else if(Rt[0] != '$')
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
				else
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
				fprintf(ASM, "\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
				
				fclose(ASM);
				value_stack.push(Rd);
				type_stack.push('b');
			}
		}
#line 3070 "parser.tab.c"
    break;

  case 80: /* expr: expr TOKEN_EQUALITYOP expr  */
#line 1331 "parser.y"
                {
        	ASM = fopen("Output.asm", "a+");
			
			if (string((yyvsp[-1].sval)) == "!=") {
				((yyval.ival)) = (yyvsp[-2].ival) != (yyvsp[0].ival) ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) != stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rt.c_str());
					fprintf(ASM," \tslti %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM," \tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else {
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM," \tslt %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM," \tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);

				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
			else if (string((yyvsp[-1].sval)) == "==") {
				((yyval.ival)) = (yyvsp[-2].ival) == (yyvsp[0].ival) ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) == stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else {
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);

				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
#line 3173 "parser.tab.c"
    break;

  case 81: /* expr: expr TOKEN_CONDITIONOP expr  */
#line 1430 "parser.y"
                {
        	ASM = fopen("Output.asm", "a+");
			
			if (string((yyvsp[-1].sval)) == "&&") {
				((yyval.ival)) = (yyvsp[-2].ival) && (yyvsp[0].ival) ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) && stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero %s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$ero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero,L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n",Label);
				}
				else {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero \n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd1.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero,L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);
				
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
			else if (string((yyvsp[-1].sval)) == "||") {
				((yyval.ival)) = (yyvsp[-2].ival) || (yyvsp[0].ival) ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");
				
				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) || stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n", Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero %s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$ero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n",Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s,L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n",Label);
				}
				else {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero \n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n", Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s,L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);
				
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
#line 3316 "parser.tab.c"
    break;

  case 82: /* expr: TOKEN_ARITHMATICOP_SUB expr  */
#line 1569 "parser.y"
                {
			((yyval.ival)) = -(yyvsp[0].ival);
  			
			char t = type_stack.top();
			type_stack.pop();
			if (t != 'i')
				yyerror("semantic error, type of values used is not correct,");
			
			string Rs = value_stack.top();
			value_stack.pop();
			
			if(Rs[0] != '$') {
				value_stack.push("-" + to_string((yyvsp[0].ival)));
				type_stack.push('i');
			}
			else {
				string Rd = assign_register('t');

				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM, "\tsub %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
				
				fclose(ASM);
				value_stack.push(Rd);
				type_stack.push('i');
			}
		}
#line 3348 "parser.tab.c"
    break;

  case 83: /* expr: TOKEN_LOGICOP expr  */
#line 1597 "parser.y"
                {
			((yyval.ival)) = !(yyvsp[0].ival);

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'b')
				yyerror("semantic error, type of values used is not correct,");
	
			string Rs = value_stack.top();
			value_stack.pop();
			
			if(Rs[0] != '$'){
					if(Rs[0] != '$' == 0)
						value_stack.push("1");
					else
						value_stack.push("0");
					
					type_stack.push('b');
			}
			else {
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');

				ASM = fopen("Output.asm", "a+");
					
				fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
				fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
				fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				fprintf(ASM, "\txori %s,%s,1\n", Rd1.c_str(), Rd1.c_str());
				
				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
			
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
#line 3392 "parser.tab.c"
    break;

  case 84: /* expr: TOKEN_LP expr TOKEN_RP  */
#line 1637 "parser.y"
                {
        	((yyval.ival)) = (yyvsp[-1].ival);
		}
#line 3400 "parser.tab.c"
    break;

  case 87: /* literal: int_literal  */
#line 1649 "parser.y"
                {
			((yyval.ival)) = (yyvsp[0].ival);
		}
#line 3408 "parser.tab.c"
    break;

  case 88: /* literal: TOKEN_CHARCONST  */
#line 1653 "parser.y"
                {

		}
#line 3416 "parser.tab.c"
    break;

  case 89: /* literal: TOKEN_BOOLEANCONST  */
#line 1657 "parser.y"
                {
			int tmp;
			if (string((yyvsp[0].sval)) == "true")
				tmp = 1;
			else if (string((yyvsp[0].sval)) == "false")
				tmp = 0;

			((yyval.ival)) = tmp;

			value_stack.push(to_string(tmp));
			type_stack.push('b');
			
			expType = 'b';
		}
#line 3435 "parser.tab.c"
    break;

  case 90: /* int_literal: TOKEN_DECIMALCONST  */
#line 1675 "parser.y"
                {
			((yyval.ival)) = (yyvsp[0].ival);

			value_stack.push(to_string((yyvsp[0].ival)));
			type_stack.push('i');
			
			expType = 'i';
		}
#line 3448 "parser.tab.c"
    break;

  case 91: /* int_literal: TOKEN_HEXADECIMALCONST  */
#line 1684 "parser.y"
                {
			unsigned int w;
			std::istringstream iss((yyvsp[0].sval));
			iss >> std::hex >> w;

			((yyval.ival)) = w;

			value_stack.push(to_string(w));
			type_stack.push('i');

			expType = 'i';
		}
#line 3465 "parser.tab.c"
    break;


#line 3469 "parser.tab.c"

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

#line 1698 "parser.y"



int main(int argc, char* argv[]) {
	yyin = fopen("Input_Code.txt", "r");
	if (yyin == 0) {
		cout << "Unable to open the file !!!" << endl;
    	return 0;
	}

  	ASM = fopen("Output.asm", "w");
	if (ASM == 0) {
    	cout << "Unable to create the output file !!!" << endl;
    	return 0;
	}
	else {
		fprintf(ASM, ".globl main\n");
		fclose(ASM);
	}

  	yyparse();

  	if (Error) {
    	fclose(ASM);
    	remove("Output.asm");
    	return 0;
  	}
	
	return 0;
}

int yyerror (const char* message) {
	printf("%s in line %d !!\n", message, line);
	Error++;
	exit(-1);
}

void add_variable (char* name, string scope, string reg, char type, int range) {
	struct Variable *ns = new Variable();
	ns->name = name;
	ns->scope = scope;
	ns->reg = reg;
	ns->type = type;
	ns->range = range;
	variables.push_back(ns);
}

struct Variable* search_variable (char* name, string scope) {
	for(int i = 0; i < variables.size(); i++) {
		if (strcmp(name, variables[i]->name) == 0 && scope == variables[i]->scope) {
			return variables[i];
		}
	}
	int m = scope.find_last_of(" ");
	while (m != -1) {
		string newscope = scope.substr(0, m);
		for (int i = 0; i < variables.size(); i++) {
      		if (strcmp(name, variables[i]->name) == 0 && newscope == variables[i]->scope) {
        		return variables[i];
      		}
    	}
    	m = newscope.find_last_of(" ");
  	}
  	return NULL;
}

struct Function* search_function (char* name) {
	for(int i = 0; i < functions.size(); i++)
		if(strcmp(name, functions[i]->name) == 0)
			return functions[i];
	return NULL;
}

void add_function (char* name, char out_type, int args, char arg_type[4]) {
	struct Function* nf = new Function();
	nf->name = name;
	nf->out_type = out_type;
	nf->args = args;
	nf->arg_type = arg_type;
	functions.push_back(nf);
}

string assign_register (char register_type) {
  	// register_type : 't','s','a'
  	switch (register_type) {
		case 't':
			for (int i = 0; i <= 9; i++)
				if (t_registers_state[i] == 0)
					{t_registers_state[i] = 1; return "$t" + to_string(i);}
			break;
		case 's':
			for (int i = 0; i <= 7; i++)
				if (s_registers_state[i] == 0)
					{s_registers_state[i] = 1; return "$s" + to_string(i);}
			break;
		case 'a':
			for (int i = 0; i <= 3; i++)
				if (a_registers_state[i] == 0)
					{a_registers_state[i] = 1; return "$a" + to_string(i);}
			break;
	}
	return "$";
}

void free_register(string reg) {
	// reg ~ '$t0'
	switch (reg[1]) {
		case 't':
			t_registers_state[reg[2] - '0'] = 0;
			break;
		case 's':
			s_registers_state[reg[2] - '0'] = 0;
			break;
		case 'a':
			a_registers_state[reg[2] - '0'] = 0;
			break;
	}
}

bool find_var(char* name) {
	for (int i = 0; i < var_list.size(); i++) {
		if (string(var_list[i]) == string(name))
			return true;
	}
	return false;
}
