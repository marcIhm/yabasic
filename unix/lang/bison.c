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
int max_switch_id=1;
int switch_id=0;

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
#define YYFINAL  247
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  168
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  426
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1001

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
       0,   147,   147,   150,   151,   152,   151,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   172,   173,   173,   174,   175,
     176,   177,   178,   179,   180,   180,   182,   182,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   194,
     195,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   212,   213,   214,   215,   216,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   263,   264,   265,
     266,   267,   271,   272,   273,   274,   275,   276,   279,   280,
     283,   284,   285,   286,   287,   290,   291,   294,   295,   298,
     299,   300,   301,   302,   303,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   340,   341,   344,
     344,   345,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   378,   381,   384,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   449,   450,   451,   454,
     455,   458,   459,   462,   463,   464,   465,   468,   471,   474,
     474,   477,   478,   479,   482,   483,   486,   487,   490,   486,
     495,   496,   499,   500,   503,   504,   505,   506,   509,   510,
     513,   514,   515,   516,   519,   520,   523,   524,   525,   526,
     529,   530,   531,   534,   535,   536,   537,   540,   541,   545,
     559,   540,   564,   565,   568,   569,   572,   573,   578,   578,
     582,   583,   586,   587,   591,   593,   592,   597,   598,   598,
     602,   602,   608,   609,   613,   614,   613,   620,   621,   625,
     625,   630,   631,   635,   636,   636,   638,   635,   642,   643,
     646,   646,   650,   651,   654,   656,   658,   655,   662,   663,
     666,   667,   667,   670,   671,   673,   674,   678,   679,   682,
     683,   685,   686,   690,   691,   692,   693,   696,   697,   698,
     699,   700,   703,   704,   705,   708,   708,   709,   709,   710,
     710,   711,   711,   712,   712,   715,   716,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   735,   736,   738,   739,   742,   743
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

#define YYPACT_NINF -710

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-710)))

