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
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
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
    tEXTERNAL = 411,
    tEXTERNAL2 = 412,
    tDATE = 413,
    tTIME = 414,
    tTOKEN = 415,
    tTOKENALT = 416,
    tSPLIT = 417,
    tSPLITALT = 418,
    tGLOB = 419,
    UMINUS = 420
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
#define YYLAST   5321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  175
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  450
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1036

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   420

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   174,     2,     2,     2,     2,
     170,   171,   167,   166,   173,   165,     2,   168,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   172,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     169
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
     290,   291,   292,   293,   294,   295,   296,   300,   301,   302,
     303,   304,   308,   309,   310,   311,   312,   313,   316,   317,
     320,   321,   322,   323,   324,   327,   328,   331,   332,   335,
     336,   337,   338,   339,   340,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   379,
     380,   383,   383,   384,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   417,   420,   423,   426,   427,
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
     700,   701,   704,   704,   709,   710,   713,   714,   717,   719,
     721,   718,   725,   726,   729,   730,   730,   733,   734,   736,
     737,   741,   742,   745,   746,   748,   749,   753,   754,   755,
     756,   759,   760,   761,   762,   763,   766,   767,   768,   771,
     771,   772,   772,   773,   773,   774,   774,   775,   775,   778,
     779,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,   798,   799,   801,   802,   805,
     806
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
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tEXTERNAL",
  "tEXTERNAL2", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT",
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
  "$@28", "endif", "short_if", "$@29", "end_of_if", "else_part",
  "elsif_part", "$@30", "$@31", "maybe_then", "inputlist", "$@32", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@33", "$@34", "$@35", "$@36", "$@37", "prompt", "printintro",
  "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
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
     415,   416,   417,   418,   419,    45,    43,    42,    47,   420,
      40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -746

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-746)))

