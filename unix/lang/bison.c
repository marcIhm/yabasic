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
    tDATE = 422,
    tTIME = 423,
    tTOKEN = 424,
    tTOKENALT = 425,
    tSPLIT = 426,
    tSPLITALT = 427,
    tGLOB = 428,
    UMINUS = 429
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
#define YYFINAL  265
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  184
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  461
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1087

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   429

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   183,     2,     2,     2,     2,
     179,   180,   176,   175,   182,   174,     2,   177,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   181,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   178
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
     379,   380,   381,   382,   383,   384,   385,   388,   389,   392,
     392,   393,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   426,   429,   432,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   503,   504,   505,   508,   509,   510,   513,   514,
     517,   518,   519,   520,   523,   526,   529,   529,   532,   533,
     534,   537,   538,   541,   542,   545,   541,   550,   551,   554,
     555,   558,   559,   560,   561,   564,   565,   568,   569,   570,
     571,   574,   575,   578,   579,   580,   581,   584,   585,   586,
     589,   590,   591,   592,   595,   596,   600,   614,   595,   619,
     620,   621,   622,   623,   624,   627,   628,   631,   632,   637,
     637,   641,   642,   645,   646,   650,   652,   651,   656,   657,
     657,   661,   661,   667,   668,   669,   670,   671,   672,   676,
     677,   676,   683,   684,   688,   688,   693,   694,   695,   696,
     697,   698,   701,   702,   702,   704,   701,   708,   709,   710,
     711,   712,   713,   716,   716,   721,   722,   725,   726,   729,
     731,   733,   730,   737,   738,   741,   742,   742,   745,   746,
     748,   749,   753,   754,   757,   758,   760,   761,   765,   766,
     767,   768,   771,   772,   773,   774,   775,   778,   779,   780,
     783,   783,   784,   784,   785,   785,   786,   786,   787,   787,
     790,   791,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   803,   804,   805,   806,   807,   810,   811,   813,   814,
     817,   818
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
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tDATE", "tTIME", "tTOKEN",
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
     425,   426,   427,   428,    45,    43,    42,    47,   429,    40,
      41,    59,    44,    35
};
# endif

#define YYPACT_NINF -773

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-773)))

