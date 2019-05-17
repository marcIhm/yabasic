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
#define YYFINAL  263
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5434

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  182
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  458
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1081

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
     489,   490,   491,   492,   493,   494,   495,   496,   497,   500,
     501,   502,   505,   506,   507,   510,   511,   514,   515,   516,
     517,   520,   523,   526,   526,   529,   530,   531,   534,   535,
     538,   539,   542,   538,   547,   548,   551,   552,   555,   556,
     557,   558,   561,   562,   565,   566,   567,   568,   571,   572,
     575,   576,   577,   578,   581,   582,   583,   586,   587,   588,
     589,   592,   593,   597,   611,   592,   616,   617,   618,   619,
     620,   621,   624,   625,   628,   629,   634,   634,   638,   639,
     642,   643,   647,   649,   648,   653,   654,   654,   658,   658,
     664,   665,   666,   667,   668,   669,   673,   674,   673,   680,
     681,   685,   685,   690,   691,   692,   693,   694,   695,   698,
     699,   699,   701,   698,   705,   706,   707,   708,   709,   710,
     713,   713,   718,   719,   722,   723,   726,   728,   730,   727,
     734,   735,   738,   739,   739,   742,   743,   745,   746,   750,
     751,   754,   755,   757,   758,   762,   763,   764,   765,   768,
     769,   770,   771,   772,   775,   776,   777,   780,   780,   781,
     781,   782,   782,   783,   783,   784,   784,   787,   788,   791,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   803,   804,   807,   808,   810,   811,   814,   815
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

#define YYPACT_NINF -775

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-775)))

