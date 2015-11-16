/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 35 "gpparser.y"

#define YYDEBUG 1
#include "globals.h"
#include "error.h"

#include "ast.h"

// Bring the standard library into the
// global namespace
// using namespace std;

// Prototypes to keep the compiler happy
void yyerror(const char *error_message);
void report_warning(const char *error_message);

/* Flags used in the AST construction. */
bool is_root = false;
bool is_bidir = false;

/* Pointers to data structures constructed by the parser. */
struct GPGraph *ast_host_graph = NULL;
struct GPRule *gp_rule = NULL; 
struct List *gp_program = NULL; 

bool syntax_error = false;


/* Line 268 of yacc.c  */
#line 99 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 19 "gpparser.y"

#include "ast.h"



/* Line 288 of yacc.c  */
#line 129 "parser.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     IF = 259,
     TRY = 260,
     THEN = 261,
     ELSE = 262,
     SKIP = 263,
     FAIL = 264,
     BREAK = 265,
     WHERE = 266,
     EDGETEST = 267,
     INDEG = 268,
     OUTDEG = 269,
     _LENGTH = 270,
     INT = 271,
     CHARACTER = 272,
     STRING = 273,
     ATOM = 274,
     LIST = 275,
     INTERFACE = 276,
     _EMPTY = 277,
     INJECTIVE = 278,
     MARK = 279,
     ANY_MARK = 280,
     ARROW = 281,
     NEQ = 282,
     GTEQ = 283,
     LTEQ = 284,
     NUM = 285,
     DNUM = 286,
     STR = 287,
     PROCID = 288,
     ID = 289,
     ROOT = 290,
     BIDIRECTIONAL = 291,
     GP_GRAPH = 292,
     GP_RULE = 293,
     GP_PROGRAM = 294,
     OR = 295,
     AND = 296,
     NOT = 297,
     UMINUS = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 64 "gpparser.y"
  
  int num;   /* value of NUM token. */
  char *str; /* value of STRING and CHAR tokens. */
  char *id;  /* value of PROCID and ID tokens. */
  int mark;  /* enum MarkTypes, value of MARK token. */
	double dnum; /* value of DNUM token. */


/* Line 293 of yacc.c  */
#line 97 "gpparser.y"
  
  struct List *list; 
  struct GPDeclaration *decl;
  struct GPCommand *command;
  struct GPProcedure *proc;
  struct GPRule *rule;
  struct GPGraph *graph;
  struct GPNode *node;
  struct GPEdge *edge;
  struct GPPos *pos;
  struct GPCondition *cond_exp;
  struct GPLabel *label;  
  struct GPAtom *atom_exp;

  int list_type; /* enum ListType */
  int check_type; /* enum CondExpType */



/* Line 293 of yacc.c  */
#line 219 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* "%code provides" blocks.  */

/* Line 340 of yacc.c  */
#line 24 "gpparser.y"

extern GPGraph *ast_host_graph; 
extern GPRule *gp_rule; 
extern List *gp_program; 
extern int yylineno;
extern string yytext;
extern FILE *yyin;
extern bool syntax_error;



/* Line 340 of yacc.c  */
#line 255 "parser.c"

