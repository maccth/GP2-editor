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
#line 42 "gpparser.y"

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
#line 26 "gpparser.y"

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
#line 71 "gpparser.y"
  
  int num;   /* value of NUM token. */
  char *str; /* value of STRING and CHAR tokens. */
  char *id;  /* value of PROCID and ID tokens. */
  int mark;  /* enum MarkTypes, value of MARK token. */
	double dnum; /* value of DNUM token. */


/* Line 293 of yacc.c  */
#line 104 "gpparser.y"
  
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
#line 31 "gpparser.y"

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
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNRULES -- Number of states.  */
#define YYNSTATES  352

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
      61,    50,    62,     2,     2,     2,     2,     2,     2,     2,
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
     515,   519,   523,   525,   527,   529,   531,   533,   535,   537,
     541,   547,   552,   559,   565,   573,   575,   578,   585,   593,
     595,   598,   608,   610,   612,   614,   618,   622,   624,   628,
     632,   634,   637
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
      -1,    61,    31,    54,    31,    62,    -1,    61,    30,    54,
      30,    62,    -1,    61,    30,    54,    44,    30,    62,    -1,
      61,    44,    30,    54,    30,    62,    -1,    61,    44,    30,
      54,    44,    30,    62,    -1,    61,    31,    54,    30,    62,
      -1,    61,    31,    54,    44,    30,    62,    -1,    61,    30,
      54,    31,    62,    -1,    61,    44,    30,    54,    31,    62,
      -1,    -1,    35,    -1,    -1,    36,    -1,    -1,    11,    92,
      -1,    93,    55,   102,    56,    -1,    12,    55,   100,    54,
     100,    94,    56,    -1,    96,    50,    96,    -1,    96,    27,
      96,    -1,    97,    62,    97,    -1,    97,    28,    97,    -1,
      97,    61,    97,    -1,    97,    29,    97,    -1,    42,    92,
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
      48,    97,    -1,    33,    -1,    34,    -1,    34,    -1,    30,
      -1,    34,    -1,    30,    -1,    34,    -1,    51,    60,    52,
      -1,    51,    88,    60,    60,    52,    -1,    51,   104,    60,
      52,    -1,    51,    88,    60,   104,    60,    52,    -1,    51,
     104,    60,   106,    52,    -1,    51,    88,    60,   104,    60,
     106,    52,    -1,   105,    -1,   104,   105,    -1,    55,   108,
      89,    54,   109,    56,    -1,    55,   108,    89,    54,   109,
      88,    56,    -1,   107,    -1,   106,   107,    -1,    55,   108,
      54,   108,    54,   108,    54,   109,    56,    -1,    30,    -1,
     110,    -1,    22,    -1,   110,    63,    24,    -1,    22,    63,
      24,    -1,   111,    -1,   110,    49,   111,    -1,   110,    49,
      22,    -1,    30,    -1,    44,    30,    -1,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   216,   217,   220,   222,   225,   226,   227,
     229,   231,   235,   240,   247,   248,   250,   253,   254,   256,
     261,   262,   263,   265,   268,   272,   274,   276,   278,   282,
     283,   287,   288,   289,   290,   291,   292,   294,   295,   296,
     298,   301,   303,   305,   308,   313,   321,   324,   328,   337,
     344,   349,   355,   357,   360,   361,   364,   367,   369,   372,
     373,   374,   375,   376,   381,   382,   383,   384,   385,   386,
     389,   390,   392,   395,   399,   400,   402,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   419,   420,   422,   423,
     428,   429,   431,   433,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   447,   448,   449,   450,   452,   453,
     457,   458,   459,   460,   462,   463,   466,   467,   469,   474,
     475,   476,   477,   479,   481,   482,   483,   484,   485,   486,
     487,   488,   492,   493,   494,   495,   503,   504,   512,   521,
     522,   523,   524,   526,   528,   531,   532,   534,   539,   545,
     546,   548,   558,   560,   561,   562,   563,   565,   566,   568,
     572,   573,   574
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
  "'('", "')'", "'!'", "'{'", "'}'", "'|'", "'<'", "'>'", "'#'", "$accept",
  "Initialise", "Program", "Declaration", "MainDecl", "ProcDecl",
  "LocalDecls", "ComSeq", "Command", "Block", "SimpleCommand",
  "RuleSetCall", "IDList", "RuleDecl", "VarDecls", "VarList", "Inter",
  "NodeIDList", "Type", "Graph", "NodeList", "Node", "EdgeList", "Edge",
  "Position", "RootNode", "Bidirection", "CondDecl", "Condition",
  "Subtype", "LabelArg", "Label", "List", "AtomExp", "ProcID", "RuleID",
  "NodeID", "EdgeID", "Variable", "HostGraph", "HostNodeList", "HostNode",
  "HostEdgeList", "HostEdge", "HostID", "HostLabel", "HostList", "HostExp", 0
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
     124,    60,    62,    35
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
      97,    97,    98,    99,   100,   100,   101,   101,   102,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   109,   109,   109,   109,   110,   110,   110,
     111,   111,   111
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
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     4,     6,     5,     7,     1,     2,     6,     7,     1,
       2,     9,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,   132,   133,     2,
       0,     0,     0,     3,     5,     7,     8,     9,     0,     0,
       1,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       6,     0,     0,   152,    86,   139,     0,     0,     0,     0,
       0,   146,   138,     0,     0,    52,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,    10,    17,    20,    32,
      37,    39,    38,    14,    11,    14,    87,     0,     0,     0,
       0,     0,     0,   141,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    41,     0,    25,     0,
       0,    44,    42,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
     143,   150,     0,     0,    59,    60,    61,    62,    63,    50,
      53,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    40,    18,    19,    21,
       0,    16,    15,     0,   154,   160,   162,     0,     0,   153,
     157,    78,    84,     0,    82,    77,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   135,   134,    86,    64,     0,
      71,     0,     0,     0,     0,    22,    24,    26,    27,    30,
      45,    43,    12,    13,     0,   161,   147,     0,     0,     0,
      79,    83,    80,    85,     0,   144,     0,    51,     0,     0,
      66,     0,     0,    74,     0,     0,     0,     0,    90,     0,
       0,     0,     0,   156,   148,   159,   158,   155,    81,     0,
      90,     0,   137,   136,    88,    68,    75,    65,     0,    56,
       0,     0,    47,     0,    90,    23,    28,     0,    48,     0,
       0,     0,   111,   120,   121,     0,     0,     0,   110,   116,
     119,    89,     0,    67,     0,     0,     0,   104,   105,   106,
     107,     0,     0,    91,     0,     0,   116,    90,    46,     0,
       0,     0,     0,     0,   125,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    54,     0,    57,
       0,   100,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,   113,   115,
     126,    73,   118,   117,   112,   114,   127,   128,   129,   130,
     131,     0,     0,    55,     0,   103,   101,   102,     0,    95,
      94,    97,    99,    98,    96,   151,   122,   123,   124,     0,
      58,     0,    92,     0,   108,     0,     0,     0,     0,   109,
      93,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    13,    14,    15,    16,    97,    56,    57,    58,
      59,    60,    90,    17,    43,    44,   208,   288,   119,    82,
     123,   124,   202,   203,    24,    67,   252,   232,   263,   264,
     347,   247,   265,   249,    61,    62,   167,   224,   250,     6,
      25,    26,    75,    76,    34,   148,   149,   150
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -243
static const yytype_int16 yypact[] =
{
     293,   -25,   300,   100,    65,   187,  -243,  -243,  -243,  -243,
     -18,   101,   128,   100,  -243,  -243,  -243,  -243,    18,    41,
    -243,   241,   186,   139,   165,   112,  -243,   198,   -12,    37,
    -243,   143,   277,  -243,   251,  -243,   297,   298,   325,   137,
      69,  -243,  -243,   140,   180,  -243,   305,   159,   231,    24,
      24,  -243,  -243,  -243,    37,   300,   282,  -243,   317,   302,
    -243,  -243,  -243,  -243,   282,  -243,  -243,   304,   169,   177,
     306,   309,   202,  -243,   241,   262,  -243,   198,   305,   291,
     198,   200,   336,    38,   305,  -243,  -243,   331,   333,   249,
     235,  -243,  -243,    37,    37,    24,  -243,    85,   121,   127,
     303,   307,   334,   308,   310,   337,   189,  -243,   264,   312,
    -243,  -243,   195,   342,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,     6,   311,   208,  -243,   313,   305,   305,   345,    24,
      24,    24,    24,   318,   340,   340,  -243,  -243,  -243,  -243,
      37,  -243,  -243,    37,   314,  -243,  -243,   346,   211,    15,
    -243,  -243,  -243,   316,  -243,  -243,   320,   322,   323,   349,
    -243,   266,   241,   291,   305,  -243,  -243,   251,  -243,   268,
    -243,   210,    34,   354,   305,   374,  -243,   376,  -243,  -243,
    -243,  -243,   282,   282,   362,  -243,  -243,   332,   173,   363,
    -243,  -243,  -243,  -243,   327,  -243,   338,  -243,    34,   339,
    -243,   216,   270,  -243,   343,   224,   335,   341,   379,   305,
      34,    24,    24,  -243,  -243,  -243,  -243,  -243,  -243,   241,
     379,   196,  -243,  -243,   360,  -243,  -243,  -243,   272,  -243,
     344,   172,  -243,    34,   379,  -243,  -243,   347,  -243,   348,
     350,   351,   352,  -243,  -243,   222,   222,   243,    51,   252,
    -243,  -243,   353,  -243,   274,    -7,   355,  -243,  -243,  -243,
    -243,   172,   172,   301,   356,    27,   230,   379,  -243,   127,
       6,     6,   198,   319,   361,   237,  -243,   357,   209,   321,
     222,   222,   222,   222,   222,     6,  -243,  -243,   247,  -243,
       6,  -243,    75,    84,   172,   172,   198,   222,   222,   222,
     222,   222,   222,  -243,   358,   364,   365,   366,  -243,  -243,
    -243,  -243,  -243,   252,  -243,  -243,   267,   267,   361,   361,
    -243,   369,     6,  -243,   370,  -243,   359,  -243,   371,   367,
     367,   252,   252,   252,   252,  -243,  -243,  -243,  -243,     6,
    -243,     6,  -243,   372,   375,   196,   196,   377,   378,  -243,
    -243,  -243
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,   384,  -243,   250,   373,   -23,   256,   -46,
    -243,  -243,  -243,    12,   380,    -2,  -159,  -243,   236,   -66,
     227,   -99,   176,  -187,   -79,   245,  -243,  -204,  -172,  -243,
    -243,     8,  -210,  -120,     7,     4,  -242,  -243,   -27,  -243,
     386,    -6,   324,   -54,   -69,   148,  -243,   240
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      45,    45,   125,    87,    88,   109,    11,    19,    64,    10,
      18,   248,   113,   289,     9,   226,   238,    19,   128,    41,
      18,   111,    42,   165,   170,    48,     5,   166,   305,   306,
     268,    89,    51,    52,    53,   206,   165,    27,    48,   220,
     166,    49,    50,   321,    46,    51,    52,    53,   324,   139,
      45,   234,   287,   120,   297,   207,    45,     7,     8,    92,
     172,   173,    91,   303,   188,    20,    41,   226,    31,   187,
       7,     8,    42,    27,   267,   112,   278,   298,   189,    54,
     340,   112,    55,   175,   176,   177,   178,   329,   330,   291,
     292,    32,    54,   196,   127,    55,    28,   343,   198,   344,
     278,    19,    19,    12,    18,    18,   170,   111,   210,   142,
     142,   266,   299,   300,   279,   294,   295,   182,     7,     8,
     183,    73,   326,   327,    74,   274,   275,   280,   281,   282,
     283,   325,   284,     7,     8,   248,   248,   140,   180,   181,
     310,   266,   293,   233,    48,   301,   302,    49,    50,   144,
     237,    51,    52,    53,     7,     8,    28,   145,   313,   146,
     316,   317,   318,   319,   320,   235,   236,    21,   277,    36,
      37,   147,    40,   143,   266,   266,     7,     8,    29,   331,
     332,   333,   334,    38,   256,   239,   240,   241,   257,   258,
     259,   260,    21,    77,    63,   215,    78,    71,    54,   100,
     101,    55,   243,   145,   244,   146,    42,   103,   104,   239,
     240,   241,    83,   102,   261,    84,   245,   147,   242,   157,
     158,   105,   239,   240,   241,    39,   243,   262,   244,    79,
      42,   312,    42,   159,    80,   239,   240,   241,    35,   243,
     245,   244,    21,    42,   163,   307,   222,    22,    23,    80,
     223,   246,   243,   245,   244,   121,    42,    21,   299,   300,
     122,    23,   108,   121,   246,   121,   245,   186,   169,   328,
     204,    33,    23,   280,   281,   282,   283,   246,   284,   121,
     280,   281,   282,   283,   228,   284,    66,    85,   134,   135,
      86,   301,   302,   310,   136,   280,   281,   282,   283,   276,
     284,   322,    93,    94,    23,   133,   323,   114,   115,   116,
     117,   118,   282,   283,   110,   284,   160,    74,   195,    74,
     200,    74,   225,   201,   253,   201,   286,   201,    65,   201,
       1,     2,     3,     7,     8,    93,    94,   129,   130,   131,
     132,   294,   295,   308,   309,   314,   315,   141,   141,   137,
     138,    68,    69,   348,   349,    70,    81,    95,    99,    96,
     106,   107,   126,   168,   153,   151,   162,   156,   164,   152,
     154,   174,   155,   171,     8,   179,   185,   184,   190,   194,
     209,   211,   191,   212,   192,   193,   213,   217,   214,   218,
     231,   230,   219,   221,   229,   227,   251,    30,   205,   197,
     295,   269,   255,   270,   254,   271,   272,   285,    47,   284,
     290,   296,   199,   311,   335,   273,   278,   304,     0,     0,
     336,   337,   338,   339,   341,    72,   345,   342,   216,   346,
       0,     0,   161,   350,   351,     0,     0,     0,    98
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-243))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      27,    28,    81,    49,    50,    74,     2,     3,    31,     2,
       3,   221,    78,   255,     2,   202,   220,    13,    84,    25,
      13,    75,    34,    30,   123,     1,    51,    34,   270,   271,
     234,    54,     8,     9,    10,     1,    30,    55,     1,   198,
      34,     4,     5,   285,    56,     8,     9,    10,   290,    95,
      77,   210,    59,    80,    27,    21,    83,    33,    34,    55,
     126,   127,    55,   267,    49,     0,    72,   254,    50,   148,
      33,    34,    34,    55,   233,    77,    49,    50,    63,    55,
     322,    83,    58,   129,   130,   131,   132,   297,   298,   261,
     262,    50,    55,   162,    56,    58,    55,   339,   164,   341,
      49,    97,    98,     3,    97,    98,   205,   161,   174,    97,
      98,   231,    28,    29,    63,    40,    41,   140,    33,    34,
     143,    52,   294,   295,    55,   245,   246,    43,    44,    45,
      46,    56,    48,    33,    34,   345,   346,    52,   134,   135,
      56,   261,   262,   209,     1,    61,    62,     4,     5,    22,
     219,     8,     9,    10,    33,    34,    55,    30,   278,    32,
     280,   281,   282,   283,   284,   211,   212,    55,   247,    30,
      31,    44,    60,    52,   294,   295,    33,    34,    50,   299,
     300,   301,   302,    44,    12,    13,    14,    15,    16,    17,
      18,    19,    55,    53,    51,    22,    56,    60,    55,    30,
      31,    58,    30,    30,    32,    32,    34,    30,    31,    13,
      14,    15,    53,    44,    42,    56,    44,    44,    22,    30,
      31,    44,    13,    14,    15,    60,    30,    55,    32,    49,
      34,    22,    34,    44,    54,    13,    14,    15,    52,    30,
      44,    32,    55,    34,    49,   272,    30,    60,    61,    54,
      34,    55,    30,    44,    32,    55,    34,    55,    28,    29,
      60,    61,    60,    55,    55,    55,    44,    56,    60,   296,
      60,    30,    61,    43,    44,    45,    46,    55,    48,    55,
      43,    44,    45,    46,    60,    48,    35,    56,    53,    54,
      59,    61,    62,    56,    59,    43,    44,    45,    46,    56,
      48,    54,    53,    54,    61,    56,    59,    16,    17,    18,
      19,    20,    45,    46,    52,    48,    52,    55,    52,    55,
      52,    55,    52,    55,    52,    55,    52,    55,    51,    55,
      37,    38,    39,    33,    34,    53,    54,     6,     7,     6,
       7,    40,    41,    24,    25,    24,    25,    97,    98,    93,
      94,    54,    54,   345,   346,    30,    51,    40,    54,    57,
      54,    52,    26,    52,    30,    62,    54,    30,    26,    62,
      62,    26,    62,    60,    34,    57,    30,    63,    62,    30,
      26,     7,    62,     7,    62,    62,    24,    24,    56,    62,
      11,    50,    54,    54,    59,    52,    36,    13,   171,   163,
      41,    54,    58,    55,   228,    55,    55,    54,    28,    48,
      55,    55,   167,    56,    56,    63,    49,   269,    -1,    -1,
      56,    56,    56,    54,    54,    39,    54,    56,   188,    54,
      -1,    -1,   108,    56,    56,    -1,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    39,    65,    51,   103,    33,    34,    77,
      98,    99,     3,    66,    67,    68,    69,    77,    98,    99,
       0,    55,    60,    61,    88,   104,   105,    55,    55,    50,
      67,    50,    50,    30,   108,    52,    30,    31,    44,    60,
      60,   105,    34,    78,    79,   102,    56,    78,     1,     4,
       5,     8,     9,    10,    55,    58,    71,    72,    73,    74,
      75,    98,    99,    51,    71,    51,    35,    89,    54,    54,
      30,    60,   104,    52,    55,   106,   107,    53,    56,    49,
      54,    51,    83,    53,    56,    56,    59,    73,    73,    71,
      76,    98,    99,    53,    54,    40,    57,    70,    70,    54,
      30,    31,    44,    30,    31,    44,    54,    52,    60,   108,
      52,   107,    79,    83,    16,    17,    18,    19,    20,    82,
     102,    55,    60,    84,    85,    88,    26,    56,    83,     6,
       7,     6,     7,    56,    53,    54,    59,    72,    72,    73,
      52,    69,    77,    52,    22,    30,    32,    44,   109,   110,
     111,    62,    62,    30,    62,    62,    30,    30,    31,    44,
      52,   106,    54,    49,    26,    30,    34,   100,    52,    60,
      85,    60,    83,    83,    26,    73,    73,    73,    73,    57,
      99,    99,    71,    71,    63,    30,    56,    88,    49,    63,
      62,    62,    62,    62,    30,    52,   108,    82,    83,    89,
      52,    55,    86,    87,    60,    84,     1,    21,    80,    26,
      83,     7,     7,    24,    56,    22,   111,    24,    62,    54,
      80,    54,    30,    34,   101,    52,    87,    52,    60,    59,
      50,    11,    91,    83,    80,    73,    73,   108,    91,    13,
      14,    15,    22,    30,    32,    44,    55,    95,    96,    97,
     102,    36,    90,    52,    86,    58,    12,    16,    17,    18,
      19,    42,    55,    92,    93,    96,    97,    80,    91,    54,
      55,    55,    55,    63,    97,    97,    56,    88,    49,    63,
      43,    44,    45,    46,    48,    54,    52,    59,    81,   100,
      55,    92,    92,    97,    40,    41,    55,    27,    50,    28,
      29,    61,    62,    91,   109,   100,   100,   102,    24,    25,
      56,    56,    22,    97,    24,    25,    97,    97,    97,    97,
      97,   100,    54,    59,   100,    56,    92,    92,   102,    96,
      96,    97,    97,    97,    97,    56,    56,    56,    56,    54,
     100,    54,    56,   100,   100,    54,    54,    94,    95,    95,
      56,    56
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
#line 144 "gpparser.y"
	{ free((yyvaluep->str)); };

