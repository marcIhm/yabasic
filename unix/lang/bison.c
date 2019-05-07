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
    tFGNST_NEW = 413,
    tFGNST_FREE = 414,
    tFGNST_DUMP = 415,
    tFGNST_SET = 416,
    tFGNST_GET = 417,
    tDATE = 418,
    tTIME = 419,
    tTOKEN = 420,
    tTOKENALT = 421,
    tSPLIT = 422,
    tSPLITALT = 423,
    tGLOB = 424,
    UMINUS = 425
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
#define YYFINAL  261
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  180
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  455
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1070

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   425

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   179,     2,     2,     2,     2,
     175,   176,   172,   171,   178,   170,     2,   173,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   177,
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
     165,   166,   167,   168,   169,   174
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
     291,   292,   293,   294,   295,   296,   297,   298,   299,   303,
     304,   305,   306,   307,   311,   312,   313,   314,   315,   316,
     319,   320,   323,   324,   325,   326,   327,   330,   331,   334,
     335,   338,   339,   340,   341,   342,   343,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   384,   385,   388,   388,   389,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   422,
     425,   428,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   497,   498,   499,   502,
     503,   504,   507,   508,   511,   512,   513,   514,   517,   520,
     523,   523,   526,   527,   528,   531,   532,   535,   536,   539,
     535,   544,   545,   548,   549,   552,   553,   554,   555,   558,
     559,   562,   563,   564,   565,   568,   569,   572,   573,   574,
     575,   578,   579,   580,   583,   584,   585,   586,   589,   590,
     594,   608,   589,   613,   614,   615,   616,   617,   618,   621,
     622,   625,   626,   631,   631,   635,   636,   639,   640,   644,
     646,   645,   650,   651,   651,   655,   655,   661,   662,   663,
     664,   665,   666,   670,   671,   670,   677,   678,   682,   682,
     687,   688,   689,   690,   691,   692,   695,   696,   696,   698,
     695,   702,   703,   704,   705,   706,   707,   710,   710,   715,
     716,   719,   720,   723,   725,   727,   724,   731,   732,   735,
     736,   736,   739,   740,   742,   743,   747,   748,   751,   752,
     754,   755,   759,   760,   761,   762,   765,   766,   767,   768,
     769,   772,   773,   774,   777,   777,   778,   778,   779,   779,
     780,   780,   781,   781,   784,   785,   788,   789,   790,   791,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     804,   805,   807,   808,   811,   812
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
  "tFGNFN_CALL", "tFGNFN_CALL2", "tFGNST_NEW", "tFGNST_FREE",
  "tFGNST_DUMP", "tFGNST_SET", "tFGNST_GET", "tDATE", "tTIME", "tTOKEN",
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
      45,    43,    42,    47,   425,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -753

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-753)))

