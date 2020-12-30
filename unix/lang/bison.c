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
    tSTART_FUNCTION_DEFINITION = 438,
    tEVAL = 439,
    tEVAL2 = 440,
    UMINUS = 441
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
#define YYFINAL  188
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  196
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1132

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   441

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   195,     2,     2,     2,     2,
     191,   192,   188,   187,   194,   186,     2,   189,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   193,
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
     185,   190
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   191,   192,   193,   196,   199,   200,   200,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   222,
     223,   223,   224,   225,   226,   227,   228,   229,   230,   230,
     232,   232,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   245,   246,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   263,   264,   265,   266,
     267,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   318,   319,   320,   321,
     322,   326,   327,   328,   329,   330,   331,   334,   335,   338,
     339,   340,   341,   342,   345,   346,   349,   350,   353,   354,
     355,   356,   357,   358,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   403,   404,   407,   407,   408,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     441,   444,   447,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   523,   524,   525,   528,   529,   530,
     531,   534,   535,   538,   539,   540,   541,   544,   547,   550,
     550,   553,   554,   555,   558,   559,   562,   563,   566,   562,
     571,   572,   575,   576,   579,   580,   581,   582,   585,   586,
     589,   590,   591,   592,   595,   596,   599,   600,   601,   602,
     605,   606,   607,   610,   611,   612,   613,   616,   617,   622,
     637,   616,   642,   643,   644,   645,   646,   647,   650,   651,
     654,   655,   660,   660,   664,   665,   668,   669,   673,   675,
     674,   679,   680,   680,   684,   684,   690,   691,   692,   693,
     694,   695,   699,   700,   699,   706,   707,   711,   711,   716,
     717,   718,   719,   720,   721,   724,   725,   725,   727,   724,
     731,   732,   733,   734,   735,   736,   739,   739,   744,   745,
     748,   749,   752,   754,   756,   753,   760,   761,   764,   765,
     765,   768,   769,   771,   772,   776,   777,   780,   781,   783,
     784,   788,   789,   790,   791,   794,   795,   796,   797,   798,
     801,   802,   803,   806,   806,   807,   807,   808,   808,   809,
     809,   810,   810,   813,   814,   817,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   833,
     834,   836,   837,   840,   841
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
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "'('", "')'", "';'", "','", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1", "statement",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "clear_fill_clause",
  "string_assignment", "to", "open_clause", "seek_clause",
  "string_scalar_or_array", "string_expression", "string_function",
  "assignment", "expression", "$@8", "$@9", "arrayref", "string_arrayref",
  "coordinates", "function", "const", "number", "symbol_or_lineno",
  "dimlist", "function_or_array", "stringfunction_or_array", "call_list",
  "$@10", "calls", "call_item", "function_definition", "$@11", "$@12",
  "$@13", "endsub", "function_name", "export", "local_list", "local_item",
  "static_list", "static_item", "paramlist", "paramitem", "for_loop",
  "$@14", "$@15", "$@16", "$@17", "next", "step_part", "next_symbol",
  "switch_number_or_string", "$@18", "sep_list", "number_or_string",
  "case_list", "$@19", "default", "$@20", "do_loop", "$@21", "loop",
  "while_loop", "$@22", "$@23", "wend", "repeat_loop", "$@24", "until",
  "if_clause", "$@25", "$@26", "$@27", "$@28", "endif", "short_if", "$@29",
  "end_of_if", "else_part", "elsif_part", "$@30", "$@31", "maybe_then",
  "inputlist", "$@32", "input", "readlist", "readitem", "datalist",
  "printlist", "using", "inputbody", "$@33", "$@34", "$@35", "$@36",
  "$@37", "prompt", "printintro", "hashed_number", "goto_list",
  "gosub_list", YY_NULLPTR
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
     435,   436,   437,   438,   439,   440,    45,    43,    42,    47,
     441,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -821

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-821)))