/* Line 1391 of yacc.c  */
#line 1545 "parser.c"
	break;
      case 33: /* "PROCID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1554 "parser.c"
	break;
      case 34: /* "ID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1563 "parser.c"
	break;
      case 66: /* "Program" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1572 "parser.c"
	break;
      case 67: /* "Declaration" */

/* Line 1391 of yacc.c  */
#line 146 "gpparser.y"
	{ freeASTDeclaration((yyvaluep->decl)); };

/* Line 1391 of yacc.c  */
#line 1581 "parser.c"
	break;
      case 68: /* "MainDecl" */

/* Line 1391 of yacc.c  */
#line 147 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1590 "parser.c"
	break;
      case 70: /* "LocalDecls" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1599 "parser.c"
	break;
      case 71: /* "ComSeq" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1608 "parser.c"
	break;
      case 72: /* "Command" */

/* Line 1391 of yacc.c  */
#line 147 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1617 "parser.c"
	break;
      case 73: /* "Block" */

/* Line 1391 of yacc.c  */
#line 147 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1626 "parser.c"
	break;
      case 74: /* "SimpleCommand" */

/* Line 1391 of yacc.c  */
#line 147 "gpparser.y"
	{ freeASTCommand((yyvaluep->command)); };

/* Line 1391 of yacc.c  */
#line 1635 "parser.c"
	break;
      case 75: /* "RuleSetCall" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1644 "parser.c"
	break;
      case 76: /* "IDList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1653 "parser.c"
	break;
      case 77: /* "RuleDecl" */