#define YYTABLE_NINF -377

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3861,   -57,   -56,  -753,  -753,  -753,  -753,  -753,    68,    68,
      68,  2931,  -753,  -753,  -753,  3470,  -136,  -126,  3470,    30,
      56,  -753,  -753,  -753,  3269,   -27,  -753,  3269,   389,  -753,
    3269,  3269,  3269,   400,    44,    68,  1733,  1143,  2071,    -9,
    3269,  2762,  3269,     9,   -19,  3269,  -753,    36,  3470,  3470,
    3470,    10,   -70,   -47,    22,    32,    48,  2071,  3470,  3470,
     173,   149,  -753,   -43,  -753,  -753,  -753,  -753,   140,   163,
    -753,   222,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  3269,
    -753,  3470,  -753,   273,  3269,  3717,  -753,  -753,  -753,  -753,
    -753,  -753,   129,   159,  -753,  -753,  -753,   177,   180,   436,
     194,   204,  3269,   207,   241,   245,   264,   270,   299,   313,
     355,   364,   380,   398,   409,   431,   437,   441,   460,   469,
     494,   497,   498,   507,   510,   518,   534,   535,   543,   548,
     551,   556,   557,   558,   562,   564,   568,   569,   570,   571,
     575,   576,   580,   582,   583,   589,   592,   594,   596,   597,
     598,   601,   606,   607,   608,   609,   614,   615,   617,   619,
     620,   622,   623,   632,   636,   637,   638,   644,   647,   649,
     650,  3269,  3269,   199,  -753,   361,  -753,  -753,  -753,  -753,
     482,   493,  3470,   143,  -753,  -753,   143,  -753,  -753,  3269,
    3717,   276,   657,   263,   658,    24,  3269,   -28,   199,   925,
     663,   666,   146,   925,   199,   453,   199,   478,   667,   668,
     240,  -753,  -753,   124,   124,  -753,  -753,   279,  -753,  3269,
    3470,  3269,    87,   925,   481,  -753,  -753,  -753,  -753,   511,
    3470,   508,  -753,  3269,  -753,    -1,   546,  -753,  -753,  3269,
    3100,  -753,  -753,   925,  -753,  -753,   140,   163,   143,    -6,
      -6,  -753,   446,   446,   446,  2240,  3470,   423,   625,  -116,
     -86,  -753,  -753,   802,  3269,  3269,  3269,  3269,  3470,  -753,
     925,   670,  3269,   143,   673,   749,   925,   425,  -753,  -753,
    -753,  -753,  3269,  3269,   909,  3269,  1902,  2071,   503,   503,
    3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    3269,  3269,  2071,  3269,  3269,  3269,  3269,  3269,  3269,  3269,
    2414,  3470,  3470,  3470,  3470,  3470,  3269,  3269,  3269,  2588,
    3269,  3470,  3269,  3470,  3269,  3470,  3470,   602,  1316,  1428,
    1508,  3470,  3470,  3470,  3470,  3470,  3470,  3470,  3470,  2071,
    3470,  -753,  -753,  3470,  3470,  3470,   677,   679,  3470,   446,
    3470,   446,  3470,   785,    13,   859,  3470,  3470,  3470,  3470,
    3470,  3470,  3470,  -753,  -753,  -753,  -753,  3269,  3269,  3269,
    3269,  3269,  3269,  3269,  3269,  3269,  3269,  3269,   683,   686,
     688,  -753,   692,   693,   691,  -753,  -110,   694,   695,   199,
     925,   830,   628,   829,  3717,  3269,   700,  3470,  -753,  -753,
    3269,   199,   340,   349,   701,    31,  -753,   869,  -753,  -753,
     513,  3269,  3269,  -753,  -753,   400,  -753,  -753,    51,  1336,
     143,   925,   447,  1619,  3269,   143,  3269,  -753,   -28,  -753,
    -753,  3269,  3470,  -753,  3269,    -1,  3269,  3269,   705,   703,
     706,   707,  -753,  4249,     4,  3269,  3269,  3470,  3470,  3717,
     708,    -1,    -1,   925,   143,   538,  -753,   199,   925,   711,
    -753,  -753,  -753,  3717,  -753,  -753,  3269,  -753,  -753,  -753,
    -753,   714,   715,  1917,  2086,  2255,   718,   414,   719,   720,
     723,   724,   725,   727,   722,   729,    -1,  2429,  4274,  4321,
    4332,  4343,  4361,   645,  4386,   843,  4397,  4408,   732,  4455,
    4473,  4520,  4531,  4542,  4567,  2606,  -753,  4585,    41,   -12,
      -4,     5,    71,  2777,  2946,   885,  -753,  4596,  4607,   102,
    4654,    57,  4679,   161,   178,  -753,   212,  -753,   246,  -753,
     283,  -753,   324,   325,   328,   338,     8,    17,   382,   393,
     410,    42,   740,    65,   741,   742,    38,    75,   141,  -753,
    -753,   145,   -89,   162,   -75,   214,  -753,  -753,   143,   143,
     143,   143,   143,   143,  -753,    68,    68,  3269,  3269,   629,
     466,   793,   549,    -2,   130,  -753,   -30,   -30,   785,   785,
    -753,  -753,   482,  -753,  -753,   493,  -753,  -753,  -753,   841,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,   514,  3115,
    3269,    81,  4719,  3551,  -753,  -753,  3269,  3269,  -753,  -753,
    3269,  -753,   547,   743,   744,   748,   758,  3284,  3469,   759,
     760,  -753,  -753,  -753,  3269,   854,   857,  -753,   220,  3770,
     925,  -753,  -753,   266,  -753,  3269,  3914,  4001,  -753,  3269,
    3269,  3269,  -753,  -753,   199,   925,   199,   925,   143,   282,
    -753,  3269,  3269,  3269,  -753,  -753,  -753,  3269,  3269,    21,
     925,  -753,  -753,  3269,  3269,  3269,  -753,  -753,  3470,  3419,
    -753,   762,   763,  -753,  -753,  3269,  3269,  3269,  3269,  -753,
    -753,  -753,  -753,  -753,  -753,  3269,  -753,  -753,  3269,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  3269,  -753,
    -753,  3269,  3269,  3269,  -753,  3269,  3269,  -753,  3470,  -753,
    -753,  -753,  -753,  -753,  3269,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  3470,  3470,  -753,  -753,  -753,
    -753,  -753,  -753,  3470,  -753,  -753,  3269,  3470,  3269,   935,
    -753,  3470,   935,  -753,  3470,  3470,  -753,   764,  -753,   766,
     909,  1268,   765,   769,  -753,   773,   782,  -753,  -753,   527,
    3717,  -753,  -753,  -753,  3269,  4048,   905,  3470,  -753,  3470,
     143,   199,   340,  4073,   547,   547,  4730,   798,   807,  -753,
     790,  -753,  -753,  -753,  -753,  3269,  3269,  -753,  -753,  4114,
    2071,  2071,  3470,  3470,  3470,  -753,  3269,  3269,   808,  4741,
    4766,  1006,  3269,   925,    -1,  -753,   810,  -753,    67,  -753,
    -753,  -753,  4791,  4802,  4813,   411,   813,   139,  -753,  -753,
    4853,  4878,   814,    54,  4925,  4936,  4947,  4965,  4990,  1323,
    5001,  5012,   151,  5059,   243,   265,   412,  5077,   422,  4125,
     -74,   426,    84,   432,   433,    68,    68,  -753,  -753,  -753,
    -753,  3269,   957,   965,   961,  5124,  3269,   831,   434,   291,
    -753,  3269,  -753,  -753,  -753,  -753,  -753,  -753,   828,   834,
     925,   925,  3470,  -753,  -753,   143,   143,   285,  4136,   925,
    -753,   936,   941,   946,  3269,  4161,  3269,   610,  3269,  -753,
    -753,  -753,  -753,  -753,  -753,  3470,  -753,  -753,  -753,  3269,
    -753,  -753,  -753,  -753,  -753,  -753,  3269,  -753,  -753,  -753,
    3470,  -753,  -753,  3269,  -753,  3269,  -753,  -753,  -753,  3470,
    -753,  3470,  -753,  -753,  3470,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,   971,   574,  5135,  3269,   967,  3470,  5146,   547,
     850,   851,   547,  -753,  -753,   143,  3470,  3470,  3470,  3470,
    3470,  5171,  3470,  -753,   853,   858,   175,  -753,    78,   451,
    4186,  5189,   484,  5200,  5211,   486,   487,   490,  3717,  4005,
    3269,   990,  -753,   864,  -753,  4197,   866,   499,  -753,  -753,
    -753,  -753,  -753,   143,   143,   143,   143,   143,   972,   301,
     868,   871,  -753,   610,  3269,  -753,  -753,  3269,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,   961,  1005,   305,  3717,  -753,
    3470,  3269,  3269,  -753,   869,  3470,  3269,  -753,  -753,  3717,
    -753,   925,  3717,  5258,  -753,  -753,   961,   791,   383,  5283,
    4208,   547,   143,   925,     0,   961,  -753,  3717,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  3470,  -753,  3269,  -753,
    -753,  -753,  -753,   839,   961,   512,  5323,  -753,  -753,  -753,
    -753,  -753,  -753,  1041,   971,  -753,  -753,  -753,  -753,  -753
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     109,     0,     0,   105,   328,   363,   368,    11,     0,     0,
       0,     0,    24,    26,   306,     0,     0,     0,     0,   307,
      18,    20,   343,   355,     0,   436,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   110,   111,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     4,     3,     0,     7,    39,    41,     9,    22,    23,
      21,     0,    13,    14,    17,    16,    15,    28,    29,     0,
     290,     0,   290,     0,     0,     6,   283,   282,    30,    31,
      38,   279,   194,   131,   280,   281,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,   250,   253,   256,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   160,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,   207,   188,   193,   133,
       0,     0,     0,    12,   290,   290,    42,   308,    19,     0,
       6,   387,     0,   440,     0,     0,   416,   432,    62,    61,
       0,     0,    63,   104,    53,     0,    55,     0,   408,   410,
      56,   406,   412,     0,     0,   413,   276,    57,    59,     0,
      89,     0,     0,   451,     0,    86,    91,    79,    40,     0,
       0,     0,    67,     0,    50,    72,     0,    88,    87,     0,
       0,   112,   113,    92,     8,    10,     0,     0,   106,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,   297,
     173,     0,   292,   114,     0,     0,   364,     4,   290,   290,
      32,    33,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    36,   177,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   311,   312,
      25,   309,   317,   318,    27,   315,     0,     0,     0,   348,
     347,     0,     4,     0,     6,     0,     0,     0,   437,   438,
       0,   419,   421,    45,     0,     0,    49,   434,   290,   290,
       0,     0,     0,   290,   290,     0,   278,   277,     0,     0,
      90,   450,     0,     0,     0,    66,     0,    71,   432,   121,
     120,     0,     0,    68,     0,    74,     0,     0,   129,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,   174,   119,     0,   288,   295,   296,   291,
     293,   289,   329,     6,   375,   373,     0,   374,   370,   372,
     369,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,   254,     0,   257,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     161,     0,     0,     0,     0,     0,   136,   208,   202,   204,
     206,   203,   205,   201,   135,     0,     0,     0,     0,   181,
     183,   185,   182,   184,   180,   199,   196,   195,   197,   198,
     290,   290,     0,   290,   290,     0,    43,    44,   345,   349,
     362,   360,   361,   358,   357,   359,   356,   377,     4,     0,
       0,     0,     0,     0,   417,    46,    47,     0,   424,   426,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   407,   414,   415,     0,     0,     0,   124,   123,   127,
     211,    51,    69,    82,    73,     0,     0,     0,   290,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   107,     0,
       5,     0,     0,     0,   303,   304,   298,     0,     0,     4,
     371,   269,   172,     0,     0,     0,   270,   271,     0,     0,
     264,     0,     0,   189,   190,     0,     0,     0,     0,   212,
     213,   214,   215,   216,   217,     0,   219,   220,     0,   222,
     223,   186,   228,   229,   224,   225,   226,   227,     0,   231,
     236,     0,     0,     0,   235,     0,     0,   141,     0,   146,
     147,   237,   170,   238,     0,   171,   148,   149,   249,   252,
     255,   258,   152,   150,   151,     0,     0,   153,   244,   154,
     248,   247,   162,     0,   245,   155,     0,     0,     0,     0,
     165,     0,     0,   167,     0,     0,   452,    35,   454,    37,
     178,   176,     0,     0,   310,     0,     0,   316,   346,   352,
       6,   389,   390,   388,     0,     0,   441,     0,   439,     0,
     422,   420,   421,     0,     0,     0,     0,   402,   404,   433,
     399,   284,   286,   290,   290,     0,     0,   409,   411,    64,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    85,     0,   294,     0,   367,
     366,   365,     0,     0,     0,     0,     0,     0,   209,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   314,   319,
     320,     0,     0,     0,   378,     0,     0,     0,     0,     0,
     418,     0,   425,   427,   428,   290,   290,   400,     0,     0,
      52,    54,     0,   125,   126,   122,   128,    83,    76,    77,
     130,     0,     0,     0,     0,     0,     0,   321,     0,   261,
     262,   263,   272,   273,   274,     0,   191,   192,   168,     0,
     218,   221,   230,   137,   138,   140,     0,   233,   234,   142,
       0,   239,   240,     0,   242,     0,   163,   156,   157,     0,
     266,     0,   164,   268,     0,   166,   187,   453,   455,   350,
     353,   344,   393,   443,     0,     0,   442,     0,     0,     0,
       0,     0,     0,   285,   287,    65,     0,     0,     0,     0,
       0,     0,     0,    81,   324,   325,     0,   322,   339,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,   109,
       0,   391,   447,     0,   444,     0,     0,     0,   430,   429,
     403,   405,   401,    84,    75,   117,   118,   116,     0,     0,
       0,     0,   299,     0,     0,   330,   275,     0,   139,   143,
     241,   243,   246,   265,   267,   351,     4,   397,     6,   379,
       0,     0,     0,   423,   434,     0,     0,   326,   327,     6,
     323,   340,     6,     0,   398,   394,   392,     0,     0,     0,
       0,     0,   115,   108,     4,   331,   169,     6,   386,   383,
     384,   385,   381,   382,   380,   448,     0,   445,     0,   431,
     302,   301,   300,     0,   395,     0,     0,   334,   336,   337,
     338,   333,   335,   341,   393,   449,   446,   342,   332,   396
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -753,  -753,   -76,  -753,   599,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  1002,  -232,  -753,  -753,  -155,   778,  -753,  1004,
     -11,  -753,  -753,   770,  -281,   -35,  -753,   634,   -32,     2,
    -753,     1,     3,   -78,  -753,  -753,   396,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,   472,  -753,   475,  -753,    69,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,   215,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,     6,  -753,  -753,  -753,
    -752,  -753,  -753,  -753,   652,  -753,  -753,   293,   643,  -753,
    -753,  -753,  -753,  -753,    70,  -753,    39,  -753,  -753
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    60,    61,   263,    62,   180,   181,   565,   566,   197,
     428,    63,    64,   431,    65,    66,   439,   173,   174,    67,
     231,   568,   567,   482,   483,   232,   176,   215,   177,    88,
     202,   178,   179,   271,   272,   459,   460,    70,   455,   806,
    1019,  1052,   656,    71,   380,   381,   384,   385,   956,   957,
      72,    83,   658,  1022,  1053,  1063,   995,  1068,    73,   189,
     589,   391,   759,   968,   853,   969,    74,   190,   596,    75,
      84,   463,   811,    76,    85,   470,    77,   393,   760,   932,
    1027,  1044,    78,   394,   763,  1009,   971,  1037,  1064,  1025,
     779,   942,   780,   210,   211,   217,   403,   604,   406,   774,
     775,   939,  1014,   407,   612,   196,   224,   747,   749
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     175,    68,   216,    69,   274,   429,   235,   236,   485,   277,
     429,    89,    90,   191,    79,    81,   199,   436,   437,   203,
     205,   207,   862,   863,  1050,   223,   223,   223,   398,   404,
     192,   399,   193,   194,   243,   608,   809,   218,   609,   184,
       1,     2,   373,  1051,   264,   265,   223,    91,   246,   185,
     247,    94,    95,   212,    91,   362,   266,   187,    94,    95,
     622,   362,   447,   188,   810,   429,   556,   237,   270,   372,
     373,   242,    86,   276,   230,    87,   228,   229,   888,   356,
     357,   358,   359,   360,   361,   362,    68,   740,    69,   741,
     994,   284,   448,   238,   239,   240,   258,   422,   440,   441,
     241,   743,   920,   744,   921,   252,   387,   388,   356,   357,
     358,   359,   360,   361,   392,   251,   365,   366,    80,    82,
     367,   368,   369,   370,   371,   372,   373,    91,   253,   365,
     366,    94,    95,   367,   368,   369,   370,   371,   372,   373,
     365,   366,   376,   377,   367,   368,   369,   370,   371,   372,
     373,   405,   195,   356,   357,   358,   359,   360,   361,   362,
     353,   355,    52,    53,    54,   362,   701,   362,   374,   375,
     376,   377,   430,   261,   702,   362,   362,   430,   390,   362,
     643,   416,   417,   703,   362,   402,   725,   979,   362,   556,
     982,    68,   262,    69,   552,   726,   554,   254,   427,   400,
     471,   472,   373,   635,   433,   435,   610,   255,   419,   362,
     421,   267,   362,   362,   213,   214,   736,   700,   730,   652,
     653,   213,   214,   256,   374,   375,   376,   377,   362,   450,
     451,   452,   430,   713,   268,   714,   362,   374,   375,   376,
     377,   732,   362,   733,   443,   269,   362,   704,   374,   375,
     376,   377,   362,   737,   677,   486,   453,   766,   362,   767,
     923,   458,   924,   544,   545,   356,   357,   358,   359,   360,
     361,   473,   474,   362,   475,   223,   223,   275,   711,  1049,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   223,   499,   500,   501,   502,   503,   504,   505,   507,
     374,   375,   376,   377,    80,   513,   514,   515,   517,   518,
     362,   520,   362,   522,   362,   894,   362,   895,   598,   738,
     396,  -376,   362,   739,   410,   478,   479,   909,   223,   910,
     613,   614,   362,   362,    82,   619,   620,   716,   365,   366,
     742,   498,   367,   368,   369,   370,   371,   372,   373,   362,
    1024,   992,   278,   993,   717,   279,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   365,   366,   282,
     362,   367,   368,   369,   370,   371,   372,   373,   542,   283,
     363,   364,   285,   362,   599,   362,   216,   659,   718,   602,
     603,   362,   745,   200,   201,    68,   632,    69,   792,   634,
     617,   618,   365,   366,   208,   209,   367,   368,   369,   370,
     371,   372,   373,   629,   362,   630,   286,   362,   415,   912,
     287,   913,   719,   365,   366,   636,   637,   367,   368,   369,
     370,   371,   372,   373,   645,   647,   362,   362,   464,   288,
     465,   914,   466,   915,   794,   289,   374,   375,   376,   377,
      68,   438,    69,   362,   362,   660,   362,   418,   840,   720,
     802,   842,   362,   946,    68,   467,    69,   556,   468,   937,
     280,   281,   362,   469,   290,   374,   375,   376,   377,  1016,
     356,   357,   358,   359,   360,   361,   378,   379,   291,   356,
     357,   358,   359,   360,   361,   362,   362,   382,   383,   362,
     721,   722,   752,   753,   723,   755,   756,   480,   481,   362,
     374,   375,   376,   377,   724,   365,   366,   615,   616,   367,
     368,   369,   370,   371,   372,   373,   605,   606,   625,   626,
     292,   374,   375,   376,   377,   370,   371,   372,   373,   293,
     365,   366,   654,   655,   367,   368,   369,   370,   371,   372,
     373,   777,   778,   362,   362,   294,   750,   751,   727,  1045,
     798,  1046,   761,   762,   362,   851,   852,   746,   748,   728,
     365,   366,   886,   295,   367,   368,   369,   370,   371,   372,
     373,   362,   362,   362,   296,   362,   729,   892,   916,   765,
     667,   899,   668,   362,   362,   772,   773,   362,   918,   776,
     795,   445,   922,   362,   362,   362,   297,    93,   925,   926,
     936,    96,   298,   789,   954,   955,   299,   804,   805,   371,
     372,   373,   362,   374,   375,   376,   377,   996,   799,   800,
     801,   411,    98,   972,   973,   300,   374,   375,   376,   377,
     803,   590,   822,   591,   301,   592,   458,   808,   374,   375,
     376,   377,   812,   813,   814,   362,   412,   362,   362,   423,
     999,   362,  1002,  1003,   820,   821,  1004,   823,   593,   302,
     362,   594,   303,   304,   824,  1013,   595,   825,   374,   375,
     376,   377,   305,   362,   854,   306,   426,   826,  1065,   424,
     827,   828,   829,   307,   830,   831,   368,   369,   370,   371,
     372,   373,   108,   833,   109,   868,   869,   365,   366,   308,
     309,   367,   368,   369,   370,   371,   372,   373,   310,   374,
     375,   376,   377,   311,   432,   837,   312,   839,   130,   131,
     132,   313,   314,   315,   136,   137,   138,   316,   140,   317,
     142,   143,   144,   318,   319,   320,   321,   149,   150,   151,
     322,   323,   154,   855,   156,   324,   158,   325,   326,   160,
     161,    68,   162,    69,   327,   164,   165,   328,   167,   329,
     169,   330,   331,   332,   870,   871,   333,   182,   525,   223,
     223,   334,   335,   336,   337,   878,   879,   940,   941,   338,
     339,   885,   340,   183,   341,   342,   186,   343,   344,   374,
     375,   376,   377,   446,  1038,   198,  1039,   345,  1040,   204,
     206,   346,   347,   348,   222,   374,   375,   376,   377,   349,
     462,   684,   350,   685,   351,   352,   248,   249,   250,   873,
     874,  1041,   395,   397,  1042,   257,   259,   260,   408,  1043,
     390,   409,   413,   414,   449,   934,   456,   927,   928,   461,
     938,   953,  1057,   549,  1058,   550,  1059,   373,   580,   273,
     368,   581,   370,   371,   372,   373,   582,   583,   584,   585,
     586,   587,   588,   951,   597,   600,   607,   958,   611,  1060,
     638,   639,  1061,   758,   640,   641,   651,  1062,   960,   657,
     661,   662,  1005,  1006,   666,   961,   670,   669,   671,   672,
     675,   673,   963,   674,   964,   365,   366,   676,   691,   367,
     368,   369,   370,   371,   372,   373,   731,   734,   735,   781,
     782,   365,   366,   783,   975,   367,   368,   369,   370,   371,
     372,   373,  1026,   784,   790,   787,   788,   791,   818,   819,
     481,   847,   845,  1034,   846,   848,  1035,   365,   366,   849,
     354,   367,   368,   369,   370,   371,   372,   373,   850,  1007,
     386,  1054,   857,   374,   375,   376,   377,   389,   867,    68,
      68,    69,    69,   865,   401,   367,   368,   369,   370,   371,
     372,   373,   866,  1021,   880,   887,  1023,   365,   366,   893,
     898,   367,   368,   369,   370,   371,   372,   373,   420,   930,
    1029,  1030,   931,    -4,   943,  1033,   935,   948,   425,    68,
     944,    69,   949,   374,   375,   376,   377,   950,   970,   687,
      68,   688,    69,    68,   976,    69,   980,   981,   990,   374,
     375,   376,   377,   991,   444,   557,  1008,  1056,    68,  1010,
      69,  1012,  -354,  1015,  1017,  1067,   454,  1018,   650,   244,
     457,   245,   623,   807,   754,   374,   375,   376,   377,   484,
     757,   707,  1020,   708,   477,   860,   929,   621,   365,   366,
    1069,   631,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,     0,  1031,     0,     0,     0,     0,   508,
     509,   510,   511,   512,     0,   374,   375,   376,   377,   519,
       0,   521,     0,   523,   524,   526,   528,   530,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   543,     0,
       0,   546,   547,   548,     0,     0,   551,     0,   553,     0,
     555,     0,     0,     0,   558,   559,   560,   561,   562,   563,
     564,     0,     0,     0,     0,     0,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,   601,   374,   375,   376,   377,
       0,     0,   883,     0,   884,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   628,     0,     0,     0,   100,   101,   102,   103,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,   644,   646,   648,   649,   225,     0,     0,
       0,     0,     0,     0,     0,   226,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,   227,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,     0,   162,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,     0,     0,   172,     0,
       0,    93,   221,     0,     0,    96,     0,     0,     0,     0,
     365,     0,     0,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   770,     0,     0,   771,   365,   366,     0,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,   457,     0,    96,   374,   375,
     376,   377,   130,   131,   132,     0,   815,   817,   136,   137,
     138,     0,   140,     0,   142,   143,   144,     0,    98,     0,
       0,   149,   150,   151,     0,     0,   154,     0,   156,     0,
     158,     0,     0,   160,   161,     0,   162,     0,     0,   164,
     165,     0,   167,     0,   169,     0,   832,     0,     0,     0,
       0,   182,   527,   374,   375,   376,   377,     0,     0,   905,
       0,   906,     0,   834,   835,     0,   374,   375,   376,   377,
       0,   836,     0,    93,   624,   838,     0,    96,     0,   841,
       0,     0,   843,   844,     0,     0,     0,     0,   108,     0,
     109,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,   858,     0,   859,     0,     0,
       0,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
     875,   876,   877,   149,   150,   151,     0,     0,   154,     0,
     156,     0,   158,     0,     0,   160,   161,     0,   162,     0,
       0,   164,   165,     0,   167,     0,   169,     0,     0,     0,
       0,     0,     0,   182,   529,     0,     0,     0,   108,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,    96,   389,
       0,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,    98,
     945,     0,     0,   149,   150,   151,     0,     0,   154,     0,
     156,     0,   158,     0,     0,   160,   161,     0,   162,     0,
       0,   164,   165,   959,   167,     0,   169,     0,     0,     0,
       0,     0,     0,   182,   531,     0,     0,     0,   962,     0,
       0,     0,     0,     0,     0,     0,     0,   965,     0,   966,
       0,     0,   967,     0,     0,     0,     0,     0,     0,     0,
       0,   627,     0,     0,     0,   977,     0,     0,     0,   108,
       0,   109,     0,     0,   983,   984,   985,   986,   987,     0,
     989,     0,     0,     0,     0,     0,    91,    92,    93,     0,
      94,    95,    96,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,    97,    98,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,   161,     0,   162,
       0,     0,   164,   165,     0,   167,     0,   169,  1028,     0,
       0,     0,     0,  1032,   182,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,  1055,   220,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,     0,   162,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,    91,    92,    93,   172,    94,
      95,    96,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   365,
     366,   105,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,   476,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,     0,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,    91,    92,    93,   172,    94,    95,
      96,   221,     0,     0,     0,     0,     0,   374,   375,   376,
     377,     0,     0,     0,     0,   663,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   365,   366,
     105,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
       0,   162,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,    91,    92,    93,   172,    94,    95,    96,
     221,     0,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,     0,     0,   664,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   365,   366,   105,
       0,   367,   368,   369,   370,   371,   372,   373,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,     0,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,   172,   442,    91,    92,    93,
       0,    94,    95,    96,     0,   374,   375,   376,   377,     0,
       0,     0,     0,   665,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   365,   366,   105,     0,   367,   368,   369,   370,   371,
     372,   373,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,     0,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,   172,
     506,    91,    92,    93,     0,    94,    95,    96,     0,   374,
     375,   376,   377,     0,     0,     0,     0,   678,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,   105,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,   106,   107,     0,     0,   108,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,     0,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
       0,     0,     0,   172,   516,    91,    92,    93,     0,    94,
      95,    96,     0,   233,     0,     0,   374,   375,   376,   377,
       0,     0,     0,     0,   698,     0,     0,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   365,
     366,   105,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,     0,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,     0,    91,    92,    93,   172,    94,    95,
      96,     0,     0,     0,     0,     0,     0,   374,   375,   376,
     377,     0,     0,     0,     0,   705,     0,     0,     0,     0,
      97,    98,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   365,   366,
     105,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,   108,     0,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
       0,   162,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,    91,    92,    93,   172,    94,    95,    96,
       0,   434,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,     0,     0,   706,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   365,   366,   105,
       0,   367,   368,   369,   370,   371,   372,   373,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,     0,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,     0,    91,    92,    93,   172,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   374,   375,   376,   377,     0,
       0,     0,     0,   764,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   365,   366,   105,     0,
     367,   368,   369,   370,   371,   372,   373,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    93,   159,   160,   161,    96,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,   172,     0,     0,     0,     0,    98,
       0,     0,     0,     0,   374,   375,   376,   377,     0,     0,
       0,     0,   785,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   816,     0,     0,     0,     0,     0,     0,     0,   108,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,   366,     0,     0,   367,   368,   369,   370,   371,
     372,   373,     0,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,    93,   142,   143,   144,
      96,     0,     0,     0,   149,   150,   151,     0,     0,   154,
     108,   156,   109,   158,     0,     0,   160,   161,     0,   162,
       0,    98,   164,   165,     0,   167,     0,   169,     0,     0,
       0,     0,     0,     0,   182,     0,   130,   131,   132,     0,
       0,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,     0,     0,
     154,     0,   156,     0,   158,     0,     0,   160,   161,     0,
     162,     0,     0,   164,   165,     0,   167,     0,   169,   374,
     375,   376,   377,     0,     0,   182,     0,   786,     0,     0,
       0,   108,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,     0,     0,     0,   149,   150,   151,     0,
       0,   154,     0,   156,     0,   158,     0,     0,   160,   161,
       0,   162,     0,     0,   164,   165,     0,   167,     0,   169,
       0,     1,     2,     3,     0,     0,   769,     4,     0,     0,
       0,     5,     0,     6,     0,     7,     8,     9,    10,    11,
    -305,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,     0,     0,     0,     0,    23,     0,
       0,    24,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,    39,    40,    41,  -109,  -109,    42,    43,    44,     0,
      45,    46,    47,     0,     0,    48,  -109,     0,    49,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   365,   366,     0,     0,   367,   368,   369,   370,
     371,   372,   373,    52,    53,    54,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,    56,     0,
       0,     4,    57,     0,     0,     5,    58,     6,    59,     7,
       8,     9,    10,    11,  -305,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,     0,     0,
       0,     0,    23,    -6,    -6,    24,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
     374,   375,   376,   377,     0,    39,    40,    41,   793,     0,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
       0,     0,    49,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,   366,     0,     0,
     367,   368,   369,   370,   371,   372,   373,    52,    53,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,    56,     0,     0,     4,    57,     0,     0,     5,
      58,     6,    59,     7,     8,     9,    10,    11,  -305,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    -6,     0,     0,     0,    23,    -6,     0,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,     0,   365,   366,    31,    32,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,   374,   375,   376,   377,     0,    39,
      40,    41,   796,     0,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,     0,     0,    49,     0,    50,    51,
     365,   366,     0,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,   365,   366,     0,    55,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      57,     0,     0,     0,    58,     0,    59,     0,     0,     0,
       0,   374,   375,   376,   377,     0,   365,   366,     0,   797,
     367,   368,   369,   370,   371,   372,   373,   365,   366,     0,
       0,   367,   368,   369,   370,   371,   372,   373,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,   375,
     376,   377,     0,   365,   366,     0,   856,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,   375,   376,   377,     0,   365,   366,
       0,   861,   367,   368,   369,   370,   371,   372,   373,   365,
     366,     0,     0,   367,   368,   369,   370,   371,   372,   373,
     365,   366,     0,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,   374,   375,   376,   377,     0,     0,
       0,     0,   872,     0,     0,   374,   375,   376,   377,     0,
       0,     0,     0,   919,     0,     0,   374,   375,   376,   377,
       0,   365,   366,     0,   947,   367,   368,   369,   370,   371,
     372,   373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   375,   376,   377,     0,   365,   366,     0,   952,
     367,   368,   369,   370,   371,   372,   373,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,     0,     0,   997,     0,     0,   374,   375,   376,
     377,     0,     0,     0,     0,  1011,     0,     0,   374,   375,
     376,   377,     0,   365,   366,     0,  1048,   367,   368,   369,
     370,   371,   372,   373,   365,   366,     0,     0,   367,   368,
     369,   370,   371,   372,   373,   365,   366,     0,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,   374,
     375,   376,   377,   365,   366,   642,     0,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   375,   376,   377,   365,   366,
     679,     0,   367,   368,   369,   370,   371,   372,   373,   365,
     366,     0,     0,   367,   368,   369,   370,   371,   372,   373,
     365,   366,     0,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   375,   376,   377,     0,     0,   680,     0,     0,
       0,     0,   374,   375,   376,   377,     0,     0,   681,     0,
       0,     0,     0,   374,   375,   376,   377,   365,   366,   682,
       0,   367,   368,   369,   370,   371,   372,   373,     0,     0,
       0,   374,   375,   376,   377,   365,   366,   683,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,   686,     0,     0,     0,     0,   374,   375,   376,
     377,     0,     0,   689,     0,     0,     0,     0,   374,   375,
     376,   377,   365,   366,   690,     0,   367,   368,   369,   370,
     371,   372,   373,   365,   366,     0,     0,   367,   368,   369,
     370,   371,   372,   373,   365,   366,     0,     0,   367,   368,
     369,   370,   371,   372,   373,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,   375,   376,   377,   365,
     366,   692,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,   374,   375,   376,   377,   365,   366,   693,
       0,   367,   368,   369,   370,   371,   372,   373,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,   365,
     366,     0,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,   375,   376,   377,     0,     0,   694,     0,     0,     0,
       0,   374,   375,   376,   377,     0,     0,   695,     0,     0,
       0,     0,   374,   375,   376,   377,   365,   366,   696,     0,
     367,   368,   369,   370,   371,   372,   373,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   374,   375,   376,
     377,   365,   366,   697,     0,   367,   368,   369,   370,   371,
     372,   373,     0,     0,     0,   374,   375,   376,   377,     0,
       0,   699,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,   709,     0,     0,     0,     0,   374,   375,   376,
     377,   365,   366,   710,     0,   367,   368,   369,   370,   371,
     372,   373,   365,   366,     0,     0,   367,   368,   369,   370,
     371,   372,   373,   365,   366,     0,     0,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   375,   376,   377,   365,   366,
     712,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
     375,   376,   377,   365,   366,   715,     0,   367,   368,   369,
     370,   371,   372,   373,   365,   366,     0,     0,   367,   368,
     369,   370,   371,   372,   373,   365,   366,     0,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,   374,
     375,   376,   377,     0,     0,   768,     0,     0,     0,     0,
     374,   375,   376,   377,     0,     0,   864,     0,     0,     0,
       0,   374,   375,   376,   377,   365,   366,   881,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   374,   375,   376,   377,
     365,   366,   882,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   375,   376,   377,     0,     0,   889,     0,     0,
       0,     0,   374,   375,   376,   377,     0,     0,   890,     0,
       0,     0,     0,   374,   375,   376,   377,   365,   366,   891,
       0,   367,   368,   369,   370,   371,   372,   373,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,   365,
     366,     0,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,   374,   375,   376,   377,   365,   366,   896,
       0,   367,   368,   369,   370,   371,   372,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,   375,
     376,   377,   365,   366,   897,     0,   367,   368,   369,   370,
     371,   372,   373,   365,   366,     0,     0,   367,   368,   369,
     370,   371,   372,   373,   365,   366,     0,     0,   367,   368,
     369,   370,   371,   372,   373,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,   375,   376,   377,     0,
       0,   900,     0,     0,     0,     0,   374,   375,   376,   377,
       0,     0,   901,     0,     0,     0,     0,   374,   375,   376,
     377,   365,   366,   902,     0,   367,   368,   369,   370,   371,
     372,   373,     0,     0,     0,   374,   375,   376,   377,   365,
     366,   903,     0,   367,   368,   369,   370,   371,   372,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,   375,   376,   377,     0,     0,   904,     0,     0,     0,
       0,   374,   375,   376,   377,     0,     0,   907,     0,     0,
       0,     0,   374,   375,   376,   377,   365,   366,   908,     0,
     367,   368,   369,   370,   371,   372,   373,   365,   366,     0,
       0,   367,   368,   369,   370,   371,   372,   373,   365,   366,
       0,     0,   367,   368,   369,   370,   371,   372,   373,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   374,
     375,   376,   377,   365,   366,   911,     0,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,   374,   375,   376,
     377,   365,   366,   917,     0,   367,   368,   369,   370,   371,
     372,   373,   365,   366,     0,     0,   367,   368,   369,   370,
     371,   372,   373,   365,   366,     0,     0,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   375,   376,   377,     0,     0,
     933,     0,     0,     0,     0,   374,   375,   376,   377,     0,
       0,   974,     0,     0,     0,     0,   374,   375,   376,   377,
     365,   366,   978,     0,   367,   368,   369,   370,   371,   372,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   375,   376,   377,   365,   366,   988,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,   374,
     375,   376,   377,     0,     0,   998,     0,     0,     0,     0,
     374,   375,   376,   377,     0,     0,  1000,     0,     0,     0,
       0,   374,   375,   376,   377,   365,   366,  1001,     0,   367,
     368,   369,   370,   371,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,   375,
     376,   377,     0,     0,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,   375,   376,   377,     0,     0,  1047,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,   375,   376,   377,     0,     0,  1066
};