#define YYTABLE_NINF -354

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3431,   -58,   -57,  -710,  -710,  -710,  -710,  -710,    50,    50,
      50,  2360,  -710,  -710,  -710,  3095,   -92,   -84,  3095,    83,
    -710,  -710,  -710,  -710,  2674,   -34,  -710,  2674,   152,  -710,
    2674,  2674,  2674,   438,    45,    50,  1246,  1089,  1560,    36,
    2674,  2203,  2674,   140,    43,  2674,  -710,    23,  3095,  3095,
    3095,    61,    64,    84,    94,   108,   138,  1560,   179,   145,
    -710,    10,  -710,  -710,  -710,  -710,   124,   146,  -710,   215,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  2674,  -710,  3095,
    -710,   308,   185,  3295,  -710,  -710,  -710,  -710,  -710,  -710,
     199,   210,  -710,  -710,   226,   235,     6,   239,   290,  2674,
     300,   302,   321,   329,   370,   372,   405,   407,   410,   411,
     421,   422,   425,   434,   435,   440,   444,   446,   448,   449,
     450,   453,   454,   455,   456,   459,   461,   462,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   477,   480,   484,
     486,   487,   493,   495,   497,   498,   502,   505,   510,   514,
     515,   516,   518,   520,   528,   531,   532,   540,   541,   544,
    2674,  2674,    33,  -710,   526,  -710,  -710,  -710,  -710,   447,
     508,  3095,   277,  -710,  -710,   277,  -710,  2674,  3295,   632,
     545,   263,   546,    13,  2674,   -49,    33,  3338,   550,   551,
     339,  3338,    33,  1575,    33,  1732,   552,   553,   377,  -710,
    -710,   383,   383,  -710,  -710,   478,  -710,  2674,  3095,  2674,
      25,  3338,   491,  -710,  -710,  -710,  -710,   522,  3095,  1894,
    -710,  2674,  -710,    -5,   555,  -710,  -710,  2674,  2517,  -710,
    -710,  3338,  -710,  -710,   124,   146,   277,    -6,    -6,  -710,
     485,   485,   485,  1717,  3095,    47,   557,  -710,  -710,   574,
    2674,  2674,  2674,  2674,  3095,  -710,  3338,   560,  2674,   277,
     562,   605,  2674,    30,  -710,  -710,  -710,  -710,  2674,  2674,
     357,  2674,  1403,  1560,   517,   517,  2674,  2674,  2674,  2674,
    2674,  2674,  2674,  2674,  2674,  2674,  2674,  2674,  1560,  2674,
    2674,  2674,  2674,  2674,  1879,  3095,  3095,  3095,  3095,  3095,
    2674,  2674,  2674,  2041,  2674,  3095,  2674,  3095,  2674,  3095,
    3095,  2735,  2831,  2888,  2935,  3095,  3095,  3095,  3095,  3095,
    3095,  3095,  1560,  3095,   565,   576,  3095,   485,  3095,   485,
    3095,   610,    -1,  1265,  3095,  3095,  3095,  3095,  3095,  3095,
    3095,  -710,  -710,  -710,  -710,  2674,  2674,  2674,  2674,  2674,
    2674,  2674,  2674,  2674,  2674,  2674,   578,   579,   580,  -710,
     582,   584,   585,  -710,   -56,   588,   589,    33,  3338,   641,
     481,   674,  3567,  2674,   591,  3095,  -710,  -710,  2674,    33,
     925,   360,   592,    18,  -710,   740,  -710,  -710,   525,  2674,
    2674,  -710,  -710,   438,  -710,  -710,    52,  2056,   277,  3338,
     452,  2985,  2674,   277,  2674,  -710,   -49,  -710,  -710,  2674,
    3095,  -710,  2674,    -5,  2674,  2674,   593,   594,   595,   596,
    -710,  4030,    24,  2674,  2674,  -710,   597,    -5,    -5,  3338,
     277,   542,  -710,    33,  3338,   598,  -710,  -710,  -710,  4055,
     602,  -710,  -710,   606,   618,  2218,  2375,  2532,   619,   175,
     600,   620,   626,   631,   633,   634,   603,   629,    -5,  2689,
    4066,  4111,  4132,  4168,  4179,   870,  4190,   940,  4213,  4234,
     635,  4245,  4292,  4315,  4347,  2840,  -710,  4358,    38,   -79,
     -11,    35,    72,  3094,  3699,   995,  -710,  4369,  4394,    87,
    4417,   -78,  4428,    96,   116,  -710,   202,  -710,   204,  -710,
     205,  -710,   211,   217,   220,   221,    39,    90,   223,   229,
       9,   637,     3,  -710,  -710,   102,   115,   166,   136,   167,
    -710,  -710,   277,   277,   277,   277,   277,   277,  -710,    50,
      50,  2674,  2674,   511,   494,   441,   342,   390,    -9,  -710,
     -39,   -39,   610,   610,  -710,  -710,   447,  -710,  -710,   508,
    -710,  -710,  -710,   717,  -710,  -710,  -710,  -710,   749,  3746,
    2674,    62,  4471,  3142,  -710,  -710,  2674,  2674,  -710,  -710,
    2674,  -710,   548,   638,   639,   643,   644,  3769,  3802,   640,
     645,  -710,  -710,  -710,  2674,   730,   733,  -710,   169,  3813,
    3338,  -710,  -710,   178,  -710,  2674,  3824,  3849,  -710,  2674,
    2674,  2674,  -710,  -710,    33,  3338,    33,  3338,  3295,  2674,
    2674,  2674,  -710,  -710,  -710,  2674,  2674,  -710,  2674,  -710,
    -710,  2674,  2674,  2674,  -710,  -710,  3095,  3045,  -710,   648,
     649,  -710,  -710,  2674,  2674,  2674,  2674,  -710,  -710,  -710,
    -710,  -710,  -710,  2674,  -710,  -710,  2674,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  2674,  -710,  -710,  2674,  2674,  2674,
    -710,  2674,  2674,  -710,  3095,  -710,  -710,  -710,  -710,  -710,
    2674,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  3095,  3095,  -710,  -710,  -710,  -710,  -710,  3095,   809,
    -710,  3095,   809,  -710,  3095,  3095,  -710,   650,  -710,   651,
     357,   711,   654,   655,  -710,   656,   657,  -710,  -710,   519,
    3295,  -710,  2674,  3872,   760,  3095,  -710,  3095,   277,    33,
     925,  3883,   548,   548,  4496,   659,   661,  -710,   663,  -710,
    -710,  -710,  -710,  2674,  2674,  -710,  -710,  3927,  1560,  1560,
    3095,  3095,  3095,  -710,  2674,  2674,   666,  4530,  4541,  1009,
    -710,  3338,    -5,  -710,   668,  -710,    74,  3295,  4552,  4573,
    4598,  4609,   233,   670,    86,  -710,  -710,  4654,  4675,   671,
      59,  4711,  4722,  4733,  4756,  4777,  1418,  4788,  4835,   100,
    4858,   106,   151,   237,   174,   240,   242,   241,   271,    50,
      50,  -710,  -710,  -710,  -710,  2674,   791,   801,   797,  4890,
    2674,   676,   273,   155,  -710,  2674,  -710,  -710,  -710,  -710,
    -710,  -710,   678,   681,  3338,  3338,  3095,  -710,  -710,   277,
     277,   183,  3952,  3338,  -710,   777,   779,   782,  2674,  2674,
     554,  2674,    16,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    3095,  -710,  -710,  -710,  2674,  -710,  -710,  -710,  -710,  -710,
    -710,  2674,  -710,  -710,  -710,  3095,  -710,  -710,  2674,  -710,
    2674,  -710,  -710,  3095,  -710,  -710,  3095,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,   806,   509,  4901,  2674,   800,  3095,
    4912,   548,   693,   694,   548,  -710,  -710,   277,  3095,  3095,
    3095,  3095,  3095,  4937,  -710,   696,   697,   250,  -710,   380,
    -710,  -710,  -710,   274,  3986,  4960,   275,  4971,  5014,   303,
     324,  3295,  3703,  2674,   816,  -710,   699,  -710,  3997,   701,
     327,  -710,  -710,  -710,  -710,  -710,   277,   277,   277,   277,
     277,   798,   702,   704,  -710,   554,  2674,  -710,  -710,  2674,
    -710,  -710,  -710,  -710,  -710,  -710,   797,   837,   667,  3295,
    -710,  3095,  2674,  2674,  -710,   740,  3095,  -710,  -710,  3295,
    -710,  3338,  3295,  5039,  -710,  -710,   797,   112,   165,  5073,
    4008,   548,   277,    28,   797,  -710,  3295,  -710,  -710,  -710,
    -710,  3095,  -710,  2674,  -710,  -710,  -710,  -710,    14,   797,
     355,  5084,  -710,  -710,   871,   806,  -710,  -710,  -710,  -710,
    -710
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     107,     0,     0,   105,   317,   344,   349,    12,     0,     0,
       0,     0,    24,    26,   295,     0,     0,     0,     0,   296,
      19,    20,   328,   340,     0,   407,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     4,
       3,     0,     8,    39,    41,    10,    22,    23,    21,     0,
      14,    15,    18,    17,    16,    28,    29,     0,   279,     0,
     279,     0,     0,     7,   272,   271,    30,    31,    38,   269,
     188,   129,   270,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
     240,   243,   246,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   130,     0,   201,   182,   187,   131,     0,
       0,     0,    13,   279,   279,    42,   297,     0,     7,   360,
       0,   411,     0,     0,   387,   403,    62,    61,     0,     0,
      63,   104,    53,     0,    55,     0,   379,   381,    56,   377,
     383,     0,     0,   384,   266,    57,    59,     0,    89,     0,
       0,   422,     0,    86,    91,    79,    40,     0,     0,     0,
      67,     0,    50,    72,     0,    88,    87,     0,     0,   110,
     111,    92,     9,    11,     0,     0,   106,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     0,     0,     0,   286,   167,     0,   281,   112,
       0,     0,     0,     4,   279,   279,    32,    33,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    36,   171,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   300,   301,    25,   298,
     306,   307,    27,   304,     0,     0,     0,   333,   332,     0,
       4,     0,   107,     0,     0,     0,   408,   409,     0,   390,
     392,    45,     0,     0,    49,   405,   279,   279,     0,     0,
       0,   279,   279,     0,   268,   267,     0,     0,    90,   421,
       0,     0,     0,    66,     0,    71,   403,   119,   118,     0,
       0,    68,     0,    74,     0,     0,   127,     0,     0,     0,
      95,     0,     0,     0,     0,     5,     0,     0,     0,   168,
     117,     0,   277,   284,   285,   280,   282,   278,   318,     0,
       0,   351,   350,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,   244,     0,   247,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   155,     0,     0,     0,     0,     0,
     134,   202,   196,   198,   200,   197,   199,   195,   133,     0,
       0,     0,     0,   175,   177,   179,   176,   178,   174,   193,
     190,   189,   191,   192,   279,   279,     0,   279,   279,     0,
      43,    44,   330,   334,   343,   342,   341,   354,     4,     0,
       0,     0,     0,     0,   388,    46,    47,     0,   395,   397,
       0,   406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   385,   386,     0,     0,     0,   122,   121,   125,
     205,    51,    69,    82,    73,     0,     0,     0,   279,     0,
       0,     0,    96,    97,    98,    99,   100,   101,     7,     0,
       0,     0,   292,   293,   287,     0,     0,   345,     0,   259,
     166,     0,     0,     0,   260,   261,     0,     0,   254,     0,
       0,   183,   184,     0,     0,     0,     0,   206,   207,   208,
     209,   210,   211,     0,   213,   214,     0,   216,   217,   180,
     220,   221,   218,   219,     0,   223,   228,     0,     0,     0,
     227,     0,     0,   139,     0,   144,   145,   229,   164,   230,
       0,   165,   146,   147,   239,   242,   245,   248,   150,   148,
     149,     0,     0,   151,   236,   238,   237,   156,     0,     0,
     159,     0,     0,   161,     0,     0,   423,    35,   425,    37,
     172,   170,     0,     0,   299,     0,     0,   305,   331,   337,
       7,   361,     0,     0,   412,     0,   410,     0,   393,   391,
     392,     0,     0,     0,     0,   373,   375,   404,   370,   273,
     275,   279,   279,     0,     0,   380,   382,    64,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       6,    80,     0,    85,     0,   283,     0,     7,     0,     0,
       0,     0,     0,     0,     0,   203,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   303,   308,   309,     0,     0,     0,   355,     0,
       0,     0,     0,     0,   389,     0,   396,   398,   399,   279,
     279,   371,     0,     0,    52,    54,     0,   123,   124,   120,
     126,    83,    76,    77,   128,     0,     0,     0,     0,     0,
     310,     0,     4,   352,   251,   252,   253,   262,   263,   264,
       0,   185,   186,   162,     0,   212,   215,   222,   135,   136,
     138,     0,   225,   226,   140,     0,   231,   232,     0,   234,
       0,   157,   256,     0,   158,   258,     0,   160,   181,   424,
     426,   335,   338,   329,   364,   414,     0,     0,   413,     0,
       0,     0,     0,     0,     0,   274,   276,    65,     0,     0,
       0,     0,     0,     0,    81,   313,   314,     0,   311,   324,
     348,   347,   346,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   107,     0,   362,   418,     0,   415,     0,     0,
       0,   401,   400,   374,   376,   372,    84,    75,   115,   116,
     114,     0,     0,     0,   288,     0,     0,   319,   265,     0,
     137,   141,   233,   235,   255,   257,   336,     4,   368,     7,
     356,     0,     0,     0,   394,   405,     0,   315,   316,     7,
     312,   325,     7,     0,   369,   365,   363,     0,     0,     0,
       0,     0,   113,     4,   320,   163,     7,   358,   359,   357,
     419,     0,   416,     0,   402,   291,   290,   289,     0,   366,
       0,     0,   323,   322,   326,   364,   420,   417,   327,   321,
     367
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -710,  -710,   -68,  -710,  -710,   269,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,   831,  -228,  -710,  -710,  -197,   159,  -710,
     832,     5,  -710,  -710,   608,  -274,    95,  -710,   488,   -31,
      -2,  -710,     0,     2,   381,  -710,  -710,   265,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,   340,  -710,   336,  -710,
     -48,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,    93,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,  -710,
    -710,  -710,  -710,  -710,  -710,  -710,  -106,  -710,  -710,  -710,
    -709,  -710,  -710,  -710,   499,  -710,  -710,   170,   489,  -710,
    -710,  -710,  -710,  -710,   -62,  -710,   -19,  -710,  -710
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   249,   608,    60,   169,   170,   529,   530,
     185,   406,    61,    62,   409,    63,    64,   417,   162,   163,
      65,   219,   532,   531,   454,   455,   220,   165,   203,   166,
      86,   190,   167,   168,   257,   258,   435,   436,    68,   431,
     754,   959,   987,   614,    69,   358,   359,   362,   363,   897,
     898,    70,    81,   616,   962,   988,   994,   937,   999,    71,
     177,   553,   369,   709,   911,   797,   912,    72,   178,   556,
      73,    82,   757,   902,    74,    83,   442,    75,   371,   710,
     874,   967,   979,    76,   372,   950,   914,   976,   995,   965,
     727,   884,   728,   198,   199,   205,   381,   564,   384,   722,
     723,   881,   955,   385,   572,   184,   212,   697,   699
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   457,    67,   204,   407,   407,   382,    87,    88,   414,
     415,    77,    79,   806,   807,   263,   164,   376,   216,   217,
     377,   180,   568,   181,   182,   569,   992,     1,     2,   179,
     900,   351,   187,   206,   400,   191,   193,   195,   246,   266,
     267,   211,   211,   211,   418,   419,   440,   234,    89,   235,
     231,   985,    92,   200,    84,    89,   993,    85,   901,    92,
     582,   351,   211,   334,   335,   336,   337,   338,   339,   407,
     986,   173,   441,   334,   335,   336,   337,   338,   339,   174,
     340,   340,   256,    66,   831,    67,   669,   657,   670,   334,
     335,   336,   337,   338,   339,   250,   251,   334,   335,   336,
     337,   338,   339,   340,   270,    78,    80,   252,   520,   176,
     370,   334,   335,   336,   337,   338,   339,   218,   383,   343,
     344,   354,   355,   345,   346,   347,   348,   349,   350,   351,
     516,   230,   518,   183,   343,   344,   223,   224,   345,   346,
     347,   348,   349,   350,   351,    52,    53,    54,   340,   352,
     353,   354,   355,   340,   977,   658,   188,   189,   340,   978,
     408,   408,   340,   520,   239,   331,   333,   687,   340,   688,
     394,   395,   922,   685,   172,   925,   378,   175,    66,   247,
      67,   570,   368,   340,   340,   595,   186,   248,   603,   380,
     192,   194,   340,   253,   340,   210,   225,   340,   340,   610,
     611,   659,   656,   201,   202,   681,   340,   236,   237,   238,
     201,   202,   397,   423,   399,   254,   245,   352,   353,   354,
     355,   340,   226,   227,   228,   408,   714,   240,   715,   229,
     635,   340,   352,   353,   354,   355,   660,   255,   259,   334,
     335,   336,   337,   338,   339,   340,   340,   241,   421,   340,
     839,   667,   840,   450,   451,   340,   682,   242,   429,   340,
     672,   340,   984,   434,   854,   340,   855,   439,   689,   470,
     857,   243,   858,   445,   446,   340,   447,   211,   211,   690,
     673,   691,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   211,   471,   472,   473,   474,   475,   477,
     693,   244,   694,   511,   558,   483,   484,   485,   487,   488,
     340,   490,   261,   492,   340,   859,   405,   860,   374,   520,
     332,   879,   411,   413,   340,   340,   340,   211,   340,   980,
     364,   981,   692,   695,   340,   740,   367,   340,   862,   625,
     863,   626,   340,   379,   742,   426,   427,   428,   262,   888,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   340,    78,   340,   340,   204,   674,   398,   675,   676,
     340,   458,    66,    80,    67,   677,   340,   403,   559,   340,
     340,   678,   340,   562,   679,   680,    89,   683,   340,   264,
      92,   936,   340,   684,   577,   578,   340,   837,   265,   340,
     340,   861,   268,   422,   864,   867,   865,   589,   866,   590,
     349,   350,   351,   430,   934,   784,   935,   433,   786,   596,
     597,   345,   346,   347,   348,   349,   350,   351,   605,   607,
     340,   449,   340,   340,   340,   868,   340,   878,   938,   941,
     343,   344,   196,   197,   345,   346,   347,   348,   349,   350,
     351,   356,   357,   269,   478,   479,   480,   481,   482,   350,
     351,   260,   340,   271,   489,   272,   491,   944,   493,   494,
     496,   498,   500,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   512,   340,   273,   515,   340,   517,   945,   519,
     416,   954,   274,   522,   523,   524,   525,   526,   527,   528,
     352,   353,   354,   355,   592,   388,   346,   594,   348,   349,
     350,   351,   360,   361,   340,   352,   353,   354,   355,   996,
     554,   452,   453,   555,   829,   565,   566,   696,   698,   575,
     576,   585,   586,   275,   561,   276,   700,   701,   352,   353,
     354,   355,   844,   393,   341,   342,   612,   613,   352,   353,
     354,   355,   725,   726,   365,   366,   795,   796,   895,   896,
     588,   348,   349,   350,   351,   713,   915,   916,   277,   593,
     278,   720,   721,   279,   280,   724,   346,   347,   348,   349,
     350,   351,   604,   606,   281,   282,   343,   344,   283,   737,
     345,   346,   347,   348,   349,   350,   351,   284,   285,   352,
     353,   354,   355,   286,   747,   748,   749,   287,    66,   288,
      67,   289,   290,   291,   751,   425,   292,   293,   294,   295,
     434,   756,   296,   758,   297,   298,   759,   760,   761,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   767,   768,
     308,   770,   798,   309,   396,   443,   444,   310,   771,   311,
     312,   772,   352,   353,   354,   355,   313,   401,   314,   773,
     315,   316,   774,   775,   776,   317,   777,   778,   318,   352,
     353,   354,   355,   319,   438,   780,  -353,   320,   321,   322,
     351,   323,   552,   324,   352,   353,   354,   355,   402,   832,
     743,   325,   343,   344,   326,   327,   345,   346,   347,   348,
     349,   350,   351,   328,   329,   752,   753,   330,   373,   375,
      66,   964,    67,   386,   387,   391,   392,   799,   557,   817,
     818,   410,   718,   424,   432,   719,   437,   343,   344,   513,
     769,   345,   346,   347,   348,   349,   350,   351,   814,   815,
     514,   544,   545,   211,   211,   547,   546,   548,   571,   822,
     823,   549,   550,   551,   560,   567,   598,    66,   708,    67,
     599,   600,   601,   609,   615,   618,   627,   573,   574,   633,
     619,   343,   579,   580,   433,   345,   346,   347,   348,   349,
     350,   351,   620,   624,   628,   762,   764,   869,   870,   629,
     352,   353,   354,   355,   630,   634,   711,   631,   632,   649,
     368,   686,   729,   730,   735,   876,   731,   732,   738,   736,
     880,   739,   765,   766,   453,   801,   789,   790,   791,   792,
     793,   794,   809,   779,   810,   352,   353,   354,   355,   811,
     824,   830,   872,   893,   838,   843,   899,   873,    -4,   877,
     781,   782,   885,   946,   947,   886,   890,   783,   891,   904,
     785,   892,   913,   787,   788,   919,   905,   923,   924,   932,
     933,   949,   951,   907,   953,   908,   957,   956,   958,   352,
     353,   354,   355,  -339,   802,   998,   803,   750,   232,   233,
     755,   966,   918,   456,   583,   707,   704,   960,   871,  1000,
     804,   973,   581,   971,   974,   591,     0,     0,     0,   819,
     820,   821,     0,     0,     0,     0,     0,     0,   989,     0,
       0,    66,    66,    67,    67,     0,     0,     0,   948,     0,
       0,     0,     0,     0,   894,   702,   703,     0,   705,   706,
     343,   344,     0,     0,   345,   346,   347,   348,   349,   350,
     351,   961,     0,     0,   963,     0,     0,     0,     0,    66,
       0,    67,     0,     0,   367,     0,     0,   969,   970,    66,
       0,    67,    66,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,   563,     0,   887,    66,     0,    67,   746,
       0,     0,     0,     0,     0,   343,   344,     0,   991,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,   903,
     343,   344,     0,     0,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,   906,     0,     0,     0,     0,     0,
       0,     0,   909,     0,     0,   910,     0,     0,   352,   353,
     354,   355,     0,     0,   642,     0,   643,     0,   920,     0,
       0,     0,     0,     0,     0,     0,     0,   926,   927,   928,
     929,   930,     0,     0,     0,   343,   344,     0,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,   343,
     344,     0,     0,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,   352,   353,   354,   355,     0,     0,     0,
       0,     0,    89,    90,    91,     0,    92,    93,   352,   353,
     354,   355,     0,     0,   645,     0,   646,     0,     0,     0,
     968,     0,   812,   813,     0,   972,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     990,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   352,   353,   354,   355,     0,     0,   663,
       0,   664,     0,   101,     0,     0,   102,   352,   353,   354,
     355,   213,     0,   827,     0,   828,     0,     0,     0,   214,
       0,     0,     0,   103,   104,     0,     0,   105,     0,   106,
     882,   883,   215,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,     0,    89,
      90,    91,   161,    92,    93,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,   102,     0,   343,   344,     0,   207,   345,
     346,   347,   348,   349,   350,   351,   208,     0,     0,     0,
     103,   104,     0,     0,   105,     0,   106,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,   159,   160,     0,    89,    90,    91,   161,
      92,    93,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,     0,   521,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   343,   344,
     102,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   448,     0,     0,     0,   103,   104,     0,
       0,   105,     0,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,     0,    89,    90,    91,   161,    92,    93,     0,
     209,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,   850,     0,   851,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   343,   344,   102,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,   105,     0,
     106,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,     0,
      89,    90,    91,   161,    92,    93,     0,   209,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,     0,     0,
       0,   389,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   343,   344,   102,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,   420,    89,    90,    91,     0,    92,    93,     0,     0,
     352,   353,   354,   355,     0,     0,     0,     0,   390,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   343,   344,   102,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,   105,     0,   106,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,   161,   476,    89,    90,    91,     0,    92,    93,
       0,     0,   352,   353,   354,   355,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   343,   344,   102,     0,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,   105,
       0,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,     0,     0,   161,   486,    89,    90,    91,     0,
      92,    93,     0,   221,   352,   353,   354,   355,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   343,   344,
     102,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
       0,   105,     0,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,     0,    89,    90,    91,   161,    92,    93,     0,
       0,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,     0,     0,   621,     0,     0,     0,    94,    95,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   343,   344,   102,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,     0,   105,     0,
     106,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,     0,
      89,    90,    91,   161,    92,    93,     0,   412,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,     0,     0,
       0,   622,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   343,   344,   102,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,     0,    89,    90,    91,
     161,    92,    93,     0,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,     0,     0,     0,   623,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,     0,     0,
      91,     0,     0,    93,     0,     0,     0,     0,   101,   343,
     344,   102,     0,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,    95,     0,     0,     0,   103,   104,
       0,     0,   105,     0,   106,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   105,     0,   106,    91,   161,     0,    93,
       0,     0,     0,     0,     0,     0,     0,   352,   353,   354,
     355,     0,     0,     0,     0,   636,     0,   125,   126,   127,
      95,     0,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,     0,     0,   144,   145,   146,     0,
       0,   149,     0,     0,   152,     0,   153,   154,     0,   156,
       0,   158,     0,    91,     0,     0,    93,     0,   171,   495,
     343,   344,     0,     0,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,     0,     0,     0,   131,
     132,   133,     0,   135,    95,   137,   138,   139,     0,     0,
       0,     0,   144,   145,   146,     0,     0,   149,     0,     0,
     152,     0,   153,   154,     0,   156,   105,   158,   106,     0,
      91,     0,     0,    93,   171,   497,     0,     0,   352,   353,
     354,   355,     0,     0,     0,     0,   654,     0,     0,     0,
     125,   126,   127,     0,    95,     0,   131,   132,   133,     0,
     135,     0,   137,   138,   139,     0,     0,     0,     0,   144,
     145,   146,     0,   105,   149,   106,     0,   152,     0,   153,
     154,     0,   156,     0,   158,     0,     0,     0,     0,     0,
      91,   171,   499,    93,     0,     0,     0,   125,   126,   127,
       0,     0,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,    95,   587,   144,   145,   146,     0,
       0,   149,     0,   105,   152,   106,   153,   154,     0,   156,
       0,   158,     0,     0,     0,     0,     0,     0,   171,   501,
      91,     0,     0,    93,     0,     0,     0,   125,   126,   127,
       0,     0,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,    95,     0,   144,   145,   146,     0,
       0,   149,     0,     0,   152,   763,   153,   154,     0,   156,
       0,   158,     0,   105,     0,   106,     0,    91,   171,     0,
      93,     0,     0,     0,   343,   344,     0,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,   125,   126,   127,
       0,    95,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,     0,     0,   144,   145,   146,     0,
       0,   149,     0,   105,   152,   106,   153,   154,     0,   156,
       0,   158,     0,     0,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
       0,     0,     0,   131,   132,   133,     0,   135,     0,   137,
     138,   139,     0,     0,     0,     0,   144,   145,   146,     0,
     105,   149,   106,     0,   152,     0,   153,   154,     0,   156,
       0,   158,   352,   353,   354,   355,     0,     0,   171,     0,
     661,     0,     0,     0,   125,   126,   127,     0,     0,     0,
     131,   132,   133,     0,   135,     0,   137,   138,   139,     0,
       0,     0,     0,   144,   145,   146,     0,     0,   149,     0,
       0,   152,     0,   153,   154,     0,   156,     0,   158,     1,
       2,     3,     0,     0,     4,   717,     0,     0,     5,     0,
       6,     0,     7,     8,     9,    10,    11,  -294,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,     0,     0,     0,     0,    23,     0,     0,    24,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
    -107,  -107,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,  -107,     0,    49,     0,    50,    51,   343,   344,
       0,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     0,
       4,     0,    56,     0,     5,    57,     6,     0,     7,     8,
       9,    10,    11,  -294,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,     0,     0,     0,
       0,    23,    -7,    -7,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     0,     0,     4,     0,    56,     0,
       5,    57,     6,     0,     7,     8,     9,    10,    11,  -294,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    -7,     0,
      24,     0,     0,     0,    -7,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,     0,     0,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,     0,     0,    49,     0,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     0,     4,     0,    56,     0,     5,    57,     6,     0,
       7,     8,     9,    10,    11,  -294,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    -7,
       0,     0,     0,    23,    -7,     0,    24,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,   343,
     344,    31,    32,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    39,    40,    41,     0,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,   343,   344,     0,     0,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,   343,
     344,     0,    55,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,    57,     0,     0,     0,   352,   353,   354,
     355,     0,   343,   344,     0,   662,   345,   346,   347,   348,
     349,   350,   351,   343,   344,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   343,   344,     0,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,   355,     0,   343,
     344,     0,   712,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,   352,   353,   354,
     355,     0,   343,   344,     0,   733,   345,   346,   347,   348,
     349,   350,   351,   343,   344,     0,     0,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,     0,     0,     0,   734,     0,
       0,   352,   353,   354,   355,     0,     0,     0,     0,   741,
       0,     0,   352,   353,   354,   355,     0,   343,   344,     0,
     744,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   353,   354,
     355,     0,   343,   344,     0,   745,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,     0,     0,     0,   800,     0,
       0,   352,   353,   354,   355,     0,   343,   344,     0,   805,
     345,   346,   347,   348,   349,   350,   351,   343,   344,     0,
       0,   345,   346,   347,   348,   349,   350,   351,   343,   344,
       0,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,   352,   353,   354,   355,     0,
     343,   344,     0,   816,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,     0,   343,   344,     0,   889,   345,
     346,   347,   348,   349,   350,   351,   343,   344,     0,     0,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,   355,     0,     0,
       0,     0,   939,     0,     0,   352,   353,   354,   355,     0,
       0,     0,     0,   952,     0,     0,   352,   353,   354,   355,
       0,   343,   344,     0,   983,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355,   343,   344,   602,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   353,   354,   355,     0,     0,   617,
       0,     0,     0,     0,   352,   353,   354,   355,   343,   344,
     637,     0,   345,   346,   347,   348,   349,   350,   351,   343,
     344,     0,     0,   345,   346,   347,   348,   349,   350,   351,
     343,   344,     0,     0,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     353,   354,   355,   343,   344,   638,     0,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,   343,   344,   639,     0,   345,   346,
     347,   348,   349,   350,   351,   343,   344,     0,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,   640,     0,     0,     0,     0,   352,   353,   354,
     355,     0,     0,   641,     0,     0,     0,     0,   352,   353,
     354,   355,   343,   344,   644,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
       0,   352,   353,   354,   355,   343,   344,   647,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,     0,   648,     0,
       0,     0,     0,   352,   353,   354,   355,   343,   344,   650,
       0,   345,   346,   347,   348,   349,   350,   351,   343,   344,
       0,     0,   345,   346,   347,   348,   349,   350,   351,   343,
     344,     0,     0,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,   353,   354,   355,   343,   344,   651,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   353,   354,   355,   343,   344,   652,
       0,   345,   346,   347,   348,   349,   350,   351,   343,   344,
       0,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,   352,   353,   354,   355,     0,
       0,   653,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,   655,     0,     0,     0,     0,   352,   353,   354,
     355,   343,   344,   665,     0,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,   353,   354,   355,   343,   344,   666,     0,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,     0,     0,     0,     0,   352,   353,   354,   355,     0,
       0,   668,     0,     0,     0,     0,   352,   353,   354,   355,
     343,   344,   671,     0,   345,   346,   347,   348,   349,   350,
     351,   343,   344,     0,     0,   345,   346,   347,   348,   349,
     350,   351,   343,   344,     0,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,   352,
     353,   354,   355,   343,   344,   716,     0,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,   355,   343,   344,
     808,     0,   345,   346,   347,   348,   349,   350,   351,   343,
     344,     0,     0,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,     0,   825,     0,     0,     0,     0,   352,
     353,   354,   355,     0,     0,   826,     0,     0,     0,     0,
     352,   353,   354,   355,   343,   344,   833,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,   352,   353,   354,   355,   343,   344,   834,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   353,   354,   355,
       0,     0,   835,     0,     0,     0,     0,   352,   353,   354,
     355,   343,   344,   836,     0,   345,   346,   347,   348,   349,
     350,   351,   343,   344,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   343,   344,     0,     0,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,     0,     0,
       0,     0,   352,   353,   354,   355,   343,   344,   841,     0,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,     0,     0,   352,   353,   354,   355,   343,   344,   842,
       0,   345,   346,   347,   348,   349,   350,   351,   343,   344,
       0,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     353,   354,   355,     0,     0,   845,     0,     0,     0,     0,
     352,   353,   354,   355,     0,     0,   846,     0,     0,     0,
       0,   352,   353,   354,   355,   343,   344,   847,     0,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,   355,   343,   344,
     848,     0,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,     0,     0,   352,   353,   354,   355,     0,
       0,   849,     0,     0,     0,     0,   352,   353,   354,   355,
     343,   344,   852,     0,   345,   346,   347,   348,   349,   350,
     351,   343,   344,     0,     0,   345,   346,   347,   348,   349,
     350,   351,   343,   344,     0,     0,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,   353,   354,   355,   343,   344,   853,
       0,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   353,   354,   355,
     343,   344,   856,     0,   345,   346,   347,   348,   349,   350,
     351,   343,   344,     0,     0,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,     0,   875,     0,     0,     0,     0,   352,
     353,   354,   355,     0,     0,   917,     0,     0,     0,     0,
     352,   353,   354,   355,   343,   344,   921,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,   353,   354,   355,   343,
     344,   931,     0,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355,     0,     0,   940,     0,     0,     0,     0,   352,
     353,   354,   355,   343,   344,   942,     0,   345,   346,   347,
     348,   349,   350,   351,   343,   344,     0,     0,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,     0,   943,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   353,   354,
     355,     0,     0,   975,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   352,   353,   354,   355,     0,     0,   982,     0,     0,
       0,     0,   352,   353,   354,   355,     0,     0,   997
};

