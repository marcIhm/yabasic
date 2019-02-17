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
    tUSING = 304,
    tPRINT = 305,
    tINPUT = 306,
    tRETURN = 307,
    tDIM = 308,
    tEND = 309,
    tEXIT = 310,
    tAT = 311,
    tSCREEN = 312,
    tREVERSE = 313,
    tCOLOUR = 314,
    tBACKCOLOUR = 315,
    tAND = 316,
    tOR = 317,
    tNOT = 318,
    tEOR = 319,
    tNEQ = 320,
    tLEQ = 321,
    tGEQ = 322,
    tLTN = 323,
    tGTN = 324,
    tEQU = 325,
    tPOW = 326,
    tREAD = 327,
    tDATA = 328,
    tRESTORE = 329,
    tOPEN = 330,
    tCLOSE = 331,
    tSEEK = 332,
    tTELL = 333,
    tAS = 334,
    tREADING = 335,
    tWRITING = 336,
    tORIGIN = 337,
    tWINDOW = 338,
    tDOT = 339,
    tLINE = 340,
    tCIRCLE = 341,
    tTRIANGLE = 342,
    tTEXT = 343,
    tCLEAR = 344,
    tFILL = 345,
    tPRINTER = 346,
    tWAIT = 347,
    tBELL = 348,
    tLET = 349,
    tARDIM = 350,
    tARSIZE = 351,
    tBIND = 352,
    tRECT = 353,
    tGETBIT = 354,
    tPUTBIT = 355,
    tGETCHAR = 356,
    tPUTCHAR = 357,
    tNEW = 358,
    tCURVE = 359,
    tSIN = 360,
    tASIN = 361,
    tCOS = 362,
    tACOS = 363,
    tTAN = 364,
    tATAN = 365,
    tEXP = 366,
    tLOG = 367,
    tSQRT = 368,
    tSQR = 369,
    tMYEOF = 370,
    tABS = 371,
    tSIG = 372,
    tINT = 373,
    tCEIL = 374,
    tFLOOR = 375,
    tFRAC = 376,
    tMOD = 377,
    tRAN = 378,
    tVAL = 379,
    tLEFT = 380,
    tRIGHT = 381,
    tMID = 382,
    tLEN = 383,
    tMIN = 384,
    tMAX = 385,
    tSTR = 386,
    tINKEY = 387,
    tCHR = 388,
    tASC = 389,
    tHEX = 390,
    tDEC = 391,
    tBIN = 392,
    tUPPER = 393,
    tLOWER = 394,
    tMOUSEX = 395,
    tMOUSEY = 396,
    tMOUSEB = 397,
    tMOUSEMOD = 398,
    tTRIM = 399,
    tLTRIM = 400,
    tRTRIM = 401,
    tINSTR = 402,
    tRINSTR = 403,
    tCHOMP = 404,
    tSYSTEM = 405,
    tSYSTEM2 = 406,
    tPEEK = 407,
    tPEEK2 = 408,
    tPOKE = 409,
    tDATE = 410,
    tTIME = 411,
    tTOKEN = 412,
    tTOKENALT = 413,
    tSPLIT = 414,
    tSPLITALT = 415,
    tGLOB = 416,
    UMINUS = 417
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
