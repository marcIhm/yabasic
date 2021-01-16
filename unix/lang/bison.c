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
    written by Marc Ihm 1995-2021
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
    tSTART_ASSIGNMENT = 438,
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
#define YYLAST   6237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  477
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1137

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
     194,   195,   189,   188,   193,   187,     2,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   192,
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
     399,   400,   401,   402,   403,   404,   405,   408,   409,   412,
     412,   413,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   446,   449,   452,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   528,   529,   530,
     533,   534,   535,   536,   539,   540,   543,   544,   545,   546,
     549,   552,   555,   555,   558,   559,   560,   563,   564,   567,
     568,   571,   567,   576,   577,   580,   581,   584,   585,   586,
     587,   590,   591,   594,   595,   596,   597,   600,   601,   604,
     605,   606,   607,   610,   611,   612,   615,   616,   617,   618,
     621,   622,   627,   642,   621,   647,   648,   649,   650,   651,
     652,   655,   656,   659,   660,   665,   665,   669,   670,   673,
     674,   678,   680,   679,   684,   685,   685,   689,   689,   695,
     696,   697,   698,   699,   700,   704,   705,   704,   711,   712,
     716,   716,   721,   722,   723,   724,   725,   726,   729,   730,
     730,   732,   729,   736,   737,   738,   739,   740,   741,   744,
     744,   749,   750,   753,   754,   757,   759,   761,   758,   765,
     766,   769,   770,   770,   773,   774,   776,   777,   781,   782,
     785,   786,   788,   789,   793,   794,   795,   796,   799,   800,
     801,   802,   803,   806,   807,   808,   811,   811,   812,   812,
     813,   813,   814,   814,   815,   815,   818,   819,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   838,   839,   841,   842,   845,   846
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
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
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
      47,   442,    59,    44,    40,    41,    35
};
# endif

#define YYPACT_NINF -827

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-827)))

