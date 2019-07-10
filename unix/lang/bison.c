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
    tFRNBF_ALLOC = 414,
    tFRNBF_FREE = 415,
    tFRNBF_SIZE = 416,
    tFRNBF_DUMP = 417,
    tFRNBF_SET = 418,
    tFRNBF_GET = 419,
    tFRNBF_GET2 = 420,
    tFRNBF_GET_BUFFER = 421,
    tFRNBF_SET_BUFFER = 422,
    tDATE = 423,
    tTIME = 424,
    tTOKEN = 425,
    tTOKENALT = 426,
    tSPLIT = 427,
    tSPLITALT = 428,
    tGLOB = 429,
    UMINUS = 430
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
#define YYFINAL  267
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  185
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  462
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1093

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   430

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   184,     2,     2,     2,     2,
     180,   181,   177,   176,   183,   175,     2,   178,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   182,
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
     179
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   188,   189,   189,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   211,   212,   212,   213,   214,
     215,   216,   217,   218,   219,   219,   221,   221,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   233,
     234,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   251,   252,   253,   254,   255,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   306,   307,   308,   309,   310,   314,   315,   316,   317,
     318,   319,   322,   323,   326,   327,   328,   329,   330,   333,
     334,   337,   338,   341,   342,   343,   344,   345,   346,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   390,   391,
     394,   394,   395,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   428,   431,   434,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   505,   506,   507,   510,   511,   512,   515,
     516,   519,   520,   521,   522,   525,   528,   531,   531,   534,
     535,   536,   539,   540,   543,   544,   547,   543,   552,   553,
     556,   557,   560,   561,   562,   563,   566,   567,   570,   571,
     572,   573,   576,   577,   580,   581,   582,   583,   586,   587,
     588,   591,   592,   593,   594,   597,   598,   602,   616,   597,
     621,   622,   623,   624,   625,   626,   629,   630,   633,   634,
     639,   639,   643,   644,   647,   648,   652,   654,   653,   658,
     659,   659,   663,   663,   669,   670,   671,   672,   673,   674,
     678,   679,   678,   685,   686,   690,   690,   695,   696,   697,
     698,   699,   700,   703,   704,   704,   706,   703,   710,   711,
     712,   713,   714,   715,   718,   718,   723,   724,   727,   728,
     731,   733,   735,   732,   739,   740,   743,   744,   744,   747,
     748,   750,   751,   755,   756,   759,   760,   762,   763,   767,
     768,   769,   770,   773,   774,   775,   776,   777,   780,   781,
     782,   785,   785,   786,   786,   787,   787,   788,   788,   789,
     789,   792,   793,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   812,   813,   815,
     816,   819,   820
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
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
  "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET",
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE",
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
     425,   426,   427,   428,   429,    45,    43,    42,    47,   430,
      40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -772

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-772)))