/* Line 1391 of yacc.c  */
#line 148 "gpparser.y"
	{ freeASTRule((yyvaluep->rule)); };

/* Line 1391 of yacc.c  */
#line 1662 "parser.c"
	break;
      case 78: /* "VarDecls" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1671 "parser.c"
	break;
      case 79: /* "VarList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1680 "parser.c"
	break;
      case 80: /* "Inter" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1689 "parser.c"
	break;
      case 81: /* "NodeIDList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1698 "parser.c"
	break;
      case 83: /* "Graph" */

/* Line 1391 of yacc.c  */
#line 149 "gpparser.y"
	{ freeASTGraph((yyvaluep->graph)); };

/* Line 1391 of yacc.c  */
#line 1707 "parser.c"
	break;
      case 84: /* "NodeList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1716 "parser.c"
	break;
      case 85: /* "Node" */

/* Line 1391 of yacc.c  */
#line 150 "gpparser.y"
	{ freeASTNode((yyvaluep->node)); };

/* Line 1391 of yacc.c  */
#line 1725 "parser.c"
	break;
      case 86: /* "EdgeList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1734 "parser.c"
	break;
      case 87: /* "Edge" */

/* Line 1391 of yacc.c  */
#line 151 "gpparser.y"
	{ freeASTEdge((yyvaluep->edge)); };