/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 261 "parser.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNRULES -- Number of states.  */
#define YYNSTATES  351

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    63,     2,     2,     2,     2,
      55,    56,    45,    43,    54,    44,    48,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    53,
      62,    50,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    60,    59,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    17,    19,    21,
      23,    27,    31,    38,    45,    46,    49,    52,    54,    58,
      62,    64,    68,    73,    80,    85,    88,    93,    98,   105,
     109,   114,   117,   119,   122,   124,   126,   128,   130,   132,
     134,   138,   141,   143,   147,   149,   153,   163,   172,   182,
     193,   197,   203,   205,   209,   214,   220,   223,   225,   229,
     231,   233,   235,   237,   239,   243,   249,   254,   261,   267,
     275,   277,   280,   287,   295,   297,   300,   311,   317,   323,
     330,   337,   345,   351,   358,   364,   371,   372,   374,   375,
     377,   378,   381,   386,   394,   398,   402,   406,   410,   414,
     418,   421,   425,   429,   433,   435,   437,   439,   441,   442,
     445,   447,   449,   453,   457,   461,   465,   467,   471,   475,
     477,   479,   481,   486,   491,   496,   499,   503,   507,   511,
     515,   519,   523,   525,   527,   529,   531,   533,   537,   543,
     548,   555,   561,   569,   571,   574,   581,   589,   591,   594,
     604,   606,   608,   612,   616,   618,   622,   626,   628,   631
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    38,    77,    -1,    39,    66,    -1,    37,
     103,    -1,    67,    -1,    66,    67,    -1,    68,    -1,    69,
      -1,    77,    -1,     3,    50,    71,    -1,    98,    50,    71,
      -1,    98,    50,    51,    70,    52,    71,    -1,    99,    50,
      51,    70,    52,    71,    -1,    -1,    70,    77,    -1,    70,
      69,    -1,    72,    -1,    71,    53,    72,    -1,    71,    54,
      72,    -1,    73,    -1,    73,    40,    73,    -1,     4,    73,
       6,    73,    -1,     4,    73,     6,    73,     7,    73,    -1,
       4,    73,     7,    73,    -1,     5,    73,    -1,     5,    73,
       6,    73,    -1,     5,    73,     7,    73,    -1,     5,    73,
       6,    73,     7,    73,    -1,    55,    71,    56,    -1,    55,
      71,    56,    57,    -1,     1,    56,    -1,    74,    -1,    74,
      57,    -1,     8,    -1,     9,    -1,    10,    -1,    75,    -1,
      99,    -1,    98,    -1,    58,    76,    59,    -1,     1,    59,
      -1,    99,    -1,    76,    54,    99,    -1,    98,    -1,    76,
      53,    99,    -1,    99,    55,    78,    56,    83,    26,    83,
      80,    91,    -1,    99,    55,    56,    83,    26,    83,    80,
      91,    -1,    98,    55,    78,    56,    83,    26,    83,    80,
      91,    -1,    99,    55,    78,    53,    56,    83,    26,    83,
      80,    91,    -1,    79,    49,    82,    -1,    78,    53,    79,
      49,    82,    -1,   102,    -1,    79,    54,   102,    -1,    21,
      50,    58,    59,    -1,    21,    50,    58,    81,    59,    -1,
       1,    59,    -1,   100,    -1,    81,    54,   100,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    51,
      60,    52,    -1,    51,    88,    60,    60,    52,    -1,    51,
      84,    60,    52,    -1,    51,    88,    60,    84,    60,    52,
      -1,    51,    84,    60,    86,    52,    -1,    51,    88,    60,
      84,    60,    86,    52,    -1,    85,    -1,    84,    85,    -1,
      55,   100,    89,    54,    95,    56,    -1,    55,   100,    89,
      54,    95,    88,    56,    -1,    87,    -1,    86,    87,    -1,
      55,   101,    90,    54,   100,    54,   100,    54,    95,    56,
      -1,    55,    31,    54,    31,    56,    -1,    55,    30,    54,
      30,    56,    -1,    55,    30,    54,    44,    30,    56,    -1,
      55,    44,    30,    54,    30,    56,    -1,    55,    44,    30,
      54,    44,    30,    56,    -1,    55,    31,    54,    30,    56,
      -1,    55,    31,    54,    44,    30,    56,    -1,    55,    30,
      54,    31,    56,    -1,    55,    44,    30,    54,    31,    56,
      -1,    -1,    35,    -1,    -1,    36,    -1,    -1,    11,    92,
      -1,    93,    55,   102,    56,    -1,    12,    55,   100,    54,
     100,    94,    56,    -1,    96,    50,    96,    -1,    96,    27,
      96,    -1,    97,    61,    97,    -1,    97,    28,    97,    -1,
      97,    62,    97,    -1,    97,    29,    97,    -1,    42,    92,
      -1,    92,    40,    92,    -1,    92,    41,    92,    -1,    55,
      92,    56,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    -1,    54,    95,    -1,    96,    -1,    22,    -1,    96,
      63,    24,    -1,    22,    63,    24,    -1,    96,    63,    25,
      -1,    22,    63,    25,    -1,    97,    -1,    96,    49,    97,
      -1,    96,    49,    22,    -1,   102,    -1,    30,    -1,    32,
      -1,    13,    55,   100,    56,    -1,    14,    55,   100,    56,
      -1,    15,    55,   102,    56,    -1,    44,    97,    -1,    55,
      97,    56,    -1,    97,    43,    97,    -1,    97,    44,    97,
      -1,    97,    45,    97,    -1,    97,    46,    97,    -1,    97,
      48,    97,    -1,    33,    -1,    34,    -1,    34,    -1,    34,
      -1,    34,    -1,    51,    60,    52,    -1,    51,    88,    60,
      60,    52,    -1,    51,   104,    60,    52,    -1,    51,    88,
      60,   104,    60,    52,    -1,    51,   104,    60,   106,    52,
      -1,    51,    88,    60,   104,    60,   106,    52,    -1,   105,
      -1,   104,   105,    -1,    55,   100,    89,    54,   108,    56,
      -1,    55,   100,    89,    54,   108,    88,    56,    -1,   107,
      -1,   106,   107,    -1,    55,   101,    54,   100,    54,   100,
      54,   108,    56,    -1,   109,    -1,    22,    -1,   109,    63,
      24,    -1,    22,    63,    24,    -1,   110,    -1,   109,    49,
     110,    -1,   109,    49,    22,    -1,    30,    -1,    44,    30,
      -1,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   207,   207,   208,   209,   212,   214,   217,   218,   219,
     221,   223,   227,   232,   239,   240,   242,   245,   246,   248,
     253,   254,   255,   257,   260,   264,   266,   268,   270,   274,
     275,   279,   280,   281,   282,   283,   284,   286,   287,   288,
     290,   293,   295,   297,   300,   305,   313,   316,   320,   329,
     336,   341,   347,   349,   352,   353,   356,   359,   361,   364,
     365,   366,   367,   368,   373,   374,   375,   376,   377,   378,
     381,   382,   384,   387,   391,   392,   394,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   411,   412,   414,   415,
     420,   421,   423,   425,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   439,   440,   441,   442,   444,   445,
     449,   450,   451,   452,   454,   455,   458,   459,   461,   466,
     467,   468,   469,   471,   473,   474,   475,   476,   477,   478,
     479,   480,   484,   485,   486,   487,   488,   497,   498,   499,
     500,   502,   504,   507,   508,   510,   514,   519,   520,   522,
     528,   529,   530,   531,   533,   534,   536,   540,   541,   542
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "IF", "TRY", "THEN", "ELSE",
  "SKIP", "FAIL", "BREAK", "WHERE", "EDGETEST", "INDEG", "OUTDEG",
  "_LENGTH", "INT", "CHARACTER", "STRING", "ATOM", "LIST", "INTERFACE",
  "_EMPTY", "INJECTIVE", "MARK", "ANY_MARK", "ARROW", "NEQ", "GTEQ",
  "LTEQ", "NUM", "DNUM", "STR", "PROCID", "ID", "ROOT", "BIDIRECTIONAL",
  "GP_GRAPH", "GP_RULE", "GP_PROGRAM", "OR", "AND", "NOT", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "'.'", "':'", "'='", "'['", "']'", "';'", "','",
  "'('", "')'", "'!'", "'{'", "'}'", "'|'", "'>'", "'<'", "'#'", "$accept",
  "Initialise", "Program", "Declaration", "MainDecl", "ProcDecl",
  "LocalDecls", "ComSeq", "Command", "Block", "SimpleCommand",
  "RuleSetCall", "IDList", "RuleDecl", "VarDecls", "VarList", "Inter",
  "NodeIDList", "Type", "Graph", "NodeList", "Node", "EdgeList", "Edge",
  "Position", "RootNode", "Bidirection", "CondDecl", "Condition",
  "Subtype", "LabelArg", "Label", "List", "AtomExp", "ProcID", "RuleID",
  "NodeID", "EdgeID", "Variable", "HostGraph", "HostNodeList", "HostNode",
  "HostEdgeList", "HostEdge", "HostLabel", "HostList", "HostExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    43,    45,    42,    47,   298,    46,    58,
      61,    91,    93,    59,    44,    40,    41,    33,   123,   125,
     124,    62,    60,    35
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    99,   100,   101,   102,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     108,   108,   108,   108,   109,   109,   109,   110,   110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     2,     1,     1,     1,
       3,     3,     6,     6,     0,     2,     2,     1,     3,     3,
       1,     3,     4,     6,     4,     2,     4,     4,     6,     3,
       4,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     3,     1,     3,     9,     8,     9,    10,
       3,     5,     1,     3,     4,     5,     2,     1,     3,     1,
       1,     1,     1,     1,     3,     5,     4,     6,     5,     7,
       1,     2,     6,     7,     1,     2,    10,     5,     5,     6,
       6,     7,     5,     6,     5,     6,     0,     1,     0,     1,
       0,     2,     4,     7,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     0,     2,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     4,     4,     4,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     5,     4,
       6,     5,     7,     1,     2,     6,     7,     1,     2,     9,
       1,     1,     3,     3,     1,     3,     3,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,   132,   133,     2,
       0,     0,     0,     3,     5,     7,     8,     9,     0,     0,
       1,     0,     0,     0,     0,   143,     0,     0,     0,     6,
       0,     0,     0,     0,   134,     0,    86,   137,     0,     0,
       0,   144,   136,     0,     0,    52,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    10,    17,    20,    32,
      37,    39,    38,    14,    11,    14,     0,     0,     0,    87,
       0,     0,     0,   139,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    41,     0,    25,     0,
       0,    44,    42,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   135,
       0,   141,   148,     0,     0,    59,    60,    61,    62,    63,
      50,    53,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    40,    18,    19,
      21,     0,    16,    15,     0,    78,    84,     0,    82,    77,
       0,     0,     0,     0,   151,   157,   159,     0,     0,   150,
     154,   140,     0,     0,     0,     0,    86,    64,     0,     0,
      71,     0,     0,     0,     0,    22,    24,    26,    27,    30,
      45,    43,    12,    13,    79,    83,    80,    85,     0,     0,
     158,     0,   145,     0,     0,     0,   142,     0,    51,     0,
       0,    66,     0,     0,    74,     0,     0,     0,     0,    90,
       0,     0,     0,     0,    81,   153,   146,   156,   155,   152,
       0,    90,     0,    88,    68,    75,    65,     0,    56,     0,
       0,    47,     0,    90,    23,    28,     0,    48,     0,     0,
       0,   111,   120,   121,     0,     0,     0,   110,   116,   119,
      89,     0,    67,     0,     0,     0,   104,   105,   106,   107,
       0,     0,    91,     0,     0,   116,    90,    46,     0,     0,
       0,     0,     0,   125,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    54,     0,    57,     0,
     100,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,   113,   115,   126,
      73,   118,   117,   112,   114,   127,   128,   129,   130,   131,
       0,     0,    55,     0,   103,   101,   102,     0,    95,    94,
      97,    99,    96,    98,   149,   122,   123,   124,     0,    58,
       0,    92,     0,   108,     0,     0,     0,     0,   109,    93,
      76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    13,    14,    15,    16,    97,    56,    57,    58,
      59,    60,    90,    17,    43,    44,   209,   287,   120,    82,
     124,   125,   203,   204,    23,    70,   251,   231,   262,   263,
     346,   246,   264,   248,    61,    62,    36,   110,   249,     6,
      24,    25,    75,    76,   158,   159,   160
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
     142,    21,    80,    30,    22,   103,  -219,  -219,  -219,  -219,
      13,    39,    94,    30,  -219,  -219,  -219,  -219,   161,   169,
    -219,   123,    96,    86,   171,  -219,   132,     5,    37,  -219,
      26,   122,   138,   148,  -219,   187,   194,  -219,   204,   223,
     -29,  -219,  -219,   106,   189,  -219,   196,   278,   277,   127,
     127,  -219,  -219,  -219,    37,    80,   137,  -219,   227,   249,
    -219,  -219,  -219,  -219,   137,  -219,   121,   153,   199,  -219,
     244,   225,   213,  -219,   280,   283,  -219,   132,   196,   305,
     132,   219,   323,    31,   196,  -219,  -219,   221,   259,    68,
     183,  -219,  -219,    37,    37,   127,  -219,    65,    78,   263,
     307,   334,   309,   310,   337,   156,    88,  -219,   285,  -219,
     314,  -219,  -219,   236,   343,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,   123,   318,   240,  -219,   312,   196,   196,   345,
     127,   127,   127,   127,   316,   340,   340,  -219,  -219,  -219,
    -219,    37,  -219,  -219,    37,  -219,  -219,   319,  -219,  -219,
     320,   321,   322,   349,   317,  -219,  -219,   351,   220,   -31,
    -219,  -219,   287,   223,   305,   196,   194,  -219,   223,   289,
    -219,   241,    75,   356,   196,   376,  -219,   377,  -219,  -219,
    -219,  -219,   137,   137,  -219,  -219,  -219,  -219,   330,   361,
    -219,   168,  -219,   332,   101,   363,  -219,   335,  -219,    75,
     336,  -219,   280,   291,  -219,   339,   242,   333,   344,   382,
     196,    75,   127,   127,  -219,  -219,  -219,  -219,  -219,  -219,
     223,   382,   200,   359,  -219,  -219,  -219,   293,  -219,   338,
     191,  -219,    75,   382,  -219,  -219,   346,  -219,   342,   347,
     348,   341,  -219,  -219,   248,   248,   228,    66,   206,  -219,
    -219,   352,  -219,   295,   -15,   350,  -219,  -219,  -219,  -219,
     191,   191,   311,   353,    25,   265,   382,  -219,    88,   223,
     223,   132,   329,   362,   272,  -219,   355,   226,   331,   248,
     248,   248,   248,   248,   223,  -219,  -219,   253,  -219,   223,
    -219,    45,   243,   191,   191,   132,   248,   248,   248,   248,
     248,   248,  -219,   357,   358,   360,   364,  -219,  -219,  -219,
    -219,  -219,   206,  -219,  -219,   284,   284,   362,   362,  -219,
     365,   223,  -219,   367,  -219,   366,  -219,   368,   369,   369,
     206,   206,   206,   206,  -219,  -219,  -219,  -219,   223,  -219,
     223,  -219,   371,   372,   200,   200,   373,   374,  -219,  -219,
    -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   385,  -219,   260,   370,   -25,   266,   -42,
    -219,  -219,  -219,     9,   388,    64,  -174,  -219,   235,   -72,
     230,  -109,   182,  -186,   -78,   246,  -219,  -193,  -211,  -219,
    -219,    17,  -218,  -105,    11,     7,  -120,   215,   -26,  -219,
     384,    -3,   315,   -59,   159,  -219,   234
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      45,    45,   166,   126,   247,    64,   114,    87,    88,    11,
      19,     9,   129,    10,    18,   170,   112,   225,   194,    34,
      19,    41,    20,    73,    18,   221,    74,    48,   237,    89,
      49,    50,   195,    12,    51,    52,    53,   233,    48,    42,
     267,    49,    50,   197,   286,    51,    52,    53,   166,   290,
     291,    45,   296,   140,   121,   172,   173,    45,   266,     7,
       8,    46,    92,     7,     8,    42,    91,   225,    26,    41,
       7,     8,     5,   302,   277,   297,   207,    63,   328,   329,
     193,    54,   325,   326,    55,   293,   294,   128,   175,   176,
     177,   178,    54,   199,    27,    55,   208,   170,     7,     8,
     236,   324,   211,   112,    19,    19,   143,   143,    18,    18,
     154,     7,     8,     7,     8,   277,   182,   141,   155,   183,
     156,    93,    94,   217,   134,   265,   247,   247,    48,   278,
     144,   155,   157,   156,   288,    51,    52,    53,   232,   273,
     274,   113,   180,   181,    28,   157,    38,   113,    37,   304,
     305,    99,   100,    32,    33,   265,   292,    34,    21,    77,
       7,     8,    78,    22,   320,   101,    42,    35,   276,   323,
     234,   235,   312,    65,   315,   316,   317,   318,   319,     1,
       2,     3,    54,   102,   103,    55,   151,   152,   265,   265,
      93,    94,    66,   330,   331,   332,   333,   104,    32,    33,
     153,   339,    67,   255,   238,   239,   240,   256,   257,   258,
     259,    30,    35,   238,   239,   240,    26,    68,   342,    31,
     343,   242,   241,   243,    27,    42,    39,   130,   131,    69,
     242,    40,   243,   260,    42,   244,   135,   136,    79,   238,
     239,   240,   137,    80,   244,   306,   261,    81,   311,   279,
     280,   281,   282,   105,   283,   245,   242,    34,   243,    39,
      42,   238,   239,   240,    71,   132,   133,    95,    39,   327,
     244,   298,   299,   108,   122,   191,   192,   107,   242,   123,
     243,   245,    42,   191,   275,   164,   279,   280,   281,   282,
      80,   283,   244,   298,   299,   168,   168,   168,   106,   309,
     169,   205,   227,   245,   300,   301,    96,   321,   279,   280,
     281,   282,   322,   283,   109,   279,   280,   281,   282,   145,
     283,   115,   116,   117,   118,   119,   300,   301,   309,   281,
     282,    83,   283,    85,    84,   111,    86,   161,    74,   196,
      74,   201,    74,   224,   202,   252,   202,   285,   202,   127,
     202,   293,   294,   307,   308,   313,   314,   142,   142,   138,
     139,   347,   348,   146,   147,   148,   149,   150,   163,   165,
     167,   174,   171,   179,     8,   184,   185,   186,   187,   188,
     189,   190,   210,   212,   213,   215,   214,   219,   216,   220,
     222,   226,   228,   230,   229,   250,   254,   269,    29,   198,
     268,   206,   270,   271,   272,   289,   284,   294,   295,   253,
     283,   310,   200,   334,   335,    47,   336,   223,   277,   338,
     337,   340,    72,   162,   341,   344,   345,   303,   218,   349,
     350,     0,     0,     0,     0,    98
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-219))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      26,    27,   122,    81,   222,    30,    78,    49,    50,     2,
       3,     2,    84,     2,     3,   124,    75,   203,    49,    34,
      13,    24,     0,    52,    13,   199,    55,     1,   221,    54,
       4,     5,    63,     3,     8,     9,    10,   211,     1,    34,
     233,     4,     5,   163,    59,     8,     9,    10,   168,   260,
     261,    77,    27,    95,    80,   127,   128,    83,   232,    33,
      34,    56,    55,    33,    34,    34,    55,   253,    55,    72,
      33,    34,    51,   266,    49,    50,     1,    51,   296,   297,
     158,    55,   293,   294,    58,    40,    41,    56,   130,   131,
     132,   133,    55,   165,    55,    58,    21,   206,    33,    34,
     220,    56,   174,   162,    97,    98,    97,    98,    97,    98,
      22,    33,    34,    33,    34,    49,   141,    52,    30,   144,
      32,    53,    54,    22,    56,   230,   344,   345,     1,    63,
      52,    30,    44,    32,   254,     8,     9,    10,   210,   244,
     245,    77,   135,   136,    50,    44,    60,    83,    52,   269,
     270,    30,    31,    30,    31,   260,   261,    34,    55,    53,
      33,    34,    56,    60,   284,    44,    34,    44,   246,   289,
     212,   213,   277,    51,   279,   280,   281,   282,   283,    37,
      38,    39,    55,    30,    31,    58,    30,    31,   293,   294,
      53,    54,    54,   298,   299,   300,   301,    44,    30,    31,
      44,   321,    54,    12,    13,    14,    15,    16,    17,    18,
      19,    50,    44,    13,    14,    15,    55,    30,   338,    50,
     340,    30,    22,    32,    55,    34,    55,     6,     7,    35,
      30,    60,    32,    42,    34,    44,    53,    54,    49,    13,
      14,    15,    59,    54,    44,   271,    55,    51,    22,    43,
      44,    45,    46,    54,    48,    55,    30,    34,    32,    55,
      34,    13,    14,    15,    60,     6,     7,    40,    55,   295,
      44,    28,    29,    60,    55,    55,    56,    52,    30,    60,
      32,    55,    34,    55,    56,    49,    43,    44,    45,    46,
      54,    48,    44,    28,    29,    55,    55,    55,    54,    56,
      60,    60,    60,    55,    61,    62,    57,    54,    43,    44,
      45,    46,    59,    48,    34,    43,    44,    45,    46,    56,
      48,    16,    17,    18,    19,    20,    61,    62,    56,    45,
      46,    53,    48,    56,    56,    52,    59,    52,    55,    52,
      55,    52,    55,    52,    55,    52,    55,    52,    55,    26,
      55,    40,    41,    24,    25,    24,    25,    97,    98,    93,
      94,   344,   345,    56,    30,    56,    56,    30,    54,    26,
      52,    26,    60,    57,    34,    56,    56,    56,    56,    30,
      63,    30,    26,     7,     7,    24,    56,    24,    56,    54,
      54,    52,    59,    11,    50,    36,    58,    55,    13,   164,
      54,   171,    55,    55,    63,    55,    54,    41,    55,   227,
      48,    56,   166,    56,    56,    27,    56,   202,    49,    54,
      56,    54,    38,   108,    56,    54,    54,   268,   194,    56,
      56,    -1,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    39,    65,    51,   103,    33,    34,    77,
      98,    99,     3,    66,    67,    68,    69,    77,    98,    99,
       0,    55,    60,    88,   104,   105,    55,    55,    50,    67,
      50,    50,    30,    31,    34,    44,   100,    52,    60,    55,
      60,   105,    34,    78,    79,   102,    56,    78,     1,     4,
       5,     8,     9,    10,    55,    58,    71,    72,    73,    74,
      75,    98,    99,    51,    71,    51,    54,    54,    30,    35,
      89,    60,   104,    52,    55,   106,   107,    53,    56,    49,
      54,    51,    83,    53,    56,    56,    59,    73,    73,    71,
      76,    98,    99,    53,    54,    40,    57,    70,    70,    30,
      31,    44,    30,    31,    44,    54,    54,    52,    60,    34,
     101,    52,   107,    79,    83,    16,    17,    18,    19,    20,
      82,   102,    55,    60,    84,    85,    88,    26,    56,    83,
       6,     7,     6,     7,    56,    53,    54,    59,    72,    72,
      73,    52,    69,    77,    52,    56,    56,    30,    56,    56,
      30,    30,    31,    44,    22,    30,    32,    44,   108,   109,
     110,    52,   106,    54,    49,    26,   100,    52,    55,    60,
      85,    60,    83,    83,    26,    73,    73,    73,    73,    57,
      99,    99,    71,    71,    56,    56,    56,    56,    30,    63,
      30,    55,    56,    88,    49,    63,    52,   100,    82,    83,
      89,    52,    55,    86,    87,    60,    84,     1,    21,    80,
      26,    83,     7,     7,    56,    24,    56,    22,   110,    24,
      54,    80,    54,   101,    52,    87,    52,    60,    59,    50,
      11,    91,    83,    80,    73,    73,   100,    91,    13,    14,
      15,    22,    30,    32,    44,    55,    95,    96,    97,   102,
      36,    90,    52,    86,    58,    12,    16,    17,    18,    19,
      42,    55,    92,    93,    96,    97,    80,    91,    54,    55,
      55,    55,    63,    97,    97,    56,    88,    49,    63,    43,
      44,    45,    46,    48,    54,    52,    59,    81,   100,    55,
      92,    92,    97,    40,    41,    55,    27,    50,    28,    29,
      61,    62,    91,   108,   100,   100,   102,    24,    25,    56,
      56,    22,    97,    24,    25,    97,    97,    97,    97,    97,
     100,    54,    59,   100,    56,    92,    92,   102,    96,    96,
      97,    97,    97,    97,    56,    56,    56,    56,    54,   100,
      54,    56,   100,   100,    54,    54,    94,    95,    95,    56,
      56
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 32: /* "STR" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->str)); };

/* Line 1391 of yacc.c  */
#line 1541 "parser.c"
	break;
      case 33: /* "PROCID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1550 "parser.c"
	break;
      case 34: /* "ID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1559 "parser.c"
	break;
      case 66: /* "Program" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1568 "parser.c"
	break;
      case 67: /* "Declaration" */