#define YYTABLE_NINF -383

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3926,   -49,   -33,  -773,  -773,  -773,  -773,  -773,   138,   138,
     138,  2986,  -773,  -773,  -773,  3552,   -92,   -82,  3552,    88,
     122,  -773,  -773,  -773,  3332,     7,  -773,  3332,    70,  -773,
    3332,  3332,  3332,   233,    36,   138,  1760,  1163,  2106,    71,
    3332,  2813,  3332,   465,    79,  3332,  -773,    49,  3552,  3552,
    3552,    73,    17,    74,    84,   102,   126,  2106,  3552,  3552,
     183,   142,  -773,    11,  -773,  -773,  -773,  -773,   281,   311,
    -773,   370,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  3332,
    -773,  3552,  -773,   402,  3332,  3778,  -773,  -773,  -773,  -773,
    -773,  -773,   237,   248,  -773,  -773,  -773,   267,   282,   227,
     330,   346,  3332,   376,   426,   444,   453,   463,   482,   490,
     493,   500,   503,   514,   517,   519,   520,   524,   535,   536,
     538,   539,   540,   541,   544,   549,   551,   552,   553,   556,
     557,   558,   559,   564,   565,   568,   579,   580,   588,   590,
     591,   592,   593,   594,   595,   596,   598,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   612,   613,   614,
     617,   618,   619,   620,   623,   624,   627,   629,   632,   633,
     634,   639,   641,   642,   643,  3332,  3332,   310,  -773,   550,
    -773,  -773,  -773,  -773,   329,   357,  3552,   314,  -773,  -773,
     314,  -773,  -773,  3332,  3778,   369,   646,   484,   647,    24,
    3332,   -28,   310,  1345,   648,   650,   366,  1345,   310,  2121,
     310,  2294,   651,   652,   447,  -773,  -773,   111,   111,  -773,
    -773,   476,  -773,  3332,  3552,  3332,    13,  1345,   513,  -773,
    -773,  -773,  -773,   547,  3552,  2472,  -773,  3332,  -773,    -1,
     566,  -773,  -773,  3332,  3159,  -773,  -773,  1345,  -773,  -773,
     281,   311,   314,    -2,    -2,  -773,   711,   711,   711,  2279,
    3552,    91,   653,   314,  -142,  -773,  -773,   692,  3332,  3332,
    3332,  3332,  3552,  -773,  1345,   428,  3332,   314,   654,   738,
    1345,   405,  -773,  -773,  -773,  -773,  3332,  3332,   640,  3332,
    1933,  2106,   424,   424,  3332,  3332,  3332,  3332,  3332,  3332,
    3332,  3332,  3332,  3332,  3332,  3332,  2106,  3332,  3332,  3332,
    3332,  3332,  3332,  3332,  2457,  3552,  3552,  3552,  3552,  3552,
    3332,  3332,  3332,  2635,  3332,  3552,  3332,  3552,  3332,  3552,
    3552,   354,   933,  1346,  1458,  3552,  3552,  3552,  3552,  3552,
    3552,  3552,  3552,  2106,  3552,  -773,  -773,  3552,  3332,  3552,
    3552,  3552,  3552,  3552,   656,   659,  3552,   711,  3552,   711,
    3552,   760,    38,  1573,  3552,  3552,  3552,  3552,  3552,  3552,
    3552,  -773,  -773,  -773,  -773,  3332,  3332,  3332,  3332,  3332,
    3332,  3332,  3332,  3332,  3332,  3332,   664,   665,   663,  -773,
     667,   668,   666,  -773,  -139,   672,   673,   310,  1345,   791,
     455,   809,  3778,  3332,   676,  3552,  -773,  -773,  3332,   310,
     683,   268,   686,    28,  -773,   853,  -773,  -773,   492,  3332,
    3332,  -773,  -773,   233,  -773,  -773,    48,  2653,   314,  1345,
     383,  1529,  3332,   314,  3332,  -773,   -28,  -773,  -773,  3332,
    3552,  -773,  3332,    -1,  3332,  3332,   693,   695,   696,   697,
    -773,  3447,  -133,  3332,  3332,  3332,  3778,   698,    -1,    -1,
    1345,   314,   534,  -773,   310,  1345,   699,  -773,  -773,  -773,
    3778,  -773,  -773,  3332,  -773,  -773,  -773,  -773,   702,   703,
    2828,  3001,  3174,   704,    -8,   705,   706,   709,   712,   710,
     714,   713,   715,    -1,  3347,  4479,  4490,  4537,  4560,  4606,
     694,  4617,  1365,  4628,  4653,   716,  4676,  4687,  4698,  4744,
    4769,  4814,  3831,  -773,  4825,  -103,  -104,   -19,     4,    41,
    3979,  4070,  1653,  -773,  4836,  4860,    52,  4885,   -90,  4896,
     250,   272,  -773,   303,  -773,   332,  -773,   360,  -773,   362,
     372,   391,   413,    18,    19,   414,   415,   416,   280,   718,
     -80,   719,   720,   417,  4907,   423,   -79,    89,    92,   132,
    -773,  -773,   160,   -14,   208,    35,   220,  -773,  -773,   314,
     314,   314,   314,   314,   314,  -773,   138,   138,  3332,  3332,
     460,    69,   180,   154,   211,   236,  -773,    22,    22,   760,
     760,  -773,  -773,   329,  -773,  -773,   357,  -773,  -773,  -773,
     833,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   516,
    4117,  3332,   144,  4952,  3608,  -773,  -773,  3332,  3332,  -773,
    -773,  3332,  -773,   569,   721,   722,   724,   728,  4142,  4187,
     729,   730,  -773,  -773,  -773,  3332,   805,   812,  -773,   276,
    4198,  1345,  -773,  -773,   292,  -773,  3332,  4209,  4234,  -773,
    3332,  3332,  3332,  -773,  -773,   310,  1345,   310,  1345,  4259,
    -773,  3332,  3332,  3332,  -773,  -773,  -773,  3332,  3332,     9,
    1345,  -773,  -773,  3332,  3332,  3332,  -773,  -773,  3552,  3503,
    -773,   732,   733,  -773,  -773,  3332,  3332,  3332,  3332,  -773,
    -773,  -773,  -773,  -773,  -773,  3332,  -773,  -773,  3332,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  3332,  -773,
    -773,  3332,  3332,  3332,  -773,  3332,  3332,  -773,  3552,  -773,
    -773,  -773,  -773,  -773,  3332,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  3552,  3552,  -773,  -773,  -773,
    -773,  -773,  -773,  3552,  -773,  -773,  -773,  -773,  -773,  -773,
    3332,  3332,  3332,  3332,   903,  -773,  3552,   903,  -773,  3552,
    3552,  -773,   734,  -773,   735,   640,   515,   739,   741,  -773,
     742,   743,  -773,  -773,   537,  3778,  -773,  -773,  -773,  3332,
    4270,   857,  3552,  -773,  3552,   314,   310,   683,  4281,   569,
     569,  4976,   736,   746,  -773,   744,  -773,  -773,  -773,  -773,
    3332,  3332,  -773,  -773,  4326,  2106,  2106,  3552,  3552,  3552,
    -773,  3332,  3332,   747,  5023,  5034,  1779,  3552,  1345,    -1,
    -773,   749,  -773,    65,  -773,  -773,  -773,  5045,  5068,  5092,
     429,   750,   145,  -773,  -773,  5103,  5114,   751,    54,  5161,
    5184,  5230,  5241,  5252,  1948,  5277,  5300,   161,  5311,   178,
     216,   450,  5322,  4351,  4398,  5368,   124,   451,   136,   458,
     469,   138,   138,  -773,  -773,  -773,  -773,  3332,   887,   895,
     891,  5393,  3332,   755,   471,   219,  -773,  3332,  -773,  -773,
    -773,  -773,  -773,  -773,   756,   757,  1345,  1345,  3552,  -773,
    -773,   314,   314,   294,  4409,  1345,  -773,   864,   868,   869,
    3332,   309,  3332,   597,  3332,  -773,  -773,  -773,  -773,  -773,
    -773,  3552,  -773,  -773,  -773,  3332,  -773,  -773,  -773,  -773,
    -773,  -773,  3332,  -773,  -773,  -773,  3552,  -773,  -773,  3332,
    -773,  3332,  -773,  -773,  3552,  3332,  -773,  -773,  3552,  -773,
    -773,  3552,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   896,
     555,  5438,  3332,   888,  3552,  5449,   569,   764,   767,   569,
    -773,  -773,   314,  3552,  3552,  3552,  3552,  3552,  5460,  3332,
    -773,   769,   770,   235,  -773,    81,   473,  4420,  5484,   479,
    5509,  5520,   480,  5531,   496,   505,  3778,  4074,  3332,   904,
    -773,   772,  -773,  4443,   773,   506,  -773,  -773,  -773,  -773,
    -773,   314,   314,   314,   314,   314,   882,  1345,   774,   775,
    -773,   597,  3332,  -773,  -773,  3332,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,   891,   920,   491,  3778,  -773,  3552,
    3332,  3332,  -773,   853,  3552,  -773,  -773,  3778,  -773,  1345,
    3778,  5576,  -773,  -773,   891,   462,   244,  5600,  4468,   569,
     314,     6,   891,  -773,  3778,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  3552,  -773,  3332,  -773,  -773,  -773,  -773,
     630,   891,   508,  5647,  -773,  -773,  -773,  -773,  -773,  -773,
     956,   896,  -773,  -773,  -773,  -773,  -773
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     110,     0,     0,   105,   334,   369,   374,    11,     0,     0,
       0,     0,    24,    26,   312,     0,     0,     0,     0,   313,
      18,    20,   349,   361,     0,   442,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     4,     3,     0,     7,    39,    41,     9,    22,    23,
      21,     0,    13,    14,    17,    16,    15,    28,    29,     0,
     296,     0,   296,     0,     0,     6,   289,   288,    30,    31,
      38,   285,   198,   132,   286,   287,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,   256,   259,   262,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   162,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
     211,   192,   197,   134,     0,     0,     0,    12,   296,   296,
      42,   314,    19,     0,     6,   393,     0,   446,     0,     0,
     422,   438,    62,    61,     0,     0,    63,   104,    53,     0,
      55,     0,   414,   416,    56,   412,   418,     0,     0,   419,
     282,    57,    59,     0,    89,     0,     0,   457,     0,    86,
      91,    79,    40,     0,     0,     0,    67,     0,    50,    72,
       0,    88,    87,     0,     0,   113,   114,    92,     8,    10,
       0,     0,   106,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     1,     2,     0,     0,     0,
       0,     0,     0,   303,   177,     0,   298,   115,     0,     0,
     370,     4,   296,   296,    32,    33,     0,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   296,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    36,   181,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,   318,    25,   315,
     323,   324,    27,   321,     0,     0,     0,   354,   353,     0,
       4,     0,     6,     0,     0,     0,   443,   444,     0,   425,
     427,    45,     0,     0,    49,   440,   296,   296,     0,     0,
       0,   296,   296,     0,   284,   283,     0,     0,    90,   456,
       0,     0,     0,    66,     0,    71,   438,   122,   121,     0,
       0,    68,     0,    74,     0,     0,   130,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     6,     0,     0,     0,
     178,   120,     0,   294,   301,   302,   297,   299,   295,   335,
       6,   381,   379,     0,   380,   376,   378,   375,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,   260,     0,   263,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   163,     0,     0,     0,     0,     0,   137,   212,   206,
     208,   210,   207,   209,   205,   136,     0,     0,     0,     0,
     185,   187,   189,   186,   188,   184,   203,   200,   199,   201,
     202,   296,   296,     0,   296,   296,     0,    43,    44,   351,
     355,   368,   366,   367,   364,   363,   365,   362,   383,     4,
       0,     0,     0,     0,     0,   423,    46,    47,     0,   430,
     432,     0,   441,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,   420,   421,     0,     0,     0,   125,   124,
     128,   215,    51,    69,    82,    73,     0,     0,     0,   296,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     0,
       5,     0,     0,     0,   309,   310,   304,     0,     0,     4,
     377,   275,   174,     0,     0,     0,   276,   277,     0,     0,
     270,     0,     0,   193,   194,     0,     0,     0,     0,   216,
     217,   218,   219,   220,   221,     0,   223,   224,     0,   226,
     227,   190,   232,   233,   228,   229,   230,   231,     0,   235,
     240,     0,     0,     0,   239,     0,     0,   142,     0,   147,
     148,   241,   172,   242,     0,   173,   149,   150,   255,   258,
     261,   264,   153,   151,   152,     0,     0,   154,   248,   155,
     254,   253,   164,     0,   249,   156,   250,   157,   252,   158,
       0,     0,     0,     0,     0,   167,     0,     0,   169,     0,
       0,   458,    35,   460,    37,   182,   180,     0,     0,   316,
       0,     0,   322,   352,   358,     6,   395,   396,   394,     0,
       0,   447,     0,   445,     0,   428,   426,   427,     0,     0,
       0,     0,   408,   410,   439,   405,   290,   292,   296,   296,
       0,     0,   415,   417,    64,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,    80,     0,
      85,     0,   300,     0,   373,   372,   371,     0,     0,     0,
       0,     0,     0,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   320,   325,   326,     0,     0,     0,
     384,     0,     0,     0,     0,     0,   424,     0,   431,   433,
     434,   296,   296,   406,     0,     0,    52,    54,     0,   126,
     127,   123,   129,    83,    76,    77,   131,     0,     0,     0,
       0,   109,     0,   327,     0,   267,   268,   269,   278,   279,
     280,     0,   195,   196,   170,     0,   222,   225,   234,   138,
     139,   141,     0,   237,   238,   143,     0,   243,   244,     0,
     246,     0,   165,   159,     0,     0,   176,   272,     0,   166,
     274,     0,   168,   191,   459,   461,   356,   359,   350,   399,
     449,     0,     0,   448,     0,     0,     0,     0,     0,     0,
     291,   293,    65,     0,     0,     0,     0,     0,     0,     0,
      81,   330,   331,     0,   328,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,   110,     0,   397,
     453,     0,   450,     0,     0,     0,   436,   435,   409,   411,
     407,    84,    75,   118,   119,   117,     0,   108,     0,     0,
     305,     0,     0,   336,   281,     0,   140,   144,   245,   247,
     251,   175,   271,   273,   357,     4,   403,     6,   385,     0,
       0,     0,   429,   440,     0,   332,   333,     6,   329,   346,
       6,     0,   404,   400,   398,     0,     0,     0,     0,     0,
     116,     4,   337,   171,     6,   392,   389,   390,   391,   387,
     388,   386,   454,     0,   451,     0,   437,   308,   307,   306,
       0,   401,     0,     0,   340,   342,   343,   344,   339,   341,
     347,   399,   455,   452,   348,   338,   402
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -773,  -773,   -81,  -773,   509,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   914,  -239,  -773,  -773,   -87,   792,  -773,   915,
     -11,  -773,  -773,   671,  -291,   -35,  -773,   543,   -26,     2,
    -773,     1,     3,   -77,  -773,  -773,   299,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,   374,  -773,   375,  -773,   -41,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,   105,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -107,  -773,  -773,  -773,
    -772,  -773,  -773,  -773,   560,  -773,  -773,   188,   545,  -773,
    -773,  -773,  -773,  -773,   -57,  -773,    32,  -773,  -773
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    60,    61,   267,    62,   184,   185,   576,   577,   201,
     436,    63,    64,   439,    65,    66,   447,   177,   178,    67,
     235,   579,   578,   489,   490,   236,   180,   219,   181,    88,
     206,   182,   183,   275,   276,   466,   467,    70,   462,   821,
    1037,  1069,   666,    71,   388,   389,   392,   393,   973,   974,
      72,    83,   668,  1040,  1070,  1080,  1013,  1085,    73,   193,
     600,   399,   774,   986,   869,   987,    74,   194,   607,    75,
      84,   470,   826,    76,    85,   477,    77,   401,   775,   949,
    1045,  1061,    78,   402,   778,  1028,   989,  1054,  1081,  1043,
     794,   959,   795,   214,   215,   221,   411,   615,   414,   789,
     790,   956,  1033,   415,   623,   200,   228,   762,   764
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     179,    68,   492,    69,   281,   278,   239,   240,   220,   437,
     437,    89,    90,   195,   444,   445,   203,   878,   879,   207,
     209,   211,    79,   430,   824,   227,   227,   227,   406,   412,
    1067,   407,   619,   370,   247,   620,   370,   222,    81,    91,
     455,   567,   370,    94,    95,   216,   227,   654,   250,  1068,
     251,    91,   825,     1,     2,    94,    95,   633,   364,   365,
     366,   367,   368,   369,   196,   437,   197,   198,   274,   232,
     233,   370,   370,   280,   204,   205,   904,   710,   711,   364,
     365,   366,   367,   368,   369,   370,    68,   188,    69,   262,
     723,   288,   724,  1012,   381,   370,   370,   189,   268,   269,
     742,   749,   743,   750,   364,   365,   366,   367,   368,   369,
     270,   395,   396,   400,    91,   191,   373,   374,    94,    95,
     375,   376,   377,   378,   379,   380,   381,   373,   374,   192,
      80,   375,   376,   377,   378,   379,   380,   381,   378,   379,
     380,   381,    86,   373,   374,    87,    82,   375,   376,   377,
     378,   379,   380,   381,   234,   413,   370,   364,   365,   366,
     367,   368,   369,   712,   361,   363,   755,   370,   756,   246,
     448,   449,   677,   370,   678,    52,    53,    54,   255,   370,
     438,   438,   398,   265,   997,   266,   713,  1000,   370,   410,
     199,   424,   425,   370,   370,    68,   256,    69,   384,   385,
     735,   736,   435,   408,   646,   478,   479,   621,   441,   443,
     217,   218,   427,   370,   429,   758,   370,   759,   567,   662,
     663,   714,   217,   218,   379,   380,   381,   370,   382,   383,
     384,   385,   721,   457,   458,   459,   438,   212,   213,   382,
     383,   384,   385,   382,   383,   384,   385,   376,   451,   378,
     379,   380,   381,   257,   687,   382,   383,   384,   385,   493,
     460,   284,   285,   258,   370,   465,   370,   370,   551,   552,
     563,   751,   565,   453,   752,   480,   481,  1066,   482,   227,
     227,   259,   380,   381,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   227,   506,   507,   508,   509,
     510,   511,   512,   514,   937,   260,   938,   370,   381,   520,
     521,   522,   524,   525,   753,   527,   940,   529,   941,   370,
     370,   609,   485,   486,   781,   910,   782,   911,   382,   383,
     384,   385,   227,   386,   387,   370,   370,   554,   505,   624,
     625,   925,   754,   926,   630,   631,   364,   365,   366,   367,
     368,   369,   271,   370,   382,   383,   384,   385,   928,    93,
     929,   390,   391,    96,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   549,   364,   365,   366,   367,
     368,   369,   272,   370,    98,   382,   383,   384,   385,   669,
     757,   370,   610,   273,   370,   370,   930,   613,   931,   567,
     220,   954,   760,    68,   643,    69,   279,   645,   628,   629,
     382,   383,   384,   385,  -382,  1010,    80,  1011,   471,   370,
     472,   640,   473,   641,  1062,   370,  1063,    82,   487,   488,
     726,   373,   374,   647,   648,   375,   376,   377,   378,   379,
     380,   381,   656,   658,   659,   474,   282,   370,   475,   616,
     617,   370,   727,   476,   108,   370,   109,    68,   807,    69,
     740,   283,   670,   856,   636,   637,   858,   370,   601,   370,
     602,    68,   603,    69,   809,  1055,   963,  1056,   370,  1057,
     130,   131,   132,   728,   370,   370,   136,   137,   138,   370,
     140,   969,   142,   143,   144,   604,   626,   627,   605,   149,
     150,   151,  1058,   606,   154,  1059,   156,   370,   158,   286,
    1060,   160,   729,   162,   767,   768,   164,   770,   771,   166,
     167,   168,   169,   241,   171,   287,   173,   376,   377,   378,
     379,   380,   381,   186,   532,   370,  1042,   370,   664,   665,
     730,   404,   731,   382,   383,   384,   385,   370,   418,   242,
     243,   244,   732,   373,   374,   289,   245,   375,   376,   377,
     378,   379,   380,   381,   776,   777,   370,   765,   766,   371,
     372,   733,   813,   792,   793,   867,   868,   373,   761,   763,
     902,   375,   376,   377,   378,   379,   380,   381,   370,   370,
     370,   370,   370,   734,   737,   738,   739,   746,   370,   915,
     780,   971,   972,   748,   370,   290,   787,   788,   463,   908,
     791,   810,   373,   374,   990,   991,   375,   376,   377,   378,
     379,   380,   381,   291,   804,   370,   370,   819,   820,   423,
     932,   939,   292,   370,   382,   383,   384,   385,   942,   814,
     815,   816,   293,  1074,   370,  1075,   370,  1076,   370,   943,
     818,   953,   837,  1014,   370,   370,   465,   823,   426,  1017,
    1020,   294,   827,   828,   829,   382,   383,   384,   385,   295,
    1077,   370,   296,  1078,   835,   836,  1022,   838,  1079,   297,
     370,   370,   298,   370,   839,  1023,  1032,   840,  1082,   382,
     383,   384,   385,   299,   870,   431,   300,   841,   301,   302,
     842,   843,   844,   303,   845,   846,   375,   376,   377,   378,
     379,   380,   381,   848,   304,   305,   446,   306,   307,   308,
     309,   884,   885,   310,   382,   383,   384,   385,   311,   432,
     312,   313,   314,   614,   456,   315,   316,   317,   318,   852,
     853,   854,   855,   319,   320,   373,   374,   321,   440,   375,
     376,   377,   378,   379,   380,   381,   373,   374,   322,   323,
     375,   376,   377,   378,   379,   380,   381,   324,   871,   325,
     326,   327,   328,   329,   330,   331,    68,   332,    69,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   886,
     887,   343,   344,   345,   227,   227,   346,   347,   348,   349,
     894,   895,   350,   351,   957,   958,   352,   187,   353,   469,
     190,   354,   355,   356,   382,   383,   384,   385,   357,   202,
     358,   359,   360,   208,   210,   403,   405,   416,   226,   417,
     421,   422,   381,   599,   468,   454,   560,   889,   890,   561,
     252,   253,   254,   591,   592,   593,   594,   595,   596,   261,
     263,   264,   597,   598,   608,   611,   398,   382,   383,   384,
     385,   951,   622,   944,   945,   618,   955,   970,   382,   383,
     384,   385,   649,   277,   694,   773,   695,   650,   651,   652,
     661,   667,   671,   672,   676,   805,   680,   679,   681,   968,
     683,   682,   806,   975,   684,   685,   701,   686,   741,   744,
     745,   796,   797,   798,   977,  1024,  1025,   799,   488,   802,
     803,   978,   833,   834,   873,   881,   861,   862,   980,   863,
     981,   864,   865,   866,   983,   882,   883,   896,   903,   947,
     909,   914,   948,    -4,   952,   965,   960,   961,    93,   966,
     967,   993,    96,   988,   998,   994,  1044,   999,  1008,  1009,
    1027,  1029,  1031,  1034,  1035,  1036,  1051,  -360,  1007,  1052,
    1084,   248,   249,    98,   491,   660,   822,   769,   362,   634,
    1038,   772,   946,  1071,  1086,   876,  1049,  1026,   394,     0,
       0,   642,     0,   632,     0,   397,     0,    68,    68,    69,
      69,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1039,     0,     0,  1041,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,     0,     0,  1047,
    1048,     0,     0,     0,     0,     0,   433,     0,    68,     0,
      69,     0,     0,   108,     0,   109,     0,     0,    68,     0,
      69,    68,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,   452,     0,  1073,    68,     0,    69,     0,   130,
     131,   132,     0,     0,   461,   136,   137,   138,   464,   140,
       0,   142,   143,   144,     0,     0,     0,     0,   149,   150,
     151,     0,   484,   154,     0,   156,     0,   158,     0,     0,
     160,     0,   162,     0,     0,   164,     0,     0,   166,   167,
     168,   169,     0,   171,     0,   173,     0,   515,   516,   517,
     518,   519,   186,   534,     0,     0,     0,   526,     0,   528,
       0,   530,   531,   533,   535,   537,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   550,     0,     0,   553,
       0,   555,   556,   557,   558,   559,     0,     0,   562,     0,
     564,     0,   566,     0,     0,     0,   569,   570,   571,   572,
     573,   574,   575,     0,     0,     0,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,     0,   100,   101,   102,   103,     0,
       0,     0,   644,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,   655,   657,   229,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,   231,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     0,
       0,     0,   176,     0,     0,     0,   225,     0,     0,     0,
       0,    93,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   785,   373,   374,   786,
       0,   375,   376,   377,   378,   379,   380,   381,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,   374,     0,
       0,   375,   376,   377,   378,   379,   380,   381,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,     0,    93,     0,     0,     0,    96,     0,     0,
     830,   832,   130,   131,   132,     0,     0,     0,   136,   137,
     138,     0,   140,     0,   142,   143,   144,     0,    98,     0,
       0,   149,   150,   151,     0,     0,   154,     0,   156,     0,
     158,     0,     0,   160,     0,   162,     0,     0,   164,     0,
     847,   166,   167,   168,   169,     0,   171,     0,   173,   382,
     383,   384,   385,     0,     0,   186,   536,   849,   850,     0,
       0,     0,     0,     0,    93,   851,     0,     0,    96,   382,
     383,   384,   385,     0,     0,   697,     0,   698,   857,     0,
       0,   859,   860,     0,     0,     0,     0,     0,   108,    98,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   874,     0,   875,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,   891,
     892,   893,     0,   149,   150,   151,     0,     0,   154,   901,
     156,     0,   158,     0,     0,   160,     0,   162,     0,     0,
     164,   638,     0,   166,   167,   168,   169,     0,   171,   108,
     173,   109,     0,     0,     0,   373,   374,   186,   538,   375,
     376,   377,   378,   379,   380,   381,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,     0,   397,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,     0,     0,   154,
     962,   156,     0,   158,     0,     0,   160,     0,   162,     0,
       0,   164,     0,     0,   166,   167,   168,   169,     0,   171,
       0,   173,     0,   976,     0,     0,     0,     0,   186,     0,
       0,     0,     0,     0,     0,   373,   374,     0,   979,   375,
     376,   377,   378,   379,   380,   381,   982,     0,     0,     0,
     984,     0,     0,   985,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   995,   382,   383,   384,
     385,     0,     0,   568,     0,  1001,  1002,  1003,  1004,  1005,
       0,     0,     0,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1046,   100,   101,   102,   103,  1050,   382,   383,   384,
     385,     0,     0,   717,     0,   718,   104,     0,     0,   105,
       0,   373,   374,     0,   223,   375,   376,   377,   378,   379,
     380,   381,   224,     0,     0,  1072,   106,   107,     0,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,   164,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,     0,    91,    92,    93,   176,
      94,    95,    96,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,   899,
       0,   900,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     373,   374,   105,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,   483,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,    91,
      92,    93,   176,    94,    95,    96,   225,     0,     0,     0,
       0,     0,   382,   383,   384,   385,     0,     0,   921,     0,
     922,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   373,   374,   105,     0,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,    91,    92,    93,   176,    94,    95,    96,   225,
       0,     0,     0,     0,     0,   382,   383,   384,   385,     0,
       0,     0,     0,   419,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   373,   374,   105,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,     0,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,   176,   450,
      91,    92,    93,     0,    94,    95,    96,     0,   382,   383,
     384,   385,     0,     0,     0,     0,   420,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   373,   374,   105,     0,   375,   376,
     377,   378,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,     0,   163,   164,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,   176,   513,    91,    92,
      93,     0,    94,    95,    96,     0,   382,   383,   384,   385,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,   105,   373,   374,     0,     0,   375,
     376,   377,   378,   379,   380,   381,     0,     0,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,     0,   163,   164,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,   176,   523,    91,    92,    93,     0,
      94,    95,    96,     0,   237,     0,     0,   382,   383,   384,
     385,     0,     0,     0,     0,   635,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     373,   374,   105,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,    91,
      92,    93,   176,    94,    95,    96,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,     0,     0,     0,     0,
     673,     0,     0,     0,     0,    97,    98,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   373,   374,   105,     0,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,    91,    92,    93,   176,    94,    95,    96,     0,
     442,     0,     0,     0,     0,   382,   383,   384,   385,     0,
       0,     0,     0,   674,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   373,   374,   105,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,     0,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,    91,    92,    93,   176,    94,
      95,    96,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,     0,     0,     0,     0,   675,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   373,
     374,   105,     0,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,     0,   163,   164,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,    93,   373,
     374,   176,    96,   375,   376,   377,   378,   379,   380,   381,
       0,   382,   383,   384,   385,     0,     0,     0,     0,   688,
       0,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   831,     0,     0,     0,     0,
       0,     0,     0,   108,     0,   109,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    96,     0,     0,
       0,   382,   383,   384,   385,     0,     0,   653,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,    98,   140,
       0,   142,   143,   144,     0,     0,     0,     0,   149,   150,
     151,     0,   108,   154,   109,   156,     0,   158,     0,     0,
     160,     0,   162,     0,     0,   164,     0,     0,   166,   167,
     168,   169,     0,   171,     0,   173,     0,     0,   130,   131,
     132,     0,   186,     0,   136,   137,   138,     0,   140,     0,
     142,   143,   144,     0,     0,     0,     0,   149,   150,   151,
       0,     0,   154,     0,   156,     0,   158,     0,   108,   160,
     109,   162,     0,     0,   164,     0,     0,   166,   167,   168,
     169,     0,   171,     0,   173,     0,     0,     0,     0,     0,
       0,   186,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
       0,     0,     0,   149,   150,   151,     0,     0,   154,     0,
     156,     0,   158,     0,     0,   160,     0,   162,     0,     0,
     164,     0,     0,   166,   167,   168,   169,     0,   171,     0,
     173,     0,     1,     2,     3,     0,     0,   784,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     8,     9,    10,
      11,  -311,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,  -110,  -110,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,  -110,     0,    49,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   373,   374,     0,     0,   375,   376,   377,
     378,   379,   380,   381,    52,    53,    54,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       1,     2,     3,    57,     0,     0,     4,     0,    58,     0,
       5,    59,     6,     0,     7,     8,     9,    10,    11,  -311,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    -6,    -6,
      24,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,   382,   383,   384,   385,     0,
      39,    40,    41,   708,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   374,     0,     0,   375,   376,   377,   378,   379,
     380,   381,    52,    53,    54,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     1,     2,
       3,    57,     0,     0,     4,     0,    58,     0,     5,    59,
       6,     0,     7,     8,     9,    10,    11,  -311,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    -6,     0,     0,     0,    23,    -6,     0,    24,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,     0,   373,   374,    31,    32,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    38,   382,   383,   384,   385,     0,    39,    40,
      41,   715,     0,    42,    43,    44,     0,    45,    46,    47,
       0,     0,    48,     0,     0,    49,     0,    50,    51,   373,
     374,     0,     0,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,   373,   374,     0,    55,   375,   376,
     377,   378,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,    57,
       0,     0,     0,     0,    58,     0,     0,    59,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,     0,   373,
     374,     0,   716,   375,   376,   377,   378,   379,   380,   381,
     373,   374,     0,     0,   375,   376,   377,   378,   379,   380,
     381,   373,   374,     0,     0,   375,   376,   377,   378,   379,
     380,   381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,     0,   373,   374,     0,   779,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   383,   384,   385,
       0,   373,   374,     0,   800,   375,   376,   377,   378,   379,
     380,   381,   373,   374,     0,     0,   375,   376,   377,   378,
     379,   380,   381,   373,   374,     0,     0,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,     0,     0,     0,     0,   801,
       0,     0,   382,   383,   384,   385,     0,     0,     0,     0,
     808,     0,     0,   382,   383,   384,   385,     0,   373,   374,
       0,   811,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,     0,   373,   374,     0,   812,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,     0,
       0,   817,     0,     0,   382,   383,   384,   385,     0,     0,
       0,     0,   872,     0,     0,   382,   383,   384,   385,     0,
     373,   374,     0,   877,   375,   376,   377,   378,   379,   380,
     381,   373,   374,     0,     0,   375,   376,   377,   378,   379,
     380,   381,   373,   374,     0,     0,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
     382,   383,   384,   385,     0,   373,   374,     0,   888,   375,
     376,   377,   378,   379,   380,   381,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   382,   383,   384,   385,     0,
     373,   374,     0,   934,   375,   376,   377,   378,   379,   380,
     381,   373,   374,     0,     0,   375,   376,   377,   378,   379,
     380,   381,   373,   374,     0,     0,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,     0,     0,     0,     0,
     935,     0,     0,   382,   383,   384,   385,     0,     0,     0,
       0,   964,     0,     0,   382,   383,   384,   385,     0,   373,
     374,     0,  1015,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
     385,     0,   373,   374,     0,  1030,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,     0,     0,     0,     0,
    1065,     0,     0,   382,   383,   384,   385,     0,     0,   689,
       0,     0,     0,     0,   382,   383,   384,   385,   373,   374,
     690,     0,   375,   376,   377,   378,   379,   380,   381,   373,
     374,     0,     0,   375,   376,   377,   378,   379,   380,   381,
     373,   374,     0,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,   373,   374,   691,     0,   375,
     376,   377,   378,   379,   380,   381,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,   373,   374,
     692,     0,   375,   376,   377,   378,   379,   380,   381,   373,
     374,     0,     0,   375,   376,   377,   378,   379,   380,   381,
     373,   374,     0,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   383,   384,   385,     0,     0,   693,     0,     0,     0,
       0,   382,   383,   384,   385,     0,     0,   696,     0,     0,
       0,     0,   382,   383,   384,   385,   373,   374,   699,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
     385,   373,   374,   700,     0,   375,   376,   377,   378,   379,
     380,   381,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   383,   384,   385,     0,     0,   702,     0,     0,     0,
       0,   382,   383,   384,   385,     0,     0,   703,     0,     0,
       0,     0,   382,   383,   384,   385,   373,   374,   704,     0,
     375,   376,   377,   378,   379,   380,   381,   373,   374,     0,
       0,   375,   376,   377,   378,   379,   380,   381,   373,   374,
       0,     0,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,   373,   374,   705,     0,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   384,   385,   373,   374,   706,
       0,   375,   376,   377,   378,   379,   380,   381,   373,   374,
       0,     0,   375,   376,   377,   378,   379,   380,   381,   373,
     374,     0,     0,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,     0,     0,   707,     0,     0,     0,     0,   382,
     383,   384,   385,     0,     0,   709,     0,     0,     0,     0,
     382,   383,   384,   385,   373,   374,   719,     0,   375,   376,
     377,   378,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,   373,   374,
     720,     0,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   382,
     383,   384,   385,     0,     0,   722,     0,     0,     0,     0,
     382,   383,   384,   385,     0,     0,   725,     0,     0,     0,
       0,   382,   383,   384,   385,   373,   374,   747,     0,   375,
     376,   377,   378,   379,   380,   381,   373,   374,     0,     0,
     375,   376,   377,   378,   379,   380,   381,   373,   374,     0,
       0,   375,   376,   377,   378,   379,   380,   381,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   383,   384,   385,
     373,   374,   783,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   383,   384,   385,   373,   374,   880,     0,   375,   376,
     377,   378,   379,   380,   381,   373,   374,     0,     0,   375,
     376,   377,   378,   379,   380,   381,   373,   374,     0,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
     385,     0,     0,   897,     0,     0,     0,     0,   382,   383,
     384,   385,     0,     0,   898,     0,     0,     0,     0,   382,
     383,   384,   385,   373,   374,   905,     0,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,   373,   374,   906,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   383,   384,   385,
       0,     0,   907,     0,     0,     0,     0,   382,   383,   384,
     385,     0,     0,   912,     0,     0,     0,     0,   382,   383,
     384,   385,   373,   374,   913,     0,   375,   376,   377,   378,
     379,   380,   381,   373,   374,     0,     0,   375,   376,   377,
     378,   379,   380,   381,   373,   374,     0,     0,   375,   376,
     377,   378,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   382,   383,   384,   385,   373,
     374,   916,     0,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,   373,   374,   917,     0,   375,   376,   377,   378,
     379,   380,   381,   373,   374,     0,     0,   375,   376,   377,
     378,   379,   380,   381,   373,   374,     0,     0,   375,   376,
     377,   378,   379,   380,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,     0,     0,
     918,     0,     0,     0,     0,   382,   383,   384,   385,     0,
       0,   919,     0,     0,     0,     0,   382,   383,   384,   385,
     373,   374,   920,     0,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,   373,   374,   923,     0,   375,
     376,   377,   378,   379,   380,   381,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,     0,     0,
     924,     0,     0,     0,     0,   382,   383,   384,   385,     0,
       0,   927,     0,     0,     0,     0,   382,   383,   384,   385,
     373,   374,   933,     0,   375,   376,   377,   378,   379,   380,
     381,   373,   374,     0,     0,   375,   376,   377,   378,   379,
     380,   381,   373,   374,     0,     0,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,   373,   374,   936,     0,
     375,   376,   377,   378,   379,   380,   381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   384,
     385,   373,   374,   950,     0,   375,   376,   377,   378,   379,
     380,   381,   373,   374,     0,     0,   375,   376,   377,   378,
     379,   380,   381,   373,   374,     0,     0,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   384,   385,     0,     0,   992,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,   996,
       0,     0,     0,     0,   382,   383,   384,   385,   373,   374,
    1006,     0,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   383,
     384,   385,   373,   374,  1016,     0,   375,   376,   377,   378,
     379,   380,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,  1018,
       0,     0,     0,     0,   382,   383,   384,   385,     0,     0,
    1019,     0,     0,     0,     0,   382,   383,   384,   385,   373,
     374,  1021,     0,   375,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   383,   384,   385,     0,     0,  1053,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   384,   385,     0,     0,
    1064,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   384,   385,     0,     0,  1083
};