#define YYTABLE_NINF -380

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3888,    -2,     5,  -775,  -775,  -775,  -775,  -775,   167,   167,
     167,  2771,  -775,  -775,  -775,   347,  -166,  -139,   347,    43,
      37,  -775,  -775,  -775,  3113,    18,  -775,  3113,   256,  -775,
    3113,  3113,  3113,   447,    32,   167,  1468,  1140,  1901,   -24,
    3113,  2600,  3113,    22,    -9,  3113,  -775,    38,   347,   347,
     347,    19,   -37,   -29,   -17,    15,    21,  1901,   347,   347,
     178,   145,  -775,    40,  -775,  -775,  -775,  -775,   130,   149,
    -775,   211,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  3113,
    -775,   347,  -775,   241,  3113,  3735,  -775,  -775,  -775,  -775,
    -775,  -775,    80,    95,  -775,  -775,  -775,    98,   104,   432,
     128,   146,  3113,   174,   182,   201,   223,   239,   249,   263,
     265,   286,   301,   305,   333,   352,   364,   373,   387,   399,
     401,   405,   423,   446,   474,   480,   488,   491,   508,   511,
     515,   518,   534,   552,   580,   583,   593,   603,   604,   607,
     608,   613,   614,   615,   618,   619,   620,   623,   624,   627,
     628,   629,   631,   634,   637,   638,   639,   640,   641,   649,
     656,   657,   669,   674,   687,   688,   689,   695,   698,   706,
     707,   711,   713,  3113,  3113,   185,  -775,   365,  -775,  -775,
    -775,  -775,   484,   514,   347,   233,  -775,  -775,   233,  -775,
    -775,  3113,  3735,   271,   714,   361,   715,    25,  3113,   -45,
     185,   650,   716,   718,   340,   650,   185,   851,   185,  1256,
     720,   724,   410,  -775,  -775,   102,   102,  -775,  -775,   563,
    -775,  3113,   347,  3113,    27,   650,   647,  -775,  -775,  -775,
    -775,   667,   347,  1267,  -775,  3113,  -775,    11,   693,  -775,
    -775,  3113,  2942,  -775,  -775,   650,  -775,  -775,   130,   149,
     233,    -1,    -1,  -775,   591,   591,   591,  2072,   347,    33,
     702,  -101,   -91,  -775,  -775,   602,  3113,  3113,  3113,  3113,
     347,  -775,   650,   528,  3113,   233,   709,   827,   650,   564,
    -775,  -775,  -775,  -775,  3113,  3113,   917,  3113,  1730,  1901,
     594,   594,  3113,  3113,  3113,  3113,  3113,  3113,  3113,  3113,
    3113,  3113,  3113,  3113,  1901,  3113,  3113,  3113,  3113,  3113,
    3113,  3113,  2248,   347,   347,   347,   347,   347,  3113,  3113,
    3113,  2424,  3113,   347,  3113,   347,  3113,   347,   347,  3186,
    3286,  3339,  3397,   347,   347,   347,   347,   347,   347,   347,
     347,  1901,   347,  -775,  -775,   347,  3113,   347,   347,   347,
     726,   727,   347,   591,   347,   591,   347,   830,   354,   503,
     347,   347,   347,   347,   347,   347,   347,  -775,  -775,  -775,
    -775,  3113,  3113,  3113,  3113,  3113,  3113,  3113,  3113,  3113,
    3113,  3113,   729,   730,   728,  -775,   732,   734,   735,  -775,
     158,   746,   747,   185,   650,   884,   570,   882,  3735,  3113,
     752,   347,  -775,  -775,  3113,   185,    -5,   429,   753,    26,
    -775,   919,  -775,  -775,   611,  3113,  3113,  -775,  -775,   447,
    -775,  -775,    46,  1278,   233,   650,   566,  3453,  3113,   233,
    3113,  -775,   -45,  -775,  -775,  3113,   347,  -775,  3113,    11,
    3113,  3113,   754,   755,   756,   757,  -775,  4175,   317,  3113,
    3113,   347,   347,  3735,   758,    11,    11,   650,   233,   710,
    -775,   185,   650,   759,  -775,  -775,  -775,  3735,  -775,  -775,
    3113,  -775,  -775,  -775,  -775,   768,   770,  1289,  1306,  1319,
     772,    86,   773,   774,   779,   780,   781,   782,   778,   783,
      11,  1332,  4199,  4224,  4235,  4289,  4313,   558,  4349,   682,
    4360,  4371,   786,  4382,  4403,  4427,  4438,  4496,  4517,  1354,
    -775,  4552,   318,   -22,     4,    17,   325,  1487,  1609,   696,
    -775,  4563,  4574,   327,  4585,   -88,  4610,   329,   336,  -775,
     343,  -775,   355,  -775,   357,  -775,   358,   375,   376,   413,
     152,   177,   415,   416,   419,   476,   787,    16,   788,   804,
     433,  4631,   206,   214,   230,  -775,  -775,   268,   -19,   277,
      29,   280,  -775,  -775,   233,   233,   233,   233,   233,   233,
    -775,   167,   167,  3113,  3113,   705,   199,   670,   172,   154,
     240,  -775,   -25,   -25,   830,   830,  -775,  -775,   484,  -775,
    -775,   514,  -775,  -775,  -775,   891,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   675,  1639,  3113,   141,  4642,  3567,
    -775,  -775,  3113,  3113,  -775,  -775,  3113,  -775,   721,   812,
     813,   784,   817,  1916,  2087,   818,   819,  -775,  -775,  -775,
    3113,   854,   918,  -775,   282,  2263,   650,  -775,  -775,   291,
    -775,  3113,  2442,  2615,  -775,  3113,  3113,  3113,  -775,  -775,
     185,   650,   185,   650,   233,   292,  -775,  3113,  3113,  3113,
    -775,  -775,  -775,  3113,  3113,    13,   650,  -775,  -775,  3113,
    3113,  3113,  -775,  -775,   347,  3509,  -775,   821,   822,  -775,
    -775,  3113,  3113,  3113,  3113,  -775,  -775,  -775,  -775,  -775,
    -775,  3113,  -775,  -775,  3113,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  3113,  -775,  -775,  3113,  3113,  3113,
    -775,  3113,  3113,  -775,   347,  -775,  -775,  -775,  -775,  -775,
    3113,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,   347,   347,  -775,  -775,  -775,  -775,  -775,  -775,   347,
    -775,  -775,  -775,  -775,   347,  3113,  3113,   996,  -775,   347,
     996,  -775,   347,   347,  -775,   824,  -775,   825,   917,   905,
     828,   829,  -775,   831,   834,  -775,  -775,   708,  3735,  -775,
    -775,  -775,  3113,  2786,   945,   347,  -775,   347,   233,   185,
      -5,  2957,   721,   721,  4699,   836,   837,  -775,   838,  -775,
    -775,  -775,  -775,  3113,  3113,  -775,  -775,  3131,  1901,  1901,
     347,   347,   347,  -775,  3113,  3113,   839,  4724,  4756,   769,
    3113,   650,    11,  -775,   843,  -775,    63,  -775,  -775,  -775,
    4767,  4778,  4789,   444,   844,   144,  -775,  -775,  4813,  4838,
     849,    49,  4849,  4903,  4927,  4963,  4974,  1001,  4985,  4996,
     202,  5017,   203,   217,   460,   464,  3778,  3931,    52,   467,
      53,   477,   494,   167,   167,  -775,  -775,  -775,  -775,  3113,
     966,   979,   986,  5041,  3113,   857,   506,   218,  -775,  3113,
    -775,  -775,  -775,  -775,  -775,  -775,   858,   859,   650,   650,
     347,  -775,  -775,   233,   233,   296,  4084,   650,  -775,   967,
     968,   969,  3113,  4109,  3113,   751,  3113,  -775,  -775,  -775,
    -775,  -775,  -775,   347,  -775,  -775,  -775,  3113,  -775,  -775,
    -775,  -775,  -775,  -775,  3113,  -775,  -775,  -775,   347,  -775,
    -775,  3113,  -775,  3113,  -775,  -775,   347,  3113,  -775,   347,
    -775,  -775,   347,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
     995,   719,  5052,  3113,   987,   347,  5110,   721,   865,   868,
     721,  -775,  -775,   233,   347,   347,   347,   347,   347,  5131,
     347,  -775,   870,   873,   126,  -775,    75,   509,  4142,  5166,
     513,  5177,  5188,   516,  5199,   526,   529,  3735,  4041,  3113,
    1006,  -775,   876,  -775,  4153,   877,   530,  -775,  -775,  -775,
    -775,  -775,   233,   233,   233,   233,   233,   984,   304,   878,
     879,  -775,   751,  3113,  -775,  -775,  3113,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   986,  1021,   489,  3735,  -775,
     347,  3113,  3113,  -775,   919,   347,  3113,  -775,  -775,  3735,
    -775,   650,  3735,  5224,  -775,  -775,   986,   626,   229,  5245,
    4164,   721,   233,   185,   650,    -7,   986,  -775,  3735,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,   347,  -775,  3113,
    -775,  -775,  -775,  -775,   846,   986,   532,  5256,  -775,  -775,
    -775,  -775,  -775,  -775,  1056,   995,  -775,  -775,  -775,  -775,
    -775
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     110,     0,     0,   105,   331,   366,   371,    11,     0,     0,
       0,     0,    24,    26,   309,     0,     0,     0,     0,   310,
      18,    20,   346,   358,     0,   439,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     4,     3,     0,     7,    39,    41,     9,    22,    23,
      21,     0,    13,    14,    17,    16,    15,    28,    29,     0,
     293,     0,   293,     0,     0,     6,   286,   285,    30,    31,
      38,   282,   196,   132,   283,   284,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,   253,   256,   259,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,   209,   190,
     195,   134,     0,     0,     0,    12,   293,   293,    42,   311,
      19,     0,     6,   390,     0,   443,     0,     0,   419,   435,
      62,    61,     0,     0,    63,   104,    53,     0,    55,     0,
     411,   413,    56,   409,   415,     0,     0,   416,   279,    57,
      59,     0,    89,     0,     0,   454,     0,    86,    91,    79,
      40,     0,     0,     0,    67,     0,    50,    72,     0,    88,
      87,     0,     0,   113,   114,    92,     8,    10,     0,     0,
     106,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,   300,   175,     0,   295,   115,     0,     0,   367,     4,
     293,   293,    32,    33,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    36,   179,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,   315,    25,   312,   320,   321,    27,   318,
       0,     0,     0,   351,   350,     0,     4,     0,     6,     0,
       0,     0,   440,   441,     0,   422,   424,    45,     0,     0,
      49,   437,   293,   293,     0,     0,     0,   293,   293,     0,
     281,   280,     0,     0,    90,   453,     0,     0,     0,    66,
       0,    71,   435,   122,   121,     0,     0,    68,     0,    74,
       0,     0,   130,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,   176,   120,     0,
     291,   298,   299,   294,   296,   292,   332,     6,   378,   376,
       0,   377,   373,   375,   372,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,   257,     0,   260,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,   162,     0,     0,     0,
       0,     0,   137,   210,   204,   206,   208,   205,   207,   203,
     136,     0,     0,     0,     0,   183,   185,   187,   184,   186,
     182,   201,   198,   197,   199,   200,   293,   293,     0,   293,
     293,     0,    43,    44,   348,   352,   365,   363,   364,   361,
     360,   362,   359,   380,     4,     0,     0,     0,     0,     0,
     420,    46,    47,     0,   427,   429,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,   417,   418,
       0,     0,     0,   125,   124,   128,   213,    51,    69,    82,
      73,     0,     0,     0,   293,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   107,     0,     5,     0,     0,     0,
     306,   307,   301,     0,     0,     4,   374,   272,   173,     0,
       0,     0,   273,   274,     0,     0,   267,     0,     0,   191,
     192,     0,     0,     0,     0,   214,   215,   216,   217,   218,
     219,     0,   221,   222,     0,   224,   225,   188,   230,   231,
     226,   227,   228,   229,     0,   233,   238,     0,     0,     0,
     237,     0,     0,   142,     0,   147,   148,   239,   171,   240,
       0,   172,   149,   150,   252,   255,   258,   261,   153,   151,
     152,     0,     0,   154,   246,   155,   251,   250,   163,     0,
     247,   156,   248,   157,     0,     0,     0,     0,   166,     0,
       0,   168,     0,     0,   455,    35,   457,    37,   180,   178,
       0,     0,   313,     0,     0,   319,   349,   355,     6,   392,
     393,   391,     0,     0,   444,     0,   442,     0,   425,   423,
     424,     0,     0,     0,     0,   405,   407,   436,   402,   287,
     289,   293,   293,     0,     0,   412,   414,    64,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    85,     0,   297,     0,   370,   369,   368,
       0,     0,     0,     0,     0,     0,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   316,   317,   322,   323,     0,
       0,     0,   381,     0,     0,     0,     0,     0,   421,     0,
     428,   430,   431,   293,   293,   403,     0,     0,    52,    54,
       0,   126,   127,   123,   129,    83,    76,    77,   131,     0,
       0,     0,     0,     0,     0,   324,     0,   264,   265,   266,
     275,   276,   277,     0,   193,   194,   169,     0,   220,   223,
     232,   138,   139,   141,     0,   235,   236,   143,     0,   241,
     242,     0,   244,     0,   164,   158,     0,     0,   269,     0,
     165,   271,     0,   167,   189,   456,   458,   353,   356,   347,
     396,   446,     0,     0,   445,     0,     0,     0,     0,     0,
       0,   288,   290,    65,     0,     0,     0,     0,     0,     0,
       0,    81,   327,   328,     0,   325,   342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,   110,     0,
     394,   450,     0,   447,     0,     0,     0,   433,   432,   406,
     408,   404,    84,    75,   118,   119,   117,     0,     0,     0,
       0,   302,     0,     0,   333,   278,     0,   140,   144,   243,
     245,   249,   174,   268,   270,   354,     4,   400,     6,   382,
       0,     0,     0,   426,   437,     0,     0,   329,   330,     6,
     326,   343,     6,     0,   401,   397,   395,     0,     0,     0,
       0,     0,   116,   109,   108,     4,   334,   170,     6,   389,
     386,   387,   388,   384,   385,   383,   451,     0,   448,     0,
     434,   305,   304,   303,     0,   398,     0,     0,   337,   339,
     340,   341,   336,   338,   344,   396,   452,   449,   345,   335,
     399
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -775,  -775,   -78,  -775,   609,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  1014,  -228,  -775,  -775,  -172,   771,  -775,  1018,
     -11,  -775,  -775,   775,  -289,   -27,  -775,   652,   -30,    -4,
    -775,     1,     3,   -64,  -775,  -775,   412,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   493,  -775,   485,  -775,    81,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,   234,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,     7,  -775,  -775,  -775,
    -774,  -775,  -775,  -775,   676,  -775,  -775,   334,   665,  -775,
    -775,  -775,  -775,  -775,    91,  -775,    14,  -775,  -775
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    60,    61,   265,    62,   182,   183,   571,   572,   199,
     432,    63,    64,   435,    65,    66,   443,   175,   176,    67,
     233,   574,   573,   486,   487,   234,   178,   217,   179,    88,
     204,   180,   181,   273,   274,   463,   464,    70,   459,   814,
    1029,  1063,   662,    71,   384,   385,   388,   389,   964,   965,
      72,    83,   664,  1032,  1064,  1074,  1004,  1079,    73,   191,
     595,   395,   767,   977,   861,   978,    74,   192,   602,    75,
      84,   467,   819,    76,    85,   474,    77,   397,   768,   940,
    1037,  1055,    78,   398,   771,  1019,   980,  1048,  1075,  1035,
     787,   950,   788,   212,   213,   219,   407,   610,   410,   782,
     783,   947,  1024,   411,   618,   198,   226,   755,   757
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     177,    68,   489,    69,   218,    89,    90,   279,   870,   871,
     433,   186,   408,   193,   237,   238,   201,  1061,   276,   205,
     207,   209,   433,   440,   441,   225,   225,   225,   817,   402,
     614,   220,   403,   615,   245,    91,  1062,   426,   187,    94,
      95,   214,     1,     2,   190,   609,   225,   377,   248,    91,
     249,   230,   231,    94,    95,   628,   818,   369,   370,   232,
     433,   371,   372,   373,   374,   375,   376,   377,   272,    79,
     189,   260,   366,   278,   896,   194,    81,   195,   196,   451,
     239,   244,   366,   444,   445,   366,    68,  1003,    69,   452,
     719,   286,   720,   360,   361,   362,   363,   364,   365,   360,
     361,   362,   363,   364,   365,    91,   240,   241,   242,    94,
      95,   369,   370,   243,   396,   371,   372,   373,   374,   375,
     376,   377,   391,   392,   253,   369,   370,   266,   267,   371,
     372,   373,   374,   375,   376,   377,   409,   369,   370,   268,
     254,   371,   372,   373,   374,   375,   376,   377,   255,   380,
     381,   366,   360,   361,   362,   363,   364,   365,   707,   748,
     256,   749,   357,   359,    52,    53,    54,   378,   379,   380,
     381,    86,   366,   988,    87,    80,   991,   366,   263,   434,
     394,   558,    82,   560,   708,   420,   421,   406,   264,   366,
     366,   434,   257,    68,   738,    69,   739,   709,   258,   197,
     366,   269,   404,   616,   215,   216,   366,   751,   431,   752,
     423,   641,   425,   449,   437,   439,   475,   476,   215,   216,
     270,   378,   379,   380,   381,   376,   377,   658,   659,   434,
     928,   931,   929,   932,   271,   378,   379,   380,   381,   454,
     455,   456,   375,   376,   377,   277,   447,   378,   379,   380,
     381,   360,   361,   362,   363,   364,   365,    80,   457,   366,
     202,   203,   683,   462,   673,   490,   674,  1060,   374,   375,
     376,   377,    82,   477,   478,   280,   479,   225,   225,   548,
     549,   281,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   225,   503,   504,   505,   506,   507,   508,
     509,   511,   482,   483,  1001,   284,  1002,   517,   518,   519,
     521,   522,   377,   524,   366,   526,  -379,   366,   502,   774,
     604,   775,   902,   285,   903,   366,   378,   379,   380,   381,
     225,   366,   731,   369,   370,   551,   562,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   619,   620,
     366,   287,    93,   625,   626,   546,    96,   732,   366,   288,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   378,   379,   380,   381,   366,   366,    98,   289,   366,
     917,   920,   918,   921,   367,   368,   744,   366,   605,   665,
     366,   366,   218,   608,   745,   922,   562,   923,   945,    68,
     290,    69,   366,   366,   623,   624,   366,  1056,   638,  1057,
     746,   640,   378,   379,   380,   381,   291,   635,   400,   636,
     360,   361,   362,   363,   364,   365,   292,   369,   370,   642,
     643,   371,   372,   373,   374,   375,   376,   377,   651,   653,
     293,   366,   294,   378,   379,   380,   381,   108,   747,   109,
     366,   210,   211,   366,    68,   366,    69,   750,   848,   666,
     753,   850,   800,   295,   366,   366,   282,   283,    68,   366,
      69,   802,   810,   130,   131,   132,   954,   366,   296,   136,
     137,   138,   297,   140,  1026,   142,   143,   144,   382,   383,
     366,   366,   149,   150,   151,   649,   706,   154,   366,   156,
     366,   158,   366,   710,   160,   717,   162,   722,   163,   366,
     298,   165,   166,   167,   723,   169,   366,   171,   386,   387,
     414,   724,   760,   761,   184,   763,   764,   366,   366,   299,
     366,   366,   562,   725,  1034,   726,   727,   378,   379,   380,
     381,   300,   360,   361,   362,   363,   364,   365,   366,   366,
     301,   369,   370,   728,   729,   371,   372,   373,   374,   375,
     376,   377,   758,   759,   302,   369,   370,   754,   756,   371,
     372,   373,   374,   375,   376,   377,   303,   468,   304,   469,
     806,   470,   305,   596,   894,   597,   366,   598,   366,   366,
     419,   730,   366,   733,   734,   773,   442,   735,   484,   485,
     306,   780,   781,   907,   471,   784,   366,   472,   611,   612,
     599,   742,   473,   600,   803,   621,   622,   366,   601,   797,
     369,   370,   900,   307,   371,   372,   373,   374,   375,   376,
     377,   812,   813,   366,   807,   808,   809,   366,   924,  1049,
     366,  1050,   925,  1051,   453,   930,   811,   631,   632,   366,
     366,   308,   462,   816,   736,   933,   830,   309,   820,   821,
     822,   378,   379,   380,   381,   310,  1052,   366,   311,  1053,
     828,   829,   934,   831,  1054,   378,   379,   380,   381,   366,
     832,   563,   366,   833,   944,   312,   366,  1005,   313,   366,
     862,  1008,   314,   834,  1011,   315,   835,   836,   837,   366,
     838,   839,   366,   366,  1013,   366,   460,  1014,  1023,   841,
    1076,   316,   369,   370,   660,   661,   371,   372,   373,   374,
     375,   376,   377,   769,   770,   785,   786,   876,   877,   317,
     378,   379,   380,   381,   846,   847,   690,   372,   691,   374,
     375,   376,   377,   422,   369,   370,   859,   860,   371,   372,
     373,   374,   375,   376,   377,   962,   963,   318,   369,   370,
     319,   863,   371,   372,   373,   374,   375,   376,   377,    68,
     320,    69,   372,   373,   374,   375,   376,   377,   981,   982,
     321,   322,   878,   879,   323,   324,   185,   225,   225,   188,
     325,   326,   327,   886,   887,   328,   329,   330,   200,   893,
     331,   332,   206,   208,   333,   334,   335,   224,   336,   948,
     949,   337,   881,   882,   338,   339,   340,   341,   342,   250,
     251,   252,   378,   379,   380,   381,   343,   427,   259,   261,
     262,   369,   370,   344,   345,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   346,   428,   394,   935,
     936,   347,   275,   942,   378,   379,   380,   381,   946,  1068,
     693,  1069,   694,  1070,   348,   349,   350,   961,   378,   379,
     380,   381,   351,   436,   713,   352,   714,   378,   379,   380,
     381,   959,   450,   353,   354,   966,  1071,   465,   355,  1072,
     356,   399,   401,   412,  1073,   413,   968,   417,   466,  1015,
    1016,   418,   377,   969,   555,   556,   586,   587,   588,   589,
     971,   590,   972,   369,   370,   591,   974,   371,   372,   373,
     374,   375,   376,   377,   592,   593,   594,   603,   617,   606,
     613,   644,   984,   766,   798,   645,   646,   647,   657,   663,
    1036,   378,   379,   380,   381,   358,   667,   891,   668,   892,
     672,  1045,   676,   675,  1046,   390,   677,   678,   681,   679,
     680,   791,   393,   682,   697,   737,   740,   369,  1017,   405,
    1065,   371,   372,   373,   374,   375,   376,   377,    68,    68,
      69,    69,   741,   371,   372,   373,   374,   375,   376,   377,
     789,   790,  1031,   424,   792,  1033,   795,   796,   799,   826,
     827,   485,   865,   429,   853,   854,   855,   856,   938,   857,
    1039,  1040,   858,   873,   874,  1044,   939,   888,   875,    68,
     895,    69,   901,   378,   379,   380,   381,   906,    -4,   448,
      68,   415,    69,    68,   943,    69,   951,   952,   956,   957,
     958,   458,   979,   989,   985,   461,   990,   999,  1067,    68,
    1000,    69,  1018,  1020,  1022,  1025,  1027,  1028,  -357,   481,
    1078,   246,   656,   369,   370,   247,   488,   371,   372,   373,
     374,   375,   376,   377,   629,   815,   765,   378,   379,   380,
     381,   762,  1080,  1030,   512,   513,   514,   515,   516,   378,
     379,   380,   381,   937,   523,   627,   525,   637,   527,   528,
     530,   532,   534,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   547,   868,  1041,   550,     0,   552,   553,
     554,     0,     0,   557,     0,   559,     0,   561,     0,     0,
       0,   564,   565,   566,   567,   568,   569,   570,     0,     0,
       0,     0,     0,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,   607,   378,   379,   380,   381,     0,     0,   913,
       0,   914,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   634,     0,
       0,     0,   100,   101,   102,   103,     0,   639,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
     650,   652,   654,   655,   227,     0,     0,     0,     0,     0,
       0,     0,   228,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,   229,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,     0,     0,     0,   174,   369,   370,
       0,   223,   371,   372,   373,   374,   375,   376,   377,   369,
     370,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     369,   370,     0,     0,   371,   372,   373,   374,   375,   376,
     377,   369,   370,     0,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,   369,   370,
       0,     0,   371,   372,   373,   374,   375,   376,   377,     0,
     778,   369,   370,   779,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   369,   370,     0,     0,
     371,   372,   373,   374,   375,   376,   377,     0,   378,   379,
     380,   381,     0,     0,   461,     0,   416,     0,     0,   378,
     379,   380,   381,     0,     0,   823,   825,   430,     0,     0,
     378,   379,   380,   381,     0,     0,     0,     0,   630,     0,
       0,   378,   379,   380,   381,     0,     0,     0,     0,   669,
       0,    91,    92,    93,     0,    94,    95,    96,   378,   379,
     380,   381,     0,     0,     0,   840,   670,     0,     0,     0,
       0,   378,   379,   380,   381,     0,     0,    97,    98,   671,
       0,     0,   842,   843,   378,   379,   380,   381,     0,     0,
     844,     0,   684,     0,     0,   845,     0,     0,     0,     0,
     849,     0,     0,   851,   852,     0,   378,   379,   380,   381,
     100,   101,   102,   103,   704,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,   866,   105,   867,   369,
     370,     0,   221,   371,   372,   373,   374,   375,   376,   377,
     222,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,   883,   884,   885,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,     0,   163,
     393,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,   174,     0,     0,     0,   223,
       0,   953,     0,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,     0,     0,     0,     0,   711,     0,     0,
       0,   369,   370,     0,   967,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,   970,
       0,     0,     0,     0,     0,     0,     0,   973,     0,     0,
     975,   369,   370,   976,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,   986,     0,     0,     0,
       0,     0,     0,     0,     0,   992,   993,   994,   995,   996,
       0,   998,     0,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,     0,     0,     0,     0,   712,
       0,  1038,   100,   101,   102,   103,  1042,  1043,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
       0,   378,   379,   380,   381,     0,     0,     0,     0,   772,
       0,     0,   480,     0,     0,     0,   106,   107,  1066,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,    91,    92,    93,   174,    94,    95,
      96,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   369,   370,
     105,     0,   371,   372,   373,   374,   375,   376,   377,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,     0,   163,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,    91,    92,    93,   174,    94,
      95,    96,   223,     0,     0,     0,     0,     0,   378,   379,
     380,   381,     0,     0,     0,     0,   793,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   369,
     370,   105,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,     0,   163,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,     0,     0,     0,   174,
     446,    91,    92,    93,     0,    94,    95,    96,     0,   378,
     379,   380,   381,     0,     0,     0,     0,   794,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   369,   370,   105,     0,   371,
     372,   373,   374,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,     0,   163,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,   174,   510,    91,    92,    93,
       0,    94,    95,    96,     0,   378,   379,   380,   381,     0,
       0,     0,     0,   801,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,     0,     0,
       0,   174,   520,    91,    92,    93,     0,    94,    95,    96,
       0,   235,     0,     0,   378,   379,   380,   381,     0,     0,
       0,     0,   804,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   369,   370,   105,
       0,   371,   372,   373,   374,   375,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,    91,    92,    93,   174,    94,    95,
      96,     0,     0,     0,     0,     0,     0,   378,   379,   380,
     381,     0,     0,     0,     0,   805,     0,     0,     0,     0,
      97,    98,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   369,   370,
     105,     0,   371,   372,   373,   374,   375,   376,   377,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,     0,   163,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,    91,    92,    93,   174,    94,
      95,    96,     0,   438,     0,     0,     0,     0,   378,   379,
     380,   381,     0,     0,     0,     0,   864,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   369,
     370,   105,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,     0,   163,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,    91,    92,    93,   174,
      94,    95,    96,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,     0,     0,     0,     0,   869,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,    93,   105,   369,   370,    96,     0,   371,   372,   373,
     374,   375,   376,   377,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,    98,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   108,     0,   109,     0,
     174,    93,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,   378,   379,   380,   381,     0,     0,     0,
       0,   880,   130,   131,   132,     0,    98,     0,   136,   137,
     138,     0,   140,     0,   142,   143,   144,     0,     0,     0,
       0,   149,   150,   151,     0,     0,   154,     0,   156,     0,
     158,     0,     0,   160,    93,   162,     0,   163,    96,     0,
     165,   166,   167,     0,   169,     0,   171,     0,     0,     0,
       0,     0,     0,   184,   529,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,    96,     0,     0,     0,
       0,     0,   130,   131,   132,     0,     0,     0,   136,   137,
     138,     0,   140,     0,   142,   143,   144,    98,     0,     0,
       0,   149,   150,   151,     0,     0,   154,     0,   156,   108,
     158,   109,     0,   160,     0,   162,     0,   163,     0,     0,
     165,   166,   167,     0,   169,     0,   171,     0,    93,     0,
       0,     0,    96,   184,   531,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,    98,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,   108,   162,   109,
     163,     0,     0,   165,   166,   167,     0,   169,     0,   171,
       0,     0,     0,     0,    93,     0,   184,   533,    96,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,   136,
     137,   138,     0,   140,     0,   142,   143,   144,     0,    98,
       0,     0,   149,   150,   151,   633,     0,   154,     0,   156,
       0,   158,     0,   108,   160,   109,   162,     0,   163,     0,
       0,   165,   166,   167,     0,   169,     0,   171,     0,     0,
       0,     0,    93,     0,   184,   535,    96,     0,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,     0,   140,
       0,   142,   143,   144,     0,     0,     0,    98,   149,   150,
     151,   824,     0,   154,     0,   156,     0,   158,     0,   108,
     160,   109,   162,     0,   163,     0,     0,   165,   166,   167,
       0,   169,     0,   171,     0,     0,     0,     0,     0,     0,
     184,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,   108,   162,   109,
     163,     0,     0,   165,   166,   167,     0,   169,     0,   171,
       0,     0,     0,     0,     0,     0,   184,     0,     0,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,   136,
     137,   138,     0,   140,     0,   142,   143,   144,     0,     0,
       0,     0,   149,   150,   151,     0,     0,   154,     0,   156,
       0,   158,     0,     0,   160,     0,   162,     0,   163,     0,
       0,   165,   166,   167,     0,   169,     0,   171,     0,     1,
       2,     3,     0,     0,   777,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,    11,  -308,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,     0,     0,     0,     0,    23,     0,     0,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,     0,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,  -110,  -110,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,  -110,     0,    49,     0,    50,    51,
     369,   370,     0,     0,   371,   372,   373,   374,   375,   376,
     377,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      57,     0,     1,     2,     3,    58,     0,    59,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     8,     9,    10,
      11,  -308,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
      -6,    -6,    24,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,    31,    32,
     378,   379,   380,   381,     0,     0,     0,     0,   926,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,     0,     0,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,     0,     0,    49,
       0,    50,    51,   369,   370,     0,     0,   371,   372,   373,
     374,   375,   376,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,    57,     0,     1,     2,     3,    58,     0,
      59,     4,     0,     0,     0,     5,     0,     6,     0,     7,
       8,     9,    10,    11,  -308,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    -6,     0,
       0,     0,    23,    -6,     0,    24,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,   378,   379,   380,   381,     0,     0,     0,
       0,   927,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    39,    40,    41,     0,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,   369,   370,     0,     0,
     371,   372,   373,   374,   375,   376,   377,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,   369,   370,     0,    55,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,    57,     0,     0,     0,
       0,    58,     0,    59,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,   369,   370,     0,     0,   371,
     372,   373,   374,   375,   376,   377,   369,   370,     0,     0,
     371,   372,   373,   374,   375,   376,   377,   369,   370,     0,
       0,   371,   372,   373,   374,   375,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,   378,   379,   380,   381,
       0,   369,   370,     0,   955,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,     0,   369,   370,     0,   960,
     371,   372,   373,   374,   375,   376,   377,   369,   370,     0,
       0,   371,   372,   373,   374,   375,   376,   377,     0,     0,
       0,     0,     0,     0,   378,   379,   380,   381,     0,     0,
       0,     0,  1006,     0,     0,   378,   379,   380,   381,     0,
       0,     0,     0,  1021,     0,     0,   378,   379,   380,   381,
       0,     0,     0,     0,  1059,     0,     0,   378,   379,   380,
     381,   369,   370,   648,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,   369,   370,   685,     0,   371,
     372,   373,   374,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,   379,   380,   381,
       0,     0,   686,     0,     0,     0,     0,   378,   379,   380,
     381,   369,   370,   687,     0,   371,   372,   373,   374,   375,
     376,   377,   369,   370,     0,     0,   371,   372,   373,   374,
     375,   376,   377,   369,   370,     0,     0,   371,   372,   373,
     374,   375,   376,   377,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,   369,   370,   688,     0,   371,
     372,   373,   374,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,   369,
     370,   689,     0,   371,   372,   373,   374,   375,   376,   377,
     369,   370,     0,     0,   371,   372,   373,   374,   375,   376,
     377,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,     0,     0,   692,     0,     0,
       0,     0,   378,   379,   380,   381,     0,     0,   695,     0,
       0,     0,     0,   378,   379,   380,   381,     0,     0,   696,
       0,     0,     0,     0,   378,   379,   380,   381,   369,   370,
     698,     0,   371,   372,   373,   374,   375,   376,   377,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,   369,
     370,   699,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,     0,     0,   700,     0,     0,     0,     0,
     378,   379,   380,   381,   369,   370,   701,     0,   371,   372,
     373,   374,   375,   376,   377,   369,   370,     0,     0,   371,
     372,   373,   374,   375,   376,   377,   369,   370,     0,     0,
     371,   372,   373,   374,   375,   376,   377,   369,   370,     0,
       0,   371,   372,   373,   374,   375,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,   379,
     380,   381,   369,   370,   702,     0,   371,   372,   373,   374,
     375,   376,   377,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,   369,   370,   703,     0,   371,   372,   373,
     374,   375,   376,   377,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   378,   379,   380,   381,     0,     0,
     705,     0,     0,     0,     0,   378,   379,   380,   381,     0,
       0,   715,     0,     0,     0,     0,   378,   379,   380,   381,
       0,     0,   716,     0,     0,     0,     0,   378,   379,   380,
     381,   369,   370,   718,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   378,   379,   380,   381,   369,   370,   721,     0,
     371,   372,   373,   374,   375,   376,   377,     0,     0,     0,
       0,     0,     0,   378,   379,   380,   381,     0,     0,   743,
       0,     0,     0,     0,   378,   379,   380,   381,   369,   370,
     776,     0,   371,   372,   373,   374,   375,   376,   377,   369,
     370,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     369,   370,     0,     0,   371,   372,   373,   374,   375,   376,
     377,   369,   370,     0,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   380,   381,   369,   370,   872,     0,   371,
     372,   373,   374,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,   379,   380,   381,
     369,   370,   889,     0,   371,   372,   373,   374,   375,   376,
     377,   369,   370,     0,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,   378,   379,
     380,   381,     0,     0,   890,     0,     0,     0,     0,   378,
     379,   380,   381,     0,     0,   897,     0,     0,     0,     0,
     378,   379,   380,   381,     0,     0,   898,     0,     0,     0,
       0,   378,   379,   380,   381,   369,   370,   899,     0,   371,
     372,   373,   374,   375,   376,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,   369,
     370,   904,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,   379,   380,   381,     0,     0,   905,     0,     0,     0,
       0,   378,   379,   380,   381,   369,   370,   908,     0,   371,
     372,   373,   374,   375,   376,   377,   369,   370,     0,     0,
     371,   372,   373,   374,   375,   376,   377,   369,   370,     0,
       0,   371,   372,   373,   374,   375,   376,   377,   369,   370,
       0,     0,   371,   372,   373,   374,   375,   376,   377,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,   369,
     370,   909,     0,   371,   372,   373,   374,   375,   376,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,   369,   370,   910,     0,   371,   372,   373,
     374,   375,   376,   377,   369,   370,     0,     0,   371,   372,
     373,   374,   375,   376,   377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   378,   379,   380,   381,     0,
       0,   911,     0,     0,     0,     0,   378,   379,   380,   381,
       0,     0,   912,     0,     0,     0,     0,   378,   379,   380,
     381,     0,     0,   915,     0,     0,     0,     0,   378,   379,
     380,   381,   369,   370,   916,     0,   371,   372,   373,   374,
     375,   376,   377,     0,     0,     0,     0,     0,     0,   378,
     379,   380,   381,   369,   370,   919,     0,   371,   372,   373,
     374,   375,   376,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   378,   379,   380,   381,     0,     0,   941,
       0,     0,     0,     0,   378,   379,   380,   381,   369,   370,
     983,     0,   371,   372,   373,   374,   375,   376,   377,   369,
     370,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     369,   370,     0,     0,   371,   372,   373,   374,   375,   376,
     377,   369,   370,     0,     0,   371,   372,   373,   374,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   378,   379,   380,   381,   369,   370,   987,     0,
     371,   372,   373,   374,   375,   376,   377,     0,     0,     0,
       0,     0,     0,   378,   379,   380,   381,   369,   370,   997,
       0,   371,   372,   373,   374,   375,   376,   377,   369,   370,
       0,     0,   371,   372,   373,   374,   375,   376,   377,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,   379,
     380,   381,     0,     0,  1007,     0,     0,     0,     0,   378,
     379,   380,   381,     0,     0,  1009,     0,     0,     0,     0,
     378,   379,   380,   381,     0,     0,  1010,     0,     0,     0,
       0,   378,   379,   380,   381,     0,     0,  1012,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,   379,   380,   381,
       0,     0,  1047,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   378,   379,   380,
     381,     0,     0,  1058,     0,     0,     0,     0,   378,   379,
     380,   381,     0,     0,  1077
};