/* Line 1391 of yacc.c  */
#line 1743 "parser.c"
	break;
      case 91: /* "CondDecl" */

/* Line 1391 of yacc.c  */
#line 152 "gpparser.y"
	{ freeASTCondition((yyvaluep->cond_exp)); };

/* Line 1391 of yacc.c  */
#line 1752 "parser.c"
	break;
      case 92: /* "Condition" */

/* Line 1391 of yacc.c  */
#line 152 "gpparser.y"
	{ freeASTCondition((yyvaluep->cond_exp)); };

/* Line 1391 of yacc.c  */
#line 1761 "parser.c"
	break;
      case 94: /* "LabelArg" */

/* Line 1391 of yacc.c  */
#line 153 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1770 "parser.c"
	break;
      case 95: /* "Label" */

/* Line 1391 of yacc.c  */
#line 153 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1779 "parser.c"
	break;
      case 96: /* "List" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1788 "parser.c"
	break;
      case 97: /* "AtomExp" */

/* Line 1391 of yacc.c  */
#line 154 "gpparser.y"
	{ freeASTAtom((yyvaluep->atom_exp)); };

/* Line 1391 of yacc.c  */
#line 1797 "parser.c"
	break;
      case 98: /* "ProcID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1806 "parser.c"
	break;
      case 99: /* "RuleID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1815 "parser.c"
	break;
      case 100: /* "NodeID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1824 "parser.c"
	break;
      case 101: /* "EdgeID" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1833 "parser.c"
	break;
      case 102: /* "Variable" */

