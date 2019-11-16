/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

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
