/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include "ast.h"

	// stuff from flex that bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;

	extern Program *program_pointer;

	void yyerror(char const *s);

#line 80 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    CHAR = 259,
    CONSTANT = 260,
    DATATYPE = 261,
    IF_K = 262,
    ELSE_K = 263,
    WHILE_K = 264,
    FOR_K = 265,
    RETURN_K = 266,
    BREAK_K = 267,
    CONTINUE_K = 268,
    INPUT_K = 269,
    OUTPUT_K = 270,
    SEMICOLON = 271,
    COMMA = 272,
    OP_MUL = 273,
    BIN_OP_MUL = 274,
    BIN_OP_ADD = 275,
    BIN_OP_SHIFT = 276,
    BIN_OP_REL = 277,
    BIN_OP_EQ = 278,
    BIN_OP_ASSIGN = 279,
    BIN_OP_BAND = 280,
    BIN_OP_BOR = 281,
    BIN_OP_BXOR = 282,
    BIN_OP_LAND = 283,
    BIN_OP_LOR = 284,
    UN_OP = 285,
    QUESTION = 286,
    COLON = 287,
    OPEN_BRACKET = 288,
    CLOSE_BRACKET = 289,
    OPEN_SQUARE = 290,
    CLOSE_SQUARE = 291,
    OPEN_CURLY = 292,
    CLOSE_CURLY = 293,
    IDENTIFIER = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:355  */

	int   ival;
	float fval;
	char  *sval;
	char  cval;

	Program *program;
	Expression *expression;
	std::vector<Expression *> *expression_vector;
	FunctionCall *functionCall;
	Declaration *declaration;
	std::vector<Declaration *> *declaration_vector;
	Statement *statement;
	std::vector<Statement *> *statement_vector;
	WhileStatement *whileStatement;
	ForStatement *forStatement;
	IfElseStatement *ifElseStatement;
	FunctionDefinition *functionDefinition;

	StringLit *stringlit;
	Identifier *identifier;
	Block *block;

