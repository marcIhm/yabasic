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
    written by Marc Ihm 1995-2018
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
    tCEIL = 373,
    tFLOOR = 374,
    tFRAC = 375,
    tMOD = 376,
    tRAN = 377,
    tVAL = 378,
    tLEFT = 379,
    tRIGHT = 380,
    tMID = 381,
    tLEN = 382,
    tMIN = 383,
    tMAX = 384,
    tSTR = 385,
    tINKEY = 386,
    tCHR = 387,
    tASC = 388,
    tHEX = 389,
    tDEC = 390,
    tBIN = 391,
    tUPPER = 392,
    tLOWER = 393,
    tMOUSEX = 394,
    tMOUSEY = 395,
    tMOUSEB = 396,
    tMOUSEMOD = 397,
    tTRIM = 398,
    tLTRIM = 399,
    tRTRIM = 400,
    tINSTR = 401,
    tRINSTR = 402,
    tCHOMP = 403,
    tSYSTEM = 404,
    tSYSTEM2 = 405,
    tPEEK = 406,
    tPEEK2 = 407,
    tPOKE = 408,
    tDATE = 409,
    tTIME = 410,
    tTOKEN = 411,
    tTOKENALT = 412,
    tSPLIT = 413,
    tSPLITALT = 414,
    tGLOB = 415,
    UMINUS = 416
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
#define YYFINAL  251
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  430
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1014

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   170,     2,     2,     2,     2,
     166,   167,   163,   162,   169,   161,     2,   164,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   168,
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
     155,   156,   157,   158,   159,   160,   165
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
     329,   330,   331,   332,   333,   334,   335,   336,   337,   340,
     341,   344,   344,   345,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   378,   381,   384,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     451,   452,   453,   456,   457,   460,   461,   464,   465,   466,
     467,   470,   473,   476,   476,   479,   480,   481,   484,   485,
     488,   489,   492,   488,   497,   498,   501,   502,   505,   506,
     507,   508,   511,   512,   515,   516,   517,   518,   521,   522,
     525,   526,   527,   528,   531,   532,   533,   536,   537,   538,
     539,   542,   543,   547,   561,   542,   566,   567,   570,   571,
     574,   575,   580,   580,   584,   585,   588,   589,   593,   595,
     594,   599,   600,   600,   604,   604,   610,   611,   615,   616,
     615,   622,   623,   627,   627,   632,   633,   637,   638,   638,
     640,   637,   644,   645,   648,   648,   652,   653,   656,   658,
     660,   657,   664,   665,   668,   669,   669,   672,   673,   675,
     676,   680,   681,   684,   685,   687,   688,   692,   693,   694,
     695,   698,   699,   700,   701,   702,   705,   706,   707,   710,
     710,   711,   711,   712,   712,   713,   713,   714,   714,   717,
     718,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   734,   737,   738,   740,   741,   744,
     745
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
  "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC", "tMOD", "tRAN",
  "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR",
  "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER",
  "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM",
  "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK",
  "tPEEK2", "tPOKE", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT",
  "tSPLITALT", "tGLOB", "'-'", "'+'", "'*'", "'/'", "UMINUS", "'('", "')'",
  "';'", "','", "'#'", "$accept", "program", "statement_list", "$@1",
  "$@2", "statement", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "assignment", "expression", "$@9", "$@10", "arrayref",
  "string_arrayref", "coordinates", "function", "const", "number",
  "symbol_or_lineno", "dimlist", "function_or_array",
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,    45,    43,    42,    47,   416,    40,    41,    59,    44,
      35
};
# endif

#define YYPACT_NINF -722

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-722)))

