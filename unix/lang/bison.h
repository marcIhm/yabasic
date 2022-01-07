/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BISON_H_INCLUDED
# define YY_YY_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tFNUM = 258,                   /* tFNUM  */
    tSYMBOL = 259,                 /* tSYMBOL  */
    tSTRSYM = 260,                 /* tSTRSYM  */
    tDOCU = 261,                   /* tDOCU  */
    tDIGITS = 262,                 /* tDIGITS  */
    tHEXDIGITS = 263,              /* tHEXDIGITS  */
    tBINDIGITS = 264,              /* tBINDIGITS  */
    tSTRING = 265,                 /* tSTRING  */
    tFOR = 266,                    /* tFOR  */
    tTO = 267,                     /* tTO  */
    tSTEP = 268,                   /* tSTEP  */
    tNEXT = 269,                   /* tNEXT  */
    tWHILE = 270,                  /* tWHILE  */
    tWEND = 271,                   /* tWEND  */
    tREPEAT = 272,                 /* tREPEAT  */
    tUNTIL = 273,                  /* tUNTIL  */
    tIMPORT = 274,                 /* tIMPORT  */
    tGOTO = 275,                   /* tGOTO  */
    tGOSUB = 276,                  /* tGOSUB  */
    tLABEL = 277,                  /* tLABEL  */
    tON = 278,                     /* tON  */
    tSUB = 279,                    /* tSUB  */
    tENDSUB = 280,                 /* tENDSUB  */
    tLOCAL = 281,                  /* tLOCAL  */
    tSTATIC = 282,                 /* tSTATIC  */
    tEXPORT = 283,                 /* tEXPORT  */
    tERROR = 284,                  /* tERROR  */
    tEXECUTE = 285,                /* tEXECUTE  */
    tEXECUTE2 = 286,               /* tEXECUTE2  */
    tCOMPILE = 287,                /* tCOMPILE  */
    tRUNTIME_CREATED_SUB = 288,    /* tRUNTIME_CREATED_SUB  */
    tINTERRUPT = 289,              /* tINTERRUPT  */
    tBREAK = 290,                  /* tBREAK  */
    tCONTINUE = 291,               /* tCONTINUE  */
    tSWITCH = 292,                 /* tSWITCH  */
    tSEND = 293,                   /* tSEND  */
    tCASE = 294,                   /* tCASE  */
    tDEFAULT = 295,                /* tDEFAULT  */
    tLOOP = 296,                   /* tLOOP  */
    tDO = 297,                     /* tDO  */
    tSEP = 298,                    /* tSEP  */
    tEOPROG = 299,                 /* tEOPROG  */
    tIF = 300,                     /* tIF  */
    tTHEN = 301,                   /* tTHEN  */
    tELSE = 302,                   /* tELSE  */
    tELSIF = 303,                  /* tELSIF  */
    tENDIF = 304,                  /* tENDIF  */
    tIMPLICITENDIF = 305,          /* tIMPLICITENDIF  */
    tUSING = 306,                  /* tUSING  */
    tPRINT = 307,                  /* tPRINT  */
    tINPUT = 308,                  /* tINPUT  */
    tRETURN = 309,                 /* tRETURN  */
    tDIM = 310,                    /* tDIM  */
    tEND = 311,                    /* tEND  */
    tEXIT = 312,                   /* tEXIT  */
    tAT = 313,                     /* tAT  */
    tSCREEN = 314,                 /* tSCREEN  */
    tREVERSE = 315,                /* tREVERSE  */
    tCOLOUR = 316,                 /* tCOLOUR  */
    tBACKCOLOUR = 317,             /* tBACKCOLOUR  */
    tAND = 318,                    /* tAND  */
    tOR = 319,                     /* tOR  */
    tNOT = 320,                    /* tNOT  */
    tBITNOT = 321,                 /* tBITNOT  */
    tEOR = 322,                    /* tEOR  */
    tSHL = 323,                    /* tSHL  */
    tSHR = 324,                    /* tSHR  */
    tNEQ = 325,                    /* tNEQ  */
    tLEQ = 326,                    /* tLEQ  */
    tGEQ = 327,                    /* tGEQ  */
    tLTN = 328,                    /* tLTN  */
    tGTN = 329,                    /* tGTN  */
    tEQU = 330,                    /* tEQU  */
    tPOW = 331,                    /* tPOW  */
    tREAD = 332,                   /* tREAD  */
    tDATA = 333,                   /* tDATA  */
    tRESTORE = 334,                /* tRESTORE  */
    tOPEN = 335,                   /* tOPEN  */
    tCLOSE = 336,                  /* tCLOSE  */
    tSEEK = 337,                   /* tSEEK  */
    tTELL = 338,                   /* tTELL  */
    tAS = 339,                     /* tAS  */
    tREADING = 340,                /* tREADING  */
    tWRITING = 341,                /* tWRITING  */
    tORIGIN = 342,                 /* tORIGIN  */
    tWINDOW = 343,                 /* tWINDOW  */
    tDOT = 344,                    /* tDOT  */
    tLINE = 345,                   /* tLINE  */
    tCIRCLE = 346,                 /* tCIRCLE  */
    tTRIANGLE = 347,               /* tTRIANGLE  */
    tTEXT = 348,                   /* tTEXT  */
    tCLEAR = 349,                  /* tCLEAR  */
    tFILL = 350,                   /* tFILL  */
    tPRINTER = 351,                /* tPRINTER  */
    tWAIT = 352,                   /* tWAIT  */
    tBELL = 353,                   /* tBELL  */
    tLET = 354,                    /* tLET  */
    tARDIM = 355,                  /* tARDIM  */
    tARSIZE = 356,                 /* tARSIZE  */
    tBIND = 357,                   /* tBIND  */
    tRECT = 358,                   /* tRECT  */
    tGETBIT = 359,                 /* tGETBIT  */
    tPUTBIT = 360,                 /* tPUTBIT  */
    tGETCHAR = 361,                /* tGETCHAR  */
    tPUTCHAR = 362,                /* tPUTCHAR  */
    tNEW = 363,                    /* tNEW  */
    tCURVE = 364,                  /* tCURVE  */
    tSIN = 365,                    /* tSIN  */
    tASIN = 366,                   /* tASIN  */
    tCOS = 367,                    /* tCOS  */
    tACOS = 368,                   /* tACOS  */
    tTAN = 369,                    /* tTAN  */
    tATAN = 370,                   /* tATAN  */
    tEXP = 371,                    /* tEXP  */
    tLOG = 372,                    /* tLOG  */
    tSQRT = 373,                   /* tSQRT  */
    tSQR = 374,                    /* tSQR  */
    tMYEOF = 375,                  /* tMYEOF  */
    tABS = 376,                    /* tABS  */
    tSIG = 377,                    /* tSIG  */
    tINT = 378,                    /* tINT  */
    tCEIL = 379,                   /* tCEIL  */
    tFLOOR = 380,                  /* tFLOOR  */
    tFRAC = 381,                   /* tFRAC  */
    tROUND = 382,                  /* tROUND  */
    tMOD = 383,                    /* tMOD  */
    tRAN = 384,                    /* tRAN  */
    tVAL = 385,                    /* tVAL  */
    tLEFT = 386,                   /* tLEFT  */
    tRIGHT = 387,                  /* tRIGHT  */
    tMID = 388,                    /* tMID  */
    tLEN = 389,                    /* tLEN  */
    tMIN = 390,                    /* tMIN  */
    tMAX = 391,                    /* tMAX  */
    tSTR = 392,                    /* tSTR  */
    tINKEY = 393,                  /* tINKEY  */
    tCHR = 394,                    /* tCHR  */
    tASC = 395,                    /* tASC  */
    tHEX = 396,                    /* tHEX  */
    tDEC = 397,                    /* tDEC  */
    tBIN = 398,                    /* tBIN  */
    tUPPER = 399,                  /* tUPPER  */
    tLOWER = 400,                  /* tLOWER  */
    tMOUSEX = 401,                 /* tMOUSEX  */
    tMOUSEY = 402,                 /* tMOUSEY  */
    tMOUSEB = 403,                 /* tMOUSEB  */
    tMOUSEMOD = 404,               /* tMOUSEMOD  */
    tTRIM = 405,                   /* tTRIM  */
    tLTRIM = 406,                  /* tLTRIM  */
    tRTRIM = 407,                  /* tRTRIM  */
    tINSTR = 408,                  /* tINSTR  */
    tRINSTR = 409,                 /* tRINSTR  */
    tCHOMP = 410,                  /* tCHOMP  */
    tSYSTEM = 411,                 /* tSYSTEM  */
    tSYSTEM2 = 412,                /* tSYSTEM2  */
    tPEEK = 413,                   /* tPEEK  */
    tPEEK2 = 414,                  /* tPEEK2  */
    tPOKE = 415,                   /* tPOKE  */
    tFRNFN_CALL = 416,             /* tFRNFN_CALL  */
    tFRNFN_CALL2 = 417,            /* tFRNFN_CALL2  */
    tFRNFN_SIZE = 418,             /* tFRNFN_SIZE  */
    tFRNBF_ALLOC = 419,            /* tFRNBF_ALLOC  */
    tFRNBF_FREE = 420,             /* tFRNBF_FREE  */
    tFRNBF_SIZE = 421,             /* tFRNBF_SIZE  */
    tFRNBF_DUMP = 422,             /* tFRNBF_DUMP  */
    tFRNBF_SET = 423,              /* tFRNBF_SET  */
    tFRNBF_GET = 424,              /* tFRNBF_GET  */
    tFRNBF_GET2 = 425,             /* tFRNBF_GET2  */
    tFRNBF_GET_BUFFER = 426,       /* tFRNBF_GET_BUFFER  */
    tFRNBF_SET_BUFFER = 427,       /* tFRNBF_SET_BUFFER  */
    tDATE = 428,                   /* tDATE  */
    tTIME = 429,                   /* tTIME  */
    tTOKEN = 430,                  /* tTOKEN  */
    tTOKENALT = 431,               /* tTOKENALT  */
    tSPLIT = 432,                  /* tSPLIT  */
    tSPLITALT = 433,               /* tSPLITALT  */
    tGLOB = 434,                   /* tGLOB  */
    tSTART_PROGRAM = 435,          /* tSTART_PROGRAM  */
    tSTART_EXPRESSION = 436,       /* tSTART_EXPRESSION  */
    tSTART_STRING_EXPRESSION = 437, /* tSTART_STRING_EXPRESSION  */
    tSTART_ASSIGNMENT = 438,       /* tSTART_ASSIGNMENT  */
    tSTART_FUNCTION_DEFINITION = 439, /* tSTART_FUNCTION_DEFINITION  */
    tEVAL = 440,                   /* tEVAL  */
    tEVAL2 = 441,                  /* tEVAL2  */
    UMINUS = 442                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int nnl;              /* number of newlines */
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