/* Line 1391 of yacc.c  */
#line 138 "gpparser.y"
	{ freeASTDeclaration((yyvaluep->decl)); };

/* Line 1391 of yacc.c  */
#line 1577 "parser.c"
	break;
      case 68: /* "MainDecl" */

/* Line 1391 of yacc.c  */
#line 139 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1586 "parser.c"
	break;
      case 70: /* "LocalDecls" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1595 "parser.c"
	break;
      case 71: /* "ComSeq" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1604 "parser.c"
	break;
      case 72: /* "Command" */

/* Line 1391 of yacc.c  */
#line 139 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1613 "parser.c"
	break;
      case 73: /* "Block" */

/* Line 1391 of yacc.c  */
#line 139 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1622 "parser.c"
	break;
      case 74: /* "SimpleCommand" */

/* Line 1391 of yacc.c  */
#line 139 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1631 "parser.c"
	break;
      case 75: /* "RuleSetCall" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1640 "parser.c"
	break;
      case 76: /* "IDList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1649 "parser.c"
	break;
      case 77: /* "RuleDecl" */

/* Line 1391 of yacc.c  */
#line 140 "gpparser.y"
	{ freeASTRule((yyvaluep->rule)); };

/* Line 1391 of yacc.c  */
#line 1658 "parser.c"
	break;
      case 78: /* "VarDecls" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1667 "parser.c"
	break;
      case 79: /* "VarList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1676 "parser.c"
	break;
      case 80: /* "Inter" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1685 "parser.c"
	break;
      case 81: /* "NodeIDList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1694 "parser.c"
	break;
      case 83: /* "Graph" */