#define YYTABLE_NINF -399

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     617,  4042,  3518,  2452,   129,   184,     2,   -45,   -43,  -827,
    -827,  -827,  -827,  -827,    83,    83,    83,  3142,  -827,  -827,
    -827,  2452,  -827,  -827,  2452,   -11,    30,  -827,  -827,  -827,
    3518,    22,  -827,  3518,   170,  -827,  3518,  3518,  3518,   303,
      17,    83,  1793,  1197,  2181,   -25,  3518,  2954,  3518,    -4,
     -51,  3518,  -827,    62,  2452,  2452,  2452,   -41,  -136,   -98,
     -90,   -72,   -69,  2181,  2452,  2452,  2452,   129,  -827,   100,
    -827,  -827,   -44,  -827,  -827,  -827,  -827,   103,   112,  -827,
     176,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,    52,
      87,  -827,  -827,  -827,  -827,   136,   140,   148,   171,  3518,
     191,   212,   221,   271,   328,   352,   358,   364,   367,   370,
     381,   387,   419,   433,   449,   460,   474,   498,   507,   513,
     524,   560,   561,   572,   579,   581,   591,   593,   609,   612,
     613,   616,   618,   629,   630,   638,   639,   644,   647,   648,
     651,   652,   653,   665,   668,   669,   670,   671,   672,   680,
     681,   684,   685,   692,   693,   695,   696,   698,   699,   705,
     710,   715,   716,   717,   721,   722,   726,   727,   729,   730,
     742,   743,   751,   752,   753,   754,   755,   758,  3518,  3518,
     534,  -827,     1,  -827,  -827,  -827,  -827,  2452,   -26,   167,
     103,   112,   199,  -827,  3518,  -827,  2452,  -827,   192,  3518,
    3873,  -827,  -827,  -827,  -827,  -827,   317,   399,   400,   434,
      89,  -827,  3518,  -827,    89,  -827,  -827,  3518,  3873,    97,
     759,   233,   760,     7,  3518,   -48,   534,  3734,   761,   762,
      65,  3734,   534,  5278,   534,  5292,   763,   765,   163,  -827,
    -827,   750,   750,  -827,  -827,   235,  -827,  3518,  2452,  3518,
      28,  3734,   243,  -827,  -827,  -827,  -827,   274,  2452,  5346,
    -827,  3518,  -827,    -8,   297,  -827,  -827,  3518,  3330,  -827,
    -827,  3734,  -827,  -827,    89,    21,    21,  -827,   504,   504,
     504,  2375,  2452,   603,   318,    89,   -65,   214,  -827,  -827,
     536,  3518,  3518,  3518,  3518,  2452,  -827,  -827,  -827,  3518,
    3518,   745,  3518,  3518,  3518,  3518,  1987,  2181,   445,   445,
    3518,  3518,  3518,  3518,  3518,  3518,  3518,  3518,  3518,  3518,
    3518,  3518,  2181,  3518,  3518,  3518,  3518,  3518,  3518,  3518,
    3518,  2568,  2452,  2452,  2452,  2452,  2452,  3518,  3518,  3518,
    2761,  3518,  2452,  3518,  2452,  3518,  2452,  2452,   398,  1380,
    1498,  1577,  2452,  2452,  2452,  2452,  2452,  2452,  2452,  2452,
    2181,  2452,  -827,  -827,  2452,  3518,  2452,  2452,  2452,  2452,
    2452,   402,   477,  2452,   504,  2452,   504,  2452,  2452,  2452,
     619,   371,  1099,  2452,  2452,  2452,  2452,  2452,  2452,  2452,
    -827,  -827,  -827,  3518,  3518,  3518,  3518,  3518,  3518,  3518,
    3518,  3518,  3518,  3518,   -81,  -827,  -827,  -827,  3734,   533,
      89,   610,   656,  3734,   620,  -827,  -827,  -827,  -827,   766,
     767,   621,  -827,   769,   770,   664,  -827,   534,  3734,   707,
    -827,   534,  3734,   768,   649,   839,  3873,  3518,   775,  2452,
    -827,  -827,  3518,   534,   442,   234,   777,    12,  -827,   878,
    -827,  -827,   611,  3518,  3518,  -827,  -827,   303,  -827,  -827,
      43,  5360,    89,  3734,   554,  3594,  3518,    89,  3518,  -827,
     -48,  -827,  -827,  3518,  2452,  -827,  3518,    -8,  3518,  3518,
     779,   709,   786,   788,  -827,  1372,   -64,  3518,  3518,  3518,
    3518,  3873,   796,    -8,    -8,  3734,    89,   676,   798,   799,
    5420,  5434,  1389,  5448,  5488,  5502,   801,   339,   809,   812,
     810,   814,   815,   817,   816,   820,    -8,  5516,  1403,  1425,
    1624,  2005,  2199,   663,  2782,   708,  2968,  3156,   819,  3344,
    3749,  3919,  4088,  4251,  4265,  4282,  5530,  -827,  4314,    -9,
     260,   296,   331,    32,  5576,  5590,   385,   797,  -827,  4328,
    4342,    41,  4356,   -83,  4410,    94,   111,  -827,   156,  -827,
     178,  -827,   228,  -827,   229,   230,   242,   259,   335,   406,
     273,   304,   312,   408,   821,   -82,   823,   825,   313,  4424,
     315,   -29,   407,   467,   469,  -827,  -827,   478,  -139,   491,
    -114,   495,   345,   350,  -827,  -827,    89,    89,    89,    89,
      89,    89,  -827,  3518,  3518,   867,   694,   574,   200,   106,
     172,  -827,    18,    18,   619,   619,  -827,  -827,  -827,  3873,
    -827,  -827,  3518,  -827,  -827,  -827,  -827,    83,    83,  -827,
    -827,   400,  -827,  -827,   434,  3518,  -827,   922,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,   691,  5658,  3518,    49,
    4484,  2645,  -827,  -827,  3518,  3518,  -827,  -827,  3518,  -827,
     738,   826,   827,   829,   830,  5672,  5686,   831,   832,  -827,
    -827,  -827,  3518,   931,   941,  -827,   501,  5718,  3734,  -827,
    -827,   503,  -827,  3518,  5732,  5746,  -827,  3518,  3518,  3518,
    -827,  -827,   534,  3734,   534,  3734,  5760,  5814,  -827,  3518,
    3518,  3518,  -827,  -827,  -827,  -827,  -827,  3518,  3518,  -827,
    3518,  3518,  3518,  -827,  2452,  -827,  3697,  -827,   833,   835,
    -827,  -827,  3518,  3518,  3518,  3518,  -827,  -827,  -827,  -827,
    -827,  3518,  -827,  -827,  3518,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  3518,  -827,  -827,  3518,
    3518,  3518,  -827,  3518,  3518,  -827,  2452,  -827,  -827,  -827,
    -827,  -827,  3518,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  2452,  2452,  -827,  -827,  -827,  -827,
    -827,  2452,  -827,  -827,  -827,  -827,  -827,  -827,  3518,  -827,
    3518,  3518,  3518,  1026,  2452,  -827,  1026,  2452,  -827,  2452,
    -827,  -827,   745,   641,  3518,    44,  3734,  -827,   840,  -827,
     841,   837,   842,  -827,   843,   844,  -827,  -827,  -827,   706,
    3873,  -827,  -827,  -827,  3518,  5828,  2452,   977,  -827,  2452,
      89,   534,   442,  5888,   738,   738,  4498,   846,   847,  -827,
     853,  -827,  -827,  -827,  -827,  3518,  3518,  -827,  -827,  5902,
    2181,  2181,  2452,  2452,  2452,  -827,  3518,  3518,   852,  4512,
    4552,   855,  2452,  2452,  3734,    -8,  -827,   857,  4566,  4580,
    4594,  4640,  4654,   356,   854,    64,  -827,  -827,  4722,  4736,
     863,    45,  4750,  4782,  4796,  4810,  4824,  1025,  4878,  4892,
      95,  4952,   152,   162,   359,  4966,  5916,  5956,  4980,   -30,
     368,    71,   382,   390,    66,  -827,  -827,  -827,    83,    83,
    -827,  -827,  -827,  -827,  3518,  1009,  1021,  1017,  5020,  3518,
     395,   868,   181,  -827,  3518,  -827,  -827,  -827,  -827,  -827,
    -827,   869,   870,  3734,  3734,  2452,  -827,  -827,    89,    89,
     531,  5970,  3734,  -827,   988,   992,  3518,   993,   537,    89,
    3518,   772,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  2452,
    -827,  -827,  -827,  -827,  3518,  -827,  -827,  -827,  -827,  -827,
    3518,  -827,  -827,  -827,  2452,  -827,  -827,  3518,  -827,  3518,
    -827,  -827,  -827,  2452,  3518,  -827,  2452,  -827,  -827,  2452,
    -827,  -827,  -827,  3518,  -827,  -827,  -827,  -827,  -827,  1023,
     733,  5034,  1011,  3518,  2452,  5048,   738,   877,   879,   738,
    -827,  -827,    89,  2452,  2452,  2452,  2452,  5062,  2452,  3518,
    -827,   881,   882,    85,  -827,   403,  5984,  5108,   422,  5122,
    5190,   423,  5204,   426,   431,    82,  3873,  4211,  3518,  1033,
    -827,   887,  -827,   888,  5998,   447,  -827,  -827,  -827,  -827,
    -827,    89,    89,    89,    89,   998,    89,  3734,   889,   890,
     772,  -827,  -827,  3518,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  3518,  -827,  1017,  1045,   308,  3873,  -827,  2452,
    3518,  3518,  -827,   878,  2452,  -827,  -827,  -827,  3873,  5218,
    3734,  3873,  -827,  -827,  1017,   956,   182,  6044,  5250,   738,
      89,    19,  -827,  1017,  3873,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  2452,  -827,  3518,  -827,  -827,  -827,  -827,  -827,
     962,  1017,   456,  5264,  -827,  -827,  -827,  -827,  -827,  -827,
    1082,  1023,  -827,  -827,  -827,  -827,  -827
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   118,     0,     0,     0,   327,     0,     0,     0,   112,
     350,   385,   390,    17,     0,     0,     0,     0,    30,    32,
     328,     0,   312,   312,     0,   329,    24,    26,   365,   377,
       0,   458,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     2,     9,
      16,     8,     0,    11,    45,    47,    13,    28,    29,    27,
       0,    19,    20,    23,    22,    21,    34,    35,   300,   208,
     140,   301,   302,   303,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,   267,   270,   273,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,   221,   202,   207,   142,     0,     0,     0,
       0,     0,     0,     1,     0,   312,     0,   312,     0,     0,
      15,   305,   304,    36,    37,    44,     0,     0,     0,     0,
      18,    49,   314,    50,    48,   330,    25,     0,    15,   409,
       0,   462,     0,     0,   438,   454,    69,    68,     0,     0,
      70,   111,    60,     0,    62,     0,   430,   432,    63,   428,
     434,     0,     0,   435,   297,    64,    66,     0,    96,     0,
       0,   473,     0,    93,    98,    86,    46,     0,     0,     0,
      74,     0,    57,    79,     0,    95,    94,     0,     0,   121,
     122,    99,    12,    14,   113,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,    51,     7,
       0,     0,     0,     0,     0,     0,   319,   312,   312,     0,
       0,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,   312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,   191,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,   187,     0,
     123,     0,     0,   386,     9,    38,    39,    40,    42,   333,
     334,    31,   331,   339,   340,    33,   337,   317,   318,   313,
     315,   370,   369,     0,     9,     0,    15,     0,     0,     0,
     459,   460,     0,   441,   443,    52,     0,     0,    56,   456,
     312,   312,     0,     0,     0,   312,   312,     0,   299,   298,
       0,     0,    97,   472,     0,     0,     0,    73,     0,    78,
     454,   130,   129,     0,     0,    75,     0,    81,     0,     0,
     138,     0,     0,     0,   102,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,   188,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,   271,
       0,   274,     0,   277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   172,     0,     0,     0,
       0,     0,     0,     0,   145,   222,   216,   218,   220,   217,
     219,   215,   144,     0,     0,   195,   197,   199,   196,   198,
     194,   213,   210,   209,   211,   212,   310,   311,   351,    15,
     397,   395,     0,   396,   392,   394,   391,     0,     0,   312,
     312,     0,   312,   312,     0,     0,   367,   371,   384,   382,
     383,   380,   379,   381,   378,   399,     9,     0,     0,     0,
       0,     0,   439,    53,    54,     0,   446,   448,     0,   457,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
     436,   437,     0,     0,     0,   133,   132,   136,   225,    58,
      76,    89,    80,     0,     0,     0,   312,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     0,     0,    10,     0,
       0,     0,   325,   326,   320,   289,   183,     0,     0,   280,
       0,     0,     0,   290,     0,   291,     0,   284,     0,     0,
     203,   204,     0,     0,     0,     0,   226,   227,   228,   229,
     230,     0,   231,   233,     0,   234,   236,   237,   200,   243,
     244,   238,   240,   241,   242,   239,     0,   246,   251,     0,
       0,     0,   250,     0,     0,   153,     0,   150,   156,   157,
     252,   181,     0,   253,   182,   158,   159,   266,   269,   272,
     275,   162,   160,   161,     0,     0,   163,   259,   164,   265,
     264,     0,   173,   260,   165,   261,   166,   263,     0,   167,
       0,     0,     0,     0,     0,   176,     0,     0,   178,     0,
     296,   186,   192,   190,     0,     9,   393,   474,    41,   476,
      43,     0,     0,   332,     0,     0,   338,   316,   368,   374,
      15,   411,   412,   410,     0,     0,     0,   463,   461,     0,
     444,   442,   443,     0,     0,     0,     0,   424,   426,   455,
     421,   306,   308,   312,   312,     0,     0,   431,   433,    71,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   388,   387,     0,     0,
     335,   336,   341,   342,     0,     0,     0,   400,     0,     0,
       0,     0,     0,   440,     0,   447,   449,   450,   312,   312,
     422,     0,     0,    59,    61,     0,   134,   135,   131,   137,
      90,    83,    84,   139,     0,     0,     0,     0,   116,   117,
       0,   343,   278,   279,   281,   282,   283,   292,   293,     0,
     294,   205,   206,   179,     0,   232,   235,   245,   146,   147,
       0,   149,   248,   249,     0,   151,   254,     0,   255,     0,
     257,   174,   168,     0,     0,   185,     0,   286,   175,     0,
     288,   177,   201,     0,   475,   477,   372,   375,   366,   415,
     465,     0,   464,     0,     0,     0,     0,     0,     0,     0,
     307,   309,    72,     0,     0,     0,     0,     0,     0,     0,
      88,   346,   347,     0,   344,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,    15,   118,     0,   413,
     469,     0,   466,     0,     0,     0,   452,   451,   425,   427,
     423,    91,    82,   126,   127,     0,   125,   115,     0,     0,
       0,   321,   295,     0,   148,   152,   256,   258,   262,   184,
     285,   287,     0,   352,   373,     9,   419,    15,   401,     0,
       0,     0,   445,   456,     0,   348,   349,   345,    15,     0,
     362,    15,   420,   416,   414,     0,     0,     0,     0,     0,
     124,     9,   180,   353,    15,   408,   405,   406,   407,   403,
     404,   402,     0,   470,     0,   467,   453,   324,   323,   322,
       0,   417,     0,     0,   356,   358,   359,   360,   355,   357,
     363,   415,   471,   468,   364,   354,   418
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -827,  -827,  -827,  -197,  -827,    25,   596,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  1037,  -253,  -827,  -827,  -153,   771,
    -827,  1038,    -2,  -827,  -827,   783,  -302,   -42,  -827,   633,
     -39,    -3,  -827,   131,   146,    70,  -827,  -827,   459,  1097,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,   480,  -827,   475,
    -827,    48,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,   202,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,   -17,  -827,
    -827,  -827,  -826,  -827,  -827,  -827,   677,  -827,  -827,   301,
     666,  -827,  -827,  -827,  -827,  -827,    59,  -827,    26,  -827,
    -827
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    68,    69,   290,    70,    71,   208,   209,   627,
     628,   225,   470,    72,    73,   473,    74,    75,   481,   180,
     181,    76,   259,   604,   603,   512,   513,   260,   183,   243,
     184,   203,   230,   185,   186,   211,   212,   429,   430,    79,
     497,   867,  1088,  1119,   704,    80,   421,   422,   425,   426,
    1023,  1024,    81,   198,   804,  1091,  1120,  1130,  1073,  1135,
      82,   217,   637,   433,   819,  1036,   916,  1037,    83,   218,
     644,    84,   199,   619,   907,    85,   200,   626,    86,   435,
     820,   999,  1095,  1111,    87,   436,   823,  1078,  1039,  1104,
    1131,  1093,   839,  1009,   840,   238,   239,   245,   445,   652,
     448,   834,   835,  1006,  1083,   449,   660,   224,   252,   808,
     810
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     182,   244,   193,   414,   471,   263,   264,   515,   925,   926,
     446,   440,   204,   205,   441,   207,   656,   215,   405,   657,
      88,   434,   478,   479,    91,    92,    93,   240,   219,   189,
     194,   227,   196,   471,   231,   233,   235,   216,   246,   464,
     251,   251,   251,   270,  1117,   390,    88,   291,   292,   271,
      91,    92,    93,   670,   794,   265,   795,   471,   278,   293,
     905,   251,   258,  1118,   391,   392,     7,     8,   277,   256,
     257,   393,   394,   395,   396,   397,   398,   399,   993,   797,
     220,   798,   221,   222,   266,   267,   268,   201,   906,   284,
     202,   269,   288,   213,   399,  1072,   279,   301,   383,   384,
     385,   386,   387,   388,   280,   389,   389,   389,   391,   392,
     762,   781,   763,   782,   594,   393,   394,   395,   396,   397,
     398,   399,   281,   389,   389,   282,   482,   483,   489,   391,
     392,   691,    77,     7,     8,   190,   393,   394,   395,   396,
     397,   398,   399,  -398,   289,   391,   392,    78,   447,   195,
     191,   197,   393,   394,   395,   396,   397,   398,   399,   389,
     391,   392,   389,   986,   788,   987,   789,   393,   394,   395,
     396,   397,   398,   399,   228,   229,   380,   382,   294,   389,
    1047,   398,   399,  1050,   190,   472,   748,   295,   400,   401,
     402,   403,   408,    58,    59,    60,   412,   413,   190,   191,
     296,   442,   458,   459,   241,   242,   658,   402,   403,   389,
     428,   406,    20,   191,   472,   432,   389,    25,   223,   469,
     389,   588,   444,   590,   683,   475,   477,   752,    53,   389,
     241,   242,   400,   401,   402,   403,   760,   389,   472,   646,
     700,   701,   826,   407,   827,   461,   195,   463,   399,   492,
     493,   494,   389,   400,   401,   402,   403,   959,   452,   960,
      58,    59,    60,   724,   989,   409,   990,   411,   516,   400,
     401,   402,   403,  1116,   397,   398,   399,   389,  1060,   485,
    1061,   197,   389,   389,   400,   401,   402,   403,   974,   765,
     975,   438,   495,   400,   401,   402,   403,   500,   501,   389,
     502,   503,   504,   505,   251,   251,   766,   236,   237,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     251,   529,   530,   531,   532,   533,   534,   535,   536,   538,
     297,    77,   508,   509,   298,   544,   545,   547,   549,   550,
     389,   552,   299,   554,   389,   977,    78,   978,   528,    77,
     389,   767,   415,   416,  1092,   979,   457,   980,   251,   400,
     401,   402,   403,   579,    78,   300,   389,   498,   499,   389,
     389,   391,   392,   768,  1004,  1112,   594,  1113,   393,   394,
     395,   396,   397,   398,   399,   302,   574,   400,   401,   402,
     403,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   389,    90,   419,   420,   303,   490,    94,   383,
     384,   385,   386,   387,   388,   304,   389,   389,   389,   417,
     418,   244,   805,   769,   770,   771,   653,   654,   460,    96,
     389,   680,   576,   577,   682,   647,   465,   772,   423,   424,
     650,   383,   384,   385,   386,   387,   388,   389,   389,   510,
     511,   665,   666,   749,   773,   383,   384,   385,   386,   387,
     388,   389,   391,   392,   677,   305,   678,   466,   776,   393,
     394,   395,   396,   397,   398,   399,   684,   685,   383,   384,
     385,   386,   387,   388,   389,   693,   695,   696,   697,   750,
     474,   899,   389,   651,   901,   400,   401,   402,   403,   777,
     389,   389,   108,   389,   109,   391,   392,   778,   785,   480,
     787,   488,   393,   394,   395,   396,   397,   398,   399,   389,
     661,   662,   306,   389,   751,   667,   668,   389,   774,   131,
     132,   133,   714,   389,   715,   137,   138,   139,   389,   141,
     800,   143,   144,   145,   389,   801,   307,   389,   150,   151,
     152,   957,   308,   155,   981,   157,   389,   159,   309,   389,
     161,   310,   163,   988,   311,   165,   594,    77,   167,   168,
     389,   169,   170,   389,   172,   312,   174,   991,   389,   491,
     755,   313,    78,   389,   177,   992,   400,   401,   402,   403,
    1002,   389,   187,   557,   389,   389,   389,   585,  1062,   775,
     790,   802,   803,   779,   383,   384,   385,   386,   387,   388,
     389,   389,   950,   314,   389,   663,   664,  1065,  1068,   389,
     806,  1070,    77,   917,   807,   809,  1071,   315,   964,   400,
     401,   402,   403,   428,   620,   389,   621,    78,   622,   673,
     674,   855,  1082,   316,   389,   394,   825,   396,   397,   398,
     399,  1132,   832,   833,   317,   389,   836,   389,   865,   866,
     791,   623,   792,   638,   624,   639,   389,   640,   318,   625,
     849,   793,   586,   383,   384,   385,   386,   387,   388,   389,
     702,   703,   880,   389,   796,   859,   860,   861,   799,   389,
     641,   389,   319,   642,   852,   399,   854,   864,   643,   811,
     812,   320,   814,   815,   391,   868,   869,   321,   870,   871,
     872,   393,   394,   395,   396,   397,   398,   399,   322,   389,
     878,   879,   389,   881,  1013,   389,   391,   392,   616,   882,
    1019,   618,   883,   393,   394,   395,   396,   397,   398,   399,
     821,   822,   837,   838,   884,   914,   915,   885,   886,   887,
      77,   888,   889,    88,   323,   324,   858,    91,    92,    93,
     891,   400,   401,   402,   403,    78,   325,   396,   397,   398,
     399,   391,   392,   326,   188,   327,  1021,  1022,   393,   394,
     395,   396,   397,   398,   399,   328,   895,   329,   896,   897,
     898,   389,   210,  1040,  1041,   214,   487,     1,     2,     3,
       4,     5,   904,   330,   226,   617,   331,   332,   232,   234,
     333,   636,   334,   250,   631,   393,   394,   395,   396,   397,
     398,   399,   918,   335,   336,   274,   275,   276,   400,   401,
     402,   403,   337,   338,   283,   285,   286,   287,   339,  1074,
    1075,   340,   341,   933,   934,   342,   343,   344,   251,   251,
     400,   401,   402,   403,   941,   942,   731,   634,   732,   345,
     391,   392,   346,   347,   348,   349,   350,   393,   394,   395,
     396,   397,   398,   399,   351,   352,   936,   937,   353,   354,
    1094,   400,   401,   402,   403,   645,   355,   356,   659,   357,
     358,  1101,   359,   360,  1103,   400,   401,   402,   403,   361,
     635,   734,   687,   735,   362,   994,   995,  1121,  1020,   363,
     364,   365,   432,   931,   932,   366,   367,  1001,   391,   392,
     368,   369,  1005,   370,   371,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   372,   373,   394,   395,
     396,   397,   398,   399,  1017,   374,   375,   376,   377,   378,
     381,    77,   379,   437,   439,   450,   451,   455,   404,   456,
     629,   630,  1026,   632,   633,   818,    78,   410,  1027,   648,
    1105,   655,  1106,   686,  1107,  1029,  1124,  1030,  1125,   688,
    1126,   689,  1032,   427,   400,   401,   402,   403,   431,   699,
     756,  1035,   757,   705,   706,   443,   713,  1108,  1007,  1008,
    1109,  1044,   716,  1127,   718,  1110,  1128,   717,   719,   722,
     720,  1129,   721,   723,   738,   850,   780,  1057,   783,   462,
     784,   841,   842,   843,   844,   851,   847,   848,   876,   467,
     877,   511,   910,   908,   909,   921,  1076,   911,   912,   913,
     928,   929,   400,   401,   402,   403,   930,   943,   946,   958,
     947,   951,   997,   486,   400,   401,   402,   403,   963,   998,
      -9,  1089,  1003,  1015,  1010,  1011,   496,  1016,  1018,  1043,
    1090,  1038,  1048,  1084,  1049,  1058,  1059,   507,  1097,  1098,
    1077,  1079,  1080,  -376,  1085,  1086,  1134,   698,   391,   392,
     272,   273,   514,   671,   817,   393,   394,   395,   396,   397,
     398,   399,   192,   539,   540,   541,   542,   543,  1087,   816,
     546,   813,  1123,   551,  1136,   553,   996,   555,   556,   558,
     560,   562,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   575,   923,   669,   578,   679,   580,   581,   582,
     583,   584,  1099,     0,   587,     0,   589,     0,   591,   592,
     593,     0,     0,     0,   596,   597,   598,   599,   600,   601,
     602,     0,   391,   392,     0,     0,     0,    77,    77,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,    78,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,     0,    91,    92,    93,    94,    77,     0,
     649,     0,   400,   401,   402,   403,     0,     0,   970,    77,
     971,     0,    77,    78,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,    78,    77,   676,    78,     0,     0,
       0,     0,     0,     0,     0,   681,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,   692,   694,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
     105,     0,     0,     0,     0,   253,   400,   401,   402,   403,
       0,     0,     0,   254,   595,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,   255,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,    90,     0,     0,     0,     0,
      94,   179,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   830,     0,     0,   831,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,   391,   392,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   108,   873,   109,   875,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,     0,    90,     0,     0,     0,     0,    94,     0,
       0,   131,   132,   133,     0,     0,     0,   137,   138,   139,
       0,   141,     0,   143,   144,   145,     0,   890,     0,    96,
     150,   151,   152,     0,     0,   155,     0,   157,     0,   159,
       0,     0,   161,     0,   163,   892,   893,   165,     0,     0,
     167,   168,   894,   169,   170,     0,   172,     0,   174,   400,
     401,   402,   403,     0,     0,   900,   177,   690,   902,     0,
     903,     0,     0,     0,   187,   559,   400,   401,   402,   403,
       0,     0,    90,     0,   709,     0,     0,    94,     0,     0,
     400,   401,   402,   403,     0,     0,     0,   920,   726,     0,
     922,     0,   108,     0,   109,     0,     0,     0,    96,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     727,     0,     0,   938,   939,   940,     0,     0,     0,   131,
     132,   133,     0,   948,   949,   137,   138,   139,     0,   141,
       0,   143,   144,   145,     0,     0,     0,     0,   150,   151,
     152,     0,     0,   155,     0,   157,     0,   159,     0,     0,
     161,     0,   163,     0,     0,   165,     0,     0,   167,   168,
       0,   169,   170,     0,   172,     0,   174,     0,     0,     0,
       0,   108,     0,   109,   177,   431,     0,   391,   392,     0,
       0,     0,   187,   561,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,  1012,     0,   131,   132,
     133,     0,     0,     0,   137,   138,   139,     0,   141,     0,
     143,   144,   145,     0,     0,     0,     0,   150,   151,   152,
    1025,     0,   155,     0,   157,     0,   159,     0,     0,   161,
       0,   163,     0,     0,   165,  1028,     0,   167,   168,     0,
     169,   170,     0,   172,  1031,   174,     0,  1033,     0,     0,
    1034,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,   187,   563,     0,     0,  1045,     0,     0,     0,     0,
       0,     0,     0,     0,  1051,  1052,  1053,  1054,     0,  1056,
       0,     0,     0,     0,     0,     0,    88,    89,    90,     0,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,   728,
       0,     0,     0,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1096,     0,     0,     0,     0,  1100,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,   105,     0,     0,     0,
       0,   247,     0,  1122,     0,     0,     0,     0,     0,   248,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,     0,   164,
     165,     0,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,   176,   177,
     178,     0,     0,     0,     0,     0,     0,   179,     0,   249,
      88,    89,    90,     0,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   391,   392,
     105,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,     0,   506,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,     0,     0,     0,     0,     0,
       0,   179,     0,   249,    88,    89,    90,     0,    91,    92,
      93,    94,   400,   401,   402,   403,     0,     0,     0,     0,
     729,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   391,   392,   105,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,     0,   164,   165,     0,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,     0,     0,     0,   179,     0,   249,    88,    89,
      90,     0,    91,    92,    93,    94,   400,   401,   402,   403,
       0,     0,     0,     0,   730,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,    90,   105,     0,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,    96,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
       0,   164,   165,     0,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,     0,   108,     0,   109,     0,
     176,   177,   178,     0,     0,     0,     0,     0,     0,   179,
     484,    88,    89,    90,     0,    91,    92,    93,    94,     0,
       0,     0,     0,   131,   132,   133,     0,     0,     0,   137,
     138,   139,     0,   141,     0,   143,   144,   145,    95,    96,
       0,     0,   150,   151,   152,     0,     0,   155,     0,   157,
       0,   159,     0,     0,   161,     0,   163,     0,     0,   165,
       0,     0,   167,   168,     0,   169,   170,     0,   172,     0,
     174,    97,    98,    99,   100,   101,   102,   103,   177,     0,
       0,     0,     0,     0,     0,     0,   187,     0,   104,     0,
      90,   105,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,    96,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,     0,   108,
       0,   109,     0,   176,   177,   178,     0,     0,     0,     0,
       0,     0,   179,   537,    88,    89,    90,     0,    91,    92,
      93,    94,     0,     0,     0,     0,   131,   132,   133,     0,
       0,     0,   137,   138,   139,     0,   141,     0,   143,   144,
     145,    95,    96,     0,     0,   150,   151,   152,     0,     0,
     155,     0,   157,     0,   159,     0,     0,   161,     0,   163,
       0,     0,   165,     0,     0,   167,   168,     0,   169,   170,
       0,   172,     0,   174,    97,    98,    99,   100,   101,   102,
     103,   177,     0,     0,     0,     0,     0,     0,     0,   829,
       0,   104,     0,     0,   105,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,     0,   164,   165,     0,
     166,   167,   168,     0,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,     0,     0,     0,   179,   548,    88,    89,    90,
       0,    91,    92,    93,    94,     0,   261,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   733,     0,     0,
       0,     0,     0,     0,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   391,   392,     0,   104,     0,     0,   105,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,     0,
     164,   165,     0,   166,   167,   168,     0,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,    88,    89,    90,   179,    91,
      92,    93,    94,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   736,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   391,
     392,     0,   104,     0,     0,   105,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,    88,    89,    90,   179,    91,    92,    93,
      94,     0,   476,   400,   401,   402,   403,     0,     0,     0,
       0,   737,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   391,   392,     0,
     104,     0,     0,   105,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,    88,    89,    90,   179,    91,    92,    93,    94,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,   739,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,    90,
       0,   105,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,    96,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
     675,   169,   170,   171,   172,   173,   174,   175,   108,     0,
     109,     0,    90,   176,   177,   178,     0,    94,     0,     0,
       0,     0,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   133,    96,     0,
       0,   137,   138,   139,     0,   141,     0,   143,   144,   145,
       0,     0,     0,     0,   150,   151,   152,     0,     0,   155,
       0,   157,     0,   159,     0,     0,   161,     0,   163,     0,
       0,   165,     0,     0,   167,   168,     0,   169,   170,     0,
     172,     0,   174,     0,     0,     0,     0,     0,     0,     0,
     177,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,   874,     0,     0,     0,   391,   392,     0,
       0,   108,     0,   109,   393,   394,   395,   396,   397,   398,
     399,     0,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,   131,   132,
     133,     0,     0,     0,   137,   138,   139,     0,   141,     0,
     143,   144,   145,     0,     0,     0,     0,   150,   151,   152,
       0,     0,   155,     0,   157,     0,   159,     0,     0,   161,
       0,   163,     0,     0,   165,     0,     0,   167,   168,     0,
     169,   170,     0,   172,     0,   174,     0,     7,     8,     9,
       0,     0,     0,   177,    10,     0,     0,     0,    11,     0,
      12,   187,    13,    14,    15,    16,    17,  -327,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,     0,     0,    30,     0,
       0,   400,   401,   402,   403,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,   400,   401,   402,   403,
       0,     0,     0,     0,   740,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,    45,    46,    47,  -118,  -118,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    54,  -118,     0,    55,     0,
      56,    57,   391,   392,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,    63,     0,     0,     0,     0,    64,     0,
       0,    65,     0,     0,     0,    66,     7,     8,     9,     0,
       0,     0,     0,    10,     0,     0,     0,    11,    67,    12,
       0,    13,    14,    15,    16,    17,  -327,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
       0,     0,     0,     0,    29,   -15,   -15,    30,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    37,    38,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   741,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
      45,    46,    47,     0,     0,    48,    49,    50,     0,    51,
      52,    53,     0,     0,    54,     0,     0,    55,     0,    56,
      57,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    63,     0,     0,     0,     0,    64,     0,     0,
      65,     0,     0,     0,    66,     7,     8,     9,     0,     0,
       0,     0,    10,     0,     0,     0,    11,    67,    12,     0,
      13,    14,    15,    16,    17,  -327,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,   -15,
       0,     0,     0,    29,   -15,     0,    30,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    37,    38,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   742,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,   391,   392,    55,     0,    56,    57,
       0,   393,   394,   395,   396,   397,   398,   399,   391,   392,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   397,
     398,   399,    58,    59,    60,   391,   392,     0,     0,    61,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,    63,     0,     0,     0,     0,    64,   391,   392,    65,
       0,     0,     0,    66,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,    67,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   743,     0,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     744,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,     0,     0,   745,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,     0,     0,   747,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   758,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   759,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   391,   392,     0,
       0,   761,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,   764,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   391,   392,     0,     0,   786,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,     0,     0,   828,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   927,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,     0,     0,   944,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   945,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   952,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,   953,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   391,   392,     0,     0,   954,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,   955,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   391,   392,     0,     0,   956,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   961,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   962,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,     0,     0,   965,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,   966,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   967,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,   968,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   391,   392,     0,     0,   969,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   972,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,     0,     0,   973,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,   976,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   982,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,     0,     0,   985,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,  1000,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,  1042,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,  1046,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,     0,     0,  1055,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,     0,     0,  1064,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,     0,     0,  1066,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,  1067,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,  1069,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   391,
     392,     0,     0,  1102,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,  1115,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,  1133,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,   453,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   391,   392,   454,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,   468,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,   672,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,   707,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   391,
     392,   710,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,   711,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,   746,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,   753,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,   754,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,   824,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,   845,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   391,   392,   846,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,   853,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,   856,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,   857,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   391,   392,   862,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   391,   392,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   391,
     392,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,   863,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   391,
     392,   919,     0,     0,     0,     0,   393,   394,   395,   396,
     397,   398,   399,   391,   392,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   397,   398,   399,   391,   392,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   391,   392,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,   924,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,   935,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   391,   392,   983,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,   984,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,  1014,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,  1063,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,  1081,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,  1114
};

