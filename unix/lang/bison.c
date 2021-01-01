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
    written by Marc Ihm 1995-2020
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
    tBINDIGITS = 264,
    tSTRING = 265,
    tFOR = 266,
    tTO = 267,
    tSTEP = 268,
    tNEXT = 269,
    tWHILE = 270,
    tWEND = 271,
    tREPEAT = 272,
    tUNTIL = 273,
    tIMPORT = 274,
    tGOTO = 275,
    tGOSUB = 276,
    tLABEL = 277,
    tON = 278,
    tSUB = 279,
    tENDSUB = 280,
    tLOCAL = 281,
    tSTATIC = 282,
    tEXPORT = 283,
    tERROR = 284,
    tEXECUTE = 285,
    tEXECUTE2 = 286,
    tCOMPILE = 287,
    tRUNTIME_CREATED_SUB = 288,
    tINTERRUPT = 289,
    tBREAK = 290,
    tCONTINUE = 291,
    tSWITCH = 292,
    tSEND = 293,
    tCASE = 294,
    tDEFAULT = 295,
    tLOOP = 296,
    tDO = 297,
    tSEP = 298,
    tEOPROG = 299,
    tIF = 300,
    tTHEN = 301,
    tELSE = 302,
    tELSIF = 303,
    tENDIF = 304,
    tIMPLICITENDIF = 305,
    tUSING = 306,
    tPRINT = 307,
    tINPUT = 308,
    tRETURN = 309,
    tDIM = 310,
    tEND = 311,
    tEXIT = 312,
    tAT = 313,
    tSCREEN = 314,
    tREVERSE = 315,
    tCOLOUR = 316,
    tBACKCOLOUR = 317,
    tAND = 318,
    tOR = 319,
    tNOT = 320,
    tBITNOT = 321,
    tEOR = 322,
    tSHL = 323,
    tSHR = 324,
    tNEQ = 325,
    tLEQ = 326,
    tGEQ = 327,
    tLTN = 328,
    tGTN = 329,
    tEQU = 330,
    tPOW = 331,
    tREAD = 332,
    tDATA = 333,
    tRESTORE = 334,
    tOPEN = 335,
    tCLOSE = 336,
    tSEEK = 337,
    tTELL = 338,
    tAS = 339,
    tREADING = 340,
    tWRITING = 341,
    tORIGIN = 342,
    tWINDOW = 343,
    tDOT = 344,
    tLINE = 345,
    tCIRCLE = 346,
    tTRIANGLE = 347,
    tTEXT = 348,
    tCLEAR = 349,
    tFILL = 350,
    tPRINTER = 351,
    tWAIT = 352,
    tBELL = 353,
    tLET = 354,
    tARDIM = 355,
    tARSIZE = 356,
    tBIND = 357,
    tRECT = 358,
    tGETBIT = 359,
    tPUTBIT = 360,
    tGETCHAR = 361,
    tPUTCHAR = 362,
    tNEW = 363,
    tCURVE = 364,
    tSIN = 365,
    tASIN = 366,
    tCOS = 367,
    tACOS = 368,
    tTAN = 369,
    tATAN = 370,
    tEXP = 371,
    tLOG = 372,
    tSQRT = 373,
    tSQR = 374,
    tMYEOF = 375,
    tABS = 376,
    tSIG = 377,
    tINT = 378,
    tCEIL = 379,
    tFLOOR = 380,
    tFRAC = 381,
    tROUND = 382,
    tMOD = 383,
    tRAN = 384,
    tVAL = 385,
    tLEFT = 386,
    tRIGHT = 387,
    tMID = 388,
    tLEN = 389,
    tMIN = 390,
    tMAX = 391,
    tSTR = 392,
    tINKEY = 393,
    tCHR = 394,
    tASC = 395,
    tHEX = 396,
    tDEC = 397,
    tBIN = 398,
    tUPPER = 399,
    tLOWER = 400,
    tMOUSEX = 401,
    tMOUSEY = 402,
    tMOUSEB = 403,
    tMOUSEMOD = 404,
    tTRIM = 405,
    tLTRIM = 406,
    tRTRIM = 407,
    tINSTR = 408,
    tRINSTR = 409,
    tCHOMP = 410,
    tSYSTEM = 411,
    tSYSTEM2 = 412,
    tPEEK = 413,
    tPEEK2 = 414,
    tPOKE = 415,
    tFRNFN_CALL = 416,
    tFRNFN_CALL2 = 417,
    tFRNFN_SIZE = 418,
    tFRNBF_ALLOC = 419,
    tFRNBF_FREE = 420,
    tFRNBF_SIZE = 421,
    tFRNBF_DUMP = 422,
    tFRNBF_SET = 423,
    tFRNBF_GET = 424,
    tFRNBF_GET2 = 425,
    tFRNBF_GET_BUFFER = 426,
    tFRNBF_SET_BUFFER = 427,
    tDATE = 428,
    tTIME = 429,
    tTOKEN = 430,
    tTOKENALT = 431,
    tSPLIT = 432,
    tSPLITALT = 433,
    tGLOB = 434,
    tSTART_PROGRAM = 435,
    tSTART_EXPRESSION = 436,
    tSTART_STRING_EXPRESSION = 437,
    tSTART_STATEMENT_LIST = 438,
    tSTART_FUNCTION_DEFINITION = 439,
    tEVAL = 440,
    tEVAL2 = 441,
    UMINUS = 442
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
#define YYFINAL  193
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  476
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   442

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   196,     2,     2,     2,     2,
     192,   193,   189,   188,   195,   187,     2,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   194,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   191
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   191,   192,   193,   194,   197,   200,   201,
     201,   205,   206,   207,   208,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   226,   227,   227,   228,   229,   230,   231,   232,   233,
     234,   234,   236,   236,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   249,   250,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   267,   268,
     269,   270,   271,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   322,   323,
     324,   325,   326,   330,   331,   332,   333,   334,   335,   338,
     339,   342,   343,   344,   345,   346,   349,   350,   353,   354,
     357,   358,   359,   360,   361,   362,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   407,   408,   411,   411,
     412,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   445,   448,   451,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   527,   528,   529,   532,
     533,   534,   535,   538,   539,   542,   543,   544,   545,   548,
     551,   554,   554,   557,   558,   559,   562,   563,   566,   567,
     570,   566,   575,   576,   579,   580,   583,   584,   585,   586,
     589,   590,   593,   594,   595,   596,   599,   600,   603,   604,
     605,   606,   609,   610,   611,   614,   615,   616,   617,   620,
     621,   626,   641,   620,   646,   647,   648,   649,   650,   651,
     654,   655,   658,   659,   664,   664,   668,   669,   672,   673,
     677,   679,   678,   683,   684,   684,   688,   688,   694,   695,
     696,   697,   698,   699,   703,   704,   703,   710,   711,   715,
     715,   720,   721,   722,   723,   724,   725,   728,   729,   729,
     731,   728,   735,   736,   737,   738,   739,   740,   743,   743,
     748,   749,   752,   753,   756,   758,   760,   757,   764,   765,
     768,   769,   769,   772,   773,   775,   776,   780,   781,   784,
     785,   787,   788,   792,   793,   794,   795,   798,   799,   800,
     801,   802,   805,   806,   807,   810,   810,   811,   811,   812,
     812,   813,   813,   814,   814,   817,   818,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   837,   838,   840,   841,   844,   845
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tFNUM", "tSYMBOL", "tSTRSYM", "tDOCU",
  "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING", "tFOR", "tTO", "tSTEP",
  "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tIMPORT", "tGOTO",
  "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB", "tLOCAL", "tSTATIC",
  "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2", "tCOMPILE",
  "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE", "tSWITCH",
  "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP", "tEOPROG", "tIF",
  "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF", "tUSING",
  "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT", "tSCREEN",
  "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT", "tBITNOT",
  "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN", "tEQU",
  "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN", "tCLOSE", "tSEEK",
  "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN", "tWINDOW", "tDOT",
  "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL", "tPRINTER",
  "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE", "tBIND", "tRECT",
  "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tSIN",
  "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT",
  "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC",
  "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN",
  "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN",
  "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM",
  "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2",
  "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE",
  "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_STATEMENT_LIST",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "'('", "')'", "';'", "','", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1",
  "assignment", "statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@8", "$@9",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    45,    43,    42,
      47,   442,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -819

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-819)))

