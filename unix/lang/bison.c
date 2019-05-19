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
    tDATE = 421,
    tTIME = 422,
    tTOKEN = 423,
    tTOKENALT = 424,
    tSPLIT = 425,
    tSPLITALT = 426,
    tGLOB = 427,
    UMINUS = 428
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
#define YYFINAL  264
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  459
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1078

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   428

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   182,     2,     2,     2,     2,
     178,   179,   175,   174,   181,   173,     2,   176,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   180,
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
     165,   166,   167,   168,   169,   170,   171,   172,   177
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
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     501,   502,   503,   506,   507,   508,   511,   512,   515,   516,
     517,   518,   521,   524,   527,   527,   530,   531,   532,   535,
     536,   539,   540,   543,   539,   548,   549,   552,   553,   556,
     557,   558,   559,   562,   563,   566,   567,   568,   569,   572,
     573,   576,   577,   578,   579,   582,   583,   584,   587,   588,
     589,   590,   593,   594,   598,   612,   593,   617,   618,   619,
     620,   621,   622,   625,   626,   629,   630,   635,   635,   639,
     640,   643,   644,   648,   650,   649,   654,   655,   655,   659,
     659,   665,   666,   667,   668,   669,   670,   674,   675,   674,
     681,   682,   686,   686,   691,   692,   693,   694,   695,   696,
     699,   700,   700,   702,   699,   706,   707,   708,   709,   710,
     711,   714,   714,   719,   720,   723,   724,   727,   729,   731,
     728,   735,   736,   739,   740,   740,   743,   744,   746,   747,
     751,   752,   755,   756,   758,   759,   763,   764,   765,   766,
     769,   770,   771,   772,   773,   776,   777,   778,   781,   781,
     782,   782,   783,   783,   784,   784,   785,   785,   788,   789,
     792,   793,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   803,   804,   805,   808,   809,   811,   812,   815,   816
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
  "tFRNBF_GET2", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT",
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
     425,   426,   427,    45,    43,    42,    47,   428,    40,    41,
      59,    44,    35
};
# endif

#define YYPACT_NINF -771

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-771)))