/* Line 1391 of yacc.c  */
#line 144 "gpparser.y"
	{ free((yyvaluep->id)); };

/* Line 1391 of yacc.c  */
#line 1842 "parser.c"
	break;
      case 103: /* "HostGraph" */

/* Line 1391 of yacc.c  */
#line 149 "gpparser.y"
	{ freeASTGraph((yyvaluep->graph)); };

/* Line 1391 of yacc.c  */
#line 1851 "parser.c"
	break;
      case 104: /* "HostNodeList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1860 "parser.c"
	break;
      case 105: /* "HostNode" */

/* Line 1391 of yacc.c  */
#line 150 "gpparser.y"
	{ freeASTNode((yyvaluep->node)); };

/* Line 1391 of yacc.c  */
#line 1869 "parser.c"
	break;
      case 106: /* "HostEdgeList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1878 "parser.c"
	break;
      case 107: /* "HostEdge" */

/* Line 1391 of yacc.c  */
#line 151 "gpparser.y"
	{ freeASTEdge((yyvaluep->edge)); };

/* Line 1391 of yacc.c  */
#line 1887 "parser.c"
	break;
      case 109: /* "HostLabel" */

/* Line 1391 of yacc.c  */
#line 153 "gpparser.y"
	{ freeASTLabel((yyvaluep->label)); };

/* Line 1391 of yacc.c  */
#line 1896 "parser.c"
	break;
      case 110: /* "HostList" */

/* Line 1391 of yacc.c  */
#line 145 "gpparser.y"
	{ freeAST((yyvaluep->list)); };

/* Line 1391 of yacc.c  */
#line 1905 "parser.c"
	break;
      case 111: /* "HostExp" */

/* Line 1391 of yacc.c  */
#line 154 "gpparser.y"
	{ freeASTAtom((yyvaluep->atom_exp)); };