#define YYTABLE_NINF -372

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3581,   -16,    -2,  -746,  -746,  -746,  -746,  -746,    81,    81,
      81,  2791,  -746,  -746,  -746,  3188,  -125,  -107,  3188,    87,
     110,  -746,  -746,  -746,  3119,   -21,  -746,  3119,    71,  -746,
    3119,  3119,  3119,    86,    44,    81,  1628,  1073,  1956,    46,
    3119,  2627,  3119,   323,    60,  3119,  -746,     7,  3188,  3188,
    3188,    47,    -3,     5,    68,   102,   125,  1956,   305,   275,
    -746,   141,  -746,  -746,  -746,  -746,   249,   274,  -746,   357,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  3119,  -746,  3188,
    -746,   382,  3119,  3443,  -746,  -746,  -746,  -746,  -746,  -746,
     228,   230,  -746,  -746,  -746,   232,   253,   180,   260,   278,
    3119,   290,   294,   308,   312,   321,   342,   363,   395,   409,
     426,   430,   442,   452,   458,   461,   470,   472,   474,   476,
     479,   481,   482,   492,   494,   495,   496,   497,   499,   502,
     509,   510,   520,   522,   526,   528,   532,   533,   534,   535,
     539,   540,   542,   546,   553,   557,   558,   559,   560,   564,
     566,   567,   569,   570,   572,   574,   575,   576,   578,   579,
     580,   583,   587,   588,   592,   593,  3119,  3119,   273,  -746,
     439,  -746,  -746,  -746,  -746,   266,   289,  3188,   226,  -746,
    -746,   226,  -746,  -746,  3119,  3443,   451,   594,   413,   597,
      25,  3119,   -17,   273,  3323,   601,   602,   324,  3323,   273,
    1647,   273,  1807,   603,   604,   380,  -746,  -746,    54,    54,
    -746,  -746,   419,  -746,  3119,  3188,  3119,    27,  3323,   421,
    -746,  -746,  -746,  -746,   465,  3188,  1971,  -746,  3119,  -746,
      12,   485,  -746,  -746,  3119,  2955,  -746,  -746,  3323,  -746,
    -746,   249,   274,   226,    24,    24,  -746,   676,   676,   676,
    2120,  3188,    93,   518,  -746,  -746,   672,  3119,  3119,  3119,
    3119,  3188,  -746,  3323,   550,  3119,   226,   605,   646,  3323,
     356,  -746,  -746,  -746,  -746,  3119,  3119,   723,  3119,  1792,
    1956,   332,   332,  3119,  3119,  3119,  3119,  3119,  3119,  3119,
    3119,  3119,  3119,  3119,  3119,  1956,  3119,  3119,  3119,  3119,
    3119,  3119,  3119,  2289,  3188,  3188,  3188,  3188,  3188,  3119,
    3119,  3119,  2458,  3119,  3188,  3119,  3188,  3119,  3188,  3188,
     329,   561,  1142,  1247,  3188,  3188,  3188,  3188,  3188,  3188,
    3188,  3188,  1956,  3188,  -746,  -746,   609,   610,  3188,   676,
    3188,   676,  3188,   703,    40,  4025,  3188,  3188,  3188,  3188,
    3188,  3188,  3188,  -746,  -746,  -746,  -746,  3119,  3119,  3119,
    3119,  3119,  3119,  3119,  3119,  3119,  3119,  3119,   626,   627,
     625,  -746,   632,   635,   633,  -746,  -122,   636,   637,   273,
    3323,   767,   521,   765,  3443,  3119,   641,  3188,  -746,  -746,
    3119,   273,    77,   204,   642,    26,  -746,   804,  -746,  -746,
     490,  3119,  3119,  -746,  -746,    86,  -746,  -746,    51,  2135,
     226,  3323,   422,  1373,  3119,   226,  3119,  -746,   -17,  -746,
    -746,  3119,  3188,  -746,  3119,    12,  3119,  3119,   644,   647,
     649,   650,  -746,  4036,   -53,  3119,  3119,  3443,   651,    12,
      12,  3323,   226,   511,  -746,   273,  3323,   652,  -746,  -746,
    -746,  3443,  -746,  -746,  3119,  -746,  -746,  -746,  -746,   648,
     662,  2304,  2476,  2642,   664,   156,   663,   666,   645,   668,
     669,   670,   671,   673,    12,  2806,  4061,  4086,  4097,  4143,
    4168,   847,  4204,  1191,  4215,  4226,   674,  4250,  4275,  4286,
    4333,  4357,  4393,  2970,  -746,  4404,    33,   -74,   -61,   -35,
     192,  3137,  3495,  1254,  -746,  4415,  4440,   201,  4464,  -101,
    4475,   212,   218,  -746,   235,  -746,   256,  -746,   279,  -746,
     306,   314,   318,   327,   -15,    -1,   358,   369,   373,   366,
     677,    21,   679,   680,  -746,  -746,     8,   -45,    85,   -41,
     153,  -746,  -746,   226,   226,   226,   226,   226,   226,  -746,
      81,    81,  3119,  3119,   760,   517,   488,   165,   252,   -65,
    -746,   -31,   -31,   703,   703,  -746,  -746,   266,  -746,  -746,
     289,  -746,  -746,  -746,   797,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,   477,  3633,  3119,    75,  4522,  3282,  -746,
    -746,  3119,  3119,  -746,  -746,  3119,  -746,   547,   682,   683,
     685,   686,  3715,  3762,   688,   689,  -746,  -746,  -746,  3119,
     762,   763,  -746,   162,  3787,  3323,  -746,  -746,   191,  -746,
    3119,  3823,  3834,  -746,  3119,  3119,  3119,  -746,  -746,   273,
    3323,   273,  3323,  -746,  3119,  3119,  3119,  -746,  -746,  -746,
    3119,  3119,    13,  3323,  -746,  -746,  3119,  3119,  3119,  -746,
    -746,  3188,  1449,  -746,   690,   691,  -746,  -746,  3119,  3119,
    3119,  3119,  -746,  -746,  -746,  -746,  -746,  -746,  3119,  -746,
    -746,  3119,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  3119,  -746,  -746,  3119,  3119,  3119,  -746,  3119,  3119,
    -746,  3188,  -746,  -746,  -746,  -746,  -746,  3119,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  3188,  3188,
    -746,  -746,  -746,  -746,  -746,  -746,  3188,  -746,  -746,   842,
    -746,  3188,   842,  -746,  3188,  3188,  -746,   692,  -746,   693,
     723,  3483,   696,   697,  -746,   698,   700,  -746,  -746,   544,
    3443,  -746,  -746,  -746,  3119,  3845,   807,  3188,  -746,  3188,
     226,   273,    77,  3870,   547,   547,  4547,   702,   704,  -746,
     705,  -746,  -746,  -746,  -746,  3119,  3119,  -746,  -746,  3895,
    1956,  1956,  3188,  3188,  3188,  -746,  3119,  3119,   709,  4582,
    4593,  1266,  3323,    12,  -746,   706,  -746,    53,  -746,  -746,
    -746,  4604,  4629,  4654,   377,   714,    89,  -746,  -746,  4665,
    4711,   715,    11,  4736,  4772,  4783,  4794,  4818,  1494,  4843,
    4854,   222,  4901,   255,   276,   379,    18,   383,    29,   396,
     397,    81,    81,  -746,  -746,  -746,  -746,  3119,   831,   838,
     850,  4925,  3119,   724,   405,   280,  -746,  3119,  -746,  -746,
    -746,  -746,  -746,  -746,   722,   727,  3323,  3323,  3188,  -746,
    -746,   226,   226,   202,  3906,  3323,  -746,   828,   829,   830,
    3119,  3119,   598,  3119,  -746,  -746,  -746,  -746,  -746,  -746,
    3188,  -746,  -746,  -746,  3119,  -746,  -746,  -746,  -746,  -746,
    -746,  3119,  -746,  -746,  -746,  3188,  -746,  -746,  3119,  -746,
    3119,  -746,  -746,  3188,  -746,  -746,  3188,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,   855,   551,  4961,  3119,   846,  3188,
    4972,   547,   735,   736,   547,  -746,  -746,   226,  3188,  3188,
    3188,  3188,  3188,  4983,  -746,   742,   750,    79,  -746,   245,
     406,  3953,  5008,   407,  5032,  5043,   424,   454,  3443,  3719,
    3119,   875,  -746,   753,  -746,  3978,   754,   455,  -746,  -746,
    -746,  -746,  -746,   226,   226,   226,   226,   226,   859,   761,
     766,  -746,   598,  3119,  -746,  -746,  3119,  -746,  -746,  -746,
    -746,  -746,  -746,   850,   894,   716,  3443,  -746,  3188,  3119,
    3119,  -746,   804,  3188,  -746,  -746,  3443,  -746,  3323,  3443,
    5090,  -746,  -746,   850,   584,   300,  5115,  4014,   547,   226,
       0,   850,  -746,  3443,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  3188,  -746,  3119,  -746,  -746,  -746,  -746,   628,
     850,   468,  5150,  -746,  -746,  -746,  -746,  -746,  -746,   929,
     855,  -746,  -746,  -746,  -746,  -746
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     107,     0,     0,   105,   323,   358,   363,    11,     0,     0,
       0,     0,    24,    26,   301,     0,     0,     0,     0,   302,
      18,    20,   338,   350,     0,   431,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     4,
       3,     0,     7,    39,    41,     9,    22,    23,    21,     0,
      13,    14,    17,    16,    15,    28,    29,     0,   285,     0,
     285,     0,     0,     6,   278,   277,    30,    31,    38,   274,
     190,   129,   275,   276,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,     0,   245,   248,   251,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   154,
     156,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,   203,   184,   189,   131,     0,     0,     0,    12,   285,
     285,    42,   303,    19,     0,     6,   382,     0,   435,     0,
       0,   411,   427,    62,    61,     0,     0,    63,   104,    53,
       0,    55,     0,   403,   405,    56,   401,   407,     0,     0,
     408,   271,    57,    59,     0,    89,     0,     0,   446,     0,
      86,    91,    79,    40,     0,     0,     0,    67,     0,    50,
      72,     0,    88,    87,     0,     0,   110,   111,    92,     8,
      10,     0,     0,   106,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,   292,   169,     0,   287,   112,     0,     0,   359,
       4,   285,   285,    32,    33,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   285,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    36,   173,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,   307,
      25,   304,   312,   313,    27,   310,     0,     0,     0,   343,
     342,     0,     4,     0,     6,     0,     0,     0,   432,   433,
       0,   414,   416,    45,     0,     0,    49,   429,   285,   285,
       0,     0,     0,   285,   285,     0,   273,   272,     0,     0,
      90,   445,     0,     0,     0,    66,     0,    71,   427,   119,
     118,     0,     0,    68,     0,    74,     0,     0,   127,     0,
       0,     0,    95,     0,     0,     0,     0,     6,     0,     0,
       0,   170,   117,     0,   283,   290,   291,   286,   288,   284,
     324,     6,   370,   368,     0,   369,   365,   367,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,   249,     0,   252,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   157,     0,     0,     0,     0,
       0,   134,   204,   198,   200,   202,   199,   201,   197,   133,
       0,     0,     0,     0,   177,   179,   181,   178,   180,   176,
     195,   192,   191,   193,   194,   285,   285,     0,   285,   285,
       0,    43,    44,   340,   344,   357,   355,   356,   353,   352,
     354,   351,   372,     4,     0,     0,     0,     0,     0,   412,
      46,    47,     0,   419,   421,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   409,   410,     0,
       0,     0,   122,   121,   125,   207,    51,    69,    82,    73,
       0,     0,     0,   285,     0,     0,     0,    96,    97,    98,
      99,   100,   101,     5,     0,     0,     0,   298,   299,   293,
       0,     0,     4,   366,   264,   168,     0,     0,     0,   265,
     266,     0,     0,   259,     0,     0,   185,   186,     0,     0,
       0,     0,   208,   209,   210,   211,   212,   213,     0,   215,
     216,     0,   218,   219,   182,   224,   225,   220,   221,   222,
     223,     0,   227,   232,     0,     0,     0,   231,     0,     0,
     139,     0,   144,   145,   233,   166,   234,     0,   167,   146,
     147,   244,   247,   250,   253,   150,   148,   149,     0,     0,
     151,   240,   152,   243,   242,   158,     0,   241,   153,     0,
     161,     0,     0,   163,     0,     0,   447,    35,   449,    37,
     174,   172,     0,     0,   305,     0,     0,   311,   341,   347,
       6,   384,   385,   383,     0,     0,   436,     0,   434,     0,
     417,   415,   416,     0,     0,     0,     0,   397,   399,   428,
     394,   279,   281,   285,   285,     0,     0,   404,   406,    64,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,    80,     0,    85,     0,   289,     0,   362,   361,
     360,     0,     0,     0,     0,     0,     0,   205,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,   309,   314,   315,     0,     0,     0,
     373,     0,     0,     0,     0,     0,   413,     0,   420,   422,
     423,   285,   285,   395,     0,     0,    52,    54,     0,   123,
     124,   120,   126,    83,    76,    77,   128,     0,     0,     0,
       0,     0,   316,     0,   256,   257,   258,   267,   268,   269,
       0,   187,   188,   164,     0,   214,   217,   226,   135,   136,
     138,     0,   229,   230,   140,     0,   235,   236,     0,   238,
       0,   159,   261,     0,   160,   263,     0,   162,   183,   448,
     450,   345,   348,   339,   388,   438,     0,     0,   437,     0,
       0,     0,     0,     0,     0,   280,   282,    65,     0,     0,
       0,     0,     0,     0,    81,   319,   320,     0,   317,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     6,   107,
       0,   386,   442,     0,   439,     0,     0,     0,   425,   424,
     398,   400,   396,    84,    75,   115,   116,   114,     0,     0,
       0,   294,     0,     0,   325,   270,     0,   137,   141,   237,
     239,   260,   262,   346,     4,   392,     6,   374,     0,     0,
       0,   418,   429,     0,   321,   322,     6,   318,   335,     6,
       0,   393,   389,   387,     0,     0,     0,     0,     0,   113,
       4,   326,   165,     6,   381,   378,   379,   380,   376,   377,
     375,   443,     0,   440,     0,   426,   297,   296,   295,     0,
     390,     0,     0,   329,   331,   332,   333,   328,   330,   336,
     388,   444,   441,   337,   327,   391
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -746,  -746,   -81,  -746,   501,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,   887,  -227,  -746,  -746,   -78,   720,  -746,   889,
     -11,  -746,  -746,   661,  -278,   -27,  -746,   536,   -26,    -4,
    -746,     1,     3,   -38,  -746,  -746,   307,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,   381,  -746,   376,  -746,   -13,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,   123,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,  -746,
    -746,  -746,  -746,  -746,  -746,  -746,   -79,  -746,  -746,  -746,
    -745,  -746,  -746,  -746,   548,  -746,  -746,   205,   538,  -746,
    -746,  -746,  -746,  -746,   -28,  -746,    30,  -746,  -746
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,    59,   256,    60,   175,   176,   550,   551,   192,
     418,    61,    62,   421,    63,    64,   429,   168,   169,    65,
     226,   553,   552,   470,   471,   227,   171,   210,   172,    86,
     197,   173,   174,   264,   265,   447,   448,    68,   443,   785,
     986,  1018,   639,    69,   370,   371,   374,   375,   927,   928,
      70,    81,   641,   989,  1019,  1029,   964,  1034,    71,   184,
     574,   381,   739,   938,   829,   939,    72,   185,   581,    73,
      82,   451,   790,    74,    83,   458,    75,   383,   740,   904,
     994,  1010,    76,   384,   743,   977,   941,  1003,  1030,   992,
     759,   914,   760,   205,   206,   212,   393,   589,   396,   754,
     755,   911,   982,   397,   597,   191,   219,   727,   729
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     170,    66,   270,    67,   473,    87,    88,   363,   211,   838,
     839,     1,     2,   186,   230,   231,   194,   426,   427,   198,
     200,   202,   419,   419,  1016,   218,   218,   218,   788,   388,
     593,   213,   389,   594,   238,   419,   187,   412,   188,   189,
     394,   363,   267,  1017,   352,   179,   218,    89,   241,   541,
     242,    92,    93,   207,    89,    77,   789,    89,    92,    93,
     607,    92,    93,   180,   863,   352,   263,   223,   224,    79,
     696,   269,   697,   355,   356,   195,   196,   357,   358,   359,
     360,   361,   362,   363,    66,    84,    67,   253,    85,   277,
     203,   204,   352,   346,   347,   348,   349,   350,   351,   684,
     364,   365,   366,   367,   382,   352,   346,   347,   348,   349,
     350,   351,   685,   352,   182,   355,   356,   183,   628,   357,
     358,   359,   360,   361,   362,   363,   720,   588,   721,   225,
     723,   352,   724,    52,    53,    54,   366,   367,   686,   355,
     356,   377,   378,   357,   358,   359,   360,   361,   362,   363,
     237,   352,   246,   190,    78,   343,   345,   395,   708,   346,
     347,   348,   349,   350,   351,   352,   949,   247,    80,   952,
     430,   431,   709,   380,   352,   248,   364,   365,   366,   367,
     392,   719,   406,   407,   420,   420,    66,   352,    67,   892,
     352,   893,   715,   352,   716,   390,   595,   420,   620,   352,
     895,   417,   896,   409,   683,   411,   352,   423,   425,   208,
     209,   541,   635,   636,   273,   274,   208,   209,   364,   365,
     366,   367,   346,   347,   348,   349,   350,   351,   257,   258,
     438,   439,   440,   459,   460,   361,   362,   363,   249,   433,
     259,   352,   364,   365,   366,   367,   746,   660,   747,   441,
     961,   352,   962,  1015,   446,   352,   474,   963,   722,   352,
     869,   537,   870,   539,   461,   462,   435,   463,   218,   218,
     368,   369,   250,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   218,   487,   488,   489,   490,   491,
     492,   493,   495,   372,   373,   251,   532,   533,   501,   502,
     503,   505,   506,   583,   508,   254,   510,   355,   356,   466,
     467,   357,   358,   359,   360,   361,   362,   363,   255,   352,
     260,   218,   352,   362,   363,   486,   725,   650,   352,   651,
     364,   365,   366,   367,    91,   772,   468,   469,    94,   346,
     347,   348,   349,   350,   351,   261,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   352,   352,    96,
     598,   599,   530,   687,   774,   604,   605,   352,   352,   452,
     642,   453,   694,   454,   584,   918,   590,   591,   352,   587,
     262,   232,   211,   699,   352,    66,   268,    67,   352,   700,
     602,   603,   352,   884,   617,   885,   455,   619,    78,   456,
      80,   352,   271,   614,   457,   615,   701,   233,   234,   235,
     364,   365,   366,   367,   236,   621,   622,   364,   365,   366,
     367,   352,   352,   272,   630,   632,   887,   702,   888,   106,
     275,   107,   346,   347,   348,   349,   350,   351,    66,   352,
      67,   816,   352,   643,   818,   352,   352,   889,   276,   890,
     703,   541,    66,   909,    67,   128,   129,   130,   353,   354,
     278,   134,   135,   136,   279,   138,   352,   140,   141,   142,
     386,  1011,   352,  1012,   147,   148,   149,   704,   280,   152,
     352,   154,   281,   156,   352,   705,   158,   159,   160,   706,
     162,   282,   164,   352,   600,   601,  -371,   400,   707,   177,
     513,   355,   356,   610,   611,   357,   358,   359,   360,   361,
     362,   363,   283,   355,   356,   637,   638,   357,   358,   359,
     360,   361,   362,   363,   352,   741,   742,   732,   733,   710,
     735,   736,   352,   284,   575,   352,   576,   713,   577,   352,
     711,   730,   731,   352,   712,   352,   726,   728,   867,   352,
     891,   757,   758,   405,   894,   358,   861,   360,   361,   362,
     363,   578,   352,   352,   579,   285,    91,   897,   898,   580,
      94,   352,   352,   352,   745,   874,   908,   965,   968,   286,
     752,   753,   827,   828,   756,   778,   360,   361,   362,   363,
     352,    96,   408,   775,   413,   971,   287,  1004,   769,  1005,
     288,  1006,   925,   926,   364,   365,   366,   367,   783,   784,
     942,   943,   289,   779,   780,   781,   364,   365,   366,   367,
     352,   352,   290,   782,  1007,   972,   981,  1008,   291,   446,
     787,   292,  1009,   801,   352,   791,   792,   793,   414,  1031,
     293,  1023,   294,  1024,   295,  1025,   296,   799,   800,   297,
     802,   298,   299,   364,   365,   366,   367,   803,   422,   830,
     804,   106,   300,   107,   301,   302,   303,   304,  1026,   305,
     805,  1027,   306,   806,   807,   808,  1028,   809,   810,   307,
     308,   428,   364,   365,   366,   367,   812,   128,   129,   130,
     309,   436,   310,   134,   135,   136,   311,   138,   312,   140,
     141,   142,   313,   314,   315,   316,   147,   148,   149,   317,
     318,   152,   319,   154,   437,   156,   320,   450,   158,   159,
     160,   444,   162,   321,   164,   844,   845,   322,   323,   324,
     325,   177,   515,   831,   326,   178,   327,   328,   181,   329,
     330,    66,   331,    67,   332,   333,   334,   193,   335,   336,
     337,   199,   201,   338,   846,   847,   217,   339,   340,   218,
     218,   991,   341,   342,   385,   854,   855,   387,   243,   244,
     245,   398,   399,   403,   404,   363,   449,   252,   355,   356,
     534,   535,   357,   358,   359,   360,   361,   362,   363,   357,
     358,   359,   360,   361,   362,   363,   565,   566,   567,   266,
     849,   850,   568,   912,   913,   569,   570,   571,   572,   573,
     582,   585,   592,   596,   623,   654,   380,   899,   900,   644,
     624,   906,   625,   626,   634,   640,   910,   358,   359,   360,
     361,   362,   363,   645,   924,   649,   652,   653,   655,   738,
     656,   657,   770,   771,   658,   674,   659,   469,   714,   923,
     717,   718,   929,   761,   762,   763,   764,   973,   974,   767,
     768,   797,   798,   931,   833,   821,   822,   823,   824,   825,
     932,   826,   841,   902,   842,   903,   862,   934,   843,   935,
     856,   364,   365,   366,   367,   868,   873,   344,   364,   365,
     366,   367,    -4,   915,   907,   993,   945,   376,   916,   920,
     921,   922,   940,   946,   379,  1000,   950,   951,  1001,   355,
     356,   391,   959,   357,   358,   359,   360,   361,   362,   363,
     960,   976,  1020,   978,   980,   364,   365,   366,   367,   975,
     983,  -349,   984,  1033,   239,   410,   240,   985,   633,    66,
      66,    67,    67,   472,   608,   415,   737,   786,   734,   987,
     901,  1035,   988,   606,   998,   990,   616,   836,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   996,   997,
       0,   434,     0,     0,     0,     0,     0,    66,     0,    67,
       0,   442,     0,     0,     0,   445,     0,    66,     0,    67,
      66,     0,    67,     0,     0,     0,     0,     0,     0,   465,
       0,     0,     0,  1022,    66,     0,    67,     0,     0,     0,
       0,     0,   364,   365,   366,   367,     0,     0,   667,     0,
     668,     0,     0,     0,   496,   497,   498,   499,   500,     0,
       0,     0,     0,     0,   507,     0,   509,     0,   511,   512,
     514,   516,   518,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   531,     0,     0,     0,     0,   536,     0,
     538,     0,   540,     0,     0,     0,   543,   544,   545,   546,
     547,   548,   549,     0,     0,     0,    89,    90,    91,     0,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,     0,     0,   586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,     0,    98,    99,   100,   101,     0,
       0,     0,   618,     0,     0,     0,     0,    91,     0,   102,
       0,    94,   103,     0,     0,   629,   631,   220,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,   104,
     105,     0,    96,   106,     0,   107,     0,     0,   222,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,   106,   167,   107,     0,     0,   216,     0,     0,
       0,     0,    91,   355,   356,     0,    94,   357,   358,   359,
     360,   361,   362,   363,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,   134,   135,   136,    96,   138,     0,
     140,   141,   142,     0,     0,     0,     0,   147,   148,   149,
       0,     0,   152,     0,   154,     0,   156,     0,     0,   158,
     159,   160,     0,   162,     0,   164,     0,     0,   750,     0,
       0,   751,   177,   517,     0,     0,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,     0,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,   107,
       0,     0,     0,     0,     0,     0,   364,   365,   366,   367,
     445,     0,   670,     0,   671,     0,     0,     0,     0,     0,
       0,   794,   796,   128,   129,   130,     0,     0,    91,   134,
     135,   136,    94,   138,     0,   140,   141,   142,     0,     0,
       0,     0,   147,   148,   149,     0,     0,   152,     0,   154,
       0,   156,     0,    96,   158,   159,   160,     0,   162,     0,
     164,   811,     0,     0,     0,     0,     0,   177,   519,   364,
     365,   366,   367,     0,     0,   690,     0,   691,   813,   814,
       0,   364,   365,   366,   367,     0,   815,   859,     0,   860,
       0,   817,     0,     0,   819,   820,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,   612,     0,   834,     0,   835,
       0,     0,     0,   106,     0,   107,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,   852,   853,     0,     0,     0,     0,   128,
     129,   130,     0,     0,     0,   134,   135,   136,     0,   138,
       0,   140,   141,   142,     0,     0,     0,     0,   147,   148,
     149,     0,     0,   152,     0,   154,     0,   156,     0,     0,
     158,   159,   160,     0,   162,     0,   164,     0,     0,     0,
       0,   795,     0,   177,     0,     0,     0,   379,     0,   106,
       0,   107,     0,     0,     0,     0,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,     0,   917,     0,
       0,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,   134,   135,   136,     0,   138,     0,   140,   141,   142,
     930,     0,     0,     0,   147,   148,   149,     0,     0,   152,
       0,   154,     0,   156,     0,   933,   158,   159,   160,     0,
     162,     0,   164,   936,     0,     0,   937,     0,     0,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   947,
       0,    89,    90,    91,     0,    92,    93,    94,   953,   954,
     955,   956,   957,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,   364,
     365,   366,   367,     0,     0,   880,     0,   881,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,     0,     0,     0,     0,   995,     0,
       0,     0,     0,   999,   102,     0,     0,   103,     0,   355,
     356,     0,   214,   357,   358,   359,   360,   361,   362,   363,
     215,     0,     0,     0,   104,   105,     0,     0,   106,     0,
     107,     0,  1021,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,    89,    90,    91,   167,    92,
      93,    94,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,     0,     0,     0,     0,
     401,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   355,
     356,   103,     0,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,   464,     0,     0,     0,   104,   105,
       0,     0,   106,     0,   107,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,    89,
      90,    91,   167,    92,    93,    94,   216,     0,     0,     0,
       0,     0,   364,   365,   366,   367,     0,     0,     0,     0,
     402,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   355,   356,   103,     0,   357,   358,   359,
     360,   361,   362,   363,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,     0,     0,   106,     0,   107,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,    89,    90,    91,   167,    92,    93,    94,
     216,     0,     0,     0,     0,     0,   364,   365,   366,   367,
       0,     0,     0,     0,   416,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   355,   356,   103,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
     106,     0,   107,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,     0,     0,     0,     0,
     167,   432,    89,    90,    91,     0,    92,    93,    94,     0,
     364,   365,   366,   367,     0,     0,     0,     0,   609,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   355,   356,   103,     0,
     357,   358,   359,   360,   361,   362,   363,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,   106,
       0,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,   167,
     494,    89,    90,    91,     0,    92,    93,    94,     0,   364,
     365,   366,   367,     0,     0,     0,     0,   646,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,   103,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,   104,   105,     0,     0,   106,     0,
     107,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,     0,     0,     0,   167,   504,
      89,    90,    91,     0,    92,    93,    94,     0,   228,     0,
       0,   364,   365,   366,   367,     0,     0,     0,     0,   647,
       0,     0,     0,     0,     0,     0,    95,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   355,   356,   103,     0,   357,   358,
     359,   360,   361,   362,   363,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,    89,    90,    91,   167,    92,    93,
      94,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,     0,     0,   648,     0,     0,     0,     0,
      95,    96,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   355,   356,
     103,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,   106,     0,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,    89,    90,
      91,   167,    92,    93,    94,     0,   424,     0,     0,     0,
       0,   364,   365,   366,   367,     0,     0,     0,     0,   661,
       0,     0,     0,     0,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   355,   356,   103,     0,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,   106,     0,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,    89,    90,    91,   167,    92,    93,    94,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,     0,     0,   681,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,   102,     0,    94,   103,   355,
     356,     0,     0,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,     0,   104,   105,     0,    96,   106,
       0,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,    91,   106,   167,
     107,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,     0,     0,     0,     0,
     688,     0,    96,     0,   128,   129,   130,     0,     0,     0,
     134,   135,   136,     0,   138,     0,   140,   141,   142,     0,
       0,     0,     0,   147,   148,   149,     0,     0,   152,     0,
     154,     0,   156,     0,     0,   158,   159,   160,     0,   162,
       0,   164,     0,     0,     0,     0,     0,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,   107,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,   134,   135,   136,     0,   138,     0,
     140,   141,   142,     0,     0,     0,     0,   147,   148,   149,
       0,     0,   152,     0,   154,     0,   156,     0,     0,   158,
     159,   160,     0,   162,     0,   164,     0,     1,     2,     3,
       0,     0,   749,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     8,     9,    10,    11,  -300,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
       0,     0,     0,     0,    23,     0,     0,    24,   364,   365,
     366,   367,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
    -107,  -107,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,  -107,     0,    49,   355,    50,    51,     0,   357,
     358,   359,   360,   361,   362,   363,     0,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     0,     0,
       0,     4,     0,     0,    56,     5,     0,     6,    57,     7,
       8,     9,    10,    11,  -300,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,     0,     0,
       0,     0,    23,    -6,    -6,    24,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,    33,    34,    35,    36,    37,    38,
     364,   365,   366,   367,     0,    39,    40,    41,   689,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,     0,    52,    53,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,     0,     0,     4,
       0,     0,    56,     5,     0,     6,    57,     7,     8,     9,
      10,    11,  -300,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    -6,     0,     0,     0,
      23,    -6,     0,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,   355,   356,    31,
      32,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,   364,   365,
     366,   367,     0,    39,    40,    41,   744,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,   355,   356,     0,     0,   357,   358,
     359,   360,   361,   362,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,   355,
     356,     0,    55,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,     0,     0,     0,     0,
     364,   365,   366,   367,     0,   355,   356,     0,   765,   357,
     358,   359,   360,   361,   362,   363,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,     0,   355,   356,     0,   766,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,     0,   355,   356,     0,
     773,   357,   358,   359,   360,   361,   362,   363,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,     0,     0,   776,     0,     0,   364,
     365,   366,   367,     0,     0,     0,     0,   777,     0,     0,
     364,   365,   366,   367,     0,   355,   356,     0,   832,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,     0,
     355,   356,     0,   837,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,   367,     0,     0,     0,     0,   848,     0,
       0,   364,   365,   366,   367,     0,   355,   356,     0,   919,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,     0,   355,   356,     0,   966,   357,   358,   359,
     360,   361,   362,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   364,   365,   366,   367,     0,   355,   356,
       0,   979,   357,   358,   359,   360,   361,   362,   363,   355,
     356,     0,     0,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,   367,     0,     0,     0,     0,  1014,     0,     0,
     364,   365,   366,   367,     0,     0,   542,     0,     0,     0,
       0,   364,   365,   366,   367,   355,   356,   627,     0,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,   365,   366,   367,
     355,   356,   662,     0,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,   367,     0,     0,   663,     0,     0,
       0,     0,   364,   365,   366,   367,   355,   356,   664,     0,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,   355,   356,   665,     0,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   364,   365,   366,   367,   355,   356,   666,
       0,   357,   358,   359,   360,   361,   362,   363,   355,   356,
       0,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,   367,     0,     0,   669,     0,     0,     0,     0,
     364,   365,   366,   367,     0,     0,   672,     0,     0,     0,
       0,   364,   365,   366,   367,   355,   356,   673,     0,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,   355,
     356,   675,     0,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,   367,     0,     0,   676,     0,     0,     0,
       0,   364,   365,   366,   367,   355,   356,   677,     0,   357,
     358,   359,   360,   361,   362,   363,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,   355,   356,   678,     0,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,   355,   356,   679,     0,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,   680,     0,     0,     0,     0,   364,
     365,   366,   367,     0,     0,   682,     0,     0,     0,     0,
     364,   365,   366,   367,   355,   356,   692,     0,   357,   358,
     359,   360,   361,   362,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,   355,
     356,   693,     0,   357,   358,   359,   360,   361,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,   367,     0,     0,   695,     0,     0,     0,     0,
     364,   365,   366,   367,   355,   356,   698,     0,   357,   358,
     359,   360,   361,   362,   363,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,   355,   356,   748,     0,   357,   358,   359,   360,   361,
     362,   363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,   365,   366,   367,   355,   356,   840,     0,
     357,   358,   359,   360,   361,   362,   363,   355,   356,     0,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,   857,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,   858,     0,     0,     0,     0,   364,
     365,   366,   367,   355,   356,   864,     0,   357,   358,   359,
     360,   361,   362,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,   365,   366,   367,   355,   356,
     865,     0,   357,   358,   359,   360,   361,   362,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,   367,     0,     0,   866,     0,     0,     0,     0,
     364,   365,   366,   367,   355,   356,   871,     0,   357,   358,
     359,   360,   361,   362,   363,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,   365,   366,   367,
     355,   356,   872,     0,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,   365,   366,   367,   355,   356,   875,     0,   357,
     358,   359,   360,   361,   362,   363,   355,   356,     0,     0,
     357,   358,   359,   360,   361,   362,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,   876,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,   877,     0,     0,     0,     0,   364,
     365,   366,   367,   355,   356,   878,     0,   357,   358,   359,
     360,   361,   362,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   364,   365,   366,   367,   355,   356,   879,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,   365,
     366,   367,     0,     0,   882,     0,     0,     0,     0,   364,
     365,   366,   367,   355,   356,   883,     0,   357,   358,   359,
     360,   361,   362,   363,   355,   356,     0,     0,   357,   358,
     359,   360,   361,   362,   363,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,   365,   366,   367,
     355,   356,   886,     0,   357,   358,   359,   360,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,   367,   355,   356,   905,     0,   357,   358,
     359,   360,   361,   362,   363,   355,   356,     0,     0,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,   365,   366,   367,
       0,     0,   944,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,   948,     0,     0,     0,     0,   364,   365,
     366,   367,   355,   356,   958,     0,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   364,   365,   366,   367,   355,   356,   967,
       0,   357,   358,   359,   360,   361,   362,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,   365,   366,
     367,     0,     0,   969,     0,     0,     0,     0,   364,   365,
     366,   367,   355,   356,   970,     0,   357,   358,   359,   360,
     361,   362,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,  1002,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   365,   366,   367,     0,     0,  1013,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   365,   366,   367,     0,
       0,  1032
};

