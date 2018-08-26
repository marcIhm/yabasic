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
    tSYSTEM = 403,
    tSYSTEM2 = 404,
    tPEEK = 405,
    tPEEK2 = 406,
    tPOKE = 407,
    tDATE = 408,
    tTIME = 409,
    tTOKEN = 410,
    tTOKENALT = 411,
    tSPLIT = 412,
    tSPLITALT = 413,
    tGLOB = 414,
    UMINUS = 415
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
#define YYFINAL  250
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  429
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1010

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   169,     2,     2,     2,     2,
     165,   166,   162,   161,   168,   160,     2,   163,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   167,
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
     155,   156,   157,   158,   159,   164
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
     439,   440,   441,   442,   443,   444,   445,   446,   447,   450,
     451,   452,   455,   456,   459,   460,   463,   464,   465,   466,
     469,   472,   475,   475,   478,   479,   480,   483,   484,   487,
     488,   491,   487,   496,   497,   500,   501,   504,   505,   506,
     507,   510,   511,   514,   515,   516,   517,   520,   521,   524,
     525,   526,   527,   530,   531,   532,   535,   536,   537,   538,
     541,   542,   546,   560,   541,   565,   566,   569,   570,   573,
     574,   579,   579,   583,   584,   587,   588,   592,   594,   593,
     598,   599,   599,   603,   603,   609,   610,   614,   615,   614,
     621,   622,   626,   626,   631,   632,   636,   637,   637,   639,
     636,   643,   644,   647,   647,   651,   652,   655,   657,   659,
     656,   663,   664,   667,   668,   668,   671,   672,   674,   675,
     679,   680,   683,   684,   686,   687,   691,   692,   693,   694,
     697,   698,   699,   700,   701,   704,   705,   706,   709,   709,
     710,   710,   711,   711,   712,   712,   713,   713,   716,   717,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   736,   737,   739,   740,   743,   744
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
  "tRTRIM", "tINSTR", "tRINSTR", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2",
  "tPOKE", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT",
  "tGLOB", "'-'", "'+'", "'*'", "'/'", "UMINUS", "'('", "')'", "';'",
  "','", "'#'", "$accept", "program", "statement_list", "$@1", "$@2",
  "statement", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
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
      45,    43,    42,    47,   415,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -718

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-718)))