#define YYTABLE_NINF -358

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3620,   -42,   -41,  -722,  -722,  -722,  -722,  -722,   173,   173,
     173,  2737,  -722,  -722,  -722,  3272,  -135,  -121,  3272,    28,
      56,  -722,  -722,  -722,  3057,    31,  -722,  3057,   200,  -722,
    3057,  3057,  3057,   302,    63,   173,  1602,  1061,  1922,    10,
    3057,  2577,  3057,    -8,   -10,  3057,  -722,    21,  3272,  3272,
    3272,    45,    15,    53,    68,    70,    90,  1922,   126,   149,
    -722,    64,  -722,  -722,  -722,  -722,   137,   163,  -722,   296,
    -722,  -722,  -722,  -722,  -722,  -722,  -722,  3057,  -722,  3272,
    -722,   256,   150,  3481,  -722,  -722,  -722,  -722,  -722,  -722,
     158,   169,  -722,  -722,   214,   218,   314,   252,   268,  3057,
     278,   284,   288,   391,   392,   394,   407,   408,   410,   417,
     427,   428,   451,   453,   455,   457,   459,   460,   462,   463,
     466,   468,   469,   474,   475,   476,   477,   478,   479,   480,
     481,   484,   487,   488,   489,   490,   491,   493,   494,   500,
     503,   506,   507,   511,   514,   515,   516,   517,   519,   520,
     524,   525,   526,   527,   532,   537,   545,   546,   547,   549,
     550,   551,   552,  3057,  3057,    49,  -722,   327,  -722,  -722,
    -722,  -722,   364,   404,  3272,   317,  -722,  -722,   317,  -722,
    -722,  3057,  3481,   443,   553,   441,   554,     6,  3057,   -32,
      49,  3524,   555,   556,   361,  3524,    49,  1203,    49,  1232,
     558,   561,   373,  -722,  -722,   164,   164,  -722,  -722,   444,
    -722,  3057,  3272,  3057,    75,  3524,   458,  -722,  -722,  -722,
    -722,   470,  3272,  1505,  -722,  3057,  -722,     1,   498,  -722,
    -722,  3057,  2897,  -722,  -722,  3524,  -722,  -722,   137,   163,
     317,    -3,    -3,  -722,   591,   591,   591,  2082,  3272,   286,
     559,  -722,  -722,   581,  3057,  3057,  3057,  3057,  3272,  -722,
    3524,   535,  3057,   317,   564,   645,  3057,    37,  -722,  -722,
    -722,  -722,  3057,  3057,  1438,  3057,  1762,  1922,   406,   406,
    3057,  3057,  3057,  3057,  3057,  3057,  3057,  3057,  3057,  3057,
    3057,  3057,  1922,  3057,  3057,  3057,  3057,  3057,  3057,  3057,
    2247,  3272,  3272,  3272,  3272,  3272,  3057,  3057,  3057,  2412,
    3057,  3272,  3057,  3272,  3057,  3272,  3272,   315,  1225,  1324,
    1401,  3272,  3272,  3272,  3272,  3272,  3272,  3272,  3272,  1922,
    3272,   567,   568,  3272,   591,  3272,   591,  3272,   666,   174,
    1621,  3272,  3272,  3272,  3272,  3272,  3272,  3272,  -722,  -722,
    -722,  -722,  3057,  3057,  3057,  3057,  3057,  3057,  3057,  3057,
    3057,  3057,  3057,   571,   573,   572,  -722,   574,   578,   576,
    -722,   117,   579,   582,    49,  3524,   707,   178,   706,  3759,
    3057,   587,  3272,  -722,  -722,  3057,    49,   261,   202,   588,
      13,  -722,   747,  -722,  -722,   426,  3057,  3057,  -722,  -722,
     302,  -722,  -722,    65,  1777,   317,  3524,   341,  3130,  3057,
     317,  3057,  -722,   -32,  -722,  -722,  3057,  3272,  -722,  3057,
       1,  3057,  3057,   592,   595,   596,   600,  -722,  4189,   266,
    3057,  3057,  -722,   602,     1,     1,  3524,   317,   461,  -722,
      49,  3524,   604,  -722,  -722,  -722,  4200,   608,  -722,  -722,
     609,   610,  1937,  2097,  2262,   611,    41,   606,   614,   616,
     625,   626,   627,   623,   630,     1,  2427,  4211,  4234,  4270,
    4316,  4339,   501,  4350,   719,  4375,  4386,   628,  4397,  4421,
    4455,  4502,  4526,  4537,  2592,  -722,  4560,   275,  -129,   -82,
     -50,   276,  2752,  2912,   773,  -722,  4571,  4582,   294,  4607,
     -11,  4642,   295,   306,  -722,   313,  -722,   330,  -722,   333,
    -722,   352,   356,   358,   359,   -40,   -39,   360,   362,   366,
     309,   629,    16,  -722,  -722,   106,   -77,   170,    66,   171,
    -722,  -722,   317,   317,   317,   317,   317,   317,  -722,   173,
     173,  3057,  3057,  1419,   416,   533,   447,    26,    87,  -722,
      -1,    -1,   666,   666,  -722,  -722,   364,  -722,  -722,   404,
    -722,  -722,  -722,   759,  -722,  -722,  -722,  -722,   758,  3076,
    3057,    40,  4687,  3325,  -722,  -722,  3057,  3057,  -722,  -722,
    3057,  -722,   473,   639,   641,   644,   646,  3894,  3941,   647,
     648,  -722,  -722,  -722,  3057,   729,   733,  -722,   187,  3966,
    3524,  -722,  -722,   220,  -722,  3057,  3977,  4000,  -722,  3057,
    3057,  3057,  -722,  -722,    49,  3524,    49,  3524,  3481,  3057,
    3057,  3057,  -722,  -722,  -722,  3057,  3057,  -722,  3057,  -722,
    -722,  3057,  3057,  3057,  -722,  -722,  3272,  3214,  -722,   649,
     650,  -722,  -722,  3057,  3057,  3057,  3057,  -722,  -722,  -722,
    -722,  -722,  -722,  3057,  -722,  -722,  3057,  -722,  -722,  -722,
    -722,  -722,  -722,  -722,  -722,  -722,  3057,  -722,  -722,  3057,
    3057,  3057,  -722,  3057,  3057,  -722,  3272,  -722,  -722,  -722,
    -722,  -722,  3057,  -722,  -722,  -722,  -722,  -722,  -722,  -722,
    -722,  -722,  -722,  3272,  3272,  -722,  -722,  -722,  -722,  -722,
    -722,  3272,   814,  -722,  3272,   814,  -722,  3272,  3272,  -722,
     651,  -722,   652,  1438,   916,   655,   657,  -722,   658,   659,
    -722,  -722,   456,  3481,  -722,  3057,  4011,   772,  3272,  -722,
    3272,   317,    49,   261,  4022,   473,   473,  4712,   662,   663,
    -722,   661,  -722,  -722,  -722,  -722,  3057,  3057,  -722,  -722,
    4047,  1922,  1922,  3272,  3272,  3272,  -722,  3057,  3057,   664,
    4723,  4747,   842,  -722,  3524,     1,  -722,   669,  -722,    67,
    3481,  4758,  4769,  4792,  4828,   369,   665,    92,  -722,  -722,
    4874,  4897,   677,    -9,  4908,  4933,  4944,  4955,  4979,  1176,
    5013,  5060,   103,  5084,   107,   236,   370,    77,   376,    97,
     377,   386,   173,   173,  -722,  -722,  -722,  -722,  3057,   795,
     809,   806,  5095,  3057,   682,   387,   237,  -722,  3057,  -722,
    -722,  -722,  -722,  -722,  -722,   683,   684,  3524,  3524,  3272,
    -722,  -722,   317,   317,   238,  4083,  3524,  -722,   783,   786,
     787,  3057,  3057,   536,  3057,    25,  -722,  -722,  -722,  -722,
    -722,  -722,  -722,  3272,  -722,  -722,  -722,  3057,  -722,  -722,
    -722,  -722,  -722,  -722,  3057,  -722,  -722,  -722,  3272,  -722,
    -722,  3057,  -722,  3057,  -722,  -722,  3272,  -722,  -722,  3272,
    -722,  -722,  -722,  -722,  -722,  -722,  -722,   811,   448,  5118,
    3057,   803,  3272,  5129,   473,   692,   693,   473,  -722,  -722,
     317,  3272,  3272,  3272,  3272,  3272,  5140,  -722,   695,   697,
     116,  -722,    33,  -722,  -722,  -722,   388,  4128,  5165,   389,
    5200,  5245,   397,   422,  3481,  3898,  3057,   819,  -722,   699,
    -722,  4153,   700,   424,  -722,  -722,  -722,  -722,  -722,   317,
     317,   317,   317,   317,   798,   701,   703,  -722,   536,  3057,
    -722,  -722,  3057,  -722,  -722,  -722,  -722,  -722,  -722,   806,
     835,   640,  3481,  -722,  3272,  3057,  3057,  -722,   747,  3272,
    -722,  -722,  3481,  -722,  3524,  3481,  5270,  -722,  -722,   806,
     548,   250,  5281,  4164,   473,   317,    23,   806,  -722,  3481,
    -722,  -722,  -722,  -722,  3272,  -722,  3057,  -722,  -722,  -722,
    -722,    22,   806,   430,  5305,  -722,  -722,   868,   811,  -722,
    -722,  -722,  -722,  -722
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     108,     0,     0,   106,   321,   348,   353,    12,     0,     0,
       0,     0,    25,    27,   299,     0,     0,     0,     0,   300,
      19,    21,   332,   344,     0,   411,    49,    61,     0,   103,
     104,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     4,
       3,     0,     8,    40,    42,    10,    23,    24,    22,     0,
      14,    15,    18,    17,    16,    29,    30,     0,   283,     0,
     283,     0,     0,     7,   276,   275,    31,    32,    39,   273,
     190,   130,   274,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   244,   247,   250,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   156,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,   203,   184,
     189,   132,     0,     0,     0,    13,   283,   283,    43,   301,
      20,     0,     7,   364,     0,   415,     0,     0,   391,   407,
      63,    62,     0,     0,    64,   105,    54,     0,    56,     0,
     383,   385,    57,   381,   387,     0,     0,   388,   270,    58,
      60,     0,    90,     0,     0,   426,     0,    87,    92,    80,
      41,     0,     0,     0,    68,     0,    51,    73,     0,    89,
      88,     0,     0,   111,   112,    93,     9,    11,     0,     0,
     107,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,   290,
     169,     0,   285,   113,     0,     0,     0,     4,   283,   283,
      33,    34,     0,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    37,
     173,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,   305,    26,   302,   310,   311,    28,
     308,     0,     0,     0,   337,   336,     0,     4,     0,   108,
       0,     0,     0,   412,   413,     0,   394,   396,    46,     0,
       0,    50,   409,   283,   283,     0,     0,     0,   283,   283,
       0,   272,   271,     0,     0,    91,   425,     0,     0,     0,
      67,     0,    72,   407,   120,   119,     0,     0,    69,     0,
      75,     0,     0,   128,     0,     0,     0,    96,     0,     0,
       0,     0,     5,     0,     0,     0,   170,   118,     0,   281,
     288,   289,   284,   286,   282,   322,     0,     0,   355,   354,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,   248,     0,   251,     0,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   157,     0,     0,     0,     0,     0,
     135,   204,   198,   200,   202,   199,   201,   197,   134,     0,
       0,     0,     0,   177,   179,   181,   178,   180,   176,   195,
     192,   191,   193,   194,   283,   283,     0,   283,   283,     0,
      44,    45,   334,   338,   347,   346,   345,   358,     4,     0,
       0,     0,     0,     0,   392,    47,    48,     0,   399,   401,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   389,   390,     0,     0,     0,   123,   122,   126,
     207,    52,    70,    83,    74,     0,     0,     0,   283,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     7,     0,
       0,     0,   296,   297,   291,     0,     0,   349,     0,   263,
     168,     0,     0,     0,   264,   265,     0,     0,   258,     0,
       0,   185,   186,     0,     0,     0,     0,   208,   209,   210,
     211,   212,   213,     0,   215,   216,     0,   218,   219,   182,
     224,   225,   220,   221,   222,   223,     0,   227,   232,     0,
       0,     0,   231,     0,     0,   140,     0,   145,   146,   233,
     166,   234,     0,   167,   147,   148,   243,   246,   249,   252,
     151,   149,   150,     0,     0,   152,   153,   240,   242,   241,
     158,     0,     0,   161,     0,     0,   163,     0,     0,   427,
      36,   429,    38,   174,   172,     0,     0,   303,     0,     0,
     309,   335,   341,     7,   365,     0,     0,   416,     0,   414,
       0,   397,   395,   396,     0,     0,     0,     0,   377,   379,
     408,   374,   277,   279,   283,   283,     0,     0,   384,   386,
      65,     0,     0,     0,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     6,    81,     0,    86,     0,   287,     0,
       7,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,   307,   312,   313,     0,     0,
       0,   359,     0,     0,     0,     0,     0,   393,     0,   400,
     402,   403,   283,   283,   375,     0,     0,    53,    55,     0,
     124,   125,   121,   127,    84,    77,    78,   129,     0,     0,
       0,     0,     0,   314,     0,     4,   356,   255,   256,   257,
     266,   267,   268,     0,   187,   188,   164,     0,   214,   217,
     226,   136,   137,   139,     0,   229,   230,   141,     0,   235,
     236,     0,   238,     0,   159,   260,     0,   160,   262,     0,
     162,   183,   428,   430,   339,   342,   333,   368,   418,     0,
       0,   417,     0,     0,     0,     0,     0,     0,   278,   280,
      66,     0,     0,     0,     0,     0,     0,    82,   317,   318,
       0,   315,   328,   352,   351,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   108,     0,   366,   422,     0,
     419,     0,     0,     0,   405,   404,   378,   380,   376,    85,
      76,   116,   117,   115,     0,     0,     0,   292,     0,     0,
     323,   269,     0,   138,   142,   237,   239,   259,   261,   340,
       4,   372,     7,   360,     0,     0,     0,   398,   409,     0,
     319,   320,     7,   316,   329,     7,     0,   373,   369,   367,
       0,     0,     0,     0,     0,   114,     4,   324,   165,     7,
     362,   363,   361,   423,     0,   420,     0,   406,   295,   294,
     293,     0,   370,     0,     0,   327,   326,   330,   368,   424,
     421,   331,   325,   371
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -722,  -722,   -71,  -722,  -722,   255,  -722,  -722,  -722,  -722,
    -722,  -722,  -722,   827,  -220,  -722,  -722,   -81,   711,  -722,
     830,     5,  -722,  -722,   605,  -273,   -33,  -722,   486,   -31,
      -5,  -722,     0,     2,   -56,  -722,  -722,   254,  -722,  -722,
    -722,  -722,  -722,  -722,  -722,  -722,   331,  -722,   334,  -722,
     -58,  -722,  -722,  -722,  -722,  -722,  -722,  -722,  -722,  -722,
    -722,  -722,    86,  -722,  -722,  -722,  -722,  -722,  -722,  -722,
    -722,  -722,  -722,  -722,  -722,  -722,  -722,  -722,  -722,  -722,
    -722,  -722,  -722,  -722,  -722,  -722,  -112,  -722,  -722,  -722,
    -721,  -722,  -722,  -722,   497,  -722,  -722,   165,   492,  -722,
    -722,  -722,  -722,  -722,   -68,  -722,   -19,  -722,  -722
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   253,   618,    60,   172,   173,   539,   540,
     189,   413,    61,    62,   416,    63,    64,   424,   165,   166,
      65,   223,   542,   541,   461,   462,   224,   168,   207,   169,
      86,   194,   170,   171,   261,   262,   442,   443,    68,   438,
     767,   972,  1000,   624,    69,   365,   366,   369,   370,   910,
     911,    70,    81,   626,   975,  1001,  1007,   950,  1012,    71,
     181,   563,   376,   722,   924,   810,   925,    72,   182,   566,
      73,    82,   770,   915,    74,    83,   449,    75,   378,   723,
     887,   980,   992,    76,   379,   963,   927,   989,  1008,   978,
     740,   897,   741,   202,   203,   209,   388,   574,   391,   735,
     736,   894,   968,   392,   582,   188,   216,   710,   712
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   414,    67,   208,    87,    88,   464,   414,   227,   228,
     383,   414,   267,   384,   819,   820,   167,   578,   220,   221,
     579,   421,   422,   389,   264,     1,     2,    77,    79,   183,
     210,   176,   191,   347,  1005,   195,   197,   199,   250,   913,
     669,   215,   215,   215,   949,   177,   998,   238,   229,   239,
     235,   350,   351,   447,   179,   352,   353,   354,   355,   356,
     357,   358,   215,   180,  1006,   999,    89,   914,    89,   358,
      92,   204,    92,   592,   230,   231,   232,   844,   234,   448,
     347,   233,   260,    66,   407,    67,   184,   670,   185,   186,
     703,   222,   704,   350,   351,   357,   358,   352,   353,   354,
     355,   356,   357,   358,   274,   341,   342,   343,   344,   345,
     346,   377,   347,   341,   342,   343,   344,   345,   346,   671,
     372,   373,   347,   347,    78,    80,   251,   350,   351,   693,
     694,   352,   353,   354,   355,   356,   357,   358,   390,   341,
     342,   343,   344,   345,   346,    52,    53,    54,   243,   254,
     255,   347,   359,   360,   361,   362,   681,   358,   682,   347,
     415,   256,   361,   362,   425,   426,   415,    89,   338,   340,
     415,    92,   385,   935,   401,   402,   938,    84,   347,   580,
      85,   244,    66,   700,    67,   701,   375,   359,   360,   361,
     362,   252,   412,   387,   359,   360,   361,   362,   418,   420,
     605,   187,   347,   347,   192,   193,   257,   727,   635,   728,
     636,   347,   450,   451,   620,   621,   404,   564,   406,   245,
     565,   433,   434,   435,   205,   206,   205,   206,   359,   360,
     361,   362,   258,   706,   246,   707,   247,   347,   341,   342,
     343,   344,   345,   346,   875,   645,   876,   465,   359,   360,
     361,   362,   428,   526,   347,   528,   248,   457,   458,   852,
     265,   853,   436,   997,   878,   347,   879,   441,   347,   347,
     867,   446,   868,   477,   870,   702,   871,   452,   453,   347,
     454,   215,   215,   947,   530,   948,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   215,   478,   479,
     480,   481,   482,   483,   484,   486,   200,   201,   568,   573,
     521,   492,   493,   494,   496,   497,   266,   499,   259,   501,
      91,   350,   351,    93,    78,   352,   353,   354,   355,   356,
     357,   358,   347,   347,   215,    80,   347,   583,   584,   705,
     708,   530,   589,   590,    95,   348,   349,   270,   271,   347,
     341,   342,   343,   344,   345,   346,   753,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   363,   364,
     575,   576,   208,   341,   342,   343,   344,   345,   346,    66,
     268,    67,   347,   602,   269,   569,   604,   350,   351,   755,
     572,   352,   353,   354,   355,   356,   357,   358,   347,   347,
     347,   587,   588,   872,   530,   873,   892,   901,   367,   368,
     459,   460,   347,   105,   599,   106,   600,   993,   272,   994,
     595,   596,   359,   360,   361,   362,   606,   607,   347,   797,
     585,   586,   799,   613,   273,   615,   617,   347,   347,   127,
     128,   129,   668,   672,   275,   133,   134,   135,   347,   137,
     276,   139,   140,   141,   277,   430,   347,   347,   146,   147,
     148,   679,   684,   151,   152,   622,   623,   155,   347,   156,
     157,   347,   159,   685,   161,   347,   698,   738,   739,   347,
     686,   174,   504,   355,   356,   357,   358,  -357,   359,   360,
     361,   362,   347,   808,   809,   347,   381,   687,   715,   716,
     688,   718,   719,   350,   351,   928,   929,   352,   353,   354,
     355,   356,   357,   358,   347,   356,   357,   358,   347,   689,
     347,   347,   347,   690,   347,   691,   692,   695,   347,   696,
     395,   347,   347,   697,   709,   711,   850,   874,   347,   347,
     908,   909,   400,   877,   880,   842,   713,   714,   347,   347,
     347,   347,   759,   881,   891,   951,   954,   278,   279,   347,
     280,   350,   351,   857,   957,   352,   353,   354,   355,   356,
     357,   358,   756,   281,   282,   726,   283,   359,   360,   361,
     362,   733,   734,   284,   347,   737,   347,   765,   766,   958,
     990,   967,   347,   285,   286,   991,   423,  1009,   353,   750,
     355,   356,   357,   358,   359,   360,   361,   362,   359,   360,
     361,   362,   782,   403,   760,   761,   762,   287,    66,   288,
      67,   289,   432,   290,   764,   291,   292,   408,   293,   294,
     441,   769,   295,   771,   296,   297,   772,   773,   774,   409,
     298,   299,   300,   301,   302,   303,   304,   305,   780,   781,
     306,   783,   811,   307,   308,   309,   310,   311,   784,   312,
     313,   785,   359,   360,   361,   362,   314,   417,   652,   315,
     653,   786,   316,   317,   787,   788,   789,   318,   790,   791,
     319,   320,   321,   322,   977,   323,   324,   793,   825,   826,
     325,   326,   327,   328,   359,   360,   361,   362,   329,   845,
     350,   351,   439,   330,   352,   353,   354,   355,   356,   357,
     358,   331,   332,   333,   445,   334,   335,   336,   337,   380,
     382,   393,   394,    66,   398,    67,   175,   399,   431,   178,
     812,   444,   830,   831,   523,   524,   358,   554,   190,   555,
     557,   556,   196,   198,   558,   559,   560,   214,   562,   561,
     567,   827,   828,   570,   577,   581,   215,   215,   608,   240,
     241,   242,   835,   836,   609,   610,   895,   896,   249,   611,
      66,   619,    67,   625,   628,   637,   629,   630,   634,   350,
     351,   638,   639,   352,   353,   354,   355,   356,   357,   358,
     263,   640,   643,   641,   642,   659,   699,   882,   883,   644,
     721,   359,   360,   361,   362,   724,   742,   751,   743,   907,
     744,   752,   745,   375,   748,   749,   778,   779,   889,   460,
     802,   803,   804,   893,   805,   806,   807,   814,   822,   823,
     824,   837,   851,   350,   351,   843,   885,   352,   353,   354,
     355,   356,   357,   358,   856,   886,   906,    -4,   890,   912,
     898,   899,   903,   959,   960,   904,   905,   926,   932,   936,
     937,   945,   917,   946,   962,   964,   966,   969,   970,   918,
     971,  -343,  1011,   763,   236,   339,   920,   237,   921,   768,
     359,   360,   361,   362,   463,   371,   655,   717,   656,   593,
     973,   979,   374,   720,   884,   931,  1013,   591,   817,   386,
     984,   986,   350,   351,   987,   601,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,  1002,     0,
       0,     0,     0,   405,    66,    66,    67,    67,     0,     0,
       0,   961,     0,   410,   359,   360,   361,   362,     0,     0,
     675,     0,   676,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   974,     0,     0,   976,     0,   429,
       0,     0,    66,     0,    67,     0,     0,     0,     0,   437,
     982,   983,    66,   440,    67,    66,   350,    67,     0,     0,
     352,   353,   354,   355,   356,   357,   358,   456,     0,    66,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1004,     0,   359,   360,   361,   362,     0,     0,   840,
       0,   841,   487,   488,   489,   490,   491,     0,     0,     0,
       0,     0,   498,     0,   500,     0,   502,   503,   505,   507,
     509,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   522,     0,     0,   525,     0,   527,     0,   529,     0,
       0,     0,   532,   533,   534,   535,   536,   537,   538,     0,
       0,     0,     0,     0,    89,    90,    91,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   598,
       0,    97,    98,    99,   100,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,   101,     0,     0,   102,     0,
       0,   614,   616,   217,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,   103,   104,     0,     0,   105,
       0,   106,     0,     0,   219,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,   164,     0,     0,
      91,   213,     0,    93,     0,     0,   350,   351,     0,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   731,     0,     0,   732,     0,     0,
       0,     0,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,   106,     0,     0,     0,    91,
       0,     0,    93,     0,     0,     0,   440,   359,   360,   361,
     362,     0,     0,   863,     0,   864,     0,   775,   777,   127,
     128,   129,     0,    95,     0,   133,   134,   135,     0,   137,
       0,   139,   140,   141,   359,   360,   361,   362,   146,   147,
     148,     0,   396,   151,   152,     0,     0,   155,     0,   156,
     157,     0,   159,     0,   161,     0,     0,   792,     0,     0,
       0,   174,   506,   359,   360,   361,   362,     0,     0,     0,
       0,   397,     0,     0,   794,   795,    91,     0,     0,    93,
       0,     0,   796,     0,     0,   798,     0,     0,   800,   801,
       0,     0,   105,     0,   106,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   815,
       0,   816,     0,     0,     0,     0,     0,     0,   127,   128,
     129,     0,     0,     0,   133,   134,   135,     0,   137,     0,
     139,   140,   141,     0,   832,   833,   834,   146,   147,   148,
       0,     0,   151,   152,     0,     0,   155,     0,   156,   157,
       0,   159,     0,   161,   353,   354,   355,   356,   357,   358,
     174,   508,     0,     0,     0,     0,     0,     0,     0,   105,
       0,   106,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
       0,     0,     0,     0,     0,   127,   128,   129,     0,     0,
       0,   133,   134,   135,     0,   137,     0,   139,   140,   141,
     900,     0,     0,     0,   146,   147,   148,     0,     0,   151,
     152,     0,     0,   155,     0,   156,   157,     0,   159,     0,
     161,     0,     0,     0,   916,   350,   351,   174,   510,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,   919,
     359,   360,   361,   362,     0,     0,     0,   922,     0,     0,
     923,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   933,     0,    89,    90,    91,     0,    92,
      93,     0,   939,   940,   941,   942,   943,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   359,   360,   361,   362,
       0,     0,     0,     0,   411,   981,   101,     0,     0,   102,
     985,   350,   351,     0,   211,   352,   353,   354,   355,   356,
     357,   358,   212,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,  1003,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,    89,    90,    91,   164,    92,
      93,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   531,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   350,   351,   102,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   455,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,    89,    90,    91,   164,    92,
      93,     0,   213,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   594,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   350,   351,   102,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,    89,    90,    91,   164,    92,
      93,     0,   213,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   631,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   350,   351,   102,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,   164,   427,
      89,    90,    91,     0,    92,    93,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   632,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   350,   351,   102,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,   164,   485,    89,    90,    91,     0,    92,
      93,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   350,   351,   102,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,   164,   495,
      89,    90,    91,     0,    92,    93,     0,   225,   359,   360,
     361,   362,     0,     0,     0,     0,   646,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   350,   351,   102,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
      89,    90,    91,   164,    92,    93,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   666,     0,     0,     0,    94,    95,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   350,   351,   102,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
      89,    90,    91,   164,    92,    93,     0,   419,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   673,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   350,   351,   102,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
      89,    90,    91,   164,    92,    93,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   674,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,   102,    91,   350,   351,    93,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,    95,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,    91,
     597,     0,    93,   164,     0,     0,     0,     0,   105,     0,
     106,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,    95,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   129,     0,     0,     0,
     133,   134,   135,     0,   137,     0,   139,   140,   141,     0,
       0,     0,     0,   146,   147,   148,     0,    91,   151,   152,
      93,     0,   155,     0,   156,   157,     0,   159,     0,   161,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,    95,     0,     0,   776,     0,     0,     0,     0,     0,
       0,     0,   105,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    93,     0,     0,     0,     0,   127,   128,
     129,     0,     0,     0,   133,   134,   135,     0,   137,     0,
     139,   140,   141,     0,    95,     0,     0,   146,   147,   148,
       0,     0,   151,   152,     0,     0,   155,     0,   156,   157,
     105,   159,   106,   161,     0,     0,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,   129,     0,
       0,     0,   133,   134,   135,     0,   137,     0,   139,   140,
     141,     0,     0,     0,     0,   146,   147,   148,     0,     0,
     151,   152,     0,   105,   155,   106,   156,   157,     0,   159,
       0,   161,     0,     0,     0,     0,     0,     0,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,     0,     0,     0,   133,   134,   135,     0,   137,
       0,   139,   140,   141,     0,     0,     0,     0,   146,   147,
     148,     0,     0,   151,   152,     0,     0,   155,     0,   156,
     157,     0,   159,     0,   161,     1,     2,     3,     0,     0,
       4,   730,     0,     0,     5,     0,     6,     0,     7,     8,
       9,    10,    11,  -298,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,     0,     0,     0,
       0,    23,     0,     0,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,  -108,  -108,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,  -108,     0,
      49,     0,    50,    51,   350,   351,     0,     0,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     0,     0,     4,
       0,    56,     0,     5,    57,     6,     0,     7,     8,     9,
      10,    11,  -298,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,     0,     0,     0,     0,
      23,    -7,    -7,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,    31,    32,
       0,     0,     0,     0,     0,   359,   360,   361,   362,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,     0,     0,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,     0,     0,    49,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     0,     4,     0,
      56,     0,     5,    57,     6,     0,     7,     8,     9,    10,
      11,  -298,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
      -7,     0,    24,     0,     0,     0,    -7,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     0,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,     0,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     0,     4,     0,    56,
       0,     5,    57,     6,     0,     7,     8,     9,    10,    11,
    -298,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    -7,     0,     0,     0,    23,    -7,
       0,    24,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,     0,   350,   351,    31,    32,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,   350,   351,     0,    55,
     352,   353,   354,   355,   356,   357,   358,   350,   351,     0,
       0,   352,   353,   354,   355,   356,   357,   358,    56,     0,
       0,    57,     0,     0,     0,   359,   360,   361,   362,     0,
     350,   351,     0,   746,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,     0,   350,   351,     0,
     747,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,     0,     0,   754,     0,     0,   359,   360,
     361,   362,     0,   350,   351,     0,   757,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,     0,     0,   758,
       0,     0,   359,   360,   361,   362,     0,     0,     0,     0,
     813,     0,     0,   359,   360,   361,   362,     0,   350,   351,
       0,   818,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,   350,   351,     0,   829,   352,   353,   354,
     355,   356,   357,   358,   350,   351,     0,     0,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,     0,   350,
     351,     0,   902,   352,   353,   354,   355,   356,   357,   358,
     350,   351,     0,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,   350,   351,     0,   952,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,     0,     0,
       0,     0,   965,     0,     0,   359,   360,   361,   362,     0,
     350,   351,     0,   996,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   360,   361,   362,     0,     0,   612,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   627,     0,     0,
       0,     0,   359,   360,   361,   362,   350,   351,   647,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,   350,
     351,   648,     0,   352,   353,   354,   355,   356,   357,   358,
     350,   351,     0,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   649,     0,   352,
     353,   354,   355,   356,   357,   358,   350,   351,     0,     0,
     352,   353,   354,   355,   356,   357,   358,   350,   351,     0,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,   350,   351,   650,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   360,   361,   362,     0,     0,   651,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   654,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,   657,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   658,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   660,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,   350,   351,   661,     0,
     352,   353,   354,   355,   356,   357,   358,   350,   351,     0,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   662,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   663,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   664,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   665,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   667,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   677,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   678,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   680,     0,   352,   353,   354,   355,
     356,   357,   358,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   683,
       0,   352,   353,   354,   355,   356,   357,   358,   350,   351,
       0,     0,   352,   353,   354,   355,   356,   357,   358,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   729,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,   821,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     838,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,   839,     0,     0,     0,     0,   359,
     360,   361,   362,     0,     0,   846,     0,     0,     0,     0,
     359,   360,   361,   362,   350,   351,   847,     0,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   848,
       0,   352,   353,   354,   355,   356,   357,   358,   350,   351,
       0,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   849,     0,   352,   353,   354,
     355,   356,   357,   358,   350,   351,     0,     0,   352,   353,
     354,   355,   356,   357,   358,   350,   351,     0,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,   350,
     351,   854,     0,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,   855,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   858,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,     0,     0,
     859,     0,     0,     0,     0,   359,   360,   361,   362,     0,
       0,   860,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   861,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   360,   361,   362,   350,   351,   862,     0,   352,   353,
     354,   355,   356,   357,   358,   350,   351,     0,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     865,     0,   352,   353,   354,   355,   356,   357,   358,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
     350,   351,     0,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   866,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,     0,
       0,   869,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   888,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,     0,   930,     0,     0,     0,     0,
     359,   360,   361,   362,     0,     0,   934,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   944,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   953,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   955,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,   956,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   988,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   995,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,  1010
};

