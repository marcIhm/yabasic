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

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(string,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(string,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(string,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(string,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
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
    tIMPLICITENDIF = 304,
    tUSING = 305,
    tPRINT = 306,
    tINPUT = 307,
    tRETURN = 308,
    tDIM = 309,
    tEND = 310,
    tEXIT = 311,
    tAT = 312,
    tSCREEN = 313,
    tREVERSE = 314,
    tCOLOUR = 315,
    tBACKCOLOUR = 316,
    tAND = 317,
    tOR = 318,
    tNOT = 319,
    tEOR = 320,
    tNEQ = 321,
    tLEQ = 322,
    tGEQ = 323,
    tLTN = 324,
    tGTN = 325,
    tEQU = 326,
    tPOW = 327,
    tREAD = 328,
    tDATA = 329,
    tRESTORE = 330,
    tOPEN = 331,
    tCLOSE = 332,
    tSEEK = 333,
    tTELL = 334,
    tAS = 335,
    tREADING = 336,
    tWRITING = 337,
    tORIGIN = 338,
    tWINDOW = 339,
    tDOT = 340,
    tLINE = 341,
    tCIRCLE = 342,
    tTRIANGLE = 343,
    tTEXT = 344,
    tCLEAR = 345,
    tFILL = 346,
    tPRINTER = 347,
    tWAIT = 348,
    tBELL = 349,
    tLET = 350,
    tARDIM = 351,
    tARSIZE = 352,
    tBIND = 353,
    tRECT = 354,
    tGETBIT = 355,
    tPUTBIT = 356,
    tGETCHAR = 357,
    tPUTCHAR = 358,
    tNEW = 359,
    tCURVE = 360,
    tSIN = 361,
    tASIN = 362,
    tCOS = 363,
    tACOS = 364,
    tTAN = 365,
    tATAN = 366,
    tEXP = 367,
    tLOG = 368,
    tSQRT = 369,
    tSQR = 370,
    tMYEOF = 371,
    tABS = 372,
    tSIG = 373,
    tINT = 374,
    tCEIL = 375,
    tFLOOR = 376,
    tFRAC = 377,
    tMOD = 378,
    tRAN = 379,
    tVAL = 380,
    tLEFT = 381,
    tRIGHT = 382,
    tMID = 383,
    tLEN = 384,
    tMIN = 385,
    tMAX = 386,
    tSTR = 387,
    tINKEY = 388,
    tCHR = 389,
    tASC = 390,
    tHEX = 391,
    tDEC = 392,
    tBIN = 393,
    tUPPER = 394,
    tLOWER = 395,
    tMOUSEX = 396,
    tMOUSEY = 397,
    tMOUSEB = 398,
    tMOUSEMOD = 399,
    tTRIM = 400,
    tLTRIM = 401,
    tRTRIM = 402,
    tINSTR = 403,
    tRINSTR = 404,
    tCHOMP = 405,
    tSYSTEM = 406,
    tSYSTEM2 = 407,
    tPEEK = 408,
    tPEEK2 = 409,
    tPOKE = 410,
    tEXTCALL = 411,
    tDATE = 412,
    tTIME = 413,
    tTOKEN = 414,
    tTOKENALT = 415,
    tSPLIT = 416,
    tSPLITALT = 417,
    tGLOB = 418,
    UMINUS = 419
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
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
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
#define YYFINAL  254
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  174
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  449
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1037

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   173,     2,     2,     2,     2,
     169,   170,   166,   165,   172,   164,     2,   167,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   171,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   168
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   186,   187,   187,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   209,   210,   210,   211,   212,
     213,   214,   215,   216,   217,   217,   219,   219,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   231,
     232,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   249,   250,   251,   252,   253,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   302,
     303,   304,   305,   306,   310,   311,   312,   313,   314,   315,
     318,   319,   322,   323,   324,   325,   326,   329,   330,   333,
     334,   337,   338,   339,   340,   341,   342,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     380,   381,   384,   384,   385,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   418,   421,   424,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   491,   492,   493,   496,   497,   498,   501,   502,   505,
     506,   507,   508,   511,   514,   517,   517,   520,   521,   522,
     525,   526,   529,   530,   533,   529,   538,   539,   542,   543,
     546,   547,   548,   549,   552,   553,   556,   557,   558,   559,
     562,   563,   566,   567,   568,   569,   572,   573,   574,   577,
     578,   579,   580,   583,   584,   588,   602,   583,   607,   608,
     609,   610,   611,   612,   615,   616,   619,   620,   625,   625,
     629,   630,   633,   634,   638,   640,   639,   644,   645,   645,
     649,   649,   655,   656,   657,   658,   659,   660,   664,   665,
     664,   671,   672,   676,   676,   681,   682,   683,   684,   685,
     686,   689,   690,   690,   692,   689,   696,   697,   698,   699,
     700,   701,   704,   705,   704,   709,   710,   713,   715,   717,
     714,   721,   722,   725,   726,   726,   729,   730,   732,   733,
     737,   738,   741,   742,   744,   745,   749,   750,   751,   752,
     755,   756,   757,   758,   759,   762,   763,   764,   767,   767,
     768,   768,   769,   769,   770,   770,   771,   771,   774,   775,
     778,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   794,   795,   797,   798,   801,   802
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
  "tELSIF", "tENDIF", "tIMPLICITENDIF", "tUSING", "tPRINT", "tINPUT",
  "tRETURN", "tDIM", "tEND", "tEXIT", "tAT", "tSCREEN", "tREVERSE",
  "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT", "tEOR", "tNEQ", "tLEQ",
  "tGEQ", "tLTN", "tGTN", "tEQU", "tPOW", "tREAD", "tDATA", "tRESTORE",
  "tOPEN", "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING",
  "tORIGIN", "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT",
  "tCLEAR", "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM",
  "tARSIZE", "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR",
  "tPUTCHAR", "tNEW", "tCURVE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN",
  "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG",
  "tINT", "tCEIL", "tFLOOR", "tFRAC", "tMOD", "tRAN", "tVAL", "tLEFT",
  "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR",
  "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY",
  "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR",
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tEXTCALL",
  "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "'('", "')'", "';'", "','", "'#'",
  "$accept", "program", "statement_list", "$@1", "statement", "$@2", "$@3",
  "$@4", "$@5", "$@6", "$@7", "clear_fill_clause", "string_assignment",
  "to", "open_clause", "seek_clause", "string_scalar_or_array",
  "string_expression", "string_function", "assignment", "expression",
  "$@8", "$@9", "arrayref", "string_arrayref", "coordinates", "function",
  "const", "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@10", "calls", "call_item",
  "function_definition", "$@11", "$@12", "$@13", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@14", "$@15", "$@16", "$@17",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@18",
  "sep_list", "number_or_string", "case_list", "$@19", "default", "$@20",
  "do_loop", "$@21", "loop", "while_loop", "$@22", "$@23", "wend",
  "repeat_loop", "$@24", "until", "if_clause", "$@25", "$@26", "$@27",
  "$@28", "endif", "short_if", "$@29", "$@30", "else_part", "elsif_part",
  "$@31", "$@32", "maybe_then", "inputlist", "$@33", "input", "readlist",
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
     415,   416,   417,   418,    45,    43,    42,    47,   419,    40,
      41,    59,    44,    35
};
# endif

#define YYPACT_NINF -743

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-743)))

