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
    tEOR = 321,
    tSHL = 322,
    tSHR = 323,
    tNEQ = 324,
    tLEQ = 325,
    tGEQ = 326,
    tLTN = 327,
    tGTN = 328,
    tEQU = 329,
    tPOW = 330,
    tREAD = 331,
    tDATA = 332,
    tRESTORE = 333,
    tOPEN = 334,
    tCLOSE = 335,
    tSEEK = 336,
    tTELL = 337,
    tAS = 338,
    tREADING = 339,
    tWRITING = 340,
    tORIGIN = 341,
    tWINDOW = 342,
    tDOT = 343,
    tLINE = 344,
    tCIRCLE = 345,
    tTRIANGLE = 346,
    tTEXT = 347,
    tCLEAR = 348,
    tFILL = 349,
    tPRINTER = 350,
    tWAIT = 351,
    tBELL = 352,
    tLET = 353,
    tARDIM = 354,
    tARSIZE = 355,
    tBIND = 356,
    tRECT = 357,
    tGETBIT = 358,
    tPUTBIT = 359,
    tGETCHAR = 360,
    tPUTCHAR = 361,
    tNEW = 362,
    tCURVE = 363,
    tSIN = 364,
    tASIN = 365,
    tCOS = 366,
    tACOS = 367,
    tTAN = 368,
    tATAN = 369,
    tEXP = 370,
    tLOG = 371,
    tSQRT = 372,
    tSQR = 373,
    tMYEOF = 374,
    tABS = 375,
    tSIG = 376,
    tINT = 377,
    tCEIL = 378,
    tFLOOR = 379,
    tFRAC = 380,
    tROUND = 381,
    tMOD = 382,
    tRAN = 383,
    tVAL = 384,
    tLEFT = 385,
    tRIGHT = 386,
    tMID = 387,
    tLEN = 388,
    tMIN = 389,
    tMAX = 390,
    tSTR = 391,
    tINKEY = 392,
    tCHR = 393,
    tASC = 394,
    tHEX = 395,
    tDEC = 396,
    tBIN = 397,
    tUPPER = 398,
    tLOWER = 399,
    tMOUSEX = 400,
    tMOUSEY = 401,
    tMOUSEB = 402,
    tMOUSEMOD = 403,
    tTRIM = 404,
    tLTRIM = 405,
    tRTRIM = 406,
    tINSTR = 407,
    tRINSTR = 408,
    tCHOMP = 409,
    tSYSTEM = 410,
    tSYSTEM2 = 411,
    tPEEK = 412,
    tPEEK2 = 413,
    tPOKE = 414,
    tFRNFN_CALL = 415,
    tFRNFN_CALL2 = 416,
    tFRNFN_SIZE = 417,
    tFRNBF_ALLOC = 418,
    tFRNBF_FREE = 419,
    tFRNBF_SIZE = 420,
    tFRNBF_DUMP = 421,
    tFRNBF_SET = 422,
    tFRNBF_GET = 423,
    tFRNBF_GET2 = 424,
    tFRNBF_GET_BUFFER = 425,
    tFRNBF_SET_BUFFER = 426,
    tDATE = 427,
    tTIME = 428,
    tTOKEN = 429,
    tTOKENALT = 430,
    tSPLIT = 431,
    tSPLITALT = 432,
    tGLOB = 433,
    UMINUS = 434
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
#define YYFINAL  271
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6071

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  466
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1110

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   434

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   188,     2,     2,     2,     2,
     184,   185,   181,   180,   187,   179,     2,   182,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   186,
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
     175,   176,   177,   178,   183
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
     501,   502,   503,   504,   505,   506,   509,   510,   511,   514,
     515,   516,   517,   520,   521,   524,   525,   526,   527,   530,
     533,   536,   536,   539,   540,   541,   544,   545,   548,   549,
     552,   548,   557,   558,   561,   562,   565,   566,   567,   568,
     571,   572,   575,   576,   577,   578,   581,   582,   585,   586,
     587,   588,   591,   592,   593,   596,   597,   598,   599,   602,
     603,   607,   621,   602,   626,   627,   628,   629,   630,   631,
     634,   635,   638,   639,   644,   644,   648,   649,   652,   653,
     657,   659,   658,   663,   664,   664,   668,   668,   674,   675,
     676,   677,   678,   679,   683,   684,   683,   690,   691,   695,
     695,   700,   701,   702,   703,   704,   705,   708,   709,   709,
     711,   708,   715,   716,   717,   718,   719,   720,   723,   723,
     728,   729,   732,   733,   736,   738,   740,   737,   744,   745,
     748,   749,   749,   752,   753,   755,   756,   760,   761,   764,
     765,   767,   768,   772,   773,   774,   775,   778,   779,   780,
     781,   782,   785,   786,   787,   790,   790,   791,   791,   792,
     792,   793,   793,   794,   794,   797,   798,   801,   802,   803,
     804,   805,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   817,   818,   820,   821,   824,   825
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
  "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT", "tEOR",
  "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN", "tEQU", "tPOW",
  "tREAD", "tDATA", "tRESTORE", "tOPEN", "tCLOSE", "tSEEK", "tTELL", "tAS",
  "tREADING", "tWRITING", "tORIGIN", "tWINDOW", "tDOT", "tLINE", "tCIRCLE",
  "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL", "tPRINTER", "tWAIT", "tBELL",
  "tLET", "tARDIM", "tARSIZE", "tBIND", "tRECT", "tGETBIT", "tPUTBIT",
  "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tSIN", "tASIN", "tCOS",
  "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF",
  "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD",
  "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX",
  "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER",
  "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tTRIM",
  "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2",
  "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE",
  "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP",
  "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2", "tFRNBF_GET_BUFFER",
  "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT",
  "tSPLITALT", "tGLOB", "'-'", "'+'", "'*'", "'/'", "UMINUS", "'('", "')'",
  "';'", "','", "'#'", "$accept", "program", "statement_list", "$@1",
  "statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,    45,
      43,    42,    47,   434,    40,    41,    59,    44,    35
};
# endif

#define YYPACT_NINF -798

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-798)))

