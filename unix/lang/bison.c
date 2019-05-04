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
    tEXTLIB = 411,
    tEXTLIB2 = 412,
    tEXTSTRUCT = 413,
    tEXTSTRUCT2 = 414,
    tDATE = 415,
    tTIME = 416,
    tTOKEN = 417,
    tTOKENALT = 418,
    tSPLIT = 419,
    tSPLITALT = 420,
    tGLOB = 421,
    UMINUS = 422
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
#define YYFINAL  258
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  177
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  459
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1066

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   422

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   176,     2,     2,     2,     2,
     172,   173,   169,   168,   175,   167,     2,   170,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   174,
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
     165,   166,   171
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
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   304,   305,   306,   307,   308,   312,   313,   314,   315,
     316,   317,   320,   321,   324,   325,   326,   327,   328,   331,
     332,   335,   336,   339,   340,   341,   342,   343,   344,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   387,   388,   391,
     391,   392,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   425,   428,   431,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     500,   501,   502,   505,   506,   507,   510,   511,   514,   515,
     516,   517,   520,   523,   526,   526,   529,   530,   531,   534,
     535,   538,   539,   542,   538,   547,   548,   551,   552,   555,
     556,   557,   558,   561,   562,   565,   566,   567,   568,   571,
     572,   575,   576,   577,   578,   581,   582,   583,   586,   587,
     588,   589,   592,   593,   597,   611,   592,   616,   617,   618,
     619,   620,   621,   624,   625,   628,   629,   634,   634,   638,
     639,   642,   643,   647,   649,   648,   653,   654,   654,   658,
     658,   664,   665,   666,   667,   668,   669,   673,   674,   673,
     680,   681,   685,   685,   690,   691,   692,   693,   694,   695,
     698,   699,   699,   701,   698,   705,   706,   707,   708,   709,
     710,   713,   713,   718,   719,   722,   723,   726,   728,   730,
     727,   734,   735,   738,   739,   739,   742,   743,   745,   746,
     750,   751,   754,   755,   757,   758,   762,   763,   764,   765,
     768,   769,   770,   771,   772,   775,   776,   777,   780,   780,
     781,   781,   782,   782,   783,   783,   784,   784,   787,   788,
     791,   792,   793,   794,   795,   796,   797,   798,   799,   800,
     801,   802,   803,   804,   807,   808,   810,   811,   814,   815
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
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tEXTLIB",
  "tEXTLIB2", "tEXTSTRUCT", "tEXTSTRUCT2", "tDATE", "tTIME", "tTOKEN",
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
     415,   416,   417,   418,   419,   420,   421,    45,    43,    42,
      47,   422,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -761

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-761)))