#define YYTABLE_NINF -398

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     529,  3936,  3269,  3708,    94,     5,    25,   -30,   -28,  -819,
    -819,  -819,  -819,  -819,   115,   115,   115,  2897,  -819,  -819,
    -819,  3708,  -155,   -52,  3708,   133,   180,  -819,  -819,  -819,
    3269,   -31,  -819,  3269,   116,  -819,  3269,  3269,  3269,   285,
      45,   115,  1490,  1181,  1948,   103,  3269,  2711,  3269,   -16,
     113,  3269,  -819,    52,  3708,  3708,  3708,   131,    53,   173,
     190,   210,   224,  1948,  3708,  3708,  3708,  3708,  -819,   175,
    -819,  -819,   -15,  -819,  -819,  -819,  -819,   258,   288,  -819,
     444,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   243,
     267,  -819,  -819,  -819,  -819,   296,   311,   313,   317,  3269,
     346,   368,   378,   397,   413,   429,   447,   451,   468,   470,
     486,   488,   490,   495,   496,   498,   499,   500,   501,   504,
     505,   506,   513,   522,   523,   524,   525,   528,   530,   531,
     541,   542,   543,   544,   545,   548,   551,   552,   559,   562,
     563,   564,   568,   575,   576,   577,   578,   580,   581,   582,
     585,   586,   590,   603,   605,   606,   615,   619,   620,   621,
     623,   624,   625,   626,   630,   631,   632,   633,   634,   642,
     646,   647,   650,   651,   652,   655,   656,   657,  3269,  3269,
      30,  -819,  6048,  -819,  -819,  -819,  -819,  3708,   192,  -819,
     258,   288,  -819,  -819,  3269,  -819,  3708,  -819,   401,  3269,
    1380,  -819,  -819,  -819,  -819,  -819,   271,    96,   327,   343,
     192,  -819,  -819,   192,  -819,  -819,  3269,  1380,   297,   658,
     477,   661,    12,  3269,   -48,    30,  6048,   663,   664,   534,
    6048,    30,   601,    30,  1642,   667,   668,   557,  -819,  -819,
     508,   508,  -819,  -819,   659,  -819,  3269,  3708,  3269,    10,
    6048,   666,  -819,  -819,  -819,  -819,   678,  3708,  1657,  -819,
    3269,  -819,    14,   679,  -819,  -819,  3269,  3083,  -819,  -819,
    6048,  -819,  -819,   192,     0,     0,  -819,   805,   805,   805,
    2138,  3708,    40,   680,   192,  -149,  -117,   192,  -819,   819,
    3269,  3269,  3269,  3269,  3708,  -819,  -819,  -819,  3269,  3269,
     991,  3269,  3269,  3269,  3269,  1758,  1948,   345,   345,  3269,
    3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    3269,  1948,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    2329,  3708,  3708,  3708,  3708,  3708,  3269,  3269,  3269,  2520,
    3269,  3708,  3269,  3708,  3269,  3708,  3708,   369,  3345,  3448,
    3519,  3708,  3708,  3708,  3708,  3708,  3708,  3708,  3708,  1948,
    3708,  -819,  -819,  3708,  3269,  3708,  3708,  3708,  3708,  3708,
     380,   670,  3708,   805,  3708,   805,  3708,  3708,  3708,   761,
     337,   794,  3708,  3708,  3708,  3708,  3708,  3708,  3708,  -819,
    -819,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    3269,  3269,   -98,  6048,   691,  3269,   192,   694,   813,  6048,
     645,  -819,  -819,  -819,  -819,   697,   707,   705,  -819,   709,
     710,   711,  -819,   714,   716,    30,  6048,   861,   765,   866,
    1380,  3269,   721,  3708,  -819,  -819,  3269,    30,   757,  -135,
     722,    13,  -819,   909,  -819,  -819,   427,  3269,  3269,  -819,
    -819,   285,  -819,  -819,    55,  1962,   192,  6048,   371,  3604,
    3269,   192,  3269,  -819,   -48,  -819,  -819,  3269,  3708,  -819,
    3269,    14,  3269,  3269,   726,   728,   732,   735,  -819,  4630,
     -47,  3269,  3269,  3269,  3269,  1380,   736,    14,    14,  6048,
     192,   598,   739,   740,  2153,  2344,  4644,  2538,  2725,  2911,
     749,   281,   753,   758,   729,   763,   760,   766,   755,   767,
      14,  3097,  4676,  4690,  4704,  4718,  4772,   537,  4786,   865,
    4846,  4860,   770,  4874,  4914,  4928,  4942,  4956,  5002,  5016,
    3982,  -819,  5084,     3,   -63,   -13,    18,    66,  4145,  4159,
     975,  -819,  5098,  5112,    67,  5144,  -102,  5158,   213,   284,
    -819,   290,  -819,   301,  -819,   330,  -819,   334,   341,   344,
     353,    42,    92,   356,   360,   363,   560,   771,   -99,   772,
     773,   364,  5172,   366,   -65,    93,   110,   193,  -819,  -819,
     227,   -46,   238,     7,   248,   375,   381,  -819,  -819,   192,
     192,   192,   192,   192,   192,  -819,  3269,  3269,   820,   105,
     690,   197,   188,    87,  -819,   -32,   -32,   761,   761,  -819,
      30,  6048,   774,  -819,  -819,  -819,  1380,  -819,  -819,  3269,
    -819,  -819,  -819,  -819,   115,   115,  -819,  -819,   327,  -819,
    -819,   343,  -819,  -819,  -819,   913,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,   597,  4176,  3269,   -64,  5186,  3760,
    -819,  -819,  3269,  3269,  -819,  -819,  3269,  -819,   644,   775,
     777,   779,   780,  4208,  4222,   782,   784,  -819,  -819,  -819,
    3269,   889,   894,  -819,   249,  4236,  6048,  -819,  -819,   303,
    -819,  3269,  4250,  4304,  -819,  3269,  3269,  3269,  -819,  -819,
      30,  6048,    30,  6048,  4318,  4378,  -819,  3269,  3269,  3269,
    -819,  -819,  -819,  -819,  -819,  3269,  3269,  -819,  3269,  3269,
    3269,  -819,  -819,  3708,  3656,  -819,   786,   793,  -819,  -819,
    3269,  3269,  3269,  3269,  -819,  -819,  -819,  -819,  -819,  -819,
    3269,  -819,  -819,  3269,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  3269,  -819,  -819,  3269,  3269,  3269,
    -819,  3269,  3269,  -819,  3708,  -819,  -819,  -819,  -819,  -819,
    3269,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  3708,  3708,  -819,  -819,  -819,  -819,  -819,  -819,  3708,
    -819,  -819,  -819,  -819,  -819,  -819,  3269,  3269,  3269,  3269,
     983,  -819,  3708,   983,  -819,  3708,  3708,  -819,  -819,   991,
     377,  3269,  3269,     6,  6048,  -819,   795,  -819,   796,   799,
     800,  -819,   801,   803,  -819,  -819,   618,  1380,  -819,  -819,
    -819,  3269,  4392,   939,  3708,  -819,  3708,   192,    30,   757,
    4406,   644,   644,  5240,   807,   808,  -819,   806,  -819,  -819,
    -819,  -819,  3269,  3269,  -819,  -819,  4446,  1948,  1948,  3708,
    3708,  3708,  -819,  3269,  3269,   809,  5254,  5314,  1085,  3708,
    3708,  6048,    14,  -819,   811,  5328,  5342,  5382,  5396,  5410,
     384,   812,    41,  -819,  -819,  5424,  5470,   818,    63,  5484,
    5552,  5566,  5580,  5612,  1617,  5626,  5640,   151,  5654,   171,
     225,   403,  5708,  4460,  4474,  5722,    15,   404,    27,   405,
     411,  -819,    80,  -819,  -819,  -819,   115,   115,  -819,  -819,
    -819,  -819,  3269,   961,   968,   969,  5782,  3269,   821,   426,
     226,  -819,  3269,  -819,  -819,  -819,  -819,  -819,  -819,   823,
     824,  6048,  6048,  3708,  -819,  -819,   192,   192,   304,  4488,
    6048,  -819,   943,   945,   946,  3269,   309,   192,  3269,   662,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  3708,  -819,
    -819,  -819,  3269,  -819,  -819,  -819,  -819,  -819,  -819,  3269,
    -819,  -819,  -819,  3708,  -819,  -819,  3269,  -819,  3269,  -819,
    -819,  3708,  3269,  -819,  -819,  3708,  -819,  -819,  3708,  -819,
    -819,  3269,  -819,  -819,  -819,  -819,  -819,   966,   609,  5796,
    3269,   964,  3708,  5810,   644,   830,   831,   644,  -819,  -819,
     192,  3708,  3708,  3708,  3708,  3708,  5850,  3269,  -819,   833,
     834,    46,  -819,   432,  4534,  5864,   434,  5878,  5892,   435,
    5938,   436,   448,   391,  1380,  4105,  3269,   980,  -819,   836,
    -819,  4548,   837,   449,  -819,  -819,  -819,  -819,  -819,   192,
     192,   192,   192,   192,   955,  6048,   838,   840,  -819,   662,
    -819,  3269,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    3269,  -819,   969,   997,   512,  1380,  -819,  3708,  3269,  3269,
    -819,   909,  3708,  -819,  -819,  1380,  -819,  5952,  6048,  1380,
    -819,  -819,   969,   867,   235,  6020,  4616,   644,   192,    26,
    -819,   969,  1380,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  3708,  -819,  3269,  -819,  -819,  -819,  -819,   908,   969,
     452,  6034,  -819,  -819,  -819,  -819,  -819,  -819,  1032,   966,
    -819,  -819,  -819,  -819,  -819
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   118,     0,     0,     0,   326,     0,     0,     0,   112,
     349,   384,   389,    17,     0,     0,     0,     0,    30,    32,
     327,     0,     0,     0,     0,   328,    24,    26,   364,   376,
       0,   457,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     2,     9,
      16,     8,     0,    11,    45,    47,    13,    28,    29,    27,
       0,    19,    20,    23,    22,    21,    34,    35,   299,   207,
     140,   300,   301,   302,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,   266,   269,   272,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     3,   220,   201,   206,   142,     0,     4,     5,
       0,     0,     6,     1,     0,   311,     0,   311,     0,     0,
      15,   304,   303,    36,    37,    44,     0,     0,     0,     0,
      18,   311,   311,    48,   329,    25,     0,    15,   408,     0,
     461,     0,     0,   437,   453,    69,    68,     0,     0,    70,
     111,    60,     0,    62,     0,   429,   431,    63,   427,   433,
       0,     0,   434,   296,    64,    66,     0,    96,     0,     0,
     472,     0,    93,    98,    86,    46,     0,     0,     0,    74,
       0,    57,    79,     0,    95,    94,     0,     0,   121,   122,
      99,    12,    14,   113,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,    51,     7,     0,
       0,     0,     0,     0,     0,   318,   311,   311,     0,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   311,   311,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,   313,   123,     0,     0,   385,
       9,    38,    39,    40,    42,   332,   333,    31,   330,   338,
     339,    33,   336,     0,     0,   369,   368,     0,     9,     0,
      15,     0,     0,     0,   458,   459,     0,   440,   442,    52,
       0,     0,    56,   455,   311,   311,     0,     0,     0,   311,
     311,     0,   298,   297,     0,     0,    97,   471,     0,     0,
       0,    73,     0,    78,   453,   130,   129,     0,     0,    75,
       0,    81,     0,     0,   138,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,   187,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     267,     0,   270,     0,   273,     0,   276,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   171,
       0,     0,     0,     0,     0,     0,     0,   145,   221,   215,
     217,   219,   216,   218,   214,   144,     0,     0,   194,   196,
     198,   195,   197,   193,   212,   209,   208,   210,   211,   309,
     316,   317,   312,   314,   310,   350,    15,   396,   394,     0,
     395,   391,   393,   390,     0,     0,   311,   311,     0,   311,
     311,     0,    49,    50,   366,   370,   383,   381,   382,   379,
     378,   380,   377,   398,     9,     0,     0,     0,     0,     0,
     438,    53,    54,     0,   445,   447,     0,   456,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,   435,   436,
       0,     0,     0,   133,   132,   136,   224,    58,    76,    89,
      80,     0,     0,     0,   311,     0,     0,     0,   103,   104,
     105,   106,   107,   108,     0,     0,    10,     0,     0,     0,
     324,   325,   319,   288,   182,     0,     0,   279,     0,     0,
       0,   289,   290,     0,     0,   283,     0,     0,   202,   203,
       0,     0,     0,     0,   225,   226,   227,   228,   229,   230,
       0,   232,   233,     0,   235,   236,   199,   242,   243,   237,
     239,   240,   241,   238,     0,   245,   250,     0,     0,     0,
     249,     0,     0,   150,     0,   155,   156,   251,   180,   252,
       0,   181,   157,   158,   265,   268,   271,   274,   161,   159,
     160,     0,     0,   162,   258,   163,   264,   263,   172,     0,
     259,   164,   260,   165,   262,   166,     0,     0,     0,     0,
       0,   175,     0,     0,   177,     0,     0,   295,   185,   191,
     189,     0,     0,     9,   392,   473,    41,   475,    43,     0,
       0,   331,     0,     0,   337,   367,   373,    15,   410,   411,
     409,     0,     0,   462,     0,   460,     0,   443,   441,   442,
       0,     0,     0,     0,   423,   425,   454,   420,   305,   307,
     311,   311,     0,     0,   430,   432,    71,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,   388,   387,   386,     0,     0,   334,   335,
     340,   341,     0,     0,     0,   399,     0,     0,     0,     0,
       0,   439,     0,   446,   448,   449,   311,   311,   421,     0,
       0,    59,    61,     0,   134,   135,   131,   137,    90,    83,
      84,   139,     0,     0,     0,     0,   116,   117,     0,   342,
     277,   278,   280,   281,   282,   291,   292,   293,     0,   204,
     205,   178,     0,   231,   234,   244,   146,   147,   149,     0,
     247,   248,   151,     0,   253,   254,     0,   256,     0,   173,
     167,     0,     0,   184,   285,     0,   174,   287,     0,   176,
     200,     0,   474,   476,   371,   374,   365,   414,   464,     0,
       0,   463,     0,     0,     0,     0,     0,     0,   306,   308,
      72,     0,     0,     0,     0,     0,     0,     0,    88,   345,
     346,     0,   343,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,    15,   118,     0,   412,   468,     0,
     465,     0,     0,     0,   451,   450,   424,   426,   422,    91,
      82,   126,   127,   125,     0,   115,     0,     0,   320,     0,
     294,     0,   148,   152,   255,   257,   261,   183,   284,   286,
       0,   351,   372,     9,   418,    15,   400,     0,     0,     0,
     444,   455,     0,   347,   348,    15,   344,     0,   361,    15,
     419,   415,   413,     0,     0,     0,     0,     0,   124,     9,
     179,   352,    15,   407,   404,   405,   406,   402,   403,   401,
     469,     0,   466,     0,   452,   323,   322,   321,     0,   416,
       0,     0,   355,   357,   358,   359,   354,   356,   362,   414,
     470,   467,   363,   353,   417
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -819,  -819,  -819,  -199,  -819,  1033,   555,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,   988,  -272,  -819,  -819,  -172,   738,
    -819,   989,    -2,  -819,  -819,   748,  -300,   -43,  -819,   628,
     -29,    -9,  -819,    65,   141,  -188,  -819,  -819,   256,  1039,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   446,  -819,   471,
    -819,    16,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   166,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   -49,  -819,
    -819,  -819,  -818,  -819,  -819,  -819,   676,  -819,  -819,   279,
     649,  -819,  -819,  -819,  -819,  -819,    28,  -819,    24,  -819,
    -819
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    68,    69,   289,    70,    71,   208,   209,   624,
     625,   224,   464,    72,    73,   467,    74,    75,   475,   180,
     181,    76,   258,   597,   596,   506,   507,   259,   183,   242,
     184,   203,   229,   185,   186,   404,   405,   612,   613,    79,
     491,   864,  1085,  1117,   702,    80,   417,   418,   421,   422,
    1021,  1022,    81,   198,   802,  1089,  1118,  1128,  1071,  1133,
      82,   216,   635,   427,   816,  1034,   914,  1035,    83,   217,
     642,    84,   199,   616,   905,    85,   200,   623,    86,   429,
     817,   997,  1093,  1109,    87,   430,   820,  1076,  1037,  1102,
    1129,  1091,   836,  1007,   837,   237,   238,   244,   439,   650,
     442,   831,   832,  1004,  1081,   443,   658,   223,   251,   806,
     808
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     182,   410,   472,   473,   262,   263,   204,   205,   509,   407,
     440,   243,   465,   923,   924,   207,   434,   654,   428,   435,
     655,   458,   903,   423,   424,   193,   465,   219,   218,   220,
     221,   226,   245,    20,   230,   232,   234,   211,    25,   388,
     250,   250,   250,   264,   397,   194,   483,   196,    88,   270,
     904,  1115,    91,    92,    93,   239,     7,     8,    88,   651,
     652,   250,    91,    92,    93,   668,    77,   255,   256,   190,
    1116,   388,   265,   266,   267,   465,   290,   291,   484,   268,
     382,   383,   384,   385,   386,   387,   388,   283,   292,   388,
     388,   759,   991,   760,   778,   587,   779,   300,     7,     8,
     382,   383,   384,   385,   386,   387,   476,   477,   492,   493,
     382,   383,   384,   385,   386,   387,   413,   414,   190,   201,
     227,   228,   202,   388,   388,   388,   389,   390,   785,   823,
     786,   824,   747,   391,   392,   393,   394,   395,   396,   397,
     212,   388,    78,   389,   390,   191,   689,   791,   441,   792,
     391,   392,   393,   394,   395,   396,   397,   400,   401,   389,
     390,   214,   195,   397,   197,   222,   391,   392,   393,   394,
     395,   396,   397,   569,   570,   388,   379,   381,   394,   395,
     396,   397,   748,    58,    59,    60,  1045,   215,   388,  1048,
     257,   388,   403,    53,   191,   466,   746,   409,   388,   681,
     794,   581,   795,   583,   436,   656,   388,   269,   984,   466,
     985,   452,   453,   749,   426,   698,   699,   463,   388,   288,
     987,   438,   988,   469,   471,    58,    59,    60,   388,   388,
     388,   644,   240,   241,   957,   481,   958,   771,   722,  1058,
     276,  1059,   240,   241,   455,   277,   457,   486,   487,   488,
     398,   399,   400,   401,   388,   388,   659,   660,   466,   750,
     757,   665,   666,   396,   397,    77,   510,   398,   399,   400,
     401,   395,   396,   397,   398,   399,   400,   401,   479,  1114,
     388,   388,    77,   398,   399,   400,   401,   772,   787,   235,
     236,   489,   398,   399,   400,   401,   494,   495,   388,   496,
     497,   498,   499,   250,   250,   788,   411,   412,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   250,
     523,   524,   525,   526,   527,   528,   529,   530,   532,   502,
     503,   415,   416,   293,   538,   539,   540,   542,   543,   388,
     545,    78,   547,  -397,   972,   522,   973,   419,   420,   504,
     505,   382,   383,   384,   385,   386,   387,   250,    78,   388,
     389,   390,   572,   294,   975,   278,   976,   391,   392,   393,
     394,   395,   396,   397,    90,   398,   399,   400,   401,    94,
     388,   388,   279,   567,   398,   399,   400,   401,   789,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
      96,   388,   280,   611,  1070,   408,   762,   382,   383,   384,
     385,   386,   387,   388,   388,   388,   281,   803,   977,   587,
     978,  1002,   790,   388,   678,   243,   388,   680,  1110,   645,
    1111,   661,   662,   793,   648,   195,   388,   388,   809,   810,
     389,   812,   813,   796,   849,   663,   664,   391,   392,   393,
     394,   395,   396,   397,   389,   390,   671,   672,   675,   197,
     676,   391,   392,   393,   394,   395,   396,   397,   295,   388,
     682,   683,   388,   108,   712,   109,   713,   763,   388,   691,
     693,   694,   695,   764,   398,   399,   400,   401,   296,   388,
     896,   388,   388,   898,   765,    77,   855,   388,   851,  1011,
     131,   132,   133,   297,  1017,   298,   137,   138,   139,   299,
     141,    88,   143,   144,   145,    91,    92,    93,   388,   150,
     151,   152,   388,   766,   155,   388,   157,   767,   159,   388,
     587,   161,   388,   163,   768,   432,   165,   769,   301,   167,
     168,   388,   169,   170,   388,   172,   770,   174,   388,   773,
      77,   388,   388,   774,   388,   177,   775,   782,  1090,   784,
     302,   187,   550,   388,   398,   399,   400,   401,   797,   388,
     303,    78,   388,   578,   798,   389,   390,   955,   398,   399,
     400,   401,   391,   392,   393,   394,   395,   396,   397,   304,
     948,   388,   388,   388,   799,   800,   979,   986,   989,   388,
     389,   390,   700,   701,   990,   305,   962,   391,   392,   393,
     394,   395,   396,   397,   388,   805,   807,   804,   915,  1001,
     388,   306,   388,   388,   388,  1060,    78,  1063,  1066,  1068,
     382,   383,   384,   385,   386,   387,   388,   388,   852,   307,
     388,  1069,  1080,   308,   822,  1130,   818,   819,   834,   835,
     829,   830,   929,   930,   833,   862,   863,   912,   913,   617,
     309,   618,   310,   619,   389,   390,  1019,  1020,   846,  1038,
    1039,   391,   392,   393,   394,   395,   396,   397,   311,   877,
     312,    77,   313,   856,   857,   858,   620,   314,   315,   621,
     316,   317,   318,   319,   622,   861,   320,   321,   322,   398,
     399,   400,   401,   865,   866,   323,   867,   868,   869,     1,
       2,     3,     4,     5,   324,   325,   326,   327,   875,   876,
     328,   878,   329,   330,   398,   399,   400,   401,   879,   446,
     729,   880,   730,   331,   332,   333,   334,   335,  1005,  1006,
     336,   188,   881,   337,   338,   882,   883,   884,   388,   885,
     886,   339,   451,   776,   340,   341,   342,    78,   888,   210,
     343,   392,   213,   394,   395,   396,   397,   344,   345,   346,
     347,   225,   348,   349,   350,   231,   233,   351,   352,   636,
     249,   637,   353,   638,   892,   893,   894,   895,   398,   399,
     400,   401,   273,   274,   275,   354,   447,   355,   356,   611,
     902,   282,   284,   285,   286,   287,   639,   357,   649,   640,
     474,   358,   359,   360,   641,   361,   362,   363,   364,   916,
     389,   390,   365,   366,   367,   368,   369,   391,   392,   393,
     394,   395,   396,   397,   370,  1072,  1073,   397,   371,   372,
     931,   932,   373,   374,   375,   250,   250,   376,   377,   378,
     431,   939,   940,   433,   454,   444,   445,   389,   390,   449,
     450,   459,   485,   579,   391,   392,   393,   394,   395,   396,
     397,   934,   935,   460,   468,   482,  1092,   398,   399,   400,
     401,  1103,    77,  1104,   609,  1105,  1099,   614,   615,   626,
    1101,   392,   393,   394,   395,   396,   397,   992,   993,   627,
     628,   629,   630,  1119,   634,  1018,   631,   632,  1106,   633,
     426,  1107,   643,   646,   653,   999,  1108,   380,   684,   657,
    1003,   716,  1122,   685,  1123,   402,  1124,   686,   389,   390,
     687,   697,   703,   704,   406,   391,   392,   393,   394,   395,
     396,   397,   711,  1016,   398,   399,   400,   401,   714,  1125,
     720,   715,  1126,   718,   425,   717,   815,  1127,    78,   719,
    1024,   437,   721,   736,   777,   780,   781,  1025,   838,   801,
     839,   840,   841,   847,  1027,   844,  1028,   845,   848,   873,
    1030,   398,   399,   400,   401,   456,   874,   588,   505,  1033,
     906,   907,   908,   909,   910,   461,   911,   918,  1041,   926,
     927,   928,   941,   949,   995,   956,   996,   398,   399,   400,
     401,   961,    -9,  1000,  1036,  1055,  1008,  1009,  1013,   480,
    1014,  1015,  1042,  1046,  1047,  1056,  1057,  1075,  1077,  1079,
    1082,  1083,   490,  1084,  1074,  -375,  1132,   189,   389,   390,
     696,   271,   272,   501,   192,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   508,   901,   732,  1087,
     733,   391,   392,   393,   394,   395,   396,   397,  1088,   533,
     534,   535,   536,   537,   811,  1086,  1095,  1096,   994,   544,
    1134,   546,   669,   548,   549,   551,   553,   555,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   568,    77,
      77,   571,   814,   573,   574,   575,   576,   577,   921,  1097,
     580,  1121,   582,   677,   584,   585,   586,     0,     0,     0,
     589,   590,   591,   592,   593,   594,   595,   667,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,   610,     0,     0,     0,     0,   389,   390,
      77,     0,     0,     0,    77,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,     0,    77,   753,     0,
     754,   647,     0,     0,     0,    78,    78,     0,   398,   399,
     400,   401,     0,     0,    88,    89,    90,     0,    91,    92,
      93,    94,     0,     0,     0,     0,     0,   674,     0,     0,
       0,     0,     0,     0,     0,     0,   679,     0,     0,     0,
       0,    95,    96,     0,     0,     0,    78,     0,     0,   690,
     692,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,   105,     0,     0,     0,     0,   252,
       0,     0,   398,   399,   400,   401,     0,   253,   944,     0,
     945,   106,   107,     0,     0,   108,     0,   109,     0,     0,
     254,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,     0,   164,   165,     0,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,     0,   179,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     7,     8,     9,   827,     0,     0,
     828,    10,     0,     0,     0,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -326,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,   870,   872,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,    45,    46,
      47,  -118,  -118,    48,    49,    50,     0,    51,    52,    53,
       0,     0,    54,  -118,     0,    55,     0,    56,    57,     0,
       0,     0,   887,    88,    89,    90,     0,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,   889,
     890,    58,    59,    60,     0,     0,     0,   891,    61,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
     897,     0,     0,   899,   900,     0,    62,     0,     0,   610,
      63,     0,     0,     0,     0,    64,     0,     0,    65,     0,
       0,     0,    66,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   919,     0,   920,    67,     0,     0,     0,     0,
     104,     0,     0,   105,     0,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,   247,   936,   937,   938,
     106,   107,     0,     0,   108,     0,   109,   946,   947,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     425,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
       0,  1010,     0,     0,     0,   176,   177,   178,     0,     0,
     389,   390,   179,     0,     0,     0,   248,   391,   392,   393,
     394,   395,   396,   397,     0,     0,  1023,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,     0,     0,
       0,  1026,   391,   392,   393,   394,   395,   396,   397,  1029,
     389,   390,     0,  1031,     0,     0,  1032,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,     0,     0,
    1043,     0,     0,     0,     0,     0,     0,     0,     0,  1049,
    1050,  1051,  1052,  1053,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,     0,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   400,   401,     0,     0,
     968,     0,   969,     0,     0,  1094,     0,     0,     0,     0,
    1098,    97,    98,    99,   100,   101,   102,   103,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   448,   104,     0,
       0,   105,     0,     0,   398,   399,   400,   401,     0,  1120,
       0,     0,   462,     0,   500,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
     179,    88,    89,    90,   248,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,   104,     0,
       0,   105,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
     179,    88,    89,    90,   248,    91,    92,    93,    94,   398,
     399,   400,   401,     0,     0,     0,     0,   670,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   390,   104,     0,
       0,   105,     0,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,     0,
     179,   478,    88,    89,    90,     0,    91,    92,    93,    94,
     398,   399,   400,   401,     0,     0,     0,     0,   705,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,   389,   390,   104,
       0,     0,   105,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,     0,
       0,     0,     0,     0,   176,   177,   178,     0,     0,     0,
       0,   179,   531,    88,    89,    90,     0,    91,    92,    93,
      94,   398,   399,   400,   401,     0,     0,     0,     0,   706,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   389,   390,   105,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,     0,   179,   541,    88,    89,    90,     0,    91,    92,
      93,    94,     0,   260,     0,   398,   399,   400,   401,     0,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   389,   390,
       0,   104,     0,     0,   105,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,     0,   164,   165,     0,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   178,     0,
      88,    89,    90,   179,    91,    92,    93,    94,     0,     0,
       0,     0,   398,   399,   400,   401,     0,     0,     0,     0,
     709,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   389,   390,     0,   104,     0,     0,
     105,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,     0,    88,    89,    90,   179,
      91,    92,    93,    94,     0,   470,     0,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,     0,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     389,   390,     0,   104,     0,     0,   105,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,     0,   164,
     165,     0,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,   176,   177,
     178,     0,    88,    89,    90,   179,    91,    92,    93,    94,
       0,     0,     0,     0,   398,   399,   400,   401,     0,     0,
       0,     0,   723,     0,     0,     0,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
      90,     0,   105,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,    96,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   108,
       0,   109,     0,    90,   176,   177,   178,     0,    94,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   133,    96,
       0,     0,   137,   138,   139,     0,   141,     0,   143,   144,
     145,     0,     0,     0,     0,   150,   151,   152,     0,     0,
     155,     0,   157,     0,   159,     0,     0,   161,     0,   163,
       0,     0,   165,     0,     0,   167,   168,     0,   169,   170,
       0,   172,     0,   174,    90,     0,     0,     0,     0,    94,
       0,   177,     0,     0,     0,     0,     0,   187,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,   108,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,     0,     0,     0,   137,   138,   139,     0,   141,
       0,   143,   144,   145,     0,     0,     0,     0,   150,   151,
     152,     0,     0,   155,     0,   157,     0,   159,     0,    90,
     161,     0,   163,     0,    94,   165,     0,     0,   167,   168,
       0,   169,   170,   108,   172,   109,   174,     0,     0,     0,
       0,     0,     0,     0,   177,    96,     0,     0,     0,     0,
     187,   554,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   133,     0,     0,     0,   137,   138,   139,     0,
     141,    90,   143,   144,   145,     0,    94,     0,     0,   150,
     151,   152,     0,     0,   155,     0,   157,     0,   159,     0,
       0,   161,     0,   163,     0,     0,   165,    96,     0,   167,
     168,     0,   169,   170,     0,   172,     0,   174,     0,     0,
     673,     0,     0,     0,     0,   177,     0,     0,   108,     0,
     109,   187,   556,    90,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,     0,    96,
       0,   137,   138,   139,     0,   141,     0,   143,   144,   145,
       0,     0,   871,     0,   150,   151,   152,     0,     0,   155,
     108,   157,   109,   159,     0,    90,   161,     0,   163,     0,
      94,   165,     0,     0,   167,   168,     0,   169,   170,     0,
     172,     0,   174,     0,     0,     0,     0,   131,   132,   133,
     177,    96,     0,   137,   138,   139,   187,   141,     0,   143,
     144,   145,     0,     0,     0,     0,   150,   151,   152,     0,
       0,   155,   108,   157,   109,   159,     0,     0,   161,     0,
     163,     0,     0,   165,     0,     0,   167,   168,     0,   169,
     170,     0,   172,     0,   174,     0,     0,     0,     0,   131,
     132,   133,   177,     0,     0,   137,   138,   139,   187,   141,
       0,   143,   144,   145,     0,     0,     0,     0,   150,   151,
     152,     0,     0,   155,   108,   157,   109,   159,     0,     0,
     161,     0,   163,     0,     0,   165,     0,     0,   167,   168,
       0,   169,   170,     0,   172,     0,   174,     0,     0,     0,
       0,   131,   132,   133,   177,     0,     0,   137,   138,   139,
     187,   141,     0,   143,   144,   145,     0,     0,     0,     0,
     150,   151,   152,     0,     0,   155,     0,   157,     0,   159,
       0,     0,   161,     0,   163,     0,     0,   165,     0,     0,
     167,   168,     0,   169,   170,     0,   172,     0,   174,     0,
       7,     8,     9,     0,     0,     0,   177,    10,     0,     0,
       0,    11,   826,    12,     0,    13,    14,    15,    16,    17,
    -326,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,   -15,
     -15,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,     0,     0,    48,
      49,    50,     0,    51,    52,    53,     0,     0,    54,     0,
       0,    55,     0,    56,    57,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,    63,     0,     0,     0,
       0,    64,     0,     0,    65,     0,     0,     0,    66,     7,
       8,     9,     0,     0,     0,     0,    10,     0,     0,     0,
      11,    67,    12,     0,    13,    14,    15,    16,    17,  -326,
       0,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,   -15,     0,     0,     0,    29,   -15,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    37,    38,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   744,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,   389,   390,
      55,     0,    56,    57,     0,   391,   392,   393,   394,   395,
     396,   397,   389,   390,     0,     0,     0,     0,     0,   391,
     392,   393,   394,   395,   396,   397,    58,    59,    60,   389,
     390,     0,     0,    61,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,    63,     0,     0,     0,     0,
      64,   389,   390,    65,     0,     0,     0,    66,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
      67,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,     0,   398,   399,   400,   401,     0,     0,     0,     0,
     751,     0,     0,     0,     0,     0,   398,   399,   400,   401,
       0,     0,     0,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,     0,
       0,   821,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   842,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   843,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   850,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,     0,     0,   853,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   854,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,   859,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   860,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   917,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,     0,
       0,   922,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   933,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   981,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   982,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,  1012,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,  1061,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,  1078,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,  1113,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   688,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   707,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,   724,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,   726,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,   727,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   728,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,   731,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,   734,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   735,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   737,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,   738,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   739,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   740,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,   741,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,   742,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,   743,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,   745,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   755,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,   756,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,   758,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   761,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   783,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,   825,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   925,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   942,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,   943,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   950,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,   951,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   952,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,   953,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   954,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   959,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,     0,     0,   960,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   963,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   964,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,   965,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,   966,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,   967,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   971,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   974,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   980,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,   983,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,   998,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,  1040,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,  1044,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,  1054,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,  1062,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,  1064,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,  1065,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,  1067,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,  1131,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401
};