#define YYTABLE_NINF -372

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3550,   -59,   -16,  -743,  -743,  -743,  -743,  -743,    61,    61,
      61,  2856,  -743,  -743,  -743,  1586,  -115,   -86,  1586,   107,
     144,  -743,  -743,  -743,  3182,   -15,  -743,  3182,    98,  -743,
    3182,  3182,  3182,   305,    32,    61,  1700,  1134,  2026,    85,
    3182,  2693,  3182,   162,    -4,  3182,  -743,    33,  1586,  1586,
    1586,    66,    23,    29,    34,    53,    64,  2026,  1586,   243,
     229,  -743,    36,  -743,  -743,  -743,  -743,   226,   248,  -743,
     299,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  3182,  -743,
    1586,  -743,   324,  3182,  3407,  -743,  -743,  -743,  -743,  -743,
    -743,   201,   277,  -743,  -743,  -743,   281,   297,   139,   323,
     329,  3182,   337,   359,   365,   374,   390,   407,   438,   446,
     481,   482,   483,   487,   490,   492,   493,   494,   495,   496,
     497,   498,   500,   501,   505,   508,   509,   510,   518,   519,
     520,   521,   522,   523,   524,   525,   527,   528,   533,   535,
     536,   537,   538,   539,   540,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   559,
     560,   561,   562,   563,   564,  3182,  3182,    30,  -743,   534,
    -743,  -743,  -743,  -743,   338,   352,  1586,   234,  -743,  -743,
     234,  -743,  -743,  3182,  3407,   296,   565,   358,   566,    24,
    3182,   -21,    30,  5337,   569,   571,   276,  5337,    30,  1242,
      30,  1355,   572,   573,   344,  -743,  -743,   263,   263,  -743,
    -743,   368,  -743,  3182,  1586,  3182,    79,  5337,   389,  -743,
    -743,  -743,  -743,   398,  1586,  1878,  -743,  3182,  -743,     4,
     450,  -743,  -743,  3182,  3019,  -743,  -743,  5337,  -743,  -743,
     226,   248,   234,    -3,    -3,  -743,   635,   635,   635,  2189,
    1586,    -8,   488,  -142,  -743,  -743,   504,  3182,  3182,  3182,
    3182,  1586,  -743,  5337,   360,  3182,   234,   574,   582,  5337,
     202,  -743,  -743,  -743,  -743,  3182,  3182,   516,  3182,  1863,
    2026,   382,   382,  3182,  3182,  3182,  3182,  3182,  3182,  3182,
    3182,  3182,  3182,  3182,  3182,  2026,  3182,  3182,  3182,  3182,
    3182,  3182,  3182,  2357,  1586,  1586,  1586,  1586,  1586,  3182,
    3182,  3182,  2525,  3182,  1586,  3182,  1586,  3182,  1586,  1586,
     884,  1199,  1310,  1436,  1586,  1586,  1586,  1586,  1586,  1586,
    1586,  1586,  2026,  1586,   575,   580,  1586,   635,  1586,   635,
    1586,   631,   161,   833,  1586,  1586,  1586,  1586,  1586,  1586,
    1586,  -743,  -743,  -743,  -743,  3182,  3182,  3182,  3182,  3182,
    3182,  3182,  3182,  3182,  3182,  3182,   583,   587,   579,  -743,
     588,   589,   590,  -743,    51,   591,   593,    30,  5337,   668,
     381,   698,  3693,  3182,   595,  1586,  -743,  -743,  3182,    30,
     705,    80,   600,    25,  -743,   737,  -743,  -743,   427,  3182,
    3182,  -743,  -743,   305,  -743,  -743,    44,  2041,   234,  5337,
     401,   375,  3182,   234,  3182,  -743,   -21,  -743,  -743,  3182,
    1586,  -743,  3182,     4,  3182,  3182,   601,   608,   609,   617,
    -743,  4236,   153,  3182,  3182,  1586,  3407,   618,     4,     4,
    5337,   234,   454,  -743,    30,  5337,   619,  -743,  -743,  -743,
    3407,  -743,  -743,  3182,  -743,  -743,  -743,  -743,   622,   623,
    2204,  2372,  2543,   624,    10,   626,   625,   627,   630,   633,
     634,   636,   638,     4,  2708,  4261,  4272,  4283,  4294,  4317,
     716,  4342,   785,  4400,  4423,   637,  4448,  4459,  4470,  4481,
    4506,  4529,  2871,  -743,  4587,   169,   -99,   -61,    -9,   190,
    3034,  3197,  1004,  -743,  4612,  4635,   208,  4646,  -101,  4657,
     275,   279,  -743,   311,  -743,   319,  -743,   334,  -743,   347,
     353,   354,   361,    42,    90,   371,   377,   392,   340,   642,
     -77,  -743,  -743,    91,  -148,   142,    16,   155,  -743,  -743,
     234,   234,   234,   234,   234,   234,  -743,    61,    61,  3182,
    3182,   766,   321,   385,   408,    94,   129,  -743,   -23,   -23,
     631,   631,  -743,  -743,   338,  -743,  -743,   352,  -743,  -743,
    -743,   763,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     758,  3450,  3182,    19,  4668,  3247,  -743,  -743,  3182,  3182,
    -743,  -743,  3182,  -743,   491,   645,   646,   650,   651,  3593,
    3736,   653,   656,  -743,  -743,  -743,  3182,   741,   748,  -743,
     210,  3879,  5337,  -743,  -743,   232,  -743,  3182,  4022,  4047,
    -743,  3182,  3182,  3182,  -743,  -743,    30,  5337,    30,  5337,
     261,  -743,  3182,  3182,  3182,  -743,  -743,  -743,  3182,  3182,
      41,  5337,  -743,  -743,  3182,  3182,  3182,  -743,  -743,  1586,
    1485,  -743,   671,   672,  -743,  -743,  3182,  3182,  3182,  3182,
    -743,  -743,  -743,  -743,  -743,  -743,  3182,  -743,  -743,  3182,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  3182,
    -743,  -743,  3182,  3182,  3182,  -743,  3182,  3182,  -743,  1586,
    -743,  -743,  -743,  -743,  -743,  3182,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  1586,  1586,  -743,  -743,
    -743,  -743,  -743,  -743,  1586,   838,  -743,  1586,   838,  -743,
    1586,  1586,  -743,   674,  -743,   689,   516,  3288,   693,   694,
    -743,   695,   696,  -743,  -743,   541,  3407,  -743,  3182,  4070,
     787,  1586,  -743,  1586,   234,    30,   705,  4081,   491,   491,
    4693,   699,   704,  -743,   703,  -743,  -743,  -743,  -743,  3182,
    3182,  -743,  -743,  4092,  2026,  2026,  1586,  1586,  1586,  -743,
    3182,  3182,   707,  4718,  4774,  1311,  1586,  5337,     4,  -743,
     709,  -743,    59,  -743,  -743,  -743,  4799,  4824,  4835,   393,
     714,   143,  -743,  -743,  4846,  4857,   715,    46,  4880,  4905,
    4963,  4986,  5011,  1719,  5022,  5033,   168,  5044,   209,   230,
     395,    69,   443,   246,   444,   453,    61,    61,  -743,  -743,
    -743,  -743,  3182,   837,   850,   848,  3836,  5069,  3182,   722,
     461,   247,  -743,  3182,  -743,  -743,  -743,  -743,  -743,  -743,
     727,   736,  5337,  5337,  1586,  -743,  -743,   234,   234,   269,
    4103,  5337,  -743,   821,   836,   839,  3182,   271,  3182,   594,
    3182,  -743,  -743,  -743,  -743,  -743,  -743,  1586,  -743,  -743,
    -743,  3182,  -743,  -743,  -743,  -743,  -743,  -743,  3182,  -743,
    -743,  -743,  1586,  -743,  -743,  3182,  -743,  3182,  -743,  -743,
    1586,  -743,  -743,  1586,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   862,   863,   570,  5092,  3182,   856,  1586,  5150,   491,
     745,   746,   491,  -743,  -743,   234,  1586,  1586,  1586,  1586,
    1586,  5175,  -743,  -743,   749,   750,   258,  -743,    70,   467,
    4129,  5198,   471,  5209,  5220,   473,   474,  3407,  3979,  3182,
     871,  -743,  -743,   751,  -743,  4154,   752,   477,  -743,  -743,
    -743,  -743,  -743,   234,   234,   234,   234,   234,   851,  -743,
     753,   754,  -743,   594,  3182,  -743,  -743,  3182,  -743,  -743,
    -743,  -743,  -743,  -743,   848,   889,   402,  3407,  -743,  1586,
    3182,  3182,  -743,   737,  1586,  -743,  -743,  3407,  -743,  5337,
    3407,  5231,  -743,  -743,   848,   576,   255,  5256,  4210,   491,
     234,   -10,   848,  -743,  3407,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  1586,  -743,  3182,  -743,  -743,  -743,  -743,
     577,   848,   484,  5281,  -743,  -743,  -743,  -743,  -743,  -743,
     923,   862,  -743,  -743,  -743,  -743,  -743
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     109,     0,     0,   107,   323,   358,   363,    11,     0,     0,
       0,     0,    24,    26,   301,     0,     0,     0,     0,   302,
      18,    20,   338,   350,     0,   430,    48,    60,     0,   104,
     105,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   110,   111,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       4,     3,     0,     7,    39,    41,     9,    22,    23,    21,
       0,    13,    14,    17,    16,    15,    28,    29,     0,   285,
       0,   285,     0,     0,     6,   278,   277,    30,    31,    38,
     274,   191,   131,   275,   276,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,   245,   248,   251,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
     204,   185,   190,   133,     0,     0,     0,    12,   285,   285,
      42,   303,    19,     0,     6,   382,     0,   434,     0,     0,
     410,   426,    62,    61,     0,     0,    63,   106,    53,     0,
      55,     0,   402,   404,    56,   400,   406,     0,     0,   407,
     271,    57,    59,     0,    89,     0,     0,   445,     0,    86,
      91,    79,    40,     0,     0,     0,    67,     0,    50,    72,
       0,    88,    87,     0,     0,   112,   113,    92,     8,    10,
       0,     0,   108,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,   292,   170,     0,   287,   114,     0,     0,   359,
       4,   285,   285,    32,    33,     0,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    36,   174,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,   307,    25,   304,
     312,   313,    27,   310,     0,     0,     0,   343,   342,     0,
       4,     0,   109,     0,     0,     0,   431,   432,     0,   413,
     415,    45,     0,     0,    49,   428,   285,   285,     0,     0,
       0,   285,   285,     0,   273,   272,     0,     0,    90,   444,
       0,     0,     0,    66,     0,    71,   426,   121,   120,     0,
       0,    68,     0,    74,     0,     0,   129,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     6,     0,     0,     0,
     171,   119,     0,   283,   290,   291,   286,   288,   284,   324,
       6,   370,   368,     0,   369,   365,   367,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,   246,     0,   249,     0,   252,     0,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   158,     0,     0,     0,     0,     0,   136,   205,
     199,   201,   203,   200,   202,   198,   135,     0,     0,     0,
       0,   178,   180,   182,   179,   181,   177,   196,   193,   192,
     194,   195,   285,   285,     0,   285,   285,     0,    43,    44,
     340,   344,   357,   355,   356,   353,   352,   354,   351,   372,
       4,     0,     0,     0,     0,     0,   411,    46,    47,     0,
     418,   420,     0,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   401,   408,   409,     0,     0,     0,   124,
     123,   127,   208,    51,    69,    82,    73,     0,     0,     0,
     285,     0,     0,     0,    96,    97,    98,    99,   100,   101,
       0,     5,     0,     0,     0,   298,   299,   293,     0,     0,
       4,   366,   264,   169,     0,     0,     0,   265,   266,     0,
       0,   259,     0,     0,   186,   187,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,     0,   216,   217,     0,
     219,   220,   183,   225,   226,   221,   222,   223,   224,     0,
     228,   233,     0,     0,     0,   232,     0,     0,   141,     0,
     146,   147,   234,   167,   235,     0,   168,   148,   149,   244,
     247,   250,   253,   152,   150,   151,     0,     0,   153,   241,
     154,   243,   242,   159,     0,     0,   162,     0,     0,   164,
       0,     0,   446,    35,   448,    37,   175,   173,     0,     0,
     305,     0,     0,   311,   341,   347,     6,   383,     0,     0,
     435,     0,   433,     0,   416,   414,   415,     0,     0,     0,
       0,   396,   398,   427,   393,   279,   281,   285,   285,     0,
       0,   403,   405,    64,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,    80,     0,    85,
       0,   289,     0,   362,   361,   360,     0,     0,     0,     0,
       0,     0,   206,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   309,
     314,   315,     0,     0,     0,   373,   109,     0,     0,     0,
       0,     0,   412,     0,   419,   421,   422,   285,   285,   394,
       0,     0,    52,    54,     0,   125,   126,   122,   128,    83,
      76,    77,   130,     0,     0,     0,     0,   102,     0,   316,
       0,   256,   257,   258,   267,   268,   269,     0,   188,   189,
     165,     0,   215,   218,   227,   137,   138,   140,     0,   230,
     231,   142,     0,   236,   237,     0,   239,     0,   160,   261,
       0,   161,   263,     0,   163,   184,   447,   449,   345,   348,
     339,   387,     4,   437,     0,     0,   436,     0,     0,     0,
       0,     0,     0,   280,   282,    65,     0,     0,     0,     0,
       0,     0,   285,    81,   319,   320,     0,   317,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     6,   109,     0,
     385,   384,   441,     0,   438,     0,     0,     0,   424,   423,
     397,   399,   395,    84,    75,   117,   118,   116,     0,   103,
       0,     0,   294,     0,     0,   325,   270,     0,   139,   143,
     238,   240,   260,   262,   346,     4,   391,     6,   374,     0,
       0,     0,   417,   428,     0,   321,   322,     6,   318,   335,
       6,     0,   392,   388,   386,     0,     0,     0,     0,     0,
     115,     4,   326,   166,     6,   381,   378,   379,   380,   376,
     377,   375,   442,     0,   439,     0,   425,   297,   296,   295,
       0,   389,     0,     0,   329,   331,   332,   333,   328,   330,
     336,   387,   443,   440,   337,   327,   390
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -743,  -743,   -79,  -743,   499,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   882,  -233,  -743,  -743,  -156,   782,  -743,   887,
     -11,  -743,  -743,   655,  -280,    78,  -743,   558,   -30,     8,
    -743,     1,     3,   -72,  -743,  -743,   304,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   379,  -743,   378,  -743,   -19,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   124,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   -84,  -743,  -743,  -743,
    -742,  -743,  -743,  -743,   568,  -743,  -743,   213,   567,  -743,
    -743,  -743,  -743,  -743,   -29,  -743,    37,  -743,  -743
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    59,    60,   256,    61,   174,   175,   547,   548,   191,
     416,    62,    63,   419,    64,    65,   427,   167,   168,    66,
     225,   550,   549,   469,   470,   226,   170,   209,   171,    87,
     196,   172,   173,   264,   265,   446,   447,    69,   442,   780,
     987,  1019,   637,    70,   368,   369,   372,   373,   926,   927,
      71,    82,   639,   990,  1020,  1030,   965,  1035,    72,   183,
     571,   379,   735,   937,   824,   938,    73,   184,   578,    74,
      83,   450,   785,    75,    84,   457,    76,   381,   736,   901,
     995,  1011,    77,   382,   826,   978,   940,  1004,  1031,   993,
     753,   912,   754,   204,   205,   211,   391,   586,   394,   748,
     749,   909,   983,   395,   594,   190,   218,   723,   725
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     169,    67,   472,    68,   210,   270,   834,   835,   417,   267,
     424,   425,    78,   185,  1017,   417,   193,    88,    89,   197,
     199,   201,   716,   350,   717,   217,   217,   217,   386,   590,
     435,   387,   591,  1018,   237,    90,   392,     1,     2,    93,
      94,   206,   186,   212,   187,   188,   217,    90,   240,   361,
     241,    93,    94,   604,   178,    80,   783,   417,   344,   345,
     346,   347,   348,   349,   350,    85,   350,   263,    86,   694,
     860,   695,   269,   682,   222,   223,   344,   345,   346,   347,
     348,   349,   964,   179,   784,    67,   236,    68,   350,   410,
     277,   428,   429,   713,   252,   714,   344,   345,   346,   347,
     348,   349,   194,   195,   350,   380,   375,   376,   353,   354,
      79,   683,   355,   356,   357,   358,   359,   360,   361,   229,
     230,   353,   354,   257,   258,   355,   356,   357,   358,   359,
     360,   361,   353,   354,   181,   259,   355,   356,   357,   358,
     359,   360,   361,   364,   365,   344,   345,   346,   347,   348,
     349,   182,   393,    81,   341,   343,   350,   350,   189,    52,
      53,    54,   350,   684,   433,   360,   361,   949,   224,   418,
     952,   245,   378,   273,   274,   350,   418,   404,   405,   390,
     648,   534,   649,   536,   350,    67,   719,    68,   720,   740,
     617,   741,   246,   388,   592,   350,   207,   208,   247,   458,
     459,   361,   407,   248,   409,   633,   634,   350,   207,   208,
     362,   363,   364,   365,   706,   451,   350,   452,   418,   453,
     231,   538,   249,   362,   363,   364,   365,   344,   345,   346,
     347,   348,   349,   250,   362,   363,   364,   365,   431,   889,
     658,   890,   454,   254,   350,   455,   232,   233,   234,   440,
     456,   587,   588,   235,   445,   350,   350,  1016,   362,   363,
     364,   365,   707,   715,   460,   461,    90,   462,   217,   217,
      93,    94,   255,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   217,   486,   487,   488,   489,   490,
     491,   492,   494,   362,   363,   364,   365,   260,   500,   501,
     502,   504,   505,   580,   507,   415,   509,   350,   350,   202,
     203,   421,   423,   866,   718,   867,   465,   466,   350,   261,
     350,   217,   262,   625,   595,   596,   350,   721,   268,   601,
     602,   538,   485,   350,   350,   437,   438,   439,   881,   681,
     882,  -371,   366,   367,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   350,   370,   371,   353,   354,
     685,   473,   355,   356,   357,   358,   359,   360,   361,   529,
      79,   640,   581,   350,   350,   350,   210,   584,   692,   884,
      92,   885,   766,    67,    95,    68,   467,   468,   599,   600,
     358,   359,   360,   361,   572,   350,   573,   350,   574,   350,
     886,   611,   887,   612,   768,    97,   344,   345,   346,   347,
     348,   349,   350,   618,   619,   384,   892,   538,   893,   907,
     350,   575,   627,   629,   576,  1012,   350,  1013,   962,   577,
     963,   597,   598,   776,   350,   811,   350,    67,   813,    68,
     350,   916,   641,   922,   350,   697,    81,   992,   398,   698,
     271,    67,   356,    68,   358,   359,   360,   361,   635,   636,
     362,   363,   364,   365,   353,   354,   272,   609,   355,   356,
     357,   358,   359,   360,   361,   107,   350,   108,   359,   360,
     361,   699,   607,   608,   350,   362,   363,   364,   365,   700,
     728,   729,   275,   731,   732,   751,   752,   614,   276,   350,
     616,   129,   130,   131,   701,   350,   278,   135,   136,   137,
     711,   139,   350,   141,   142,   143,   403,   702,   350,   350,
     148,   149,   150,   703,   704,   153,   350,   155,   279,   157,
     443,   705,   158,   159,   280,   161,   350,   163,   726,   727,
     406,   708,   350,   281,   176,   858,   436,   709,   772,   362,
     363,   364,   365,   351,   352,   722,   724,   350,   350,   282,
     350,   411,   710,   864,   871,   888,   362,   363,   364,   365,
     412,   739,   362,   363,   364,   365,   283,   746,   747,   822,
     823,   750,   355,   356,   357,   358,   359,   360,   361,  1005,
    1024,  1006,  1025,  1007,  1026,   763,   353,   354,   924,   925,
     355,   356,   357,   358,   359,   360,   361,   284,   350,   350,
     773,   774,   775,   891,   894,   285,  1008,  1027,   350,  1009,
    1028,   777,   420,   895,  1010,  1029,   350,   445,   782,   942,
     943,   906,   350,   786,   787,   788,   350,   966,   350,   350,
     426,   969,   350,   972,   973,   794,   795,   982,   797,   350,
     286,   287,   288,   449,  1032,   798,   289,   825,   799,   290,
     434,   291,   292,   293,   294,   295,   296,   297,   800,   298,
     299,   801,   802,   803,   300,   804,   805,   301,   302,   303,
     362,   363,   364,   365,   807,   840,   841,   304,   305,   306,
     307,   308,   309,   310,   311,   769,   312,   313,   362,   363,
     364,   365,   314,   361,   315,   316,   317,   318,   319,   320,
     570,   778,   779,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   827,   335,   336,
     337,   338,   339,   340,   383,   385,   796,    67,   396,    68,
     397,   401,   402,   579,   448,   531,   593,   902,   842,   843,
     532,   564,   562,   217,   217,   585,   563,   565,   566,   850,
     851,   568,   567,   569,   582,   910,   911,   353,   354,   589,
     620,   355,   356,   357,   358,   359,   360,   361,   353,   354,
     621,   622,   355,   356,   357,   358,   359,   360,   361,   623,
     632,   638,   642,   643,   647,   651,   652,   177,   650,   653,
     180,   845,   846,   654,   655,   734,   737,   672,   656,   192,
     657,   378,   712,   198,   200,   755,   756,   904,   216,   757,
     758,   764,   908,   761,   896,   897,   762,    67,   765,    68,
     242,   243,   244,   356,   357,   358,   359,   360,   361,   251,
     253,   792,   793,   468,   829,   921,   816,   353,   354,   928,
     959,   355,   356,   357,   358,   359,   360,   361,   974,   975,
     930,   817,   266,   818,   819,   820,   821,   931,   837,   362,
     363,   364,   365,   838,   933,   839,   934,   852,   859,   899,
     362,   363,   364,   365,   865,   870,   665,   900,   666,    92,
      -4,   905,   918,    95,   945,   353,   354,   913,   994,   355,
     356,   357,   358,   359,   360,   361,   914,   919,  1001,   939,
     920,  1002,   941,   946,    97,   950,   951,   977,   960,   961,
     979,   981,   984,   985,   986,  1021,  -349,  1034,   976,   238,
     362,   363,   364,   365,   239,   631,   923,   471,    67,    67,
      68,    68,   781,   730,   988,   733,   898,  1036,   342,   362,
     363,   364,   365,   989,   999,   668,   991,   669,   374,   832,
       0,     0,     0,     0,   605,   377,     0,     0,     0,   997,
     998,   603,   389,     0,     0,     0,     0,     0,    67,     0,
      68,     0,     0,   613,   107,     0,   108,     0,    67,     0,
      68,    67,     0,    68,     0,     0,   408,   362,   363,   364,
     365,     0,     0,   539,  1023,    67,   413,    68,     0,     0,
     129,   130,   131,     0,     0,     0,   135,   136,   137,     0,
     139,     0,   141,   142,   143,     0,     0,     0,     0,   148,
     149,   150,   432,     0,   153,     0,   155,     0,   157,     0,
       0,   158,   159,   441,   161,     0,   163,   444,     0,     0,
       0,     0,     0,   176,   512,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,     0,   353,   354,     0,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
     499,     0,     0,     0,     0,     0,   506,     0,   508,     0,
     510,   511,   513,   515,   517,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   530,     0,     0,   533,     0,
     535,     0,   537,     0,     0,     0,   540,   541,   542,   543,
     544,   545,   546,     0,     0,     0,     0,    90,    91,    92,
       0,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,     0,   583,   362,   363,
     364,   365,     0,     0,   688,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,     0,     0,    99,   100,   101,   102,
       0,     0,   615,     0,    92,     0,     0,     0,    95,     0,
     103,     0,     0,   104,     0,   626,   628,   630,   219,     0,
       0,     0,     0,     0,     0,     0,   220,     0,     0,    97,
     105,   106,     0,     0,   107,     0,   108,     0,     0,   221,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   107,
       0,   108,     0,   166,   353,   354,     0,   215,   355,   356,
     357,   358,   359,   360,   361,    92,     0,     0,     0,    95,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   135,   136,   137,     0,   139,     0,   141,   142,   143,
      97,     0,     0,     0,   148,   149,   150,     0,     0,   153,
       0,   155,     0,   157,     0,     0,   158,   159,     0,   161,
       0,   163,     0,     0,     0,     0,     0,   744,   176,   514,
     745,     0,     0,   353,   354,     0,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     107,     0,   108,     0,   399,     0,     0,   353,   354,     0,
     444,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,   789,   791,     0,     0,     0,   129,   130,   131,     0,
       0,    92,   135,   136,   137,    95,   139,     0,   141,   142,
     143,     0,     0,     0,     0,   148,   149,   150,     0,     0,
     153,     0,   155,     0,   157,     0,    97,   158,   159,     0,
     161,   806,   163,     0,     0,   362,   363,   364,   365,   176,
     516,   855,     0,   856,     0,     0,     0,     0,   808,   809,
      92,     0,     0,     0,    95,     0,   810,     0,     0,   812,
       0,     0,   814,   815,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,   362,
     363,   364,   365,   830,     0,   831,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   847,   848,
     849,     0,     0,     0,     0,     0,     0,     0,   857,     0,
       0,     0,   129,   130,   131,     0,     0,     0,   135,   136,
     137,     0,   139,     0,   141,   142,   143,   790,     0,     0,
       0,   148,   149,   150,     0,   107,   153,   108,   155,     0,
     157,    92,     0,   158,   159,    95,   161,     0,   163,     0,
       0,     0,     0,     0,   377,   176,   518,     0,     0,     0,
       0,   129,   130,   131,     0,     0,    97,   135,   136,   137,
       0,   139,     0,   141,   142,   143,   915,     0,     0,     0,
     148,   149,   150,     0,     0,   153,     0,   155,     0,   157,
       0,     0,   158,   159,     0,   161,     0,   163,     0,   929,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   932,     0,     0,     0,     0,     0,
       0,     0,   935,     0,     0,   936,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,   108,   947,
       0,     0,     0,     0,     0,     0,     0,     0,   953,   954,
     955,   956,   957,    90,    91,    92,     0,    93,    94,    95,
       0,     0,   129,   130,   131,     0,     0,     0,   135,   136,
     137,     0,   139,     0,   141,   142,   143,     0,     0,    96,
      97,   148,   149,   150,     0,     0,   153,     0,   155,     0,
     157,     0,     0,   158,   159,     0,   161,     0,   163,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,     0,
       0,   996,    99,   100,   101,   102,  1000,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,   104,
       0,   353,   354,     0,   213,   355,   356,   357,   358,   359,
     360,   361,   214,     0,     0,  1022,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,   158,   159,   160,
     161,   162,   163,   164,   165,     0,    90,    91,    92,   166,
      93,    94,    95,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   364,   365,     0,     0,   877,
       0,   878,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     353,   354,   104,     0,   355,   356,   357,   358,   359,   360,
     361,     0,     0,     0,     0,   463,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   165,     0,    90,
      91,    92,   166,    93,    94,    95,   215,     0,     0,     0,
       0,     0,   362,   363,   364,   365,     0,     0,     0,     0,
     414,     0,     0,     0,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   353,   354,   104,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,     0,     0,   107,     0,   108,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,   158,   159,   160,   161,   162,   163,   164,
     165,     0,    90,    91,    92,   166,    93,    94,    95,   215,
       0,     0,     0,     0,     0,   362,   363,   364,   365,     0,
       0,     0,     0,   606,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   353,   354,   104,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,     0,     0,   166,   430,
      90,    91,    92,     0,    93,    94,    95,     0,   362,   363,
     364,   365,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   353,   354,   104,     0,   355,   356,
     357,   358,   359,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,   107,     0,   108,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,   158,   159,   160,   161,   162,   163,
     164,   165,     0,     0,     0,     0,   166,   493,    90,    91,
      92,     0,    93,    94,    95,     0,   362,   363,   364,   365,
       0,     0,     0,     0,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,   104,   353,   354,     0,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,   158,   159,   160,   161,   162,   163,   164,   165,
       0,     0,     0,     0,   166,   503,    90,    91,    92,     0,
      93,    94,    95,     0,   227,     0,     0,   362,   363,   364,
     365,     0,     0,     0,     0,   646,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     353,   354,   104,     0,   355,   356,   357,   358,   359,   360,
     361,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
     158,   159,   160,   161,   162,   163,   164,   165,     0,    90,
      91,    92,   166,    93,    94,    95,     0,     0,     0,     0,
       0,     0,   362,   363,   364,   365,     0,     0,     0,     0,
     659,     0,     0,     0,     0,    96,    97,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   353,   354,   104,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,     0,     0,   107,     0,   108,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,   158,   159,   160,   161,   162,   163,   164,
     165,     0,    90,    91,    92,   166,    93,    94,    95,     0,
     422,     0,     0,     0,     0,   362,   363,   364,   365,     0,
       0,     0,     0,   679,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   353,   354,   104,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,   158,   159,   160,   161,
     162,   163,   164,   165,     0,    90,    91,    92,   166,    93,
      94,    95,     0,     0,     0,     0,     0,     0,   362,   363,
     364,   365,     0,     0,     0,     0,   686,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,    92,     0,     0,     0,    95,     0,   103,   353,
     354,   104,     0,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,    97,   105,   106,
       0,     0,   107,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   107,     0,   108,
     353,   166,     0,     0,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,     0,     0,     0,     0,   687,
       0,     0,     0,   129,   130,   131,     0,     0,     0,   135,
     136,   137,     0,   139,     0,   141,   142,   143,     0,     0,
       0,     0,   148,   149,   150,     0,     0,   153,     0,   155,
       0,   157,     0,     0,   158,   159,     0,   161,     0,   163,
       0,     1,     2,     3,     0,     0,   743,     4,     0,     0,
       0,     5,     0,     6,     0,     7,     8,     9,    10,    11,
    -300,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,     0,     0,     0,     0,    23,     0,
       0,    24,   362,   363,   364,   365,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,  -109,  -109,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,  -109,     0,    49,     0,
      50,    51,   353,   354,     0,     0,   355,   356,   357,   358,
     359,   360,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     0,    56,     0,
       4,     0,    57,    58,     5,     0,     6,     0,     7,     8,
       9,    10,    11,  -300,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,     0,     0,     0,
       0,    23,    -6,    -6,    24,     0,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,     0,     0,     0,
      31,    32,     0,     0,   362,   363,   364,   365,     0,     0,
       0,     0,   738,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,    39,    40,    41,     0,     0,    42,
      43,    44,     0,    45,    46,    47,     0,     0,    48,     0,
       0,    49,     0,    50,    51,   353,   354,     0,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       0,    56,     0,     4,     0,    57,    58,     5,     0,     6,
       0,     7,     8,     9,    10,    11,  -300,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
       0,     0,     0,     0,    23,    -6,     0,    24,     0,     0,
       0,    -6,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,   362,   363,   364,
     365,     0,     0,     0,     0,   759,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
       0,     0,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,     0,     0,    49,     0,    50,    51,   353,   354,
       0,     0,   355,   356,   357,   358,   359,   360,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,    56,     0,     4,     0,    57,    58,
       5,     0,     6,     0,     7,     8,     9,    10,    11,  -300,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    -6,     0,
      24,     0,     0,     0,     0,    -6,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
     362,   363,   364,   365,     0,     0,     0,     0,   760,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,   353,   354,     0,     0,   355,   356,   357,   358,   359,
     360,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,    56,     0,     4,
       0,    57,    58,     5,     0,     6,     0,     7,     8,     9,
      10,    11,  -300,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    -6,     0,     0,     0,
      23,    -6,     0,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,   362,   363,   364,   365,     0,     0,     0,
       0,   767,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,   353,   354,     0,     0,   355,   356,
     357,   358,   359,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,   353,
     354,     0,    55,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,   353,   354,    57,    58,   355,   356,   357,   358,
     359,   360,   361,   353,   354,     0,     0,   355,   356,   357,
     358,   359,   360,   361,   353,   354,     0,     0,   355,   356,
     357,   358,   359,   360,   361,   353,   354,     0,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
       0,   353,   354,     0,   770,   355,   356,   357,   358,   359,
     360,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365,     0,   353,   354,     0,   771,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,   365,     0,     0,
       0,     0,   828,     0,     0,   362,   363,   364,   365,     0,
       0,     0,     0,   833,     0,     0,   362,   363,   364,   365,
       0,     0,     0,     0,   844,     0,     0,   362,   363,   364,
     365,     0,   353,   354,     0,   917,   355,   356,   357,   358,
     359,   360,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   364,   365,     0,   353,   354,
       0,   967,   355,   356,   357,   358,   359,   360,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,   363,
     364,   365,     0,   353,   354,     0,   980,   355,   356,   357,
     358,   359,   360,   361,   353,   354,     0,     0,   355,   356,
     357,   358,   359,   360,   361,   353,   354,     0,     0,   355,
     356,   357,   358,   359,   360,   361,   353,   354,     0,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,   365,     0,   353,
     354,     0,  1015,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,   363,   364,   365,   353,   354,   624,     0,   355,   356,
     357,   358,   359,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   363,   364,   365,     0,
       0,   660,     0,     0,     0,     0,   362,   363,   364,   365,
       0,     0,   661,     0,     0,     0,     0,   362,   363,   364,
     365,     0,     0,   662,     0,     0,     0,     0,   362,   363,
     364,   365,   353,   354,   663,     0,   355,   356,   357,   358,
     359,   360,   361,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365,   353,   354,   664,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     353,   354,   667,     0,   355,   356,   357,   358,   359,   360,
     361,   353,   354,     0,     0,   355,   356,   357,   358,   359,
     360,   361,   353,   354,     0,     0,   355,   356,   357,   358,
     359,   360,   361,   353,   354,     0,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,   365,   353,   354,
     670,     0,   355,   356,   357,   358,   359,   360,   361,     0,
       0,     0,     0,     0,     0,     0,     0,   362,   363,   364,
     365,   353,   354,   671,     0,   355,   356,   357,   358,   359,
     360,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   362,   363,   364,   365,     0,     0,   673,     0,
       0,     0,     0,   362,   363,   364,   365,     0,     0,   674,
       0,     0,     0,     0,   362,   363,   364,   365,     0,     0,
     675,     0,     0,     0,     0,   362,   363,   364,   365,   353,
     354,   676,     0,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,   363,   364,   365,   353,   354,   677,     0,   355,   356,
     357,   358,   359,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   364,   365,   353,   354,   678,
       0,   355,   356,   357,   358,   359,   360,   361,   353,   354,
       0,     0,   355,   356,   357,   358,   359,   360,   361,   353,
     354,     0,     0,   355,   356,   357,   358,   359,   360,   361,
     353,   354,     0,     0,   355,   356,   357,   358,   359,   360,
     361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365,   353,   354,   680,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     353,   354,   690,     0,   355,   356,   357,   358,   359,   360,
     361,     0,     0,     0,     0,     0,     0,     0,     0,   362,
     363,   364,   365,     0,     0,   691,     0,     0,     0,     0,
     362,   363,   364,   365,     0,     0,   693,     0,     0,     0,
       0,   362,   363,   364,   365,     0,     0,   696,     0,     0,
       0,     0,   362,   363,   364,   365,   353,   354,   742,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   362,   363,   364,
     365,   353,   354,   836,     0,   355,   356,   357,   358,   359,
     360,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   362,   363,   364,   365,   353,   354,   853,     0,
     355,   356,   357,   358,   359,   360,   361,   353,   354,     0,
       0,   355,   356,   357,   358,   359,   360,   361,   353,   354,
       0,     0,   355,   356,   357,   358,   359,   360,   361,   353,
     354,     0,     0,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,   362,   363,
     364,   365,   353,   354,   854,     0,   355,   356,   357,   358,
     359,   360,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   364,   365,   353,   354,   861,
       0,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,   363,
     364,   365,     0,     0,   862,     0,     0,     0,     0,   362,
     363,   364,   365,     0,     0,   863,     0,     0,     0,     0,
     362,   363,   364,   365,     0,     0,   868,     0,     0,     0,
       0,   362,   363,   364,   365,   353,   354,   869,     0,   355,
     356,   357,   358,   359,   360,   361,     0,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,   365,   353,   354,
     872,     0,   355,   356,   357,   358,   359,   360,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   362,
     363,   364,   365,   353,   354,   873,     0,   355,   356,   357,
     358,   359,   360,   361,   353,   354,     0,     0,   355,   356,
     357,   358,   359,   360,   361,   353,   354,     0,     0,   355,
     356,   357,   358,   359,   360,   361,   353,   354,     0,     0,
     355,   356,   357,   358,   359,   360,   361,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   362,   363,   364,
     365,   353,   354,   874,     0,   355,   356,   357,   358,   359,
     360,   361,     0,     0,     0,     0,     0,     0,     0,     0,
     362,   363,   364,   365,   353,   354,   875,     0,   355,   356,
     357,   358,   359,   360,   361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   363,   364,   365,     0,
       0,   876,     0,     0,     0,     0,   362,   363,   364,   365,
       0,     0,   879,     0,     0,     0,     0,   362,   363,   364,
     365,     0,     0,   880,     0,     0,     0,     0,   362,   363,
     364,   365,   353,   354,   883,     0,   355,   356,   357,   358,
     359,   360,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   364,   365,   353,   354,   903,
       0,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,   364,   365,
     353,   354,   944,     0,   355,   356,   357,   358,   359,   360,
     361,   353,   354,     0,     0,   355,   356,   357,   358,   359,
     360,   361,   353,   354,     0,     0,   355,   356,   357,   358,
     359,   360,   361,   353,   354,     0,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,   363,   364,   365,   353,   354,
     948,     0,   355,   356,   357,   358,   359,   360,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   362,
     363,   364,   365,   353,   354,   958,     0,   355,   356,   357,
     358,   359,   360,   361,     0,     0,     0,     0,     0,     0,
       0,     0,   362,   363,   364,   365,     0,     0,   968,     0,
       0,     0,     0,   362,   363,   364,   365,     0,     0,   970,
       0,     0,     0,     0,   362,   363,   364,   365,     0,     0,
     971,     0,     0,     0,     0,   362,   363,   364,   365,   353,
     354,  1003,     0,   355,   356,   357,   358,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,   363,   364,   365,     0,     0,  1014,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   363,   364,   365,     0,
       0,  1033,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   363,   364,   365
};

