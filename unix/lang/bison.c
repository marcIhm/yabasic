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
    tFGNFN_CALL = 411,
    tFGNFN_CALL2 = 412,
    tFGNBF_NEW = 413,
    tFGNBF_FREE = 414,
    tFGNBF_DUMP = 415,
    tFGNBF_SET = 416,
    tFGNBF_GET = 417,
    tFGNBF_GET2 = 418,
    tDATE = 419,
    tTIME = 420,
    tTOKEN = 421,
    tTOKENALT = 422,
    tSPLIT = 423,
    tSPLITALT = 424,
    tGLOB = 425,
    UMINUS = 426
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
#define YYFINAL  262
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5512

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  181
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  457
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1079

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   180,     2,     2,     2,     2,
     176,   177,   173,   172,   179,   171,     2,   174,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   178,
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
     165,   166,   167,   168,   169,   170,   175
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   187,   188,   188,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   210,   211,   211,   212,   213,
     214,   215,   216,   217,   218,   218,   220,   220,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   232,
     233,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   250,   251,   252,   253,   254,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     304,   305,   306,   307,   308,   312,   313,   314,   315,   316,
     317,   320,   321,   324,   325,   326,   327,   328,   331,   332,
     335,   336,   339,   340,   341,   342,   343,   344,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   386,   387,   390,   390,   391,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   424,   427,   430,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   499,   500,
     501,   504,   505,   506,   509,   510,   513,   514,   515,   516,
     519,   522,   525,   525,   528,   529,   530,   533,   534,   537,
     538,   541,   537,   546,   547,   550,   551,   554,   555,   556,
     557,   560,   561,   564,   565,   566,   567,   570,   571,   574,
     575,   576,   577,   580,   581,   582,   585,   586,   587,   588,
     591,   592,   596,   610,   591,   615,   616,   617,   618,   619,
     620,   623,   624,   627,   628,   633,   633,   637,   638,   641,
     642,   646,   648,   647,   652,   653,   653,   657,   657,   663,
     664,   665,   666,   667,   668,   672,   673,   672,   679,   680,
     684,   684,   689,   690,   691,   692,   693,   694,   697,   698,
     698,   700,   697,   704,   705,   706,   707,   708,   709,   712,
     712,   717,   718,   721,   722,   725,   727,   729,   726,   733,
     734,   737,   738,   738,   741,   742,   744,   745,   749,   750,
     753,   754,   756,   757,   761,   762,   763,   764,   767,   768,
     769,   770,   771,   774,   775,   776,   779,   779,   780,   780,
     781,   781,   782,   782,   783,   783,   786,   787,   790,   791,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   803,   806,   807,   809,   810,   813,   814
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
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE",
  "tFGNFN_CALL", "tFGNFN_CALL2", "tFGNBF_NEW", "tFGNBF_FREE",
  "tFGNBF_DUMP", "tFGNBF_SET", "tFGNBF_GET", "tFGNBF_GET2", "tDATE",
  "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "'-'",
  "'+'", "'*'", "'/'", "UMINUS", "'('", "')'", "';'", "','", "'#'",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,    45,    43,    42,    47,   426,    40,    41,    59,    44,
      35
};
# endif

#define YYPACT_NINF -724

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-724)))