#define YYTABLE_NINF -396

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,  3979,  3258,  3747,    71,     5,   -57,   -50,  -821,  -821,
    -821,  -821,  -821,    51,    51,    51,  2888,  -821,  -821,  -821,
    3747,  -117,   -91,  3747,    31,   112,  -821,  -821,  -821,  3258,
     -32,  -821,  3258,   248,  -821,  3258,  3258,  3258,   263,    44,
      51,  1487,  1122,  1944,   -17,  3258,  2703,  3258,   183,    43,
    3258,  -821,    58,  3747,  3747,  3747,     6,   -51,   -39,   -26,
      -3,    14,  1944,  3747,  3747,  3747,  3747,  -821,   156,  -821,
     -60,  -821,  -821,  -821,  -821,   133,   136,  -821,   195,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,    32,    46,  -821,
    -821,  -821,  -821,    88,   135,   139,   147,  3258,   149,   164,
     180,   188,   210,   216,   230,   259,   290,   312,   316,   328,
     343,   347,   355,   361,   376,   389,   413,   435,   436,   455,
     459,   468,   469,   477,   478,   486,   500,   526,   529,   539,
     540,   545,   549,   554,   557,   566,   568,   569,   571,   572,
     574,   575,   576,   577,   578,   580,   581,   582,   585,   586,
     587,   594,   599,   604,   607,   608,   614,   615,   616,   617,
     622,   624,   626,   627,   630,   631,   642,   643,   644,   645,
     648,   655,   656,   659,   667,   668,  3258,  3258,   638,  -821,
    1360,  -821,  -821,  -821,  -821,  3747,    47,  -821,  -821,  3258,
    -821,  3747,  -821,   250,  3258,  1314,  -821,  -821,  -821,  -821,
    -821,   268,   399,   363,   365,    47,  -821,  -821,    47,  -821,
    -821,  3258,  1314,    96,   669,   207,   670,    13,  3258,   -34,
     638,  1360,   671,   676,   221,  1360,   638,   600,   638,   781,
     681,   683,   306,  -821,  -821,   451,   451,  -821,  -821,   338,
    -821,  3258,  3747,  3258,    83,  1360,   350,  -821,  -821,  -821,
    -821,   449,  3747,  1613,  -821,  3258,  -821,     1,   512,  -821,
    -821,  3258,  3073,  -821,  -821,  1360,  -821,  -821,   133,   136,
      47,    -9,    -9,  -821,   479,   479,   479,  2133,  3747,   364,
     532,    47,  -149,  -138,    47,  -821,   721,  3258,  3258,  3258,
    3258,  3747,  -821,  -821,  -821,  3258,  3258,  1967,  3258,  3258,
    3258,  3258,  1755,  1944,   428,   428,  3258,  3258,  3258,  3258,
    3258,  3258,  3258,  3258,  3258,  3258,  3258,  3258,  1944,  3258,
    3258,  3258,  3258,  3258,  3258,  3258,  3258,  2323,  3747,  3747,
    3747,  3747,  3747,  3258,  3258,  3258,  2513,  3258,  3747,  3258,
    3747,  3258,  3747,  3747,   398,  3334,  3443,  3519,  3747,  3747,
    3747,  3747,  3747,  3747,  3747,  3747,  1944,  3747,  -821,  -821,
    3747,  3258,  3747,  3747,  3747,  3747,  3747,   450,   588,  3747,
     479,  3747,   479,  3747,  3747,  3747,   792,    10,  1390,  3747,
    3747,  3747,  3747,  3747,  3747,  3747,  -821,  -821,  3258,  3258,
    3258,  3258,  3258,  3258,  3258,  3258,  3258,  3258,  3258,   -10,
    1360,   684,  3258,    47,   685,   739,  1360,   857,  -821,  -821,
    -821,  -821,   687,   689,   695,  -821,   699,   702,   703,  -821,
     710,   711,   638,  1360,   866,   878,   858,  1314,  3258,   719,
    3747,  -821,  -821,  3258,   638,   442,   247,   720,    15,  -821,
     903,  -821,  -821,   448,  3258,  3258,  -821,  -821,   263,  -821,
    -821,    69,  1639,    47,  1360,   379,  3610,  3258,    47,  3258,
    -821,   -34,  -821,  -821,  3258,  3747,  -821,  3258,     1,  3258,
    3258,   723,   722,   724,   726,  -821,  4576,    89,  3258,  3258,
    3258,  3258,  1314,   727,     1,     1,  1360,    47,   517,   734,
     736,  1654,  1958,  4590,  2148,  2338,  2531,   746,   562,   745,
     749,   755,   760,   761,   762,   753,   758,     1,  2717,  4657,
    4671,  4685,  4717,  4731,   535,  4745,   756,  4759,  4812,   763,
    4826,  4886,  4900,  4914,  4953,  4967,  4981,  2902,  -821,  4995,
     224,  -130,   -98,   -97,   226,  3087,  3660,   861,  -821,  5041,
    5055,   236,  5122,  -101,  5136,   238,   264,  -821,   274,  -821,
     293,  -821,   295,  -821,   307,   333,   341,   353,   -14,   -11,
     367,   383,   386,   374,   767,   -89,   769,   771,   390,  5150,
     392,     9,    -8,    20,    23,  -821,  -821,    63,  -148,    93,
    -121,   108,   408,   409,  -821,  -821,    47,    47,    47,    47,
      47,    47,  -821,  3258,  3258,   811,   677,   309,   546,   322,
     -64,  -821,   -53,   -53,   792,   792,  -821,   638,  1360,   772,
    -821,  -821,  -821,  1314,  -821,  -821,  3258,  -821,  -821,  -821,
    -821,    51,    51,  -821,  -821,   363,  -821,  -821,   365,  -821,
    -821,  -821,   887,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,   514,  4026,  3258,    26,  5182,  3804,  -821,  -821,  3258,
    3258,  -821,  -821,  3258,  -821,   589,   773,   780,   788,   790,
    4189,  4203,   791,   795,  -821,  -821,  -821,  3258,   898,   900,
    -821,   142,  4220,  1360,  -821,  -821,   215,  -821,  3258,  4252,
    4266,  -821,  3258,  3258,  3258,  -821,  -821,   638,  1360,   638,
    1360,  4280,  4294,  -821,  3258,  3258,  3258,  -821,  -821,  -821,
    -821,  -821,  3258,  3258,  -821,  3258,  3258,  3258,  -821,  -821,
    3747,  3667,  -821,   797,   799,  -821,  -821,  3258,  3258,  3258,
    3258,  -821,  -821,  -821,  -821,  -821,  -821,  3258,  -821,  -821,
    3258,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  3258,  -821,  -821,  3258,  3258,  3258,  -821,  3258,  3258,
    -821,  3747,  -821,  -821,  -821,  -821,  -821,  3258,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  3747,  3747,
    -821,  -821,  -821,  -821,  -821,  -821,  3747,  -821,  -821,  -821,
    -821,  -821,  -821,  3258,  3258,  3258,  3258,   987,  -821,  3747,
     987,  -821,  3747,  3747,  -821,  -821,  1967,   623,  3258,  3258,
      21,  1360,  -821,   800,  -821,   802,   810,   813,  -821,   814,
     815,  -821,  -821,   573,  1314,  -821,  -821,  -821,  3258,  4347,
     945,  3747,  -821,  3747,    47,   638,   442,  4361,   589,   589,
    5196,   817,   822,  -821,   820,  -821,  -821,  -821,  -821,  3258,
    3258,  -821,  -821,  4421,  1944,  1944,  3747,  3747,  3747,  -821,
    3258,  3258,   823,  5210,  5224,   947,  3747,  3747,  1360,     1,
    -821,   833,  5277,  5291,  5351,  5365,  5379,   410,   834,   157,
    -821,  -821,  5418,  5432,   835,    38,  5446,  5460,  5506,  5520,
    5587,   988,  5601,  5615,   158,  5647,   166,   169,   452,  5661,
    4435,  4449,  5675,   -76,   453,   -30,   462,   465,  -821,    57,
    -821,  -821,  -821,    51,    51,  -821,  -821,  -821,  -821,  3258,
     982,   990,   989,  5689,  3258,   839,   466,   170,  -821,  3258,
    -821,  -821,  -821,  -821,  -821,  -821,   841,   842,  1360,  1360,
    3747,  -821,  -821,    47,    47,   218,  4488,  1360,  -821,   961,
     962,   963,  3258,   223,    47,  3258,   611,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  3747,  -821,  -821,  -821,  3258,
    -821,  -821,  -821,  -821,  -821,  -821,  3258,  -821,  -821,  -821,
    3747,  -821,  -821,  3258,  -821,  3258,  -821,  -821,  3747,  3258,
    -821,  -821,  3747,  -821,  -821,  3747,  -821,  -821,  3258,  -821,
    -821,  -821,  -821,  -821,   991,   564,  5742,  3258,   977,  3747,
    5756,   589,   849,   850,   589,  -821,  -821,    47,  3747,  3747,
    3747,  3747,  3747,  5816,  3258,  -821,   852,   853,    41,  -821,
     474,  4502,  5830,   475,  5844,  5883,   496,  5897,   497,   498,
      75,  1314,  4149,  3258,   998,  -821,   855,  -821,  4516,   863,
     515,  -821,  -821,  -821,  -821,  -821,    47,    47,    47,    47,
      47,   996,  1360,   865,   880,  -821,   611,  -821,  3258,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  3258,  -821,   989,
    1037,   302,  1314,  -821,  3747,  3258,  3258,  -821,   903,  3747,
    -821,  -821,  1314,  -821,  5911,  1360,  1314,  -821,  -821,   989,
     944,   212,  5925,  4530,   589,    47,    17,  -821,   989,  1314,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  3747,  -821,
    3258,  -821,  -821,  -821,  -821,   960,   989,   527,  5971,  -821,
    -821,  -821,  -821,  -821,  -821,  1073,   991,  -821,  -821,  -821,
    -821,  -821
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   116,     0,     0,   324,     0,     0,     0,   110,   347,
     382,   387,    15,     0,     0,     0,     0,    28,    30,   325,
       0,     0,     0,     0,   326,    22,    24,   362,   374,     0,
     455,    53,    65,     0,   107,   108,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,   117,   118,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     2,     8,     7,
       0,    11,    43,    45,    13,    26,    27,    25,     0,    17,
      18,    21,    20,    19,    32,    33,   297,   205,   138,   298,
     299,   300,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,   264,   267,   270,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
       3,   218,   199,   204,   140,     0,     4,     5,     1,     0,
     309,     0,   309,     0,     0,    10,   302,   301,    34,    35,
      42,     0,     0,     0,     0,    16,   309,   309,    46,   327,
      23,     0,    10,   406,     0,   459,     0,     0,   435,   451,
      67,    66,     0,     0,    68,   109,    58,     0,    60,     0,
     427,   429,    61,   425,   431,     0,     0,   432,   294,    62,
      64,     0,    94,     0,     0,   470,     0,    91,    96,    84,
      44,     0,     0,     0,    72,     0,    55,    77,     0,    93,
      92,     0,     0,   119,   120,    97,    12,    14,     0,     0,
     111,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,    49,     6,     0,     0,     0,     0,
       0,     0,   316,   309,   309,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   309,   309,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,     0,   311,   121,     0,     0,   383,     8,    36,    37,
      38,    40,   330,   331,    29,   328,   336,   337,    31,   334,
       0,     0,   367,   366,     0,     8,     0,    10,     0,     0,
       0,   456,   457,     0,   438,   440,    50,     0,     0,    54,
     453,   309,   309,     0,     0,     0,   309,   309,     0,   296,
     295,     0,     0,    95,   469,     0,     0,     0,    71,     0,
      76,   451,   128,   127,     0,     0,    73,     0,    79,     0,
       0,   136,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   185,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,   268,
       0,   271,     0,   274,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   169,     0,     0,     0,
       0,     0,     0,     0,   143,   219,   213,   215,   217,   214,
     216,   212,   142,     0,     0,   192,   194,   196,   193,   195,
     191,   210,   207,   206,   208,   209,   307,   314,   315,   310,
     312,   308,   348,    10,   394,   392,     0,   393,   389,   391,
     388,     0,     0,   309,   309,     0,   309,   309,     0,    47,
      48,   364,   368,   381,   379,   380,   377,   376,   378,   375,
     396,     8,     0,     0,     0,     0,     0,   436,    51,    52,
       0,   443,   445,     0,   454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,   433,   434,     0,     0,     0,
     131,   130,   134,   222,    56,    74,    87,    78,     0,     0,
       0,   309,     0,     0,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     9,     0,     0,     0,   322,   323,   317,
     286,   180,     0,     0,   277,     0,     0,     0,   287,   288,
       0,     0,   281,     0,     0,   200,   201,     0,     0,     0,
       0,   223,   224,   225,   226,   227,   228,     0,   230,   231,
       0,   233,   234,   197,   240,   241,   235,   237,   238,   239,
     236,     0,   243,   248,     0,     0,     0,   247,     0,     0,
     148,     0,   153,   154,   249,   178,   250,     0,   179,   155,
     156,   263,   266,   269,   272,   159,   157,   158,     0,     0,
     160,   256,   161,   262,   261,   170,     0,   257,   162,   258,
     163,   260,   164,     0,     0,     0,     0,     0,   173,     0,
       0,   175,     0,     0,   293,   183,   189,   187,     0,     0,
       8,   390,   471,    39,   473,    41,     0,     0,   329,     0,
       0,   335,   365,   371,    10,   408,   409,   407,     0,     0,
     460,     0,   458,     0,   441,   439,   440,     0,     0,     0,
       0,   421,   423,   452,   418,   303,   305,   309,   309,     0,
       0,   428,   430,    69,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
     386,   385,   384,     0,     0,   332,   333,   338,   339,     0,
       0,     0,   397,     0,     0,     0,     0,     0,   437,     0,
     444,   446,   447,   309,   309,   419,     0,     0,    57,    59,
       0,   132,   133,   129,   135,    88,    81,    82,   137,     0,
       0,     0,     0,   114,   115,     0,   340,   275,   276,   278,
     279,   280,   289,   290,   291,     0,   202,   203,   176,     0,
     229,   232,   242,   144,   145,   147,     0,   245,   246,   149,
       0,   251,   252,     0,   254,     0,   171,   165,     0,     0,
     182,   283,     0,   172,   285,     0,   174,   198,     0,   472,
     474,   369,   372,   363,   412,   462,     0,     0,   461,     0,
       0,     0,     0,     0,     0,   304,   306,    70,     0,     0,
       0,     0,     0,     0,     0,    86,   343,   344,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,    10,   116,     0,   410,   466,     0,   463,     0,     0,
       0,   449,   448,   422,   424,   420,    89,    80,   124,   125,
     123,     0,   113,     0,     0,   318,     0,   292,     0,   146,
     150,   253,   255,   259,   181,   282,   284,     0,   349,   370,
       8,   416,    10,   398,     0,     0,     0,   442,   453,     0,
     345,   346,    10,   342,     0,   359,    10,   417,   413,   411,
       0,     0,     0,     0,     0,   122,     8,   177,   350,    10,
     405,   402,   403,   404,   400,   401,   399,   467,     0,   464,
       0,   450,   321,   320,   319,     0,   414,     0,     0,   353,
     355,   356,   357,   352,   354,   360,   412,   468,   465,   361,
     351,   415
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -821,  -821,  -821,  -191,  -821,   597,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  1047,  -256,  -821,  -821,  -132,   738,  -821,
    1058,    -2,  -821,  -821,   809,  -304,   -40,  -821,   664,   -37,
      -4,  -821,    65,    74,  -100,  -821,  -821,   318,  1120,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,   503,  -821,   510,  -821,
      86,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,   234,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,  -821,
    -821,  -821,  -821,  -821,  -821,  -821,  -821,    18,  -821,  -821,
    -821,  -820,  -821,  -821,  -821,   697,  -821,  -821,   323,   693,
    -821,  -821,  -821,  -821,  -821,    70,  -821,    25,  -821,  -821
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    67,    68,   286,    69,   203,   204,   621,   622,
     219,   461,    70,    71,   464,    72,    73,   472,   178,   179,
      74,   253,   594,   593,   503,   504,   254,   181,   237,   182,
     198,   224,   183,   184,   401,   402,   609,   610,    77,   488,
     861,  1082,  1114,   699,    78,   414,   415,   418,   419,  1018,
    1019,    79,   193,   799,  1086,  1115,  1125,  1068,  1130,    80,
     211,   632,   424,   813,  1031,   911,  1032,    81,   212,   639,
      82,   194,   613,   902,    83,   195,   620,    84,   426,   814,
     994,  1090,  1106,    85,   427,   817,  1073,  1034,  1099,  1126,
    1088,   833,  1004,   834,   232,   233,   239,   436,   647,   439,
     828,   829,  1001,  1078,   440,   655,   218,   246,   803,   805
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,   506,   238,   462,   407,   188,   257,   258,   920,   921,
     199,   200,   394,   462,   202,   469,   470,   431,   189,   651,
     432,   425,   652,   394,   437,   191,   214,   213,   215,   216,
     221,   287,   288,   225,   227,   229,   240,   900,   385,   245,
     245,   245,  1112,   289,   788,   480,   789,    86,   265,   385,
     462,    89,    90,    91,   234,   196,   481,   385,   197,   209,
     245,  1113,     6,     7,   744,   901,    75,   250,   251,   988,
     252,   791,    86,   792,   206,    76,    89,    90,    91,   665,
     379,   380,   381,   382,   383,   384,   385,   280,  1067,   385,
     385,   756,   404,   757,   455,   297,   745,   746,   385,    19,
     207,   386,   387,   775,    24,   776,   420,   421,   388,   389,
     390,   391,   392,   393,   394,   273,   981,   268,   982,   210,
     386,   387,   395,   396,   397,   398,   269,   388,   389,   390,
     391,   392,   393,   394,   190,   397,   398,   264,   386,   387,
     274,   192,  -395,   473,   474,   388,   389,   390,   391,   392,
     393,   394,   275,   379,   380,   381,   382,   383,   384,   386,
     387,   438,   984,   217,   985,   276,   388,   389,   390,   391,
     392,   393,   394,   385,   376,   378,   385,   385,   385,   385,
     768,  1042,   584,   769,  1045,   463,   784,   400,   277,    57,
      58,    59,   406,   489,   490,   463,   385,   385,   449,   450,
     285,   782,   584,   783,   433,   278,   653,   385,   290,   423,
     385,   291,   678,   385,   785,   460,   435,   786,   820,   292,
     821,   466,   468,   190,   395,   396,   397,   398,   695,   696,
     235,   236,   463,  1055,   385,  1056,   641,   192,   578,   452,
     580,   454,   259,   395,   396,   397,   398,   483,   484,   485,
     385,   719,   222,   223,   405,   235,   236,   787,   566,   567,
      75,   395,   396,   397,   398,   429,   507,   230,   231,    76,
     385,   260,   261,   262,  1111,   476,   385,    75,   263,   293,
     385,   686,   395,   396,   397,   398,    76,   790,   486,     1,
       2,     3,     4,   491,   492,   385,   493,   494,   495,   496,
     245,   245,   793,   408,   409,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   245,   520,   521,   522,
     523,   524,   525,   526,   527,   529,   294,   499,   500,   385,
     295,   535,   536,   537,   539,   540,   846,   542,   296,   544,
     298,   656,   657,   519,   385,   385,   662,   663,  1087,   954,
     969,   955,   970,   385,   245,   299,   385,   385,   972,   569,
     973,   974,   584,   975,   999,   386,   387,   412,   413,   416,
     417,   300,   388,   389,   390,   391,   392,   393,   394,   301,
     389,   564,   391,   392,   393,   394,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   393,   394,   385,
     608,   302,   385,    88,  1107,   385,  1108,   303,    92,   848,
     385,   385,  1008,   385,   238,   443,   743,  1014,   747,   410,
     411,   304,   800,   385,   675,   385,   642,   677,   754,    94,
     759,   645,   501,   502,   379,   380,   381,   382,   383,   384,
     648,   649,   660,   661,   379,   380,   381,   382,   383,   384,
     305,   385,   658,   659,    86,   672,   760,   673,    89,    90,
      91,   385,   386,   387,   668,   669,   761,   679,   680,   388,
     389,   390,   391,   392,   393,   394,   688,   690,   691,   692,
     385,   306,   385,   893,   471,   762,   895,   763,   395,   396,
     397,   398,    75,   646,   385,   395,   396,   397,   398,   764,
     448,    76,   106,   307,   107,   386,   387,   308,   395,   396,
     397,   398,   388,   389,   390,   391,   392,   393,   394,   309,
     385,   697,   698,   806,   807,   765,   809,   810,   385,   129,
     130,   131,   451,   766,   310,   135,   136,   137,   311,   139,
     385,   141,   142,   143,   456,   767,   312,    75,   148,   149,
     150,   385,   313,   153,   385,   155,    76,   157,   478,   770,
     159,   385,   161,   815,   816,   163,   773,   314,   165,   166,
     385,   167,   168,   385,   170,   771,   172,   385,   772,   385,
     315,   852,   779,   175,   781,   395,   396,   397,   398,   185,
     547,   796,   797,   831,   832,   385,   385,   385,   386,   387,
     794,   795,   952,   945,   316,   388,   389,   390,   391,   392,
     393,   394,   909,   910,   801,  1016,  1017,   802,   804,   959,
     392,   393,   394,   912,  1035,  1036,   317,   318,   395,   396,
     397,   398,   379,   380,   381,   382,   383,   384,   849,   385,
     385,   819,   575,   457,   976,   983,   319,   826,   827,   385,
     320,   830,   385,   385,   986,   859,   860,   987,   998,   321,
     322,   385,   385,   386,   387,   843,  1057,  1060,   323,   324,
     388,   389,   390,   391,   392,   393,   394,   325,    75,   874,
     853,   854,   855,   385,   385,   385,   386,    76,  1063,  1065,
    1066,   326,   858,   388,   389,   390,   391,   392,   393,   394,
     862,   863,   385,   864,   865,   866,   465,  1077,   379,   380,
     381,   382,   383,   384,   385,   872,   873,   327,   875,  1127,
     328,   395,   396,   397,   398,   876,   479,   726,   877,   727,
     329,   330,   395,   396,   397,   398,   331,   926,   927,   878,
     332,   186,   879,   880,   881,   333,   882,   883,   334,   385,
     391,   392,   393,   394,   709,   885,   710,   335,   205,   336,
     337,   208,   338,   339,   482,   340,   341,   342,   343,   344,
     220,   345,   346,   347,   226,   228,   348,   349,   350,   244,
     576,   889,   890,   891,   892,   351,   395,   396,   397,   398,
     352,   270,   271,   272,   444,   353,   608,   899,   354,   355,
     279,   281,   282,   283,   284,   356,   357,   358,   359,   395,
     396,   397,   398,   360,   612,   361,   913,   362,   363,   386,
     387,   364,   365,  1002,  1003,   385,   388,   389,   390,   391,
     392,   393,   394,   366,   367,   368,   369,   928,   929,   370,
    1069,  1070,   245,   245,   386,   387,   371,   372,   936,   937,
     373,   388,   389,   390,   391,   392,   393,   394,   374,   375,
     428,   430,   441,   395,   396,   397,   398,   442,   394,   931,
     932,   614,   446,   615,   447,   616,   606,   611,   623,    75,
     624,  1089,   389,   390,   391,   392,   393,   394,    76,   625,
     626,  1096,   633,   627,   634,  1098,   635,   628,   617,   989,
     990,   618,   629,   630,   640,  1015,   619,   423,  1116,   631,
     643,   650,   996,   654,   681,   377,   682,  1000,   683,   636,
     684,   694,   637,   399,   386,   387,   700,   638,   701,   403,
     812,   388,   389,   390,   391,   392,   393,   394,   708,   711,
    1013,   712,   395,   396,   397,   398,   713,   717,   729,   422,
     730,   714,   718,   715,   716,   733,   434,  1021,  1100,   774,
    1101,   777,  1102,   778,  1022,   835,   798,   395,   396,   397,
     398,  1024,   836,  1025,  1119,   445,  1120,  1027,  1121,   837,
     453,   838,   844,   841,   845,  1103,  1030,   842,  1104,   870,
     458,   871,   502,  1105,   903,  1038,   904,   395,   396,   397,
     398,  1122,   905,   915,  1123,   906,   907,   908,   923,  1124,
     386,   387,  1052,   924,   925,   938,   477,   388,   389,   390,
     391,   392,   393,   394,   946,   992,   953,   958,   993,   487,
     997,  1071,    -8,  1005,  1006,  1039,  1010,  1011,  1012,  1033,
     498,  1043,  1044,  1053,  1054,  1072,  1074,   395,   396,   397,
     398,   386,   387,   750,  1076,   751,  1084,  1080,   388,   389,
     390,   391,   392,   393,   394,  1085,   530,   531,   532,   533,
     534,  1079,  1081,  1092,  1093,  -373,   541,  1129,   543,   693,
     545,   546,   548,   550,   552,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   565,    75,    75,   568,   266,
     570,   571,   572,   573,   574,    76,    76,   577,  1118,   579,
     267,   581,   582,   583,   505,   666,   898,   586,   587,   588,
     589,   590,   591,   592,   187,    86,    87,    88,   808,    89,
      90,    91,    92,   395,   396,   397,   398,    75,   811,   941,
     607,   942,  1083,   991,  1131,   664,    76,    75,  1094,   918,
       0,    75,    93,    94,   674,     0,    76,     0,     0,     0,
      76,     0,     0,     0,    75,     0,     0,     0,   644,     0,
       0,     0,     0,    76,   395,   396,   397,   398,     0,     0,
     965,     0,   966,     0,     0,    95,    96,    97,    98,    99,
     100,   101,     0,     0,   671,     0,     0,     0,     0,     0,
       0,     0,   102,   676,     0,   103,     0,     0,     0,     0,
     247,     0,     0,     0,     0,     0,   687,   689,   248,     0,
       0,     0,   104,   105,     0,     0,   106,     0,   107,     0,
       0,   249,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,     0,   162,   163,
       0,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,     0,   174,   175,   176,     0,
       0,     0,     0,   177,     0,     0,     0,   243,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,     0,    10,
       0,    11,     0,    12,    13,    14,    15,    16,  -324,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,     0,     0,     0,     0,    28,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
      34,    35,     0,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,   824,     0,     0,   825,     0,     0,
       0,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,    44,    45,    46,  -116,  -116,    47,    48,    49,
       0,    50,    51,    52,     0,     0,    53,  -116,     0,    54,
       0,    55,    56,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59,   867,   869,
       0,     0,    60,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
      61,     0,     0,     0,    62,     0,     0,     0,     0,    63,
       0,     0,    64,     0,     0,     0,    65,     0,     0,   884,
      86,    87,    88,     0,    89,    90,    91,    92,    66,     0,
       0,     0,     0,     0,     0,     0,   886,   887,     0,     0,
       0,     0,     0,     0,   888,     0,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,   894,     0,     0,
     896,   897,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
      95,    96,    97,    98,    99,   100,   101,     0,     0,   916,
       0,   917,     0,     0,     0,     0,     0,   102,     0,     0,
     103,     0,     0,     0,     0,   241,   395,   396,   397,   398,
       0,     0,   585,   242,   933,   934,   935,   104,   105,     0,
       0,   106,     0,   107,   943,   944,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   422,   158,   159,
     160,   161,     0,   162,   163,     0,   164,   165,   166,     0,
     167,   168,   169,   170,   171,   172,   173,     0,  1007,     0,
       0,   174,   175,   176,     0,     0,   386,   387,   177,     0,
       0,     0,   243,   388,   389,   390,   391,   392,   393,   394,
       0,     0,     0,  1020,     0,     0,     0,     0,     0,     0,
       0,     0,   386,   387,     0,     0,     0,     0,  1023,   388,
     389,   390,   391,   392,   393,   394,  1026,   386,   387,     0,
    1028,     0,     0,  1029,   388,   389,   390,   391,   392,   393,
     394,     0,     0,     0,     0,     0,     0,  1040,     0,     0,
       0,     0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,
    1050,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,     0,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   397,   398,     0,     0,     0,     0,   459,     0,     0,
       0,     0,  1091,     0,     0,     0,     0,  1095,    95,    96,
      97,    98,    99,   100,   101,   395,   396,   397,   398,     0,
       0,     0,     0,   667,     0,   102,     0,     0,   103,     0,
     395,   396,   397,   398,     0,     0,  1117,     0,   702,     0,
       0,   497,     0,     0,     0,   104,   105,     0,     0,   106,
       0,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   158,   159,   160,   161,
       0,   162,   163,     0,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,     0,   174,
     175,   176,     0,     0,     0,     0,   177,    86,    87,    88,
     243,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,   386,   387,     0,   102,     0,     0,   103,   388,   389,
     390,   391,   392,   393,   394,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   104,   105,     0,     0,   106,     0,
     107,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,     0,
     162,   163,     0,   164,   165,   166,     0,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,     0,   174,   175,
     176,     0,     0,     0,     0,   177,    86,    87,    88,   243,
      89,    90,    91,    92,   395,   396,   397,   398,     0,     0,
       0,     0,   703,   395,   396,   397,   398,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   386,   387,   102,     0,     0,   103,     0,   388,   389,
     390,   391,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   175,   176,
       0,     0,     0,     0,   177,   475,    86,    87,    88,     0,
      89,    90,    91,    92,   395,   396,   397,   398,     0,     0,
       0,     0,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   386,   387,   102,     0,     0,   103,     0,   388,   389,
     390,   391,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   175,   176,
       0,     0,     0,     0,   177,   528,    86,    87,    88,     0,
      89,    90,    91,    92,   395,   396,   397,   398,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   386,   387,   103,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   175,   176,
       0,     0,     0,     0,   177,   538,    86,    87,    88,     0,
      89,    90,    91,    92,     0,   255,     0,   395,   396,   397,
     398,     0,     0,     0,     0,   707,     0,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
     386,   387,     0,   102,     0,     0,   103,   388,   389,   390,
     391,   392,   393,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   175,   176,
       0,    86,    87,    88,   177,    89,    90,    91,    92,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,     0,
       0,   720,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,   386,   387,     0,   102,     0,
       0,   103,   388,   389,   390,   391,   392,   393,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,   106,     0,   107,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,     0,   162,   163,     0,   164,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,     0,     0,
       0,     0,   174,   175,   176,     0,    86,    87,    88,   177,
      89,    90,    91,    92,     0,   467,     0,     0,   395,   396,
     397,   398,     0,     0,     0,     0,   741,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
     386,   387,     0,   102,     0,     0,   103,   388,   389,   390,
     391,   392,   393,   394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,   106,     0,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   175,   176,
       0,    86,    87,    88,   177,    89,    90,    91,    92,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,     0,
       0,   748,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,    88,
       0,   103,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,   106,     0,   107,    94,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,     0,   162,   163,     0,   164,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,   106,     0,
     107,     0,   174,   175,   176,     0,     0,     0,    88,   177,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   135,   136,   137,    94,   139,     0,   141,   142,   143,
       0,     0,     0,     0,   148,   149,   150,     0,     0,   153,
       0,   155,     0,   157,     0,     0,   159,     0,   161,     0,
       0,   163,     0,     0,   165,   166,     0,   167,   168,     0,
     170,     0,   172,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,    88,   185,   549,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,   107,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     135,   136,   137,     0,   139,     0,   141,   142,   143,     0,
       0,     0,     0,   148,   149,   150,     0,     0,   153,     0,
     155,     0,   157,     0,     0,   159,     0,   161,     0,     0,
     163,     0,     0,   165,   166,    88,   167,   168,     0,   170,
      92,   172,     0,   106,     0,   107,     0,     0,   175,     0,
       0,     0,     0,     0,   185,   551,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   135,   136,   137,     0,
     139,     0,   141,   142,   143,     0,     0,     0,     0,   148,
     149,   150,    88,     0,   153,     0,   155,    92,   157,     0,
       0,   159,     0,   161,     0,     0,   163,     0,     0,   165,
     166,     0,   167,   168,     0,   170,     0,   172,    94,     0,
       0,     0,     0,     0,   175,     0,   670,     0,     0,     0,
     185,   553,     0,     0,   106,     0,   107,     0,     0,     0,
       0,     0,     0,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   135,   136,   137,
       0,   139,    88,   141,   142,   143,     0,    92,     0,     0,
     148,   149,   150,   868,     0,   153,     0,   155,     0,   157,
       0,   106,   159,   107,   161,     0,     0,   163,    94,     0,
     165,   166,     0,   167,   168,     0,   170,     0,   172,     0,
       0,     0,     0,     0,     0,   175,     0,     0,   129,   130,
     131,   185,     0,     0,   135,   136,   137,     0,   139,    88,
     141,   142,   143,     0,    92,     0,     0,   148,   149,   150,
       0,     0,   153,     0,   155,     0,   157,     0,     0,   159,
       0,   161,     0,     0,   163,    94,     0,   165,   166,     0,
     167,   168,     0,   170,     0,   172,   395,   396,   397,   398,
       0,   106,   175,   107,   749,     0,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   135,   136,   137,     0,   139,     0,
     141,   142,   143,     0,     0,     0,     0,   148,   149,   150,
       0,     0,   153,     0,   155,     0,   157,     0,   106,   159,
     107,   161,     0,     0,   163,     0,     0,   165,   166,     0,
     167,   168,     0,   170,     0,   172,     0,     0,     0,     0,
       0,     0,   175,     0,     0,   129,   130,   131,   185,     0,
       0,   135,   136,   137,     0,   139,     0,   141,   142,   143,
       0,     0,     0,     0,   148,   149,   150,     0,     0,   153,
       0,   155,     0,   157,     0,     0,   159,     0,   161,     0,
       0,   163,     0,     0,   165,   166,     0,   167,   168,     0,
     170,     0,   172,     6,     7,     8,     0,     0,     0,   175,
       9,     0,     0,     0,    10,   823,    11,     0,    12,    13,
      14,    15,    16,  -324,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,     0,     0,     0,
       0,    28,   -10,   -10,    29,     0,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,     0,    44,    45,    46,
       0,     0,    47,    48,    49,     0,    50,    51,    52,     0,
       0,    53,     0,     0,    54,     0,    55,    56,     0,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,     0,     0,     0,     0,     0,     0,     0,
      57,    58,    59,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    62,
       0,     0,     0,     0,    63,     0,     0,    64,     0,     0,
       0,    65,     0,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    66,    10,     0,    11,     0,    12,    13,
      14,    15,    16,  -324,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,   -10,     0,     0,
       0,    28,   -10,     0,    29,     0,     0,     0,     0,     0,
       0,    30,    31,    32,    33,    34,    35,     0,     0,     0,
      36,    37,   395,   396,   397,   398,     0,     0,     0,     0,
     818,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,     0,    44,    45,    46,
       0,     0,    47,    48,    49,     0,    50,    51,    52,     0,
       0,    53,   386,   387,    54,     0,    55,    56,     0,   388,
     389,   390,   391,   392,   393,   394,   386,   387,     0,     0,
       0,     0,     0,   388,   389,   390,   391,   392,   393,   394,
      57,    58,    59,   386,   387,     0,     0,    60,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    62,
       0,     0,     0,     0,    63,   386,   387,    64,     0,     0,
       0,    65,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,    66,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   386,   387,     0,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,     0,     0,     0,     0,   395,   396,   397,   398,     0,
       0,     0,     0,   839,     0,     0,     0,     0,     0,   395,
     396,   397,   398,     0,     0,     0,     0,   840,     0,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,     0,     0,   847,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,     0,     0,   850,     0,     0,     0,
       0,     0,   395,   396,   397,   398,     0,     0,     0,     0,
     851,     0,     0,     0,     0,     0,   395,   396,   397,   398,
       0,     0,     0,     0,   856,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   386,   387,     0,     0,   857,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   386,   387,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,     0,
       0,   914,     0,     0,     0,     0,     0,   395,   396,   397,
     398,   386,   387,     0,     0,   919,     0,     0,   388,   389,
     390,   391,   392,   393,   394,   386,   387,     0,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,     0,     0,   930,     0,     0,     0,     0,
       0,   395,   396,   397,   398,     0,     0,     0,     0,   978,
       0,     0,     0,     0,     0,   395,   396,   397,   398,   386,
     387,     0,     0,   979,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
       0,     0,     0,     0,   395,   396,   397,   398,     0,     0,
       0,     0,  1009,     0,     0,     0,     0,     0,   395,   396,
     397,   398,     0,     0,     0,     0,  1058,     0,     0,     0,
       0,     0,   395,   396,   397,   398,     0,     0,     0,     0,
    1075,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,     0,     0,  1110,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,   685,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,   704,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   386,   387,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,   721,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,   386,   387,   723,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,   724,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,     0,     0,   728,     0,     0,
       0,     0,     0,     0,     0,   395,   396,   397,   398,   386,
     387,   731,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   386,   387,     0,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,     0,     0,   732,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,   386,   387,   734,     0,
       0,     0,     0,   388,   389,   390,   391,   392,   393,   394,
     386,   387,     0,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,   735,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
       0,     0,   736,     0,     0,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   386,   387,   737,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   397,   398,     0,     0,   738,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,   739,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,   740,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,   386,   387,   742,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,   752,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,   386,   387,   753,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   386,   387,     0,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,     0,     0,   758,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,   780,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,     0,     0,   822,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,     0,     0,   922,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
       0,     0,   939,     0,     0,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   386,   387,   940,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   386,   387,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,   947,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,   386,   387,   948,     0,     0,     0,     0,   388,   389,
     390,   391,   392,   393,   394,   386,   387,     0,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     0,     0,   949,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,     0,     0,   950,     0,     0,
       0,     0,     0,     0,     0,   395,   396,   397,   398,   386,
     387,   951,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,     0,     0,     0,
       0,     0,     0,     0,   395,   396,   397,   398,     0,     0,
     956,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,     0,     0,   957,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,     0,     0,   960,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,   961,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,   962,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
     386,   387,   963,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   386,   387,     0,     0,     0,     0,     0,   388,
     389,   390,   391,   392,   393,   394,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,   964,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,   967,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,   386,   387,   968,     0,     0,
       0,     0,   388,   389,   390,   391,   392,   393,   394,   386,
     387,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,   971,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,   977,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,     0,     0,   980,     0,     0,
       0,     0,     0,     0,     0,   395,   396,   397,   398,   386,
     387,   995,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   386,   387,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   386,   387,     0,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,     0,     0,  1037,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,   386,   387,  1041,     0,
       0,     0,     0,   388,   389,   390,   391,   392,   393,   394,
     386,   387,     0,     0,     0,     0,     0,   388,   389,   390,
     391,   392,   393,   394,   386,   387,     0,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,   386,   387,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,     0,     0,  1051,     0,
       0,     0,     0,     0,     0,     0,   395,   396,   397,   398,
       0,     0,  1059,     0,     0,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   386,   387,  1061,     0,     0,     0,
       0,   388,   389,   390,   391,   392,   393,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   397,   398,     0,     0,  1062,     0,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,     0,     0,  1064,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,  1097,     0,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,     0,     0,  1128
};

