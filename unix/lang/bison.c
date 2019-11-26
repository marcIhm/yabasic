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
    UMINUS = 435
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
#define YYFINAL  272
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  190
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   435

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   189,     2,     2,     2,     2,
     185,   186,   182,   181,   188,   180,     2,   183,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   187,
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
     175,   176,   177,   178,   179,   184
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   189,   190,   190,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   212,   213,   213,   214,   215,
     216,   217,   218,   219,   220,   220,   222,   222,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   234,
     235,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   252,   253,   254,   255,   256,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   315,   316,   317,   318,
     319,   320,   323,   324,   327,   328,   329,   330,   331,   334,
     335,   338,   339,   342,   343,   344,   345,   346,   347,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   391,   392,
     395,   395,   396,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   429,   432,   435,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   510,   511,   512,
     515,   516,   517,   518,   521,   522,   525,   526,   527,   528,
     531,   534,   537,   537,   540,   541,   542,   545,   546,   549,
     550,   553,   549,   558,   559,   562,   563,   566,   567,   568,
     569,   572,   573,   576,   577,   578,   579,   582,   583,   586,
     587,   588,   589,   592,   593,   594,   597,   598,   599,   600,
     603,   604,   608,   622,   603,   627,   628,   629,   630,   631,
     632,   635,   636,   639,   640,   645,   645,   649,   650,   653,
     654,   658,   660,   659,   664,   665,   665,   669,   669,   675,
     676,   677,   678,   679,   680,   684,   685,   684,   691,   692,
     696,   696,   701,   702,   703,   704,   705,   706,   709,   710,
     710,   712,   709,   716,   717,   718,   719,   720,   721,   724,
     724,   729,   730,   733,   734,   737,   739,   741,   738,   745,
     746,   749,   750,   750,   753,   754,   756,   757,   761,   762,
     765,   766,   768,   769,   773,   774,   775,   776,   779,   780,
     781,   782,   783,   786,   787,   788,   791,   791,   792,   792,
     793,   793,   794,   794,   795,   795,   798,   799,   802,   803,
     804,   805,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   815,   818,   819,   821,   822,   825,   826
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
      45,    43,    42,    47,   435,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -802

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-802)))