static const yytype_int16 yycheck[] =
{
      11,     0,    34,     0,    82,    11,    41,    42,   289,    85,
      11,     9,    10,    24,    71,    71,    27,   249,   250,    30,
      31,    32,   774,   775,    24,    36,    37,    38,     4,    57,
      57,     7,    59,    60,    45,     4,    15,    35,     7,   175,
       4,     5,    72,    43,    87,    88,    57,     3,    47,   175,
      47,     7,     8,     9,     3,   171,    99,    27,     7,     8,
       9,   171,   178,     7,    43,    11,   176,    58,    79,    71,
      72,    90,     4,    84,    83,     7,    37,    38,    11,    66,
      67,    68,    69,    70,    71,   171,    85,   176,    85,   178,
      12,   102,   178,    84,    85,    86,    57,    10,   253,   254,
      91,   176,   176,   178,   178,   175,   184,   185,    66,    67,
      68,    69,    70,    71,   190,   105,    62,    63,   175,   175,
      66,    67,    68,    69,    70,    71,    72,     3,   175,    62,
      63,     7,     8,    66,    67,    68,    69,    70,    71,    72,
      62,    63,   172,   173,    66,    67,    68,    69,    70,    71,
      72,   179,   179,    66,    67,    68,    69,    70,    71,   171,
     171,   172,   126,   127,   128,   171,   178,   171,   170,   171,
     172,   173,   178,     0,   178,   171,   171,   178,   189,   171,
     176,   213,   214,   178,   171,   196,   178,   939,   171,   176,
     942,   190,    43,   190,   349,   178,   351,   175,   233,   175,
     278,   279,    72,   435,   239,   240,   175,   175,   219,   171,
     221,    71,   171,   171,   170,   171,   178,   176,   176,   451,
     452,   170,   171,   175,   170,   171,   172,   173,   171,   264,
     265,   266,   178,   176,    71,   178,   171,   170,   171,   172,
     173,   176,   171,   178,   255,    23,   171,   176,   170,   171,
     172,   173,   171,   178,   486,   290,   267,   176,   171,   178,
     176,   272,   178,   341,   342,    66,    67,    68,    69,    70,
      71,   282,   283,   171,   285,   286,   287,     4,   176,  1031,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     170,   171,   172,   173,   175,   316,   317,   318,   319,   320,
     171,   322,   171,   324,   171,   176,   171,   178,   394,   178,
      57,    45,   171,   178,   178,   286,   287,   176,   339,   178,
     408,   409,   171,   171,   175,   413,   414,   176,    62,    63,
     178,   302,    66,    67,    68,    69,    70,    71,    72,   171,
      45,   176,   175,   178,   176,   175,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,    62,    63,   175,
     171,    66,    67,    68,    69,    70,    71,    72,   339,   175,
      19,    20,   175,   171,   395,   171,   418,   463,   176,   400,
      50,   171,   178,     4,     5,   394,   431,   394,   178,   434,
     411,   412,    62,    63,     4,     5,    66,    67,    68,    69,
      70,    71,    72,   424,   171,   426,   175,   171,   178,   176,
     175,   178,   176,    62,    63,   436,   437,    66,    67,    68,
      69,    70,    71,    72,   445,   446,   171,   171,    13,   175,
      15,   176,    17,   178,   178,   175,   170,   171,   172,   173,
     449,     5,   449,   171,   171,   466,   171,   178,   739,   176,
     178,   742,   171,   178,   463,    40,   463,   176,    43,   178,
      34,    35,   171,    48,   175,   170,   171,   172,   173,   178,
      66,    67,    68,    69,    70,    71,     4,     5,   175,    66,
      67,    68,    69,    70,    71,   171,   171,     4,     5,   171,
     176,   176,   580,   581,   176,   583,   584,     4,     5,   171,
     170,   171,   172,   173,   176,    62,    63,     4,     5,    66,
      67,    68,    69,    70,    71,    72,   177,   178,    81,    82,
     175,   170,   171,   172,   173,    69,    70,    71,    72,   175,
      62,    63,     4,     5,    66,    67,    68,    69,    70,    71,
      72,     4,     5,   171,   171,   175,   567,   568,   176,   176,
     638,   178,    48,    49,   171,    38,    39,   565,   566,   176,
      62,    63,   804,   175,    66,    67,    68,    69,    70,    71,
      72,   171,   171,   171,   175,   171,   176,   176,   176,   600,
     176,   823,   178,   171,   171,   606,   607,   171,   176,   610,
     635,   178,   176,   171,   171,   171,   175,     5,   176,   176,
     176,     9,   175,   624,     4,     5,   175,   652,   653,    70,
      71,    72,   171,   170,   171,   172,   173,   176,   639,   640,
     641,   178,    30,    59,    60,   175,   170,   171,   172,   173,
     651,    13,   677,    15,   175,    17,   657,   658,   170,   171,
     172,   173,   663,   664,   665,   171,   178,   171,   171,   178,
     176,   171,   176,   176,   675,   676,   176,   678,    40,   175,
     171,    43,   175,   175,   685,   176,    48,   688,   170,   171,
     172,   173,   175,   171,   760,   175,   178,   698,   176,   178,
     701,   702,   703,   175,   705,   706,    67,    68,    69,    70,
      71,    72,   100,   714,   102,   783,   784,    62,    63,   175,
     175,    66,    67,    68,    69,    70,    71,    72,   175,   170,
     171,   172,   173,   175,   178,   736,   175,   738,   126,   127,
     128,   175,   175,   175,   132,   133,   134,   175,   136,   175,
     138,   139,   140,   175,   175,   175,   175,   145,   146,   147,
     175,   175,   150,   764,   152,   175,   154,   175,   175,   157,
     158,   760,   160,   760,   175,   163,   164,   175,   166,   175,
     168,   175,   175,   175,   785,   786,   175,   175,   176,   790,
     791,   175,   175,   175,   175,   796,   797,   865,   866,   175,
     175,   802,   175,    15,   175,   175,    18,   175,   175,   170,
     171,   172,   173,   178,    13,    27,    15,   175,    17,    31,
      32,   175,   175,   175,    36,   170,   171,   172,   173,   175,
      71,   176,   175,   178,   175,   175,    48,    49,    50,   790,
     791,    40,   175,   175,    43,    57,    58,    59,   175,    48,
     851,   175,   175,   175,    42,   856,   176,   845,   846,   176,
     861,   886,    13,   176,    15,   176,    17,    72,   175,    81,
      67,   175,    69,    70,    71,    72,   178,   175,   175,   178,
     176,   176,    42,   884,    45,   175,   175,   888,     9,    40,
     175,   178,    43,    42,   178,   178,   178,    48,   899,   178,
     176,   176,   968,   969,   176,   906,   176,   178,   175,   175,
     178,   176,   913,   176,   915,    62,    63,   178,   176,    66,
      67,    68,    69,    70,    71,    72,   176,   176,   176,   176,
     176,    62,    63,   175,   935,    66,    67,    68,    69,    70,
      71,    72,  1008,   175,    80,   176,   176,    80,   176,   176,
       5,   176,   178,  1019,   178,   176,  1022,    62,    63,   176,
     172,    66,    67,    68,    69,    70,    71,    72,   176,   970,
     182,  1037,    57,   170,   171,   172,   173,   189,   178,   968,
     969,   968,   969,   175,   196,    66,    67,    68,    69,    70,
      71,    72,   175,   994,   176,   175,   997,    62,    63,   176,
     176,    66,    67,    68,    69,    70,    71,    72,   220,    42,
    1011,  1012,    37,    42,   176,  1016,   175,    71,   230,  1008,
     176,  1008,    71,   170,   171,   172,   173,    71,    47,   176,
    1019,   178,  1019,  1022,    57,  1022,   176,   176,   175,   170,
     171,   172,   173,   175,   256,   176,    46,  1048,  1037,   175,
    1037,   175,    37,    71,   176,     4,   268,   176,   449,    47,
     272,    47,   418,   657,   582,   170,   171,   172,   173,   289,
     585,   176,   993,   178,   286,   772,   851,   415,    62,    63,
    1064,   428,    66,    67,    68,    69,    70,    71,    72,   170,
     171,   172,   173,    -1,  1014,    -1,    -1,    -1,    -1,   311,
     312,   313,   314,   315,    -1,   170,   171,   172,   173,   321,
      -1,   323,    -1,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,    -1,
      -1,   343,   344,   345,    -1,    -1,   348,    -1,   350,    -1,
     352,    -1,    -1,    -1,   356,   357,   358,   359,   360,   361,
     362,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,   397,   170,   171,   172,   173,
      -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,   445,   446,   447,   448,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,    -1,   175,    -1,
      -1,     5,   179,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   603,    -1,    -1,   606,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,   657,    -1,     9,   170,   171,
     172,   173,   126,   127,   128,    -1,   668,   669,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    -1,    30,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,
     154,    -1,    -1,   157,   158,    -1,   160,    -1,    -1,   163,
     164,    -1,   166,    -1,   168,    -1,   708,    -1,    -1,    -1,
      -1,   175,   176,   170,   171,   172,   173,    -1,    -1,   176,
      -1,   178,    -1,   725,   726,    -1,   170,   171,   172,   173,
      -1,   733,    -1,     5,   178,   737,    -1,     9,    -1,   741,
      -1,    -1,   744,   745,    -1,    -1,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,   767,    -1,   769,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    -1,
     792,   793,   794,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,   158,    -1,   160,    -1,
      -1,   163,   164,    -1,   166,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,    -1,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,     9,   851,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    30,
     872,    -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,   158,    -1,   160,    -1,
      -1,   163,   164,   895,   166,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,    -1,    -1,    -1,   910,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,    -1,   921,
      -1,    -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,   937,    -1,    -1,    -1,   100,
      -1,   102,    -1,    -1,   946,   947,   948,   949,   950,    -1,
     952,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    29,    30,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,   158,    -1,   160,
      -1,    -1,   163,   164,    -1,   166,    -1,   168,  1010,    -1,
      -1,    -1,    -1,  1015,   175,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,     3,     4,     5,   175,     7,
       8,     9,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     158,    -1,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,     3,     4,     5,   175,     7,     8,
       9,   179,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
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
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,     3,     4,     5,   175,     7,     8,     9,
     179,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    29,
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
     150,   151,   152,   153,   154,    -1,   156,   157,   158,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,   175,   176,     3,     4,     5,
      -1,     7,     8,     9,    -1,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
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
     166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,   175,
     176,     3,     4,     5,    -1,     7,     8,     9,    -1,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,   178,    -1,    -1,
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
     152,   153,   154,    -1,   156,   157,   158,    -1,   160,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,   175,   176,     3,     4,     5,    -1,     7,
       8,     9,    -1,    11,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
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
     158,    -1,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,     3,     4,     5,   175,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
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
      -1,   160,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,     3,     4,     5,   175,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    29,
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
     150,   151,   152,   153,   154,    -1,   156,   157,   158,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,     3,     4,     5,   175,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    29,    30,
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
      -1,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,     5,   138,   139,   140,
       9,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
     100,   152,   102,   154,    -1,    -1,   157,   158,    -1,   160,
      -1,    30,   163,   164,    -1,   166,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,
     150,    -1,   152,    -1,   154,    -1,    -1,   157,   158,    -1,
     160,    -1,    -1,   163,   164,    -1,   166,    -1,   168,   170,
     171,   172,   173,    -1,    -1,   175,    -1,   178,    -1,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,   158,
      -1,   160,    -1,    -1,   163,   164,    -1,   166,    -1,   168,
      -1,     4,     5,     6,    -1,    -1,   175,    10,    -1,    -1,
      -1,    14,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,   101,    -1,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,   126,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,   151,    -1,
      -1,    10,   155,    -1,    -1,    14,   159,    16,   161,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
     170,   171,   172,   173,    -1,    84,    85,    86,   178,    -1,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,   126,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,   151,    -1,    -1,    10,   155,    -1,    -1,    14,
     159,    16,   161,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    -1,    62,    63,    60,    61,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,   170,   171,   172,   173,    -1,    84,
      85,    86,   178,    -1,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    -1,    -1,   101,    -1,   103,   104,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    62,    63,    -1,   133,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    62,    63,    -1,   178,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,   173,    -1,    62,    63,    -1,   178,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,   171,   172,   173,    -1,    62,    63,
      -1,   178,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,   178,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,   178,    -1,    -1,   170,   171,   172,   173,
      -1,    62,    63,    -1,   178,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    62,    63,    -1,   178,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,   178,    -1,    -1,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,   170,   171,
     172,   173,    -1,    62,    63,    -1,   178,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,   170,
     171,   172,   173,    62,    63,   176,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   171,   172,   173,    62,    63,
     176,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   170,   171,   172,   173,    62,    63,   176,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,   170,   171,   172,   173,    62,    63,   176,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    -1,    -1,   176,    -1,    -1,    -1,    -1,   170,   171,
     172,   173,    62,    63,   176,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    62,
      63,   176,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,   170,   171,   172,   173,    62,    63,   176,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    62,    63,   176,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    62,    63,   176,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    62,    63,   176,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   171,   172,   173,    62,    63,
     176,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,   173,    62,    63,   176,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,   170,
     171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    62,    63,   176,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      62,    63,   176,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,
      -1,    -1,    -1,   170,   171,   172,   173,    62,    63,   176,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,   170,   171,   172,   173,    62,    63,   176,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,   173,    62,    63,   176,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      -1,    -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,
     173,    62,    63,   176,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,   170,   171,   172,   173,    62,
      63,   176,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,
      -1,    -1,   170,   171,   172,   173,    62,    63,   176,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,   173,    62,    63,   176,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,   170,   171,   172,
     173,    62,    63,   176,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,    -1,
     176,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,   176,    -1,    -1,    -1,    -1,   170,   171,   172,   173,
      62,    63,   176,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    62,    63,   176,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,   170,
     171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,    -1,    -1,   176,    -1,    -1,    -1,
      -1,   170,   171,   172,   173,    62,    63,   176,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,   173,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,   171,   172,   173,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,   171,   172,   173,    -1,    -1,   176
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
     181,   182,   184,   191,   192,   194,   195,   199,   211,   212,
     217,   223,   230,   238,   246,   249,   253,   256,   262,    71,
     175,    71,   175,   231,   250,   254,     4,     7,   209,   209,
     209,     3,     4,     5,     7,     8,     9,    29,    30,    33,
      62,    63,    64,    65,    76,    79,    96,    97,   100,   102,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   156,
     157,   158,   160,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   175,   197,   198,   200,   206,   208,   211,   212,
     185,   186,   175,   197,   175,   175,   197,    27,     7,   239,
     247,   200,    57,    59,    60,   179,   285,   189,   197,   200,
       4,     5,   210,   200,   197,   200,   197,   200,     4,     5,
     273,   274,     9,   170,   171,   207,   208,   275,   209,    84,
      92,   179,   197,   200,   286,    84,    92,   105,   286,   286,
      83,   200,   205,    11,    52,   205,   205,    58,    84,    85,
      86,    91,    90,   200,   192,   199,   211,   212,   197,   197,
     197,   105,   175,   175,   175,   175,   175,   197,   286,   197,
     197,     0,    43,   183,    87,    88,    99,    71,    71,    23,
     200,   213,   214,   197,   213,     4,   200,   182,   175,   175,
      34,    35,   175,   175,   200,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   200,   197,   200,    66,    67,    68,    69,
      70,    71,   171,    19,    20,    62,    63,    66,    67,    68,
      69,    70,    71,    72,   170,   171,   172,   173,     4,     5,
     224,   225,     4,     5,   226,   227,   197,   213,   213,   197,
     200,   241,   182,   257,   263,   175,    57,   175,     4,     7,
     175,   197,   200,   276,    57,   179,   278,   283,   175,   175,
     178,   178,   178,   175,   175,   178,   208,   208,   178,   200,
     197,   200,    10,   178,   178,   197,   178,   205,   190,    11,
     178,   193,   178,   205,    11,   205,   193,   193,     5,   196,
     196,   196,   176,   200,   197,   178,   178,   178,   178,    42,
     205,   205,   205,   200,   197,   218,   176,   197,   200,   215,
     216,   176,    71,   251,    13,    15,    17,    40,    43,    48,
     255,   213,   213,   200,   200,   200,    92,   197,   286,   286,
       4,     5,   203,   204,   203,   204,   205,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   286,   200,
     200,   200,   200,   200,   200,   200,   176,   200,   197,   197,
     197,   197,   197,   200,   200,   200,   176,   200,   200,   197,
     200,   197,   200,   197,   197,   176,   197,   176,   197,   176,
     197,   176,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   286,   197,   213,   213,   197,   197,   197,   176,
     176,   197,   196,   197,   196,   197,   176,   176,   197,   197,
     197,   197,   197,   197,   197,   187,   188,   202,   201,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     175,   175,   178,   175,   175,   178,   176,   176,    42,   240,
      13,    15,    17,    40,    43,    48,   248,    45,   182,   200,
     175,   197,   200,    50,   277,   177,   178,   175,     4,     7,
     175,     9,   284,   213,   213,     4,     5,   200,   200,   213,
     213,   274,     9,   207,   178,    81,    82,    92,   197,   200,
     200,   278,   205,   197,   205,   193,   200,   200,   175,   178,
     178,   178,   176,   176,   197,   200,   197,   200,   197,   197,
     184,   178,   193,   193,     4,     5,   222,   178,   232,   182,
     200,   176,   176,   178,   178,   178,   176,   176,   178,   178,
     176,   175,   175,   176,   176,   178,   178,   193,   178,   176,
     176,   176,   176,   176,   176,   178,   176,   176,   178,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   178,   176,
     176,   178,   178,   178,   176,   178,   178,   176,   178,   176,
     176,   176,   176,   176,   178,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   178,   178,   176,   176,   176,
     176,   176,   176,   178,   176,   176,   178,   178,   178,   178,
     176,   178,   178,   176,   178,   178,   209,   287,   209,   288,
     200,   200,   213,   213,   225,   213,   213,   227,    42,   242,
     258,    48,    49,   264,   178,   200,   176,   178,   176,   175,
     197,   197,   200,   200,   279,   280,   200,     4,     5,   270,
     272,   176,   176,   175,   175,   178,   178,   176,   176,   200,
      80,    80,   178,   178,   178,   205,   178,   178,   213,   200,
     200,   200,   178,   200,   205,   205,   219,   216,   200,    15,
      43,   252,   200,   200,   200,   197,    92,   197,   176,   176,
     200,   200,   205,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   197,   200,   197,   197,   197,   200,   197,   200,
     204,   197,   204,   197,   197,   178,   178,   176,   176,   176,
     176,    38,    39,   244,   182,   200,   178,    57,   197,   197,
     277,   178,   270,   270,   176,   175,   175,   178,   213,   213,
     200,   200,   178,   286,   286,   197,   197,   197,   200,   200,
     176,   176,   176,   176,   178,   200,   193,   175,    11,   176,
     176,   176,   176,   176,   176,   178,   176,   176,   176,   193,
     176,   176,   176,   176,   176,   176,   178,   176,   176,   176,
     178,   176,   176,   178,   176,   178,   176,   176,   176,   178,
     176,   178,   176,   176,   178,   176,   176,   209,   209,   241,
      42,    37,   259,   176,   200,   175,   176,   178,   200,   281,
     213,   213,   271,   176,   176,   197,   178,   178,    71,    71,
      71,   200,   178,   205,     4,     5,   228,   229,   200,   197,
     200,   200,   197,   200,   200,   197,   197,   197,   243,   245,
      47,   266,    59,    60,   176,   200,    57,   197,   176,   270,
     176,   176,   270,   197,   197,   197,   197,   197,   176,   197,
     175,   175,   176,   178,    12,   236,   176,   178,   176,   176,
     176,   176,   176,   176,   176,   182,   182,   200,    46,   265,
     175,   178,   175,   176,   282,    71,   178,   176,   176,   220,
     229,   200,   233,   200,    45,   269,   182,   260,   197,   200,
     200,   284,   197,   200,   182,   182,   176,   267,    13,    15,
      17,    40,    43,    48,   261,   176,   178,   176,   178,   270,
      24,    43,   221,   234,   182,   197,   200,    13,    15,    17,
      40,    43,    48,   235,   268,   176,   176,     4,   237,   266
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   180,   181,   182,   183,   182,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   185,   184,   186,   184,   184,   184,
     184,   184,   184,   184,   187,   184,   188,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   189,   184,
     190,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   191,
     191,   191,   191,   191,   192,   192,   192,   192,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   196,
     196,   197,   197,   197,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   201,   200,   202,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   203,
     204,   205,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   207,   207,   207,   208,
     208,   208,   209,   209,   210,   210,   210,   210,   211,   212,
     214,   213,   215,   215,   215,   216,   216,   218,   219,   220,
     217,   221,   221,   222,   222,   223,   223,   223,   223,   224,
     224,   225,   225,   225,   225,   226,   226,   227,   227,   227,
     227,   228,   228,   228,   229,   229,   229,   229,   231,   232,
     233,   234,   230,   235,   235,   235,   235,   235,   235,   236,
     236,   237,   237,   239,   238,   240,   240,   241,   241,   242,
     243,   242,   244,   245,   244,   247,   246,   248,   248,   248,
     248,   248,   248,   250,   251,   249,   252,   252,   254,   253,
     255,   255,   255,   255,   255,   255,   257,   258,   259,   260,
     256,   261,   261,   261,   261,   261,   261,   263,   262,   264,
     264,   265,   265,   266,   267,   268,   266,   269,   269,   270,
     271,   270,   272,   272,   272,   272,   273,   273,   274,   274,
     274,   274,   275,   275,   275,   275,   276,   276,   276,   276,
     276,   277,   277,   277,   279,   278,   280,   278,   281,   278,
     282,   278,   283,   278,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     286,   286,   287,   287,   288,   288
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
       4,     4,     1,     1,     2,     1,     2,     4,    10,     0,
       1,     1,     2,     2,     3,    10,     8,     8,     8,     3,
       1,     1,     6,     4,     4,     6,     6,     4,     6,     1,
       4,     1,     1,     1,     1,     3,     3,     6,     6,     8,
       6,     4,     6,     8,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     1,     3,
       1,     3,     4,     6,     6,     4,     6,     4,     6,    10,
       4,     4,     4,     3,     3,     0,     4,     0,     4,     2,
       3,     3,     3,     3,     3,     3,     4,     6,     1,     4,
       4,     6,     6,     1,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     3,     6,     6,     4,     4,     4,     4,     6,
       6,     8,     6,     8,     4,     4,     8,     4,     4,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     4,     6,     6,     6,     8,     1,     2,     2,     1,
       1,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       0,     2,     0,     1,     3,     1,     1,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     1,     4,
       4,     0,     1,     3,     1,     1,     3,     3,     0,     0,
       0,     0,    14,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     1,     0,     7,     1,     2,     1,     1,     0,
       0,     5,     0,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     1,     1,     0,     4,
       1,     2,     1,     1,     1,     1,     0,     0,     0,     0,
      11,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     0,     2,     0,     0,     0,     7,     0,     1,     1,
       0,     4,     1,     4,     1,     4,     1,     3,     1,     4,
       1,     4,     1,     1,     3,     3,     0,     2,     4,     1,
       3,     0,     2,     6,     0,     4,     0,     4,     0,     6,
       0,     9,     0,     3,     0,     1,     0,     2,     2,     4,
       1,     4,     6,     6,     7,    10,    12,     7,    10,    12,
       2,     1,     1,     3,     1,     3
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

    {add_command(cFGNST_FREE,NULL,NULL);}

    break;

  case 108:

    {add_command(cFGNST_SET_NUMBER, NULL, NULL);}

    break;

  case 109:

    {drawmode=0;}

    break;

  case 110:

    {drawmode=dmCLEAR;}

    break;

  case 111:

    {drawmode=dmFILL;}

    break;

  case 112:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 113:

    {drawmode=dmFILL+dmCLEAR;}

    break;

  case 114:

    {add_command(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 115:

    {create_changestring(fMID);}

    break;

  case 116:

    {create_changestring(fMID2);}

    break;

  case 117:

    {create_changestring(fLEFT);}

    break;

  case 118:

    {create_changestring(fRIGHT);}

    break;

  case 119:

    {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 122:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 123:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 124:

    {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}

    break;

  case 125:

    {add_command(cSWAP,NULL,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 126:

    {add_command(cSWAP,NULL,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 127:

    {add_command(cSEEK,NULL,NULL);}

    break;

  case 128:

    {add_command(cSEEK2,NULL,NULL);}

    break;

  case 129:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 130:

    {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}

    break;

  case 131:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 133:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 134:

    {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}

    break;

  case 135:

    {add_command(cCONCAT,NULL,NULL);}

    break;

  case 137:

    {create_function(fLEFT);}

    break;

  case 138:

    {create_function(fRIGHT);}

    break;

  case 139:

    {create_function(fMID);}

    break;

  case 140:

    {create_function(fMID2);}

    break;

  case 141:

    {create_function(fSTR);}

    break;

  case 142:

    {create_function(fSTR2);}

    break;

  case 143:

    {create_function(fSTR3);}

    break;

  case 144:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 145:

    {create_pushdbl(-1);create_function(fINKEY);}

    break;

  case 146:

    {create_function(fINKEY);}

    break;

  case 147:

    {create_function(fCHR);}

    break;

  case 148:

    {create_function(fUPPER);}

    break;

  case 149:

    {create_function(fLOWER);}

    break;

  case 150:

    {create_function(fLTRIM);}

    break;

  case 151:

    {create_function(fRTRIM);}

    break;

  case 152:

    {create_function(fTRIM);}

    break;

  case 153:

    {create_function(fCHOMP);}

    break;

  case 154:

    {create_function(fSYSTEM2);}

    break;

  case 155:

    {create_function(fFGNFN_CALL2);}

    break;

  case 156:

    {create_function(fFGNST_NEW);}

    break;

  case 157:

    {create_function(fFGNST_DUMP);}

    break;

  case 158:

    {create_function(fDATE);}

    break;

  case 159:

    {create_function(fDATE);}

    break;

  case 160:

    {create_function(fTIME);}

    break;

  case 161:

    {create_function(fTIME);}

    break;

  case 162:

    {create_function(fPEEK2);}

    break;

  case 163:

    {create_function(fPEEK3);}

    break;

  case 164:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 165:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 166:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 167:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 168:

    {create_function(fGETBIT);}

    break;

  case 169:

    {create_function(fGETCHAR);}

    break;

  case 170:

    {create_function(fHEX);}

    break;

  case 171:

    {create_function(fBIN);}

    break;

  case 172:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 173:

    {add_command(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}

    break;

  case 174:

    {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}

    break;

  case 175:

    {add_command(cORSHORT,NULL,NULL);pushlabel();}

    break;

  case 176:

    {poplabel();create_boole('|');}

    break;

  case 177:

    {add_command(cANDSHORT,NULL,NULL);pushlabel();}

    break;

  case 178:

    {poplabel();create_boole('&');}

    break;

  case 179:

    {create_boole('!');}

    break;

  case 180:

    {create_dblrelop('=');}

    break;

  case 181:

    {create_dblrelop('!');}

    break;

  case 182:

    {create_dblrelop('<');}

    break;

  case 183:

    {create_dblrelop('{');}

    break;

  case 184:

    {create_dblrelop('>');}

    break;

  case 185:

    {create_dblrelop('}');}

    break;

  case 186:

    {add_command(cTESTEOF,NULL,NULL);}

    break;

  case 187:

    {add_command(cGLOB,NULL,NULL);}

    break;

  case 188:

    {create_pushdbl((yyvsp[0].fnum));}

    break;

  case 189:

    {add_command(cARDIM,"",NULL);}

    break;

  case 190:

    {add_command(cARDIM,"",NULL);}

    break;

  case 191:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 192:

    {add_command(cARSIZE,"",NULL);}

    break;

  case 193:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}

    break;

  case 194:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 195:

    {create_dblbin('+');}

    break;

  case 196:

    {create_dblbin('-');}

    break;

  case 197:

    {create_dblbin('*');}

    break;

  case 198:

    {create_dblbin('/');}

    break;

  case 199:

    {create_dblbin('^');}

    break;

  case 200:

    {add_command(cNEGATE,NULL,NULL);}

    break;

  case 201:

    {create_strrelop('=');}

    break;

  case 202:

    {create_strrelop('!');}

    break;

  case 203:

    {create_strrelop('<');}

    break;

  case 204:

    {create_strrelop('{');}

    break;

  case 205:

    {create_strrelop('>');}

    break;

  case 206:

    {create_strrelop('}');}

    break;

  case 209:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 210:

    {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 212:

    {create_function(fSIN);}

    break;

  case 213:

    {create_function(fASIN);}

    break;

  case 214:

    {create_function(fCOS);}

    break;

  case 215:

    {create_function(fACOS);}

    break;

  case 216:

    {create_function(fTAN);}

    break;

  case 217:

    {create_function(fATAN);}

    break;

  case 218:

    {create_function(fATAN2);}

    break;

  case 219:

    {create_function(fEXP);}

    break;

  case 220:

    {create_function(fLOG);}

    break;

  case 221:

    {create_function(fLOG2);}

    break;

  case 222:

    {create_function(fSQRT);}

    break;

  case 223:

    {create_function(fSQR);}

    break;

  case 224:

    {create_function(fINT);}

    break;

  case 225:

    {create_function(fCEIL);}

    break;

  case 226:

    {create_function(fFLOOR);}

    break;

  case 227:

    {create_function(fFRAC);}

    break;

  case 228:

    {create_function(fABS);}

    break;

  case 229:

    {create_function(fSIG);}

    break;

  case 230:

    {create_function(fMOD);}

    break;

  case 231:

    {create_function(fRAN);}

    break;

  case 232:

    {create_function(fRAN2);}

    break;

  case 233:

    {create_function(fMIN);}

    break;

  case 234:

    {create_function(fMAX);}

    break;

  case 235:

    {create_function(fLEN);}

    break;

  case 236:

    {create_function(fVAL);}

    break;

  case 237:

    {create_function(fASC);}

    break;

  case 238:

    {create_function(fDEC);}

    break;

  case 239:

    {create_function(fDEC2);}

    break;

  case 240:

    {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}

    break;

  case 241:

    {create_function(fINSTR2);}

    break;

  case 242:

    {create_function(fRINSTR);}

    break;

  case 243:

    {create_function(fRINSTR2);}

    break;

  case 244:

    {create_function(fSYSTEM);}

    break;

  case 245:

    {create_function(fFGNFN_CALL);}

    break;

  case 246:

    {create_function(fFGNST_GET_NUMBER);}

    break;

  case 247:

    {create_function(fPEEK4);}

    break;

  case 248:

    {create_function(fPEEK);}

    break;

  case 249:

    {create_function(fMOUSEX);}

    break;

  case 250:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 251:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 252:

    {create_function(fMOUSEY);}

    break;

  case 253:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 255:

    {create_function(fMOUSEB);}

    break;

  case 256:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 258:

    {create_function(fMOUSEMOD);}

    break;

  case 259:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 261:

    {create_function(fAND);}

    break;

  case 262:

    {create_function(fOR);}

    break;

  case 263:

    {create_function(fEOR);}

    break;

  case 264:

    {create_function(fTELL);}

    break;

  case 265:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 266:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 267:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 268:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 269:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 270:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 271:

    {create_myopen(0);}

    break;

  case 272:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 273:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 274:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 275:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 276:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 277:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 278:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 279:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 280:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 281:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 282:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 283:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 284:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 285:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 286:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 287:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 288:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 289:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 290:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 297:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 298:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 299:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 300:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 301:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 302:

    {missing_endsub--;}

    break;

  case 303:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 304:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 305:

    {exported=FALSE;}

    break;

  case 306:

    {exported=TRUE;}

    break;

  case 307:

    {exported=FALSE;}

    break;

  case 308:

    {exported=TRUE;}

    break;

  case 311:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 312:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 313:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 314:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 317:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 318:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 319:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 320:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 324:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 325:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 326:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 327:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 328:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 329:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 330:

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

  case 331:

    {
             swap();popgoto();poplabel();}

    break;

  case 332:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 333:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 334:

    {missing_next--;}

    break;

  case 335:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 336:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 337:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 338:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 339:

    {create_pushdbl(1);}

    break;

  case 341:

    {pop(stSTRING);}

    break;

  case 342:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 343:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 344:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 350:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 351:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 353:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 355:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 357:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 358:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 359:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 360:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 361:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 362:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 363:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 364:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 366:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 367:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 368:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 370:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 371:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 372:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 373:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 374:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 375:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 376:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 377:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 378:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 379:

    {poplabel();}

    break;

  case 381:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 382:

    {missing_endif--;}

    break;

  case 383:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 384:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 385:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 386:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 387:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 389:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 390:

    {poplabel();}

    break;

  case 394:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 395:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 400:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 402:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 403:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 404:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 405:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 408:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 409:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 410:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 411:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 412:

    {create_strdata((yyvsp[0].string));}

    break;

  case 413:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 414:

    {create_strdata((yyvsp[0].string));}

    break;

  case 415:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 419:

    {create_print('s');}

    break;

  case 420:

    {create_print('s');}

    break;

  case 421:

    {create_print('d');}

    break;

  case 422:

    {create_print('u');}

    break;

  case 423:

    {create_print('U');}

    break;

  case 424:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 425:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 426:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 427:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 428:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 429:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 430:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 431:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 432:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 433:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 434:

    {create_pushstr("?");create_print('s');}

    break;

  case 435:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 436:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 437:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 438:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 439:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 440:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 448:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 453:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 454:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 455:

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