static const yytype_int16 yycheck[] =
{
       2,   305,    39,    12,   195,     0,    46,    47,   828,   829,
      14,    15,    76,    12,    16,   271,   272,     4,    75,     4,
       7,   212,     7,    76,    58,    75,    58,    29,    60,    61,
      32,    91,    92,    35,    36,    37,    40,    16,   187,    41,
      42,    43,    25,   103,   192,   194,   194,     3,    50,   187,
      12,     7,     8,     9,    10,     4,   194,   187,     7,    28,
      62,    44,     4,     5,   194,    44,     1,    42,    43,    12,
      87,   192,     3,   194,   191,     1,     7,     8,     9,    10,
      70,    71,    72,    73,    74,    75,   187,    62,    13,   187,
     187,   192,   192,   194,    11,    97,   194,   194,   187,    28,
     191,    63,    64,   192,    33,   194,   206,   207,    70,    71,
      72,    73,    74,    75,    76,   109,   192,    52,   194,     7,
      63,    64,   186,   187,   188,   189,    52,    70,    71,    72,
      73,    74,    75,    76,   191,   188,   189,    94,    63,    64,
     191,   191,    46,   275,   276,    70,    71,    72,    73,    74,
      75,    76,   191,    70,    71,    72,    73,    74,    75,    63,
      64,   195,   192,   195,   194,   191,    70,    71,    72,    73,
      74,    75,    76,   187,   176,   177,   187,   187,   187,   187,
     194,  1001,   192,   194,  1004,   194,   194,   189,   191,   131,
     132,   133,   194,   293,   294,   194,   187,   187,   235,   236,
      44,   192,   192,   194,   191,   191,   191,   187,    75,   211,
     187,    75,   468,   187,   194,   255,   218,   194,   192,    24,
     194,   261,   262,   191,   186,   187,   188,   189,   484,   485,
     186,   187,   194,   192,   187,   194,   427,   191,   370,   241,
     372,   243,    59,   186,   187,   188,   189,   287,   288,   289,
     187,   507,     4,     5,     4,   186,   187,   194,   358,   359,
     195,   186,   187,   188,   189,    58,   306,     4,     5,   195,
     187,    88,    89,    90,  1094,   277,   187,   212,    95,   191,
     187,   192,   186,   187,   188,   189,   212,   194,   290,   180,
     181,   182,   183,   295,   296,   187,   298,   299,   300,   301,
     302,   303,   194,    35,    36,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   191,   302,   303,   187,
     191,   333,   334,   335,   336,   337,   194,   339,   191,   341,
     191,   441,   442,   318,   187,   187,   446,   447,    46,   192,
     192,   194,   194,   187,   356,   191,   187,   187,   192,   361,
     194,   192,   192,   194,   194,    63,    64,     4,     5,     4,
       5,   191,    70,    71,    72,    73,    74,    75,    76,   191,
      71,   356,    73,    74,    75,    76,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,    75,    76,   187,
     402,   191,   187,     5,   192,   187,   194,   191,    10,   194,
     187,   187,   194,   187,   451,   194,   192,   194,   192,    20,
      21,   191,   613,   187,   464,   187,   428,   467,   192,    31,
     192,   433,     4,     5,    70,    71,    72,    73,    74,    75,
     193,   194,   444,   445,    70,    71,    72,    73,    74,    75,
     191,   187,     4,     5,     3,   457,   192,   459,     7,     8,
       9,   187,    63,    64,    85,    86,   192,   469,   470,    70,
      71,    72,    73,    74,    75,    76,   478,   479,   480,   481,
     187,   191,   187,   787,     5,   192,   790,   192,   186,   187,
     188,   189,   427,    51,   187,   186,   187,   188,   189,   192,
     194,   427,   104,   191,   106,    63,    64,   191,   186,   187,
     188,   189,    70,    71,    72,    73,    74,    75,    76,   191,
     187,     4,     5,   623,   624,   192,   626,   627,   187,   131,
     132,   133,   194,   192,   191,   137,   138,   139,   191,   141,
     187,   143,   144,   145,   194,   192,   191,   482,   150,   151,
     152,   187,   191,   155,   187,   157,   482,   159,   194,   192,
     162,   187,   164,    49,    50,   167,   192,   191,   170,   171,
     187,   173,   174,   187,   176,   192,   178,   187,   192,   187,
     191,   681,   192,   185,   192,   186,   187,   188,   189,   191,
     192,   593,   594,     4,     5,   187,   187,   187,    63,    64,
     192,   192,   192,   859,   191,    70,    71,    72,    73,    74,
      75,    76,    39,    40,   616,     4,     5,   621,   622,   875,
      74,    75,    76,   814,    60,    61,   191,   191,   186,   187,
     188,   189,    70,    71,    72,    73,    74,    75,   678,   187,
     187,   643,   192,   194,   192,   192,   191,   649,   650,   187,
     191,   653,   187,   187,   192,   695,   696,   192,   192,   191,
     191,   187,   187,    63,    64,   667,   192,   192,   191,   191,
      70,    71,    72,    73,    74,    75,    76,   191,   613,   719,
     682,   683,   684,   187,   187,   187,    63,   613,   192,   192,
     192,   191,   694,    70,    71,    72,    73,    74,    75,    76,
     702,   703,   187,   705,   706,   707,   194,   192,    70,    71,
      72,    73,    74,    75,   187,   717,   718,   191,   720,   192,
     191,   186,   187,   188,   189,   727,   194,   192,   730,   194,
     191,   191,   186,   187,   188,   189,   191,   837,   838,   741,
     191,     3,   744,   745,   746,   191,   748,   749,   191,   187,
      73,    74,    75,    76,   192,   757,   194,   191,    20,   191,
     191,    23,   191,   191,    43,   191,   191,   191,   191,   191,
      32,   191,   191,   191,    36,    37,   191,   191,   191,    41,
     192,   783,   784,   785,   786,   191,   186,   187,   188,   189,
     191,    53,    54,    55,   194,   191,   798,   799,   191,   191,
      62,    63,    64,    65,    66,   191,   191,   191,   191,   186,
     187,   188,   189,   191,    75,   191,   818,   191,   191,    63,
      64,   191,   191,   923,   924,   187,    70,    71,    72,    73,
      74,    75,    76,   191,   191,   191,   191,   839,   840,   191,
    1031,  1032,   844,   845,    63,    64,   191,   191,   850,   851,
     191,    70,    71,    72,    73,    74,    75,    76,   191,   191,
     191,   191,   191,   186,   187,   188,   189,   191,    76,   844,
     845,    14,   191,    16,   191,    18,   192,   192,   191,   814,
     191,  1072,    71,    72,    73,    74,    75,    76,   814,   194,
     191,  1082,    14,   191,    16,  1086,    18,   194,    41,   903,
     904,    44,   192,   192,    46,   945,    49,   909,  1099,    43,
     191,   191,   914,    10,   191,   177,   194,   919,   194,    41,
     194,   194,    44,   185,    63,    64,   192,    49,   192,   191,
      43,    70,    71,    72,    73,    74,    75,    76,   192,   194,
     942,   192,   186,   187,   188,   189,   191,   194,   192,   211,
     194,   191,   194,   192,   192,   192,   218,   959,    14,   192,
      16,   192,    18,   192,   966,   192,   194,   186,   187,   188,
     189,   973,   192,   975,    14,   194,    16,   979,    18,   191,
     242,   191,    84,   192,    84,    41,   988,   192,    44,   192,
     252,   192,     5,    49,   194,   997,   194,   186,   187,   188,
     189,    41,   192,    58,    44,   192,   192,   192,   191,    49,
      63,    64,  1014,   191,   194,   192,   278,    70,    71,    72,
      73,    74,    75,    76,   191,    43,   192,   192,    38,   291,
     191,  1033,    43,   192,   192,    58,    75,    75,    75,    48,
     302,   192,   192,   191,   191,    47,   191,   186,   187,   188,
     189,    63,    64,   192,   191,   194,  1058,   192,    70,    71,
      72,    73,    74,    75,    76,  1067,   328,   329,   330,   331,
     332,    75,   192,  1075,  1076,    38,   338,     4,   340,   482,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,  1031,  1032,   360,    52,
     362,   363,   364,   365,   366,  1031,  1032,   369,  1110,   371,
      52,   373,   374,   375,   305,   451,   798,   379,   380,   381,
     382,   383,   384,   385,     4,     3,     4,     5,   625,     7,
       8,     9,    10,   186,   187,   188,   189,  1072,   628,   192,
     402,   194,  1056,   909,  1126,   448,  1072,  1082,  1078,   826,
      -1,  1086,    30,    31,   461,    -1,  1082,    -1,    -1,    -1,
    1086,    -1,    -1,    -1,  1099,    -1,    -1,    -1,   430,    -1,
      -1,    -1,    -1,  1099,   186,   187,   188,   189,    -1,    -1,
     192,    -1,   194,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,   465,    -1,    83,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,   478,   479,    96,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,   195,     4,     5,
       6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   646,    -1,    -1,   649,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,   105,
      -1,   107,   108,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   710,   711,
      -1,    -1,   138,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,   168,    -1,    -1,    -1,   172,    -1,    -1,   751,
       3,     4,     5,    -1,     7,     8,     9,    10,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   768,   769,    -1,    -1,
      -1,    -1,    -1,    -1,   776,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,
     792,   793,    -1,    -1,    -1,    -1,   798,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,   821,
      -1,   823,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,   186,   187,   188,   189,
      -1,    -1,   192,    96,   846,   847,   848,   100,   101,    -1,
      -1,   104,    -1,   106,   856,   857,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   909,   161,   162,
     163,   164,    -1,   166,   167,    -1,   169,   170,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,    -1,   930,    -1,
      -1,   184,   185,   186,    -1,    -1,    63,    64,   191,    -1,
      -1,    -1,   195,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,   955,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,   970,    70,
      71,    72,    73,    74,    75,    76,   978,    63,    64,    -1,
     982,    -1,    -1,   985,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,   999,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1008,  1009,  1010,  1011,
    1012,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,  1074,    -1,    -1,    -1,    -1,  1079,    63,    64,
      65,    66,    67,    68,    69,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,    80,    -1,    -1,    83,    -1,
     186,   187,   188,   189,    -1,    -1,  1108,    -1,   194,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,     3,     4,     5,
     195,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    80,    -1,    -1,    83,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,   100,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,   162,   163,   164,    -1,
     166,   167,    -1,   169,   170,   171,    -1,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,     3,     4,     5,   195,
       7,     8,     9,    10,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    80,    -1,    -1,    83,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,   192,     3,     4,     5,    -1,
       7,     8,     9,    10,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    80,    -1,    -1,    83,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,   192,     3,     4,     5,    -1,
       7,     8,     9,    10,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    63,    64,    83,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,   192,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    12,    -1,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
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
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,     3,     4,     5,   191,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   184,   185,   186,    -1,     3,     4,     5,   191,
       7,     8,     9,    10,    -1,    12,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
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
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,     3,     4,     5,   191,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
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
      -1,   173,   174,   175,   176,   177,   178,   179,   104,    -1,
     106,    -1,   184,   185,   186,    -1,    -1,    -1,     5,   191,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,   137,   138,   139,    31,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,
      -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,
     176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,     5,   191,   192,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,   106,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,    -1,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,   151,   152,    -1,    -1,   155,    -1,
     157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,    -1,
     167,    -1,    -1,   170,   171,     5,   173,   174,    -1,   176,
      10,   178,    -1,   104,    -1,   106,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
     151,   152,     5,    -1,   155,    -1,   157,    10,   159,    -1,
      -1,   162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,
     171,    -1,   173,   174,    -1,   176,    -1,   178,    31,    -1,
      -1,    -1,    -1,    -1,   185,    -1,    96,    -1,    -1,    -1,
     191,   192,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,     5,   143,   144,   145,    -1,    10,    -1,    -1,
     150,   151,   152,    96,    -1,   155,    -1,   157,    -1,   159,
      -1,   104,   162,   106,   164,    -1,    -1,   167,    31,    -1,
     170,   171,    -1,   173,   174,    -1,   176,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,   131,   132,
     133,   191,    -1,    -1,   137,   138,   139,    -1,   141,     5,
     143,   144,   145,    -1,    10,    -1,    -1,   150,   151,   152,
      -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,
      -1,   164,    -1,    -1,   167,    31,    -1,   170,   171,    -1,
     173,   174,    -1,   176,    -1,   178,   186,   187,   188,   189,
      -1,   104,   185,   106,   194,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,    -1,   155,    -1,   157,    -1,   159,    -1,   104,   162,
     106,   164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,
     173,   174,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,    -1,   131,   132,   133,   191,    -1,
      -1,   137,   138,   139,    -1,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,
      -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,
     176,    -1,   178,     4,     5,     6,    -1,    -1,    -1,   185,
      11,    -1,    -1,    -1,    15,   191,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,   107,   108,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,   165,    -1,    -1,   168,    -1,    -1,
      -1,   172,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
      11,    -1,    -1,   184,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,    63,    64,   105,    -1,   107,   108,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
     131,   132,   133,    63,    64,    -1,    -1,   138,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,   165,    63,    64,   168,    -1,    -1,
      -1,   172,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,   184,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,    -1,    -1,   194,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,    63,    64,    -1,    -1,   194,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    63,    64,    -1,    -1,   194,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,    63,
      64,    -1,    -1,   194,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,    -1,    -1,   194,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    63,    64,   192,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,    63,
      64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    63,    64,   192,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,    63,    64,   192,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    63,    64,   192,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    63,    64,   192,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   186,   187,
     188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,    63,    64,   192,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    63,    64,   192,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,    63,
      64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      63,    64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    63,    64,   192,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,    63,
      64,   192,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,    63,    64,   192,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   186,   187,   188,   189,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,    63,    64,   192,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   180,   181,   182,   183,   197,     4,     5,     6,    11,
      15,    17,    19,    20,    21,    22,    23,    26,    27,    28,
      29,    30,    31,    32,    33,    35,    36,    37,    42,    45,
      52,    53,    54,    55,    56,    57,    61,    62,    77,    78,
      79,    80,    81,    82,    88,    89,    90,    93,    94,    95,
      97,    98,    99,   102,   105,   107,   108,   131,   132,   133,
     138,   156,   160,   165,   168,   172,   184,   198,   199,   201,
     208,   209,   211,   212,   216,   228,   229,   234,   240,   247,
     255,   263,   266,   270,   273,   279,     3,     4,     5,     7,
       8,     9,    10,    30,    31,    63,    64,    65,    66,    67,
      68,    69,    80,    83,   100,   101,   104,   106,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   161,   162,
     163,   164,   166,   167,   169,   170,   171,   173,   174,   175,
     176,   177,   178,   179,   184,   185,   186,   191,   214,   215,
     217,   223,   225,   228,   229,   191,   214,   234,     0,    75,
     191,    75,   191,   248,   267,   271,     4,     7,   226,   226,
     226,    34,   217,   202,   203,   214,   191,   191,   214,    28,
       7,   256,   264,   217,    58,    60,    61,   195,   302,   206,
     214,   217,     4,     5,   227,   217,   214,   217,   214,   217,
       4,     5,   290,   291,    10,   186,   187,   224,   225,   292,
     226,    88,    96,   195,   214,   217,   303,    88,    96,   109,
     303,   303,    87,   217,   222,    12,    53,   222,   222,    59,
      88,    89,    90,    95,    94,   217,   209,   216,   228,   229,
     214,   214,   214,   109,   191,   191,   191,   191,   191,   214,
     303,   214,   214,   214,   214,    44,   200,    91,    92,   103,
      75,    75,    24,   191,   191,   191,   191,   217,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   217,   214,   217,    70,
      71,    72,    73,    74,    75,   187,    63,    64,    70,    71,
      72,    73,    74,    75,    76,   186,   187,   188,   189,   214,
     217,   230,   231,   214,   230,     4,   217,   199,    35,    36,
      20,    21,     4,     5,   241,   242,     4,     5,   243,   244,
     230,   230,   214,   217,   258,   199,   274,   280,   191,    58,
     191,     4,     7,   191,   214,   217,   293,    58,   195,   295,
     300,   191,   191,   194,   194,   194,   191,   191,   194,   225,
     225,   194,   217,   214,   217,    11,   194,   194,   214,   194,
     222,   207,    12,   194,   210,   194,   222,    12,   222,   210,
     210,     5,   213,   213,   213,   192,   217,   214,   194,   194,
     194,   194,    43,   222,   222,   222,   217,   214,   235,   230,
     230,   217,   217,   217,   217,   217,   217,    96,   214,   303,
     303,     4,     5,   220,   221,   220,   221,   222,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   303,
     217,   217,   217,   217,   217,   217,   217,   217,   192,   217,
     214,   214,   214,   214,   214,   217,   217,   217,   192,   217,
     217,   214,   217,   214,   217,   214,   214,   192,   214,   192,
     214,   192,   214,   192,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   303,   214,   230,   230,   214,   217,
     214,   214,   214,   214,   214,   192,   192,   214,   213,   214,
     213,   214,   214,   214,   192,   192,   214,   214,   214,   214,
     214,   214,   214,   219,   218,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   192,   214,   217,   232,
     233,   192,    75,   268,    14,    16,    18,    41,    44,    49,
     272,   204,   205,   191,   191,   194,   191,   191,   194,   192,
     192,    43,   257,    14,    16,    18,    41,    44,    49,   265,
      46,   199,   217,   191,   214,   217,    51,   294,   193,   194,
     191,     4,     7,   191,    10,   301,   230,   230,     4,     5,
     217,   217,   230,   230,   291,    10,   224,   194,    85,    86,
      96,   214,   217,   217,   295,   222,   214,   222,   210,   217,
     217,   191,   194,   194,   194,   192,   192,   214,   217,   214,
     217,   217,   217,   201,   194,   210,   210,     4,     5,   239,
     192,   192,   194,   194,   192,   194,   194,   194,   192,   192,
     194,   194,   192,   191,   191,   192,   192,   194,   194,   210,
     194,   192,   192,   192,   192,   192,   192,   194,   192,   192,
     194,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   194,   192,   192,   194,   194,   194,   192,   194,   194,
     192,   194,   192,   192,   192,   192,   192,   194,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   194,   194,
     192,   192,   192,   192,   192,   192,   194,   192,   192,   192,
     192,   192,   192,   194,   194,   194,   194,   194,   192,   194,
     194,   192,   194,   194,   192,   192,   217,   217,   194,   249,
     199,   217,   226,   304,   226,   305,   230,   230,   242,   230,
     230,   244,    43,   259,   275,    49,    50,   281,   194,   217,
     192,   194,   192,   191,   214,   214,   217,   217,   296,   297,
     217,     4,     5,   287,   289,   192,   192,   191,   191,   194,
     194,   192,   192,   217,    84,    84,   194,   194,   194,   222,
     194,   194,   230,   217,   217,   217,   194,   194,   217,   222,
     222,   236,   217,   217,   217,   217,   217,   214,    96,   214,
     192,   192,   217,   217,   222,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   214,   217,   214,   214,   214,   217,
     217,   217,   217,   221,   214,   221,   214,   214,   233,   217,
      16,    44,   269,   194,   194,   192,   192,   192,   192,    39,
      40,   261,   199,   217,   194,    58,   214,   214,   294,   194,
     287,   287,   192,   191,   191,   194,   230,   230,   217,   217,
     194,   303,   303,   214,   214,   214,   217,   217,   192,   192,
     192,   192,   194,   214,   214,   210,   191,   192,   192,   192,
     192,   192,   192,   192,   192,   194,   192,   192,   192,   210,
     192,   192,   192,   192,   192,   192,   194,   192,   192,   192,
     194,   192,   192,   194,   192,   194,   192,   192,   194,   194,
     192,   192,   194,   192,   192,   194,   192,   192,    12,   226,
     226,   258,    43,    38,   276,   192,   217,   191,   192,   194,
     217,   298,   230,   230,   288,   192,   192,   214,   194,   194,
      75,    75,    75,   217,   194,   222,     4,     5,   245,   246,
     214,   217,   217,   214,   217,   217,   214,   217,   214,   214,
     217,   260,   262,    48,   283,    60,    61,   192,   217,    58,
     214,   192,   287,   192,   192,   287,   214,   214,   214,   214,
     214,   192,   217,   191,   191,   192,   194,   192,   194,   192,
     192,   192,   192,   192,   192,   192,   192,    13,   253,   199,
     199,   217,    47,   282,   191,   194,   191,   192,   299,    75,
     192,   192,   237,   246,   217,   217,   250,    46,   286,   199,
     277,   214,   217,   217,   301,   214,   199,   192,   199,   284,
      14,    16,    18,    41,    44,    49,   278,   192,   194,   192,
     194,   287,    25,    44,   238,   251,   199,   214,   217,    14,
      16,    18,    41,    44,    49,   252,   285,   192,   192,     4,
     254,   283
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   196,   197,   197,   197,   197,   198,   199,   200,   199,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   201,
     203,   201,   201,   201,   201,   201,   201,   201,   204,   201,
     205,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   206,   201,   207,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   208,   208,   208,   208,
     208,   209,   209,   209,   209,   209,   209,   210,   210,   211,
     211,   211,   211,   211,   212,   212,   213,   213,   214,   214,
     214,   214,   214,   214,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   216,   216,   218,   217,   219,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     220,   221,   222,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   225,   225,   225,
     225,   226,   226,   227,   227,   227,   227,   228,   229,   231,
     230,   232,   232,   232,   233,   233,   235,   236,   237,   234,
     238,   238,   239,   239,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   243,   243,   244,   244,   244,   244,
     245,   245,   245,   246,   246,   246,   246,   248,   249,   250,
     251,   247,   252,   252,   252,   252,   252,   252,   253,   253,
     254,   254,   256,   255,   257,   257,   258,   258,   259,   260,
     259,   261,   262,   261,   264,   263,   265,   265,   265,   265,
     265,   265,   267,   268,   266,   269,   269,   271,   270,   272,
     272,   272,   272,   272,   272,   274,   275,   276,   277,   273,
     278,   278,   278,   278,   278,   278,   280,   279,   281,   281,
     282,   282,   283,   284,   285,   283,   286,   286,   287,   288,
     287,   289,   289,   289,   289,   290,   290,   291,   291,   291,
     291,   292,   292,   292,   292,   293,   293,   293,   293,   293,
     294,   294,   294,   296,   295,   297,   295,   298,   295,   299,
     295,   300,   295,   301,   301,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   303,
     303,   304,   304,   305,   305
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     0,     4,
       0,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     0,     3,
       0,     3,     1,     1,     2,     2,     3,     3,     0,     5,
       0,     5,     2,     1,     2,     1,     2,     4,     4,     2,
       3,     4,     4,     0,     3,     0,     4,     6,     2,     6,
       2,     2,     2,     1,     2,     1,     2,     2,     2,     5,
       7,     3,     2,     3,     4,     5,     3,     2,     4,     3,
       8,     6,     6,     2,     2,     5,     7,     4,     6,     8,
       5,     2,     2,     2,     2,     3,     2,     2,     1,     1,
       3,     4,     4,     4,     4,     4,     4,     1,     1,     2,
       1,     2,     2,     8,     6,     6,     0,     1,     1,     2,
       2,     3,    10,     8,     8,     8,     3,     1,     1,     6,
       4,     4,     6,     6,     4,     6,     1,     4,     1,     1,
       1,     1,     3,     3,     6,     6,     8,     6,     4,     6,
       8,     1,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     1,     3,     1,     3,
       4,     6,     6,     4,     6,     4,     6,    10,     4,     4,
       4,     8,     6,     4,     3,     3,     0,     4,     0,     4,
       2,     3,     3,     3,     3,     3,     3,     4,     6,     1,
       4,     4,     6,     6,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     4,     8,
       4,     4,     4,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     6,     6,     4,     6,     6,
       6,     4,     8,     6,     8,     6,     4,     4,     4,     6,
       6,     6,     8,     4,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     4,     6,     4,     6,     4,     4,     0,
       2,     0,     1,     3,     1,     1,     0,     0,     0,    11,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     3,
       1,     1,     4,     4,     1,     3,     1,     1,     4,     4,
       0,     1,     3,     1,     1,     3,     3,     0,     0,     0,
       0,    14,     1,     1,     1,     1,     1,     1,     0,     2,
       0,     1,     0,     7,     1,     2,     1,     1,     0,     0,
       5,     0,     0,     4,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     0,     6,     1,     1,     0,     4,     1,
       2,     1,     1,     1,     1,     0,     0,     0,     0,    11,
       1,     1,     1,     1,     1,     1,     0,     5,     1,     1,
       0,     2,     0,     0,     0,     7,     0,     1,     1,     0,
       4,     1,     4,     1,     4,     1,     3,     1,     4,     1,
       4,     1,     1,     3,     3,     0,     2,     4,     1,     3,
       0,     2,     6,     0,     4,     0,     4,     0,     6,     0,
       9,     0,     3,     0,     1,     0,     2,     2,     4,     1,
       4,     6,     6,     7,    10,    12,     7,    10,    12,     2,
       1,     1,     3,     1,     3
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
        case 6:

    {YYACCEPT;}

    break;

  case 8:

    {if (severity_so_far >= sERROR) {YYABORT;}}

    break;

  case 15:

    {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}

    break;

  case 16:

    {add_command(cERROR,NULL,NULL);}

    break;

  case 22:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 23:

    {add_command(cPOP_MULTI,NULL,NULL);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}

    break;

  case 24:

    {add_command(cPOP_MULTI,NULL,NULL);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}

    break;

  case 26:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 27:

    {create_call((yyvsp[0].symbol));add_command(cPOP,NULL,NULL);}

    break;

  case 28:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}

    break;

  case 30:

    {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}

    break;

  case 34:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 35:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 36:

    {create_exception(TRUE);}

    break;

  case 37:

    {create_exception(FALSE);}

    break;

  case 38:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 39:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 40:

    {add_command(cSKIPPER,NULL,NULL);}

    break;

  case 41:

    {add_command(cNOP,NULL,NULL);}

    break;

  case 42:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}

    break;

  case 43:

    {add_command(cCHECKOPEN,NULL,NULL);}

    break;

  case 44:

    {add_command(cCLOSE,NULL,NULL);}

    break;

  case 45:

    {add_command(cCHECKSEEK,NULL,NULL);}

    break;

  case 46:

    {add_command(cCOMPILE,NULL,NULL);}

    break;

  case 47:

    {create_execute(0);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 48:

    {create_execute(1);add_command(cPOP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 49:

    {create_function(fEVAL);add_command(cPOP,NULL,NULL);}

    break;

  case 50:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}

    break;

  case 51:

    {create_colour(0);create_pps(cPOPSTREAM,0);}

    break;

  case 52:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}

    break;

  case 53:

    {tileol=FALSE;}

    break;

  case 55:

    {tileol=TRUE;}

    break;

  case 57:

    {add_command(cGCOLOUR,NULL,NULL);}

    break;

  case 58:

    {add_command(cGCOLOUR2,NULL,NULL);}

    break;

  case 59:

    {add_command(cGBACKCOLOUR,NULL,NULL);}

    break;

  case 60:

    {add_command(cGBACKCOLOUR2,NULL,NULL);}

    break;

  case 63:

    {create_restore("");}

    break;

  case 64:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}

    break;

  case 65:

    {if (function_type!=ftNONE) {
	       add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;
	       add_command(cPOPSYMLIST,NULL,NULL);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL,NULL,NULL);
            } else {
               add_command(cRETURN_FROM_GOSUB,NULL,NULL);
            }}

    break;

  case 66:

    {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 67:

    {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL,NULL,NULL);}

    break;

  case 69:

    {create_openwin(FALSE);}

    break;

  case 70:

    {create_openwin(TRUE);}

    break;

  case 71:

    {add_command(cMOVEORIGIN,NULL,NULL);}

    break;

  case 72:

    {add_command(cDOT,NULL,NULL);}

    break;

  case 73:

    {add_command(cDOT,NULL,NULL);putindrawmode(dmCLEAR);}

    break;

  case 74:

    {create_line(2);}

    break;

  case 75:

    {create_line(2);putindrawmode(dmCLEAR);}

    break;

  case 76:

    {create_line(1);}

    break;

  case 77:

    {create_line(1);}

    break;

  case 78:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 79:

    {create_line(1);putindrawmode(dmCLEAR);}

    break;

  case 80:

    {add_command(cPUTBIT,NULL,NULL);}

    break;

  case 81:

    {create_pushstr("solid"); add_command(cPUTBIT,NULL,NULL);}

    break;

  case 82:

    {add_command(cPUTCHAR,NULL,NULL);}

    break;

  case 83:

    {create_line(-1);}

    break;

  case 84:

    {create_line(0);}

    break;

  case 85:

    {add_command(cCIRCLE,NULL,NULL);putindrawmode(0);}

    break;

  case 86:

    {add_command(cTRIANGLE,NULL,NULL);putindrawmode(0);}

    break;

  case 87:

    {add_command(cTEXT1,NULL,NULL);}

    break;

  case 88:

    {add_command(cTEXT2,NULL,NULL);}

    break;

  case 89:

    {add_command(cTEXT3,NULL,NULL);}

    break;

  case 90:

    {add_command(cRECT,NULL,NULL);putindrawmode(0);}

    break;

  case 91:

    {add_command(cCLOSEWIN,NULL,NULL);}

    break;

  case 92:

    {add_command(cCLEARWIN,NULL,NULL);}

    break;

  case 93:

    {add_command(cCLEARSCR,NULL,NULL);}

    break;

  case 94:

    {create_openprinter(0);}

    break;

  case 95:

    {create_openprinter(1);}

    break;

  case 96:

    {add_command(cCLOSEPRN,NULL,NULL);}

    break;

  case 97:

    {add_command(cWAIT,NULL,NULL);}

    break;

  case 98:

    {add_command(cBELL,NULL,NULL);}

    break;

  case 99:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 100:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 101:

    {create_function(fINKEY);add_command(cPOP,NULL,NULL);}

    break;

  case 102:

    {create_function(fSYSTEM);
	add_command(cPOP,NULL,NULL);}

    break;

  case 103:

    {create_poke('s');}

    break;

  case 104:

    {create_poke('d');}

    break;

  case 105:

    {create_poke('S');}

    break;

  case 106:

    {create_poke('D');}

    break;

  case 107:

    {add_command(cEND,NULL,NULL);}

    break;

  case 108:

    {create_pushdbl(0);add_command(cEXIT,NULL,NULL);}

    break;

  case 109:

    {add_command(cEXIT,NULL,NULL);}

    break;

  case 110:

    {create_docu((yyvsp[0].symbol));}

    break;

  case 111:

    {add_command(cBIND,NULL,NULL);}

    break;

  case 112:

    {add_command(cFRNBF_FREE,NULL,NULL);}

    break;

  case 113:

    {add_command(cFRNBF_SET_NUMBER, NULL, NULL);}

    break;

  case 114:

    {add_command(cFRNBF_SET_STRING, NULL, NULL);}

    break;

  case 115:

    {add_command(cFRNBF_SET_BUFFER, NULL, NULL);}

    break;

  case 116:

    {drawmode=0;}

    break;

  case 117:

    {drawmode=dmCLEAR;}

    break;

  case 118:

    {drawmode=dmFILL;}

    break;

  case 119:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 120:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 121:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 122:

    {create_changestring(fMID);}

    break;

  case 123:

    {create_changestring(fMID2);}

    break;

  case 124:

    {create_changestring(fLEFT);}

    break;

  case 125:

    {create_changestring(fRIGHT);}

    break;

  case 126:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 129:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 130:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 131:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 132:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 133:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 134:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 135:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 136:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 137:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 138:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 140:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 141:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 142:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 144:

    {create_function(fLEFT);}

    break;

  case 145:

    {create_function(fRIGHT);}

    break;

  case 146:

    {create_function(fMID);}

    break;

  case 147:

    {create_function(fMID2);}

    break;

  case 148:

    {create_function(fSTR);}

    break;

  case 149:

    {create_function(fSTR2);}

    break;

  case 150:

    {create_function(fSTR3);}

    break;

  case 151:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 152:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 153:

    {create_function(fINKEY);}

    break;

  case 154:

    {create_function(fCHR);}

    break;

  case 155:

    {create_function(fUPPER);}

    break;

  case 156:

    {create_function(fLOWER);}

    break;

  case 157:

    {create_function(fLTRIM);}

    break;

  case 158:

    {create_function(fRTRIM);}

    break;

  case 159:

    {create_function(fTRIM);}

    break;

  case 160:

    {create_function(fCHOMP);}

    break;

  case 161:

    {create_function(fSYSTEM2);}

    break;

  case 162:

    {create_function(fFRNFN_CALL2);}

    break;

  case 163:

    {create_function(fFRNBF_ALLOC);}

    break;

  case 164:

    {create_function(fFRNBF_DUMP);}

    break;

  case 165:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 166:

    {create_function(fDATE);}

    break;

  case 167:

    {create_function(fDATE);}

    break;

  case 168:

    {create_function(fTIME);}

    break;

  case 169:

    {create_function(fTIME);}

    break;

  case 170:

    {create_function(fPEEK2);}

    break;

  case 171:

    {create_function(fPEEK3);}

    break;

  case 172:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 173:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 174:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 175:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 176:

    {create_function(fGETBIT);}

    break;

  case 177:

    {create_function(fGETCHAR);}

    break;

  case 178:

    {create_function(fHEX);}

    break;

  case 179:

    {create_function(fBIN);}

    break;

  case 180:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 181:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 182:

    {create_function(fFRNBF_GET_BUFFER);}

    break;

  case 183:

    {create_function(fEVAL2);}

    break;

  case 184:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 185:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 186:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 187:

    {poplabel();create_boole('|');}

    break;

  case 188:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 189:

    {poplabel();create_boole('&');}

    break;

  case 190:

    {create_boole('!');}

    break;

  case 191:

    {create_dblrelop('=');}

    break;

  case 192:

    {create_dblrelop('!');}

    break;

  case 193:

    {create_dblrelop('<');}

    break;

  case 194:

    {create_dblrelop('{');}

    break;

  case 195:

    {create_dblrelop('>');}

    break;

  case 196:

    {create_dblrelop('}');}

    break;

  case 197:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 198:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 199:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 200:

    {add_command(cARDIM,"",NULL);}

    break;

  case 201:

    {add_command(cARDIM,"",NULL);}

    break;

  case 202:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 203:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 204:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 205:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 206:

    {create_dblbin('+');}

    break;

  case 207:

    {create_dblbin('-');}

    break;

  case 208:

    {create_dblbin('*');}

    break;

  case 209:

    {create_dblbin('/');}

    break;

  case 210:

    {create_dblbin('^');}

    break;

  case 211:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 212:

    {create_strrelop('=');}

    break;

  case 213:

    {create_strrelop('!');}

    break;

  case 214:

    {create_strrelop('<');}

    break;

  case 215:

    {create_strrelop('{');}

    break;

  case 216:

    {create_strrelop('>');}

    break;

  case 217:

    {create_strrelop('}');}

    break;

  case 220:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 221:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 223:

    {create_function(fSIN);}

    break;

  case 224:

    {create_function(fASIN);}

    break;

  case 225:

    {create_function(fCOS);}

    break;

  case 226:

    {create_function(fACOS);}

    break;

  case 227:

    {create_function(fTAN);}

    break;

  case 228:

    {create_function(fATAN);}

    break;

  case 229:

    {create_function(fATAN2);}

    break;

  case 230:

    {create_function(fEXP);}

    break;

  case 231:

    {create_function(fLOG);}

    break;

  case 232:

    {create_function(fLOG2);}

    break;

  case 233:

    {create_function(fSQRT);}

    break;

  case 234:

    {create_function(fSQR);}

    break;

  case 235:

    {create_function(fINT);}

    break;

  case 236:

    {create_function(fROUND);}

    break;

  case 237:

    {create_function(fCEIL);}

    break;

  case 238:

    {create_function(fFLOOR);}

    break;

  case 239:

    {create_function(fFRAC);}

    break;

  case 240:

    {create_function(fABS);}

    break;

  case 241:

    {create_function(fSIG);}

    break;

  case 242:

    {create_function(fMOD);}

    break;

  case 243:

    {create_function(fRAN);}

    break;

  case 244:

    {create_function(fRAN2);}

    break;

  case 245:

    {create_function(fMIN);}

    break;

  case 246:

    {create_function(fMAX);}

    break;

  case 247:

    {create_function(fLEN);}

    break;

  case 248:

    {create_function(fVAL);}

    break;

  case 249:

    {create_function(fASC);}

    break;

  case 250:

    {create_function(fDEC);}

    break;

  case 251:

    {create_function(fDEC2);}

    break;

  case 252:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 253:

    {create_function(fINSTR2);}

    break;

  case 254:

    {create_function(fRINSTR);}

    break;

  case 255:

    {create_function(fRINSTR2);}

    break;

  case 256:

    {create_function(fSYSTEM);}

    break;

  case 257:

    {create_function(fFRNFN_CALL);}

    break;

  case 258:

    {create_function(fFRNFN_SIZE);}

    break;

  case 259:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 260:

    {create_function(fFRNBF_SIZE);}

    break;

  case 261:

    {create_function(fPEEK4);}

    break;

  case 262:

    {create_function(fPEEK);}

    break;

  case 263:

    {create_function(fMOUSEX);}

    break;

  case 264:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 265:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 266:

    {create_function(fMOUSEY);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 268:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 269:

    {create_function(fMOUSEB);}

    break;

  case 270:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 271:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 272:

    {create_function(fMOUSEMOD);}

    break;

  case 273:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 274:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 275:

    {create_function(fAND);}

    break;

  case 276:

    {create_function(fOR);}

    break;

  case 277:

    {create_function(fBITNOT);}

    break;

  case 278:

    {create_function(fEOR);}

    break;

  case 279:

    {create_function(fSHL);}

    break;

  case 280:

    {create_function(fSHR);}

    break;

  case 281:

    {create_function(fTELL);}

    break;

  case 282:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 283:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 284:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 285:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 286:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 287:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 288:

    {create_myopen(0);}

    break;

  case 289:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 290:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 291:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 292:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 293:

    {create_function(fEVAL);}

    break;

  case 294:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 295:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 296:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 297:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 298:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 299:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 300:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 301:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 302:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 303:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 304:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 305:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 306:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 307:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 308:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 309:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 316:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 317:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 318:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 319:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 320:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 321:

    {missing_endsub--;}

    break;

  case 322:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 323:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 324:

    {exported=FALSE;}

    break;

  case 325:

    {exported=TRUE;}

    break;

  case 326:

    {exported=FALSE;}

    break;

  case 327:

    {exported=TRUE;}

    break;

  case 330:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 331:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 332:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 333:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 336:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 337:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 338:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 339:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 343:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 344:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 345:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 346:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 347:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 348:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     add_command(cRESETSKIPONCE2,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 349:

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

  case 350:

    {
             swap();popgoto();poplabel();}

    break;

  case 351:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 352:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 353:

    {missing_next--;}

    break;

  case 354:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 355:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 356:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 357:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 358:

    {create_pushdbl(1);}

    break;

  case 360:

    {pop(stSTRING);}

    break;

  case 361:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 362:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 363:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 369:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 370:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 372:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 374:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 376:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 377:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 378:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 379:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 380:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 381:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 382:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 383:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 385:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 386:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 387:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 389:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 390:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 391:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 392:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 393:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 394:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 395:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 396:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 397:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 398:

    {poplabel();}

    break;

  case 400:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 401:

    {missing_endif--;}

    break;

  case 402:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 403:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 404:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 405:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 406:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 408:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 409:

    {poplabel();}

    break;

  case 413:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 414:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 419:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 421:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 422:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 423:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 424:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 427:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 428:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 429:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 430:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 431:

    {create_strdata((yyvsp[0].string));}

    break;

  case 432:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 433:

    {create_strdata((yyvsp[0].string));}

    break;

  case 434:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 438:

    {create_print('s');}

    break;

  case 439:

    {create_print('s');}

    break;

  case 440:

    {create_print('d');}

    break;

  case 441:

    {create_print('u');}

    break;

  case 442:

    {create_print('U');}

    break;

  case 443:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 444:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 445:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 446:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 447:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 448:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 449:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 450:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 451:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 452:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 453:

    {create_pushstr("?");create_print('s');}

    break;

  case 454:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 455:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 457:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 460:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 461:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 462:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 463:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 464:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 465:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 466:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 467:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 468:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 471:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 472:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 473:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 474:

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
