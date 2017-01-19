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


/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2017
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int mylineno = 1; /* line number; counts fresh in every new file */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct libfile_name *current_libfile; /*  defined in main.c: name of currently parsed file */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

void report_missing(int severity,char *text) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    error(severity,text);
    string[0]='\0';
    if (missing_endif)
      sprintf(string,"if statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    else if (missing_next)
      sprintf(string,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    else if (missing_wend)
      sprintf(string,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    else if (missing_until)
      sprintf(string,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    else if (missing_loop)
      sprintf(string,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    if (string[0]) error(severity,string);
  }
}
     



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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.h".  */
#ifndef YY_YY_BISON_H_INCLUDED
# define YY_YY_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tFNUM = 258,
    tSYMBOL = 259,
    tSTRSYM = 260,
    tDOCU = 261,
    tDIGITS = 262,
    tSTRING = 263,
    tFOR = 264,
    tTO = 265,
    tSTEP = 266,
    tNEXT = 267,
    tWHILE = 268,
    tWEND = 269,
    tREPEAT = 270,
    tUNTIL = 271,
    tIMPORT = 272,
    tGOTO = 273,
    tGOSUB = 274,
    tLABEL = 275,
    tON = 276,
    tSUB = 277,
    tENDSUB = 278,
    tLOCAL = 279,
    tSTATIC = 280,
    tEXPORT = 281,
    tERROR = 282,
    tEXECUTE = 283,
    tEXECUTE2 = 284,
    tCOMPILE = 285,
    tRUNTIME_CREATED_SUB = 286,
    tINTERRUPT = 287,
    tBREAK = 288,
    tCONTINUE = 289,
    tSWITCH = 290,
    tSEND = 291,
    tCASE = 292,
    tDEFAULT = 293,
    tLOOP = 294,
    tDO = 295,
    tSEP = 296,
    tEOPROG = 297,
    tIF = 298,
    tTHEN = 299,
    tELSE = 300,
    tELSIF = 301,
    tENDIF = 302,
    tUSING = 303,
    tPRINT = 304,
    tINPUT = 305,
    tRETURN = 306,
    tDIM = 307,
    tEND = 308,
    tEXIT = 309,
    tAT = 310,
    tSCREEN = 311,
    tREVERSE = 312,
    tCOLOUR = 313,
    tBACKCOLOUR = 314,
    tAND = 315,
    tOR = 316,
    tNOT = 317,
    tEOR = 318,
    tNEQ = 319,
    tLEQ = 320,
    tGEQ = 321,
    tLTN = 322,
    tGTN = 323,
    tEQU = 324,
    tPOW = 325,
    tREAD = 326,
    tDATA = 327,
    tRESTORE = 328,
    tOPEN = 329,
    tCLOSE = 330,
    tSEEK = 331,
    tTELL = 332,
    tAS = 333,
    tREADING = 334,
    tWRITING = 335,
    tORIGIN = 336,
    tWINDOW = 337,
    tDOT = 338,
    tLINE = 339,
    tCIRCLE = 340,
    tTRIANGLE = 341,
    tTEXT = 342,
    tCLEAR = 343,
    tFILL = 344,
    tPRINTER = 345,
    tWAIT = 346,
    tBELL = 347,
    tLET = 348,
    tARDIM = 349,
    tARSIZE = 350,
    tBIND = 351,
    tRECT = 352,
    tGETBIT = 353,
    tPUTBIT = 354,
    tGETCHAR = 355,
    tPUTCHAR = 356,
    tNEW = 357,
    tCURVE = 358,
    tSIN = 359,
    tASIN = 360,
    tCOS = 361,
    tACOS = 362,
    tTAN = 363,
    tATAN = 364,
    tEXP = 365,
    tLOG = 366,
    tSQRT = 367,
    tSQR = 368,
    tMYEOF = 369,
    tABS = 370,
    tSIG = 371,
    tINT = 372,
    tFRAC = 373,
    tMOD = 374,
    tRAN = 375,
    tVAL = 376,
    tLEFT = 377,
    tRIGHT = 378,
    tMID = 379,
    tLEN = 380,
    tMIN = 381,
    tMAX = 382,
    tSTR = 383,
    tINKEY = 384,
    tCHR = 385,
    tASC = 386,
    tHEX = 387,
    tDEC = 388,
    tBIN = 389,
    tUPPER = 390,
    tLOWER = 391,
    tMOUSEX = 392,
    tMOUSEY = 393,
    tMOUSEB = 394,
    tMOUSEMOD = 395,
    tTRIM = 396,
    tLTRIM = 397,
    tRTRIM = 398,
    tINSTR = 399,
    tRINSTR = 400,
    tSYSTEM = 401,
    tSYSTEM2 = 402,
    tPEEK = 403,
    tPEEK2 = 404,
    tPOKE = 405,
    tDATE = 406,
    tTIME = 407,
    tTOKEN = 408,
    tTOKENALT = 409,
    tSPLIT = 410,
    tSPLITALT = 411,
    tGLOB = 412,
    UMINUS = 413
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int sep;              /* number of newlines */
  char *string;         /* quoted string */
  char *symbol;         /* general symbol */
  char *digits;         /* string of digits */
  char *docu;		/* embedded documentation */


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */



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
#define YYFINAL  248
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  427
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1002

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   413

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   167,     2,     2,     2,     2,
     163,   164,   160,   159,   166,   158,     2,   161,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   165,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   162
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   148,   149,   150,   149,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   171,   172,   172,   173,
     174,   175,   176,   177,   178,   179,   179,   181,   181,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     193,   194,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   211,   212,   213,   214,   215,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   262,   263,
     264,   265,   266,   270,   271,   272,   273,   274,   275,   278,
     279,   282,   283,   284,   285,   286,   289,   290,   293,   294,
     297,   298,   299,   300,   301,   302,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   339,   340,
     343,   343,   344,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   377,   380,   383,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   448,   449,   450,
     453,   454,   457,   458,   461,   462,   463,   464,   467,   470,
     473,   473,   476,   477,   478,   481,   482,   485,   486,   489,
     485,   494,   495,   498,   499,   502,   503,   504,   505,   508,
     509,   512,   513,   514,   515,   518,   519,   522,   523,   524,
     525,   528,   529,   530,   533,   534,   535,   536,   539,   540,
     544,   558,   539,   563,   564,   567,   568,   571,   572,   577,
     577,   581,   582,   585,   586,   590,   592,   591,   596,   597,
     597,   601,   601,   607,   608,   612,   613,   612,   619,   620,
     624,   624,   629,   630,   634,   635,   635,   637,   634,   641,
     642,   645,   645,   649,   650,   653,   655,   657,   654,   661,
     662,   665,   666,   666,   669,   670,   672,   673,   677,   678,
     681,   682,   684,   685,   689,   690,   691,   692,   695,   696,
     697,   698,   699,   702,   703,   704,   707,   707,   708,   708,
     709,   709,   710,   710,   711,   711,   714,   715,   718,   719,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   734,   735,   737,   738,   741,   742
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tFNUM", "tSYMBOL", "tSTRSYM", "tDOCU",
  "tDIGITS", "tSTRING", "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND",
  "tREPEAT", "tUNTIL", "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON",
  "tSUB", "tENDSUB", "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE",
  "tEXECUTE2", "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK",
  "tCONTINUE", "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO",
  "tSEP", "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tUSING",
  "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT", "tSCREEN",
  "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT", "tEOR",
  "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN", "tEQU", "tPOW", "tREAD", "tDATA",
  "tRESTORE", "tOPEN", "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING",
  "tWRITING", "tORIGIN", "tWINDOW", "tDOT", "tLINE", "tCIRCLE",
  "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL", "tPRINTER", "tWAIT", "tBELL",
  "tLET", "tARDIM", "tARSIZE", "tBIND", "tRECT", "tGETBIT", "tPUTBIT",
  "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tSIN", "tASIN", "tCOS",
  "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF",
  "tABS", "tSIG", "tINT", "tFRAC", "tMOD", "tRAN", "tVAL", "tLEFT",
  "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR",
  "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY",
  "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tDATE", "tTIME",
  "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "'-'", "'+'",
  "'*'", "'/'", "UMINUS", "'('", "')'", "';'", "','", "'#'", "$accept",
  "program", "statement_list", "$@1", "$@2", "statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "clear_fill_clause", "string_assignment",
  "to", "open_clause", "seek_clause", "string_scalar_or_array",
  "string_expression", "string_function", "assignment", "expression",
  "$@9", "$@10", "arrayref", "string_arrayref", "coordinates", "function",
  "const", "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@11", "calls", "call_item",
  "function_definition", "$@12", "$@13", "$@14", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@19",
  "sep_list", "number_or_string", "case_list", "$@20", "default", "$@21",
  "do_loop", "$@22", "loop", "while_loop", "$@23", "$@24", "wend",
  "repeat_loop", "$@25", "until", "if_clause", "$@26", "$@27", "$@28",
  "$@29", "endif", "short_if", "$@30", "else_part", "elsif_part", "$@31",
  "$@32", "maybe_then", "inputlist", "$@33", "input", "readlist",
  "readitem", "datalist", "printlist", "using", "inputbody", "$@34",
  "$@35", "$@36", "$@37", "$@38", "prompt", "printintro", "hashed_number",
  "goto_list", "gosub_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,    45,    43,
      42,    47,   413,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -719

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-719)))