static const yytype_int16 yycheck[] =
{
       0,   275,     0,    34,    10,    10,    55,     9,    10,   237,
     238,    69,    69,   722,   723,    83,    11,     4,    37,    38,
       7,    55,     4,    57,    58,     7,    12,     4,     5,    24,
      14,    70,    27,    35,     9,    30,    31,    32,    57,    33,
      34,    36,    37,    38,   241,   242,    16,    47,     3,    47,
      45,    23,     7,     8,     4,     3,    42,     7,    42,     7,
       8,    70,    57,    64,    65,    66,    67,    68,    69,    10,
      42,   163,    42,    64,    65,    66,    67,    68,    69,   163,
     159,   159,    77,    83,    10,    83,   164,   166,   166,    64,
      65,    66,    67,    68,    69,    85,    86,    64,    65,    66,
      67,    68,    69,   159,    99,   163,   163,    97,   164,    26,
     178,    64,    65,    66,    67,    68,    69,    81,   167,    60,
      61,   160,   161,    64,    65,    66,    67,    68,    69,    70,
     327,    88,   329,   167,    60,    61,    41,    42,    64,    65,
      66,    67,    68,    69,    70,   122,   123,   124,   159,   158,
     159,   160,   161,   159,    42,   166,     4,     5,   159,    47,
     166,   166,   159,   164,   103,   160,   161,   164,   159,   166,
     201,   202,   881,   164,    15,   884,   163,    18,   178,     0,
     178,   163,   177,   159,   159,   413,    27,    42,   164,   184,
      31,    32,   159,    69,   159,    36,    56,   159,   159,   427,
     428,   166,   164,   158,   159,   166,   159,    48,    49,    50,
     158,   159,   207,   166,   209,    69,    57,   158,   159,   160,
     161,   159,    82,    83,    84,   166,   164,   163,   166,    89,
     458,   159,   158,   159,   160,   161,   164,    22,    79,    64,
      65,    66,    67,    68,    69,   159,   159,   163,   243,   159,
     164,   164,   166,   272,   273,   159,   166,   163,   253,   159,
     164,   159,   971,   258,   164,   159,   166,   262,   166,   288,
     164,   163,   166,   268,   269,   159,   271,   272,   273,   164,
     164,   166,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     164,   163,   166,   322,   372,   300,   301,   302,   303,   304,
     159,   306,     4,   308,   159,   164,   221,   166,    55,   164,
     161,   166,   227,   228,   159,   159,   159,   322,   159,   164,
     171,   166,   166,   166,   159,   166,   177,   159,   164,   164,
     166,   166,   159,   184,   166,   250,   251,   252,   163,   166,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   159,   163,   159,   159,   396,   164,   208,   164,   164,
     159,   276,   372,   163,   372,   164,   159,   218,   373,   159,
     159,   164,   159,   378,   164,   164,     3,   164,   159,   163,
       7,    11,   159,   164,   389,   390,   159,   164,   163,   159,
     159,   164,   163,   244,   164,   164,   164,   402,   166,   404,
      68,    69,    70,   254,   164,   689,   166,   258,   692,   414,
     415,    64,    65,    66,    67,    68,    69,    70,   423,   424,
     159,   272,   159,   159,   159,   164,   159,   164,   164,   164,
      60,    61,     4,     5,    64,    65,    66,    67,    68,    69,
      70,     4,     5,   163,   295,   296,   297,   298,   299,    69,
      70,    80,   159,   163,   305,   163,   307,   164,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   159,   163,   326,   159,   328,   164,   330,
       5,   164,   163,   334,   335,   336,   337,   338,   339,   340,
     158,   159,   160,   161,   409,   166,    65,   412,    67,    68,
      69,    70,     4,     5,   159,   158,   159,   160,   161,   164,
      39,     4,     5,    42,   752,   165,   166,   529,   530,     4,
       5,    79,    80,   163,   375,   163,   531,   532,   158,   159,
     160,   161,   770,   166,    18,    19,     4,     5,   158,   159,
     160,   161,     4,     5,   173,   174,    37,    38,     4,     5,
     401,    67,    68,    69,    70,   560,    57,    58,   163,   410,
     163,   566,   567,   163,   163,   570,    65,    66,    67,    68,
      69,    70,   423,   424,   163,   163,    60,    61,   163,   584,
      64,    65,    66,    67,    68,    69,    70,   163,   163,   158,
     159,   160,   161,   163,   599,   600,   601,   163,   608,   163,
     608,   163,   163,   163,   609,    41,   163,   163,   163,   163,
     615,   616,   163,   618,   163,   163,   621,   622,   623,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   633,   634,
     163,   636,   710,   163,   166,   264,   265,   163,   643,   163,
     163,   646,   158,   159,   160,   161,   163,   166,   163,   654,
     163,   163,   657,   658,   659,   163,   661,   662,   163,   158,
     159,   160,   161,   163,    69,   670,    44,   163,   163,   163,
      70,   163,    41,   163,   158,   159,   160,   161,   166,   757,
     595,   163,    60,    61,   163,   163,    64,    65,    66,    67,
      68,    69,    70,   163,   163,   610,   611,   163,   163,   163,
     710,    44,   710,   163,   163,   163,   163,   712,    44,   738,
     739,   166,   563,   166,   164,   566,   164,    60,    61,   164,
     635,    64,    65,    66,    67,    68,    69,    70,   733,   734,
     164,   163,   163,   738,   739,   163,   166,   163,     8,   744,
     745,   166,   164,   164,   163,   163,   163,   757,    41,   757,
     166,   166,   166,   166,   166,   163,   166,   386,   387,   166,
     164,    60,   391,   392,   615,    64,    65,    66,    67,    68,
      69,    70,   164,   164,   164,   626,   627,   789,   790,   163,
     158,   159,   160,   161,   163,   166,    47,   164,   164,   164,
     795,   164,   164,   164,   164,   800,   163,   163,    78,   164,
     805,    78,   164,   164,     5,    55,   166,   166,   164,   164,
     164,   164,   163,   664,   163,   158,   159,   160,   161,   166,
     164,   163,    41,   828,   164,   164,   831,    36,    41,   163,
     681,   682,   164,   911,   912,   164,    69,   688,    69,   844,
     691,    69,    46,   694,   695,    55,   851,   164,   164,   163,
     163,    45,   163,   858,   163,   860,   164,    69,   164,   158,
     159,   160,   161,    36,   715,     4,   717,   608,    47,    47,
     615,   949,   877,   275,   396,   549,   546,   935,   795,   995,
     720,   959,   393,   955,   962,   406,    -1,    -1,    -1,   740,
     741,   742,    -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,
      -1,   911,   912,   911,   912,    -1,    -1,    -1,   913,    -1,
      -1,    -1,    -1,    -1,   829,   544,   545,    -1,   547,   548,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,   936,    -1,    -1,   939,    -1,    -1,    -1,    -1,   949,
      -1,   949,    -1,    -1,   795,    -1,    -1,   952,   953,   959,
      -1,   959,   962,    -1,   962,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,   816,   976,    -1,   976,   598,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,   983,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,   840,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,   855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   863,    -1,    -1,   866,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,   166,    -1,   879,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   888,   889,   890,
     891,   892,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,   158,   159,
     160,   161,    -1,    -1,   164,    -1,   166,    -1,    -1,    -1,
     951,    -1,   731,   732,    -1,   956,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,   158,   159,   160,   161,    -1,    -1,   164,
      -1,   166,    -1,    74,    -1,    -1,    77,   158,   159,   160,
     161,    82,    -1,   164,    -1,   166,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
     809,   810,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,     3,
       4,     5,   163,     7,     8,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    77,    -1,    60,    61,    -1,    82,    64,
      65,    66,    67,    68,    69,    70,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,     3,     4,     5,   163,
       7,     8,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,
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
     147,   148,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,     3,     4,     5,   163,     7,     8,    -1,
     167,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,   166,    -1,    -1,    -1,    28,    29,
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
       3,     4,     5,   163,     7,     8,    -1,   167,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
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
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
     163,   164,     3,     4,     5,    -1,     7,     8,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    60,    61,    77,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,   100,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,   163,   164,     3,     4,     5,    -1,     7,     8,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
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
      -1,    -1,    -1,    -1,   163,   164,     3,     4,     5,    -1,
       7,     8,    -1,    10,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     147,   148,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,     3,     4,     5,   163,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       3,     4,     5,   163,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
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
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,     3,     4,     5,
     163,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    74,    60,
      61,    77,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,    98,    -1,   100,     5,   163,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   122,   123,   124,
      29,    -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
      -1,   146,    -1,    -1,   149,    -1,   151,   152,    -1,   154,
      -1,   156,    -1,     5,    -1,    -1,     8,    -1,   163,   164,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,   128,
     129,   130,    -1,   132,    29,   134,   135,   136,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,    -1,   146,    -1,    -1,
     149,    -1,   151,   152,    -1,   154,    98,   156,   100,    -1,
       5,    -1,    -1,     8,   163,   164,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     122,   123,   124,    -1,    29,    -1,   128,   129,   130,    -1,
     132,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,    -1,    98,   146,   100,    -1,   149,    -1,   151,
     152,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,    -1,
       5,   163,   164,     8,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    29,    90,   141,   142,   143,    -1,
      -1,   146,    -1,    98,   149,   100,   151,   152,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
       5,    -1,    -1,     8,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    29,    -1,   141,   142,   143,    -1,
      -1,   146,    -1,    -1,   149,    90,   151,   152,    -1,   154,
      -1,   156,    -1,    98,    -1,   100,    -1,     5,   163,    -1,
       8,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,   122,   123,   124,
      -1,    29,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
      -1,   146,    -1,    98,   149,   100,   151,   152,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
      98,   146,   100,    -1,   149,    -1,   151,   152,    -1,   154,
      -1,   156,   158,   159,   160,   161,    -1,    -1,   163,    -1,
     166,    -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,
     128,   129,   130,    -1,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,   141,   142,   143,    -1,    -1,   146,    -1,
      -1,   149,    -1,   151,   152,    -1,   154,    -1,   156,     4,
       5,     6,    -1,    -1,     9,   163,    -1,    -1,    13,    -1,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    -1,
      -1,    96,    97,    -1,    99,    -1,   101,   102,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
       9,    -1,   147,    -1,    13,   150,    15,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    87,    88,
      89,    -1,    91,    92,    93,    -1,    -1,    96,    -1,    -1,
      99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,     9,    -1,   147,    -1,
      13,   150,    15,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    41,    -1,
      43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    87,    88,    89,    -1,    91,    92,
      93,    -1,    -1,    96,    -1,    -1,    99,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,   147,    -1,    13,   150,    15,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    -1,    60,
      61,    58,    59,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      87,    88,    89,    -1,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    99,    -1,   101,   102,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,    60,
      61,    -1,   129,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    60,    61,    -1,   166,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    60,
      61,    -1,   166,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    60,    61,    -1,   166,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,   158,   159,   160,   161,    -1,    60,    61,    -1,
     166,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    60,    61,    -1,   166,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,
      -1,   158,   159,   160,   161,    -1,    60,    61,    -1,   166,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      60,    61,    -1,   166,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    60,    61,    -1,   166,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,   166,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,   158,   159,   160,   161,
      -1,    60,    61,    -1,   166,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    60,    61,   164,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,    61,
     164,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    60,    61,   164,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    60,    61,   164,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    60,    61,   164,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    60,    61,   164,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      60,    61,   164,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    60,    61,   164,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,    61,
     164,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    60,    61,   164,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    60,    61,   164,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    60,    61,   164,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    60,    61,   164,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,    61,
     164,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      60,    61,   164,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    60,    61,   164,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      60,    61,   164,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    60,    61,   164,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    60,
      61,   164,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    60,    61,   164,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164
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
     175,   163,   186,   163,   163,   186,    26,   228,   236,   189,
      55,    57,    58,   167,   273,   178,   186,   189,     4,     5,
     199,   189,   186,   189,   186,   189,     4,     5,   261,   262,
       8,   158,   159,   196,   197,   263,   198,    82,    90,   167,
     186,   189,   274,    82,    90,   103,   274,   274,    81,   189,
     194,    10,    50,   194,   194,    56,    82,    83,    84,    89,
      88,   189,   181,   188,   200,   201,   186,   186,   186,   103,
     163,   163,   163,   163,   163,   186,   274,     0,    42,   171,
      85,    86,    97,    69,    69,    22,   189,   202,   203,   186,
     202,     4,   163,   170,   163,   163,    33,    34,   163,   163,
     189,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   189,   186,   189,    64,    65,    66,    67,    68,    69,
     159,    18,    19,    60,    61,    64,    65,    66,    67,    68,
      69,    70,   158,   159,   160,   161,     4,     5,   213,   214,
       4,     5,   215,   216,   186,   202,   202,   186,   189,   230,
     170,   246,   252,   163,    55,   163,     4,     7,   163,   186,
     189,   264,    55,   167,   266,   271,   163,   163,   166,   166,
     166,   163,   163,   166,   197,   197,   166,   189,   186,   189,
       9,   166,   166,   186,   166,   194,   179,    10,   166,   182,
     166,   194,    10,   194,   182,   182,     5,   185,   185,   185,
     164,   189,   186,   166,   166,    41,   194,   194,   194,   189,
     186,   207,   164,   186,   189,   204,   205,   164,    69,   189,
      16,    42,   244,   202,   202,   189,   189,   189,    90,   186,
     274,   274,     4,     5,   192,   193,   192,   193,   194,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     274,   189,   189,   189,   189,   189,   164,   189,   186,   186,
     186,   186,   186,   189,   189,   189,   164,   189,   189,   186,
     189,   186,   189,   186,   186,   164,   186,   164,   186,   164,
     186,   164,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   274,   186,   164,   164,   186,   185,   186,   185,   186,
     164,   164,   186,   186,   186,   186,   186,   186,   186,   176,
     177,   191,   190,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   163,   163,   166,   163,   163,   166,
     164,   164,    41,   229,    39,    42,   237,    44,   170,   189,
     163,   186,   189,    48,   265,   165,   166,   163,     4,     7,
     163,     8,   272,   202,   202,     4,     5,   189,   189,   202,
     202,   262,     8,   196,   166,    79,    80,    90,   186,   189,
     189,   266,   194,   186,   194,   182,   189,   189,   163,   166,
     166,   166,   164,   164,   186,   189,   186,   189,   172,   166,
     182,   182,     4,     5,   211,   166,   221,   164,   163,   164,
     164,   166,   166,   166,   164,   164,   166,   166,   164,   163,
     163,   164,   164,   166,   166,   182,   166,   164,   164,   164,
     164,   164,   164,   166,   164,   164,   166,   164,   164,   164,
     164,   164,   164,   164,   166,   164,   164,   166,   166,   166,
     164,   166,   166,   164,   166,   164,   164,   164,   164,   164,
     166,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   166,   166,   164,   164,   164,   164,   164,   166,   166,
     164,   166,   166,   164,   166,   166,   198,   275,   198,   276,
     189,   189,   202,   202,   214,   202,   202,   216,    41,   231,
     247,    47,   166,   189,   164,   166,   164,   163,   186,   186,
     189,   189,   267,   268,   189,     4,     5,   258,   260,   164,
     164,   163,   163,   166,   166,   164,   164,   189,    78,    78,
     166,   166,   166,   194,   166,   166,   202,   189,   189,   189,
     173,   189,   194,   194,   208,   205,   189,   240,   189,   189,
     189,   189,   186,    90,   186,   164,   164,   189,   189,   194,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   186,
     189,   186,   186,   186,   193,   186,   193,   186,   186,   166,
     166,   164,   164,   164,   164,    37,    38,   233,   170,   189,
     166,    55,   186,   186,   265,   166,   258,   258,   164,   163,
     163,   166,   202,   202,   189,   189,   166,   274,   274,   186,
     186,   186,   189,   189,   164,   164,   164,   164,   166,   182,
     163,    10,   170,   164,   164,   164,   164,   164,   164,   164,
     166,   164,   164,   164,   182,   164,   164,   164,   164,   164,
     164,   166,   164,   164,   164,   166,   164,   164,   166,   164,
     166,   164,   164,   166,   164,   164,   166,   164,   164,   198,
     198,   230,    41,    36,   248,   164,   189,   163,   164,   166,
     189,   269,   202,   202,   259,   164,   164,   186,   166,   166,
      69,    69,    69,   189,   194,     4,     5,   217,   218,   189,
      14,    42,   241,   186,   189,   189,   186,   189,   189,   186,
     186,   232,   234,    46,   254,    57,    58,   164,   189,    55,
     186,   164,   258,   164,   164,   258,   186,   186,   186,   186,
     186,   164,   163,   163,   164,   166,    11,   225,   164,   166,
     164,   164,   164,   164,   164,   164,   170,   170,   189,    45,
     253,   163,   166,   163,   164,   270,    69,   164,   164,   209,
     218,   189,   222,   189,    44,   257,   170,   249,   186,   189,
     189,   272,   186,   170,   170,   164,   255,    42,    47,   250,
     164,   166,   164,   166,   258,    23,    42,   210,   223,   170,
     186,   189,    12,    42,   224,   256,   164,   164,     4,   226,
     254
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   168,   169,   170,   171,   172,   170,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   174,   173,   175,   173,   173,   173,
     173,   173,   173,   173,   176,   173,   177,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   178,   173,
     179,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   180,   180,   180,
     180,   180,   181,   181,   181,   181,   181,   181,   182,   182,
     183,   183,   183,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   186,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   188,   190,
     189,   191,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   192,   193,   194,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   196,   196,   196,   197,
     197,   198,   198,   199,   199,   199,   199,   200,   201,   203,
     202,   204,   204,   204,   205,   205,   207,   208,   209,   206,
     210,   210,   211,   211,   212,   212,   212,   212,   213,   213,
     214,   214,   214,   214,   215,   215,   216,   216,   216,   216,
     217,   217,   217,   218,   218,   218,   218,   220,   221,   222,
     223,   219,   224,   224,   225,   225,   226,   226,   228,   227,
     229,   229,   230,   230,   231,   232,   231,   233,   234,   233,
     236,   235,   237,   237,   239,   240,   238,   241,   241,   243,
     242,   244,   244,   246,   247,   248,   249,   245,   250,   250,
     252,   251,   253,   253,   254,   255,   256,   254,   257,   257,
     258,   259,   258,   260,   260,   260,   260,   261,   261,   262,
     262,   262,   262,   263,   263,   263,   263,   264,   264,   264,
     264,   264,   265,   265,   265,   267,   266,   268,   266,   269,
     266,   270,   266,   271,   266,   272,   272,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   274,   274,   275,   275,   276,   276
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     0,     5,     0,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     3,     1,     1,
       2,     2,     3,     3,     0,     5,     0,     5,     2,     1,
       2,     1,     2,     4,     4,     3,     4,     4,     0,     3,
       0,     4,     6,     2,     6,     2,     2,     2,     1,     2,
       1,     2,     2,     2,     5,     7,     3,     2,     3,     4,
       5,     3,     2,     4,     3,     8,     6,     6,     2,     2,
       5,     7,     4,     6,     8,     5,     2,     2,     2,     2,
       3,     2,     2,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     1,     1,     2,     1,     2,     0,     1,     1,
       2,     2,     3,    10,     8,     8,     8,     3,     1,     1,
       6,     4,     4,     6,     6,     4,     6,     1,     4,     1,
       1,     1,     1,     3,     3,     6,     6,     8,     6,     4,
       6,     8,     1,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     3,     1,     3,     4,     6,     6,     4,
       6,     4,     6,    10,     4,     4,     4,     3,     3,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       4,     6,     1,     4,     4,     6,     6,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     4,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     4,     6,     6,     6,     8,     1,     2,     2,     1,
       1,     1,     1,     4,     6,     4,     6,     4,     4,     0,
       2,     0,     1,     3,     1,     1,     0,     0,     0,    11,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     3,
       1,     1,     4,     4,     1,     3,     1,     1,     4,     4,
       0,     1,     3,     1,     1,     3,     3,     0,     0,     0,
       0,    14,     1,     1,     0,     2,     0,     1,     0,     7,
       1,     2,     1,     1,     0,     0,     5,     0,     0,     4,
       0,     4,     1,     1,     0,     0,     8,     1,     1,     0,
       4,     1,     4,     0,     0,     0,     0,    11,     1,     1,
       0,     5,     0,     2,     0,     0,     0,     7,     0,     1,
       1,     0,     4,     1,     4,     1,     4,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     2,     6,     0,     4,     0,     4,     0,
       6,     0,     9,     0,     3,     0,     1,     0,     2,     2,
       4,     1,     4,     6,     6,     7,    10,    12,     7,    10,
      12,     2,     1,     1,     3,     1,     3
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

    {add_command(cBREAK,NULL,NULL);if (!loop_nesting && !switch_nesting) error(ERROR,"break outside loop or switch");}

    break;

  case 20:

    {create_continue;if (!loop_nesting) error(ERROR,"continue outside loop");}

    break;

  case 22:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 23:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 24:

    {if (function_type==ftNONE) error(ERROR,"no use for 'local' outside functions");}

    break;

  case 26:

    {if (function_type==ftNONE) error(ERROR,"no use for 'static' outside functions");}

    break;

  case 30:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 31:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 32:

    {create_exception(TRUE);}

    break;

  case 33:

    {create_exception(FALSE);}

    break;

  case 34:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 35:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 36:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 37:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 38:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 39:

    {add_command(cCHECKOPEN,NULL,NULL);}

    break;

  case 40:

    {add_command(cCLOSE,NULL,NULL);}

    break;

  case 41:

    {add_command(cCHECKSEEK,NULL,NULL);}

    break;

  case 42:

    {add_command(cCOMPILE,NULL,NULL);}

    break;

  case 43:

    {create_execute(0);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 44:

    {create_execute(1);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 45:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}

    break;

  case 46:

    {create_colour(0);create_pps(cPOPSTREAM,0);}

    break;

  case 47:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}

    break;

  case 48:

    {tileol=FALSE;}

    break;

  case 50:

    {tileol=TRUE;}

    break;

  case 52:

    {add_command(cGCOLOUR,NULL,NULL);}

    break;

  case 53:

    {add_command(cGCOLOUR2,NULL,NULL);}

    break;

  case 54:

    {add_command(cGBACKCOLOUR,NULL,NULL);}

    break;

  case 55:

    {add_command(cGBACKCOLOUR2,NULL,NULL);}

    break;

  case 58:

    {create_restore("");}

    break;

  case 59:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 60:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;
	       add_command(cPOPSYMLIST,NULL,NULL);
               create_retval(ftNONE,function_type);
               add_command(cRET_FROM_FUN,NULL,NULL);
            } else {
               add_command(cRETURN,NULL,NULL);
            }}

    break;

  case 61:

    {if (switch_nesting) add_command(cPOP_SWITCH_VALUE,NULL,NULL); if (function_type==ftNONE) {error(ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_retval(ftNUMBER,function_type);add_command(cRET_FROM_FUN,NULL,NULL);}

    break;

  case 62:

    {if (switch_nesting) add_command(cPOP_SWITCH_VALUE,NULL,NULL); if (function_type==ftNONE) {error(ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_retval(ftSTRING,function_type);add_command(cRET_FROM_FUN,NULL,NULL);}

    break;

  case 64:

    {create_openwin(FALSE);}

    break;

  case 65:

    {create_openwin(TRUE);}

    break;

  case 66:

    {add_command(cMOVEORIGIN,NULL,NULL);}

    break;

  case 67:

    {add_command(cDOT,NULL,NULL);}

    break;

  case 68:

    {add_command(cDOT,NULL,NULL);putindrawmode(dmCLEAR);}

    break;

  case 69:

    {create_line(2);}

    break;

  case 70:

    {create_line(2);putindrawmode(dmCLEAR);}

    break;

  case 71:

    {create_line(1);}

    break;

  case 72:

    {create_line(1);}

    break;

  case 73:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 74:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 75:

    {add_command(cPUTBIT,NULL,NULL);}

    break;

  case 76:

    {create_pushstr("solid"); add_command(cPUTBIT,NULL,NULL);}

    break;

  case 77:

    {add_command(cPUTCHAR,NULL,NULL);}

    break;

  case 78:

    {create_line(-1);}

    break;

  case 79:

    {create_line(0);}

    break;

  case 80:

    {add_command(cCIRCLE,NULL,NULL);putindrawmode(0);}

    break;

  case 81:

    {add_command(cTRIANGLE,NULL,NULL);putindrawmode(0);}

    break;

  case 82:

    {add_command(cTEXT1,NULL,NULL);}

    break;

  case 83:

    {add_command(cTEXT2,NULL,NULL);}

    break;

  case 84:

    {add_command(cTEXT3,NULL,NULL);}

    break;

  case 85:

    {add_command(cRECT,NULL,NULL);putindrawmode(0);}

    break;

  case 86:

    {add_command(cCLOSEWIN,NULL,NULL);}

    break;

  case 87:

    {add_command(cCLEARWIN,NULL,NULL);}

    break;

  case 88:

    {add_command(cCLEARSCR,NULL,NULL);}

    break;

  case 89:

    {create_openprinter(0);}

    break;

  case 90:

    {create_openprinter(1);}

    break;

  case 91:

    {add_command(cCLOSEPRN,NULL,NULL);}

    break;

  case 92:

    {add_command(cWAIT,NULL,NULL);}

    break;

  case 93:

    {add_command(cBELL,NULL,NULL);}

    break;

  case 94:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 95:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 96:

    {create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 97:

    {create_function(fSYSTEM2);
	add_command(cPOP,NULL,NULL);}

    break;

  case 98:

    {create_poke('s');}

    break;

  case 99:

    {create_poke('d');}

    break;

  case 100:

    {create_poke('S');}

    break;

  case 101:

    {create_poke('D');}

    break;

  case 102:

    {add_command(cEND,NULL,NULL);}

    break;

  case 103:

    {create_pushdbl(0);add_command(cEXIT,NULL,NULL);}

    break;

  case 104:

    {add_command(cEXIT,NULL,NULL);}

    break;

  case 105:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 106:

    {add_command(cBIND,NULL,NULL);}

    break;

  case 107:

    {drawmode=0;}

    break;

  case 108:

    {drawmode=dmCLEAR;}

    break;

  case 109:

    {drawmode=dmFILL;}

    break;

  case 110:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 111:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 112:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 113:

    {create_changestring(fMID);}

    break;

  case 114:

    {create_changestring(fMID2);}

    break;

  case 115:

    {create_changestring(fLEFT);}

    break;

  case 116:

    {create_changestring(fRIGHT);}

    break;

  case 117:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 120:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 121:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 122:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 123:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 124:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 125:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 126:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 127:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 128:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 129:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 131:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 132:

    {if ((yyvsp[0].string)==NULL) {error(ERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 133:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 135:

    {create_function(fLEFT);}

    break;

  case 136:

    {create_function(fRIGHT);}

    break;

  case 137:

    {create_function(fMID);}

    break;

  case 138:

    {create_function(fMID2);}

    break;

  case 139:

    {create_function(fSTR);}

    break;

  case 140:

    {create_function(fSTR2);}

    break;

  case 141:

    {create_function(fSTR3);}

    break;

  case 142:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 143:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 144:

    {create_function(fINKEY);}

    break;

  case 145:

    {create_function(fCHR);}

    break;

  case 146:

    {create_function(fUPPER);}

    break;

  case 147:

    {create_function(fLOWER);}

    break;

  case 148:

    {create_function(fLTRIM);}

    break;

  case 149:

    {create_function(fRTRIM);}

    break;

  case 150:

    {create_function(fTRIM);}

    break;

  case 151:

    {create_function(fSYSTEM);}

    break;

  case 152:

    {create_function(fDATE);}

    break;

  case 153:

    {create_function(fDATE);}

    break;

  case 154:

    {create_function(fTIME);}

    break;

  case 155:

    {create_function(fTIME);}

    break;

  case 156:

    {create_function(fPEEK2);}

    break;

  case 157:

    {create_function(fPEEK3);}

    break;

  case 158:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 159:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 160:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 161:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 162:

    {create_function(fGETBIT);}

    break;

  case 163:

    {create_function(fGETCHAR);}

    break;

  case 164:

    {create_function(fHEX);}

    break;

  case 165:

    {create_function(fBIN);}

    break;

  case 166:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 167:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 168:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 169:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 170:

    {poplabel();create_boole('|');}

    break;

  case 171:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 172:

    {poplabel();create_boole('&');}

    break;

  case 173:

    {create_boole('!');}

    break;

  case 174:

    {create_dblrelop('=');}

    break;

  case 175:

    {create_dblrelop('!');}

    break;

  case 176:

    {create_dblrelop('<');}

    break;

  case 177:

    {create_dblrelop('{');}

    break;

  case 178:

    {create_dblrelop('>');}

    break;

  case 179:

    {create_dblrelop('}');}

    break;

  case 180:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 181:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 182:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 183:

    {add_command(cARDIM,"",NULL);}

    break;

  case 184:

    {add_command(cARDIM,"",NULL);}

    break;

  case 185:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 186:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 187:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 188:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 189:

    {create_dblbin('+');}

    break;

  case 190:

    {create_dblbin('-');}

    break;

  case 191:

    {create_dblbin('*');}

    break;

  case 192:

    {create_dblbin('/');}

    break;

  case 193:

    {create_dblbin('^');}

    break;

  case 194:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 195:

    {create_strrelop('=');}

    break;

  case 196:

    {create_strrelop('!');}

    break;

  case 197:

    {create_strrelop('<');}

    break;

  case 198:

    {create_strrelop('{');}

    break;

  case 199:

    {create_strrelop('>');}

    break;

  case 200:

    {create_strrelop('}');}

    break;

  case 203:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 204:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 206:

    {create_function(fSIN);}

    break;

  case 207:

    {create_function(fASIN);}

    break;

  case 208:

    {create_function(fCOS);}

    break;

  case 209:

    {create_function(fACOS);}

    break;

  case 210:

    {create_function(fTAN);}

    break;

  case 211:

    {create_function(fATAN);}

    break;

  case 212:

    {create_function(fATAN2);}

    break;

  case 213:

    {create_function(fEXP);}

    break;

  case 214:

    {create_function(fLOG);}

    break;

  case 215:

    {create_function(fLOG2);}

    break;

  case 216:

    {create_function(fSQRT);}

    break;

  case 217:

    {create_function(fSQR);}

    break;

  case 218:

    {create_function(fINT);}

    break;

  case 219:

    {create_function(fFRAC);}

    break;

  case 220:

    {create_function(fABS);}

    break;

  case 221:

    {create_function(fSIG);}

    break;

  case 222:

    {create_function(fMOD);}

    break;

  case 223:

    {create_function(fRAN);}

    break;

  case 224:

    {create_function(fRAN2);}

    break;

  case 225:

    {create_function(fMIN);}

    break;

  case 226:

    {create_function(fMAX);}

    break;

  case 227:

    {create_function(fLEN);}

    break;

  case 228:

    {create_function(fVAL);}

    break;

  case 229:

    {create_function(fASC);}

    break;

  case 230:

    {create_function(fDEC);}

    break;

  case 231:

    {create_function(fDEC2);}

    break;

  case 232:

    {if (check_compat) error(WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 233:

    {create_function(fINSTR2);}

    break;

  case 234:

    {create_function(fRINSTR);}

    break;

  case 235:

    {create_function(fRINSTR2);}

    break;

  case 236:

    {create_function(fSYSTEM2);}

    break;

  case 237:

    {create_function(fPEEK4);}

    break;

  case 238:

    {create_function(fPEEK);}

    break;

  case 239:

    {create_function(fMOUSEX);}

    break;

  case 240:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 241:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 242:

    {create_function(fMOUSEY);}

    break;

  case 243:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 244:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 245:

    {create_function(fMOUSEB);}

    break;

  case 246:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 247:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 248:

    {create_function(fMOUSEMOD);}

    break;

  case 249:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 250:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 251:

    {create_function(fAND);}

    break;

  case 252:

    {create_function(fOR);}

    break;

  case 253:

    {create_function(fEOR);}

    break;

  case 254:

    {create_function(fTELL);}

    break;

  case 255:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 256:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 257:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 258:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 259:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 260:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 261:

    {create_myopen(0);}

    break;

  case 262:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 263:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 264:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 265:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 266:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 267:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 268:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 269:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 270:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 271:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 272:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 273:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 274:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 275:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 276:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 277:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 278:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 279:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 286:

    {missing_endsub++;missing_endsub_line=mylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {error(ERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 287:

    {if (exported) create_sublink((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_numparam();}

    break;

  case 288:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 289:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_retval(ftNONE,function_type);function_type=ftNONE;add_command(cRET_FROM_FUN,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 290:

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);error(ERROR,string);} YYABORT;}

    break;

  case 291:

    {missing_endsub--;}

    break;

  case 292:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 293:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 294:

    {exported=FALSE;}

    break;

  case 295:

    {exported=TRUE;}

    break;

  case 296:

    {exported=FALSE;}

    break;

  case 297:

    {exported=TRUE;}

    break;

  case 300:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 301:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 302:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 303:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 306:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 307:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 308:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 309:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 313:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 314:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 315:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 316:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 317:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=mylineno;}

    break;

  case 318:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command(cCONTINUE_HERE,NULL,NULL);}

    break;

  case 319:

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

  case 320:

    {
             swap();popgoto();poplabel();}

    break;

  case 321:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 322:

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);error(ERROR,string);} YYABORT;}

    break;

  case 323:

    {missing_next--;}

    break;

  case 324:

    {create_pushdbl(1);}

    break;

  case 326:

    {pop(stSTRING);}

    break;

  case 327:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {error(ERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 328:

    {switch_nesting++;switch_id=max_switch_id++;add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 329:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);switch_nesting--;switch_id=0;}

    break;

  case 330:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 331:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep);}

    break;

  case 335:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 336:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 338:

    {if ((yyvsp[0].sep)>=0) mylineno+=(yyvsp[0].sep); add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 340:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command(cCONTINUE_HERE,NULL,NULL);missing_loop++;missing_loop_line=mylineno;pushgoto();}

    break;

  case 342:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);error(ERROR,string);} YYABORT;}

    break;

  case 343:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 344:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command(cCONTINUE_HERE,NULL,NULL);missing_wend++;missing_wend_line=mylineno;pushgoto();}

    break;

  case 345:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 347:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);error(ERROR,string);} YYABORT;}

    break;

  case 348:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 349:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command(cCONTINUE_HERE,NULL,NULL);missing_until++;missing_until_line=mylineno;pushgoto();}

    break;

  case 351:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);error(ERROR,string);} YYABORT;}

    break;

  case 352:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 353:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 354:

    {missing_endif++;missing_endif_line=mylineno;}

    break;

  case 355:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 356:

    {poplabel();}

    break;

  case 358:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);error(ERROR,string);} YYABORT;}

    break;

  case 359:

    {missing_endif--;}

    break;

  case 360:

    {fi_pending++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 361:

    {poplabel();}

    break;

  case 365:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 366:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 371:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 373:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 374:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 375:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 376:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 379:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 380:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 381:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 382:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 383:

    {create_strdata((yyvsp[0].string));}

    break;

  case 384:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 385:

    {create_strdata((yyvsp[0].string));}

    break;

  case 386:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 390:

    {create_print('s');}

    break;

  case 391:

    {create_print('s');}

    break;

  case 392:

    {create_print('d');}

    break;

  case 393:

    {create_print('u');}

    break;

  case 394:

    {create_print('U');}

    break;

  case 395:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 396:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 397:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 398:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 399:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 400:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 401:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 402:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 403:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 404:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 405:

    {create_pushstr("?");create_print('s');}

    break;

  case 406:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 407:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 408:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 409:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 410:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 411:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 412:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 413:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 414:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 415:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 416:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 417:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 418:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 419:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 420:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 423:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 424:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 425:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 426:

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