#line 184 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   114,   117,   118,   119,   122,   123,   126,
     127,   128,   129,   132,   133,   137,   138,   142,   143,   144,
     145,   146,   150,   151,   152,   156,   157,   161,   162,   166,
     167,   171,   172,   176,   177,   181,   182,   186,   187,   191,
     192,   196,   197,   201,   202,   206,   207,   210,   213,   214,
     217,   218,   219,   220,   224,   225,   228,   229,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   244,   245,
     249,   252,   255,   256,   257,   258,   259,   260,   261,   262,
     265,   266,   269,   270,   273,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "CHAR", "CONSTANT", "DATATYPE",
  "IF_K", "ELSE_K", "WHILE_K", "FOR_K", "RETURN_K", "BREAK_K",
  "CONTINUE_K", "INPUT_K", "OUTPUT_K", "SEMICOLON", "COMMA", "OP_MUL",
  "BIN_OP_MUL", "BIN_OP_ADD", "BIN_OP_SHIFT", "BIN_OP_REL", "BIN_OP_EQ",
  "BIN_OP_ASSIGN", "BIN_OP_BAND", "BIN_OP_BOR", "BIN_OP_BXOR",
  "BIN_OP_LAND", "BIN_OP_LOR", "UN_OP", "QUESTION", "COLON",
  "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_SQUARE", "CLOSE_SQUARE",
  "OPEN_CURLY", "CLOSE_CURLY", "IDENTIFIER", "$accept", "program",
  "literal", "arrayAccessList", "term", "arrayAccessTerm", "prec0",
  "prec1", "prec2", "prec3", "prec4", "prec5", "prec6", "prec7", "prec8",
  "prec9", "prec10", "prec11", "prec12", "prec13", "expression",
  "commaSeparatedExpressions", "functionCall", "declaration",
  "commaSeparatedDeclarations", "statement", "statements", "block",
  "whileStatement", "forStatement", "ifElseStatement",
  "functionIdentifier", "functionDefinition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,   -13,    15,   -97,   -13,   -97,   -27,   -97,   -97,   -97,
      -2,   -13,    21,   -97,   -10,    29,    63,   -97,    65,    21,
     351,    45,   -97,   -97,   -97,    54,    57,    58,   142,    66,
      76,    61,    62,   -97,   351,     8,     8,     8,   351,    64,
     -97,    29,    71,   -97,   -97,     0,    83,    84,    82,    85,
      81,    80,    91,    90,    17,    97,   -97,   106,   -97,    44,
     -97,    24,   -97,   -97,   -97,   -97,   -97,    88,   351,   351,
     351,   173,   -97,   115,   -97,   -97,     8,   351,   -97,   -97,
     -97,   -97,   102,    95,    45,   -97,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   -97,
     -97,   -97,   -97,   -97,   101,   105,   108,   204,   124,   -97,
     114,   116,   -97,   -97,   -97,    -9,   -97,   -97,     0,    83,
      84,    82,    85,    81,    80,    91,    90,   -15,   -97,   -97,
      21,    21,   227,   135,   259,   -97,   -97,   351,   -97,   351,
     144,   -97,    21,   119,   282,   305,   138,   -97,   126,    21,
     -97,    21,    21,   125,    21,   127,   328,   -97,   -97,   -97,
      21,   -97,    21,    21,   129,   -97,   -97,   -97,    21,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,    82,     0,     1,     3,    83,
       0,     0,     0,    56,     0,    54,     0,    85,     0,     0,
       0,    55,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     9,
      10,    14,    16,    21,    24,    26,    28,    30,    32,    34,
      36,    38,    40,    42,    44,    46,    47,     0,    11,     0,
      68,     0,    65,    64,    63,    57,    84,     0,     0,     0,
       0,     0,    60,     0,    61,    62,     0,     0,    20,    18,
      19,    17,     0,     0,    13,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,    70,    69,     7,     0,     0,     0,     0,     0,    59,
       0,     0,    12,    50,    48,     0,    23,    22,    25,    27,
      29,    31,    33,    35,    37,    39,    41,     0,    45,     8,
       0,     0,     0,     0,     0,    52,    53,     0,    51,     0,
      80,    71,     0,     0,     0,     0,     0,    49,    43,     0,
      79,     0,     0,     0,     0,     0,     0,    81,    78,    77,
       0,    76,     0,     0,     0,    73,    74,    75,     0,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,   123,   -97,    89,    49,   -31,    78,    79,
      92,    93,    77,    86,    96,    75,    87,   -96,   -97,    73,
     -18,   -97,   -97,   155,   164,   131,   -97,   -19,   -97,   -97,
     -97,     5,   178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    40,    21,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   115,    58,    13,    59,    60,    61,    17,    62,    63,
      64,     6,     3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,   127,    67,    78,    11,     4,    10,    18,   137,     9,
      73,    22,    23,    24,    96,     7,    15,   139,    86,    87,
      82,     1,    31,    32,    19,   138,     5,    22,    23,    24,
      11,    25,    12,    26,    27,    28,    29,    30,    31,    32,
      33,    38,    34,   148,    35,     1,    96,    39,    97,    36,
     104,   105,   106,   108,    37,   116,   117,    38,    16,   111,
     100,    18,   101,    39,    20,   114,    22,    23,    24,    11,
      25,    11,    26,    27,    28,    29,    30,    31,    32,    33,
      68,    34,    74,    35,    79,    80,    81,    69,    36,   133,
      70,    71,    75,    37,    76,    77,    38,    83,    22,    23,
      24,    85,    39,    88,    90,    89,    92,    93,    91,    31,
      32,   140,   141,    34,   143,    35,   146,    94,    95,   147,
      36,    98,    99,   150,   103,    37,   153,   155,    38,   113,
     157,   109,   158,   159,    39,   161,   112,   129,   164,   130,
     134,   165,   131,   166,   167,    22,    23,    24,   135,   169,
     136,   144,   149,   151,   156,    96,    31,    32,    72,   160,
      34,   162,    35,   168,    84,   110,   118,    36,   119,   122,
     125,   128,    37,    65,    14,    38,    22,    23,    24,   123,
       8,    39,   120,   126,   121,     0,     0,    31,    32,   107,
     124,    34,   102,    35,     0,     0,     0,     0,    36,     0,
       0,     0,     0,    37,     0,     0,    38,    22,    23,    24,
       0,     0,    39,     0,     0,     0,     0,     0,    31,    32,
     132,     0,    34,     0,    35,     0,     0,     0,     0,    36,
      22,    23,    24,     0,    37,     0,     0,    38,     0,     0,
       0,    31,    32,    39,     0,    34,     0,    35,     0,     0,
       0,     0,    36,     0,     0,     0,     0,    37,     0,     0,
      38,   142,    22,    23,    24,     0,    39,     0,     0,     0,
       0,     0,     0,    31,    32,   145,     0,    34,     0,    35,
       0,     0,     0,     0,    36,    22,    23,    24,     0,    37,
       0,     0,    38,     0,     0,     0,    31,    32,    39,     0,
      34,     0,    35,     0,     0,     0,     0,    36,    22,    23,
      24,     0,    37,     0,     0,    38,   152,     0,     0,    31,
      32,    39,     0,    34,     0,    35,     0,     0,     0,     0,
      36,    22,    23,    24,     0,    37,     0,     0,    38,   154,
       0,     0,    31,    32,    39,     0,    34,     0,    35,     0,
       0,     0,     0,    36,    22,    23,    24,     0,    37,     0,
       0,    38,   163,     0,     0,    31,    32,    39,     0,    34,
       0,    35,     0,     0,     0,     0,    36,     0,     0,     0,
       0,    37,     0,     0,    38,     0,     0,     0,     0,     0,
      39
};