#define YYTABLE_NINF -355

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3543,   -49,   -38,  -719,  -719,  -719,  -719,  -719,    83,    83,
      83,  2731,  -719,  -719,  -719,  3199,  -123,  -109,  3199,   133,
      82,  -719,  -719,  -719,  3045,     6,  -719,  3045,    73,  -719,
    3045,  3045,  3045,   108,    48,    83,  1617,  1082,  1931,    97,
    3045,  2574,  3045,    -8,    80,  3045,  -719,    23,  3199,  3199,
    3199,    96,    22,    64,    90,    98,   109,  1931,   214,   170,
    -719,   -52,  -719,  -719,  -719,  -719,   233,   254,  -719,   305,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  3045,  -719,  3199,
    -719,   339,   201,  3407,  -719,  -719,  -719,  -719,  -719,  -719,
     220,   256,  -719,  -719,   297,   327,    88,   349,   360,  3045,
     361,   368,   369,   370,   378,   381,   385,   395,   404,   405,
     408,   418,   420,   423,   424,   425,   426,   428,   429,   430,
     431,   432,   433,   438,   441,   445,   447,   449,   451,   457,
     460,   462,   468,   470,   471,   472,   473,   474,   475,   484,
     487,   488,   490,   491,   492,   493,   494,   495,   496,   499,
     503,   508,   509,   510,   511,   512,   517,   526,   527,   530,
    3045,  3045,   281,  -719,   439,  -719,  -719,  -719,  -719,   132,
     331,  3199,   279,  -719,  -719,   279,  -719,  -719,  3045,  3407,
     485,   531,   389,   539,    17,  3045,   -41,   281,   871,   540,
     541,   284,   871,   281,  1197,   281,  1265,   542,   543,   436,
    -719,  -719,   298,   298,  -719,  -719,   464,  -719,  3045,  3199,
    3045,     3,   871,   466,  -719,  -719,  -719,  -719,   482,  3199,
    1398,  -719,  3045,  -719,    -3,   544,  -719,  -719,  3045,  2888,
    -719,  -719,   871,  -719,  -719,   233,   254,   279,    -6,    -6,
    -719,   529,   529,   529,  2088,  3199,    51,   546,  -719,  -719,
     572,  3045,  3045,  3045,  3045,  3199,  -719,   871,   545,  3045,
     279,   550,   515,  3045,    49,  -719,  -719,  -719,  -719,  3045,
    3045,  1407,  3045,  1774,  1931,   377,   377,  3045,  3045,  3045,
    3045,  3045,  3045,  3045,  3045,  3045,  3045,  3045,  3045,  1931,
    3045,  3045,  3045,  3045,  3045,  2250,  3199,  3199,  3199,  3199,
    3199,  3045,  3045,  3045,  2412,  3045,  3199,  3045,  3199,  3045,
    3199,  3199,   313,  1152,  1248,  1387,  3199,  3199,  3199,  3199,
    3199,  3199,  3199,  1931,  3199,   553,   564,  3199,   529,  3199,
     529,  3199,   556,   173,  1636,  3199,  3199,  3199,  3199,  3199,
    3199,  3199,  -719,  -719,  -719,  -719,  3045,  3045,  3045,  3045,
    3045,  3045,  3045,  3045,  3045,  3045,  3045,   566,   574,   575,
    -719,   579,   580,   583,  -719,  -134,   582,   588,   281,   871,
     667,   119,   663,  3679,  3045,   591,  3199,  -719,  -719,  3045,
     281,   631,   226,   592,    19,  -719,   730,  -719,  -719,   427,
    3045,  3045,  -719,  -719,   108,  -719,  -719,    50,  1429,   279,
     871,   373,  1519,  3045,   279,  3045,  -719,   -41,  -719,  -719,
    3045,  3199,  -719,  3045,    -3,  3045,  3045,   594,   593,   595,
     596,  -719,  4098,   -61,  3045,  3045,  -719,   597,    -3,    -3,
     871,   279,   467,  -719,   281,   871,   598,  -719,  -719,  -719,
    4109,   603,  -719,  -719,   604,   607,  1789,  1946,  2103,   608,
      28,   601,   609,   616,   620,   621,   629,   614,   618,    -3,
    2265,  4120,  4142,  4167,  4178,  4222,   655,  4244,   666,  4280,
    4291,   630,  4302,  4324,  4346,  4357,  2427,  -719,  4404,    29,
    -120,   -58,    25,    52,  2589,  2746,   808,  -719,  4426,  4459,
      66,  4470,    92,  4481,   117,   158,  -719,   253,  -719,   269,
    -719,   275,  -719,   287,   302,   304,   311,    38,    39,   325,
     351,   358,   632,   101,  -719,  -719,    77,   -64,   103,    62,
     104,  -719,  -719,   279,   279,   279,   279,   279,   279,  -719,
      83,    83,  3045,  3045,   320,   337,    87,   458,   -10,    16,
    -719,   -55,   -55,   556,   556,  -719,  -719,   132,  -719,  -719,
     331,  -719,  -719,  -719,   757,  -719,  -719,  -719,  -719,   755,
    2903,  3045,   107,  4506,  3254,  -719,  -719,  3045,  3045,  -719,
    -719,  3045,  -719,   469,   639,   640,   642,   644,  3064,  3811,
     645,   646,  -719,  -719,  -719,  3045,   734,   740,  -719,   145,
    3858,   871,  -719,  -719,   154,  -719,  3045,  3881,  3914,  -719,
    3045,  3045,  3045,  -719,  -719,   281,   871,   281,   871,  3407,
    3045,  3045,  3045,  -719,  -719,  -719,  3045,  3045,  -719,  3045,
    -719,  -719,  3045,  3045,  3045,  -719,  -719,  3199,  3115,  -719,
     656,   658,  -719,  -719,  3045,  3045,  3045,  3045,  -719,  -719,
    -719,  -719,  -719,  -719,  3045,  -719,  -719,  3045,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  3045,  -719,  -719,  3045,  3045,
    3045,  -719,  3045,  3045,  -719,  3199,  -719,  -719,  -719,  -719,
    -719,  3045,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  3199,  3199,  -719,  -719,  -719,  -719,  -719,  3199,
     803,  -719,  3199,   803,  -719,  3199,  3199,  -719,   657,  -719,
     662,  1407,  3447,   665,   669,  -719,   671,   672,  -719,  -719,
     450,  3407,  -719,  3045,  3925,   776,  3199,  -719,  3199,   279,
     281,   631,  3936,   469,   469,  4528,   675,   676,  -719,   674,
    -719,  -719,  -719,  -719,  3045,  3045,  -719,  -719,  3961,  1931,
    1931,  3199,  3199,  3199,  -719,  3045,  3045,   677,  4539,  4583,
     860,  -719,   871,    -3,  -719,   681,  -719,    74,  3407,  4608,
    4641,  4652,  4663,   352,   682,   174,  -719,  -719,  4685,  4710,
     683,    63,  4721,  4765,  4787,  4823,  4834,   934,  4845,  4867,
     175,  4889,   203,   204,   354,    86,   355,   116,   371,   383,
      83,    83,  -719,  -719,  -719,  -719,  3045,   804,   812,   810,
    4900,  3045,   686,   397,   212,  -719,  3045,  -719,  -719,  -719,
    -719,  -719,  -719,   688,   689,   871,   871,  3199,  -719,  -719,
     279,   279,   160,  3984,   871,  -719,   785,   786,   787,  3045,
    3045,   497,  3045,    24,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  3199,  -719,  -719,  -719,  3045,  -719,  -719,  -719,  -719,
    -719,  -719,  3045,  -719,  -719,  -719,  3199,  -719,  -719,  3045,
    -719,  3045,  -719,  -719,  3199,  -719,  -719,  3199,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,   813,   463,  4947,  3045,   805,
    3199,  4969,   469,   694,   697,   469,  -719,  -719,   279,  3199,
    3199,  3199,  3199,  3199,  5002,  -719,   699,   700,   208,  -719,
     333,  -719,  -719,  -719,   398,  3995,  5013,   400,  5024,  5049,
     401,   410,  3407,  3815,  3045,   820,  -719,   704,  -719,  4039,
     707,   411,  -719,  -719,  -719,  -719,  -719,   279,   279,   279,
     279,   279,   802,   715,   717,  -719,   497,  3045,  -719,  -719,
    3045,  -719,  -719,  -719,  -719,  -719,  -719,   810,   846,   617,
    3407,  -719,  3199,  3045,  3045,  -719,   730,  3199,  -719,  -719,
    3407,  -719,   871,  3407,  5071,  -719,  -719,   810,   535,   250,
    5082,  4064,   469,   279,    65,   810,  -719,  3407,  -719,  -719,
    -719,  -719,  3199,  -719,  3045,  -719,  -719,  -719,  -719,    10,
     810,   421,  5126,  -719,  -719,   880,   813,  -719,  -719,  -719,
    -719,  -719
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     108,     0,     0,   106,   318,   345,   350,    12,     0,     0,
       0,     0,    25,    27,   296,     0,     0,     0,     0,   297,
      19,    21,   329,   341,     0,   408,    49,    61,     0,   103,
     104,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     4,
       3,     0,     8,    40,    42,    10,    23,    24,    22,     0,
      14,    15,    18,    17,    16,    29,    30,     0,   280,     0,
     280,     0,     0,     7,   273,   272,    31,    32,    39,   270,
     189,   130,   271,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
     241,   244,   247,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,   202,   183,   188,   132,     0,
       0,     0,    13,   280,   280,    43,   298,    20,     0,     7,
     361,     0,   412,     0,     0,   388,   404,    63,    62,     0,
       0,    64,   105,    54,     0,    56,     0,   380,   382,    57,
     378,   384,     0,     0,   385,   267,    58,    60,     0,    90,
       0,     0,   423,     0,    87,    92,    80,    41,     0,     0,
       0,    68,     0,    51,    73,     0,    89,    88,     0,     0,
     111,   112,    93,     9,    11,     0,     0,   107,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     0,     0,     0,   287,   168,     0,   282,
     113,     0,     0,     0,     4,   280,   280,    33,    34,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    37,   172,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   301,   302,    26,
     299,   307,   308,    28,   305,     0,     0,     0,   334,   333,
       0,     4,     0,   108,     0,     0,     0,   409,   410,     0,
     391,   393,    46,     0,     0,    50,   406,   280,   280,     0,
       0,     0,   280,   280,     0,   269,   268,     0,     0,    91,
     422,     0,     0,     0,    67,     0,    72,   404,   120,   119,
       0,     0,    69,     0,    75,     0,     0,   128,     0,     0,
       0,    96,     0,     0,     0,     0,     5,     0,     0,     0,
     169,   118,     0,   278,   285,   286,   281,   283,   279,   319,
       0,     0,   352,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,   245,     0,
     248,     0,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   156,     0,     0,     0,     0,
       0,   135,   203,   197,   199,   201,   198,   200,   196,   134,
       0,     0,     0,     0,   176,   178,   180,   177,   179,   175,
     194,   191,   190,   192,   193,   280,   280,     0,   280,   280,
       0,    44,    45,   331,   335,   344,   343,   342,   355,     4,
       0,     0,     0,     0,     0,   389,    47,    48,     0,   396,
     398,     0,   407,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   379,   386,   387,     0,     0,     0,   123,   122,
     126,   206,    52,    70,    83,    74,     0,     0,     0,   280,
       0,     0,     0,    97,    98,    99,   100,   101,   102,     7,
       0,     0,     0,   293,   294,   288,     0,     0,   346,     0,
     260,   167,     0,     0,     0,   261,   262,     0,     0,   255,
       0,     0,   184,   185,     0,     0,     0,     0,   207,   208,
     209,   210,   211,   212,     0,   214,   215,     0,   217,   218,
     181,   221,   222,   219,   220,     0,   224,   229,     0,     0,
       0,   228,     0,     0,   140,     0,   145,   146,   230,   165,
     231,     0,   166,   147,   148,   240,   243,   246,   249,   151,
     149,   150,     0,     0,   152,   237,   239,   238,   157,     0,
       0,   160,     0,     0,   162,     0,     0,   424,    36,   426,
      38,   173,   171,     0,     0,   300,     0,     0,   306,   332,
     338,     7,   362,     0,     0,   413,     0,   411,     0,   394,
     392,   393,     0,     0,     0,     0,   374,   376,   405,   371,
     274,   276,   280,   280,     0,     0,   381,   383,    65,     0,
       0,     0,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     6,    81,     0,    86,     0,   284,     0,     7,     0,
       0,     0,     0,     0,     0,     0,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   304,   309,   310,     0,     0,     0,   356,
       0,     0,     0,     0,     0,   390,     0,   397,   399,   400,
     280,   280,   372,     0,     0,    53,    55,     0,   124,   125,
     121,   127,    84,    77,    78,   129,     0,     0,     0,     0,
       0,   311,     0,     4,   353,   252,   253,   254,   263,   264,
     265,     0,   186,   187,   163,     0,   213,   216,   223,   136,
     137,   139,     0,   226,   227,   141,     0,   232,   233,     0,
     235,     0,   158,   257,     0,   159,   259,     0,   161,   182,
     425,   427,   336,   339,   330,   365,   415,     0,     0,   414,
       0,     0,     0,     0,     0,     0,   275,   277,    66,     0,
       0,     0,     0,     0,     0,    82,   314,   315,     0,   312,
     325,   349,   348,   347,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   108,     0,   363,   419,     0,   416,     0,
       0,     0,   402,   401,   375,   377,   373,    85,    76,   116,
     117,   115,     0,     0,     0,   289,     0,     0,   320,   266,
       0,   138,   142,   234,   236,   256,   258,   337,     4,   369,
       7,   357,     0,     0,     0,   395,   406,     0,   316,   317,
       7,   313,   326,     7,     0,   370,   366,   364,     0,     0,
       0,     0,     0,   114,     4,   321,   164,     7,   359,   360,
     358,   420,     0,   417,     0,   403,   292,   291,   290,     0,
     367,     0,     0,   324,   323,   327,   365,   421,   418,   328,
     322,   368
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -719,  -719,   -70,  -719,  -719,   276,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,   839,  -228,  -719,  -719,   -73,   738,  -719,
     840,     5,  -719,  -719,   612,  -275,   -33,  -719,   498,   -31,
       9,  -719,     0,     2,   -63,  -719,  -719,   273,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   344,  -719,   342,  -719,
     -42,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,   100,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   -99,  -719,  -719,  -719,
    -718,  -719,  -719,  -719,   504,  -719,  -719,   179,   501,  -719,
    -719,  -719,  -719,  -719,   -54,  -719,    42,  -719,  -719
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   250,   609,    60,   169,   170,   530,   531,
     186,   407,    61,    62,   410,    63,    64,   418,   162,   163,
      65,   220,   533,   532,   455,   456,   221,   165,   204,   166,
      86,   191,   167,   168,   258,   259,   436,   437,    68,   432,
     755,   960,   988,   615,    69,   359,   360,   363,   364,   898,
     899,    70,    81,   617,   963,   989,   995,   938,  1000,    71,
     178,   554,   370,   710,   912,   798,   913,    72,   179,   557,
      73,    82,   758,   903,    74,    83,   443,    75,   372,   711,
     875,   968,   980,    76,   373,   951,   915,   977,   996,   966,
     728,   885,   729,   199,   200,   206,   382,   565,   385,   723,
     724,   882,   956,   386,   573,   185,   213,   698,   700
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   458,    67,   205,   408,   807,   808,   408,   224,   225,
     415,   416,   401,   264,   383,   352,   164,   261,    87,    88,
      77,   377,   993,   569,   378,   341,   570,     1,     2,   180,
     521,    79,   188,   251,   252,   192,   194,   196,   901,   341,
     173,   212,   212,   212,   207,   253,   658,   235,   226,   236,
     232,    89,   994,    89,   174,    92,   201,    92,   583,   351,
     352,   181,   212,   182,   183,   441,   902,   335,   336,   337,
     338,   339,   340,   408,   227,   228,   229,   189,   190,   217,
     218,   230,   257,    66,   832,    67,   352,    84,   986,   177,
      85,   442,   335,   336,   337,   338,   339,   340,   341,   247,
     691,   341,   692,   604,   271,   355,   356,   987,   659,   371,
     366,   367,   197,   198,    78,   335,   336,   337,   338,   339,
     340,   267,   268,   344,   345,    80,   384,   346,   347,   348,
     349,   350,   351,   352,   344,   345,   357,   358,   346,   347,
     348,   349,   350,   351,   352,    52,    53,    54,   353,   354,
     355,   356,   347,   341,   349,   350,   351,   352,   555,   176,
     409,   556,   341,   409,   923,   332,   334,   926,   231,   419,
     420,   395,   396,   184,   353,   354,   355,   356,   219,    66,
     379,    67,   571,   369,   341,   241,   596,   341,   341,   406,
     381,   660,   626,   657,   627,   412,   414,   341,   341,   240,
     611,   612,   444,   445,   682,   683,   202,   203,   202,   203,
     341,   341,   249,   398,   248,   400,   661,   424,   427,   428,
     429,   353,   354,   355,   356,   341,   694,   242,   695,   409,
     668,   636,   353,   354,   355,   356,   341,   335,   336,   337,
     338,   339,   340,   690,   459,   353,   354,   355,   356,   422,
     863,   341,   864,   243,   985,   517,   670,   519,   671,   430,
     341,   244,   341,   341,   435,   688,   341,   689,   440,   693,
     696,   715,   245,   716,   446,   447,   341,   448,   212,   212,
     866,   673,   867,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   212,   472,   473,   474,   475,   476,
     478,    89,   254,   559,   341,    92,   484,   485,   486,   488,
     489,   741,   491,   341,   493,   451,   452,   341,    91,   341,
     743,    93,   674,   255,   574,   575,   889,   256,   212,   580,
     581,   471,   341,   341,   341,   361,   362,   521,   840,   855,
     841,   856,    95,   262,   937,   335,   336,   337,   338,   339,
     340,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   341,   341,   263,   512,   205,   858,   860,   859,
     861,   341,   935,    66,   936,    67,   521,   593,   880,   560,
     595,   453,   454,    78,   563,   347,   348,   349,   350,   351,
     352,   566,   567,   344,   345,   578,   579,   346,   347,   348,
     349,   350,   351,   352,   349,   350,   351,   352,   590,   341,
     591,   105,   341,   106,   981,   785,   982,   675,   787,    80,
     597,   598,   335,   336,   337,   338,   339,   340,   341,   606,
     608,   576,   577,   676,   341,   125,   126,   127,   341,   677,
     341,   131,   132,   133,   375,   135,   341,   137,   138,   139,
     389,   678,   586,   587,   144,   145,   146,   342,   343,   149,
     265,   341,   152,   341,   153,   154,   679,   156,   680,   158,
     341,   613,   614,   726,   727,   681,   171,   496,   353,   354,
     355,   356,   703,   704,   341,   706,   707,   796,   797,   684,
     266,   353,   354,   355,   356,   353,   354,   355,   356,   344,
     345,   896,   897,   346,   347,   348,   349,   350,   351,   352,
     341,   341,   269,   341,   341,   685,   838,   341,   862,   865,
     916,   917,   686,   270,   272,   830,   350,   351,   352,  -354,
     341,   273,   274,   275,   417,   868,   747,   701,   702,   697,
     699,   276,   341,   845,   277,   344,   345,   869,   278,   346,
     347,   348,   349,   350,   351,   352,   341,   341,   279,   341,
     341,   879,   939,   744,   942,   945,   714,   280,   281,   341,
     341,   282,   721,   722,   946,   955,   725,   978,   753,   754,
     341,   283,   979,   284,   439,   997,   285,   286,   287,   288,
     738,   289,   290,   291,   292,   293,   294,   353,   354,   355,
     356,   295,   394,   770,   296,   748,   749,   750,   297,    66,
     298,    67,   299,   426,   300,   752,   353,   354,   355,   356,
     301,   435,   757,   302,   759,   303,   352,   760,   761,   762,
     397,   304,   402,   305,   306,   307,   308,   309,   310,   768,
     769,   799,   771,   353,   354,   355,   356,   311,   403,   772,
     312,   313,   773,   314,   315,   316,   317,   318,   319,   320,
     774,   965,   321,   775,   776,   777,   322,   778,   779,   813,
     814,   323,   324,   325,   326,   327,   781,   344,   345,   564,
     328,   346,   347,   348,   349,   350,   351,   352,   833,   329,
     330,   344,   345,   331,   374,   346,   347,   348,   349,   350,
     351,   352,   376,   387,   388,   392,   393,   558,   553,   433,
     411,    66,   425,    67,   438,   344,   345,   514,   800,   346,
     347,   348,   349,   350,   351,   352,   344,   345,   515,   545,
     346,   347,   348,   349,   350,   351,   352,   546,   572,   815,
     816,   547,   548,   549,   212,   212,   551,   883,   884,   550,
     823,   824,   552,   172,   561,   568,   175,   599,    66,   600,
      67,   601,   602,   610,   616,   187,   619,   628,   620,   193,
     195,   621,   625,   629,   211,   353,   354,   355,   356,   630,
     634,   818,   819,   631,   635,   632,   237,   238,   239,   353,
     354,   355,   356,   633,   650,   246,   687,   895,   709,   870,
     871,   369,   712,   730,   731,   732,   877,   733,   454,   736,
     737,   881,   739,   353,   354,   355,   356,   260,   740,   643,
     766,   644,   767,   790,   353,   354,   355,   356,   791,   792,
     646,   802,   647,   793,   894,   794,   795,   900,   810,   811,
     812,   825,   947,   948,   831,   873,   839,   844,   874,   878,
     905,    -4,   886,   887,   891,   892,   893,   906,   924,   914,
     920,   925,   933,   934,   908,   950,   909,   952,   344,   345,
     954,   957,   346,   347,   348,   349,   350,   351,   352,   958,
     967,   959,  -340,   919,   999,   751,   233,   234,   457,   756,
     974,   705,   708,   975,   961,   584,   872,  1001,   582,   333,
     805,     0,   972,     0,     0,     0,     0,   990,   592,   365,
       0,     0,    66,    66,    67,    67,   368,     0,     0,   949,
     344,   345,     0,   380,   346,   347,   348,   349,   350,   351,
     352,   344,   345,     0,     0,   346,   347,   348,   349,   350,
     351,   352,   962,     0,     0,   964,     0,   399,     0,     0,
      66,     0,    67,     0,     0,     0,     0,   404,   970,   971,
      66,     0,    67,    66,     0,    67,   353,   354,   355,   356,
       0,     0,   664,     0,   665,     0,     0,    66,     0,    67,
       0,     0,     0,   423,     0,     0,     0,     0,     0,   992,
       0,     0,     0,   431,   344,   345,     0,   434,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,   353,   354,
     355,   356,     0,     0,   828,     0,   829,     0,     0,   353,
     354,   355,   356,     0,   479,   480,   481,   482,   483,     0,
       0,     0,     0,     0,   490,     0,   492,     0,   494,   495,
     497,   499,   501,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   513,     0,     0,   516,     0,   518,     0,   520,
       0,     0,     0,   523,   524,   525,   526,   527,   528,   529,
       0,     0,     0,     0,     0,    89,    90,    91,     0,    92,
      93,     0,   353,   354,   355,   356,     0,     0,   851,     0,
     852,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,   562,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,     0,    97,    98,    99,   100,     0,     0,     0,   594,
       0,     0,     0,     0,     0,     0,   101,    91,     0,   102,
      93,     0,   605,   607,   214,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,   103,   104,     0,     0,
     105,    95,   106,     0,     0,   216,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,     0,   210,
     105,     0,   106,    91,     0,     0,    93,   344,   345,     0,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,   125,   126,   127,    95,     0,     0,
     131,   132,   133,     0,   135,     0,   137,   138,   139,     0,
       0,     0,     0,   144,   145,   146,     0,     0,   149,     0,
       0,   152,   719,   153,   154,   720,   156,     0,   158,     0,
       0,     0,     0,     0,     0,   171,   498,     0,     0,     0,
       0,     0,     0,     0,     0,   344,   345,     0,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,   106,     0,
       0,     0,     0,     0,   434,   353,   354,   355,   356,     0,
       0,     0,     0,   390,     0,   763,   765,     0,     0,     0,
     125,   126,   127,     0,     0,     0,   131,   132,   133,     0,
     135,     0,   137,   138,   139,     0,     0,     0,     0,   144,
     145,   146,    91,     0,   149,    93,     0,   152,     0,   153,
     154,     0,   156,   780,   158,     0,     0,     0,     0,     0,
       0,   171,   500,     0,     0,     0,    95,     0,     0,     0,
     782,   783,     0,   353,   354,   355,   356,   784,     0,     0,
     786,   391,     0,   788,   789,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   803,     0,   804,     0,   344,   345,
       0,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   346,   347,   348,   349,   350,   351,   352,     0,   820,
     821,   822,     0,     0,     0,   105,     0,   106,     0,   344,
     345,     0,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   127,     0,     0,     0,   131,   132,   133,     0,   135,
       0,   137,   138,   139,    91,     0,     0,    93,   144,   145,
     146,     0,     0,   149,   368,     0,   152,     0,   153,   154,
       0,   156,     0,   158,     0,     0,     0,     0,    95,     0,
     171,   502,     0,     0,     0,   888,   353,   354,   355,   356,
       0,     0,     0,     0,   405,   353,   354,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   904,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,     0,   907,   585,     0,     0,     0,     0,
       0,     0,   910,     0,     0,   911,     0,     0,     0,   588,
       0,     0,     0,     0,     0,     0,     0,   105,   921,   106,
      89,    90,    91,     0,    92,    93,     0,   927,   928,   929,
     930,   931,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,   127,     0,    94,    95,   131,   132,   133,
       0,   135,     0,   137,   138,   139,     0,     0,     0,     0,
     144,   145,   146,     0,     0,   149,     0,     0,   152,     0,
     153,   154,     0,   156,     0,   158,     0,    97,    98,    99,
     100,     0,   171,     0,     0,     0,     0,     0,     0,     0,
     969,   101,     0,     0,   102,   973,   344,   345,     0,   208,
     346,   347,   348,   349,   350,   351,   352,   209,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
     991,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,     0,    89,    90,    91,
     161,    92,    93,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,   354,   355,   356,     0,     0,
     522,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   344,
     345,   102,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,   449,     0,     0,     0,   103,   104,
       0,     0,   105,     0,   106,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,     0,    89,    90,    91,   161,    92,    93,
       0,   210,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,     0,     0,   622,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   344,   345,   102,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,   105,
       0,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
       0,    89,    90,    91,   161,    92,    93,     0,   210,     0,
       0,     0,     0,     0,   353,   354,   355,   356,     0,     0,
       0,     0,   623,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   344,   345,   102,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,     0,     0,   105,     0,   106,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,   161,   421,    89,    90,    91,     0,    92,    93,     0,
       0,   353,   354,   355,   356,     0,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   344,   345,   102,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,   105,     0,
     106,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,   161,   477,    89,    90,    91,     0,    92,
      93,     0,     0,   353,   354,   355,   356,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   344,   345,   102,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,   487,    89,    90,    91,
       0,    92,    93,     0,   222,   353,   354,   355,   356,     0,
       0,     0,     0,   655,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   344,
     345,   102,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,     0,   105,     0,   106,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,     0,    89,    90,    91,   161,    92,    93,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,     0,     0,   662,     0,     0,     0,    94,
      95,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   344,   345,   102,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,   105,
       0,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
       0,    89,    90,    91,   161,    92,    93,     0,   413,     0,
       0,     0,     0,     0,   353,   354,   355,   356,     0,     0,
       0,     0,   663,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   344,   345,   102,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,     0,     0,   105,     0,   106,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,     0,    89,    90,
      91,   161,    92,    93,     0,     0,     0,     0,     0,     0,
       0,   353,   354,   355,   356,     0,     0,     0,     0,   713,
       0,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
      91,     0,   102,    93,   344,   345,     0,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,   103,
     104,     0,     0,   105,    95,   106,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,    91,   764,     0,    93,   161,     0,
       0,     0,     0,   105,     0,   106,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,     0,     0,    95,     0,
     734,     0,     0,     0,     0,     0,     0,   125,   126,   127,
       0,     0,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,     0,     0,   144,   145,   146,    91,
       0,   149,    93,     0,   152,     0,   153,   154,     0,   156,
       0,   158,     0,     0,     0,     0,     0,     0,   171,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,   127,     0,     0,     0,   131,   132,   133,
       0,   135,     0,   137,   138,   139,     0,     0,     0,     0,
     144,   145,   146,     0,     0,   149,     0,     0,   152,     0,
     153,   154,   105,   156,   106,   158,     0,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   127,     0,
       0,     0,   131,   132,   133,     0,   135,     0,   137,   138,
     139,     0,     0,     0,     0,   144,   145,   146,     0,     0,
     149,     0,     0,   152,     0,   153,   154,     0,   156,     0,
     158,     1,     2,     3,     0,     0,     4,   718,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,    11,  -295,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,  -108,  -108,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,  -108,     0,    49,   344,    50,    51,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     0,     4,     0,    56,     0,     5,    57,     6,     0,
       7,     8,     9,    10,    11,  -295,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,     0,
       0,     0,     0,    23,    -7,    -7,    24,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,   353,   354,   355,   356,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    39,    40,    41,     0,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     0,     4,     0,
      56,     0,     5,    57,     6,     0,     7,     8,     9,    10,
      11,  -295,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
      -7,     0,    24,     0,     0,     0,    -7,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     0,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,     0,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     0,     4,     0,    56,     0,     5,    57,
       6,     0,     7,     8,     9,    10,    11,  -295,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    -7,     0,     0,     0,    23,    -7,     0,    24,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,   344,   345,    31,    32,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
       0,     0,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,     0,     0,    49,     0,    50,    51,   344,   345,
       0,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,   344,   345,     0,    55,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,    57,     0,     0,     0,   353,
     354,   355,   356,     0,   344,   345,     0,   735,   346,   347,
     348,   349,   350,   351,   352,   344,   345,     0,     0,   346,
     347,   348,   349,   350,   351,   352,   344,   345,     0,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   353,   354,   355,   356,
       0,   344,   345,     0,   742,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,     0,   344,   345,     0,   745,   346,   347,
     348,   349,   350,   351,   352,   344,   345,     0,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,     0,     0,     0,     0,
     746,     0,     0,   353,   354,   355,   356,     0,     0,     0,
       0,   801,     0,     0,   353,   354,   355,   356,     0,   344,
     345,     0,   806,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,     0,   344,   345,     0,   817,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,     0,     0,     0,     0,
     890,     0,     0,   353,   354,   355,   356,     0,   344,   345,
       0,   940,   346,   347,   348,   349,   350,   351,   352,   344,
     345,     0,     0,   346,   347,   348,   349,   350,   351,   352,
     344,   345,     0,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,   344,   345,     0,   953,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,     0,   344,   345,     0,
     984,   346,   347,   348,   349,   350,   351,   352,   344,   345,
       0,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,     0,     0,     0,     0,   353,   354,   355,   356,
       0,     0,   603,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,   618,     0,     0,     0,     0,   353,   354,
     355,   356,   344,   345,   638,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,     0,     0,     0,     0,
     353,   354,   355,   356,   344,   345,   639,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,   354,   355,   356,     0,
       0,   640,     0,     0,     0,     0,   353,   354,   355,   356,
     344,   345,   641,     0,   346,   347,   348,   349,   350,   351,
     352,   344,   345,     0,     0,   346,   347,   348,   349,   350,
     351,   352,   344,   345,     0,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,     0,     0,     0,     0,
     353,   354,   355,   356,   344,   345,   642,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,   344,   345,   645,     0,
     346,   347,   348,   349,   350,   351,   352,   344,   345,     0,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,   354,
     355,   356,     0,     0,   648,     0,     0,     0,     0,   353,
     354,   355,   356,     0,     0,   649,     0,     0,     0,     0,
     353,   354,   355,   356,   344,   345,   651,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,   344,   345,   652,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,   353,   354,   355,   356,     0,     0,
     653,     0,     0,     0,     0,   353,   354,   355,   356,   344,
     345,   654,     0,   346,   347,   348,   349,   350,   351,   352,
     344,   345,     0,     0,   346,   347,   348,   349,   350,   351,
     352,   344,   345,     0,     0,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,   344,   345,   656,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,   353,   354,   355,   356,   344,   345,
     666,     0,   346,   347,   348,   349,   350,   351,   352,   344,
     345,     0,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,   667,     0,     0,     0,     0,   353,   354,
     355,   356,     0,     0,   669,     0,     0,     0,     0,   353,
     354,   355,   356,   344,   345,   672,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,   354,   355,   356,   344,   345,
     717,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,     0,     0,     0,     0,   353,   354,   355,   356,
       0,     0,   809,     0,     0,     0,     0,   353,   354,   355,
     356,   344,   345,   826,     0,   346,   347,   348,   349,   350,
     351,   352,   344,   345,     0,     0,   346,   347,   348,   349,
     350,   351,   352,   344,   345,     0,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,     0,     0,     0,
       0,   353,   354,   355,   356,   344,   345,   827,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   353,   354,   355,   356,
     344,   345,   834,     0,   346,   347,   348,   349,   350,   351,
     352,   344,   345,     0,     0,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,     0,     0,   835,     0,     0,     0,     0,
     353,   354,   355,   356,     0,     0,   836,     0,     0,     0,
       0,   353,   354,   355,   356,   344,   345,   837,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,     0,   353,   354,   355,   356,   344,   345,   842,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,   354,
     355,   356,     0,     0,   843,     0,     0,     0,     0,   353,
     354,   355,   356,   344,   345,   846,     0,   346,   347,   348,
     349,   350,   351,   352,   344,   345,     0,     0,   346,   347,
     348,   349,   350,   351,   352,   344,   345,     0,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,     0,
       0,     0,     0,   353,   354,   355,   356,   344,   345,   847,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,   353,   354,   355,   356,   344,
     345,   848,     0,   346,   347,   348,   349,   350,   351,   352,
     344,   345,     0,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   353,   354,   355,   356,     0,     0,   849,     0,     0,
       0,     0,   353,   354,   355,   356,     0,     0,   850,     0,
       0,     0,     0,   353,   354,   355,   356,   344,   345,   853,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,     0,   353,   354,   355,   356,   344,
     345,   854,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,   857,     0,     0,     0,     0,   353,   354,
     355,   356,   344,   345,   876,     0,   346,   347,   348,   349,
     350,   351,   352,   344,   345,     0,     0,   346,   347,   348,
     349,   350,   351,   352,   344,   345,     0,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,   354,   355,   356,   344,
     345,   918,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,   344,   345,   922,     0,   346,   347,   348,   349,   350,
     351,   352,   344,   345,     0,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,     0,     0,     0,     0,
     353,   354,   355,   356,     0,     0,   932,     0,     0,     0,
       0,   353,   354,   355,   356,     0,     0,   941,     0,     0,
       0,     0,   353,   354,   355,   356,   344,   345,   943,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   353,   354,   355,
     356,     0,     0,   944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,     0,     0,   976,     0,     0,     0,     0,
     353,   354,   355,   356,     0,     0,   983,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,   354,   355,   356,     0,     0,
     998
};