#define YYTABLE_NINF -379

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3907,   -48,   -38,  -724,  -724,  -724,  -724,  -724,   174,   174,
     174,  2929,  -724,  -724,  -724,  3545,  -152,  -146,  3545,    16,
      40,  -724,  -724,  -724,  3269,   -15,  -724,  3269,    71,  -724,
    3269,  3269,  3269,   186,    32,   174,  1724,  1134,  2064,   -24,
    3269,  2759,  3269,   290,    -3,  3269,  -724,    49,  3545,  3545,
    3545,     6,   -34,    -8,    17,    45,    65,  2064,  3545,  3545,
     182,   131,  -724,   -27,  -724,  -724,  -724,  -724,   157,   183,
    -724,   179,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  3269,
    -724,  3545,  -724,   267,  3269,  3763,  -724,  -724,  -724,  -724,
    -724,  -724,    98,   104,  -724,  -724,  -724,   135,   152,   310,
     165,   216,  3269,   234,   248,   262,   280,   293,   295,   307,
     309,   323,   331,   334,   342,   353,   365,   396,   398,   436,
     460,   464,   482,   484,   486,   496,   503,   525,   559,   570,
     577,   590,   601,   612,   617,   624,   625,   626,   628,   629,
     634,   635,   636,   637,   638,   642,   643,   644,   645,   646,
     647,   653,   654,   662,   663,   664,   675,   678,   681,   682,
     683,   684,   685,   686,   691,   694,   696,   701,   703,   704,
     705,   707,  3269,  3269,    26,  -724,   363,  -724,  -724,  -724,
    -724,   351,   391,  3545,   355,  -724,  -724,   355,  -724,  -724,
    3269,  3763,   198,   708,   537,   709,    24,  3269,   -43,    26,
    5338,   710,   711,   510,  5338,    26,   513,    26,  1315,   712,
     713,   547,  -724,  -724,   116,   116,  -724,  -724,   667,  -724,
    3269,  3545,  3269,    12,  5338,   689,  -724,  -724,  -724,  -724,
     717,  3545,  1326,  -724,  3269,  -724,     4,   718,  -724,  -724,
    3269,  3099,  -724,  -724,  5338,  -724,  -724,   157,   183,   355,
      -6,    -6,  -724,   885,   885,   885,  2234,  3545,    35,   719,
     -95,   -72,  -724,  -724,   633,  3269,  3269,  3269,  3269,  3545,
    -724,  5338,   714,  3269,   355,   715,   828,  5338,   430,  -724,
    -724,  -724,  -724,  3269,  3269,   702,  3269,  1894,  2064,   540,
     540,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    3269,  3269,  3269,  2064,  3269,  3269,  3269,  3269,  3269,  3269,
    3269,  2409,  3545,  3545,  3545,  3545,  3545,  3269,  3269,  3269,
    2584,  3269,  3545,  3269,  3545,  3269,  3545,  3545,   348,  1308,
    1421,  1474,  3545,  3545,  3545,  3545,  3545,  3545,  3545,  3545,
    2064,  3545,  -724,  -724,  3545,  3545,  3545,  3545,   724,   725,
    3545,   885,  3545,   885,  3545,   831,    86,   849,  3545,  3545,
    3545,  3545,  3545,  3545,  3545,  -724,  -724,  -724,  -724,  3269,
    3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
     728,   729,   731,  -724,   730,   732,   734,  -724,   -87,   745,
     746,    26,  5338,   882,   574,   880,  3763,  3269,   750,  3545,
    -724,  -724,  3269,    26,   480,   440,   751,    25,  -724,   919,
    -724,  -724,   592,  3269,  3269,  -724,  -724,   186,  -724,  -724,
      55,  1353,   355,  5338,   566,  3419,  3269,   355,  3269,  -724,
     -43,  -724,  -724,  3269,  3545,  -724,  3269,     4,  3269,  3269,
     753,   752,   754,   755,  -724,  4233,   -36,  3269,  3269,  3545,
    3545,  3763,   762,     4,     4,  5338,   355,   677,  -724,    26,
    5338,   764,  -724,  -724,  -724,  3763,  -724,  -724,  3269,  -724,
    -724,  -724,  -724,   768,   770,  1586,  1602,  1633,   771,   487,
     772,   775,   756,   777,   778,   779,   780,   781,     4,  1909,
    4244,  4255,  4297,  4322,  4368,   538,  4379,   670,  4390,  4410,
     784,  4435,  4446,  4457,  4503,  4523,  4570,  2079,  -724,  4581,
     -14,   -52,   -12,    80,   -13,  2249,  2424,   692,  -724,  4592,
    4616,    52,  4636,     8,  4647,   155,   236,  -724,   401,  -724,
     416,  -724,   418,  -724,   457,   458,   465,   467,   154,   170,
     497,   499,   501,   557,   785,    61,   797,   798,   171,   201,
     221,   239,  -724,  -724,   240,  -112,   274,    31,   325,  -724,
    -724,   355,   355,   355,   355,   355,   355,  -724,   174,   174,
    3269,  3269,   392,   249,   318,   233,    -2,   151,  -724,   -23,
     -23,   831,   831,  -724,  -724,   351,  -724,  -724,   391,  -724,
    -724,  -724,   912,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   727,  2602,  3269,    67,  4658,  3596,  -724,  -724,  3269,
    3269,  -724,  -724,  3269,  -724,   776,   803,   804,   782,   806,
    2774,  2944,   807,   808,  -724,  -724,  -724,  3269,   903,   906,
    -724,   359,  3114,  5338,  -724,  -724,   360,  -724,  3269,  3284,
    3420,  -724,  3269,  3269,  3269,  -724,  -724,    26,  5338,    26,
    5338,   355,   361,  -724,  3269,  3269,  3269,  -724,  -724,  -724,
    3269,  3269,    23,  5338,  -724,  -724,  3269,  3269,  3269,  -724,
    -724,  3545,  3470,  -724,   810,   812,  -724,  -724,  3269,  3269,
    3269,  3269,  -724,  -724,  -724,  -724,  -724,  -724,  3269,  -724,
    -724,  3269,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  3269,  -724,  -724,  3269,  3269,  3269,  -724,  3269,  3269,
    -724,  3545,  -724,  -724,  -724,  -724,  -724,  3269,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  3545,  3545,
    -724,  -724,  -724,  -724,  -724,  -724,  3545,  -724,  -724,  3269,
    3545,  3269,  3269,   986,  -724,  3545,   986,  -724,  3545,  3545,
    -724,   813,  -724,   815,   702,   901,   818,   819,  -724,   820,
     822,  -724,  -724,   748,  3763,  -724,  -724,  -724,  3269,  3469,
     943,  3545,  -724,  3545,   355,    26,   480,  3815,   776,   776,
    4705,   825,   826,  -724,   824,  -724,  -724,  -724,  -724,  3269,
    3269,  -724,  -724,  3959,  2064,  2064,  3545,  3545,  3545,  -724,
    3269,  3269,   827,  4729,  4771,   765,  3269,  5338,     4,  -724,
     829,  -724,    46,  -724,  -724,  -724,  4782,  4793,  4818,   527,
     830,   237,  -724,  -724,  4842,  4853,   833,    63,  4864,  4906,
    4931,  4977,  4988,   996,  4999,  5019,   272,  5044,   300,   324,
     528,  5055,   530,  4047,  4094,    76,   531,   200,   541,   542,
     174,   174,  -724,  -724,  -724,  -724,  3269,   964,   974,   970,
    5066,  3269,   838,   544,   337,  -724,  3269,  -724,  -724,  -724,
    -724,  -724,  -724,   839,   841,  5338,  5338,  3545,  -724,  -724,
     355,   355,   389,  4119,  5338,  -724,   944,   954,   956,  3269,
    4161,  3269,   787,  3269,  -724,  -724,  -724,  -724,  -724,  -724,
    3545,  -724,  -724,  -724,  3269,  -724,  -724,  -724,  -724,  -724,
    -724,  3269,  -724,  -724,  -724,  3545,  -724,  -724,  3269,  -724,
    3269,  -724,  -724,  -724,  3545,  3269,  -724,  3545,  -724,  -724,
    3545,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   982,   737,
    5112,  3269,   975,  3545,  5132,   776,   857,   858,   776,  -724,
    -724,   355,  3545,  3545,  3545,  3545,  3545,  5179,  3545,  -724,
     861,   862,   288,  -724,    77,   548,  4172,  5190,   550,  5201,
    5225,   571,  5245,   572,   573,  3763,  4051,  3269,   993,  -724,
     865,  -724,  4183,   866,   575,  -724,  -724,  -724,  -724,  -724,
     355,   355,   355,   355,   355,   972,   390,   867,   868,  -724,
     787,  3269,  -724,  -724,  3269,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   970,  1011,   268,  3763,  -724,  3545,  3269,
    3269,  -724,   919,  3545,  3269,  -724,  -724,  3763,  -724,  5338,
    3763,  5256,  -724,  -724,   970,   598,   349,  5267,  4208,   776,
     355,    26,  5338,    -7,   970,  -724,  3763,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  3545,  -724,  3269,  -724,  -724,
    -724,  -724,   648,   970,   579,  5314,  -724,  -724,  -724,  -724,
    -724,  -724,  1046,   982,  -724,  -724,  -724,  -724,  -724
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     110,     0,     0,   105,   330,   365,   370,    11,     0,     0,
       0,     0,    24,    26,   308,     0,     0,     0,     0,   309,
      18,    20,   345,   357,     0,   438,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     4,     3,     0,     7,    39,    41,     9,    22,    23,
      21,     0,    13,    14,    17,    16,    15,    28,    29,     0,
     292,     0,   292,     0,     0,     6,   285,   284,    30,    31,
      38,   281,   196,   132,   282,   283,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,   252,   255,   258,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   161,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,   209,   190,   195,
     134,     0,     0,     0,    12,   292,   292,    42,   310,    19,
       0,     6,   389,     0,   442,     0,     0,   418,   434,    62,
      61,     0,     0,    63,   104,    53,     0,    55,     0,   410,
     412,    56,   408,   414,     0,     0,   415,   278,    57,    59,
       0,    89,     0,     0,   453,     0,    86,    91,    79,    40,
       0,     0,     0,    67,     0,    50,    72,     0,    88,    87,
       0,     0,   113,   114,    92,     8,    10,     0,     0,   106,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,     0,     0,     0,
     299,   175,     0,   294,   115,     0,     0,   366,     4,   292,
     292,    32,    33,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    36,   179,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,   314,    25,   311,   319,   320,    27,   317,     0,     0,
       0,   350,   349,     0,     4,     0,     6,     0,     0,     0,
     439,   440,     0,   421,   423,    45,     0,     0,    49,   436,
     292,   292,     0,     0,     0,   292,   292,     0,   280,   279,
       0,     0,    90,   452,     0,     0,     0,    66,     0,    71,
     434,   122,   121,     0,     0,    68,     0,    74,     0,     0,
     130,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,   176,   120,     0,   290,   297,
     298,   293,   295,   291,   331,     6,   377,   375,     0,   376,
     372,   374,   371,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,   256,
       0,   259,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   162,     0,     0,     0,     0,     0,   137,
     210,   204,   206,   208,   205,   207,   203,   136,     0,     0,
       0,     0,   183,   185,   187,   184,   186,   182,   201,   198,
     197,   199,   200,   292,   292,     0,   292,   292,     0,    43,
      44,   347,   351,   364,   362,   363,   360,   359,   361,   358,
     379,     4,     0,     0,     0,     0,     0,   419,    46,    47,
       0,   426,   428,     0,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   416,   417,     0,     0,     0,
     125,   124,   128,   213,    51,    69,    82,    73,     0,     0,
       0,   292,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   107,     0,     5,     0,     0,     0,   305,   306,   300,
       0,     0,     4,   373,   271,   173,     0,     0,     0,   272,
     273,     0,     0,   266,     0,     0,   191,   192,     0,     0,
       0,     0,   214,   215,   216,   217,   218,   219,     0,   221,
     222,     0,   224,   225,   188,   230,   231,   226,   227,   228,
     229,     0,   233,   238,     0,     0,     0,   237,     0,     0,
     142,     0,   147,   148,   239,   171,   240,     0,   172,   149,
     150,   251,   254,   257,   260,   153,   151,   152,     0,     0,
     154,   246,   155,   250,   249,   163,     0,   247,   156,     0,
       0,     0,     0,     0,   166,     0,     0,   168,     0,     0,
     454,    35,   456,    37,   180,   178,     0,     0,   312,     0,
       0,   318,   348,   354,     6,   391,   392,   390,     0,     0,
     443,     0,   441,     0,   424,   422,   423,     0,     0,     0,
       0,   404,   406,   435,   401,   286,   288,   292,   292,     0,
       0,   411,   413,    64,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,    80,     0,    85,
       0,   296,     0,   369,   368,   367,     0,     0,     0,     0,
       0,     0,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   316,   321,   322,     0,     0,     0,   380,
       0,     0,     0,     0,     0,   420,     0,   427,   429,   430,
     292,   292,   402,     0,     0,    52,    54,     0,   126,   127,
     123,   129,    83,    76,    77,   131,     0,     0,     0,     0,
       0,     0,   323,     0,   263,   264,   265,   274,   275,   276,
       0,   193,   194,   169,     0,   220,   223,   232,   138,   139,
     141,     0,   235,   236,   143,     0,   241,   242,     0,   244,
       0,   164,   157,   158,     0,     0,   268,     0,   165,   270,
       0,   167,   189,   455,   457,   352,   355,   346,   395,   445,
       0,     0,   444,     0,     0,     0,     0,     0,     0,   287,
     289,    65,     0,     0,     0,     0,     0,     0,     0,    81,
     326,   327,     0,   324,   341,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,   110,     0,   393,   449,
       0,   446,     0,     0,     0,   432,   431,   405,   407,   403,
      84,    75,   118,   119,   117,     0,     0,     0,     0,   301,
       0,     0,   332,   277,     0,   140,   144,   243,   245,   248,
     174,   267,   269,   353,     4,   399,     6,   381,     0,     0,
       0,   425,   436,     0,     0,   328,   329,     6,   325,   342,
       6,     0,   400,   396,   394,     0,     0,     0,     0,     0,
     116,   109,   108,     4,   333,   170,     6,   388,   385,   386,
     387,   383,   384,   382,   450,     0,   447,     0,   433,   304,
     303,   302,     0,   397,     0,     0,   336,   338,   339,   340,
     335,   337,   343,   395,   451,   448,   344,   334,   398
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -724,  -724,   -81,  -724,   600,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  1005,  -241,  -724,  -724,  -156,   767,  -724,  1006,
     -11,  -724,  -724,   766,  -288,   -35,  -724,   640,   -26,     2,
    -724,     1,     3,   -64,  -724,  -724,   395,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   472,  -724,   473,  -724,    69,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   214,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,     5,  -724,  -724,  -724,
    -723,  -724,  -724,  -724,   659,  -724,  -724,   301,   641,  -724,
    -724,  -724,  -724,  -724,    62,  -724,    14,  -724,  -724
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    60,    61,   264,    62,   181,   182,   568,   569,   198,
     430,    63,    64,   433,    65,    66,   441,   174,   175,    67,
     232,   571,   570,   484,   485,   233,   177,   216,   178,    88,
     203,   179,   180,   272,   273,   461,   462,    70,   457,   810,
    1027,  1061,   659,    71,   382,   383,   386,   387,   962,   963,
      72,    83,   661,  1030,  1062,  1072,  1002,  1077,    73,   190,
     592,   393,   763,   975,   858,   976,    74,   191,   599,    75,
      84,   465,   815,    76,    85,   472,    77,   395,   764,   938,
    1035,  1053,    78,   396,   767,  1017,   978,  1046,  1073,  1033,
     783,   948,   784,   211,   212,   218,   405,   607,   408,   778,
     779,   945,  1022,   409,   615,   197,   225,   751,   753
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     176,    68,   487,    69,   278,   431,   236,   237,   217,   438,
     439,    89,    90,   192,   406,   431,   200,  1059,   275,   204,
     206,   208,   424,    79,   185,   224,   224,   224,   400,   611,
     186,   401,   612,    81,   244,    91,  1060,   219,   813,    94,
      95,   213,   193,   188,   194,   195,   224,   189,   247,   375,
     248,   229,   230,     1,     2,   867,   868,   893,    91,   231,
     265,   266,    94,    95,   625,   744,   814,   745,   271,   374,
     375,   259,   267,   277,   431,   201,   202,   364,   358,   359,
     360,   361,   362,   363,   449,   364,    68,   243,    69,  1001,
     559,   285,   358,   359,   360,   361,   362,   363,   442,   443,
     364,   358,   359,   360,   361,   362,   363,   450,   367,   368,
     394,   252,   369,   370,   371,   372,   373,   374,   375,    91,
     364,   389,   390,    94,    95,   367,   368,   704,    80,   369,
     370,   371,   372,   373,   374,   375,   364,   407,    82,   367,
     368,   646,   253,   369,   370,   371,   372,   373,   374,   375,
     378,   379,   358,   359,   360,   361,   362,   363,   364,   364,
     364,   355,   357,   703,   707,   196,   364,   705,   254,   376,
     377,   378,   379,   432,   263,    52,    53,    54,    86,   392,
     364,    87,   262,   432,   364,   716,   404,   717,   418,   419,
     209,   210,    68,   255,    69,   555,   638,   557,   364,   429,
     402,   613,   270,   214,   215,   435,   437,   364,   747,   421,
     748,   423,   655,   656,   447,   473,   474,   376,   377,   378,
     379,   256,   986,   375,   364,   989,   214,   215,   268,   714,
     452,   453,   454,   364,   376,   377,   378,   379,   735,   364,
     736,   257,   432,  -378,   770,   445,   771,   680,   376,   377,
     378,   379,   364,   926,   269,   927,   488,   455,   364,   706,
     367,   368,   460,   559,   369,   370,   371,   372,   373,   374,
     375,   276,   475,   476,    80,   477,   224,   224,   546,   547,
      82,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   224,   501,   502,   503,   504,   505,   506,   507,
     509,   480,   481,   373,   374,   375,   515,   516,   517,   519,
     520,   279,   522,  1032,   524,   601,  1058,   500,   372,   373,
     374,   375,   376,   377,   378,   379,   364,   364,   280,   224,
     367,   368,   719,   728,   369,   370,   371,   372,   373,   374,
     375,   283,   364,   364,   281,   282,   616,   617,   238,   729,
     739,   622,   623,    93,   544,   380,   381,    96,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   376,
     377,   378,   379,   364,   239,   240,   241,   929,    98,   930,
     740,   242,   365,   366,   662,   370,   602,   372,   373,   374,
     375,   605,   284,   364,   217,   384,   385,    68,   635,    69,
     741,   637,   620,   621,   376,   377,   378,   379,   364,   364,
     286,   364,   364,   720,   899,   632,   900,   633,   742,   743,
     376,   377,   378,   379,   287,   367,   368,   639,   640,   369,
     370,   371,   372,   373,   374,   375,   648,   650,   288,   376,
     377,   378,   379,   466,   364,   467,   364,   468,   108,   914,
     109,   915,    68,   746,    69,   845,   289,   663,   847,   370,
     371,   372,   373,   374,   375,   999,    68,  1000,    69,   290,
     469,   291,   364,   470,   130,   131,   132,   917,   471,   918,
     136,   137,   138,   292,   140,   293,   142,   143,   144,   376,
     377,   378,   379,   149,   150,   151,   364,   364,   154,   294,
     156,   919,   158,   920,   749,   160,   161,   295,   162,   364,
     296,   164,   165,   166,   559,   168,   943,   170,   297,   756,
     757,   364,   759,   760,   183,   527,  1054,   364,  1055,   298,
     606,   364,   364,   364,   376,   377,   378,   379,   796,   798,
     806,   299,   367,   368,   482,   483,   369,   370,   371,   372,
     373,   374,   375,   358,   359,   360,   361,   362,   363,   754,
     755,   364,   364,   376,   377,   378,   379,   891,   952,  1024,
     750,   752,   300,   364,   301,   367,   368,   802,   721,   369,
     370,   371,   372,   373,   374,   375,   904,   593,   364,   594,
     364,   595,   769,   722,   398,   723,   618,   619,   776,   777,
     367,   368,   780,   799,   369,   370,   371,   372,   373,   374,
     375,  1047,   302,  1048,   596,  1049,   793,   597,   608,   609,
     808,   809,   598,   358,   359,   360,   361,   362,   363,   364,
     364,   803,   804,   805,   724,   725,   303,   364,  1050,   364,
     304,  1051,   726,   807,   727,   826,  1052,   628,   629,   460,
     812,   376,   377,   378,   379,   816,   817,   818,   305,   364,
     306,  1066,   307,  1067,   670,  1068,   671,   824,   825,   364,
     827,   364,   308,   364,   730,   451,   731,   828,   732,   309,
     829,   657,   658,   859,   376,   377,   378,   379,  1069,   412,
     830,  1070,   413,   831,   832,   833,  1071,   834,   835,   364,
     364,   310,   364,   364,   897,   921,   837,   923,   928,   376,
     377,   378,   379,   364,   364,   687,   364,   688,   931,   932,
     364,   942,   364,   873,   874,  1003,   417,  1006,   841,   364,
     843,   844,   367,   368,   733,   311,   369,   370,   371,   372,
     373,   374,   375,   364,   364,   364,   312,   364,  1009,  1011,
    1012,   364,  1021,   313,   367,   368,  1074,   860,   369,   370,
     371,   372,   373,   374,   375,    68,   314,    69,   369,   370,
     371,   372,   373,   374,   375,   765,   766,   315,   875,   876,
     781,   782,   184,   224,   224,   187,   856,   857,   316,   883,
     884,   960,   961,   317,   199,   890,   979,   980,   205,   207,
     318,   319,   320,   223,   321,   322,   946,   947,   878,   879,
     323,   324,   325,   326,   327,   249,   250,   251,   328,   329,
     330,   331,   332,   333,   258,   260,   261,   367,   368,   334,
     335,   369,   370,   371,   372,   373,   374,   375,   336,   337,
     338,   376,   377,   378,   379,   392,   420,   690,   274,   691,
     940,   339,   933,   934,   340,   944,   959,   341,   342,   343,
     344,   345,   346,   376,   377,   378,   379,   347,   425,   710,
     348,   711,   349,   376,   377,   378,   379,   350,   957,   351,
     352,   353,   964,   354,   397,   399,   410,   411,   415,   416,
     440,   458,   463,   966,  1013,  1014,   426,   434,   448,   464,
     967,   552,   553,   375,   583,   584,   586,   969,   587,   970,
     585,   367,   368,   588,   972,   369,   370,   371,   372,   373,
     374,   375,   589,   590,   591,   600,   603,   610,   614,   641,
     982,   642,   674,   643,   644,  1034,   376,   377,   378,   379,
     356,   654,   888,   660,   889,   664,  1043,   665,   669,  1044,
     388,   672,   673,   675,   762,   676,   677,   391,   787,   678,
     679,   694,   734,   367,   403,  1063,  1015,   369,   370,   371,
     372,   373,   374,   375,   737,   738,    68,    68,    69,    69,
     785,   786,   788,   794,   791,   792,   795,   822,   422,   823,
    1029,   483,   850,  1031,   851,   852,   853,   854,   427,   855,
     862,   870,   871,   872,   885,   892,   936,   898,  1037,  1038,
     903,   937,    -4,  1042,   941,   954,   949,    68,   950,    69,
     376,   377,   378,   379,   446,   955,   560,   956,    68,   977,
      69,    68,   983,    69,   987,   988,   456,   997,   998,  1016,
     459,  1018,  1020,  1023,  1025,  1026,  1065,    68,  -356,    69,
    1076,   653,   245,   246,   479,   811,   486,   758,   367,   368,
     626,   761,   369,   370,   371,   372,   373,   374,   375,  1028,
     935,   634,   376,   377,   378,   379,   624,   865,  1078,   510,
     511,   512,   513,   514,  1039,     0,     0,     0,     0,   521,
       0,   523,     0,   525,   526,   528,   530,   532,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   545,     0,
       0,   548,   549,   550,   551,     0,     0,   554,     0,   556,
       0,   558,     0,     0,     0,   561,   562,   563,   564,   565,
     566,   567,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,   604,   376,   377,   378,
     379,     0,     0,   910,     0,   911,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,     0,     0,     0,   100,   101,   102,   103,
       0,   636,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   647,   649,   651,   652,   226,     0,
       0,     0,     0,     0,     0,     0,   227,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,   228,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,     0,     0,    93,   222,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   774,     0,     0,   775,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
     109,     0,     0,     0,     0,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,    93,   459,     0,     0,
      96,     0,     0,     0,   130,   131,   132,     0,   819,   821,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
       0,    98,     0,   149,   150,   151,     0,     0,   154,     0,
     156,     0,   158,     0,     0,   160,   161,     0,   162,     0,
       0,   164,   165,   166,     0,   168,     0,   170,   836,    93,
       0,     0,     0,    96,   183,   529,   376,   377,   378,   379,
       0,     0,     0,     0,   414,   838,   839,   376,   377,   378,
     379,     0,     0,   840,    98,   428,     0,   842,     0,     0,
       0,     0,   846,     0,     0,   848,   849,     0,     0,     0,
       0,   108,     0,   109,   376,   377,   378,   379,     0,     0,
       0,     0,   627,     0,     0,     0,     0,     0,   863,     0,
     864,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,   880,   881,   882,   149,   150,   151,     0,
       0,   154,     0,   156,   108,   158,   109,     0,   160,   161,
       0,   162,     0,     0,   164,   165,   166,     0,   168,     0,
     170,     0,     0,     0,     0,     0,     0,   183,   531,     0,
     130,   131,   132,     0,     0,     0,   136,   137,   138,     0,
     140,     0,   142,   143,   144,     0,     0,     0,     0,   149,
     150,   151,     0,   391,   154,     0,   156,     0,   158,     0,
       0,   160,   161,     0,   162,     0,     0,   164,   165,   166,
       0,   168,     0,   170,   951,     0,     0,     0,   367,   368,
     183,   533,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,   367,   368,     0,   965,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,   968,     0,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,   973,   367,   368,   974,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,     0,     0,     0,   990,
     991,   992,   993,   994,     0,   996,     0,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,   376,   377,   378,
     379,     0,     0,     0,     0,   666,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,     0,
       0,   667,     0,     0,     0,  1036,   100,   101,   102,   103,
    1040,  1041,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   376,   377,   378,   379,   220,     0,
       0,     0,   668,     0,     0,     0,   221,     0,     0,     0,
     106,   107,  1064,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,    91,    92,    93,
     173,    94,    95,    96,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   367,   368,   105,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,   478,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,    91,    92,    93,
     173,    94,    95,    96,   222,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   681,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   367,   368,   105,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,    91,    92,    93,
     173,    94,    95,    96,   222,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   701,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   367,   368,   105,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   444,    91,    92,    93,     0,    94,    95,    96,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   367,   368,   105,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,     0,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   173,   508,    91,    92,    93,
       0,    94,    95,    96,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   709,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   518,    91,    92,    93,     0,    94,    95,    96,     0,
     234,     0,     0,   376,   377,   378,   379,     0,     0,     0,
       0,   768,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   367,   368,   105,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,     0,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,    91,    92,    93,   173,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   789,     0,     0,     0,     0,    97,    98,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   367,   368,   105,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,     0,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,    91,    92,    93,   173,    94,    95,    96,     0,
     436,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   790,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   367,   368,   105,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,     0,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,    91,    92,    93,   173,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   797,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   367,   368,   105,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    93,   159,   160,   161,    96,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   173,     0,     0,     0,    98,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    96,
       0,     0,   367,   368,     0,     0,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,   108,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,   130,   131,   132,     0,     0,
      93,   136,   137,   138,    96,   140,     0,   142,   143,   144,
       0,     0,   820,     0,   149,   150,   151,     0,     0,   154,
     108,   156,   109,   158,     0,    98,   160,   161,     0,   162,
       0,     0,   164,   165,   166,     0,   168,     0,   170,     0,
       0,   376,   377,   378,   379,   183,   130,   131,   132,   801,
       0,    93,   136,   137,   138,    96,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,     0,     0,
     154,     0,   156,     0,   158,     0,    98,   160,   161,     0,
     162,     0,     0,   164,   165,   166,     0,   168,     0,   170,
     376,   377,   378,   379,     0,   108,   183,   109,   861,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,     0,     0,     0,   136,   137,   138,
       0,   140,     0,   142,   143,   144,     0,     0,     0,     0,
     149,   150,   151,     0,     0,   154,   108,   156,   109,   158,
       0,     0,   160,   161,     0,   162,     0,     0,   164,   165,
     166,     0,   168,     0,   170,     0,     0,     0,     0,     0,
       0,   183,   130,   131,   132,     0,     0,     0,   136,   137,
     138,     0,   140,     0,   142,   143,   144,     0,     0,     0,
       0,   149,   150,   151,     0,     0,   154,     0,   156,     0,
     158,     0,     0,   160,   161,     0,   162,     0,     0,   164,
     165,   166,     0,   168,     0,   170,     0,     1,     2,     3,
       0,     0,   773,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     8,     9,    10,    11,  -307,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
       0,     0,     0,     0,    23,     0,     0,    24,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,     0,     0,     0,     0,     0,    39,    40,    41,
    -110,  -110,    42,    43,    44,     0,    45,    46,    47,     0,
       0,    48,  -110,     0,    49,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,    56,     0,     0,     4,    57,     0,
       0,     5,    58,     6,    59,     7,     8,     9,    10,    11,
    -307,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,     0,     0,     0,     0,    23,    -6,
      -6,    24,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,   376,   377,   378,   379,
       0,    39,    40,    41,   866,     0,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,     0,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,    56,     0,
       0,     4,    57,     0,     0,     5,    58,     6,    59,     7,
       8,     9,    10,    11,  -307,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    -6,     0,
       0,     0,    23,    -6,     0,    24,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,   367,
     368,    31,    32,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
     376,   377,   378,   379,     0,    39,    40,    41,   877,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,   367,   368,     0,    55,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,    57,     0,     0,     0,
      58,     0,    59,     0,     0,     0,     0,     0,   376,   377,
     378,   379,     0,   367,   368,     0,   924,   369,   370,   371,
     372,   373,   374,   375,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
     367,   368,     0,   925,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,   367,   368,     0,   953,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,     0,     0,
     958,     0,     0,   376,   377,   378,   379,     0,     0,     0,
       0,  1004,     0,     0,   376,   377,   378,   379,     0,   367,
     368,     0,  1019,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,     0,   367,   368,     0,  1057,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,   377,   378,   379,     0,     0,
     645,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   682,     0,     0,     0,     0,   376,   377,   378,   379,
     367,   368,   683,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,   367,   368,     0,     0,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,   376,   377,
     378,   379,   367,   368,   684,     0,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   685,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,     0,     0,   686,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,   689,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   692,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   693,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,   695,     0,     0,     0,     0,   376,   377,   378,
     379,     0,     0,   696,     0,     0,     0,     0,   376,   377,
     378,   379,   367,   368,   697,     0,   369,   370,   371,   372,
     373,   374,   375,   367,   368,     0,     0,   369,   370,   371,
     372,   373,   374,   375,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,   377,   378,   379,   367,   368,
     698,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,   376,   377,   378,   379,   367,   368,
     699,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,   700,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,   702,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   712,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   713,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,   376,   377,   378,
     379,     0,     0,   715,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,   718,     0,     0,     0,     0,   376,
     377,   378,   379,   367,   368,   772,     0,   369,   370,   371,
     372,   373,   374,   375,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
     367,   368,   869,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,   367,   368,   886,     0,   369,   370,
     371,   372,   373,   374,   375,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,   887,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,   894,
       0,     0,     0,     0,   376,   377,   378,   379,   367,   368,
     895,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,   367,   368,   896,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,   901,
       0,     0,     0,     0,   376,   377,   378,   379,     0,     0,
     902,     0,     0,     0,     0,   376,   377,   378,   379,   367,
     368,   905,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   906,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   376,   377,   378,   379,   367,   368,   907,     0,
     369,   370,   371,   372,   373,   374,   375,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,   908,     0,     0,     0,     0,   376,
     377,   378,   379,     0,     0,   909,     0,     0,     0,     0,
     376,   377,   378,   379,   367,   368,   912,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
     376,   377,   378,   379,   367,   368,   913,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   916,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,   922,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   939,     0,   369,   370,   371,   372,   373,
     374,   375,   367,   368,     0,     0,   369,   370,   371,   372,
     373,   374,   375,   367,   368,     0,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   981,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   985,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,   995,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,  1005,     0,     0,
       0,     0,   376,   377,   378,   379,   367,   368,  1007,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
     367,   368,  1008,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,  1010,     0,     0,     0,     0,   376,   377,   378,
     379,     0,     0,  1045,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,  1056,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,  1075,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379
};

