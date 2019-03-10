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

void report_if_missing(int severity,char *text) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    error(severity,text);
    string[0]='\0';
    if (missing_endif)
      sprintf(string,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
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
    tHEXDIGITS = 263,
    tSTRING = 264,
    tFOR = 265,
    tTO = 266,
    tSTEP = 267,
    tNEXT = 268,
    tWHILE = 269,
    tWEND = 270,
    tREPEAT = 271,
    tUNTIL = 272,
    tIMPORT = 273,
    tGOTO = 274,
    tGOSUB = 275,
    tLABEL = 276,
    tON = 277,
    tSUB = 278,
    tENDSUB = 279,
    tLOCAL = 280,
    tSTATIC = 281,
    tEXPORT = 282,
    tERROR = 283,
    tEXECUTE = 284,
    tEXECUTE2 = 285,
    tCOMPILE = 286,
    tRUNTIME_CREATED_SUB = 287,
    tINTERRUPT = 288,
    tBREAK = 289,
    tCONTINUE = 290,
    tSWITCH = 291,
    tSEND = 292,
    tCASE = 293,
    tDEFAULT = 294,
    tLOOP = 295,
    tDO = 296,
    tSEP = 297,
    tEOPROG = 298,
    tIF = 299,
    tTHEN = 300,
    tELSE = 301,
    tELSIF = 302,
    tENDIF = 303,
    tUSING = 304,
    tPRINT = 305,
    tINPUT = 306,
    tRETURN = 307,
    tDIM = 308,
    tEND = 309,
    tEXIT = 310,
    tAT = 311,
    tSCREEN = 312,
    tREVERSE = 313,
    tCOLOUR = 314,
    tBACKCOLOUR = 315,
    tAND = 316,
    tOR = 317,
    tNOT = 318,
    tEOR = 319,
    tNEQ = 320,
    tLEQ = 321,
    tGEQ = 322,
    tLTN = 323,
    tGTN = 324,
    tEQU = 325,
    tPOW = 326,
    tREAD = 327,
    tDATA = 328,
    tRESTORE = 329,
    tOPEN = 330,
    tCLOSE = 331,
    tSEEK = 332,
    tTELL = 333,
    tAS = 334,
    tREADING = 335,
    tWRITING = 336,
    tORIGIN = 337,
    tWINDOW = 338,
    tDOT = 339,
    tLINE = 340,
    tCIRCLE = 341,
    tTRIANGLE = 342,
    tTEXT = 343,
    tCLEAR = 344,
    tFILL = 345,
    tPRINTER = 346,
    tWAIT = 347,
    tBELL = 348,
    tLET = 349,
    tARDIM = 350,
    tARSIZE = 351,
    tBIND = 352,
    tRECT = 353,
    tGETBIT = 354,
    tPUTBIT = 355,
    tGETCHAR = 356,
    tPUTCHAR = 357,
    tNEW = 358,
    tCURVE = 359,
    tSIN = 360,
    tASIN = 361,
    tCOS = 362,
    tACOS = 363,
    tTAN = 364,
    tATAN = 365,
    tEXP = 366,
    tLOG = 367,
    tSQRT = 368,
    tSQR = 369,
    tMYEOF = 370,
    tABS = 371,
    tSIG = 372,
    tINT = 373,
    tCEIL = 374,
    tFLOOR = 375,
    tFRAC = 376,
    tMOD = 377,
    tRAN = 378,
    tVAL = 379,
    tLEFT = 380,
    tRIGHT = 381,
    tMID = 382,
    tLEN = 383,
    tMIN = 384,
    tMAX = 385,
    tSTR = 386,
    tINKEY = 387,
    tCHR = 388,
    tASC = 389,
    tHEX = 390,
    tDEC = 391,
    tBIN = 392,
    tUPPER = 393,
    tLOWER = 394,
    tMOUSEX = 395,
    tMOUSEY = 396,
    tMOUSEB = 397,
    tMOUSEMOD = 398,
    tTRIM = 399,
    tLTRIM = 400,
    tRTRIM = 401,
    tINSTR = 402,
    tRINSTR = 403,
    tCHOMP = 404,
    tSYSTEM = 405,
    tSYSTEM2 = 406,
    tPEEK = 407,
    tPEEK2 = 408,
    tPOKE = 409,
    tDATE = 410,
    tTIME = 411,
    tTOKEN = 412,
    tTOKENALT = 413,
    tSPLIT = 414,
    tSPLITALT = 415,
    tGLOB = 416,
    UMINUS = 417
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
  error_without_position(sERROR,message);
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
#define YYFINAL  252
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  172
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  430
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1014

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   171,     2,     2,     2,     2,
     167,   168,   164,   163,   170,   162,     2,   165,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   169,
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
     155,   156,   157,   158,   159,   160,   161,   166
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   150,   151,   151,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   173,   174,   174,   175,   176,
     177,   178,   179,   180,   181,   181,   183,   183,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   195,
     196,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   213,   214,   215,   216,   217,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   264,   265,   266,
     267,   268,   272,   273,   274,   275,   276,   277,   280,   281,
     284,   285,   286,   287,   288,   291,   292,   295,   296,   299,
     300,   301,   302,   303,   304,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   342,   343,
     346,   346,   347,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   380,   383,   386,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   453,
     454,   455,   458,   459,   460,   463,   464,   467,   468,   469,
     470,   473,   476,   479,   479,   482,   483,   484,   487,   488,
     491,   492,   495,   491,   500,   501,   504,   505,   508,   509,
     510,   511,   514,   515,   518,   519,   520,   521,   524,   525,
     528,   529,   530,   531,   534,   535,   536,   539,   540,   541,
     542,   545,   546,   550,   564,   545,   569,   570,   573,   574,
     577,   578,   583,   583,   587,   588,   591,   592,   596,   598,
     597,   602,   603,   603,   607,   607,   613,   614,   618,   619,
     618,   625,   626,   630,   630,   635,   636,   640,   641,   641,
     643,   640,   647,   648,   651,   651,   655,   656,   659,   661,
     663,   660,   667,   668,   671,   672,   672,   675,   676,   678,
     679,   683,   684,   687,   688,   690,   691,   695,   696,   697,
     698,   701,   702,   703,   704,   705,   708,   709,   710,   713,
     713,   714,   714,   715,   715,   716,   716,   717,   717,   720,
     721,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   740,   741,   743,   744,   747,
     748
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tFNUM", "tSYMBOL", "tSTRSYM", "tDOCU",
  "tDIGITS", "tHEXDIGITS", "tSTRING", "tFOR", "tTO", "tSTEP", "tNEXT",
  "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tIMPORT", "tGOTO", "tGOSUB",
  "tLABEL", "tON", "tSUB", "tENDSUB", "tLOCAL", "tSTATIC", "tEXPORT",
  "tERROR", "tEXECUTE", "tEXECUTE2", "tCOMPILE", "tRUNTIME_CREATED_SUB",
  "tINTERRUPT", "tBREAK", "tCONTINUE", "tSWITCH", "tSEND", "tCASE",
  "tDEFAULT", "tLOOP", "tDO", "tSEP", "tEOPROG", "tIF", "tTHEN", "tELSE",
  "tELSIF", "tENDIF", "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM",
  "tEND", "tEXIT", "tAT", "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR",
  "tAND", "tOR", "tNOT", "tEOR", "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN",
  "tEQU", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN", "tCLOSE", "tSEEK",
  "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN", "tWINDOW", "tDOT",
  "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL", "tPRINTER",
  "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE", "tBIND", "tRECT",
  "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tSIN",
  "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT",
  "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC",
  "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN",
  "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN",
  "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM",
  "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "'-'", "'+'", "'*'", "'/'",
  "UMINUS", "'('", "')'", "';'", "','", "'#'", "$accept", "program",
  "statement_list", "$@1", "statement", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "clear_fill_clause", "string_assignment", "to", "open_clause",
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
     415,   416,    45,    43,    42,    47,   417,    40,    41,    59,
      44,    35
};
# endif

#define YYPACT_NINF -731

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-731)))