#define YYTABLE_NINF -357

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3395,   -44,   -39,  -718,  -718,  -718,  -718,  -718,   101,   101,
     101,  2782,  -718,  -718,  -718,  2195,  -125,  -102,  2195,    45,
      99,  -718,  -718,  -718,  3100,    17,  -718,  3100,    23,  -718,
    3100,  3100,  3100,    82,    -2,   101,  1654,  1115,  1972,    55,
    3100,  2623,  3100,   185,    60,  3100,  -718,    29,  2195,  2195,
    2195,    61,    25,    51,    54,    62,   201,  1972,   177,   200,
    -718,    -5,  -718,  -718,  -718,  -718,   301,   353,  -718,   414,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  3100,  -718,  2195,
    -718,   434,   343,  3257,  -718,  -718,  -718,  -718,  -718,  -718,
     356,   360,  -718,  -718,   380,   383,   154,   412,   415,  3100,
     425,   430,   443,   445,   449,   455,   461,   464,   466,   467,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   488,
     491,   494,   495,   496,   498,   499,   500,   501,   502,   504,
     505,   509,   514,   515,   516,   517,   518,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   530,   531,   536,   539,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,  3100,  3100,   363,  -718,    77,  -718,  -718,  -718,
    -718,   198,   302,  2195,   306,  -718,  -718,   306,  -718,  -718,
    3100,  3257,   341,   553,   519,   555,    14,  3100,    -9,   363,
    3300,   557,   558,   351,  3300,   363,  1300,   363,  1533,   559,
     560,   448,  -718,  -718,    81,    81,  -718,  -718,   486,  -718,
    3100,  2195,  3100,     1,  3300,   534,  -718,  -718,  -718,  -718,
     570,  2195,  1544,  -718,  3100,  -718,    -3,   571,  -718,  -718,
    3100,  2941,  -718,  -718,  3300,  -718,  -718,   301,   353,   306,
      21,    21,  -718,   512,   512,   512,  2131,  2195,   274,   581,
    -718,  -718,   616,  3100,  3100,  3100,  3100,  2195,  -718,  3300,
     398,  3100,   306,   427,   593,  3100,     6,  -718,  -718,  -718,
    -718,  3100,  3100,   676,  3100,  1813,  1972,   349,   349,  3100,
    3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,
    3100,  1972,  3100,  3100,  3100,  3100,  3100,  3100,  3100,  2295,
    2195,  2195,  2195,  2195,  2195,  3100,  3100,  3100,  2459,  3100,
    2195,  3100,  2195,  3100,  2195,  2195,   315,   895,  1178,  1278,
    2195,  2195,  2195,  2195,  2195,  2195,  2195,  1972,  2195,   584,
     585,  2195,   512,  2195,   512,  2195,   684,   329,  1580,  2195,
    2195,  2195,  2195,  2195,  2195,  2195,  -718,  -718,  -718,  -718,
    3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,  3100,
    3100,   592,   596,   594,  -718,   598,   599,   597,  -718,   -27,
     603,   604,   363,  3300,   719,    83,   734,  3533,  3100,   614,
    2195,  -718,  -718,  3100,   363,   489,   236,   615,    19,  -718,
     773,  -718,  -718,   451,  3100,  3100,  -718,  -718,    82,  -718,
    -718,    48,  1558,   306,  3300,   396,  1376,  3100,   306,  3100,
    -718,    -9,  -718,  -718,  3100,  2195,  -718,  3100,    -3,  3100,
    3100,   618,   624,   625,   627,  -718,  3971,   -26,  3100,  3100,
    -718,   628,    -3,    -3,  3300,   306,   482,  -718,   363,  3300,
     629,  -718,  -718,  -718,  3982,   619,  -718,  -718,   634,   638,
    1828,  1987,  2146,   640,   282,   639,   642,   645,   646,   647,
     652,   644,   653,    -3,  2310,  4004,  4029,  4040,  4086,  4108,
     537,  4144,   667,  4155,  4166,   654,  4190,  4212,  4223,  4270,
    4294,  4327,  2474,  -718,  4338,    40,    46,    67,    75,   117,
    2638,  2797,   841,  -718,  4349,  4374,   156,  4398,   169,  4409,
     170,   225,  -718,   313,  -718,   333,  -718,   344,  -718,   346,
     348,   350,   354,    91,   103,   372,   375,   352,   656,   206,
    -718,  -718,   104,    94,   147,   116,   184,  -718,  -718,   306,
     306,   306,   306,   306,   306,  -718,   101,   101,  3100,  3100,
     721,     9,   164,   -11,    87,    93,  -718,    37,    37,   684,
     684,  -718,  -718,   198,  -718,  -718,   302,  -718,  -718,  -718,
     782,  -718,  -718,  -718,  -718,   778,  2956,  3100,   207,  4453,
    2359,  -718,  -718,  3100,  3100,  -718,  -718,  3100,  -718,   492,
     660,   665,   669,   675,  3667,  3714,   666,   677,  -718,  -718,
    -718,  3100,   763,   766,  -718,   208,  3739,  3300,  -718,  -718,
     276,  -718,  3100,  3772,  3783,  -718,  3100,  3100,  3100,  -718,
    -718,   363,  3300,   363,  3300,  3257,  3100,  3100,  3100,  -718,
    -718,  -718,  3100,  3100,  -718,  3100,  -718,  -718,  3100,  3100,
    3100,  -718,  -718,  2195,  1425,  -718,   681,   685,  -718,  -718,
    3100,  3100,  3100,  3100,  -718,  -718,  -718,  -718,  -718,  -718,
    3100,  -718,  -718,  3100,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  3100,  -718,  -718,  3100,  3100,  3100,  -718,
    3100,  3100,  -718,  2195,  -718,  -718,  -718,  -718,  -718,  3100,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    2195,  2195,  -718,  -718,  -718,  -718,  -718,  2195,   845,  -718,
    2195,   845,  -718,  2195,  2195,  -718,   686,  -718,   687,   676,
     707,   690,   691,  -718,   693,   694,  -718,  -718,   497,  3257,
    -718,  3100,  3794,   797,  2195,  -718,  2195,   306,   363,   489,
    3819,   492,   492,  4478,   688,   696,  -718,   695,  -718,  -718,
    -718,  -718,  3100,  3100,  -718,  -718,  3844,  1972,  1972,  2195,
    2195,  2195,  -718,  3100,  3100,   698,  4513,  4524,  1230,  -718,
    3300,    -3,  -718,   697,  -718,    63,  3257,  4535,  4557,  4582,
    4593,   385,   700,   221,  -718,  -718,  4639,  4661,   705,    50,
    4697,  4708,  4719,  4743,  4765,  1285,  4776,  4823,   296,  4847,
     304,   316,   386,   153,   399,   212,   400,   401,   101,   101,
    -718,  -718,  -718,  -718,  3100,   832,   839,   835,  4880,  3100,
     712,   402,   317,  -718,  3100,  -718,  -718,  -718,  -718,  -718,
    -718,   713,   714,  3300,  3300,  2195,  -718,  -718,   306,   306,
     293,  3855,  3300,  -718,   809,   816,   818,  3100,  3100,   595,
    3100,    47,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  2195,
    -718,  -718,  -718,  3100,  -718,  -718,  -718,  -718,  -718,  -718,
    3100,  -718,  -718,  -718,  2195,  -718,  -718,  3100,  -718,  3100,
    -718,  -718,  2195,  -718,  -718,  2195,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,   842,   561,  4891,  3100,   834,  2195,  4902,
     492,   724,   726,   492,  -718,  -718,   306,  2195,  2195,  2195,
    2195,  2195,  4927,  -718,   728,   729,   224,  -718,    33,  -718,
    -718,  -718,   409,  3899,  4951,   410,  4962,  5006,   420,   422,
    3257,  3671,  3100,   850,  -718,   732,  -718,  3924,   733,   426,
    -718,  -718,  -718,  -718,  -718,   306,   306,   306,   306,   306,
     843,   738,   748,  -718,   595,  3100,  -718,  -718,  3100,  -718,
    -718,  -718,  -718,  -718,  -718,   835,   879,   462,  3257,  -718,
    2195,  3100,  3100,  -718,   773,  2195,  -718,  -718,  3257,  -718,
    3300,  3257,  5031,  -718,  -718,   835,   119,   332,  5066,  3960,
     492,   306,    22,   835,  -718,  3257,  -718,  -718,  -718,  -718,
    2195,  -718,  3100,  -718,  -718,  -718,  -718,    12,   835,   428,
    5077,  -718,  -718,   912,   842,  -718,  -718,  -718,  -718,  -718
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     108,     0,     0,   106,   320,   347,   352,    12,     0,     0,
       0,     0,    25,    27,   298,     0,     0,     0,     0,   299,
      19,    21,   331,   343,     0,   410,    49,    61,     0,   103,
     104,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     4,
       3,     0,     8,    40,    42,    10,    23,    24,    22,     0,
      14,    15,    18,    17,    16,    29,    30,     0,   282,     0,
     282,     0,     0,     7,   275,   274,    31,    32,    39,   272,
     189,   130,   273,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   243,   246,   249,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   155,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,   202,   183,   188,
     132,     0,     0,     0,    13,   282,   282,    43,   300,    20,
       0,     7,   363,     0,   414,     0,     0,   390,   406,    63,
      62,     0,     0,    64,   105,    54,     0,    56,     0,   382,
     384,    57,   380,   386,     0,     0,   387,   269,    58,    60,
       0,    90,     0,     0,   425,     0,    87,    92,    80,    41,
       0,     0,     0,    68,     0,    51,    73,     0,    89,    88,
       0,     0,   111,   112,    93,     9,    11,     0,     0,   107,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,     0,     0,     0,   289,   168,
       0,   284,   113,     0,     0,     0,     4,   282,   282,    33,
      34,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   195,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    37,   172,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   303,   304,    26,   301,   309,   310,    28,   307,     0,
       0,     0,   336,   335,     0,     4,     0,   108,     0,     0,
       0,   411,   412,     0,   393,   395,    46,     0,     0,    50,
     408,   282,   282,     0,     0,     0,   282,   282,     0,   271,
     270,     0,     0,    91,   424,     0,     0,     0,    67,     0,
      72,   406,   120,   119,     0,     0,    69,     0,    75,     0,
       0,   128,     0,     0,     0,    96,     0,     0,     0,     0,
       5,     0,     0,     0,   169,   118,     0,   280,   287,   288,
     283,   285,   281,   321,     0,     0,   354,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,   247,     0,   250,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   156,     0,     0,     0,     0,     0,   135,   203,   197,
     199,   201,   198,   200,   196,   134,     0,     0,     0,     0,
     176,   178,   180,   177,   179,   175,   194,   191,   190,   192,
     193,   282,   282,     0,   282,   282,     0,    44,    45,   333,
     337,   346,   345,   344,   357,     4,     0,     0,     0,     0,
       0,   391,    47,    48,     0,   398,   400,     0,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,   388,
     389,     0,     0,     0,   123,   122,   126,   206,    52,    70,
      83,    74,     0,     0,     0,   282,     0,     0,     0,    97,
      98,    99,   100,   101,   102,     7,     0,     0,     0,   295,
     296,   290,     0,     0,   348,     0,   262,   167,     0,     0,
       0,   263,   264,     0,     0,   257,     0,     0,   184,   185,
       0,     0,     0,     0,   207,   208,   209,   210,   211,   212,
       0,   214,   215,     0,   217,   218,   181,   223,   224,   219,
     220,   221,   222,     0,   226,   231,     0,     0,     0,   230,
       0,     0,   140,     0,   145,   146,   232,   165,   233,     0,
     166,   147,   148,   242,   245,   248,   251,   151,   149,   150,
       0,     0,   152,   239,   241,   240,   157,     0,     0,   160,
       0,     0,   162,     0,     0,   426,    36,   428,    38,   173,
     171,     0,     0,   302,     0,     0,   308,   334,   340,     7,
     364,     0,     0,   415,     0,   413,     0,   396,   394,   395,
       0,     0,     0,     0,   376,   378,   407,   373,   276,   278,
     282,   282,     0,     0,   383,   385,    65,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,     6,
      81,     0,    86,     0,   286,     0,     7,     0,     0,     0,
       0,     0,     0,     0,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,   306,   311,   312,     0,     0,     0,   358,     0,     0,
       0,     0,     0,   392,     0,   399,   401,   402,   282,   282,
     374,     0,     0,    53,    55,     0,   124,   125,   121,   127,
      84,    77,    78,   129,     0,     0,     0,     0,     0,   313,
       0,     4,   355,   254,   255,   256,   265,   266,   267,     0,
     186,   187,   163,     0,   213,   216,   225,   136,   137,   139,
       0,   228,   229,   141,     0,   234,   235,     0,   237,     0,
     158,   259,     0,   159,   261,     0,   161,   182,   427,   429,
     338,   341,   332,   367,   417,     0,     0,   416,     0,     0,
       0,     0,     0,     0,   277,   279,    66,     0,     0,     0,
       0,     0,     0,    82,   316,   317,     0,   314,   327,   351,
     350,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   108,     0,   365,   421,     0,   418,     0,     0,     0,
     404,   403,   377,   379,   375,    85,    76,   116,   117,   115,
       0,     0,     0,   291,     0,     0,   322,   268,     0,   138,
     142,   236,   238,   258,   260,   339,     4,   371,     7,   359,
       0,     0,     0,   397,   408,     0,   318,   319,     7,   315,
     328,     7,     0,   372,   368,   366,     0,     0,     0,     0,
       0,   114,     4,   323,   164,     7,   361,   362,   360,   422,
       0,   419,     0,   405,   294,   293,   292,     0,   369,     0,
       0,   326,   325,   329,   367,   423,   420,   330,   324,   370
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -718,  -718,   -72,  -718,  -718,   303,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,   870,  -188,  -718,  -718,  -154,   767,  -718,
     872,     5,  -718,  -718,   648,  -275,   -33,  -718,   532,   -30,
       3,  -718,     0,     2,   -63,  -718,  -718,   307,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,   378,  -718,   369,  -718,
     -16,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,   128,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,   -70,  -718,  -718,  -718,
    -717,  -718,  -718,  -718,   538,  -718,  -718,   209,   533,  -718,
    -718,  -718,  -718,  -718,   -29,  -718,   -18,  -718,  -718
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   252,   615,    60,   171,   172,   536,   537,
     188,   411,    61,    62,   414,    63,    64,   422,   164,   165,
      65,   222,   539,   538,   459,   460,   223,   167,   206,   168,
      86,   193,   169,   170,   260,   261,   440,   441,    68,   436,
     763,   968,   996,   621,    69,   363,   364,   367,   368,   906,
     907,    70,    81,   623,   971,   997,  1003,   946,  1008,    71,
     180,   560,   374,   718,   920,   806,   921,    72,   181,   563,
      73,    82,   766,   911,    74,    83,   447,    75,   376,   719,
     883,   976,   988,    76,   377,   959,   923,   985,  1004,   974,
     736,   893,   737,   201,   202,   208,   386,   571,   389,   731,
     732,   890,   964,   390,   579,   187,   215,   706,   708
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    89,    67,   462,   207,    92,   203,   412,   226,   227,
     405,   266,    87,    88,   815,   816,   166,   263,   381,   219,
     220,   382,   445,   575,  1001,    77,   576,   191,   192,   182,
      79,   412,   190,     1,     2,   194,   196,   198,   209,   249,
     175,   214,   214,   214,   945,   994,   387,   237,   446,   238,
     234,    89,   419,   420,  1002,    92,   589,   354,   355,   356,
     412,   909,   214,   176,   995,   339,   340,   341,   342,   343,
     344,   178,   183,   840,   184,   185,   353,   354,   355,   356,
     253,   254,   259,    66,    89,    67,   199,   200,    92,   910,
     423,   424,   255,   348,   349,   346,   347,   350,   351,   352,
     353,   354,   355,   356,   273,    84,   179,   356,    85,   375,
     348,   349,   370,   371,   350,   351,   352,   353,   354,   355,
     356,    78,   561,   348,   349,   562,    80,   350,   351,   352,
     353,   354,   355,   356,   345,   345,   221,   348,   349,   527,
     610,   350,   351,   352,   353,   354,   355,   356,   233,   357,
     358,   359,   360,    52,    53,    54,   355,   356,   204,   205,
     388,   986,   345,   356,   242,   413,   987,   336,   338,   357,
     358,   359,   360,   931,   399,   400,   934,   250,   523,   383,
     525,    66,   345,    67,   577,   373,   186,   269,   270,   413,
     243,   410,   385,   357,   358,   359,   360,   416,   418,   359,
     360,   345,   361,   362,   448,   449,   665,   345,   204,   205,
     357,   358,   359,   360,   666,   402,   244,   404,   413,   245,
     431,   432,   433,   357,   358,   359,   360,   246,   345,   351,
     602,   353,   354,   355,   356,   667,   345,   357,   358,   359,
     360,   228,   251,   668,   617,   618,   463,   357,   358,   359,
     360,   426,   345,   357,   358,   359,   360,   455,   456,   690,
     699,   434,   700,   993,   345,   345,   439,   229,   230,   231,
     444,   691,   698,   475,   232,   642,   450,   451,   345,   452,
     214,   214,   702,   669,   703,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   214,   476,   477,   478,
     479,   480,   481,   482,   484,   565,   365,   366,   345,   518,
     490,   491,   492,   494,   495,   701,   497,   345,   499,   871,
      91,   872,   676,    93,   357,   358,   359,   360,   580,   581,
     345,   345,   214,   586,   587,   678,   681,   679,   339,   340,
     341,   342,   343,   344,    95,   345,   339,   340,   341,   342,
     343,   344,   704,   457,   458,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   247,   345,   345,   345,
     256,   207,   696,   723,   697,   724,   749,    66,   874,    67,
     875,   599,   345,   566,   601,  -356,   345,   848,   569,   849,
     943,   682,   944,   339,   340,   341,   342,   343,   344,   584,
     585,   348,   349,   572,   573,   350,   351,   352,   353,   354,
     355,   356,   596,   105,   597,   106,   339,   340,   341,   342,
     343,   344,   257,   793,   603,   604,   795,   339,   340,   341,
     342,   343,   344,   612,   614,   345,   258,   345,   264,   127,
     128,   129,   428,   345,   751,   133,   134,   135,   632,   137,
     633,   139,   140,   141,   345,   582,   583,   345,   146,   147,
     148,   897,   863,   151,   864,   345,   154,   345,   155,   156,
     866,   158,   867,   160,   345,   592,   593,   345,   345,   683,
     173,   502,   868,   527,   869,   888,   619,   620,   711,   712,
     345,   714,   715,   345,   345,   527,   734,   735,   989,   684,
     990,   357,   358,   359,   360,   345,   973,   345,   265,   345,
     685,   345,   686,   345,   687,   345,   688,   421,   694,   393,
     689,    78,   348,   349,   345,    80,   350,   351,   352,   353,
     354,   355,   356,   345,   804,   805,   345,   570,   692,   705,
     707,   693,   755,   709,   710,   267,   345,   345,   268,   348,
     349,   846,   870,   350,   351,   352,   353,   354,   355,   356,
     345,   345,   345,   345,   437,   873,   876,   877,   887,   752,
     345,   345,   722,   838,   379,   947,   950,   271,   729,   730,
     272,   345,   733,   345,   761,   762,   953,   345,   954,   345,
     274,   853,   963,   442,  1005,   275,   746,   348,   349,   904,
     905,   350,   351,   352,   353,   354,   355,   356,   276,   778,
     277,   756,   757,   758,   278,    66,   398,    67,   924,   925,
     279,   760,   357,   358,   359,   360,   280,   439,   765,   281,
     767,   282,   283,   768,   769,   770,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   776,   777,   807,   779,   357,
     358,   359,   360,   293,   401,   780,   294,   430,   781,   295,
     296,   297,   443,   298,   299,   300,   301,   302,   782,   303,
     304,   783,   784,   785,   305,   786,   787,   821,   822,   306,
     307,   308,   309,   310,   789,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   841,   320,   321,   357,   358,   359,
     360,   322,   406,   649,   323,   650,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   378,    66,
     380,    67,   391,   392,   396,   397,   808,   348,   349,   826,
     827,   350,   351,   352,   353,   354,   355,   356,   407,   415,
     350,   351,   352,   353,   354,   355,   356,   823,   824,   429,
     520,   521,   214,   214,   356,   891,   892,   551,   831,   832,
     559,   552,   553,   554,   555,   556,    66,   348,    67,   557,
     558,   350,   351,   352,   353,   354,   355,   356,   564,   567,
     574,   578,   174,   605,   625,   177,   351,   352,   353,   354,
     355,   356,   606,   607,   189,   608,   616,   622,   195,   197,
     626,   878,   879,   213,   627,   903,   631,   634,   635,   373,
     636,   637,   640,   638,   885,   239,   240,   241,   639,   889,
     656,   641,   695,   717,   248,   720,   738,   357,   358,   359,
     360,   739,   744,   652,   740,   653,   357,   358,   359,   360,
     741,   747,   902,   745,   748,   908,   262,   774,   955,   956,
     458,   775,   810,   818,   798,   799,   800,   801,   913,   802,
     803,   819,   839,   820,   833,   914,   847,   357,   358,   359,
     360,   852,   916,   881,   917,   882,    -4,   886,   899,   894,
     895,   357,   358,   359,   360,   900,   975,   901,   922,   928,
     932,   927,   933,   941,   942,   958,   982,   960,   962,   983,
      91,   348,   349,    93,   966,   350,   351,   352,   353,   354,
     355,   356,   965,   998,   967,  -342,  1007,   235,   759,   236,
      66,    66,    67,    67,    95,   716,   461,   957,   969,   764,
     337,   713,   880,   590,  1009,   980,   588,     0,   813,     0,
     369,     0,     0,     0,   598,     0,     0,   372,     0,     0,
     970,     0,     0,   972,   384,     0,     0,     0,    66,     0,
      67,     0,     0,     0,     0,     0,   978,   979,    66,     0,
      67,    66,     0,    67,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,     0,    66,     0,    67,   408,     0,
       0,     0,     0,   105,     0,   106,     0,  1000,     0,     0,
       0,   357,   358,   359,   360,     0,     0,   672,     0,   673,
       0,     0,     0,     0,   427,     0,     0,     0,     0,   127,
     128,   129,     0,     0,   435,   133,   134,   135,   438,   137,
       0,   139,   140,   141,     0,     0,     0,     0,   146,   147,
     148,     0,   454,   151,     0,     0,   154,     0,   155,   156,
       0,   158,     0,   160,     0,     0,     0,     0,     0,     0,
     173,   504,     0,     0,     0,     0,     0,   485,   486,   487,
     488,   489,     0,     0,     0,     0,     0,   496,     0,   498,
       0,   500,   501,   503,   505,   507,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   519,     0,     0,   522,     0,
     524,     0,   526,     0,     0,     0,   529,   530,   531,   532,
     533,   534,   535,     0,     0,     0,     0,     0,    89,    90,
      91,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,   568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   595,     0,    97,    98,    99,   100,     0,
       0,     0,   600,    91,     0,     0,    93,     0,     0,   101,
       0,     0,   102,     0,     0,   611,   613,   216,     0,     0,
       0,     0,     0,     0,     0,   217,     0,    95,     0,   103,
     104,     0,     0,   105,     0,   106,     0,     0,   218,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,   105,     0,   106,     0,
     163,     0,     0,    91,   212,     0,    93,     0,     0,     0,
     348,   349,     0,     0,   350,   351,   352,   353,   354,   355,
     356,     0,   127,   128,   129,     0,     0,    95,   133,   134,
     135,     0,   137,     0,   139,   140,   141,     0,     0,     0,
       0,   146,   147,   148,     0,     0,   151,     0,     0,   154,
       0,   155,   156,     0,   158,     0,   160,   727,     0,     0,
     728,     0,     0,   173,   506,   348,   349,     0,     0,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     348,   349,     0,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,   105,     0,   106,     0,
       0,    91,     0,     0,    93,     0,     0,     0,     0,   438,
     357,   358,   359,   360,     0,     0,   836,     0,   837,     0,
     771,   773,   127,   128,   129,    95,     0,     0,   133,   134,
     135,     0,   137,     0,   139,   140,   141,     0,     0,     0,
       0,   146,   147,   148,     0,     0,   151,     0,     0,   154,
      91,   155,   156,    93,   158,     0,   160,     0,     0,     0,
     788,     0,     0,   173,   508,   357,   358,   359,   360,     0,
       0,   859,     0,   860,    95,     0,     0,   790,   791,     0,
     357,   358,   359,   360,   792,     0,   594,   794,   394,     0,
     796,   797,     0,     0,   105,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   811,     0,   812,     0,     0,     0,     0,     0,     0,
     127,   128,   129,     0,     0,     0,   133,   134,   135,     0,
     137,     0,   139,   140,   141,   772,   828,   829,   830,   146,
     147,   148,     0,   105,   151,   106,     0,   154,     0,   155,
     156,     0,   158,     0,   160,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,     0,     0,     0,   133,   134,   135,     0,   137,
       0,   139,   140,   141,     0,     0,     0,     0,   146,   147,
     148,   372,     0,   151,     0,     0,   154,     0,   155,   156,
       0,   158,     0,   160,     0,     0,     0,     0,     0,     0,
     173,     0,   896,   348,   349,     0,     0,   350,   351,   352,
     353,   354,   355,   356,   348,   349,     0,     0,   350,   351,
     352,   353,   354,   355,   356,     0,   912,     0,   348,   349,
       0,     0,   350,   351,   352,   353,   354,   355,   356,     0,
       0,   915,     0,     0,     0,     0,     0,     0,     0,   918,
     348,   349,   919,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   929,     0,    89,    90,    91,
       0,    92,    93,     0,   935,   936,   937,   938,   939,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,     0,     0,     0,
       0,   395,     0,     0,   357,   358,   359,   360,     0,     0,
       0,     0,   409,     0,    97,    98,    99,   100,   357,   358,
     359,   360,     0,     0,     0,     0,   591,   977,   101,     0,
       0,   102,   981,     0,     0,     0,   210,     0,     0,     0,
     357,   358,   359,   360,   211,     0,   528,     0,   103,   104,
       0,     0,   105,     0,   106,     0,     0,   999,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,     0,    89,    90,    91,   163,
      92,    93,     0,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   348,   349,
     102,     0,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   453,     0,     0,     0,   103,   104,     0,
       0,   105,     0,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   162,     0,    89,    90,    91,   163,    92,
      93,     0,   212,     0,     0,     0,     0,     0,   357,   358,
     359,   360,     0,     0,     0,     0,   628,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   348,   349,   102,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,     0,    89,    90,    91,   163,    92,    93,
       0,   212,     0,     0,     0,     0,     0,   357,   358,   359,
     360,     0,     0,     0,     0,   629,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,     0,     0,     0,     0,     0,
      91,     0,     0,    93,     0,   101,   348,   349,   102,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,    95,   103,   104,     0,     0,   105,
       0,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   105,     0,   106,   163,   425,    89,    90,
      91,     0,    92,    93,     0,     0,   357,   358,   359,   360,
       0,     0,     0,     0,   630,     0,     0,     0,     0,   127,
     128,   129,     0,    94,    95,   133,   134,   135,     0,   137,
       0,   139,   140,   141,     0,     0,     0,     0,   146,   147,
     148,     0,     0,   151,     0,     0,   154,     0,   155,   156,
       0,   158,     0,   160,     0,    97,    98,    99,   100,     0,
     173,     0,     0,     0,    91,     0,     0,    93,     0,   101,
     348,   349,   102,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,     0,     0,    95,   103,
     104,     0,     0,   105,     0,   106,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   105,     0,   106,
     163,   483,    89,    90,    91,     0,    92,    93,     0,     0,
     357,   358,   359,   360,     0,     0,     0,     0,   643,     0,
       0,     0,     0,   127,   128,   129,     0,    94,    95,   133,
     134,   135,     0,   137,     0,   139,   140,   141,     0,     0,
       0,     0,   146,   147,   148,     0,     0,   151,     0,     0,
     154,     0,   155,   156,     0,   158,     0,   160,     0,    97,
      98,    99,   100,     0,   726,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   348,   349,   102,     0,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,   105,     0,   106,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,   163,   493,    89,    90,    91,     0,
      92,    93,     0,   224,   357,   358,   359,   360,     0,     0,
       0,     0,   663,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   348,   349,
     102,     0,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
       0,   105,     0,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   162,     0,    89,    90,    91,   163,    92,
      93,     0,     0,     0,     0,     0,     0,     0,   357,   358,
     359,   360,     0,     0,     0,     0,   670,     0,     0,     0,
      94,    95,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   348,   349,   102,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,     0,    89,    90,    91,   163,    92,    93,
       0,   417,     0,     0,     0,     0,     0,   357,   358,   359,
     360,     0,     0,     0,     0,   671,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   348,   349,   102,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,   105,
       0,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,   158,   159,   160,
     161,   162,     0,    89,    90,    91,   163,    92,    93,     0,
       0,     0,     0,     0,     0,     0,   357,   358,   359,   360,
       0,     0,     0,     0,   721,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,   105,     0,
     106,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,     1,     2,     3,     0,   163,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,    11,  -297,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,  -108,  -108,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,  -108,     0,    49,     0,    50,    51,
     348,   349,     0,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     0,     4,     0,    56,     0,     5,    57,
       6,     0,     7,     8,     9,    10,    11,  -297,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,     0,     0,     0,     0,    23,    -7,    -7,    24,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
     357,   358,   359,   360,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
       0,     0,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,     0,     0,    49,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     0,     4,     0,    56,     0,     5,    57,     6,     0,
       7,     8,     9,    10,    11,  -297,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,     0,
       0,     0,     0,    23,    -7,     0,    24,     0,     0,     0,
      -7,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    39,    40,    41,     0,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     0,
       4,     0,    56,     0,     5,    57,     6,     0,     7,     8,
       9,    10,    11,  -297,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    -7,     0,     0,
       0,    23,    -7,     0,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,   348,   349,    31,
      32,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,   348,   349,     0,     0,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,   348,
     349,     0,    55,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,    57,     0,     0,     0,   357,   358,   359,
     360,     0,   348,   349,     0,   742,   350,   351,   352,   353,
     354,   355,   356,   348,   349,     0,     0,   350,   351,   352,
     353,   354,   355,   356,   348,   349,     0,     0,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,     0,   348,
     349,     0,   743,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
     358,   359,   360,     0,   348,   349,     0,   750,   350,   351,
     352,   353,   354,   355,   356,   348,   349,     0,     0,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
       0,     0,   357,   358,   359,   360,     0,     0,     0,     0,
     753,     0,     0,   357,   358,   359,   360,     0,     0,     0,
       0,   754,     0,     0,   357,   358,   359,   360,     0,   348,
     349,     0,   809,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
     358,   359,   360,     0,   348,   349,     0,   814,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,     0,     0,
       0,     0,   825,     0,     0,   357,   358,   359,   360,     0,
     348,   349,     0,   898,   350,   351,   352,   353,   354,   355,
     356,   348,   349,     0,     0,   350,   351,   352,   353,   354,
     355,   356,   348,   349,     0,     0,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,     0,     0,   357,
     358,   359,   360,     0,   348,   349,     0,   948,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,     0,   348,
     349,     0,   961,   350,   351,   352,   353,   354,   355,   356,
     348,   349,     0,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   359,   360,     0,     0,     0,     0,   992,     0,
       0,   357,   358,   359,   360,     0,     0,   609,     0,     0,
       0,     0,   357,   358,   359,   360,   348,   349,   624,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,   348,   349,
     644,     0,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
     358,   359,   360,     0,     0,   645,     0,     0,     0,     0,
     357,   358,   359,   360,   348,   349,   646,     0,   350,   351,
     352,   353,   354,   355,   356,   348,   349,     0,     0,   350,
     351,   352,   353,   354,   355,   356,   348,   349,     0,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   358,   359,   360,
     348,   349,   647,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,     0,     0,   357,   358,
     359,   360,   348,   349,   648,     0,   350,   351,   352,   353,
     354,   355,   356,   348,   349,     0,     0,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,     0,     0,
     651,     0,     0,     0,     0,   357,   358,   359,   360,     0,
       0,   654,     0,     0,     0,     0,   357,   358,   359,   360,
     348,   349,   655,     0,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   359,   360,   348,   349,   657,     0,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,   357,   358,   359,   360,     0,     0,   658,     0,
       0,     0,     0,   357,   358,   359,   360,   348,   349,   659,
       0,   350,   351,   352,   353,   354,   355,   356,   348,   349,
       0,     0,   350,   351,   352,   353,   354,   355,   356,   348,
     349,     0,     0,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   359,   360,   348,   349,   660,     0,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,   348,   349,
     661,     0,   350,   351,   352,   353,   354,   355,   356,   348,
     349,     0,     0,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,   357,   358,   359,
     360,     0,     0,   662,     0,     0,     0,     0,   357,   358,
     359,   360,     0,     0,   664,     0,     0,     0,     0,   357,
     358,   359,   360,   348,   349,   674,     0,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,   358,   359,   360,   348,   349,
     675,     0,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   357,   358,
     359,   360,     0,     0,   677,     0,     0,     0,     0,   357,
     358,   359,   360,   348,   349,   680,     0,   350,   351,   352,
     353,   354,   355,   356,   348,   349,     0,     0,   350,   351,
     352,   353,   354,   355,   356,   348,   349,     0,     0,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,   348,   349,   725,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   357,   358,
     359,   360,   348,   349,   817,     0,   350,   351,   352,   353,
     354,   355,   356,   348,   349,     0,     0,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,     0,     0,   834,
       0,     0,     0,     0,   357,   358,   359,   360,     0,     0,
     835,     0,     0,     0,     0,   357,   358,   359,   360,   348,
     349,   842,     0,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,   357,   358,   359,
     360,   348,   349,   843,     0,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   357,   358,   359,   360,     0,     0,   844,     0,
       0,     0,     0,   357,   358,   359,   360,   348,   349,   845,
       0,   350,   351,   352,   353,   354,   355,   356,   348,   349,
       0,     0,   350,   351,   352,   353,   354,   355,   356,   348,
     349,     0,     0,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
     358,   359,   360,   348,   349,   850,     0,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,     0,     0,
       0,   357,   358,   359,   360,   348,   349,   851,     0,   350,
     351,   352,   353,   354,   355,   356,   348,   349,     0,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   358,   359,
     360,     0,     0,   854,     0,     0,     0,     0,   357,   358,
     359,   360,     0,     0,   855,     0,     0,     0,     0,   357,
     358,   359,   360,   348,   349,   856,     0,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,   348,   349,   857,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,   357,   358,   359,   360,     0,
       0,   858,     0,     0,     0,     0,   357,   358,   359,   360,
     348,   349,   861,     0,   350,   351,   352,   353,   354,   355,
     356,   348,   349,     0,     0,   350,   351,   352,   353,   354,
     355,   356,   348,   349,     0,     0,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,   348,   349,   862,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   358,   359,
     360,   348,   349,   865,     0,   350,   351,   352,   353,   354,
     355,   356,   348,   349,     0,     0,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   359,   360,     0,     0,   884,     0,     0,     0,
       0,   357,   358,   359,   360,     0,     0,   926,     0,     0,
       0,     0,   357,   358,   359,   360,   348,   349,   930,     0,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   358,   359,
     360,   348,   349,   940,     0,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,   358,   359,   360,     0,     0,   949,     0,     0,
       0,     0,   357,   358,   359,   360,   348,   349,   951,     0,
     350,   351,   352,   353,   354,   355,   356,   348,   349,     0,
       0,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   358,   359,   360,
       0,     0,   952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,   358,   359,   360,     0,     0,   984,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   358,   359,   360,
       0,     0,   991,     0,     0,     0,     0,   357,   358,   359,
     360,     0,     0,  1006
};