#define YYTABLE_NINF -381

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3956,   -30,   -29,  -771,  -771,  -771,  -771,  -771,   107,   107,
     107,  2962,  -771,  -771,  -771,  3581,  -154,  -140,  3581,    88,
      64,  -771,  -771,  -771,  3306,   -24,  -771,  3306,   224,  -771,
    3306,  3306,  3306,   276,    36,   107,  1743,  1153,  2087,    54,
    3306,  2790,  3306,    39,    93,  3306,  -771,    72,  3581,  3581,
    3581,    81,    17,    19,    60,    68,    77,  2087,  3581,  3581,
     257,   239,  -771,   117,  -771,  -771,  -771,  -771,   234,   236,
    -771,   292,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  3306,
    -771,  3581,  -771,   336,  3306,  3808,  -771,  -771,  -771,  -771,
    -771,  -771,   147,   166,  -771,  -771,  -771,   204,   216,   180,
     232,   290,  3306,   331,   335,   337,   361,   364,   368,   370,
     392,   402,   441,   470,   480,   501,   518,   527,   536,   537,
     542,   545,   547,   548,   549,   551,   552,   554,   555,   556,
     557,   563,   564,   574,   575,   583,   584,   586,   587,   588,
     589,   590,   591,   597,   598,   599,   600,   601,   602,   604,
     605,   608,   609,   610,   613,   614,   615,   616,   620,   623,
     625,   626,   628,   629,   630,   631,   632,   634,   635,   636,
     641,   650,   651,   652,  3306,  3306,    13,  -771,   419,  -771,
    -771,  -771,  -771,   299,   353,  3581,   222,  -771,  -771,   222,
    -771,  -771,  3306,  3808,   543,   653,   409,   657,    24,  3306,
     -47,    13,   931,   658,   661,   289,   931,    13,   852,    13,
    1277,   662,   666,   302,  -771,  -771,   321,   321,  -771,  -771,
     385,  -771,  3306,  3581,  3306,   252,   931,   475,  -771,  -771,
    -771,  -771,   505,  3581,  1370,  -771,  3306,  -771,    12,   526,
    -771,  -771,  3306,  3134,  -771,  -771,   931,  -771,  -771,   234,
     236,   222,    11,    11,  -771,   716,   716,   716,  2259,  3581,
      38,   664,   222,  -125,  -771,  -771,   686,  3306,  3306,  3306,
    3306,  3581,  -771,   931,   454,  3306,   222,   667,   660,   931,
     459,  -771,  -771,  -771,  -771,  3306,  3306,   346,  3306,  1915,
    2087,   491,   491,  3306,  3306,  3306,  3306,  3306,  3306,  3306,
    3306,  3306,  3306,  3306,  3306,  2087,  3306,  3306,  3306,  3306,
    3306,  3306,  3306,  2436,  3581,  3581,  3581,  3581,  3581,  3306,
    3306,  3306,  2613,  3306,  3581,  3306,  3581,  3306,  3581,  3581,
       0,   378,  1329,  1480,  3581,  3581,  3581,  3581,  3581,  3581,
    3581,  3581,  2087,  3581,  -771,  -771,  3581,  3306,  3581,  3581,
    3581,  3581,   668,   669,  3581,   716,  3581,   716,  3581,   709,
      -4,  1623,  3581,  3581,  3581,  3581,  3581,  3581,  3581,  -771,
    -771,  -771,  -771,  3306,  3306,  3306,  3306,  3306,  3306,  3306,
    3306,  3306,  3306,  3306,   680,   689,   674,  -771,   690,   691,
     685,  -771,   -84,   694,   695,    13,   931,   828,   460,   830,
    3808,  3306,   698,  3581,  -771,  -771,  3306,    13,   688,   273,
     699,    25,  -771,   869,  -771,  -771,   550,  3306,  3306,  -771,
    -771,   276,  -771,  -771,    44,  1487,   222,   931,   508,  3476,
    3306,   222,  3306,  -771,   -47,  -771,  -771,  3306,  3581,  -771,
    3306,    12,  3306,  3306,   701,   700,   702,   703,  -771,  4354,
     -81,  3306,  3306,  3306,  3808,   704,    12,    12,   931,   222,
     595,  -771,    13,   931,   706,  -771,  -771,  -771,  3808,  -771,
    -771,  3306,  -771,  -771,  -771,  -771,   710,   711,  1502,  1531,
    1655,   712,   284,   707,   713,   715,   718,   719,   720,   721,
     722,    12,  1930,  4379,  4426,  4437,  4448,  4469,   755,  4494,
     994,  4505,  4516,   726,  4563,  4584,  4631,  4642,  4653,  4678,
    2102,  -771,  4699,   -23,   -82,   -13,     8,    89,  2274,  2451,
    1015,  -771,  4710,  4721,   250,  4768,   -78,  4793,   251,   254,
    -771,   277,  -771,   288,  -771,   305,  -771,   352,   355,   359,
     362,    46,    56,   388,   389,   417,   182,   727,   156,   728,
     729,   443,  4836,   449,   452,    80,    86,  -771,  -771,    95,
    -121,   132,  -109,   219,  -771,  -771,   222,   222,   222,   222,
     222,   222,  -771,   107,   107,  3306,  3306,   377,   489,   502,
     201,   261,   -32,  -771,    -3,    -3,   709,   709,  -771,  -771,
     299,  -771,  -771,   353,  -771,  -771,  -771,   838,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,   553,  2631,  3306,   160,
    4847,  3639,  -771,  -771,  3306,  3306,  -771,  -771,  3306,  -771,
     637,   730,   731,   723,   734,  2805,  2977,   738,   746,  -771,
    -771,  -771,  3306,   820,   846,  -771,   246,  3149,   931,  -771,
    -771,   269,  -771,  3306,  3321,  3420,  -771,  3306,  3306,  3306,
    -771,  -771,    13,   931,    13,   931,  4100,  -771,  3306,  3306,
    3306,  -771,  -771,  -771,  3306,  3306,    42,   931,  -771,  -771,
    3306,  3306,  3306,  -771,  -771,  3581,  3525,  -771,   748,   754,
    -771,  -771,  3306,  3306,  3306,  3306,  -771,  -771,  -771,  -771,
    -771,  -771,  3306,  -771,  -771,  3306,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  3306,  -771,  -771,  3306,  3306,
    3306,  -771,  3306,  3306,  -771,  3581,  -771,  -771,  -771,  -771,
    -771,  3306,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  3581,  3581,  -771,  -771,  -771,  -771,  -771,  -771,
    3581,  -771,  -771,  -771,  -771,  -771,  -771,  3306,  3306,   932,
    -771,  3581,   932,  -771,  3581,  3581,  -771,   758,  -771,   759,
     346,  3848,   762,   763,  -771,   764,   765,  -771,  -771,   644,
    3808,  -771,  -771,  -771,  3306,  4147,   881,  3581,  -771,  3581,
     222,    13,   688,  4172,   637,   637,  4858,   768,   769,  -771,
     770,  -771,  -771,  -771,  -771,  3306,  3306,  -771,  -771,  4216,
    2087,  2087,  3581,  3581,  3581,  -771,  3306,  3306,   771,  4883,
    4908,  1339,  3581,   931,    12,  -771,   776,  -771,   173,  -771,
    -771,  -771,  4919,  4930,  4973,   453,   777,   164,  -771,  -771,
    4998,  5045,   778,    50,  5056,  5067,  5088,  5113,  5124,  1352,
    5135,  5182,   199,  5203,   207,   210,   455,  4227,  4238,   -92,
     456,   -50,   465,   466,   107,   107,  -771,  -771,  -771,  -771,
    3306,   913,   921,   918,  5250,  3306,   783,   476,   218,  -771,
    3306,  -771,  -771,  -771,  -771,  -771,  -771,   785,   786,   931,
     931,  3581,  -771,  -771,   222,   222,   278,  4263,   931,  -771,
     892,   895,   896,  3306,   320,  3306,   708,  3306,  -771,  -771,
    -771,  -771,  -771,  -771,  3581,  -771,  -771,  -771,  3306,  -771,
    -771,  -771,  -771,  -771,  -771,  3306,  -771,  -771,  -771,  3581,
    -771,  -771,  3306,  -771,  3306,  -771,  3581,  3306,  -771,  3581,
    -771,  -771,  3581,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
     923,   633,  5261,  3306,   914,  3581,  5272,   637,   793,   794,
     637,  -771,  -771,   222,  3581,  3581,  3581,  3581,  3581,  5297,
    3306,  -771,   796,   797,    -5,  -771,   515,   478,  4288,  5318,
     494,  5329,  5340,   506,  5387,   521,   529,  3808,  4104,  3306,
     936,  -771,   799,  -771,  4299,   806,   530,  -771,  -771,  -771,
    -771,  -771,   222,   222,   222,   222,   222,   915,   931,   808,
     809,  -771,   708,  3306,  -771,  -771,  3306,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,   918,   948,   677,  3808,  -771,
    3581,  3306,  3306,  -771,   869,  3581,  -771,  -771,  3808,  -771,
     931,  3808,  5412,  -771,  -771,   918,   603,   230,  5455,  4310,
     637,   222,    35,   918,  -771,  3808,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  3581,  -771,  3306,  -771,  -771,  -771,
    -771,   757,   918,   532,  5466,  -771,  -771,  -771,  -771,  -771,
    -771,   985,   923,  -771,  -771,  -771,  -771,  -771
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     110,     0,     0,   105,   332,   367,   372,    11,     0,     0,
       0,     0,    24,    26,   310,     0,     0,     0,     0,   311,
      18,    20,   347,   359,     0,   440,    48,    60,     0,   102,
     103,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     4,     3,     0,     7,    39,    41,     9,    22,    23,
      21,     0,    13,    14,    17,    16,    15,    28,    29,     0,
     294,     0,   294,     0,     0,     6,   287,   286,    30,    31,
      38,   283,   196,   132,   284,   285,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,   254,   257,   260,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   161,     0,
       0,     0,     0,     0,     0,     0,     0,   133,     0,   209,
     190,   195,   134,     0,     0,     0,    12,   294,   294,    42,
     312,    19,     0,     6,   391,     0,   444,     0,     0,   420,
     436,    62,    61,     0,     0,    63,   104,    53,     0,    55,
       0,   412,   414,    56,   410,   416,     0,     0,   417,   280,
      57,    59,     0,    89,     0,     0,   455,     0,    86,    91,
      79,    40,     0,     0,     0,    67,     0,    50,    72,     0,
      88,    87,     0,     0,   113,   114,    92,     8,    10,     0,
       0,   106,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     1,     2,     0,     0,     0,     0,
       0,     0,   301,   175,     0,   296,   115,     0,     0,   368,
       4,   294,   294,    32,    33,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      36,   179,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   315,   316,    25,   313,   321,   322,
      27,   319,     0,     0,     0,   352,   351,     0,     4,     0,
       6,     0,     0,     0,   441,   442,     0,   423,   425,    45,
       0,     0,    49,   438,   294,   294,     0,     0,     0,   294,
     294,     0,   282,   281,     0,     0,    90,   454,     0,     0,
       0,    66,     0,    71,   436,   122,   121,     0,     0,    68,
       0,    74,     0,     0,   130,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     6,     0,     0,     0,   176,   120,
       0,   292,   299,   300,   295,   297,   293,   333,     6,   379,
     377,     0,   378,   374,   376,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,   258,     0,   261,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   162,     0,
       0,     0,     0,     0,   137,   210,   204,   206,   208,   205,
     207,   203,   136,     0,     0,     0,     0,   183,   185,   187,
     184,   186,   182,   201,   198,   197,   199,   200,   294,   294,
       0,   294,   294,     0,    43,    44,   349,   353,   366,   364,
     365,   362,   361,   363,   360,   381,     4,     0,     0,     0,
       0,     0,   421,    46,    47,     0,   428,   430,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   411,
     418,   419,     0,     0,     0,   125,   124,   128,   213,    51,
      69,    82,    73,     0,     0,     0,   294,     0,     0,     0,
      96,    97,    98,    99,   100,   101,     0,     5,     0,     0,
       0,   307,   308,   302,     0,     0,     4,   375,   273,   173,
       0,     0,     0,   274,   275,     0,     0,   268,     0,     0,
     191,   192,     0,     0,     0,     0,   214,   215,   216,   217,
     218,   219,     0,   221,   222,     0,   224,   225,   188,   230,
     231,   226,   227,   228,   229,     0,   233,   238,     0,     0,
       0,   237,     0,     0,   142,     0,   147,   148,   239,   171,
     240,     0,   172,   149,   150,   253,   256,   259,   262,   153,
     151,   152,     0,     0,   154,   246,   155,   252,   251,   163,
       0,   247,   156,   248,   157,   250,   158,     0,     0,     0,
     166,     0,     0,   168,     0,     0,   456,    35,   458,    37,
     180,   178,     0,     0,   314,     0,     0,   320,   350,   356,
       6,   393,   394,   392,     0,     0,   445,     0,   443,     0,
     426,   424,   425,     0,     0,     0,     0,   406,   408,   437,
     403,   288,   290,   294,   294,     0,     0,   413,   415,    64,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    85,     0,   298,     0,   371,
     370,   369,     0,     0,     0,     0,     0,     0,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,   318,   323,   324,
       0,     0,     0,   382,     0,     0,     0,     0,     0,   422,
       0,   429,   431,   432,   294,   294,   404,     0,     0,    52,
      54,     0,   126,   127,   123,   129,    83,    76,    77,   131,
       0,     0,     0,     0,   109,     0,   325,     0,   265,   266,
     267,   276,   277,   278,     0,   193,   194,   169,     0,   220,
     223,   232,   138,   139,   141,     0,   235,   236,   143,     0,
     241,   242,     0,   244,     0,   164,     0,     0,   270,     0,
     165,   272,     0,   167,   189,   457,   459,   354,   357,   348,
     397,   447,     0,     0,   446,     0,     0,     0,     0,     0,
       0,   289,   291,    65,     0,     0,     0,     0,     0,     0,
       0,    81,   328,   329,     0,   326,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,   110,     0,
     395,   451,     0,   448,     0,     0,     0,   434,   433,   407,
     409,   405,    84,    75,   118,   119,   117,     0,   108,     0,
       0,   303,     0,     0,   334,   279,     0,   140,   144,   243,
     245,   249,   174,   269,   271,   355,     4,   401,     6,   383,
       0,     0,     0,   427,   438,     0,   330,   331,     6,   327,
     344,     6,     0,   402,   398,   396,     0,     0,     0,     0,
       0,   116,     4,   335,   170,     6,   390,   387,   388,   389,
     385,   386,   384,   452,     0,   449,     0,   435,   306,   305,
     304,     0,   399,     0,     0,   338,   340,   341,   342,   337,
     339,   345,   397,   453,   450,   346,   336,   400
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -771,  -771,   -83,  -771,   558,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,   943,  -235,  -771,  -771,  -202,   784,  -771,   944,
     -11,  -771,  -771,   714,  -288,   -35,  -771,   572,   -26,     2,
    -771,     1,     3,    78,  -771,  -771,   340,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,   415,  -771,   416,  -771,     6,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,   153,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,   -58,  -771,  -771,  -771,
    -770,  -771,  -771,  -771,   594,  -771,  -771,   238,   582,  -771,
    -771,  -771,  -771,  -771,    -6,  -771,    37,  -771,  -771
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    60,    61,   266,    62,   183,   184,   573,   574,   200,
     434,    63,    64,   437,    65,    66,   445,   176,   177,    67,
     234,   576,   575,   487,   488,   235,   179,   218,   180,    88,
     205,   181,   182,   274,   275,   464,   465,    70,   460,   816,
    1028,  1060,   663,    71,   386,   387,   390,   391,   964,   965,
      72,    83,   665,  1031,  1061,  1071,  1004,  1076,    73,   192,
     597,   397,   769,   977,   862,   978,    74,   193,   604,    75,
      84,   468,   821,    76,    85,   475,    77,   399,   770,   940,
    1036,  1052,    78,   400,   773,  1019,   980,  1045,  1072,  1034,
     789,   950,   790,   213,   214,   220,   409,   612,   412,   784,
     785,   947,  1024,   413,   620,   199,   227,   757,   759
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     178,    68,   280,    69,   490,    93,   238,   239,   219,    96,
     410,    89,    90,   194,   871,   872,   202,   442,   443,   206,
     208,   210,   435,   435,   187,   226,   226,   226,   404,   616,
      98,   405,   617,   195,   246,   196,   197,   221,   188,    91,
     379,    79,    81,    94,    95,   215,   226,    91,   249,   368,
     250,    94,    95,   630,   446,   447,   453,   819,   750,  1058,
     751,   435,   362,   363,   364,   365,   366,   367,   273,   379,
     753,   191,   754,   279,   231,   232,     1,     2,  1059,   362,
     363,   364,   365,   366,   367,   820,    68,   928,    69,   929,
     368,   287,   368,   368,   261,   564,   368,   240,   651,   708,
     108,   720,   109,   721,   362,   363,   364,   365,   366,   367,
     398,    86,   371,   372,    87,   190,   373,   374,   375,   376,
     377,   378,   379,   241,   242,   243,   130,   131,   132,   931,
     244,   932,   136,   137,   138,   411,   140,   233,   142,   143,
     144,   380,   381,   382,   383,   149,   150,   151,    80,    82,
     154,   368,   156,   560,   158,   562,   707,   160,   198,   162,
     277,   368,   164,   359,   361,   166,   167,   168,   709,   170,
     368,   172,   382,   383,  1001,   564,  1002,   988,   185,   530,
     991,   396,   368,   245,   897,   368,   254,   368,   408,   710,
     422,   423,   436,   436,    68,   255,    69,   256,    52,    53,
      54,   433,   406,   618,   267,   268,   643,   439,   441,   216,
     217,   425,   368,   427,   283,   284,   269,   216,   217,   451,
     368,   659,   660,   380,   381,   382,   383,   732,   203,   204,
     368,   436,   455,   456,   457,   371,   372,   733,   257,   373,
     374,   375,   376,   377,   378,   379,   258,   449,   362,   363,
     364,   365,   366,   367,   368,   259,   684,   264,   491,   458,
     368,   747,   428,   368,   463,   393,   394,   748,   711,   368,
    1057,   377,   378,   379,   478,   479,   749,   480,   226,   226,
     211,   212,   265,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   226,   504,   505,   506,   507,   508,
     509,   510,   512,   384,   385,   270,   368,   271,   518,   519,
     520,   522,   523,   752,   525,   272,   527,   606,   362,   363,
     364,   365,   366,   367,    91,    80,   483,   484,    94,    95,
     368,   226,   378,   379,   368,   739,   552,   740,   368,   776,
     278,   777,   503,   903,    82,   904,   380,   381,   382,   383,
     362,   363,   364,   365,   366,   367,   368,   388,   389,   476,
     477,   737,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   368,   380,   381,   382,   383,   918,   547,
     919,   368,   281,    93,   368,   666,   921,    96,   922,   923,
     607,   924,   368,   368,   282,   610,   368,   564,   219,   945,
     755,    68,   640,    69,   368,   642,   625,   626,    98,  1053,
     285,  1054,   373,   374,   375,   376,   377,   378,   379,   637,
     368,   638,   549,   550,   368,   368,   368,   802,   368,   718,
     723,   644,   645,   724,   380,   381,   382,   383,   369,   370,
     653,   655,   656,   368,   374,   375,   376,   377,   378,   379,
     804,   368,   368,   613,   614,    68,   725,    69,   368,   954,
     667,   849,   368,   674,   851,   675,   402,   726,   286,    68,
     416,    69,   469,   598,   470,   599,   471,   600,   108,   368,
     109,   371,   372,   421,   727,   373,   374,   375,   376,   377,
     378,   379,   621,   622,   368,   485,   486,   627,   628,   472,
     601,   960,   473,   602,   130,   131,   132,   474,   603,   288,
     136,   137,   138,   289,   140,   290,   142,   143,   144,   380,
     381,   382,   383,   149,   150,   151,   368,  1003,   154,   368,
     156,   728,   158,   368,   729,   160,   368,   162,   730,   291,
     164,   731,   292,   166,   167,   168,   293,   170,   294,   172,
     380,   381,   382,   383,   623,   624,   185,   532,   376,   377,
     378,   379,   368,   368,   760,   761,   424,   734,   735,   374,
     295,   376,   377,   378,   379,   756,   758,   371,   372,   895,
     296,   373,   374,   375,   376,   377,   378,   379,  -380,   633,
     634,   368,   380,   381,   382,   383,   736,   775,   908,   661,
     662,   771,   772,   782,   783,   371,   372,   786,   805,   373,
     374,   375,   376,   377,   378,   379,  1046,   368,  1047,   297,
    1048,   799,   743,   368,   814,   815,   368,   368,   745,   368,
     368,   746,   901,   461,   925,   930,   809,   810,   811,   368,
     368,   787,   788,  1049,   933,   934,  1050,   813,   298,   832,
     368,  1051,   368,   463,   818,   944,   429,  1005,   299,   822,
     823,   824,   380,   381,   382,   383,   762,   763,   368,   765,
     766,   830,   831,  1008,   833,   380,   381,   382,   383,   300,
     368,   834,   860,   861,   835,  1011,   430,   863,   380,   381,
     382,   383,   981,   982,   836,   368,   301,   837,   838,   839,
    1013,   840,   841,   368,   368,   302,   368,   438,  1014,  1023,
     843,  1073,   962,   963,   303,   304,   380,   381,   382,   383,
     305,   444,  1033,   306,   808,   307,   308,   309,   454,   310,
     311,   467,   312,   313,   314,   315,   847,   848,   611,   371,
     372,   316,   317,   373,   374,   375,   376,   377,   378,   379,
     371,   372,   318,   319,   373,   374,   375,   376,   377,   378,
     379,   320,   321,   864,   322,   323,   324,   325,   326,   327,
    1065,    68,  1066,    69,  1067,   328,   329,   330,   331,   332,
     333,   379,   334,   335,   879,   880,   336,   337,   338,   226,
     226,   339,   340,   341,   342,   887,   888,  1068,   343,   186,
    1069,   344,   189,   345,   346,  1070,   347,   348,   349,   350,
     351,   201,   352,   353,   354,   207,   209,   371,   372,   355,
     225,   373,   374,   375,   376,   377,   378,   379,   356,   357,
     358,   401,   251,   252,   253,   403,   414,   882,   883,   415,
     419,   260,   262,   263,   420,   452,   466,   557,   558,   396,
     380,   381,   382,   383,   942,   590,   935,   936,   588,   946,
     961,   380,   381,   382,   383,   276,   593,   589,   591,   592,
     596,   877,   878,   594,   595,   605,   608,   615,   619,   646,
     768,   647,   959,   648,   649,   658,   966,   664,   676,   668,
     669,   673,   677,   678,  1015,  1016,   679,   968,   680,   681,
     800,   793,   682,   683,   969,   698,   738,   741,   742,   791,
     792,   971,   794,   972,   371,   372,   974,   797,   373,   374,
     375,   376,   377,   378,   379,   798,   801,   828,   380,   381,
     382,   383,   984,   829,   691,  1035,   692,   486,   866,   854,
     855,   856,   857,   858,   859,  1042,   874,   875,  1043,   998,
     889,   876,   948,   949,   896,   938,   902,   907,   939,   360,
      -4,   943,  1062,   956,   951,   952,   957,   958,  1017,   392,
     979,   985,   989,   990,   999,  1000,   395,  1020,    68,    68,
      69,    69,  1018,   407,  1022,  -358,  1025,  1026,  1027,  1075,
     247,   248,  1030,   371,   372,  1032,   631,   373,   374,   375,
     376,   377,   378,   379,   817,   764,   489,   426,  1029,   767,
    1038,  1039,   657,   937,  1077,   629,   639,   431,  1040,    68,
     869,    69,     0,     0,     0,   380,   381,   382,   383,    68,
       0,    69,    68,   417,    69,     0,     0,     0,     0,     0,
       0,     0,     0,   450,     0,  1064,    68,     0,    69,     0,
       0,     0,     0,     0,     0,   459,   371,   372,     0,   462,
     373,   374,   375,   376,   377,   378,   379,     0,     0,     0,
       0,     0,     0,   482,     0,     0,     0,   371,   372,     0,
       0,   373,   374,   375,   376,   377,   378,   379,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   513,   514,
     515,   516,   517,     0,   380,   381,   382,   383,   524,     0,
     526,     0,   528,   529,   531,   533,   535,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   548,     0,     0,
     551,     0,   553,   554,   555,   556,     0,     0,   559,     0,
     561,     0,   563,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,     0,     0,     0,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,     0,   380,   381,   382,
     383,     0,     0,   694,     0,   695,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,   609,   380,   381,
     382,   383,     0,     0,   714,     0,   715,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   636,     0,   100,   101,   102,   103,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,   652,   654,   228,     0,     0,
       0,     0,     0,     0,     0,   229,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,   230,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,     0,
       0,   175,     0,     0,    93,   224,     0,     0,    96,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   780,     0,     0,   781,     0,
       0,   371,   372,     0,     0,   373,   374,   375,   376,   377,
     378,   379,     0,     0,   371,   372,     0,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,   108,
       0,   109,   371,   372,     0,     0,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,     0,   462,     0,
     380,   381,   382,   383,     0,   130,   131,   132,   418,   825,
     827,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,    93,   160,     0,   162,    96,
       0,   164,     0,     0,   166,   167,   168,     0,   170,   842,
     172,     0,     0,     0,     0,     0,     0,   185,   534,     0,
      98,     0,   380,   381,   382,   383,   844,   845,   892,     0,
     893,     0,     0,     0,   846,   380,   381,   382,   383,     0,
       0,   914,     0,   915,     0,   850,     0,     0,   852,   853,
       0,     0,     0,   380,   381,   382,   383,     0,     0,   371,
     372,   432,     0,   373,   374,   375,   376,   377,   378,   379,
       0,   867,     0,   868,   371,   372,     0,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
     108,     0,   109,     0,     0,     0,   884,   885,   886,     0,
       0,     0,     0,   371,   372,     0,   894,   373,   374,   375,
     376,   377,   378,   379,     0,     0,   130,   131,   132,     0,
       0,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,     0,     0,
     154,     0,   156,     0,   158,     0,     0,   160,     0,   162,
       0,     0,   164,     0,   395,   166,   167,   168,     0,   170,
       0,   172,     0,     0,     0,     0,     0,     0,   185,   536,
     380,   381,   382,   383,     0,   953,     0,     0,   632,     0,
       0,     0,     0,     0,     0,   380,   381,   382,   383,     0,
       0,     0,     0,   670,     0,   371,   372,     0,   967,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,   970,   380,   381,   382,   383,     0,     0,
     973,     0,   671,   975,     0,     0,   976,   371,   372,     0,
       0,   373,   374,   375,   376,   377,   378,   379,     0,   986,
       0,     0,     0,     0,     0,     0,     0,     0,   992,   993,
     994,   995,   996,     0,     0,     0,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
       0,     0,   565,     0,  1037,   100,   101,   102,   103,  1041,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,     0,     0,     0,     0,   222,   380,   381,
     382,   383,     0,     0,     0,   223,   672,     0,  1063,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,    91,    92,
      93,   175,    94,    95,    96,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   371,   372,   105,     0,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,   481,     0,     0,
       0,   106,   107,     0,     0,   108,     0,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,     0,   163,   164,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
      91,    92,    93,   175,    94,    95,    96,   224,     0,     0,
       0,     0,     0,   380,   381,   382,   383,     0,     0,     0,
       0,   685,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   371,   372,   105,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,   108,     0,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,     0,   163,   164,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,    91,    92,    93,   175,    94,    95,    96,   224,
       0,     0,     0,     0,     0,   380,   381,   382,   383,     0,
       0,     0,     0,   705,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   371,   372,   105,     0,
     373,   374,   375,   376,   377,   378,   379,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,   108,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,     0,
     163,   164,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,     0,     0,     0,     0,   175,   448,    91,
      92,    93,     0,    94,    95,    96,     0,   380,   381,   382,
     383,     0,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   371,   372,   105,     0,   373,   374,   375,
     376,   377,   378,   379,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,   175,   511,    91,    92,    93,     0,
      94,    95,    96,     0,   380,   381,   382,   383,     0,     0,
       0,     0,   713,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,   371,   372,     0,     0,   373,   374,   375,
     376,   377,   378,   379,     0,     0,     0,     0,     0,   106,
     107,     0,     0,   108,     0,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,     0,
       0,   175,   521,    91,    92,    93,     0,    94,    95,    96,
       0,   236,     0,     0,   380,   381,   382,   383,     0,     0,
       0,     0,   774,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   371,   372,   105,
       0,   373,   374,   375,   376,   377,   378,   379,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
     108,     0,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,   164,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,    91,    92,    93,   175,    94,
      95,    96,     0,     0,     0,     0,     0,     0,   380,   381,
     382,   383,     0,     0,     0,     0,   795,     0,     0,     0,
       0,    97,    98,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   371,
     372,   105,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,   108,     0,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,     0,   163,   164,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,    91,    92,    93,
     175,    94,    95,    96,     0,   440,     0,     0,     0,     0,
     380,   381,   382,   383,     0,     0,     0,     0,   796,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   371,   372,   105,     0,   373,   374,   375,   376,   377,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,   108,     0,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,    91,
      92,    93,   175,    94,    95,    96,     0,     0,     0,     0,
       0,     0,   380,   381,   382,   383,     0,     0,     0,     0,
     803,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   371,   372,   105,     0,   373,   374,   375,
     376,   377,   378,   379,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,   108,     0,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,    93,   371,   372,   175,    96,   373,   374,   375,   376,
     377,   378,   379,     0,   380,   381,   382,   383,     0,     0,
       0,     0,   806,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   635,     0,
       0,     0,     0,     0,     0,     0,   108,     0,   109,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
      96,     0,     0,   380,   381,   382,   383,     0,     0,     0,
       0,   807,   130,   131,   132,     0,     0,     0,   136,   137,
     138,    98,   140,     0,   142,   143,   144,   826,     0,     0,
       0,   149,   150,   151,     0,   108,   154,   109,   156,     0,
     158,     0,     0,   160,     0,   162,     0,     0,   164,     0,
       0,   166,   167,   168,    93,   170,     0,   172,    96,     0,
       0,   130,   131,   132,   185,     0,     0,   136,   137,   138,
       0,   140,     0,   142,   143,   144,     0,     0,     0,    98,
     149,   150,   151,     0,     0,   154,     0,   156,     0,   158,
       0,   108,   160,   109,   162,     0,     0,   164,     0,     0,
     166,   167,   168,     0,   170,     0,   172,     0,     0,     0,
       0,     0,     0,   185,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,     0,     0,     0,   149,   150,   151,     0,
       0,   154,     0,   156,     0,   158,     0,     0,   160,   108,
     162,   109,     0,   164,     0,     0,   166,   167,   168,     0,
     170,     0,   172,     0,     0,     0,     0,     0,     0,   185,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,     0,   162,     0,
       0,   164,     0,     0,   166,   167,   168,     0,   170,     0,
     172,     0,     1,     2,     3,     0,     0,   779,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     8,     9,    10,
      11,  -309,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,     0,     0,     0,     0,    23,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,     0,
       0,     0,    39,    40,    41,  -110,  -110,    42,    43,    44,
       0,    45,    46,    47,     0,     0,    48,  -110,     0,    49,
     371,    50,    51,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       1,     2,     3,    57,     0,     0,     4,     0,    58,     0,
       5,    59,     6,     0,     7,     8,     9,    10,    11,  -309,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,     0,     0,     0,     0,    23,    -6,    -6,
      24,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,     0,     0,
       0,   380,   381,   382,   383,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
      39,    40,    41,     0,     0,    42,    43,    44,     0,    45,
      46,    47,     0,     0,    48,     0,     0,    49,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     1,     2,
       3,    57,     0,     0,     4,     0,    58,     0,     5,    59,
       6,     0,     7,     8,     9,    10,    11,  -309,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    -6,     0,     0,     0,    23,    -6,     0,    24,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
      30,     0,   371,   372,    31,    32,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,    39,    40,
      41,     0,     0,    42,    43,    44,     0,    45,    46,    47,
       0,     0,    48,     0,     0,    49,     0,    50,    51,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,   371,   372,     0,    55,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,    57,
       0,     0,     0,     0,    58,     0,     0,    59,     0,     0,
       0,     0,     0,   380,   381,   382,   383,     0,   371,   372,
       0,   812,   373,   374,   375,   376,   377,   378,   379,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     371,   372,     0,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,   381,   382,   383,     0,   371,   372,     0,   865,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,   381,   382,   383,     0,
     371,   372,     0,   870,   373,   374,   375,   376,   377,   378,
     379,   371,   372,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   371,   372,     0,     0,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,     0,     0,   380,
     381,   382,   383,     0,     0,     0,     0,   881,     0,     0,
     380,   381,   382,   383,     0,     0,     0,     0,   926,     0,
       0,   380,   381,   382,   383,     0,   371,   372,     0,   927,
     373,   374,   375,   376,   377,   378,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
       0,   371,   372,     0,   955,   373,   374,   375,   376,   377,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,     0,     0,     0,     0,  1006,
       0,     0,   380,   381,   382,   383,     0,     0,     0,     0,
    1021,     0,     0,   380,   381,   382,   383,     0,   371,   372,
       0,  1056,   373,   374,   375,   376,   377,   378,   379,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     371,   372,     0,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,   380,   381,   382,
     383,   371,   372,   650,     0,   373,   374,   375,   376,   377,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   381,   382,   383,   371,   372,   686,     0,
     373,   374,   375,   376,   377,   378,   379,   371,   372,     0,
       0,   373,   374,   375,   376,   377,   378,   379,   371,   372,
       0,     0,   373,   374,   375,   376,   377,   378,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   380,
     381,   382,   383,     0,     0,   687,     0,     0,     0,     0,
     380,   381,   382,   383,     0,     0,   688,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   689,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,   380,   381,   382,   383,   371,   372,   690,     0,
     373,   374,   375,   376,   377,   378,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   380,   381,   382,
     383,     0,     0,   693,     0,     0,     0,     0,   380,   381,
     382,   383,     0,     0,   696,     0,     0,     0,     0,   380,
     381,   382,   383,   371,   372,   697,     0,   373,   374,   375,
     376,   377,   378,   379,   371,   372,     0,     0,   373,   374,
     375,   376,   377,   378,   379,   371,   372,     0,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   699,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,   380,   381,   382,
     383,   371,   372,   700,     0,   373,   374,   375,   376,   377,
     378,   379,   371,   372,     0,     0,   373,   374,   375,   376,
     377,   378,   379,   371,   372,     0,     0,   373,   374,   375,
     376,   377,   378,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   380,   381,   382,   383,     0,     0,
     701,     0,     0,     0,     0,   380,   381,   382,   383,     0,
       0,   702,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   703,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   704,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,   380,   381,   382,   383,     0,     0,   706,     0,
       0,     0,     0,   380,   381,   382,   383,     0,     0,   716,
       0,     0,     0,     0,   380,   381,   382,   383,   371,   372,
     717,     0,   373,   374,   375,   376,   377,   378,   379,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     371,   372,     0,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   719,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   722,     0,   373,   374,   375,   376,   377,   378,
     379,   371,   372,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   371,   372,     0,     0,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,     0,     0,   380,
     381,   382,   383,     0,     0,   744,     0,     0,     0,     0,
     380,   381,   382,   383,     0,     0,   778,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   873,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   890,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,     0,     0,   891,     0,     0,
       0,     0,   380,   381,   382,   383,     0,     0,   898,     0,
       0,     0,     0,   380,   381,   382,   383,   371,   372,   899,
       0,   373,   374,   375,   376,   377,   378,   379,   371,   372,
       0,     0,   373,   374,   375,   376,   377,   378,   379,   371,
     372,     0,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   900,     0,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   905,     0,   373,
     374,   375,   376,   377,   378,   379,   371,   372,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   371,   372,     0,
       0,   373,   374,   375,   376,   377,   378,   379,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   380,   381,
     382,   383,     0,     0,   906,     0,     0,     0,     0,   380,
     381,   382,   383,     0,     0,   909,     0,     0,     0,     0,
     380,   381,   382,   383,   371,   372,   910,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,   371,   372,   911,     0,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
       0,     0,   912,     0,     0,     0,     0,   380,   381,   382,
     383,     0,     0,   913,     0,     0,     0,     0,   380,   381,
     382,   383,   371,   372,   916,     0,   373,   374,   375,   376,
     377,   378,   379,   371,   372,     0,     0,   373,   374,   375,
     376,   377,   378,   379,   371,   372,     0,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,   381,   382,   383,   371,
     372,   917,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,   380,   381,   382,   383,
     371,   372,   920,     0,   373,   374,   375,   376,   377,   378,
     379,   371,   372,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   371,   372,     0,     0,   373,   374,   375,   376,
     377,   378,   379,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   380,   381,   382,   383,     0,     0,   941,
       0,     0,     0,     0,   380,   381,   382,   383,     0,     0,
     983,     0,     0,     0,     0,   380,   381,   382,   383,   371,
     372,   987,     0,   373,   374,   375,   376,   377,   378,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,   381,   382,   383,   371,   372,   997,     0,   373,   374,
     375,   376,   377,   378,   379,     0,     0,     0,     0,     0,
       0,   380,   381,   382,   383,     0,     0,  1007,     0,     0,
       0,     0,   380,   381,   382,   383,     0,     0,  1009,     0,
       0,     0,     0,   380,   381,   382,   383,   371,   372,  1010,
       0,   373,   374,   375,   376,   377,   378,   379,   371,   372,
       0,     0,   373,   374,   375,   376,   377,   378,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,   381,   382,   383,     0,     0,  1012,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,   381,   382,   383,     0,
       0,  1044,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   380,   381,
     382,   383,     0,     0,  1055,     0,     0,     0,     0,   380,
     381,   382,   383,     0,     0,  1074
};