static const yytype_int16 yycheck[] =
{
      11,     0,   291,     0,    34,     9,    10,    85,   782,   783,
      11,   177,    57,    24,    41,    42,    27,    24,    82,    30,
      31,    32,    11,   251,   252,    36,    37,    38,    15,     4,
       4,    35,     7,     7,    45,     3,    43,    10,   177,     7,
       8,     9,     4,     5,     7,    50,    57,    72,    47,     3,
      47,    37,    38,     7,     8,     9,    43,    62,    63,    83,
      11,    66,    67,    68,    69,    70,    71,    72,    79,    71,
      27,    57,   173,    84,    11,    57,    71,    59,    60,   180,
      58,    90,   173,   255,   256,   173,    85,    12,    85,   180,
     178,   102,   180,    66,    67,    68,    69,    70,    71,    66,
      67,    68,    69,    70,    71,     3,    84,    85,    86,     7,
       8,    62,    63,    91,   192,    66,    67,    68,    69,    70,
      71,    72,   186,   187,   105,    62,    63,    87,    88,    66,
      67,    68,    69,    70,    71,    72,   181,    62,    63,    99,
     177,    66,    67,    68,    69,    70,    71,    72,   177,   174,
     175,   173,    66,    67,    68,    69,    70,    71,   180,   178,
     177,   180,   173,   174,   126,   127,   128,   172,   173,   174,
     175,     4,   173,   947,     7,   177,   950,   173,     0,   180,
     191,   353,   177,   355,   180,   215,   216,   198,    43,   173,
     173,   180,   177,   192,   178,   192,   180,   180,   177,   181,
     173,    71,   177,   177,   172,   173,   173,   178,   235,   180,
     221,   439,   223,   180,   241,   242,   280,   281,   172,   173,
      71,   172,   173,   174,   175,    71,    72,   455,   456,   180,
     178,   178,   180,   180,    23,   172,   173,   174,   175,   266,
     267,   268,    70,    71,    72,     4,   257,   172,   173,   174,
     175,    66,    67,    68,    69,    70,    71,   177,   269,   173,
       4,     5,   490,   274,   178,   292,   180,  1041,    69,    70,
      71,    72,   177,   284,   285,   177,   287,   288,   289,   343,
     344,   177,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   288,   289,   178,   177,   180,   318,   319,   320,
     321,   322,    72,   324,   173,   326,    45,   173,   304,   178,
     398,   180,   178,   177,   180,   173,   172,   173,   174,   175,
     341,   173,   180,    62,    63,   346,   178,    66,    67,    68,
      69,    70,    71,    72,   172,   173,   174,   175,   412,   413,
     173,   177,     5,   417,   418,   341,     9,   180,   173,   177,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   172,   173,   174,   175,   173,   173,    30,   177,   173,
     178,   178,   180,   180,    19,    20,   180,   173,   399,   467,
     173,   173,   422,   404,   180,   178,   178,   180,   180,   398,
     177,   398,   173,   173,   415,   416,   173,   178,   435,   180,
     180,   438,   172,   173,   174,   175,   177,   428,    57,   430,
      66,    67,    68,    69,    70,    71,   177,    62,    63,   440,
     441,    66,    67,    68,    69,    70,    71,    72,   449,   450,
     177,   173,   177,   172,   173,   174,   175,   100,   180,   102,
     173,     4,     5,   173,   453,   173,   453,   180,   747,   470,
     180,   750,   180,   177,   173,   173,    34,    35,   467,   173,
     467,   180,   180,   126,   127,   128,   180,   173,   177,   132,
     133,   134,   177,   136,   180,   138,   139,   140,     4,     5,
     173,   173,   145,   146,   147,   178,   178,   150,   173,   152,
     173,   154,   173,   178,   157,   178,   159,   178,   161,   173,
     177,   164,   165,   166,   178,   168,   173,   170,     4,     5,
     180,   178,   586,   587,   177,   589,   590,   173,   173,   177,
     173,   173,   178,   178,    45,   178,   178,   172,   173,   174,
     175,   177,    66,    67,    68,    69,    70,    71,   173,   173,
     177,    62,    63,   178,   178,    66,    67,    68,    69,    70,
      71,    72,   573,   574,   177,    62,    63,   571,   572,    66,
      67,    68,    69,    70,    71,    72,   177,    13,   177,    15,
     644,    17,   177,    13,   812,    15,   173,    17,   173,   173,
     180,   178,   173,   178,   178,   606,     5,   178,     4,     5,
     177,   612,   613,   831,    40,   616,   173,    43,   179,   180,
      40,   178,    48,    43,   641,     4,     5,   173,    48,   630,
      62,    63,   178,   177,    66,    67,    68,    69,    70,    71,
      72,   658,   659,   173,   645,   646,   647,   173,   178,    13,
     173,    15,   178,    17,    42,   178,   657,    81,    82,   173,
     173,   177,   663,   664,   178,   178,   683,   177,   669,   670,
     671,   172,   173,   174,   175,   177,    40,   173,   177,    43,
     681,   682,   178,   684,    48,   172,   173,   174,   175,   173,
     691,   178,   173,   694,   178,   177,   173,   178,   177,   173,
     768,   178,   177,   704,   178,   177,   707,   708,   709,   173,
     711,   712,   173,   173,   178,   173,   178,   178,   178,   720,
     178,   177,    62,    63,     4,     5,    66,    67,    68,    69,
      70,    71,    72,    48,    49,     4,     5,   791,   792,   177,
     172,   173,   174,   175,   745,   746,   178,    67,   180,    69,
      70,    71,    72,   180,    62,    63,    38,    39,    66,    67,
      68,    69,    70,    71,    72,     4,     5,   177,    62,    63,
     177,   772,    66,    67,    68,    69,    70,    71,    72,   768,
     177,   768,    67,    68,    69,    70,    71,    72,    59,    60,
     177,   177,   793,   794,   177,   177,    15,   798,   799,    18,
     177,   177,   177,   804,   805,   177,   177,   177,    27,   810,
     177,   177,    31,    32,   177,   177,   177,    36,   177,   873,
     874,   177,   798,   799,   177,   177,   177,   177,   177,    48,
      49,    50,   172,   173,   174,   175,   177,   180,    57,    58,
      59,    62,    63,   177,   177,    66,    67,    68,    69,    70,
      71,    72,   172,   173,   174,   175,   177,   180,   859,   853,
     854,   177,    81,   864,   172,   173,   174,   175,   869,    13,
     178,    15,   180,    17,   177,   177,   177,   894,   172,   173,
     174,   175,   177,   180,   178,   177,   180,   172,   173,   174,
     175,   892,   180,   177,   177,   896,    40,   178,   177,    43,
     177,   177,   177,   177,    48,   177,   907,   177,    71,   977,
     978,   177,    72,   914,   178,   178,   177,   177,   180,   177,
     921,   177,   923,    62,    63,   180,   927,    66,    67,    68,
      69,    70,    71,    72,   178,   178,    42,    45,     9,   177,
     177,   177,   943,    42,    80,   180,   180,   180,   180,   180,
    1018,   172,   173,   174,   175,   174,   178,   178,   178,   180,
     178,  1029,   178,   180,  1032,   184,   177,   177,   180,   178,
     178,   177,   191,   180,   178,   178,   178,    62,   979,   198,
    1048,    66,    67,    68,    69,    70,    71,    72,   977,   978,
     977,   978,   178,    66,    67,    68,    69,    70,    71,    72,
     178,   178,  1003,   222,   177,  1006,   178,   178,    80,   178,
     178,     5,    57,   232,   180,   180,   178,   178,    42,   178,
    1021,  1022,   178,   177,   177,  1026,    37,   178,   180,  1018,
     177,  1018,   178,   172,   173,   174,   175,   178,    42,   258,
    1029,   180,  1029,  1032,   177,  1032,   178,   178,    71,    71,
      71,   270,    47,   178,    57,   274,   178,   177,  1059,  1048,
     177,  1048,    46,   177,   177,    71,   178,   178,    37,   288,
       4,    47,   453,    62,    63,    47,   291,    66,    67,    68,
      69,    70,    71,    72,   422,   663,   591,   172,   173,   174,
     175,   588,  1075,  1002,   313,   314,   315,   316,   317,   172,
     173,   174,   175,   859,   323,   419,   325,   432,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   780,  1024,   345,    -1,   347,   348,
     349,    -1,    -1,   352,    -1,   354,    -1,   356,    -1,    -1,
      -1,   360,   361,   362,   363,   364,   365,   366,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,   401,   172,   173,   174,   175,    -1,    -1,   178,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
     449,   450,   451,   452,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
      -1,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,   177,    62,    63,
      -1,   181,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
     609,    62,    63,   612,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,   172,   173,
     174,   175,    -1,    -1,   663,    -1,   180,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   674,   675,   180,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,     3,     4,     5,    -1,     7,     8,     9,   172,   173,
     174,   175,    -1,    -1,    -1,   714,   180,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,    29,    30,   180,
      -1,    -1,   731,   732,   172,   173,   174,   175,    -1,    -1,
     739,    -1,   180,    -1,    -1,   744,    -1,    -1,    -1,    -1,
     749,    -1,    -1,   752,   753,    -1,   172,   173,   174,   175,
      62,    63,    64,    65,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,   775,    79,   777,    62,
      63,    -1,    84,    66,    67,    68,    69,    70,    71,    72,
      92,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,    -1,
     102,   800,   801,   802,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,    -1,   161,
     859,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,   181,
      -1,   880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    62,    63,    -1,   903,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,
     929,    62,    63,   932,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,   945,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,   955,   956,   957,   958,
      -1,   960,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,  1020,    62,    63,    64,    65,  1025,  1026,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,   172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,  1057,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
      -1,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,     3,     4,     5,   177,     7,     8,
       9,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,     3,     4,     5,   177,     7,
       8,     9,   181,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
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
     158,   159,    -1,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,   177,
     178,     3,     4,     5,    -1,     7,     8,     9,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
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
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,   177,   178,     3,     4,     5,
      -1,     7,     8,     9,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,
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
     156,   157,   158,   159,    -1,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,   177,   178,     3,     4,     5,    -1,     7,     8,     9,
      -1,    11,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    29,
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
      -1,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,     3,     4,     5,   177,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
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
     159,    -1,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,     3,     4,     5,   177,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,
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
     158,   159,    -1,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,     3,     4,     5,   177,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,     5,    79,    62,    63,     9,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    30,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   100,    -1,   102,    -1,
     177,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,   126,   127,   128,    -1,    30,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,
     154,    -1,    -1,   157,     5,   159,    -1,   161,     9,    -1,
     164,   165,   166,    -1,   168,    -1,   170,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    30,    -1,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,   100,
     154,   102,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
     164,   165,   166,    -1,   168,    -1,   170,    -1,     5,    -1,
      -1,    -1,     9,   177,   178,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    -1,    30,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,   100,   159,   102,
     161,    -1,    -1,   164,   165,   166,    -1,   168,    -1,   170,
      -1,    -1,    -1,    -1,     5,    -1,   177,   178,     9,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,    -1,   138,   139,   140,    -1,    30,
      -1,    -1,   145,   146,   147,    92,    -1,   150,    -1,   152,
      -1,   154,    -1,   100,   157,   102,   159,    -1,   161,    -1,
      -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,    -1,
      -1,    -1,     5,    -1,   177,   178,     9,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    30,   145,   146,
     147,    92,    -1,   150,    -1,   152,    -1,   154,    -1,   100,
     157,   102,   159,    -1,   161,    -1,    -1,   164,   165,   166,
      -1,   168,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,   100,   159,   102,
     161,    -1,    -1,   164,   165,   166,    -1,   168,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,   154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,   164,   165,   166,    -1,   168,    -1,   170,    -1,     4,
       5,     6,    -1,    -1,   177,    10,    -1,    -1,    -1,    14,
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
     155,    -1,     4,     5,     6,   160,    -1,   162,    10,    -1,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    60,    61,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    -1,    -1,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    -1,    -1,   101,
      -1,   103,   104,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,   155,    -1,     4,     5,     6,   160,    -1,
     162,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    61,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    73,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,    -1,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    62,    63,    -1,   133,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    62,    63,    -1,   180,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    62,    63,    -1,   180,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,    63,
     178,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    62,    63,   178,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    62,    63,   178,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    62,    63,   178,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,
     178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    62,    63,   178,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    62,    63,   178,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,    63,
     178,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      62,    63,   178,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    62,    63,   178,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,
      63,   178,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    62,    63,   178,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,    -1,
      -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    62,    63,   178,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    62,    63,   178,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   172,   173,   174,   175,    62,    63,
     178,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,   175,    62,    63,   178,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,    62,    63,   178,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,    -1,    -1,   178,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,    -1,   178
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
     157,   158,   159,   161,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   177,   199,   200,   202,   208,   210,
     213,   214,   187,   188,   177,   199,   177,   177,   199,    27,
       7,   241,   249,   202,    57,    59,    60,   181,   287,   191,
     199,   202,     4,     5,   212,   202,   199,   202,   199,   202,
       4,     5,   275,   276,     9,   172,   173,   209,   210,   277,
     211,    84,    92,   181,   199,   202,   288,    84,    92,   105,
     288,   288,    83,   202,   207,    11,    52,   207,   207,    58,
      84,    85,    86,    91,    90,   202,   194,   201,   213,   214,
     199,   199,   199,   105,   177,   177,   177,   177,   177,   199,
     288,   199,   199,     0,    43,   185,    87,    88,    99,    71,
      71,    23,   202,   215,   216,   199,   215,     4,   202,   184,
     177,   177,    34,    35,   177,   177,   202,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   202,   199,   202,
      66,    67,    68,    69,    70,    71,   173,    19,    20,    62,
      63,    66,    67,    68,    69,    70,    71,    72,   172,   173,
     174,   175,     4,     5,   226,   227,     4,     5,   228,   229,
     199,   215,   215,   199,   202,   243,   184,   259,   265,   177,
      57,   177,     4,     7,   177,   199,   202,   278,    57,   181,
     280,   285,   177,   177,   180,   180,   180,   177,   177,   180,
     210,   210,   180,   202,   199,   202,    10,   180,   180,   199,
     180,   207,   192,    11,   180,   195,   180,   207,    11,   207,
     195,   195,     5,   198,   198,   198,   178,   202,   199,   180,
     180,   180,   180,    42,   207,   207,   207,   202,   199,   220,
     178,   199,   202,   217,   218,   178,    71,   253,    13,    15,
      17,    40,    43,    48,   257,   215,   215,   202,   202,   202,
      92,   199,   288,   288,     4,     5,   205,   206,   205,   206,
     207,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   288,   202,   202,   202,   202,   202,   202,   202,
     178,   202,   199,   199,   199,   199,   199,   202,   202,   202,
     178,   202,   202,   199,   202,   199,   202,   199,   199,   178,
     199,   178,   199,   178,   199,   178,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   288,   199,   215,   215,
     199,   202,   199,   199,   199,   178,   178,   199,   198,   199,
     198,   199,   178,   178,   199,   199,   199,   199,   199,   199,
     199,   189,   190,   204,   203,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   177,   177,   180,   177,
     177,   180,   178,   178,    42,   242,    13,    15,    17,    40,
      43,    48,   250,    45,   184,   202,   177,   199,   202,    50,
     279,   179,   180,   177,     4,     7,   177,     9,   286,   215,
     215,     4,     5,   202,   202,   215,   215,   276,     9,   209,
     180,    81,    82,    92,   199,   202,   202,   280,   207,   199,
     207,   195,   202,   202,   177,   180,   180,   180,   178,   178,
     199,   202,   199,   202,   199,   199,   186,   180,   195,   195,
       4,     5,   224,   180,   234,   184,   202,   178,   178,   180,
     180,   180,   178,   178,   180,   180,   178,   177,   177,   178,
     178,   180,   180,   195,   180,   178,   178,   178,   178,   178,
     178,   180,   178,   178,   180,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   180,   178,   178,   180,   180,   180,
     178,   180,   180,   178,   180,   178,   178,   178,   178,   178,
     180,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   180,   180,   178,   178,   178,   178,   178,   178,   180,
     178,   178,   178,   178,   180,   180,   180,   180,   178,   180,
     180,   178,   180,   180,   211,   289,   211,   290,   202,   202,
     215,   215,   227,   215,   215,   229,    42,   244,   260,    48,
      49,   266,   180,   202,   178,   180,   178,   177,   199,   199,
     202,   202,   281,   282,   202,     4,     5,   272,   274,   178,
     178,   177,   177,   180,   180,   178,   178,   202,    80,    80,
     180,   180,   180,   207,   180,   180,   215,   202,   202,   202,
     180,   202,   207,   207,   221,   218,   202,    15,    43,   254,
     202,   202,   202,   199,    92,   199,   178,   178,   202,   202,
     207,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     199,   202,   199,   199,   199,   199,   202,   202,   206,   199,
     206,   199,   199,   180,   180,   178,   178,   178,   178,    38,
      39,   246,   184,   202,   180,    57,   199,   199,   279,   180,
     272,   272,   178,   177,   177,   180,   215,   215,   202,   202,
     180,   288,   288,   199,   199,   199,   202,   202,   178,   178,
     178,   178,   180,   202,   195,   177,    11,   178,   178,   178,
     178,   178,   178,   180,   178,   178,   178,   195,   178,   178,
     178,   178,   178,   178,   180,   178,   178,   178,   180,   178,
     178,   180,   178,   180,   178,   178,   180,   180,   178,   180,
     178,   178,   180,   178,   178,   211,   211,   243,    42,    37,
     261,   178,   202,   177,   178,   180,   202,   283,   215,   215,
     273,   178,   178,   199,   180,   180,    71,    71,    71,   202,
     180,   207,     4,     5,   230,   231,   202,   199,   202,   202,
     199,   202,   202,   199,   202,   199,   199,   245,   247,    47,
     268,    59,    60,   178,   202,    57,   199,   178,   272,   178,
     178,   272,   199,   199,   199,   199,   199,   178,   199,   177,
     177,   178,   180,    12,   238,   178,   180,   178,   178,   178,
     178,   178,   178,   178,   178,   184,   184,   202,    46,   267,
     177,   180,   177,   178,   284,    71,   180,   178,   178,   222,
     231,   202,   235,   202,    45,   271,   184,   262,   199,   202,
     202,   286,   199,   199,   202,   184,   184,   178,   269,    13,
      15,    17,    40,    43,    48,   263,   178,   180,   178,   180,
     272,    24,    43,   223,   236,   184,   199,   202,    13,    15,
      17,    40,    43,    48,   237,   270,   178,   178,     4,   239,
     268
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
     208,   208,   208,   208,   208,   208,   208,   208,   208,   209,
     209,   209,   210,   210,   210,   211,   211,   212,   212,   212,
     212,   213,   214,   216,   215,   217,   217,   217,   218,   218,
     220,   221,   222,   219,   223,   223,   224,   224,   225,   225,
     225,   225,   226,   226,   227,   227,   227,   227,   228,   228,
     229,   229,   229,   229,   230,   230,   230,   231,   231,   231,
     231,   233,   234,   235,   236,   232,   237,   237,   237,   237,
     237,   237,   238,   238,   239,   239,   241,   240,   242,   242,
     243,   243,   244,   245,   244,   246,   247,   246,   249,   248,
     250,   250,   250,   250,   250,   250,   252,   253,   251,   254,
     254,   256,   255,   257,   257,   257,   257,   257,   257,   259,
     260,   261,   262,   258,   263,   263,   263,   263,   263,   263,
     265,   264,   266,   266,   267,   267,   268,   269,   270,   268,
     271,   271,   272,   273,   272,   274,   274,   274,   274,   275,
     275,   276,   276,   276,   276,   277,   277,   277,   277,   278,
     278,   278,   278,   278,   279,   279,   279,   281,   280,   282,
     280,   283,   280,   284,   280,   285,   280,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   288,   288,   289,   289,   290,   290
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
       4,     4,     4,     4,     4,     4,     4,     4,     6,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     3,     3,     0,     4,     0,
       4,     2,     3,     3,     3,     3,     3,     3,     4,     6,
       1,     4,     4,     6,     6,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     4,     8,
       4,     4,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     6,     6,     6,     4,     8,     6,
       8,     6,     4,     4,     4,     6,     6,     6,     8,     1,
       2,     2,     1,     1,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     0,     2,     0,     1,     3,     1,     1,
       0,     0,     0,    11,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     3,     1,     1,     4,     4,     1,     3,
       1,     1,     4,     4,     0,     1,     3,     1,     1,     3,
       3,     0,     0,     0,     0,    14,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     1,     0,     7,     1,     2,
       1,     1,     0,     0,     5,     0,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     0,     6,     1,
       1,     0,     4,     1,     2,     1,     1,     1,     1,     0,
       0,     0,     0,    11,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     1,     0,     2,     0,     0,     0,     7,
       0,     1,     1,     0,     4,     1,     4,     1,     4,     1,
       3,     1,     4,     1,     4,     1,     1,     3,     3,     0,
       2,     4,     1,     3,     0,     2,     6,     0,     4,     0,
       4,     0,     6,     0,     9,     0,     3,     0,     1,     0,
       2,     2,     4,     1,     4,     6,     6,     7,    10,    12,
       7,    10,    12,     2,     1,     1,     3,     1,     3
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

    {create_function(fFRNFN_SIZE);}

    break;

  case 249:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 250:

    {create_function(fPEEK4);}

    break;

  case 251:

    {create_function(fPEEK);}

    break;

  case 252:

    {create_function(fMOUSEX);}

    break;

  case 253:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 255:

    {create_function(fMOUSEY);}

    break;

  case 256:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 258:

    {create_function(fMOUSEB);}

    break;

  case 259:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 261:

    {create_function(fMOUSEMOD);}

    break;

  case 262:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 263:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 264:

    {create_function(fAND);}

    break;

  case 265:

    {create_function(fOR);}

    break;

  case 266:

    {create_function(fEOR);}

    break;

  case 267:

    {create_function(fTELL);}

    break;

  case 268:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 269:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 270:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 271:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 272:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 273:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 274:

    {create_myopen(0);}

    break;

  case 275:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 276:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 277:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 278:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 279:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 280:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 281:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 282:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 283:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 284:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 285:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 286:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 287:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 288:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 289:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 290:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 291:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 292:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 293:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 300:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 301:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 302:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 303:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 304:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 305:

    {missing_endsub--;}

    break;

  case 306:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 307:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 308:

    {exported=FALSE;}

    break;

  case 309:

    {exported=TRUE;}

    break;

  case 310:

    {exported=FALSE;}

    break;

  case 311:

    {exported=TRUE;}

    break;

  case 314:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 315:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 316:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 317:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 320:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 321:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 322:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 323:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 327:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 328:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 329:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 330:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 331:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 332:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 333:

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

  case 334:

    {
             swap();popgoto();poplabel();}

    break;

  case 335:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 336:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 337:

    {missing_next--;}

    break;

  case 338:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 339:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 340:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 341:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 342:

    {create_pushdbl(1);}

    break;

  case 344:

    {pop(stSTRING);}

    break;

  case 345:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 346:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 347:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 353:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 354:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 356:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 358:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 360:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 361:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 362:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 363:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 364:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 365:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 366:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 367:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 369:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 370:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 371:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 373:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 374:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 375:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 376:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 377:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 378:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 379:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 380:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 381:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 382:

    {poplabel();}

    break;

  case 384:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 385:

    {missing_endif--;}

    break;

  case 386:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 387:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 388:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 389:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 390:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 392:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 393:

    {poplabel();}

    break;

  case 397:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 398:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 403:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 405:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 406:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 407:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 408:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 411:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 412:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 413:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 414:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 415:

    {create_strdata((yyvsp[0].string));}

    break;

  case 416:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 417:

    {create_strdata((yyvsp[0].string));}

    break;

  case 418:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 422:

    {create_print('s');}

    break;

  case 423:

    {create_print('s');}

    break;

  case 424:

    {create_print('d');}

    break;

  case 425:

    {create_print('u');}

    break;

  case 426:

    {create_print('U');}

    break;

  case 427:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 428:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 429:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 430:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 431:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 432:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 433:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 434:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 435:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 436:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 437:

    {create_pushstr("?");create_print('s');}

    break;

  case 438:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 439:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 440:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 451:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 455:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 456:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 457:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 458:

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