/* Line 1391 of yacc.c  */
#line 141 "gpparser.y"
	{ freeASTGraph((yyvaluep->graph)); };

/* Line 1391 of yacc.c  */
#line 1703 "parser.c"
	break;
      case 84: /* "NodeList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1712 "parser.c"
	break;
      case 85: /* "Node" */

/* Line 1391 of yacc.c  */
#line 142 "gpparser.y"
	{ freeASTNode((yyvaluep->node)); };

/* Line 1391 of yacc.c  */
#line 1721 "parser.c"
	break;
      case 86: /* "EdgeList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1730 "parser.c"
	break;
      case 87: /* "Edge" */

/* Line 1391 of yacc.c  */
#line 143 "gpparser.y"
	{ freeASTEdge((yyvaluep->edge)); };

/* Line 1391 of yacc.c  */
#line 1739 "parser.c"
	break;
      case 91: /* "CondDecl" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ freeASTCondition((yyvaluep->cond_exp)); };

/* Line 1391 of yacc.c  */
#line 1748 "parser.c"
	break;
      case 92: /* "Condition" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ freeASTCondition((yyvaluep->cond_exp)); };

/* Line 1391 of yacc.c  */
#line 1757 "parser.c"
	break;
      case 94: /* "LabelArg" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1766 "parser.c"
	break;
      case 95: /* "Label" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1775 "parser.c"
	break;
      case 96: /* "List" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1784 "parser.c"
	break;
      case 97: /* "AtomExp" */