/* Line 1391 of yacc.c  */
#line 1914 "parser.c"
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
#line 215 "gpparser.y"
    { gp_rule = (yyvsp[(2) - (2)].rule); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 216 "gpparser.y"
    { gp_program = (yyvsp[(2) - (2)].list); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 217 "gpparser.y"
    { ast_host_graph = (yyvsp[(2) - (2)].graph); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 220 "gpparser.y"
    { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].decl), NULL); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 222 "gpparser.y"
    { (yyval.list) = addASTDecl(GLOBAL_DECLARATIONS, 
                                               (yylsp[(2) - (2)]), (yyvsp[(2) - (2)].decl), (yyvsp[(1) - (2)].list)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 225 "gpparser.y"
    { (yyval.decl) = newASTMainDecl((yyloc), (yyvsp[(1) - (1)].command)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 226 "gpparser.y"
    { (yyval.decl) = newASTProcedureDecl((yyloc), (yyvsp[(1) - (1)].proc)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 227 "gpparser.y"
    { (yyval.decl) = newASTRuleDecl((yyloc), (yyvsp[(1) - (1)].rule)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 229 "gpparser.y"
    { (yyval.command) = newASTCommandSequence((yylsp[(1) - (3)]), (yyvsp[(3) - (3)].list)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 231 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].id), NULL, 
                                               newASTCommandSequence((yylsp[(3) - (3)]) ,(yyvsp[(3) - (3)].list)));
					  if((yyvsp[(1) - (3)].id)) free((yyvsp[(1) - (3)].id)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 236 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)].list), 
                                               newASTCommandSequence((yylsp[(6) - (6)]), (yyvsp[(6) - (6)].list)));
				          if((yyvsp[(1) - (6)].id)) free((yyvsp[(1) - (6)].id)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 241 "gpparser.y"
    { (yyval.proc) = newASTProcedure((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)].list), 
                                               newASTCommandSequence((yylsp[(6) - (6)]), (yyvsp[(6) - (6)].list)));
                                          report_warning("Procedure names must "
 					   "start with an upper-case letter."); 
					  if((yyvsp[(1) - (6)].id)) free((yyvsp[(1) - (6)].id)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 247 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 248 "gpparser.y"
    { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[(2) - (2)]), 
                                               newASTRuleDecl((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].rule)), (yyvsp[(1) - (2)].list)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 250 "gpparser.y"
    { (yyval.list) = addASTDecl(LOCAL_DECLARATIONS, (yylsp[(2) - (2)]),
                                               newASTProcedureDecl((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].proc)), (yyvsp[(1) - (2)].list)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 253 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].command), NULL); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 254 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].command), (yyvsp[(1) - (3)].list)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 256 "gpparser.y"
    { (yyval.list) = addASTCommand((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].command), (yyvsp[(1) - (3)].list));
                                          report_warning("Incorrect use of comma "
					    "to separate commands. Perhaps you "
					    "meant to use a semicolon?"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 262 "gpparser.y"
    { (yyval.command) = newASTOrStmt((yyloc), (yyvsp[(1) - (3)].command), (yyvsp[(3) - (3)].command)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 263 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), (yyvsp[(4) - (4)].command), newASTSkip((yyloc))); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 265 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(6) - (6)].command)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 268 "gpparser.y"
    { (yyval.command) = newASTCondBranch(IF_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), newASTSkip((yyloc)), (yyvsp[(4) - (4)].command));
                                          report_warning("No 'then' clause in if "
						         "statement."); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 272 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (2)].command), newASTSkip((yyloc)), newASTSkip((yyloc))); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 274 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), (yyvsp[(4) - (4)].command), newASTSkip((yyloc))); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 276 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                               (yyvsp[(2) - (4)].command), newASTSkip((yyloc)), (yyvsp[(4) - (4)].command)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 278 "gpparser.y"
    { (yyval.command) = newASTCondBranch(TRY_STATEMENT, (yyloc),
                                                (yyvsp[(2) - (6)].command), (yyvsp[(4) - (6)].command), (yyvsp[(6) - (6)].command)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 282 "gpparser.y"
    { (yyval.command) = newASTCommandSequence((yyloc), (yyvsp[(2) - (3)].list)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 283 "gpparser.y"
    { (yyval.command) = newASTAlap((yyloc), 
                                               newASTCommandSequence((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].list))); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 287 "gpparser.y"
    { (yyval.command) = NULL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 289 "gpparser.y"
    { (yyval.command) = newASTAlap((yyloc), (yyvsp[(1) - (2)].command)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 290 "gpparser.y"
    { (yyval.command) = newASTSkip((yyloc)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 291 "gpparser.y"
    { (yyval.command) = newASTEmptyStatement((yyloc), FAIL_STATEMENT); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 292 "gpparser.y"
    { (yyval.command) = newASTEmptyStatement((yyloc), BREAK_STATEMENT); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 294 "gpparser.y"
    { (yyval.command) = newASTRuleSetCall((yyloc), (yyvsp[(1) - (1)].list)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 295 "gpparser.y"
    { (yyval.command) = newASTRuleCall((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 296 "gpparser.y"
    { (yyval.command) = newASTProcCall((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 298 "gpparser.y"
    { (yyval.list) = (yyvsp[(2) - (3)].list); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 301 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 303 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL);
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 305 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list)); 
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 308 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL);
                                          report_warning("Procedure name used in "
					   "a rule set. Rule names must start "
					   "with a lower-case letter.");
				          if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 313 "gpparser.y"
    { (yyval.list) = addASTRule((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list));
                                          report_warning("Incorrect use of semicolon "
					   "in a rule set. Perhaps you meant to "
					   "use a comma?"); 
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 322 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (9)]), (yyvsp[(1) - (9)].id), (yyvsp[(3) - (9)].list), (yyvsp[(5) - (9)].graph), (yyvsp[(7) - (9)].graph), (yyvsp[(8) - (9)].list), (yyvsp[(9) - (9)].cond_exp)); 
					  if((yyvsp[(1) - (9)].id)) free((yyvsp[(1) - (9)].id)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 325 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (8)]), (yyvsp[(1) - (8)].id), NULL, (yyvsp[(4) - (8)].graph), (yyvsp[(6) - (8)].graph), (yyvsp[(7) - (8)].list), (yyvsp[(8) - (8)].cond_exp));
					  if((yyvsp[(1) - (8)].id)) free((yyvsp[(1) - (8)].id)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 329 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (9)]), (yyvsp[(1) - (9)].id), (yyvsp[(3) - (9)].list), (yyvsp[(5) - (9)].graph), (yyvsp[(7) - (9)].graph), (yyvsp[(8) - (9)].list), (yyvsp[(9) - (9)].cond_exp)); 
                                          report_warning("Rule names must "
 					   "start with a lower-case letter."
				 	   "letter.");
					  if((yyvsp[(1) - (9)].id)) free((yyvsp[(1) - (9)].id)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 338 "gpparser.y"
    { (yyval.rule) = newASTRule((yylsp[(1) - (10)]), (yyvsp[(1) - (10)].id), (yyvsp[(3) - (10)].list), (yyvsp[(6) - (10)].graph), (yyvsp[(8) - (10)].graph), (yyvsp[(9) - (10)].list), (yyvsp[(10) - (10)].cond_exp));  
                                          report_warning("Semicolon at the end "
					    "of a rule's variable list");
					  if((yyvsp[(1) - (10)].id)) free((yyvsp[(1) - (10)].id)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 344 "gpparser.y"
    { (yyval.list) = addASTVariableDecl((yyvsp[(3) - (3)].list_type), (yyloc), (yyvsp[(1) - (3)].list), NULL); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 349 "gpparser.y"
    { (yyloc).first_column = (yylsp[(3) - (5)]).first_column;
				          (yyloc).first_line = (yylsp[(3) - (5)]).first_line;
					  (yyloc).last_column = (yylsp[(5) - (5)]).last_column;
				          (yyloc).last_column = (yylsp[(5) - (5)]).last_column;
					  (yyval.list) = addASTVariableDecl((yyvsp[(5) - (5)].list_type), (yyloc), (yyvsp[(3) - (5)].list), (yyvsp[(1) - (5)].list)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 355 "gpparser.y"
    { (yyval.list) = addASTVariable((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL); 
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 357 "gpparser.y"
    { (yyval.list) = addASTVariable((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list)); 
		 	                  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 360 "gpparser.y"
    { (yyval.list) = NULL; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 361 "gpparser.y"
    { (yyval.list) = (yyvsp[(4) - (5)].list); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 364 "gpparser.y"
    { report_warning("Error in an interface list.");  
                                          (yyval.list) = NULL; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 367 "gpparser.y"
    { (yyval.list) = addASTNodeID((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].id), NULL); 
					  if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 369 "gpparser.y"
    { (yyval.list) = addASTNodeID((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].id), (yyvsp[(1) - (3)].list));
					  if((yyvsp[(3) - (3)].id)) free((yyvsp[(3) - (3)].id)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 372 "gpparser.y"
    { (yyval.list_type) = INT_DECLARATIONS; }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 373 "gpparser.y"
    { (yyval.list_type) = CHAR_DECLARATIONS; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 374 "gpparser.y"
    { (yyval.list_type) = STRING_DECLARATIONS; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 375 "gpparser.y"
    { (yyval.list_type) = ATOM_DECLARATIONS; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 376 "gpparser.y"
    { (yyval.list_type) = LIST_DECLARATIONS; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 381 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 382 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 383 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (4)].list), NULL); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 384 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (6)].list), NULL); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 385 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (5)].list), (yyvsp[(4) - (5)].list)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 387 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (7)].list), (yyvsp[(6) - (7)].list)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 389 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 390 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].list)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 392 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (6)]), is_root, (yyvsp[(2) - (6)].id), (yyvsp[(5) - (6)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (6)].id)) free((yyvsp[(2) - (6)].id)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 396 "gpparser.y"
    { (yyval.node) = newASTNode((yylsp[(2) - (7)]), is_root, (yyvsp[(2) - (7)].id), (yyvsp[(5) - (7)].label)); 
 					  is_root = false; 	
					  if((yyvsp[(2) - (7)].id)) free((yyvsp[(2) - (7)].id)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 399 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].edge), NULL); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 400 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].edge), (yyvsp[(1) - (2)].list)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 403 "gpparser.y"
    { (yyval.edge) = newASTEdge((yylsp[(2) - (10)]), is_bidir, (yyvsp[(2) - (10)].id), (yyvsp[(5) - (10)].id), (yyvsp[(7) - (10)].id), (yyvsp[(9) - (10)].label));
                                          is_bidir = false; if((yyvsp[(2) - (10)].id)) free((yyvsp[(2) - (10)].id)); 
					  if((yyvsp[(5) - (10)].id)) free((yyvsp[(5) - (10)].id)); if((yyvsp[(7) - (10)].id)) free((yyvsp[(7) - (10)].id)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 408 "gpparser.y"
    { }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 409 "gpparser.y"
    { }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 410 "gpparser.y"
    { }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 411 "gpparser.y"
    { }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 412 "gpparser.y"
    { }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 413 "gpparser.y"
    { }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 414 "gpparser.y"
    { }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 415 "gpparser.y"
    { }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 416 "gpparser.y"
    { }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 420 "gpparser.y"
    { is_root = true; }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 423 "gpparser.y"
    { is_bidir = true; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 428 "gpparser.y"
    { (yyval.cond_exp) = NULL; }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 429 "gpparser.y"
    { (yyval.cond_exp) = (yyvsp[(2) - (2)].cond_exp); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 431 "gpparser.y"
    { (yyval.cond_exp) = newASTSubtypePred((yyvsp[(1) - (4)].check_type), (yyloc), (yyvsp[(3) - (4)].id)); 
					  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 434 "gpparser.y"
    { (yyval.cond_exp) = newASTEdgePred((yyloc), (yyvsp[(3) - (7)].id), (yyvsp[(5) - (7)].id), (yyvsp[(6) - (7)].label)); 
					  if((yyvsp[(3) - (7)].id)) free((yyvsp[(3) - (7)].id)); if((yyvsp[(5) - (7)].id)) free((yyvsp[(5) - (7)].id)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 436 "gpparser.y"
    { (yyval.cond_exp) = newASTListComparison(EQUAL, (yyloc), (yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 437 "gpparser.y"
    { (yyval.cond_exp) = newASTListComparison(NOT_EQUAL, (yyloc), (yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 438 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(GREATER, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 439 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(GREATER_EQUAL, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 440 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(LESS, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 441 "gpparser.y"
    { (yyval.cond_exp) = newASTAtomComparison(LESS_EQUAL, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 442 "gpparser.y"
    { (yyval.cond_exp) = newASTNotExp((yyloc), (yyvsp[(2) - (2)].cond_exp)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 443 "gpparser.y"
    { (yyval.cond_exp) = newASTBinaryExp(BOOL_OR, (yyloc), (yyvsp[(1) - (3)].cond_exp), (yyvsp[(3) - (3)].cond_exp)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 444 "gpparser.y"
    { (yyval.cond_exp) = newASTBinaryExp(BOOL_AND, (yyloc), (yyvsp[(1) - (3)].cond_exp), (yyvsp[(3) - (3)].cond_exp)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 445 "gpparser.y"
    { (yyval.cond_exp) = (yyvsp[(2) - (3)].cond_exp); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 447 "gpparser.y"
    { (yyval.check_type) = INT_CHECK; }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 448 "gpparser.y"
    { (yyval.check_type) = CHAR_CHECK; }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 449 "gpparser.y"
    { (yyval.check_type) = STRING_CHECK; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 450 "gpparser.y"
    { (yyval.check_type) = ATOM_CHECK; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 452 "gpparser.y"
    { (yyval.label) = NULL; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 453 "gpparser.y"
    { (yyval.label) = (yyvsp[(2) - (2)].label); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 457 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, (yyvsp[(1) - (1)].list)); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 458 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, NULL); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 459 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 460 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 462 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 463 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 466 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].atom_exp), NULL); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 467 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].atom_exp), (yyvsp[(1) - (3)].list)); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 469 "gpparser.y"
    { (yyval.list) = (yyvsp[(1) - (3)].list);
    					  report_warning("Empty symbol in the "
     					                 "middle of a list.\n"); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 474 "gpparser.y"
    { (yyval.atom_exp) = newASTVariable((yyloc), (yyvsp[(1) - (1)].id)); if((yyvsp[(1) - (1)].id)) free((yyvsp[(1) - (1)].id)); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 475 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), (yyvsp[(1) - (1)].num)); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 476 "gpparser.y"
    { (yyval.atom_exp) = newASTString((yyloc), (yyvsp[(1) - (1)].str)); if((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 477 "gpparser.y"
    { (yyval.atom_exp) = newASTDegreeOp(INDEGREE, (yyloc), (yyvsp[(3) - (4)].id)); 
					  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 479 "gpparser.y"
    { (yyval.atom_exp) = newASTDegreeOp(OUTDEGREE, (yyloc), (yyvsp[(3) - (4)].id)); 
				 	  if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 481 "gpparser.y"
    { (yyval.atom_exp) = newASTLength((yyloc), (yyvsp[(3) - (4)].id)); if((yyvsp[(3) - (4)].id)) free((yyvsp[(3) - (4)].id)); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 482 "gpparser.y"
    { (yyval.atom_exp) = newASTNegExp((yyloc), (yyvsp[(2) - (2)].atom_exp)); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 483 "gpparser.y"
    { (yyval.atom_exp) = (yyvsp[(2) - (3)].atom_exp); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 484 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(ADD, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp));  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 485 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(SUBTRACT, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 486 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(MULTIPLY, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 487 "gpparser.y"
    { (yyval.atom_exp) = newASTBinaryOp(DIVIDE, (yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 488 "gpparser.y"
    { (yyval.atom_exp) = newASTConcat((yyloc), (yyvsp[(1) - (3)].atom_exp), (yyvsp[(3) - (3)].atom_exp)); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 495 "gpparser.y"
    { char id[64]; int write;
                            write = snprintf(id, 64, "%d", (yyvsp[(1) - (1)].num));
                            if (write < 0) {
                                yyerror("Node ID conversion failed.");
                                exit(1);
                            }
                            else (yyval.id) = strdup(id);
                        }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 504 "gpparser.y"
    { char id[64]; int write;
                            write = snprintf(id, 64, "%d", (yyvsp[(1) - (1)].num));
                            if (write < 0) {
                                yyerror("Edge ID conversion failed.");
                                exit(1);
                            }
                            else (yyval.id) = strdup(id);
                        }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 521 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 522 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), NULL, NULL); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 523 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (4)].list), NULL); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 525 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (6)].list), NULL); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 527 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(2) - (5)].list), (yyvsp[(4) - (5)].list)); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 529 "gpparser.y"
    { (yyval.graph) = newASTGraph((yyloc), (yyvsp[(4) - (7)].list), (yyvsp[(6) - (7)].list)); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 531 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 532 "gpparser.y"
    { (yyval.list) = addASTNode((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].list)); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 535 "gpparser.y"
    { char buffer1[12];
                               snprintf(buffer1, 12,"%d",(yyvsp[(2) - (6)].num));
                               (yyval.node) = newASTNode((yylsp[(2) - (6)]), is_root, buffer1, (yyvsp[(5) - (6)].label));
                      is_root = false; }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 540 "gpparser.y"
    { char buffer1[12];
                               snprintf(buffer1, 12,"%d",(yyvsp[(2) - (7)].num));
                               (yyval.node) = newASTNode((yylsp[(2) - (7)]), is_root, buffer1, (yyvsp[(5) - (7)].label));
                                is_root = false; }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 545 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].edge), NULL); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 546 "gpparser.y"
    { (yyval.list) = addASTEdge((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].edge), (yyvsp[(1) - (2)].list)); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 549 "gpparser.y"
    { char buffer1[12];
                       snprintf(buffer1, 12,"%d",(yyvsp[(2) - (9)].num));
                      char buffer2[12];
                       snprintf(buffer2, 12,"%d",(yyvsp[(4) - (9)].num));
                      char buffer3[12];
                       snprintf(buffer3, 12,"%d",(yyvsp[(6) - (9)].num));

                                (yyval.edge) = newASTEdge((yylsp[(2) - (9)]), false, buffer1, buffer2 , buffer3, (yyvsp[(8) - (9)].label));
                            }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 560 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, (yyvsp[(1) - (1)].list)); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 561 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), NONE, NULL); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 562 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), (yyvsp[(1) - (3)].list)); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 563 "gpparser.y"
    { (yyval.label) = newASTLabel((yyloc), (yyvsp[(3) - (3)].mark), NULL); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 565 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].atom_exp), NULL); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 566 "gpparser.y"
    { (yyval.list) = addASTAtom((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].atom_exp), (yyvsp[(1) - (3)].list)); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 568 "gpparser.y"
    { (yyval.list) = (yyvsp[(1) - (3)].list);
					  report_warning("Error: empty symbol in the "
     					                 "middle of a list.\n"); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 572 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), (yyvsp[(1) - (1)].num)); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 573 "gpparser.y"
    { (yyval.atom_exp) = newASTNumber((yyloc), -((yyvsp[(2) - (2)].num))); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 574 "gpparser.y"
    { (yyval.atom_exp) = newASTString((yyloc), (yyvsp[(1) - (1)].str)); if((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); }
    break;



/* Line 1806 of yacc.c  */
#line 3396 "parser.c"
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
#line 576 "gpparser.y"


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
        