static const yytype_int16 yycheck[] =
{
      11,     0,   290,     0,    85,    11,    41,    42,    34,   250,
     251,     9,    10,    24,    57,    11,    27,    24,    82,    30,
      31,    32,    10,    71,   176,    36,    37,    38,     4,     4,
     176,     7,     7,    71,    45,     3,    43,    35,    15,     7,
       8,     9,    57,    27,    59,    60,    57,     7,    47,    72,
      47,    37,    38,     4,     5,   778,   779,    11,     3,    83,
      87,    88,     7,     8,     9,   177,    43,   179,    79,    71,
      72,    57,    99,    84,    11,     4,     5,   172,    66,    67,
      68,    69,    70,    71,   179,   172,    85,    90,    85,    12,
     177,   102,    66,    67,    68,    69,    70,    71,   254,   255,
     172,    66,    67,    68,    69,    70,    71,   179,    62,    63,
     191,   105,    66,    67,    68,    69,    70,    71,    72,     3,
     172,   185,   186,     7,     8,    62,    63,   179,   176,    66,
      67,    68,    69,    70,    71,    72,   172,   180,   176,    62,
      63,   177,   176,    66,    67,    68,    69,    70,    71,    72,
     173,   174,    66,    67,    68,    69,    70,    71,   172,   172,
     172,   172,   173,   177,   177,   180,   172,   179,   176,   171,
     172,   173,   174,   179,    43,   126,   127,   128,     4,   190,
     172,     7,     0,   179,   172,   177,   197,   179,   214,   215,
       4,     5,   191,   176,   191,   351,   437,   353,   172,   234,
     176,   176,    23,   171,   172,   240,   241,   172,   177,   220,
     179,   222,   453,   454,   179,   279,   280,   171,   172,   173,
     174,   176,   945,    72,   172,   948,   171,   172,    71,   177,
     265,   266,   267,   172,   171,   172,   173,   174,   177,   172,
     179,   176,   179,    45,   177,   256,   179,   488,   171,   172,
     173,   174,   172,   177,    71,   179,   291,   268,   172,   179,
      62,    63,   273,   177,    66,    67,    68,    69,    70,    71,
      72,     4,   283,   284,   176,   286,   287,   288,   342,   343,
     176,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   287,   288,    70,    71,    72,   317,   318,   319,   320,
     321,   176,   323,    45,   325,   396,  1039,   303,    69,    70,
      71,    72,   171,   172,   173,   174,   172,   172,   176,   340,
      62,    63,   177,   179,    66,    67,    68,    69,    70,    71,
      72,   176,   172,   172,    34,    35,   410,   411,    58,   179,
     179,   415,   416,     5,   340,     4,     5,     9,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   171,
     172,   173,   174,   172,    84,    85,    86,   177,    30,   179,
     179,    91,    19,    20,   465,    67,   397,    69,    70,    71,
      72,   402,   176,   172,   420,     4,     5,   396,   433,   396,
     179,   436,   413,   414,   171,   172,   173,   174,   172,   172,
     176,   172,   172,   177,   177,   426,   179,   428,   179,   179,
     171,   172,   173,   174,   176,    62,    63,   438,   439,    66,
      67,    68,    69,    70,    71,    72,   447,   448,   176,   171,
     172,   173,   174,    13,   172,    15,   172,    17,   100,   177,
     102,   179,   451,   179,   451,   743,   176,   468,   746,    67,
      68,    69,    70,    71,    72,   177,   465,   179,   465,   176,
      40,   176,   172,    43,   126,   127,   128,   177,    48,   179,
     132,   133,   134,   176,   136,   176,   138,   139,   140,   171,
     172,   173,   174,   145,   146,   147,   172,   172,   150,   176,
     152,   177,   154,   179,   179,   157,   158,   176,   160,   172,
     176,   163,   164,   165,   177,   167,   179,   169,   176,   583,
     584,   172,   586,   587,   176,   177,   177,   172,   179,   176,
      50,   172,   172,   172,   171,   172,   173,   174,   179,   179,
     179,   176,    62,    63,     4,     5,    66,    67,    68,    69,
      70,    71,    72,    66,    67,    68,    69,    70,    71,   570,
     571,   172,   172,   171,   172,   173,   174,   808,   179,   179,
     568,   569,   176,   172,   176,    62,    63,   641,   177,    66,
      67,    68,    69,    70,    71,    72,   827,    13,   172,    15,
     172,    17,   603,   177,    57,   177,     4,     5,   609,   610,
      62,    63,   613,   638,    66,    67,    68,    69,    70,    71,
      72,    13,   176,    15,    40,    17,   627,    43,   178,   179,
     655,   656,    48,    66,    67,    68,    69,    70,    71,   172,
     172,   642,   643,   644,   177,   177,   176,   172,    40,   172,
     176,    43,   177,   654,   177,   680,    48,    81,    82,   660,
     661,   171,   172,   173,   174,   666,   667,   668,   176,   172,
     176,    13,   176,    15,   177,    17,   179,   678,   679,   172,
     681,   172,   176,   172,   177,    42,   177,   688,   177,   176,
     691,     4,     5,   764,   171,   172,   173,   174,    40,   179,
     701,    43,   179,   704,   705,   706,    48,   708,   709,   172,
     172,   176,   172,   172,   177,   177,   717,   177,   177,   171,
     172,   173,   174,   172,   172,   177,   172,   179,   177,   177,
     172,   177,   172,   787,   788,   177,   179,   177,   739,   172,
     741,   742,    62,    63,   177,   176,    66,    67,    68,    69,
      70,    71,    72,   172,   172,   172,   176,   172,   177,   177,
     177,   172,   177,   176,    62,    63,   177,   768,    66,    67,
      68,    69,    70,    71,    72,   764,   176,   764,    66,    67,
      68,    69,    70,    71,    72,    48,    49,   176,   789,   790,
       4,     5,    15,   794,   795,    18,    38,    39,   176,   800,
     801,     4,     5,   176,    27,   806,    59,    60,    31,    32,
     176,   176,   176,    36,   176,   176,   870,   871,   794,   795,
     176,   176,   176,   176,   176,    48,    49,    50,   176,   176,
     176,   176,   176,   176,    57,    58,    59,    62,    63,   176,
     176,    66,    67,    68,    69,    70,    71,    72,   176,   176,
     176,   171,   172,   173,   174,   856,   179,   177,    81,   179,
     861,   176,   850,   851,   176,   866,   891,   176,   176,   176,
     176,   176,   176,   171,   172,   173,   174,   176,   179,   177,
     176,   179,   176,   171,   172,   173,   174,   176,   889,   176,
     176,   176,   893,   176,   176,   176,   176,   176,   176,   176,
       5,   177,   177,   904,   975,   976,   179,   179,   179,    71,
     911,   177,   177,    72,   176,   176,   176,   918,   176,   920,
     179,    62,    63,   179,   925,    66,    67,    68,    69,    70,
      71,    72,   177,   177,    42,    45,   176,   176,     9,   176,
     941,   179,   176,   179,   179,  1016,   171,   172,   173,   174,
     173,   179,   177,   179,   179,   177,  1027,   177,   177,  1030,
     183,   179,   177,   176,    42,   177,   177,   190,   176,   179,
     179,   177,   177,    62,   197,  1046,   977,    66,    67,    68,
      69,    70,    71,    72,   177,   177,   975,   976,   975,   976,
     177,   177,   176,    80,   177,   177,    80,   177,   221,   177,
    1001,     5,   179,  1004,   179,   177,   177,   177,   231,   177,
      57,   176,   176,   179,   177,   176,    42,   177,  1019,  1020,
     177,    37,    42,  1024,   176,    71,   177,  1016,   177,  1016,
     171,   172,   173,   174,   257,    71,   177,    71,  1027,    47,
    1027,  1030,    57,  1030,   177,   177,   269,   176,   176,    46,
     273,   176,   176,    71,   177,   177,  1057,  1046,    37,  1046,
       4,   451,    47,    47,   287,   660,   290,   585,    62,    63,
     420,   588,    66,    67,    68,    69,    70,    71,    72,  1000,
     856,   430,   171,   172,   173,   174,   417,   776,  1073,   312,
     313,   314,   315,   316,  1022,    -1,    -1,    -1,    -1,   322,
      -1,   324,    -1,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    -1,
      -1,   344,   345,   346,   347,    -1,    -1,   350,    -1,   352,
      -1,   354,    -1,    -1,    -1,   358,   359,   360,   361,   362,
     363,   364,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,   399,   171,   172,   173,
     174,    -1,    -1,   177,    -1,   179,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   425,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,   447,   448,   449,   450,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
     176,    -1,    -1,     5,   180,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,    -1,    -1,   609,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,     5,   660,    -1,    -1,
       9,    -1,    -1,    -1,   126,   127,   128,    -1,   671,   672,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    -1,
      -1,    30,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,   158,    -1,   160,    -1,
      -1,   163,   164,   165,    -1,   167,    -1,   169,   711,     5,
      -1,    -1,    -1,     9,   176,   177,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,   728,   729,   171,   172,   173,
     174,    -1,    -1,   736,    30,   179,    -1,   740,    -1,    -1,
      -1,    -1,   745,    -1,    -1,   748,   749,    -1,    -1,    -1,
      -1,   100,    -1,   102,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,   771,    -1,
     773,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,   796,   797,   798,   145,   146,   147,    -1,
      -1,   150,    -1,   152,   100,   154,   102,    -1,   157,   158,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,   167,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   856,   150,    -1,   152,    -1,   154,    -1,
      -1,   157,   158,    -1,   160,    -1,    -1,   163,   164,   165,
      -1,   167,    -1,   169,   877,    -1,    -1,    -1,    62,    63,
     176,   177,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,   900,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   924,    -1,    -1,   927,    62,    63,   930,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
     943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   952,
     953,   954,   955,   956,    -1,   958,    -1,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,  1018,    62,    63,    64,    65,
    1023,  1024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,   171,   172,   173,   174,    84,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    97,  1055,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,     3,     4,     5,
     176,     7,     8,     9,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    62,    63,    79,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,     3,     4,     5,
     176,     7,     8,     9,   180,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    62,    63,    79,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,     3,     4,     5,
     176,     7,     8,     9,   180,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    62,    63,    79,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
     176,   177,     3,     4,     5,    -1,     7,     8,     9,    -1,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
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
     151,   152,   153,   154,    -1,   156,   157,   158,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,   176,   177,     3,     4,     5,
      -1,     7,     8,     9,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,
     176,   177,     3,     4,     5,    -1,     7,     8,     9,    -1,
      11,    -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    62,    63,    79,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,     3,     4,     5,   176,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     151,   152,   153,   154,    -1,   156,   157,   158,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,     3,     4,     5,   176,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    29,    30,
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
     151,   152,   153,   154,    -1,   156,   157,   158,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,     3,     4,     5,   176,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    29,    30,
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
     151,   152,   153,   154,     5,   156,   157,   158,     9,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,     9,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
       5,   132,   133,   134,     9,   136,    -1,   138,   139,   140,
      -1,    -1,    92,    -1,   145,   146,   147,    -1,    -1,   150,
     100,   152,   102,   154,    -1,    30,   157,   158,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,   167,    -1,   169,    -1,
      -1,   171,   172,   173,   174,   176,   126,   127,   128,   179,
      -1,     5,   132,   133,   134,     9,   136,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,
     150,    -1,   152,    -1,   154,    -1,    30,   157,   158,    -1,
     160,    -1,    -1,   163,   164,   165,    -1,   167,    -1,   169,
     171,   172,   173,   174,    -1,   100,   176,   102,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,    -1,   150,   100,   152,   102,   154,
      -1,    -1,   157,   158,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      -1,   176,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,    -1,   163,
     164,   165,    -1,   167,    -1,   169,    -1,     4,     5,     6,
      -1,    -1,   176,    10,    -1,    -1,    -1,    14,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,   101,    -1,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,   151,    -1,    -1,    10,   155,    -1,
      -1,    14,   159,    16,   161,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,   171,   172,   173,   174,
      -1,    84,    85,    86,   179,    -1,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,   151,    -1,
      -1,    10,   155,    -1,    -1,    14,   159,    16,   161,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    -1,    62,
      63,    60,    61,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
     171,   172,   173,   174,    -1,    84,    85,    86,   179,    -1,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    62,    63,    -1,   133,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    -1,    62,    63,    -1,   179,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      62,    63,    -1,   179,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    -1,    62,    63,    -1,   179,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,   171,   172,   173,   174,    -1,    62,
      63,    -1,   179,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,    -1,    62,    63,    -1,   179,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      62,    63,   177,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    62,    63,   177,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    62,    63,   177,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,    62,    63,   177,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,    62,    63,   177,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    62,    63,   177,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,    62,    63,
     177,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,    62,    63,
     177,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    62,    63,   177,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    62,    63,   177,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,    62,    63,   177,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      62,    63,   177,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    62,    63,   177,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    -1,    -1,   177,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,    62,    63,
     177,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,    62,    63,   177,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    62,
      63,   177,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    62,    63,   177,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    62,    63,   177,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,   171,
     172,   173,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    62,    63,   177,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    62,    63,   177,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    62,    63,   177,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    62,    63,   177,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,    62,    63,   177,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,   171,   172,   173,   174,    -1,    -1,   177,    -1,    -1,
      -1,    -1,   171,   172,   173,   174,    62,    63,   177,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      62,    63,   177,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,
      -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,   173,
     174,    -1,    -1,   177,    -1,    -1,    -1,    -1,   171,   172,
     173,   174,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,   174,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,   174
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
     103,   104,   126,   127,   128,   133,   151,   155,   159,   161,
     182,   183,   185,   192,   193,   195,   196,   200,   212,   213,
     218,   224,   231,   239,   247,   250,   254,   257,   263,    71,
     176,    71,   176,   232,   251,   255,     4,     7,   210,   210,
     210,     3,     4,     5,     7,     8,     9,    29,    30,    33,
      62,    63,    64,    65,    76,    79,    96,    97,   100,   102,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   156,
     157,   158,   160,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   176,   198,   199,   201,   207,   209,   212,
     213,   186,   187,   176,   198,   176,   176,   198,    27,     7,
     240,   248,   201,    57,    59,    60,   180,   286,   190,   198,
     201,     4,     5,   211,   201,   198,   201,   198,   201,     4,
       5,   274,   275,     9,   171,   172,   208,   209,   276,   210,
      84,    92,   180,   198,   201,   287,    84,    92,   105,   287,
     287,    83,   201,   206,    11,    52,   206,   206,    58,    84,
      85,    86,    91,    90,   201,   193,   200,   212,   213,   198,
     198,   198,   105,   176,   176,   176,   176,   176,   198,   287,
     198,   198,     0,    43,   184,    87,    88,    99,    71,    71,
      23,   201,   214,   215,   198,   214,     4,   201,   183,   176,
     176,    34,    35,   176,   176,   201,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   201,   198,   201,    66,    67,
      68,    69,    70,    71,   172,    19,    20,    62,    63,    66,
      67,    68,    69,    70,    71,    72,   171,   172,   173,   174,
       4,     5,   225,   226,     4,     5,   227,   228,   198,   214,
     214,   198,   201,   242,   183,   258,   264,   176,    57,   176,
       4,     7,   176,   198,   201,   277,    57,   180,   279,   284,
     176,   176,   179,   179,   179,   176,   176,   179,   209,   209,
     179,   201,   198,   201,    10,   179,   179,   198,   179,   206,
     191,    11,   179,   194,   179,   206,    11,   206,   194,   194,
       5,   197,   197,   197,   177,   201,   198,   179,   179,   179,
     179,    42,   206,   206,   206,   201,   198,   219,   177,   198,
     201,   216,   217,   177,    71,   252,    13,    15,    17,    40,
      43,    48,   256,   214,   214,   201,   201,   201,    92,   198,
     287,   287,     4,     5,   204,   205,   204,   205,   206,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     287,   201,   201,   201,   201,   201,   201,   201,   177,   201,
     198,   198,   198,   198,   198,   201,   201,   201,   177,   201,
     201,   198,   201,   198,   201,   198,   198,   177,   198,   177,
     198,   177,   198,   177,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   287,   198,   214,   214,   198,   198,
     198,   198,   177,   177,   198,   197,   198,   197,   198,   177,
     177,   198,   198,   198,   198,   198,   198,   198,   188,   189,
     203,   202,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   176,   176,   179,   176,   176,   179,   177,
     177,    42,   241,    13,    15,    17,    40,    43,    48,   249,
      45,   183,   201,   176,   198,   201,    50,   278,   178,   179,
     176,     4,     7,   176,     9,   285,   214,   214,     4,     5,
     201,   201,   214,   214,   275,     9,   208,   179,    81,    82,
      92,   198,   201,   201,   279,   206,   198,   206,   194,   201,
     201,   176,   179,   179,   179,   177,   177,   198,   201,   198,
     201,   198,   198,   185,   179,   194,   194,     4,     5,   223,
     179,   233,   183,   201,   177,   177,   179,   179,   179,   177,
     177,   179,   179,   177,   176,   176,   177,   177,   179,   179,
     194,   179,   177,   177,   177,   177,   177,   177,   179,   177,
     177,   179,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   179,   177,   177,   179,   179,   179,   177,   179,   179,
     177,   179,   177,   177,   177,   177,   177,   179,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   179,   179,
     177,   177,   177,   177,   177,   177,   179,   177,   177,   179,
     179,   179,   179,   179,   177,   179,   179,   177,   179,   179,
     210,   288,   210,   289,   201,   201,   214,   214,   226,   214,
     214,   228,    42,   243,   259,    48,    49,   265,   179,   201,
     177,   179,   177,   176,   198,   198,   201,   201,   280,   281,
     201,     4,     5,   271,   273,   177,   177,   176,   176,   179,
     179,   177,   177,   201,    80,    80,   179,   179,   179,   206,
     179,   179,   214,   201,   201,   201,   179,   201,   206,   206,
     220,   217,   201,    15,    43,   253,   201,   201,   201,   198,
      92,   198,   177,   177,   201,   201,   206,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   198,   201,   198,   198,
     198,   201,   198,   201,   201,   205,   198,   205,   198,   198,
     179,   179,   177,   177,   177,   177,    38,    39,   245,   183,
     201,   179,    57,   198,   198,   278,   179,   271,   271,   177,
     176,   176,   179,   214,   214,   201,   201,   179,   287,   287,
     198,   198,   198,   201,   201,   177,   177,   177,   177,   179,
     201,   194,   176,    11,   177,   177,   177,   177,   177,   177,
     179,   177,   177,   177,   194,   177,   177,   177,   177,   177,
     177,   179,   177,   177,   177,   179,   177,   177,   179,   177,
     179,   177,   177,   177,   179,   179,   177,   179,   177,   177,
     179,   177,   177,   210,   210,   242,    42,    37,   260,   177,
     201,   176,   177,   179,   201,   282,   214,   214,   272,   177,
     177,   198,   179,   179,    71,    71,    71,   201,   179,   206,
       4,     5,   229,   230,   201,   198,   201,   201,   198,   201,
     201,   198,   201,   198,   198,   244,   246,    47,   267,    59,
      60,   177,   201,    57,   198,   177,   271,   177,   177,   271,
     198,   198,   198,   198,   198,   177,   198,   176,   176,   177,
     179,    12,   237,   177,   179,   177,   177,   177,   177,   177,
     177,   177,   177,   183,   183,   201,    46,   266,   176,   179,
     176,   177,   283,    71,   179,   177,   177,   221,   230,   201,
     234,   201,    45,   270,   183,   261,   198,   201,   201,   285,
     198,   198,   201,   183,   183,   177,   268,    13,    15,    17,
      40,    43,    48,   262,   177,   179,   177,   179,   271,    24,
      43,   222,   235,   183,   198,   201,    13,    15,    17,    40,
      43,    48,   236,   269,   177,   177,     4,   238,   267
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   181,   182,   183,   184,   183,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   186,   185,   187,   185,   185,   185,
     185,   185,   185,   185,   188,   185,   189,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   190,   185,
     191,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     192,   192,   192,   192,   192,   193,   193,   193,   193,   193,
     193,   194,   194,   195,   195,   195,   195,   195,   196,   196,
     197,   197,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   200,   200,   202,   201,   203,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   204,   205,   206,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   208,   208,
     208,   209,   209,   209,   210,   210,   211,   211,   211,   211,
     212,   213,   215,   214,   216,   216,   216,   217,   217,   219,
     220,   221,   218,   222,   222,   223,   223,   224,   224,   224,
     224,   225,   225,   226,   226,   226,   226,   227,   227,   228,
     228,   228,   228,   229,   229,   229,   230,   230,   230,   230,
     232,   233,   234,   235,   231,   236,   236,   236,   236,   236,
     236,   237,   237,   238,   238,   240,   239,   241,   241,   242,
     242,   243,   244,   243,   245,   246,   245,   248,   247,   249,
     249,   249,   249,   249,   249,   251,   252,   250,   253,   253,
     255,   254,   256,   256,   256,   256,   256,   256,   258,   259,
     260,   261,   257,   262,   262,   262,   262,   262,   262,   264,
     263,   265,   265,   266,   266,   267,   268,   269,   267,   270,
     270,   271,   272,   271,   273,   273,   273,   273,   274,   274,
     275,   275,   275,   275,   276,   276,   276,   276,   277,   277,
     277,   277,   277,   278,   278,   278,   280,   279,   281,   279,
     282,   279,   283,   279,   284,   279,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   287,   287,   288,   288,   289,   289
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
       4,     4,     1,     1,     2,     1,     2,     4,    10,    10,
       0,     1,     1,     2,     2,     3,    10,     8,     8,     8,
       3,     1,     1,     6,     4,     4,     6,     6,     4,     6,
       1,     4,     1,     1,     1,     1,     3,     3,     6,     6,
       8,     6,     4,     6,     8,     1,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     3,     3,     0,     4,     0,
       4,     2,     3,     3,     3,     3,     3,     3,     4,     6,
       1,     4,     4,     6,     6,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     8,     4,
       4,     4,     1,     3,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     6,     6,     6,     4,     8,     6,     8,
       6,     4,     4,     4,     6,     6,     6,     8,     1,     2,
       2,     1,     1,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     0,     2,     0,     1,     3,     1,     1,     0,
       0,     0,    11,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     3,     1,     1,     4,     4,     1,     3,     1,
       1,     4,     4,     0,     1,     3,     1,     1,     3,     3,
       0,     0,     0,     0,    14,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     1,     0,     7,     1,     2,     1,
       1,     0,     0,     5,     0,     0,     4,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     0,     6,     1,     1,
       0,     4,     1,     2,     1,     1,     1,     1,     0,     0,
       0,     0,    11,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     1,     0,     2,     0,     0,     0,     7,     0,
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

    {add_command(cFGNBF_FREE,NULL,NULL);}

    break;

  case 108:

    {add_command(cFGNBF_SET_NUMBER, NULL, NULL);}

    break;

  case 109:

    {add_command(cFGNBF_SET_STRING, NULL, NULL);}

    break;

  case 110:

    {drawmode=0;}

    break;

  case 111:

    {drawmode=dmCLEAR;}

    break;

  case 112:

    {drawmode=dmFILL;}

    break;

  case 113:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 114:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 115:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 116:

    {create_changestring(fMID);}

    break;

  case 117:

    {create_changestring(fMID2);}

    break;

  case 118:

    {create_changestring(fLEFT);}

    break;

  case 119:

    {create_changestring(fRIGHT);}

    break;

  case 120:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 123:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 124:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 125:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 126:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 127:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 128:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 129:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 130:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 131:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 132:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 134:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 135:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 136:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 138:

    {create_function(fLEFT);}

    break;

  case 139:

    {create_function(fRIGHT);}

    break;

  case 140:

    {create_function(fMID);}

    break;

  case 141:

    {create_function(fMID2);}

    break;

  case 142:

    {create_function(fSTR);}

    break;

  case 143:

    {create_function(fSTR2);}

    break;

  case 144:

    {create_function(fSTR3);}

    break;

  case 145:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 146:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 147:

    {create_function(fINKEY);}

    break;

  case 148:

    {create_function(fCHR);}

    break;

  case 149:

    {create_function(fUPPER);}

    break;

  case 150:

    {create_function(fLOWER);}

    break;

  case 151:

    {create_function(fLTRIM);}

    break;

  case 152:

    {create_function(fRTRIM);}

    break;

  case 153:

    {create_function(fTRIM);}

    break;

  case 154:

    {create_function(fCHOMP);}

    break;

  case 155:

    {create_function(fSYSTEM2);}

    break;

  case 156:

    {create_function(fFGNFN_CALL2);}

    break;

  case 157:

    {create_function(fFGNBF_NEW);}

    break;

  case 158:

    {create_function(fFGNBF_DUMP);}

    break;

  case 159:

    {create_function(fDATE);}

    break;

  case 160:

    {create_function(fDATE);}

    break;

  case 161:

    {create_function(fTIME);}

    break;

  case 162:

    {create_function(fTIME);}

    break;

  case 163:

    {create_function(fPEEK2);}

    break;

  case 164:

    {create_function(fPEEK3);}

    break;

  case 165:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 166:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 167:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 168:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 169:

    {create_function(fGETBIT);}

    break;

  case 170:

    {create_function(fGETCHAR);}

    break;

  case 171:

    {create_function(fHEX);}

    break;

  case 172:

    {create_function(fBIN);}

    break;

  case 173:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 174:

    {create_function(fFGNBF_GET_STRING);}

    break;

  case 175:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 176:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 177:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 178:

    {poplabel();create_boole('|');}

    break;

  case 179:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 180:

    {poplabel();create_boole('&');}

    break;

  case 181:

    {create_boole('!');}

    break;

  case 182:

    {create_dblrelop('=');}

    break;

  case 183:

    {create_dblrelop('!');}

    break;

  case 184:

    {create_dblrelop('<');}

    break;

  case 185:

    {create_dblrelop('{');}

    break;

  case 186:

    {create_dblrelop('>');}

    break;

  case 187:

    {create_dblrelop('}');}

    break;

  case 188:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 189:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 190:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 191:

    {add_command(cARDIM,"",NULL);}

    break;

  case 192:

    {add_command(cARDIM,"",NULL);}

    break;

  case 193:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 194:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 195:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 196:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 197:

    {create_dblbin('+');}

    break;

  case 198:

    {create_dblbin('-');}

    break;

  case 199:

    {create_dblbin('*');}

    break;

  case 200:

    {create_dblbin('/');}

    break;

  case 201:

    {create_dblbin('^');}

    break;

  case 202:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 203:

    {create_strrelop('=');}

    break;

  case 204:

    {create_strrelop('!');}

    break;

  case 205:

    {create_strrelop('<');}

    break;

  case 206:

    {create_strrelop('{');}

    break;

  case 207:

    {create_strrelop('>');}

    break;

  case 208:

    {create_strrelop('}');}

    break;

  case 211:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 212:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 214:

    {create_function(fSIN);}

    break;

  case 215:

    {create_function(fASIN);}

    break;

  case 216:

    {create_function(fCOS);}

    break;

  case 217:

    {create_function(fACOS);}

    break;

  case 218:

    {create_function(fTAN);}

    break;

  case 219:

    {create_function(fATAN);}

    break;

  case 220:

    {create_function(fATAN2);}

    break;

  case 221:

    {create_function(fEXP);}

    break;

  case 222:

    {create_function(fLOG);}

    break;

  case 223:

    {create_function(fLOG2);}

    break;

  case 224:

    {create_function(fSQRT);}

    break;

  case 225:

    {create_function(fSQR);}

    break;

  case 226:

    {create_function(fINT);}

    break;

  case 227:

    {create_function(fCEIL);}

    break;

  case 228:

    {create_function(fFLOOR);}

    break;

  case 229:

    {create_function(fFRAC);}

    break;

  case 230:

    {create_function(fABS);}

    break;

  case 231:

    {create_function(fSIG);}

    break;

  case 232:

    {create_function(fMOD);}

    break;

  case 233:

    {create_function(fRAN);}

    break;

  case 234:

    {create_function(fRAN2);}

    break;

  case 235:

    {create_function(fMIN);}

    break;

  case 236:

    {create_function(fMAX);}

    break;

  case 237:

    {create_function(fLEN);}

    break;

  case 238:

    {create_function(fVAL);}

    break;

  case 239:

    {create_function(fASC);}

    break;

  case 240:

    {create_function(fDEC);}

    break;

  case 241:

    {create_function(fDEC2);}

    break;

  case 242:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 243:

    {create_function(fINSTR2);}

    break;

  case 244:

    {create_function(fRINSTR);}

    break;

  case 245:

    {create_function(fRINSTR2);}

    break;

  case 246:

    {create_function(fSYSTEM);}

    break;

  case 247:

    {create_function(fFGNFN_CALL);}

    break;

  case 248:

    {create_function(fFGNBF_GET_NUMBER);}

    break;

  case 249:

    {create_function(fPEEK4);}

    break;

  case 250:

    {create_function(fPEEK);}

    break;

  case 251:

    {create_function(fMOUSEX);}

    break;

  case 252:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 253:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 254:

    {create_function(fMOUSEY);}

    break;

  case 255:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 256:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 257:

    {create_function(fMOUSEB);}

    break;

  case 258:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 259:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 260:

    {create_function(fMOUSEMOD);}

    break;

  case 261:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 262:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 263:

    {create_function(fAND);}

    break;

  case 264:

    {create_function(fOR);}

    break;

  case 265:

    {create_function(fEOR);}

    break;

  case 266:

    {create_function(fTELL);}

    break;

  case 267:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 268:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 269:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 270:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 271:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 272:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 273:

    {create_myopen(0);}

    break;

  case 274:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 275:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 276:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 277:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 278:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 279:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 280:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 281:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 282:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 283:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 284:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 285:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 286:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 287:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 288:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 289:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 290:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 291:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 292:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 299:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 300:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 301:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 302:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 303:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 304:

    {missing_endsub--;}

    break;

  case 305:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 306:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 307:

    {exported=FALSE;}

    break;

  case 308:

    {exported=TRUE;}

    break;

  case 309:

    {exported=FALSE;}

    break;

  case 310:

    {exported=TRUE;}

    break;

  case 313:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 314:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 315:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 316:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 319:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 320:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 321:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 322:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 326:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 327:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 328:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 329:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 330:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 331:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 332:

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

  case 333:

    {
             swap();popgoto();poplabel();}

    break;

  case 334:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 335:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 336:

    {missing_next--;}

    break;

  case 337:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 338:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 339:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 340:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 341:

    {create_pushdbl(1);}

    break;

  case 343:

    {pop(stSTRING);}

    break;

  case 344:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 345:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 346:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 352:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 353:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 355:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 357:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 359:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 360:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 361:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 362:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 363:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 364:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 365:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 366:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 368:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 369:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 370:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 372:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 373:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 374:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 375:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 376:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 377:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 378:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 379:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 380:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 381:

    {poplabel();}

    break;

  case 383:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 384:

    {missing_endif--;}

    break;

  case 385:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 386:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 387:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 388:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 389:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 391:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 392:

    {poplabel();}

    break;

  case 396:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 397:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 402:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 404:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 405:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 406:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 407:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 410:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 411:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 412:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 413:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 414:

    {create_strdata((yyvsp[0].string));}

    break;

  case 415:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 416:

    {create_strdata((yyvsp[0].string));}

    break;

  case 417:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 421:

    {create_print('s');}

    break;

  case 422:

    {create_print('s');}

    break;

  case 423:

    {create_print('d');}

    break;

  case 424:

    {create_print('u');}

    break;

  case 425:

    {create_print('U');}

    break;

  case 426:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 427:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 428:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 429:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 430:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 431:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 432:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 433:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 434:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 435:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 436:

    {create_pushstr("?");create_print('s');}

    break;

  case 437:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 438:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 439:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 440:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 450:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 454:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 455:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 456:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 457:

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