static const yytype_int16 yycheck[] =
{
       0,    10,     0,    34,     9,    10,   279,    10,    41,    42,
       4,    10,    83,     7,   735,   736,    11,     4,    37,    38,
       7,   241,   242,    55,    80,     4,     5,    69,    69,    24,
      35,   166,    27,   162,    12,    30,    31,    32,    57,    14,
     169,    36,    37,    38,    11,   166,    23,    47,    56,    47,
      45,    60,    61,    16,    26,    64,    65,    66,    67,    68,
      69,    70,    57,     7,    42,    42,     3,    42,     3,    70,
       7,     8,     7,     8,    82,    83,    84,    10,    88,    42,
     162,    89,    77,    83,     9,    83,    55,   169,    57,    58,
     167,    81,   169,    60,    61,    69,    70,    64,    65,    66,
      67,    68,    69,    70,    99,    64,    65,    66,    67,    68,
      69,   182,   162,    64,    65,    66,    67,    68,    69,   169,
     176,   177,   162,   162,   166,   166,     0,    60,    61,   169,
     169,    64,    65,    66,    67,    68,    69,    70,   170,    64,
      65,    66,    67,    68,    69,   124,   125,   126,   103,    85,
      86,   162,   161,   162,   163,   164,   167,    70,   169,   162,
     169,    97,   163,   164,   245,   246,   169,     3,   163,   164,
     169,     7,   166,   894,   205,   206,   897,     4,   162,   166,
       7,   166,   182,   167,   182,   169,   181,   161,   162,   163,
     164,    42,   225,   188,   161,   162,   163,   164,   231,   232,
     420,   170,   162,   162,     4,     5,    69,   167,   167,   169,
     169,   162,   268,   269,   434,   435,   211,    39,   213,   166,
      42,   254,   255,   256,   161,   162,   161,   162,   161,   162,
     163,   164,    69,   167,   166,   169,   166,   162,    64,    65,
      66,    67,    68,    69,   167,   465,   169,   280,   161,   162,
     163,   164,   247,   334,   162,   336,   166,   276,   277,   167,
       4,   169,   257,   984,   167,   162,   169,   262,   162,   162,
     167,   266,   169,   292,   167,   169,   169,   272,   273,   162,
     275,   276,   277,   167,   167,   169,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,     4,     5,   379,    48,
     329,   306,   307,   308,   309,   310,   166,   312,    22,   314,
       5,    60,    61,     8,   166,    64,    65,    66,    67,    68,
      69,    70,   162,   162,   329,   166,   162,   393,   394,   169,
     169,   167,   398,   399,    29,    18,    19,    33,    34,   162,
      64,    65,    66,    67,    68,    69,   169,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     4,     5,
     168,   169,   403,    64,    65,    66,    67,    68,    69,   379,
     166,   379,   162,   416,   166,   380,   419,    60,    61,   169,
     385,    64,    65,    66,    67,    68,    69,    70,   162,   162,
     162,   396,   397,   167,   167,   169,   169,   169,     4,     5,
       4,     5,   162,    98,   409,   100,   411,   167,   166,   169,
      79,    80,   161,   162,   163,   164,   421,   422,   162,   702,
       4,     5,   705,   167,   166,   430,   431,   162,   162,   124,
     125,   126,   167,   167,   166,   130,   131,   132,   162,   134,
     166,   136,   137,   138,   166,   169,   162,   162,   143,   144,
     145,   167,   167,   148,   149,     4,     5,   152,   162,   154,
     155,   162,   157,   167,   159,   162,   167,     4,     5,   162,
     167,   166,   167,    67,    68,    69,    70,    44,   161,   162,
     163,   164,   162,    37,    38,   162,    55,   167,   554,   555,
     167,   557,   558,    60,    61,    57,    58,    64,    65,    66,
      67,    68,    69,    70,   162,    68,    69,    70,   162,   167,
     162,   162,   162,   167,   162,   167,   167,   167,   162,   167,
     169,   162,   162,   167,   539,   540,   167,   167,   162,   162,
       4,     5,   169,   167,   167,   765,   541,   542,   162,   162,
     162,   162,   608,   167,   167,   167,   167,   166,   166,   162,
     166,    60,    61,   783,   167,    64,    65,    66,    67,    68,
      69,    70,   605,   166,   166,   570,   166,   161,   162,   163,
     164,   576,   577,   166,   162,   580,   162,   620,   621,   167,
      42,   167,   162,   166,   166,    47,     5,   167,    65,   594,
      67,    68,    69,    70,   161,   162,   163,   164,   161,   162,
     163,   164,   645,   169,   609,   610,   611,   166,   618,   166,
     618,   166,    41,   166,   619,   166,   166,   169,   166,   166,
     625,   626,   166,   628,   166,   166,   631,   632,   633,   169,
     166,   166,   166,   166,   166,   166,   166,   166,   643,   644,
     166,   646,   723,   166,   166,   166,   166,   166,   653,   166,
     166,   656,   161,   162,   163,   164,   166,   169,   167,   166,
     169,   666,   166,   166,   669,   670,   671,   166,   673,   674,
     166,   166,   166,   166,    44,   166,   166,   682,   744,   745,
     166,   166,   166,   166,   161,   162,   163,   164,   166,   770,
      60,    61,   167,   166,    64,    65,    66,    67,    68,    69,
      70,   166,   166,   166,    69,   166,   166,   166,   166,   166,
     166,   166,   166,   723,   166,   723,    15,   166,   169,    18,
     725,   167,   751,   752,   167,   167,    70,   166,    27,   166,
     166,   169,    31,    32,   166,   169,   167,    36,    41,   167,
      44,   746,   747,   166,   166,     8,   751,   752,   166,    48,
      49,    50,   757,   758,   169,   169,   822,   823,    57,   169,
     770,   169,   770,   169,   166,   169,   167,   167,   167,    60,
      61,   167,   166,    64,    65,    66,    67,    68,    69,    70,
      79,   166,   169,   167,   167,   167,   167,   802,   803,   169,
      41,   161,   162,   163,   164,    47,   167,    78,   167,   842,
     166,    78,   166,   808,   167,   167,   167,   167,   813,     5,
     169,   169,   167,   818,   167,   167,   167,    55,   166,   166,
     169,   167,   167,    60,    61,   166,    41,    64,    65,    66,
      67,    68,    69,    70,   167,    36,   841,    41,   166,   844,
     167,   167,    69,   924,   925,    69,    69,    46,    55,   167,
     167,   166,   857,   166,    45,   166,   166,    69,   167,   864,
     167,    36,     4,   618,    47,   164,   871,    47,   873,   625,
     161,   162,   163,   164,   279,   174,   167,   556,   169,   403,
     948,   962,   181,   559,   808,   890,  1008,   400,   733,   188,
     968,   972,    60,    61,   975,   413,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,   989,    -1,
      -1,    -1,    -1,   212,   924,   925,   924,   925,    -1,    -1,
      -1,   926,    -1,   222,   161,   162,   163,   164,    -1,    -1,
     167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   949,    -1,    -1,   952,    -1,   248,
      -1,    -1,   962,    -1,   962,    -1,    -1,    -1,    -1,   258,
     965,   966,   972,   262,   972,   975,    60,   975,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,   276,    -1,   989,
      -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   996,    -1,   161,   162,   163,   164,    -1,    -1,   167,
      -1,   169,   301,   302,   303,   304,   305,    -1,    -1,    -1,
      -1,    -1,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,    -1,    -1,   333,    -1,   335,    -1,   337,    -1,
      -1,    -1,   341,   342,   343,   344,   345,   346,   347,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,   430,   431,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,
       5,   170,    -1,     8,    -1,    -1,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   573,    -1,    -1,   576,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,     5,
      -1,    -1,     8,    -1,    -1,    -1,   625,   161,   162,   163,
     164,    -1,    -1,   167,    -1,   169,    -1,   636,   637,   124,
     125,   126,    -1,    29,    -1,   130,   131,   132,    -1,   134,
      -1,   136,   137,   138,   161,   162,   163,   164,   143,   144,
     145,    -1,   169,   148,   149,    -1,    -1,   152,    -1,   154,
     155,    -1,   157,    -1,   159,    -1,    -1,   676,    -1,    -1,
      -1,   166,   167,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,   693,   694,     5,    -1,    -1,     8,
      -1,    -1,   701,    -1,    -1,   704,    -1,    -1,   707,   708,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   728,
      -1,   730,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,    -1,
     136,   137,   138,    -1,   753,   754,   755,   143,   144,   145,
      -1,    -1,   148,   149,    -1,    -1,   152,    -1,   154,   155,
      -1,   157,    -1,   159,    65,    66,    67,    68,    69,    70,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   808,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,    -1,   136,   137,   138,
     829,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,   148,
     149,    -1,    -1,   152,    -1,   154,   155,    -1,   157,    -1,
     159,    -1,    -1,    -1,   853,    60,    61,   166,   167,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,   868,
     161,   162,   163,   164,    -1,    -1,    -1,   876,    -1,    -1,
     879,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,   892,    -1,     3,     4,     5,    -1,     7,
       8,    -1,   901,   902,   903,   904,   905,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,   964,    74,    -1,    -1,    77,
     969,    60,    61,    -1,    82,    64,    65,    66,    67,    68,
      69,    70,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,    -1,   994,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,     3,     4,     5,   166,     7,
       8,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    60,    61,    77,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,     3,     4,     5,   166,     7,
       8,    -1,   170,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,     3,     4,     5,   166,     7,
       8,    -1,   170,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
       3,     4,     5,    -1,     7,     8,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    60,    61,    77,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,   167,     3,     4,     5,    -1,     7,
       8,    -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,   167,
       3,     4,     5,    -1,     7,     8,    -1,    10,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    60,    61,    77,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
       3,     4,     5,   166,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    60,    61,    77,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
       3,     4,     5,   166,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    60,    61,    77,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
       3,     4,     5,   166,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,     5,    60,    61,     8,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    29,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,     5,
      90,    -1,     8,   166,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,    29,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,    -1,   134,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,     5,   148,   149,
       8,    -1,   152,    -1,   154,   155,    -1,   157,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,    -1,
     136,   137,   138,    -1,    29,    -1,    -1,   143,   144,   145,
      -1,    -1,   148,   149,    -1,    -1,   152,    -1,   154,   155,
      98,   157,   100,   159,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,   130,   131,   132,    -1,   134,    -1,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
     148,   149,    -1,    98,   152,   100,   154,   155,    -1,   157,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
      -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,   148,   149,    -1,    -1,   152,    -1,   154,
     155,    -1,   157,    -1,   159,     4,     5,     6,    -1,    -1,
       9,   166,    -1,    -1,    13,    -1,    15,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    92,    93,    -1,    -1,    96,    97,    -1,
      99,    -1,   101,   102,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,
      -1,   150,    -1,    13,   153,    15,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    87,    88,    89,
      -1,    91,    92,    93,    -1,    -1,    96,    -1,    -1,    99,
      -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,    -1,
     150,    -1,    13,   153,    15,    -1,    17,    18,    19,    20,
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
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,    -1,    -1,     9,    -1,   150,
      -1,    13,   153,    15,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    -1,    60,    61,    58,    59,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    87,    88,    89,    -1,    91,
      92,    93,    -1,    -1,    96,    -1,    -1,    99,    -1,   101,
     102,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,    -1,    60,    61,    -1,   131,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,   150,    -1,
      -1,   153,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      60,    61,    -1,   169,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    60,    61,    -1,
     169,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,   161,   162,
     163,   164,    -1,    60,    61,    -1,   169,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
     169,    -1,    -1,   161,   162,   163,   164,    -1,    60,    61,
      -1,   169,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    60,    61,    -1,   169,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    60,
      61,    -1,   169,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    60,    61,    -1,   169,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,   161,   162,   163,   164,    -1,
      60,    61,    -1,   169,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    60,    61,   167,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,
      61,   167,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    60,    61,   167,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    60,    61,   167,    -1,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    60,    61,   167,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,
      61,   167,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
     167,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    60,    61,   167,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167
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
     101,   102,   124,   125,   126,   131,   150,   153,   172,   173,
     176,   183,   184,   186,   187,   191,   203,   204,   209,   215,
     222,   230,   238,   241,   245,   248,   254,    69,   166,    69,
     166,   223,   242,   246,     4,     7,   201,   201,   201,     3,
       4,     5,     7,     8,    28,    29,    32,    60,    61,    62,
      63,    74,    77,    94,    95,    98,   100,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   154,   155,   156,   157,
     158,   159,   160,   161,   166,   189,   190,   192,   198,   200,
     203,   204,   177,   178,   166,   189,   166,   166,   189,    26,
       7,   231,   239,   192,    55,    57,    58,   170,   276,   181,
     189,   192,     4,     5,   202,   192,   189,   192,   189,   192,
       4,     5,   264,   265,     8,   161,   162,   199,   200,   266,
     201,    82,    90,   170,   189,   192,   277,    82,    90,   103,
     277,   277,    81,   192,   197,    10,    50,   197,   197,    56,
      82,    83,    84,    89,    88,   192,   184,   191,   203,   204,
     189,   189,   189,   103,   166,   166,   166,   166,   166,   189,
     277,     0,    42,   174,    85,    86,    97,    69,    69,    22,
     192,   205,   206,   189,   205,     4,   166,   173,   166,   166,
      33,    34,   166,   166,   192,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   192,   189,
     192,    64,    65,    66,    67,    68,    69,   162,    18,    19,
      60,    61,    64,    65,    66,    67,    68,    69,    70,   161,
     162,   163,   164,     4,     5,   216,   217,     4,     5,   218,
     219,   189,   205,   205,   189,   192,   233,   173,   249,   255,
     166,    55,   166,     4,     7,   166,   189,   192,   267,    55,
     170,   269,   274,   166,   166,   169,   169,   169,   166,   166,
     169,   200,   200,   169,   192,   189,   192,     9,   169,   169,
     189,   169,   197,   182,    10,   169,   185,   169,   197,    10,
     197,   185,   185,     5,   188,   188,   188,   167,   192,   189,
     169,   169,    41,   197,   197,   197,   192,   189,   210,   167,
     189,   192,   207,   208,   167,    69,   192,    16,    42,   247,
     205,   205,   192,   192,   192,    90,   189,   277,   277,     4,
       5,   195,   196,   195,   196,   197,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   277,   192,   192,
     192,   192,   192,   192,   192,   167,   192,   189,   189,   189,
     189,   189,   192,   192,   192,   167,   192,   192,   189,   192,
     189,   192,   189,   189,   167,   189,   167,   189,   167,   189,
     167,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   277,   189,   167,   167,   189,   188,   189,   188,   189,
     167,   167,   189,   189,   189,   189,   189,   189,   189,   179,
     180,   194,   193,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   166,   166,   169,   166,   166,   169,
     167,   167,    41,   232,    39,    42,   240,    44,   173,   192,
     166,   189,   192,    48,   268,   168,   169,   166,     4,     7,
     166,     8,   275,   205,   205,     4,     5,   192,   192,   205,
     205,   265,     8,   199,   169,    79,    80,    90,   189,   192,
     192,   269,   197,   189,   197,   185,   192,   192,   166,   169,
     169,   169,   167,   167,   189,   192,   189,   192,   175,   169,
     185,   185,     4,     5,   214,   169,   224,   167,   166,   167,
     167,   169,   169,   169,   167,   167,   169,   169,   167,   166,
     166,   167,   167,   169,   169,   185,   169,   167,   167,   167,
     167,   167,   167,   169,   167,   167,   169,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   169,   167,   167,   169,
     169,   169,   167,   169,   169,   167,   169,   167,   167,   167,
     167,   167,   169,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   169,   169,   167,   167,   167,   167,   167,
     167,   169,   169,   167,   169,   169,   167,   169,   169,   201,
     278,   201,   279,   192,   192,   205,   205,   217,   205,   205,
     219,    41,   234,   250,    47,   169,   192,   167,   169,   167,
     166,   189,   189,   192,   192,   270,   271,   192,     4,     5,
     261,   263,   167,   167,   166,   166,   169,   169,   167,   167,
     192,    78,    78,   169,   169,   169,   197,   169,   169,   205,
     192,   192,   192,   176,   192,   197,   197,   211,   208,   192,
     243,   192,   192,   192,   192,   189,    90,   189,   167,   167,
     192,   192,   197,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   189,   192,   189,   189,   189,   196,   189,   196,
     189,   189,   169,   169,   167,   167,   167,   167,    37,    38,
     236,   173,   192,   169,    55,   189,   189,   268,   169,   261,
     261,   167,   166,   166,   169,   205,   205,   192,   192,   169,
     277,   277,   189,   189,   189,   192,   192,   167,   167,   167,
     167,   169,   185,   166,    10,   173,   167,   167,   167,   167,
     167,   167,   167,   169,   167,   167,   167,   185,   167,   167,
     167,   167,   167,   167,   169,   167,   167,   167,   169,   167,
     167,   169,   167,   169,   167,   167,   169,   167,   167,   169,
     167,   167,   201,   201,   233,    41,    36,   251,   167,   192,
     166,   167,   169,   192,   272,   205,   205,   262,   167,   167,
     189,   169,   169,    69,    69,    69,   192,   197,     4,     5,
     220,   221,   192,    14,    42,   244,   189,   192,   192,   189,
     192,   192,   189,   189,   235,   237,    46,   257,    57,    58,
     167,   192,    55,   189,   167,   261,   167,   167,   261,   189,
     189,   189,   189,   189,   167,   166,   166,   167,   169,    11,
     228,   167,   169,   167,   167,   167,   167,   167,   167,   173,
     173,   192,    45,   256,   166,   169,   166,   167,   273,    69,
     167,   167,   212,   221,   192,   225,   192,    44,   260,   173,
     252,   189,   192,   192,   275,   189,   173,   173,   167,   258,
      42,    47,   253,   167,   169,   167,   169,   261,    23,    42,
     213,   226,   173,   189,   192,    12,    42,   227,   259,   167,
     167,     4,   229,   257
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   171,   172,   173,   174,   175,   173,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   177,   176,   178,   176,   176,
     176,   176,   176,   176,   176,   179,   176,   180,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   181,
     176,   182,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   183,   183,
     183,   183,   183,   184,   184,   184,   184,   184,   184,   185,
     185,   186,   186,   186,   186,   186,   187,   187,   188,   188,
     189,   189,   189,   189,   189,   189,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   191,
     191,   193,   192,   194,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   195,   196,   197,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   199,   200,   200,   201,   201,   202,   202,   202,
     202,   203,   204,   206,   205,   207,   207,   207,   208,   208,
     210,   211,   212,   209,   213,   213,   214,   214,   215,   215,
     215,   215,   216,   216,   217,   217,   217,   217,   218,   218,
     219,   219,   219,   219,   220,   220,   220,   221,   221,   221,
     221,   223,   224,   225,   226,   222,   227,   227,   228,   228,
     229,   229,   231,   230,   232,   232,   233,   233,   234,   235,
     234,   236,   237,   236,   239,   238,   240,   240,   242,   243,
     241,   244,   244,   246,   245,   247,   247,   249,   250,   251,
     252,   248,   253,   253,   255,   254,   256,   256,   257,   258,
     259,   257,   260,   260,   261,   262,   261,   263,   263,   263,
     263,   264,   264,   265,   265,   265,   265,   266,   266,   266,
     266,   267,   267,   267,   267,   267,   268,   268,   268,   270,
     269,   271,   269,   272,   269,   273,   269,   274,   269,   275,
     275,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   277,   277,   278,   278,   279,
     279
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
       4,     4,     4,     4,     1,     3,     1,     3,     4,     6,
       6,     4,     6,     4,     6,    10,     4,     4,     4,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     3,     6,
       6,     4,     4,     4,     4,     6,     6,     8,     6,     8,
       4,     4,     4,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       1,     2,     2,     1,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     0,     2,     0,     1,     3,     1,     1,
       0,     0,     0,    11,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     3,     1,     1,     4,     4,     1,     3,
       1,     1,     4,     4,     0,     1,     3,     1,     1,     3,
       3,     0,     0,     0,     0,    14,     1,     1,     0,     2,
       0,     1,     0,     7,     1,     2,     1,     1,     0,     0,
       5,     0,     0,     4,     0,     4,     1,     1,     0,     0,
       8,     1,     1,     0,     4,     1,     4,     0,     0,     0,
       0,    11,     1,     1,     0,     5,     0,     2,     0,     0,
       0,     7,     0,     1,     1,     0,     4,     1,     4,     1,
       4,     1,     3,     1,     4,     1,     4,     1,     1,     3,
       3,     0,     2,     4,     1,     3,     0,     2,     6,     0,
       4,     0,     4,     0,     6,     0,     9,     0,     3,     0,
       1,     0,     2,     2,     4,     1,     4,     6,     6,     7,
      10,    12,     7,    10,    12,     2,     1,     1,     3,     1,
       3
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

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 12:

    {report_missing(ERROR,"can not import a library in a loop or an if-statement");}

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

    {create_function(fCHOMP);}

    break;

  case 153:

    {create_function(fSYSTEM);}

    break;

  case 154:

    {create_function(fDATE);}

    break;

  case 155:

    {create_function(fDATE);}

    break;

  case 156:

    {create_function(fTIME);}

    break;

  case 157:

    {create_function(fTIME);}

    break;

  case 158:

    {create_function(fPEEK2);}

    break;

  case 159:

    {create_function(fPEEK3);}

    break;

  case 160:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 161:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 162:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 163:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 164:

    {create_function(fGETBIT);}

    break;

  case 165:

    {create_function(fGETCHAR);}

    break;

  case 166:

    {create_function(fHEX);}

    break;

  case 167:

    {create_function(fBIN);}

    break;

  case 168:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 169:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 170:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 171:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 172:

    {poplabel();create_boole('|');}

    break;

  case 173:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 174:

    {poplabel();create_boole('&');}

    break;

  case 175:

    {create_boole('!');}

    break;

  case 176:

    {create_dblrelop('=');}

    break;

  case 177:

    {create_dblrelop('!');}

    break;

  case 178:

    {create_dblrelop('<');}

    break;

  case 179:

    {create_dblrelop('{');}

    break;

  case 180:

    {create_dblrelop('>');}

    break;

  case 181:

    {create_dblrelop('}');}

    break;

  case 182:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 183:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 184:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 185:

    {add_command(cARDIM,"",NULL);}

    break;

  case 186:

    {add_command(cARDIM,"",NULL);}

    break;

  case 187:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 188:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 189:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 190:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 191:

    {create_dblbin('+');}

    break;

  case 192:

    {create_dblbin('-');}

    break;

  case 193:

    {create_dblbin('*');}

    break;

  case 194:

    {create_dblbin('/');}

    break;

  case 195:

    {create_dblbin('^');}

    break;

  case 196:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 197:

    {create_strrelop('=');}

    break;

  case 198:

    {create_strrelop('!');}

    break;

  case 199:

    {create_strrelop('<');}

    break;

  case 200:

    {create_strrelop('{');}

    break;

  case 201:

    {create_strrelop('>');}

    break;

  case 202:

    {create_strrelop('}');}

    break;

  case 205:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 206:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 208:

    {create_function(fSIN);}

    break;

  case 209:

    {create_function(fASIN);}

    break;

  case 210:

    {create_function(fCOS);}

    break;

  case 211:

    {create_function(fACOS);}

    break;

  case 212:

    {create_function(fTAN);}

    break;

  case 213:

    {create_function(fATAN);}

    break;

  case 214:

    {create_function(fATAN2);}

    break;

  case 215:

    {create_function(fEXP);}

    break;

  case 216:

    {create_function(fLOG);}

    break;

  case 217:

    {create_function(fLOG2);}

    break;

  case 218:

    {create_function(fSQRT);}

    break;

  case 219:

    {create_function(fSQR);}

    break;

  case 220:

    {create_function(fINT);}

    break;

  case 221:

    {create_function(fCEIL);}

    break;

  case 222:

    {create_function(fFLOOR);}

    break;

  case 223:

    {create_function(fFRAC);}

    break;

  case 224:

    {create_function(fABS);}

    break;

  case 225:

    {create_function(fSIG);}

    break;

  case 226:

    {create_function(fMOD);}

    break;

  case 227:

    {create_function(fRAN);}

    break;

  case 228:

    {create_function(fRAN2);}

    break;

  case 229:

    {create_function(fMIN);}

    break;

  case 230:

    {create_function(fMAX);}

    break;

  case 231:

    {create_function(fLEN);}

    break;

  case 232:

    {create_function(fVAL);}

    break;

  case 233:

    {create_function(fASC);}

    break;

  case 234:

    {create_function(fDEC);}

    break;

  case 235:

    {create_function(fDEC2);}

    break;

  case 236:

    {if (check_compat) error(WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 237:

    {create_function(fINSTR2);}

    break;

  case 238:

    {create_function(fRINSTR);}

    break;

  case 239:

    {create_function(fRINSTR2);}

    break;

  case 240:

    {create_function(fSYSTEM2);}

    break;

  case 241:

    {create_function(fPEEK4);}

    break;

  case 242:

    {create_function(fPEEK);}

    break;

  case 243:

    {create_function(fMOUSEX);}

    break;

  case 244:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 245:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 246:

    {create_function(fMOUSEY);}

    break;

  case 247:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 248:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 249:

    {create_function(fMOUSEB);}

    break;

  case 250:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 251:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 252:

    {create_function(fMOUSEMOD);}

    break;

  case 253:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 255:

    {create_function(fAND);}

    break;

  case 256:

    {create_function(fOR);}

    break;

  case 257:

    {create_function(fEOR);}

    break;

  case 258:

    {create_function(fTELL);}

    break;

  case 259:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 260:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 261:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 262:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 263:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 264:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 265:

    {create_myopen(0);}

    break;

  case 266:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 267:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 268:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 269:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 270:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 271:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 272:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 273:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 274:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 275:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 276:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 277:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 278:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 279:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 280:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 281:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 282:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 283:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 290:

    {missing_endsub++;missing_endsub_line=mylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {error(ERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 291:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 292:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 293:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 294:

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);error(ERROR,string);} YYABORT;}

    break;

  case 295:

    {missing_endsub--;}

    break;

  case 296:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 297:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 298:

    {exported=FALSE;}

    break;

  case 299:

    {exported=TRUE;}

    break;

  case 300:

    {exported=FALSE;}

    break;

  case 301:

    {exported=TRUE;}

    break;

  case 304:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 305:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 306:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 307:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 310:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 311:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 312:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 313:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 317:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 318:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 319:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 320:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 321:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=mylineno;}

    break;

  case 322:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 323:

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

  case 324:

    {
             swap();popgoto();poplabel();}

    break;

  case 325:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 326:

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);error(ERROR,string);} YYABORT;}

    break;

  case 327:

    {missing_next--;}

    break;

  case 328:

    {create_pushdbl(1);}

    break;

  case 330:

    {pop(stSTRING);}

    break;

  case 331:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {error(ERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 332:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 333:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 334:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 335:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 339:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 340:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 342:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep); add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 344:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=mylineno;pushgoto();}

    break;

  case 346:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);error(ERROR,string);} YYABORT;}

    break;

  case 347:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 348:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=mylineno;pushgoto();}

    break;

  case 349:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 351:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);error(ERROR,string);} YYABORT;}

    break;

  case 352:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 353:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=mylineno;pushgoto();}

    break;

  case 355:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);error(ERROR,string);} YYABORT;}

    break;

  case 356:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 357:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 358:

    {missing_endif++;missing_endif_line=mylineno;}

    break;

  case 359:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 360:

    {poplabel();}

    break;

  case 362:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);error(ERROR,string);} YYABORT;}

    break;

  case 363:

    {missing_endif--;}

    break;

  case 364:

    {fi_pending++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 365:

    {poplabel();}

    break;

  case 369:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 370:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 375:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 377:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 378:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 379:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 380:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 383:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 384:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 385:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 386:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 387:

    {create_strdata((yyvsp[0].string));}

    break;

  case 388:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 389:

    {create_strdata((yyvsp[0].string));}

    break;

  case 390:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 394:

    {create_print('s');}

    break;

  case 395:

    {create_print('s');}

    break;

  case 396:

    {create_print('d');}

    break;

  case 397:

    {create_print('u');}

    break;

  case 398:

    {create_print('U');}

    break;

  case 399:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 400:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 401:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 402:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 403:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 404:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 405:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 406:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 407:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 408:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 409:

    {create_pushstr("?");create_print('s');}

    break;

  case 410:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 411:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 412:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 413:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 414:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 415:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 416:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 417:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 418:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 419:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 420:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 421:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 422:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 423:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 424:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 427:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 428:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 429:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 430:

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