/* Line 1391 of yacc.c  */
#line 146 "gpparser.y"
	{ freeASTAtom((yyvaluep->atom_exp)); };

/* Line 1391 of yacc.c  */
#line 1793 "parser.c"
	break;
      case 98: /* "ProcID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1802 "parser.c"
	break;
      case 99: /* "RuleID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1811 "parser.c"
	break;
      case 100: /* "NodeID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1820 "parser.c"
	break;
      case 101: /* "EdgeID" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1829 "parser.c"
	break;
      case 102: /* "Variable" */

/* Line 1391 of yacc.c  */
#line 136 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1838 "parser.c"
	break;
      case 103: /* "HostGraph" */

/* Line 1391 of yacc.c  */
#line 141 "gpparser.y"
	{ freeASTGraph((yyvaluep->graph)); };

/* Line 1391 of yacc.c  */
#line 1847 "parser.c"
	break;
      case 104: /* "HostNodeList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1856 "parser.c"
	break;
      case 105: /* "HostNode" */

/* Line 1391 of yacc.c  */
#line 142 "gpparser.y"
	{ freeASTNode((yyvaluep->node)); };

/* Line 1391 of yacc.c  */
#line 1865 "parser.c"
	break;
      case 106: /* "HostEdgeList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1874 "parser.c"
	break;
      case 107: /* "HostEdge" */

