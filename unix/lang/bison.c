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
    tFRNFN_CALL = 411,
    tFRNFN_CALL2 = 412,
    tFRNFN_SIZE = 413,
    tFRNBF_NEW = 414,
    tFRNBF_FREE = 415,
    tFRNBF_DUMP = 416,
    tFRNBF_SET = 417,
    tFRNBF_GET = 418,
    tFRNBF_GET2 = 419,
    tDATE = 420,
    tTIME = 421,
    tTOKEN = 422,
    tTOKENALT = 423,
    tSPLIT = 424,
    tSPLITALT = 425,
    tGLOB = 426,
    UMINUS = 427
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
#define YYLAST   5617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  182
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  457
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1079

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   427

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   181,     2,     2,     2,     2,
     177,   178,   174,   173,   180,   172,     2,   175,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   179,
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
     165,   166,   167,   168,   169,   170,   171,   176
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
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_NEW",
  "tFRNBF_FREE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
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
     425,   426,    45,    43,    42,    47,   427,    40,    41,    59,
      44,    35
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
    3922,   -22,   -18,  -724,  -724,  -724,  -724,  -724,   134,   134,
     134,  2936,  -724,  -724,  -724,  3543,  -153,  -110,  3543,    63,
      69,  -724,  -724,  -724,  3278,   -24,  -724,  3278,   115,  -724,
    3278,  3278,  3278,   266,    35,   134,  1724,  1134,  2066,    59,
    3278,  2765,  3278,   264,    60,  3278,  -724,    25,  3543,  3543,
    3543,    55,   -23,     0,     5,    27,    37,  2066,  3543,  3543,
     180,   159,  -724,     7,  -724,  -724,  -724,  -724,   120,   146,
    -724,   205,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  3278,
    -724,  3543,  -724,   251,  3278,  3769,  -724,  -724,  -724,  -724,
    -724,  -724,    97,   103,  -724,  -724,  -724,   126,   128,   209,
     150,   156,  3278,   168,   179,   196,   200,   213,   223,   233,
     247,   274,   284,   300,   302,   312,   314,   329,   351,   381,
     385,   389,   399,   410,   418,   420,   438,   464,   481,   483,
     485,   489,   492,   495,   498,   505,   579,   589,   600,   611,
     614,   615,   616,   619,   620,   623,   625,   627,   628,   633,
     634,   635,   636,   637,   650,   651,   652,   653,   656,   657,
     665,   666,   667,   669,   670,   672,   674,   677,   680,   681,
     682,   683,  3278,  3278,   338,  -724,   363,  -724,  -724,  -724,
    -724,   337,   371,  3543,   219,  -724,  -724,   219,  -724,  -724,
    3278,  3769,   197,   684,   458,   685,    10,  3278,   -25,   338,
    1259,   686,   691,   341,  1259,   338,   512,   338,  1352,   694,
     696,   413,  -724,  -724,   561,   561,  -724,  -724,   431,  -724,
    3278,  3543,  3278,    12,  1259,   509,  -724,  -724,  -724,  -724,
     521,  3543,  1534,  -724,  3278,  -724,     4,   541,  -724,  -724,
    3278,  3107,  -724,  -724,  1259,  -724,  -724,   120,   146,   219,
      -6,    -6,  -724,   714,   714,   714,  2237,  3543,    30,   557,
    -103,   -69,  -724,  -724,   707,  3278,  3278,  3278,  3278,  3543,
    -724,  1259,   701,  3278,   219,   703,   730,  1259,   456,  -724,
    -724,  -724,  -724,  3278,  3278,   702,  3278,  1895,  2066,   409,
     409,  3278,  3278,  3278,  3278,  3278,  3278,  3278,  3278,  3278,
    3278,  3278,  3278,  2066,  3278,  3278,  3278,  3278,  3278,  3278,
    3278,  2413,  3543,  3543,  3543,  3543,  3543,  3278,  3278,  3278,
    2589,  3278,  3543,  3278,  3543,  3278,  3543,  3543,   348,  1309,
    1421,  1488,  3543,  3543,  3543,  3543,  3543,  3543,  3543,  3543,
    2066,  3543,  -724,  -724,  3543,  3543,  3543,  3543,   705,   706,
    3543,   714,  3543,   714,  3543,   797,   486,   769,  3543,  3543,
    3543,  3543,  3543,  3543,  3543,  -724,  -724,  -724,  -724,  3278,
    3278,  3278,  3278,  3278,  3278,  3278,  3278,  3278,  3278,  3278,
     708,   709,   700,  -724,   710,   711,   712,  -724,  -133,   713,
     718,   338,  1259,   847,   548,   845,  3769,  3278,   720,  3543,
    -724,  -724,  3278,   338,   479,   144,   721,    24,  -724,   896,
    -724,  -724,   434,  3278,  3278,  -724,  -724,   266,  -724,  -724,
      51,  1743,   219,  1259,   449,  3431,  3278,   219,  3278,  -724,
     -25,  -724,  -724,  3278,  3543,  -724,  3278,     4,  3278,  3278,
     729,   728,   732,   733,  -724,  1606,   -86,  3278,  3278,  3543,
    3543,  3769,   735,     4,     4,  1259,   219,   539,  -724,   338,
    1259,   736,  -724,  -724,  -724,  3769,  -724,  -724,  3278,  -724,
    -724,  -724,  -724,   739,   740,  1910,  2081,  2252,   741,    -5,
     742,   743,   734,   750,   753,   754,   748,   749,     4,  2428,
    4395,  4406,  4417,  4439,  4463,   538,  4474,   692,  4531,  4553,
     755,  4588,  4599,  4610,  4621,  4645,  4667,  2607,  -724,  4678,
     -71,    81,   131,   152,    80,  2780,  2951,   995,  -724,  4735,
    4759,   286,  4792,   -15,  4803,   289,   319,  -724,   412,  -724,
     416,  -724,   439,  -724,   440,   441,   469,   500,   216,   239,
     503,   526,   527,   556,   756,    17,   758,   759,   276,   280,
     290,   292,  -724,  -724,   305,  -139,   310,   -75,   328,  -724,
    -724,   219,   219,   219,   219,   219,   219,  -724,   134,   134,
    3278,  3278,   751,    65,   832,   248,   272,    -3,  -724,   -49,
     -49,   797,   797,  -724,  -724,   337,  -724,  -724,   371,  -724,
    -724,  -724,   868,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   524,  3122,  3278,    20,  4814,  3601,  -724,  -724,  3278,
    3278,  -724,  -724,  3278,  -724,   624,   760,   761,   768,   771,
    3293,  3812,   773,   774,  -724,  -724,  -724,  3278,   840,   873,
    -724,   330,  3965,  1259,  -724,  -724,   344,  -724,  3278,  4118,
    4143,  -724,  3278,  3278,  3278,  -724,  -724,   338,  1259,   338,
    1259,   219,   354,  -724,  3278,  3278,  3278,  -724,  -724,  -724,
    3278,  3278,    32,  1259,  -724,  -724,  3278,  3278,  3278,  -724,
    -724,  3543,  3487,  -724,   776,   777,  -724,  -724,  3278,  3278,
    3278,  3278,  -724,  -724,  -724,  -724,  -724,  -724,  3278,  -724,
    -724,  3278,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  3278,  -724,  -724,  3278,  3278,  3278,  -724,  3278,  3278,
    -724,  3543,  -724,  -724,  -724,  -724,  -724,  3278,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  3543,  3543,
    -724,  -724,  -724,  -724,  -724,  -724,  3543,  -724,  -724,  3278,
    3543,  3278,  3278,   951,  -724,  3543,   951,  -724,  3543,  3543,
    -724,   778,  -724,   779,   702,   568,   782,   783,  -724,   784,
     785,  -724,  -724,   687,  3769,  -724,  -724,  -724,  3278,  4176,
     910,  3543,  -724,  3543,   219,   338,   479,  4187,   624,   624,
    4825,   791,   792,  -724,   790,  -724,  -724,  -724,  -724,  3278,
    3278,  -724,  -724,  4198,  2066,  2066,  3543,  3543,  3543,  -724,
    3278,  3278,   793,  4849,  4873,  1006,  3278,  1259,     4,  -724,
     795,  -724,    61,  -724,  -724,  -724,  4884,  4939,  4963,   529,
     796,    68,  -724,  -724,  4998,  5009,   802,    46,  5020,  5031,
    5053,  5077,  5088,  1326,  5145,  5167,   148,  5202,   201,   207,
     530,  5213,   536,  4209,  4233,   -14,   542,    -2,   544,   554,
     134,   134,  -724,  -724,  -724,  -724,  3278,   931,   938,   939,
    5224,  3278,   805,   560,   215,  -724,  3278,  -724,  -724,  -724,
    -724,  -724,  -724,   806,   807,  1259,  1259,  3543,  -724,  -724,
     219,   219,   359,  4258,  1259,  -724,   912,   915,   916,  3278,
    4269,  3278,   731,  3278,  -724,  -724,  -724,  -724,  -724,  -724,
    3543,  -724,  -724,  -724,  3278,  -724,  -724,  -724,  -724,  -724,
    -724,  3278,  -724,  -724,  -724,  3543,  -724,  -724,  3278,  -724,
    3278,  -724,  -724,  -724,  3543,  3278,  -724,  3543,  -724,  -724,
    3543,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   942,   727,
    5235,  3278,   934,  3543,  5259,   624,   814,   816,   624,  -724,
    -724,   219,  3543,  3543,  3543,  3543,  3543,  5281,  3543,  -724,
     818,   819,    49,  -724,    77,   566,  4324,  5292,   572,  5349,
    5373,   573,  5406,   574,   575,  3769,  4075,  3278,   953,  -724,
     820,  -724,  4348,   823,   602,  -724,  -724,  -724,  -724,  -724,
     219,   219,   219,   219,   219,   930,   360,   824,   825,  -724,
     731,  3278,  -724,  -724,  3278,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   939,   973,   268,  3769,  -724,  3543,  3278,
    3278,  -724,   896,  3543,  3278,  -724,  -724,  3769,  -724,  1259,
    3769,  5417,  -724,  -724,   939,   631,   238,  5428,  4384,   624,
     219,   338,  1259,    50,   939,  -724,  3769,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  3543,  -724,  3278,  -724,  -724,
    -724,  -724,   648,   939,   603,  5439,  -724,  -724,  -724,  -724,
    -724,  -724,  1007,   942,  -724,  -724,  -724,  -724,  -724
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
    -724,  -724,   -81,  -724,   563,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,   965,  -241,  -724,  -724,  -170,   767,  -724,   968,
     -11,  -724,  -724,   726,  -288,   -35,  -724,   598,   -26,     2,
    -724,     1,     3,   -64,  -724,  -724,   361,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   435,  -724,   437,  -724,    22,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   167,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,   -47,  -724,  -724,  -724,
    -723,  -724,  -724,  -724,   610,  -724,  -724,   253,   604,  -724,
    -724,  -724,  -724,  -724,    13,  -724,    14,  -724,  -724
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
     439,    89,    90,   192,   400,   431,   200,   401,   275,   204,
     206,   208,   424,   375,   185,   224,   224,   224,   611,     1,
       2,   612,   406,   193,   244,   194,   195,   219,    91,   744,
     364,   745,    94,    95,   213,   559,   224,   813,   247,    79,
     248,   229,   230,    81,    91,   867,   868,   431,    94,    95,
     625,   358,   359,   360,   361,   362,   363,   186,   271,   375,
     364,   259,   893,   277,  1059,   814,   189,   449,   358,   359,
     360,   361,   362,   363,   442,   443,    68,   364,    69,  1001,
     188,   285,   646,  1060,   265,   266,   358,   359,   360,   361,
     362,   363,   364,   747,   364,   748,   267,   703,   367,   368,
     394,   450,   369,   370,   371,   372,   373,   374,   375,   201,
     202,   389,   390,   367,   368,   378,   379,   369,   370,   371,
     372,   373,   374,   375,   372,   373,   374,   375,    86,   367,
     368,    87,   231,   369,   370,   371,   372,   373,   374,   375,
     243,    52,    53,    54,   253,    80,   407,   196,   364,    82,
     252,   355,   357,   716,   926,   717,   927,   364,   364,   376,
     377,   378,   379,   670,   432,   671,   929,   254,   930,   392,
     262,   555,   255,   557,   432,   364,   404,   402,   418,   419,
     364,   268,    68,   364,    69,   735,   638,   736,   770,   429,
     771,   613,   263,   364,   256,   435,   437,   214,   215,   421,
     447,   423,   655,   656,   257,   473,   474,   269,   376,   377,
     378,   379,   986,   214,   215,   989,   432,   999,   270,  1000,
     452,   453,   454,   376,   377,   378,   379,   376,   377,   378,
     379,   364,  -378,   281,   282,   445,   899,   680,   900,   376,
     377,   378,   379,   364,   364,   276,   488,   455,   707,   367,
     368,   704,   460,   369,   370,   371,   372,   373,   374,   375,
     209,   210,   475,   476,    80,   477,   224,   224,   546,   547,
      82,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   224,   501,   502,   503,   504,   505,   506,   507,
     509,   480,   481,   279,   364,   280,   515,   516,   517,   519,
     520,   705,   522,  1032,   524,   601,  1058,   500,   373,   374,
     375,   364,   238,   608,   609,   364,   914,   283,   915,   224,
     367,   368,   706,   284,   369,   370,   371,   372,   373,   374,
     375,   380,   381,   374,   375,   286,   616,   617,   239,   240,
     241,   622,   623,    93,   544,   242,   287,    96,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   376,
     377,   378,   379,   288,   364,   384,   385,   289,    98,   917,
     364,   918,   365,   366,   662,   919,   602,   920,   364,   364,
     290,   605,   364,   559,   217,   943,   728,    68,   635,    69,
     291,   637,   620,   621,   358,   359,   360,   361,   362,   363,
     292,   364,   364,   482,   483,   632,  1054,   633,  1055,   729,
     376,   377,   378,   379,   293,   367,   368,   639,   640,   369,
     370,   371,   372,   373,   374,   375,   648,   650,   618,   619,
     376,   377,   378,   379,   376,   377,   378,   379,   108,   364,
     109,   294,    68,   364,    69,   845,   739,   663,   847,   364,
     740,   295,   364,   364,   714,   364,    68,   719,    69,   466,
     741,   467,   742,   468,   130,   131,   132,   296,   364,   297,
     136,   137,   138,   364,   140,   743,   142,   143,   144,   298,
     746,   299,   364,   149,   150,   151,   469,   720,   154,   470,
     156,   364,   158,   364,   471,   160,   300,   161,   749,   162,
     796,   364,   164,   165,   166,   398,   168,   364,   170,   756,
     757,   412,   759,   760,   798,   183,   527,   364,   301,   606,
     628,   629,   364,   364,   806,   376,   377,   378,   379,   952,
    1024,   367,   368,   657,   658,   369,   370,   371,   372,   373,
     374,   375,   358,   359,   360,   361,   362,   363,   302,   754,
     755,   593,   303,   594,    91,   595,   304,   891,    94,    95,
     750,   752,   765,   766,   367,   368,   305,   802,   369,   370,
     371,   372,   373,   374,   375,   364,   904,   306,   596,   364,
     721,   597,   769,   417,   722,   307,   598,   308,   776,   777,
     367,   368,   780,   799,   369,   370,   371,   372,   373,   374,
     375,   420,   364,   364,   364,   309,   793,   723,   724,   725,
     808,   809,   358,   359,   360,   361,   362,   363,   781,   782,
     367,   803,   804,   805,   369,   370,   371,   372,   373,   374,
     375,   310,   364,   807,  1047,   826,  1048,   726,  1049,   460,
     812,   376,   377,   378,   379,   816,   817,   818,   311,   364,
     312,  1066,   313,  1067,   559,  1068,   314,   824,   825,   315,
     827,  1050,   316,   364,  1051,   317,   364,   828,   727,  1052,
     829,   730,   318,   859,   376,   377,   378,   379,  1069,   425,
     830,  1070,   413,   831,   832,   833,  1071,   834,   835,   364,
     364,   426,   364,   364,   731,   732,   837,   897,   921,   364,
     376,   377,   378,   379,   923,   364,   687,   364,   688,   440,
     928,   434,   931,   873,   874,   856,   857,   364,   841,   364,
     843,   844,   932,   364,   733,   960,   961,   448,   942,   364,
     376,   377,   378,   379,  1003,   364,   364,   364,   364,   451,
    1006,  1009,  1011,  1012,   367,   368,   319,   860,   369,   370,
     371,   372,   373,   374,   375,    68,   320,    69,   369,   370,
     371,   372,   373,   374,   375,   364,   364,   321,   875,   876,
    1021,  1074,   184,   224,   224,   187,   979,   980,   322,   883,
     884,   323,   324,   325,   199,   890,   326,   327,   205,   207,
     328,   464,   329,   223,   330,   331,   946,   947,   878,   879,
     332,   333,   334,   335,   336,   249,   250,   251,   370,   371,
     372,   373,   374,   375,   258,   260,   261,   337,   338,   339,
     340,   367,   368,   341,   342,   369,   370,   371,   372,   373,
     374,   375,   343,   344,   345,   392,   346,   347,   274,   348,
     940,   349,   933,   934,   350,   944,   959,   351,   352,   353,
     354,   397,   399,   410,   376,   377,   378,   379,   411,   375,
     690,   415,   691,   416,   376,   377,   378,   379,   957,   458,
     585,   463,   964,   552,   553,   583,   584,   586,   587,   591,
     600,   589,   588,   966,  1013,  1014,   590,   603,   610,   370,
     967,   372,   373,   374,   375,   614,   641,   969,   642,   970,
     762,   674,   643,   644,   972,   654,   660,   664,   665,   669,
     794,   673,   672,   376,   377,   378,   379,   675,   678,   679,
     982,   676,   677,   694,   734,  1034,   737,   738,   785,   786,
     356,   376,   377,   378,   379,   787,  1043,   560,   788,  1044,
     388,   791,   792,   795,   822,   823,   483,   391,   850,   851,
     852,   853,   854,   855,   403,  1063,  1015,   862,   870,   871,
     872,   885,   892,   936,   898,   937,    68,    68,    69,    69,
     903,    -4,   941,   954,   949,   950,   955,   956,   422,   977,
    1029,   983,   987,  1031,   988,   997,   998,  1018,   427,  1016,
    1020,  1023,  1025,  1026,   376,   377,   378,   379,  1037,  1038,
    -356,  1076,   245,  1042,   653,   246,   486,    68,   626,    69,
     758,   811,  1028,   935,   446,   761,  1078,   624,    68,   865,
      69,    68,     0,    69,   634,  1039,   456,     0,     0,     0,
     459,     0,     0,     0,     0,     0,  1065,    68,     0,    69,
       0,     0,     0,     0,   479,     0,     0,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,   510,
     511,   512,   513,   514,     0,     0,     0,     0,     0,   521,
       0,   523,     0,   525,   526,   528,   530,   532,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   545,     0,
       0,   548,   549,   550,   551,     0,     0,   554,     0,   556,
       0,   558,     0,     0,     0,   561,   562,   563,   564,   565,
     566,   567,     0,     0,     0,     0,     0,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,   604,   376,   377,   378,
     379,     0,     0,   710,     0,   711,     0,     0,   376,   377,
     378,   379,     0,     0,   888,     0,   889,     0,     0,     0,
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
     159,   160,     0,   161,     0,   162,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,   173,     0,     0,    93,   222,     0,     0,    96,     0,
       0,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   774,     0,     0,   775,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,   109,     0,     0,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,     0,    93,   459,     0,     0,
      96,   376,   377,   378,   379,   130,   131,   132,   819,   821,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,    98,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,     0,   161,     0,
     162,     0,     0,   164,   165,   166,     0,   168,   836,   170,
       0,     0,     0,     0,     0,     0,   183,   529,     0,     0,
       0,     0,     0,    93,     0,   838,   839,    96,   376,   377,
     378,   379,     0,   840,   910,     0,   911,   842,     0,     0,
       0,     0,   846,     0,     0,   848,   849,     0,    98,     0,
       0,   108,     0,   109,   376,   377,   378,   379,     0,     0,
       0,     0,   414,     0,     0,     0,     0,     0,   863,     0,
     864,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,   880,   881,   882,   149,   150,   151,     0,
       0,   154,     0,   156,     0,   158,     0,     0,   160,     0,
     161,     0,   162,     0,     0,   164,   165,   166,   108,   168,
     109,   170,     0,     0,     0,     0,   367,   368,   183,   531,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,   391,   140,     0,   142,   143,   144,     0,
       0,     0,     0,   149,   150,   151,     0,     0,   154,     0,
     156,     0,   158,     0,   951,   160,     0,   161,     0,   162,
       0,     0,   164,   165,   166,     0,   168,     0,   170,     0,
       0,     0,     0,     0,     0,   183,   533,   965,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,     0,
       0,     0,   968,     0,     0,     0,     0,     0,     0,     0,
       0,   971,     0,     0,   973,     0,     0,   974,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
     984,     0,     0,     0,   428,     0,     0,     0,     0,   990,
     991,   992,   993,   994,     0,   996,     0,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,   645,  1036,   100,   101,   102,   103,
    1040,  1041,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,     0,   367,   368,     0,   220,   369,
     370,   371,   372,   373,   374,   375,   221,     0,     0,     0,
     106,   107,  1064,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,     0,   161,     0,   162,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,    91,    92,
      93,   173,    94,    95,    96,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   627,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   367,   368,   105,     0,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,   478,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,     0,   161,     0,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,    91,
      92,    93,   173,    94,    95,    96,   222,     0,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,     0,     0,
     666,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   367,   368,   105,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,     0,   161,     0,   162,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
      91,    92,    93,   173,    94,    95,    96,   222,     0,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,     0,
       0,   667,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   367,   368,   105,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,     0,   161,     0,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,     0,     0,     0,   173,   444,    91,    92,    93,     0,
      94,    95,    96,     0,   376,   377,   378,   379,     0,     0,
       0,     0,   668,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     367,   368,   105,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,     0,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     173,   508,    91,    92,    93,     0,    94,    95,    96,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   105,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,     0,   161,     0,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,   173,   518,    91,    92,
      93,     0,    94,    95,    96,     0,   234,     0,     0,   376,
     377,   378,   379,     0,     0,     0,     0,   701,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   367,   368,   105,     0,   369,   370,   371,   372,
     373,   374,   375,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,     0,   161,     0,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     0,    91,
      92,    93,   173,    94,    95,    96,     0,     0,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,     0,     0,
     708,     0,     0,     0,     0,    97,    98,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   367,   368,   105,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,     0,   161,     0,   162,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
      91,    92,    93,   173,    94,    95,    96,     0,   436,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,     0,
       0,   709,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   367,   368,   105,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,     0,   161,     0,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
       0,    91,    92,    93,   173,    94,    95,    96,     0,     0,
       0,     0,     0,     0,   376,   377,   378,   379,     0,     0,
       0,     0,   768,     0,     0,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   367,   368,   105,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,    93,   161,     0,   162,
      96,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,    98,     0,     0,     0,   376,   377,   378,   379,     0,
       0,     0,     0,   789,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,   108,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,    96,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,    98,     0,     0,   149,   150,   151,   820,
       0,   154,     0,   156,     0,   158,     0,   108,   160,   109,
     161,     0,   162,     0,     0,   164,   165,   166,     0,   168,
       0,   170,     0,     0,     0,     0,    93,     0,   183,     0,
      96,     0,     0,   130,   131,   132,     0,     0,     0,   136,
     137,   138,     0,   140,     0,   142,   143,   144,     0,     0,
       0,    98,   149,   150,   151,     0,     0,   154,     0,   156,
       0,   158,     0,   108,   160,   109,   161,     0,   162,     0,
       0,   164,   165,   166,     0,   168,     0,   170,     0,     0,
       0,     0,     0,     0,   183,     0,     0,     0,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,     0,   140,
       0,   142,   143,   144,     0,     0,     0,     0,   149,   150,
     151,     0,     0,   154,     0,   156,     0,   158,     0,     0,
     160,   108,   161,   109,   162,     0,     0,   164,   165,   166,
       0,   168,     0,   170,     0,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,     0,     0,     0,   149,   150,   151,     0,
       0,   154,     0,   156,     0,   158,     0,     0,   160,     0,
     161,     0,   162,     0,     0,   164,   165,   166,     0,   168,
       0,   170,     0,     1,     2,     3,     0,     0,   773,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,    11,  -307,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,     0,     0,     0,     0,
      23,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,  -110,  -110,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,  -110,     0,
      49,     0,    50,    51,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,     1,     2,     3,    58,
       0,    59,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     8,     9,    10,    11,  -307,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,     0,
       0,     0,     0,    23,    -6,    -6,    24,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,    29,    30,     0,
       0,     0,    31,    32,   376,   377,   378,   379,     0,     0,
       0,     0,   790,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    39,    40,    41,     0,
       0,    42,    43,    44,     0,    45,    46,    47,     0,     0,
      48,     0,     0,    49,     0,    50,    51,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,    57,     0,     1,
       2,     3,    58,     0,    59,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,    11,  -307,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    -6,     0,     0,     0,    23,    -6,     0,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,   376,   377,   378,
     379,     0,     0,     0,     0,   797,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,     0,     0,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,     0,     0,    49,     0,    50,    51,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,   367,   368,     0,    55,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      57,     0,     0,     0,     0,    58,     0,    59,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,   367,   368,     0,   800,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
     367,   368,     0,   801,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,     0,     0,   861,     0,     0,   376,
     377,   378,   379,     0,     0,     0,     0,   866,     0,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   877,     0,
       0,   376,   377,   378,   379,     0,   367,   368,     0,   924,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
     367,   368,     0,   925,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,     0,     0,   953,     0,
       0,   376,   377,   378,   379,     0,   367,   368,     0,   958,
     369,   370,   371,   372,   373,   374,   375,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,   367,   368,
       0,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
       0,   367,   368,     0,  1004,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,   367,   368,     0,  1019,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,     0,     0,  1057,     0,     0,   376,   377,   378,
     379,     0,     0,   682,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,   683,     0,     0,     0,     0,   376,
     377,   378,   379,   367,   368,   684,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   685,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   686,     0,     0,     0,     0,   376,   377,   378,   379,
     367,   368,   689,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,   367,   368,     0,     0,   369,   370,   371,   372,
     373,   374,   375,   367,   368,     0,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   692,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,   367,
     368,   693,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,   695,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,   696,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,   697,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   698,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   699,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,     0,     0,   700,     0,     0,     0,     0,
     376,   377,   378,   379,   367,   368,   702,     0,   369,   370,
     371,   372,   373,   374,   375,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   712,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   713,     0,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,   376,   377,   378,   379,     0,     0,
     715,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   718,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,   772,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   869,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   886,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   887,     0,     0,     0,     0,   376,   377,   378,   379,
     367,   368,   894,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,   367,   368,     0,     0,   369,   370,   371,   372,
     373,   374,   375,   367,   368,     0,     0,   369,   370,   371,
     372,   373,   374,   375,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   895,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,   367,
     368,   896,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,   901,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,   902,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,   905,     0,
       0,     0,     0,   376,   377,   378,   379,   367,   368,   906,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,   367,
     368,   907,     0,   369,   370,   371,   372,   373,   374,   375,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,     0,     0,   908,     0,     0,     0,     0,
     376,   377,   378,   379,   367,   368,   909,     0,   369,   370,
     371,   372,   373,   374,   375,   367,   368,     0,     0,   369,
     370,   371,   372,   373,   374,   375,   367,   368,     0,     0,
     369,   370,   371,   372,   373,   374,   375,   367,   368,     0,
       0,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   912,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,   376,
     377,   378,   379,   367,   368,   913,     0,   369,   370,   371,
     372,   373,   374,   375,   367,   368,     0,     0,   369,   370,
     371,   372,   373,   374,   375,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,   377,   378,   379,     0,     0,
     916,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,   922,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,   939,     0,     0,     0,     0,   376,   377,   378,
     379,   367,   368,   981,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,   367,   368,   985,     0,   369,
     370,   371,   372,   373,   374,   375,     0,     0,     0,     0,
       0,     0,     0,   376,   377,   378,   379,     0,     0,   995,
       0,     0,     0,     0,   376,   377,   378,   379,   367,   368,
    1005,     0,   369,   370,   371,   372,   373,   374,   375,   367,
     368,     0,     0,   369,   370,   371,   372,   373,   374,   375,
     367,   368,     0,     0,   369,   370,   371,   372,   373,   374,
     375,   367,   368,     0,     0,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,  1007,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,   378,   379,     0,
       0,  1008,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,   377,
     378,   379,     0,     0,  1010,     0,     0,     0,     0,   376,
     377,   378,   379,     0,     0,  1045,     0,     0,     0,     0,
     376,   377,   378,   379,     0,     0,  1056,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,  1075
};