#define YYTABLE_NINF -388

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4105,   -56,   -29,  -798,  -798,  -798,  -798,  -798,    96,    96,
      96,  3078,  -798,  -798,  -798,  3724,  -148,  -120,  3724,    45,
      94,  -798,  -798,  -798,  3434,     7,  -798,  3434,   330,  -798,
    3434,  3434,  3434,   349,    32,    96,  1805,  1188,  2169,    10,
    3434,  2900,  3434,   -28,    38,  3434,  -798,    90,  3724,  3724,
    3724,    31,   -24,    15,    20,    34,    51,  2169,  3724,  3724,
    3724,   156,   127,  -798,   -14,  -798,  -798,  -798,  -798,   141,
     164,  -798,   222,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    3434,  -798,  3724,  -798,   287,  3434,  3948,  -798,  -798,  -798,
    -798,  -798,  -798,   105,   129,  -798,  -798,  -798,  -798,   133,
     152,   410,   178,   210,  3434,   221,   242,   253,   280,   292,
     294,   298,   307,   311,   313,   337,   365,   392,   448,   467,
     471,   472,   473,   474,   475,   482,   483,   485,   488,   489,
     490,   491,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   508,   517,   518,   520,   521,   522,   523,   525,   532,
     547,   561,   562,   564,   566,   569,   570,   571,   576,   579,
     580,   581,   582,   594,   595,   599,   615,   616,   617,   618,
     619,   620,   621,   624,   625,   626,   629,   630,   631,   632,
    3434,  3434,   350,  -798,   481,  -798,  -798,  -798,  -798,   519,
     568,  3724,   145,  -798,  -798,   145,  -798,  -798,  3434,  3948,
     515,   635,   306,   636,    25,  3434,   -30,   350,  5889,   638,
     639,   220,  5889,   350,   698,   350,  1379,   642,   646,   248,
    -798,  -798,   181,   181,  -798,  -798,   302,  -798,  3434,  3724,
    3434,    11,  5889,   359,  -798,  -798,  -798,  -798,   438,  3724,
    1392,  -798,  3434,  -798,     5,   478,  -798,  -798,  3434,  3256,
    -798,  -798,  5889,  -798,  -798,   141,   164,   145,    -7,    -7,
    -798,   457,   457,   457,  2351,  3724,    36,   511,   145,   -12,
       6,  -798,  -798,   656,  3434,  3434,  3434,  3434,  3724,  -798,
    5889,   530,  3434,   145,   567,   710,  5889,   384,  -798,  -798,
    -798,  -798,  3434,  3434,   654,  3434,  3434,  3434,  1987,  2169,
     578,   578,  3434,  3434,  3434,  3434,  3434,  3434,  3434,  3434,
    3434,  3434,  3434,  3434,  2169,  3434,  3434,  3434,  3434,  3434,
    3434,  3434,  3434,  2534,  3724,  3724,  3724,  3724,  3724,  3434,
    3434,  3434,  2717,  3434,  3724,  3434,  3724,  3434,  3724,  3724,
     356,  1380,  1516,  1591,  3724,  3724,  3724,  3724,  3724,  3724,
    3724,  3724,  2169,  3724,  -798,  -798,  3724,  3434,  3724,  3724,
    3724,  3724,  3724,   612,   647,  3724,   457,  3724,   457,  3724,
     752,   259,   888,  3724,  3724,  3724,  3724,  3724,  3724,  3724,
    -798,  -798,  -798,  -798,  3434,  3434,  3434,  3434,  3434,  3434,
    3434,  3434,  3434,  3434,  3434,   655,   659,   644,  -798,   660,
     661,   651,  -798,   -94,   662,   667,   350,  5889,   797,   733,
     807,  3948,  3434,   670,  3724,  -798,  -798,  3434,   350,   669,
     373,   671,    26,  -798,   846,  -798,  -798,   592,  3434,  3434,
    -798,  -798,   349,  -798,  -798,    48,  1423,   145,  5889,   514,
    3588,  3434,   145,  3434,  -798,   -30,  -798,  -798,  3434,  3724,
    -798,  3434,     5,  3434,  3434,   673,   678,   679,   684,  -798,
    1709,   -68,  3434,  3434,  3434,  3434,  3948,   685,     5,     5,
    5889,   145,   604,  -798,   350,  5889,   686,  -798,  -798,  -798,
    3948,  -798,  -798,  3434,  -798,  -798,  -798,  -798,   689,   690,
    1639,  2001,  2183,  2368,  2551,   697,    92,   700,   704,   706,
     707,   708,   709,   713,   719,     5,  2734,  4598,  4611,  4646,
    4674,  4687,   717,  4731,   849,  4744,  4766,   722,  4807,  4820,
    4833,  4864,  4886,  4899,  4953,  2914,  -798,  4966,    21,    46,
      67,   103,    70,  3092,  3270,   914,  -798,  4984,  5019,   183,
    5032,   -88,  5045,   204,   275,  -798,   285,  -798,   286,  -798,
     288,  -798,   295,   299,   305,   323,   136,   208,   324,   331,
     333,   278,   723,   -69,   725,   726,   335,  5086,   347,   -13,
     223,   224,   228,  -798,  -798,   247,  -138,   249,   -83,   251,
    -798,  -798,   145,   145,   145,   145,   145,   145,  -798,    96,
      96,  3434,  3434,   464,   555,   190,    -3,   177,   -37,  -798,
     -52,   -52,   752,   752,  -798,  -798,   519,  -798,  -798,   568,
    -798,  -798,  -798,   852,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   585,  3448,  3434,    18,  5104,  3774,  -798,  -798,
    3434,  3434,  -798,  -798,  3434,  -798,   613,   730,   731,   745,
     746,  3637,  3993,   732,   747,  -798,  -798,  -798,  3434,   850,
     854,  -798,   260,  4150,  5889,  -798,  -798,   261,  -798,  3434,
    4301,  4314,  -798,  3434,  3434,  3434,  -798,  -798,   350,  5889,
     350,  5889,  4332,  4367,  -798,  3434,  3434,  3434,  -798,  -798,
    -798,  3434,  3434,     8,  5889,  -798,  -798,  3434,  3434,  3434,
    3434,  3434,  -798,  -798,  3724,  3638,  -798,   750,   753,  -798,
    -798,  3434,  3434,  3434,  3434,  -798,  -798,  -798,  -798,  -798,
    -798,  3434,  -798,  -798,  3434,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  3434,  -798,  -798,  3434,  3434,
    3434,  -798,  3434,  3434,  -798,  3724,  -798,  -798,  -798,  -798,
    -798,  3434,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  3724,  3724,  -798,  -798,  -798,  -798,  -798,  -798,
    3724,  -798,  -798,  -798,  -798,  -798,  -798,  3434,  3434,  3434,
    3434,   934,  -798,  3724,   934,  -798,  3724,  3724,  -798,   755,
    -798,   757,   654,  1557,   760,   761,  -798,   763,   764,  -798,
    -798,   600,  3948,  -798,  -798,  -798,  3434,  4380,   882,  3724,
    -798,  3724,   145,   350,   669,  4393,   613,   613,  5117,   766,
     769,  -798,   767,  -798,  -798,  -798,  -798,  3434,  3434,  -798,
    -798,  4434,  2169,  2169,  3724,  3724,  3724,  -798,  3434,  3434,
     770,  5165,  5178,  1041,  3724,  3724,  5889,     5,  -798,   772,
    -798,    63,  -798,  -798,  -798,  5206,  5237,  5250,  5263,  5298,
     362,   782,    89,  -798,  -798,  5326,  5339,   783,    50,  5383,
    5396,  5418,  5459,  5472,  1054,  5485,  5516,    93,  5538,   157,
     158,   363,  5551,  4452,  4465,  5605,    -4,   377,    49,   378,
     386,    96,    96,  -798,  -798,  -798,  -798,  3434,   922,   931,
     927,  5618,  3434,   787,   389,   180,  -798,  3434,  -798,  -798,
    -798,  -798,  -798,  -798,   788,   789,  5889,  5889,  3724,  -798,
    -798,   145,   145,   269,  4513,  5889,  -798,   898,   901,   906,
    3434,   270,   145,  3434,   643,  3434,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  3724,  -798,  -798,  -798,  3434,  -798,
    -798,  -798,  -798,  -798,  -798,  3434,  -798,  -798,  -798,  3724,
    -798,  -798,  3434,  -798,  3434,  -798,  -798,  3724,  3434,  -798,
    -798,  3724,  -798,  -798,  3724,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   942,   589,  5636,  3434,   924,  3724,  5671,   613,
     809,   811,   613,  -798,  -798,   145,  3724,  3724,  3724,  3724,
    3724,  5684,  3434,  -798,   808,   813,    83,  -798,    77,   390,
    4526,  5697,   427,  5738,  5756,   430,  5769,   431,   441,  3948,
    4262,  3434,   948,  -798,   814,  -798,  4554,   815,   451,  -798,
    -798,  -798,  -798,  -798,   145,   145,   145,   145,   145,   928,
    5889,   818,   819,  -798,   643,  3434,  -798,  -798,  3434,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,   927,   967,   531,
    3948,  -798,  3724,  3434,  3434,  -798,   846,  3724,  -798,  -798,
    3948,  -798,  5889,  3948,  5817,  -798,  -798,   927,   780,   212,
    5830,  4585,   613,   145,    19,   927,  -798,  3948,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  3724,  -798,  3434,  -798,
    -798,  -798,  -798,   887,   927,   453,  5858,  -798,  -798,  -798,
    -798,  -798,  -798,  1002,   942,  -798,  -798,  -798,  -798,  -798
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     111,     0,     0,   105,   339,   374,   379,    11,     0,     0,
       0,     0,    24,    26,   317,     0,     0,     0,     0,   318,
      18,    20,   354,   366,     0,   447,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   112,   113,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     4,     3,     0,     7,    39,    41,     9,    22,
      23,    21,     0,    13,    14,    17,    16,    15,    28,    29,
       0,   301,     0,   301,     0,     0,     6,   294,   293,    30,
      31,    38,   289,   199,   133,   290,   291,   292,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,     0,     0,     0,     0,
     258,   261,   264,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   212,   193,   198,   135,     0,
       0,     0,    12,   301,   301,    42,   319,    19,     0,     6,
     398,     0,   451,     0,     0,   427,   443,    62,    61,     0,
       0,    63,   104,    53,     0,    55,     0,   419,   421,    56,
     417,   423,     0,     0,   424,   286,    57,    59,     0,    89,
       0,     0,   462,     0,    86,    91,    79,    40,     0,     0,
       0,    67,     0,    50,    72,     0,    88,    87,     0,     0,
     114,   115,    92,     8,    10,     0,     0,   106,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,   308,
     178,     0,   303,   116,     0,     0,   375,     4,   301,   301,
      32,    33,     0,     0,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   301,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    36,   182,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   322,   323,    25,   320,   328,
     329,    27,   326,     0,     0,     0,   359,   358,     0,     4,
       0,     6,     0,     0,     0,   448,   449,     0,   430,   432,
      45,     0,     0,    49,   445,   301,   301,     0,     0,     0,
     301,   301,     0,   288,   287,     0,     0,    90,   461,     0,
       0,     0,    66,     0,    71,   443,   123,   122,     0,     0,
      68,     0,    74,     0,     0,   131,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
     179,   121,     0,   299,   306,   307,   302,   304,   300,   340,
       6,   386,   384,     0,   385,   381,   383,   380,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,   262,     0,   265,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   164,     0,     0,     0,     0,     0,
     138,   213,   207,   209,   211,   208,   210,   206,   137,     0,
       0,     0,     0,   186,   188,   190,   187,   189,   185,   204,
     201,   200,   202,   203,   301,   301,     0,   301,   301,     0,
      43,    44,   356,   360,   373,   371,   372,   369,   368,   370,
     367,   388,     4,     0,     0,     0,     0,     0,   428,    46,
      47,     0,   435,   437,     0,   446,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   418,   425,   426,     0,     0,
       0,   126,   125,   129,   216,    51,    69,    82,    73,     0,
       0,     0,   301,     0,     0,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     5,     0,     0,     0,   314,   315,
     309,     0,     0,     4,   382,   279,   175,     0,     0,     0,
       0,     0,   280,   281,     0,     0,   274,     0,     0,   194,
     195,     0,     0,     0,     0,   217,   218,   219,   220,   221,
     222,     0,   224,   225,     0,   227,   228,   191,   234,   235,
     229,   231,   232,   233,   230,     0,   237,   242,     0,     0,
       0,   241,     0,     0,   143,     0,   148,   149,   243,   173,
     244,     0,   174,   150,   151,   257,   260,   263,   266,   154,
     152,   153,     0,     0,   155,   250,   156,   256,   255,   165,
       0,   251,   157,   252,   158,   254,   159,     0,     0,     0,
       0,     0,   168,     0,     0,   170,     0,     0,   463,    35,
     465,    37,   183,   181,     0,     0,   321,     0,     0,   327,
     357,   363,     6,   400,   401,   399,     0,     0,   452,     0,
     450,     0,   433,   431,   432,     0,     0,     0,     0,   413,
     415,   444,   410,   295,   297,   301,   301,     0,     0,   420,
     422,    64,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,    85,     0,
     305,     0,   378,   377,   376,     0,     0,     0,     0,     0,
       0,     0,     0,   214,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,   325,   330,   331,     0,     0,     0,
     389,     0,     0,     0,     0,     0,   429,     0,   436,   438,
     439,   301,   301,   411,     0,     0,    52,    54,     0,   127,
     128,   124,   130,    83,    76,    77,   132,     0,     0,     0,
       0,   109,   110,     0,   332,     0,   269,   270,   271,   272,
     273,   282,   283,   284,     0,   196,   197,   171,     0,   223,
     226,   236,   139,   140,   142,     0,   239,   240,   144,     0,
     245,   246,     0,   248,     0,   166,   160,     0,     0,   177,
     276,     0,   167,   278,     0,   169,   192,   464,   466,   361,
     364,   355,   404,   454,     0,     0,   453,     0,     0,     0,
       0,     0,     0,   296,   298,    65,     0,     0,     0,     0,
       0,     0,     0,    81,   335,   336,     0,   333,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
     111,     0,   402,   458,     0,   455,     0,     0,     0,   441,
     440,   414,   416,   412,    84,    75,   119,   120,   118,     0,
     108,     0,     0,   310,     0,     0,   341,   285,     0,   141,
     145,   247,   249,   253,   176,   275,   277,   362,     4,   408,
       6,   390,     0,     0,     0,   434,   445,     0,   337,   338,
       6,   334,   351,     6,     0,   409,   405,   403,     0,     0,
       0,     0,     0,   117,     4,   342,   172,     6,   397,   394,
     395,   396,   392,   393,   391,   459,     0,   456,     0,   442,
     313,   312,   311,     0,   406,     0,     0,   345,   347,   348,
     349,   344,   346,   352,   404,   460,   457,   353,   343,   407
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -798,  -798,   -84,  -798,   541,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   962,  -244,  -798,  -798,  -209,   810,  -798,   969,
     -11,  -798,  -798,   716,  -297,   -35,  -798,   583,   -26,     2,
    -798,     1,     3,   -40,  -798,  -798,   338,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,   408,  -798,   411,  -798,    -9,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   134,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,   -82,  -798,  -798,  -798,
    -797,  -798,  -798,  -798,   591,  -798,  -798,   229,   587,  -798,
    -798,  -798,  -798,  -798,   -21,  -798,    41,  -798,  -798
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    62,   273,    63,   189,   190,   589,   590,   206,
     445,    64,    65,   448,    66,    67,   456,   182,   183,    68,
     240,   592,   591,   501,   502,   241,   185,   224,   186,    89,
     211,   187,   188,   281,   282,   476,   477,    71,   472,   839,
    1060,  1092,   680,    72,   397,   398,   401,   402,   996,   997,
      73,    84,   682,  1063,  1093,  1103,  1036,  1108,    74,   198,
     613,   408,   791,  1009,   889,  1010,    75,   199,   620,    76,
      85,   480,   844,    77,    86,   487,    78,   410,   792,   972,
    1068,  1084,    79,   411,   795,  1051,  1012,  1077,  1104,  1066,
     811,   982,   812,   219,   220,   226,   420,   628,   423,   806,
     807,   979,  1056,   424,   636,   205,   233,   779,   781
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     184,    69,   287,    70,   504,   446,   244,   245,   225,   898,
     899,    90,    91,   200,   453,   454,   208,   446,    80,   212,
     214,   216,   439,   390,   842,   232,   232,   232,   421,   415,
     632,   246,   416,   633,   252,    92,   193,   227,   390,    95,
      96,    97,   221,   284,  1090,    82,   232,   772,   255,   773,
     256,    92,   843,   457,   458,    95,    96,    97,   646,   247,
     248,   249,   446,  1091,   194,   201,   250,   202,   203,   280,
     388,   389,   390,   196,   286,   925,   274,   275,   237,   238,
     373,   374,   375,   376,   377,   378,   379,    69,   276,    70,
    1035,   580,   379,   294,     1,     2,   239,   740,   267,   741,
      87,   197,   775,    88,   776,   373,   374,   375,   376,   377,
     378,   379,   379,   382,   383,   409,   759,   667,   760,   384,
     385,   386,   387,   388,   389,   390,   382,   383,    81,   393,
     394,   251,   384,   385,   386,   387,   388,   389,   390,   260,
     382,   383,   391,   392,   393,   394,   384,   385,   386,   387,
     388,   389,   390,   404,   405,    83,   271,   576,   422,   578,
     261,   373,   374,   375,   376,   377,   378,   379,   379,   370,
     372,   272,   766,   379,   767,   464,   391,   392,   393,   394,
     447,   960,  1020,   961,    92,  1023,   379,   407,    95,    96,
      97,   379,   447,   465,   419,   204,   433,   434,   379,   262,
      69,   379,    70,   798,   263,   799,   727,   444,   659,   417,
     634,   222,   223,   450,   452,   277,   379,   436,   264,   438,
      52,    53,    54,   462,   676,   677,   379,   222,   223,   391,
     392,   393,   394,   728,   963,   265,   964,   447,   278,   467,
     468,   469,   391,   392,   393,   394,   279,   379,   488,   489,
     379,   389,   390,   460,   729,   731,   391,   392,   393,   394,
     385,   703,   387,   388,   389,   390,   470,   505,  1033,   379,
    1034,   475,   379,   379,   933,  1089,   934,   693,   948,   694,
     949,   490,   491,   379,   492,   493,   494,   232,   232,    81,
     730,   285,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   232,   518,   519,   520,   521,   522,   523,
     524,   525,   527,    83,   564,   565,   379,   288,   533,   534,
     535,   537,   538,   752,   540,   379,   542,   622,   373,   374,
     375,   376,   377,   378,   209,   210,   289,   379,   379,   497,
     498,   232,   951,   953,   952,   954,   567,   373,   374,   375,
     376,   377,   378,   217,   218,   517,   391,   392,   393,   394,
     379,    94,   292,   379,   413,   580,    98,   977,   738,   391,
     392,   393,   394,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   379,   637,   638,   100,   379,   743,
     643,   644,   379,   562,   293,   753,   683,  1085,   481,  1086,
     482,   623,   483,   379,   379,   295,   626,   427,   379,   225,
     768,   769,    69,   656,    70,   770,   658,   641,   642,   373,
     374,   375,   376,   377,   378,   484,   296,   379,   485,   379,
     653,   379,   654,   486,   771,   432,   774,   297,   777,   379,
     379,   379,   660,   661,   580,   290,   291,   824,   826,   379,
     379,   669,   671,   672,   673,   379,   986,   992,   379,   112,
     744,   113,   455,   757,   298,   379,   379,    69,   379,    70,
     745,   746,   684,   747,   876,   379,   299,   878,   300,   379,
     748,    69,   301,    70,   749,   379,   135,   136,   137,   435,
     750,   302,   141,   142,   143,   303,   145,   304,   147,   148,
     149,   380,   381,   379,   379,   154,   155,   156,   751,   754,
     159,   379,   161,   379,   163,   379,   755,   165,   756,   167,
     763,   305,   169,   395,   396,   171,   172,   379,   173,   174,
     379,   176,   765,   178,   385,   386,   387,   388,   389,   390,
     191,   545,   379,   379,   382,   383,   440,   931,   955,   306,
     384,   385,   386,   387,   388,   389,   390,   379,   379,   629,
     630,  -387,   962,   965,   784,   785,   379,   787,   788,   379,
     379,   966,   399,   400,   976,  1037,   307,  1065,   382,   383,
     782,   783,   499,   500,   384,   385,   386,   387,   388,   389,
     390,   778,   780,   923,   382,   383,   639,   640,   649,   650,
     384,   385,   386,   387,   388,   389,   390,   379,   678,   679,
     379,   379,  1040,   797,   938,  1043,  1045,   809,   810,   804,
     805,   379,   830,   808,   827,   441,  1046,   387,   388,   389,
     390,   379,   308,   379,   793,   794,  1055,   821,  1105,   887,
     888,   837,   838,   391,   392,   393,   394,   994,   995,  1013,
    1014,   309,   831,   832,   833,   310,   311,   312,   313,   314,
     391,   392,   393,   394,   836,   449,   315,   316,   857,   317,
     475,   841,   318,   319,   320,   321,   845,   846,   847,   848,
     849,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     855,   856,   331,   858,   391,   392,   393,   394,   463,   466,
     859,   332,   333,   860,   334,   335,   336,   337,   890,   338,
     391,   392,   393,   394,   861,   473,   339,   862,   863,   864,
     627,   865,   866,   384,   385,   386,   387,   388,   389,   390,
     868,   340,   382,   383,   391,   392,   393,   394,   384,   385,
     386,   387,   388,   389,   390,   341,   342,   614,   343,   615,
     344,   616,   478,   345,   346,   347,   872,   873,   874,   875,
     348,   382,   383,   349,   350,   351,   352,   384,   385,   386,
     387,   388,   389,   390,   617,   904,   905,   618,   353,   354,
     382,   383,   619,   355,   479,   891,   384,   385,   386,   387,
     388,   389,   390,    69,  1078,    70,  1079,   573,  1080,   356,
     357,   358,   359,   360,   361,   362,   906,   907,   363,   364,
     365,   232,   232,   366,   367,   368,   369,   914,   915,   412,
     414,  1081,   425,   426,  1082,   192,   430,   390,   195,  1083,
     431,   606,   574,   391,   392,   393,   394,   207,   609,   604,
     612,   213,   215,   605,   607,   608,   231,   610,   391,   392,
     393,   394,   611,   621,   624,   631,   635,   662,   257,   258,
     259,   980,   981,   909,   910,   663,   664,   266,   268,   269,
     270,   665,   675,   681,   685,   686,   407,   391,   392,   393,
     394,   974,   692,   967,   968,   428,   978,   695,   993,   696,
     697,   698,   283,   699,   700,   790,   391,   392,   393,   394,
     701,  1097,   710,  1098,   711,  1099,   702,   717,   758,   991,
     761,   762,   382,   383,   998,   813,   814,   819,   384,   385,
     386,   387,   388,   389,   390,  1047,  1048,  1000,  1100,   815,
     816,  1101,   820,   822,  1001,   853,  1102,   823,   854,   500,
     893,  1003,   881,  1004,   882,   883,   884,  1006,   885,   886,
     901,   382,   383,   902,   903,   916,   924,   384,   385,   386,
     387,   388,   389,   390,  1016,   970,  1067,   932,   937,   971,
      -4,   975,   988,   983,   984,   989,  1074,   382,   383,  1075,
     990,  1030,  1017,   384,   385,   386,   387,   388,   389,   390,
    1011,   371,  1031,  1094,  1021,  1050,  1022,  1032,  1052,  1054,
    1049,   403,  1057,  1058,  1059,  -365,  1107,   674,   406,   253,
      69,    69,    70,    70,   786,   418,   254,   503,   647,   840,
     789,   969,  1109,   645,  1062,  1061,     0,  1064,   391,   392,
     393,   394,   655,   896,   713,  1072,   714,     0,     0,   437,
       0,     0,  1070,  1071,     0,     0,     0,     0,     0,   442,
       0,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    70,    69,     0,    70,   391,   392,   393,
     394,     0,     0,   581,     0,   461,     0,  1096,    69,     0,
      70,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,     0,   474,   391,   392,   393,   394,     0,     0,   734,
       0,   735,     0,     0,   382,   383,     0,     0,   496,     0,
     384,   385,   386,   387,   388,   389,   390,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,   528,   529,   530,   531,   532,     0,
       0,     0,     0,     0,   539,     0,   541,     0,   543,   544,
     546,   548,   550,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   563,     0,     0,   566,     0,   568,   569,
     570,   571,   572,     0,     0,   575,     0,   577,     0,   579,
       0,     0,     0,   582,   583,   584,   585,   586,   587,   588,
       0,    92,    93,    94,     0,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     391,   392,   393,   394,   625,     0,   919,     0,   920,     0,
       0,     0,     0,   391,   392,   393,   394,     0,     0,   944,
       0,   945,     0,     0,     0,     0,     0,     0,     0,     0,
     652,   102,   103,   104,   105,   106,   107,     0,     0,   657,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
     109,     0,   668,   670,     0,   234,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,   110,   111,     0,
       0,   112,     0,   113,     0,     0,   236,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,     0,   168,   169,     0,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,   180,     0,     0,
       0,     0,   181,     0,     0,     0,   230,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   802,     0,     0,
     803,     0,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,   382,   383,     0,     0,     0,
       0,   384,   385,   386,   387,   388,   389,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,   113,   382,   383,     0,     0,
       0,   474,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,   850,   852,     0,     0,     0,     0,
     135,   136,   137,     0,     0,     0,   141,   142,   143,     0,
     145,    94,   147,   148,   149,     0,    98,     0,     0,   154,
     155,   156,     0,     0,   159,     0,   161,     0,   163,     0,
       0,   165,     0,   167,     0,   867,   169,   100,     0,   171,
     172,     0,   173,   174,     0,   176,     0,   178,   391,   392,
     393,   394,   869,   870,   191,   547,   429,     0,     0,     0,
     871,   391,   392,   393,   394,     0,     0,     0,     0,   443,
       0,     0,     0,   877,     0,     0,   879,   880,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
       0,    98,   391,   392,   393,   394,     0,     0,     0,   894,
     648,   895,     0,     0,     0,     0,     0,     0,     0,   112,
     382,   113,   100,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,     0,   911,   912,   913,     0,     0,     0,
       0,     0,     0,     0,   921,   922,   135,   136,   137,     0,
       0,     0,   141,   142,   143,     0,   145,     0,   147,   148,
     149,     0,     0,     0,     0,   154,   155,   156,     0,     0,
     159,     0,   161,     0,   163,     0,     0,   165,     0,   167,
       0,     0,   169,     0,     0,   171,   172,     0,   173,   174,
       0,   176,     0,   178,   112,     0,   113,   406,     0,     0,
     191,   549,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,     0,     0,     0,   985,     0,
       0,   135,   136,   137,     0,     0,     0,   141,   142,   143,
       0,   145,     0,   147,   148,   149,   391,   392,   393,   394,
     154,   155,   156,     0,   999,   159,     0,   161,     0,   163,
       0,     0,   165,     0,   167,     0,     0,   169,     0,  1002,
     171,   172,     0,   173,   174,     0,   176,  1005,   178,     0,
       0,  1007,   382,   383,  1008,   191,   551,     0,   384,   385,
     386,   387,   388,   389,   390,     0,     0,  1018,     0,     0,
       0,     0,     0,     0,     0,     0,  1024,  1025,  1026,  1027,
    1028,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,   391,   392,
     393,   394,     0,     0,     0,     0,   687,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1069,     0,     0,     0,     0,  1073,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,   109,   391,   392,
     393,   394,   228,     0,   666,     0,  1095,     0,     0,     0,
     229,     0,     0,     0,   110,   111,     0,     0,   112,     0,
     113,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   167,     0,
     168,   169,     0,   170,   171,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   180,     0,     0,     0,     0,   181,
      92,    93,    94,   230,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   108,     0,     0,   109,
     384,   385,   386,   387,   388,   389,   390,     0,     0,     0,
       0,     0,   495,     0,     0,     0,   110,   111,     0,     0,
     112,     0,   113,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,   180,     0,     0,     0,
       0,   181,    92,    93,    94,   230,    95,    96,    97,    98,
     391,   392,   393,   394,     0,     0,     0,     0,   688,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   383,   108,     0,
       0,   109,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,   112,     0,   113,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,     0,   168,   169,     0,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,   180,     0,
       0,     0,     0,   181,    92,    93,    94,   230,    95,    96,
      97,    98,   391,   392,   393,   394,     0,     0,     0,     0,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   382,   383,   109,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,   112,     0,   113,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,     0,   168,   169,     0,   170,
     171,   172,     0,   173,   174,   175,   176,   177,   178,   179,
     180,     0,     0,     0,     0,   181,   459,    92,    93,    94,
       0,    95,    96,    97,    98,     0,     0,   391,   392,   393,
     394,     0,     0,     0,     0,   690,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,   382,   383,   109,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   390,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,   112,     0,   113,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,     0,   168,
     169,     0,   170,   171,   172,     0,   173,   174,   175,   176,
     177,   178,   179,   180,     0,     0,     0,     0,   181,   526,
      92,    93,    94,     0,    95,    96,    97,    98,     0,     0,
     391,   392,   393,   394,     0,     0,     0,     0,   691,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   382,   383,   109,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
     112,     0,   113,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,   180,     0,     0,     0,
       0,   181,   536,    92,    93,    94,     0,    95,    96,    97,
      98,     0,   242,   391,   392,   393,   394,     0,     0,     0,
       0,   704,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,   108,
       0,     0,   109,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,   112,     0,   113,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,     0,   168,   169,     0,   170,   171,
     172,     0,   173,   174,   175,   176,   177,   178,   179,   180,
       0,    92,    93,    94,   181,    95,    96,    97,    98,     0,
       0,     0,     0,   391,   392,   393,   394,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,    99,   100,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,   382,   383,   108,     0,     0,
     109,   384,   385,   386,   387,   388,   389,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,   112,     0,   113,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,     0,   168,   169,     0,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,   180,     0,    92,
      93,    94,   181,    95,    96,    97,    98,     0,   451,     0,
       0,   391,   392,   393,   394,     0,     0,     0,     0,   732,
       0,     0,     0,     0,     0,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,   108,     0,     0,   109,   384,
     385,   386,   387,   388,   389,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,   112,
       0,   113,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
       0,   168,   169,     0,   170,   171,   172,     0,   173,   174,
     175,   176,   177,   178,   179,   180,     0,    92,    93,    94,
     181,    95,    96,    97,    98,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,     0,     0,   733,     0,     0,
       0,     0,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   382,   383,   108,     0,     0,   109,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,     0,     0,   112,     0,   113,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    94,   164,   165,   166,   167,    98,   168,
     169,     0,   170,   171,   172,     0,   173,   174,   175,   176,
     177,   178,   179,   180,     0,     0,     0,     0,   181,   100,
       0,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,     0,     0,     0,     0,   796,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   651,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,     0,     0,     0,     0,     0,     0,
     382,   383,     0,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,     0,     0,     0,     0,     0,   135,   136,
     137,     0,     0,     0,   141,   142,   143,     0,   145,    94,
     147,   148,   149,   851,    98,     0,     0,   154,   155,   156,
       0,   112,   159,   113,   161,     0,   163,     0,     0,   165,
       0,   167,     0,     0,   169,   100,     0,   171,   172,     0,
     173,   174,     0,   176,     0,   178,     0,     0,   135,   136,
     137,     0,   191,     0,   141,   142,   143,     0,   145,    94,
     147,   148,   149,     0,    98,     0,     0,   154,   155,   156,
       0,     0,   159,     0,   161,     0,   163,     0,     0,   165,
       0,   167,     0,     0,   169,   100,     0,   171,   172,     0,
     173,   174,     0,   176,     0,   178,   391,   392,   393,   394,
       0,     0,   191,     0,   817,     0,     0,   112,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,     0,     0,     0,
     141,   142,   143,     0,   145,     0,   147,   148,   149,     0,
       0,     0,     0,   154,   155,   156,     0,   112,   159,   113,
     161,     0,   163,     0,     0,   165,     0,   167,     0,     0,
     169,     0,     0,   171,   172,     0,   173,   174,     0,   176,
       0,   178,     0,     0,   135,   136,   137,     0,   191,     0,
     141,   142,   143,     0,   145,     0,   147,   148,   149,     0,
       0,     0,     0,   154,   155,   156,     0,     0,   159,     0,
     161,     0,   163,     0,     0,   165,     0,   167,     0,     0,
     169,     0,     0,   171,   172,     0,   173,   174,     0,   176,
       0,   178,     1,     2,     3,     0,     0,     0,   801,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,    11,  -316,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,     0,     0,     0,     0,
      23,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,    39,    40,    41,  -111,  -111,
      42,    43,    44,     0,    45,    46,    47,     0,     0,    48,
    -111,     0,    49,     0,    50,    51,   382,   383,     0,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,    57,     0,     1,
       2,     3,    58,     0,     0,    59,     4,     0,     0,    60,
       5,     0,     6,     0,     7,     8,     9,    10,    11,  -316,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    -6,    -6,
      24,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
       0,     0,   391,   392,   393,   394,     0,     0,     0,     0,
     818,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,     0,     0,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,     0,     0,    49,
       0,    50,    51,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,   388,   389,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    57,     0,     1,     2,     3,    58,
       0,     0,    59,     4,     0,     0,    60,     5,     0,     6,
       0,     7,     8,     9,    10,    11,  -316,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      -6,     0,     0,     0,    23,    -6,     0,    24,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,     0,     0,   825,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,    39,
      40,    41,     0,     0,    42,    43,    44,     0,    45,    46,
      47,     0,     0,    48,   382,   383,    49,     0,    50,    51,
     384,   385,   386,   387,   388,   389,   390,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,    52,    53,    54,   382,   383,     0,     0,    55,
       0,   384,   385,   386,   387,   388,   389,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,    57,     0,     0,     0,     0,    58,     0,     0,    59,
     382,   383,     0,    60,     0,     0,   384,   385,   386,   387,
     388,   389,   390,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,   388,   389,   390,   382,   383,     0,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,   392,   393,   394,     0,     0,     0,     0,   828,     0,
       0,     0,     0,   391,   392,   393,   394,   382,   383,     0,
       0,   829,     0,   384,   385,   386,   387,   388,   389,   390,
       0,   391,   392,   393,   394,   382,   383,     0,     0,   834,
       0,   384,   385,   386,   387,   388,   389,   390,   382,   383,
       0,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
       0,     0,     0,     0,   835,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,     0,     0,   892,     0,     0,
       0,     0,   391,   392,   393,   394,   382,   383,     0,     0,
     897,     0,   384,   385,   386,   387,   388,   389,   390,   382,
     383,     0,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,   392,   393,   394,   382,   383,     0,
       0,   908,     0,   384,   385,   386,   387,   388,   389,   390,
       0,   391,   392,   393,   394,     0,     0,     0,     0,   957,
       0,     0,     0,     0,   391,   392,   393,   394,   382,   383,
       0,     0,   958,     0,   384,   385,   386,   387,   388,   389,
     390,   382,   383,     0,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,   382,   383,     0,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,     0,     0,     0,     0,
     987,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,     0,     0,  1038,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,   392,   393,   394,   382,   383,     0,
       0,  1053,     0,   384,   385,   386,   387,   388,   389,   390,
     382,   383,     0,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,     0,   391,   392,   393,   394,     0,     0,
       0,     0,  1088,     0,     0,     0,     0,   391,   392,   393,
     394,     0,     0,   705,     0,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   382,   383,   706,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   390,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   707,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,   392,   393,   394,     0,     0,   708,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     382,   383,   709,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,   388,   389,   390,   382,   383,     0,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,     0,
     391,   392,   393,   394,     0,     0,   712,     0,     0,     0,
       0,     0,     0,   391,   392,   393,   394,   382,   383,   715,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   716,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
       0,     0,   718,     0,     0,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,   719,     0,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   382,   383,   720,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,   382,
     383,     0,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,   391,   392,   393,   394,   382,   383,   721,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
       0,     0,     0,     0,     0,   391,   392,   393,   394,     0,
       0,   722,     0,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   382,   383,   723,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,   382,   383,     0,     0,     0,
       0,   384,   385,   386,   387,   388,   389,   390,   382,   383,
       0,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   391,   392,   393,   394,     0,     0,   724,     0,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   726,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,   391,   392,   393,   394,   382,   383,   736,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
     382,   383,     0,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,     0,     0,   737,     0,     0,     0,     0,     0,
       0,   391,   392,   393,   394,     0,     0,   739,     0,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   382,   383,
     742,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,   382,   383,     0,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   764,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,   391,   392,   393,   394,     0,     0,   800,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     382,   383,   900,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,   388,   389,   390,   382,   383,     0,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,     0,     0,
     917,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   382,   383,   918,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   926,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,     0,   391,   392,   393,   394,
       0,     0,   927,     0,     0,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,   928,     0,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   382,   383,   929,     0,
       0,     0,   384,   385,   386,   387,   388,   389,   390,   382,
     383,     0,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   382,   383,   930,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   391,   392,   393,   394,     0,
       0,   935,     0,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   382,   383,   936,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,   382,   383,     0,     0,     0,
       0,   384,   385,   386,   387,   388,   389,   390,   382,   383,
       0,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,     0,   391,   392,   393,   394,     0,     0,   939,     0,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   382,
     383,   940,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   382,   383,   941,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,   382,   383,     0,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,   392,
     393,   394,     0,     0,   942,     0,     0,     0,     0,     0,
       0,   391,   392,   393,   394,     0,     0,   943,     0,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   382,   383,
     946,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,   382,   383,     0,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,   391,   392,   393,   394,   382,
     383,   947,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,     0,     0,     0,     0,     0,   391,   392,   393,
     394,     0,     0,   950,     0,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   382,   383,   956,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   390,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,   388,   389,   390,
     382,   383,     0,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   391,   392,   393,   394,     0,     0,
     959,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   382,   383,   973,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,   391,   392,   393,   394,   382,
     383,  1015,     0,     0,     0,   384,   385,   386,   387,   388,
     389,   390,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,     0,     0,  1019,     0,     0,     0,
       0,     0,     0,   391,   392,   393,   394,     0,     0,  1029,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     382,   383,  1039,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,   388,   389,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   382,   383,  1041,     0,     0,     0,   384,   385,   386,
     387,   388,   389,   390,     0,   391,   392,   393,   394,     0,
       0,  1042,     0,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   382,   383,  1044,     0,     0,     0,   384,   385,
     386,   387,   388,   389,   390,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
       0,     0,  1076,     0,     0,     0,     0,     0,     0,   391,
     392,   393,   394,     0,     0,  1087,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,   392,
     393,   394
};