#define YYTABLE_NINF -389

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4202,   -23,   -21,  -802,  -802,  -802,  -802,  -802,   105,   105,
     105,  3092,  -802,  -802,  -802,  3798,  -154,  -132,  3798,    39,
      81,  -802,  -802,  -802,  3450,   -22,  -802,  3450,   128,  -802,
    3450,  3450,  3450,   143,    48,   105,  1812,  1193,  2178,    76,
    3450,  2913,  3450,   311,    17,  3450,  -802,    19,  3798,  3798,
    3798,    60,    11,    14,    54,    68,    95,  2178,  3798,  3798,
    3798,   183,   168,  -802,    27,  -802,  -802,  -802,  -802,   144,
     160,  -802,   303,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    3450,  -802,  3798,  -802,   332,  3450,  4044,  -802,  -802,  -802,
    -802,  -802,  -802,   162,   172,  -802,  -802,  -802,  -802,   187,
     204,   229,   208,   219,  3450,   225,   228,   232,   273,   281,
     299,   308,   312,   321,   338,   355,   388,   397,   401,   405,
     412,   426,   436,   452,   458,   465,   496,   506,   507,   508,
     517,   518,   520,   535,   542,   543,   545,   547,   550,   553,
     554,   555,   556,   557,   565,   566,   568,   569,   570,   572,
     573,   580,   581,   582,   587,   589,   590,   591,   592,   595,
     596,   597,   600,   601,   602,   603,   613,   615,   616,   618,
     619,   624,   627,   628,   629,   632,   633,   634,   635,   638,
     639,  3450,  3450,   260,  -802,   376,  -802,  -802,  -802,  -802,
     288,   521,  3798,   310,  -802,  -802,   310,  -802,  -802,  3450,
    4044,   528,   640,   445,   641,    25,  3450,   -40,   260,  5967,
     642,   645,   329,  5967,   260,  1313,   260,  1352,   647,   648,
     363,  -802,  -802,    83,    83,  -802,  -802,   441,  -802,  3450,
    3798,  3450,    32,  5967,   525,  -802,  -802,  -802,  -802,   531,
    3798,  1385,  -802,  3450,  -802,     5,   564,  -802,  -802,  3450,
    3271,  -802,  -802,  5967,  -802,  -802,   144,   160,   310,    -7,
      -7,  -802,   630,   630,   630,  2361,  3798,    85,   585,   310,
    -153,  -120,  -802,  -802,   493,  3450,  3450,  3450,  3450,  3798,
    -802,  5967,   446,  3450,   310,   643,   631,  5967,   497,  -802,
    -802,  -802,  -802,  3450,  3450,  1212,  3450,  3450,  3450,  3450,
    1995,  2178,   567,   567,  3450,  3450,  3450,  3450,  3450,  3450,
    3450,  3450,  3450,  3450,  3450,  3450,  2178,  3450,  3450,  3450,
    3450,  3450,  3450,  3450,  3450,  2545,  3798,  3798,  3798,  3798,
    3798,  3450,  3450,  3450,  2729,  3450,  3798,  3450,  3798,  3450,
    3798,  3798,   357,  1386,  1516,  3527,  3798,  3798,  3798,  3798,
    3798,  3798,  3798,  3798,  2178,  3798,  -802,  -802,  3798,  3450,
    3798,  3798,  3798,  3798,  3798,   649,   650,  3798,   630,  3798,
     630,  3798,   726,   279,   891,  3798,  3798,  3798,  3798,  3798,
    3798,  3798,  -802,  -802,  -802,  -802,  3450,  3450,  3450,  3450,
    3450,  3450,  3450,  3450,  3450,  3450,  3450,   652,   653,   646,
    -802,   654,   656,   655,  -802,  -141,   660,   662,   260,  5967,
     799,   504,   801,  4044,  3450,   665,  3798,  -802,  -802,  3450,
     260,   673,   451,   666,    26,  -802,   842,  -802,  -802,   637,
    3450,  3450,  -802,  -802,   143,  -802,  -802,    56,  1399,   310,
    5967,   561,  3631,  3450,   310,  3450,  -802,   -40,  -802,  -802,
    3450,  3798,  -802,  3450,     5,  3450,  3450,   672,   670,   671,
     680,  -802,  3471,  -137,  3450,  3450,  3450,  3450,  4044,   681,
       5,     5,  5967,   310,   644,  -802,   260,  5967,   686,  -802,
    -802,  -802,  4044,  -802,  -802,  3450,  -802,  -802,  -802,  -802,
     674,   689,  1525,  1539,  4626,  1560,  1682,  1716,   690,    71,
     691,   692,   696,   697,   698,   700,   695,   701,     5,  2009,
    4640,  4654,  4687,  4701,  4715,   720,  4775,   852,  4789,  4836,
     705,  4850,  4864,  4878,  4910,  4924,  4938,  4999,  2192,  -802,
    5013,   174,   -87,   -73,   -16,   188,  2376,  2560,   918,  -802,
    5059,  5073,   209,  5087,   -20,  5101,   247,   249,  -802,   250,
    -802,   256,  -802,   257,  -802,   276,   278,   286,   287,    -8,
       6,   289,   296,   300,   351,   707,    -2,   708,   710,   306,
    5134,   318,    70,    46,    62,    80,  -802,  -802,    89,   -57,
     103,   131,   137,  -802,  -802,   310,   310,   310,   310,   310,
     310,  -802,   105,   105,  3450,  3450,   534,   488,   625,    24,
      -5,    41,  -802,    34,    34,   726,   726,  -802,  -802,   288,
    -802,  -802,   521,  -802,  -802,  -802,   834,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,   604,  2747,  3450,    74,  5148,
    3869,  -802,  -802,  3450,  3450,  -802,  -802,  3450,  -802,   661,
     711,   712,   714,   719,  2927,  3106,   721,   723,  -802,  -802,
    -802,  3450,   821,   826,  -802,   157,  3285,  5967,  -802,  -802,
     158,  -802,  3450,  3680,  3764,  -802,  3450,  3450,  3450,  -802,
    -802,   260,  5967,   260,  5967,  4090,  4248,  -802,  3450,  3450,
    3450,  -802,  -802,  -802,  3450,  3450,    31,  5967,  -802,  -802,
    3450,  3450,  -802,  3450,  3450,  3450,  -802,  -802,  3798,  3714,
    -802,   725,   728,  -802,  -802,  3450,  3450,  3450,  3450,  -802,
    -802,  -802,  -802,  -802,  -802,  3450,  -802,  -802,  3450,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  3450,
    -802,  -802,  3450,  3450,  3450,  -802,  3450,  3450,  -802,  3798,
    -802,  -802,  -802,  -802,  -802,  3450,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  3798,  3798,  -802,  -802,
    -802,  -802,  -802,  -802,  3798,  -802,  -802,  -802,  -802,  -802,
    -802,  3450,  3450,  3450,  3450,   907,  -802,  3798,   907,  -802,
    3798,  3798,  -802,   729,  -802,   731,  1212,   505,   734,   735,
    -802,   746,   747,  -802,  -802,   636,  4044,  -802,  -802,  -802,
    3450,  4400,   876,  3798,  -802,  3798,   310,   260,   673,  4414,
     661,   661,  5162,   750,   751,  -802,   749,  -802,  -802,  -802,
    -802,  3450,  3450,  -802,  -802,  4431,  2178,  2178,  3798,  3798,
    3798,  -802,  3450,  3450,   753,  5222,  5236,  1045,  3798,  3798,
    5967,     5,  -802,   755,  -802,    64,  -802,  -802,  -802,  5283,
    5297,  5311,  5325,  5357,   324,   756,    90,  -802,  -802,  5371,
    5385,   757,    50,  5446,  5460,  5506,  5520,  5534,  1059,  5548,
    5581,    93,  5595,   156,   177,   348,  5609,  4463,  4477,  5669,
     185,   358,   241,   366,   368,   105,   105,  -802,  -802,  -802,
    -802,  3450,   898,   906,   903,  5683,  3450,   763,   369,   178,
    -802,  3450,  -802,  -802,  -802,  -802,  -802,  -802,   764,   766,
    5967,  5967,  3798,  -802,  -802,   310,   310,   180,  4491,  5967,
    -802,   874,   878,   881,  3450,   224,   310,  3450,   685,  3450,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  3798,  -802,
    -802,  -802,  3450,  -802,  -802,  -802,  -802,  -802,  -802,  3450,
    -802,  -802,  -802,  3798,  -802,  -802,  3450,  -802,  3450,  -802,
    -802,  3798,  3450,  -802,  -802,  3798,  -802,  -802,  3798,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,   909,   617,  5730,  3450,
     900,  3798,  5744,   661,   773,   774,   661,  -802,  -802,   310,
    3798,  3798,  3798,  3798,  3798,  5758,  3450,  -802,   784,   786,
     292,  -802,     9,   379,  4552,  5772,   407,  5804,  5818,   432,
    5832,   433,   444,  4044,  4360,  3450,   925,  -802,   788,  -802,
    4566,   789,   447,  -802,  -802,  -802,  -802,  -802,   310,   310,
     310,   310,   310,   901,  5967,   791,   792,  -802,   685,  3450,
    -802,  -802,  3450,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,   903,   937,   588,  4044,  -802,  3798,  3450,  3450,  -802,
     842,  3798,  -802,  -802,  4044,  -802,  5967,  4044,  5893,  -802,
    -802,   903,   571,   221,  5907,  4612,   661,   310,    16,   903,
    -802,  4044,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    3798,  -802,  3450,  -802,  -802,  -802,  -802,   715,   903,   450,
    5953,  -802,  -802,  -802,  -802,  -802,  -802,   975,   909,  -802,
    -802,  -802,  -802,  -802
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     111,     0,     0,   105,   340,   375,   380,    11,     0,     0,
       0,     0,    24,    26,   318,     0,     0,     0,     0,   319,
      18,    20,   355,   367,     0,   448,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   112,   113,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     4,     3,     0,     7,    39,    41,     9,    22,
      23,    21,     0,    13,    14,    17,    16,    15,    28,    29,
       0,   302,     0,   302,     0,     0,     6,   295,   294,    30,
      31,    38,   290,   199,   133,   291,   292,   293,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,     0,     0,     0,
       0,   258,   261,   264,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   163,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,   212,   193,   198,   135,
       0,     0,     0,    12,   302,   302,    42,   320,    19,     0,
       6,   399,     0,   452,     0,     0,   428,   444,    62,    61,
       0,     0,    63,   104,    53,     0,    55,     0,   420,   422,
      56,   418,   424,     0,     0,   425,   287,    57,    59,     0,
      89,     0,     0,   463,     0,    86,    91,    79,    40,     0,
       0,     0,    67,     0,    50,    72,     0,    88,    87,     0,
       0,   114,   115,    92,     8,    10,     0,     0,   106,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     1,     2,     0,     0,     0,     0,     0,     0,
     309,   178,     0,   304,   116,     0,     0,   376,     4,   302,
     302,    32,    33,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    36,   182,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,   324,    25,
     321,   329,   330,    27,   327,     0,     0,     0,   360,   359,
       0,     4,     0,     6,     0,     0,     0,   449,   450,     0,
     431,   433,    45,     0,     0,    49,   446,   302,   302,     0,
       0,     0,   302,   302,     0,   289,   288,     0,     0,    90,
     462,     0,     0,     0,    66,     0,    71,   444,   123,   122,
       0,     0,    68,     0,    74,     0,     0,   131,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,   179,   121,     0,   300,   307,   308,   303,   305,
     301,   341,     6,   387,   385,     0,   386,   382,   384,   381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
     262,     0,   265,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   164,     0,     0,
       0,     0,     0,   138,   213,   207,   209,   211,   208,   210,
     206,   137,     0,     0,     0,     0,   186,   188,   190,   187,
     189,   185,   204,   201,   200,   202,   203,   302,   302,     0,
     302,   302,     0,    43,    44,   357,   361,   374,   372,   373,
     370,   369,   371,   368,   389,     4,     0,     0,     0,     0,
       0,   429,    46,    47,     0,   436,   438,     0,   447,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,   426,
     427,     0,     0,     0,   126,   125,   129,   216,    51,    69,
      82,    73,     0,     0,     0,   302,     0,     0,     0,    96,
      97,    98,    99,   100,   101,     0,     0,     5,     0,     0,
       0,   315,   316,   310,     0,     0,     4,   383,   280,   175,
       0,     0,   271,     0,     0,     0,   281,   282,     0,     0,
     275,     0,     0,   194,   195,     0,     0,     0,     0,   217,
     218,   219,   220,   221,   222,     0,   224,   225,     0,   227,
     228,   191,   234,   235,   229,   231,   232,   233,   230,     0,
     237,   242,     0,     0,     0,   241,     0,     0,   143,     0,
     148,   149,   243,   173,   244,     0,   174,   150,   151,   257,
     260,   263,   266,   154,   152,   153,     0,     0,   155,   250,
     156,   256,   255,   165,     0,   251,   157,   252,   158,   254,
     159,     0,     0,     0,     0,     0,   168,     0,     0,   170,
       0,     0,   464,    35,   466,    37,   183,   181,     0,     0,
     322,     0,     0,   328,   358,   364,     6,   401,   402,   400,
       0,     0,   453,     0,   451,     0,   434,   432,   433,     0,
       0,     0,     0,   414,   416,   445,   411,   296,   298,   302,
     302,     0,     0,   421,   423,    64,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    85,     0,   306,     0,   379,   378,   377,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,   326,   331,
     332,     0,     0,     0,   390,     0,     0,     0,     0,     0,
     430,     0,   437,   439,   440,   302,   302,   412,     0,     0,
      52,    54,     0,   127,   128,   124,   130,    83,    76,    77,
     132,     0,     0,     0,     0,   109,   110,     0,   333,     0,
     269,   270,   272,   273,   274,   283,   284,   285,     0,   196,
     197,   171,     0,   223,   226,   236,   139,   140,   142,     0,
     239,   240,   144,     0,   245,   246,     0,   248,     0,   166,
     160,     0,     0,   177,   277,     0,   167,   279,     0,   169,
     192,   465,   467,   362,   365,   356,   405,   455,     0,     0,
     454,     0,     0,     0,     0,     0,     0,   297,   299,    65,
       0,     0,     0,     0,     0,     0,     0,    81,   336,   337,
       0,   334,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,   111,     0,   403,   459,     0,   456,
       0,     0,     0,   442,   441,   415,   417,   413,    84,    75,
     119,   120,   118,     0,   108,     0,     0,   311,     0,     0,
     342,   286,     0,   141,   145,   247,   249,   253,   176,   276,
     278,   363,     4,   409,     6,   391,     0,     0,     0,   435,
     446,     0,   338,   339,     6,   335,   352,     6,     0,   410,
     406,   404,     0,     0,     0,     0,     0,   117,     4,   343,
     172,     6,   398,   395,   396,   397,   393,   394,   392,   460,
       0,   457,     0,   443,   314,   313,   312,     0,   407,     0,
       0,   346,   348,   349,   350,   345,   347,   353,   405,   461,
     458,   354,   344,   408
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -802,  -802,   -84,  -802,   516,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,   939,  -245,  -802,  -802,  -168,   813,  -802,   940,
     -11,  -802,  -802,   693,  -299,   -35,  -802,   562,   -26,     2,
    -802,     1,     3,   -41,  -802,  -802,   314,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,   391,  -802,   389,  -802,   -36,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,   112,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -102,  -802,  -802,  -802,
    -801,  -802,  -802,  -802,   574,  -802,  -802,   199,   563,  -802,
    -802,  -802,  -802,  -802,   -51,  -802,    40,  -802,  -802
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    62,   274,    63,   190,   191,   592,   593,   207,
     447,    64,    65,   450,    66,    67,   458,   183,   184,    68,
     241,   595,   594,   504,   505,   242,   186,   225,   187,    89,
     212,   188,   189,   282,   283,   478,   479,    71,   474,   843,
    1064,  1096,   683,    72,   399,   400,   403,   404,  1000,  1001,
      73,    84,   685,  1067,  1097,  1107,  1040,  1112,    74,   199,
     616,   410,   795,  1013,   893,  1014,    75,   200,   623,    76,
      85,   482,   848,    77,    86,   489,    78,   412,   796,   976,
    1072,  1088,    79,   413,   799,  1055,  1016,  1081,  1108,  1070,
     815,   986,   816,   220,   221,   227,   422,   631,   425,   810,
     811,   983,  1060,   426,   639,   206,   234,   783,   785
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     185,    69,   288,    70,   507,   448,   245,   246,   226,   902,
     903,    90,    91,   201,   455,   456,   209,   448,   423,   213,
     215,   217,  1039,     1,     2,   233,   233,   233,   381,   417,
     635,   194,   418,   636,   253,   466,   202,   228,   203,   204,
     381,  1094,   285,   441,   381,   583,   233,   846,   256,   670,
     257,    92,    80,   195,    82,    95,    96,    97,   222,    92,
    1095,   381,   448,    95,    96,    97,   649,   197,   467,   281,
     391,   392,   384,   385,   287,   847,   929,   238,   239,   386,
     387,   388,   389,   390,   391,   392,    92,    69,   198,    70,
      95,    96,    97,   295,   381,   459,   460,   268,   390,   391,
     392,   732,   375,   376,   377,   378,   379,   380,   381,    87,
     392,   252,    88,   384,   385,   733,   411,   392,   275,   276,
     386,   387,   388,   389,   390,   391,   392,   384,   385,   776,
     277,   777,   210,   211,   386,   387,   388,   389,   390,   391,
     392,   375,   376,   377,   378,   379,   380,   218,   219,   424,
      52,    53,    54,   406,   407,   375,   376,   377,   378,   379,
     380,   381,    81,   240,    83,   381,   744,   205,   745,   261,
     372,   374,   734,   381,   381,   393,   394,   395,   396,   381,
     756,   449,  1024,   272,   763,  1027,   764,   381,   409,   393,
     394,   395,   396,   449,   757,   421,   262,   435,   436,   263,
     579,    69,   581,    70,   393,   394,   395,   396,   446,   662,
     419,   637,   273,   381,   452,   454,   395,   396,   438,   278,
     440,   393,   394,   395,   396,   679,   680,   381,   223,   224,
     393,   394,   395,   396,   772,   279,   223,   224,   449,   264,
     469,   470,   471,   381,   393,   394,   395,   396,   490,   491,
     773,   381,   381,   265,   462,   381,   770,   697,   771,   698,
     802,   381,   803,   707,   291,   292,   381,   472,   774,   508,
     381,   381,   477,   464,   381,  1093,   937,   775,   938,   952,
     266,   953,   492,   493,   381,   494,   495,   496,   497,   233,
     233,   778,   397,   398,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   233,   521,   522,   523,   524,
     525,   526,   527,   528,   530,   567,   568,   779,   381,   780,
     536,   537,   538,   540,   541,   781,   543,   280,   545,   625,
     375,   376,   377,   378,   379,   380,   286,   381,   381,   381,
     500,   501,   955,   233,   956,   828,   830,    81,   570,   375,
     376,   377,   378,   379,   380,   381,   520,    83,   381,   381,
     731,   381,    94,   957,   583,   958,   981,    98,   990,   381,
     247,   964,   289,   965,   735,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   640,   641,   100,   290,
     381,   646,   647,   293,   565,   742,   382,   383,   686,   248,
     249,   250,   381,   626,   294,   381,   251,  1089,   629,  1090,
     296,   226,   996,   297,    69,   659,    70,   298,   661,   644,
     645,   375,   376,   377,   378,   379,   380,   967,   381,   968,
     381,   381,   656,   747,   657,   748,   749,   381,   381,   384,
     385,   381,   750,   751,   663,   664,   386,   387,   388,   389,
     390,   391,   392,   672,   674,   675,   676,   381,   299,   381,
     381,   113,   752,   114,   753,   583,   300,   381,   381,    69,
     381,    70,   754,   755,   687,   758,   880,   381,  1037,   882,
    1038,   381,   759,    69,   301,    70,   760,   381,   136,   137,
     138,   381,   767,   302,   142,   143,   144,   303,   146,   381,
     148,   149,   150,   415,   769,   381,   304,   155,   156,   157,
     935,   483,   160,   484,   162,   485,   164,   429,   617,   166,
     618,   168,   619,   305,   170,   401,   402,   172,   173,   381,
     174,   175,   381,   177,   959,   179,   468,   761,   486,   381,
     306,   487,   192,   548,   966,   620,   488,   381,   621,   381,
     381,   434,   969,   622,   970,   980,   393,   394,   395,   396,
     381,   389,   390,   391,   392,  1041,   788,   789,   384,   791,
     792,   502,   503,   307,  -388,   386,   387,   388,   389,   390,
     391,   392,   308,   786,   787,  1082,   309,  1083,   381,  1084,
     310,   384,   385,  1044,   782,   784,   927,   311,   386,   387,
     388,   389,   390,   391,   392,   387,   388,   389,   390,   391,
     392,   312,  1085,   381,   381,  1086,   801,   942,  1047,  1049,
    1087,   313,   808,   809,   834,   381,   812,   831,   381,   437,
    1050,   381,   475,  1059,  1069,   457,  1109,   314,   632,   633,
     825,   642,   643,   315,   841,   842,   652,   653,   681,   682,
     316,   384,   385,   797,   798,   835,   836,   837,   386,   387,
     388,   389,   390,   391,   392,   813,   814,   840,   393,   394,
     395,   396,   861,   477,   845,   891,   892,  1017,  1018,   849,
     850,   317,   851,   852,   853,   393,   394,   395,   396,   998,
     999,   318,   319,   320,   859,   860,   387,   862,   389,   390,
     391,   392,   321,   322,   863,   323,   481,   864,   393,   394,
     395,   396,   894,   442,   393,   394,   395,   396,   865,   443,
     324,   866,   867,   868,   630,   869,   870,   325,   326,  1101,
     327,  1102,   328,  1103,   872,   329,   384,   385,   330,   331,
     332,   333,   334,   386,   387,   388,   389,   390,   391,   392,
     335,   336,   451,   337,   338,   339,  1104,   340,   341,  1105,
     876,   877,   878,   879,  1106,   342,   343,   344,   393,   394,
     395,   396,   345,   465,   346,   347,   348,   349,   908,   909,
     350,   351,   352,   384,   385,   353,   354,   355,   356,   895,
     386,   387,   388,   389,   390,   391,   392,    69,   357,    70,
     358,   359,   392,   360,   361,   393,   394,   395,   396,   362,
     910,   911,   363,   364,   365,   233,   233,   366,   367,   368,
     369,   918,   919,   370,   371,   414,   416,   427,   193,   480,
     428,   196,   432,   433,   609,   576,   577,   607,   608,   610,
     208,   611,   615,   612,   214,   216,   613,   624,   614,   232,
     627,   634,   638,   393,   394,   395,   396,   665,   666,   667,
     688,   258,   259,   260,   984,   985,   913,   914,   668,   678,
     267,   269,   270,   271,   684,   689,   696,   794,   700,   699,
     409,   701,   702,   705,   703,   978,   704,   971,   972,   706,
     982,   721,   997,   762,   765,   284,   766,   817,   818,   819,
     393,   394,   395,   396,   820,   826,   714,   823,   715,   824,
     827,   857,   503,   995,   858,   384,   385,   885,  1002,   886,
     887,   888,   386,   387,   388,   389,   390,   391,   392,  1051,
    1052,  1004,   889,   890,   897,   905,   906,   907,  1005,   920,
     928,   974,   936,   941,   975,  1007,    -4,  1008,   979,   992,
     987,  1010,   988,   993,   384,   385,   994,  1015,  1021,  1025,
    1026,   386,   387,   388,   389,   390,   391,   392,  1020,  1035,
    1071,  1036,  1054,  1056,  1058,  -366,  1061,  1062,  1063,  1111,
    1078,   384,   385,  1079,   677,  1034,   254,   255,   386,   387,
     388,   389,   390,   391,   392,   373,   506,  1098,   844,   650,
     790,   793,  1065,   973,  1053,   405,  1113,   900,   648,  1076,
     658,     0,   408,     0,    69,    69,    70,    70,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,  1066,     0,
       0,  1068,   393,   394,   395,   396,     0,     0,   717,     0,
     718,     0,     0,   439,     0,     0,  1074,  1075,     0,     0,
       0,     0,     0,   444,     0,    69,     0,    70,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    70,    69,     0,
      70,   393,   394,   395,   396,     0,     0,   584,     0,   463,
       0,  1100,    69,     0,    70,     0,     0,     0,     0,     0,
       0,     0,   473,     0,     0,     0,   476,     0,   393,   394,
     395,   396,     0,     0,   738,     0,   739,     0,   384,   385,
       0,     0,     0,   499,     0,   386,   387,   388,   389,   390,
     391,   392,   384,   385,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,   531,
     532,   533,   534,   535,     0,     0,     0,     0,     0,   542,
       0,   544,     0,   546,   547,   549,   551,   553,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   566,     0,
       0,   569,     0,   571,   572,   573,   574,   575,     0,     0,
     578,     0,   580,     0,   582,     0,     0,     0,   585,   586,
     587,   588,   589,   590,   591,     0,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   393,   394,   395,   396,   628,
       0,   923,     0,   924,     0,     0,     0,     0,     0,   393,
     394,   395,   396,     0,     0,   948,     0,   949,     0,     0,
       0,     0,     0,     0,     0,   655,   102,   103,   104,   105,
     106,   107,   108,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,   110,   671,   673,     0,
       0,   235,   386,   387,   388,   389,   390,   391,   392,   236,
       0,     0,     0,   111,   112,     0,     0,   113,     0,   114,
       0,     0,   237,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,     0,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,   384,   385,   182,     0,
       0,     0,   231,   386,   387,   388,   389,   390,   391,   392,
       0,    94,   393,   394,   395,   396,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   100,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   806,     0,     0,   807,     0,   384,   385,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   384,   385,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,   114,   393,   394,   395,   396,   476,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   854,   856,     0,     0,     0,     0,   136,   137,   138,
       0,    94,     0,   142,   143,   144,    98,   146,     0,   148,
     149,   150,   393,   394,   395,   396,   155,   156,   157,     0,
     431,   160,     0,   162,     0,   164,     0,   100,   166,     0,
     168,     0,   871,   170,     0,     0,   172,   173,     0,   174,
     175,     0,   177,     0,   179,   393,   394,   395,   396,   873,
     874,   192,   550,   445,     0,     0,     0,   875,     0,   393,
     394,   395,   396,     0,     0,     0,     0,   651,   384,   385,
     881,     0,     0,   883,   884,   386,   387,   388,   389,   390,
     391,   392,   384,   385,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   898,     0,   899,     0,
     113,     0,   114,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,   915,   916,   917,     0,     0,     0,   136,   137,   138,
       0,   925,   926,   142,   143,   144,     0,   146,     0,   148,
     149,   150,     0,     0,     0,     0,   155,   156,   157,     0,
       0,   160,     0,   162,     0,   164,     0,     0,   166,     0,
     168,     0,     0,   170,     0,     0,   172,   173,     0,   174,
     175,     0,   177,     0,   179,     0,     0,     0,     0,     0,
       0,   192,   552,     0,   408,   393,   394,   395,   396,     0,
       0,     0,     0,   690,     0,     0,     0,     0,     0,   393,
     394,   395,   396,     0,     0,   989,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,   384,   385,     0,   693,     0,
       0,  1003,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,     0,     0,     0,  1006,     0,     0,     0,
       0,     0,     0,     0,  1009,     0,     0,     0,  1011,   384,
     385,  1012,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,     0,  1022,     0,     0,     0,     0,     0,
       0,     0,     0,  1028,  1029,  1030,  1031,  1032,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,   396,     0,     0,     0,  1073,
     694,     0,     0,     0,  1077,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,   110,   393,   394,   395,   396,
     229,     0,     0,  1099,   695,     0,     0,     0,   230,     0,
       0,     0,   111,   112,     0,     0,   113,     0,   114,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,     0,     0,     0,     0,   182,    92,    93,
      94,   231,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,   384,   385,     0,   109,     0,     0,   110,   386,
     387,   388,   389,   390,   391,   392,     0,     0,     0,     0,
       0,   498,     0,     0,     0,   111,   112,     0,     0,   113,
       0,   114,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
       0,   169,   170,     0,   171,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
     182,    92,    93,    94,   231,    95,    96,    97,    98,   393,
     394,   395,   396,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   109,     0,
       0,   110,   386,   387,   388,   389,   390,   391,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
       0,     0,   113,     0,   114,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,   165,
     166,   167,   168,     0,   169,   170,     0,   171,   172,   173,
       0,   174,   175,   176,   177,   178,   179,   180,   181,     0,
       0,     0,     0,   182,    92,    93,    94,   231,    95,    96,
      97,    98,   393,   394,   395,   396,     0,     0,     0,     0,
     729,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   109,     0,     0,   110,     0,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,     0,     0,   113,     0,   114,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,     0,     0,     0,     0,   182,   461,    92,    93,
      94,     0,    95,    96,    97,    98,   393,   394,   395,   396,
       0,     0,     0,     0,   736,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,   384,   385,   109,     0,     0,   110,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,     0,     0,   113,
       0,   114,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
       0,   169,   170,     0,   171,   172,   173,     0,   174,   175,
     176,   177,   178,   179,   180,   181,     0,     0,     0,     0,
     182,   529,    92,    93,    94,     0,    95,    96,    97,    98,
     393,   394,   395,   396,     0,     0,     0,     0,   737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     384,   385,   110,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,     0,   111,
     112,     0,     0,   113,     0,   114,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,     0,
     165,   166,   167,   168,     0,   169,   170,     0,   171,   172,
     173,     0,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,   182,   539,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   243,     0,   393,   394,   395,
     396,     0,     0,     0,     0,   800,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   109,     0,     0,   110,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,   113,     0,   114,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,   165,   166,   167,   168,     0,   169,
     170,     0,   171,   172,   173,     0,   174,   175,   176,   177,
     178,   179,   180,   181,     0,    92,    93,    94,   182,    95,
      96,    97,    98,     0,     0,     0,     0,   393,   394,   395,
     396,     0,     0,     0,     0,   821,     0,     0,     0,     0,
       0,     0,    99,   100,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   384,
     385,     0,   109,     0,     0,   110,   386,   387,   388,   389,
     390,   391,   392,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,     0,     0,   113,     0,   114,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,   165,   166,   167,   168,     0,   169,   170,
       0,   171,   172,   173,     0,   174,   175,   176,   177,   178,
     179,   180,   181,     0,    92,    93,    94,   182,    95,    96,
      97,    98,     0,   453,     0,     0,   393,   394,   395,   396,
       0,     0,     0,     0,   822,     0,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,   384,   385,
       0,   109,     0,     0,   110,   386,   387,   388,   389,   390,
     391,   392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,     0,     0,   113,     0,   114,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,   165,   166,   167,   168,     0,   169,   170,     0,
     171,   172,   173,     0,   174,   175,   176,   177,   178,   179,
     180,   181,     0,    92,    93,    94,   182,    95,    96,    97,
      98,     0,     0,     0,     0,   393,   394,   395,   396,     0,
       0,     0,     0,   829,     0,     0,     0,     0,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    94,   110,   384,   385,     0,    98,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     0,
     111,   112,     0,     0,   113,     0,   114,     0,   100,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,   165,   166,   167,   168,     0,   169,   170,     0,   171,
     172,   173,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   113,     0,   114,     0,   182,    94,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,     0,     0,   669,   136,   137,
     138,     0,   100,     0,   142,   143,   144,     0,   146,     0,
     148,   149,   150,     0,     0,     0,     0,   155,   156,   157,
       0,     0,   160,     0,   162,     0,   164,     0,     0,   166,
       0,   168,     0,     0,   170,     0,     0,   172,   173,     0,
     174,   175,     0,   177,     0,   179,     0,     0,     0,     0,
       0,     0,   192,   554,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,    98,     0,     0,   654,     0,     0,
       0,     0,     0,     0,     0,   113,     0,   114,     0,     0,
       0,     0,     0,   384,   385,   100,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,     0,   136,   137,   138,     0,     0,     0,   142,   143,
     144,     0,   146,     0,   148,   149,   150,     0,     0,     0,
       0,   155,   156,   157,     0,     0,   160,     0,   162,     0,
     164,     0,     0,   166,     0,   168,     0,     0,   170,     0,
       0,   172,   173,    94,   174,   175,     0,   177,    98,   179,
     855,     0,     0,     0,     0,     0,   192,     0,   113,     0,
     114,     0,     0,     0,     0,     0,     0,   384,   385,   100,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,   142,   143,   144,     0,   146,     0,   148,   149,   150,
     393,   394,   395,   396,   155,   156,   157,     0,   832,   160,
       0,   162,     0,   164,    94,     0,   166,     0,   168,    98,
       0,   170,     0,     0,   172,   173,     0,   174,   175,     0,
     177,     0,   179,     0,     0,     0,     0,     0,     0,   192,
     100,     0,   113,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,     0,     0,     0,   142,   143,   144,     0,   146,
       0,   148,   149,   150,   393,   394,   395,   396,   155,   156,
     157,     0,   833,   160,     0,   162,     0,   164,     0,     0,
     166,     0,   168,     0,     0,   170,     0,     0,   172,   173,
       0,   174,   175,   113,   177,   114,   179,     0,     0,     0,
       0,     0,     0,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,     0,     0,     0,   142,   143,   144,     0,
     146,     0,   148,   149,   150,     0,     0,     0,     0,   155,
     156,   157,     0,     0,   160,     0,   162,     0,   164,     0,
       0,   166,     0,   168,     0,     0,   170,     0,     0,   172,
     173,     0,   174,   175,     0,   177,     0,   179,     1,     2,
       3,     0,     0,     0,   805,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,    11,  -317,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,     0,     0,     0,     0,    23,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,  -111,  -111,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,  -111,     0,    49,
       0,    50,    51,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,     1,     2,     3,    58,
       0,     0,    59,     4,     0,     0,    60,     5,     0,     6,
       0,     7,     8,     9,    10,    11,  -317,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
       0,     0,     0,     0,    23,    -6,    -6,    24,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,     0,     0,     0,   838,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,    57,     0,     1,     2,     3,    58,     0,     0,
      59,     4,     0,     0,    60,     5,     0,     6,     0,     7,
       8,     9,    10,    11,  -317,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    -6,     0,
       0,     0,    23,    -6,     0,    24,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,   393,   394,
     395,   396,     0,     0,     0,     0,   839,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,    39,    40,
      41,     0,     0,    42,    43,    44,     0,    45,    46,    47,
       0,     0,    48,   384,   385,    49,     0,    50,    51,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,    52,    53,    54,   384,   385,     0,     0,    55,     0,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      57,     0,     0,     0,     0,    58,   384,   385,    59,     0,
       0,     0,    60,   386,   387,   388,   389,   390,   391,   392,
     384,   385,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   384,   385,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,     0,     0,     0,   896,     0,
       0,     0,     0,     0,   393,   394,   395,   396,     0,     0,
       0,     0,   901,     0,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   384,   385,     0,     0,   912,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   384,
     385,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,     0,     0,     0,
       0,   961,     0,     0,     0,     0,     0,   393,   394,   395,
     396,     0,     0,     0,     0,   962,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   384,   385,     0,     0,   991,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   384,
     385,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,     0,   393,   394,   395,   396,     0,     0,     0,     0,
    1042,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     384,   385,     0,     0,  1057,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   384,   385,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   384,   385,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,     0,     0,     0,     0,
    1092,     0,     0,     0,     0,     0,   393,   394,   395,   396,
       0,     0,   692,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,     0,   709,     0,     0,     0,
       0,     0,     0,     0,   393,   394,   395,   396,   384,   385,
     710,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   384,   385,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,     0,   393,   394,   395,
     396,     0,     0,   711,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,     0,     0,   712,     0,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   384,
     385,   713,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,     0,
       0,   716,     0,     0,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   384,   385,   719,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,     0,   393,   394,   395,   396,
       0,     0,   720,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,   393,   394,   395,   396,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   384,   385,   724,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   384,   385,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,   393,   394,   395,   396,     0,     0,
     726,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   384,   385,   727,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   384,   385,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     384,   385,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   384,   385,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,     0,   393,
     394,   395,   396,     0,     0,   728,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   384,   385,   730,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   384,   385,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,     0,     0,   740,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   396,     0,     0,   741,
       0,     0,     0,     0,     0,     0,     0,   393,   394,   395,
     396,     0,     0,   743,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,   384,   385,   746,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   384,
     385,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,     0,   393,   394,   395,   396,     0,     0,
     768,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,     0,     0,   804,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   384,   385,   904,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     384,   385,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   384,   385,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   384,   385,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,     0,     0,   921,     0,
       0,     0,     0,     0,     0,     0,   393,   394,   395,   396,
     384,   385,   922,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   384,   385,     0,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   384,   385,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,     0,   393,   394,   395,   396,     0,     0,   930,
       0,     0,     0,     0,     0,     0,     0,   393,   394,   395,
     396,     0,     0,   931,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,     0,     0,   932,     0,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   384,
     385,   933,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,     0,     0,   934,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,   396,     0,     0,   939,     0,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,   384,
     385,   940,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   384,   385,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,     0,   393,   394,   395,   396,
       0,     0,   943,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,   384,   385,   944,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   384,   385,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   384,   385,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
       0,     0,   945,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,   396,     0,     0,   946,     0,     0,     0,
       0,     0,     0,     0,   393,   394,   395,   396,     0,     0,
     947,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,   384,   385,   950,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   384,   385,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
       0,   393,   394,   395,   396,     0,     0,   951,     0,     0,
       0,     0,     0,     0,     0,   393,   394,   395,   396,     0,
       0,   954,     0,     0,     0,     0,     0,     0,     0,   393,
     394,   395,   396,   384,   385,   960,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   384,   385,     0,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   384,   385,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,     0,     0,   963,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   396,   384,   385,   977,
       0,     0,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   384,   385,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   384,   385,     0,     0,     0,
       0,     0,   386,   387,   388,   389,   390,   391,   392,     0,
     393,   394,   395,   396,     0,     0,  1019,     0,     0,     0,
       0,     0,     0,     0,   393,   394,   395,   396,     0,     0,
    1023,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,     0,     0,  1033,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   384,   385,  1043,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     384,   385,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,     0,     0,
    1045,     0,     0,     0,     0,     0,     0,     0,   393,   394,
     395,   396,     0,     0,  1046,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   384,   385,  1048,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     384,   385,     0,     0,     0,     0,     0,   386,   387,   388,
     389,   390,   391,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   396,     0,     0,  1080,
       0,     0,     0,     0,     0,     0,     0,   393,   394,   395,
     396,     0,     0,  1091,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,   394,   395,   396,     0,     0,  1110,
       0,     0,     0,     0,     0,     0,     0,   393,   394,   395,
     396
};