#define YYTABLE_NINF -358

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3627,   -65,   -55,  -731,  -731,  -731,  -731,  -731,    83,    83,
      83,  2751,  -731,  -731,  -731,  3283,  -145,  -137,  3283,    25,
      97,  -731,  -731,  -731,  3073,    -3,  -731,  3073,   134,  -731,
    3073,  3073,  3073,   280,    51,    83,  1609,  1069,  1931,   -48,
    3073,  2590,  3073,    16,   -18,  3073,  -731,    23,  3283,  3283,
    3283,    13,   -32,   -20,    17,    48,   109,  1931,   154,   119,
    -731,   143,  -731,  -731,  -731,  -731,   102,   125,  -731,   195,
    -731,  -731,  -731,  -731,  -731,  -731,  -731,  3073,  -731,  3283,
    -731,   231,   167,  3490,  -731,  -731,  -731,  -731,  -731,  -731,
     181,   184,  -731,  -731,  -731,   202,   206,   274,   214,   216,
    3073,   228,   264,   284,   298,   300,   313,   333,   361,   369,
     382,   414,   426,   441,   445,   457,   466,   487,   500,   502,
     503,   504,   506,   507,   511,   514,   517,   520,   529,   535,
     538,   543,   544,   545,   548,   549,   558,   561,   562,   563,
     565,   566,   568,   569,   571,   574,   575,   576,   577,   578,
     580,   581,   582,   587,   589,   594,   595,   598,   599,   604,
     607,   608,   610,   611,  3073,  3073,   421,  -731,   190,  -731,
    -731,  -731,  -731,   306,   402,  3283,    87,  -731,  -731,    87,
    -731,  -731,  3073,  3490,   343,   612,   218,   613,     7,  3073,
     -16,   421,  5141,   614,   615,   116,  5141,   421,  1184,   421,
    1211,   616,   617,   151,  -731,  -731,   100,   100,  -731,  -731,
     153,  -731,  3073,  3283,  3073,    53,  5141,   223,  -731,  -731,
    -731,  -731,   340,  3283,  1240,  -731,  3073,  -731,     9,   425,
    -731,  -731,  3073,  2912,  -731,  -731,  5141,  -731,  -731,   102,
     125,    87,   -10,   -10,  -731,   639,   639,   639,  2092,  3283,
     275,   476,  -731,  -731,   626,  3073,  3073,  3073,  3073,  3283,
    -731,  5141,   489,  3073,    87,   559,   633,  3073,    14,  -731,
    -731,  -731,  -731,  3073,  3073,   464,  3073,  1770,  1931,   415,
     415,  3073,  3073,  3073,  3073,  3073,  3073,  3073,  3073,  3073,
    3073,  3073,  3073,  1931,  3073,  3073,  3073,  3073,  3073,  3073,
    3073,  2258,  3283,  3283,  3283,  3283,  3283,  3073,  3073,  3073,
    2424,  3073,  3283,  3073,  3283,  3073,  3283,  3283,   317,  1233,
    1332,  1385,  3283,  3283,  3283,  3283,  3283,  3283,  3283,  3283,
    1931,  3283,   605,   622,  3283,   639,  3283,   639,  3283,   714,
     331,  1500,  3283,  3283,  3283,  3283,  3283,  3283,  3283,  -731,
    -731,  -731,  -731,  3073,  3073,  3073,  3073,  3073,  3073,  3073,
    3073,  3073,  3073,  3073,   628,   629,   621,  -731,   630,   632,
     623,  -731,    68,   636,   640,   421,  5141,   765,    73,   766,
    3764,  3073,   643,  3283,  -731,  -731,  3073,   421,   501,   312,
     645,    19,  -731,   810,  -731,  -731,   515,  3073,  3073,  -731,
    -731,   280,  -731,  -731,    58,  1255,    87,  5141,   458,  3145,
    3073,    87,  3073,  -731,   -16,  -731,  -731,  3073,  3283,  -731,
    3073,     9,  3073,  3073,   654,   660,   661,   664,  -731,  4014,
     156,  3073,  3073,  3490,   665,     9,     9,  5141,    87,   553,
    -731,   421,  5141,   673,  -731,  -731,  -731,  4025,   677,  -731,
    -731,   679,   680,  1489,  1512,  1628,   682,    10,   675,   685,
     687,   688,   689,   690,   686,   691,     9,  1785,  4050,  4075,
    4086,  4130,  4155,   536,  4191,   624,  4202,  4213,   692,  4235,
    4260,  4271,  4318,  4340,  4376,  1946,  -731,  4387,   170,   -79,
      -5,    12,   226,  2107,  2273,   652,  -731,  4398,  4423,   301,
    4445,    -7,  4456,   308,   311,  -731,   315,  -731,   334,  -731,
     335,  -731,   341,   374,   377,   392,    18,    38,   393,   411,
     412,   446,   695,    99,  -731,  -731,   176,  -122,   186,   -98,
     187,  -731,  -731,    87,    87,    87,    87,    87,    87,  -731,
      83,    83,  3073,  3073,   758,   389,   259,   638,    81,    40,
    -731,   -38,   -38,   714,   714,  -731,  -731,   306,  -731,  -731,
     402,  -731,  -731,  -731,   817,  -731,  -731,  -731,  -731,   816,
    2442,  3073,   103,  4503,  3332,  -731,  -731,  3073,  3073,  -731,
    -731,  3073,  -731,   560,   697,   698,   700,   701,  2605,  2766,
     702,   703,  -731,  -731,  -731,  3073,   793,   794,  -731,   209,
    2927,  5141,  -731,  -731,   277,  -731,  3073,  3091,  3282,  -731,
    3073,  3073,  3073,  -731,  -731,   421,  5141,   421,  5141,  -731,
    3073,  3073,  3073,  -731,  -731,  -731,  3073,  3073,  -731,  3073,
    -731,  -731,  3073,  3073,  3073,  -731,  -731,  3283,  3232,  -731,
     706,   707,  -731,  -731,  3073,  3073,  3073,  3073,  -731,  -731,
    -731,  -731,  -731,  -731,  3073,  -731,  -731,  3073,  -731,  -731,
    -731,  -731,  -731,  -731,  -731,  -731,  -731,  3073,  -731,  -731,
    3073,  3073,  3073,  -731,  3073,  3073,  -731,  3283,  -731,  -731,
    -731,  -731,  -731,  3073,  -731,  -731,  -731,  -731,  -731,  -731,
    -731,  -731,  -731,  -731,  3283,  3283,  -731,  -731,  -731,  -731,
    -731,  -731,  3283,   872,  -731,  3283,   872,  -731,  3283,  3283,
    -731,   709,  -731,   710,   464,  1437,   713,   715,  -731,   717,
     718,  -731,  -731,   539,  3490,  -731,  3073,  3543,   826,  3283,
    -731,  3283,    87,   421,   501,  3680,   560,   560,  4528,   720,
     721,  -731,   722,  -731,  -731,  -731,  -731,  3073,  3073,  -731,
    -731,  3817,  1931,  1931,  3283,  3283,  3283,  -731,  3073,  3073,
     723,  4561,  4572,   771,  5141,     9,  -731,   726,  -731,    75,
    3490,  4583,  4608,  4633,  4644,   422,   728,   107,  -731,  -731,
    4688,  4713,   729,    63,  4749,  4760,  4771,  4793,  4818,   844,
    4829,  4876,   207,  4898,   208,   222,   424,    28,   428,    64,
     431,   467,    83,    83,  -731,  -731,  -731,  -731,  3073,   848,
     861,   858,  4934,  3073,   736,   473,   262,  -731,  3073,  -731,
    -731,  -731,  -731,  -731,  -731,   739,   749,  5141,  5141,  3283,
    -731,  -731,    87,    87,   283,  3897,  5141,  -731,   834,   849,
     859,  3073,  3073,   606,  3073,    66,  -731,  -731,  -731,  -731,
    -731,  -731,  -731,  3283,  -731,  -731,  -731,  3073,  -731,  -731,
    -731,  -731,  -731,  -731,  3073,  -731,  -731,  -731,  3283,  -731,
    -731,  3073,  -731,  3073,  -731,  -731,  3283,  -731,  -731,  3283,
    -731,  -731,  -731,  -731,  -731,  -731,  -731,   871,   564,  4945,
    3073,   874,  3283,  4956,   560,   760,   769,   560,  -731,  -731,
      87,  3283,  3283,  3283,  3283,  3283,  4981,  -731,   773,   776,
      79,  -731,    27,  -731,  -731,  -731,   477,  3944,  5003,   479,
    5014,  5061,   480,   490,  3490,  3901,  3073,   892,  -731,   777,
    -731,  3969,   778,   492,  -731,  -731,  -731,  -731,  -731,    87,
      87,    87,    87,    87,   876,   779,   780,  -731,   606,  3073,
    -731,  -731,  3073,  -731,  -731,  -731,  -731,  -731,  -731,   858,
     912,   456,  3490,  -731,  3283,  3073,  3073,  -731,   810,  3283,
    -731,  -731,  3490,  -731,  5141,  3490,  5086,  -731,  -731,   858,
     123,   271,  5119,  4003,   560,    87,    21,   858,  -731,  3490,
    -731,  -731,  -731,  -731,  3283,  -731,  3073,  -731,  -731,  -731,
    -731,     8,   858,   493,  5130,  -731,  -731,   946,   871,  -731,
    -731,  -731,  -731,  -731
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     107,     0,     0,   105,   321,   348,   353,    11,     0,     0,
       0,     0,    24,    26,   299,     0,     0,     0,     0,   300,
      18,    20,   332,   344,     0,   411,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     4,
       3,     0,     7,    39,    41,     9,    22,    23,    21,     0,
      13,    14,    17,    16,    15,    28,    29,     0,   283,     0,
     283,     0,     0,     6,   276,   275,    30,    31,    38,   272,
     189,   129,   273,   274,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,     0,   243,   246,   249,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,   202,
     183,   188,   131,     0,     0,     0,    12,   283,   283,    42,
     301,    19,     0,     6,   364,     0,   415,     0,     0,   391,
     407,    62,    61,     0,     0,    63,   104,    53,     0,    55,
       0,   383,   385,    56,   381,   387,     0,     0,   388,   269,
      57,    59,     0,    89,     0,     0,   426,     0,    86,    91,
      79,    40,     0,     0,     0,    67,     0,    50,    72,     0,
      88,    87,     0,     0,   110,   111,    92,     8,    10,     0,
       0,   106,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,     0,     0,     0,
     290,   168,     0,   285,   112,     0,     0,     0,     4,   283,
     283,    32,    33,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      36,   172,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,   305,    25,   302,   310,   311,
      27,   308,     0,     0,     0,   337,   336,     0,     4,     0,
     107,     0,     0,     0,   412,   413,     0,   394,   396,    45,
       0,     0,    49,   409,   283,   283,     0,     0,     0,   283,
     283,     0,   271,   270,     0,     0,    90,   425,     0,     0,
       0,    66,     0,    71,   407,   119,   118,     0,     0,    68,
       0,    74,     0,     0,   127,     0,     0,     0,    95,     0,
       0,     0,     0,     6,     0,     0,     0,   169,   117,     0,
     281,   288,   289,   284,   286,   282,   322,     0,     0,   355,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,   247,     0,   250,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   156,     0,     0,     0,     0,
       0,   134,   203,   197,   199,   201,   198,   200,   196,   133,
       0,     0,     0,     0,   176,   178,   180,   177,   179,   175,
     194,   191,   190,   192,   193,   283,   283,     0,   283,   283,
       0,    43,    44,   334,   338,   347,   346,   345,   358,     4,
       0,     0,     0,     0,     0,   392,    46,    47,     0,   399,
     401,     0,   410,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   389,   390,     0,     0,     0,   122,   121,
     125,   206,    51,    69,    82,    73,     0,     0,     0,   283,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     5,
       0,     0,     0,   296,   297,   291,     0,     0,   349,     0,
     262,   167,     0,     0,     0,   263,   264,     0,     0,   257,
       0,     0,   184,   185,     0,     0,     0,     0,   207,   208,
     209,   210,   211,   212,     0,   214,   215,     0,   217,   218,
     181,   223,   224,   219,   220,   221,   222,     0,   226,   231,
       0,     0,     0,   230,     0,     0,   139,     0,   144,   145,
     232,   165,   233,     0,   166,   146,   147,   242,   245,   248,
     251,   150,   148,   149,     0,     0,   151,   239,   152,   241,
     240,   157,     0,     0,   160,     0,     0,   162,     0,     0,
     427,    35,   429,    37,   173,   171,     0,     0,   303,     0,
       0,   309,   335,   341,     6,   365,     0,     0,   416,     0,
     414,     0,   397,   395,   396,     0,     0,     0,     0,   377,
     379,   408,   374,   277,   279,   283,   283,     0,     0,   384,
     386,    64,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    80,     0,    85,     0,   287,     0,
       6,     0,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,   307,   312,   313,     0,     0,
       0,   359,     0,     0,     0,     0,     0,   393,     0,   400,
     402,   403,   283,   283,   375,     0,     0,    52,    54,     0,
     123,   124,   120,   126,    83,    76,    77,   128,     0,     0,
       0,     0,     0,   314,     0,     4,   356,   254,   255,   256,
     265,   266,   267,     0,   186,   187,   163,     0,   213,   216,
     225,   135,   136,   138,     0,   228,   229,   140,     0,   234,
     235,     0,   237,     0,   158,   259,     0,   159,   261,     0,
     161,   182,   428,   430,   339,   342,   333,   368,   418,     0,
       0,   417,     0,     0,     0,     0,     0,     0,   278,   280,
      65,     0,     0,     0,     0,     0,     0,    81,   317,   318,
       0,   315,   328,   352,   351,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     6,   107,     0,   366,   422,     0,
     419,     0,     0,     0,   405,   404,   378,   380,   376,    84,
      75,   115,   116,   114,     0,     0,     0,   292,     0,     0,
     323,   268,     0,   137,   141,   236,   238,   258,   260,   340,
       4,   372,     6,   360,     0,     0,     0,   398,   409,     0,
     319,   320,     6,   316,   329,     6,     0,   373,   369,   367,
       0,     0,     0,     0,     0,   113,     4,   324,   164,     6,
     362,   363,   361,   423,     0,   420,     0,   406,   295,   294,
     293,     0,   370,     0,     0,   327,   326,   330,   368,   424,
     421,   331,   325,   371
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -731,  -731,   -73,  -731,   518,  -731,  -731,  -731,  -731,  -731,
    -731,  -731,   905,  -224,  -731,  -731,  -178,   719,  -731,   906,
       5,  -731,  -731,   676,  -277,   -33,  -731,   551,   -30,     3,
    -731,     0,     2,   -63,  -731,  -731,   332,  -731,  -731,  -731,
    -731,  -731,  -731,  -731,  -731,   403,  -731,   399,  -731,    15,
    -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,
    -731,   157,  -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,
    -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,  -731,
    -731,  -731,  -731,  -731,  -731,   -47,  -731,  -731,  -731,  -730,
    -731,  -731,  -731,   572,  -731,  -731,   232,   555,  -731,  -731,
    -731,  -731,  -731,    -1,  -731,   -13,  -731,  -731
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   254,    60,   173,   174,   540,   541,   190,
     414,    61,    62,   417,    63,    64,   425,   166,   167,    65,
     224,   543,   542,   462,   463,   225,   169,   208,   170,    86,
     195,   171,   172,   262,   263,   443,   444,    68,   439,   767,
     972,  1000,   625,    69,   366,   367,   370,   371,   910,   911,
      70,    81,   627,   975,  1001,  1007,   950,  1012,    71,   182,
     564,   377,   723,   924,   810,   925,    72,   183,   567,    73,
      82,   770,   915,    74,    83,   450,    75,   379,   724,   887,
     980,   992,    76,   380,   963,   927,   989,  1008,   978,   741,
     897,   742,   203,   204,   210,   389,   575,   392,   736,   737,
     894,   968,   393,   583,   189,   217,   711,   713
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   415,    67,   465,   209,    77,   819,   820,   228,   229,
     268,   384,    87,    88,   385,    79,   168,   265,   422,   423,
     415,  1005,   177,   579,   221,   222,   580,     1,     2,   184,
     178,   448,   192,   359,   223,   196,   198,   200,   211,   949,
     390,   216,   216,   216,   251,   998,   704,   239,   705,   240,
     236,  1006,   180,   185,    89,   186,   187,   449,    92,    93,
     205,    89,   216,   408,   999,    92,    93,   593,   426,   427,
     707,   235,   708,   230,   415,   342,   343,   344,   345,   346,
     347,   913,   261,    66,   348,    67,   844,    84,   351,   352,
      85,   670,   353,   354,   355,   356,   357,   358,   359,   231,
     232,   233,    78,    89,   181,   275,   234,    92,    93,   914,
     378,   359,    80,   565,   373,   374,   566,   244,   342,   343,
     344,   345,   346,   347,   351,   352,   362,   363,   353,   354,
     355,   356,   357,   358,   359,   245,   351,   352,   193,   194,
     353,   354,   355,   356,   357,   358,   359,   246,    52,    53,
      54,   358,   359,   348,   252,   391,   348,   527,   348,   529,
     416,   682,   253,   683,   935,   671,   990,   938,   188,   339,
     341,   991,   258,   348,   386,   348,   402,   403,   636,   416,
     637,   348,   672,    66,   247,    67,   581,   376,   694,   360,
     361,   362,   363,   413,   388,   259,   875,   606,   876,   419,
     421,   348,   360,   361,   362,   363,   451,   452,   695,   349,
     350,   621,   622,   206,   207,   248,   348,   405,   260,   407,
     206,   207,   434,   435,   436,   360,   361,   362,   363,   255,
     256,   348,   878,   416,   879,   266,   531,   360,   361,   362,
     363,   257,   646,   360,   361,   362,   363,   947,   466,   948,
     348,   351,   352,   429,   997,   353,   354,   355,   356,   357,
     358,   359,   348,   437,   458,   459,   348,   701,   442,   702,
     348,   728,   447,   729,   382,   852,   249,   853,   453,   454,
     478,   455,   216,   216,   201,   202,   396,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   216,   479,
     480,   481,   482,   483,   484,   485,   487,   569,   271,   272,
     364,   365,   493,   494,   495,   497,   498,   522,   500,   348,
     502,   401,    91,   404,   614,   354,    94,   356,   357,   358,
     359,   584,   585,   348,   267,   216,   590,   591,   669,   348,
     342,   343,   344,   345,   346,   347,   703,    96,    78,   348,
     348,    80,   360,   361,   362,   363,   706,   709,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   269,
     348,   348,   348,   270,   209,   867,   870,   868,   871,   754,
      66,   273,    67,   274,   603,   348,   570,   605,  -357,   348,
     872,   573,   873,   409,   673,   276,   342,   343,   344,   345,
     346,   347,   588,   589,   351,   352,   368,   369,   353,   354,
     355,   356,   357,   358,   359,   600,   106,   601,   107,   460,
     461,   360,   361,   362,   363,   348,   797,   607,   608,   799,
     531,   277,   892,    66,   348,    67,   616,   618,   348,   993,
     348,   994,   128,   129,   130,   431,   348,   756,   134,   135,
     136,   278,   138,   901,   140,   141,   142,   356,   357,   358,
     359,   147,   148,   149,   348,   279,   152,   280,   154,   680,
     156,   348,   157,   158,   348,   160,   685,   162,   348,   686,
     281,   576,   577,   687,   175,   505,   342,   343,   344,   345,
     346,   347,   716,   717,   348,   719,   720,   348,   348,   531,
     282,   977,   688,   689,   348,   360,   361,   362,   363,   690,
     410,   342,   343,   344,   345,   346,   347,   351,   352,   586,
     587,   353,   354,   355,   356,   357,   358,   359,   283,   353,
     354,   355,   356,   357,   358,   359,   284,   348,   596,   597,
     348,   842,   691,   710,   712,   692,   760,   714,   715,   285,
     574,   360,   361,   362,   363,   348,   348,   623,   624,   857,
     693,   696,   351,   352,   739,   740,   353,   354,   355,   356,
     357,   358,   359,   757,   348,   348,   727,   808,   809,   697,
     698,   286,   734,   735,   348,   348,   738,   348,   765,   766,
     850,   348,   874,   287,   348,   418,   877,   351,   352,   880,
     751,   353,   354,   355,   356,   357,   358,   359,   288,   348,
     908,   909,   289,   782,   699,   761,   762,   763,   360,   361,
     362,   363,   928,   929,   290,   764,   360,   361,   362,   363,
     348,   442,   769,   291,   771,   881,   348,   772,   773,   774,
     348,   891,   348,   348,   424,   951,   432,   954,   957,   780,
     781,   811,   783,   348,   292,   348,   348,   440,   958,   784,
     967,  1009,   785,   360,   361,   362,   363,   293,   433,   294,
     295,   296,   786,   297,   298,   787,   788,   789,   299,   790,
     791,   300,   825,   826,   301,   351,   352,   302,   793,   353,
     354,   355,   356,   357,   358,   359,   303,   845,   360,   361,
     362,   363,   304,   446,   653,   305,   654,   357,   358,   359,
     306,   307,   308,   351,   352,   309,   310,   353,   354,   355,
     356,   357,   358,   359,    66,   311,    67,   445,   312,   313,
     314,   812,   315,   316,   176,   317,   318,   179,   319,   830,
     831,   320,   321,   322,   323,   324,   191,   325,   326,   327,
     197,   199,   827,   828,   328,   215,   329,   216,   216,   895,
     896,   330,   331,   835,   836,   332,   333,   241,   242,   243,
      66,   334,    67,   524,   335,   336,   250,   337,   338,   381,
     383,   394,   395,   399,   400,   359,   360,   361,   362,   363,
     525,   557,   656,   560,   657,   555,   556,   558,   264,   559,
     360,   361,   362,   363,   561,   882,   883,   563,   562,   907,
     571,   568,   578,   376,   360,   361,   362,   363,   889,   582,
     676,   609,   677,   893,   354,   355,   356,   357,   358,   359,
     610,   611,   351,   352,   612,   620,   353,   354,   355,   356,
     357,   358,   359,   626,   629,   638,   906,   630,   631,   912,
     635,   959,   960,   639,   640,   641,   644,   642,   643,   722,
     660,   645,   917,   700,   725,   743,   744,   745,   746,   918,
     749,   750,   752,   753,   778,   779,   920,   461,   921,   802,
     803,   804,   814,   805,   340,   806,   807,   822,   823,   979,
     885,   837,   824,   843,   372,   931,   851,   856,   886,   986,
      -4,   375,   987,   890,   903,   351,   352,   898,   387,   353,
     354,   355,   356,   357,   358,   359,  1002,   899,   926,   904,
     360,   361,   362,   363,    66,    66,    67,    67,   936,   905,
     932,   961,   406,   360,   361,   362,   363,   937,   962,   840,
     945,   841,   411,   946,   964,   966,   969,   970,   971,  -343,
    1011,   619,   237,   238,   974,   594,   464,   976,   768,   721,
     718,  1013,    66,   973,    67,   884,   817,   984,   430,   602,
     982,   983,    66,   592,    67,    66,     0,    67,   438,     0,
       0,     0,   441,     0,     0,     0,     0,     0,     0,    66,
       0,    67,     0,     0,     0,     0,   457,     0,     0,     0,
       0,  1004,     0,     0,     0,     0,   360,   361,   362,   363,
       0,     0,   863,     0,   864,     0,     0,     0,     0,     0,
       0,   488,   489,   490,   491,   492,     0,     0,     0,     0,
       0,   499,     0,   501,     0,   503,   504,   506,   508,   510,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     523,     0,     0,   526,     0,   528,     0,   530,     0,     0,
       0,   533,   534,   535,   536,   537,   538,   539,     0,     0,
       0,     0,    89,    90,    91,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,     0,
      98,    99,   100,   101,     0,     0,     0,   604,     0,     0,
       0,     0,     0,     0,   102,     0,     0,   103,     0,     0,
     615,   617,   218,     0,     0,     0,     0,     0,     0,     0,
     219,     0,     0,     0,   104,   105,     0,     0,   106,     0,
     107,     0,     0,   220,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,   165,     0,    91,     0,
     214,     0,    94,     0,     0,   351,   352,     0,     0,   353,
     354,   355,   356,   357,   358,   359,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,   351,   352,     0,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   732,     0,     0,   733,     0,     0,     0,
       0,   351,   352,     0,     0,   353,   354,   355,   356,   357,
     358,   359,     0,     0,     0,     0,   351,   352,     0,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,     0,   106,     0,   107,     0,     0,    91,     0,     0,
       0,    94,     0,     0,     0,   441,   360,   361,   362,   363,
       0,     0,     0,     0,   397,     0,   775,   777,   128,   129,
     130,     0,    96,     0,   134,   135,   136,     0,   138,     0,
     140,   141,   142,   360,   361,   362,   363,   147,   148,   149,
       0,   398,   152,     0,   154,     0,   156,     0,   157,   158,
      91,   160,     0,   162,    94,     0,   792,     0,     0,     0,
     175,   507,   360,   361,   362,   363,     0,     0,     0,     0,
     412,     0,     0,   794,   795,    96,     0,   360,   361,   362,
     363,   796,     0,     0,   798,   595,     0,   800,   801,     0,
       0,   106,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   815,     0,
     816,     0,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,   134,   135,   136,     0,   138,     0,   140,
     141,   142,     0,   832,   833,   834,   147,   148,   149,     0,
       0,   152,     0,   154,   106,   156,   107,   157,   158,     0,
     160,     0,   162,     0,     0,     0,     0,     0,   351,   175,
     509,     0,   353,   354,   355,   356,   357,   358,   359,     0,
     128,   129,   130,     0,     0,     0,   134,   135,   136,     0,
     138,     0,   140,   141,   142,     0,     0,   375,     0,   147,
     148,   149,     0,     0,   152,     0,   154,     0,   156,     0,
     157,   158,     0,   160,     0,   162,     0,     0,   900,     0,
     351,   352,   175,   511,   353,   354,   355,   356,   357,   358,
     359,   351,   352,     0,     0,   353,   354,   355,   356,   357,
     358,   359,   916,   351,   352,     0,     0,   353,   354,   355,
     356,   357,   358,   359,     0,     0,     0,   919,     0,     0,
       0,     0,     0,     0,     0,   922,     0,     0,   923,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,   933,    89,    90,    91,     0,    92,    93,    94,     0,
     939,   940,   941,   942,   943,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   361,   362,   363,     0,     0,     0,     0,   632,
       0,     0,   360,   361,   362,   363,     0,     0,   532,     0,
      98,    99,   100,   101,   360,   361,   362,   363,     0,     0,
       0,     0,   633,   981,   102,     0,     0,   103,   985,   351,
     352,     0,   212,   353,   354,   355,   356,   357,   358,   359,
     213,     0,     0,     0,   104,   105,     0,     0,   106,     0,
     107,     0,     0,  1003,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,     0,    89,    90,    91,   165,    92,    93,    94,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,     0,     0,     0,     0,   634,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   351,   352,   103,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,   456,     0,     0,     0,   104,   105,     0,     0,   106,
       0,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,   159,   160,   161,
     162,   163,   164,     0,    89,    90,    91,   165,    92,    93,
      94,   214,     0,     0,     0,     0,     0,   360,   361,   362,
     363,     0,     0,     0,     0,   647,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   351,   352,   103,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
     106,     0,   107,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,   159,   160,
     161,   162,   163,   164,     0,    89,    90,    91,   165,    92,
      93,    94,   214,     0,     0,     0,     0,     0,   360,   361,
     362,   363,     0,     0,     0,     0,   667,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   351,   352,
     103,     0,   353,   354,   355,   356,   357,   358,   359,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,   106,     0,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,     0,     0,   165,
     428,    89,    90,    91,     0,    92,    93,    94,     0,   360,
     361,   362,   363,     0,     0,     0,     0,   674,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   351,   352,   103,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,     0,     0,   165,   486,    89,    90,    91,
       0,    92,    93,    94,     0,   360,   361,   362,   363,     0,
       0,     0,     0,   675,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,   103,   351,   352,     0,     0,   353,   354,   355,
     356,   357,   358,   359,     0,     0,     0,     0,     0,   104,
     105,     0,     0,   106,     0,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,   165,   496,    89,    90,    91,     0,    92,    93,    94,
       0,   226,     0,     0,   360,   361,   362,   363,     0,     0,
       0,     0,   726,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   351,   352,   103,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,   106,
       0,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,   159,   160,   161,
     162,   163,   164,     0,    89,    90,    91,   165,    92,    93,
      94,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,     0,     0,     0,     0,   747,     0,     0,     0,     0,
      95,    96,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   351,   352,   103,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
     106,     0,   107,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,   159,   160,
     161,   162,   163,   164,     0,    89,    90,    91,   165,    92,
      93,    94,     0,   420,     0,     0,     0,     0,   360,   361,
     362,   363,     0,     0,     0,     0,   748,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   351,   352,
     103,     0,   353,   354,   355,   356,   357,   358,   359,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,   106,     0,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,     0,    89,    90,    91,   165,
      92,    93,    94,     0,     0,     0,     0,     0,     0,   360,
     361,   362,   363,     0,     0,     0,     0,   755,     0,     0,
       0,     0,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
      91,   103,   351,   352,    94,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,   104,   105,
       0,     0,   106,     0,   107,    96,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   598,    91,     0,     0,
     165,    94,     0,     0,   106,     0,   107,     0,     0,     0,
       0,     0,     0,   360,   361,   362,   363,     0,     0,     0,
       0,   758,    96,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,     0,     0,     0,   134,   135,   136,     0,
     138,     0,   140,   141,   142,     0,     0,     0,    91,   147,
     148,   149,    94,     0,   152,     0,   154,     0,   156,     0,
     157,   158,     0,   160,     0,   162,     0,     0,     0,     0,
       0,     0,   175,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,   106,     0,   107,     0,     0,     0,    91,     0,     0,
       0,    94,     0,   351,   352,     0,     0,   353,   354,   355,
     356,   357,   358,   359,     0,     0,     0,   128,   129,   130,
       0,     0,    96,   134,   135,   136,     0,   138,     0,   140,
     141,   142,     0,     0,     0,     0,   147,   148,   149,     0,
       0,   152,   106,   154,   107,   156,     0,   157,   158,     0,
     160,     0,   162,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,   134,   135,   136,     0,   138,     0,
     140,   141,   142,     0,     0,     0,     0,   147,   148,   149,
       0,   106,   152,   107,   154,     0,   156,     0,   157,   158,
       0,   160,     0,   162,   360,   361,   362,   363,     0,     0,
     175,     0,   759,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,   134,   135,   136,     0,   138,     0,   140,
     141,   142,     0,     0,     0,     0,   147,   148,   149,     0,
       0,   152,     0,   154,     0,   156,     0,   157,   158,     0,
     160,     0,   162,     0,     1,     2,     3,     0,     0,   731,
       4,     0,     0,     0,     5,     0,     6,     0,     7,     8,
       9,    10,    11,  -298,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,     0,     0,     0,
       0,    23,     0,     0,    24,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,  -107,  -107,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,  -107,     0,
      49,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,   352,     0,     0,   353,   354,
     355,   356,   357,   358,   359,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     0,     0,     0,     4,     0,     0,
      56,     5,     0,     6,    57,     7,     8,     9,    10,    11,
    -298,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,     0,     0,     0,     0,    23,    -6,
      -6,    24,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,   360,   361,   362,   363,     0,
      39,    40,    41,   813,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   351,   352,     0,     0,   353,   354,   355,   356,   357,
     358,   359,    52,    53,    54,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     0,     0,     0,     4,     0,     0,    56,     5,     0,
       6,    57,     7,     8,     9,    10,    11,  -298,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,     0,     0,     0,     0,    23,    -6,     0,    24,     0,
       0,     0,    -6,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,   360,   361,   362,   363,     0,    39,    40,    41,
     818,     0,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,     0,     0,    49,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,   352,
       0,     0,   353,   354,   355,   356,   357,   358,   359,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     0,
       0,     4,     0,     0,    56,     5,     0,     6,    57,     7,
       8,     9,    10,    11,  -298,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    -6,     0,
       0,     0,    23,    -6,     0,    24,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,     0,   351,   352,
      31,    32,   353,   354,   355,   356,   357,   358,   359,     0,
       0,     0,     0,    33,    34,    35,    36,    37,    38,   360,
     361,   362,   363,     0,    39,    40,    41,   829,     0,    42,
      43,    44,     0,    45,    46,    47,     0,     0,    48,     0,
       0,    49,     0,    50,    51,   351,   352,     0,     0,   353,
     354,   355,   356,   357,   358,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
     351,   352,     0,    55,   353,   354,   355,   356,   357,   358,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,    57,     0,     0,     0,   360,
     361,   362,   363,     0,   351,   352,     0,   902,   353,   354,
     355,   356,   357,   358,   359,   351,   352,     0,     0,   353,
     354,   355,   356,   357,   358,   359,   351,   352,     0,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   360,   361,   362,   363,
       0,   351,   352,     0,   952,   353,   354,   355,   356,   357,
     358,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   361,   362,   363,     0,   351,   352,     0,   965,
     353,   354,   355,   356,   357,   358,   359,   351,   352,     0,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,     0,
       0,     0,     0,   996,     0,     0,   360,   361,   362,   363,
       0,     0,   613,     0,     0,     0,     0,   360,   361,   362,
     363,   351,   352,   628,     0,   353,   354,   355,   356,   357,
     358,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,   361,   362,   363,   351,   352,   648,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,     0,     0,   649,     0,     0,     0,     0,   360,   361,
     362,   363,   351,   352,   650,     0,   353,   354,   355,   356,
     357,   358,   359,   351,   352,     0,     0,   353,   354,   355,
     356,   357,   358,   359,   351,   352,     0,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,   360,   361,   362,   363,   351,   352,   651,     0,
     353,   354,   355,   356,   357,   358,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,   351,   352,   652,     0,   353,   354,   355,   356,   357,
     358,   359,   351,   352,     0,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,   361,   362,   363,     0,     0,   655,
       0,     0,     0,     0,   360,   361,   362,   363,     0,     0,
     658,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   659,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,   351,   352,   661,     0,   353,   354,   355,   356,   357,
     358,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,   361,   362,   363,     0,     0,   662,     0,
       0,     0,     0,   360,   361,   362,   363,   351,   352,   663,
       0,   353,   354,   355,   356,   357,   358,   359,   351,   352,
       0,     0,   353,   354,   355,   356,   357,   358,   359,   351,
     352,     0,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   664,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,   360,   361,   362,   363,   351,   352,   665,     0,
     353,   354,   355,   356,   357,   358,   359,   351,   352,     0,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   361,
     362,   363,     0,     0,   666,     0,     0,     0,     0,   360,
     361,   362,   363,     0,     0,   668,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   678,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   679,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,     0,     0,   681,     0,     0,     0,     0,   360,   361,
     362,   363,   351,   352,   684,     0,   353,   354,   355,   356,
     357,   358,   359,   351,   352,     0,     0,   353,   354,   355,
     356,   357,   358,   359,   351,   352,     0,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   730,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   821,     0,   353,   354,
     355,   356,   357,   358,   359,   351,   352,     0,     0,   353,
     354,   355,   356,   357,   358,   359,     0,     0,     0,     0,
       0,     0,     0,   360,   361,   362,   363,     0,     0,   838,
       0,     0,     0,     0,   360,   361,   362,   363,     0,     0,
     839,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   846,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   847,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,     0,
       0,   848,     0,     0,     0,     0,   360,   361,   362,   363,
     351,   352,   849,     0,   353,   354,   355,   356,   357,   358,
     359,   351,   352,     0,     0,   353,   354,   355,   356,   357,
     358,   359,   351,   352,     0,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   854,     0,   353,   354,
     355,   356,   357,   358,   359,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   855,     0,   353,   354,   355,   356,   357,   358,   359,
     351,   352,     0,     0,   353,   354,   355,   356,   357,   358,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   361,   362,   363,     0,     0,   858,     0,     0,
       0,     0,   360,   361,   362,   363,     0,     0,   859,     0,
       0,     0,     0,   360,   361,   362,   363,   351,   352,   860,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,   351,
     352,   861,     0,   353,   354,   355,   356,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,     0,     0,   862,     0,     0,     0,
       0,   360,   361,   362,   363,   351,   352,   865,     0,   353,
     354,   355,   356,   357,   358,   359,   351,   352,     0,     0,
     353,   354,   355,   356,   357,   358,   359,   351,   352,     0,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   361,
     362,   363,   351,   352,   866,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   351,   352,   869,     0,   353,   354,
     355,   356,   357,   358,   359,   351,   352,     0,     0,   353,
     354,   355,   356,   357,   358,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   360,   361,   362,   363,
       0,     0,   888,     0,     0,     0,     0,   360,   361,   362,
     363,     0,     0,   930,     0,     0,     0,     0,   360,   361,
     362,   363,   351,   352,   934,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,   361,   362,   363,   351,   352,   944,
       0,   353,   354,   355,   356,   357,   358,   359,     0,     0,
       0,     0,     0,     0,     0,   360,   361,   362,   363,     0,
       0,   953,     0,     0,     0,     0,   360,   361,   362,   363,
     351,   352,   955,     0,   353,   354,   355,   356,   357,   358,
     359,   351,   352,     0,     0,   353,   354,   355,   356,   357,
     358,   359,   351,   352,     0,     0,   353,   354,   355,   356,
     357,   358,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,   361,   362,   363,     0,     0,   956,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   361,
     362,   363,     0,     0,   988,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   361,   362,   363,     0,     0,   995,     0,     0,
       0,     0,   360,   361,   362,   363,     0,     0,  1010,     0,
       0,     0,     0,   360,   361,   362,   363
};