#define YYTABLE_NINF -384

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4117,   -41,   -31,  -772,  -772,  -772,  -772,  -772,    87,    87,
      87,  3004,  -772,  -772,  -772,  3743,  -165,  -156,  3743,    17,
      26,  -772,  -772,  -772,  3352,   -21,  -772,  3352,   124,  -772,
    3352,  3352,  3352,   266,    52,    87,  1771,  1170,  2119,    19,
    3352,  2830,  3352,   258,   -33,  3352,  -772,    47,  3743,  3743,
    3743,   -20,  -108,   -32,   -16,   -12,    20,  2119,  3743,  3743,
    3743,   184,   143,  -772,    11,  -772,  -772,  -772,  -772,   136,
     161,  -772,   215,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    3352,  -772,  3743,  -772,   253,  3352,  3965,  -772,  -772,  -772,
    -772,  -772,  -772,   130,   138,  -772,  -772,  -772,   172,   197,
     272,   218,   240,  3352,   242,   244,   250,   252,   279,   281,
     283,   309,   340,   343,   389,   397,   406,   424,   425,   428,
     439,   442,   450,   469,   478,   479,   489,   491,   493,   497,
     506,   510,   516,   520,   523,   532,   542,   543,   558,   560,
     561,   568,   571,   572,   580,   583,   584,   604,   605,   606,
     607,   612,   615,   616,   617,   621,   622,   626,   627,   629,
     630,   631,   636,   637,   638,   639,   640,   641,   642,   643,
     647,   650,   651,   652,   654,   655,  3352,  3352,    38,  -772,
     316,  -772,  -772,  -772,  -772,   333,   358,  3743,   325,  -772,
    -772,   325,  -772,  -772,  3352,  3965,   371,   656,   361,   657,
      24,  3352,   -22,    38,  1324,   658,   664,   330,  1324,    38,
     665,    38,   687,   669,   670,   405,  -772,  -772,   194,   194,
    -772,  -772,   443,  -772,  3352,  3743,  3352,   151,  1324,   514,
    -772,  -772,  -772,  -772,   541,  3743,   865,  -772,  3352,  -772,
      -2,   556,  -772,  -772,  3352,  3178,  -772,  -772,  1324,  -772,
    -772,   136,   161,   325,    -6,    -6,  -772,   499,   499,   499,
    2293,  3743,    12,   668,   325,  -127,  -106,  -772,  -772,   810,
    3352,  3352,  3352,  3352,  3743,  -772,  1324,   672,  3352,   325,
     677,   768,  1324,    28,  -772,  -772,  -772,  -772,  3352,  3352,
     487,  3352,  1945,  2119,   360,   360,  3352,  3352,  3352,  3352,
    3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,  2119,  3352,
    3352,  3352,  3352,  3352,  3352,  3352,  2472,  3743,  3743,  3743,
    3743,  3743,  3352,  3352,  3352,  2651,  3352,  3743,  3352,  3743,
    3352,  3743,  3743,  1358,  1502,  3510,  3561,  3743,  3743,  3743,
    3743,  3743,  3743,  3743,  3743,  2119,  3743,  -772,  -772,  3743,
    3352,  3743,  3743,  3743,  3743,  3743,   678,   679,  3743,   499,
    3743,   499,  3743,   795,    53,  1649,  3743,  3743,  3743,  3743,
    3743,  3743,  3743,  -772,  -772,  -772,  -772,  3352,  3352,  3352,
    3352,  3352,  3352,  3352,  3352,  3352,  3352,  3352,   692,   698,
     700,  -772,   701,   704,   702,  -772,    92,   705,   706,    38,
    1324,   846,   559,   844,  3965,  3352,   710,  3743,  -772,  -772,
    3352,    38,   416,   146,   711,    25,  -772,   883,  -772,  -772,
     376,  3352,  3352,  -772,  -772,   266,  -772,  -772,    55,  1041,
     325,  1324,   462,  3617,  3352,   325,  3352,  -772,   -22,  -772,
    -772,  3352,  3743,  -772,  3352,    -2,  3352,  3352,   713,   712,
     714,   715,  -772,  1664,   219,  3352,  3352,  3352,  3352,  3965,
     717,    -2,    -2,  1324,   325,   446,  -772,    38,  1324,   718,
    -772,  -772,  -772,  3965,  -772,  -772,  3352,  -772,  -772,  -772,
    -772,   721,   722,  1289,  1365,  1376,   723,   288,   724,   725,
     716,   731,   732,   733,   729,   735,    -2,  1501,  4008,  4466,
    4477,  4523,  4548,   440,  4594,   470,  4605,  4616,   734,  4640,
    4665,  4676,  4687,  4733,  4757,  1524,  -772,  4804,   296,   -86,
     -58,    -4,   314,  1790,  1960,   699,  -772,  4815,  4826,   324,
    4850,   -88,  4874,   369,   384,  -772,   392,  -772,   399,  -772,
     402,  -772,   408,   409,   419,   420,     6,    23,   444,   452,
     474,   448,   738,   -80,   739,   740,   476,  4885,   494,    -5,
      40,    50,    72,  -772,  -772,    93,   -69,    96,   -68,   164,
    -772,  -772,   325,   325,   325,   325,   325,   325,  -772,    87,
      87,  3352,  3352,   459,   321,   613,   251,   463,    68,  -772,
     -25,   -25,   795,   795,  -772,  -772,   333,  -772,  -772,   358,
    -772,  -772,  -772,   863,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,   432,  2134,  3352,     4,  4896,  3794,  -772,  -772,
    3352,  3352,  -772,  -772,  3352,  -772,   547,   741,   742,   736,
     745,  2308,  2487,   748,   757,  -772,  -772,  -772,  3352,   859,
     860,  -772,   165,  2669,  1324,  -772,  -772,   177,  -772,  3352,
    2845,  3019,  -772,  3352,  3352,  3352,  -772,  -772,    38,  1324,
      38,  1324,  3193,  3367,  -772,  3352,  3352,  3352,  -772,  -772,
    -772,  3352,  3352,    -1,  1324,  -772,  -772,  3352,  3352,  3352,
    -772,  -772,  3743,  3668,  -772,   761,   762,  -772,  -772,  3352,
    3352,  3352,  3352,  -772,  -772,  -772,  -772,  -772,  -772,  3352,
    -772,  -772,  3352,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  3352,  -772,  -772,  3352,  3352,  3352,  -772,  3352,
    3352,  -772,  3743,  -772,  -772,  -772,  -772,  -772,  3352,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  3743,
    3743,  -772,  -772,  -772,  -772,  -772,  -772,  3743,  -772,  -772,
    -772,  -772,  -772,  -772,  3352,  3352,  3352,  3352,   936,  -772,
    3743,   936,  -772,  3743,  3743,  -772,   763,  -772,   765,   487,
    3562,   764,   769,  -772,   770,   771,  -772,  -772,   528,  3965,
    -772,  -772,  -772,  3352,  3527,   887,  3743,  -772,  3743,   325,
      38,   416,  4265,   547,   547,  4943,   773,   774,  -772,   772,
    -772,  -772,  -772,  -772,  3352,  3352,  -772,  -772,  4312,  2119,
    2119,  3743,  3743,  3743,  -772,  3352,  3352,   775,  4967,  5013,
    1010,  3743,  3743,  1324,    -2,  -772,   777,  -772,    75,  -772,
    -772,  -772,  5024,  5035,  5060,   511,   779,   149,  -772,  -772,
    5084,  5095,   780,    64,  5106,  5152,  5177,  5223,  5234,  1030,
    5245,  5269,   150,  5294,   220,   232,   513,  5305,  4337,  4383,
    5316,    73,   517,    77,   534,   535,    87,    87,  -772,  -772,
    -772,  -772,  3352,   916,   926,   923,  5362,  3352,   786,   537,
     236,  -772,  3352,  -772,  -772,  -772,  -772,  -772,  -772,   787,
     788,  1324,  1324,  3743,  -772,  -772,   325,   325,   221,  4394,
    1324,  -772,   896,   899,   900,  3352,   238,   325,  3352,   593,
    3352,  -772,  -772,  -772,  -772,  -772,  -772,  3743,  -772,  -772,
    -772,  3352,  -772,  -772,  -772,  -772,  -772,  -772,  3352,  -772,
    -772,  -772,  3743,  -772,  -772,  3352,  -772,  3352,  -772,  -772,
    3743,  3352,  -772,  -772,  3743,  -772,  -772,  3743,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   925,   552,  5386,  3352,   918,
    3743,  5433,   547,   792,   796,   547,  -772,  -772,   325,  3743,
    3743,  3743,  3743,  3743,  5444,  3352,  -772,   798,   799,   102,
    -772,    88,   538,  4405,  5455,   544,  5479,  5503,   545,  5514,
     566,   598,  3965,  4269,  3352,   934,  -772,   801,  -772,  4430,
     802,   600,  -772,  -772,  -772,  -772,  -772,   325,   325,   325,
     325,   325,   914,  1324,   805,   806,  -772,   593,  3352,  -772,
    -772,  3352,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
     923,   951,   386,  3965,  -772,  3743,  3352,  3352,  -772,   883,
    3743,  -772,  -772,  3965,  -772,  1324,  3965,  5525,  -772,  -772,
     923,   659,   292,  5572,  4455,   547,   325,    41,   923,  -772,
    3965,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  3743,
    -772,  3352,  -772,  -772,  -772,  -772,   760,   923,   602,  5596,
    -772,  -772,  -772,  -772,  -772,  -772,   985,   925,  -772,  -772,
    -772,  -772,  -772
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     111,     0,     0,   105,   335,   370,   375,    11,     0,     0,
       0,     0,    24,    26,   313,     0,     0,     0,     0,   314,
      18,    20,   350,   362,     0,   443,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   112,   113,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     4,     3,     0,     7,    39,    41,     9,    22,
      23,    21,     0,    13,    14,    17,    16,    15,    28,    29,
       0,   297,     0,   297,     0,     0,     6,   290,   289,    30,
      31,    38,   286,   199,   133,   287,   288,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,   257,   260,   263,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,   212,   193,   198,   135,     0,     0,     0,    12,   297,
     297,    42,   315,    19,     0,     6,   394,     0,   447,     0,
       0,   423,   439,    62,    61,     0,     0,    63,   104,    53,
       0,    55,     0,   415,   417,    56,   413,   419,     0,     0,
     420,   283,    57,    59,     0,    89,     0,     0,   458,     0,
      86,    91,    79,    40,     0,     0,     0,    67,     0,    50,
      72,     0,    88,    87,     0,     0,   114,   115,    92,     8,
      10,     0,     0,   106,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     1,     2,     0,
       0,     0,     0,     0,     0,   304,   178,     0,   299,   116,
       0,     0,   371,     4,   297,   297,    32,    33,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,   297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    36,   182,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,   319,
      25,   316,   324,   325,    27,   322,     0,     0,     0,   355,
     354,     0,     4,     0,     6,     0,     0,     0,   444,   445,
       0,   426,   428,    45,     0,     0,    49,   441,   297,   297,
       0,     0,     0,   297,   297,     0,   285,   284,     0,     0,
      90,   457,     0,     0,     0,    66,     0,    71,   439,   123,
     122,     0,     0,    68,     0,    74,     0,     0,   131,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,   179,   121,     0,   295,   302,   303,   298,
     300,   296,   336,     6,   382,   380,     0,   381,   377,   379,
     376,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,   261,     0,   264,
       0,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   164,     0,     0,     0,     0,     0,
     138,   213,   207,   209,   211,   208,   210,   206,   137,     0,
       0,     0,     0,   186,   188,   190,   187,   189,   185,   204,
     201,   200,   202,   203,   297,   297,     0,   297,   297,     0,
      43,    44,   352,   356,   369,   367,   368,   365,   364,   366,
     363,   384,     4,     0,     0,     0,     0,     0,   424,    46,
      47,     0,   431,   433,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   414,   421,   422,     0,     0,
       0,   126,   125,   129,   216,    51,    69,    82,    73,     0,
       0,     0,   297,     0,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     5,     0,     0,     0,   310,   311,
     305,     0,     0,     4,   378,   276,   175,     0,     0,     0,
     277,   278,     0,     0,   271,     0,     0,   194,   195,     0,
       0,     0,     0,   217,   218,   219,   220,   221,   222,     0,
     224,   225,     0,   227,   228,   191,   233,   234,   229,   230,
     231,   232,     0,   236,   241,     0,     0,     0,   240,     0,
       0,   143,     0,   148,   149,   242,   173,   243,     0,   174,
     150,   151,   256,   259,   262,   265,   154,   152,   153,     0,
       0,   155,   249,   156,   255,   254,   165,     0,   250,   157,
     251,   158,   253,   159,     0,     0,     0,     0,     0,   168,
       0,     0,   170,     0,     0,   459,    35,   461,    37,   183,
     181,     0,     0,   317,     0,     0,   323,   353,   359,     6,
     396,   397,   395,     0,     0,   448,     0,   446,     0,   429,
     427,   428,     0,     0,     0,     0,   409,   411,   440,   406,
     291,   293,   297,   297,     0,     0,   416,   418,    64,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    85,     0,   301,     0,   374,
     373,   372,     0,     0,     0,     0,     0,     0,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,   321,
     326,   327,     0,     0,     0,   385,     0,     0,     0,     0,
       0,   425,     0,   432,   434,   435,   297,   297,   407,     0,
       0,    52,    54,     0,   127,   128,   124,   130,    83,    76,
      77,   132,     0,     0,     0,     0,   109,   110,     0,   328,
       0,   268,   269,   270,   279,   280,   281,     0,   196,   197,
     171,     0,   223,   226,   235,   139,   140,   142,     0,   238,
     239,   144,     0,   244,   245,     0,   247,     0,   166,   160,
       0,     0,   177,   273,     0,   167,   275,     0,   169,   192,
     460,   462,   357,   360,   351,   400,   450,     0,     0,   449,
       0,     0,     0,     0,     0,     0,   292,   294,    65,     0,
       0,     0,     0,     0,     0,     0,    81,   331,   332,     0,
     329,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,   111,     0,   398,   454,     0,   451,     0,
       0,     0,   437,   436,   410,   412,   408,    84,    75,   119,
     120,   118,     0,   108,     0,     0,   306,     0,     0,   337,
     282,     0,   141,   145,   246,   248,   252,   176,   272,   274,
     358,     4,   404,     6,   386,     0,     0,     0,   430,   441,
       0,   333,   334,     6,   330,   347,     6,     0,   405,   401,
     399,     0,     0,     0,     0,     0,   117,     4,   338,   172,
       6,   393,   390,   391,   392,   388,   389,   387,   455,     0,
     452,     0,   438,   309,   308,   307,     0,   402,     0,     0,
     341,   343,   344,   345,   340,   342,   348,   400,   456,   453,
     349,   339,   403
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -772,  -772,   -84,  -772,   531,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,   945,  -237,  -772,  -772,  -192,   797,  -772,   950,
     -11,  -772,  -772,   707,  -291,   -35,  -772,   573,   -26,     2,
    -772,     1,     3,   -73,  -772,  -772,   328,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   404,  -772,   407,  -772,   -14,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,   132,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,   -82,  -772,  -772,  -772,
    -771,  -772,  -772,  -772,   586,  -772,  -772,   217,   574,  -772,
    -772,  -772,  -772,  -772,   -30,  -772,    16,  -772,  -772
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    62,   269,    63,   185,   186,   579,   580,   202,
     438,    64,    65,   441,    66,    67,   449,   178,   179,    68,
     236,   582,   581,   492,   493,   237,   181,   220,   182,    89,
     207,   183,   184,   277,   278,   469,   470,    71,   465,   826,
    1043,  1075,   670,    72,   390,   391,   394,   395,   979,   980,
      73,    84,   672,  1046,  1076,  1086,  1019,  1091,    74,   194,
     603,   401,   778,   992,   874,   993,    75,   195,   610,    76,
      85,   473,   831,    77,    86,   480,    78,   403,   779,   955,
    1051,  1067,    79,   404,   782,  1034,   995,  1060,  1087,  1049,
     798,   965,   799,   215,   216,   222,   413,   618,   416,   793,
     794,   962,  1039,   417,   626,   201,   229,   766,   768
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,    69,   283,    70,   495,   439,   240,   241,   221,   439,
     280,    90,    91,   196,   829,   189,   204,   446,   447,   208,
     210,   212,   883,   884,   190,   228,   228,   228,   408,   622,
      80,   409,   623,   193,   248,   414,   197,   223,   198,   199,
      82,   474,   830,   475,   192,   476,   228,   383,   251,   372,
     252,     1,     2,   233,   234,    92,   457,   247,    92,    95,
      96,   217,    95,    96,   636,  1073,   450,   451,   477,   276,
     372,   478,   257,   263,   282,   439,   479,   458,   366,   367,
     368,   369,   370,   371,  1074,   256,   910,    69,   372,    70,
     372,    87,   290,   727,    88,   728,   372,   715,   270,   271,
    1018,   746,   235,   747,   366,   367,   368,   369,   370,   371,
     272,   402,   759,   762,   760,   763,   397,   398,   372,   366,
     367,   368,   369,   370,   371,   716,   375,   376,   205,   206,
     377,   378,   379,   380,   381,   382,   383,   375,   376,    81,
     383,   377,   378,   379,   380,   381,   382,   383,   258,    83,
     375,   376,   386,   387,   377,   378,   379,   380,   381,   382,
     383,   432,   415,   200,   259,   363,   365,   566,   260,   568,
     372,   372,   372,    52,    53,    54,   753,   440,   754,   717,
     372,   440,   372,   400,   267,   785,   268,   786,   372,   739,
     412,  1003,   426,   427,  1006,   455,    69,    92,    70,   372,
     261,    95,    96,   437,   410,   624,   740,   273,   649,   443,
     445,   481,   482,   429,   372,   431,   372,   366,   367,   368,
     369,   370,   371,   755,   666,   667,   372,   218,   219,   372,
     218,   219,   274,   756,   570,   460,   461,   462,   275,   384,
     385,   386,   387,   384,   385,   386,   387,   440,   372,   453,
     384,   385,   386,   387,   943,   757,   944,   281,   946,   691,
     947,   496,   463,   384,   385,   386,   387,   468,   372,   372,
     213,   214,   372,   570,   554,   555,   758,   483,   484,   761,
     485,   228,   228,  1016,  1072,  1017,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   228,   509,   510,
     511,   512,   513,   514,   515,   517,   286,   287,   488,   489,
      81,   523,   524,   525,   527,   528,   242,   530,    83,   532,
     612,   381,   382,   383,   508,   372,   372,   372,   619,   620,
     916,   931,   917,   932,   228,   373,   374,   388,   389,   557,
     372,   372,   243,   244,   245,   627,   628,   764,   811,   246,
     633,   634,   284,   372,   366,   367,   368,   369,   370,   371,
     813,   552,   392,   393,   490,   491,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   285,   375,   376,
     629,   630,   377,   378,   379,   380,   381,   382,   383,   673,
     380,   381,   382,   383,   613,   372,   372,   372,   288,   616,
     657,   934,   221,   935,   969,    69,   646,    70,   372,   648,
     631,   632,   372,   936,   372,   937,  -383,   570,   406,   960,
     289,   975,   291,   643,   292,   644,   384,   385,   386,   387,
     293,  1048,   294,   375,   376,   650,   651,   377,   378,   379,
     380,   381,   382,   383,   659,   661,   662,   663,   375,   376,
     668,   669,   377,   378,   379,   380,   381,   382,   383,   295,
      69,   296,    70,   297,   372,   674,   617,   861,   372,   681,
     863,   682,   372,  1068,    69,  1069,    70,   714,   375,   376,
     780,   781,   377,   378,   379,   380,   381,   382,   383,   298,
     372,   384,   385,   386,   387,   718,   384,   385,   386,   387,
     372,   372,   375,   376,   448,   725,   377,   378,   379,   380,
     381,   382,   383,   420,   366,   367,   368,   369,   370,   371,
     299,   771,   772,   300,   774,   775,   378,   379,   380,   381,
     382,   383,   375,   376,   382,   383,   377,   378,   379,   380,
     381,   382,   383,   639,   640,   372,   384,   385,   386,   387,
     730,   796,   797,   377,   378,   379,   380,   381,   382,   383,
     372,   384,   385,   386,   387,   731,   872,   873,   372,   301,
     769,   770,   604,   732,   605,   372,   606,   302,   372,   817,
     733,   765,   767,   734,   372,   372,   303,   908,   425,   735,
     736,   384,   385,   386,   387,   372,   372,   977,   978,   607,
     737,   738,   608,   784,   304,   305,   921,   609,   306,   791,
     792,   996,   997,   795,   814,   384,   385,   386,   387,   307,
     372,   698,   308,   699,   372,   741,   428,   808,   372,   744,
     309,   824,   825,   742,   384,   385,   386,   387,   384,   385,
     386,   387,   818,   819,   820,   384,   385,   386,   387,   310,
     372,   701,   372,   702,   823,   743,   842,   750,   311,   312,
     468,   828,   384,   385,   386,   387,   832,   833,   834,   313,
     372,   314,  1061,   315,  1062,   752,  1063,   316,   840,   841,
     378,   843,   380,   381,   382,   383,   317,   372,   844,   372,
     318,   845,   914,   372,   938,   875,   319,   433,   945,  1064,
     320,   846,  1065,   321,   847,   848,   849,  1066,   850,   851,
     372,   372,   322,   372,   372,   948,   949,   853,   959,  1020,
     372,   372,   323,   324,   434,  1023,  1026,   375,   376,   889,
     890,   377,   378,   379,   380,   381,   382,   383,   325,   442,
     326,   327,   372,   857,   858,   859,   860,  1028,   328,   375,
     376,   329,   330,   377,   378,   379,   380,   381,   382,   383,
     331,   375,   376,   332,   333,   377,   378,   379,   380,   381,
     382,   383,   876,  1080,   372,  1081,   372,  1082,   372,  1029,
      69,  1038,    70,  1088,   334,   335,   336,   337,   384,   385,
     386,   387,   338,   891,   892,   339,   340,   341,   228,   228,
    1083,   342,   343,  1084,   899,   900,   344,   345,  1085,   346,
     347,   348,   188,   963,   964,   191,   349,   350,   351,   352,
     353,   354,   355,   356,   203,   894,   895,   357,   209,   211,
     358,   359,   360,   227,   361,   362,   405,   407,   418,   472,
     384,   385,   386,   387,   419,   253,   254,   255,   421,   423,
     424,   456,   459,   466,   262,   264,   265,   266,   471,   563,
     564,   400,   384,   385,   386,   387,   957,   383,   950,   951,
     422,   961,   594,   976,   384,   385,   386,   387,   595,   279,
     721,   597,   722,   596,   598,   599,   600,   601,   602,   611,
     614,   621,   625,   652,   974,   653,   685,   654,   655,   981,
     665,   671,   675,   676,   680,   777,   684,   683,  1030,  1031,
     983,   686,   689,   687,   688,   705,   802,   984,   690,   745,
     748,   749,   800,   801,   986,   803,   987,   375,   376,   806,
     989,   377,   378,   379,   380,   381,   382,   383,   807,   809,
     810,   491,   838,   839,   878,   868,   866,   999,   867,  1050,
     869,   870,   871,   886,   887,   888,   901,   909,   953,  1057,
     915,   920,  1058,   954,  1013,    -4,   958,   971,   966,   967,
     972,   973,   994,  1004,   364,  1000,  1077,  1005,  1014,  1015,
    1033,  1035,  1037,  1032,   396,  1040,  1041,  1042,  -361,  1090,
     664,   399,   249,    69,    69,    70,    70,   250,   411,   827,
     773,   637,   494,  1044,   952,  1092,   776,  1045,   881,  1055,
    1047,   635,   645,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,  1053,  1054,     0,     0,     0,
       0,     0,   435,     0,    69,     0,    70,     0,     0,     0,
     384,   385,   386,   387,    69,     0,    70,    69,   436,    70,
       0,     0,     0,     0,     0,     0,     0,     0,   454,     0,
    1079,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,   464,   375,   376,     0,   467,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,     0,     0,   487,
       0,     0,   375,   376,     0,     0,   377,   378,   379,   380,
     381,   382,   383,   375,   376,     0,     0,   377,   378,   379,
     380,   381,   382,   383,   518,   519,   520,   521,   522,     0,
       0,     0,     0,     0,   529,     0,   531,     0,   533,   534,
     536,   538,   540,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   553,     0,     0,   556,     0,   558,   559,
     560,   561,   562,     0,     0,   565,     0,   567,     0,   569,
       0,     0,     0,   572,   573,   574,   575,   576,   577,   578,
       0,     0,     0,    92,    93,    94,     0,    95,    96,    97,
       0,     0,     0,     0,     0,   384,   385,   386,   387,     0,
       0,   904,     0,   905,     0,     0,     0,     0,     0,    98,
      99,     0,     0,     0,   615,   384,   385,   386,   387,     0,
       0,   927,     0,   928,     0,     0,   384,   385,   386,   387,
       0,     0,     0,     0,   638,     0,     0,     0,     0,     0,
     642,     0,   101,   102,   103,   104,     0,     0,     0,   647,
       0,     0,     0,     0,     0,     0,   105,     0,     0,   106,
       0,     0,   658,   660,   230,     0,     0,     0,     0,     0,
       0,     0,   231,     0,     0,     0,   107,   108,     0,     0,
     109,     0,   110,     0,     0,   232,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
       0,   164,   165,     0,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,     0,     0,     0,
     177,   375,   376,     0,   226,   377,   378,   379,   380,   381,
     382,   383,     0,    94,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   375,   376,    99,     0,
     377,   378,   379,   380,   381,   382,   383,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   789,     0,     0,   790,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
     110,     0,     0,     0,   384,   385,   386,   387,   467,     0,
       0,     0,   677,     0,     0,     0,     0,     0,     0,   835,
     837,     0,     0,     0,   131,   132,   133,     0,     0,     0,
     137,   138,   139,     0,   141,     0,   143,   144,   145,   384,
     385,   386,   387,   150,   151,   152,     0,    94,   155,     0,
     157,    97,   159,     0,     0,   161,     0,   163,     0,   852,
     165,     0,     0,   167,   168,     0,   169,   170,     0,   172,
       0,   174,    99,     0,     0,     0,   854,   855,   187,   535,
     384,   385,   386,   387,   856,     0,     0,     0,   678,     0,
       0,   384,   385,   386,   387,     0,     0,   862,     0,   679,
     864,   865,     0,   375,   376,     0,     0,   377,   378,   379,
     380,   381,   382,   383,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   879,     0,   880,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,     0,     0,     0,
       0,     0,   109,     0,   110,     0,     0,     0,   896,   897,
     898,     0,     0,     0,     0,     0,     0,     0,   906,   907,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     133,     0,     0,     0,   137,   138,   139,     0,   141,     0,
     143,   144,   145,     0,     0,     0,     0,   150,   151,   152,
       0,     0,   155,     0,   157,     0,   159,     0,     0,   161,
       0,   163,     0,     0,   165,     0,     0,   167,   168,   399,
     169,   170,     0,   172,     0,   174,   384,   385,   386,   387,
       0,     0,   187,   537,   692,     0,     0,     0,     0,     0,
     968,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,     0,     0,   712,     0,     0,
       0,   375,   376,     0,   982,   377,   378,   379,   380,   381,
     382,   383,     0,     0,     0,     0,   375,   376,     0,   985,
     377,   378,   379,   380,   381,   382,   383,   988,     0,     0,
       0,   990,     0,     0,   991,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1001,     0,     0,
       0,     0,     0,     0,     0,     0,  1007,  1008,  1009,  1010,
    1011,     0,     0,     0,    92,    93,    94,     0,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   384,   385,   386,   387,     0,     0,
     571,     0,  1052,   101,   102,   103,   104,  1056,     0,   384,
     385,   386,   387,     0,     0,   656,     0,   105,     0,     0,
     106,     0,   375,   376,     0,   224,   377,   378,   379,   380,
     381,   382,   383,   225,     0,     0,  1078,   107,   108,     0,
       0,   109,     0,   110,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   162,
     163,     0,   164,   165,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,     0,    92,    93,
      94,   177,    95,    96,    97,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   386,   387,     0,
       0,     0,     0,   719,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   375,   376,   106,     0,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,   486,     0,     0,
       0,   107,   108,     0,     0,   109,     0,   110,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
     176,     0,    92,    93,    94,   177,    95,    96,    97,   226,
       0,     0,     0,     0,     0,   384,   385,   386,   387,     0,
       0,     0,     0,   720,     0,     0,     0,     0,    98,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   375,   376,   106,     0,
     377,   378,   379,   380,   381,   382,   383,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,   109,
       0,   110,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,     0,
     164,   165,     0,   166,   167,   168,     0,   169,   170,   171,
     172,   173,   174,   175,   176,     0,    92,    93,    94,   177,
      95,    96,    97,   226,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,     0,     0,   783,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     375,   376,   106,     0,   377,   378,   379,   380,   381,   382,
     383,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,   109,     0,   110,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,     0,   164,   165,     0,   166,   167,   168,
       0,   169,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,     0,   177,   452,    92,    93,    94,     0,    95,
      96,    97,     0,   384,   385,   386,   387,     0,     0,     0,
       0,   804,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   375,
     376,   106,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,   109,     0,   110,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   176,     0,     0,
       0,     0,   177,   516,    92,    93,    94,     0,    95,    96,
      97,     0,   384,   385,   386,   387,     0,     0,     0,     0,
     805,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
     106,   375,   376,     0,     0,   377,   378,   379,   380,   381,
     382,   383,     0,     0,     0,     0,     0,   107,   108,     0,
       0,   109,     0,   110,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   162,
     163,     0,   164,   165,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,   176,     0,     0,     0,
       0,   177,   526,    92,    93,    94,     0,    95,    96,    97,
       0,   238,     0,     0,   384,   385,   386,   387,     0,     0,
       0,     0,   812,     0,     0,     0,     0,     0,     0,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   375,   376,   106,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
     109,     0,   110,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
       0,   164,   165,     0,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   174,   175,   176,     0,    92,    93,    94,
     177,    95,    96,    97,     0,     0,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,     0,     0,   815,     0,
       0,     0,     0,    98,    99,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   375,   376,   106,     0,   377,   378,   379,   380,   381,
     382,   383,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,   109,     0,   110,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,   176,
       0,    92,    93,    94,   177,    95,    96,    97,     0,   444,
       0,     0,     0,     0,   384,   385,   386,   387,     0,     0,
       0,     0,   816,     0,     0,     0,     0,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   375,   376,   106,     0,   377,
     378,   379,   380,   381,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,   109,     0,
     110,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,     0,   164,
     165,     0,   166,   167,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   176,     0,    92,    93,    94,   177,    95,
      96,    97,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,     0,     0,   821,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   375,
     376,   106,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,   109,     0,   110,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,    94,   166,   167,   168,    97,
     169,   170,   171,   172,   173,   174,   175,   176,     0,     0,
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
      99,     0,   384,   385,   386,   387,     0,     0,     0,     0,
     822,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   375,
     376,    99,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,   375,     0,    97,     0,   377,   378,
     379,   380,   381,   382,   383,     0,   131,   132,   133,     0,
       0,     0,   137,   138,   139,     0,   141,    99,   143,   144,
     145,     0,     0,     0,     0,   150,   151,   152,     0,     0,
     155,   109,   157,   110,   159,     0,     0,   161,     0,   163,
       0,     0,   165,    94,     0,   167,   168,    97,   169,   170,
       0,   172,     0,   174,     0,     0,     0,   131,   132,   133,
     187,   539,     0,   137,   138,   139,     0,   141,    99,   143,
     144,   145,   384,   385,   386,   387,   150,   151,   152,   641,
     877,   155,     0,   157,     0,   159,     0,   109,   161,   110,
     163,     0,     0,   165,     0,     0,   167,   168,     0,   169,
     170,     0,   172,     0,   174,     0,     0,   384,   385,   386,
     387,   187,   541,   131,   132,   133,     0,     0,    94,   137,
     138,   139,    97,   141,     0,   143,   144,   145,     0,     0,
     836,     0,   150,   151,   152,     0,     0,   155,   109,   157,
     110,   159,     0,    99,   161,     0,   163,     0,     0,   165,
       0,     0,   167,   168,     0,   169,   170,     0,   172,     0,
     174,     0,     0,     0,   131,   132,   133,   187,     0,    94,
     137,   138,   139,    97,   141,     0,   143,   144,   145,     0,
       0,     0,     0,   150,   151,   152,     0,     0,   155,     0,
     157,     0,   159,     0,    99,   161,     0,   163,     0,     0,
     165,     0,     0,   167,   168,     0,   169,   170,     0,   172,
       0,   174,     0,   109,     0,   110,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,     0,     0,     0,   137,   138,   139,     0,   141,
       0,   143,   144,   145,     0,     0,     0,     0,   150,   151,
     152,     0,     0,   155,   109,   157,   110,   159,     0,     0,
     161,     0,   163,     0,     0,   165,     0,     0,   167,   168,
       0,   169,   170,     0,   172,     0,   174,     0,     0,     0,
     131,   132,   133,   187,     0,     0,   137,   138,   139,     0,
     141,     0,   143,   144,   145,     0,     0,     0,     0,   150,
     151,   152,     0,     0,   155,     0,   157,     0,   159,     0,
       0,   161,     0,   163,     0,     0,   165,     0,     0,   167,
     168,     0,   169,   170,     0,   172,     0,   174,     0,     1,
       2,     3,     0,     0,   788,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,    11,  -312,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,     0,     0,     0,     0,    23,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,  -111,  -111,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,  -111,     0,    49,     0,    50,    51,
     375,   376,     0,     0,   377,   378,   379,   380,   381,   382,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      57,     1,     2,     3,     0,    58,     0,     4,    59,     0,
       0,     5,    60,     6,     0,     7,     8,     9,    10,    11,
    -312,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,     0,     0,     0,     0,    23,    -6,
      -6,    24,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,   384,   385,   386,   387,     0,     0,   693,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     0,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,     0,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,    57,     1,     2,     3,     0,    58,     0,     4,
      59,     0,     0,     5,    60,     6,     0,     7,     8,     9,
      10,    11,  -312,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    -6,     0,     0,     0,
      23,    -6,     0,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,   375,   376,    31,
      32,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,    39,    40,    41,     0,     0,    42,    43,
      44,     0,    45,    46,    47,     0,     0,    48,     0,     0,
      49,     0,    50,    51,   375,   376,     0,     0,   377,   378,
     379,   380,   381,   382,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,   375,
     376,     0,    55,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,     0,     0,     0,    58,
       0,     0,    59,     0,     0,     0,    60,     0,     0,     0,
     384,   385,   386,   387,     0,   375,   376,     0,   882,   377,
     378,   379,   380,   381,   382,   383,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   385,   386,
     387,     0,   375,   376,     0,   893,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   385,   386,   387,     0,   375,   376,     0,
     940,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   375,
     376,     0,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,     0,     0,   941,     0,     0,   384,
     385,   386,   387,     0,     0,     0,     0,   970,     0,     0,
     384,   385,   386,   387,     0,   375,   376,     0,  1021,   377,
     378,   379,   380,   381,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   386,   387,     0,
     375,   376,     0,  1036,   377,   378,   379,   380,   381,   382,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,     0,     0,  1071,     0,
       0,   384,   385,   386,   387,     0,     0,   694,     0,     0,
       0,     0,   384,   385,   386,   387,   375,   376,   695,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,   375,   376,   696,     0,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   384,   385,   386,   387,   375,   376,   697,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   375,
     376,     0,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   700,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   703,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   704,     0,   377,
     378,   379,   380,   381,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   386,   387,   375,
     376,   706,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   707,     0,     0,     0,
       0,   384,   385,   386,   387,     0,     0,   708,     0,     0,
       0,     0,   384,   385,   386,   387,   375,   376,   709,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,   375,   376,   710,     0,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   385,   386,   387,   375,   376,   711,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   713,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   723,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   724,     0,   377,
     378,   379,   380,   381,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   386,   387,   375,
     376,   726,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   729,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   751,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   787,     0,   377,
     378,   379,   380,   381,   382,   383,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,   375,   376,   885,     0,   377,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   385,   386,   387,   375,   376,   902,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,   903,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   911,     0,     0,     0,     0,
     384,   385,   386,   387,   375,   376,   912,     0,   377,   378,
     379,   380,   381,   382,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   385,   386,   387,   375,
     376,   913,     0,   377,   378,   379,   380,   381,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   918,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   919,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   922,     0,   377,
     378,   379,   380,   381,   382,   383,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   385,   386,
     387,   375,   376,   923,     0,   377,   378,   379,   380,   381,
     382,   383,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   384,   385,   386,   387,   375,   376,   924,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,   375,   376,
       0,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,   925,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   926,     0,     0,     0,     0,
     384,   385,   386,   387,   375,   376,   929,     0,   377,   378,
     379,   380,   381,   382,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   384,   385,   386,   387,   375,   376,
     930,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,   933,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,   939,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   942,     0,   377,
     378,   379,   380,   381,   382,   383,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   385,   386,
     387,   375,   376,   956,     0,   377,   378,   379,   380,   381,
     382,   383,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,   385,   386,   387,   375,   376,   998,     0,   377,
     378,   379,   380,   381,   382,   383,   375,   376,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   375,   376,     0,
       0,   377,   378,   379,   380,   381,   382,   383,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,  1002,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,  1012,     0,     0,     0,     0,
     384,   385,   386,   387,   375,   376,  1022,     0,   377,   378,
     379,   380,   381,   382,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   384,   385,   386,   387,   375,   376,
    1024,     0,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,  1025,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,  1027,     0,     0,     0,     0,
     384,   385,   386,   387,     0,     0,  1059,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   385,   386,
     387,     0,     0,  1070,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,   385,   386,   387,     0,     0,  1089
};