/* Line 1391 of yacc.c  */
#line 143 "gpparser.y"
	{ freeASTEdge((yyvaluep->edge)); };

/* Line 1391 of yacc.c  */
#line 1883 "parser.c"
	break;
      case 108: /* "HostLabel" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1892 "parser.c"
	break;
      case 109: /* "HostList" */

/* Line 1391 of yacc.c  */
#line 137 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1901 "parser.c"
	break;
      case 110: /* "HostExp" */

/* Line 1391 of yacc.c  */
#line 146 "gpparser.y"
	{ freeASTAtom((yyvaluep->atom_exp)); };

/* Line 1391 of yacc.c  */
#line 1910 "parser.c"
	break;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 207 "gpparser.y"
    { gp_rule = (yyvsp[(2) - (2)].rule); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 208 "gpparser.y"
    { gp_program = (yyvsp[(2) - (2)].list); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 209 "gpparser.y"
    { ast_host_graph = (yyvsp[(2) - (2)].graph); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 212 "gpparser.y"
    { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].decl), NULL); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 214 "gpparser.y"
    { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[(2) - (2)]), (yyvsp[(2) - (2)].decl), (yyvsp[(1) - (2)].list)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 217 "gpparser.y"
    { (yyval.decl) = newASTMainDecl((yyloc), (yyvsp[(1) - (1)].command)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 218 "gpparser.y"
    { (yyval.decl) = newASTProcedureDecl((yyloc), (yyvsp[(1) - (1)].proc)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 219 "gpparser.y"
    { (yyval.decl) = newASTRuleDecl((yyloc), (yyvsp[(1) - (1)].rule)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 221 "gpparser.y"
    { (yyval.command) = newASTCommandSequence((yylsp[(1) - (3)]), (yyvsp[(3) - (3)].list)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 223 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].id), NULL, 
                                               newASTCommandSequence((yylsp[(3) - (3)]) ,(yyvsp[(3) - (3)].list)));
					  if((yyvsp[(1) - (3)].id)) free((yyvsp[(1) - (3)].id)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 228 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)].list), 
                                               newASTCommandSequence((yylsp[(6) - (6)]), (yyvsp[(6) - (6)].list)));
				          if((yyvsp[(1) - (6)].id)) free((yyvsp[(1) - (6)].id)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 233 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)].list), 
                                               newASTCommandSequence((yylsp[(6) - (6)]), (yyvsp[(6) - (6)].list)));
                                          report_warning("Procedure names must "
 					   "start with an upper-case letter."); 
					  if((yyvsp[(1) - (6)].id)) free((yyvsp[(1) - (6)].id)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 239 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 240 "gpparser.y"
    { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[(2) - (2)]), 
                                               newASTRuleDecl((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].rule)), (yyvsp[(1) - (2)].list)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 242 "gpparser.y"
    { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[(2) - (2)]),
                                               newASTProcedureDecl((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].proc)), (yyvsp[(1) - (2)].list)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 245 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].command), NULL); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 246 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].command), (yyvsp[(1) - (3)].list)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 248 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].command), (yyvsp[(1) - (3)].list));
                                          report_warning("Incorrect use of comma "
					    "to separate commands. Perhaps you "
					    "meant to use a semicolon?"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 254 "gpparser.y"
    { (yyval.command) = newASTOrStmt((yyloc), (yyvsp[(1) - (3)].command), (yyvsp[(3) - (3)].command)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 255 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), (yyvsp[(4) - (4)].command), newASTSkip((yyloc))); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 257 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(6) - (6)].command)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 260 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), newASTSkip((yyloc)), (yyvsp[(4) - (4)].command));
                                          report_warning("No 'then' clause in if "
						         "statement."); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 264 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (2)].command), newASTSkip((yyloc)), newASTSkip((yyloc))); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 266 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), (yyvsp[(4) - (4)].command), newASTSkip((yyloc))); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 268 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), newASTSkip((yyloc)), (yyvsp[(4) - (4)].command)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 270 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                                (yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(6) - (6)].command)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 274 "gpparser.y"
    { (yyval.command) = newASTCommandSequence((yyloc), (yyvsp[(2) - (3)].list)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 275 "gpparser.y"
    { (yyval.command) = newASTAlap((yyloc), 
                                               newASTCommandSequence((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].list))); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 279 "gpparser.y"
    { (yyval.command) = NULL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 281 "gpparser.y"
    { (yyval.command) = newASTAlap((yyloc), (yyvsp[(1) - (2)].command)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 282 "gpparser.y"
    { (yyval.command) = newASTSkip((yyloc)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 283 "gpparser.y"
    { (yyval.command) = newASTEmptyStatement((yyloc), FAIL_STATEMENT); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 284 "gpparser.y"
    { (yyval.command) = newASTEmptyStatement((yyloc), BREAK_STATEMENT); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 286 "gpparser.y"
    { (yyval.command) = newASTRuleSetCall((yyloc), (yyvsp[(1) - (1)].list)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 287 "gpparser.y"
    { (yyval.command) = newASTRuleCall((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 288 "gpparser.y"
    { (yyval.command) = newASTProcCall((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 290 "gpparser.y"
    { (yyval.list) = (yyvsp[(2) - (3)].list); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 293 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 295 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL);
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 297 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list)); 
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 300 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL);
                                          report_warning("Procedure name used in "
					   "a rule set. Rule names must start "
					   "with a lower-case letter.");
				          if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 305 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list));
                                          report_warning("Incorrect use of semicolon "
					   "in a rule set. Perhaps you meant to "
					   "use a comma?"); 
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 314 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (9)]), (yyvsp[(1) - (9)].id), (yyvsp[(3) - (9)].list), (yyvsp[(5) - (9)].graph), (yyvsp[(7) - (9)].graph), (yyvsp[(8) - (9)].list), (yyvsp[(9) - (9)].cond_exp)); 
					  if((yyvsp[(1) - (9)].id)) free((yyvsp[(1) - (9)].id)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 317 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (8)]), (yyvsp[(1) - (8)].id), NULL, (yyvsp[(4) - (8)].graph), (yyvsp[(6) - (8)].graph), (yyvsp[(7) - (8)].list), (yyvsp[(8) - (8)].cond_exp));
					  if((yyvsp[(1) - (8)].id)) free((yyvsp[(1) - (8)].id)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 321 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (9)]), (yyvsp[(1) - (9)].id), (yyvsp[(3) - (9)].list), (yyvsp[(5) - (9)].graph), (yyvsp[(7) - (9)].graph), (yyvsp[(8) - (9)].list), (yyvsp[(9) - (9)].cond_exp)); 
                                          report_warning("Rule names must "
 					   "start with a lower-case letter."
				 	   "letter.");
					  if((yyvsp[(1) - (9)].id)) free((yyvsp[(1) - (9)].id)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 330 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (10)]), (yyvsp[(1) - (10)].id), (yyvsp[(3) - (10)].list), (yyvsp[(6) - (10)].graph), (yyvsp[(8) - (10)].graph), (yyvsp[(9) - (10)].list), (yyvsp[(10) - (10)].cond_exp));  
                                          report_warning("Semicolon at the end "
					    "of a rule's variable list");
					  if((yyvsp[(1) - (10)].id)) free((yyvsp[(1) - (10)].id)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 336 "gpparser.y"
    { (yyval.list) = addASTVariableDecl((yyvsp[(3) - (3)].list_type), (yyloc), (yyvsp[(1) - (3)].list), NULL); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 341 "gpparser.y"
    { (yyloc).first_column = (yylsp[(3) - (5)]).first_column;
				          (yyloc).first_line = (yylsp[(3) - (5)]).first_line;
					  (yyloc).last_column = (yylsp[(5) - (5)]).last_column;
				          (yyloc).last_column = (yylsp[(5) - (5)]).last_column;
					  (yyval.list) = addASTVariableDecl((yyvsp[(5) - (5)].list_type), (yyloc), (yyvsp[(3) - (5)].list), (yyvsp[(1) - (5)].list)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 347 "gpparser.y"
    { (yyval.list) = addASTVariable((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL); 
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 349 "gpparser.y"
    { (yyval.list) = addASTVariable((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list)); 
		 	                  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 352 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 353 "gpparser.y"
    { (yyval.list) = (yyvsp[(4) - (5)].list); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 356 "gpparser.y"
    { report_warning("Error in an interface list.");  
                                          (yyval.list) = NULL; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 359 "gpparser.y"
    { (yyval.list) = addASTNodeID((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL); 
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 361 "gpparser.y"
    { (yyval.list) = addASTNodeID((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list));
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 364 "gpparser.y"
    { (yyval.list_type) = INT_DECLARATIONS; }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 365 "gpparser.y"
    { (yyval.list_type) = CHAR_DECLARATIONS; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 366 "gpparser.y"
    { (yyval.list_type) = STRING_DECLARATIONS; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 367 "gpparser.y"
    { (yyval.list_type) = ATOM_DECLARATIONS; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 368 "gpparser.y"
    { (yyval.list_type) = LIST_DECLARATIONS; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 373 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 374 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 375 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (4)].list), NULL); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 376 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (6)].list), NULL); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 377 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (5)].list), (yyvsp[(4) - (5)].list)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 379 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (7)].list), (yyvsp[(6) - (7)].list)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 381 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 382 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].list)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 384 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (6)]), is_root, (yyvsp[(2) - (6)].id), (yyvsp[(5) - (6)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (6)].id)) free((yyvsp[(2) - (6)].id)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 388 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (7)]), is_root, (yyvsp[(2) - (7)].id), (yyvsp[(5) - (7)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (7)].id)) free((yyvsp[(2) - (7)].id)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 391 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].edge), NULL); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 392 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].edge), (yyvsp[(1) - (2)].list)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 395 "gpparser.y"
    { (yyval.edge) = newASTEdge((yylsp[(2) - (10)]), is_bidir, (yyvsp[(2) - (10)].id), (yyvsp[(5) - (10)].id), (yyvsp[(7) - (10)].id), (yyvsp[(9) - (10)].label));
                                          is_bidir = false; if((yyvsp[(2) - (10)].id)) free((yyvsp[(2) - (10)].id)); 
					  if((yyvsp[(5) - (10)].id)) free((yyvsp[(5) - (10)].id)); if((yyvsp[(7) - (10)].id)) free((yyvsp[(7) - (10)].id)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 400 "gpparser.y"
    { }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 401 "gpparser.y"
    { }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 402 "gpparser.y"
    { }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 403 "gpparser.y"
    { }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 404 "gpparser.y"
    { }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 405 "gpparser.y"
    { }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 406 "gpparser.y"
    { }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 407 "gpparser.y"
    { }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 408 "gpparser.y"
    { }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 412 "gpparser.y"
    { is_root = true; }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 415 "gpparser.y"
    { is_bidir = true; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 420 "gpparser.y"
    { (yyval.cond_exp) = NULL; }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 421 "gpparser.y"
    { (yyval.cond_exp) = (yyvsp[(2) - (2)].cond_exp); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 423 "gpparser.y"
    { (yyval.cond_exp) = newASTSubtypePred((yyvsp[(1) - (4)].check_type), (yyloc), (yyvsp[(3) - (4)].id)); 
					  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 426 "gpparser.y"
    { (yyval.cond_exp) = newASTEdgePred((yyloc), (yyvsp[(3) - (7)].id), (yyvsp[(5) - (7)].id), (yyvsp[(6) - (7)].label)); 
					  if((yyvsp[(3) - (7)].id)) free((yyvsp[(3) - (7)].id)); if((yyvsp[(5) - (7)].id)) free((yyvsp[(5) - (7)].id)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 428 "gpparser.y"
    { (yyval.cond_exp) = newASTListComparison(EQUAL, (yyloc), (yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 429 "gpparser.y"
    { (yyval.cond_exp) = newASTListComparison(NOT_EQUAL, (yyloc), (yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 430 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(GREATER, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 431 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(GREATER_EQUAL, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 432 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(LESS, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 433 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(LESS_EQUAL, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 434 "gpparser.y"
    { (yyval.cond_exp) = newASTNotExp((yyloc), (yyvsp[(2) - (2)].cond_exp)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 435 "gpparser.y"
    { (yyval.cond_exp) = newASTBinaryExp(BOOL_OR, (yyloc), (yyvsp[(1) - (3)].cond_exp), (yyvsp[(3) - (3)].cond_exp)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 436 "gpparser.y"
    { (yyval.cond_exp) = newASTBinaryExp(BOOL_AND, (yyloc), (yyvsp[(1) - (3)].cond_exp), (yyvsp[(3) - (3)].cond_exp)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 437 "gpparser.y"
    { (yyval.cond_exp) = (yyvsp[(2) - (3)].cond_exp); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 439 "gpparser.y"
    { (yyval.check_type) = INT_CHECK; }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 440 "gpparser.y"
    { (yyval.check_type) = CHAR_CHECK; }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 441 "gpparser.y"
    { (yyval.check_type) = STRING_CHECK; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 442 "gpparser.y"
    { (yyval.check_type) = ATOM_CHECK; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 444 "gpparser.y"
    { (yyval.label) = NULL; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 445 "gpparser.y"
    { (yyval.label) = (yyvsp[(2) - (2)].label); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 449 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, (yyvsp[(1) - (1)].list)); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 450 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, NULL); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 451 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 452 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 454 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 455 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 458 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].atom_exp), NULL); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 459 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].atom_exp), (yyvsp[(1) - (3)].list)); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 461 "gpparser.y"
    { (yyval.list) = (yyvsp[(1) - (3)].list);
    					  report_warning("Empty symbol in the "
     					                 "middle of a list.\n"); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 466 "gpparser.y"
    { (yyval.atom_exp) = newASTVariable((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 467 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), (yyvsp[(1) - (1)].num)); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 468 "gpparser.y"
    { (yyval.atom_exp) = newASTString((yyloc), (yyvsp[(1) - (1)].str)); if((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 469 "gpparser.y"
    { (yyval.atom_exp) = newASTDegreeOp(INDEGREE, (yyloc), (yyvsp[(3) - (4)].id)); 
					  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 471 "gpparser.y"
    { (yyval.atom_exp) = newASTDegreeOp(OUTDEGREE, (yyloc), (yyvsp[(3) - (4)].id)); 
				 	  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 473 "gpparser.y"
    { (yyval.atom_exp) = newASTLength((yyloc), (yyvsp[(3) - (4)].id)); if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 474 "gpparser.y"
    { (yyval.atom_exp) = newASTNegExp((yyloc), (yyvsp[(2) - (2)].atom_exp)); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 475 "gpparser.y"
    { (yyval.atom_exp) = (yyvsp[(2) - (3)].atom_exp); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 476 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(ADD, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp));  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 477 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(SUBTRACT, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 478 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(MULTIPLY, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 479 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(DIVIDE, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 480 "gpparser.y"
    { (yyval.atom_exp) = newASTConcat((yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 497 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 498 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 499 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (4)].list), NULL); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 501 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (6)].list), NULL); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 503 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (5)].list), (yyvsp[(4) - (5)].list)); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 505 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (7)].list), (yyvsp[(6) - (7)].list)); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 507 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 508 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].list)); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 511 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (6)]), is_root, (yyvsp[(2) - (6)].id), (yyvsp[(5) - (6)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (6)].id)) free((yyvsp[(2) - (6)].id)); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 515 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (7)]), is_root, (yyvsp[(2) - (7)].id), (yyvsp[(5) - (7)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (7)].id)) free((yyvsp[(2) - (7)].id)); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 519 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].edge), NULL); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 520 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].edge), (yyvsp[(1) - (2)].list)); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 523 "gpparser.y"
    { (yyval.edge) = newASTEdge((yylsp[(2) - (9)]), false, (yyvsp[(2) - (9)].id), (yyvsp[(4) - (9)].id), (yyvsp[(6) - (9)].id), (yyvsp[(8) - (9)].label));
					  if((yyvsp[(2) - (9)].id)) free((yyvsp[(2) - (9)].id)); 
					  if((yyvsp[(4) - (9)].id)) free((yyvsp[(4) - (9)].id)); 
                     			  if((yyvsp[(6) - (9)].id)) free((yyvsp[(6) - (9)].id)); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 528 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, (yyvsp[(1) - (1)].list)); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 529 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, NULL); }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 530 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 531 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 533 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].atom_exp), NULL); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 534 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].atom_exp), (yyvsp[(1) - (3)].list)); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 536 "gpparser.y"
    { (yyval.list) = (yyvsp[(1) - (3)].list);
					  report_warning("Error: empty symbol in the "
     					                 "middle of a list.\n"); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 540 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), (yyvsp[(1) - (1)].num)); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 541 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), -((yyvsp[(2) - (2)].num))); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 542 "gpparser.y"
    { (yyval.atom_exp) = newASTString((yyloc), (yyvsp[(1) - (1)].str)); if((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); }
    break;



/* Line 1806 of yacc.c  */
#line 3357 "parser.c"
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
  *++yylsp = yyloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 2067 of yacc.c  */
#line 544 "gpparser.y"


/* Bison calls yyerror whenever it encounters an error. It prints error
 * messages to stderr and log_file. */
void yyerror(const char *error_message)
{
   fprintf(stderr, "Error at '%c': %s\n\n", yychar, error_message);
   /*fprintf(log_file, "%d.%d-%d.%d: Error at '%s': %s\n\n", 
           yylloc.first_line, yylloc.first_column, yylloc.last_line, 
           yylloc.last_column, yytext, error_message);*/
}

/* report_warning is identical to yyerror except that it doesn't refer to yytext.
 * This is called in the action code of error-catching Bison rules in which
 * the value of yytext may be misleading. */
void report_warning(const char *error_message)
{
   fprintf(stderr, "Error: %s\n\n", error_message);
   /*fprintf(log_file, "%d.%d-%d.%d: Error: %s\n\n", 
           yylloc.first_line, yylloc.first_column, yylloc.last_line, 
           yylloc.last_column, error_message);*/
   syntax_error = true;
}
        