static const yytype_int16 yycheck[] =
{
      11,     0,   282,     0,    34,    84,   748,   749,    11,    81,
     243,   244,    71,    24,    24,    11,    27,     9,    10,    30,
      31,    32,   170,   165,   172,    36,    37,    38,     4,     4,
     172,     7,     7,    43,    45,     3,    57,     4,     5,     7,
       8,     9,    57,    35,    59,    60,    57,     3,    47,    72,
      47,     7,     8,     9,   169,    71,    15,    11,    66,    67,
      68,    69,    70,    71,   165,     4,   165,    78,     7,   170,
      11,   172,    83,   172,    37,    38,    66,    67,    68,    69,
      70,    71,    12,   169,    43,    84,    90,    84,   165,    10,
     101,   247,   248,   170,    57,   172,    66,    67,    68,    69,
      70,    71,     4,     5,   165,   184,   178,   179,    62,    63,
     169,   172,    66,    67,    68,    69,    70,    71,    72,    41,
      42,    62,    63,    87,    88,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    27,    99,    66,    67,    68,    69,
      70,    71,    72,   166,   167,    66,    67,    68,    69,    70,
      71,     7,   173,   169,   165,   166,   165,   165,   173,   126,
     127,   128,   165,   172,   172,    71,    72,   909,    83,   172,
     912,   105,   183,    34,    35,   165,   172,   207,   208,   190,
     170,   337,   172,   339,   165,   184,   170,   184,   172,   170,
     423,   172,   169,   169,   169,   165,   164,   165,   169,   271,
     272,    72,   213,   169,   215,   438,   439,   165,   164,   165,
     164,   165,   166,   167,   172,    13,   165,    15,   172,    17,
      58,   170,   169,   164,   165,   166,   167,    66,    67,    68,
      69,    70,    71,   169,   164,   165,   166,   167,   249,   170,
     473,   172,    40,     0,   165,    43,    84,    85,    86,   260,
      48,   171,   172,    91,   265,   165,   165,   999,   164,   165,
     166,   167,   172,   172,   275,   276,     3,   278,   279,   280,
       7,     8,    43,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   164,   165,   166,   167,    71,   309,   310,
     311,   312,   313,   382,   315,   227,   317,   165,   165,     4,
       5,   233,   234,   170,   172,   172,   279,   280,   165,    71,
     165,   332,    23,   170,   396,   397,   165,   172,     4,   401,
     402,   170,   295,   165,   165,   257,   258,   259,   170,   170,
     172,    45,     4,     5,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   165,     4,     5,    62,    63,
     170,   283,    66,    67,    68,    69,    70,    71,    72,   332,
     169,   450,   383,   165,   165,   165,   406,   388,   170,   170,
       5,   172,   172,   382,     9,   382,     4,     5,   399,   400,
      69,    70,    71,    72,    13,   165,    15,   165,    17,   165,
     170,   412,   172,   414,   172,    30,    66,    67,    68,    69,
      70,    71,   165,   424,   425,    57,   170,   170,   172,   172,
     165,    40,   433,   434,    43,   170,   165,   172,   170,    48,
     172,     4,     5,   172,   165,   715,   165,   436,   718,   436,
     165,   172,   453,   172,   165,   170,   169,    45,   172,   170,
     169,   450,    67,   450,    69,    70,    71,    72,     4,     5,
     164,   165,   166,   167,    62,    63,   169,    92,    66,    67,
      68,    69,    70,    71,    72,   100,   165,   102,    70,    71,
      72,   170,    81,    82,   165,   164,   165,   166,   167,   170,
     562,   563,   169,   565,   566,     4,     5,   419,   169,   165,
     422,   126,   127,   128,   170,   165,   169,   132,   133,   134,
     170,   136,   165,   138,   139,   140,   172,   170,   165,   165,
     145,   146,   147,   170,   170,   150,   165,   152,   169,   154,
     170,   170,   157,   158,   169,   160,   165,   162,   549,   550,
     172,   170,   165,   169,   169,   778,    42,   170,   620,   164,
     165,   166,   167,    19,    20,   547,   548,   165,   165,   169,
     165,   172,   170,   170,   797,   170,   164,   165,   166,   167,
     172,   582,   164,   165,   166,   167,   169,   588,   589,    38,
      39,   592,    66,    67,    68,    69,    70,    71,    72,    13,
      13,    15,    15,    17,    17,   606,    62,    63,     4,     5,
      66,    67,    68,    69,    70,    71,    72,   169,   165,   165,
     621,   622,   623,   170,   170,   169,    40,    40,   165,    43,
      43,   632,   172,   170,    48,    48,   165,   638,   639,    59,
      60,   170,   165,   644,   645,   646,   165,   170,   165,   165,
       5,   170,   165,   170,   170,   656,   657,   170,   659,   165,
     169,   169,   169,    71,   170,   666,   169,   736,   669,   169,
     172,   169,   169,   169,   169,   169,   169,   169,   679,   169,
     169,   682,   683,   684,   169,   686,   687,   169,   169,   169,
     164,   165,   166,   167,   695,   757,   758,   169,   169,   169,
     169,   169,   169,   169,   169,   617,   169,   169,   164,   165,
     166,   167,   169,    72,   169,   169,   169,   169,   169,   169,
      42,   633,   634,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   738,   169,   169,
     169,   169,   169,   169,   169,   169,   658,   736,   169,   736,
     169,   169,   169,    45,   170,   170,     9,   826,   759,   760,
     170,   172,   169,   764,   765,    50,   169,   169,   169,   770,
     771,   170,   172,   170,   169,   837,   838,    62,    63,   169,
     169,    66,    67,    68,    69,    70,    71,    72,    62,    63,
     172,   172,    66,    67,    68,    69,    70,    71,    72,   172,
     172,   172,   170,   170,   170,   170,   169,    15,   172,   169,
      18,   764,   765,   170,   170,    42,    48,   170,   172,    27,
     172,   822,   170,    31,    32,   170,   170,   828,    36,   169,
     169,    80,   833,   170,   816,   817,   170,   826,    80,   826,
      48,    49,    50,    67,    68,    69,    70,    71,    72,    57,
      58,   170,   170,     5,    57,   856,   172,    62,    63,   860,
     922,    66,    67,    68,    69,    70,    71,    72,   937,   938,
     871,   172,    80,   170,   170,   170,   170,   878,   169,   164,
     165,   166,   167,   169,   885,   172,   887,   170,   169,    42,
     164,   165,   166,   167,   170,   170,   170,    37,   172,     5,
      42,   169,    71,     9,   905,    62,    63,   170,   977,    66,
      67,    68,    69,    70,    71,    72,   170,    71,   987,    47,
      71,   990,    49,    57,    30,   170,   170,    46,   169,   169,
     169,   169,    71,   170,   170,  1004,    37,     4,   939,    47,
     164,   165,   166,   167,    47,   436,   858,   282,   937,   938,
     937,   938,   638,   564,   963,   567,   822,  1031,   166,   164,
     165,   166,   167,   964,   983,   170,   967,   172,   176,   746,
      -1,    -1,    -1,    -1,   406,   183,    -1,    -1,    -1,   980,
     981,   403,   190,    -1,    -1,    -1,    -1,    -1,   977,    -1,
     977,    -1,    -1,   416,   100,    -1,   102,    -1,   987,    -1,
     987,   990,    -1,   990,    -1,    -1,   214,   164,   165,   166,
     167,    -1,    -1,   170,  1015,  1004,   224,  1004,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,   250,    -1,   150,    -1,   152,    -1,   154,    -1,
      -1,   157,   158,   261,   160,    -1,   162,   265,    -1,    -1,
      -1,    -1,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,
     308,    -1,    -1,    -1,    -1,    -1,   314,    -1,   316,    -1,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,    -1,    -1,   336,    -1,
     338,    -1,   340,    -1,    -1,    -1,   344,   345,   346,   347,
     348,   349,   350,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,   385,   164,   165,
     166,   167,    -1,    -1,   170,    -1,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   411,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,   420,    -1,     5,    -1,    -1,    -1,     9,    -1,
      76,    -1,    -1,    79,    -1,   433,   434,   435,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    30,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   100,
      -1,   102,    -1,   169,    62,    63,    -1,   173,    66,    67,
      68,    69,    70,    71,    72,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      30,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,   158,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,   585,   169,   170,
     588,    -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     100,    -1,   102,    -1,   172,    -1,    -1,    62,    63,    -1,
     638,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,   649,   650,    -1,    -1,    -1,   126,   127,   128,    -1,
      -1,     5,   132,   133,   134,     9,   136,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,
     150,    -1,   152,    -1,   154,    -1,    30,   157,   158,    -1,
     160,   689,   162,    -1,    -1,   164,   165,   166,   167,   169,
     170,   170,    -1,   172,    -1,    -1,    -1,    -1,   706,   707,
       5,    -1,    -1,    -1,     9,    -1,   714,    -1,    -1,   717,
      -1,    -1,   720,   721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,   164,
     165,   166,   167,   741,    -1,   743,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   766,   767,
     768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    92,    -1,    -1,
      -1,   145,   146,   147,    -1,   100,   150,   102,   152,    -1,
     154,     5,    -1,   157,   158,     9,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,   822,   169,   170,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    30,   132,   133,   134,
      -1,   136,    -1,   138,   139,   140,   844,    -1,    -1,    -1,
     145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,   154,
      -1,    -1,   157,   158,    -1,   160,    -1,   162,    -1,   867,
      -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   882,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   890,    -1,    -1,   893,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   907,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,   917,
     918,   919,   920,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    29,
      30,   145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,   979,    62,    63,    64,    65,   984,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    62,    63,    -1,    84,    66,    67,    68,    69,    70,
      71,    72,    92,    -1,    -1,  1013,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,     3,     4,     5,   169,
       7,     8,     9,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,
      -1,   172,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      62,    63,    79,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,     3,
       4,     5,   169,     7,     8,     9,   173,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    62,    63,    79,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,     3,     4,     5,   169,     7,     8,     9,   173,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    62,    63,    79,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,   169,   170,
       3,     4,     5,    -1,     7,     8,     9,    -1,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    62,    63,    79,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,   102,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,   169,   170,     3,     4,
       5,    -1,     7,     8,     9,    -1,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,   169,   170,     3,     4,     5,    -1,
       7,     8,     9,    -1,    11,    -1,    -1,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      62,    63,    79,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,     3,
       4,     5,   169,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    -1,    -1,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    62,    63,    79,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,     3,     4,     5,   169,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    62,    63,    79,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,     3,     4,     5,   169,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    76,    62,
      63,    79,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    96,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   100,    -1,   102,
      62,   169,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,   164,   165,   166,   167,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,   154,    -1,    -1,   157,   158,    -1,   160,    -1,   162,
      -1,     4,     5,     6,    -1,    -1,   169,    10,    -1,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    44,   164,   165,   166,   167,    -1,    -1,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,   101,    -1,
     103,   104,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,   151,    -1,
      10,    -1,   155,   156,    14,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,   172,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    -1,    -1,    89,
      90,    91,    -1,    93,    94,    95,    -1,    -1,    98,    -1,
      -1,   101,    -1,   103,   104,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,   151,    -1,    10,    -1,   155,   156,    14,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,   164,   165,   166,
     167,    -1,    -1,    -1,    -1,   172,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      -1,    -1,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    -1,   103,   104,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,   151,    -1,    10,    -1,   155,   156,
      14,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,   172,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    -1,    -1,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,   103,
     104,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,   151,    -1,    10,
      -1,   155,   156,    14,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,   172,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    -1,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    62,
      63,    -1,   133,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    62,    63,   155,   156,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      -1,    62,    63,    -1,   172,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    -1,    62,    63,    -1,   172,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,   172,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,   172,    -1,    -1,   164,   165,   166,
     167,    -1,    62,    63,    -1,   172,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    -1,    62,    63,
      -1,   172,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    -1,    62,    63,    -1,   172,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,    62,
      63,    -1,   172,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    62,    63,   170,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,   170,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      -1,    -1,   170,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    -1,    -1,   170,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    62,    63,   170,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    62,    63,   170,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      62,    63,   170,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    62,    63,
     170,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    62,    63,   170,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
     170,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    62,
      63,   170,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    62,    63,   170,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    62,    63,   170,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    62,    63,   170,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      62,    63,   170,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,    -1,    -1,   170,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,   170,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    -1,    -1,   170,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    62,    63,   170,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    62,    63,   170,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    62,    63,   170,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    62,    63,   170,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    62,    63,   170,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    -1,    -1,   170,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,    -1,    -1,   170,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,   170,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    62,    63,   170,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    62,    63,
     170,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,    62,    63,   170,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    62,    63,   170,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    62,    63,   170,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,   170,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      -1,    -1,   170,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    -1,    -1,   170,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    62,    63,   170,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    62,    63,   170,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      62,    63,   170,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    62,    63,
     170,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,    62,    63,   170,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,   170,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
     170,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    62,
      63,   170,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,    10,    14,    16,    18,    19,    20,
      21,    22,    25,    26,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    41,    44,    51,    52,    53,    54,    55,
      56,    60,    61,    73,    74,    75,    76,    77,    78,    84,
      85,    86,    89,    90,    91,    93,    94,    95,    98,   101,
     103,   104,   126,   127,   128,   133,   151,   155,   156,   175,
     176,   178,   185,   186,   188,   189,   193,   205,   206,   211,
     217,   224,   232,   240,   243,   247,   250,   256,    71,   169,
      71,   169,   225,   244,   248,     4,     7,   203,   203,   203,
       3,     4,     5,     7,     8,     9,    29,    30,    33,    62,
      63,    64,    65,    76,    79,    96,    97,   100,   102,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   157,   158,
     159,   160,   161,   162,   163,   164,   169,   191,   192,   194,
     200,   202,   205,   206,   179,   180,   169,   191,   169,   169,
     191,    27,     7,   233,   241,   194,    57,    59,    60,   173,
     279,   183,   191,   194,     4,     5,   204,   194,   191,   194,
     191,   194,     4,     5,   267,   268,     9,   164,   165,   201,
     202,   269,   203,    84,    92,   173,   191,   194,   280,    84,
      92,   105,   280,   280,    83,   194,   199,    11,    52,   199,
     199,    58,    84,    85,    86,    91,    90,   194,   186,   193,
     205,   206,   191,   191,   191,   105,   169,   169,   169,   169,
     169,   191,   280,   191,     0,    43,   177,    87,    88,    99,
      71,    71,    23,   194,   207,   208,   191,   207,     4,   194,
     176,   169,   169,    34,    35,   169,   169,   194,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   194,   191,   194,    66,    67,    68,    69,    70,    71,
     165,    19,    20,    62,    63,    66,    67,    68,    69,    70,
      71,    72,   164,   165,   166,   167,     4,     5,   218,   219,
       4,     5,   220,   221,   191,   207,   207,   191,   194,   235,
     176,   251,   257,   169,    57,   169,     4,     7,   169,   191,
     194,   270,    57,   173,   272,   277,   169,   169,   172,   172,
     172,   169,   169,   172,   202,   202,   172,   194,   191,   194,
      10,   172,   172,   191,   172,   199,   184,    11,   172,   187,
     172,   199,    11,   199,   187,   187,     5,   190,   190,   190,
     170,   194,   191,   172,   172,   172,    42,   199,   199,   199,
     194,   191,   212,   170,   191,   194,   209,   210,   170,    71,
     245,    13,    15,    17,    40,    43,    48,   249,   207,   207,
     194,   194,   194,    92,   191,   280,   280,     4,     5,   197,
     198,   197,   198,   199,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   280,   194,   194,   194,   194,
     194,   194,   194,   170,   194,   191,   191,   191,   191,   191,
     194,   194,   194,   170,   194,   194,   191,   194,   191,   194,
     191,   191,   170,   191,   170,   191,   170,   191,   170,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   280,
     191,   170,   170,   191,   190,   191,   190,   191,   170,   170,
     191,   191,   191,   191,   191,   191,   191,   181,   182,   196,
     195,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   169,   169,   172,   169,   169,   172,   170,   170,
      42,   234,    13,    15,    17,    40,    43,    48,   242,    45,
     176,   194,   169,   191,   194,    50,   271,   171,   172,   169,
       4,     7,   169,     9,   278,   207,   207,     4,     5,   194,
     194,   207,   207,   268,     9,   201,   172,    81,    82,    92,
     191,   194,   194,   272,   199,   191,   199,   187,   194,   194,
     169,   172,   172,   172,   170,   170,   191,   194,   191,   194,
     191,   178,   172,   187,   187,     4,     5,   216,   172,   226,
     176,   194,   170,   170,   172,   172,   172,   170,   170,   172,
     172,   170,   169,   169,   170,   170,   172,   172,   187,   172,
     170,   170,   170,   170,   170,   170,   172,   170,   170,   172,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   172,
     170,   170,   172,   172,   172,   170,   172,   172,   170,   172,
     170,   170,   170,   170,   170,   172,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   172,   172,   170,   170,
     170,   170,   170,   170,   172,   172,   170,   172,   172,   170,
     172,   172,   203,   281,   203,   282,   194,   194,   207,   207,
     219,   207,   207,   221,    42,   236,   252,    48,   172,   194,
     170,   172,   170,   169,   191,   191,   194,   194,   273,   274,
     194,     4,     5,   264,   266,   170,   170,   169,   169,   172,
     172,   170,   170,   194,    80,    80,   172,   172,   172,   199,
     172,   172,   207,   194,   194,   194,   172,   194,   199,   199,
     213,   210,   194,    15,    43,   246,   194,   194,   194,   191,
      92,   191,   170,   170,   194,   194,   199,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   191,   194,   191,   191,
     191,   198,   191,   198,   191,   191,   172,   172,   170,   170,
     170,   170,    38,    39,   238,   176,   258,   194,   172,    57,
     191,   191,   271,   172,   264,   264,   170,   169,   169,   172,
     207,   207,   194,   194,   172,   280,   280,   191,   191,   191,
     194,   194,   170,   170,   170,   170,   172,   191,   187,   169,
      11,   170,   170,   170,   170,   170,   170,   172,   170,   170,
     170,   187,   170,   170,   170,   170,   170,   170,   172,   170,
     170,   170,   172,   170,   170,   172,   170,   172,   170,   170,
     172,   170,   170,   172,   170,   170,   203,   203,   235,    42,
      37,   253,   176,   170,   194,   169,   170,   172,   194,   275,
     207,   207,   265,   170,   170,   191,   172,   172,    71,    71,
      71,   194,   172,   199,     4,     5,   222,   223,   194,   191,
     194,   194,   191,   194,   194,   191,   191,   237,   239,    47,
     260,    49,    59,    60,   170,   194,    57,   191,   170,   264,
     170,   170,   264,   191,   191,   191,   191,   191,   170,   207,
     169,   169,   170,   172,    12,   230,   170,   172,   170,   170,
     170,   170,   170,   170,   176,   176,   194,    46,   259,   169,
     172,   169,   170,   276,    71,   170,   170,   214,   223,   194,
     227,   194,    45,   263,   176,   254,   191,   194,   194,   278,
     191,   176,   176,   170,   261,    13,    15,    17,    40,    43,
      48,   255,   170,   172,   170,   172,   264,    24,    43,   215,
     228,   176,   191,   194,    13,    15,    17,    40,    43,    48,
     229,   262,   170,   170,     4,   231,   260
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   174,   175,   176,   177,   176,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   179,   178,   180,   178,   178,   178,
     178,   178,   178,   178,   181,   178,   182,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   183,   178,
     184,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   185,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   186,
     187,   187,   188,   188,   188,   188,   188,   189,   189,   190,
     190,   191,   191,   191,   191,   191,   191,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     193,   193,   195,   194,   196,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   197,   198,   199,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   201,   201,   201,   202,   202,   202,   203,   203,   204,
     204,   204,   204,   205,   206,   208,   207,   209,   209,   209,
     210,   210,   212,   213,   214,   211,   215,   215,   216,   216,
     217,   217,   217,   217,   218,   218,   219,   219,   219,   219,
     220,   220,   221,   221,   221,   221,   222,   222,   222,   223,
     223,   223,   223,   225,   226,   227,   228,   224,   229,   229,
     229,   229,   229,   229,   230,   230,   231,   231,   233,   232,
     234,   234,   235,   235,   236,   237,   236,   238,   239,   238,
     241,   240,   242,   242,   242,   242,   242,   242,   244,   245,
     243,   246,   246,   248,   247,   249,   249,   249,   249,   249,
     249,   251,   252,   253,   254,   250,   255,   255,   255,   255,
     255,   255,   257,   258,   256,   259,   259,   260,   261,   262,
     260,   263,   263,   264,   265,   264,   266,   266,   266,   266,
     267,   267,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   271,   271,   271,   273,   272,
     274,   272,   275,   272,   276,   272,   277,   272,   278,   278,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   280,   280,   281,   281,   282,   282
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
       4,     4,     6,     8,     1,     1,     2,     1,     2,     0,
       1,     1,     2,     2,     3,    10,     8,     8,     8,     3,
       1,     1,     6,     4,     4,     6,     6,     4,     6,     1,
       4,     1,     1,     1,     1,     3,     3,     6,     6,     8,
       6,     4,     6,     8,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     3,     1,     3,     4,
       6,     6,     4,     6,     4,     6,    10,     4,     4,     4,
       3,     3,     0,     4,     0,     4,     2,     3,     3,     3,
       3,     3,     3,     4,     6,     1,     4,     4,     6,     6,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     3,
       6,     6,     4,     4,     4,     4,     6,     6,     8,     6,
       8,     4,     4,     4,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     6,     6,     6,     4,
       8,     6,     8,     6,     4,     4,     4,     6,     6,     6,
       8,     1,     2,     2,     1,     1,     1,     1,     1,     4,
       6,     4,     6,     4,     4,     0,     2,     0,     1,     3,
       1,     1,     0,     0,     0,    11,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     3,     1,     1,     4,     4,
       1,     3,     1,     1,     4,     4,     0,     1,     3,     1,
       1,     3,     3,     0,     0,     0,     0,    14,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     1,     0,     7,
       1,     2,     1,     1,     0,     0,     5,     0,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     1,     1,     0,     4,     1,     2,     1,     1,     1,
       1,     0,     0,     0,     0,    11,     1,     1,     1,     1,
       1,     1,     0,     0,     8,     0,     2,     0,     0,     0,
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

    {if (severity_so_far >= sERROR) {YYABORT;}}

    break;

  case 11:

    {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}

    break;

  case 12:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 18:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 19:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 20:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}

    break;

  case 22:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 23:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 24:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}

    break;

  case 26:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}

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

    {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 62:

    {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

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

    {add_command(cPUSHFREE,NULL,NULL);add_command(cEXTCALL,NULL,NULL);}

    break;

  case 103:

    {add_command(cEXTCALL,NULL,NULL);}

    break;

  case 104:

    {add_command(cEND,NULL,NULL);}

    break;

  case 105:

    {create_pushdbl(0);add_command(cEXIT,NULL,NULL);}

    break;

  case 106:

    {add_command(cEXIT,NULL,NULL);}

    break;

  case 107:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 108:

    {add_command(cBIND,NULL,NULL);}

    break;

  case 109:

    {drawmode=0;}

    break;

  case 110:

    {drawmode=dmCLEAR;}

    break;

  case 111:

    {drawmode=dmFILL;}

    break;

  case 112:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 113:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 114:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 115:

    {create_changestring(fMID);}

    break;

  case 116:

    {create_changestring(fMID2);}

    break;

  case 117:

    {create_changestring(fLEFT);}

    break;

  case 118:

    {create_changestring(fRIGHT);}

    break;

  case 119:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 122:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 123:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 124:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 125:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 126:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 127:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 128:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 129:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 130:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 131:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 133:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 134:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 135:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 137:

    {create_function(fLEFT);}

    break;

  case 138:

    {create_function(fRIGHT);}

    break;

  case 139:

    {create_function(fMID);}

    break;

  case 140:

    {create_function(fMID2);}

    break;

  case 141:

    {create_function(fSTR);}

    break;

  case 142:

    {create_function(fSTR2);}

    break;

  case 143:

    {create_function(fSTR3);}

    break;

  case 144:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 145:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 146:

    {create_function(fINKEY);}

    break;

  case 147:

    {create_function(fCHR);}

    break;

  case 148:

    {create_function(fUPPER);}

    break;

  case 149:

    {create_function(fLOWER);}

    break;

  case 150:

    {create_function(fLTRIM);}

    break;

  case 151:

    {create_function(fRTRIM);}

    break;

  case 152:

    {create_function(fTRIM);}

    break;

  case 153:

    {create_function(fCHOMP);}

    break;

  case 154:

    {create_function(fSYSTEM2);}

    break;

  case 155:

    {create_function(fDATE);}

    break;

  case 156:

    {create_function(fDATE);}

    break;

  case 157:

    {create_function(fTIME);}

    break;

  case 158:

    {create_function(fTIME);}

    break;

  case 159:

    {create_function(fPEEK2);}

    break;

  case 160:

    {create_function(fPEEK3);}

    break;

  case 161:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 162:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 163:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 164:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 165:

    {create_function(fGETBIT);}

    break;

  case 166:

    {create_function(fGETCHAR);}

    break;

  case 167:

    {create_function(fHEX);}

    break;

  case 168:

    {create_function(fBIN);}

    break;

  case 169:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 170:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 171:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 172:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 173:

    {poplabel();create_boole('|');}

    break;

  case 174:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 175:

    {poplabel();create_boole('&');}

    break;

  case 176:

    {create_boole('!');}

    break;

  case 177:

    {create_dblrelop('=');}

    break;

  case 178:

    {create_dblrelop('!');}

    break;

  case 179:

    {create_dblrelop('<');}

    break;

  case 180:

    {create_dblrelop('{');}

    break;

  case 181:

    {create_dblrelop('>');}

    break;

  case 182:

    {create_dblrelop('}');}

    break;

  case 183:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 184:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 185:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 186:

    {add_command(cARDIM,"",NULL);}

    break;

  case 187:

    {add_command(cARDIM,"",NULL);}

    break;

  case 188:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 189:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 190:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 191:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 192:

    {create_dblbin('+');}

    break;

  case 193:

    {create_dblbin('-');}

    break;

  case 194:

    {create_dblbin('*');}

    break;

  case 195:

    {create_dblbin('/');}

    break;

  case 196:

    {create_dblbin('^');}

    break;

  case 197:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 198:

    {create_strrelop('=');}

    break;

  case 199:

    {create_strrelop('!');}

    break;

  case 200:

    {create_strrelop('<');}

    break;

  case 201:

    {create_strrelop('{');}

    break;

  case 202:

    {create_strrelop('>');}

    break;

  case 203:

    {create_strrelop('}');}

    break;

  case 206:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 207:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 209:

    {create_function(fSIN);}

    break;

  case 210:

    {create_function(fASIN);}

    break;

  case 211:

    {create_function(fCOS);}

    break;

  case 212:

    {create_function(fACOS);}

    break;

  case 213:

    {create_function(fTAN);}

    break;

  case 214:

    {create_function(fATAN);}

    break;

  case 215:

    {create_function(fATAN2);}

    break;

  case 216:

    {create_function(fEXP);}

    break;

  case 217:

    {create_function(fLOG);}

    break;

  case 218:

    {create_function(fLOG2);}

    break;

  case 219:

    {create_function(fSQRT);}

    break;

  case 220:

    {create_function(fSQR);}

    break;

  case 221:

    {create_function(fINT);}

    break;

  case 222:

    {create_function(fCEIL);}

    break;

  case 223:

    {create_function(fFLOOR);}

    break;

  case 224:

    {create_function(fFRAC);}

    break;

  case 225:

    {create_function(fABS);}

    break;

  case 226:

    {create_function(fSIG);}

    break;

  case 227:

    {create_function(fMOD);}

    break;

  case 228:

    {create_function(fRAN);}

    break;

  case 229:

    {create_function(fRAN2);}

    break;

  case 230:

    {create_function(fMIN);}

    break;

  case 231:

    {create_function(fMAX);}

    break;

  case 232:

    {create_function(fLEN);}

    break;

  case 233:

    {create_function(fVAL);}

    break;

  case 234:

    {create_function(fASC);}

    break;

  case 235:

    {create_function(fDEC);}

    break;

  case 236:

    {create_function(fDEC2);}

    break;

  case 237:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 238:

    {create_function(fINSTR2);}

    break;

  case 239:

    {create_function(fRINSTR);}

    break;

  case 240:

    {create_function(fRINSTR2);}

    break;

  case 241:

    {create_function(fSYSTEM);}

    break;

  case 242:

    {create_function(fPEEK4);}

    break;

  case 243:

    {create_function(fPEEK);}

    break;

  case 244:

    {create_function(fMOUSEX);}

    break;

  case 245:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 246:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 247:

    {create_function(fMOUSEY);}

    break;

  case 248:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 249:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 250:

    {create_function(fMOUSEB);}

    break;

  case 251:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 252:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 253:

    {create_function(fMOUSEMOD);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 255:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 256:

    {create_function(fAND);}

    break;

  case 257:

    {create_function(fOR);}

    break;

  case 258:

    {create_function(fEOR);}

    break;

  case 259:

    {create_function(fTELL);}

    break;

  case 260:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 261:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 262:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 263:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 264:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 265:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 266:

    {create_myopen(0);}

    break;

  case 267:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 268:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 269:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 270:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 271:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 272:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 273:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 274:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 275:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 276:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 277:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 278:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 279:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 280:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 281:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 282:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 283:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 284:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 285:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 292:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 293:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 294:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 295:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 296:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 297:

    {missing_endsub--;}

    break;

  case 298:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 299:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 300:

    {exported=FALSE;}

    break;

  case 301:

    {exported=TRUE;}

    break;

  case 302:

    {exported=FALSE;}

    break;

  case 303:

    {exported=TRUE;}

    break;

  case 306:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 307:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 308:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 309:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 312:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 313:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 314:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 315:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 319:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 320:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 321:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 322:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 323:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 324:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 325:

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

  case 326:

    {
             swap();popgoto();poplabel();}

    break;

  case 327:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 328:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 329:

    {missing_next--;}

    break;

  case 330:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 331:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 332:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 333:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 334:

    {create_pushdbl(1);}

    break;

  case 336:

    {pop(stSTRING);}

    break;

  case 337:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 338:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 339:

    {report_if_missing("cannot close switch-construct: another control structure has not ended yet",FALSE);add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 345:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 346:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 348:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 350:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 352:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 353:

    {missing_loop--;report_if_missing("cannot close do-loop: another control structure has not ended yet",FALSE);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 354:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 355:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 356:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 357:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 358:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 359:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 361:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 362:

    {missing_wend--;report_if_missing("cannot close while-loop: another control structure has not ended yet",FALSE);swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 363:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 365:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 366:

    {missing_until--;report_if_missing("cannot close repeat-loop: another control structure has not ended yet",FALSE);add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 367:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 368:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 369:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 370:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 371:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 372:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 373:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 374:

    {poplabel();}

    break;

  case 376:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 377:

    {missing_endif--;report_if_missing("cannot close if-statement: another control structure has not ended yet",FALSE);}

    break;

  case 378:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 379:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 380:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 381:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 382:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 383:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 384:

    {poplabel();}

    break;

  case 388:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 389:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 394:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 396:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 397:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 398:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 399:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 402:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 403:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 404:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 405:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 406:

    {create_strdata((yyvsp[0].string));}

    break;

  case 407:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 408:

    {create_strdata((yyvsp[0].string));}

    break;

  case 409:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 413:

    {create_print('s');}

    break;

  case 414:

    {create_print('s');}

    break;

  case 415:

    {create_print('d');}

    break;

  case 416:

    {create_print('u');}

    break;

  case 417:

    {create_print('U');}

    break;

  case 418:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 419:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 420:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 421:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 422:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 423:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 424:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 425:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 426:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 427:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 428:

    {create_pushstr("?");create_print('s');}

    break;

  case 429:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 430:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 431:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 432:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 433:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 434:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 435:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 436:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 437:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 438:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 439:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 440:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 442:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 447:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 448:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 449:

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