static const yytype_int16 yycheck[] =
{
      11,     0,   290,     0,    85,    11,    41,    42,    34,   250,
     251,     9,    10,    24,     4,    11,    27,     7,    82,    30,
      31,    32,    10,    72,   177,    36,    37,    38,     4,     4,
       5,     7,    57,    57,    45,    59,    60,    35,     3,   178,
     173,   180,     7,     8,     9,   178,    57,    15,    47,    71,
      47,    37,    38,    71,     3,   778,   779,    11,     7,     8,
       9,    66,    67,    68,    69,    70,    71,   177,    79,    72,
     173,    57,    11,    84,    24,    43,     7,   180,    66,    67,
      68,    69,    70,    71,   254,   255,    85,   173,    85,    12,
      27,   102,   178,    43,    87,    88,    66,    67,    68,    69,
      70,    71,   173,   178,   173,   180,    99,   178,    62,    63,
     191,   180,    66,    67,    68,    69,    70,    71,    72,     4,
       5,   185,   186,    62,    63,   174,   175,    66,    67,    68,
      69,    70,    71,    72,    69,    70,    71,    72,     4,    62,
      63,     7,    83,    66,    67,    68,    69,    70,    71,    72,
      90,   126,   127,   128,   177,   177,   181,   181,   173,   177,
     105,   172,   173,   178,   178,   180,   180,   173,   173,   172,
     173,   174,   175,   178,   180,   180,   178,   177,   180,   190,
       0,   351,   177,   353,   180,   173,   197,   177,   214,   215,
     173,    71,   191,   173,   191,   178,   437,   180,   178,   234,
     180,   177,    43,   173,   177,   240,   241,   172,   173,   220,
     180,   222,   453,   454,   177,   279,   280,    71,   172,   173,
     174,   175,   945,   172,   173,   948,   180,   178,    23,   180,
     265,   266,   267,   172,   173,   174,   175,   172,   173,   174,
     175,   173,    45,    34,    35,   256,   178,   488,   180,   172,
     173,   174,   175,   173,   173,     4,   291,   268,   178,    62,
      63,   180,   273,    66,    67,    68,    69,    70,    71,    72,
       4,     5,   283,   284,   177,   286,   287,   288,   342,   343,
     177,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   287,   288,   177,   173,   177,   317,   318,   319,   320,
     321,   180,   323,    45,   325,   396,  1039,   303,    70,    71,
      72,   173,    58,   179,   180,   173,   178,   177,   180,   340,
      62,    63,   180,   177,    66,    67,    68,    69,    70,    71,
      72,     4,     5,    71,    72,   177,   410,   411,    84,    85,
      86,   415,   416,     5,   340,    91,   177,     9,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   172,
     173,   174,   175,   177,   173,     4,     5,   177,    30,   178,
     173,   180,    19,    20,   465,   178,   397,   180,   173,   173,
     177,   402,   173,   178,   420,   180,   180,   396,   433,   396,
     177,   436,   413,   414,    66,    67,    68,    69,    70,    71,
     177,   173,   173,     4,     5,   426,   178,   428,   180,   180,
     172,   173,   174,   175,   177,    62,    63,   438,   439,    66,
      67,    68,    69,    70,    71,    72,   447,   448,     4,     5,
     172,   173,   174,   175,   172,   173,   174,   175,   100,   173,
     102,   177,   451,   173,   451,   743,   180,   468,   746,   173,
     180,   177,   173,   173,   178,   173,   465,   178,   465,    13,
     180,    15,   180,    17,   126,   127,   128,   177,   173,   177,
     132,   133,   134,   173,   136,   180,   138,   139,   140,   177,
     180,   177,   173,   145,   146,   147,    40,   178,   150,    43,
     152,   173,   154,   173,    48,   157,   177,   159,   180,   161,
     180,   173,   164,   165,   166,    57,   168,   173,   170,   583,
     584,   180,   586,   587,   180,   177,   178,   173,   177,    50,
      81,    82,   173,   173,   180,   172,   173,   174,   175,   180,
     180,    62,    63,     4,     5,    66,    67,    68,    69,    70,
      71,    72,    66,    67,    68,    69,    70,    71,   177,   570,
     571,    13,   177,    15,     3,    17,   177,   808,     7,     8,
     568,   569,    48,    49,    62,    63,   177,   641,    66,    67,
      68,    69,    70,    71,    72,   173,   827,   177,    40,   173,
     178,    43,   603,   180,   178,   177,    48,   177,   609,   610,
      62,    63,   613,   638,    66,    67,    68,    69,    70,    71,
      72,   180,   173,   173,   173,   177,   627,   178,   178,   178,
     655,   656,    66,    67,    68,    69,    70,    71,     4,     5,
      62,   642,   643,   644,    66,    67,    68,    69,    70,    71,
      72,   177,   173,   654,    13,   680,    15,   178,    17,   660,
     661,   172,   173,   174,   175,   666,   667,   668,   177,   173,
     177,    13,   177,    15,   178,    17,   177,   678,   679,   177,
     681,    40,   177,   173,    43,   177,   173,   688,   178,    48,
     691,   178,   177,   764,   172,   173,   174,   175,    40,   180,
     701,    43,   180,   704,   705,   706,    48,   708,   709,   173,
     173,   180,   173,   173,   178,   178,   717,   178,   178,   173,
     172,   173,   174,   175,   178,   173,   178,   173,   180,     5,
     178,   180,   178,   787,   788,    38,    39,   173,   739,   173,
     741,   742,   178,   173,   178,     4,     5,   180,   178,   173,
     172,   173,   174,   175,   178,   173,   173,   173,   173,    42,
     178,   178,   178,   178,    62,    63,   177,   768,    66,    67,
      68,    69,    70,    71,    72,   764,   177,   764,    66,    67,
      68,    69,    70,    71,    72,   173,   173,   177,   789,   790,
     178,   178,    15,   794,   795,    18,    59,    60,   177,   800,
     801,   177,   177,   177,    27,   806,   177,   177,    31,    32,
     177,    71,   177,    36,   177,   177,   870,   871,   794,   795,
     177,   177,   177,   177,   177,    48,    49,    50,    67,    68,
      69,    70,    71,    72,    57,    58,    59,   177,   177,   177,
     177,    62,    63,   177,   177,    66,    67,    68,    69,    70,
      71,    72,   177,   177,   177,   856,   177,   177,    81,   177,
     861,   177,   850,   851,   177,   866,   891,   177,   177,   177,
     177,   177,   177,   177,   172,   173,   174,   175,   177,    72,
     178,   177,   180,   177,   172,   173,   174,   175,   889,   178,
     180,   178,   893,   178,   178,   177,   177,   177,   177,    42,
      45,   178,   180,   904,   975,   976,   178,   177,   177,    67,
     911,    69,    70,    71,    72,     9,   177,   918,   180,   920,
      42,   177,   180,   180,   925,   180,   180,   178,   178,   178,
      80,   178,   180,   172,   173,   174,   175,   177,   180,   180,
     941,   178,   178,   178,   178,  1016,   178,   178,   178,   178,
     173,   172,   173,   174,   175,   177,  1027,   178,   177,  1030,
     183,   178,   178,    80,   178,   178,     5,   190,   180,   180,
     178,   178,   178,   178,   197,  1046,   977,    57,   177,   177,
     180,   178,   177,    42,   178,    37,   975,   976,   975,   976,
     178,    42,   177,    71,   178,   178,    71,    71,   221,    47,
    1001,    57,   178,  1004,   178,   177,   177,   177,   231,    46,
     177,    71,   178,   178,   172,   173,   174,   175,  1019,  1020,
      37,     4,    47,  1024,   451,    47,   290,  1016,   420,  1016,
     585,   660,  1000,   856,   257,   588,  1073,   417,  1027,   776,
    1027,  1030,    -1,  1030,   430,  1022,   269,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,  1057,  1046,    -1,  1046,
      -1,    -1,    -1,    -1,   287,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,   312,
     313,   314,   315,   316,    -1,    -1,    -1,    -1,    -1,   322,
      -1,   324,    -1,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    -1,
      -1,   344,   345,   346,   347,    -1,    -1,   350,    -1,   352,
      -1,   354,    -1,    -1,    -1,   358,   359,   360,   361,   362,
     363,   364,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,   399,   172,   173,   174,
     175,    -1,    -1,   178,    -1,   180,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,    -1,   180,    -1,    -1,    -1,
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
     156,   157,    -1,   159,    -1,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,    -1,    -1,     5,   181,    -1,    -1,     9,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,     5,   660,    -1,    -1,
       9,   172,   173,   174,   175,   126,   127,   128,   671,   672,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    30,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    -1,   164,   165,   166,    -1,   168,   711,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,    -1,    -1,
      -1,    -1,    -1,     5,    -1,   728,   729,     9,   172,   173,
     174,   175,    -1,   736,   178,    -1,   180,   740,    -1,    -1,
      -1,    -1,   745,    -1,    -1,   748,   749,    -1,    30,    -1,
      -1,   100,    -1,   102,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,   771,    -1,
     773,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,   796,   797,   798,   145,   146,   147,    -1,
      -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,   164,   165,   166,   100,   168,
     102,   170,    -1,    -1,    -1,    -1,    62,    63,   177,   178,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,   856,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,   877,   157,    -1,   159,    -1,   161,
      -1,    -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   900,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   924,    -1,    -1,   927,    -1,    -1,   930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
     943,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,   952,
     953,   954,   955,   956,    -1,   958,    -1,     3,     4,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,  1018,    62,    63,    64,    65,
    1023,  1024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    62,    63,    -1,    84,    66,
      67,    68,    69,    70,    71,    72,    92,    -1,    -1,    -1,
      96,    97,  1055,    -1,   100,    -1,   102,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,    -1,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,     3,     4,
       5,   177,     7,     8,     9,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    62,    63,    79,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,    -1,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,     3,
       4,     5,   177,     7,     8,     9,   181,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
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
     154,    -1,   156,   157,    -1,   159,    -1,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
       3,     4,     5,   177,     7,     8,     9,   181,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
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
     153,   154,    -1,   156,   157,    -1,   159,    -1,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,   177,   178,     3,     4,     5,    -1,
       7,     8,     9,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     157,    -1,   159,    -1,   161,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
     177,   178,     3,     4,     5,    -1,     7,     8,     9,    -1,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,    -1,
     161,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,   177,   178,     3,     4,
       5,    -1,     7,     8,     9,    -1,    11,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
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
      -1,   156,   157,    -1,   159,    -1,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,     3,
       4,     5,   177,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
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
     154,    -1,   156,   157,    -1,   159,    -1,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
       3,     4,     5,   177,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
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
     153,   154,    -1,   156,   157,    -1,   159,    -1,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,     3,     4,     5,   177,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    62,    63,    79,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,     5,   159,    -1,   161,
       9,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,    30,    -1,    -1,   145,   146,   147,    92,
      -1,   150,    -1,   152,    -1,   154,    -1,   100,   157,   102,
     159,    -1,   161,    -1,    -1,   164,   165,   166,    -1,   168,
      -1,   170,    -1,    -1,    -1,    -1,     5,    -1,   177,    -1,
       9,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    30,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,   154,    -1,   100,   157,   102,   159,    -1,   161,    -1,
      -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,
     157,   100,   159,   102,   161,    -1,    -1,   164,   165,   166,
      -1,   168,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,   164,   165,   166,    -1,   168,
      -1,   170,    -1,     4,     5,     6,    -1,    -1,   177,    10,
      -1,    -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
     101,    -1,   103,   104,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,    -1,     4,     5,     6,   160,
      -1,   162,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    60,    61,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,
      -1,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    -1,    -1,   101,    -1,   103,   104,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,    -1,     4,
       5,     6,   160,    -1,   162,    10,    -1,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    60,    61,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    -1,    -1,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    -1,    -1,   101,    -1,   103,   104,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    62,    63,    -1,   133,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    62,    63,    -1,   180,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      62,    63,    -1,   180,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,   172,   173,   174,   175,    -1,    62,    63,    -1,   180,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      62,    63,    -1,   180,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,   172,   173,   174,   175,    -1,    62,    63,    -1,   180,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    62,    63,    -1,   180,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    62,    63,    -1,   180,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,   172,   173,   174,
     175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    62,    63,   178,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      62,    63,   178,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    62,    63,   178,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    62,    63,   178,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    62,    63,   178,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
     178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      62,    63,   178,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    62,    63,   178,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    62,    63,   178,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    62,    63,   178,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
     178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,    63,
     178,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178
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
     103,   104,   126,   127,   128,   133,   151,   155,   160,   162,
     183,   184,   186,   193,   194,   196,   197,   201,   213,   214,
     219,   225,   232,   240,   248,   251,   255,   258,   264,    71,
     177,    71,   177,   233,   252,   256,     4,     7,   211,   211,
     211,     3,     4,     5,     7,     8,     9,    29,    30,    33,
      62,    63,    64,    65,    76,    79,    96,    97,   100,   102,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   156,
     157,   159,   161,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   177,   199,   200,   202,   208,   210,   213,
     214,   187,   188,   177,   199,   177,   177,   199,    27,     7,
     241,   249,   202,    57,    59,    60,   181,   287,   191,   199,
     202,     4,     5,   212,   202,   199,   202,   199,   202,     4,
       5,   275,   276,     9,   172,   173,   209,   210,   277,   211,
      84,    92,   181,   199,   202,   288,    84,    92,   105,   288,
     288,    83,   202,   207,    11,    52,   207,   207,    58,    84,
      85,    86,    91,    90,   202,   194,   201,   213,   214,   199,
     199,   199,   105,   177,   177,   177,   177,   177,   199,   288,
     199,   199,     0,    43,   185,    87,    88,    99,    71,    71,
      23,   202,   215,   216,   199,   215,     4,   202,   184,   177,
     177,    34,    35,   177,   177,   202,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   202,   199,   202,    66,    67,
      68,    69,    70,    71,   173,    19,    20,    62,    63,    66,
      67,    68,    69,    70,    71,    72,   172,   173,   174,   175,
       4,     5,   226,   227,     4,     5,   228,   229,   199,   215,
     215,   199,   202,   243,   184,   259,   265,   177,    57,   177,
       4,     7,   177,   199,   202,   278,    57,   181,   280,   285,
     177,   177,   180,   180,   180,   177,   177,   180,   210,   210,
     180,   202,   199,   202,    10,   180,   180,   199,   180,   207,
     192,    11,   180,   195,   180,   207,    11,   207,   195,   195,
       5,   198,   198,   198,   178,   202,   199,   180,   180,   180,
     180,    42,   207,   207,   207,   202,   199,   220,   178,   199,
     202,   217,   218,   178,    71,   253,    13,    15,    17,    40,
      43,    48,   257,   215,   215,   202,   202,   202,    92,   199,
     288,   288,     4,     5,   205,   206,   205,   206,   207,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     288,   202,   202,   202,   202,   202,   202,   202,   178,   202,
     199,   199,   199,   199,   199,   202,   202,   202,   178,   202,
     202,   199,   202,   199,   202,   199,   199,   178,   199,   178,
     199,   178,   199,   178,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   288,   199,   215,   215,   199,   199,
     199,   199,   178,   178,   199,   198,   199,   198,   199,   178,
     178,   199,   199,   199,   199,   199,   199,   199,   189,   190,
     204,   203,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   177,   177,   180,   177,   177,   180,   178,
     178,    42,   242,    13,    15,    17,    40,    43,    48,   250,
      45,   184,   202,   177,   199,   202,    50,   279,   179,   180,
     177,     4,     7,   177,     9,   286,   215,   215,     4,     5,
     202,   202,   215,   215,   276,     9,   209,   180,    81,    82,
      92,   199,   202,   202,   280,   207,   199,   207,   195,   202,
     202,   177,   180,   180,   180,   178,   178,   199,   202,   199,
     202,   199,   199,   186,   180,   195,   195,     4,     5,   224,
     180,   234,   184,   202,   178,   178,   180,   180,   180,   178,
     178,   180,   180,   178,   177,   177,   178,   178,   180,   180,
     195,   180,   178,   178,   178,   178,   178,   178,   180,   178,
     178,   180,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   180,   178,   178,   180,   180,   180,   178,   180,   180,
     178,   180,   178,   178,   178,   178,   178,   180,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   180,   180,
     178,   178,   178,   178,   178,   178,   180,   178,   178,   180,
     180,   180,   180,   180,   178,   180,   180,   178,   180,   180,
     211,   289,   211,   290,   202,   202,   215,   215,   227,   215,
     215,   229,    42,   244,   260,    48,    49,   266,   180,   202,
     178,   180,   178,   177,   199,   199,   202,   202,   281,   282,
     202,     4,     5,   272,   274,   178,   178,   177,   177,   180,
     180,   178,   178,   202,    80,    80,   180,   180,   180,   207,
     180,   180,   215,   202,   202,   202,   180,   202,   207,   207,
     221,   218,   202,    15,    43,   254,   202,   202,   202,   199,
      92,   199,   178,   178,   202,   202,   207,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   199,   202,   199,   199,
     199,   202,   199,   202,   202,   206,   199,   206,   199,   199,
     180,   180,   178,   178,   178,   178,    38,    39,   246,   184,
     202,   180,    57,   199,   199,   279,   180,   272,   272,   178,
     177,   177,   180,   215,   215,   202,   202,   180,   288,   288,
     199,   199,   199,   202,   202,   178,   178,   178,   178,   180,
     202,   195,   177,    11,   178,   178,   178,   178,   178,   178,
     180,   178,   178,   178,   195,   178,   178,   178,   178,   178,
     178,   180,   178,   178,   178,   180,   178,   178,   180,   178,
     180,   178,   178,   178,   180,   180,   178,   180,   178,   178,
     180,   178,   178,   211,   211,   243,    42,    37,   261,   178,
     202,   177,   178,   180,   202,   283,   215,   215,   273,   178,
     178,   199,   180,   180,    71,    71,    71,   202,   180,   207,
       4,     5,   230,   231,   202,   199,   202,   202,   199,   202,
     202,   199,   202,   199,   199,   245,   247,    47,   268,    59,
      60,   178,   202,    57,   199,   178,   272,   178,   178,   272,
     199,   199,   199,   199,   199,   178,   199,   177,   177,   178,
     180,    12,   238,   178,   180,   178,   178,   178,   178,   178,
     178,   178,   178,   184,   184,   202,    46,   267,   177,   180,
     177,   178,   284,    71,   180,   178,   178,   222,   231,   202,
     235,   202,    45,   271,   184,   262,   199,   202,   202,   286,
     199,   199,   202,   184,   184,   178,   269,    13,    15,    17,
      40,    43,    48,   263,   178,   180,   178,   180,   272,    24,
      43,   223,   236,   184,   199,   202,    13,    15,    17,    40,
      43,    48,   237,   270,   178,   178,     4,   239,   268
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   182,   183,   184,   185,   184,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   187,   186,   188,   186,   186,   186,
     186,   186,   186,   186,   189,   186,   190,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   191,   186,
     192,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     193,   193,   193,   193,   193,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   196,   196,   196,   197,   197,
     198,   198,   199,   199,   199,   199,   199,   199,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   201,   201,   203,   202,   204,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   205,   206,   207,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   210,   210,   210,   211,   211,   212,   212,   212,   212,
     213,   214,   216,   215,   217,   217,   217,   218,   218,   220,
     221,   222,   219,   223,   223,   224,   224,   225,   225,   225,
     225,   226,   226,   227,   227,   227,   227,   228,   228,   229,
     229,   229,   229,   230,   230,   230,   231,   231,   231,   231,
     233,   234,   235,   236,   232,   237,   237,   237,   237,   237,
     237,   238,   238,   239,   239,   241,   240,   242,   242,   243,
     243,   244,   245,   244,   246,   247,   246,   249,   248,   250,
     250,   250,   250,   250,   250,   252,   253,   251,   254,   254,
     256,   255,   257,   257,   257,   257,   257,   257,   259,   260,
     261,   262,   258,   263,   263,   263,   263,   263,   263,   265,
     264,   266,   266,   267,   267,   268,   269,   270,   268,   271,
     271,   272,   273,   272,   274,   274,   274,   274,   275,   275,
     276,   276,   276,   276,   277,   277,   277,   277,   278,   278,
     278,   278,   278,   279,   279,   279,   281,   280,   282,   280,
     283,   280,   284,   280,   285,   280,   286,   286,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   288,   288,   289,   289,   290,   290
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

    {add_command(cFRNBF_FREE,NULL,NULL);}

    break;

  case 108:

    {add_command(cFRNBF_SET_NUMBER, NULL, NULL);}

    break;

  case 109:

    {add_command(cFRNBF_SET_STRING, NULL, NULL);}

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

    {create_function(fFRNFN_CALL2);}

    break;

  case 157:

    {create_function(fFRNBF_NEW);}

    break;

  case 158:

    {create_function(fFRNBF_DUMP);}

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

    {create_function(fFRNBF_GET_STRING);}

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

    {create_function(fFRNFN_CALL);}

    break;

  case 248:

    {create_function(fFRNBF_GET_NUMBER);}

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