static const yytype_int16 yycheck[] =
{
       2,   200,   274,   275,    47,    48,    15,    16,   308,   197,
      58,    40,    12,   831,   832,    17,     4,     4,   217,     7,
       7,    11,    16,   211,   212,     0,    12,    58,    30,    60,
      61,    33,    41,    28,    36,    37,    38,   192,    33,   188,
      42,    43,    44,    59,    76,    75,   195,    75,     3,    51,
      44,    25,     7,     8,     9,    10,     4,     5,     3,   194,
     195,    63,     7,     8,     9,    10,     1,    43,    44,     4,
      44,   188,    88,    89,    90,    12,    91,    92,   195,    95,
      70,    71,    72,    73,    74,    75,   188,    63,   103,   188,
     188,   193,    12,   195,   193,   193,   195,    99,     4,     5,
      70,    71,    72,    73,    74,    75,   278,   279,   296,   297,
      70,    71,    72,    73,    74,    75,    20,    21,    53,     4,
       4,     5,     7,   188,   188,   188,    63,    64,   193,   193,
     195,   195,   195,    70,    71,    72,    73,    74,    75,    76,
     192,   188,     1,    63,    64,     4,   193,   193,   196,   195,
      70,    71,    72,    73,    74,    75,    76,   189,   190,    63,
      64,    28,   192,    76,   192,   196,    70,    71,    72,    73,
      74,    75,    76,   361,   362,   188,   178,   179,    73,    74,
      75,    76,   195,   131,   132,   133,  1004,     7,   188,  1007,
      87,   188,   194,    99,    53,   195,   193,   199,   188,   471,
     193,   373,   195,   375,   192,   192,   188,    94,   193,   195,
     195,   240,   241,   195,   216,   487,   488,   260,   188,    44,
     193,   223,   195,   266,   267,   131,   132,   133,   188,   188,
     188,   430,   187,   188,   193,   195,   195,   195,   510,   193,
     109,   195,   187,   188,   246,   192,   248,   290,   291,   292,
     187,   188,   189,   190,   188,   188,   444,   445,   195,   193,
     193,   449,   450,    75,    76,   200,   309,   187,   188,   189,
     190,    74,    75,    76,   187,   188,   189,   190,   280,  1097,
     188,   188,   217,   187,   188,   189,   190,   195,   195,     4,
       5,   293,   187,   188,   189,   190,   298,   299,   188,   301,
     302,   303,   304,   305,   306,   195,    35,    36,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   305,
     306,     4,     5,    75,   336,   337,   338,   339,   340,   188,
     342,   200,   344,    46,   193,   321,   195,     4,     5,     4,
       5,    70,    71,    72,    73,    74,    75,   359,   217,   188,
      63,    64,   364,    75,   193,   192,   195,    70,    71,    72,
      73,    74,    75,    76,     5,   187,   188,   189,   190,    10,
     188,   188,   192,   359,   187,   188,   189,   190,   195,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
      31,   188,   192,   405,    13,     4,   193,    70,    71,    72,
      73,    74,    75,   188,   188,   188,   192,   616,   193,   193,
     195,   195,   195,   188,   467,   454,   188,   470,   193,   431,
     195,     4,     5,   195,   436,   192,   188,   188,   626,   627,
      63,   629,   630,   195,   195,   447,   448,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    85,    86,   460,   192,
     462,    70,    71,    72,    73,    74,    75,    76,    24,   188,
     472,   473,   188,   104,   193,   106,   195,   193,   188,   481,
     482,   483,   484,   193,   187,   188,   189,   190,   192,   188,
     790,   188,   188,   793,   193,   430,   684,   188,   195,   195,
     131,   132,   133,   192,   195,   192,   137,   138,   139,   192,
     141,     3,   143,   144,   145,     7,     8,     9,   188,   150,
     151,   152,   188,   193,   155,   188,   157,   193,   159,   188,
     193,   162,   188,   164,   193,    58,   167,   193,   192,   170,
     171,   188,   173,   174,   188,   176,   193,   178,   188,   193,
     485,   188,   188,   193,   188,   186,   193,   193,    46,   193,
     192,   192,   193,   188,   187,   188,   189,   190,   193,   188,
     192,   430,   188,   193,   193,    63,    64,   193,   187,   188,
     189,   190,    70,    71,    72,    73,    74,    75,    76,   192,
     862,   188,   188,   188,   596,   597,   193,   193,   193,   188,
      63,    64,     4,     5,   193,   192,   878,    70,    71,    72,
      73,    74,    75,    76,   188,   624,   625,   619,   817,   193,
     188,   192,   188,   188,   188,   193,   485,   193,   193,   193,
      70,    71,    72,    73,    74,    75,   188,   188,   681,   192,
     188,   193,   193,   192,   646,   193,    49,    50,     4,     5,
     652,   653,   840,   841,   656,   698,   699,    39,    40,    14,
     192,    16,   192,    18,    63,    64,     4,     5,   670,    60,
      61,    70,    71,    72,    73,    74,    75,    76,   192,   722,
     192,   616,   192,   685,   686,   687,    41,   192,   192,    44,
     192,   192,   192,   192,    49,   697,   192,   192,   192,   187,
     188,   189,   190,   705,   706,   192,   708,   709,   710,   180,
     181,   182,   183,   184,   192,   192,   192,   192,   720,   721,
     192,   723,   192,   192,   187,   188,   189,   190,   730,   195,
     193,   733,   195,   192,   192,   192,   192,   192,   926,   927,
     192,     3,   744,   192,   192,   747,   748,   749,   188,   751,
     752,   192,   195,   193,   192,   192,   192,   616,   760,    21,
     192,    71,    24,    73,    74,    75,    76,   192,   192,   192,
     192,    33,   192,   192,   192,    37,    38,   192,   192,    14,
      42,    16,   192,    18,   786,   787,   788,   789,   187,   188,
     189,   190,    54,    55,    56,   192,   195,   192,   192,   801,
     802,    63,    64,    65,    66,    67,    41,   192,    51,    44,
       5,   192,   192,   192,    49,   192,   192,   192,   192,   821,
      63,    64,   192,   192,   192,   192,   192,    70,    71,    72,
      73,    74,    75,    76,   192,  1034,  1035,    76,   192,   192,
     842,   843,   192,   192,   192,   847,   848,   192,   192,   192,
     192,   853,   854,   192,   195,   192,   192,    63,    64,   192,
     192,   195,    43,   193,    70,    71,    72,    73,    74,    75,
      76,   847,   848,   195,   195,   195,  1075,   187,   188,   189,
     190,    14,   817,    16,   193,    18,  1085,   193,    75,   192,
    1089,    71,    72,    73,    74,    75,    76,   906,   907,   192,
     195,   192,   192,  1102,    43,   948,   195,   193,    41,   193,
     912,    44,    46,   192,   192,   917,    49,   179,   192,    10,
     922,   192,    14,   195,    16,   187,    18,   195,    63,    64,
     195,   195,   193,   193,   196,    70,    71,    72,    73,    74,
      75,    76,   193,   945,   187,   188,   189,   190,   195,    41,
     195,   193,    44,   193,   216,   192,    43,    49,   817,   193,
     962,   223,   195,   193,   193,   193,   193,   969,   193,   195,
     193,   192,   192,    84,   976,   193,   978,   193,    84,   193,
     982,   187,   188,   189,   190,   247,   193,   193,     5,   991,
     195,   195,   193,   193,   193,   257,   193,    58,  1000,   192,
     192,   195,   193,   192,    43,   193,    38,   187,   188,   189,
     190,   193,    43,   192,    48,  1017,   193,   193,    75,   281,
      75,    75,    58,   193,   193,   192,   192,    47,   192,   192,
      75,   193,   294,   193,  1036,    38,     4,     4,    63,    64,
     485,    53,    53,   305,     5,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,   308,   801,   193,  1061,
     195,    70,    71,    72,    73,    74,    75,    76,  1070,   331,
     332,   333,   334,   335,   628,  1059,  1078,  1079,   912,   341,
    1129,   343,   454,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,  1034,
    1035,   363,   631,   365,   366,   367,   368,   369,   829,  1081,
     372,  1113,   374,   464,   376,   377,   378,    -1,    -1,    -1,
     382,   383,   384,   385,   386,   387,   388,   451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1075,    -1,    -1,   405,    -1,    -1,    -1,    -1,    63,    64,
    1085,    -1,    -1,    -1,  1089,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,    -1,  1102,   193,    -1,
     195,   433,    -1,    -1,    -1,  1034,  1035,    -1,   187,   188,
     189,   190,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,  1075,    -1,    -1,   481,
     482,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,    -1,
    1089,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1102,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,    -1,   187,   188,   189,   190,    -1,    96,   193,    -1,
     195,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,   649,    -1,    -1,
     652,    11,    -1,    -1,    -1,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   713,   714,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,   103,    -1,   105,    -1,   107,   108,    -1,
      -1,    -1,   754,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
     772,   131,   132,   133,    -1,    -1,    -1,   779,   138,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     792,    -1,    -1,   795,   796,    -1,   156,    -1,    -1,   801,
     160,    -1,    -1,    -1,    -1,   165,    -1,    -1,   168,    -1,
      -1,    -1,   172,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,   824,    -1,   826,   185,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,   849,   850,   851,
     100,   101,    -1,    -1,   104,    -1,   106,   859,   860,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     912,   161,   162,   163,   164,    -1,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
      -1,   933,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      63,    64,   192,    -1,    -1,    -1,   196,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,   958,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,   973,    70,    71,    72,    73,    74,    75,    76,   981,
      63,    64,    -1,   985,    -1,    -1,   988,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
    1002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1011,
    1012,  1013,  1014,  1015,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
     193,    -1,   195,    -1,    -1,  1077,    -1,    -1,    -1,    -1,
    1082,    63,    64,    65,    66,    67,    68,    69,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    80,    -1,
      -1,    83,    -1,    -1,   187,   188,   189,   190,    -1,  1111,
      -1,    -1,   195,    -1,    96,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
     192,     3,     4,     5,   196,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    80,    -1,
      -1,    83,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
     192,     3,     4,     5,   196,     7,     8,     9,    10,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    80,    -1,
      -1,    83,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
     192,   193,     3,     4,     5,    -1,     7,     8,     9,    10,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    80,
      -1,    -1,    83,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,
      -1,   192,   193,     3,     4,     5,    -1,     7,     8,     9,
      10,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    63,    64,    83,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161,   162,   163,   164,    -1,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,    -1,   192,   193,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    12,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    80,    -1,    -1,    83,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
       3,     4,     5,   192,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    80,    -1,    -1,
      83,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    -1,   161,   162,
     163,   164,    -1,   166,   167,    -1,   169,   170,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,    -1,     3,     4,     5,   192,
       7,     8,     9,    10,    -1,    12,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    80,    -1,    -1,    83,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,     3,     4,     5,   192,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
       5,    -1,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    31,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,   104,
      -1,   106,    -1,     5,   185,   186,   187,    -1,    10,    -1,
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    31,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,     5,    -1,    -1,    -1,    -1,    10,
      -1,   186,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,     5,
     162,    -1,   164,    -1,    10,   167,    -1,    -1,   170,   171,
      -1,   173,   174,   104,   176,   106,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    31,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,     5,   143,   144,   145,    -1,    10,    -1,    -1,   150,
     151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,   164,    -1,    -1,   167,    31,    -1,   170,
     171,    -1,   173,   174,    -1,   176,    -1,   178,    -1,    -1,
      96,    -1,    -1,    -1,    -1,   186,    -1,    -1,   104,    -1,
     106,   192,   193,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    31,
      -1,   137,   138,   139,    -1,   141,    -1,   143,   144,   145,
      -1,    -1,    96,    -1,   150,   151,   152,    -1,    -1,   155,
     104,   157,   106,   159,    -1,     5,   162,    -1,   164,    -1,
      10,   167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,
     176,    -1,   178,    -1,    -1,    -1,    -1,   131,   132,   133,
     186,    31,    -1,   137,   138,   139,   192,   141,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
      -1,   155,   104,   157,   106,   159,    -1,    -1,   162,    -1,
     164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,
     174,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,   131,
     132,   133,   186,    -1,    -1,   137,   138,   139,   192,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,   155,   104,   157,   106,   159,    -1,    -1,
     162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,
      -1,   173,   174,    -1,   176,    -1,   178,    -1,    -1,    -1,
      -1,   131,   132,   133,   186,    -1,    -1,   137,   138,   139,
     192,   141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,   164,    -1,    -1,   167,    -1,    -1,
     170,   171,    -1,   173,   174,    -1,   176,    -1,   178,    -1,
       4,     5,     6,    -1,    -1,    -1,   186,    11,    -1,    -1,
      -1,    15,   192,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    93,
      94,    95,    -1,    97,    98,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,   107,   108,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,   165,    -1,    -1,   168,    -1,    -1,    -1,   172,     4,
       5,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      15,   185,    17,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,    63,    64,
     105,    -1,   107,   108,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   131,   132,   133,    63,
      64,    -1,    -1,   138,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,    63,    64,   168,    -1,    -1,    -1,   172,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
     185,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,    -1,
      -1,   195,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,    -1,
      -1,   195,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   180,   181,   182,   183,   184,   198,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    77,
      78,    79,    80,    81,    82,    88,    89,    90,    93,    94,
      95,    97,    98,    99,   102,   105,   107,   108,   131,   132,
     133,   138,   156,   160,   165,   168,   172,   185,   199,   200,
     202,   203,   210,   211,   213,   214,   218,   230,   231,   236,
     242,   249,   257,   265,   268,   272,   275,   281,     3,     4,
       5,     7,     8,     9,    10,    30,    31,    63,    64,    65,
      66,    67,    68,    69,    80,    83,   100,   101,   104,   106,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     161,   162,   163,   164,   166,   167,   169,   170,   171,   173,
     174,   175,   176,   177,   178,   179,   185,   186,   187,   192,
     216,   217,   219,   225,   227,   230,   231,   192,   216,   202,
     230,   231,   236,     0,    75,   192,    75,   192,   250,   269,
     273,     4,     7,   228,   228,   228,    34,   219,   204,   205,
     216,   192,   192,   216,    28,     7,   258,   266,   219,    58,
      60,    61,   196,   304,   208,   216,   219,     4,     5,   229,
     219,   216,   219,   216,   219,     4,     5,   292,   293,    10,
     187,   188,   226,   227,   294,   228,    88,    96,   196,   216,
     219,   305,    88,    96,   109,   305,   305,    87,   219,   224,
      12,    53,   224,   224,    59,    88,    89,    90,    95,    94,
     219,   211,   218,   216,   216,   216,   109,   192,   192,   192,
     192,   192,   216,   305,   216,   216,   216,   216,    44,   201,
      91,    92,   103,    75,    75,    24,   192,   192,   192,   192,
     219,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   219,
     216,   219,    70,    71,    72,    73,    74,    75,   188,    63,
      64,    70,    71,    72,    73,    74,    75,    76,   187,   188,
     189,   190,   216,   219,   232,   233,   216,   232,     4,   219,
     200,    35,    36,    20,    21,     4,     5,   243,   244,     4,
       5,   245,   246,   232,   232,   216,   219,   260,   200,   276,
     282,   192,    58,   192,     4,     7,   192,   216,   219,   295,
      58,   196,   297,   302,   192,   192,   195,   195,   195,   192,
     192,   195,   227,   227,   195,   219,   216,   219,    11,   195,
     195,   216,   195,   224,   209,    12,   195,   212,   195,   224,
      12,   224,   212,   212,     5,   215,   215,   215,   193,   219,
     216,   195,   195,   195,   195,    43,   224,   224,   224,   219,
     216,   237,   232,   232,   219,   219,   219,   219,   219,   219,
      96,   216,   305,   305,     4,     5,   222,   223,   222,   223,
     224,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   305,   219,   219,   219,   219,   219,   219,   219,
     219,   193,   219,   216,   216,   216,   216,   216,   219,   219,
     219,   193,   219,   219,   216,   219,   216,   219,   216,   216,
     193,   216,   193,   216,   193,   216,   193,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   305,   216,   232,
     232,   216,   219,   216,   216,   216,   216,   216,   193,   193,
     216,   215,   216,   215,   216,   216,   216,   193,   193,   216,
     216,   216,   216,   216,   216,   216,   221,   220,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   193,
     216,   219,   234,   235,   193,    75,   270,    14,    16,    18,
      41,    44,    49,   274,   206,   207,   192,   192,   195,   192,
     192,   195,   193,   193,    43,   259,    14,    16,    18,    41,
      44,    49,   267,    46,   200,   219,   192,   216,   219,    51,
     296,   194,   195,   192,     4,     7,   192,    10,   303,   232,
     232,     4,     5,   219,   219,   232,   232,   293,    10,   226,
     195,    85,    86,    96,   216,   219,   219,   297,   224,   216,
     224,   212,   219,   219,   192,   195,   195,   195,   193,   193,
     216,   219,   216,   219,   219,   219,   203,   195,   212,   212,
       4,     5,   241,   193,   193,   195,   195,   193,   195,   195,
     195,   193,   193,   195,   195,   193,   192,   192,   193,   193,
     195,   195,   212,   195,   193,   193,   193,   193,   193,   193,
     195,   193,   193,   195,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   195,   193,   193,   195,   195,   195,
     193,   195,   195,   193,   195,   193,   193,   193,   193,   193,
     195,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   195,   195,   193,   193,   193,   193,   193,   193,   195,
     193,   193,   193,   193,   193,   193,   195,   195,   195,   195,
     195,   193,   195,   195,   193,   195,   195,   193,   193,   219,
     219,   195,   251,   200,   219,   228,   306,   228,   307,   232,
     232,   244,   232,   232,   246,    43,   261,   277,    49,    50,
     283,   195,   219,   193,   195,   193,   192,   216,   216,   219,
     219,   298,   299,   219,     4,     5,   289,   291,   193,   193,
     192,   192,   195,   195,   193,   193,   219,    84,    84,   195,
     195,   195,   224,   195,   195,   232,   219,   219,   219,   195,
     195,   219,   224,   224,   238,   219,   219,   219,   219,   219,
     216,    96,   216,   193,   193,   219,   219,   224,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   216,   219,   216,
     216,   216,   219,   219,   219,   219,   223,   216,   223,   216,
     216,   235,   219,    16,    44,   271,   195,   195,   193,   193,
     193,   193,    39,    40,   263,   200,   219,   195,    58,   216,
     216,   296,   195,   289,   289,   193,   192,   192,   195,   232,
     232,   219,   219,   195,   305,   305,   216,   216,   216,   219,
     219,   193,   193,   193,   193,   195,   216,   216,   212,   192,
     193,   193,   193,   193,   193,   193,   193,   193,   195,   193,
     193,   193,   212,   193,   193,   193,   193,   193,   193,   195,
     193,   193,   193,   195,   193,   193,   195,   193,   195,   193,
     193,   195,   195,   193,   193,   195,   193,   193,   195,   193,
     193,    12,   228,   228,   260,    43,    38,   278,   193,   219,
     192,   193,   195,   219,   300,   232,   232,   290,   193,   193,
     216,   195,   195,    75,    75,    75,   219,   195,   224,     4,
       5,   247,   248,   216,   219,   219,   216,   219,   219,   216,
     219,   216,   216,   219,   262,   264,    48,   285,    60,    61,
     193,   219,    58,   216,   193,   289,   193,   193,   289,   216,
     216,   216,   216,   216,   193,   219,   192,   192,   193,   195,
     193,   195,   193,   193,   193,   193,   193,   193,   193,   193,
      13,   255,   200,   200,   219,    47,   284,   192,   195,   192,
     193,   301,    75,   193,   193,   239,   248,   219,   219,   252,
      46,   288,   200,   279,   216,   219,   219,   303,   216,   200,
     193,   200,   286,    14,    16,    18,    41,    44,    49,   280,
     193,   195,   193,   195,   289,    25,    44,   240,   253,   200,
     216,   219,    14,    16,    18,    41,    44,    49,   254,   287,
     193,   193,     4,   256,   285
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   198,   198,   198,   198,   199,   200,   201,
     200,   202,   202,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   203,   205,   203,   203,   203,   203,   203,   203,   203,
     206,   203,   207,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   208,   203,   209,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   211,   211,   212,
     212,   213,   213,   213,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   216,   216,   216,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   218,   218,   220,   219,
     221,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   222,   223,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   227,
     227,   227,   227,   228,   228,   229,   229,   229,   229,   230,
     231,   233,   232,   234,   234,   234,   235,   235,   237,   238,
     239,   236,   240,   240,   241,   241,   242,   242,   242,   242,
     243,   243,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   247,   247,   247,   248,   248,   248,   248,   250,
     251,   252,   253,   249,   254,   254,   254,   254,   254,   254,
     255,   255,   256,   256,   258,   257,   259,   259,   260,   260,
     261,   262,   261,   263,   264,   263,   266,   265,   267,   267,
     267,   267,   267,   267,   269,   270,   268,   271,   271,   273,
     272,   274,   274,   274,   274,   274,   274,   276,   277,   278,
     279,   275,   280,   280,   280,   280,   280,   280,   282,   281,
     283,   283,   284,   284,   285,   286,   287,   285,   288,   288,
     289,   290,   289,   291,   291,   291,   291,   292,   292,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   296,   296,   296,   298,   297,   299,   297,   300,
     297,   301,   297,   302,   297,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   305,   305,   306,   306,   307,   307
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     1,     0,
       4,     1,     2,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     2,     2,     3,     3,
       0,     5,     0,     5,     2,     1,     2,     1,     2,     4,
       4,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     1,     3,
       1,     3,     4,     6,     6,     4,     6,     4,     6,    10,
       4,     4,     4,     8,     6,     4,     3,     3,     0,     4,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     4,
       6,     1,     4,     4,     6,     6,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     8,     4,     4,     4,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     6,     6,     4,
       6,     6,     6,     4,     8,     6,     8,     6,     4,     4,
       4,     6,     6,     6,     8,     4,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     0,     2,     0,     1,     3,     1,     1,     0,     0,
       0,    11,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     3,     1,     1,     4,     4,     1,     3,     1,     1,
       4,     4,     0,     1,     3,     1,     1,     3,     3,     0,
       0,     0,     0,    14,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     1,     0,     7,     1,     2,     1,     1,
       0,     0,     5,     0,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     1,     1,     0,
       4,     1,     2,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     1,     0,     2,     0,     0,     0,     7,     0,     1,
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
        case 7:

    {YYACCEPT;}

    break;

  case 9:

    {if (severity_so_far >= sERROR) {YYABORT;}}

    break;

  case 17:

    {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}

    break;

  case 18:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 24:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 25:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 26:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}

    break;

  case 28:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 29:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 30:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}

    break;

  case 32:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}

    break;

  case 36:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 37:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 38:

    {create_exception(TRUE);}

    break;

  case 39:

    {create_exception(FALSE);}

    break;

  case 40:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 41:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 42:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 43:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 44:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 45:

    {add_command(cCHECKOPEN,NULL,NULL);}

    break;

  case 46:

    {add_command(cCLOSE,NULL,NULL);}

    break;

  case 47:

    {add_command(cCHECKSEEK,NULL,NULL);}

    break;

  case 48:

    {add_command(cCOMPILE,NULL,NULL);}

    break;

  case 49:

    {create_execute(0);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 50:

    {create_execute(1);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 51:

    {create_function(fEVAL3);add_command(cPOP,NULL,NULL);}

    break;

  case 52:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}

    break;

  case 53:

    {create_colour(0);create_pps(cPOPSTREAM,0);}

    break;

  case 54:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}

    break;

  case 55:

    {tileol=FALSE;}

    break;

  case 57:

    {tileol=TRUE;}

    break;

  case 59:

    {add_command(cGCOLOUR,NULL,NULL);}

    break;

  case 60:

    {add_command(cGCOLOUR2,NULL,NULL);}

    break;

  case 61:

    {add_command(cGBACKCOLOUR,NULL,NULL);}

    break;

  case 62:

    {add_command(cGBACKCOLOUR2,NULL,NULL);}

    break;

  case 65:

    {create_restore("");}

    break;

  case 66:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 67:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;
	       add_command(cPOPSYMLIST,NULL,NULL);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL,NULL,NULL);
            } else {
               add_command(cRETURN_FROM_GOSUB,NULL,NULL);
            }}

    break;

  case 68:

    {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 69:

    {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 71:

    {create_openwin(FALSE);}

    break;

  case 72:

    {create_openwin(TRUE);}

    break;

  case 73:

    {add_command(cMOVEORIGIN,NULL,NULL);}

    break;

  case 74:

    {add_command(cDOT,NULL,NULL);}

    break;

  case 75:

    {add_command(cDOT,NULL,NULL);putindrawmode(dmCLEAR);}

    break;

  case 76:

    {create_line(2);}

    break;

  case 77:

    {create_line(2);putindrawmode(dmCLEAR);}

    break;

  case 78:

    {create_line(1);}

    break;

  case 79:

    {create_line(1);}

    break;

  case 80:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 81:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 82:

    {add_command(cPUTBIT,NULL,NULL);}

    break;

  case 83:

    {create_pushstr("solid"); add_command(cPUTBIT,NULL,NULL);}

    break;

  case 84:

    {add_command(cPUTCHAR,NULL,NULL);}

    break;

  case 85:

    {create_line(-1);}

    break;

  case 86:

    {create_line(0);}

    break;

  case 87:

    {add_command(cCIRCLE,NULL,NULL);putindrawmode(0);}

    break;

  case 88:

    {add_command(cTRIANGLE,NULL,NULL);putindrawmode(0);}

    break;

  case 89:

    {add_command(cTEXT1,NULL,NULL);}

    break;

  case 90:

    {add_command(cTEXT2,NULL,NULL);}

    break;

  case 91:

    {add_command(cTEXT3,NULL,NULL);}

    break;

  case 92:

    {add_command(cRECT,NULL,NULL);putindrawmode(0);}

    break;

  case 93:

    {add_command(cCLOSEWIN,NULL,NULL);}

    break;

  case 94:

    {add_command(cCLEARWIN,NULL,NULL);}

    break;

  case 95:

    {add_command(cCLEARSCR,NULL,NULL);}

    break;

  case 96:

    {create_openprinter(0);}

    break;

  case 97:

    {create_openprinter(1);}

    break;

  case 98:

    {add_command(cCLOSEPRN,NULL,NULL);}

    break;

  case 99:

    {add_command(cWAIT,NULL,NULL);}

    break;

  case 100:

    {add_command(cBELL,NULL,NULL);}

    break;

  case 101:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 102:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 103:

    {create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 104:

    {create_function(fSYSTEM);
	add_command(cPOP,NULL,NULL);}

    break;

  case 105:

    {create_poke('s');}

    break;

  case 106:

    {create_poke('d');}

    break;

  case 107:

    {create_poke('S');}

    break;

  case 108:

    {create_poke('D');}

    break;

  case 109:

    {add_command(cEND,NULL,NULL);}

    break;

  case 110:

    {create_pushdbl(0);add_command(cEXIT,NULL,NULL);}

    break;

  case 111:

    {add_command(cEXIT,NULL,NULL);}

    break;

  case 112:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 113:

    {add_command(cBIND,NULL,NULL);}

    break;

  case 114:

    {add_command(cFRNBF_FREE,NULL,NULL);}

    break;

  case 115:

    {add_command(cFRNBF_SET_NUMBER, NULL, NULL);}

    break;

  case 116:

    {add_command(cFRNBF_SET_STRING, NULL, NULL);}

    break;

  case 117:

    {add_command(cFRNBF_SET_BUFFER, NULL, NULL);}

    break;

  case 118:

    {drawmode=0;}

    break;

  case 119:

    {drawmode=dmCLEAR;}

    break;

  case 120:

    {drawmode=dmFILL;}

    break;

  case 121:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 122:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 123:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 124:

    {create_changestring(fMID);}

    break;

  case 125:

    {create_changestring(fMID2);}

    break;

  case 126:

    {create_changestring(fLEFT);}

    break;

  case 127:

    {create_changestring(fRIGHT);}

    break;

  case 128:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 131:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 132:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 133:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 134:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 135:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 136:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 137:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 138:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 139:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 140:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 142:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 143:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 144:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 146:

    {create_function(fLEFT);}

    break;

  case 147:

    {create_function(fRIGHT);}

    break;

  case 148:

    {create_function(fMID);}

    break;

  case 149:

    {create_function(fMID2);}

    break;

  case 150:

    {create_function(fSTR);}

    break;

  case 151:

    {create_function(fSTR2);}

    break;

  case 152:

    {create_function(fSTR3);}

    break;

  case 153:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 154:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 155:

    {create_function(fINKEY);}

    break;

  case 156:

    {create_function(fCHR);}

    break;

  case 157:

    {create_function(fUPPER);}

    break;

  case 158:

    {create_function(fLOWER);}

    break;

  case 159:

    {create_function(fLTRIM);}

    break;

  case 160:

    {create_function(fRTRIM);}

    break;

  case 161:

    {create_function(fTRIM);}

    break;

  case 162:

    {create_function(fCHOMP);}

    break;

  case 163:

    {create_function(fSYSTEM2);}

    break;

  case 164:

    {create_function(fFRNFN_CALL2);}

    break;

  case 165:

    {create_function(fFRNBF_ALLOC);}

    break;

  case 166:

    {create_function(fFRNBF_DUMP);}

    break;

  case 167:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 168:

    {create_function(fDATE);}

    break;

  case 169:

    {create_function(fDATE);}

    break;

  case 170:

    {create_function(fTIME);}

    break;

  case 171:

    {create_function(fTIME);}

    break;

  case 172:

    {create_function(fPEEK2);}

    break;

  case 173:

    {create_function(fPEEK3);}

    break;

  case 174:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 175:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 176:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 177:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 178:

    {create_function(fGETBIT);}

    break;

  case 179:

    {create_function(fGETCHAR);}

    break;

  case 180:

    {create_function(fHEX);}

    break;

  case 181:

    {create_function(fBIN);}

    break;

  case 182:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 183:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 184:

    {create_function(fFRNBF_GET_BUFFER);}

    break;

  case 185:

    {create_function(fEVAL2);}

    break;

  case 186:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 187:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 188:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 189:

    {poplabel();create_boole('|');}

    break;

  case 190:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 191:

    {poplabel();create_boole('&');}

    break;

  case 192:

    {create_boole('!');}

    break;

  case 193:

    {create_dblrelop('=');}

    break;

  case 194:

    {create_dblrelop('!');}

    break;

  case 195:

    {create_dblrelop('<');}

    break;

  case 196:

    {create_dblrelop('{');}

    break;

  case 197:

    {create_dblrelop('>');}

    break;

  case 198:

    {create_dblrelop('}');}

    break;

  case 199:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 200:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 201:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 202:

    {add_command(cARDIM,"",NULL);}

    break;

  case 203:

    {add_command(cARDIM,"",NULL);}

    break;

  case 204:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 205:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 206:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 207:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 208:

    {create_dblbin('+');}

    break;

  case 209:

    {create_dblbin('-');}

    break;

  case 210:

    {create_dblbin('*');}

    break;

  case 211:

    {create_dblbin('/');}

    break;

  case 212:

    {create_dblbin('^');}

    break;

  case 213:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 214:

    {create_strrelop('=');}

    break;

  case 215:

    {create_strrelop('!');}

    break;

  case 216:

    {create_strrelop('<');}

    break;

  case 217:

    {create_strrelop('{');}

    break;

  case 218:

    {create_strrelop('>');}

    break;

  case 219:

    {create_strrelop('}');}

    break;

  case 222:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 223:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 225:

    {create_function(fSIN);}

    break;

  case 226:

    {create_function(fASIN);}

    break;

  case 227:

    {create_function(fCOS);}

    break;

  case 228:

    {create_function(fACOS);}

    break;

  case 229:

    {create_function(fTAN);}

    break;

  case 230:

    {create_function(fATAN);}

    break;

  case 231:

    {create_function(fATAN2);}

    break;

  case 232:

    {create_function(fEXP);}

    break;

  case 233:

    {create_function(fLOG);}

    break;

  case 234:

    {create_function(fLOG2);}

    break;

  case 235:

    {create_function(fSQRT);}

    break;

  case 236:

    {create_function(fSQR);}

    break;

  case 237:

    {create_function(fINT);}

    break;

  case 238:

    {create_function(fROUND);}

    break;

  case 239:

    {create_function(fCEIL);}

    break;

  case 240:

    {create_function(fFLOOR);}

    break;

  case 241:

    {create_function(fFRAC);}

    break;

  case 242:

    {create_function(fABS);}

    break;

  case 243:

    {create_function(fSIG);}

    break;

  case 244:

    {create_function(fMOD);}

    break;

  case 245:

    {create_function(fRAN);}

    break;

  case 246:

    {create_function(fRAN2);}

    break;

  case 247:

    {create_function(fMIN);}

    break;

  case 248:

    {create_function(fMAX);}

    break;

  case 249:

    {create_function(fLEN);}

    break;

  case 250:

    {create_function(fVAL);}

    break;

  case 251:

    {create_function(fASC);}

    break;

  case 252:

    {create_function(fDEC);}

    break;

  case 253:

    {create_function(fDEC2);}

    break;

  case 254:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 255:

    {create_function(fINSTR2);}

    break;

  case 256:

    {create_function(fRINSTR);}

    break;

  case 257:

    {create_function(fRINSTR2);}

    break;

  case 258:

    {create_function(fSYSTEM);}

    break;

  case 259:

    {create_function(fFRNFN_CALL);}

    break;

  case 260:

    {create_function(fFRNFN_SIZE);}

    break;

  case 261:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 262:

    {create_function(fFRNBF_SIZE);}

    break;

  case 263:

    {create_function(fPEEK4);}

    break;

  case 264:

    {create_function(fPEEK);}

    break;

  case 265:

    {create_function(fMOUSEX);}

    break;

  case 266:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 268:

    {create_function(fMOUSEY);}

    break;

  case 269:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 270:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 271:

    {create_function(fMOUSEB);}

    break;

  case 272:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 273:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 274:

    {create_function(fMOUSEMOD);}

    break;

  case 275:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 276:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 277:

    {create_function(fAND);}

    break;

  case 278:

    {create_function(fOR);}

    break;

  case 279:

    {create_function(fBITNOT);}

    break;

  case 280:

    {create_function(fEOR);}

    break;

  case 281:

    {create_function(fSHL);}

    break;

  case 282:

    {create_function(fSHR);}

    break;

  case 283:

    {create_function(fTELL);}

    break;

  case 284:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 285:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 286:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 287:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 288:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 289:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 290:

    {create_myopen(0);}

    break;

  case 291:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 292:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 293:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 294:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 295:

    {create_function(fEVAL);}

    break;

  case 296:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 297:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 298:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 299:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 300:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 301:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 302:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 303:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 304:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 305:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 306:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 307:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 308:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 309:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 310:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 311:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 318:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 319:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 320:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 321:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 322:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 323:

    {missing_endsub--;}

    break;

  case 324:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 325:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 326:

    {exported=FALSE;}

    break;

  case 327:

    {exported=TRUE;}

    break;

  case 328:

    {exported=FALSE;}

    break;

  case 329:

    {exported=TRUE;}

    break;

  case 332:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 333:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 334:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 335:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 338:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 339:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 340:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 341:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 345:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 346:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 347:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 348:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 349:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 350:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     add_command(cRESETSKIPONCE2,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 351:

    { /* pushes another expression */
	     add_command(cSKIPONCE,NULL,NULL);
	     pushlabel();
	     add_command(cSTARTFOR,NULL,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE,NULL,NULL);
	     add_command(cFORINCREMENT,NULL,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK,NULL,NULL);
	     add_command(cDECIDE,NULL,NULL);
             pushlabel();}

    break;

  case 352:

    {
             swap();popgoto();poplabel();}

    break;

  case 353:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 354:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 355:

    {missing_next--;}

    break;

  case 356:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 357:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 358:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 359:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 360:

    {create_pushdbl(1);}

    break;

  case 362:

    {pop(stSTRING);}

    break;

  case 363:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 364:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 365:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 371:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 372:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 374:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 376:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 378:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 379:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 380:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 381:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 382:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 383:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 384:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 385:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 387:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 388:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 389:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 391:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 392:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 393:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 394:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 395:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 396:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 397:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 398:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 399:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 400:

    {poplabel();}

    break;

  case 402:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 403:

    {missing_endif--;}

    break;

  case 404:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 405:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 406:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 407:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 408:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 410:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 411:

    {poplabel();}

    break;

  case 415:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 416:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 421:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 423:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 424:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 425:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 426:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 429:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 430:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 431:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 432:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 433:

    {create_strdata((yyvsp[0].string));}

    break;

  case 434:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 435:

    {create_strdata((yyvsp[0].string));}

    break;

  case 436:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 440:

    {create_print('s');}

    break;

  case 441:

    {create_print('s');}

    break;

  case 442:

    {create_print('d');}

    break;

  case 443:

    {create_print('u');}

    break;

  case 444:

    {create_print('U');}

    break;

  case 445:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 446:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 447:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 448:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 449:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 450:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 451:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 452:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 453:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 454:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 455:

    {create_pushstr("?");create_print('s');}

    break;

  case 456:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 457:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 460:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 461:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 462:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 463:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 464:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 465:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 466:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 467:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 468:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 469:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 470:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 473:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 474:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 475:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 476:

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
