/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

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
    written by Marc Ihm 1995-2019
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
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
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

#endif /* !YY_YY_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */


/* Unqualified %code blocks.  */


void
yyerror(char *message) {
  error(ERROR,message);
}

void
lyyerror(YYLTYPE where, int severity, char *message) {
  error(severity,message);
}



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
#define YYLAST   5315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  429
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1013

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
       0,   146,   146,   149,   150,   150,   154,   155,   156,   157,
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
     331,   332,   333,   334,   335,   336,   337,   338,   341,   342,
     345,   345,   346,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   379,   382,   385,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   452,
     453,   454,   457,   458,   461,   462,   465,   466,   467,   468,
     471,   474,   477,   477,   480,   481,   482,   485,   486,   489,
     490,   493,   489,   498,   499,   502,   503,   506,   507,   508,
     509,   512,   513,   516,   517,   518,   519,   522,   523,   526,
     527,   528,   529,   532,   533,   534,   537,   538,   539,   540,
     543,   544,   548,   562,   543,   567,   568,   571,   572,   575,
     576,   581,   581,   585,   586,   589,   590,   594,   596,   595,
     600,   601,   601,   605,   605,   611,   612,   616,   617,   616,
     623,   624,   628,   628,   633,   634,   638,   639,   639,   641,
     638,   645,   646,   649,   649,   653,   654,   657,   659,   661,
     658,   665,   666,   669,   670,   670,   673,   674,   676,   677,
     681,   682,   685,   686,   688,   689,   693,   694,   695,   696,
     699,   700,   701,   702,   703,   706,   707,   708,   711,   711,
     712,   712,   713,   713,   714,   714,   715,   715,   718,   719,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   738,   739,   741,   742,   745,   746
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
  "statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "assignment", "expression", "$@8", "$@9", "arrayref",
  "string_arrayref", "coordinates", "function", "const", "number",
  "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@10", "calls", "call_item",
  "function_definition", "$@11", "$@12", "$@13", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@14", "$@15", "$@16", "$@17",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@18",
  "sep_list", "number_or_string", "case_list", "$@19", "default", "$@20",
  "do_loop", "$@21", "loop", "while_loop", "$@22", "$@23", "wend",
  "repeat_loop", "$@24", "until", "if_clause", "$@25", "$@26", "$@27",
  "$@28", "endif", "short_if", "$@29", "else_part", "elsif_part", "$@30",
  "$@31", "maybe_then", "inputlist", "$@32", "input", "readlist",
  "readitem", "datalist", "printlist", "using", "inputbody", "$@33",
  "$@34", "$@35", "$@36", "$@37", "prompt", "printintro", "hashed_number",
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
    3576,   -44,   -39,  -718,  -718,  -718,  -718,  -718,   142,   142,
     142,  2742,  -718,  -718,  -718,  3219,  -106,  -100,  3219,    86,
     116,  -718,  -718,  -718,  3062,    32,  -718,  3062,    96,  -718,
    3062,  3062,  3062,   166,    19,   142,  1607,  1067,  1927,    56,
    3062,  2582,  3062,   190,    70,  3062,  -718,    35,  3219,  3219,
    3219,    47,    42,   118,   144,   154,   181,  1927,   162,   169,
    -718,   -40,  -718,  -718,  -718,  -718,   281,   287,  -718,   193,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  3062,  -718,  3219,
    -718,   380,   222,  3439,  -718,  -718,  -718,  -718,  -718,  -718,
     234,   274,  -718,  -718,   276,   296,   167,   300,   312,  3062,
     320,   330,   362,   408,   414,   420,   438,   447,   463,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   484,   487,
     488,   490,   491,   493,   494,   496,   498,   500,   501,   502,
     503,   504,   506,   507,   511,   514,   526,   527,   528,   534,
     538,   539,   540,   541,   545,   546,   548,   550,   552,   560,
     561,   570,   580,   584,   588,   589,   594,   595,   598,   602,
     604,   606,   607,  3062,  3062,   309,  -718,    87,  -718,  -718,
    -718,  -718,   228,   260,  3219,   241,  -718,  -718,   241,  -718,
    -718,  3062,  3439,   439,   609,   516,   610,    -3,  3062,   -32,
     309,  5151,   611,   612,   283,  5151,   309,   723,   309,  1209,
     613,   614,   373,  -718,  -718,    41,    41,  -718,  -718,   393,
    -718,  3062,  3219,  3062,    11,  5151,   428,  -718,  -718,  -718,
    -718,   442,  3219,  1513,  -718,  3062,  -718,    18,   519,  -718,
    -718,  3062,  2902,  -718,  -718,  5151,  -718,  -718,   281,   287,
     241,    28,    28,  -718,   740,   740,   740,  2087,  3219,    51,
     578,  -718,  -718,   741,  3062,  3062,  3062,  3062,  3219,  -718,
    5151,   618,  3062,   241,   619,   712,  3062,    49,  -718,  -718,
    -718,  -718,  3062,  3062,   191,  3062,  1767,  1927,   271,   271,
    3062,  3062,  3062,  3062,  3062,  3062,  3062,  3062,  3062,  3062,
    3062,  3062,  1927,  3062,  3062,  3062,  3062,  3062,  3062,  3062,
    2252,  3219,  3219,  3219,  3219,  3219,  3062,  3062,  3062,  2417,
    3062,  3219,  3062,  3219,  3062,  3219,  3219,   313,  1231,  1330,
    1404,  3219,  3219,  3219,  3219,  3219,  3219,  3219,  3219,  1927,
    3219,   627,   628,  3219,   740,  3219,   740,  3219,   729,    29,
    1626,  3219,  3219,  3219,  3219,  3219,  3219,  3219,  -718,  -718,
    -718,  -718,  3062,  3062,  3062,  3062,  3062,  3062,  3062,  3062,
    3062,  3062,  3062,   634,   635,   633,  -718,   637,   638,   636,
    -718,   -41,   639,   640,   309,  5151,   768,   146,   766,  3713,
    3062,   645,  3219,  -718,  -718,  3062,   309,   673,   160,   647,
      17,  -718,   806,  -718,  -718,   515,  3062,  3062,  -718,  -718,
     166,  -718,  -718,    48,  1782,   241,  5151,   451,   565,  3062,
     241,  3062,  -718,   -32,  -718,  -718,  3062,  3219,  -718,  3062,
      18,  3062,  3062,   649,   650,   651,   652,  -718,  3238,    68,
    3062,  3062,  3439,   654,    18,    18,  5151,   241,   536,  -718,
     309,  5151,   655,  -718,  -718,  -718,  4035,   659,  -718,  -718,
     660,   661,  1942,  2102,  2267,   662,   176,   657,   663,   665,
     666,   671,   672,   664,   674,    18,  2432,  4080,  4105,  4140,
    4151,  4162,   846,  4185,   917,  4210,  4221,   675,  4267,  4290,
    4326,  4337,  4348,  4372,  2597,  -718,  4395,   256,   -70,   171,
     218,   279,  2757,  2917,  1182,  -718,  4406,  4453,   286,  4477,
    -108,  4511,   292,   293,  -718,   302,  -718,   314,  -718,   315,
    -718,   331,   335,   349,   367,   220,   235,   370,   376,   377,
     258,   677,   -60,  -718,  -718,   236,    50,   237,   140,   250,
    -718,  -718,   241,   241,   241,   241,   241,   241,  -718,   142,
     142,  3062,  3062,   326,   522,   445,   405,   415,   246,  -718,
      14,    14,   729,   729,  -718,  -718,   228,  -718,  -718,   260,
    -718,  -718,  -718,   775,  -718,  -718,  -718,  -718,   771,  3081,
    3062,   -59,  4522,  3283,  -718,  -718,  3062,  3062,  -718,  -718,
    3062,  -718,   579,   679,   680,   683,   684,  3261,  3492,   687,
     688,  -718,  -718,  -718,  3062,   762,   763,  -718,   253,  3629,
    5151,  -718,  -718,   255,  -718,  3062,  3766,  3846,  -718,  3062,
    3062,  3062,  -718,  -718,   309,  5151,   309,  5151,  -718,  3062,
    3062,  3062,  -718,  -718,  -718,  3062,  3062,  -718,  3062,  -718,
    -718,  3062,  3062,  3062,  -718,  -718,  3219,  3135,  -718,   689,
     690,  -718,  -718,  3062,  3062,  3062,  3062,  -718,  -718,  -718,
    -718,  -718,  -718,  3062,  -718,  -718,  3062,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  3062,  -718,  -718,  3062,
    3062,  3062,  -718,  3062,  3062,  -718,  3219,  -718,  -718,  -718,
    -718,  -718,  3062,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  3219,  3219,  -718,  -718,  -718,  -718,  -718,
    -718,  3219,   853,  -718,  3219,   853,  -718,  3219,  3219,  -718,
     682,  -718,   691,   191,  1441,   692,   695,  -718,   696,   697,
    -718,  -718,   558,  3439,  -718,  3062,  3893,   810,  3219,  -718,
    3219,   241,   309,   673,  3918,   579,   579,  4533,   700,   701,
    -718,   702,  -718,  -718,  -718,  -718,  3062,  3062,  -718,  -718,
    3952,  1927,  1927,  3219,  3219,  3219,  -718,  3062,  3062,   703,
    4558,  4582,  1238,  5151,    18,  -718,   706,  -718,    64,  3439,
    4593,  4638,  4663,  4698,   386,   707,    45,  -718,  -718,  4709,
    4720,   709,     3,  4743,  4768,  4779,  4825,  4848,  1253,  4884,
    4895,    62,  4906,   101,   170,   387,   201,   388,   202,   390,
     394,   142,   142,  -718,  -718,  -718,  -718,  3062,   828,   837,
     838,  4930,  3062,   714,   396,   179,  -718,  3062,  -718,  -718,
    -718,  -718,  -718,  -718,   711,   715,  5151,  5151,  3219,  -718,
    -718,   241,   241,   259,  3963,  5151,  -718,   814,   819,   820,
    3062,  3062,   621,  3062,    39,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  3219,  -718,  -718,  -718,  3062,  -718,  -718,  -718,
    -718,  -718,  -718,  3062,  -718,  -718,  -718,  3219,  -718,  -718,
    3062,  -718,  3062,  -718,  -718,  3219,  -718,  -718,  3219,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,   847,   577,  4953,  3062,
     840,  3219,  4964,   579,   730,   732,   579,  -718,  -718,   241,
    3219,  3219,  3219,  3219,  3219,  5011,  -718,   735,   736,   262,
    -718,    75,  -718,  -718,  -718,   397,  3974,  5035,   398,  5069,
    5080,   431,   443,  3439,  3850,  3062,   851,  -718,   738,  -718,
    3999,   742,   455,  -718,  -718,  -718,  -718,  -718,   241,   241,
     241,   241,   241,   849,   752,   753,  -718,   621,  3062,  -718,
    -718,  3062,  -718,  -718,  -718,  -718,  -718,  -718,   838,   873,
     457,  3439,  -718,  3219,  3062,  3062,  -718,   806,  3219,  -718,
    -718,  3439,  -718,  5151,  3439,  5091,  -718,  -718,   838,   581,
     182,  5116,  4024,   579,   241,    10,   838,  -718,  3439,  -718,
    -718,  -718,  -718,  3219,  -718,  3062,  -718,  -718,  -718,  -718,
      46,   838,   465,  5140,  -718,  -718,   918,   847,  -718,  -718,
    -718,  -718,  -718
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     107,     0,     0,   105,   320,   347,   352,    11,     0,     0,
       0,     0,    24,    26,   298,     0,     0,     0,     0,   299,
      18,    20,   331,   343,     0,   410,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     4,
       3,     0,     7,    39,    41,     9,    22,    23,    21,     0,
      13,    14,    17,    16,    15,    28,    29,     0,   282,     0,
     282,     0,     0,     6,   275,   274,    30,    31,    38,   272,
     189,   129,   273,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,     0,   243,   246,   249,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   155,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   202,   183,
     188,   131,     0,     0,     0,    12,   282,   282,    42,   300,
      19,     0,     6,   363,     0,   414,     0,     0,   390,   406,
      62,    61,     0,     0,    63,   104,    53,     0,    55,     0,
     382,   384,    56,   380,   386,     0,     0,   387,   269,    57,
      59,     0,    89,     0,     0,   425,     0,    86,    91,    79,
      40,     0,     0,     0,    67,     0,    50,    72,     0,    88,
      87,     0,     0,   110,   111,    92,     8,    10,     0,     0,
     106,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,   289,
     168,     0,   284,   112,     0,     0,     0,     4,   282,   282,
      32,    33,     0,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    36,
     172,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   304,    25,   301,   309,   310,    27,
     307,     0,     0,     0,   336,   335,     0,     4,     0,   107,
       0,     0,     0,   411,   412,     0,   393,   395,    45,     0,
       0,    49,   408,   282,   282,     0,     0,     0,   282,   282,
       0,   271,   270,     0,     0,    90,   424,     0,     0,     0,
      66,     0,    71,   406,   119,   118,     0,     0,    68,     0,
      74,     0,     0,   127,     0,     0,     0,    95,     0,     0,
       0,     0,     6,     0,     0,     0,   169,   117,     0,   280,
     287,   288,   283,   285,   281,   321,     0,     0,   354,   353,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,   247,     0,   250,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   156,     0,     0,     0,     0,     0,
     134,   203,   197,   199,   201,   198,   200,   196,   133,     0,
       0,     0,     0,   176,   178,   180,   177,   179,   175,   194,
     191,   190,   192,   193,   282,   282,     0,   282,   282,     0,
      43,    44,   333,   337,   346,   345,   344,   357,     4,     0,
       0,     0,     0,     0,   391,    46,    47,     0,   398,   400,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,   388,   389,     0,     0,     0,   122,   121,   125,
     206,    51,    69,    82,    73,     0,     0,     0,   282,     0,
       0,     0,    96,    97,    98,    99,   100,   101,     5,     0,
       0,     0,   295,   296,   290,     0,     0,   348,     0,   262,
     167,     0,     0,     0,   263,   264,     0,     0,   257,     0,
       0,   184,   185,     0,     0,     0,     0,   207,   208,   209,
     210,   211,   212,     0,   214,   215,     0,   217,   218,   181,
     223,   224,   219,   220,   221,   222,     0,   226,   231,     0,
       0,     0,   230,     0,     0,   139,     0,   144,   145,   232,
     165,   233,     0,   166,   146,   147,   242,   245,   248,   251,
     150,   148,   149,     0,     0,   151,   239,   152,   241,   240,
     157,     0,     0,   160,     0,     0,   162,     0,     0,   426,
      35,   428,    37,   173,   171,     0,     0,   302,     0,     0,
     308,   334,   340,     6,   364,     0,     0,   415,     0,   413,
       0,   396,   394,   395,     0,     0,     0,     0,   376,   378,
     407,   373,   276,   278,   282,   282,     0,     0,   383,   385,
      64,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,    80,     0,    85,     0,   286,     0,     6,
       0,     0,     0,     0,     0,     0,     0,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,   306,   311,   312,     0,     0,     0,
     358,     0,     0,     0,     0,     0,   392,     0,   399,   401,
     402,   282,   282,   374,     0,     0,    52,    54,     0,   123,
     124,   120,   126,    83,    76,    77,   128,     0,     0,     0,
       0,     0,   313,     0,     4,   355,   254,   255,   256,   265,
     266,   267,     0,   186,   187,   163,     0,   213,   216,   225,
     135,   136,   138,     0,   228,   229,   140,     0,   234,   235,
       0,   237,     0,   158,   259,     0,   159,   261,     0,   161,
     182,   427,   429,   338,   341,   332,   367,   417,     0,     0,
     416,     0,     0,     0,     0,     0,     0,   277,   279,    65,
       0,     0,     0,     0,     0,     0,    81,   316,   317,     0,
     314,   327,   351,   350,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     6,   107,     0,   365,   421,     0,   418,
       0,     0,     0,   404,   403,   377,   379,   375,    84,    75,
     115,   116,   114,     0,     0,     0,   291,     0,     0,   322,
     268,     0,   137,   141,   236,   238,   258,   260,   339,     4,
     371,     6,   359,     0,     0,     0,   397,   408,     0,   318,
     319,     6,   315,   328,     6,     0,   372,   368,   366,     0,
       0,     0,     0,     0,   113,     4,   323,   164,     6,   361,
     362,   360,   422,     0,   419,     0,   405,   294,   293,   292,
       0,   369,     0,     0,   326,   325,   329,   367,   423,   420,
     330,   324,   370
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -718,  -718,   -71,  -718,   489,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,   880,  -231,  -718,  -718,   -51,   717,  -718,   881,
       5,  -718,  -718,   653,  -272,   -33,  -718,   530,   -31,    -4,
    -718,     0,     2,   -63,  -718,  -718,   306,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,   378,  -718,   379,  -718,   -12,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,   129,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,   -67,  -718,  -718,  -718,  -717,
    -718,  -718,  -718,   537,  -718,  -718,   208,   529,  -718,  -718,
    -718,  -718,  -718,   -24,  -718,   -23,  -718,  -718
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   253,    60,   172,   173,   539,   540,   189,
     413,    61,    62,   416,    63,    64,   424,   165,   166,    65,
     223,   542,   541,   461,   462,   224,   168,   207,   169,    86,
     194,   170,   171,   261,   262,   442,   443,    68,   438,   766,
     971,   999,   624,    69,   365,   366,   369,   370,   909,   910,
      70,    81,   626,   974,  1000,  1006,   949,  1011,    71,   181,
     563,   376,   722,   923,   809,   924,    72,   182,   566,    73,
      82,   769,   914,    74,    83,   449,    75,   378,   723,   886,
     979,   991,    76,   379,   962,   926,   988,  1007,   977,   740,
     896,   741,   202,   203,   209,   388,   574,   391,   735,   736,
     893,   967,   392,   582,   188,   216,   710,   712
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   383,    67,   208,   384,    87,    88,   464,   227,   228,
     421,   422,   267,   414,   220,   221,   167,   264,   818,   819,
     407,   578,    89,   389,   579,    77,    92,   204,   414,   183,
      79,   210,   191,   997,   250,   195,   197,   199,   414,     1,
       2,   215,   215,   215,    89,   254,   255,   238,    92,   239,
     235,    89,   998,   912,   347,    92,   592,   256,  1004,   681,
     176,   682,   215,   350,   351,   447,   177,   352,   353,   354,
     355,   356,   357,   358,   843,   341,   342,   343,   344,   345,
     346,   913,   260,    66,   358,    67,   948,   184,  1005,   185,
     186,   448,   347,   341,   342,   343,   344,   345,   346,   669,
     192,   193,   347,   347,   274,   348,   349,   700,   727,   701,
     728,   377,   179,   372,   373,   341,   342,   343,   344,   345,
     346,   347,    78,   180,   350,   351,   530,    80,   352,   353,
     354,   355,   356,   357,   358,   350,   351,   222,   390,   352,
     353,   354,   355,   356,   357,   358,    84,   350,   351,    85,
     243,   352,   353,   354,   355,   356,   357,   358,   234,    52,
      53,    54,   251,   385,   359,   360,   361,   362,   338,   340,
     200,   201,   415,   347,   401,   402,   934,   361,   362,   937,
     205,   206,    66,   580,    67,   564,   375,   415,   565,   605,
     347,   347,   412,   387,   425,   426,   530,   415,   418,   420,
     270,   271,   187,   620,   621,   450,   451,   347,   244,   205,
     206,   252,   851,   347,   852,   259,   404,   703,   406,   704,
     430,   433,   434,   435,   347,   359,   360,   361,   362,   866,
     347,   867,   363,   364,   645,   613,   359,   360,   361,   362,
     341,   342,   343,   344,   345,   346,   229,   465,   359,   360,
     361,   362,   428,   457,   458,   352,   353,   354,   355,   356,
     357,   358,   436,   347,   367,   368,   996,   441,   869,   477,
     870,   446,   230,   231,   232,   459,   460,   452,   453,   233,
     454,   215,   215,   526,   245,   528,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   215,   478,   479,
     480,   481,   482,   483,   484,   486,   521,   706,   568,   707,
     246,   492,   493,   494,   496,   497,   358,   499,    91,   501,
     247,    93,   341,   342,   343,   344,   345,   346,   575,   576,
     583,   584,   347,   347,   215,   589,   590,   871,   347,   872,
     670,   347,    95,   635,   347,   636,   530,   248,   891,   992,
     257,   993,   359,   360,   361,   362,   258,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   874,   877,
     875,   878,   208,   341,   342,   343,   344,   345,   346,    66,
     347,    67,   347,   602,   265,   569,   604,   671,   266,   693,
     572,   353,   354,   355,   356,   357,   358,   347,   347,   347,
      78,   587,   588,   347,   694,   702,   705,   359,   360,   361,
     362,   105,   347,   106,   599,   347,   600,   347,   347,   708,
     347,   347,   753,   668,   755,   698,   606,   607,   900,   946,
     796,   947,    66,   798,    67,   615,   617,   127,   128,   129,
      80,   347,   268,   133,   134,   135,   672,   137,   347,   139,
     140,   141,   395,   679,   347,   347,   146,   147,   148,   684,
     685,   151,   269,   153,   347,   155,   272,   156,   157,   686,
     159,   347,   161,   356,   357,   358,   347,   347,   273,   174,
     504,   687,   688,  -356,   357,   358,   275,   359,   360,   361,
     362,   715,   716,   347,   718,   719,   276,   347,   689,   350,
     351,   976,   690,   352,   353,   354,   355,   356,   357,   358,
     353,   347,   355,   356,   357,   358,   691,   350,   351,   585,
     586,   352,   353,   354,   355,   356,   357,   358,   277,   347,
     595,   596,   347,   841,   692,   709,   711,   695,   347,   347,
     622,   623,   400,   696,   697,   759,   713,   714,   347,   347,
     347,   856,   347,   849,   873,   876,   347,   879,   347,   347,
     347,   880,   403,   890,   950,   953,   359,   360,   361,   362,
      91,   381,   756,    93,   278,   726,   359,   360,   361,   362,
     279,   733,   734,   738,   739,   737,   280,   764,   765,   355,
     356,   357,   358,   347,    95,   807,   808,   408,   956,   750,
     359,   360,   361,   362,   281,   347,   359,   360,   361,   362,
     957,   409,   781,   282,   760,   761,   762,   347,   359,   360,
     361,   362,   966,   989,   763,   907,   908,   347,   990,   283,
     441,   768,  1008,   770,   927,   928,   771,   772,   773,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   779,   780,
     293,   782,   810,   294,   295,   597,   296,   297,   783,   298,
     299,   784,   300,   105,   301,   106,   302,   303,   304,   305,
     306,   785,   307,   308,   786,   787,   788,   309,   789,   790,
     310,   824,   825,   359,   360,   361,   362,   792,   417,   127,
     128,   129,   311,   312,   313,   133,   134,   135,   844,   137,
     314,   139,   140,   141,   315,   316,   317,   318,   146,   147,
     148,   319,   320,   151,   321,   153,   322,   155,   323,   156,
     157,   573,   159,    66,   161,    67,   324,   325,   829,   830,
     811,   174,   175,   350,   351,   178,   326,   352,   353,   354,
     355,   356,   357,   358,   190,   423,   327,   431,   196,   198,
     328,   826,   827,   214,   329,   330,   215,   215,   894,   895,
     331,   332,   834,   835,   333,   240,   241,   242,   334,    66,
     335,    67,   336,   337,   249,   380,   382,   393,   394,   398,
     399,   445,   432,   350,   351,   439,   444,   352,   353,   354,
     355,   356,   357,   358,   523,   524,   263,   881,   882,   358,
     554,   555,   556,   557,   558,   559,   560,   561,   906,   562,
     567,   570,   375,   577,   581,   608,   721,   888,   724,   609,
     610,   611,   892,   619,   625,   628,   637,   629,   630,   634,
     638,   639,   640,   643,   359,   360,   361,   362,   641,   642,
     751,   752,   659,   644,   699,   905,   742,   743,   911,   744,
     745,   801,   958,   959,   748,   749,   777,   778,   460,   803,
     802,   916,   804,   805,   806,   813,   821,   822,   917,   884,
     836,   823,   842,   885,   850,   919,   855,   920,   897,    -4,
     889,   339,   898,   902,   359,   360,   361,   362,   903,   904,
     978,   371,   396,   925,   930,   931,   961,   935,   374,   936,
     985,   944,   945,   986,   963,   386,   350,   351,   965,  -342,
     352,   353,   354,   355,   356,   357,   358,  1001,   968,   969,
     970,   618,  1010,    66,    66,    67,    67,   236,   237,   405,
     960,   767,   463,   593,   717,   972,   883,   591,   720,   410,
    1012,   816,   601,   983,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   973,     0,     0,   975,     0,     0,     0,
       0,    66,     0,    67,     0,   429,     0,     0,     0,   981,
     982,    66,     0,    67,    66,   437,    67,   350,   351,   440,
       0,   352,   353,   354,   355,   356,   357,   358,    66,     0,
      67,     0,     0,   456,     0,     0,     0,     0,     0,     0,
    1003,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   652,     0,   653,     0,     0,   487,   488,
     489,   490,   491,     0,     0,     0,     0,     0,   498,     0,
     500,     0,   502,   503,   505,   507,   509,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   522,     0,     0,
     525,     0,   527,     0,   529,     0,     0,     0,   532,   533,
     534,   535,   536,   537,   538,     0,     0,     0,     0,     0,
      89,    90,    91,     0,    92,    93,     0,     0,   359,   360,
     361,   362,     0,     0,   655,     0,   656,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,     0,    97,    98,    99,
     100,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,   101,     0,     0,   102,     0,     0,   614,   616,   217,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
     219,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,   164,     0,     0,    91,   213,     0,    93,
       0,     0,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     731,     0,     0,   732,     0,     0,     0,     0,   350,   351,
       0,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,   105,
       0,   106,     0,     0,     0,    91,     0,     0,    93,     0,
       0,     0,   440,   359,   360,   361,   362,     0,     0,   675,
       0,   676,     0,   774,   776,   127,   128,   129,     0,    95,
       0,   133,   134,   135,     0,   137,     0,   139,   140,   141,
     359,   360,   361,   362,   146,   147,   148,     0,   397,   151,
       0,   153,     0,   155,     0,   156,   157,     0,   159,     0,
     161,     0,     0,   791,     0,     0,     0,   174,   506,   359,
     360,   361,   362,     0,     0,   839,     0,   840,     0,    91,
     793,   794,    93,     0,   359,   360,   361,   362,   795,     0,
     862,   797,   863,     0,   799,   800,     0,     0,   105,     0,
     106,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   814,     0,   815,     0,     0,
       0,     0,     0,     0,   127,   128,   129,     0,     0,     0,
     133,   134,   135,     0,   137,     0,   139,   140,   141,     0,
     831,   832,   833,   146,   147,   148,     0,     0,   151,     0,
     153,     0,   155,     0,   156,   157,     0,   159,     0,   161,
       0,     0,     0,     0,     0,     0,   174,   508,     0,     0,
       0,   350,   105,     0,   106,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,     0,   127,   128,
     129,     0,     0,     0,   133,   134,   135,     0,   137,     0,
     139,   140,   141,     0,     0,   899,     0,   146,   147,   148,
       0,     0,   151,     0,   153,     0,   155,     0,   156,   157,
       0,   159,     0,   161,     0,     0,     0,     0,     0,   915,
     174,   510,     0,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,   918,     0,     0,     0,     0,     0,
       0,     0,   921,     0,     0,   922,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   932,     0,
      89,    90,    91,     0,    92,    93,     0,   938,   939,   940,
     941,   942,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,   359,   360,   361,   362,     0,     0,
     980,   101,   411,     0,   102,   984,   350,   351,     0,   211,
     352,   353,   354,   355,   356,   357,   358,   212,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
    1002,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
      89,    90,    91,   164,    92,    93,     0,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   531,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   350,   351,   102,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   455,     0,     0,
       0,   103,   104,     0,     0,   105,     0,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
      89,    90,    91,   164,    92,    93,     0,   213,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   594,     0,     0,     0,    94,    95,     0,     0,     0,
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
      89,    90,    91,   164,    92,    93,     0,   213,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   631,     0,     0,     0,    94,    95,     0,     0,     0,
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
       0,     0,     0,   164,   427,    89,    90,    91,     0,    92,
      93,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   632,     0,     0,     0,     0,     0,     0,     0,     0,
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
     160,   161,   162,   163,     0,     0,     0,     0,   164,   485,
      89,    90,    91,     0,    92,    93,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   633,     0,     0,     0,
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
       0,     0,     0,   164,   495,    89,    90,    91,     0,    92,
      93,     0,   225,   359,   360,   361,   362,     0,     0,     0,
       0,   646,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
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
      93,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   666,     0,     0,     0,
      94,    95,     0,     0,    96,     0,     0,     0,     0,     0,
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
      93,     0,   419,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   673,     0,     0,     0,
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
      93,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   674,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,   102,
      91,   350,   351,    93,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   103,   104,     0,     0,
     105,     0,   106,     0,    95,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,    91,   775,     0,    93,   164,     0,
       0,     0,     0,   105,     0,   106,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,    95,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,     0,     0,     0,   133,   134,   135,     0,   137,
       0,   139,   140,   141,     0,     0,     0,     0,   146,   147,
     148,     0,     0,   151,     0,   153,     0,   155,    91,   156,
     157,    93,   159,     0,   161,     0,     0,     0,   350,   351,
       0,   174,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,    95,     0,     0,     0,     0,   105,     0,   106,
       0,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,   133,
     134,   135,     0,   137,     0,   139,   140,   141,     0,     0,
       0,     0,   146,   147,   148,     0,     0,   151,     0,   153,
       0,   155,     0,   156,   157,     0,   159,     0,   161,     0,
       0,   105,     0,   106,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,     0,   612,     0,   127,   128,   129,
       0,     0,     0,   133,   134,   135,     0,   137,     0,   139,
     140,   141,   359,   360,   361,   362,   146,   147,   148,     0,
     746,   151,     0,   153,     0,   155,     0,   156,   157,     0,
     159,     0,   161,     1,     2,     3,     0,     0,     4,   730,
       0,     0,     5,     0,     6,     0,     7,     8,     9,    10,
      11,  -297,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
       0,     0,    24,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,  -107,  -107,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,  -107,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,     0,     4,     0,     0,    56,     5,
       0,     6,    57,     7,     8,     9,    10,    11,  -297,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,     0,     0,     0,     0,    23,    -6,    -6,    24,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,     0,     0,     0,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    38,   359,   360,   361,   362,     0,    39,    40,
      41,   747,     0,    42,    43,    44,     0,    45,    46,    47,
       0,     0,    48,     0,     0,    49,     0,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
      52,    53,    54,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,     0,     4,     0,     0,    56,     5,     0,     6,    57,
       7,     8,     9,    10,    11,  -297,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,     0,
       0,     0,     0,    23,    -6,     0,    24,     0,     0,     0,
      -6,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
     359,   360,   361,   362,     0,    39,    40,    41,   754,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   350,   351,     0,     0,
     352,   353,   354,   355,   356,   357,   358,    52,    53,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     0,     0,     4,
       0,     0,    56,     5,     0,     6,    57,     7,     8,     9,
      10,    11,  -297,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    -6,     0,     0,     0,
      23,    -6,     0,    24,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,     0,   350,   351,    31,    32,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,   359,   360,   361,
     362,     0,    39,    40,    41,   757,     0,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,     0,     0,    49,
       0,    50,    51,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,   350,   351,
       0,    55,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,     0,     0,   359,   360,   361,
     362,     0,   350,   351,     0,   758,   352,   353,   354,   355,
     356,   357,   358,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,   350,   351,     0,     0,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,     0,   350,
     351,     0,   812,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,   350,   351,     0,   817,   352,   353,
     354,   355,   356,   357,   358,   350,   351,     0,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   828,     0,     0,   359,   360,   361,   362,     0,     0,
       0,     0,   901,     0,     0,   359,   360,   361,   362,     0,
     350,   351,     0,   951,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   360,   361,   362,     0,   350,   351,     0,   964,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,     0,
       0,     0,     0,   995,     0,     0,   359,   360,   361,   362,
     350,   351,   627,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   647,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   648,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   649,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   650,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   651,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   654,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   657,     0,     0,
       0,     0,   359,   360,   361,   362,   350,   351,   658,     0,
     352,   353,   354,   355,   356,   357,   358,   350,   351,     0,
       0,   352,   353,   354,   355,   356,   357,   358,   350,   351,
       0,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   660,     0,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   661,     0,   352,
     353,   354,   355,   356,   357,   358,   350,   351,     0,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   662,     0,     0,     0,     0,   359,   360,
     361,   362,     0,     0,   663,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   664,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,   350,   351,   665,
       0,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,   667,     0,     0,     0,     0,   359,   360,   361,
     362,   350,   351,   677,     0,   352,   353,   354,   355,   356,
     357,   358,   350,   351,     0,     0,   352,   353,   354,   355,
     356,   357,   358,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     678,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   350,   351,   680,     0,   352,   353,   354,   355,
     356,   357,   358,   350,   351,     0,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   683,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,   729,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     820,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   837,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,   362,     0,     0,   838,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     845,     0,   352,   353,   354,   355,   356,   357,   358,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
     350,   351,     0,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   846,     0,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     847,     0,   352,   353,   354,   355,   356,   357,   358,   350,
     351,     0,     0,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,     0,   848,     0,     0,     0,     0,
     359,   360,   361,   362,     0,     0,   853,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   854,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,   350,   351,
     857,     0,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,     0,     0,   858,     0,     0,     0,     0,
     359,   360,   361,   362,   350,   351,   859,     0,   352,   353,
     354,   355,   356,   357,   358,   350,   351,     0,     0,   352,
     353,   354,   355,   356,   357,   358,   350,   351,     0,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   860,     0,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   350,   351,   861,     0,   352,   353,   354,
     355,   356,   357,   358,   350,   351,     0,     0,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,   362,     0,
       0,   864,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,   865,     0,     0,     0,     0,   359,   360,   361,
     362,   350,   351,   868,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,   350,   351,   887,     0,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,     0,     0,
     929,     0,     0,     0,     0,   359,   360,   361,   362,   350,
     351,   933,     0,   352,   353,   354,   355,   356,   357,   358,
     350,   351,     0,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,   350,   351,   943,     0,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   359,   360,   361,   362,
     350,   351,   952,     0,   352,   353,   354,   355,   356,   357,
     358,   350,   351,     0,     0,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   360,   361,   362,     0,     0,   954,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,   955,     0,     0,
       0,     0,   359,   360,   361,   362,     0,     0,   987,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,     0,     0,   994,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   362,     0,     0,  1009,     0,     0,
       0,     0,   359,   360,   361,   362
};