static const yytype_int16 yycheck[] =
{
      11,     0,    86,     0,   303,    12,    41,    42,    34,   810,
     811,     9,    10,    24,   259,   260,    27,    12,    58,    30,
      31,    32,    13,     4,     5,    36,    37,    38,   181,     4,
       4,   185,     7,     7,    45,   188,    58,    35,    60,    61,
     181,    25,    83,    11,   181,   186,    57,    16,    47,   186,
      47,     3,    75,   185,    75,     7,     8,     9,    10,     3,
      44,   181,    12,     7,     8,     9,    10,    28,   188,    80,
      75,    76,    63,    64,    85,    44,    12,    37,    38,    70,
      71,    72,    73,    74,    75,    76,     3,    86,     7,    86,
       7,     8,     9,   104,   181,   263,   264,    57,    74,    75,
      76,   188,    70,    71,    72,    73,    74,    75,   181,     4,
      76,    94,     7,    63,    64,   188,   200,    76,    91,    92,
      70,    71,    72,    73,    74,    75,    76,    63,    64,   186,
     103,   188,     4,     5,    70,    71,    72,    73,    74,    75,
      76,    70,    71,    72,    73,    74,    75,     4,     5,   189,
     131,   132,   133,   194,   195,    70,    71,    72,    73,    74,
      75,   181,   185,    87,   185,   181,   186,   189,   188,   109,
     181,   182,   188,   181,   181,   180,   181,   182,   183,   181,
     188,   188,   983,     0,   186,   986,   188,   181,   199,   180,
     181,   182,   183,   188,   188,   206,   185,   223,   224,   185,
     368,   200,   370,   200,   180,   181,   182,   183,   243,   454,
     185,   185,    44,   181,   249,   250,   182,   183,   229,    75,
     231,   180,   181,   182,   183,   470,   471,   181,   180,   181,
     180,   181,   182,   183,   188,    75,   180,   181,   188,   185,
     275,   276,   277,   181,   180,   181,   182,   183,   289,   290,
     188,   181,   181,   185,   265,   181,   186,   186,   188,   188,
     186,   181,   188,   508,    35,    36,   181,   278,   188,   304,
     181,   181,   283,   188,   181,  1076,   186,   188,   188,   186,
     185,   188,   293,   294,   181,   296,   297,   298,   299,   300,
     301,   188,     4,     5,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   356,   357,   186,   181,   188,
     331,   332,   333,   334,   335,   188,   337,    24,   339,   413,
      70,    71,    72,    73,    74,    75,     4,   181,   181,   181,
     300,   301,   186,   354,   188,   188,   188,   185,   359,    70,
      71,    72,    73,    74,    75,   181,   316,   185,   181,   181,
     186,   181,     5,   186,   186,   188,   188,    10,   188,   181,
      59,   186,   185,   188,   186,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   427,   428,    31,   185,
     181,   432,   433,   185,   354,   186,    20,    21,   482,    88,
      89,    90,   181,   414,   185,   181,    95,   186,   419,   188,
     185,   437,   188,   185,   413,   450,   413,   185,   453,   430,
     431,    70,    71,    72,    73,    74,    75,   186,   181,   188,
     181,   181,   443,   186,   445,   186,   186,   181,   181,    63,
      64,   181,   186,   186,   455,   456,    70,    71,    72,    73,
      74,    75,    76,   464,   465,   466,   467,   181,   185,   181,
     181,   104,   186,   106,   186,   186,   185,   181,   181,   468,
     181,   468,   186,   186,   485,   186,   775,   181,   186,   778,
     188,   181,   186,   482,   185,   482,   186,   181,   131,   132,
     133,   181,   186,   185,   137,   138,   139,   185,   141,   181,
     143,   144,   145,    58,   186,   181,   185,   150,   151,   152,
     186,    14,   155,    16,   157,    18,   159,   188,    14,   162,
      16,   164,    18,   185,   167,     4,     5,   170,   171,   181,
     173,   174,   181,   176,   186,   178,    43,   186,    41,   181,
     185,    44,   185,   186,   186,    41,    49,   181,    44,   181,
     181,   188,   186,    49,   186,   186,   180,   181,   182,   183,
     181,    73,    74,    75,    76,   186,   607,   608,    63,   610,
     611,     4,     5,   185,    46,    70,    71,    72,    73,    74,
      75,    76,   185,   594,   595,    14,   185,    16,   181,    18,
     185,    63,    64,   186,   592,   593,   841,   185,    70,    71,
      72,    73,    74,    75,    76,    71,    72,    73,    74,    75,
      76,   185,    41,   181,   181,    44,   627,   862,   186,   186,
      49,   185,   633,   634,   665,   181,   637,   662,   181,   188,
     186,   181,   186,   186,    46,     5,   186,   185,   187,   188,
     651,     4,     5,   185,   679,   680,    85,    86,     4,     5,
     185,    63,    64,    49,    50,   666,   667,   668,    70,    71,
      72,    73,    74,    75,    76,     4,     5,   678,   180,   181,
     182,   183,   707,   684,   685,    39,    40,    60,    61,   690,
     691,   185,   693,   694,   695,   180,   181,   182,   183,     4,
       5,   185,   185,   185,   705,   706,    71,   708,    73,    74,
      75,    76,   185,   185,   715,   185,    75,   718,   180,   181,
     182,   183,   796,   188,   180,   181,   182,   183,   729,   188,
     185,   732,   733,   734,    51,   736,   737,   185,   185,    14,
     185,    16,   185,    18,   745,   185,    63,    64,   185,   185,
     185,   185,   185,    70,    71,    72,    73,    74,    75,    76,
     185,   185,   188,   185,   185,   185,    41,   185,   185,    44,
     771,   772,   773,   774,    49,   185,   185,   185,   180,   181,
     182,   183,   185,   188,   185,   185,   185,   185,   819,   820,
     185,   185,   185,    63,    64,   185,   185,   185,   185,   800,
      70,    71,    72,    73,    74,    75,    76,   796,   185,   796,
     185,   185,    76,   185,   185,   180,   181,   182,   183,   185,
     821,   822,   185,   185,   185,   826,   827,   185,   185,   185,
     185,   832,   833,   185,   185,   185,   185,   185,    15,   186,
     185,    18,   185,   185,   188,   186,   186,   185,   185,   185,
      27,   185,    43,   188,    31,    32,   186,    46,   186,    36,
     185,   185,    10,   180,   181,   182,   183,   185,   188,   188,
     186,    48,    49,    50,   905,   906,   826,   827,   188,   188,
      57,    58,    59,    60,   188,   186,   186,    43,   186,   188,
     891,   185,   185,   188,   186,   896,   186,   885,   886,   188,
     901,   186,   927,   186,   186,    82,   186,   186,   186,   185,
     180,   181,   182,   183,   185,    84,   186,   186,   188,   186,
      84,   186,     5,   924,   186,    63,    64,   188,   929,   188,
     186,   186,    70,    71,    72,    73,    74,    75,    76,  1013,
    1014,   942,   186,   186,    58,   185,   185,   188,   949,   186,
     185,    43,   186,   186,    38,   956,    43,   958,   185,    75,
     186,   962,   186,    75,    63,    64,    75,    48,    58,   186,
     186,    70,    71,    72,    73,    74,    75,    76,   979,   185,
    1054,   185,    47,   185,   185,    38,    75,   186,   186,     4,
    1064,    63,    64,  1067,   468,   996,    47,    47,    70,    71,
      72,    73,    74,    75,    76,   182,   303,  1081,   684,   437,
     609,   612,  1038,   891,  1015,   192,  1108,   808,   434,  1060,
     447,    -1,   199,    -1,  1013,  1014,  1013,  1014,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,
      -1,  1042,   180,   181,   182,   183,    -1,    -1,   186,    -1,
     188,    -1,    -1,   230,    -1,    -1,  1057,  1058,    -1,    -1,
      -1,    -1,    -1,   240,    -1,  1054,    -1,  1054,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1064,    -1,  1064,  1067,    -1,
    1067,   180,   181,   182,   183,    -1,    -1,   186,    -1,   266,
      -1,  1092,  1081,    -1,  1081,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,    -1,    -1,    -1,   283,    -1,   180,   181,
     182,   183,    -1,    -1,   186,    -1,   188,    -1,    63,    64,
      -1,    -1,    -1,   300,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,   326,
     327,   328,   329,   330,    -1,    -1,    -1,    -1,    -1,   336,
      -1,   338,    -1,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,    -1,
      -1,   358,    -1,   360,   361,   362,   363,   364,    -1,    -1,
     367,    -1,   369,    -1,   371,    -1,    -1,    -1,   375,   376,
     377,   378,   379,   380,   381,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,   180,   181,   182,   183,   416,
      -1,   186,    -1,   188,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,    -1,    -1,   186,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,    63,    64,    65,    66,
      67,    68,    69,    -1,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,   464,   465,    -1,
      -1,    88,    70,    71,    72,    73,    74,    75,    76,    96,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    63,    64,   185,    -1,
      -1,    -1,   189,    70,    71,    72,    73,    74,    75,    76,
      -1,     5,   180,   181,   182,   183,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    31,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   630,    -1,    -1,   633,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,   106,   180,   181,   182,   183,   684,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   698,   699,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,     5,    -1,   137,   138,   139,    10,   141,    -1,   143,
     144,   145,   180,   181,   182,   183,   150,   151,   152,    -1,
     188,   155,    -1,   157,    -1,   159,    -1,    31,   162,    -1,
     164,    -1,   739,   167,    -1,    -1,   170,   171,    -1,   173,
     174,    -1,   176,    -1,   178,   180,   181,   182,   183,   756,
     757,   185,   186,   188,    -1,    -1,    -1,   764,    -1,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    63,    64,
     777,    -1,    -1,   780,   781,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   803,    -1,   805,    -1,
     104,    -1,   106,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,   828,   829,   830,    -1,    -1,    -1,   131,   132,   133,
      -1,   838,   839,   137,   138,   139,    -1,   141,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
      -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,
     164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,
     174,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   186,    -1,   891,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,    -1,    -1,   912,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    63,    64,    -1,   188,    -1,
      -1,   938,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   953,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   961,    -1,    -1,    -1,   965,    63,
      64,   968,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,   981,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   990,   991,   992,   993,   994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,    -1,    -1,    -1,  1056,
     188,    -1,    -1,    -1,  1061,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,   180,   181,   182,   183,
      88,    -1,    -1,  1090,   188,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,     3,     4,
       5,   189,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    80,    -1,    -1,    83,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,     3,     4,     5,   189,     7,     8,     9,    10,   180,
     181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,    -1,
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
      -1,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,     3,     4,     5,   189,     7,     8,
       9,    10,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    80,    -1,    -1,    83,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,   186,     3,     4,
       5,    -1,     7,     8,     9,    10,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    80,    -1,    -1,    83,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,   186,     3,     4,     5,    -1,     7,     8,     9,    10,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      63,    64,    83,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,   186,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    12,    -1,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
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
     177,   178,   179,   180,    -1,     3,     4,     5,   185,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
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
     178,   179,   180,    -1,     3,     4,     5,   185,     7,     8,
       9,    10,    -1,    12,    -1,    -1,   180,   181,   182,   183,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     179,   180,    -1,     3,     4,     5,   185,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,
      -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,     5,    83,    63,    64,    -1,    10,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
     100,   101,    -1,    -1,   104,    -1,   106,    -1,    31,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161,   162,   163,   164,    -1,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
     180,   104,    -1,   106,    -1,   185,     5,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    -1,    -1,   186,   131,   132,
     133,    -1,    31,    -1,   137,   138,   139,    -1,   141,    -1,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,   162,
      -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,    -1,
     173,   174,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    63,    64,    31,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,    -1,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,   151,   152,    -1,    -1,   155,    -1,   157,    -1,
     159,    -1,    -1,   162,    -1,   164,    -1,    -1,   167,    -1,
      -1,   170,   171,     5,   173,   174,    -1,   176,    10,   178,
      96,    -1,    -1,    -1,    -1,    -1,   185,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    31,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,   137,   138,   139,    -1,   141,    -1,   143,   144,   145,
     180,   181,   182,   183,   150,   151,   152,    -1,   188,   155,
      -1,   157,    -1,   159,     5,    -1,   162,    -1,   164,    10,
      -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,    -1,
     176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      31,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,   141,
      -1,   143,   144,   145,   180,   181,   182,   183,   150,   151,
     152,    -1,   188,   155,    -1,   157,    -1,   159,    -1,    -1,
     162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,   171,
      -1,   173,   174,   104,   176,   106,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,    -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
     151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,   164,    -1,    -1,   167,    -1,    -1,   170,
     171,    -1,   173,   174,    -1,   176,    -1,   178,     4,     5,
       6,    -1,    -1,    -1,   185,    11,    -1,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,   105,
      -1,   107,   108,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,    -1,     4,     5,     6,   165,
      -1,    -1,   168,    11,    -1,    -1,   172,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
     108,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,    -1,     4,     5,     6,   165,    -1,    -1,
     168,    11,    -1,    -1,   172,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    -1,    -1,    -1,    -1,   188,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    93,    94,    95,    -1,    97,    98,    99,
      -1,    -1,   102,    63,    64,   105,    -1,   107,   108,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,   131,   132,   133,    63,    64,    -1,    -1,   138,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,   165,    63,    64,   168,    -1,
      -1,    -1,   172,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    63,    64,    -1,    -1,   188,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   180,   181,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,    -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    63,    64,    -1,    -1,   188,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
      63,    64,    -1,    -1,   188,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   180,   181,   182,   183,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    63,    64,
     186,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    -1,   180,   181,   182,
     183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,    63,
      64,   186,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   180,   181,   182,   183,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,    63,    64,   186,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,   180,   181,   182,   183,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    63,    64,   186,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
     180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    63,    64,   186,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    -1,   180,
     181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    63,    64,   186,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   180,
     181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    63,    64,   186,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,    63,    64,   186,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   180,   181,   182,   183,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
      63,    64,   186,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,   180,   181,   182,   183,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,    63,
      64,   186,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   180,   181,   182,
     183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,    63,
      64,   186,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,   180,   181,   182,   183,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    63,    64,   186,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,   180,   181,   182,   183,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    63,    64,   186,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,   180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,   183,    63,    64,   186,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,   180,
     181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    63,    64,   186,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
     180,   181,   182,   183,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,    63,    64,   186,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,   180,   181,   182,   183,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,    63,    64,   186,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
     183
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,    11,    15,    17,    19,    20,    21,
      22,    23,    26,    27,    28,    29,    30,    31,    32,    33,
      35,    36,    37,    42,    45,    52,    53,    54,    55,    56,
      57,    61,    62,    77,    78,    79,    80,    81,    82,    88,
      89,    90,    93,    94,    95,    97,    98,    99,   102,   105,
     107,   108,   131,   132,   133,   138,   156,   160,   165,   168,
     172,   191,   192,   194,   201,   202,   204,   205,   209,   221,
     222,   227,   233,   240,   248,   256,   259,   263,   266,   272,
      75,   185,    75,   185,   241,   260,   264,     4,     7,   219,
     219,   219,     3,     4,     5,     7,     8,     9,    10,    30,
      31,    34,    63,    64,    65,    66,    67,    68,    69,    80,
      83,   100,   101,   104,   106,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   161,   162,   163,   164,   166,
     167,   169,   170,   171,   173,   174,   175,   176,   177,   178,
     179,   180,   185,   207,   208,   210,   216,   218,   221,   222,
     195,   196,   185,   207,   185,   185,   207,    28,     7,   249,
     257,   210,    58,    60,    61,   189,   295,   199,   207,   210,
       4,     5,   220,   210,   207,   210,   207,   210,     4,     5,
     283,   284,    10,   180,   181,   217,   218,   285,   219,    88,
      96,   189,   207,   210,   296,    88,    96,   109,   296,   296,
      87,   210,   215,    12,    53,   215,   215,    59,    88,    89,
      90,    95,    94,   210,   202,   209,   221,   222,   207,   207,
     207,   109,   185,   185,   185,   185,   185,   207,   296,   207,
     207,   207,     0,    44,   193,    91,    92,   103,    75,    75,
      24,   210,   223,   224,   207,   223,     4,   210,   192,   185,
     185,    35,    36,   185,   185,   210,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   210,   207,   210,    70,    71,    72,    73,    74,
      75,   181,    20,    21,    63,    64,    70,    71,    72,    73,
      74,    75,    76,   180,   181,   182,   183,     4,     5,   234,
     235,     4,     5,   236,   237,   207,   223,   223,   207,   210,
     251,   192,   267,   273,   185,    58,   185,     4,     7,   185,
     207,   210,   286,    58,   189,   288,   293,   185,   185,   188,
     188,   188,   185,   185,   188,   218,   218,   188,   210,   207,
     210,    11,   188,   188,   207,   188,   215,   200,    12,   188,
     203,   188,   215,    12,   215,   203,   203,     5,   206,   206,
     206,   186,   210,   207,   188,   188,   188,   188,    43,   215,
     215,   215,   210,   207,   228,   186,   207,   210,   225,   226,
     186,    75,   261,    14,    16,    18,    41,    44,    49,   265,
     223,   223,   210,   210,   210,   210,   210,   210,    96,   207,
     296,   296,     4,     5,   213,   214,   213,   214,   215,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     296,   210,   210,   210,   210,   210,   210,   210,   210,   186,
     210,   207,   207,   207,   207,   207,   210,   210,   210,   186,
     210,   210,   207,   210,   207,   210,   207,   207,   186,   207,
     186,   207,   186,   207,   186,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   296,   207,   223,   223,   207,
     210,   207,   207,   207,   207,   207,   186,   186,   207,   206,
     207,   206,   207,   186,   186,   207,   207,   207,   207,   207,
     207,   207,   197,   198,   212,   211,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   185,   185,   188,
     185,   185,   188,   186,   186,    43,   250,    14,    16,    18,
      41,    44,    49,   258,    46,   192,   210,   185,   207,   210,
      51,   287,   187,   188,   185,     4,     7,   185,    10,   294,
     223,   223,     4,     5,   210,   210,   223,   223,   284,    10,
     217,   188,    85,    86,    96,   207,   210,   210,   288,   215,
     207,   215,   203,   210,   210,   185,   188,   188,   188,   186,
     186,   207,   210,   207,   210,   210,   210,   194,   188,   203,
     203,     4,     5,   232,   188,   242,   192,   210,   186,   186,
     188,   188,   186,   188,   188,   188,   186,   186,   188,   188,
     186,   185,   185,   186,   186,   188,   188,   203,   188,   186,
     186,   186,   186,   186,   186,   188,   186,   186,   188,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   188,
     186,   186,   188,   188,   188,   186,   188,   188,   186,   188,
     186,   186,   186,   186,   186,   188,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   188,   188,   186,   186,
     186,   186,   186,   186,   188,   186,   186,   186,   186,   186,
     186,   188,   188,   188,   188,   188,   186,   188,   188,   186,
     188,   188,   219,   297,   219,   298,   210,   210,   223,   223,
     235,   223,   223,   237,    43,   252,   268,    49,    50,   274,
     188,   210,   186,   188,   186,   185,   207,   207,   210,   210,
     289,   290,   210,     4,     5,   280,   282,   186,   186,   185,
     185,   188,   188,   186,   186,   210,    84,    84,   188,   188,
     188,   215,   188,   188,   223,   210,   210,   210,   188,   188,
     210,   215,   215,   229,   226,   210,    16,    44,   262,   210,
     210,   210,   210,   210,   207,    96,   207,   186,   186,   210,
     210,   215,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   207,   210,   207,   207,   207,   210,   210,   210,   210,
     214,   207,   214,   207,   207,   188,   188,   186,   186,   186,
     186,    39,    40,   254,   192,   210,   188,    58,   207,   207,
     287,   188,   280,   280,   186,   185,   185,   188,   223,   223,
     210,   210,   188,   296,   296,   207,   207,   207,   210,   210,
     186,   186,   186,   186,   188,   207,   207,   203,   185,    12,
     186,   186,   186,   186,   186,   186,   186,   186,   188,   186,
     186,   186,   203,   186,   186,   186,   186,   186,   186,   188,
     186,   186,   186,   188,   186,   186,   188,   186,   188,   186,
     186,   188,   188,   186,   186,   188,   186,   186,   188,   186,
     186,   219,   219,   251,    43,    38,   269,   186,   210,   185,
     186,   188,   210,   291,   223,   223,   281,   186,   186,   207,
     188,   188,    75,    75,    75,   210,   188,   215,     4,     5,
     238,   239,   210,   207,   210,   210,   207,   210,   210,   207,
     210,   207,   207,   253,   255,    48,   276,    60,    61,   186,
     210,    58,   207,   186,   280,   186,   186,   280,   207,   207,
     207,   207,   207,   186,   210,   185,   185,   186,   188,    13,
     246,   186,   188,   186,   186,   186,   186,   186,   186,   186,
     186,   192,   192,   210,    47,   275,   185,   188,   185,   186,
     292,    75,   186,   186,   230,   239,   210,   243,   210,    46,
     279,   192,   270,   207,   210,   210,   294,   207,   192,   192,
     186,   277,    14,    16,    18,    41,    44,    49,   271,   186,
     188,   186,   188,   280,    25,    44,   231,   244,   192,   207,
     210,    14,    16,    18,    41,    44,    49,   245,   278,   186,
     186,     4,   247,   276
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   190,   191,   192,   193,   192,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   195,   194,   196,   194,   194,   194,
     194,   194,   194,   194,   197,   194,   198,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   199,   194,
     200,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   201,   201,   201,   201,   201,   202,   202,   202,   202,
     202,   202,   203,   203,   204,   204,   204,   204,   204,   205,
     205,   206,   206,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     211,   210,   212,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   213,   214,   215,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   217,   217,   217,
     218,   218,   218,   218,   219,   219,   220,   220,   220,   220,
     221,   222,   224,   223,   225,   225,   225,   226,   226,   228,
     229,   230,   227,   231,   231,   232,   232,   233,   233,   233,
     233,   234,   234,   235,   235,   235,   235,   236,   236,   237,
     237,   237,   237,   238,   238,   238,   239,   239,   239,   239,
     241,   242,   243,   244,   240,   245,   245,   245,   245,   245,
     245,   246,   246,   247,   247,   249,   248,   250,   250,   251,
     251,   252,   253,   252,   254,   255,   254,   257,   256,   258,
     258,   258,   258,   258,   258,   260,   261,   259,   262,   262,
     264,   263,   265,   265,   265,   265,   265,   265,   267,   268,
     269,   270,   266,   271,   271,   271,   271,   271,   271,   273,
     272,   274,   274,   275,   275,   276,   277,   278,   276,   279,
     279,   280,   281,   280,   282,   282,   282,   282,   283,   283,
     284,   284,   284,   284,   285,   285,   285,   285,   286,   286,
     286,   286,   286,   287,   287,   287,   289,   288,   290,   288,
     291,   288,   292,   288,   293,   288,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   296,   296,   297,   297,   298,   298
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
       4,     4,     1,     1,     2,     1,     2,     2,     8,     6,
       6,     0,     1,     1,     2,     2,     3,    10,     8,     8,
       8,     3,     1,     1,     6,     4,     4,     6,     6,     4,
       6,     1,     4,     1,     1,     1,     1,     3,     3,     6,
       6,     8,     6,     4,     6,     8,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     1,     3,     1,     3,     4,     6,     6,     4,     6,
       4,     6,    10,     4,     4,     4,     8,     6,     3,     3,
       0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
       3,     4,     6,     1,     4,     4,     6,     6,     1,     1,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     3,     6,
       6,     4,     4,     4,     4,     6,     6,     8,     6,     8,
       4,     4,     4,     8,     4,     4,     4,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     6,
       6,     4,     6,     6,     6,     4,     8,     6,     8,     6,
       4,     4,     4,     6,     6,     6,     8,     1,     2,     2,
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

    {add_command(cFRNBF_SET_BUFFER, NULL, NULL);}

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

    {create_function(fFRNFN_CALL2);}

    break;

  case 158:

    {create_function(fFRNBF_ALLOC);}

    break;

  case 159:

    {create_function(fFRNBF_DUMP);}

    break;

  case 160:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 161:

    {create_function(fDATE);}

    break;

  case 162:

    {create_function(fDATE);}

    break;

  case 163:

    {create_function(fTIME);}

    break;

  case 164:

    {create_function(fTIME);}

    break;

  case 165:

    {create_function(fPEEK2);}

    break;

  case 166:

    {create_function(fPEEK3);}

    break;

  case 167:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 168:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 169:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 170:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 171:

    {create_function(fGETBIT);}

    break;

  case 172:

    {create_function(fGETCHAR);}

    break;

  case 173:

    {create_function(fHEX);}

    break;

  case 174:

    {create_function(fBIN);}

    break;

  case 175:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 176:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 177:

    {create_function(fFRNBF_GET_BUFFER);}

    break;

  case 178:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 179:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 180:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 181:

    {poplabel();create_boole('|');}

    break;

  case 182:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 183:

    {poplabel();create_boole('&');}

    break;

  case 184:

    {create_boole('!');}

    break;

  case 185:

    {create_dblrelop('=');}

    break;

  case 186:

    {create_dblrelop('!');}

    break;

  case 187:

    {create_dblrelop('<');}

    break;

  case 188:

    {create_dblrelop('{');}

    break;

  case 189:

    {create_dblrelop('>');}

    break;

  case 190:

    {create_dblrelop('}');}

    break;

  case 191:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 192:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 193:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 194:

    {add_command(cARDIM,"",NULL);}

    break;

  case 195:

    {add_command(cARDIM,"",NULL);}

    break;

  case 196:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 197:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 198:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 199:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 200:

    {create_dblbin('+');}

    break;

  case 201:

    {create_dblbin('-');}

    break;

  case 202:

    {create_dblbin('*');}

    break;

  case 203:

    {create_dblbin('/');}

    break;

  case 204:

    {create_dblbin('^');}

    break;

  case 205:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 206:

    {create_strrelop('=');}

    break;

  case 207:

    {create_strrelop('!');}

    break;

  case 208:

    {create_strrelop('<');}

    break;

  case 209:

    {create_strrelop('{');}

    break;

  case 210:

    {create_strrelop('>');}

    break;

  case 211:

    {create_strrelop('}');}

    break;

  case 214:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 215:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 217:

    {create_function(fSIN);}

    break;

  case 218:

    {create_function(fASIN);}

    break;

  case 219:

    {create_function(fCOS);}

    break;

  case 220:

    {create_function(fACOS);}

    break;

  case 221:

    {create_function(fTAN);}

    break;

  case 222:

    {create_function(fATAN);}

    break;

  case 223:

    {create_function(fATAN2);}

    break;

  case 224:

    {create_function(fEXP);}

    break;

  case 225:

    {create_function(fLOG);}

    break;

  case 226:

    {create_function(fLOG2);}

    break;

  case 227:

    {create_function(fSQRT);}

    break;

  case 228:

    {create_function(fSQR);}

    break;

  case 229:

    {create_function(fINT);}

    break;

  case 230:

    {create_function(fROUND);}

    break;

  case 231:

    {create_function(fCEIL);}

    break;

  case 232:

    {create_function(fFLOOR);}

    break;

  case 233:

    {create_function(fFRAC);}

    break;

  case 234:

    {create_function(fABS);}

    break;

  case 235:

    {create_function(fSIG);}

    break;

  case 236:

    {create_function(fMOD);}

    break;

  case 237:

    {create_function(fRAN);}

    break;

  case 238:

    {create_function(fRAN2);}

    break;

  case 239:

    {create_function(fMIN);}

    break;

  case 240:

    {create_function(fMAX);}

    break;

  case 241:

    {create_function(fLEN);}

    break;

  case 242:

    {create_function(fVAL);}

    break;

  case 243:

    {create_function(fASC);}

    break;

  case 244:

    {create_function(fDEC);}

    break;

  case 245:

    {create_function(fDEC2);}

    break;

  case 246:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 247:

    {create_function(fINSTR2);}

    break;

  case 248:

    {create_function(fRINSTR);}

    break;

  case 249:

    {create_function(fRINSTR2);}

    break;

  case 250:

    {create_function(fSYSTEM);}

    break;

  case 251:

    {create_function(fFRNFN_CALL);}

    break;

  case 252:

    {create_function(fFRNFN_SIZE);}

    break;

  case 253:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 254:

    {create_function(fFRNBF_SIZE);}

    break;

  case 255:

    {create_function(fPEEK4);}

    break;

  case 256:

    {create_function(fPEEK);}

    break;

  case 257:

    {create_function(fMOUSEX);}

    break;

  case 258:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 259:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 260:

    {create_function(fMOUSEY);}

    break;

  case 261:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 262:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 263:

    {create_function(fMOUSEB);}

    break;

  case 264:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 265:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 266:

    {create_function(fMOUSEMOD);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 268:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 269:

    {create_function(fAND);}

    break;

  case 270:

    {create_function(fOR);}

    break;

  case 271:

    {create_function(fBITNOT);}

    break;

  case 272:

    {create_function(fEOR);}

    break;

  case 273:

    {create_function(fSHL);}

    break;

  case 274:

    {create_function(fSHR);}

    break;

  case 275:

    {create_function(fTELL);}

    break;

  case 276:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 277:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 278:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 279:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 280:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 281:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 282:

    {create_myopen(0);}

    break;

  case 283:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 284:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 285:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 286:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 287:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 288:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 289:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 290:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 291:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 292:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 293:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 294:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 295:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 296:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 297:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 298:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 299:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 300:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 301:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 302:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 309:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 310:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 311:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 312:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 313:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 314:

    {missing_endsub--;}

    break;

  case 315:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 316:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 317:

    {exported=FALSE;}

    break;

  case 318:

    {exported=TRUE;}

    break;

  case 319:

    {exported=FALSE;}

    break;

  case 320:

    {exported=TRUE;}

    break;

  case 323:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 324:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 325:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 326:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 329:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 330:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 331:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 332:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 336:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 337:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 338:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 339:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 340:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 341:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 342:

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

  case 343:

    {
             swap();popgoto();poplabel();}

    break;

  case 344:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 345:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 346:

    {missing_next--;}

    break;

  case 347:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 348:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 349:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 350:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 351:

    {create_pushdbl(1);}

    break;

  case 353:

    {pop(stSTRING);}

    break;

  case 354:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 355:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 356:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 362:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 363:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 365:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 367:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 369:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 370:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 371:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 372:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 373:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 374:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 375:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 376:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 378:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 379:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 380:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 382:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 383:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 384:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 385:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 386:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 387:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 388:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 389:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 390:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 391:

    {poplabel();}

    break;

  case 393:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 394:

    {missing_endif--;}

    break;

  case 395:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 396:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 397:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 398:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 399:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 401:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 402:

    {poplabel();}

    break;

  case 406:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 407:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 412:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 414:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 415:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 416:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 417:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 420:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 421:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 422:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 423:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 424:

    {create_strdata((yyvsp[0].string));}

    break;

  case 425:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 426:

    {create_strdata((yyvsp[0].string));}

    break;

  case 427:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 431:

    {create_print('s');}

    break;

  case 432:

    {create_print('s');}

    break;

  case 433:

    {create_print('d');}

    break;

  case 434:

    {create_print('u');}

    break;

  case 435:

    {create_print('U');}

    break;

  case 436:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 437:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 438:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 439:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 440:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 441:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 442:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 443:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 444:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 445:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 446:

    {create_pushstr("?");create_print('s');}

    break;

  case 447:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 448:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 454:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 455:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 457:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 460:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 461:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 464:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 465:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 466:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 467:

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