#define YYTABLE_NINF -381

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3689,   -41,   -38,  -761,  -761,  -761,  -761,  -761,    84,    84,
      84,  2887,  -761,  -761,  -761,  1187,  -144,  -130,  1187,    62,
      52,  -761,  -761,  -761,  3219,     4,  -761,  3219,   111,  -761,
    3219,  3219,  3219,   180,    32,    84,  1710,  1119,  2042,    -5,
    3219,  2721,  3219,    17,     2,  3219,  -761,    66,  1187,  1187,
    1187,     7,   -48,   -37,    18,    37,    61,  2042,  1187,   104,
     200,  -761,   -19,  -761,  -761,  -761,  -761,   188,   227,  -761,
     278,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  3219,  -761,
    1187,  -761,   329,  3219,  3546,  -761,  -761,  -761,  -761,  -761,
    -761,   193,   203,  -761,  -761,  -761,   207,   220,   289,   223,
     230,  3219,   244,   263,   265,   271,   274,   286,   295,   317,
     326,   328,   332,   335,   338,   341,   350,   358,   383,   389,
     397,   433,   439,   443,   458,   468,   474,   509,   512,   516,
     520,   528,   530,   536,   560,   566,   570,   571,   572,   573,
     578,   582,   591,   593,   595,   596,   597,   600,   606,   607,
     608,   611,   612,   613,   620,   621,   622,   626,   627,   642,
     646,   647,   648,   649,   652,   655,   656,   670,   675,  3219,
    3219,   584,  -761,   357,  -761,  -761,  -761,  -761,   413,   429,
    1187,   218,  -761,  -761,   218,  -761,  -761,  3219,  3546,   449,
     686,   399,   687,     5,  3219,   -33,   584,  3424,   695,   696,
     316,  3424,   584,   782,   584,   794,   698,   699,   411,  -761,
    -761,   470,   470,  -761,  -761,   417,  -761,  3219,  1187,  3219,
      28,  3424,   438,  -761,  -761,  -761,  -761,   451,  1187,  1237,
    -761,  3219,  -761,    12,   457,  -761,  -761,  3219,  3053,  -761,
    -761,  3424,  -761,  -761,   188,   227,   218,    11,    11,  -761,
     393,   393,   393,  2208,  1187,   505,   499,  -132,  -761,  -761,
     491,  3219,  3219,  3219,  3219,  1187,  -761,  3424,   504,  3219,
     218,   522,   650,  3424,   564,  -761,  -761,  -761,  -761,  3219,
    3219,  2209,  3219,  1876,  2042,   549,   549,  3219,  3219,  3219,
    3219,  3219,  3219,  3219,  3219,  3219,  3219,  3219,  3219,  2042,
    3219,  3219,  3219,  3219,  3219,  3219,  3219,  2379,  1187,  1187,
    1187,  1187,  1187,  3219,  3219,  3219,  2550,  3219,  1187,  3219,
    1187,  3219,  1187,  1187,   336,  1292,  1405,  1458,  1187,  1187,
    1187,  1187,  1187,  1187,  1187,  1187,  2042,  1187,  -761,  -761,
    1187,  3219,   563,   583,  1187,   393,  1187,   393,  1187,   743,
      59,   763,  1187,  1187,  1187,  1187,  1187,  1187,  1187,  -761,
    -761,  -761,  -761,  3219,  3219,  3219,  3219,  3219,  3219,  3219,
    3219,  3219,  3219,  3219,   700,   708,   665,  -761,   710,   717,
     711,  -761,    39,   726,   732,   584,  3424,   801,   868,   845,
    3546,  3219,   741,  1187,  -761,  -761,  3219,   584,   496,   427,
     745,    25,  -761,   906,  -761,  -761,   639,  3219,  3219,  -761,
    -761,   180,  -761,  -761,    46,  1585,   218,  3424,   576,   601,
    3219,   218,  3219,  -761,   -33,  -761,  -761,  3219,  1187,  -761,
    3219,    12,  3219,  3219,   746,   731,   744,   747,  -761,  4095,
     166,  3219,  3219,  3219,  3546,   748,    12,    12,  3424,   218,
     663,  -761,   584,  3424,   749,  -761,  -761,  -761,  3546,  -761,
    -761,  3219,  -761,  -761,  -761,  -761,   752,   753,  1615,  1628,
    1891,   755,    79,   760,   761,   770,   771,   774,   775,   769,
     779,    12,  2057,  4142,  4153,  4164,  4180,  4204,   734,  4215,
     986,  4226,  4273,   785,  4289,  4335,  4346,  4357,  4382,  4398,
    2223,  -761,  4409,   205,  -124,  -123,   -92,   276,  2394,  2568,
    1301,  -761,  4420,  4466,   284,  4491,   -91,  4529,   292,   298,
    -761,   311,  -761,   312,  -761,   319,  -761,   355,   361,   374,
     375,   -89,   -24,   376,   377,   410,   102,   786,   -68,   787,
     797,    -1,   280,  4540,  -761,  -761,    20,  -115,    30,    50,
      47,  -761,  -761,   218,   218,   218,   218,   218,   218,  -761,
      84,    84,  3219,  3219,   825,   159,   245,   272,   -15,   237,
    -761,   152,   152,   743,   743,  -761,  -761,   413,  -761,  -761,
     429,  -761,  -761,  -761,   879,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   668,  2736,  3219,    73,  4551,  3294,  -761,
    -761,  3219,  3219,  -761,  -761,  3219,  -761,   714,   798,   799,
     802,   803,  2902,  3068,   800,   805,  -761,  -761,  -761,  3219,
     900,   903,  -761,    81,  3239,  3424,  -761,  -761,   132,  -761,
    3219,  3828,  3875,  -761,  3219,  3219,  3219,  -761,  -761,   584,
    3424,   584,  3424,   529,  3424,  -761,  3219,  3219,  3219,  -761,
    -761,  -761,  3219,  3219,    22,  3424,  -761,  -761,  3219,  3219,
    3219,  -761,  -761,  1187,  3383,  -761,   811,   812,  -761,  -761,
    3219,  3219,  3219,  3219,  -761,  -761,  -761,  -761,  -761,  -761,
    3219,  -761,  -761,  3219,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  3219,  -761,  -761,  3219,  3219,  3219,  -761,
    3219,  3219,  -761,  1187,  -761,  -761,  -761,  -761,  -761,  3219,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    1187,  1187,  -761,  -761,  -761,  -761,  -761,  -761,  1187,  -761,
    -761,  3219,  -761,  3219,  -761,   981,  -761,  1187,   981,  -761,
    1187,  1187,  -761,   813,  -761,   814,  2209,   643,   817,   818,
    -761,   826,   830,  -761,  -761,   685,  3546,  -761,  -761,  -761,
    3219,  3900,   941,  1187,  -761,  1187,   218,   584,   496,  3938,
     714,   714,  4575,   834,   836,  -761,   835,  -761,  -761,  -761,
    -761,  3219,  3219,  -761,  -761,  3949,  2042,  2042,  1187,  1187,
    1187,  -761,  3219,  3219,   838,  4600,  4611,  1316,  3219,  3424,
      12,  -761,   837,  -761,    70,  -761,  -761,  -761,  4622,  4660,
    4684,   412,   839,    82,  -761,  -761,  4731,  4742,   841,    51,
    4753,  4769,  4793,  4804,  4815,  1574,  4862,  4878,   195,  4924,
     196,   214,   414,  3960,   808,  4935,   101,   420,   124,   441,
     454,    84,    84,  -761,  -761,  -761,  -761,  3219,   973,   980,
     978,  4946,  3219,   850,   460,   215,  -761,  3219,  -761,  -761,
    -761,  -761,  -761,  -761,   852,   853,  3424,  3424,  1187,  -761,
    -761,   218,   218,   143,  3985,  3424,  -761,   952,   958,   960,
    3219,  4010,  3219,   721,  3219,  -761,  -761,  -761,  -761,  -761,
    -761,  1187,  -761,  -761,  -761,  3219,  -761,  -761,  -761,  -761,
    -761,  -761,  3219,  -761,  -761,  -761,  1187,  -761,  -761,  3219,
    -761,  3219,  -761,  1187,  -761,  -761,  -761,  1187,  -761,  -761,
    1187,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   985,   671,
    4971,  3219,   982,  1187,  4987,   714,   864,   865,   714,  -761,
    -761,   218,  1187,  1187,  1187,  1187,  1187,  4998,  1187,  -761,
     869,   871,   235,  -761,    94,   461,  4021,  5009,   488,  5055,
    5080,   502,   503,   510,  3546,  3832,  3219,   994,  -761,   872,
    -761,  4032,   873,   523,  -761,  -761,  -761,  -761,  -761,   218,
     218,   218,   218,   218,   975,   199,   874,   877,  -761,   721,
    3219,  -761,  -761,  3219,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   978,  1014,   469,  3546,  -761,  1187,  3219,  3219,  -761,
     906,  1187,  3219,  -761,  -761,  3546,  -761,  3424,  3546,  5118,
    -761,  -761,   978,   897,   226,  5129,  4070,   714,   218,  3424,
      23,   978,  -761,  3546,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  1187,  -761,  3219,  -761,  -761,  -761,  -761,   987,
     978,   526,  5140,  -761,  -761,  -761,  -761,  -761,  -761,  1055,
     985,  -761,  -761,  -761,  -761,  -761
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     111,     0,     0,   105,   332,   367,   372,    11,     0,     0,
       0,     0,    24,    26,   310,     0,     0,     0,     0,   311,
      18,    20,   347,   359,     0,   440,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   112,   113,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       4,     3,     0,     7,    39,    41,     9,    22,    23,    21,
       0,    13,    14,    17,    16,    15,    28,    29,     0,   294,
       0,   294,     0,     0,     6,   287,   286,    30,    31,    38,
     283,   198,   133,   284,   285,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
       0,     0,     0,     0,   254,   257,   260,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   164,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,   211,   192,   197,   135,     0,     0,
       0,    12,   294,   294,    42,   312,    19,     0,     6,   391,
       0,   444,     0,     0,   420,   436,    62,    61,     0,     0,
      63,   104,    53,     0,    55,     0,   412,   414,    56,   410,
     416,     0,     0,   417,   280,    57,    59,     0,    89,     0,
       0,   455,     0,    86,    91,    79,    40,     0,     0,     0,
      67,     0,    50,    72,     0,    88,    87,     0,     0,   114,
     115,    92,     8,    10,     0,     0,   106,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,   107,     1,     2,
       0,     0,     0,     0,     0,     0,   301,   177,     0,   296,
     116,     0,     0,   368,     4,   294,   294,    32,    33,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      36,   181,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   316,    25,   313,   321,   322,
      27,   319,     0,     0,     0,   352,   351,     0,     4,     0,
       6,     0,     0,     0,   441,   442,     0,   423,   425,    45,
       0,     0,    49,   438,   294,   294,     0,     0,     0,   294,
     294,     0,   282,   281,     0,     0,    90,   454,     0,     0,
       0,    66,     0,    71,   436,   123,   122,     0,     0,    68,
       0,    74,     0,     0,   131,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     6,     0,     0,     0,   178,   121,
       0,   292,   299,   300,   295,   297,   293,   333,     6,   379,
     377,     0,   378,   374,   376,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,   258,     0,   261,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   165,     0,     0,     0,     0,
       0,   138,   212,   206,   208,   210,   207,   209,   205,   137,
       0,     0,     0,     0,   185,   187,   189,   186,   188,   184,
     203,   200,   199,   201,   202,   294,   294,     0,   294,   294,
       0,    43,    44,   349,   353,   366,   364,   365,   362,   361,
     363,   360,   381,     4,     0,     0,     0,     0,     0,   421,
      46,    47,     0,   428,   430,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   418,   419,     0,
       0,     0,   126,   125,   129,   215,    51,    69,    82,    73,
       0,     0,     0,   294,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   109,   108,     5,     0,     0,     0,   307,
     308,   302,     0,     0,     4,   375,   273,   176,     0,     0,
       0,   274,   275,     0,     0,   268,     0,     0,   193,   194,
       0,     0,     0,     0,   216,   217,   218,   219,   220,   221,
       0,   223,   224,     0,   226,   227,   190,   232,   233,   228,
     229,   230,   231,     0,   235,   240,     0,     0,     0,   239,
       0,     0,   143,     0,   148,   149,   241,   174,   242,     0,
     175,   150,   151,   253,   256,   259,   262,   154,   152,   153,
       0,     0,   155,   248,   156,   252,   251,   166,     0,   249,
     157,     0,   159,     0,   158,     0,   169,     0,     0,   171,
       0,     0,   456,    35,   458,    37,   182,   180,     0,     0,
     314,     0,     0,   320,   350,   356,     6,   393,   394,   392,
       0,     0,   445,     0,   443,     0,   426,   424,   425,     0,
       0,     0,     0,   406,   408,   437,   403,   288,   290,   294,
     294,     0,     0,   413,   415,    64,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,    80,
       0,    85,     0,   298,     0,   371,   370,   369,     0,     0,
       0,     0,     0,     0,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   318,   323,   324,     0,     0,     0,
     382,     0,     0,     0,     0,     0,   422,     0,   429,   431,
     432,   294,   294,   404,     0,     0,    52,    54,     0,   127,
     128,   124,   130,    83,    76,    77,   132,     0,     0,     0,
       0,     0,     0,   325,     0,   265,   266,   267,   276,   277,
     278,     0,   195,   196,   172,     0,   222,   225,   234,   139,
     140,   142,     0,   237,   238,   144,     0,   243,   244,     0,
     246,     0,   167,     0,   161,   160,   270,     0,   168,   272,
       0,   170,   191,   457,   459,   354,   357,   348,   397,   447,
       0,     0,   446,     0,     0,     0,     0,     0,     0,   289,
     291,    65,     0,     0,     0,     0,     0,     0,     0,    81,
     328,   329,     0,   326,   343,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,   111,     0,   395,   451,     0,
     448,     0,     0,     0,   434,   433,   407,   409,   405,    84,
      75,   119,   120,   118,     0,     0,     0,     0,   303,     0,
       0,   334,   279,     0,   141,   145,   245,   247,   250,   269,
     271,   355,     4,   401,     6,   383,     0,     0,     0,   427,
     438,     0,     0,   330,   331,     6,   327,   344,     6,     0,
     402,   398,   396,     0,     0,     0,     0,     0,   117,   110,
       4,   335,   173,     6,   390,   387,   388,   389,   385,   386,
     384,   452,     0,   449,     0,   435,   306,   305,   304,     0,
     399,     0,     0,   338,   340,   341,   342,   337,   339,   345,
     397,   453,   450,   346,   336,   400
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -761,  -761,   -77,  -761,   616,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  1015,  -230,  -761,  -761,    -7,   759,  -761,  1016,
     -11,  -761,  -761,   778,  -284,   -27,  -761,   651,   -30,    -4,
    -761,     1,     3,   -73,  -761,  -761,   409,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,   489,  -761,   492,  -761,    85,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   228,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,    13,  -761,  -761,  -761,
    -760,  -761,  -761,  -761,   667,  -761,  -761,   308,   673,  -761,
    -761,  -761,  -761,  -761,    88,  -761,    36,  -761,  -761
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    59,    60,   260,    61,   178,   179,   560,   561,   195,
     424,    62,    63,   427,    64,    65,   435,   171,   172,    66,
     229,   563,   562,   477,   478,   230,   174,   213,   175,    87,
     200,   176,   177,   268,   269,   454,   455,    69,   450,   802,
    1015,  1048,   651,    70,   376,   377,   380,   381,   952,   953,
      71,    82,   653,  1018,  1049,  1059,   991,  1064,    72,   187,
     584,   387,   755,   964,   849,   965,    73,   188,   591,    74,
      83,   458,   807,    75,    84,   465,    76,   389,   756,   928,
    1023,  1040,    77,   390,   759,  1005,   967,  1033,  1060,  1021,
     775,   938,   776,   208,   209,   215,   399,   599,   402,   770,
     771,   935,  1010,   403,   607,   194,   222,   743,   745
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     173,    67,   480,    68,   214,    88,    89,   274,   271,   394,
     858,   859,   395,   189,   233,   234,   197,   432,   433,   201,
     203,   205,   425,   425,   400,   221,   221,   221,   182,   603,
      78,   216,   604,    80,   241,    90,   358,   805,   418,    93,
      94,   210,   183,   443,   358,   358,   221,  1046,   244,    90,
     245,   696,   697,    93,    94,   617,   368,   369,   736,   186,
     737,   190,   425,   191,   192,   806,  1047,   267,   261,   262,
       1,     2,   273,   226,   227,   235,   358,   358,   228,   358,
     263,   884,   708,   698,   709,    67,   720,    68,    85,   185,
     281,    86,   240,   256,   352,   353,   354,   355,   356,   357,
     358,   236,   237,   238,   258,   727,   990,   728,   239,   383,
     384,   388,   249,   361,   362,   198,   199,   363,   364,   365,
     366,   367,   368,   369,   250,   352,   353,   354,   355,   356,
     357,    79,   361,   362,    81,   251,   363,   364,   365,   366,
     367,   368,   369,   401,   358,   352,   353,   354,   355,   356,
     357,   721,   370,   371,   372,   373,   361,   362,   349,   351,
     363,   364,   365,   366,   367,   368,   369,   358,   352,   353,
     354,   355,   356,   357,   731,   975,   386,   396,   978,   358,
     193,   412,   413,   398,   206,   207,   426,   426,   358,    67,
     252,    68,    52,    53,    54,   735,   358,   605,   358,   211,
     212,   630,   466,   467,   423,   738,   415,   358,   417,   253,
     429,   431,   551,   211,   212,   358,   647,   648,   370,   371,
     372,   373,   741,   739,   369,   740,   426,   358,   366,   367,
     368,   369,   551,   254,   445,   446,   447,   370,   371,   372,
     373,   358,   439,   259,   436,   437,   762,   358,   763,   358,
     358,   672,   662,   448,   663,   890,   788,   891,   453,   264,
     481,   370,   371,   372,   373,   539,   540,  1045,   468,   469,
     358,   470,   221,   221,   916,   725,   917,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   221,   494,
     495,   496,   497,   498,   499,   500,   502,   919,   265,   920,
     358,   266,   508,   509,   510,   512,   513,   790,   515,   369,
     517,   358,   364,   593,   366,   367,   368,   369,   942,   473,
     474,   372,   373,   277,   278,   221,   370,   371,   372,   373,
     543,   608,   609,   272,   358,   493,   614,   615,   547,   638,
     549,    92,   367,   368,   369,    95,   352,   353,   354,   355,
     356,   357,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   358,   358,    79,    97,   358,   905,   908,
     906,   909,   537,   358,  1012,    81,   359,   360,   695,   275,
     594,   654,   358,   358,   214,   597,   358,   910,   551,   911,
     933,    67,   276,    68,   358,   279,   612,   613,   434,  1041,
     627,  1042,   280,   629,   370,   371,   372,   373,   988,   624,
     989,   625,   370,   371,   372,   373,   282,   374,   375,   361,
     362,   631,   632,   363,   364,   365,   366,   367,   368,   369,
     640,   642,   644,   378,   379,   283,   107,   284,   108,   370,
     371,   372,   373,   285,   358,    67,   286,    68,   358,   699,
     655,   836,   358,   732,   838,   733,   392,   706,   287,    67,
     358,    68,   129,   130,   131,   711,   358,   288,   135,   136,
     137,   712,   139,    90,   141,   142,   143,    93,    94,   358,
     358,   148,   149,   150,   713,   714,   153,   358,   155,   289,
     157,   406,   715,   159,  -380,   161,   162,   163,   290,   165,
     291,   167,   748,   749,   292,   751,   752,   293,   180,   520,
     294,   361,   362,   295,  1020,   363,   364,   365,   366,   367,
     368,   369,   296,   358,   370,   371,   372,   373,   716,   358,
     297,   361,   362,   444,   717,   363,   364,   365,   366,   367,
     368,   369,   358,   358,   358,   358,   598,   718,   719,   722,
     723,   746,   747,   475,   476,   298,   742,   744,   361,   362,
     794,   299,   363,   364,   365,   366,   367,   368,   369,   300,
     882,   352,   353,   354,   355,   356,   357,   459,   358,   460,
     358,   461,   358,   724,   761,   888,   411,   912,   358,   895,
     768,   769,   414,   918,   772,   352,   353,   354,   355,   356,
     357,   600,   601,   791,   462,   301,    92,   463,   785,   358,
      95,   302,   464,   419,   921,   303,   370,   371,   372,   373,
     800,   801,   358,   795,   796,   797,   420,   922,   358,   358,
     304,    97,   428,   932,   992,   799,   370,   371,   372,   373,
     305,   453,   804,   610,   611,   818,   306,   808,   809,   810,
     352,   353,   354,   355,   356,   357,   358,   620,   621,   816,
     817,   995,   819,   370,   371,   372,   373,   649,   650,   820,
     358,   358,   821,   358,   442,   998,   999,   451,   358,   850,
     441,   307,   822,  1000,   308,   823,   824,   825,   309,   826,
     827,   358,   310,   622,   358,   456,  1009,   358,   829,  1061,
     311,   107,   312,   108,   798,   361,   864,   865,   313,   363,
     364,   365,   366,   367,   368,   369,   757,   758,   773,   774,
     833,   457,   835,   847,   848,   950,   951,   129,   130,   131,
     968,   969,   314,   135,   136,   137,   544,   139,   315,   141,
     142,   143,   316,   317,   318,   319,   148,   149,   150,   851,
     320,   153,   358,   155,   321,   157,   545,    67,   159,    68,
     161,   162,   163,   322,   165,   323,   167,   324,   325,   326,
     866,   867,   327,   180,   181,   221,   221,   184,   328,   329,
     330,   874,   875,   331,   332,   333,   196,   881,   936,   937,
     202,   204,   334,   335,   336,   220,   361,   362,   337,   338,
     363,   364,   365,   366,   367,   368,   369,   246,   247,   248,
     370,   371,   372,   373,   339,   369,   255,   257,   340,   341,
     342,   343,   869,   870,   344,   361,   362,   345,   346,   363,
     364,   365,   366,   367,   368,   369,   386,   923,   924,   270,
     577,   930,   347,   583,   361,   362,   934,   348,   363,   364,
     365,   366,   367,   368,   369,   949,   361,   362,   391,   393,
     363,   364,   365,   366,   367,   368,   369,   404,   405,   947,
     409,   410,   575,   954,   352,   353,   354,   355,   356,   357,
     576,   585,   578,   586,   956,   587,   580,  1001,  1002,   579,
     592,   957,   364,   365,   366,   367,   368,   369,   959,   581,
     960,   370,   371,   372,   373,   582,   634,   679,   588,   680,
    1034,   589,  1035,   595,  1036,   606,   590,   602,   633,   635,
     971,   754,   636,   646,   652,   656,   657,  1022,   661,   350,
     370,   371,   372,   373,   665,   664,   552,  1037,  1030,   382,
    1038,  1031,   666,   667,   670,  1039,   385,   668,   669,   370,
     371,   372,   373,   397,   671,  1003,  1050,   407,   686,   726,
     729,   370,   371,   372,   373,    67,    67,    68,    68,   408,
     730,   777,   778,   783,   779,   780,   358,   416,   784,  1017,
     786,   914,  1019,   787,   814,   815,   476,   421,   841,   842,
     843,   844,   370,   371,   372,   373,  1025,  1026,   853,   845,
    1053,  1029,  1054,   846,  1055,    67,   861,    68,   862,   883,
     863,   876,   889,   440,   894,   926,    67,   927,    68,    67,
      -4,    68,   931,   944,   449,   939,   940,  1056,   452,   945,
    1057,   946,   966,  1052,    67,  1058,    68,   976,   977,   972,
    1004,   986,   472,   987,  1006,  1008,  1011,  1013,   361,   362,
    1014,  -358,   363,   364,   365,   366,   367,   368,   369,  1063,
     645,   803,   242,   243,   479,   618,   750,   503,   504,   505,
     506,   507,   753,  1065,  1016,   925,   856,   514,   616,   516,
       0,   518,   519,   521,   523,   525,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   538,   626,  1027,   541,
     542,     0,     0,   546,     0,   548,     0,   550,     0,     0,
       0,   553,   554,   555,   556,   557,   558,   559,     0,     0,
       0,     0,    90,    91,    92,     0,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,   596,   370,   371,   372,   373,     0,     0,   682,
       0,   683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   623,     0,
       0,    99,   100,   101,   102,     0,     0,   628,     0,     0,
       0,     0,    92,     0,     0,   103,    95,     0,   104,     0,
     639,   641,   643,   223,     0,     0,     0,     0,     0,     0,
       0,   224,     0,     0,     0,   105,   106,    97,     0,   107,
       0,   108,     0,     0,   225,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   107,     0,   108,
       0,   170,     0,     0,     0,   219,     0,    92,     0,   361,
     362,    95,     0,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,   129,   130,   131,     0,     0,     0,   135,
     136,   137,    97,   139,     0,   141,   142,   143,     0,     0,
       0,     0,   148,   149,   150,     0,     0,   153,     0,   155,
       0,   157,     0,     0,   159,     0,   161,   162,   163,     0,
     165,     0,   167,     0,     0,     0,     0,   766,     0,   180,
     767,     0,     0,   361,   362,     0,     0,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   361,   362,
       0,     0,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,   107,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,   371,   372,   373,     0,     0,
      92,   452,   422,     0,    95,     0,     0,     0,   129,   130,
     131,     0,   811,   813,   135,   136,   137,     0,   139,     0,
     141,   142,   143,     0,     0,    97,     0,   148,   149,   150,
       0,     0,   153,     0,   155,     0,   157,     0,     0,   159,
       0,   161,   162,   163,     0,   165,     0,   167,     0,     0,
       0,     0,   828,    92,   180,   522,     0,    95,   370,   371,
     372,   373,     0,     0,   702,     0,   703,     0,     0,   830,
     831,     0,     0,   370,   371,   372,   373,   832,    97,   879,
       0,   880,   834,     0,     0,     0,   837,     0,     0,   839,
     840,     0,     0,     0,     0,   107,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   854,     0,   855,     0,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   135,   136,   137,
       0,   139,     0,   141,   142,   143,     0,   871,   872,   873,
     148,   149,   150,     0,     0,   153,     0,   155,   107,   157,
     108,     0,   159,     0,   161,   162,   163,     0,   165,     0,
     167,     0,     0,     0,     0,     0,     0,   180,   524,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     135,   136,   137,     0,   139,     0,   141,   142,   143,     0,
       0,     0,     0,   148,   149,   150,   385,     0,   153,     0,
     155,     0,   157,     0,     0,   159,     0,   161,   162,   163,
       0,   165,     0,   167,     0,     0,     0,   941,     0,     0,
     180,   526,     0,     0,     0,     0,   361,   362,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   361,   362,     0,
     955,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,   958,     0,     0,     0,     0,
       0,     0,   961,     0,     0,     0,   962,   361,   362,   963,
       0,   363,   364,   365,   366,   367,   368,   369,     0,     0,
     361,   362,   973,     0,   363,   364,   365,   366,   367,   368,
     369,   979,   980,   981,   982,   983,     0,   985,     0,     0,
       0,     0,     0,    90,    91,    92,     0,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,   370,   371,   372,   373,     0,     0,   901,     0,   902,
       0,     0,   370,   371,   372,   373,     0,     0,     0,     0,
     619,     0,     0,     0,     0,  1024,     0,     0,     0,     0,
    1028,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,   103,     0,     0,   104,
     658,     0,     0,     0,   217,   370,   371,   372,   373,     0,
       0,  1051,   218,   659,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,    90,
      91,    92,   170,    93,    94,    95,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   361,   362,   104,     0,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   471,     0,
       0,     0,   105,   106,     0,     0,   107,     0,   108,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,    90,    91,    92,   170,    93,
      94,    95,   219,     0,     0,     0,     0,     0,   370,   371,
     372,   373,     0,     0,     0,     0,   660,     0,     0,     0,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   361,
     362,   104,     0,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,     0,   107,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,    90,    91,    92,   170,    93,    94,    95,   219,     0,
       0,     0,     0,     0,   370,   371,   372,   373,     0,     0,
       0,     0,   673,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,   363,   364,   365,   366,   367,
     368,   369,     0,     0,   103,   361,   362,   104,     0,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,     0,   107,     0,
     108,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   370,   371,   372,   373,
     170,   438,    90,    91,    92,     0,    93,    94,    95,     0,
     370,   371,   372,   373,     0,     0,     0,     0,   693,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   361,   362,   104,     0,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,     0,     0,
       0,   170,   501,    90,    91,    92,     0,    93,    94,    95,
       0,   370,   371,   372,   373,     0,     0,     0,     0,   700,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,   104,
     361,   362,     0,     0,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,   170,   511,    90,    91,    92,     0,    93,    94,
      95,     0,   231,     0,     0,   370,   371,   372,   373,     0,
       0,     0,     0,   701,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   361,   362,
     104,     0,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,     0,
       0,   107,     0,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
      90,    91,    92,   170,    93,    94,    95,     0,     0,     0,
       0,     0,     0,   370,   371,   372,   373,     0,     0,     0,
       0,   760,     0,     0,     0,     0,    96,    97,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   361,   362,   104,     0,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,   107,     0,   108,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,    90,    91,    92,   170,
      93,    94,    95,     0,   430,     0,     0,     0,     0,   370,
     371,   372,   373,     0,     0,     0,     0,   781,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     361,   362,   104,     0,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,    90,    91,    92,   170,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   370,   371,   372,   373,     0,
       0,     0,     0,   782,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,   104,    92,
       0,   361,   362,    95,     0,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,    97,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,    92,     0,
       0,   170,    95,     0,   107,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,   373,
       0,     0,     0,    97,   789,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   135,   136,   137,     0,
     139,     0,   141,   142,   143,     0,     0,     0,     0,   148,
     149,   150,     0,     0,   153,     0,   155,     0,   157,     0,
       0,   159,     0,   161,   162,   163,     0,   165,     0,   167,
       0,     0,     0,     0,     0,     0,   765,     0,     0,     0,
       0,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,     0,     0,   107,     0,   108,   361,   362,     0,     0,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,   135,   136,   137,     0,   139,
       0,   141,   142,   143,     0,     0,     0,     0,   148,   149,
     150,     0,     0,   153,     0,   155,     0,   157,     0,     0,
     159,     0,   161,   162,   163,     0,   165,     0,   167,     0,
       1,     2,     3,     0,     0,   180,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,    11,  -309,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,   370,   371,   372,   373,     0,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      39,    40,    41,  -111,  -111,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,  -111,     0,    49,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     0,    56,     0,     4,
       0,    57,     0,     5,    58,     6,     0,     7,     8,     9,
      10,    11,  -309,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,     0,     0,     0,     0,
      23,    -6,    -6,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     0,
      56,     0,     4,     0,    57,     0,     5,    58,     6,     0,
       7,     8,     9,    10,    11,  -309,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    -6,
       0,     0,     0,    23,    -6,     0,    24,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,    29,    30,     0,
     361,   362,    31,    32,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    39,    40,    41,     0,
       0,    42,    43,    44,     0,    45,    46,    47,     0,     0,
      48,     0,     0,    49,     0,    50,    51,   361,   362,     0,
       0,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,   361,   362,     0,    55,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,    57,     0,     0,
      58,     0,     0,     0,     0,   370,   371,   372,   373,     0,
     361,   362,     0,   792,   363,   364,   365,   366,   367,   368,
     369,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,   369,   361,   362,     0,     0,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,     0,   361,   362,     0,
     793,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,   371,   372,
     373,     0,   361,   362,     0,   852,   363,   364,   365,   366,
     367,   368,   369,   361,   362,     0,     0,   363,   364,   365,
     366,   367,   368,   369,   361,   362,     0,     0,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,   857,     0,     0,   370,   371,   372,   373,
       0,     0,     0,     0,   868,     0,     0,   370,   371,   372,
     373,     0,   361,   362,     0,   913,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,     0,   361,   362,     0,
     943,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,   371,   372,
     373,     0,     0,     0,     0,   948,     0,     0,   370,   371,
     372,   373,     0,     0,     0,     0,   993,     0,     0,   370,
     371,   372,   373,     0,   361,   362,     0,  1007,   363,   364,
     365,   366,   367,   368,   369,   361,   362,     0,     0,   363,
     364,   365,   366,   367,   368,   369,   361,   362,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,     0,   361,   362,     0,  1044,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,   361,   362,   637,     0,
     363,   364,   365,   366,   367,   368,   369,   361,   362,     0,
       0,   363,   364,   365,   366,   367,   368,   369,   361,   362,
       0,     0,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
     371,   372,   373,     0,     0,   674,     0,     0,     0,     0,
     370,   371,   372,   373,     0,     0,   675,     0,     0,     0,
       0,   370,   371,   372,   373,   361,   362,   676,     0,   363,
     364,   365,   366,   367,   368,   369,     0,   370,   371,   372,
     373,   361,   362,   677,     0,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   371,   372,   373,     0,     0,   678,     0,     0,
       0,     0,   370,   371,   372,   373,     0,     0,   681,     0,
       0,     0,     0,   370,   371,   372,   373,   361,   362,   684,
       0,   363,   364,   365,   366,   367,   368,   369,   361,   362,
       0,     0,   363,   364,   365,   366,   367,   368,   369,   361,
     362,     0,     0,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,   373,   361,   362,   685,     0,   363,   364,
     365,   366,   367,   368,   369,     0,   370,   371,   372,   373,
     361,   362,   687,     0,   363,   364,   365,   366,   367,   368,
     369,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,   369,   361,   362,     0,     0,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,     0,     0,   688,     0,
       0,     0,     0,   370,   371,   372,   373,     0,     0,   689,
       0,     0,     0,     0,   370,   371,   372,   373,   361,   362,
     690,     0,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
     371,   372,   373,   361,   362,   691,     0,   363,   364,   365,
     366,   367,   368,   369,     0,   370,   371,   372,   373,     0,
       0,   692,     0,     0,     0,     0,   370,   371,   372,   373,
       0,     0,   694,     0,     0,     0,     0,   370,   371,   372,
     373,   361,   362,   704,     0,   363,   364,   365,   366,   367,
     368,   369,   361,   362,     0,     0,   363,   364,   365,   366,
     367,   368,   369,   361,   362,     0,     0,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   370,   371,   372,   373,   361,   362,   705,
       0,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,   371,
     372,   373,   361,   362,   707,     0,   363,   364,   365,   366,
     367,   368,   369,   361,   362,     0,     0,   363,   364,   365,
     366,   367,   368,   369,   361,   362,     0,     0,   363,   364,
     365,   366,   367,   368,   369,     0,   370,   371,   372,   373,
       0,     0,   710,     0,     0,     0,     0,   370,   371,   372,
     373,     0,     0,   734,     0,     0,     0,     0,   370,   371,
     372,   373,   361,   362,   764,     0,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,   361,   362,   860,     0,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,   371,   372,
     373,     0,     0,   877,     0,     0,     0,     0,   370,   371,
     372,   373,     0,     0,   878,     0,     0,     0,     0,   370,
     371,   372,   373,   361,   362,   885,     0,   363,   364,   365,
     366,   367,   368,   369,   361,   362,     0,     0,   363,   364,
     365,   366,   367,   368,   369,   361,   362,     0,     0,   363,
     364,   365,   366,   367,   368,   369,     0,   370,   371,   372,
     373,   361,   362,   886,     0,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   371,   372,   373,   361,   362,   887,     0,   363,
     364,   365,   366,   367,   368,   369,   361,   362,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   361,   362,     0,
       0,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,   371,
     372,   373,     0,     0,   892,     0,     0,     0,     0,   370,
     371,   372,   373,     0,     0,   893,     0,     0,     0,     0,
     370,   371,   372,   373,   361,   362,   896,     0,   363,   364,
     365,   366,   367,   368,   369,     0,   370,   371,   372,   373,
     361,   362,   897,     0,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,   373,     0,     0,   898,     0,     0,     0,
       0,   370,   371,   372,   373,     0,     0,   899,     0,     0,
       0,     0,   370,   371,   372,   373,   361,   362,   900,     0,
     363,   364,   365,   366,   367,   368,   369,   361,   362,     0,
       0,   363,   364,   365,   366,   367,   368,   369,   361,   362,
       0,     0,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
     371,   372,   373,   361,   362,   903,     0,   363,   364,   365,
     366,   367,   368,   369,     0,   370,   371,   372,   373,   361,
     362,   904,     0,   363,   364,   365,   366,   367,   368,   369,
     361,   362,     0,     0,   363,   364,   365,   366,   367,   368,
     369,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   371,   372,   373,     0,     0,   907,     0,     0,
       0,     0,   370,   371,   372,   373,     0,     0,   915,     0,
       0,     0,     0,   370,   371,   372,   373,   361,   362,   929,
       0,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,   371,
     372,   373,   361,   362,   970,     0,   363,   364,   365,   366,
     367,   368,   369,     0,   370,   371,   372,   373,     0,     0,
     974,     0,     0,     0,     0,   370,   371,   372,   373,     0,
       0,   984,     0,     0,     0,     0,   370,   371,   372,   373,
     361,   362,   994,     0,   363,   364,   365,   366,   367,   368,
     369,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,   369,   361,   362,     0,     0,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   370,   371,   372,   373,     0,     0,   996,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,   371,   372,
     373,     0,     0,   997,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   370,   371,   372,   373,     0,
       0,  1032,     0,     0,     0,     0,   370,   371,   372,   373,
       0,     0,  1043,     0,     0,     0,     0,   370,   371,   372,
     373,     0,     0,  1062
};