static const yytype_int16 yycheck[] =
{
      11,     0,    86,     0,   295,    11,    41,    42,    34,    11,
      83,     9,    10,    24,    15,   180,    27,   254,   255,    30,
      31,    32,   793,   794,   180,    36,    37,    38,     4,     4,
      71,     7,     7,     7,    45,    57,    57,    35,    59,    60,
      71,    13,    43,    15,    27,    17,    57,    72,    47,   176,
      47,     4,     5,    37,    38,     3,   183,    90,     3,     7,
       8,     9,     7,     8,     9,    24,   258,   259,    40,    80,
     176,    43,   180,    57,    85,    11,    48,   183,    66,    67,
      68,    69,    70,    71,    43,   105,    11,    86,   176,    86,
     176,     4,   103,   181,     7,   183,   176,   183,    87,    88,
      12,   181,    83,   183,    66,    67,    68,    69,    70,    71,
      99,   195,   181,   181,   183,   183,   189,   190,   176,    66,
      67,    68,    69,    70,    71,   183,    62,    63,     4,     5,
      66,    67,    68,    69,    70,    71,    72,    62,    63,   180,
      72,    66,    67,    68,    69,    70,    71,    72,   180,   180,
      62,    63,   177,   178,    66,    67,    68,    69,    70,    71,
      72,    10,   184,   184,   180,   176,   177,   359,   180,   361,
     176,   176,   176,   126,   127,   128,   181,   183,   183,   183,
     176,   183,   176,   194,     0,   181,    43,   183,   176,   183,
     201,   962,   218,   219,   965,   183,   195,     3,   195,   176,
     180,     7,     8,   238,   180,   180,   183,    71,   445,   244,
     245,   284,   285,   224,   176,   226,   176,    66,    67,    68,
      69,    70,    71,   183,   461,   462,   176,   175,   176,   176,
     175,   176,    71,   183,   181,   270,   271,   272,    23,   175,
     176,   177,   178,   175,   176,   177,   178,   183,   176,   260,
     175,   176,   177,   178,   181,   183,   183,     4,   181,   496,
     183,   296,   273,   175,   176,   177,   178,   278,   176,   176,
       4,     5,   176,   181,   347,   348,   183,   288,   289,   183,
     291,   292,   293,   181,  1055,   183,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    34,    35,   292,   293,
     180,   322,   323,   324,   325,   326,    58,   328,   180,   330,
     404,    70,    71,    72,   308,   176,   176,   176,   182,   183,
     181,   181,   183,   183,   345,    19,    20,     4,     5,   350,
     176,   176,    84,    85,    86,   418,   419,   183,   183,    91,
     423,   424,   180,   176,    66,    67,    68,    69,    70,    71,
     183,   345,     4,     5,     4,     5,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   180,    62,    63,
       4,     5,    66,    67,    68,    69,    70,    71,    72,   473,
      69,    70,    71,    72,   405,   176,   176,   176,   180,   410,
     181,   181,   428,   183,   183,   404,   441,   404,   176,   444,
     421,   422,   176,   181,   176,   183,    45,   181,    57,   183,
     180,   183,   180,   434,   180,   436,   175,   176,   177,   178,
     180,    45,   180,    62,    63,   446,   447,    66,    67,    68,
      69,    70,    71,    72,   455,   456,   457,   458,    62,    63,
       4,     5,    66,    67,    68,    69,    70,    71,    72,   180,
     459,   180,   459,   180,   176,   476,    50,   758,   176,   181,
     761,   183,   176,   181,   473,   183,   473,   181,    62,    63,
      48,    49,    66,    67,    68,    69,    70,    71,    72,   180,
     176,   175,   176,   177,   178,   181,   175,   176,   177,   178,
     176,   176,    62,    63,     5,   181,    66,    67,    68,    69,
      70,    71,    72,   183,    66,    67,    68,    69,    70,    71,
     180,   594,   595,   180,   597,   598,    67,    68,    69,    70,
      71,    72,    62,    63,    71,    72,    66,    67,    68,    69,
      70,    71,    72,    81,    82,   176,   175,   176,   177,   178,
     181,     4,     5,    66,    67,    68,    69,    70,    71,    72,
     176,   175,   176,   177,   178,   181,    38,    39,   176,   180,
     581,   582,    13,   181,    15,   176,    17,   180,   176,   652,
     181,   579,   580,   181,   176,   176,   180,   824,   183,   181,
     181,   175,   176,   177,   178,   176,   176,     4,     5,    40,
     181,   181,    43,   614,   180,   180,   843,    48,   180,   620,
     621,    59,    60,   624,   649,   175,   176,   177,   178,   180,
     176,   181,   180,   183,   176,   181,   183,   638,   176,   181,
     180,   666,   667,   181,   175,   176,   177,   178,   175,   176,
     177,   178,   653,   654,   655,   175,   176,   177,   178,   180,
     176,   181,   176,   183,   665,   181,   691,   181,   180,   180,
     671,   672,   175,   176,   177,   178,   677,   678,   679,   180,
     176,   180,    13,   180,    15,   181,    17,   180,   689,   690,
      67,   692,    69,    70,    71,    72,   180,   176,   699,   176,
     180,   702,   181,   176,   181,   779,   180,   183,   181,    40,
     180,   712,    43,   180,   715,   716,   717,    48,   719,   720,
     176,   176,   180,   176,   176,   181,   181,   728,   181,   181,
     176,   176,   180,   180,   183,   181,   181,    62,    63,   802,
     803,    66,    67,    68,    69,    70,    71,    72,   180,   183,
     180,   180,   176,   754,   755,   756,   757,   181,   180,    62,
      63,   180,   180,    66,    67,    68,    69,    70,    71,    72,
     180,    62,    63,   180,   180,    66,    67,    68,    69,    70,
      71,    72,   783,    13,   176,    15,   176,    17,   176,   181,
     779,   181,   779,   181,   180,   180,   180,   180,   175,   176,
     177,   178,   180,   804,   805,   180,   180,   180,   809,   810,
      40,   180,   180,    43,   815,   816,   180,   180,    48,   180,
     180,   180,    15,   886,   887,    18,   180,   180,   180,   180,
     180,   180,   180,   180,    27,   809,   810,   180,    31,    32,
     180,   180,   180,    36,   180,   180,   180,   180,   180,    71,
     175,   176,   177,   178,   180,    48,    49,    50,   183,   180,
     180,   183,    42,   181,    57,    58,    59,    60,   181,   181,
     181,   872,   175,   176,   177,   178,   877,    72,   866,   867,
     183,   882,   180,   908,   175,   176,   177,   178,   180,    82,
     181,   180,   183,   183,   180,   183,   181,   181,    42,    45,
     180,   180,     9,   180,   905,   183,   180,   183,   183,   910,
     183,   183,   181,   181,   181,    42,   181,   183,   992,   993,
     921,   180,   183,   181,   181,   181,   180,   928,   183,   181,
     181,   181,   181,   181,   935,   180,   937,    62,    63,   181,
     941,    66,    67,    68,    69,    70,    71,    72,   181,    80,
      80,     5,   181,   181,    57,   181,   183,   958,   183,  1033,
     181,   181,   181,   180,   180,   183,   181,   180,    42,  1043,
     181,   181,  1046,    37,   975,    42,   180,    71,   181,   181,
      71,    71,    47,   181,   177,    57,  1060,   181,   180,   180,
      46,   180,   180,   994,   187,    71,   181,   181,    37,     4,
     459,   194,    47,   992,   993,   992,   993,    47,   201,   671,
     596,   428,   295,  1017,   872,  1087,   599,  1018,   791,  1039,
    1021,   425,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,  1036,  1037,    -1,    -1,    -1,
      -1,    -1,   235,    -1,  1033,    -1,  1033,    -1,    -1,    -1,
     175,   176,   177,   178,  1043,    -1,  1043,  1046,   183,  1046,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,
    1071,  1060,    -1,  1060,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,    62,    63,    -1,   278,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   292,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,   317,   318,   319,   320,   321,    -1,
      -1,    -1,    -1,    -1,   327,    -1,   329,    -1,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,    -1,    -1,   349,    -1,   351,   352,
     353,   354,   355,    -1,    -1,   358,    -1,   360,    -1,   362,
      -1,    -1,    -1,   366,   367,   368,   369,   370,   371,   372,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,   407,   175,   176,   177,   178,    -1,
      -1,   181,    -1,   183,    -1,    -1,   175,   176,   177,   178,
      -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
     433,    -1,    62,    63,    64,    65,    -1,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,   455,   456,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
      -1,   161,   162,    -1,   164,   165,   166,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
     180,    62,    63,    -1,   184,    66,    67,    68,    69,    70,
      71,    72,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    30,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   617,    -1,    -1,   620,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,   175,   176,   177,   178,   671,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,   682,
     683,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,   175,
     176,   177,   178,   145,   146,   147,    -1,     5,   150,    -1,
     152,     9,   154,    -1,    -1,   157,    -1,   159,    -1,   722,
     162,    -1,    -1,   165,   166,    -1,   168,   169,    -1,   171,
      -1,   173,    30,    -1,    -1,    -1,   739,   740,   180,   181,
     175,   176,   177,   178,   747,    -1,    -1,    -1,   183,    -1,
      -1,   175,   176,   177,   178,    -1,    -1,   760,    -1,   183,
     763,   764,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   786,    -1,   788,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   811,   812,
     813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,   822,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,
      -1,   159,    -1,    -1,   162,    -1,    -1,   165,   166,   872,
     168,   169,    -1,   171,    -1,   173,   175,   176,   177,   178,
      -1,    -1,   180,   181,   183,    -1,    -1,    -1,    -1,    -1,
     893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,    62,    63,    -1,   917,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    62,    63,    -1,   932,
      66,    67,    68,    69,    70,    71,    72,   940,    -1,    -1,
      -1,   944,    -1,    -1,   947,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   969,   970,   971,   972,
     973,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,    -1,
     181,    -1,  1035,    62,    63,    64,    65,  1040,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    76,    -1,    -1,
      79,    -1,    62,    63,    -1,    84,    66,    67,    68,    69,
      70,    71,    72,    92,    -1,    -1,  1069,    96,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,    -1,   161,   162,    -1,   164,   165,   166,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,     3,     4,
       5,   180,     7,     8,     9,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,   183,    29,    30,    -1,    -1,    -1,    -1,
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
      -1,   156,   157,   158,   159,    -1,   161,   162,    -1,   164,
     165,   166,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,     3,     4,     5,   180,     7,     8,     9,   184,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,
      -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    29,    30,
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
     151,   152,   153,   154,    -1,   156,   157,   158,   159,    -1,
     161,   162,    -1,   164,   165,   166,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,     3,     4,     5,   180,
       7,     8,     9,   184,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,
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
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,   181,     3,     4,     5,    -1,     7,
       8,     9,    -1,   175,   176,   177,   178,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,    -1,   161,   162,    -1,   164,   165,   166,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,   181,     3,     4,     5,    -1,     7,     8,
       9,    -1,   175,   176,   177,   178,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      79,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,    -1,   161,   162,    -1,   164,   165,   166,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,   181,     3,     4,     5,    -1,     7,     8,     9,
      -1,    11,    -1,    -1,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   161,   162,    -1,   164,   165,   166,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,     3,     4,     5,
     180,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,
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
     156,   157,   158,   159,    -1,   161,   162,    -1,   164,   165,
     166,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,     3,     4,     5,   180,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    29,    30,    -1,
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
     152,   153,   154,    -1,   156,   157,   158,   159,    -1,   161,
     162,    -1,   164,   165,   166,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,     3,     4,     5,   180,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,    -1,
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
     158,   159,    -1,   161,   162,     5,   164,   165,   166,     9,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,   175,   176,   177,   178,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    30,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    62,    -1,     9,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,    30,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,
     150,   100,   152,   102,   154,    -1,    -1,   157,    -1,   159,
      -1,    -1,   162,     5,    -1,   165,   166,     9,   168,   169,
      -1,   171,    -1,   173,    -1,    -1,    -1,   126,   127,   128,
     180,   181,    -1,   132,   133,   134,    -1,   136,    30,   138,
     139,   140,   175,   176,   177,   178,   145,   146,   147,    92,
     183,   150,    -1,   152,    -1,   154,    -1,   100,   157,   102,
     159,    -1,    -1,   162,    -1,    -1,   165,   166,    -1,   168,
     169,    -1,   171,    -1,   173,    -1,    -1,   175,   176,   177,
     178,   180,   181,   126,   127,   128,    -1,    -1,     5,   132,
     133,   134,     9,   136,    -1,   138,   139,   140,    -1,    -1,
      92,    -1,   145,   146,   147,    -1,    -1,   150,   100,   152,
     102,   154,    -1,    30,   157,    -1,   159,    -1,    -1,   162,
      -1,    -1,   165,   166,    -1,   168,   169,    -1,   171,    -1,
     173,    -1,    -1,    -1,   126,   127,   128,   180,    -1,     5,
     132,   133,   134,     9,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    30,   157,    -1,   159,    -1,    -1,
     162,    -1,    -1,   165,   166,    -1,   168,   169,    -1,   171,
      -1,   173,    -1,   100,    -1,   102,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,    -1,   150,   100,   152,   102,   154,    -1,    -1,
     157,    -1,   159,    -1,    -1,   162,    -1,    -1,   165,   166,
      -1,   168,   169,    -1,   171,    -1,   173,    -1,    -1,    -1,
     126,   127,   128,   180,    -1,    -1,   132,   133,   134,    -1,
     136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,    -1,   150,    -1,   152,    -1,   154,    -1,
      -1,   157,    -1,   159,    -1,    -1,   162,    -1,    -1,   165,
     166,    -1,   168,   169,    -1,   171,    -1,   173,    -1,     4,
       5,     6,    -1,    -1,   180,    10,    -1,    -1,    -1,    14,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,   101,    -1,   103,   104,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,     4,     5,     6,    -1,   160,    -1,    10,   163,    -1,
      -1,    14,   167,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,   175,   176,   177,   178,    -1,    -1,   181,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,    -1,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,     4,     5,     6,    -1,   160,    -1,    10,
     163,    -1,    -1,    14,   167,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    -1,    62,    63,    60,
      61,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    -1,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,   103,   104,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    62,
      63,    -1,   133,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
      -1,    -1,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    62,    63,    -1,   183,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
     178,    -1,    62,    63,    -1,   183,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    -1,    62,    63,    -1,
     183,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,    -1,
     175,   176,   177,   178,    -1,    62,    63,    -1,   183,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    -1,
      62,    63,    -1,   183,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,
      -1,   175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    62,    63,   181,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    62,    63,   181,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,   177,   178,    62,    63,   181,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    62,
      63,   181,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    62,    63,   181,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    62,    63,   181,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    62,    63,   181,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    62,
      63,   181,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    62,    63,   181,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    62,    63,   181,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    62,    63,   181,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,    62,
      63,   181,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
     178,    62,    63,   181,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,    62,    63,   181,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    62,    63,   181,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,    62,    63,
     181,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
     178,    62,    63,   181,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    62,    63,   181,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    62,    63,   181,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,    62,    63,
     181,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,
     178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,    -1,    -1,   181
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
     103,   104,   126,   127,   128,   133,   151,   155,   160,   163,
     167,   186,   187,   189,   196,   197,   199,   200,   204,   216,
     217,   222,   228,   235,   243,   251,   254,   258,   261,   267,
      71,   180,    71,   180,   236,   255,   259,     4,     7,   214,
     214,   214,     3,     4,     5,     7,     8,     9,    29,    30,
      33,    62,    63,    64,    65,    76,    79,    96,    97,   100,
     102,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   161,   162,   164,   165,   166,   168,
     169,   170,   171,   172,   173,   174,   175,   180,   202,   203,
     205,   211,   213,   216,   217,   190,   191,   180,   202,   180,
     180,   202,    27,     7,   244,   252,   205,    57,    59,    60,
     184,   290,   194,   202,   205,     4,     5,   215,   205,   202,
     205,   202,   205,     4,     5,   278,   279,     9,   175,   176,
     212,   213,   280,   214,    84,    92,   184,   202,   205,   291,
      84,    92,   105,   291,   291,    83,   205,   210,    11,    52,
     210,   210,    58,    84,    85,    86,    91,    90,   205,   197,
     204,   216,   217,   202,   202,   202,   105,   180,   180,   180,
     180,   180,   202,   291,   202,   202,   202,     0,    43,   188,
      87,    88,    99,    71,    71,    23,   205,   218,   219,   202,
     218,     4,   205,   187,   180,   180,    34,    35,   180,   180,
     205,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   205,   202,   205,    66,    67,    68,    69,
      70,    71,   176,    19,    20,    62,    63,    66,    67,    68,
      69,    70,    71,    72,   175,   176,   177,   178,     4,     5,
     229,   230,     4,     5,   231,   232,   202,   218,   218,   202,
     205,   246,   187,   262,   268,   180,    57,   180,     4,     7,
     180,   202,   205,   281,    57,   184,   283,   288,   180,   180,
     183,   183,   183,   180,   180,   183,   213,   213,   183,   205,
     202,   205,    10,   183,   183,   202,   183,   210,   195,    11,
     183,   198,   183,   210,    11,   210,   198,   198,     5,   201,
     201,   201,   181,   205,   202,   183,   183,   183,   183,    42,
     210,   210,   210,   205,   202,   223,   181,   202,   205,   220,
     221,   181,    71,   256,    13,    15,    17,    40,    43,    48,
     260,   218,   218,   205,   205,   205,    92,   202,   291,   291,
       4,     5,   208,   209,   208,   209,   210,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   291,   205,
     205,   205,   205,   205,   205,   205,   181,   205,   202,   202,
     202,   202,   202,   205,   205,   205,   181,   205,   205,   202,
     205,   202,   205,   202,   202,   181,   202,   181,   202,   181,
     202,   181,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   291,   202,   218,   218,   202,   205,   202,   202,
     202,   202,   202,   181,   181,   202,   201,   202,   201,   202,
     181,   181,   202,   202,   202,   202,   202,   202,   202,   192,
     193,   207,   206,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   180,   180,   183,   180,   180,   183,
     181,   181,    42,   245,    13,    15,    17,    40,    43,    48,
     253,    45,   187,   205,   180,   202,   205,    50,   282,   182,
     183,   180,     4,     7,   180,     9,   289,   218,   218,     4,
       5,   205,   205,   218,   218,   279,     9,   212,   183,    81,
      82,    92,   202,   205,   205,   283,   210,   202,   210,   198,
     205,   205,   180,   183,   183,   183,   181,   181,   202,   205,
     202,   205,   205,   205,   189,   183,   198,   198,     4,     5,
     227,   183,   237,   187,   205,   181,   181,   183,   183,   183,
     181,   181,   183,   183,   181,   180,   180,   181,   181,   183,
     183,   198,   183,   181,   181,   181,   181,   181,   181,   183,
     181,   181,   183,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   183,   181,   181,   183,   183,   183,   181,   183,
     183,   181,   183,   181,   181,   181,   181,   181,   183,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   183,
     183,   181,   181,   181,   181,   181,   181,   183,   181,   181,
     181,   181,   181,   181,   183,   183,   183,   183,   183,   181,
     183,   183,   181,   183,   183,   214,   292,   214,   293,   205,
     205,   218,   218,   230,   218,   218,   232,    42,   247,   263,
      48,    49,   269,   183,   205,   181,   183,   181,   180,   202,
     202,   205,   205,   284,   285,   205,     4,     5,   275,   277,
     181,   181,   180,   180,   183,   183,   181,   181,   205,    80,
      80,   183,   183,   183,   210,   183,   183,   218,   205,   205,
     205,   183,   183,   205,   210,   210,   224,   221,   205,    15,
      43,   257,   205,   205,   205,   202,    92,   202,   181,   181,
     205,   205,   210,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   202,   205,   202,   202,   202,   205,   205,   205,
     205,   209,   202,   209,   202,   202,   183,   183,   181,   181,
     181,   181,    38,    39,   249,   187,   205,   183,    57,   202,
     202,   282,   183,   275,   275,   181,   180,   180,   183,   218,
     218,   205,   205,   183,   291,   291,   202,   202,   202,   205,
     205,   181,   181,   181,   181,   183,   202,   202,   198,   180,
      11,   181,   181,   181,   181,   181,   181,   183,   181,   181,
     181,   198,   181,   181,   181,   181,   181,   181,   183,   181,
     181,   181,   183,   181,   181,   183,   181,   183,   181,   181,
     183,   183,   181,   181,   183,   181,   181,   183,   181,   181,
     214,   214,   246,    42,    37,   264,   181,   205,   180,   181,
     183,   205,   286,   218,   218,   276,   181,   181,   202,   183,
     183,    71,    71,    71,   205,   183,   210,     4,     5,   233,
     234,   205,   202,   205,   205,   202,   205,   205,   202,   205,
     202,   202,   248,   250,    47,   271,    59,    60,   181,   205,
      57,   202,   181,   275,   181,   181,   275,   202,   202,   202,
     202,   202,   181,   205,   180,   180,   181,   183,    12,   241,
     181,   183,   181,   181,   181,   181,   181,   181,   181,   181,
     187,   187,   205,    46,   270,   180,   183,   180,   181,   287,
      71,   181,   181,   225,   234,   205,   238,   205,    45,   274,
     187,   265,   202,   205,   205,   289,   202,   187,   187,   181,
     272,    13,    15,    17,    40,    43,    48,   266,   181,   183,
     181,   183,   275,    24,    43,   226,   239,   187,   202,   205,
      13,    15,    17,    40,    43,    48,   240,   273,   181,   181,
       4,   242,   271
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   185,   186,   187,   188,   187,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   190,   189,   191,   189,   189,   189,
     189,   189,   189,   189,   192,   189,   193,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   194,   189,
     195,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   196,   196,   196,   196,   196,   197,   197,   197,   197,
     197,   197,   198,   198,   199,   199,   199,   199,   199,   200,
     200,   201,   201,   202,   202,   202,   202,   202,   202,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   204,   204,
     206,   205,   207,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   208,   209,   210,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   212,   212,   212,   213,   213,   213,   214,
     214,   215,   215,   215,   215,   216,   217,   219,   218,   220,
     220,   220,   221,   221,   223,   224,   225,   222,   226,   226,
     227,   227,   228,   228,   228,   228,   229,   229,   230,   230,
     230,   230,   231,   231,   232,   232,   232,   232,   233,   233,
     233,   234,   234,   234,   234,   236,   237,   238,   239,   235,
     240,   240,   240,   240,   240,   240,   241,   241,   242,   242,
     244,   243,   245,   245,   246,   246,   247,   248,   247,   249,
     250,   249,   252,   251,   253,   253,   253,   253,   253,   253,
     255,   256,   254,   257,   257,   259,   258,   260,   260,   260,
     260,   260,   260,   262,   263,   264,   265,   261,   266,   266,
     266,   266,   266,   266,   268,   267,   269,   269,   270,   270,
     271,   272,   273,   271,   274,   274,   275,   276,   275,   277,
     277,   277,   277,   278,   278,   279,   279,   279,   279,   280,
     280,   280,   280,   281,   281,   281,   281,   281,   282,   282,
     282,   284,   283,   285,   283,   286,   283,   287,   283,   288,
     283,   289,   289,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   291,   291,   292,
     292,   293,   293
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
       4,     4,     4,     4,     4,     6,     4,     3,     6,     6,
       4,     4,     4,     4,     6,     6,     8,     6,     8,     4,
       4,     4,     8,     4,     4,     4,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     6,     6,
       6,     4,     8,     6,     8,     6,     4,     4,     4,     6,
       6,     6,     8,     1,     2,     2,     1,     1,     1,     1,
       1,     4,     6,     4,     6,     4,     4,     0,     2,     0,
       1,     3,     1,     1,     0,     0,     0,    11,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     3,     1,     1,
       4,     4,     1,     3,     1,     1,     4,     4,     0,     1,
       3,     1,     1,     3,     3,     0,     0,     0,     0,    14,
       1,     1,     1,     1,     1,     1,     0,     2,     0,     1,
       0,     7,     1,     2,     1,     1,     0,     0,     5,     0,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     1,     1,     0,     4,     1,     2,     1,
       1,     1,     1,     0,     0,     0,     0,    11,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     1,     0,     2,
       0,     0,     0,     7,     0,     1,     1,     0,     4,     1,
       4,     1,     4,     1,     3,     1,     4,     1,     4,     1,
       1,     3,     3,     0,     2,     4,     1,     3,     0,     2,
       6,     0,     4,     0,     4,     0,     6,     0,     9,     0,
       3,     0,     1,     0,     2,     2,     4,     1,     4,     6,
       6,     7,    10,    12,     7,    10,    12,     2,     1,     1,
       3,     1,     3
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

    {create_function(fCEIL);}

    break;

  case 231:

    {create_function(fFLOOR);}

    break;

  case 232:

    {create_function(fFRAC);}

    break;

  case 233:

    {create_function(fABS);}

    break;

  case 234:

    {create_function(fSIG);}

    break;

  case 235:

    {create_function(fMOD);}

    break;

  case 236:

    {create_function(fRAN);}

    break;

  case 237:

    {create_function(fRAN2);}

    break;

  case 238:

    {create_function(fMIN);}

    break;

  case 239:

    {create_function(fMAX);}

    break;

  case 240:

    {create_function(fLEN);}

    break;

  case 241:

    {create_function(fVAL);}

    break;

  case 242:

    {create_function(fASC);}

    break;

  case 243:

    {create_function(fDEC);}

    break;

  case 244:

    {create_function(fDEC2);}

    break;

  case 245:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 246:

    {create_function(fINSTR2);}

    break;

  case 247:

    {create_function(fRINSTR);}

    break;

  case 248:

    {create_function(fRINSTR2);}

    break;

  case 249:

    {create_function(fSYSTEM);}

    break;

  case 250:

    {create_function(fFRNFN_CALL);}

    break;

  case 251:

    {create_function(fFRNFN_SIZE);}

    break;

  case 252:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 253:

    {create_function(fFRNBF_SIZE);}

    break;

  case 254:

    {create_function(fPEEK4);}

    break;

  case 255:

    {create_function(fPEEK);}

    break;

  case 256:

    {create_function(fMOUSEX);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 258:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 259:

    {create_function(fMOUSEY);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 261:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 262:

    {create_function(fMOUSEB);}

    break;

  case 263:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 264:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 265:

    {create_function(fMOUSEMOD);}

    break;

  case 266:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 267:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 268:

    {create_function(fAND);}

    break;

  case 269:

    {create_function(fOR);}

    break;

  case 270:

    {create_function(fEOR);}

    break;

  case 271:

    {create_function(fTELL);}

    break;

  case 272:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 273:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 274:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 275:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 276:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 277:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 278:

    {create_myopen(0);}

    break;

  case 279:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 280:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 281:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 282:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 283:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 284:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 285:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 286:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 287:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 288:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 289:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 290:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 291:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 292:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 293:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 294:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 295:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 296:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 297:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 304:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 305:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 306:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 307:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 308:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 309:

    {missing_endsub--;}

    break;

  case 310:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 311:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 312:

    {exported=FALSE;}

    break;

  case 313:

    {exported=TRUE;}

    break;

  case 314:

    {exported=FALSE;}

    break;

  case 315:

    {exported=TRUE;}

    break;

  case 318:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 319:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 320:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 321:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 324:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 325:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 326:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 327:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 331:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 332:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 333:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 334:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 335:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 336:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 337:

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

  case 338:

    {
             swap();popgoto();poplabel();}

    break;

  case 339:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 340:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 341:

    {missing_next--;}

    break;

  case 342:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 343:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 344:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 345:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 346:

    {create_pushdbl(1);}

    break;

  case 348:

    {pop(stSTRING);}

    break;

  case 349:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 350:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 351:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 357:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 358:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 360:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 362:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 364:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 365:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 366:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 367:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 368:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 369:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 370:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 371:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 373:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 374:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 375:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 377:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 378:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 379:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 380:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 381:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 382:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 383:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 384:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 385:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 386:

    {poplabel();}

    break;

  case 388:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 389:

    {missing_endif--;}

    break;

  case 390:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 391:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 392:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 393:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 394:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 396:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 397:

    {poplabel();}

    break;

  case 401:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 402:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 407:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 409:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 410:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 411:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 412:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 415:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 416:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 417:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 418:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 419:

    {create_strdata((yyvsp[0].string));}

    break;

  case 420:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 421:

    {create_strdata((yyvsp[0].string));}

    break;

  case 422:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 426:

    {create_print('s');}

    break;

  case 427:

    {create_print('s');}

    break;

  case 428:

    {create_print('d');}

    break;

  case 429:

    {create_print('u');}

    break;

  case 430:

    {create_print('U');}

    break;

  case 431:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 432:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 433:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 434:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 435:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 436:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 437:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 438:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 439:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 440:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 441:

    {create_pushstr("?");create_print('s');}

    break;

  case 442:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 443:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 454:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 455:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 459:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 460:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 461:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 462:

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