static const yytype_int16 yycheck[] =
{
       0,     3,     0,   278,    34,     7,     8,    10,    41,    42,
       9,    83,     9,    10,   731,   732,    11,    80,     4,    37,
      38,     7,    16,     4,    12,    69,     7,     4,     5,    24,
      69,    10,    27,     4,     5,    30,    31,    32,    35,    57,
     165,    36,    37,    38,    11,    23,    55,    47,    42,    47,
      45,     3,   240,   241,    42,     7,     8,    68,    69,    70,
      10,    14,    57,   165,    42,    64,    65,    66,    67,    68,
      69,    26,    55,    10,    57,    58,    67,    68,    69,    70,
      85,    86,    77,    83,     3,    83,     4,     5,     7,    42,
     244,   245,    97,    60,    61,    18,    19,    64,    65,    66,
      67,    68,    69,    70,    99,     4,     7,    70,     7,   181,
      60,    61,   175,   176,    64,    65,    66,    67,    68,    69,
      70,   165,    39,    60,    61,    42,   165,    64,    65,    66,
      67,    68,    69,    70,   161,   161,    81,    60,    61,   166,
     166,    64,    65,    66,    67,    68,    69,    70,    88,   160,
     161,   162,   163,   124,   125,   126,    69,    70,   160,   161,
     169,    42,   161,    70,   103,   168,    47,   162,   163,   160,
     161,   162,   163,   890,   204,   205,   893,     0,   332,   165,
     334,   181,   161,   181,   165,   180,   169,    33,    34,   168,
     165,   224,   187,   160,   161,   162,   163,   230,   231,   162,
     163,   161,     4,     5,   267,   268,   166,   161,   160,   161,
     160,   161,   162,   163,   168,   210,   165,   212,   168,   165,
     253,   254,   255,   160,   161,   162,   163,   165,   161,    65,
     418,    67,    68,    69,    70,   168,   161,   160,   161,   162,
     163,    56,    42,   168,   432,   433,   279,   160,   161,   162,
     163,   246,   161,   160,   161,   162,   163,   275,   276,   168,
     166,   256,   168,   980,   161,   161,   261,    82,    83,    84,
     265,   168,   168,   291,    89,   463,   271,   272,   161,   274,
     275,   276,   166,   166,   168,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   377,     4,     5,   161,   327,
     305,   306,   307,   308,   309,   168,   311,   161,   313,   166,
       5,   168,   166,     8,   160,   161,   162,   163,   391,   392,
     161,   161,   327,   396,   397,   166,   166,   168,    64,    65,
      66,    67,    68,    69,    29,   161,    64,    65,    66,    67,
      68,    69,   168,     4,     5,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   165,   161,   161,   161,
      69,   401,   166,   166,   168,   168,   168,   377,   166,   377,
     168,   414,   161,   378,   417,    44,   161,   166,   383,   168,
     166,   166,   168,    64,    65,    66,    67,    68,    69,   394,
     395,    60,    61,   167,   168,    64,    65,    66,    67,    68,
      69,    70,   407,    98,   409,   100,    64,    65,    66,    67,
      68,    69,    69,   698,   419,   420,   701,    64,    65,    66,
      67,    68,    69,   428,   429,   161,    22,   161,     4,   124,
     125,   126,   168,   161,   168,   130,   131,   132,   166,   134,
     168,   136,   137,   138,   161,     4,     5,   161,   143,   144,
     145,   168,   166,   148,   168,   161,   151,   161,   153,   154,
     166,   156,   168,   158,   161,    79,    80,   161,   161,   166,
     165,   166,   166,   166,   168,   168,     4,     5,   551,   552,
     161,   554,   555,   161,   161,   166,     4,     5,   166,   166,
     168,   160,   161,   162,   163,   161,    44,   161,   165,   161,
     166,   161,   166,   161,   166,   161,   166,     5,   166,   168,
     166,   165,    60,    61,   161,   165,    64,    65,    66,    67,
      68,    69,    70,   161,    37,    38,   161,    48,   166,   536,
     537,   166,   605,   538,   539,   165,   161,   161,   165,    60,
      61,   166,   166,    64,    65,    66,    67,    68,    69,    70,
     161,   161,   161,   161,   166,   166,   166,   166,   166,   602,
     161,   161,   567,   761,    55,   166,   166,   165,   573,   574,
     165,   161,   577,   161,   617,   618,   166,   161,   166,   161,
     165,   779,   166,   166,   166,   165,   591,    60,    61,     4,
       5,    64,    65,    66,    67,    68,    69,    70,   165,   642,
     165,   606,   607,   608,   165,   615,   168,   615,    57,    58,
     165,   616,   160,   161,   162,   163,   165,   622,   623,   165,
     625,   165,   165,   628,   629,   630,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   640,   641,   719,   643,   160,
     161,   162,   163,   165,   168,   650,   165,    41,   653,   165,
     165,   165,    69,   165,   165,   165,   165,   165,   663,   165,
     165,   666,   667,   668,   165,   670,   671,   740,   741,   165,
     165,   165,   165,   165,   679,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   766,   165,   165,   160,   161,   162,
     163,   165,   168,   166,   165,   168,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   719,
     165,   719,   165,   165,   165,   165,   721,    60,    61,   747,
     748,    64,    65,    66,    67,    68,    69,    70,   168,   168,
      64,    65,    66,    67,    68,    69,    70,   742,   743,   168,
     166,   166,   747,   748,    70,   818,   819,   165,   753,   754,
      41,   165,   168,   165,   165,   168,   766,    60,   766,   166,
     166,    64,    65,    66,    67,    68,    69,    70,    44,   165,
     165,     8,    15,   165,   165,    18,    65,    66,    67,    68,
      69,    70,   168,   168,    27,   168,   168,   168,    31,    32,
     166,   798,   799,    36,   166,   838,   166,   168,   166,   804,
     165,   165,   168,   166,   809,    48,    49,    50,   166,   814,
     166,   168,   166,    41,    57,    47,   166,   160,   161,   162,
     163,   166,   166,   166,   165,   168,   160,   161,   162,   163,
     165,    78,   837,   166,    78,   840,    79,   166,   920,   921,
       5,   166,    55,   165,   168,   168,   166,   166,   853,   166,
     166,   165,   165,   168,   166,   860,   166,   160,   161,   162,
     163,   166,   867,    41,   869,    36,    41,   165,    69,   166,
     166,   160,   161,   162,   163,    69,   958,    69,    46,    55,
     166,   886,   166,   165,   165,    45,   968,   165,   165,   971,
       5,    60,    61,     8,   166,    64,    65,    66,    67,    68,
      69,    70,    69,   985,   166,    36,     4,    47,   615,    47,
     920,   921,   920,   921,    29,   556,   278,   922,   944,   622,
     163,   553,   804,   401,  1004,   964,   398,    -1,   729,    -1,
     173,    -1,    -1,    -1,   411,    -1,    -1,   180,    -1,    -1,
     945,    -1,    -1,   948,   187,    -1,    -1,    -1,   958,    -1,
     958,    -1,    -1,    -1,    -1,    -1,   961,   962,   968,    -1,
     968,   971,    -1,   971,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,   985,    -1,   985,   221,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,   992,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,   168,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,   257,   130,   131,   132,   261,   134,
      -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   275,   148,    -1,    -1,   151,    -1,   153,   154,
      -1,   156,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,    -1,    -1,    -1,    -1,    -1,   300,   301,   302,
     303,   304,    -1,    -1,    -1,    -1,    -1,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,    -1,    -1,   331,    -1,
     333,    -1,   335,    -1,    -1,    -1,   339,   340,   341,   342,
     343,   344,   345,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,   380,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,   415,     5,    -1,    -1,     8,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,   428,   429,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    29,    -1,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,    98,    -1,   100,    -1,
     165,    -1,    -1,     5,   169,    -1,     8,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,   124,   125,   126,    -1,    -1,    29,   130,   131,
     132,    -1,   134,    -1,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,   148,    -1,    -1,   151,
      -1,   153,   154,    -1,   156,    -1,   158,   570,    -1,    -1,
     573,    -1,    -1,   165,   166,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,
      -1,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,   622,
     160,   161,   162,   163,    -1,    -1,   166,    -1,   168,    -1,
     633,   634,   124,   125,   126,    29,    -1,    -1,   130,   131,
     132,    -1,   134,    -1,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,   148,    -1,    -1,   151,
       5,   153,   154,     8,   156,    -1,   158,    -1,    -1,    -1,
     673,    -1,    -1,   165,   166,   160,   161,   162,   163,    -1,
      -1,   166,    -1,   168,    29,    -1,    -1,   690,   691,    -1,
     160,   161,   162,   163,   697,    -1,    90,   700,   168,    -1,
     703,   704,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   724,    -1,   726,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,   130,   131,   132,    -1,
     134,    -1,   136,   137,   138,    90,   749,   750,   751,   143,
     144,   145,    -1,    98,   148,   100,    -1,   151,    -1,   153,
     154,    -1,   156,    -1,   158,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
      -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,   804,    -1,   148,    -1,    -1,   151,    -1,   153,   154,
      -1,   156,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,   825,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,   849,    -1,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,   864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,
      60,    61,   875,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,   888,    -1,     3,     4,     5,
      -1,     7,     8,    -1,   897,   898,   899,   900,   901,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    60,    61,    62,    63,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   960,    74,    -1,
      -1,    77,   965,    -1,    -1,    -1,    82,    -1,    -1,    -1,
     160,   161,   162,   163,    90,    -1,   166,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,    -1,   990,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,     3,     4,     5,   165,
       7,     8,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    60,    61,
      77,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,     3,     4,     5,   165,     7,
       8,    -1,   169,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
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
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,     3,     4,     5,   165,     7,     8,
      -1,   169,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,     8,    -1,    74,    60,    61,    77,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    94,    95,    -1,    -1,    98,
      -1,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,    -1,    98,    -1,   100,   165,   166,     3,     4,
       5,    -1,     7,     8,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    28,    29,   130,   131,   132,    -1,   134,
      -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,   148,    -1,    -1,   151,    -1,   153,   154,
      -1,   156,    -1,   158,    -1,    60,    61,    62,    63,    -1,
     165,    -1,    -1,    -1,     5,    -1,    -1,     8,    -1,    74,
      60,    61,    77,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    94,
      95,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,    98,    -1,   100,
     165,   166,     3,     4,     5,    -1,     7,     8,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    28,    29,   130,
     131,   132,    -1,   134,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,    -1,   148,    -1,    -1,
     151,    -1,   153,   154,    -1,   156,    -1,   158,    -1,    60,
      61,    62,    63,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    60,    61,    77,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,     3,     4,     5,    -1,
       7,     8,    -1,    10,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    60,    61,
      77,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,     3,     4,     5,   165,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,     3,     4,     5,   165,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    28,
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
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
     159,   160,    -1,     3,     4,     5,   165,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,   159,
     160,     4,     5,     6,    -1,   165,     9,    -1,    -1,    -1,
      13,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    -1,    -1,    96,    97,    -1,    99,    -1,   101,   102,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,     9,    -1,   149,    -1,    13,   152,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    87,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    96,    -1,    -1,    99,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,   149,    -1,    13,   152,    15,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
       9,    -1,   149,    -1,    13,   152,    15,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    -1,    60,    61,    58,
      59,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    87,    88,
      89,    -1,    91,    92,    93,    -1,    -1,    96,    -1,    -1,
      99,    -1,   101,   102,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,    60,
      61,    -1,   131,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    60,    61,    -1,   168,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    60,
      61,    -1,   168,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    -1,    60,    61,    -1,   168,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   160,   161,   162,   163,    -1,    60,
      61,    -1,   168,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    -1,    60,    61,    -1,   168,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,   160,   161,   162,   163,    -1,
      60,    61,    -1,   168,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    -1,    60,    61,    -1,   168,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    60,
      61,    -1,   168,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    60,    61,   166,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    60,    61,
     166,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    60,    61,   166,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      60,    61,   166,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    60,    61,   166,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      60,    61,   166,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    60,    61,   166,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    60,    61,   166,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    60,    61,   166,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    60,    61,
     166,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    60,    61,   166,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    60,    61,
     166,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    60,    61,   166,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    60,    61,   166,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    60,    61,   166,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,
     166,    -1,    -1,    -1,    -1,   160,   161,   162,   163,    60,
      61,   166,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    60,    61,   166,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    60,    61,   166,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    60,    61,   166,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,    60,    61,   166,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,    60,    61,   166,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    60,    61,   166,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      60,    61,   166,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,    60,    61,   166,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    60,    61,   166,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,   166,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    60,    61,   166,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    60,    61,   166,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,    60,    61,   166,    -1,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,   166,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,   166
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
     101,   102,   124,   125,   126,   131,   149,   152,   171,   172,
     175,   182,   183,   185,   186,   190,   202,   203,   208,   214,
     221,   229,   237,   240,   244,   247,   253,    69,   165,    69,
     165,   222,   241,   245,     4,     7,   200,   200,   200,     3,
       4,     5,     7,     8,    28,    29,    32,    60,    61,    62,
      63,    74,    77,    94,    95,    98,   100,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   153,   154,   155,   156,   157,
     158,   159,   160,   165,   188,   189,   191,   197,   199,   202,
     203,   176,   177,   165,   188,   165,   165,   188,    26,     7,
     230,   238,   191,    55,    57,    58,   169,   275,   180,   188,
     191,     4,     5,   201,   191,   188,   191,   188,   191,     4,
       5,   263,   264,     8,   160,   161,   198,   199,   265,   200,
      82,    90,   169,   188,   191,   276,    82,    90,   103,   276,
     276,    81,   191,   196,    10,    50,   196,   196,    56,    82,
      83,    84,    89,    88,   191,   183,   190,   202,   203,   188,
     188,   188,   103,   165,   165,   165,   165,   165,   188,   276,
       0,    42,   173,    85,    86,    97,    69,    69,    22,   191,
     204,   205,   188,   204,     4,   165,   172,   165,   165,    33,
      34,   165,   165,   191,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   191,   188,   191,    64,
      65,    66,    67,    68,    69,   161,    18,    19,    60,    61,
      64,    65,    66,    67,    68,    69,    70,   160,   161,   162,
     163,     4,     5,   215,   216,     4,     5,   217,   218,   188,
     204,   204,   188,   191,   232,   172,   248,   254,   165,    55,
     165,     4,     7,   165,   188,   191,   266,    55,   169,   268,
     273,   165,   165,   168,   168,   168,   165,   165,   168,   199,
     199,   168,   191,   188,   191,     9,   168,   168,   188,   168,
     196,   181,    10,   168,   184,   168,   196,    10,   196,   184,
     184,     5,   187,   187,   187,   166,   191,   188,   168,   168,
      41,   196,   196,   196,   191,   188,   209,   166,   188,   191,
     206,   207,   166,    69,   191,    16,    42,   246,   204,   204,
     191,   191,   191,    90,   188,   276,   276,     4,     5,   194,
     195,   194,   195,   196,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   276,   191,   191,   191,   191,
     191,   191,   191,   166,   191,   188,   188,   188,   188,   188,
     191,   191,   191,   166,   191,   191,   188,   191,   188,   191,
     188,   188,   166,   188,   166,   188,   166,   188,   166,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   276,   188,
     166,   166,   188,   187,   188,   187,   188,   166,   166,   188,
     188,   188,   188,   188,   188,   188,   178,   179,   193,   192,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   165,   165,   168,   165,   165,   168,   166,   166,    41,
     231,    39,    42,   239,    44,   172,   191,   165,   188,   191,
      48,   267,   167,   168,   165,     4,     7,   165,     8,   274,
     204,   204,     4,     5,   191,   191,   204,   204,   264,     8,
     198,   168,    79,    80,    90,   188,   191,   191,   268,   196,
     188,   196,   184,   191,   191,   165,   168,   168,   168,   166,
     166,   188,   191,   188,   191,   174,   168,   184,   184,     4,
       5,   213,   168,   223,   166,   165,   166,   166,   168,   168,
     168,   166,   166,   168,   168,   166,   165,   165,   166,   166,
     168,   168,   184,   168,   166,   166,   166,   166,   166,   166,
     168,   166,   166,   168,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   168,   166,   166,   168,   168,   168,   166,
     168,   168,   166,   168,   166,   166,   166,   166,   166,   168,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     168,   168,   166,   166,   166,   166,   166,   168,   168,   166,
     168,   168,   166,   168,   168,   200,   277,   200,   278,   191,
     191,   204,   204,   216,   204,   204,   218,    41,   233,   249,
      47,   168,   191,   166,   168,   166,   165,   188,   188,   191,
     191,   269,   270,   191,     4,     5,   260,   262,   166,   166,
     165,   165,   168,   168,   166,   166,   191,    78,    78,   168,
     168,   168,   196,   168,   168,   204,   191,   191,   191,   175,
     191,   196,   196,   210,   207,   191,   242,   191,   191,   191,
     191,   188,    90,   188,   166,   166,   191,   191,   196,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   188,   191,
     188,   188,   188,   195,   188,   195,   188,   188,   168,   168,
     166,   166,   166,   166,    37,    38,   235,   172,   191,   168,
      55,   188,   188,   267,   168,   260,   260,   166,   165,   165,
     168,   204,   204,   191,   191,   168,   276,   276,   188,   188,
     188,   191,   191,   166,   166,   166,   166,   168,   184,   165,
      10,   172,   166,   166,   166,   166,   166,   166,   166,   168,
     166,   166,   166,   184,   166,   166,   166,   166,   166,   166,
     168,   166,   166,   166,   168,   166,   166,   168,   166,   168,
     166,   166,   168,   166,   166,   168,   166,   166,   200,   200,
     232,    41,    36,   250,   166,   191,   165,   166,   168,   191,
     271,   204,   204,   261,   166,   166,   188,   168,   168,    69,
      69,    69,   191,   196,     4,     5,   219,   220,   191,    14,
      42,   243,   188,   191,   191,   188,   191,   191,   188,   188,
     234,   236,    46,   256,    57,    58,   166,   191,    55,   188,
     166,   260,   166,   166,   260,   188,   188,   188,   188,   188,
     166,   165,   165,   166,   168,    11,   227,   166,   168,   166,
     166,   166,   166,   166,   166,   172,   172,   191,    45,   255,
     165,   168,   165,   166,   272,    69,   166,   166,   211,   220,
     191,   224,   191,    44,   259,   172,   251,   188,   191,   191,
     274,   188,   172,   172,   166,   257,    42,    47,   252,   166,
     168,   166,   168,   260,    23,    42,   212,   225,   172,   188,
     191,    12,    42,   226,   258,   166,   166,     4,   228,   256
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   170,   171,   172,   173,   174,   172,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   176,   175,   177,   175,   175,
     175,   175,   175,   175,   175,   178,   175,   179,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   180,
     175,   181,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   182,   182,
     182,   182,   182,   183,   183,   183,   183,   183,   183,   184,
     184,   185,   185,   185,   185,   185,   186,   186,   187,   187,
     188,   188,   188,   188,   188,   188,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   190,   190,
     192,   191,   193,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   194,   195,   196,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   198,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   201,
     202,   203,   205,   204,   206,   206,   206,   207,   207,   209,
     210,   211,   208,   212,   212,   213,   213,   214,   214,   214,
     214,   215,   215,   216,   216,   216,   216,   217,   217,   218,
     218,   218,   218,   219,   219,   219,   220,   220,   220,   220,
     222,   223,   224,   225,   221,   226,   226,   227,   227,   228,
     228,   230,   229,   231,   231,   232,   232,   233,   234,   233,
     235,   236,   235,   238,   237,   239,   239,   241,   242,   240,
     243,   243,   245,   244,   246,   246,   248,   249,   250,   251,
     247,   252,   252,   254,   253,   255,   255,   256,   257,   258,
     256,   259,   259,   260,   261,   260,   262,   262,   262,   262,
     263,   263,   264,   264,   264,   264,   265,   265,   265,   265,
     266,   266,   266,   266,   266,   267,   267,   267,   269,   268,
     270,   268,   271,   268,   272,   268,   273,   268,   274,   274,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   277,   277,   278,   278
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
       4,     4,     4,     4,     4,     6,     4,     3,     6,     6,
       4,     4,     4,     4,     6,     6,     8,     6,     8,     4,
       4,     4,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     6,     6,     6,     4,     8,     6,
       8,     6,     4,     4,     4,     6,     6,     6,     8,     1,
       2,     2,     1,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     0,     2,     0,     1,     3,     1,     1,     0,
       0,     0,    11,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     3,     1,     1,     4,     4,     1,     3,     1,
       1,     4,     4,     0,     1,     3,     1,     1,     3,     3,
       0,     0,     0,     0,    14,     1,     1,     0,     2,     0,
       1,     0,     7,     1,     2,     1,     1,     0,     0,     5,
       0,     0,     4,     0,     4,     1,     1,     0,     0,     8,
       1,     1,     0,     4,     1,     4,     0,     0,     0,     0,
      11,     1,     1,     0,     5,     0,     2,     0,     0,     0,
       7,     0,     1,     1,     0,     4,     1,     4,     1,     4,
       1,     3,     1,     4,     1,     4,     1,     1,     3,     3,
       0,     2,     4,     1,     3,     0,     2,     6,     0,     4,
       0,     4,     0,     6,     0,     9,     0,     3,     0,     1,
       0,     2,     2,     4,     1,     4,     6,     6,     7,    10,
      12,     7,    10,    12,     2,     1,     1,     3,     1,     3
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

    {create_function(fCEIL);}

    break;

  case 221:

    {create_function(fFLOOR);}

    break;

  case 222:

    {create_function(fFRAC);}

    break;

  case 223:

    {create_function(fABS);}

    break;

  case 224:

    {create_function(fSIG);}

    break;

  case 225:

    {create_function(fMOD);}

    break;

  case 226:

    {create_function(fRAN);}

    break;

  case 227:

    {create_function(fRAN2);}

    break;

  case 228:

    {create_function(fMIN);}

    break;

  case 229:

    {create_function(fMAX);}

    break;

  case 230:

    {create_function(fLEN);}

    break;

  case 231:

    {create_function(fVAL);}

    break;

  case 232:

    {create_function(fASC);}

    break;

  case 233:

    {create_function(fDEC);}

    break;

  case 234:

    {create_function(fDEC2);}

    break;

  case 235:

    {if (check_compat) error(WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 236:

    {create_function(fINSTR2);}

    break;

  case 237:

    {create_function(fRINSTR);}

    break;

  case 238:

    {create_function(fRINSTR2);}

    break;

  case 239:

    {create_function(fSYSTEM2);}

    break;

  case 240:

    {create_function(fPEEK4);}

    break;

  case 241:

    {create_function(fPEEK);}

    break;

  case 242:

    {create_function(fMOUSEX);}

    break;

  case 243:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 244:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 245:

    {create_function(fMOUSEY);}

    break;

  case 246:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 247:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 248:

    {create_function(fMOUSEB);}

    break;

  case 249:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 250:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 251:

    {create_function(fMOUSEMOD);}

    break;

  case 252:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 253:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 254:

    {create_function(fAND);}

    break;

  case 255:

    {create_function(fOR);}

    break;

  case 256:

    {create_function(fEOR);}

    break;

  case 257:

    {create_function(fTELL);}

    break;

  case 258:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 259:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 260:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 261:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 262:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 263:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 264:

    {create_myopen(0);}

    break;

  case 265:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 266:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 267:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 268:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 269:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 270:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 271:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 272:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 273:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 274:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 275:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 276:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 277:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 278:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 279:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 280:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 281:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 282:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 289:

    {missing_endsub++;missing_endsub_line=mylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {error(ERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 290:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 291:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 292:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 293:

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);error(ERROR,string);} YYABORT;}

    break;

  case 294:

    {missing_endsub--;}

    break;

  case 295:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 296:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 297:

    {exported=FALSE;}

    break;

  case 298:

    {exported=TRUE;}

    break;

  case 299:

    {exported=FALSE;}

    break;

  case 300:

    {exported=TRUE;}

    break;

  case 303:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 304:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 305:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 306:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 309:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 310:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 311:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 312:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 316:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 317:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 318:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 319:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 320:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=mylineno;}

    break;

  case 321:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 322:

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

  case 323:

    {
             swap();popgoto();poplabel();}

    break;

  case 324:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 325:

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);error(ERROR,string);} YYABORT;}

    break;

  case 326:

    {missing_next--;}

    break;

  case 327:

    {create_pushdbl(1);}

    break;

  case 329:

    {pop(stSTRING);}

    break;

  case 330:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {error(ERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 331:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 332:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 333:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 334:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 338:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 339:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 341:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep); add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 343:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=mylineno;pushgoto();}

    break;

  case 345:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);error(ERROR,string);} YYABORT;}

    break;

  case 346:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 347:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=mylineno;pushgoto();}

    break;

  case 348:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 350:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);error(ERROR,string);} YYABORT;}

    break;

  case 351:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 352:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=mylineno;pushgoto();}

    break;

  case 354:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);error(ERROR,string);} YYABORT;}

    break;

  case 355:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 356:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 357:

    {missing_endif++;missing_endif_line=mylineno;}

    break;

  case 358:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 359:

    {poplabel();}

    break;

  case 361:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);error(ERROR,string);} YYABORT;}

    break;

  case 362:

    {missing_endif--;}

    break;

  case 363:

    {fi_pending++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 364:

    {poplabel();}

    break;

  case 368:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 369:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 374:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 376:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 377:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 378:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 379:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 382:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 383:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 384:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 385:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 386:

    {create_strdata((yyvsp[0].string));}

    break;

  case 387:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 388:

    {create_strdata((yyvsp[0].string));}

    break;

  case 389:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 393:

    {create_print('s');}

    break;

  case 394:

    {create_print('s');}

    break;

  case 395:

    {create_print('d');}

    break;

  case 396:

    {create_print('u');}

    break;

  case 397:

    {create_print('U');}

    break;

  case 398:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 399:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 400:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 401:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 402:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 403:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 404:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 405:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 406:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 407:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 408:

    {create_pushstr("?");create_print('s');}

    break;

  case 409:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 410:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 411:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 412:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 413:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 414:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 415:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 416:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 417:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 418:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 419:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 420:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 421:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 422:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 423:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 426:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 427:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 428:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 429:

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