static const yytype_int16 yycheck[] =
{
       2,    40,     0,   200,    12,    47,    48,   309,   834,   835,
      58,     4,    15,    16,     7,    17,     4,    28,    44,     7,
       3,   218,   275,   276,     7,     8,     9,    10,    30,     4,
      75,    33,    75,    12,    36,    37,    38,     7,    41,    11,
      42,    43,    44,    94,    25,    44,     3,    91,    92,    51,
       7,     8,     9,    10,   193,    59,   195,    12,   194,   103,
      16,    63,    87,    44,    63,    64,     4,     5,   109,    43,
      44,    70,    71,    72,    73,    74,    75,    76,    12,   193,
      58,   195,    60,    61,    88,    89,    90,     4,    44,    63,
       7,    95,    67,    23,    76,    13,   194,    99,    70,    71,
      72,    73,    74,    75,   194,   188,   188,   188,    63,    64,
     193,   193,   195,   195,   195,    70,    71,    72,    73,    74,
      75,    76,   194,   188,   188,   194,   279,   280,   193,    63,
      64,   195,     1,     4,     5,     4,    70,    71,    72,    73,
      74,    75,    76,    46,    44,    63,    64,     1,   196,   194,
       4,   194,    70,    71,    72,    73,    74,    75,    76,   188,
      63,    64,   188,   193,   193,   195,   195,    70,    71,    72,
      73,    74,    75,    76,     4,     5,   178,   179,    75,   188,
    1006,    75,    76,  1009,    53,   193,   195,    75,   187,   188,
     189,   190,   194,   131,   132,   133,     4,   199,    67,    53,
      24,   194,   241,   242,   187,   188,   194,   189,   190,   188,
     212,    44,    28,    67,   193,   217,   188,    33,   196,   261,
     188,   374,   224,   376,   477,   267,   268,   195,    99,   188,
     187,   188,   187,   188,   189,   190,   195,   188,   193,   436,
     493,   494,   193,    44,   195,   247,   194,   249,    76,   291,
     292,   293,   188,   187,   188,   189,   190,   193,   193,   195,
     131,   132,   133,   516,   193,   195,   195,   197,   310,   187,
     188,   189,   190,  1099,    74,    75,    76,   188,   193,   281,
     195,   194,   188,   188,   187,   188,   189,   190,   193,   195,
     195,    58,   294,   187,   188,   189,   190,   299,   300,   188,
     302,   303,   304,   305,   306,   307,   195,     4,     5,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     194,   200,   306,   307,   194,   337,   338,   339,   340,   341,
     188,   343,   194,   345,   188,   193,   200,   195,   322,   218,
     188,   195,    35,    36,    46,   193,   193,   195,   360,   187,
     188,   189,   190,   365,   218,   194,   188,   297,   298,   188,
     188,    63,    64,   195,   193,   193,   195,   195,    70,    71,
      72,    73,    74,    75,    76,   194,   360,   187,   188,   189,
     190,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   188,     5,     4,     5,   194,   193,    10,    70,
      71,    72,    73,    74,    75,   194,   188,   188,   188,    20,
      21,   460,   619,   195,   195,   195,   192,   193,   193,    31,
     188,   473,   362,   363,   476,   437,   193,   195,     4,     5,
     442,    70,    71,    72,    73,    74,    75,   188,   188,     4,
       5,   453,   454,   193,   195,    70,    71,    72,    73,    74,
      75,   188,    63,    64,   466,   194,   468,   193,   195,    70,
      71,    72,    73,    74,    75,    76,   478,   479,    70,    71,
      72,    73,    74,    75,   188,   487,   488,   489,   490,   193,
     193,   793,   188,    51,   796,   187,   188,   189,   190,   195,
     188,   188,   104,   188,   106,    63,    64,   195,   195,     5,
     195,   193,    70,    71,    72,    73,    74,    75,    76,   188,
     450,   451,   194,   188,   193,   455,   456,   188,   193,   131,
     132,   133,   193,   188,   195,   137,   138,   139,   188,   141,
     195,   143,   144,   145,   188,   195,   194,   188,   150,   151,
     152,   195,   194,   155,   195,   157,   188,   159,   194,   188,
     162,   194,   164,   195,   194,   167,   195,   436,   170,   171,
     188,   173,   174,   188,   176,   194,   178,   195,   188,    43,
     195,   194,   436,   188,   186,   195,   187,   188,   189,   190,
     195,   188,   194,   195,   188,   188,   188,   195,   195,   193,
     193,   603,   604,   195,    70,    71,    72,    73,    74,    75,
     188,   188,   865,   194,   188,     4,     5,   195,   195,   188,
     622,   195,   491,   820,   627,   628,   195,   194,   881,   187,
     188,   189,   190,   635,    14,   188,    16,   491,    18,    85,
      86,   683,   195,   194,   188,    71,   648,    73,    74,    75,
      76,   195,   654,   655,   194,   188,   658,   188,   700,   701,
     193,    41,   193,    14,    44,    16,   188,    18,   194,    49,
     672,   193,   195,    70,    71,    72,    73,    74,    75,   188,
       4,     5,   724,   188,   193,   687,   688,   689,   193,   188,
      41,   188,   194,    44,   193,    76,   193,   699,    49,   629,
     630,   194,   632,   633,    63,   707,   708,   194,   710,   711,
     712,    70,    71,    72,    73,    74,    75,    76,   194,   188,
     722,   723,   188,   725,   193,   188,    63,    64,   195,   731,
     193,    75,   734,    70,    71,    72,    73,    74,    75,    76,
      49,    50,     4,     5,   746,    39,    40,   749,   750,   751,
     619,   753,   754,     3,   194,   194,   686,     7,     8,     9,
     762,   187,   188,   189,   190,   619,   194,    73,    74,    75,
      76,    63,    64,   194,     3,   194,     4,     5,    70,    71,
      72,    73,    74,    75,    76,   194,   788,   194,   790,   791,
     792,   188,    21,    60,    61,    24,   193,   180,   181,   182,
     183,   184,   804,   194,    33,   195,   194,   194,    37,    38,
     194,    43,   194,    42,   193,    70,    71,    72,    73,    74,
      75,    76,   824,   194,   194,    54,    55,    56,   187,   188,
     189,   190,   194,   194,    63,    64,    65,    66,   194,  1036,
    1037,   194,   194,   845,   846,   194,   194,   194,   850,   851,
     187,   188,   189,   190,   856,   857,   193,   193,   195,   194,
      63,    64,   194,   194,   194,   194,   194,    70,    71,    72,
      73,    74,    75,    76,   194,   194,   850,   851,   194,   194,
    1077,   187,   188,   189,   190,    46,   194,   194,    10,   194,
     194,  1088,   194,   194,  1091,   187,   188,   189,   190,   194,
     193,   193,   193,   195,   194,   908,   909,  1104,   950,   194,
     194,   194,   914,   843,   844,   194,   194,   919,    63,    64,
     194,   194,   924,   194,   194,    70,    71,    72,    73,    74,
      75,    76,   187,   188,   189,   190,   194,   194,    71,    72,
      73,    74,    75,    76,   946,   194,   194,   194,   194,   194,
     179,   820,   194,   194,   194,   194,   194,   194,   187,   194,
     194,   194,   964,   194,   194,    43,   820,   196,   970,   194,
      14,   194,    16,   194,    18,   977,    14,   979,    16,   193,
      18,   193,   984,   212,   187,   188,   189,   190,   217,   193,
     193,   993,   195,   195,   195,   224,   195,    41,   928,   929,
      44,  1003,   193,    41,   194,    49,    44,   195,   194,   193,
     195,    49,   195,   193,   195,    84,   195,  1019,   195,   248,
     195,   195,   195,   194,   194,    84,   195,   195,   195,   258,
     195,     5,   195,   193,   193,    58,  1038,   195,   195,   195,
     194,   194,   187,   188,   189,   190,   193,   195,   193,   195,
     195,   194,    43,   282,   187,   188,   189,   190,   195,    38,
      43,  1063,   194,    75,   195,   195,   295,    75,    75,    58,
    1072,    48,   195,    75,   195,   194,   194,   306,  1080,  1081,
      47,   194,   194,    38,   195,   195,     4,   491,    63,    64,
      53,    53,   309,   460,   635,    70,    71,    72,    73,    74,
      75,    76,     5,   332,   333,   334,   335,   336,  1060,   634,
     339,   631,  1114,   342,  1131,   344,   914,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   832,   457,   364,   470,   366,   367,   368,
     369,   370,  1083,    -1,   373,    -1,   375,    -1,   377,   378,
     379,    -1,    -1,    -1,   383,   384,   385,   386,   387,   388,
     389,    -1,    63,    64,    -1,    -1,    -1,  1036,  1037,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,  1036,  1037,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,  1077,    -1,
     439,    -1,   187,   188,   189,   190,    -1,    -1,   193,  1088,
     195,    -1,  1091,  1077,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,  1088,  1104,   465,  1091,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
    1104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,   187,   188,   189,   190,
      -1,    -1,    -1,    96,   195,    -1,    -1,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    -1,   161,   162,
     163,   164,    -1,   166,   167,    -1,   169,   170,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,     5,    -1,    -1,    -1,    -1,
      10,   194,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   651,    -1,    -1,   654,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,   104,   714,   106,   716,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,    -1,   143,   144,   145,    -1,   756,    -1,    31,
     150,   151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,   164,   774,   775,   167,    -1,    -1,
     170,   171,   781,   173,   174,    -1,   176,    -1,   178,   187,
     188,   189,   190,    -1,    -1,   794,   186,   195,   797,    -1,
     799,    -1,    -1,    -1,   194,   195,   187,   188,   189,   190,
      -1,    -1,     5,    -1,   195,    -1,    -1,    10,    -1,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,   826,   195,    -1,
     829,    -1,   104,    -1,   106,    -1,    -1,    -1,    31,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,   852,   853,   854,    -1,    -1,    -1,   131,
     132,   133,    -1,   862,   863,   137,   138,   139,    -1,   141,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,
     162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,
      -1,   173,   174,    -1,   176,    -1,   178,    -1,    -1,    -1,
      -1,   104,    -1,   106,   186,   914,    -1,    63,    64,    -1,
      -1,    -1,   194,   195,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,   935,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
     959,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,
      -1,   164,    -1,    -1,   167,   974,    -1,   170,   171,    -1,
     173,   174,    -1,   176,   983,   178,    -1,   986,    -1,    -1,
     989,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,  1004,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1013,  1014,  1015,  1016,    -1,  1018,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1079,    -1,    -1,    -1,    -1,  1084,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    88,    -1,  1112,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    63,    64,
      83,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    96,    -1,    -1,    -1,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    -1,   161,   162,
     163,   164,    -1,   166,   167,    -1,   169,   170,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,     3,     4,     5,    -1,     7,     8,
       9,    10,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    63,    64,    83,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,     3,     4,
       5,    -1,     7,     8,     9,    10,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,     5,    83,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    31,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,    -1,   104,    -1,   106,    -1,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,   137,
     138,   139,    -1,   141,    -1,   143,   144,   145,    30,    31,
      -1,    -1,   150,   151,   152,    -1,    -1,   155,    -1,   157,
      -1,   159,    -1,    -1,   162,    -1,   164,    -1,    -1,   167,
      -1,    -1,   170,   171,    -1,   173,   174,    -1,   176,    -1,
     178,    63,    64,    65,    66,    67,    68,    69,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    80,    -1,
       5,    83,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    31,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,   104,
      -1,   106,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    30,    31,    -1,    -1,   150,   151,   152,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,    63,    64,    65,    66,    67,    68,
      69,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    80,    -1,    -1,    83,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    80,    -1,    -1,    83,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,   162,   163,   164,    -1,
     166,   167,    -1,   169,   170,   171,    -1,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,    -1,    -1,    -1,     3,     4,     5,   194,     7,
       8,     9,    10,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    80,    -1,    -1,    83,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
      -1,    -1,    -1,     3,     4,     5,   194,     7,     8,     9,
      10,    -1,    12,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      80,    -1,    -1,    83,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161,   162,   163,   164,    -1,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,     3,     4,     5,   194,     7,     8,     9,    10,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,     5,
      -1,    83,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    31,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      96,   173,   174,   175,   176,   177,   178,   179,   104,    -1,
     106,    -1,     5,   185,   186,   187,    -1,    10,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    31,    -1,
      -1,   137,   138,   139,    -1,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,
      -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,
     176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    63,    64,    -1,
      -1,   104,    -1,   106,    70,    71,    72,    73,    74,    75,
      76,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,
      -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,
     173,   174,    -1,   176,    -1,   178,    -1,     4,     5,     6,
      -1,    -1,    -1,   186,    11,    -1,    -1,    -1,    15,    -1,
      17,   194,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,   187,   188,   189,   190,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,   105,    -1,
     107,   108,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,    -1,
      -1,   168,    -1,    -1,    -1,   172,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    15,   185,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    -1,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
     108,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,   165,    -1,    -1,
     168,    -1,    -1,    -1,   172,     4,     5,     6,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    15,   185,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,    63,    64,   105,    -1,   107,   108,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   131,   132,   133,    63,    64,    -1,    -1,   138,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,    63,    64,   168,
      -1,    -1,    -1,   172,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,   185,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,    -1,
      -1,   195,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193
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
     174,   175,   176,   177,   178,   179,   185,   186,   187,   194,
     216,   217,   219,   225,   227,   230,   231,   194,   216,   202,
     230,   231,   236,     0,    75,   194,    75,   194,   250,   269,
     273,     4,     7,   228,   228,   228,    34,   219,   204,   205,
     216,   232,   233,   232,   216,    28,     7,   258,   266,   219,
      58,    60,    61,   196,   304,   208,   216,   219,     4,     5,
     229,   219,   216,   219,   216,   219,     4,     5,   292,   293,
      10,   187,   188,   226,   227,   294,   228,    88,    96,   196,
     216,   219,   305,    88,    96,   109,   305,   305,    87,   219,
     224,    12,    53,   224,   224,    59,    88,    89,    90,    95,
      94,   219,   211,   218,   216,   216,   216,   109,   194,   194,
     194,   194,   194,   216,   305,   216,   216,   216,   202,    44,
     201,    91,    92,   103,    75,    75,    24,   194,   194,   194,
     194,   219,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     219,   216,   219,    70,    71,    72,    73,    74,    75,   188,
      44,    63,    64,    70,    71,    72,    73,    74,    75,    76,
     187,   188,   189,   190,   216,    44,    44,    44,   219,   232,
     216,   232,     4,   219,   200,    35,    36,    20,    21,     4,
       5,   243,   244,     4,     5,   245,   246,   216,   219,   234,
     235,   216,   219,   260,   200,   276,   282,   194,    58,   194,
       4,     7,   194,   216,   219,   295,    58,   196,   297,   302,
     194,   194,   193,   193,   193,   194,   194,   193,   227,   227,
     193,   219,   216,   219,    11,   193,   193,   216,   193,   224,
     209,    12,   193,   212,   193,   224,    12,   224,   212,   212,
       5,   215,   215,   215,   195,   219,   216,   193,   193,   193,
     193,    43,   224,   224,   224,   219,   216,   237,   232,   232,
     219,   219,   219,   219,   219,   219,    96,   216,   305,   305,
       4,     5,   222,   223,   222,   223,   224,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   305,   219,
     219,   219,   219,   219,   219,   219,   219,   195,   219,   216,
     216,   216,   216,   216,   219,   219,   216,   219,   195,   219,
     219,   216,   219,   216,   219,   216,   216,   195,   216,   195,
     216,   195,   216,   195,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   305,   216,   232,   232,   216,   219,
     216,   216,   216,   216,   216,   195,   195,   216,   215,   216,
     215,   216,   216,   216,   195,   195,   216,   216,   216,   216,
     216,   216,   216,   221,   220,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   195,   195,    75,   270,
      14,    16,    18,    41,    44,    49,   274,   206,   207,   194,
     194,   193,   194,   194,   193,   193,    43,   259,    14,    16,
      18,    41,    44,    49,   267,    46,   200,   219,   194,   216,
     219,    51,   296,   192,   193,   194,     4,     7,   194,    10,
     303,   232,   232,     4,     5,   219,   219,   232,   232,   293,
      10,   226,   193,    85,    86,    96,   216,   219,   219,   297,
     224,   216,   224,   212,   219,   219,   194,   193,   193,   193,
     195,   195,   216,   219,   216,   219,   219,   219,   203,   193,
     212,   212,     4,     5,   241,   195,   195,   193,   193,   195,
     193,   193,   193,   195,   193,   195,   193,   195,   194,   194,
     195,   195,   193,   193,   212,   193,   195,   195,   195,   195,
     195,   193,   195,   195,   193,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   193,   195,   195,   193,
     193,   193,   195,   193,   193,   195,   193,   195,   195,   195,
     195,   195,   193,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   193,   193,   195,   195,   195,   195,
     195,   193,   195,   195,   195,   195,   195,   195,   193,   195,
     193,   193,   193,   193,   193,   195,   193,   193,   195,   193,
     195,   195,   219,   219,   251,   200,   219,   228,   306,   228,
     307,   232,   232,   244,   232,   232,   246,   235,    43,   261,
     277,    49,    50,   283,   193,   219,   193,   195,   195,   194,
     216,   216,   219,   219,   298,   299,   219,     4,     5,   289,
     291,   195,   195,   194,   194,   193,   193,   195,   195,   219,
      84,    84,   193,   193,   193,   224,   193,   193,   232,   219,
     219,   219,   193,   193,   219,   224,   224,   238,   219,   219,
     219,   219,   219,   216,    96,   216,   195,   195,   219,   219,
     224,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     216,   219,   216,   216,   216,   219,   219,   219,   219,   223,
     216,   223,   216,   216,   219,    16,    44,   271,   193,   193,
     195,   195,   195,   195,    39,    40,   263,   200,   219,   193,
     216,    58,   216,   296,   193,   289,   289,   195,   194,   194,
     193,   232,   232,   219,   219,   193,   305,   305,   216,   216,
     216,   219,   219,   195,   195,   195,   193,   195,   216,   216,
     212,   194,   195,   195,   195,   195,   195,   195,   195,   193,
     195,   195,   195,   195,   212,   195,   195,   195,   195,   195,
     193,   195,   195,   195,   193,   195,   195,   193,   195,   193,
     195,   195,   195,   193,   193,   195,   193,   195,   195,   193,
     195,   195,   195,    12,   228,   228,   260,    43,    38,   278,
     195,   219,   195,   194,   193,   219,   300,   232,   232,   290,
     195,   195,   216,   193,   193,    75,    75,   219,    75,   193,
     224,     4,     5,   247,   248,   216,   219,   219,   216,   219,
     219,   216,   219,   216,   216,   219,   262,   264,    48,   285,
      60,    61,   195,    58,   219,   216,   195,   289,   195,   195,
     289,   216,   216,   216,   216,   195,   216,   219,   194,   194,
     193,   195,   195,   193,   195,   195,   195,   195,   195,   195,
     195,   195,    13,   255,   200,   200,   219,    47,   284,   194,
     194,   193,   195,   301,    75,   195,   195,   248,   239,   219,
     219,   252,    46,   288,   200,   279,   216,   219,   219,   303,
     216,   200,   195,   200,   286,    14,    16,    18,    41,    44,
      49,   280,   193,   195,   193,   195,   289,    25,    44,   240,
     253,   200,   216,   219,    14,    16,    18,    41,    44,    49,
     254,   287,   195,   195,     4,   256,   285
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
     217,   217,   217,   217,   217,   217,   217,   218,   218,   220,
     219,   221,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   222,   223,   224,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   226,   226,   226,
     227,   227,   227,   227,   228,   228,   229,   229,   229,   229,
     230,   231,   233,   232,   234,   234,   234,   235,   235,   237,
     238,   239,   236,   240,   240,   241,   241,   242,   242,   242,
     242,   243,   243,   244,   244,   244,   244,   245,   245,   246,
     246,   246,   246,   247,   247,   247,   248,   248,   248,   248,
     250,   251,   252,   253,   249,   254,   254,   254,   254,   254,
     254,   255,   255,   256,   256,   258,   257,   259,   259,   260,
     260,   261,   262,   261,   263,   264,   263,   266,   265,   267,
     267,   267,   267,   267,   267,   269,   270,   268,   271,   271,
     273,   272,   274,   274,   274,   274,   274,   274,   276,   277,
     278,   279,   275,   280,   280,   280,   280,   280,   280,   282,
     281,   283,   283,   284,   284,   285,   286,   287,   285,   288,
     288,   289,   290,   289,   291,   291,   291,   291,   292,   292,
     293,   293,   293,   293,   294,   294,   294,   294,   295,   295,
     295,   295,   295,   296,   296,   296,   298,   297,   299,   297,
     300,   297,   301,   297,   302,   297,   303,   303,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   305,   306,   306,   307,   307
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       4,     1,     2,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     2,     2,     3,     3,
       0,     5,     0,     5,     2,     1,     2,     1,     2,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     6,     4,     3,     3,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       4,     6,     1,     4,     4,     6,     6,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     3,     6,     6,
       4,     4,     4,     4,     6,     6,     8,     6,     8,     4,
       4,     4,     8,     4,     4,     4,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     6,     6,
       4,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     4,     6,     6,     6,     8,     4,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     6,
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
        case 3:

    {YYACCEPT;}

    break;

  case 4:

    {YYACCEPT;}

    break;

  case 5:

    {YYACCEPT;}

    break;

  case 6:

    {YYACCEPT;}

    break;

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

    {add_command(cERROR);}

    break;

  case 24:

    {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 25:

    {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 26:

    {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}

    break;

  case 28:

    {create_call((yyvsp[0].symbol));add_command(cPOP);}

    break;

  case 29:

    {create_call((yyvsp[0].symbol));add_command(cPOP);}

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

    {add_command(cSKIPPER);}

    break;

  case 41:

    {add_command(cNOP);}

    break;

  case 42:

    {add_command(cSKIPPER);}

    break;

  case 43:

    {add_command(cNOP);}

    break;

  case 44:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 45:

    {add_command(cCHECKOPEN);}

    break;

  case 46:

    {add_command(cCLOSE);}

    break;

  case 47:

    {add_command(cCHECKSEEK);}

    break;

  case 48:

    {add_command(cCOMPILE);}

    break;

  case 49:

    {create_execute(0);add_command(cPOP);add_command(cPOP);}

    break;

  case 50:

    {create_execute(1);add_command(cPOP);add_command(cPOP);}

    break;

  case 51:

    {create_eval(evASSIGNMENT);}

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

    {add_command(cGCOLOUR);}

    break;

  case 60:

    {add_command(cGCOLOUR2);}

    break;

  case 61:

    {add_command(cGBACKCOLOUR);}

    break;

  case 62:

    {add_command(cGBACKCOLOUR2);}

    break;

  case 65:

    {create_restore("");}

    break;

  case 66:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 67:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}

    break;

  case 68:

    {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}

    break;

  case 69:

    {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}

    break;

  case 71:

    {create_openwin(FALSE);}

    break;

  case 72:

    {create_openwin(TRUE);}

    break;

  case 73:

    {add_command(cMOVEORIGIN);}

    break;

  case 74:

    {add_command(cDOT);}

    break;

  case 75:

    {add_command(cDOT);putindrawmode(dmCLEAR);}

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

    {add_command(cPUTBIT);}

    break;

  case 83:

    {create_pushstr("solid"); add_command(cPUTBIT);}

    break;

  case 84:

    {add_command(cPUTCHAR);}

    break;

  case 85:

    {create_line(-1);}

    break;

  case 86:

    {create_line(0);}

    break;

  case 87:

    {add_command(cCIRCLE);putindrawmode(0);}

    break;

  case 88:

    {add_command(cTRIANGLE);putindrawmode(0);}

    break;

  case 89:

    {add_command(cTEXT1);}

    break;

  case 90:

    {add_command(cTEXT2);}

    break;

  case 91:

    {add_command(cTEXT3);}

    break;

  case 92:

    {add_command(cRECT);putindrawmode(0);}

    break;

  case 93:

    {add_command(cCLOSEWIN);}

    break;

  case 94:

    {add_command(cCLEARWIN);}

    break;

  case 95:

    {add_command(cCLEARSCR);}

    break;

  case 96:

    {create_openprinter(0);}

    break;

  case 97:

    {create_openprinter(1);}

    break;

  case 98:

    {add_command(cCLOSEPRN);}

    break;

  case 99:

    {add_command(cWAIT);}

    break;

  case 100:

    {add_command(cBELL);}

    break;

  case 101:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}

    break;

  case 102:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}

    break;

  case 103:

    {create_function(fINKEY);add_command(cPOP);}

    break;

  case 104:

    {create_function(fSYSTEM);
	add_command(cPOP);}

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

    {add_command(cEND);}

    break;

  case 110:

    {create_pushdbl(0);add_command(cEXIT);}

    break;

  case 111:

    {add_command(cEXIT);}

    break;

  case 112:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 113:

    {add_command(cBIND);}

    break;

  case 114:

    {add_command(cFRNBF_FREE);}

    break;

  case 115:

    {add_command(cFRNBF_SET_NUMBER);}

    break;

  case 116:

    {add_command(cFRNBF_SET_STRING);}

    break;

  case 117:

    {add_command(cFRNBF_SET_BUFFER);}

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

    {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

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

    {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 135:

    {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 136:

    {add_command(cSEEK);}

    break;

  case 137:

    {add_command(cSEEK2);}

    break;

  case 138:

    {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 139:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 140:

    {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 142:

    {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 143:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 144:

    {add_command(cCONCAT);}

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

    {create_function(fSTR4);}

    break;

  case 154:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 155:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 156:

    {create_function(fINKEY);}

    break;

  case 157:

    {create_function(fCHR);}

    break;

  case 158:

    {create_function(fUPPER);}

    break;

  case 159:

    {create_function(fLOWER);}

    break;

  case 160:

    {create_function(fLTRIM);}

    break;

  case 161:

    {create_function(fRTRIM);}

    break;

  case 162:

    {create_function(fTRIM);}

    break;

  case 163:

    {create_function(fCHOMP);}

    break;

  case 164:

    {create_function(fSYSTEM2);}

    break;

  case 165:

    {create_function(fFRNFN_CALL2);}

    break;

  case 166:

    {create_function(fFRNBF_ALLOC);}

    break;

  case 167:

    {create_function(fFRNBF_DUMP);}

    break;

  case 168:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 169:

    {create_function(fDATE);}

    break;

  case 170:

    {create_function(fDATE);}

    break;

  case 171:

    {create_function(fTIME);}

    break;

  case 172:

    {create_function(fTIME);}

    break;

  case 173:

    {create_function(fPEEK2);}

    break;

  case 174:

    {create_function(fPEEK3);}

    break;

  case 175:

    {add_command(cTOKENALT2);}

    break;

  case 176:

    {add_command(cTOKENALT);}

    break;

  case 177:

    {add_command(cSPLITALT2);}

    break;

  case 178:

    {add_command(cSPLITALT);}

    break;

  case 179:

    {create_function(fGETBIT);}

    break;

  case 180:

    {create_function(fGETCHAR);}

    break;

  case 181:

    {create_function(fHEX);}

    break;

  case 182:

    {create_function(fBIN);}

    break;

  case 183:

    {create_execute(1);add_command(cSWAP);add_command(cPOP);}

    break;

  case 184:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 185:

    {create_function(fFRNBF_GET_BUFFER);}

    break;

  case 186:

    {create_eval(evSTRING);}

    break;

  case 187:

    {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 188:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 189:

    {add_command(cORSHORT);pushlabel();}

    break;

  case 190:

    {poplabel();create_boole('|');}

    break;

  case 191:

    {add_command(cANDSHORT);pushlabel();}

    break;

  case 192:

    {poplabel();create_boole('&');}

    break;

  case 193:

    {create_boole('!');}

    break;

  case 194:

    {create_dblrelop('=');}

    break;

  case 195:

    {create_dblrelop('!');}

    break;

  case 196:

    {create_dblrelop('<');}

    break;

  case 197:

    {create_dblrelop('{');}

    break;

  case 198:

    {create_dblrelop('>');}

    break;

  case 199:

    {create_dblrelop('}');}

    break;

  case 200:

    {add_command(cTESTEOF);}

    break;

  case 201:

    {add_command(cGLOB);}

    break;

  case 202:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 203:

    {add_command_with_sym_and_diag(cARDIM,"",NULL);}

    break;

  case 204:

    {add_command_with_sym_and_diag(cARDIM,"",NULL);}

    break;

  case 205:

    {add_command_with_sym_and_diag(cARSIZE,"",NULL);}

    break;

  case 206:

    {add_command_with_sym_and_diag(cARSIZE,"",NULL);}

    break;

  case 207:

    {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 208:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 209:

    {create_dblbin('+');}

    break;

  case 210:

    {create_dblbin('-');}

    break;

  case 211:

    {create_dblbin('*');}

    break;

  case 212:

    {create_dblbin('/');}

    break;

  case 213:

    {create_dblbin('^');}

    break;

  case 214:

    {add_command(cNEGATE);}

    break;

  case 215:

    {create_strrelop('=');}

    break;

  case 216:

    {create_strrelop('!');}

    break;

  case 217:

    {create_strrelop('<');}

    break;

  case 218:

    {create_strrelop('{');}

    break;

  case 219:

    {create_strrelop('>');}

    break;

  case 220:

    {create_strrelop('}');}

    break;

  case 223:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 224:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 226:

    {create_function(fSIN);}

    break;

  case 227:

    {create_function(fASIN);}

    break;

  case 228:

    {create_function(fCOS);}

    break;

  case 229:

    {create_function(fACOS);}

    break;

  case 230:

    {create_function(fTAN);}

    break;

  case 231:

    {create_function(fATAN);}

    break;

  case 232:

    {create_function(fATAN2);}

    break;

  case 233:

    {create_function(fEXP);}

    break;

  case 234:

    {create_function(fLOG);}

    break;

  case 235:

    {create_function(fLOG2);}

    break;

  case 236:

    {create_function(fSQRT);}

    break;

  case 237:

    {create_function(fSQR);}

    break;

  case 238:

    {create_function(fINT);}

    break;

  case 239:

    {create_function(fROUND);}

    break;

  case 240:

    {create_function(fCEIL);}

    break;

  case 241:

    {create_function(fFLOOR);}

    break;

  case 242:

    {create_function(fFRAC);}

    break;

  case 243:

    {create_function(fABS);}

    break;

  case 244:

    {create_function(fSIG);}

    break;

  case 245:

    {create_function(fMOD);}

    break;

  case 246:

    {create_function(fRAN);}

    break;

  case 247:

    {create_function(fRAN2);}

    break;

  case 248:

    {create_function(fMIN);}

    break;

  case 249:

    {create_function(fMAX);}

    break;

  case 250:

    {create_function(fLEN);}

    break;

  case 251:

    {create_function(fVAL);}

    break;

  case 252:

    {create_function(fASC);}

    break;

  case 253:

    {create_function(fDEC);}

    break;

  case 254:

    {create_function(fDEC2);}

    break;

  case 255:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 256:

    {create_function(fINSTR2);}

    break;

  case 257:

    {create_function(fRINSTR);}

    break;

  case 258:

    {create_function(fRINSTR2);}

    break;

  case 259:

    {create_function(fSYSTEM);}

    break;

  case 260:

    {create_function(fFRNFN_CALL);}

    break;

  case 261:

    {create_function(fFRNFN_SIZE);}

    break;

  case 262:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 263:

    {create_function(fFRNBF_SIZE);}

    break;

  case 264:

    {create_function(fPEEK4);}

    break;

  case 265:

    {create_function(fPEEK);}

    break;

  case 266:

    {create_function(fMOUSEX);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 268:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 269:

    {create_function(fMOUSEY);}

    break;

  case 270:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 271:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 272:

    {create_function(fMOUSEB);}

    break;

  case 273:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 274:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 275:

    {create_function(fMOUSEMOD);}

    break;

  case 276:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 277:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 278:

    {create_function(fAND);}

    break;

  case 279:

    {create_function(fOR);}

    break;

  case 280:

    {create_function(fBITNOT);}

    break;

  case 281:

    {create_function(fEOR);}

    break;

  case 282:

    {create_function(fSHL);}

    break;

  case 283:

    {create_function(fSHR);}

    break;

  case 284:

    {create_function(fTELL);}

    break;

  case 285:

    {add_command(cTOKEN2);}

    break;

  case 286:

    {add_command(cTOKEN);}

    break;

  case 287:

    {add_command(cSPLIT2);}

    break;

  case 288:

    {add_command(cSPLIT);}

    break;

  case 289:

    {create_execute(0);add_command(cSWAP);add_command(cPOP);}

    break;

  case 290:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 291:

    {create_myopen(0);}

    break;

  case 292:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 293:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 294:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 295:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 296:

    {create_eval(evNUMBER);}

    break;

  case 297:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 298:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 299:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 300:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 301:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 302:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 303:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 304:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 305:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 306:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 307:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 308:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 309:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 310:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 311:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 312:

    {add_command(cPUSHFREE);}

    break;

  case 319:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 320:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}

    break;

  case 321:

    {create_require(stFREE);add_command(cPOP);}

    break;

  case 322:

    {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}

    break;

  case 323:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 324:

    {missing_endsub--;}

    break;

  case 325:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 326:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 327:

    {exported=FALSE;}

    break;

  case 328:

    {exported=TRUE;}

    break;

  case 329:

    {exported=FALSE;}

    break;

  case 330:

    {exported=TRUE;}

    break;

  case 333:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 334:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 335:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 336:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 339:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 340:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 341:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 342:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 346:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 347:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 348:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 349:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 350:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}

    break;

  case 351:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 352:

    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}

    break;

  case 353:

    {
             swap();popgoto();poplabel();}

    break;

  case 354:

    {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 355:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 356:

    {missing_next--;}

    break;

  case 357:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 358:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 359:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 360:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 361:

    {create_pushdbl(1);}

    break;

  case 363:

    {pop(stSTRING);}

    break;

  case 364:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 365:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}

    break;

  case 366:

    {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}

    break;

  case 372:

    {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}

    break;

  case 373:

    {add_command(cNEXT_CASE_HERE);}

    break;

  case 375:

    {add_command(cNEXT_CASE_HERE);}

    break;

  case 377:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 379:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 380:

    {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 381:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 382:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 383:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 384:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 385:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 386:

    {add_command(cDECIDE);
	      pushlabel();}

    break;

  case 388:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 389:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 390:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 392:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 393:

    {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}

    break;

  case 394:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 395:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 396:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 397:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 398:

    {add_command(cDECIDE);storelabel();pushlabel();}

    break;

  case 399:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 400:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 401:

    {poplabel();}

    break;

  case 403:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 404:

    {missing_endif--;}

    break;

  case 405:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 406:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 407:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 408:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 409:

    {in_short_if++;add_command(cDECIDE);pushlabel();}

    break;

  case 411:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 412:

    {poplabel();}

    break;

  case 416:

    {add_command(cDECIDE);pushlabel();}

    break;

  case 417:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 422:

    {add_command(cCHKPROMPT);}

    break;

  case 424:

    {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 425:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 426:

    {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 427:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 430:

    {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 431:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 432:

    {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 433:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 434:

    {create_strdata((yyvsp[0].string));}

    break;

  case 435:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 436:

    {create_strdata((yyvsp[0].string));}

    break;

  case 437:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 441:

    {create_print('s');}

    break;

  case 442:

    {create_print('s');}

    break;

  case 443:

    {create_print('d');}

    break;

  case 444:

    {create_print('u');}

    break;

  case 445:

    {create_print('U');}

    break;

  case 446:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}

    break;

  case 447:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 448:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 449:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 450:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 451:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 452:

    {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 453:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 454:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 455:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 456:

    {create_pushstr("?");create_print('s');}

    break;

  case 457:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 458:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}

    break;

  case 460:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 461:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 462:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 463:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 464:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 465:

    {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 466:

    {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 467:

    {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 468:

    {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 469:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}

    break;

  case 470:

    {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 471:

    {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 474:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 475:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 476:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

    break;

  case 477:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}

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