static const yytype_int16 yycheck[] =
{
      11,     0,   286,     0,    34,     9,    10,    84,    81,     4,
     770,   771,     7,    24,    41,    42,    27,   247,   248,    30,
      31,    32,    11,    11,    57,    36,    37,    38,   172,     4,
      71,    35,     7,    71,    45,     3,   168,    15,    10,     7,
       8,     9,   172,   175,   168,   168,    57,    24,    47,     3,
      47,   175,   175,     7,     8,     9,    71,    72,   173,     7,
     175,    57,    11,    59,    60,    43,    43,    78,    87,    88,
       4,     5,    83,    37,    38,    58,   168,   168,    83,   168,
      99,    11,   173,   175,   175,    84,   175,    84,     4,    27,
     101,     7,    90,    57,    66,    67,    68,    69,    70,    71,
     168,    84,    85,    86,     0,   173,    12,   175,    91,   182,
     183,   188,   105,    62,    63,     4,     5,    66,    67,    68,
      69,    70,    71,    72,   172,    66,    67,    68,    69,    70,
      71,   172,    62,    63,   172,   172,    66,    67,    68,    69,
      70,    71,    72,   176,   168,    66,    67,    68,    69,    70,
      71,   175,   167,   168,   169,   170,    62,    63,   169,   170,
      66,    67,    68,    69,    70,    71,    72,   168,    66,    67,
      68,    69,    70,    71,   175,   935,   187,   172,   938,   168,
     176,   211,   212,   194,     4,     5,   175,   175,   168,   188,
     172,   188,   126,   127,   128,   175,   168,   172,   168,   167,
     168,   431,   275,   276,   231,   175,   217,   168,   219,   172,
     237,   238,   173,   167,   168,   168,   446,   447,   167,   168,
     169,   170,   175,   173,    72,   175,   175,   168,    69,    70,
      71,    72,   173,   172,   261,   262,   263,   167,   168,   169,
     170,   168,   253,    43,   251,   252,   173,   168,   175,   168,
     168,   481,   173,   264,   175,   173,   175,   175,   269,    71,
     287,   167,   168,   169,   170,   338,   339,  1027,   279,   280,
     168,   282,   283,   284,   173,   173,   175,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   173,    71,   175,
     168,    23,   313,   314,   315,   316,   317,   175,   319,    72,
     321,   168,    67,   390,    69,    70,    71,    72,   175,   283,
     284,   169,   170,    34,    35,   336,   167,   168,   169,   170,
     341,   404,   405,     4,   168,   299,   409,   410,   345,   173,
     347,     5,    70,    71,    72,     9,    66,    67,    68,    69,
      70,    71,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   168,   168,   172,    30,   168,   173,   173,
     175,   175,   336,   168,   175,   172,    19,    20,   173,   172,
     391,   458,   168,   168,   414,   396,   168,   173,   173,   175,
     175,   390,   172,   390,   168,   172,   407,   408,     5,   173,
     427,   175,   172,   430,   167,   168,   169,   170,   173,   420,
     175,   422,   167,   168,   169,   170,   172,     4,     5,    62,
      63,   432,   433,    66,    67,    68,    69,    70,    71,    72,
     441,   442,   443,     4,     5,   172,   100,   172,   102,   167,
     168,   169,   170,   172,   168,   444,   172,   444,   168,   173,
     461,   735,   168,   173,   738,   175,    57,   173,   172,   458,
     168,   458,   126,   127,   128,   173,   168,   172,   132,   133,
     134,   173,   136,     3,   138,   139,   140,     7,     8,   168,
     168,   145,   146,   147,   173,   173,   150,   168,   152,   172,
     154,   175,   173,   157,    45,   159,   160,   161,   172,   163,
     172,   165,   575,   576,   172,   578,   579,   172,   172,   173,
     172,    62,    63,   172,    45,    66,    67,    68,    69,    70,
      71,    72,   172,   168,   167,   168,   169,   170,   173,   168,
     172,    62,    63,    42,   173,    66,    67,    68,    69,    70,
      71,    72,   168,   168,   168,   168,    50,   173,   173,   173,
     173,   562,   563,     4,     5,   172,   560,   561,    62,    63,
     633,   172,    66,    67,    68,    69,    70,    71,    72,   172,
     800,    66,    67,    68,    69,    70,    71,    13,   168,    15,
     168,    17,   168,   173,   595,   173,   175,   173,   168,   819,
     601,   602,   175,   173,   605,    66,    67,    68,    69,    70,
      71,   174,   175,   630,    40,   172,     5,    43,   619,   168,
       9,   172,    48,   175,   173,   172,   167,   168,   169,   170,
     647,   648,   168,   634,   635,   636,   175,   173,   168,   168,
     172,    30,   175,   173,   173,   646,   167,   168,   169,   170,
     172,   652,   653,     4,     5,   672,   172,   658,   659,   660,
      66,    67,    68,    69,    70,    71,   168,    81,    82,   670,
     671,   173,   673,   167,   168,   169,   170,     4,     5,   680,
     168,   168,   683,   168,   175,   173,   173,   173,   168,   756,
     175,   172,   693,   173,   172,   696,   697,   698,   172,   700,
     701,   168,   172,    92,   168,   173,   173,   168,   709,   173,
     172,   100,   172,   102,   175,    62,   779,   780,   172,    66,
      67,    68,    69,    70,    71,    72,    48,    49,     4,     5,
     731,    71,   733,    38,    39,     4,     5,   126,   127,   128,
      59,    60,   172,   132,   133,   134,   173,   136,   172,   138,
     139,   140,   172,   172,   172,   172,   145,   146,   147,   760,
     172,   150,   168,   152,   172,   154,   173,   756,   157,   756,
     159,   160,   161,   172,   163,   172,   165,   172,   172,   172,
     781,   782,   172,   172,    15,   786,   787,    18,   172,   172,
     172,   792,   793,   172,   172,   172,    27,   798,   861,   862,
      31,    32,   172,   172,   172,    36,    62,    63,   172,   172,
      66,    67,    68,    69,    70,    71,    72,    48,    49,    50,
     167,   168,   169,   170,   172,    72,    57,    58,   172,   172,
     172,   172,   786,   787,   172,    62,    63,   172,   172,    66,
      67,    68,    69,    70,    71,    72,   847,   841,   842,    80,
     175,   852,   172,    42,    62,    63,   857,   172,    66,    67,
      68,    69,    70,    71,    72,   882,    62,    63,   172,   172,
      66,    67,    68,    69,    70,    71,    72,   172,   172,   880,
     172,   172,   172,   884,    66,    67,    68,    69,    70,    71,
     172,    13,   172,    15,   895,    17,   175,   964,   965,   172,
      45,   902,    67,    68,    69,    70,    71,    72,   909,   173,
     911,   167,   168,   169,   170,   173,   175,   173,    40,   175,
      13,    43,    15,   172,    17,     9,    48,   172,   172,   175,
     931,    42,   175,   175,   175,   173,   173,  1004,   173,   170,
     167,   168,   169,   170,   173,   175,   173,    40,  1015,   180,
      43,  1018,   172,   172,   175,    48,   187,   173,   173,   167,
     168,   169,   170,   194,   175,   966,  1033,   175,   173,   173,
     173,   167,   168,   169,   170,   964,   965,   964,   965,   175,
     173,   173,   173,   173,   172,   172,   168,   218,   173,   990,
      80,   173,   993,    80,   173,   173,     5,   228,   175,   175,
     173,   173,   167,   168,   169,   170,  1007,  1008,    57,   173,
      13,  1012,    15,   173,    17,  1004,   172,  1004,   172,   172,
     175,   173,   173,   254,   173,    42,  1015,    37,  1015,  1018,
      42,  1018,   172,    71,   265,   173,   173,    40,   269,    71,
      43,    71,    47,  1044,  1033,    48,  1033,   173,   173,    57,
      46,   172,   283,   172,   172,   172,    71,   173,    62,    63,
     173,    37,    66,    67,    68,    69,    70,    71,    72,     4,
     444,   652,    47,    47,   286,   414,   577,   308,   309,   310,
     311,   312,   580,  1060,   989,   847,   768,   318,   411,   320,
      -1,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   424,  1010,   340,
     341,    -1,    -1,   344,    -1,   346,    -1,   348,    -1,    -1,
      -1,   352,   353,   354,   355,   356,   357,   358,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,   393,   167,   168,   169,   170,    -1,    -1,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,   428,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    76,     9,    -1,    79,    -1,
     441,   442,   443,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    96,    97,    30,    -1,   100,
      -1,   102,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   100,    -1,   102,
      -1,   172,    -1,    -1,    -1,   176,    -1,     5,    -1,    62,
      63,     9,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    30,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,   154,    -1,    -1,   157,    -1,   159,   160,   161,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,   598,    -1,   172,
     601,    -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,    -1,
       5,   652,   175,    -1,     9,    -1,    -1,    -1,   126,   127,
     128,    -1,   663,   664,   132,   133,   134,    -1,   136,    -1,
     138,   139,   140,    -1,    -1,    30,    -1,   145,   146,   147,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,
      -1,   159,   160,   161,    -1,   163,    -1,   165,    -1,    -1,
      -1,    -1,   703,     5,   172,   173,    -1,     9,   167,   168,
     169,   170,    -1,    -1,   173,    -1,   175,    -1,    -1,   720,
     721,    -1,    -1,   167,   168,   169,   170,   728,    30,   173,
      -1,   175,   733,    -1,    -1,    -1,   737,    -1,    -1,   740,
     741,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   763,    -1,   765,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,    -1,   138,   139,   140,    -1,   788,   789,   790,
     145,   146,   147,    -1,    -1,   150,    -1,   152,   100,   154,
     102,    -1,   157,    -1,   159,   160,   161,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,   847,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,    -1,   159,   160,   161,
      -1,   163,    -1,   165,    -1,    -1,    -1,   868,    -1,    -1,
     172,   173,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
     891,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,
      -1,    -1,   913,    -1,    -1,    -1,   917,    62,    63,   920,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      62,    63,   933,    -1,    66,    67,    68,    69,    70,    71,
      72,   942,   943,   944,   945,   946,    -1,   948,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,   167,   168,   169,   170,    -1,    -1,   173,    -1,   175,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,  1006,    -1,    -1,    -1,    -1,
    1011,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    76,    -1,    -1,    79,
     175,    -1,    -1,    -1,    84,   167,   168,   169,   170,    -1,
      -1,  1042,    92,   175,    -1,    -1,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,     3,
       4,     5,   172,     7,     8,     9,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    62,    63,    79,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,     3,     4,     5,   172,     7,
       8,     9,   176,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    62,
      63,    79,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,     3,     4,     5,   172,     7,     8,     9,   176,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    76,    62,    63,    79,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   167,   168,   169,   170,
     172,   173,     3,     4,     5,    -1,     7,     8,     9,    -1,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,   175,    -1,
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
     161,   162,   163,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,   172,   173,     3,     4,     5,    -1,     7,     8,     9,
      -1,   167,   168,   169,   170,    -1,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,   172,   173,     3,     4,     5,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
       3,     4,     5,   172,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,    -1,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     153,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,     3,     4,     5,   172,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      62,    63,    79,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,     3,     4,     5,   172,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,     5,
      -1,    62,    63,     9,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    30,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,     5,    -1,
      -1,   172,     9,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
      -1,    -1,    -1,    30,   175,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,
      -1,   157,    -1,   159,   160,   161,    -1,   163,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,
     157,    -1,   159,   160,   161,    -1,   163,    -1,   165,    -1,
       4,     5,     6,    -1,    -1,   172,    10,    -1,    -1,    -1,
      14,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      44,   167,   168,   169,   170,    -1,    -1,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    99,    -1,   101,    -1,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,   151,    -1,    10,
      -1,   155,    -1,    14,   158,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    -1,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
     151,    -1,    10,    -1,   155,    -1,    14,   158,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    -1,
      62,    63,    60,    61,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,
      -1,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    62,    63,    -1,   133,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,    -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,
      62,    63,    -1,   175,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    62,    63,    -1,
     175,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    62,    63,    -1,   175,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,   175,    -1,    -1,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,   175,    -1,    -1,   167,   168,   169,
     170,    -1,    62,    63,    -1,   175,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    62,    63,    -1,
     175,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,   175,    -1,    -1,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,   175,    -1,    -1,   167,
     168,   169,   170,    -1,    62,    63,    -1,   175,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,   167,   168,   169,
     170,    -1,    62,    63,    -1,   175,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    62,    63,   173,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,    62,    63,   173,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,   167,   168,   169,
     170,    62,    63,   173,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,    62,    63,   173,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,    62,    63,   173,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,   167,   168,   169,   170,
      62,    63,   173,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,    62,    63,
     173,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    62,    63,   173,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,   167,   168,   169,   170,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    62,    63,   173,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,    62,    63,   173,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    62,    63,   173,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,   167,   168,   169,   170,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,   173,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    62,    63,   173,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    62,    63,   173,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,   173,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    -1,    -1,   173,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    62,    63,   173,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,   167,   168,   169,
     170,    62,    63,   173,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,    62,    63,   173,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    -1,    -1,   173,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,    62,    63,   173,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,   167,   168,   169,   170,
      62,    63,   173,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    62,    63,   173,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,    62,    63,   173,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,   167,   168,   169,   170,    62,
      63,   173,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,    62,    63,   173,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,    62,    63,   173,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,   167,   168,   169,   170,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
      62,    63,   173,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,   170,    -1,
      -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,   173
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
     103,   104,   126,   127,   128,   133,   151,   155,   158,   178,
     179,   181,   188,   189,   191,   192,   196,   208,   209,   214,
     220,   227,   235,   243,   246,   250,   253,   259,    71,   172,
      71,   172,   228,   247,   251,     4,     7,   206,   206,   206,
       3,     4,     5,     7,     8,     9,    29,    30,    33,    62,
      63,    64,    65,    76,    79,    96,    97,   100,   102,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     172,   194,   195,   197,   203,   205,   208,   209,   182,   183,
     172,   194,   172,   172,   194,    27,     7,   236,   244,   197,
      57,    59,    60,   176,   282,   186,   194,   197,     4,     5,
     207,   197,   194,   197,   194,   197,     4,     5,   270,   271,
       9,   167,   168,   204,   205,   272,   206,    84,    92,   176,
     194,   197,   283,    84,    92,   105,   283,   283,    83,   197,
     202,    11,    52,   202,   202,    58,    84,    85,    86,    91,
      90,   197,   189,   196,   208,   209,   194,   194,   194,   105,
     172,   172,   172,   172,   172,   194,   283,   194,     0,    43,
     180,    87,    88,    99,    71,    71,    23,   197,   210,   211,
     194,   210,     4,   197,   179,   172,   172,    34,    35,   172,
     172,   197,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   197,
     194,   197,    66,    67,    68,    69,    70,    71,   168,    19,
      20,    62,    63,    66,    67,    68,    69,    70,    71,    72,
     167,   168,   169,   170,     4,     5,   221,   222,     4,     5,
     223,   224,   194,   210,   210,   194,   197,   238,   179,   254,
     260,   172,    57,   172,     4,     7,   172,   194,   197,   273,
      57,   176,   275,   280,   172,   172,   175,   175,   175,   172,
     172,   175,   205,   205,   175,   197,   194,   197,    10,   175,
     175,   194,   175,   202,   187,    11,   175,   190,   175,   202,
      11,   202,   190,   190,     5,   193,   193,   193,   173,   197,
     194,   175,   175,   175,    42,   202,   202,   202,   197,   194,
     215,   173,   194,   197,   212,   213,   173,    71,   248,    13,
      15,    17,    40,    43,    48,   252,   210,   210,   197,   197,
     197,    92,   194,   283,   283,     4,     5,   200,   201,   200,
     201,   202,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   283,   197,   197,   197,   197,   197,   197,
     197,   173,   197,   194,   194,   194,   194,   194,   197,   197,
     197,   173,   197,   197,   194,   197,   194,   197,   194,   194,
     173,   194,   173,   194,   173,   194,   173,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   283,   194,   210,
     210,   194,   194,   197,   173,   173,   194,   193,   194,   193,
     194,   173,   173,   194,   194,   194,   194,   194,   194,   194,
     184,   185,   199,   198,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   172,   172,   175,   172,   172,
     175,   173,   173,    42,   237,    13,    15,    17,    40,    43,
      48,   245,    45,   179,   197,   172,   194,   197,    50,   274,
     174,   175,   172,     4,     7,   172,     9,   281,   210,   210,
       4,     5,   197,   197,   210,   210,   271,     9,   204,   175,
      81,    82,    92,   194,   197,   197,   275,   202,   194,   202,
     190,   197,   197,   172,   175,   175,   175,   173,   173,   194,
     197,   194,   197,   194,   197,   181,   175,   190,   190,     4,
       5,   219,   175,   229,   179,   197,   173,   173,   175,   175,
     175,   173,   173,   175,   175,   173,   172,   172,   173,   173,
     175,   175,   190,   175,   173,   173,   173,   173,   173,   173,
     175,   173,   173,   175,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   175,   173,   173,   175,   175,   175,   173,
     175,   175,   173,   175,   173,   173,   173,   173,   173,   175,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     175,   175,   173,   173,   173,   173,   173,   173,   175,   173,
     173,   175,   173,   175,   173,   175,   173,   175,   175,   173,
     175,   175,   206,   284,   206,   285,   197,   197,   210,   210,
     222,   210,   210,   224,    42,   239,   255,    48,    49,   261,
     175,   197,   173,   175,   173,   172,   194,   194,   197,   197,
     276,   277,   197,     4,     5,   267,   269,   173,   173,   172,
     172,   175,   175,   173,   173,   197,    80,    80,   175,   175,
     175,   202,   175,   175,   210,   197,   197,   197,   175,   197,
     202,   202,   216,   213,   197,    15,    43,   249,   197,   197,
     197,   194,    92,   194,   173,   173,   197,   197,   202,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   194,   197,
     194,   194,   194,   197,   194,   197,   201,   194,   201,   194,
     194,   175,   175,   173,   173,   173,   173,    38,    39,   241,
     179,   197,   175,    57,   194,   194,   274,   175,   267,   267,
     173,   172,   172,   175,   210,   210,   197,   197,   175,   283,
     283,   194,   194,   194,   197,   197,   173,   173,   173,   173,
     175,   197,   190,   172,    11,   173,   173,   173,   173,   173,
     173,   175,   173,   173,   173,   190,   173,   173,   173,   173,
     173,   173,   175,   173,   173,   173,   175,   173,   173,   175,
     173,   175,   173,   175,   173,   173,   173,   175,   173,   173,
     175,   173,   173,   206,   206,   238,    42,    37,   256,   173,
     197,   172,   173,   175,   197,   278,   210,   210,   268,   173,
     173,   194,   175,   175,    71,    71,    71,   197,   175,   202,
       4,     5,   225,   226,   197,   194,   197,   197,   194,   197,
     197,   194,   194,   194,   240,   242,    47,   263,    59,    60,
     173,   197,    57,   194,   173,   267,   173,   173,   267,   194,
     194,   194,   194,   194,   173,   194,   172,   172,   173,   175,
      12,   233,   173,   175,   173,   173,   173,   173,   173,   173,
     173,   179,   179,   197,    46,   262,   172,   175,   172,   173,
     279,    71,   175,   173,   173,   217,   226,   197,   230,   197,
      45,   266,   179,   257,   194,   197,   197,   281,   194,   197,
     179,   179,   173,   264,    13,    15,    17,    40,    43,    48,
     258,   173,   175,   173,   175,   267,    24,    43,   218,   231,
     179,   194,   197,    13,    15,    17,    40,    43,    48,   232,
     265,   173,   173,     4,   234,   263
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   177,   178,   179,   180,   179,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   182,   181,   183,   181,   181,   181,
     181,   181,   181,   181,   184,   181,   185,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   186,   181,
     187,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   188,   188,   188,   188,   188,   189,   189,   189,   189,
     189,   189,   190,   190,   191,   191,   191,   191,   191,   192,
     192,   193,   193,   194,   194,   194,   194,   194,   194,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   198,
     197,   199,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   200,   201,   202,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   205,   205,   205,   206,   206,   207,   207,
     207,   207,   208,   209,   211,   210,   212,   212,   212,   213,
     213,   215,   216,   217,   214,   218,   218,   219,   219,   220,
     220,   220,   220,   221,   221,   222,   222,   222,   222,   223,
     223,   224,   224,   224,   224,   225,   225,   225,   226,   226,
     226,   226,   228,   229,   230,   231,   227,   232,   232,   232,
     232,   232,   232,   233,   233,   234,   234,   236,   235,   237,
     237,   238,   238,   239,   240,   239,   241,   242,   241,   244,
     243,   245,   245,   245,   245,   245,   245,   247,   248,   246,
     249,   249,   251,   250,   252,   252,   252,   252,   252,   252,
     254,   255,   256,   257,   253,   258,   258,   258,   258,   258,
     258,   260,   259,   261,   261,   262,   262,   263,   264,   265,
     263,   266,   266,   267,   268,   267,   269,   269,   269,   269,
     270,   270,   271,   271,   271,   271,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   274,   274,   274,   276,   275,
     277,   275,   278,   275,   279,   275,   280,   275,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   283,   283,   284,   284,   285,   285
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
       4,     4,     1,     1,     2,     1,     2,     2,     4,     4,
      10,     0,     1,     1,     2,     2,     3,    10,     8,     8,
       8,     3,     1,     1,     6,     4,     4,     6,     6,     4,
       6,     1,     4,     1,     1,     1,     1,     3,     3,     6,
       6,     8,     6,     4,     6,     8,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     1,     3,     1,     3,     4,     6,     6,     4,
       6,     4,     6,    10,     4,     4,     4,     3,     3,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       4,     6,     1,     4,     4,     6,     6,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       8,     4,     4,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       1,     2,     2,     1,     1,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     0,     2,     0,     1,     3,     1,
       1,     0,     0,     0,    11,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     3,     1,     1,     4,     4,     1,
       3,     1,     1,     4,     4,     0,     1,     3,     1,     1,
       3,     3,     0,     0,     0,     0,    14,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     1,     0,     7,     1,
       2,     1,     1,     0,     0,     5,     0,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     0,     6,
       1,     1,     0,     4,     1,     2,     1,     1,     1,     1,
       0,     0,     0,     0,    11,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     1,     0,     2,     0,     0,     0,
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

    {lyyerror(sERROR,"command extstruct needs at minimum two string arguments");}

    break;

  case 108:

    {lyyerror(sERROR,"command extstruct needs at minimum two string arguments");}

    break;

  case 109:

    {add_command(cPUSHFREE,NULL,NULL); add_command(cEXTSTRUCT_FREE,NULL,NULL);}

    break;

  case 110:

    {add_command(cPUSHFREE,NULL,NULL); add_command(cEXTSTRUCT_SET_NUMBER, NULL, NULL);}

    break;

  case 111:

    {drawmode=0;}

    break;

  case 112:

    {drawmode=dmCLEAR;}

    break;

  case 113:

    {drawmode=dmFILL;}

    break;

  case 114:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 115:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 116:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 117:

    {create_changestring(fMID);}

    break;

  case 118:

    {create_changestring(fMID2);}

    break;

  case 119:

    {create_changestring(fLEFT);}

    break;

  case 120:

    {create_changestring(fRIGHT);}

    break;

  case 121:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 124:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 125:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 126:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 127:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 128:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 129:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 130:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 131:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 132:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 133:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 135:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 136:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 137:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 139:

    {create_function(fLEFT);}

    break;

  case 140:

    {create_function(fRIGHT);}

    break;

  case 141:

    {create_function(fMID);}

    break;

  case 142:

    {create_function(fMID2);}

    break;

  case 143:

    {create_function(fSTR);}

    break;

  case 144:

    {create_function(fSTR2);}

    break;

  case 145:

    {create_function(fSTR3);}

    break;

  case 146:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 147:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 148:

    {create_function(fINKEY);}

    break;

  case 149:

    {create_function(fCHR);}

    break;

  case 150:

    {create_function(fUPPER);}

    break;

  case 151:

    {create_function(fLOWER);}

    break;

  case 152:

    {create_function(fLTRIM);}

    break;

  case 153:

    {create_function(fRTRIM);}

    break;

  case 154:

    {create_function(fTRIM);}

    break;

  case 155:

    {create_function(fCHOMP);}

    break;

  case 156:

    {create_function(fSYSTEM2);}

    break;

  case 157:

    {create_function(fEXTLIB2);}

    break;

  case 158:

    {lyyerror(sERROR,"function extstruct needs a string as its first argument");}

    break;

  case 159:

    {lyyerror(sERROR,"function extstruct needs more than a single string-argument");}

    break;

  case 160:

    {add_command(cPUSHFREE,NULL,NULL); create_function(fEXTSTRUCT_NEW);}

    break;

  case 161:

    {add_command(cPUSHFREE,NULL,NULL); create_function(fEXTSTRUCT_DUMP);}

    break;

  case 162:

    {create_function(fDATE);}

    break;

  case 163:

    {create_function(fDATE);}

    break;

  case 164:

    {create_function(fTIME);}

    break;

  case 165:

    {create_function(fTIME);}

    break;

  case 166:

    {create_function(fPEEK2);}

    break;

  case 167:

    {create_function(fPEEK3);}

    break;

  case 168:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 169:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 170:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 171:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 172:

    {create_function(fGETBIT);}

    break;

  case 173:

    {create_function(fGETCHAR);}

    break;

  case 174:

    {create_function(fHEX);}

    break;

  case 175:

    {create_function(fBIN);}

    break;

  case 176:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 177:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 178:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 179:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 180:

    {poplabel();create_boole('|');}

    break;

  case 181:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 182:

    {poplabel();create_boole('&');}

    break;

  case 183:

    {create_boole('!');}

    break;

  case 184:

    {create_dblrelop('=');}

    break;

  case 185:

    {create_dblrelop('!');}

    break;

  case 186:

    {create_dblrelop('<');}

    break;

  case 187:

    {create_dblrelop('{');}

    break;

  case 188:

    {create_dblrelop('>');}

    break;

  case 189:

    {create_dblrelop('}');}

    break;

  case 190:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 191:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 192:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 193:

    {add_command(cARDIM,"",NULL);}

    break;

  case 194:

    {add_command(cARDIM,"",NULL);}

    break;

  case 195:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 196:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 197:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 198:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 199:

    {create_dblbin('+');}

    break;

  case 200:

    {create_dblbin('-');}

    break;

  case 201:

    {create_dblbin('*');}

    break;

  case 202:

    {create_dblbin('/');}

    break;

  case 203:

    {create_dblbin('^');}

    break;

  case 204:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 205:

    {create_strrelop('=');}

    break;

  case 206:

    {create_strrelop('!');}

    break;

  case 207:

    {create_strrelop('<');}

    break;

  case 208:

    {create_strrelop('{');}

    break;

  case 209:

    {create_strrelop('>');}

    break;

  case 210:

    {create_strrelop('}');}

    break;

  case 213:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 214:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 216:

    {create_function(fSIN);}

    break;

  case 217:

    {create_function(fASIN);}

    break;

  case 218:

    {create_function(fCOS);}

    break;

  case 219:

    {create_function(fACOS);}

    break;

  case 220:

    {create_function(fTAN);}

    break;

  case 221:

    {create_function(fATAN);}

    break;

  case 222:

    {create_function(fATAN2);}

    break;

  case 223:

    {create_function(fEXP);}

    break;

  case 224:

    {create_function(fLOG);}

    break;

  case 225:

    {create_function(fLOG2);}

    break;

  case 226:

    {create_function(fSQRT);}

    break;

  case 227:

    {create_function(fSQR);}

    break;

  case 228:

    {create_function(fINT);}

    break;

  case 229:

    {create_function(fCEIL);}

    break;

  case 230:

    {create_function(fFLOOR);}

    break;

  case 231:

    {create_function(fFRAC);}

    break;

  case 232:

    {create_function(fABS);}

    break;

  case 233:

    {create_function(fSIG);}

    break;

  case 234:

    {create_function(fMOD);}

    break;

  case 235:

    {create_function(fRAN);}

    break;

  case 236:

    {create_function(fRAN2);}

    break;

  case 237:

    {create_function(fMIN);}

    break;

  case 238:

    {create_function(fMAX);}

    break;

  case 239:

    {create_function(fLEN);}

    break;

  case 240:

    {create_function(fVAL);}

    break;

  case 241:

    {create_function(fASC);}

    break;

  case 242:

    {create_function(fDEC);}

    break;

  case 243:

    {create_function(fDEC2);}

    break;

  case 244:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 245:

    {create_function(fINSTR2);}

    break;

  case 246:

    {create_function(fRINSTR);}

    break;

  case 247:

    {create_function(fRINSTR2);}

    break;

  case 248:

    {create_function(fSYSTEM);}

    break;

  case 249:

    {create_function(fEXTLIB);}

    break;

  case 250:

    {add_command(cPUSHFREE,NULL,NULL); create_function(fEXTSTRUCT_GET_NUMBER);}

    break;

  case 251:

    {create_function(fPEEK4);}

    break;

  case 252:

    {create_function(fPEEK);}

    break;

  case 253:

    {create_function(fMOUSEX);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 255:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 256:

    {create_function(fMOUSEY);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 258:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 259:

    {create_function(fMOUSEB);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 261:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 262:

    {create_function(fMOUSEMOD);}

    break;

  case 263:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 264:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 265:

    {create_function(fAND);}

    break;

  case 266:

    {create_function(fOR);}

    break;

  case 267:

    {create_function(fEOR);}

    break;

  case 268:

    {create_function(fTELL);}

    break;

  case 269:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 270:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 271:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 272:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 273:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 274:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 275:

    {create_myopen(0);}

    break;

  case 276:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 277:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 278:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 279:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 280:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 281:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 282:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 283:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 284:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 285:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 286:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 287:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 288:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 289:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 290:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 291:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 292:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 293:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 294:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 301:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 302:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 303:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 304:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 305:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 306:

    {missing_endsub--;}

    break;

  case 307:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 308:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 309:

    {exported=FALSE;}

    break;

  case 310:

    {exported=TRUE;}

    break;

  case 311:

    {exported=FALSE;}

    break;

  case 312:

    {exported=TRUE;}

    break;

  case 315:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 316:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 317:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 318:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 321:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 322:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 323:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 324:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 328:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 329:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 330:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 331:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 332:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 333:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 334:

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

  case 335:

    {
             swap();popgoto();poplabel();}

    break;

  case 336:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 337:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 338:

    {missing_next--;}

    break;

  case 339:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 340:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 341:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 342:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 343:

    {create_pushdbl(1);}

    break;

  case 345:

    {pop(stSTRING);}

    break;

  case 346:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 347:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 348:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 354:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 355:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 357:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 359:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 361:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 362:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 363:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 364:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 365:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 366:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 367:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 368:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 370:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 371:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 372:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 374:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 375:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 376:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 377:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 378:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 379:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 380:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 381:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 382:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 383:

    {poplabel();}

    break;

  case 385:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 386:

    {missing_endif--;}

    break;

  case 387:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 388:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 389:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 390:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 391:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 393:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 394:

    {poplabel();}

    break;

  case 398:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 399:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 404:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 406:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 407:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 408:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 409:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 412:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 413:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 414:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 415:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 416:

    {create_strdata((yyvsp[0].string));}

    break;

  case 417:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 418:

    {create_strdata((yyvsp[0].string));}

    break;

  case 419:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 423:

    {create_print('s');}

    break;

  case 424:

    {create_print('s');}

    break;

  case 425:

    {create_print('d');}

    break;

  case 426:

    {create_print('u');}

    break;

  case 427:

    {create_print('U');}

    break;

  case 428:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 429:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 430:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 431:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 432:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 433:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 434:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 435:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 436:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 437:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 438:

    {create_pushstr("?");create_print('s');}

    break;

  case 439:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 440:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 452:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 457:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 458:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 459:

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