static const yytype_int16 yycheck[] =
{
      11,     0,    83,     0,   282,     9,    10,    72,    34,   754,
     755,     4,     5,    24,    41,    42,    27,   244,   245,    30,
      31,    32,    11,    11,    24,    36,    37,    38,    15,     4,
       4,    35,     7,     7,    45,    11,    57,    10,    59,    60,
      57,    72,    80,    43,   166,   170,    57,     3,    47,   171,
      47,     7,     8,     9,     3,    71,    43,     3,     7,     8,
       9,     7,     8,   170,    11,   166,    77,    37,    38,    71,
     171,    82,   173,    62,    63,     4,     5,    66,    67,    68,
      69,    70,    71,    72,    83,     4,    83,    57,     7,   100,
       4,     5,   166,    66,    67,    68,    69,    70,    71,   173,
     165,   166,   167,   168,   185,   166,    66,    67,    68,    69,
      70,    71,   173,   166,    27,    62,    63,     7,   171,    66,
      67,    68,    69,    70,    71,    72,   171,    50,   173,    83,
     171,   166,   173,   126,   127,   128,   167,   168,   173,    62,
      63,   179,   180,    66,    67,    68,    69,    70,    71,    72,
      90,   166,   105,   174,   170,   166,   167,   174,   173,    66,
      67,    68,    69,    70,    71,   166,   911,   170,   170,   914,
     248,   249,   173,   184,   166,   170,   165,   166,   167,   168,
     191,   173,   208,   209,   173,   173,   185,   166,   185,   171,
     166,   173,   171,   166,   173,   170,   170,   173,   425,   166,
     171,   228,   173,   214,   171,   216,   166,   234,   235,   165,
     166,   171,   439,   440,    34,    35,   165,   166,   165,   166,
     167,   168,    66,    67,    68,    69,    70,    71,    87,    88,
     257,   258,   259,   271,   272,    70,    71,    72,   170,   250,
      99,   166,   165,   166,   167,   168,   171,   474,   173,   260,
     171,   166,   173,   998,   265,   166,   283,    12,   173,   166,
     171,   339,   173,   341,   275,   276,   173,   278,   279,   280,
       4,     5,   170,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,     4,     5,   170,   334,   335,   309,   310,
     311,   312,   313,   384,   315,     0,   317,    62,    63,   279,
     280,    66,    67,    68,    69,    70,    71,    72,    43,   166,
      71,   332,   166,    71,    72,   295,   173,   171,   166,   173,
     165,   166,   167,   168,     5,   173,     4,     5,     9,    66,
      67,    68,    69,    70,    71,    71,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   166,   166,    30,
     398,   399,   332,   171,   173,   403,   404,   166,   166,    13,
     451,    15,   171,    17,   385,   173,   172,   173,   166,   390,
      23,    58,   408,   171,   166,   384,     4,   384,   166,   171,
     401,   402,   166,   171,   421,   173,    40,   424,   170,    43,
     170,   166,   170,   414,    48,   416,   171,    84,    85,    86,
     165,   166,   167,   168,    91,   426,   427,   165,   166,   167,
     168,   166,   166,   170,   435,   436,   171,   171,   173,   100,
     170,   102,    66,    67,    68,    69,    70,    71,   437,   166,
     437,   719,   166,   454,   722,   166,   166,   171,   170,   173,
     171,   171,   451,   173,   451,   126,   127,   128,    19,    20,
     170,   132,   133,   134,   170,   136,   166,   138,   139,   140,
      57,   171,   166,   173,   145,   146,   147,   171,   170,   150,
     166,   152,   170,   154,   166,   171,   157,   158,   159,   171,
     161,   170,   163,   166,     4,     5,    45,   173,   171,   170,
     171,    62,    63,    81,    82,    66,    67,    68,    69,    70,
      71,    72,   170,    62,    63,     4,     5,    66,    67,    68,
      69,    70,    71,    72,   166,    48,    49,   565,   566,   171,
     568,   569,   166,   170,    13,   166,    15,   171,    17,   166,
     171,   552,   553,   166,   171,   166,   550,   551,   171,   166,
     171,     4,     5,   173,   171,    67,   783,    69,    70,    71,
      72,    40,   166,   166,    43,   170,     5,   171,   171,    48,
       9,   166,   166,   166,   585,   802,   171,   171,   171,   170,
     591,   592,    38,    39,   595,   623,    69,    70,    71,    72,
     166,    30,   173,   620,   173,   171,   170,    13,   609,    15,
     170,    17,     4,     5,   165,   166,   167,   168,   635,   636,
      59,    60,   170,   624,   625,   626,   165,   166,   167,   168,
     166,   166,   170,   634,    40,   171,   171,    43,   170,   640,
     641,   170,    48,   660,   166,   646,   647,   648,   173,   171,
     170,    13,   170,    15,   170,    17,   170,   658,   659,   170,
     661,   170,   170,   165,   166,   167,   168,   668,   173,   740,
     671,   100,   170,   102,   170,   170,   170,   170,    40,   170,
     681,    43,   170,   684,   685,   686,    48,   688,   689,   170,
     170,     5,   165,   166,   167,   168,   697,   126,   127,   128,
     170,   173,   170,   132,   133,   134,   170,   136,   170,   138,
     139,   140,   170,   170,   170,   170,   145,   146,   147,   170,
     170,   150,   170,   152,    42,   154,   170,    71,   157,   158,
     159,   171,   161,   170,   163,   763,   764,   170,   170,   170,
     170,   170,   171,   744,   170,    15,   170,   170,    18,   170,
     170,   740,   170,   740,   170,   170,   170,    27,   170,   170,
     170,    31,    32,   170,   765,   766,    36,   170,   170,   770,
     771,    45,   170,   170,   170,   776,   777,   170,    48,    49,
      50,   170,   170,   170,   170,    72,   171,    57,    62,    63,
     171,   171,    66,    67,    68,    69,    70,    71,    72,    66,
      67,    68,    69,    70,    71,    72,   170,   170,   173,    79,
     770,   771,   170,   841,   842,   170,   173,   171,   171,    42,
      45,   170,   170,     9,   170,   170,   827,   821,   822,   171,
     173,   832,   173,   173,   173,   173,   837,    67,    68,    69,
      70,    71,    72,   171,   861,   171,   173,   171,   170,    42,
     171,   171,    80,    80,   173,   171,   173,     5,   171,   860,
     171,   171,   863,   171,   171,   170,   170,   938,   939,   171,
     171,   171,   171,   874,    57,   173,   173,   171,   171,   171,
     881,   171,   170,    42,   170,    37,   170,   888,   173,   890,
     171,   165,   166,   167,   168,   171,   171,   167,   165,   166,
     167,   168,    42,   171,   170,   976,   907,   177,   171,    71,
      71,    71,    47,    57,   184,   986,   171,   171,   989,    62,
      63,   191,   170,    66,    67,    68,    69,    70,    71,    72,
     170,    46,  1003,   170,   170,   165,   166,   167,   168,   940,
      71,    37,   171,     4,    47,   215,    47,   171,   437,   938,
     939,   938,   939,   282,   408,   225,   570,   640,   567,   962,
     827,  1030,   963,   405,   982,   966,   418,   752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,   980,
      -1,   251,    -1,    -1,    -1,    -1,    -1,   976,    -1,   976,
      -1,   261,    -1,    -1,    -1,   265,    -1,   986,    -1,   986,
     989,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,  1014,  1003,    -1,  1003,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,   171,    -1,
     173,    -1,    -1,    -1,   304,   305,   306,   307,   308,    -1,
      -1,    -1,    -1,    -1,   314,    -1,   316,    -1,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,    -1,    -1,    -1,    -1,   338,    -1,
     340,    -1,   342,    -1,    -1,    -1,   346,   347,   348,   349,
     350,   351,   352,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,   387,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   413,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,   422,    -1,    -1,    -1,    -1,     5,    -1,    76,
      -1,     9,    79,    -1,    -1,   435,   436,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    30,   100,    -1,   102,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,   100,   170,   102,    -1,    -1,   174,    -1,    -1,
      -1,    -1,     5,    62,    63,    -1,     9,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    30,   136,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,
     158,   159,    -1,   161,    -1,   163,    -1,    -1,   588,    -1,
      -1,   591,   170,   171,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     640,    -1,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,   651,   652,   126,   127,   128,    -1,    -1,     5,   132,
     133,   134,     9,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,   154,    -1,    30,   157,   158,   159,    -1,   161,    -1,
     163,   691,    -1,    -1,    -1,    -1,    -1,   170,   171,   165,
     166,   167,   168,    -1,    -1,   171,    -1,   173,   708,   709,
      -1,   165,   166,   167,   168,    -1,   716,   171,    -1,   173,
      -1,   721,    -1,    -1,   724,   725,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,   747,    -1,   749,
      -1,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   772,   773,   774,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,
     157,   158,   159,    -1,   161,    -1,   163,    -1,    -1,    -1,
      -1,    92,    -1,   170,    -1,    -1,    -1,   827,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,   848,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
     870,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,   885,   157,   158,   159,    -1,
     161,    -1,   163,   893,    -1,    -1,   896,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,
      -1,     3,     4,     5,    -1,     7,     8,     9,   918,   919,
     920,   921,   922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,   165,
     166,   167,   168,    -1,    -1,   171,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,   978,    -1,
      -1,    -1,    -1,   983,    76,    -1,    -1,    79,    -1,    62,
      63,    -1,    84,    66,    67,    68,    69,    70,    71,    72,
      92,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,
     102,    -1,  1012,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,     3,     4,     5,   170,     7,
       8,     9,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    62,
      63,    79,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,     3,
       4,     5,   170,     7,     8,     9,   174,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
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
     154,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,     3,     4,     5,   170,     7,     8,     9,
     174,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    62,    63,    79,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
     170,   171,     3,     4,     5,    -1,     7,     8,     9,    -1,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
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
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,
     171,     3,     4,     5,    -1,     7,     8,     9,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,   170,   171,
       3,     4,     5,    -1,     7,     8,     9,    -1,    11,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
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
     153,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,     3,     4,     5,   170,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    62,    63,
      79,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,     3,     4,
       5,   170,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    62,    63,    79,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,     3,     4,     5,   170,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    76,    -1,     9,    79,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    30,   100,
      -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,     5,   100,   170,
     102,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    30,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,   158,   159,    -1,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,   102,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,
     158,   159,    -1,   161,    -1,   163,    -1,     4,     5,     6,
      -1,    -1,   170,    10,    -1,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,   165,   166,
     167,   168,    -1,    -1,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,   101,    62,   103,   104,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,   151,    14,    -1,    16,   155,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,    73,    74,    75,    76,    77,    78,
     165,   166,   167,   168,    -1,    84,    85,    86,   173,    -1,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    -1,   151,    14,    -1,    16,   155,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    -1,    62,    63,    60,
      61,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,   165,   166,
     167,   168,    -1,    84,    85,    86,   173,    -1,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    62,
      63,    -1,   133,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    62,    63,    -1,   173,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    62,    63,    -1,   173,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    -1,    62,    63,    -1,
     173,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
     165,   166,   167,   168,    -1,    62,    63,    -1,   173,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      62,    63,    -1,   173,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,
      -1,   165,   166,   167,   168,    -1,    62,    63,    -1,   173,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    62,    63,    -1,   173,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    -1,    62,    63,
      -1,   173,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    62,    63,   171,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      62,    63,   171,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    62,    63,   171,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    62,    63,   171,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    62,    63,   171,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    62,    63,   171,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    62,
      63,   171,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    62,    63,   171,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    62,    63,   171,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    62,    63,   171,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    62,    63,   171,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    62,
      63,   171,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    62,    63,   171,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    62,    63,   171,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,    62,    63,   171,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    62,    63,   171,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,    62,    63,
     171,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    62,    63,   171,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      62,    63,   171,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    62,    63,   171,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    62,    63,   171,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    62,    63,   171,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    62,    63,   171,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      62,    63,   171,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    62,    63,   171,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    62,    63,   171,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    62,    63,   171,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    62,    63,   171,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,   171
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
     103,   104,   126,   127,   128,   133,   151,   155,   176,   177,
     179,   186,   187,   189,   190,   194,   206,   207,   212,   218,
     225,   233,   241,   244,   248,   251,   257,    71,   170,    71,
     170,   226,   245,   249,     4,     7,   204,   204,   204,     3,
       4,     5,     7,     8,     9,    29,    30,    33,    62,    63,
      64,    65,    76,    79,    96,    97,   100,   102,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   170,   192,   193,
     195,   201,   203,   206,   207,   180,   181,   170,   192,   170,
     170,   192,    27,     7,   234,   242,   195,    57,    59,    60,
     174,   280,   184,   192,   195,     4,     5,   205,   195,   192,
     195,   192,   195,     4,     5,   268,   269,     9,   165,   166,
     202,   203,   270,   204,    84,    92,   174,   192,   195,   281,
      84,    92,   105,   281,   281,    83,   195,   200,    11,    52,
     200,   200,    58,    84,    85,    86,    91,    90,   195,   187,
     194,   206,   207,   192,   192,   192,   105,   170,   170,   170,
     170,   170,   192,   281,     0,    43,   178,    87,    88,    99,
      71,    71,    23,   195,   208,   209,   192,   208,     4,   195,
     177,   170,   170,    34,    35,   170,   170,   195,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   195,   192,   195,    66,    67,    68,    69,
      70,    71,   166,    19,    20,    62,    63,    66,    67,    68,
      69,    70,    71,    72,   165,   166,   167,   168,     4,     5,
     219,   220,     4,     5,   221,   222,   192,   208,   208,   192,
     195,   236,   177,   252,   258,   170,    57,   170,     4,     7,
     170,   192,   195,   271,    57,   174,   273,   278,   170,   170,
     173,   173,   173,   170,   170,   173,   203,   203,   173,   195,
     192,   195,    10,   173,   173,   192,   173,   200,   185,    11,
     173,   188,   173,   200,    11,   200,   188,   188,     5,   191,
     191,   191,   171,   195,   192,   173,   173,    42,   200,   200,
     200,   195,   192,   213,   171,   192,   195,   210,   211,   171,
      71,   246,    13,    15,    17,    40,    43,    48,   250,   208,
     208,   195,   195,   195,    92,   192,   281,   281,     4,     5,
     198,   199,   198,   199,   200,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   281,   195,   195,   195,
     195,   195,   195,   195,   171,   195,   192,   192,   192,   192,
     192,   195,   195,   195,   171,   195,   195,   192,   195,   192,
     195,   192,   192,   171,   192,   171,   192,   171,   192,   171,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     281,   192,   208,   208,   171,   171,   192,   191,   192,   191,
     192,   171,   171,   192,   192,   192,   192,   192,   192,   192,
     182,   183,   197,   196,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   170,   170,   173,   170,   170,
     173,   171,   171,    42,   235,    13,    15,    17,    40,    43,
      48,   243,    45,   177,   195,   170,   192,   195,    50,   272,
     172,   173,   170,     4,     7,   170,     9,   279,   208,   208,
       4,     5,   195,   195,   208,   208,   269,     9,   202,   173,
      81,    82,    92,   192,   195,   195,   273,   200,   192,   200,
     188,   195,   195,   170,   173,   173,   173,   171,   171,   192,
     195,   192,   195,   179,   173,   188,   188,     4,     5,   217,
     173,   227,   177,   195,   171,   171,   173,   173,   173,   171,
     171,   173,   173,   171,   170,   170,   171,   171,   173,   173,
     188,   173,   171,   171,   171,   171,   171,   171,   173,   171,
     171,   173,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   173,   171,   171,   173,   173,   173,   171,   173,   173,
     171,   173,   171,   171,   171,   171,   171,   173,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   173,   173,
     171,   171,   171,   171,   171,   171,   173,   171,   171,   173,
     171,   173,   173,   171,   173,   173,   204,   282,   204,   283,
     195,   195,   208,   208,   220,   208,   208,   222,    42,   237,
     253,    48,    49,   259,   173,   195,   171,   173,   171,   170,
     192,   192,   195,   195,   274,   275,   195,     4,     5,   265,
     267,   171,   171,   170,   170,   173,   173,   171,   171,   195,
      80,    80,   173,   173,   173,   200,   173,   173,   208,   195,
     195,   195,   195,   200,   200,   214,   211,   195,    15,    43,
     247,   195,   195,   195,   192,    92,   192,   171,   171,   195,
     195,   200,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   192,   195,   192,   192,   192,   199,   192,   199,   192,
     192,   173,   173,   171,   171,   171,   171,    38,    39,   239,
     177,   195,   173,    57,   192,   192,   272,   173,   265,   265,
     171,   170,   170,   173,   208,   208,   195,   195,   173,   281,
     281,   192,   192,   192,   195,   195,   171,   171,   171,   171,
     173,   188,   170,    11,   171,   171,   171,   171,   171,   171,
     173,   171,   171,   171,   188,   171,   171,   171,   171,   171,
     171,   173,   171,   171,   171,   173,   171,   171,   173,   171,
     173,   171,   171,   173,   171,   171,   173,   171,   171,   204,
     204,   236,    42,    37,   254,   171,   195,   170,   171,   173,
     195,   276,   208,   208,   266,   171,   171,   192,   173,   173,
      71,    71,    71,   195,   200,     4,     5,   223,   224,   195,
     192,   195,   195,   192,   195,   195,   192,   192,   238,   240,
      47,   261,    59,    60,   171,   195,    57,   192,   171,   265,
     171,   171,   265,   192,   192,   192,   192,   192,   171,   170,
     170,   171,   173,    12,   231,   171,   173,   171,   171,   171,
     171,   171,   171,   177,   177,   195,    46,   260,   170,   173,
     170,   171,   277,    71,   171,   171,   215,   224,   195,   228,
     195,    45,   264,   177,   255,   192,   195,   195,   279,   192,
     177,   177,   171,   262,    13,    15,    17,    40,    43,    48,
     256,   171,   173,   171,   173,   265,    24,    43,   216,   229,
     177,   192,   195,    13,    15,    17,    40,    43,    48,   230,
     263,   171,   171,     4,   232,   261
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   175,   176,   177,   178,   177,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   180,   179,   181,   179,   179,   179,
     179,   179,   179,   179,   182,   179,   183,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   184,   179,
     185,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   186,   186,   186,
     186,   186,   187,   187,   187,   187,   187,   187,   188,   188,
     189,   189,   189,   189,   189,   190,   190,   191,   191,   192,
     192,   192,   192,   192,   192,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   194,
     194,   196,   195,   197,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   198,   199,   200,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   202,   202,   202,   203,   203,   203,   204,   204,   205,
     205,   205,   205,   206,   207,   209,   208,   210,   210,   210,
     211,   211,   213,   214,   215,   212,   216,   216,   217,   217,
     218,   218,   218,   218,   219,   219,   220,   220,   220,   220,
     221,   221,   222,   222,   222,   222,   223,   223,   223,   224,
     224,   224,   224,   226,   227,   228,   229,   225,   230,   230,
     230,   230,   230,   230,   231,   231,   232,   232,   234,   233,
     235,   235,   236,   236,   237,   238,   237,   239,   240,   239,
     242,   241,   243,   243,   243,   243,   243,   243,   245,   246,
     244,   247,   247,   249,   248,   250,   250,   250,   250,   250,
     250,   252,   253,   254,   255,   251,   256,   256,   256,   256,
     256,   256,   258,   257,   259,   259,   260,   260,   261,   262,
     263,   261,   264,   264,   265,   266,   265,   267,   267,   267,
     267,   268,   268,   269,   269,   269,   269,   270,   270,   270,
     270,   271,   271,   271,   271,   271,   272,   272,   272,   274,
     273,   275,   273,   276,   273,   277,   273,   278,   273,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   281,   281,   282,   282,   283,
     283
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
       4,     4,     4,     4,     1,     3,     1,     3,     4,     6,
       6,     4,     6,     4,     6,    10,     4,     4,     4,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     3,     6,
       6,     4,     4,     4,     4,     6,     6,     8,     6,     8,
       4,     4,     4,     4,     4,     1,     3,     4,     1,     3,
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
       1,     1,     0,     5,     1,     1,     0,     2,     0,     0,
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

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

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

    {create_function(fEXTERNAL2);}

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

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

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

    {create_function(fSYSTEM);}

    break;

  case 241:

    {create_function(fEXTERNAL);}

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

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

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

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

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

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 363:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 365:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 366:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

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

    {missing_endif--;}

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

  case 384:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 385:

    {poplabel();}

    break;

  case 389:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 390:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 395:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 397:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 398:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 399:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 400:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 403:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 404:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 405:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 406:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 407:

    {create_strdata((yyvsp[0].string));}

    break;

  case 408:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 409:

    {create_strdata((yyvsp[0].string));}

    break;

  case 410:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 414:

    {create_print('s');}

    break;

  case 415:

    {create_print('s');}

    break;

  case 416:

    {create_print('d');}

    break;

  case 417:

    {create_print('u');}

    break;

  case 418:

    {create_print('U');}

    break;

  case 419:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 420:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 421:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 422:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 423:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 424:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 425:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 426:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 427:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 428:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 429:

    {create_pushstr("?");create_print('s');}

    break;

  case 430:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 431:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 432:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 433:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 434:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 435:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 436:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 437:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 438:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 439:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 440:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 443:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 448:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 449:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 450:

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