static const yytype_int16 yycheck[] =
{
       0,   276,     0,    34,    10,   723,   724,    10,    41,    42,
     238,   239,     9,    83,    55,    70,    11,    80,     9,    10,
      69,     4,    12,     4,     7,   159,     7,     4,     5,    24,
     164,    69,    27,    85,    86,    30,    31,    32,    14,   159,
     163,    36,    37,    38,    35,    97,   166,    47,    56,    47,
      45,     3,    42,     3,   163,     7,     8,     7,     8,    69,
      70,    55,    57,    57,    58,    16,    42,    64,    65,    66,
      67,    68,    69,    10,    82,    83,    84,     4,     5,    37,
      38,    89,    77,    83,    10,    83,    70,     4,    23,     7,
       7,    42,    64,    65,    66,    67,    68,    69,   159,    57,
     164,   159,   166,   164,    99,   160,   161,    42,   166,   179,
     173,   174,     4,     5,   163,    64,    65,    66,    67,    68,
      69,    33,    34,    60,    61,   163,   167,    64,    65,    66,
      67,    68,    69,    70,    60,    61,     4,     5,    64,    65,
      66,    67,    68,    69,    70,   122,   123,   124,   158,   159,
     160,   161,    65,   159,    67,    68,    69,    70,    39,    26,
     166,    42,   159,   166,   882,   160,   161,   885,    88,   242,
     243,   202,   203,   167,   158,   159,   160,   161,    81,   179,
     163,   179,   163,   178,   159,   163,   414,   159,   159,   222,
     185,   166,   164,   164,   166,   228,   229,   159,   159,   103,
     428,   429,   265,   266,   166,   166,   158,   159,   158,   159,
     159,   159,    42,   208,     0,   210,   164,   166,   251,   252,
     253,   158,   159,   160,   161,   159,   164,   163,   166,   166,
     164,   459,   158,   159,   160,   161,   159,    64,    65,    66,
      67,    68,    69,   166,   277,   158,   159,   160,   161,   244,
     164,   159,   166,   163,   972,   328,   164,   330,   166,   254,
     159,   163,   159,   159,   259,   164,   159,   166,   263,   166,
     166,   164,   163,   166,   269,   270,   159,   272,   273,   274,
     164,   164,   166,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,     3,    69,   373,   159,     7,   301,   302,   303,   304,
     305,   166,   307,   159,   309,   273,   274,   159,     5,   159,
     166,     8,   164,    69,   387,   388,   166,    22,   323,   392,
     393,   289,   159,   159,   159,     4,     5,   164,   164,   164,
     166,   166,    29,     4,    11,    64,    65,    66,    67,    68,
      69,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   159,   159,   163,   323,   397,   164,   164,   166,
     166,   159,   164,   373,   166,   373,   164,   410,   166,   374,
     413,     4,     5,   163,   379,    65,    66,    67,    68,    69,
      70,   165,   166,    60,    61,   390,   391,    64,    65,    66,
      67,    68,    69,    70,    67,    68,    69,    70,   403,   159,
     405,    98,   159,   100,   164,   690,   166,   164,   693,   163,
     415,   416,    64,    65,    66,    67,    68,    69,   159,   424,
     425,     4,     5,   164,   159,   122,   123,   124,   159,   164,
     159,   128,   129,   130,    55,   132,   159,   134,   135,   136,
     166,   164,    79,    80,   141,   142,   143,    18,    19,   146,
     163,   159,   149,   159,   151,   152,   164,   154,   164,   156,
     159,     4,     5,     4,     5,   164,   163,   164,   158,   159,
     160,   161,   545,   546,   159,   548,   549,    37,    38,   164,
     163,   158,   159,   160,   161,   158,   159,   160,   161,    60,
      61,     4,     5,    64,    65,    66,    67,    68,    69,    70,
     159,   159,   163,   159,   159,   164,   164,   159,   164,   164,
      57,    58,   164,   163,   163,   753,    68,    69,    70,    44,
     159,   163,   163,   163,     5,   164,   599,   532,   533,   530,
     531,   163,   159,   771,   163,    60,    61,   164,   163,    64,
      65,    66,    67,    68,    69,    70,   159,   159,   163,   159,
     159,   164,   164,   596,   164,   164,   561,   163,   163,   159,
     159,   163,   567,   568,   164,   164,   571,    42,   611,   612,
     159,   163,    47,   163,    69,   164,   163,   163,   163,   163,
     585,   163,   163,   163,   163,   163,   163,   158,   159,   160,
     161,   163,   166,   636,   163,   600,   601,   602,   163,   609,
     163,   609,   163,    41,   163,   610,   158,   159,   160,   161,
     163,   616,   617,   163,   619,   163,    70,   622,   623,   624,
     166,   163,   166,   163,   163,   163,   163,   163,   163,   634,
     635,   711,   637,   158,   159,   160,   161,   163,   166,   644,
     163,   163,   647,   163,   163,   163,   163,   163,   163,   163,
     655,    44,   163,   658,   659,   660,   163,   662,   663,   732,
     733,   163,   163,   163,   163,   163,   671,    60,    61,    48,
     163,    64,    65,    66,    67,    68,    69,    70,   758,   163,
     163,    60,    61,   163,   163,    64,    65,    66,    67,    68,
      69,    70,   163,   163,   163,   163,   163,    44,    41,   164,
     166,   711,   166,   711,   164,    60,    61,   164,   713,    64,
      65,    66,    67,    68,    69,    70,    60,    61,   164,   163,
      64,    65,    66,    67,    68,    69,    70,   163,     8,   734,
     735,   166,   163,   163,   739,   740,   164,   810,   811,   166,
     745,   746,   164,    15,   163,   163,    18,   163,   758,   166,
     758,   166,   166,   166,   166,    27,   163,   166,   164,    31,
      32,   164,   164,   164,    36,   158,   159,   160,   161,   163,
     166,   739,   740,   163,   166,   164,    48,    49,    50,   158,
     159,   160,   161,   164,   164,    57,   164,   830,    41,   790,
     791,   796,    47,   164,   164,   163,   801,   163,     5,   164,
     164,   806,    78,   158,   159,   160,   161,    79,    78,   164,
     164,   166,   164,   166,   158,   159,   160,   161,   166,   164,
     164,    55,   166,   164,   829,   164,   164,   832,   163,   163,
     166,   164,   912,   913,   163,    41,   164,   164,    36,   163,
     845,    41,   164,   164,    69,    69,    69,   852,   164,    46,
      55,   164,   163,   163,   859,    45,   861,   163,    60,    61,
     163,    69,    64,    65,    66,    67,    68,    69,    70,   164,
     950,   164,    36,   878,     4,   609,    47,    47,   276,   616,
     960,   547,   550,   963,   936,   397,   796,   996,   394,   161,
     721,    -1,   956,    -1,    -1,    -1,    -1,   977,   407,   171,
      -1,    -1,   912,   913,   912,   913,   178,    -1,    -1,   914,
      60,    61,    -1,   185,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,   937,    -1,    -1,   940,    -1,   209,    -1,    -1,
     950,    -1,   950,    -1,    -1,    -1,    -1,   219,   953,   954,
     960,    -1,   960,   963,    -1,   963,   158,   159,   160,   161,
      -1,    -1,   164,    -1,   166,    -1,    -1,   977,    -1,   977,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   984,
      -1,    -1,    -1,   255,    60,    61,    -1,   259,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,   166,    -1,    -1,   158,
     159,   160,   161,    -1,   296,   297,   298,   299,   300,    -1,
      -1,    -1,    -1,    -1,   306,    -1,   308,    -1,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,    -1,    -1,   327,    -1,   329,    -1,   331,
      -1,    -1,    -1,   335,   336,   337,   338,   339,   340,   341,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
       8,    -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     402,    -1,    60,    61,    62,    63,    -1,    -1,    -1,   411,
      -1,    -1,    -1,    -1,    -1,    -1,    74,     5,    -1,    77,
       8,    -1,   424,   425,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    29,   100,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
      98,    -1,   100,     5,    -1,    -1,     8,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,    29,    -1,    -1,
     128,   129,   130,    -1,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,    -1,   146,    -1,
      -1,   149,   564,   151,   152,   567,   154,    -1,   156,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,    -1,   616,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   627,   628,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,    -1,   128,   129,   130,    -1,
     132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,     5,    -1,   146,     8,    -1,   149,    -1,   151,
     152,    -1,   154,   665,   156,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   164,    -1,    -1,    -1,    29,    -1,    -1,    -1,
     682,   683,    -1,   158,   159,   160,   161,   689,    -1,    -1,
     692,   166,    -1,   695,   696,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   716,    -1,   718,    -1,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,   741,
     742,   743,    -1,    -1,    -1,    98,    -1,   100,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    -1,    -1,    -1,   128,   129,   130,    -1,   132,
      -1,   134,   135,   136,     5,    -1,    -1,     8,   141,   142,
     143,    -1,    -1,   146,   796,    -1,   149,    -1,   151,   152,
      -1,   154,    -1,   156,    -1,    -1,    -1,    -1,    29,    -1,
     163,   164,    -1,    -1,    -1,   817,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,   856,   166,    -1,    -1,    -1,    -1,
      -1,    -1,   864,    -1,    -1,   867,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,   880,   100,
       3,     4,     5,    -1,     7,     8,    -1,   889,   890,   891,
     892,   893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    28,    29,   128,   129,   130,
      -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,   146,    -1,    -1,   149,    -1,
     151,   152,    -1,   154,    -1,   156,    -1,    60,    61,    62,
      63,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     952,    74,    -1,    -1,    77,   957,    60,    61,    -1,    82,
      64,    65,    66,    67,    68,    69,    70,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
     982,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,     3,     4,     5,
     163,     7,     8,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
     164,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    60,
      61,    77,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,     3,     4,     5,   163,     7,     8,
      -1,   167,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    60,    61,    77,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,     3,     4,     5,   163,     7,     8,    -1,   167,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    60,    61,    77,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,     3,     4,     5,    -1,     7,     8,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    60,    61,    77,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,    -1,   163,   164,     3,     4,     5,    -1,     7,
       8,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    60,    61,    77,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,    -1,   163,   164,     3,     4,     5,
      -1,     7,     8,    -1,    10,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    60,
      61,    77,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,     3,     4,     5,   163,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    60,    61,    77,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,     3,     4,     5,   163,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    60,    61,    77,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,     3,     4,
       5,   163,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
       5,    -1,    77,     8,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    29,   100,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,     5,    90,    -1,     8,   163,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    29,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,   141,   142,   143,     5,
      -1,   146,     8,    -1,   149,    -1,   151,   152,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,   128,   129,   130,
      -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,    -1,   146,    -1,    -1,   149,    -1,
     151,   152,    98,   154,   100,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,   135,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,    -1,
     146,    -1,    -1,   149,    -1,   151,   152,    -1,   154,    -1,
     156,     4,     5,     6,    -1,    -1,     9,   163,    -1,    -1,
      13,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    -1,    -1,    96,    97,    -1,    99,    60,   101,   102,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,   147,    -1,    13,   150,    15,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,    -1,
     147,    -1,    13,   150,    15,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    87,    88,    89,    -1,
      91,    92,    93,    -1,    -1,    96,    -1,    -1,    99,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,     9,    -1,   147,    -1,    13,   150,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    60,    61,    58,    59,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    87,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    96,    -1,    -1,    99,    -1,   101,   102,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,    60,    61,    -1,   129,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,    -1,    -1,   150,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    60,    61,    -1,   166,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    60,    61,    -1,   166,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    60,    61,    -1,   166,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,   158,   159,   160,   161,    -1,    60,
      61,    -1,   166,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    60,    61,    -1,   166,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,   158,   159,   160,   161,    -1,    60,    61,
      -1,   166,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    60,    61,    -1,   166,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    60,    61,    -1,
     166,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    60,    61,   164,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      60,    61,   164,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
     164,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,
      61,   164,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,    61,
     164,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    60,    61,   164,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,    61,
     164,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    60,    61,   164,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    60,    61,   164,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      60,    61,   164,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    60,    61,   164,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    60,    61,   164,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,
      61,   164,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,
      61,   164,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    60,    61,   164,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,
      61,   164,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    60,    61,   164,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
     164
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,     9,    13,    15,    17,    18,    19,
      20,    21,    24,    25,    26,    27,    28,    29,    30,    31,
      33,    34,    35,    40,    43,    49,    50,    51,    52,    53,
      54,    58,    59,    71,    72,    73,    74,    75,    76,    82,
      83,    84,    87,    88,    89,    91,    92,    93,    96,    99,
     101,   102,   122,   123,   124,   129,   147,   150,   169,   170,
     173,   180,   181,   183,   184,   188,   200,   201,   206,   212,
     219,   227,   235,   238,   242,   245,   251,    69,   163,    69,
     163,   220,   239,   243,     4,     7,   198,   198,   198,     3,
       4,     5,     7,     8,    28,    29,    32,    60,    61,    62,
      63,    74,    77,    94,    95,    98,   100,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   151,   152,   153,   154,   155,   156,   157,
     158,   163,   186,   187,   189,   195,   197,   200,   201,   174,
     175,   163,   186,   163,   163,   186,    26,     7,   228,   236,
     189,    55,    57,    58,   167,   273,   178,   186,   189,     4,
       5,   199,   189,   186,   189,   186,   189,     4,     5,   261,
     262,     8,   158,   159,   196,   197,   263,   198,    82,    90,
     167,   186,   189,   274,    82,    90,   103,   274,   274,    81,
     189,   194,    10,    50,   194,   194,    56,    82,    83,    84,
      89,    88,   189,   181,   188,   200,   201,   186,   186,   186,
     103,   163,   163,   163,   163,   163,   186,   274,     0,    42,
     171,    85,    86,    97,    69,    69,    22,   189,   202,   203,
     186,   202,     4,   163,   170,   163,   163,    33,    34,   163,
     163,   189,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   189,   186,   189,    64,    65,    66,    67,    68,
      69,   159,    18,    19,    60,    61,    64,    65,    66,    67,
      68,    69,    70,   158,   159,   160,   161,     4,     5,   213,
     214,     4,     5,   215,   216,   186,   202,   202,   186,   189,
     230,   170,   246,   252,   163,    55,   163,     4,     7,   163,
     186,   189,   264,    55,   167,   266,   271,   163,   163,   166,
     166,   166,   163,   163,   166,   197,   197,   166,   189,   186,
     189,     9,   166,   166,   186,   166,   194,   179,    10,   166,
     182,   166,   194,    10,   194,   182,   182,     5,   185,   185,
     185,   164,   189,   186,   166,   166,    41,   194,   194,   194,
     189,   186,   207,   164,   186,   189,   204,   205,   164,    69,
     189,    16,    42,   244,   202,   202,   189,   189,   189,    90,
     186,   274,   274,     4,     5,   192,   193,   192,   193,   194,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   274,   189,   189,   189,   189,   189,   164,   189,   186,
     186,   186,   186,   186,   189,   189,   189,   164,   189,   189,
     186,   189,   186,   189,   186,   186,   164,   186,   164,   186,
     164,   186,   164,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   274,   186,   164,   164,   186,   185,   186,   185,
     186,   164,   164,   186,   186,   186,   186,   186,   186,   186,
     176,   177,   191,   190,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   163,   163,   166,   163,   163,
     166,   164,   164,    41,   229,    39,    42,   237,    44,   170,
     189,   163,   186,   189,    48,   265,   165,   166,   163,     4,
       7,   163,     8,   272,   202,   202,     4,     5,   189,   189,
     202,   202,   262,     8,   196,   166,    79,    80,    90,   186,
     189,   189,   266,   194,   186,   194,   182,   189,   189,   163,
     166,   166,   166,   164,   164,   186,   189,   186,   189,   172,
     166,   182,   182,     4,     5,   211,   166,   221,   164,   163,
     164,   164,   166,   166,   166,   164,   164,   166,   166,   164,
     163,   163,   164,   164,   166,   166,   182,   166,   164,   164,
     164,   164,   164,   164,   166,   164,   164,   166,   164,   164,
     164,   164,   164,   164,   164,   166,   164,   164,   166,   166,
     166,   164,   166,   166,   164,   166,   164,   164,   164,   164,
     164,   166,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   166,   166,   164,   164,   164,   164,   164,   166,
     166,   164,   166,   166,   164,   166,   166,   198,   275,   198,
     276,   189,   189,   202,   202,   214,   202,   202,   216,    41,
     231,   247,    47,   166,   189,   164,   166,   164,   163,   186,
     186,   189,   189,   267,   268,   189,     4,     5,   258,   260,
     164,   164,   163,   163,   166,   166,   164,   164,   189,    78,
      78,   166,   166,   166,   194,   166,   166,   202,   189,   189,
     189,   173,   189,   194,   194,   208,   205,   189,   240,   189,
     189,   189,   189,   186,    90,   186,   164,   164,   189,   189,
     194,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     186,   189,   186,   186,   186,   193,   186,   193,   186,   186,
     166,   166,   164,   164,   164,   164,    37,    38,   233,   170,
     189,   166,    55,   186,   186,   265,   166,   258,   258,   164,
     163,   163,   166,   202,   202,   189,   189,   166,   274,   274,
     186,   186,   186,   189,   189,   164,   164,   164,   164,   166,
     182,   163,    10,   170,   164,   164,   164,   164,   164,   164,
     164,   166,   164,   164,   164,   182,   164,   164,   164,   164,
     164,   164,   166,   164,   164,   164,   166,   164,   164,   166,
     164,   166,   164,   164,   166,   164,   164,   166,   164,   164,
     198,   198,   230,    41,    36,   248,   164,   189,   163,   164,
     166,   189,   269,   202,   202,   259,   164,   164,   186,   166,
     166,    69,    69,    69,   189,   194,     4,     5,   217,   218,
     189,    14,    42,   241,   186,   189,   189,   186,   189,   189,
     186,   186,   232,   234,    46,   254,    57,    58,   164,   189,
      55,   186,   164,   258,   164,   164,   258,   186,   186,   186,
     186,   186,   164,   163,   163,   164,   166,    11,   225,   164,
     166,   164,   164,   164,   164,   164,   164,   170,   170,   189,
      45,   253,   163,   166,   163,   164,   270,    69,   164,   164,
     209,   218,   189,   222,   189,    44,   257,   170,   249,   186,
     189,   189,   272,   186,   170,   170,   164,   255,    42,    47,
     250,   164,   166,   164,   166,   258,    23,    42,   210,   223,
     170,   186,   189,    12,    42,   224,   256,   164,   164,     4,
     226,   254
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   170,   171,   172,   170,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   174,   173,   175,   173,   173,
     173,   173,   173,   173,   173,   176,   173,   177,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   178,
     173,   179,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   180,   180,
     180,   180,   180,   181,   181,   181,   181,   181,   181,   182,
     182,   183,   183,   183,   183,   183,   184,   184,   185,   185,
     186,   186,   186,   186,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     190,   189,   191,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   192,   193,   194,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   196,
     197,   197,   198,   198,   199,   199,   199,   199,   200,   201,
     203,   202,   204,   204,   204,   205,   205,   207,   208,   209,
     206,   210,   210,   211,   211,   212,   212,   212,   212,   213,
     213,   214,   214,   214,   214,   215,   215,   216,   216,   216,
     216,   217,   217,   217,   218,   218,   218,   218,   220,   221,
     222,   223,   219,   224,   224,   225,   225,   226,   226,   228,
     227,   229,   229,   230,   230,   231,   232,   231,   233,   234,
     233,   236,   235,   237,   237,   239,   240,   238,   241,   241,
     243,   242,   244,   244,   246,   247,   248,   249,   245,   250,
     250,   252,   251,   253,   253,   254,   255,   256,   254,   257,
     257,   258,   259,   258,   260,   260,   260,   260,   261,   261,
     262,   262,   262,   262,   263,   263,   263,   263,   264,   264,
     264,   264,   264,   265,   265,   265,   267,   266,   268,   266,
     269,   266,   270,   266,   271,   266,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   274,   274,   275,   275,   276,   276
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     0,     5,     0,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     0,     3,     0,     3,     1,
       1,     2,     2,     3,     3,     0,     5,     0,     5,     2,
       1,     2,     1,     2,     4,     4,     3,     4,     4,     0,
       3,     0,     4,     6,     2,     6,     2,     2,     2,     1,
       2,     1,     2,     2,     2,     5,     7,     3,     2,     3,
       4,     5,     3,     2,     4,     3,     8,     6,     6,     2,
       2,     5,     7,     4,     6,     8,     5,     2,     2,     2,
       2,     3,     2,     2,     1,     1,     3,     4,     4,     4,
       4,     4,     4,     1,     1,     2,     1,     2,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     3,     1,     3,     4,     6,     6,
       4,     6,     4,     6,    10,     4,     4,     4,     3,     3,
       0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
       3,     4,     6,     1,     4,     4,     6,     6,     1,     1,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     4,     3,     6,     6,     4,     4,
       4,     4,     6,     6,     8,     6,     8,     4,     4,     4,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     6,     6,     6,     4,     8,     6,     8,     6,
       4,     4,     4,     6,     6,     6,     8,     1,     2,     2,
       1,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       0,     2,     0,     1,     3,     1,     1,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     1,     4,
       4,     0,     1,     3,     1,     1,     3,     3,     0,     0,
       0,     0,    14,     1,     1,     0,     2,     0,     1,     0,
       7,     1,     2,     1,     1,     0,     0,     5,     0,     0,
       4,     0,     4,     1,     1,     0,     0,     8,     1,     1,
       0,     4,     1,     4,     0,     0,     0,     0,    11,     1,
       1,     0,     5,     0,     2,     0,     0,     0,     7,     0,
       1,     1,     0,     4,     1,     4,     1,     4,     1,     3,
       1,     4,     1,     4,     1,     1,     3,     3,     0,     2,
       4,     1,     3,     0,     2,     6,     0,     4,     0,     4,
       0,     6,     0,     9,     0,     3,     0,     1,     0,     2,
       2,     4,     1,     4,     6,     6,     7,    10,    12,     7,
      10,    12,     2,     1,     1,     3,     1,     3
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

    {YYACCEPT;}

    break;

  case 4:

    {if (errorlevel<=ERROR) {YYABORT;}}

    break;

  case 5:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep); else switchlib();}

    break;

  case 12:

    {report_missing(ERROR,"do not import a library in a loop or an if-statement");switchlib();}

    break;

  case 13:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 19:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) error(ERROR,"break outside loop or switch");}

    break;

  case 20:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) error(ERROR,"break outside loop or switch");}

    break;

  case 21:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) error(ERROR,"continue outside loop");}

    break;

  case 23:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 24:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 25:

    {if (function_type==ftNONE) error(ERROR,"no use for 'local' outside functions");}

    break;

  case 27:

    {if (function_type==ftNONE) error(ERROR,"no use for 'static' outside functions");}

    break;

  case 31:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 32:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 33:

    {create_exception(TRUE);}

    break;

  case 34:

    {create_exception(FALSE);}

    break;

  case 35:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 36:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 37:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 38:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 39:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 40:

    {add_command(cCHECKOPEN,NULL,NULL);}

    break;

  case 41:

    {add_command(cCLOSE,NULL,NULL);}

    break;

  case 42:

    {add_command(cCHECKSEEK,NULL,NULL);}

    break;

  case 43:

    {add_command(cCOMPILE,NULL,NULL);}

    break;

  case 44:

    {create_execute(0);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 45:

    {create_execute(1);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 46:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}

    break;

  case 47:

    {create_colour(0);create_pps(cPOPSTREAM,0);}

    break;

  case 48:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}

    break;

  case 49:

    {tileol=FALSE;}

    break;

  case 51:

    {tileol=TRUE;}

    break;

  case 53:

    {add_command(cGCOLOUR,NULL,NULL);}

    break;

  case 54:

    {add_command(cGCOLOUR2,NULL,NULL);}

    break;

  case 55:

    {add_command(cGBACKCOLOUR,NULL,NULL);}

    break;

  case 56:

    {add_command(cGBACKCOLOUR2,NULL,NULL);}

    break;

  case 59:

    {create_restore("");}

    break;

  case 60:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 61:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;
	       add_command(cPOPSYMLIST,NULL,NULL);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL,NULL,NULL);
            } else {
               add_command(cRETURN_FROM_GOSUB,NULL,NULL);
            }}

    break;

  case 62:

    {if (function_type==ftNONE) {error(ERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 63:

    {if (function_type==ftNONE) {error(ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 65:

    {create_openwin(FALSE);}

    break;

  case 66:

    {create_openwin(TRUE);}

    break;

  case 67:

    {add_command(cMOVEORIGIN,NULL,NULL);}

    break;

  case 68:

    {add_command(cDOT,NULL,NULL);}

    break;

  case 69:

    {add_command(cDOT,NULL,NULL);putindrawmode(dmCLEAR);}

    break;

  case 70:

    {create_line(2);}

    break;

  case 71:

    {create_line(2);putindrawmode(dmCLEAR);}

    break;

  case 72:

    {create_line(1);}

    break;

  case 73:

    {create_line(1);}

    break;

  case 74:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 75:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 76:

    {add_command(cPUTBIT,NULL,NULL);}

    break;

  case 77:

    {create_pushstr("solid"); add_command(cPUTBIT,NULL,NULL);}

    break;

  case 78:

    {add_command(cPUTCHAR,NULL,NULL);}

    break;

  case 79:

    {create_line(-1);}

    break;

  case 80:

    {create_line(0);}

    break;

  case 81:

    {add_command(cCIRCLE,NULL,NULL);putindrawmode(0);}

    break;

  case 82:

    {add_command(cTRIANGLE,NULL,NULL);putindrawmode(0);}

    break;

  case 83:

    {add_command(cTEXT1,NULL,NULL);}

    break;

  case 84:

    {add_command(cTEXT2,NULL,NULL);}

    break;

  case 85:

    {add_command(cTEXT3,NULL,NULL);}

    break;

  case 86:

    {add_command(cRECT,NULL,NULL);putindrawmode(0);}

    break;

  case 87:

    {add_command(cCLOSEWIN,NULL,NULL);}

    break;

  case 88:

    {add_command(cCLEARWIN,NULL,NULL);}

    break;

  case 89:

    {add_command(cCLEARSCR,NULL,NULL);}

    break;

  case 90:

    {create_openprinter(0);}

    break;

  case 91:

    {create_openprinter(1);}

    break;

  case 92:

    {add_command(cCLOSEPRN,NULL,NULL);}

    break;

  case 93:

    {add_command(cWAIT,NULL,NULL);}

    break;

  case 94:

    {add_command(cBELL,NULL,NULL);}

    break;

  case 95:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 96:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 97:

    {create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 98:

    {create_function(fSYSTEM2);
	add_command(cPOP,NULL,NULL);}

    break;

  case 99:

    {create_poke('s');}

    break;

  case 100:

    {create_poke('d');}

    break;

  case 101:

    {create_poke('S');}

    break;

  case 102:

    {create_poke('D');}

    break;

  case 103:

    {add_command(cEND,NULL,NULL);}

    break;

  case 104:

    {create_pushdbl(0);add_command(cEXIT,NULL,NULL);}

    break;

  case 105:

    {add_command(cEXIT,NULL,NULL);}

    break;

  case 106:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 107:

    {add_command(cBIND,NULL,NULL);}

    break;

  case 108:

    {drawmode=0;}

    break;

  case 109:

    {drawmode=dmCLEAR;}

    break;

  case 110:

    {drawmode=dmFILL;}

    break;

  case 111:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 112:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 113:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 114:

    {create_changestring(fMID);}

    break;

  case 115:

    {create_changestring(fMID2);}

    break;

  case 116:

    {create_changestring(fLEFT);}

    break;

  case 117:

    {create_changestring(fRIGHT);}

    break;

  case 118:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 121:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 122:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 123:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 124:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 125:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 126:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 127:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 128:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 129:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 130:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 132:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 133:

    {if ((yyvsp[0].string)==NULL) {error(ERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 134:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 136:

    {create_function(fLEFT);}

    break;

  case 137:

    {create_function(fRIGHT);}

    break;

  case 138:

    {create_function(fMID);}

    break;

  case 139:

    {create_function(fMID2);}

    break;

  case 140:

    {create_function(fSTR);}

    break;

  case 141:

    {create_function(fSTR2);}

    break;

  case 142:

    {create_function(fSTR3);}

    break;

  case 143:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 144:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 145:

    {create_function(fINKEY);}

    break;

  case 146:

    {create_function(fCHR);}

    break;

  case 147:

    {create_function(fUPPER);}

    break;

  case 148:

    {create_function(fLOWER);}

    break;

  case 149:

    {create_function(fLTRIM);}

    break;

  case 150:

    {create_function(fRTRIM);}

    break;

  case 151:

    {create_function(fTRIM);}

    break;

  case 152:

    {create_function(fSYSTEM);}

    break;

  case 153:

    {create_function(fDATE);}

    break;

  case 154:

    {create_function(fDATE);}

    break;

  case 155:

    {create_function(fTIME);}

    break;

  case 156:

    {create_function(fTIME);}

    break;

  case 157:

    {create_function(fPEEK2);}

    break;

  case 158:

    {create_function(fPEEK3);}

    break;

  case 159:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 160:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 161:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 162:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 163:

    {create_function(fGETBIT);}

    break;

  case 164:

    {create_function(fGETCHAR);}

    break;

  case 165:

    {create_function(fHEX);}

    break;

  case 166:

    {create_function(fBIN);}

    break;

  case 167:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 168:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 169:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 170:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 171:

    {poplabel();create_boole('|');}

    break;

  case 172:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 173:

    {poplabel();create_boole('&');}

    break;

  case 174:

    {create_boole('!');}

    break;

  case 175:

    {create_dblrelop('=');}

    break;

  case 176:

    {create_dblrelop('!');}

    break;

  case 177:

    {create_dblrelop('<');}

    break;

  case 178:

    {create_dblrelop('{');}

    break;

  case 179:

    {create_dblrelop('>');}

    break;

  case 180:

    {create_dblrelop('}');}

    break;

  case 181:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 182:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 183:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 184:

    {add_command(cARDIM,"",NULL);}

    break;

  case 185:

    {add_command(cARDIM,"",NULL);}

    break;

  case 186:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 187:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 188:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 189:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 190:

    {create_dblbin('+');}

    break;

  case 191:

    {create_dblbin('-');}

    break;

  case 192:

    {create_dblbin('*');}

    break;

  case 193:

    {create_dblbin('/');}

    break;

  case 194:

    {create_dblbin('^');}

    break;

  case 195:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 196:

    {create_strrelop('=');}

    break;

  case 197:

    {create_strrelop('!');}

    break;

  case 198:

    {create_strrelop('<');}

    break;

  case 199:

    {create_strrelop('{');}

    break;

  case 200:

    {create_strrelop('>');}

    break;

  case 201:

    {create_strrelop('}');}

    break;

  case 204:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 205:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 207:

    {create_function(fSIN);}

    break;

  case 208:

    {create_function(fASIN);}

    break;

  case 209:

    {create_function(fCOS);}

    break;

  case 210:

    {create_function(fACOS);}

    break;

  case 211:

    {create_function(fTAN);}

    break;

  case 212:

    {create_function(fATAN);}

    break;

  case 213:

    {create_function(fATAN2);}

    break;

  case 214:

    {create_function(fEXP);}

    break;

  case 215:

    {create_function(fLOG);}

    break;

  case 216:

    {create_function(fLOG2);}

    break;

  case 217:

    {create_function(fSQRT);}

    break;

  case 218:

    {create_function(fSQR);}

    break;

  case 219:

    {create_function(fINT);}

    break;

  case 220:

    {create_function(fFRAC);}

    break;

  case 221:

    {create_function(fABS);}

    break;

  case 222:

    {create_function(fSIG);}

    break;

  case 223:

    {create_function(fMOD);}

    break;

  case 224:

    {create_function(fRAN);}

    break;

  case 225:

    {create_function(fRAN2);}

    break;

  case 226:

    {create_function(fMIN);}

    break;

  case 227:

    {create_function(fMAX);}

    break;

  case 228:

    {create_function(fLEN);}

    break;

  case 229:

    {create_function(fVAL);}

    break;

  case 230:

    {create_function(fASC);}

    break;

  case 231:

    {create_function(fDEC);}

    break;

  case 232:

    {create_function(fDEC2);}

    break;

  case 233:

    {if (check_compat) error(WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 234:

    {create_function(fINSTR2);}

    break;

  case 235:

    {create_function(fRINSTR);}

    break;

  case 236:

    {create_function(fRINSTR2);}

    break;

  case 237:

    {create_function(fSYSTEM2);}

    break;

  case 238:

    {create_function(fPEEK4);}

    break;

  case 239:

    {create_function(fPEEK);}

    break;

  case 240:

    {create_function(fMOUSEX);}

    break;

  case 241:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 242:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 243:

    {create_function(fMOUSEY);}

    break;

  case 244:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 245:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 246:

    {create_function(fMOUSEB);}

    break;

  case 247:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 248:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 249:

    {create_function(fMOUSEMOD);}

    break;

  case 250:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 251:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 252:

    {create_function(fAND);}

    break;

  case 253:

    {create_function(fOR);}

    break;

  case 254:

    {create_function(fEOR);}

    break;

  case 255:

    {create_function(fTELL);}

    break;

  case 256:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 257:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 258:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 259:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 260:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 261:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 262:

    {create_myopen(0);}

    break;

  case 263:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 264:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 265:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 266:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 267:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 268:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 269:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 270:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 271:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 272:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 273:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 274:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 275:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 276:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 277:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 278:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 279:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 280:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 287:

    {missing_endsub++;missing_endsub_line=mylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {error(ERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 288:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 289:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 290:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 291:

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);error(ERROR,string);} YYABORT;}

    break;

  case 292:

    {missing_endsub--;}

    break;

  case 293:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 294:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 295:

    {exported=FALSE;}

    break;

  case 296:

    {exported=TRUE;}

    break;

  case 297:

    {exported=FALSE;}

    break;

  case 298:

    {exported=TRUE;}

    break;

  case 301:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 302:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 303:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 304:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 307:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 308:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 309:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 310:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 314:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 315:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 316:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 317:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 318:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=mylineno;}

    break;

  case 319:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 320:

    { /* pushes another expression */
	     add_command(cSKIPONCE,NULL,NULL);
	     pushlabel();
	     add_command(cSTARTFOR,NULL,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORINCREMENT,NULL,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK,NULL,NULL);
	     add_command(cDECIDE,NULL,NULL);
             pushlabel();}

    break;

  case 321:

    {
             swap();popgoto();poplabel();}

    break;

  case 322:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 323:

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);error(ERROR,string);} YYABORT;}

    break;

  case 324:

    {missing_next--;}

    break;

  case 325:

    {create_pushdbl(1);}

    break;

  case 327:

    {pop(stSTRING);}

    break;

  case 328:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {error(ERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 329:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 330:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 331:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 332:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 336:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 337:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 339:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep); add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 341:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=mylineno;pushgoto();}

    break;

  case 343:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);error(ERROR,string);} YYABORT;}

    break;

  case 344:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 345:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=mylineno;pushgoto();}

    break;

  case 346:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 348:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);error(ERROR,string);} YYABORT;}

    break;

  case 349:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 350:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=mylineno;pushgoto();}

    break;

  case 352:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);error(ERROR,string);} YYABORT;}

    break;

  case 353:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 354:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 355:

    {missing_endif++;missing_endif_line=mylineno;}

    break;

  case 356:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 357:

    {poplabel();}

    break;

  case 359:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);error(ERROR,string);} YYABORT;}

    break;

  case 360:

    {missing_endif--;}

    break;

  case 361:

    {fi_pending++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 362:

    {poplabel();}

    break;

  case 366:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 367:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 372:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 374:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 375:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 376:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 377:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 380:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 381:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 382:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 383:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 384:

    {create_strdata((yyvsp[0].string));}

    break;

  case 385:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 386:

    {create_strdata((yyvsp[0].string));}

    break;

  case 387:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 391:

    {create_print('s');}

    break;

  case 392:

    {create_print('s');}

    break;

  case 393:

    {create_print('d');}

    break;

  case 394:

    {create_print('u');}

    break;

  case 395:

    {create_print('U');}

    break;

  case 396:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 397:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 398:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 399:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 400:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 401:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 402:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 403:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 404:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 405:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 406:

    {create_pushstr("?");create_print('s');}

    break;

  case 407:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 408:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 409:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 410:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 411:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 412:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 413:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 414:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 415:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 416:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 417:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 418:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 419:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 420:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 421:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 424:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 425:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 426:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 427:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;



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