static const yytype_int16 yycheck[] =
{
      11,     0,    85,     0,   292,     5,    41,    42,    34,     9,
      57,     9,    10,    24,   784,   785,    27,   252,   253,    30,
      31,    32,    11,    11,   178,    36,    37,    38,     4,     4,
      30,     7,     7,    57,    45,    59,    60,    35,   178,     3,
      72,    71,    71,     7,     8,     9,    57,     3,    47,   174,
      47,     7,     8,     9,   256,   257,   181,    15,   179,    24,
     181,    11,    66,    67,    68,    69,    70,    71,    79,    72,
     179,     7,   181,    84,    37,    38,     4,     5,    43,    66,
      67,    68,    69,    70,    71,    43,    85,   179,    85,   181,
     174,   102,   174,   174,    57,   179,   174,    58,   179,   181,
     100,   179,   102,   181,    66,    67,    68,    69,    70,    71,
     193,     4,    62,    63,     7,    27,    66,    67,    68,    69,
      70,    71,    72,    84,    85,    86,   126,   127,   128,   179,
      91,   181,   132,   133,   134,   182,   136,    83,   138,   139,
     140,   173,   174,   175,   176,   145,   146,   147,   178,   178,
     150,   174,   152,   355,   154,   357,   179,   157,   182,   159,
      82,   174,   162,   174,   175,   165,   166,   167,   181,   169,
     174,   171,   175,   176,   179,   179,   181,   947,   178,   179,
     950,   192,   174,    90,    11,   174,   105,   174,   199,   181,
     216,   217,   181,   181,   193,   178,   193,   178,   126,   127,
     128,   236,   178,   178,    87,    88,   441,   242,   243,   173,
     174,   222,   174,   224,    34,    35,    99,   173,   174,   181,
     174,   456,   457,   173,   174,   175,   176,   181,     4,     5,
     174,   181,   267,   268,   269,    62,    63,   181,   178,    66,
      67,    68,    69,    70,    71,    72,   178,   258,    66,    67,
      68,    69,    70,    71,   174,   178,   491,     0,   293,   270,
     174,   181,    10,   174,   275,   187,   188,   181,   179,   174,
    1040,    70,    71,    72,   285,   286,   181,   288,   289,   290,
       4,     5,    43,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,     4,     5,    71,   174,    71,   319,   320,
     321,   322,   323,   181,   325,    23,   327,   400,    66,    67,
      68,    69,    70,    71,     3,   178,   289,   290,     7,     8,
     174,   342,    71,    72,   174,   179,   347,   181,   174,   179,
       4,   181,   305,   179,   178,   181,   173,   174,   175,   176,
      66,    67,    68,    69,    70,    71,   174,     4,     5,   281,
     282,   179,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   174,   173,   174,   175,   176,   179,   342,
     181,   174,   178,     5,   174,   468,   179,     9,   181,   179,
     401,   181,   174,   174,   178,   406,   174,   179,   424,   181,
     181,   400,   437,   400,   174,   440,   417,   418,    30,   179,
     178,   181,    66,    67,    68,    69,    70,    71,    72,   430,
     174,   432,   344,   345,   174,   174,   174,   181,   174,   179,
     179,   442,   443,   179,   173,   174,   175,   176,    19,    20,
     451,   452,   453,   174,    67,    68,    69,    70,    71,    72,
     181,   174,   174,   180,   181,   454,   179,   454,   174,   181,
     471,   749,   174,   179,   752,   181,    57,   179,   178,   468,
     181,   468,    13,    13,    15,    15,    17,    17,   100,   174,
     102,    62,    63,   181,   179,    66,    67,    68,    69,    70,
      71,    72,   414,   415,   174,     4,     5,   419,   420,    40,
      40,   181,    43,    43,   126,   127,   128,    48,    48,   178,
     132,   133,   134,   178,   136,   178,   138,   139,   140,   173,
     174,   175,   176,   145,   146,   147,   174,    12,   150,   174,
     152,   179,   154,   174,   179,   157,   174,   159,   179,   178,
     162,   179,   178,   165,   166,   167,   178,   169,   178,   171,
     173,   174,   175,   176,     4,     5,   178,   179,    69,    70,
      71,    72,   174,   174,   575,   576,   181,   179,   179,    67,
     178,    69,    70,    71,    72,   573,   574,    62,    63,   814,
     178,    66,    67,    68,    69,    70,    71,    72,    45,    81,
      82,   174,   173,   174,   175,   176,   179,   608,   833,     4,
       5,    48,    49,   614,   615,    62,    63,   618,   643,    66,
      67,    68,    69,    70,    71,    72,    13,   174,    15,   178,
      17,   632,   179,   174,   659,   660,   174,   174,   179,   174,
     174,   179,   179,   179,   179,   179,   647,   648,   649,   174,
     174,     4,     5,    40,   179,   179,    43,   658,   178,   684,
     174,    48,   174,   664,   665,   179,   181,   179,   178,   670,
     671,   672,   173,   174,   175,   176,   588,   589,   174,   591,
     592,   682,   683,   179,   685,   173,   174,   175,   176,   178,
     174,   692,    38,    39,   695,   179,   181,   770,   173,   174,
     175,   176,    59,    60,   705,   174,   178,   708,   709,   710,
     179,   712,   713,   174,   174,   178,   174,   181,   179,   179,
     721,   179,     4,     5,   178,   178,   173,   174,   175,   176,
     178,     5,    45,   178,   646,   178,   178,   178,    42,   178,
     178,    71,   178,   178,   178,   178,   747,   748,    50,    62,
      63,   178,   178,    66,    67,    68,    69,    70,    71,    72,
      62,    63,   178,   178,    66,    67,    68,    69,    70,    71,
      72,   178,   178,   774,   178,   178,   178,   178,   178,   178,
      13,   770,    15,   770,    17,   178,   178,   178,   178,   178,
     178,    72,   178,   178,   795,   796,   178,   178,   178,   800,
     801,   178,   178,   178,   178,   806,   807,    40,   178,    15,
      43,   178,    18,   178,   178,    48,   178,   178,   178,   178,
     178,    27,   178,   178,   178,    31,    32,    62,    63,   178,
      36,    66,    67,    68,    69,    70,    71,    72,   178,   178,
     178,   178,    48,    49,    50,   178,   178,   800,   801,   178,
     178,    57,    58,    59,   178,   181,   179,   179,   179,   860,
     173,   174,   175,   176,   865,   181,   854,   855,   178,   870,
     895,   173,   174,   175,   176,    81,   181,   178,   178,   178,
      42,   793,   794,   179,   179,    45,   178,   178,     9,   178,
      42,   181,   893,   181,   181,   181,   897,   181,   181,   179,
     179,   179,   179,   178,   977,   978,   178,   908,   179,   179,
      80,   178,   181,   181,   915,   179,   179,   179,   179,   179,
     179,   922,   178,   924,    62,    63,   927,   179,    66,    67,
      68,    69,    70,    71,    72,   179,    80,   179,   173,   174,
     175,   176,   943,   179,   179,  1018,   181,     5,    57,   181,
     181,   179,   179,   179,   179,  1028,   178,   178,  1031,   960,
     179,   181,   874,   875,   178,    42,   179,   179,    37,   175,
      42,   178,  1045,    71,   179,   179,    71,    71,   979,   185,
      47,    57,   179,   179,   178,   178,   192,   178,   977,   978,
     977,   978,    46,   199,   178,    37,    71,   179,   179,     4,
      47,    47,  1003,    62,    63,  1006,   424,    66,    67,    68,
      69,    70,    71,    72,   664,   590,   292,   223,  1002,   593,
    1021,  1022,   454,   860,  1072,   421,   434,   233,  1024,  1018,
     782,  1018,    -1,    -1,    -1,   173,   174,   175,   176,  1028,
      -1,  1028,  1031,   181,  1031,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,  1056,  1045,    -1,  1045,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    62,    63,    -1,   275,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,
     316,   317,   318,    -1,   173,   174,   175,   176,   324,    -1,
     326,    -1,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,    -1,    -1,
     346,    -1,   348,   349,   350,   351,    -1,    -1,   354,    -1,
     356,    -1,   358,    -1,    -1,    -1,   362,   363,   364,   365,
     366,   367,   368,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,    -1,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,   403,   173,   174,
     175,   176,    -1,    -1,   179,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,   451,   452,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,     5,   182,    -1,    -1,     9,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   611,    -1,    -1,   614,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,   100,
      -1,   102,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,   664,    -1,
     173,   174,   175,   176,    -1,   126,   127,   128,   181,   675,
     676,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,     5,   157,    -1,   159,     9,
      -1,   162,    -1,    -1,   165,   166,   167,    -1,   169,   715,
     171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,    -1,
      30,    -1,   173,   174,   175,   176,   732,   733,   179,    -1,
     181,    -1,    -1,    -1,   740,   173,   174,   175,   176,    -1,
      -1,   179,    -1,   181,    -1,   751,    -1,    -1,   754,   755,
      -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,    62,
      63,   181,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,   777,    -1,   779,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,   802,   803,   804,    -1,
      -1,    -1,    -1,    62,    63,    -1,   812,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,
     150,    -1,   152,    -1,   154,    -1,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,   860,   165,   166,   167,    -1,   169,
      -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     173,   174,   175,   176,    -1,   881,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    62,    63,    -1,   904,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   919,   173,   174,   175,   176,    -1,    -1,
     926,    -1,   181,   929,    -1,    -1,   932,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,   945,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,   955,
     956,   957,   958,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      -1,    -1,   179,    -1,  1020,    62,    63,    64,    65,  1025,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    84,   173,   174,
     175,   176,    -1,    -1,    -1,    92,   181,    -1,  1054,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,     3,     4,
       5,   178,     7,     8,     9,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
       3,     4,     5,   178,     7,     8,     9,   182,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
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
     173,    -1,     3,     4,     5,   178,     7,     8,     9,   182,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    29,    30,
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
     171,   172,   173,    -1,    -1,    -1,    -1,   178,   179,     3,
       4,     5,    -1,     7,     8,     9,    -1,   173,   174,   175,
     176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   178,   179,     3,     4,     5,    -1,
       7,     8,     9,    -1,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    79,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,    -1,   161,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,   178,   179,     3,     4,     5,    -1,     7,     8,     9,
      -1,    11,    -1,    -1,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    29,
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
      -1,   161,   162,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,     3,     4,     5,   178,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
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
     168,   169,   170,   171,   172,   173,    -1,     3,     4,     5,
     178,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
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
     156,   157,   158,   159,    -1,   161,   162,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,     3,
       4,     5,   178,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
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
      -1,     5,    62,    63,   178,     9,    66,    67,    68,    69,
      70,    71,    72,    -1,   173,   174,   175,   176,    -1,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
       9,    -1,    -1,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   181,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    30,   136,    -1,   138,   139,   140,    92,    -1,    -1,
      -1,   145,   146,   147,    -1,   100,   150,   102,   152,    -1,
     154,    -1,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,
      -1,   165,   166,   167,     5,   169,    -1,   171,     9,    -1,
      -1,   126,   127,   128,   178,    -1,    -1,   132,   133,   134,
      -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,    30,
     145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,   154,
      -1,   100,   157,   102,   159,    -1,    -1,   162,    -1,    -1,
     165,   166,   167,    -1,   169,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,   100,
     159,   102,    -1,   162,    -1,    -1,   165,   166,   167,    -1,
     169,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,   138,   139,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,   154,    -1,    -1,   157,    -1,   159,    -1,
      -1,   162,    -1,    -1,   165,   166,   167,    -1,   169,    -1,
     171,    -1,     4,     5,     6,    -1,    -1,   178,    10,    -1,
      -1,    -1,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,   101,
      62,   103,   104,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
       4,     5,     6,   155,    -1,    -1,    10,    -1,   160,    -1,
      14,   163,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,   173,   174,   175,   176,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    -1,    -1,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,     4,     5,
       6,   155,    -1,    -1,    10,    -1,   160,    -1,    14,   163,
      16,    -1,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    -1,    62,    63,    60,    61,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    -1,    -1,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,   103,   104,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    62,    63,    -1,   133,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,   163,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    -1,    62,    63,
      -1,   181,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    -1,    62,    63,    -1,   181,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      62,    63,    -1,   181,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,    -1,
     173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,    -1,
      -1,   173,   174,   175,   176,    -1,    62,    63,    -1,   181,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      -1,    62,    63,    -1,   181,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,   173,   174,   175,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,   173,   174,   175,   176,    -1,    62,    63,
      -1,   181,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,    62,    63,   179,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    62,    63,   179,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    62,    63,   179,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   173,   174,
     175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    62,    63,   179,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,    62,    63,   179,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,
      -1,    -1,    -1,    -1,   173,   174,   175,   176,    62,    63,
     179,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      62,    63,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    -1,    -1,   179,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    62,    63,   179,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    62,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    62,    63,   179,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    62,    63,   179,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,   173,   174,   175,
     176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   173,   174,
     175,   176,    62,    63,   179,    -1,    66,    67,    68,    69,
      70,    71,    72,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    62,    63,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    62,
      63,   179,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,
      62,    63,   179,    -1,    66,    67,    68,    69,    70,    71,
      72,    62,    63,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,
      -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    62,
      63,   179,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    62,    63,   179,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,    -1,    -1,   179,    -1,    -1,
      -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,    62,    63,   179,
      -1,    66,    67,    68,    69,    70,    71,    72,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,   179
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
     184,   185,   187,   194,   195,   197,   198,   202,   214,   215,
     220,   226,   233,   241,   249,   252,   256,   259,   265,    71,
     178,    71,   178,   234,   253,   257,     4,     7,   212,   212,
     212,     3,     4,     5,     7,     8,     9,    29,    30,    33,
      62,    63,    64,    65,    76,    79,    96,    97,   100,   102,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   156,
     157,   158,   159,   161,   162,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   178,   200,   201,   203,   209,
     211,   214,   215,   188,   189,   178,   200,   178,   178,   200,
      27,     7,   242,   250,   203,    57,    59,    60,   182,   288,
     192,   200,   203,     4,     5,   213,   203,   200,   203,   200,
     203,     4,     5,   276,   277,     9,   173,   174,   210,   211,
     278,   212,    84,    92,   182,   200,   203,   289,    84,    92,
     105,   289,   289,    83,   203,   208,    11,    52,   208,   208,
      58,    84,    85,    86,    91,    90,   203,   195,   202,   214,
     215,   200,   200,   200,   105,   178,   178,   178,   178,   178,
     200,   289,   200,   200,     0,    43,   186,    87,    88,    99,
      71,    71,    23,   203,   216,   217,   200,   216,     4,   203,
     185,   178,   178,    34,    35,   178,   178,   203,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   203,
     200,   203,    66,    67,    68,    69,    70,    71,   174,    19,
      20,    62,    63,    66,    67,    68,    69,    70,    71,    72,
     173,   174,   175,   176,     4,     5,   227,   228,     4,     5,
     229,   230,   200,   216,   216,   200,   203,   244,   185,   260,
     266,   178,    57,   178,     4,     7,   178,   200,   203,   279,
      57,   182,   281,   286,   178,   178,   181,   181,   181,   178,
     178,   181,   211,   211,   181,   203,   200,   203,    10,   181,
     181,   200,   181,   208,   193,    11,   181,   196,   181,   208,
      11,   208,   196,   196,     5,   199,   199,   199,   179,   203,
     200,   181,   181,   181,    42,   208,   208,   208,   203,   200,
     221,   179,   200,   203,   218,   219,   179,    71,   254,    13,
      15,    17,    40,    43,    48,   258,   216,   216,   203,   203,
     203,    92,   200,   289,   289,     4,     5,   206,   207,   206,
     207,   208,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   289,   203,   203,   203,   203,   203,   203,
     203,   179,   203,   200,   200,   200,   200,   200,   203,   203,
     203,   179,   203,   203,   200,   203,   200,   203,   200,   200,
     179,   200,   179,   200,   179,   200,   179,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   289,   200,   216,
     216,   200,   203,   200,   200,   200,   200,   179,   179,   200,
     199,   200,   199,   200,   179,   179,   200,   200,   200,   200,
     200,   200,   200,   190,   191,   205,   204,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   178,   178,
     181,   178,   178,   181,   179,   179,    42,   243,    13,    15,
      17,    40,    43,    48,   251,    45,   185,   203,   178,   200,
     203,    50,   280,   180,   181,   178,     4,     7,   178,     9,
     287,   216,   216,     4,     5,   203,   203,   216,   216,   277,
       9,   210,   181,    81,    82,    92,   200,   203,   203,   281,
     208,   200,   208,   196,   203,   203,   178,   181,   181,   181,
     179,   179,   200,   203,   200,   203,   203,   187,   181,   196,
     196,     4,     5,   225,   181,   235,   185,   203,   179,   179,
     181,   181,   181,   179,   179,   181,   181,   179,   178,   178,
     179,   179,   181,   181,   196,   181,   179,   179,   179,   179,
     179,   179,   181,   179,   179,   181,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   181,   179,   179,   181,   181,
     181,   179,   181,   181,   179,   181,   179,   179,   179,   179,
     179,   181,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   181,   181,   179,   179,   179,   179,   179,   179,
     181,   179,   179,   179,   179,   179,   179,   181,   181,   181,
     179,   181,   181,   179,   181,   181,   212,   290,   212,   291,
     203,   203,   216,   216,   228,   216,   216,   230,    42,   245,
     261,    48,    49,   267,   181,   203,   179,   181,   179,   178,
     200,   200,   203,   203,   282,   283,   203,     4,     5,   273,
     275,   179,   179,   178,   178,   181,   181,   179,   179,   203,
      80,    80,   181,   181,   181,   208,   181,   181,   216,   203,
     203,   203,   181,   203,   208,   208,   222,   219,   203,    15,
      43,   255,   203,   203,   203,   200,    92,   200,   179,   179,
     203,   203,   208,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   200,   203,   200,   200,   200,   203,   203,   207,
     200,   207,   200,   200,   181,   181,   179,   179,   179,   179,
      38,    39,   247,   185,   203,   181,    57,   200,   200,   280,
     181,   273,   273,   179,   178,   178,   181,   216,   216,   203,
     203,   181,   289,   289,   200,   200,   200,   203,   203,   179,
     179,   179,   179,   181,   200,   196,   178,    11,   179,   179,
     179,   179,   179,   179,   181,   179,   179,   179,   196,   179,
     179,   179,   179,   179,   179,   181,   179,   179,   179,   181,
     179,   179,   181,   179,   181,   179,   181,   181,   179,   181,
     179,   179,   181,   179,   179,   212,   212,   244,    42,    37,
     262,   179,   203,   178,   179,   181,   203,   284,   216,   216,
     274,   179,   179,   200,   181,   181,    71,    71,    71,   203,
     181,   208,     4,     5,   231,   232,   203,   200,   203,   203,
     200,   203,   203,   200,   203,   200,   200,   246,   248,    47,
     269,    59,    60,   179,   203,    57,   200,   179,   273,   179,
     179,   273,   200,   200,   200,   200,   200,   179,   203,   178,
     178,   179,   181,    12,   239,   179,   181,   179,   179,   179,
     179,   179,   179,   179,   179,   185,   185,   203,    46,   268,
     178,   181,   178,   179,   285,    71,   179,   179,   223,   232,
     203,   236,   203,    45,   272,   185,   263,   200,   203,   203,
     287,   200,   185,   185,   179,   270,    13,    15,    17,    40,
      43,    48,   264,   179,   181,   179,   181,   273,    24,    43,
     224,   237,   185,   200,   203,    13,    15,    17,    40,    43,
      48,   238,   271,   179,   179,     4,   240,   269
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   183,   184,   185,   186,   185,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   187,   189,   187,   187,   187,
     187,   187,   187,   187,   190,   187,   191,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   192,   187,
     193,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     194,   194,   194,   194,   194,   195,   195,   195,   195,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   198,   198,
     199,   199,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   202,   202,   204,   203,   205,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   206,   207,   208,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     210,   210,   210,   211,   211,   211,   212,   212,   213,   213,
     213,   213,   214,   215,   217,   216,   218,   218,   218,   219,
     219,   221,   222,   223,   220,   224,   224,   225,   225,   226,
     226,   226,   226,   227,   227,   228,   228,   228,   228,   229,
     229,   230,   230,   230,   230,   231,   231,   231,   232,   232,
     232,   232,   234,   235,   236,   237,   233,   238,   238,   238,
     238,   238,   238,   239,   239,   240,   240,   242,   241,   243,
     243,   244,   244,   245,   246,   245,   247,   248,   247,   250,
     249,   251,   251,   251,   251,   251,   251,   253,   254,   252,
     255,   255,   257,   256,   258,   258,   258,   258,   258,   258,
     260,   261,   262,   263,   259,   264,   264,   264,   264,   264,
     264,   266,   265,   267,   267,   268,   268,   269,   270,   271,
     269,   272,   272,   273,   274,   273,   275,   275,   275,   275,
     276,   276,   277,   277,   277,   277,   278,   278,   278,   278,
     279,   279,   279,   279,   279,   280,   280,   280,   282,   281,
     283,   281,   284,   281,   285,   281,   286,   281,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   289,   289,   290,   290,   291,   291
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     3,     3,     0,     4,     0,
       4,     2,     3,     3,     3,     3,     3,     3,     4,     6,
       1,     4,     4,     6,     6,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     4,     8,
       4,     4,     4,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       1,     2,     2,     1,     1,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     0,     2,     0,     1,     3,     1,
       1,     0,     0,     0,    11,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     3,     1,     1,     4,     4,     1,
       3,     1,     1,     4,     4,     0,     1,     3,     1,     1,
       3,     3,     0,     0,     0,     0,    14,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     1,     0,     7,     1,
       2,     1,     1,     0,     0,     5,     0,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     0,     6,
       1,     1,     0,     4,     1,     2,     1,     1,     1,     1,
       0,     0,     0,     0,    11,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     1,     0,     2,     0,     0,     0,
       7,     0,     1,     1,     0,     4,     1,     4,     1,     4,
       1,     3,     1,     4,     1,     4,     1,     1,     3,     3,
       0,     2,     4,     1,     3,     0,     2,     6,     0,     4,
       0,     4,     0,     6,     0,     9,     0,     3,     0,     1,
       0,     2,     2,     4,     1,     4,     6,     6,     7,    10,
      12,     7,    10,    12,     2,     1,     1,     3,     1,     3
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

    {create_function(fFRNBF_SIZE);}

    break;

  case 251:

    {create_function(fPEEK4);}

    break;

  case 252:

    {create_function(fPEEK);}

    break;

  case 253:

    {create_function(fMOUSEX);}

    break;

  case 254:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 255:

    {create_pushstr("");create_function(fMOUSEX);}

    break;

  case 256:

    {create_function(fMOUSEY);}

    break;

  case 257:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 258:

    {create_pushstr("");create_function(fMOUSEY);}

    break;

  case 259:

    {create_function(fMOUSEB);}

    break;

  case 260:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 261:

    {create_pushstr("");create_function(fMOUSEB);}

    break;

  case 262:

    {create_function(fMOUSEMOD);}

    break;

  case 263:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 264:

    {create_pushstr("");create_function(fMOUSEMOD);}

    break;

  case 265:

    {create_function(fAND);}

    break;

  case 266:

    {create_function(fOR);}

    break;

  case 267:

    {create_function(fEOR);}

    break;

  case 268:

    {create_function(fTELL);}

    break;

  case 269:

    {add_command(cTOKEN2,NULL,NULL);}

    break;

  case 270:

    {add_command(cTOKEN,NULL,NULL);}

    break;

  case 271:

    {add_command(cSPLIT2,NULL,NULL);}

    break;

  case 272:

    {add_command(cSPLIT,NULL,NULL);}

    break;

  case 273:

    {create_execute(0);add_command(cSWAP,NULL,NULL);add_command(cPOP,NULL,NULL);}

    break;

  case 274:

    {create_myopen(OPEN_PRINTER);}

    break;

  case 275:

    {create_myopen(0);}

    break;

  case 276:

    {create_myopen(OPEN_HAS_MODE);}

    break;

  case 277:

    {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}

    break;

  case 278:

    {create_myopen(OPEN_HAS_STREAM);}

    break;

  case 279:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}

    break;

  case 280:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 281:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 282:

    {(yyval.fnum)=-(yyvsp[0].fnum);}

    break;

  case 283:

    {(yyval.fnum)=(yyvsp[0].fnum);}

    break;

  case 284:

    {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}

    break;

  case 285:

    {(yyval.fnum)=(double)strtol((yyvsp[0].digits),NULL,0);}

    break;

  case 286:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}

    break;

  case 287:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 288:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 289:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}

    break;

  case 290:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 291:

    {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}

    break;

  case 292:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 293:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}

    break;

  case 294:

    {add_command(cPUSHFREE,NULL,NULL);}

    break;

  case 301:

    {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("do not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}

    break;

  case 302:

    {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL,NULL);add_command(cCLEARREFS,NULL,NULL);firstref=lastref=lastcmd;
		       create_count_params();}

    break;

  case 303:

    {create_require(stFREE);add_command(cPOP,NULL,NULL);}

    break;

  case 304:

    {add_command(cCLEARREFS,NULL,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL,NULL);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL,NULL,NULL);lastref=NULL;create_endfunction();poplabel();}

    break;

  case 305:

    {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 306:

    {missing_endsub--;}

    break;

  case 307:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 308:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}

    break;

  case 309:

    {exported=FALSE;}

    break;

  case 310:

    {exported=TRUE;}

    break;

  case 311:

    {exported=FALSE;}

    break;

  case 312:

    {exported=TRUE;}

    break;

  case 315:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}

    break;

  case 316:

    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}

    break;

  case 317:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}

    break;

  case 318:

    {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}

    break;

  case 321:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}

    break;

  case 322:

    {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}

    break;

  case 323:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}

    break;

  case 324:

    {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}

    break;

  case 328:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 329:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}

    break;

  case 330:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}

    break;

  case 331:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}

    break;

  case 332:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);missing_next++;missing_next_line=yylineno;}

    break;

  case 333:

    {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE,NULL,NULL);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}

    break;

  case 334:

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

  case 335:

    {
             swap();popgoto();poplabel();}

    break;

  case 336:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 337:

    {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 338:

    {missing_next--;}

    break;

  case 339:

    {report_conflicting_close("a closing next is expected before endif",'e');}

    break;

  case 340:

    {report_conflicting_close("a closing next is expected before wend",'w');}

    break;

  case 341:

    {report_conflicting_close("a closing next is expected before until",'l');}

    break;

  case 342:

    {report_conflicting_close("a closing next is expected before loop",'l');}

    break;

  case 343:

    {create_pushdbl(1);}

    break;

  case 345:

    {pop(stSTRING);}

    break;

  case 346:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }

    break;

  case 347:

    {push_switch_id();add_command(cBEGIN_SWITCH_MARK,NULL,NULL);}

    break;

  case 348:

    {add_command(cBREAK_HERE,NULL,NULL);add_command(cPOP,NULL,NULL);add_command(cEND_SWITCH_MARK,NULL,NULL);pop_switch_id();}

    break;

  case 354:

    {add_command(cSWITCH_COMPARE,NULL,NULL);add_command(cDECIDE,NULL,NULL);add_command(cNEXT_CASE,NULL,NULL);}

    break;

  case 355:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 357:

    {add_command(cNEXT_CASE_HERE,NULL,NULL);}

    break;

  case 359:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}

    break;

  case 361:

    {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 362:

    {missing_loop--;popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 363:

    {report_conflicting_close("a closing loop is expected before endif",'e');}

    break;

  case 364:

    {report_conflicting_close("a closing loop is expected before wend",'w');}

    break;

  case 365:

    {report_conflicting_close("a closing loop is expected before until",'l');}

    break;

  case 366:

    {report_conflicting_close("a closing loop is expected before next",'n');}

    break;

  case 367:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}

    break;

  case 368:

    {add_command(cDECIDE,NULL,NULL);
	      pushlabel();}

    break;

  case 370:

    {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 371:

    {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 372:

    {loop_nesting++;add_command(cBEGIN_LOOP_MARK,NULL,NULL);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}

    break;

  case 374:

    {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 375:

    {missing_until--;add_command(cDECIDE,NULL,NULL);popgoto();add_command(cBREAK_HERE,NULL,NULL);add_command(cEND_LOOP_MARK,NULL,NULL);loop_nesting--;}

    break;

  case 376:

    {report_conflicting_close("a closing until is expected before endif",'e');}

    break;

  case 377:

    {report_conflicting_close("a closing until is expected before wend",'w');}

    break;

  case 378:

    {report_conflicting_close("a closing until is expected before loop",'l');}

    break;

  case 379:

    {report_conflicting_close("a closing until is expected before next",'n');}

    break;

  case 380:

    {add_command(cDECIDE,NULL,NULL);storelabel();pushlabel();}

    break;

  case 381:

    {missing_endif++;missing_endif_line=yylineno;}

    break;

  case 382:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 383:

    {poplabel();}

    break;

  case 385:

    {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}

    break;

  case 386:

    {missing_endif--;}

    break;

  case 387:

    {report_conflicting_close("a closing endif is expected before wend",'w');}

    break;

  case 388:

    {report_conflicting_close("a closing endif is expected before until",'l');}

    break;

  case 389:

    {report_conflicting_close("a closing endif is expected before loop",'l');}

    break;

  case 390:

    {report_conflicting_close("a closing endif is expected before next",'n');}

    break;

  case 391:

    {in_short_if++;add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 393:

    {error(sERROR,"an if-statement without 'then' does not allow 'endif'");}

    break;

  case 394:

    {poplabel();}

    break;

  case 398:

    {add_command(cDECIDE,NULL,NULL);pushlabel();}

    break;

  case 399:

    {swap();matchgoto();swap();poplabel();}

    break;

  case 404:

    {add_command(cCHKPROMPT,NULL,NULL);}

    break;

  case 406:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 407:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 408:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 409:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 412:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 413:

    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}

    break;

  case 414:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);}

    break;

  case 415:

    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}

    break;

  case 416:

    {create_strdata((yyvsp[0].string));}

    break;

  case 417:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 418:

    {create_strdata((yyvsp[0].string));}

    break;

  case 419:

    {create_dbldata((yyvsp[0].fnum));}

    break;

  case 423:

    {create_print('s');}

    break;

  case 424:

    {create_print('s');}

    break;

  case 425:

    {create_print('d');}

    break;

  case 426:

    {create_print('u');}

    break;

  case 427:

    {create_print('U');}

    break;

  case 428:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,1);}

    break;

  case 429:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 430:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}

    break;

  case 431:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 432:

    {create_pps(cPUSHSTREAM,1);}

    break;

  case 433:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 434:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 435:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 436:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}

    break;

  case 437:

    {create_pps(cPOPSTREAM,0);}

    break;

  case 438:

    {create_pushstr("?");create_print('s');}

    break;

  case 439:

    {create_pushstr((yyvsp[0].string));create_print('s');}

    break;

  case 440:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 441:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),FALSE);create_pps(cPUSHSTREAM,0);}

    break;

  case 442:

    {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}

    break;

  case 443:

    {create_pps(cPUSHSTREAM,0);}

    break;

  case 444:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 445:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 446:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 447:

    {add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 448:

    {add_command(cMOVE,NULL,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 449:

    {add_command(cMOVE,NULL,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 450:

    {add_command(cMOVE,NULL,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 451:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL,NULL);}

    break;

  case 452:

    {create_colour(2);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 453:

    {create_colour(3);add_command(cMOVE,NULL,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}

    break;

  case 456:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 457:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 458:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP,NULL,NULL);}

    break;

  case 459:

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