static const yytype_int16 yycheck[] =
{
      11,     0,   293,     0,    85,    82,    41,    42,    34,    11,
      11,     9,    10,    24,   253,   254,    27,   789,   790,    30,
      31,    32,    71,    10,    15,    36,    37,    38,     4,    57,
      24,     7,     4,   175,    45,     7,   175,    35,    71,     3,
     182,   180,   175,     7,     8,     9,    57,   180,    47,    43,
      47,     3,    43,     4,     5,     7,     8,     9,    66,    67,
      68,    69,    70,    71,    57,    11,    59,    60,    79,    37,
      38,   175,   175,    84,     4,     5,    11,   180,   182,    66,
      67,    68,    69,    70,    71,   175,    85,   179,    85,    57,
     180,   102,   182,    12,    72,   175,   175,   179,    87,    88,
     180,   180,   182,   182,    66,    67,    68,    69,    70,    71,
      99,   188,   189,   194,     3,    27,    62,    63,     7,     8,
      66,    67,    68,    69,    70,    71,    72,    62,    63,     7,
     179,    66,    67,    68,    69,    70,    71,    72,    69,    70,
      71,    72,     4,    62,    63,     7,   179,    66,    67,    68,
      69,    70,    71,    72,    83,   183,   175,    66,    67,    68,
      69,    70,    71,   182,   175,   176,   180,   175,   182,    90,
     257,   258,   180,   175,   182,   126,   127,   128,   105,   175,
     182,   182,   193,     0,   956,    43,   182,   959,   175,   200,
     183,   217,   218,   175,   175,   194,   179,   194,   176,   177,
     182,   182,   237,   179,   443,   282,   283,   179,   243,   244,
     174,   175,   223,   175,   225,   180,   175,   182,   180,   458,
     459,   180,   174,   175,    70,    71,    72,   175,   174,   175,
     176,   177,   180,   268,   269,   270,   182,     4,     5,   174,
     175,   176,   177,   174,   175,   176,   177,    67,   259,    69,
      70,    71,    72,   179,   493,   174,   175,   176,   177,   294,
     271,    34,    35,   179,   175,   276,   175,   175,   345,   346,
     357,   182,   359,   182,   182,   286,   287,  1049,   289,   290,
     291,   179,    71,    72,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   180,   179,   182,   175,    72,   320,
     321,   322,   323,   324,   182,   326,   180,   328,   182,   175,
     175,   402,   290,   291,   180,   180,   182,   182,   174,   175,
     176,   177,   343,     4,     5,   175,   175,   348,   306,   416,
     417,   180,   182,   182,   421,   422,    66,    67,    68,    69,
      70,    71,    71,   175,   174,   175,   176,   177,   180,     5,
     182,     4,     5,     9,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   343,    66,    67,    68,    69,
      70,    71,    71,   175,    30,   174,   175,   176,   177,   470,
     182,   175,   403,    23,   175,   175,   180,   408,   182,   180,
     426,   182,   182,   402,   439,   402,     4,   442,   419,   420,
     174,   175,   176,   177,    45,   180,   179,   182,    13,   175,
      15,   432,    17,   434,   180,   175,   182,   179,     4,     5,
     180,    62,    63,   444,   445,    66,    67,    68,    69,    70,
      71,    72,   453,   454,   455,    40,   179,   175,    43,   181,
     182,   175,   180,    48,   100,   175,   102,   456,   182,   456,
     180,   179,   473,   754,    81,    82,   757,   175,    13,   175,
      15,   470,    17,   470,   182,    13,   182,    15,   175,    17,
     126,   127,   128,   180,   175,   175,   132,   133,   134,   175,
     136,   182,   138,   139,   140,    40,     4,     5,    43,   145,
     146,   147,    40,    48,   150,    43,   152,   175,   154,   179,
      48,   157,   180,   159,   591,   592,   162,   594,   595,   165,
     166,   167,   168,    58,   170,   179,   172,    67,    68,    69,
      70,    71,    72,   179,   180,   175,    45,   175,     4,     5,
     180,    57,   180,   174,   175,   176,   177,   175,   182,    84,
      85,    86,   180,    62,    63,   179,    91,    66,    67,    68,
      69,    70,    71,    72,    48,    49,   175,   578,   579,    19,
      20,   180,   649,     4,     5,    38,    39,    62,   576,   577,
     819,    66,    67,    68,    69,    70,    71,    72,   175,   175,
     175,   175,   175,   180,   180,   180,   180,   180,   175,   838,
     611,     4,     5,   180,   175,   179,   617,   618,   180,   180,
     621,   646,    62,    63,    59,    60,    66,    67,    68,    69,
      70,    71,    72,   179,   635,   175,   175,   662,   663,   182,
     180,   180,   179,   175,   174,   175,   176,   177,   180,   650,
     651,   652,   179,    13,   175,    15,   175,    17,   175,   180,
     661,   180,   687,   180,   175,   175,   667,   668,   182,   180,
     180,   179,   673,   674,   675,   174,   175,   176,   177,   179,
      40,   175,   179,    43,   685,   686,   180,   688,    48,   179,
     175,   175,   179,   175,   695,   180,   180,   698,   180,   174,
     175,   176,   177,   179,   775,   182,   179,   708,   179,   179,
     711,   712,   713,   179,   715,   716,    66,    67,    68,    69,
      70,    71,    72,   724,   179,   179,     5,   179,   179,   179,
     179,   798,   799,   179,   174,   175,   176,   177,   179,   182,
     179,   179,   179,    50,    42,   179,   179,   179,   179,   750,
     751,   752,   753,   179,   179,    62,    63,   179,   182,    66,
      67,    68,    69,    70,    71,    72,    62,    63,   179,   179,
      66,    67,    68,    69,    70,    71,    72,   179,   779,   179,
     179,   179,   179,   179,   179,   179,   775,   179,   775,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   800,
     801,   179,   179,   179,   805,   806,   179,   179,   179,   179,
     811,   812,   179,   179,   881,   882,   179,    15,   179,    71,
      18,   179,   179,   179,   174,   175,   176,   177,   179,    27,
     179,   179,   179,    31,    32,   179,   179,   179,    36,   179,
     179,   179,    72,    42,   180,   182,   180,   805,   806,   180,
      48,    49,    50,   179,   179,   182,   179,   179,   182,    57,
      58,    59,   180,   180,    45,   179,   867,   174,   175,   176,
     177,   872,     9,   861,   862,   179,   877,   902,   174,   175,
     176,   177,   179,    81,   180,    42,   182,   182,   182,   182,
     182,   182,   180,   180,   180,    80,   180,   182,   179,   900,
     180,   179,    80,   904,   180,   182,   180,   182,   180,   180,
     180,   180,   180,   179,   915,   986,   987,   179,     5,   180,
     180,   922,   180,   180,    57,   179,   182,   182,   929,   180,
     931,   180,   180,   180,   935,   179,   182,   180,   179,    42,
     180,   180,    37,    42,   179,    71,   180,   180,     5,    71,
      71,   952,     9,    47,   180,    57,  1027,   180,   179,   179,
      46,   179,   179,    71,   180,   180,  1037,    37,   969,  1040,
       4,    47,    47,    30,   293,   456,   667,   593,   176,   426,
    1011,   596,   867,  1054,  1081,   787,  1033,   988,   186,    -1,
      -1,   436,    -1,   423,    -1,   193,    -1,   986,   987,   986,
     987,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1012,    -1,    -1,  1015,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,  1030,
    1031,    -1,    -1,    -1,    -1,    -1,   234,    -1,  1027,    -1,
    1027,    -1,    -1,   100,    -1,   102,    -1,    -1,  1037,    -1,
    1037,  1040,    -1,  1040,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,  1065,  1054,    -1,  1054,    -1,   126,
     127,   128,    -1,    -1,   272,   132,   133,   134,   276,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   290,   150,    -1,   152,    -1,   154,    -1,    -1,
     157,    -1,   159,    -1,    -1,   162,    -1,    -1,   165,   166,
     167,   168,    -1,   170,    -1,   172,    -1,   315,   316,   317,
     318,   319,   179,   180,    -1,    -1,    -1,   325,    -1,   327,
      -1,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,    -1,    -1,   347,
      -1,   349,   350,   351,   352,   353,    -1,    -1,   356,    -1,
     358,    -1,   360,    -1,    -1,    -1,   364,   365,   366,   367,
     368,   369,   370,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,   405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   431,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,   453,   454,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   614,    62,    63,   617,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,
      -1,    -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,
     678,   679,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,    -1,   138,   139,   140,    -1,    30,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,
     154,    -1,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,
     718,   165,   166,   167,   168,    -1,   170,    -1,   172,   174,
     175,   176,   177,    -1,    -1,   179,   180,   735,   736,    -1,
      -1,    -1,    -1,    -1,     5,   743,    -1,    -1,     9,   174,
     175,   176,   177,    -1,    -1,   180,    -1,   182,   756,    -1,
      -1,   759,   760,    -1,    -1,    -1,    -1,    -1,   100,    30,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   782,    -1,   784,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,   807,
     808,   809,    -1,   145,   146,   147,    -1,    -1,   150,   817,
     152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,    -1,
     162,    92,    -1,   165,   166,   167,   168,    -1,   170,   100,
     172,   102,    -1,    -1,    -1,    62,    63,   179,   180,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,   867,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
     888,   152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,    -1,   165,   166,   167,   168,    -1,   170,
      -1,   172,    -1,   911,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,   926,    66,
      67,    68,    69,    70,    71,    72,   934,    -1,    -1,    -1,
     938,    -1,    -1,   941,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   954,   174,   175,   176,
     177,    -1,    -1,   180,    -1,   963,   964,   965,   966,   967,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1029,    62,    63,    64,    65,  1034,   174,   175,   176,
     177,    -1,    -1,   180,    -1,   182,    76,    -1,    -1,    79,
      -1,    62,    63,    -1,    84,    66,    67,    68,    69,    70,
      71,    72,    92,    -1,    -1,  1063,    96,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
      -1,   161,   162,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,     3,     4,     5,   179,
       7,     8,     9,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,
      -1,   182,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      62,    63,    79,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,     3,
       4,     5,   179,     7,     8,     9,   183,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,    -1,
     182,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
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
     154,    -1,   156,   157,   158,   159,    -1,   161,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,     3,     4,     5,   179,     7,     8,     9,   183,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    29,    30,
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
     161,   162,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,   180,
       3,     4,     5,    -1,     7,     8,     9,    -1,   174,   175,
     176,   177,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
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
     153,   154,    -1,   156,   157,   158,   159,    -1,   161,   162,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,   180,     3,     4,
       5,    -1,     7,     8,     9,    -1,   174,   175,   176,   177,
      -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    79,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    96,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,    -1,   161,   162,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,   180,     3,     4,     5,    -1,
       7,     8,     9,    -1,    11,    -1,    -1,   174,   175,   176,
     177,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
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
     167,   168,   169,   170,   171,   172,   173,   174,    -1,     3,
       4,     5,   179,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
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
     154,    -1,   156,   157,   158,   159,    -1,   161,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,     3,     4,     5,   179,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    29,    30,
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
     161,   162,    -1,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,     3,     4,     5,   179,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,
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
     158,   159,    -1,   161,   162,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,     5,    62,
      63,   179,     9,    66,    67,    68,    69,    70,    71,    72,
      -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    -1,   180,    -1,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    30,   136,
      -1,   138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   100,   150,   102,   152,    -1,   154,    -1,    -1,
     157,    -1,   159,    -1,    -1,   162,    -1,    -1,   165,   166,
     167,   168,    -1,   170,    -1,   172,    -1,    -1,   126,   127,
     128,    -1,   179,    -1,   132,   133,   134,    -1,   136,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,   100,   157,
     102,   159,    -1,    -1,   162,    -1,    -1,   165,   166,   167,
     168,    -1,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,    -1,   138,   139,   140,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,
     152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,    -1,
     162,    -1,    -1,   165,   166,   167,   168,    -1,   170,    -1,
     172,    -1,     4,     5,     6,    -1,    -1,   179,    10,    -1,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,   101,
      -1,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
       4,     5,     6,   155,    -1,    -1,    10,    -1,   160,    -1,
      14,   163,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,   174,   175,   176,   177,    -1,
      84,    85,    86,   182,    -1,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,     4,     5,
       6,   155,    -1,    -1,    10,    -1,   160,    -1,    14,   163,
      16,    -1,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    -1,    62,    63,    60,    61,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,   174,   175,   176,   177,    -1,    84,    85,
      86,   182,    -1,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,   103,   104,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    62,    63,    -1,   133,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,    62,
      63,    -1,   182,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    62,    63,    -1,   182,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
      -1,    62,    63,    -1,   182,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,   182,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,
     182,    -1,    -1,   174,   175,   176,   177,    -1,    62,    63,
      -1,   182,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    -1,    62,    63,    -1,   182,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,
      -1,   182,    -1,    -1,   174,   175,   176,   177,    -1,    -1,
      -1,    -1,   182,    -1,    -1,   174,   175,   176,   177,    -1,
      62,    63,    -1,   182,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    -1,    62,    63,    -1,   182,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,
      62,    63,    -1,   182,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,
     182,    -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,
      -1,   182,    -1,    -1,   174,   175,   176,   177,    -1,    62,
      63,    -1,   182,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,    -1,    62,    63,    -1,   182,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,    -1,    -1,
     182,    -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,    63,
     180,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    62,    63,   180,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,    63,
     180,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    62,    63,   180,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,    62,    63,   180,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    62,    63,   180,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    62,    63,   180,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,    62,    63,   180,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   174,
     175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    62,    63,   180,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,    63,
     180,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    62,    63,   180,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
      62,    63,   180,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    62,    63,   180,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   174,
     175,   176,   177,    62,    63,   180,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    62,    63,   180,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,    -1,    -1,   180,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    62,    63,   180,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,
      63,   180,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    62,    63,   180,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,
      -1,   180,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
      62,    63,   180,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    62,    63,   180,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,
      -1,   180,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
      62,    63,   180,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    62,    63,   180,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,    62,    63,   180,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,    63,
     180,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,    62,    63,   180,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   174,   175,   176,   177,    62,
      63,   180,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,    -1,    -1,   180
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
     185,   186,   188,   195,   196,   198,   199,   203,   215,   216,
     221,   227,   234,   242,   250,   253,   257,   260,   266,    71,
     179,    71,   179,   235,   254,   258,     4,     7,   213,   213,
     213,     3,     4,     5,     7,     8,     9,    29,    30,    33,
      62,    63,    64,    65,    76,    79,    96,    97,   100,   102,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   156,
     157,   158,   159,   161,   162,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   179,   201,   202,   204,
     210,   212,   215,   216,   189,   190,   179,   201,   179,   179,
     201,    27,     7,   243,   251,   204,    57,    59,    60,   183,
     289,   193,   201,   204,     4,     5,   214,   204,   201,   204,
     201,   204,     4,     5,   277,   278,     9,   174,   175,   211,
     212,   279,   213,    84,    92,   183,   201,   204,   290,    84,
      92,   105,   290,   290,    83,   204,   209,    11,    52,   209,
     209,    58,    84,    85,    86,    91,    90,   204,   196,   203,
     215,   216,   201,   201,   201,   105,   179,   179,   179,   179,
     179,   201,   290,   201,   201,     0,    43,   187,    87,    88,
      99,    71,    71,    23,   204,   217,   218,   201,   217,     4,
     204,   186,   179,   179,    34,    35,   179,   179,   204,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   204,   201,   204,    66,    67,    68,    69,    70,    71,
     175,    19,    20,    62,    63,    66,    67,    68,    69,    70,
      71,    72,   174,   175,   176,   177,     4,     5,   228,   229,
       4,     5,   230,   231,   201,   217,   217,   201,   204,   245,
     186,   261,   267,   179,    57,   179,     4,     7,   179,   201,
     204,   280,    57,   183,   282,   287,   179,   179,   182,   182,
     182,   179,   179,   182,   212,   212,   182,   204,   201,   204,
      10,   182,   182,   201,   182,   209,   194,    11,   182,   197,
     182,   209,    11,   209,   197,   197,     5,   200,   200,   200,
     180,   204,   201,   182,   182,   182,    42,   209,   209,   209,
     204,   201,   222,   180,   201,   204,   219,   220,   180,    71,
     255,    13,    15,    17,    40,    43,    48,   259,   217,   217,
     204,   204,   204,    92,   201,   290,   290,     4,     5,   207,
     208,   207,   208,   209,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   290,   204,   204,   204,   204,
     204,   204,   204,   180,   204,   201,   201,   201,   201,   201,
     204,   204,   204,   180,   204,   204,   201,   204,   201,   204,
     201,   201,   180,   201,   180,   201,   180,   201,   180,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   290,
     201,   217,   217,   201,   204,   201,   201,   201,   201,   201,
     180,   180,   201,   200,   201,   200,   201,   180,   180,   201,
     201,   201,   201,   201,   201,   201,   191,   192,   206,   205,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   179,   179,   182,   179,   179,   182,   180,   180,    42,
     244,    13,    15,    17,    40,    43,    48,   252,    45,   186,
     204,   179,   201,   204,    50,   281,   181,   182,   179,     4,
       7,   179,     9,   288,   217,   217,     4,     5,   204,   204,
     217,   217,   278,     9,   211,   182,    81,    82,    92,   201,
     204,   204,   282,   209,   201,   209,   197,   204,   204,   179,
     182,   182,   182,   180,   180,   201,   204,   201,   204,   204,
     188,   182,   197,   197,     4,     5,   226,   182,   236,   186,
     204,   180,   180,   182,   182,   182,   180,   180,   182,   182,
     180,   179,   179,   180,   180,   182,   182,   197,   182,   180,
     180,   180,   180,   180,   180,   182,   180,   180,   182,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   182,   180,
     180,   182,   182,   182,   180,   182,   182,   180,   182,   180,
     180,   180,   180,   180,   182,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   182,   182,   180,   180,   180,
     180,   180,   180,   182,   180,   180,   180,   180,   180,   180,
     182,   182,   182,   182,   182,   180,   182,   182,   180,   182,
     182,   213,   291,   213,   292,   204,   204,   217,   217,   229,
     217,   217,   231,    42,   246,   262,    48,    49,   268,   182,
     204,   180,   182,   180,   179,   201,   201,   204,   204,   283,
     284,   204,     4,     5,   274,   276,   180,   180,   179,   179,
     182,   182,   180,   180,   204,    80,    80,   182,   182,   182,
     209,   182,   182,   217,   204,   204,   204,   182,   204,   209,
     209,   223,   220,   204,    15,    43,   256,   204,   204,   204,
     201,    92,   201,   180,   180,   204,   204,   209,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   201,   204,   201,
     201,   201,   204,   204,   204,   204,   208,   201,   208,   201,
     201,   182,   182,   180,   180,   180,   180,    38,    39,   248,
     186,   204,   182,    57,   201,   201,   281,   182,   274,   274,
     180,   179,   179,   182,   217,   217,   204,   204,   182,   290,
     290,   201,   201,   201,   204,   204,   180,   180,   180,   180,
     182,   201,   197,   179,    11,   180,   180,   180,   180,   180,
     180,   182,   180,   180,   180,   197,   180,   180,   180,   180,
     180,   180,   182,   180,   180,   180,   182,   180,   180,   182,
     180,   182,   180,   180,   182,   182,   180,   180,   182,   180,
     180,   182,   180,   180,   213,   213,   245,    42,    37,   263,
     180,   204,   179,   180,   182,   204,   285,   217,   217,   275,
     180,   180,   201,   182,   182,    71,    71,    71,   204,   182,
     209,     4,     5,   232,   233,   204,   201,   204,   204,   201,
     204,   204,   201,   204,   201,   201,   247,   249,    47,   270,
      59,    60,   180,   204,    57,   201,   180,   274,   180,   180,
     274,   201,   201,   201,   201,   201,   180,   204,   179,   179,
     180,   182,    12,   240,   180,   182,   180,   180,   180,   180,
     180,   180,   180,   180,   186,   186,   204,    46,   269,   179,
     182,   179,   180,   286,    71,   180,   180,   224,   233,   204,
     237,   204,    45,   273,   186,   264,   201,   204,   204,   288,
     201,   186,   186,   180,   271,    13,    15,    17,    40,    43,
      48,   265,   180,   182,   180,   182,   274,    24,    43,   225,
     238,   186,   201,   204,    13,    15,    17,    40,    43,    48,
     239,   272,   180,   180,     4,   241,   270
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   184,   185,   186,   187,   186,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   188,   190,   188,   188,   188,
     188,   188,   188,   188,   191,   188,   192,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   193,   188,
     194,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   196,
     196,   197,   197,   198,   198,   198,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   203,   203,   205,
     204,   206,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   207,   208,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   211,   212,   212,   212,   213,   213,
     214,   214,   214,   214,   215,   216,   218,   217,   219,   219,
     219,   220,   220,   222,   223,   224,   221,   225,   225,   226,
     226,   227,   227,   227,   227,   228,   228,   229,   229,   229,
     229,   230,   230,   231,   231,   231,   231,   232,   232,   232,
     233,   233,   233,   233,   235,   236,   237,   238,   234,   239,
     239,   239,   239,   239,   239,   240,   240,   241,   241,   243,
     242,   244,   244,   245,   245,   246,   247,   246,   248,   249,
     248,   251,   250,   252,   252,   252,   252,   252,   252,   254,
     255,   253,   256,   256,   258,   257,   259,   259,   259,   259,
     259,   259,   261,   262,   263,   264,   260,   265,   265,   265,
     265,   265,   265,   267,   266,   268,   268,   269,   269,   270,
     271,   272,   270,   273,   273,   274,   275,   274,   276,   276,
     276,   276,   277,   277,   278,   278,   278,   278,   279,   279,
     279,   279,   280,   280,   280,   280,   280,   281,   281,   281,
     283,   282,   284,   282,   285,   282,   286,   282,   287,   282,
     288,   288,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   290,   290,   291,   291,
     292,   292
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
       0,     1,     1,     2,     2,     3,    10,     8,     8,     8,
       3,     1,     1,     6,     4,     4,     6,     6,     4,     6,
       1,     4,     1,     1,     1,     1,     3,     3,     6,     6,
       8,     6,     4,     6,     8,     1,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       1,     3,     1,     3,     4,     6,     6,     4,     6,     4,
       6,    10,     4,     4,     4,     8,     6,     3,     3,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       4,     6,     1,     4,     4,     6,     6,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     8,     4,     4,     4,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     6,     6,     6,
       4,     8,     6,     8,     6,     4,     4,     4,     6,     6,
       6,     8,     1,     2,     2,     1,     1,     1,     1,     1,
       4,     6,     4,     6,     4,     4,     0,     2,     0,     1,
       3,     1,     1,     0,     0,     0,    11,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     3,     1,     1,     4,
       4,     1,     3,     1,     1,     4,     4,     0,     1,     3,
       1,     1,     3,     3,     0,     0,     0,     0,    14,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     1,     0,
       7,     1,     2,     1,     1,     0,     0,     5,     0,     0,
       4,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       0,     6,     1,     1,     0,     4,     1,     2,     1,     1,
       1,     1,     0,     0,     0,     0,    11,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     1,     0,     2,     0,
       0,     0,     7,     0,     1,     1,     0,     4,     1,     4,
       1,     4,     1,     3,     1,     4,     1,     4,     1,     1,
       3,     3,     0,     2,     4,     1,     3,     0,     2,     6,
       0,     4,     0,     4,     0,     6,     0,     9,     0,     3,
       0,     1,     0,     2,     2,     4,     1,     4,     6,     6,
       7,    10,    12,     7,    10,    12,     2,     1,     1,     3,
       1,     3
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

    {create_function(fFRNBF_ALLOC);}

    break;

  case 158:

    {create_function(fFRNBF_DUMP);}

    break;

  case 159:

    {create_function(fFRNBF_DUMP2);}

    break;

  case 160:

    {create_function(fDATE);}

    break;

  case 161:

    {create_function(fDATE);}

    break;

  case 162:

    {create_function(fTIME);}

    break;

  case 163:

    {create_function(fTIME);}

    break;

  case 164:

    {create_function(fPEEK2);}

    break;

  case 165:

    {create_function(fPEEK3);}

    break;

  case 166:

    {add_command(cTOKENALT2,NULL,NULL);}

    break;

  case 167:

    {add_command(cTOKENALT,NULL,NULL);}

    break;

  case 168:

    {add_command(cSPLITALT2,NULL,NULL);}

    break;

  case 169:

    {add_command(cSPLITALT,NULL,NULL);}

    break;

  case 170:

    {create_function(fGETBIT);}

    break;

  case 171:

    {create_function(fGETCHAR);}

    break;

  case 172:

    {create_function(fHEX);}

    break;

  case 173:

    {create_function(fBIN);}

    break;

  case 174:

    {create_execute(1);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 175:

    {create_function(fFRNBF_GET_STRING);}

    break;

  case 176:

    {create_function(fFRNBF_GET_BUFFER);}

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

    {create_function(fFRNFN_CALL);}

    break;

  case 250:

    {create_function(fFRNFN_SIZE);}

    break;

  case 251:

    {create_function(fFRNBF_GET_NUMBER);}

    break;

  case 252:

    {create_function(fFRNBF_SIZE);}

    break;

  case 253:

    {create_function(fPEEK4);}

    break;

  case 254:

    {create_function(fPEEK);}

    break;

  case 255:

    {create_function(fMOUSEX);}

    break;

  case 256:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 258:

    {create_function(fMOUSEY);}

    break;

  case 259:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 261:

    {create_function(fMOUSEB);}

    break;

  case 262:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 263:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 264:

    {create_function(fMOUSEMOD);}

    break;

  case 265:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 266:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 267:

    {create_function(fAND);}

    break;

  case 268:

    {create_function(fOR);}

    break;

  case 269:

    {create_function(fEOR);}

    break;

  case 270:

    {create_function(fTELL);}

    break;

  case 271:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 272:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 273:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 274:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 275:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 276:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 277:

    {create_myopen(0);}

    break;

  case 278:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 279:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 280:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 281:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 282:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 283:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 284:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 285:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 286:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 287:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 288:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 289:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 290:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 291:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 292:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 293:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 294:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 295:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 296:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 303:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 304:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 305:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 306:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 307:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 308:

    {missing_endsub--;}

    break;

  case 309:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 310:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 311:

    {exported=FALSE;}

    break;

  case 312:

    {exported=TRUE;}

    break;

  case 313:

    {exported=FALSE;}

    break;

  case 314:

    {exported=TRUE;}

    break;

  case 317:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 318:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 319:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 320:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 323:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 324:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 325:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 326:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 330:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 331:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 332:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 333:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 334:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 335:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 336:

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

  case 337:

    {
             swap();popgoto();poplabel();}

    break;

  case 338:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 339:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 340:

    {missing_next--;}

    break;

  case 341:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 342:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 343:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 344:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 345:

    {create_pushdbl(1);}

    break;

  case 347:

    {pop(stSTRING);}

    break;

  case 348:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 349:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 350:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 356:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 357:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 359:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 361:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 363:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 364:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 365:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 366:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 367:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 368:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 369:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 370:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 372:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 373:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 374:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 376:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 377:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 378:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 379:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 380:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 381:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 382:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 383:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 384:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 385:

    {poplabel();}

    break;

  case 387:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 388:

    {missing_endif--;}

    break;

  case 389:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 390:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 391:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 392:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 393:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 395:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 396:

    {poplabel();}

    break;

  case 400:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 401:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 406:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 408:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 409:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 410:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 411:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 414:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 415:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 416:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 417:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 418:

    {create_strdata((yyvsp[0].string));}

    break;

  case 419:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 420:

    {create_strdata((yyvsp[0].string));}

    break;

  case 421:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 425:

    {create_print('s');}

    break;

  case 426:

    {create_print('s');}

    break;

  case 427:

    {create_print('d');}

    break;

  case 428:

    {create_print('u');}

    break;

  case 429:

    {create_print('U');}

    break;

  case 430:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 431:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 432:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 433:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 434:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 435:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 436:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 437:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 438:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 439:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 440:

    {create_pushstr("?");create_print('s');}

    break;

  case 441:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 442:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 454:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 455:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 459:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 460:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 461:

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