static const yytype_int16 yycheck[] =
{
       0,    11,     0,   280,    34,    70,   736,   737,    41,    42,
      83,     4,     9,    10,     7,    70,    11,    80,   242,   243,
      11,    13,   167,     4,    37,    38,     7,     4,     5,    24,
     167,    17,    27,    71,    82,    30,    31,    32,    35,    12,
      56,    36,    37,    38,    57,    24,   168,    47,   170,    47,
      45,    43,    27,    56,     3,    58,    59,    43,     7,     8,
       9,     3,    57,    10,    43,     7,     8,     9,   246,   247,
     168,    89,   170,    57,    11,    65,    66,    67,    68,    69,
      70,    15,    77,    83,   163,    83,    11,     4,    61,    62,
       7,   170,    65,    66,    67,    68,    69,    70,    71,    83,
      84,    85,   167,     3,     7,   100,    90,     7,     8,    43,
     183,    71,   167,    40,   177,   178,    43,   104,    65,    66,
      67,    68,    69,    70,    61,    62,   164,   165,    65,    66,
      67,    68,    69,    70,    71,   167,    61,    62,     4,     5,
      65,    66,    67,    68,    69,    70,    71,   167,   125,   126,
     127,    70,    71,   163,     0,   171,   163,   335,   163,   337,
     170,   168,    43,   170,   894,   170,    43,   897,   171,   164,
     165,    48,    70,   163,   167,   163,   206,   207,   168,   170,
     170,   163,   170,   183,   167,   183,   167,   182,   170,   162,
     163,   164,   165,   226,   189,    70,   168,   421,   170,   232,
     233,   163,   162,   163,   164,   165,   269,   270,   170,    19,
      20,   435,   436,   162,   163,   167,   163,   212,    23,   214,
     162,   163,   255,   256,   257,   162,   163,   164,   165,    86,
      87,   163,   168,   170,   170,     4,   168,   162,   163,   164,
     165,    98,   466,   162,   163,   164,   165,   168,   281,   170,
     163,    61,    62,   248,   984,    65,    66,    67,    68,    69,
      70,    71,   163,   258,   277,   278,   163,   168,   263,   170,
     163,   168,   267,   170,    56,   168,   167,   170,   273,   274,
     293,   276,   277,   278,     4,     5,   170,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   380,    34,    35,
       4,     5,   307,   308,   309,   310,   311,   330,   313,   163,
     315,   170,     5,   170,   168,    66,     9,    68,    69,    70,
      71,   394,   395,   163,   167,   330,   399,   400,   168,   163,
      65,    66,    67,    68,    69,    70,   170,    30,   167,   163,
     163,   167,   162,   163,   164,   165,   170,   170,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   167,
     163,   163,   163,   167,   404,   168,   168,   170,   170,   170,
     380,   167,   380,   167,   417,   163,   381,   420,    45,   163,
     168,   386,   170,   170,   168,   167,    65,    66,    67,    68,
      69,    70,   397,   398,    61,    62,     4,     5,    65,    66,
      67,    68,    69,    70,    71,   410,    99,   412,   101,     4,
       5,   162,   163,   164,   165,   163,   703,   422,   423,   706,
     168,   167,   170,   433,   163,   433,   431,   432,   163,   168,
     163,   170,   125,   126,   127,   170,   163,   170,   131,   132,
     133,   167,   135,   170,   137,   138,   139,    68,    69,    70,
      71,   144,   145,   146,   163,   167,   149,   167,   151,   168,
     153,   163,   155,   156,   163,   158,   168,   160,   163,   168,
     167,   169,   170,   168,   167,   168,    65,    66,    67,    68,
      69,    70,   555,   556,   163,   558,   559,   163,   163,   168,
     167,    45,   168,   168,   163,   162,   163,   164,   165,   168,
     170,    65,    66,    67,    68,    69,    70,    61,    62,     4,
       5,    65,    66,    67,    68,    69,    70,    71,   167,    65,
      66,    67,    68,    69,    70,    71,   167,   163,    80,    81,
     163,   765,   168,   540,   541,   168,   609,   542,   543,   167,
      49,   162,   163,   164,   165,   163,   163,     4,     5,   783,
     168,   168,    61,    62,     4,     5,    65,    66,    67,    68,
      69,    70,    71,   606,   163,   163,   571,    38,    39,   168,
     168,   167,   577,   578,   163,   163,   581,   163,   621,   622,
     168,   163,   168,   167,   163,   170,   168,    61,    62,   168,
     595,    65,    66,    67,    68,    69,    70,    71,   167,   163,
       4,     5,   167,   646,   168,   610,   611,   612,   162,   163,
     164,   165,    58,    59,   167,   620,   162,   163,   164,   165,
     163,   626,   627,   167,   629,   168,   163,   632,   633,   634,
     163,   168,   163,   163,     5,   168,   170,   168,   168,   644,
     645,   724,   647,   163,   167,   163,   163,   168,   168,   654,
     168,   168,   657,   162,   163,   164,   165,   167,    42,   167,
     167,   167,   667,   167,   167,   670,   671,   672,   167,   674,
     675,   167,   745,   746,   167,    61,    62,   167,   683,    65,
      66,    67,    68,    69,    70,    71,   167,   770,   162,   163,
     164,   165,   167,    70,   168,   167,   170,    69,    70,    71,
     167,   167,   167,    61,    62,   167,   167,    65,    66,    67,
      68,    69,    70,    71,   724,   167,   724,   168,   167,   167,
     167,   726,   167,   167,    15,   167,   167,    18,   167,   752,
     753,   167,   167,   167,   167,   167,    27,   167,   167,   167,
      31,    32,   747,   748,   167,    36,   167,   752,   753,   822,
     823,   167,   167,   758,   759,   167,   167,    48,    49,    50,
     770,   167,   770,   168,   167,   167,    57,   167,   167,   167,
     167,   167,   167,   167,   167,    71,   162,   163,   164,   165,
     168,   170,   168,   170,   170,   167,   167,   167,    79,   167,
     162,   163,   164,   165,   168,   802,   803,    42,   168,   842,
     167,    45,   167,   808,   162,   163,   164,   165,   813,     9,
     168,   167,   170,   818,    66,    67,    68,    69,    70,    71,
     170,   170,    61,    62,   170,   170,    65,    66,    67,    68,
      69,    70,    71,   170,   167,   170,   841,   168,   168,   844,
     168,   924,   925,   168,   167,   167,   170,   168,   168,    42,
     168,   170,   857,   168,    48,   168,   168,   167,   167,   864,
     168,   168,    79,    79,   168,   168,   871,     5,   873,   170,
     170,   168,    56,   168,   165,   168,   168,   167,   167,   962,
      42,   168,   170,   167,   175,   890,   168,   168,    37,   972,
      42,   182,   975,   167,    70,    61,    62,   168,   189,    65,
      66,    67,    68,    69,    70,    71,   989,   168,    47,    70,
     162,   163,   164,   165,   924,   925,   924,   925,   168,    70,
      56,   926,   213,   162,   163,   164,   165,   168,    46,   168,
     167,   170,   223,   167,   167,   167,    70,   168,   168,    37,
       4,   433,    47,    47,   949,   404,   280,   952,   626,   560,
     557,  1008,   962,   948,   962,   808,   734,   968,   249,   414,
     965,   966,   972,   401,   972,   975,    -1,   975,   259,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,   989,
      -1,   989,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,
      -1,   996,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
      -1,    -1,   168,    -1,   170,    -1,    -1,    -1,    -1,    -1,
      -1,   302,   303,   304,   305,   306,    -1,    -1,    -1,    -1,
      -1,   312,    -1,   314,    -1,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,    -1,    -1,   334,    -1,   336,    -1,   338,    -1,    -1,
      -1,   342,   343,   344,   345,   346,   347,   348,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
     431,   432,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,
     101,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,    -1,     5,    -1,
     171,    -1,     9,    -1,    -1,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   574,    -1,    -1,   577,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   101,    -1,    -1,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,   626,   162,   163,   164,   165,
      -1,    -1,    -1,    -1,   170,    -1,   637,   638,   125,   126,
     127,    -1,    30,    -1,   131,   132,   133,    -1,   135,    -1,
     137,   138,   139,   162,   163,   164,   165,   144,   145,   146,
      -1,   170,   149,    -1,   151,    -1,   153,    -1,   155,   156,
       5,   158,    -1,   160,     9,    -1,   677,    -1,    -1,    -1,
     167,   168,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,    -1,    -1,   694,   695,    30,    -1,   162,   163,   164,
     165,   702,    -1,    -1,   705,   170,    -1,   708,   709,    -1,
      -1,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   729,    -1,
     731,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,
     138,   139,    -1,   754,   755,   756,   144,   145,   146,    -1,
      -1,   149,    -1,   151,    99,   153,   101,   155,   156,    -1,
     158,    -1,   160,    -1,    -1,    -1,    -1,    -1,    61,   167,
     168,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
     125,   126,   127,    -1,    -1,    -1,   131,   132,   133,    -1,
     135,    -1,   137,   138,   139,    -1,    -1,   808,    -1,   144,
     145,   146,    -1,    -1,   149,    -1,   151,    -1,   153,    -1,
     155,   156,    -1,   158,    -1,   160,    -1,    -1,   829,    -1,
      61,    62,   167,   168,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,   853,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,   868,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   876,    -1,    -1,   879,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   892,     3,     4,     5,    -1,     7,     8,     9,    -1,
     901,   902,   903,   904,   905,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,
      61,    62,    63,    64,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,   964,    75,    -1,    -1,    78,   969,    61,
      62,    -1,    83,    65,    66,    67,    68,    69,    70,    71,
      91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,
     101,    -1,    -1,   994,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,     3,     4,     5,   167,     7,     8,     9,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    61,    62,    78,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,
      -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,     3,     4,     5,   167,     7,     8,
       9,   171,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    61,    62,    78,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,    -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,     3,     4,     5,   167,     7,
       8,     9,   171,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    61,    62,
      78,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,    -1,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,     3,     4,     5,    -1,     7,     8,     9,    -1,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    61,    62,    78,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    99,    -1,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,     3,     4,     5,
      -1,     7,     8,     9,    -1,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    99,    -1,   101,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,     3,     4,     5,    -1,     7,     8,     9,
      -1,    11,    -1,    -1,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    61,    62,    78,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,
      -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,     3,     4,     5,   167,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    61,    62,    78,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,    -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,     3,     4,     5,   167,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    61,    62,
      78,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,    -1,   101,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,     3,     4,     5,   167,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
       5,    78,    61,    62,     9,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    99,    -1,   101,    30,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,   160,   161,   162,    91,     5,    -1,    -1,
     167,     9,    -1,    -1,    99,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,   170,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,   131,   132,   133,    -1,
     135,    -1,   137,   138,   139,    -1,    -1,    -1,     5,   144,
     145,   146,     9,    -1,   149,    -1,   151,    -1,   153,    -1,
     155,   156,    -1,   158,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,   101,    -1,    -1,    -1,     5,    -1,    -1,
      -1,     9,    -1,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    30,   131,   132,   133,    -1,   135,    -1,   137,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
      -1,   149,    99,   151,   101,   153,    -1,   155,   156,    -1,
     158,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,
     137,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,    99,   149,   101,   151,    -1,   153,    -1,   155,   156,
      -1,   158,    -1,   160,   162,   163,   164,   165,    -1,    -1,
     167,    -1,   170,    -1,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,   131,   132,   133,    -1,   135,    -1,   137,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,
      -1,   149,    -1,   151,    -1,   153,    -1,   155,   156,    -1,
     158,    -1,   160,    -1,     4,     5,     6,    -1,    -1,   167,
      10,    -1,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    -1,    -1,    97,    98,    -1,
     100,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,   125,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
     150,    14,    -1,    16,   154,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,   162,   163,   164,   165,    -1,
      83,    84,    85,   170,    -1,    88,    89,    90,    -1,    92,
      93,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    -1,   150,    14,    -1,
      16,   154,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,   162,   163,   164,   165,    -1,    83,    84,    85,
     170,    -1,    88,    89,    90,    -1,    92,    93,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,   150,    14,    -1,    16,   154,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    61,    62,
      59,    60,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,   162,
     163,   164,   165,    -1,    83,    84,    85,   170,    -1,    88,
      89,    90,    -1,    92,    93,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,   103,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      61,    62,    -1,   132,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,   162,
     163,   164,   165,    -1,    61,    62,    -1,   170,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
      -1,    61,    62,    -1,   170,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    -1,    61,    62,    -1,   170,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   162,   163,   164,   165,
      -1,    -1,   168,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    61,    62,   168,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    61,    62,   168,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    61,    62,   168,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    61,    62,   168,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    61,    62,   168,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,
     168,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    61,    62,   168,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    61,    62,   168,
      -1,    65,    66,    67,    68,    69,    70,    71,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    61,    62,   168,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    61,    62,   168,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,
     168,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,   168,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
      61,    62,   168,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    61,    62,   168,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    61,
      62,   168,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    -1,    -1,   168,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    61,    62,   168,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    61,    62,   168,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,    61,    62,   168,    -1,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
      -1,    -1,   168,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,   168,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    61,    62,   168,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    61,    62,   168,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,   168,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
      61,    62,   168,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,    -1,    -1,   168,    -1,
      -1,    -1,    -1,   162,   163,   164,   165
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,    10,    14,    16,    18,    19,    20,
      21,    22,    25,    26,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    41,    44,    50,    51,    52,    53,    54,
      55,    59,    60,    72,    73,    74,    75,    76,    77,    83,
      84,    85,    88,    89,    90,    92,    93,    94,    97,   100,
     102,   103,   125,   126,   127,   132,   150,   154,   173,   174,
     176,   183,   184,   186,   187,   191,   203,   204,   209,   215,
     222,   230,   238,   241,   245,   248,   254,    70,   167,    70,
     167,   223,   242,   246,     4,     7,   201,   201,   201,     3,
       4,     5,     7,     8,     9,    29,    30,    33,    61,    62,
      63,    64,    75,    78,    95,    96,    99,   101,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   155,   156,   157,
     158,   159,   160,   161,   162,   167,   189,   190,   192,   198,
     200,   203,   204,   177,   178,   167,   189,   167,   167,   189,
      27,     7,   231,   239,   192,    56,    58,    59,   171,   276,
     181,   189,   192,     4,     5,   202,   192,   189,   192,   189,
     192,     4,     5,   264,   265,     9,   162,   163,   199,   200,
     266,   201,    83,    91,   171,   189,   192,   277,    83,    91,
     104,   277,   277,    82,   192,   197,    11,    51,   197,   197,
      57,    83,    84,    85,    90,    89,   192,   184,   191,   203,
     204,   189,   189,   189,   104,   167,   167,   167,   167,   167,
     189,   277,     0,    43,   175,    86,    87,    98,    70,    70,
      23,   192,   205,   206,   189,   205,     4,   167,   174,   167,
     167,    34,    35,   167,   167,   192,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   192,
     189,   192,    65,    66,    67,    68,    69,    70,   163,    19,
      20,    61,    62,    65,    66,    67,    68,    69,    70,    71,
     162,   163,   164,   165,     4,     5,   216,   217,     4,     5,
     218,   219,   189,   205,   205,   189,   192,   233,   174,   249,
     255,   167,    56,   167,     4,     7,   167,   189,   192,   267,
      56,   171,   269,   274,   167,   167,   170,   170,   170,   167,
     167,   170,   200,   200,   170,   192,   189,   192,    10,   170,
     170,   189,   170,   197,   182,    11,   170,   185,   170,   197,
      11,   197,   185,   185,     5,   188,   188,   188,   168,   192,
     189,   170,   170,    42,   197,   197,   197,   192,   189,   210,
     168,   189,   192,   207,   208,   168,    70,   192,    17,    43,
     247,   205,   205,   192,   192,   192,    91,   189,   277,   277,
       4,     5,   195,   196,   195,   196,   197,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   277,   192,
     192,   192,   192,   192,   192,   192,   168,   192,   189,   189,
     189,   189,   189,   192,   192,   192,   168,   192,   192,   189,
     192,   189,   192,   189,   189,   168,   189,   168,   189,   168,
     189,   168,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   277,   189,   168,   168,   189,   188,   189,   188,
     189,   168,   168,   189,   189,   189,   189,   189,   189,   189,
     179,   180,   194,   193,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   167,   167,   170,   167,   167,
     170,   168,   168,    42,   232,    40,    43,   240,    45,   174,
     192,   167,   189,   192,    49,   268,   169,   170,   167,     4,
       7,   167,     9,   275,   205,   205,     4,     5,   192,   192,
     205,   205,   265,     9,   199,   170,    80,    81,    91,   189,
     192,   192,   269,   197,   189,   197,   185,   192,   192,   167,
     170,   170,   170,   168,   168,   189,   192,   189,   192,   176,
     170,   185,   185,     4,     5,   214,   170,   224,   168,   167,
     168,   168,   170,   170,   170,   168,   168,   170,   170,   168,
     167,   167,   168,   168,   170,   170,   185,   170,   168,   168,
     168,   168,   168,   168,   170,   168,   168,   170,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   170,   168,   168,
     170,   170,   170,   168,   170,   170,   168,   170,   168,   168,
     168,   168,   168,   170,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   170,   170,   168,   168,   168,   168,
     168,   168,   170,   170,   168,   170,   170,   168,   170,   170,
     201,   278,   201,   279,   192,   192,   205,   205,   217,   205,
     205,   219,    42,   234,   250,    48,   170,   192,   168,   170,
     168,   167,   189,   189,   192,   192,   270,   271,   192,     4,
       5,   261,   263,   168,   168,   167,   167,   170,   170,   168,
     168,   192,    79,    79,   170,   170,   170,   197,   170,   170,
     205,   192,   192,   192,   192,   197,   197,   211,   208,   192,
     243,   192,   192,   192,   192,   189,    91,   189,   168,   168,
     192,   192,   197,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   189,   192,   189,   189,   189,   196,   189,   196,
     189,   189,   170,   170,   168,   168,   168,   168,    38,    39,
     236,   174,   192,   170,    56,   189,   189,   268,   170,   261,
     261,   168,   167,   167,   170,   205,   205,   192,   192,   170,
     277,   277,   189,   189,   189,   192,   192,   168,   168,   168,
     168,   170,   185,   167,    11,   174,   168,   168,   168,   168,
     168,   168,   168,   170,   168,   168,   168,   185,   168,   168,
     168,   168,   168,   168,   170,   168,   168,   168,   170,   168,
     168,   170,   168,   170,   168,   168,   170,   168,   168,   170,
     168,   168,   201,   201,   233,    42,    37,   251,   168,   192,
     167,   168,   170,   192,   272,   205,   205,   262,   168,   168,
     189,   170,   170,    70,    70,    70,   192,   197,     4,     5,
     220,   221,   192,    15,    43,   244,   189,   192,   192,   189,
     192,   192,   189,   189,   235,   237,    47,   257,    58,    59,
     168,   192,    56,   189,   168,   261,   168,   168,   261,   189,
     189,   189,   189,   189,   168,   167,   167,   168,   170,    12,
     228,   168,   170,   168,   168,   168,   168,   168,   168,   174,
     174,   192,    46,   256,   167,   170,   167,   168,   273,    70,
     168,   168,   212,   221,   192,   225,   192,    45,   260,   174,
     252,   189,   192,   192,   275,   189,   174,   174,   168,   258,
      43,    48,   253,   168,   170,   168,   170,   261,    24,    43,
     213,   226,   174,   189,   192,    13,    43,   227,   259,   168,
     168,     4,   229,   257
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   172,   173,   174,   175,   174,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   176,   178,   176,   176,   176,
     176,   176,   176,   176,   179,   176,   180,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   181,   176,
     182,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   185,   185,
     186,   186,   186,   186,   186,   187,   187,   188,   188,   189,
     189,   189,   189,   189,   189,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   191,   191,
     193,   192,   194,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   195,   196,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   199,
     199,   199,   200,   200,   200,   201,   201,   202,   202,   202,
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
       2,     2,     1,     1,     1,     1,     1,     4,     6,     4,
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

    {if (severity_so_far>=sERROR) {YYABORT;}}

    break;

  case 11:

    {report_if_missing(sERROR,"can not import a library in a loop or an if-statement");}

    break;

  case 12:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 18:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror((yylsp[0]),sERROR,"break outside loop or switch");}

    break;

  case 19:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror((yylsp[-1]),sERROR,"break outside loop or switch");}

    break;

  case 20:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror((yylsp[0]),sERROR,"continue outside loop");}

    break;

  case 22:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 23:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 24:

    {if (function_type==ftNONE) lyyerror((yylsp[0]),sERROR,"no use for 'local' outside functions");}

    break;

  case 26:

    {if (function_type==ftNONE) lyyerror((yylsp[0]),sERROR,"no use for 'static' outside functions");}

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

    {if (function_type==ftNONE) {lyyerror((yylsp[-1]),sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 62:

    {if (function_type==ftNONE) {lyyerror((yylsp[-1]),sERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

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

    {if ((yyvsp[0].string)==NULL) {lyyerror((yylsp[0]),sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

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

    {if (check_compat) lyyerror((yylsp[-5]),sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

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

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

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

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing(sWARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {lyyerror((yylsp[-1]),sERROR,"nested functions not allowed");YYABORT;}}

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

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of file",missing_endsub_line);yyerror(string);} YYABORT;}

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

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

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

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen not 'next' at end of file",missing_next_line);yyerror(string);} YYABORT;}

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
             {lyyerror((yylsp[0]),sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 332:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 333:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 339:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 340:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 342:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 344:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 346:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of file",missing_loop_line);yyerror(string);} YYABORT;}

    break;

  case 347:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 348:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 349:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 351:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of file",missing_wend_line);yyerror(string);} YYABORT;}

    break;

  case 352:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 353:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 355:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of file",missing_until_line);yyerror(string);} YYABORT;}

    break;

  case 356:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 357:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 358:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 359:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 360:

    {poplabel();}

    break;

  case 362:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of file",missing_endif_line);yyerror(string);} YYABORT;}

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