static const yytype_int16 yycheck[] =
{
      11,     0,    86,     0,   301,    12,    41,    42,    34,   806,
     807,     9,    10,    24,   258,   259,    27,    12,    74,    30,
      31,    32,    11,    75,    16,    36,    37,    38,    58,     4,
       4,    59,     7,     7,    45,     3,   184,    35,    75,     7,
       8,     9,    10,    83,    25,    74,    57,   185,    47,   187,
      47,     3,    44,   262,   263,     7,     8,     9,    10,    87,
      88,    89,    12,    44,   184,    58,    94,    60,    61,    80,
      73,    74,    75,    28,    85,    12,    90,    91,    37,    38,
      69,    70,    71,    72,    73,    74,   180,    86,   102,    86,
      13,   185,   180,   104,     4,     5,    86,   185,    57,   187,
       4,     7,   185,     7,   187,    69,    70,    71,    72,    73,
      74,   180,   180,    63,    64,   199,   185,   185,   187,    69,
      70,    71,    72,    73,    74,    75,    63,    64,   184,   181,
     182,    93,    69,    70,    71,    72,    73,    74,    75,   108,
      63,    64,   179,   180,   181,   182,    69,    70,    71,    72,
      73,    74,    75,   193,   194,   184,     0,   366,   188,   368,
     184,    69,    70,    71,    72,    73,    74,   180,   180,   180,
     181,    44,   185,   180,   187,   187,   179,   180,   181,   182,
     187,   185,   979,   187,     3,   982,   180,   198,     7,     8,
       9,   180,   187,   187,   205,   188,   222,   223,   180,   184,
     199,   180,   199,   185,   184,   187,   185,   242,   452,   184,
     184,   179,   180,   248,   249,    74,   180,   228,   184,   230,
     130,   131,   132,   187,   468,   469,   180,   179,   180,   179,
     180,   181,   182,   187,   185,   184,   187,   187,    74,   274,
     275,   276,   179,   180,   181,   182,    24,   180,   288,   289,
     180,    74,    75,   264,   187,   185,   179,   180,   181,   182,
      70,   505,    72,    73,    74,    75,   277,   302,   185,   180,
     187,   282,   180,   180,   185,  1072,   187,   185,   185,   187,
     187,   292,   293,   180,   295,   296,   297,   298,   299,   184,
     187,     4,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   184,   354,   355,   180,   184,   329,   330,
     331,   332,   333,   187,   335,   180,   337,   411,    69,    70,
      71,    72,    73,    74,     4,     5,   184,   180,   180,   298,
     299,   352,   185,   185,   187,   187,   357,    69,    70,    71,
      72,    73,    74,     4,     5,   314,   179,   180,   181,   182,
     180,     5,   184,   180,    58,   185,    10,   187,   185,   179,
     180,   181,   182,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   180,   425,   426,    31,   180,   185,
     430,   431,   180,   352,   184,   187,   480,   185,    14,   187,
      16,   412,    18,   180,   180,   184,   417,   187,   180,   435,
     187,   187,   411,   448,   411,   187,   451,   428,   429,    69,
      70,    71,    72,    73,    74,    41,   184,   180,    44,   180,
     441,   180,   443,    49,   187,   187,   187,   184,   187,   180,
     180,   180,   453,   454,   185,    35,    36,   187,   187,   180,
     180,   462,   463,   464,   465,   180,   187,   187,   180,   103,
     185,   105,     5,   185,   184,   180,   180,   466,   180,   466,
     185,   185,   483,   185,   771,   180,   184,   774,   184,   180,
     185,   480,   184,   480,   185,   180,   130,   131,   132,   187,
     185,   184,   136,   137,   138,   184,   140,   184,   142,   143,
     144,    20,    21,   180,   180,   149,   150,   151,   185,   185,
     154,   180,   156,   180,   158,   180,   185,   161,   185,   163,
     185,   184,   166,     4,     5,   169,   170,   180,   172,   173,
     180,   175,   185,   177,    70,    71,    72,    73,    74,    75,
     184,   185,   180,   180,    63,    64,   187,   185,   185,   184,
      69,    70,    71,    72,    73,    74,    75,   180,   180,   186,
     187,    46,   185,   185,   604,   605,   180,   607,   608,   180,
     180,   185,     4,     5,   185,   185,   184,    46,    63,    64,
     591,   592,     4,     5,    69,    70,    71,    72,    73,    74,
      75,   589,   590,   837,    63,    64,     4,     5,    84,    85,
      69,    70,    71,    72,    73,    74,    75,   180,     4,     5,
     180,   180,   185,   624,   858,   185,   185,     4,     5,   630,
     631,   180,   662,   634,   659,   187,   185,    72,    73,    74,
      75,   180,   184,   180,    49,    50,   185,   648,   185,    39,
      40,   676,   677,   179,   180,   181,   182,     4,     5,    60,
      61,   184,   663,   664,   665,   184,   184,   184,   184,   184,
     179,   180,   181,   182,   675,   187,   184,   184,   703,   184,
     681,   682,   184,   184,   184,   184,   687,   688,   689,   690,
     691,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     701,   702,   184,   704,   179,   180,   181,   182,   187,    43,
     711,   184,   184,   714,   184,   184,   184,   184,   792,   184,
     179,   180,   181,   182,   725,   185,   184,   728,   729,   730,
      51,   732,   733,    69,    70,    71,    72,    73,    74,    75,
     741,   184,    63,    64,   179,   180,   181,   182,    69,    70,
      71,    72,    73,    74,    75,   184,   184,    14,   184,    16,
     184,    18,   185,   184,   184,   184,   767,   768,   769,   770,
     184,    63,    64,   184,   184,   184,   184,    69,    70,    71,
      72,    73,    74,    75,    41,   815,   816,    44,   184,   184,
      63,    64,    49,   184,    74,   796,    69,    70,    71,    72,
      73,    74,    75,   792,    14,   792,    16,   185,    18,   184,
     184,   184,   184,   184,   184,   184,   817,   818,   184,   184,
     184,   822,   823,   184,   184,   184,   184,   828,   829,   184,
     184,    41,   184,   184,    44,    15,   184,    75,    18,    49,
     184,   187,   185,   179,   180,   181,   182,    27,   187,   184,
      43,    31,    32,   184,   184,   184,    36,   185,   179,   180,
     181,   182,   185,    46,   184,   184,    10,   184,    48,    49,
      50,   901,   902,   822,   823,   187,   187,    57,    58,    59,
      60,   187,   187,   187,   185,   185,   887,   179,   180,   181,
     182,   892,   185,   881,   882,   187,   897,   187,   923,   185,
     184,   184,    82,   185,   185,    43,   179,   180,   181,   182,
     187,    14,   185,    16,   187,    18,   187,   185,   185,   920,
     185,   185,    63,    64,   925,   185,   185,   185,    69,    70,
      71,    72,    73,    74,    75,  1009,  1010,   938,    41,   184,
     184,    44,   185,    83,   945,   185,    49,    83,   185,     5,
      58,   952,   187,   954,   187,   185,   185,   958,   185,   185,
     184,    63,    64,   184,   187,   185,   184,    69,    70,    71,
      72,    73,    74,    75,   975,    43,  1050,   185,   185,    38,
      43,   184,    74,   185,   185,    74,  1060,    63,    64,  1063,
      74,   992,    58,    69,    70,    71,    72,    73,    74,    75,
      48,   181,   184,  1077,   185,    47,   185,   184,   184,   184,
    1011,   191,    74,   185,   185,    38,     4,   466,   198,    47,
    1009,  1010,  1009,  1010,   606,   205,    47,   301,   435,   681,
     609,   887,  1104,   432,  1035,  1034,    -1,  1038,   179,   180,
     181,   182,   445,   804,   185,  1056,   187,    -1,    -1,   229,
      -1,    -1,  1053,  1054,    -1,    -1,    -1,    -1,    -1,   239,
      -1,  1050,    -1,  1050,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1060,    -1,  1060,  1063,    -1,  1063,   179,   180,   181,
     182,    -1,    -1,   185,    -1,   265,    -1,  1088,  1077,    -1,
    1077,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,
      -1,    -1,   282,   179,   180,   181,   182,    -1,    -1,   185,
      -1,   187,    -1,    -1,    63,    64,    -1,    -1,   298,    -1,
      69,    70,    71,    72,    73,    74,    75,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,    -1,
      -1,    -1,    -1,    -1,   334,    -1,   336,    -1,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,    -1,    -1,   356,    -1,   358,   359,
     360,   361,   362,    -1,    -1,   365,    -1,   367,    -1,   369,
      -1,    -1,    -1,   373,   374,   375,   376,   377,   378,   379,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
     179,   180,   181,   182,   414,    -1,   185,    -1,   187,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,   185,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    63,    64,    65,    66,    67,    68,    -1,    -1,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      82,    -1,   462,   463,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,
     630,    -1,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    63,    64,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,   105,    63,    64,    -1,    -1,
      -1,   681,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,   694,   695,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,    -1,    -1,   136,   137,   138,    -1,
     140,     5,   142,   143,   144,    -1,    10,    -1,    -1,   149,
     150,   151,    -1,    -1,   154,    -1,   156,    -1,   158,    -1,
      -1,   161,    -1,   163,    -1,   735,   166,    31,    -1,   169,
     170,    -1,   172,   173,    -1,   175,    -1,   177,   179,   180,
     181,   182,   752,   753,   184,   185,   187,    -1,    -1,    -1,
     760,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,   773,    -1,    -1,   776,   777,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    10,   179,   180,   181,   182,    -1,    -1,    -1,   799,
     187,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      63,   105,    31,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,   824,   825,   826,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   834,   835,   130,   131,   132,    -1,
      -1,    -1,   136,   137,   138,    -1,   140,    -1,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,    -1,
     154,    -1,   156,    -1,   158,    -1,    -1,   161,    -1,   163,
      -1,    -1,   166,    -1,    -1,   169,   170,    -1,   172,   173,
      -1,   175,    -1,   177,   103,    -1,   105,   887,    -1,    -1,
     184,   185,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,   908,    -1,
      -1,   130,   131,   132,    -1,    -1,    -1,   136,   137,   138,
      -1,   140,    -1,   142,   143,   144,   179,   180,   181,   182,
     149,   150,   151,    -1,   934,   154,    -1,   156,    -1,   158,
      -1,    -1,   161,    -1,   163,    -1,    -1,   166,    -1,   949,
     169,   170,    -1,   172,   173,    -1,   175,   957,   177,    -1,
      -1,   961,    63,    64,   964,   184,   185,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,   977,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   986,   987,   988,   989,
     990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,   179,   180,
     181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1052,    -1,    -1,    -1,    -1,  1057,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    82,   179,   180,
     181,   182,    87,    -1,   185,    -1,  1086,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,   161,   162,   163,    -1,
     165,   166,    -1,   168,   169,   170,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,
       3,     4,     5,   188,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    79,    -1,    -1,    82,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    99,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,     3,     4,     5,   188,     7,     8,     9,    10,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    79,    -1,
      -1,    82,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,   160,
     161,   162,   163,    -1,   165,   166,    -1,   168,   169,   170,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,   184,     3,     4,     5,   188,     7,     8,
       9,    10,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    63,    64,    82,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,   161,   162,   163,    -1,   165,   166,    -1,   168,
     169,   170,    -1,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,   185,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    63,    64,    82,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,   103,    -1,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,    -1,   165,
     166,    -1,   168,   169,   170,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    63,    64,    82,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,   161,   162,
     163,    -1,   165,   166,    -1,   168,   169,   170,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,   185,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    12,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    79,
      -1,    -1,    82,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,    -1,   165,   166,    -1,   168,   169,
     170,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
      -1,     3,     4,     5,   184,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    79,    -1,    -1,
      82,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,   170,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,     3,
       4,     5,   184,     7,     8,     9,    10,    -1,    12,    -1,
      -1,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    79,    -1,    -1,    82,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
      -1,   165,   166,    -1,   168,   169,   170,    -1,   172,   173,
     174,   175,   176,   177,   178,   179,    -1,     3,     4,     5,
     184,     7,     8,     9,    10,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    79,    -1,    -1,    82,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,   103,    -1,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     5,   160,   161,   162,   163,    10,   165,
     166,    -1,   168,   169,   170,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    -1,   184,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,    -1,    -1,    -1,   136,   137,   138,    -1,   140,     5,
     142,   143,   144,    95,    10,    -1,    -1,   149,   150,   151,
      -1,   103,   154,   105,   156,    -1,   158,    -1,    -1,   161,
      -1,   163,    -1,    -1,   166,    31,    -1,   169,   170,    -1,
     172,   173,    -1,   175,    -1,   177,    -1,    -1,   130,   131,
     132,    -1,   184,    -1,   136,   137,   138,    -1,   140,     5,
     142,   143,   144,    -1,    10,    -1,    -1,   149,   150,   151,
      -1,    -1,   154,    -1,   156,    -1,   158,    -1,    -1,   161,
      -1,   163,    -1,    -1,   166,    31,    -1,   169,   170,    -1,
     172,   173,    -1,   175,    -1,   177,   179,   180,   181,   182,
      -1,    -1,   184,    -1,   187,    -1,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   103,   154,   105,
     156,    -1,   158,    -1,    -1,   161,    -1,   163,    -1,    -1,
     166,    -1,    -1,   169,   170,    -1,   172,   173,    -1,   175,
      -1,   177,    -1,    -1,   130,   131,   132,    -1,   184,    -1,
     136,   137,   138,    -1,   140,    -1,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,    -1,   154,    -1,
     156,    -1,   158,    -1,    -1,   161,    -1,   163,    -1,    -1,
     166,    -1,    -1,   169,   170,    -1,   172,   173,    -1,   175,
      -1,   177,     4,     5,     6,    -1,    -1,    -1,   184,    11,
      -1,    -1,    -1,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    -1,    -1,   101,
     102,    -1,   104,    -1,   106,   107,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,    -1,    -1,   159,    -1,     4,
       5,     6,   164,    -1,    -1,   167,    11,    -1,    -1,   171,
      15,    -1,    17,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,   106,   107,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,   159,    -1,     4,     5,     6,   164,
      -1,    -1,   167,    11,    -1,    -1,   171,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    96,    97,
      98,    -1,    -1,   101,    63,    64,   104,    -1,   106,   107,
      69,    70,    71,    72,    73,    74,    75,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,   130,   131,   132,    63,    64,    -1,    -1,   137,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      63,    64,    -1,   171,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    63,    64,    -1,
      -1,   187,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,   179,   180,   181,   182,    63,    64,    -1,    -1,   187,
      -1,    69,    70,    71,    72,    73,    74,    75,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    63,    64,    -1,    -1,
     187,    -1,    69,    70,    71,    72,    73,    74,    75,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    63,    64,    -1,
      -1,   187,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,    64,
      -1,    -1,   187,    -1,    69,    70,    71,    72,    73,    74,
      75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,    -1,    -1,   187,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    63,    64,    -1,
      -1,   187,    -1,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,   179,   180,   181,   182,    -1,    -1,
      -1,    -1,   187,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,    63,    64,   185,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      63,    64,   185,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
     179,   180,   181,   182,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    63,    64,   185,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    63,    64,   185,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,   179,   180,   181,   182,    63,    64,   185,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,    63,    64,   185,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    63,    64,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,   179,   180,   181,   182,    63,    64,   185,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,   182,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,    64,
     185,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,   179,   180,   181,   182,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      63,    64,   185,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    63,    64,   185,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,   179,   180,   181,   182,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,    63,    64,   185,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    63,    64,   185,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,    63,    64,   185,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    63,    64,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,   179,   180,   181,   182,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    63,    64,   185,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,   182,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,    63,    64,
     185,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,    63,    64,   185,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    63,    64,   185,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,   179,   180,   181,   182,    63,
      64,   185,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      63,    64,   185,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    63,    64,   185,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,   179,   180,   181,   182,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,    63,    64,   185,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,    11,    15,    17,    19,    20,    21,
      22,    23,    26,    27,    28,    29,    30,    31,    32,    33,
      35,    36,    37,    42,    45,    52,    53,    54,    55,    56,
      57,    61,    62,    76,    77,    78,    79,    80,    81,    87,
      88,    89,    92,    93,    94,    96,    97,    98,   101,   104,
     106,   107,   130,   131,   132,   137,   155,   159,   164,   167,
     171,   190,   191,   193,   200,   201,   203,   204,   208,   220,
     221,   226,   232,   239,   247,   255,   258,   262,   265,   271,
      74,   184,    74,   184,   240,   259,   263,     4,     7,   218,
     218,   218,     3,     4,     5,     7,     8,     9,    10,    30,
      31,    34,    63,    64,    65,    66,    67,    68,    79,    82,
      99,   100,   103,   105,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   160,   161,   162,   163,   165,   166,
     168,   169,   170,   172,   173,   174,   175,   176,   177,   178,
     179,   184,   206,   207,   209,   215,   217,   220,   221,   194,
     195,   184,   206,   184,   184,   206,    28,     7,   248,   256,
     209,    58,    60,    61,   188,   294,   198,   206,   209,     4,
       5,   219,   209,   206,   209,   206,   209,     4,     5,   282,
     283,    10,   179,   180,   216,   217,   284,   218,    87,    95,
     188,   206,   209,   295,    87,    95,   108,   295,   295,    86,
     209,   214,    12,    53,   214,   214,    59,    87,    88,    89,
      94,    93,   209,   201,   208,   220,   221,   206,   206,   206,
     108,   184,   184,   184,   184,   184,   206,   295,   206,   206,
     206,     0,    44,   192,    90,    91,   102,    74,    74,    24,
     209,   222,   223,   206,   222,     4,   209,   191,   184,   184,
      35,    36,   184,   184,   209,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     209,   206,   209,    69,    70,    71,    72,    73,    74,   180,
      20,    21,    63,    64,    69,    70,    71,    72,    73,    74,
      75,   179,   180,   181,   182,     4,     5,   233,   234,     4,
       5,   235,   236,   206,   222,   222,   206,   209,   250,   191,
     266,   272,   184,    58,   184,     4,     7,   184,   206,   209,
     285,    58,   188,   287,   292,   184,   184,   187,   187,   187,
     184,   184,   187,   217,   217,   187,   209,   206,   209,    11,
     187,   187,   206,   187,   214,   199,    12,   187,   202,   187,
     214,    12,   214,   202,   202,     5,   205,   205,   205,   185,
     209,   206,   187,   187,   187,   187,    43,   214,   214,   214,
     209,   206,   227,   185,   206,   209,   224,   225,   185,    74,
     260,    14,    16,    18,    41,    44,    49,   264,   222,   222,
     209,   209,   209,   209,   209,    95,   206,   295,   295,     4,
       5,   212,   213,   212,   213,   214,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   295,   209,   209,
     209,   209,   209,   209,   209,   209,   185,   209,   206,   206,
     206,   206,   206,   209,   209,   209,   185,   209,   209,   206,
     209,   206,   209,   206,   206,   185,   206,   185,   206,   185,
     206,   185,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   295,   206,   222,   222,   206,   209,   206,   206,
     206,   206,   206,   185,   185,   206,   205,   206,   205,   206,
     185,   185,   206,   206,   206,   206,   206,   206,   206,   196,
     197,   211,   210,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   184,   184,   187,   184,   184,   187,
     185,   185,    43,   249,    14,    16,    18,    41,    44,    49,
     257,    46,   191,   209,   184,   206,   209,    51,   286,   186,
     187,   184,     4,     7,   184,    10,   293,   222,   222,     4,
       5,   209,   209,   222,   222,   283,    10,   216,   187,    84,
      85,    95,   206,   209,   209,   287,   214,   206,   214,   202,
     209,   209,   184,   187,   187,   187,   185,   185,   206,   209,
     206,   209,   209,   209,   193,   187,   202,   202,     4,     5,
     231,   187,   241,   191,   209,   185,   185,   187,   187,   187,
     187,   187,   185,   185,   187,   187,   185,   184,   184,   185,
     185,   187,   187,   202,   187,   185,   185,   185,   185,   185,
     185,   187,   185,   185,   187,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   187,   185,   185,   187,   187,
     187,   185,   187,   187,   185,   187,   185,   185,   185,   185,
     185,   187,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   187,   187,   185,   185,   185,   185,   185,   185,
     187,   185,   185,   185,   185,   185,   185,   187,   187,   187,
     187,   187,   185,   187,   187,   185,   187,   187,   218,   296,
     218,   297,   209,   209,   222,   222,   234,   222,   222,   236,
      43,   251,   267,    49,    50,   273,   187,   209,   185,   187,
     185,   184,   206,   206,   209,   209,   288,   289,   209,     4,
       5,   279,   281,   185,   185,   184,   184,   187,   187,   185,
     185,   209,    83,    83,   187,   187,   187,   214,   187,   187,
     222,   209,   209,   209,   187,   187,   209,   214,   214,   228,
     225,   209,    16,    44,   261,   209,   209,   209,   209,   209,
     206,    95,   206,   185,   185,   209,   209,   214,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   206,   209,   206,
     206,   206,   209,   209,   209,   209,   213,   206,   213,   206,
     206,   187,   187,   185,   185,   185,   185,    39,    40,   253,
     191,   209,   187,    58,   206,   206,   286,   187,   279,   279,
     185,   184,   184,   187,   222,   222,   209,   209,   187,   295,
     295,   206,   206,   206,   209,   209,   185,   185,   185,   185,
     187,   206,   206,   202,   184,    12,   185,   185,   185,   185,
     185,   185,   185,   185,   187,   185,   185,   185,   202,   185,
     185,   185,   185,   185,   185,   187,   185,   185,   185,   187,
     185,   185,   187,   185,   187,   185,   185,   187,   187,   185,
     185,   187,   185,   185,   187,   185,   185,   218,   218,   250,
      43,    38,   268,   185,   209,   184,   185,   187,   209,   290,
     222,   222,   280,   185,   185,   206,   187,   187,    74,    74,
      74,   209,   187,   214,     4,     5,   237,   238,   209,   206,
     209,   209,   206,   209,   209,   206,   209,   206,   206,   252,
     254,    48,   275,    60,    61,   185,   209,    58,   206,   185,
     279,   185,   185,   279,   206,   206,   206,   206,   206,   185,
     209,   184,   184,   185,   187,    13,   245,   185,   187,   185,
     185,   185,   185,   185,   185,   185,   185,   191,   191,   209,
      47,   274,   184,   187,   184,   185,   291,    74,   185,   185,
     229,   238,   209,   242,   209,    46,   278,   191,   269,   206,
     209,   209,   293,   206,   191,   191,   185,   276,    14,    16,
      18,    41,    44,    49,   270,   185,   187,   185,   187,   279,
      25,    44,   230,   243,   191,   206,   209,    14,    16,    18,
      41,    44,    49,   244,   277,   185,   185,     4,   246,   275
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   189,   190,   191,   192,   191,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   193,   195,   193,   193,   193,
     193,   193,   193,   193,   196,   193,   197,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   198,   193,
     199,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   200,   200,   200,   200,   200,   201,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   204,
     204,   205,   205,   206,   206,   206,   206,   206,   206,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   208,   208,
     210,   209,   211,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   212,   213,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   216,   216,   216,   217,
     217,   217,   217,   218,   218,   219,   219,   219,   219,   220,
     221,   223,   222,   224,   224,   224,   225,   225,   227,   228,
     229,   226,   230,   230,   231,   231,   232,   232,   232,   232,
     233,   233,   234,   234,   234,   234,   235,   235,   236,   236,
     236,   236,   237,   237,   237,   238,   238,   238,   238,   240,
     241,   242,   243,   239,   244,   244,   244,   244,   244,   244,
     245,   245,   246,   246,   248,   247,   249,   249,   250,   250,
     251,   252,   251,   253,   254,   253,   256,   255,   257,   257,
     257,   257,   257,   257,   259,   260,   258,   261,   261,   263,
     262,   264,   264,   264,   264,   264,   264,   266,   267,   268,
     269,   265,   270,   270,   270,   270,   270,   270,   272,   271,
     273,   273,   274,   274,   275,   276,   277,   275,   278,   278,
     279,   280,   279,   281,   281,   281,   281,   282,   282,   283,
     283,   283,   283,   284,   284,   284,   284,   285,   285,   285,
     285,   285,   286,   286,   286,   288,   287,   289,   287,   290,
     287,   291,   287,   292,   287,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   295,   295,   296,   296,   297,   297
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
       6,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     4,     6,     6,     6,     8,     1,     2,     2,     1,
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

    {create_function(fEOR);}

    break;

  case 272:

    {create_function(fSHL);}

    break;

  case 273:

    {create_function(fSHR);}

    break;

  case 274:

    {create_function(fTELL);}

    break;

  case 275:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 276:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 277:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 278:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 279:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 280:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 281:

    {create_myopen(0);}

    break;

  case 282:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 283:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 284:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 285:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 286:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 287:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 288:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 289:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 290:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 291:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}

    break;

  case 292:

    {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}

    break;

  case 293:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 294:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 295:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 296:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 297:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 298:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 299:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 300:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 301:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 308:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 309:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 310:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 311:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 312:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 313:

    {missing_endsub--;}

    break;

  case 314:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 315:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 316:

    {exported=FALSE;}

    break;

  case 317:

    {exported=TRUE;}

    break;

  case 318:

    {exported=FALSE;}

    break;

  case 319:

    {exported=TRUE;}

    break;

  case 322:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 323:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 324:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 325:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 328:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 329:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 330:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 331:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 335:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 336:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 337:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 338:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 339:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 340:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 341:

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

  case 342:

    {
             swap();popgoto();poplabel();}

    break;

  case 343:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 344:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 345:

    {missing_next--;}

    break;

  case 346:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 347:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 348:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 349:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 350:

    {create_pushdbl(1);}

    break;

  case 352:

    {pop(stSTRING);}

    break;

  case 353:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 354:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 355:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 361:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 362:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 364:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 366:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 368:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 369:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 370:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 371:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 372:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 373:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 374:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 375:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 377:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 378:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 379:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 381:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 382:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 383:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 384:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 385:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 386:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 387:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 388:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 389:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 390:

    {poplabel();}

    break;

  case 392:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 393:

    {missing_endif--;}

    break;

  case 394:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 395:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 396:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 397:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 398:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 400:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 401:

    {poplabel();}

    break;

  case 405:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 406:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 411:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 413:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 414:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 415:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 416:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 419:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 420:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 421:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 422:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 423:

    {create_strdata((yyvsp[0].string));}

    break;

  case 424:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 425:

    {create_strdata((yyvsp[0].string));}

    break;

  case 426:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 430:

    {create_print('s');}

    break;

  case 431:

    {create_print('s');}

    break;

  case 432:

    {create_print('d');}

    break;

  case 433:

    {create_print('u');}

    break;

  case 434:

    {create_print('U');}

    break;

  case 435:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 436:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 437:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 438:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 439:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 440:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 441:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 442:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 443:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 444:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 445:

    {create_pushstr("?");create_print('s');}

    break;

  case 446:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 447:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 452:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 454:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 455:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 457:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 458:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 459:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 460:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 463:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 464:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 465:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 466:

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