static const yytype_int16 yycheck[] =
{
       0,     4,     0,    34,     7,     9,    10,   279,    41,    42,
     241,   242,    83,    10,    37,    38,    11,    80,   735,   736,
       9,     4,     3,    55,     7,    69,     7,     8,    10,    24,
      69,    35,    27,    23,    57,    30,    31,    32,    10,     4,
       5,    36,    37,    38,     3,    85,    86,    47,     7,    47,
      45,     3,    42,    14,   162,     7,     8,    97,    12,   167,
     166,   169,    57,    60,    61,    16,   166,    64,    65,    66,
      67,    68,    69,    70,    10,    64,    65,    66,    67,    68,
      69,    42,    77,    83,    70,    83,    11,    55,    42,    57,
      58,    42,   162,    64,    65,    66,    67,    68,    69,   169,
       4,     5,   162,   162,    99,    18,    19,   167,   167,   169,
     169,   182,    26,   176,   177,    64,    65,    66,    67,    68,
      69,   162,   166,     7,    60,    61,   167,   166,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    81,   170,    64,
      65,    66,    67,    68,    69,    70,     4,    60,    61,     7,
     103,    64,    65,    66,    67,    68,    69,    70,    88,   124,
     125,   126,     0,   166,   161,   162,   163,   164,   163,   164,
       4,     5,   169,   162,   205,   206,   893,   163,   164,   896,
     161,   162,   182,   166,   182,    39,   181,   169,    42,   420,
     162,   162,   225,   188,   245,   246,   167,   169,   231,   232,
      33,    34,   170,   434,   435,   268,   269,   162,   166,   161,
     162,    42,   167,   162,   169,    22,   211,   167,   213,   169,
     169,   254,   255,   256,   162,   161,   162,   163,   164,   167,
     162,   169,     4,     5,   465,   167,   161,   162,   163,   164,
      64,    65,    66,    67,    68,    69,    56,   280,   161,   162,
     163,   164,   247,   276,   277,    64,    65,    66,    67,    68,
      69,    70,   257,   162,     4,     5,   983,   262,   167,   292,
     169,   266,    82,    83,    84,     4,     5,   272,   273,    89,
     275,   276,   277,   334,   166,   336,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   329,   167,   379,   169,
     166,   306,   307,   308,   309,   310,    70,   312,     5,   314,
     166,     8,    64,    65,    66,    67,    68,    69,   168,   169,
     393,   394,   162,   162,   329,   398,   399,   167,   162,   169,
     169,   162,    29,   167,   162,   169,   167,   166,   169,   167,
      69,   169,   161,   162,   163,   164,    69,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   167,   167,
     169,   169,   403,    64,    65,    66,    67,    68,    69,   379,
     162,   379,   162,   416,     4,   380,   419,   169,   166,   169,
     385,    65,    66,    67,    68,    69,    70,   162,   162,   162,
     166,   396,   397,   162,   169,   169,   169,   161,   162,   163,
     164,    98,   162,   100,   409,   162,   411,   162,   162,   169,
     162,   162,   169,   167,   169,   167,   421,   422,   169,   167,
     702,   169,   432,   705,   432,   430,   431,   124,   125,   126,
     166,   162,   166,   130,   131,   132,   167,   134,   162,   136,
     137,   138,   169,   167,   162,   162,   143,   144,   145,   167,
     167,   148,   166,   150,   162,   152,   166,   154,   155,   167,
     157,   162,   159,    68,    69,    70,   162,   162,   166,   166,
     167,   167,   167,    44,    69,    70,   166,   161,   162,   163,
     164,   554,   555,   162,   557,   558,   166,   162,   167,    60,
      61,    44,   167,    64,    65,    66,    67,    68,    69,    70,
      65,   162,    67,    68,    69,    70,   167,    60,    61,     4,
       5,    64,    65,    66,    67,    68,    69,    70,   166,   162,
      79,    80,   162,   764,   167,   539,   540,   167,   162,   162,
       4,     5,   169,   167,   167,   608,   541,   542,   162,   162,
     162,   782,   162,   167,   167,   167,   162,   167,   162,   162,
     162,   167,   169,   167,   167,   167,   161,   162,   163,   164,
       5,    55,   605,     8,   166,   570,   161,   162,   163,   164,
     166,   576,   577,     4,     5,   580,   166,   620,   621,    67,
      68,    69,    70,   162,    29,    37,    38,   169,   167,   594,
     161,   162,   163,   164,   166,   162,   161,   162,   163,   164,
     167,   169,   645,   166,   609,   610,   611,   162,   161,   162,
     163,   164,   167,    42,   619,     4,     5,   162,    47,   166,
     625,   626,   167,   628,    57,    58,   631,   632,   633,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   643,   644,
     166,   646,   723,   166,   166,    90,   166,   166,   653,   166,
     166,   656,   166,    98,   166,   100,   166,   166,   166,   166,
     166,   666,   166,   166,   669,   670,   671,   166,   673,   674,
     166,   744,   745,   161,   162,   163,   164,   682,   169,   124,
     125,   126,   166,   166,   166,   130,   131,   132,   769,   134,
     166,   136,   137,   138,   166,   166,   166,   166,   143,   144,
     145,   166,   166,   148,   166,   150,   166,   152,   166,   154,
     155,    48,   157,   723,   159,   723,   166,   166,   751,   752,
     725,   166,    15,    60,    61,    18,   166,    64,    65,    66,
      67,    68,    69,    70,    27,     5,   166,   169,    31,    32,
     166,   746,   747,    36,   166,   166,   751,   752,   821,   822,
     166,   166,   757,   758,   166,    48,    49,    50,   166,   769,
     166,   769,   166,   166,    57,   166,   166,   166,   166,   166,
     166,    69,    41,    60,    61,   167,   167,    64,    65,    66,
      67,    68,    69,    70,   167,   167,    79,   801,   802,    70,
     166,   166,   169,   166,   166,   169,   167,   167,   841,    41,
      44,   166,   807,   166,     8,   166,    41,   812,    47,   169,
     169,   169,   817,   169,   169,   166,   169,   167,   167,   167,
     167,   166,   166,   169,   161,   162,   163,   164,   167,   167,
      78,    78,   167,   169,   167,   840,   167,   167,   843,   166,
     166,   169,   923,   924,   167,   167,   167,   167,     5,   167,
     169,   856,   167,   167,   167,    55,   166,   166,   863,    41,
     167,   169,   166,    36,   167,   870,   167,   872,   167,    41,
     166,   164,   167,    69,   161,   162,   163,   164,    69,    69,
     961,   174,   169,    46,   889,    55,    45,   167,   181,   167,
     971,   166,   166,   974,   166,   188,    60,    61,   166,    36,
      64,    65,    66,    67,    68,    69,    70,   988,    69,   167,
     167,   432,     4,   923,   924,   923,   924,    47,    47,   212,
     925,   625,   279,   403,   556,   947,   807,   400,   559,   222,
    1007,   733,   413,   967,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   948,    -1,    -1,   951,    -1,    -1,    -1,
      -1,   961,    -1,   961,    -1,   248,    -1,    -1,    -1,   964,
     965,   971,    -1,   971,   974,   258,   974,    60,    61,   262,
      -1,    64,    65,    66,    67,    68,    69,    70,   988,    -1,
     988,    -1,    -1,   276,    -1,    -1,    -1,    -1,    -1,    -1,
     995,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,   169,    -1,    -1,   301,   302,
     303,   304,   305,    -1,    -1,    -1,    -1,    -1,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,    -1,    -1,
     333,    -1,   335,    -1,   337,    -1,    -1,    -1,   341,   342,
     343,   344,   345,   346,   347,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,   382,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   408,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,   430,   431,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,    -1,     5,   170,    -1,     8,
      -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     573,    -1,    -1,   576,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    98,
      -1,   100,    -1,    -1,    -1,     5,    -1,    -1,     8,    -1,
      -1,    -1,   625,   161,   162,   163,   164,    -1,    -1,   167,
      -1,   169,    -1,   636,   637,   124,   125,   126,    -1,    29,
      -1,   130,   131,   132,    -1,   134,    -1,   136,   137,   138,
     161,   162,   163,   164,   143,   144,   145,    -1,   169,   148,
      -1,   150,    -1,   152,    -1,   154,   155,    -1,   157,    -1,
     159,    -1,    -1,   676,    -1,    -1,    -1,   166,   167,   161,
     162,   163,   164,    -1,    -1,   167,    -1,   169,    -1,     5,
     693,   694,     8,    -1,   161,   162,   163,   164,   701,    -1,
     167,   704,   169,    -1,   707,   708,    -1,    -1,    98,    -1,
     100,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   728,    -1,   730,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,    -1,   134,    -1,   136,   137,   138,    -1,
     753,   754,   755,   143,   144,   145,    -1,    -1,   148,    -1,
     150,    -1,   152,    -1,   154,   155,    -1,   157,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,    -1,    -1,
      -1,    60,    98,    -1,   100,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   807,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,    -1,
     136,   137,   138,    -1,    -1,   828,    -1,   143,   144,   145,
      -1,    -1,   148,    -1,   150,    -1,   152,    -1,   154,   155,
      -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,   852,
     166,   167,    -1,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,   867,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   875,    -1,    -1,   878,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   891,    -1,
       3,     4,     5,    -1,     7,     8,    -1,   900,   901,   902,
     903,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
     963,    74,   169,    -1,    77,   968,    60,    61,    -1,    82,
      64,    65,    66,    67,    68,    69,    70,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
     993,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
       3,     4,     5,   166,     7,     8,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    60,    61,    77,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    -1,   100,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
       3,     4,     5,   166,     7,     8,    -1,   170,    -1,    -1,
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
       3,     4,     5,   166,     7,     8,    -1,   170,    -1,    -1,
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
       8,    -1,    10,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,     3,     4,     5,   166,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   161,   162,
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
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
       5,    60,    61,     8,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,   100,    -1,    29,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,     5,    90,    -1,     8,   166,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,    29,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,    -1,    -1,    -1,   130,   131,   132,    -1,   134,
      -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,   148,    -1,   150,    -1,   152,     5,   154,
     155,     8,   157,    -1,   159,    -1,    -1,    -1,    60,    61,
      -1,   166,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    98,    -1,   100,
      -1,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,   130,
     131,   132,    -1,   134,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,    -1,   148,    -1,   150,
      -1,   152,    -1,   154,   155,    -1,   157,    -1,   159,    -1,
      -1,    98,    -1,   100,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    -1,   167,    -1,   124,   125,   126,
      -1,    -1,    -1,   130,   131,   132,    -1,   134,    -1,   136,
     137,   138,   161,   162,   163,   164,   143,   144,   145,    -1,
     169,   148,    -1,   150,    -1,   152,    -1,   154,   155,    -1,
     157,    -1,   159,     4,     5,     6,    -1,    -1,     9,   166,
      -1,    -1,    13,    -1,    15,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    -1,    -1,    96,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,   124,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,   149,    13,
      -1,    15,   153,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,   161,   162,   163,   164,    -1,    82,    83,
      84,   169,    -1,    87,    88,    89,    -1,    91,    92,    93,
      -1,    -1,    96,    -1,    -1,    99,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,   149,    13,    -1,    15,   153,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
     161,   162,   163,   164,    -1,    82,    83,    84,   169,    -1,
      87,    88,    89,    -1,    91,    92,    93,    -1,    -1,    96,
      -1,    -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,   124,   125,   126,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,   149,    13,    -1,    15,   153,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    -1,    60,    61,    58,    59,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,   161,   162,   163,
     164,    -1,    82,    83,    84,   169,    -1,    87,    88,    89,
      -1,    91,    92,    93,    -1,    -1,    96,    -1,    -1,    99,
      -1,   101,   102,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    60,    61,
      -1,   131,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,   153,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    60,    61,    -1,   169,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    60,
      61,    -1,   169,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    60,    61,    -1,   169,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,    -1,   161,   162,   163,   164,    -1,
      60,    61,    -1,   169,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    60,    61,    -1,   169,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    60,    61,   167,    -1,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    60,    61,   167,
      -1,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    60,    61,   167,    -1,    64,    65,    66,    67,    68,
      69,    70,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    60,    61,   167,    -1,    64,    65,    66,    67,
      68,    69,    70,    60,    61,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,    61,
     167,    -1,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    60,    61,   167,    -1,    64,    65,
      66,    67,    68,    69,    70,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,   164,    60,    61,   167,    -1,    64,    65,    66,
      67,    68,    69,    70,    60,    61,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,
      -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      -1,    -1,   167,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    60,    61,   167,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    60,    61,   167,    -1,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
     167,    -1,    -1,    -1,    -1,   161,   162,   163,   164,    60,
      61,   167,    -1,    64,    65,    66,    67,    68,    69,    70,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    60,    61,   167,    -1,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
      60,    61,   167,    -1,    64,    65,    66,    67,    68,    69,
      70,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,   167,    -1,    -1,
      -1,    -1,   161,   162,   163,   164
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
     101,   102,   124,   125,   126,   131,   149,   153,   172,   173,
     175,   182,   183,   185,   186,   190,   202,   203,   208,   214,
     221,   229,   237,   240,   244,   247,   253,    69,   166,    69,
     166,   222,   241,   245,     4,     7,   200,   200,   200,     3,
       4,     5,     7,     8,    28,    29,    32,    60,    61,    62,
      63,    74,    77,    94,    95,    98,   100,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   154,   155,   156,   157,
     158,   159,   160,   161,   166,   188,   189,   191,   197,   199,
     202,   203,   176,   177,   166,   188,   166,   166,   188,    26,
       7,   230,   238,   191,    55,    57,    58,   170,   275,   180,
     188,   191,     4,     5,   201,   191,   188,   191,   188,   191,
       4,     5,   263,   264,     8,   161,   162,   198,   199,   265,
     200,    82,    90,   170,   188,   191,   276,    82,    90,   103,
     276,   276,    81,   191,   196,    10,    50,   196,   196,    56,
      82,    83,    84,    89,    88,   191,   183,   190,   202,   203,
     188,   188,   188,   103,   166,   166,   166,   166,   166,   188,
     276,     0,    42,   174,    85,    86,    97,    69,    69,    22,
     191,   204,   205,   188,   204,     4,   166,   173,   166,   166,
      33,    34,   166,   166,   191,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   191,   188,
     191,    64,    65,    66,    67,    68,    69,   162,    18,    19,
      60,    61,    64,    65,    66,    67,    68,    69,    70,   161,
     162,   163,   164,     4,     5,   215,   216,     4,     5,   217,
     218,   188,   204,   204,   188,   191,   232,   173,   248,   254,
     166,    55,   166,     4,     7,   166,   188,   191,   266,    55,
     170,   268,   273,   166,   166,   169,   169,   169,   166,   166,
     169,   199,   199,   169,   191,   188,   191,     9,   169,   169,
     188,   169,   196,   181,    10,   169,   184,   169,   196,    10,
     196,   184,   184,     5,   187,   187,   187,   167,   191,   188,
     169,   169,    41,   196,   196,   196,   191,   188,   209,   167,
     188,   191,   206,   207,   167,    69,   191,    16,    42,   246,
     204,   204,   191,   191,   191,    90,   188,   276,   276,     4,
       5,   194,   195,   194,   195,   196,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   276,   191,   191,
     191,   191,   191,   191,   191,   167,   191,   188,   188,   188,
     188,   188,   191,   191,   191,   167,   191,   191,   188,   191,
     188,   191,   188,   188,   167,   188,   167,   188,   167,   188,
     167,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   276,   188,   167,   167,   188,   187,   188,   187,   188,
     167,   167,   188,   188,   188,   188,   188,   188,   188,   178,
     179,   193,   192,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   166,   166,   169,   166,   166,   169,
     167,   167,    41,   231,    39,    42,   239,    44,   173,   191,
     166,   188,   191,    48,   267,   168,   169,   166,     4,     7,
     166,     8,   274,   204,   204,     4,     5,   191,   191,   204,
     204,   264,     8,   198,   169,    79,    80,    90,   188,   191,
     191,   268,   196,   188,   196,   184,   191,   191,   166,   169,
     169,   169,   167,   167,   188,   191,   188,   191,   175,   169,
     184,   184,     4,     5,   213,   169,   223,   167,   166,   167,
     167,   169,   169,   169,   167,   167,   169,   169,   167,   166,
     166,   167,   167,   169,   169,   184,   169,   167,   167,   167,
     167,   167,   167,   169,   167,   167,   169,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   169,   167,   167,   169,
     169,   169,   167,   169,   169,   167,   169,   167,   167,   167,
     167,   167,   169,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   169,   169,   167,   167,   167,   167,   167,
     167,   169,   169,   167,   169,   169,   167,   169,   169,   200,
     277,   200,   278,   191,   191,   204,   204,   216,   204,   204,
     218,    41,   233,   249,    47,   169,   191,   167,   169,   167,
     166,   188,   188,   191,   191,   269,   270,   191,     4,     5,
     260,   262,   167,   167,   166,   166,   169,   169,   167,   167,
     191,    78,    78,   169,   169,   169,   196,   169,   169,   204,
     191,   191,   191,   191,   196,   196,   210,   207,   191,   242,
     191,   191,   191,   191,   188,    90,   188,   167,   167,   191,
     191,   196,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   188,   191,   188,   188,   188,   195,   188,   195,   188,
     188,   169,   169,   167,   167,   167,   167,    37,    38,   235,
     173,   191,   169,    55,   188,   188,   267,   169,   260,   260,
     167,   166,   166,   169,   204,   204,   191,   191,   169,   276,
     276,   188,   188,   188,   191,   191,   167,   167,   167,   167,
     169,   184,   166,    10,   173,   167,   167,   167,   167,   167,
     167,   167,   169,   167,   167,   167,   184,   167,   167,   167,
     167,   167,   167,   169,   167,   167,   167,   169,   167,   167,
     169,   167,   169,   167,   167,   169,   167,   167,   169,   167,
     167,   200,   200,   232,    41,    36,   250,   167,   191,   166,
     167,   169,   191,   271,   204,   204,   261,   167,   167,   188,
     169,   169,    69,    69,    69,   191,   196,     4,     5,   219,
     220,   191,    14,    42,   243,   188,   191,   191,   188,   191,
     191,   188,   188,   234,   236,    46,   256,    57,    58,   167,
     191,    55,   188,   167,   260,   167,   167,   260,   188,   188,
     188,   188,   188,   167,   166,   166,   167,   169,    11,   227,
     167,   169,   167,   167,   167,   167,   167,   167,   173,   173,
     191,    45,   255,   166,   169,   166,   167,   272,    69,   167,
     167,   211,   220,   191,   224,   191,    44,   259,   173,   251,
     188,   191,   191,   274,   188,   173,   173,   167,   257,    42,
      47,   252,   167,   169,   167,   169,   260,    23,    42,   212,
     225,   173,   188,   191,    12,    42,   226,   258,   167,   167,
       4,   228,   256
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   171,   172,   173,   174,   173,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   175,   177,   175,   175,   175,
     175,   175,   175,   175,   178,   175,   179,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   180,   175,
     181,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   182,   182,   182,
     182,   182,   183,   183,   183,   183,   183,   183,   184,   184,
     185,   185,   185,   185,   185,   186,   186,   187,   187,   188,
     188,   188,   188,   188,   188,   189,   189,   189,   189,   189,
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
       0,     2,     2,     1,     0,     4,     0,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     2,
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
    default: /* Avoid compiler warnings. */
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        case 2:

    {YYACCEPT;}

    break;

  case 4:

    {if (errorlevel<=ERROR) {YYABORT;}}

    break;

  case 11:

    {report_missing(ERROR,"can not import a library in a loop or an if-statement");}

    break;

  case 12:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 18:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror((yylsp[0]),ERROR,"break outside loop or switch");}

    break;

  case 19:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror((yylsp[-1]),ERROR,"break outside loop or switch");}

    break;

  case 20:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror((yylsp[0]),ERROR,"continue outside loop");}

    break;

  case 22:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 23:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 24:

    {if (function_type==ftNONE) lyyerror((yylsp[0]),ERROR,"no use for 'local' outside functions");}

    break;

  case 26:

    {if (function_type==ftNONE) lyyerror((yylsp[0]),ERROR,"no use for 'static' outside functions");}

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
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL,NULL,NULL);
            } else {
               add_command(cRETURN_FROM_GOSUB,NULL,NULL);
            }}

    break;

  case 61:

    {if (function_type==ftNONE) {lyyerror((yylsp[-1]),ERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 62:

    {if (function_type==ftNONE) {lyyerror((yylsp[-1]),ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

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

    {create_function(fSYSTEM);
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

    {if ((yyvsp[0].string)==NULL) {lyyerror((yylsp[0]),ERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

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

    {create_function(fCHOMP);}

    break;

  case 152:

    {create_function(fSYSTEM2);}

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

    {if (check_compat) lyyerror((yylsp[-5]),WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

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

    {create_function(fSYSTEM);}

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

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {lyyerror((yylsp[-1]),ERROR,"nested functions not allowed");YYABORT;}}

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

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

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

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

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

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

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
             {lyyerror((yylsp[0]),ERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 331:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 332:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 338:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 339:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 341:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 343:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 345:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

    break;

  case 346:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 347:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 348:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 350:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

    break;

  case 351:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 352:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 354:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

    break;

  case 355:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 356:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 357:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 358:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 359:

    {poplabel();}

    break;

  case 361:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);lyyerror((yylsp[0]),ERROR,string);} YYABORT;}

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
  *++yylsp = yyloc;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