static const yytype_int16 yycheck[] =
{
      19,    97,    20,    34,     6,    18,    33,    17,    17,     4,
      28,     3,     4,     5,    29,     0,    11,    32,    18,    19,
      38,     6,    14,    15,    34,    34,    39,     3,     4,     5,
       6,     7,    34,     9,    10,    11,    12,    13,    14,    15,
      16,    33,    18,   139,    20,     6,    29,    39,    31,    25,
      68,    69,    70,    71,    30,    86,    87,    33,    37,    77,
      16,    17,    38,    39,    35,    83,     3,     4,     5,     6,
       7,     6,     9,    10,    11,    12,    13,    14,    15,    16,
      35,    18,    16,    20,    35,    36,    37,    33,    25,   107,
      33,    33,    16,    30,    33,    33,    33,    33,     3,     4,
       5,    30,    39,    20,    22,    21,    25,    27,    23,    14,
      15,   130,   131,    18,   132,    20,   134,    26,    28,   137,
      25,    24,    16,   142,    36,    30,   144,   145,    33,    34,
     149,    16,   151,   152,    39,   154,    34,    36,   156,    34,
      16,   160,    34,   162,   163,     3,     4,     5,    34,   168,
      34,    16,     8,    34,    16,    29,    14,    15,    16,    34,
      18,    34,    20,    34,    41,    76,    88,    25,    89,    92,
      95,    98,    30,    18,    10,    33,     3,     4,     5,    93,
       2,    39,    90,    96,    91,    -1,    -1,    14,    15,    16,
      94,    18,    61,    20,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,     3,     4,     5,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
       3,     4,     5,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    14,    15,    39,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,     3,     4,     5,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    14,    15,    39,    -1,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,     3,     4,
       5,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    14,
      15,    39,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,     3,     4,     5,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    14,    15,    39,    -1,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,     3,     4,     5,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    14,    15,    39,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    41,    72,    18,    39,    71,     0,    72,    71,
      33,     6,    34,    63,    64,    71,    37,    67,    17,    34,
      35,    43,     3,     4,     5,     7,     9,    10,    11,    12,
      13,    14,    15,    16,    18,    20,    25,    30,    33,    39,
      42,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    64,
      65,    66,    68,    69,    70,    63,    67,    60,    35,    33,
      33,    33,    16,    60,    16,    16,    33,    33,    47,    46,
      46,    46,    60,    33,    43,    30,    18,    19,    20,    21,
      22,    23,    25,    27,    26,    28,    29,    31,    24,    16,
      16,    38,    65,    36,    60,    60,    60,    16,    60,    16,
      45,    60,    34,    34,    60,    61,    47,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    36,
      34,    34,    16,    60,    16,    34,    34,    17,    34,    32,
      67,    67,    34,    60,    16,    16,    60,    60,    57,     8,
      67,    34,    34,    60,    34,    60,    16,    67,    67,    67,
      34,    67,    34,    34,    60,    67,    67,    67,    34,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    43,    43,    44,
      44,    44,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     1,
       1,     1,     3,     2,     1,     2,     1,     2,     2,     2,
       2,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     3,
       3,     4,     4,     4,     2,     3,     1,     3,     1,     3,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       3,     5,     9,     8,     8,     8,     7,     7,     7,     6,
       5,     7,     1,     2,     6,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 113 "parser.y" /* yacc.c:1646  */
    { std::vector<FunctionDefinition *> *it = new std::vector<FunctionDefinition *>(); it->push_back((yyvsp[0].functionDefinition)); (yyval.program) = new Program(it); program_pointer = (yyval.program); }
#line 1442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].program)->functions->push_back((yyvsp[0].functionDefinition)); (yyval.program) = (yyvsp[-1].program); program_pointer = (yyval.program); }
#line 1448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new StringLit((yyvsp[0].sval)); }
#line 1454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CharLit((yyvsp[0].cval)); }
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new IntLit((yyvsp[0].ival));}
#line 1466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_vector) = new std::vector<Expression *>(); (yyval.expression_vector)->push_back((yyvsp[-1].expression)); }
#line 1472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].expression_vector)->push_back((yyvsp[-1].expression)); (yyval.expression_vector) = (yyvsp[-3].expression_vector); }
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Identifier((yyvsp[0].sval)); }
#line 1484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].functionCall); }
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].expression)->array_accesses = (yyvsp[0].expression_vector); (yyval.expression) = (yyvsp[-1].expression); }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostUnaryOpExpression((yyvsp[-1].expression), (yyvsp[0].sval)); }
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreUnaryOpExpression((yyvsp[0].expression), (yyvsp[-1].sval)); }
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreUnaryOpExpression((yyvsp[0].expression), (yyvsp[-1].sval)); }
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreUnaryOpExpression((yyvsp[0].expression), (yyvsp[-1].sval)); }
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].expression)->dereference += 1;  (yyval.expression) = (yyvsp[0].expression); }
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new TernaryOpExpression((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].sval), (yyvsp[0].expression)); }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.expression_vector) = new std::vector<Expression *>(); (yyval.expression_vector)->push_back((yyvsp[0].expression)); }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expression_vector)->push_back((yyvsp[0].expression)); (yyval.expression_vector) = (yyvsp[-2].expression_vector); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.functionCall) = new FunctionCall(new Identifier((yyvsp[-2].sval)), NULL ); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.functionCall) = new FunctionCall(new Identifier((yyvsp[-3].sval)), (yyvsp[-1].expression_vector)); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 219 "parser.y" /* yacc.c:1646  */
    { std::vector<Expression *> *it = new std::vector<Expression *>(); it->push_back((yyvsp[-1].expression)); (yyval.functionCall) = new FunctionCall(new Identifier((yyvsp[-3].sval)), it); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 220 "parser.y" /* yacc.c:1646  */
    { std::vector<Expression *> *it = new std::vector<Expression *>(); it->push_back((yyvsp[-1].expression)); (yyval.functionCall) = new FunctionCall(new Identifier((yyvsp[-3].sval)), it); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration) = new Declaration((yyvsp[-1].sval), (yyvsp[0].identifier), NULL ); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.declaration) = new Declaration((yyvsp[-2].sval), (yyvsp[-1].identifier), (yyvsp[0].expression_vector)); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 228 "parser.y" /* yacc.c:1646  */
    { std::vector<Declaration *> *it = new std::vector<Declaration *>(); it->push_back((yyvsp[0].declaration)); (yyval.declaration_vector) = it; }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].declaration_vector)->push_back((yyvsp[0].declaration)); (yyval.declaration_vector) = (yyvsp[-2].declaration_vector); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 232 "parser.y" /* yacc.c:1646  */
    { /*$$ = $1;*/ (yyval.statement) = new EmptyStatement(); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnStatement((yyvsp[-1].expression)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnStatement(NULL); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BreakStatement(); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ContinueStatement(); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].ifElseStatement); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].forStatement); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].whileStatement); }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ExpressionStatement((yyvsp[-1].expression)); }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new DeclarationStatement((yyvsp[-1].declaration_vector)); }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 244 "parser.y" /* yacc.c:1646  */
    { std::vector<Statement *> *it = new std::vector<Statement *>(); it->push_back((yyvsp[0].statement)); (yyval.statement_vector) = it; }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_vector)->push_back((yyvsp[0].statement)); (yyval.statement_vector) = (yyvsp[-1].statement_vector); }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new Block((yyvsp[-1].statement_vector)); }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.whileStatement) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement((yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement(NULL, (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement((yyvsp[-5].expression), NULL, (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement((yyvsp[-5].expression), (yyvsp[-3].expression), NULL, (yyvsp[0].block)); }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement((yyvsp[-4].expression), NULL, NULL, (yyvsp[0].block)); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement(NULL, (yyvsp[-3].expression), NULL, (yyvsp[0].block)); }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement(NULL, NULL, (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.forStatement) = new ForStatement(NULL, NULL, NULL, (yyvsp[0].block)); }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.ifElseStatement) = new IfElseStatement((yyvsp[-2].expression), (yyvsp[0].block), NULL); }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.ifElseStatement) = new IfElseStatement((yyvsp[-4].expression), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.identifier) = new Identifier((yyvsp[0].sval)); }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].identifier)->reference += 1; (yyval.identifier) = (yyvsp[0].identifier); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.functionDefinition) = new FunctionDefinition((yyvsp[-5].sval), (yyvsp[-4].identifier), (yyvsp[-2].declaration_vector), (yyvsp[0].block)); }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.functionDefinition) = new FunctionDefinition((yyvsp[-4].sval), (yyvsp[-3].identifier), NULL, (yyvsp[0].block)); }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1944 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 275 "parser.y" /* yacc.c:1906  */


void yyerror(char const *s)
{
	fprintf(stderr, "error: %s\n", s);
}
