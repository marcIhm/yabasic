/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2026
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


# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tFNUM = 3,                      /* tFNUM  */
  YYSYMBOL_tSYMBOL = 4,                    /* tSYMBOL  */
  YYSYMBOL_tSTRSYM = 5,                    /* tSTRSYM  */
  YYSYMBOL_tDOCU = 6,                      /* tDOCU  */
  YYSYMBOL_tDIGITS = 7,                    /* tDIGITS  */
  YYSYMBOL_tHEXDIGITS = 8,                 /* tHEXDIGITS  */
  YYSYMBOL_tBINDIGITS = 9,                 /* tBINDIGITS  */
  YYSYMBOL_tSTRING = 10,                   /* tSTRING  */
  YYSYMBOL_tFOR = 11,                      /* tFOR  */
  YYSYMBOL_tTO = 12,                       /* tTO  */
  YYSYMBOL_tSTEP = 13,                     /* tSTEP  */
  YYSYMBOL_tNEXT = 14,                     /* tNEXT  */
  YYSYMBOL_tWHILE = 15,                    /* tWHILE  */
  YYSYMBOL_tWEND = 16,                     /* tWEND  */
  YYSYMBOL_tREPEAT = 17,                   /* tREPEAT  */
  YYSYMBOL_tUNTIL = 18,                    /* tUNTIL  */
  YYSYMBOL_tIMPORT = 19,                   /* tIMPORT  */
  YYSYMBOL_tGOTO = 20,                     /* tGOTO  */
  YYSYMBOL_tGOSUB = 21,                    /* tGOSUB  */
  YYSYMBOL_tLABEL = 22,                    /* tLABEL  */
  YYSYMBOL_tON = 23,                       /* tON  */
  YYSYMBOL_tSUB = 24,                      /* tSUB  */
  YYSYMBOL_tENDSUB = 25,                   /* tENDSUB  */
  YYSYMBOL_tLOCAL = 26,                    /* tLOCAL  */
  YYSYMBOL_tSTATIC = 27,                   /* tSTATIC  */
  YYSYMBOL_tEXPORT = 28,                   /* tEXPORT  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tEXECUTE = 30,                  /* tEXECUTE  */
  YYSYMBOL_tEXECUTE2 = 31,                 /* tEXECUTE2  */
  YYSYMBOL_tCOMPILE = 32,                  /* tCOMPILE  */
  YYSYMBOL_tRUNTIME_CREATED_SUB = 33,      /* tRUNTIME_CREATED_SUB  */
  YYSYMBOL_tINTERRUPT = 34,                /* tINTERRUPT  */
  YYSYMBOL_tBREAK = 35,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 36,                 /* tCONTINUE  */
  YYSYMBOL_tSWITCH = 37,                   /* tSWITCH  */
  YYSYMBOL_tSEND = 38,                     /* tSEND  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tDEFAULT = 40,                  /* tDEFAULT  */
  YYSYMBOL_tLOOP = 41,                     /* tLOOP  */
  YYSYMBOL_tDO = 42,                       /* tDO  */
  YYSYMBOL_tSEP = 43,                      /* tSEP  */
  YYSYMBOL_tEOPROG = 44,                   /* tEOPROG  */
  YYSYMBOL_tIF = 45,                       /* tIF  */
  YYSYMBOL_tTHEN = 46,                     /* tTHEN  */
  YYSYMBOL_tELSE = 47,                     /* tELSE  */
  YYSYMBOL_tELSIF = 48,                    /* tELSIF  */
  YYSYMBOL_tENDIF = 49,                    /* tENDIF  */
  YYSYMBOL_tIMPLICITENDIF = 50,            /* tIMPLICITENDIF  */
  YYSYMBOL_tUSING = 51,                    /* tUSING  */
  YYSYMBOL_tPRINT = 52,                    /* tPRINT  */
  YYSYMBOL_tINPUT = 53,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 54,                   /* tRETURN  */
  YYSYMBOL_tDIM = 55,                      /* tDIM  */
  YYSYMBOL_tEND = 56,                      /* tEND  */
  YYSYMBOL_tEXIT = 57,                     /* tEXIT  */
  YYSYMBOL_tAT = 58,                       /* tAT  */
  YYSYMBOL_tSCREEN = 59,                   /* tSCREEN  */
  YYSYMBOL_tREVERSE = 60,                  /* tREVERSE  */
  YYSYMBOL_tCOLOUR = 61,                   /* tCOLOUR  */
  YYSYMBOL_tBACKCOLOUR = 62,               /* tBACKCOLOUR  */
  YYSYMBOL_tAND = 63,                      /* tAND  */
  YYSYMBOL_tOR = 64,                       /* tOR  */
  YYSYMBOL_tNOT = 65,                      /* tNOT  */
  YYSYMBOL_tBITNOT = 66,                   /* tBITNOT  */
  YYSYMBOL_tEOR = 67,                      /* tEOR  */
  YYSYMBOL_tSHL = 68,                      /* tSHL  */
  YYSYMBOL_tSHR = 69,                      /* tSHR  */
  YYSYMBOL_tNEQ = 70,                      /* tNEQ  */
  YYSYMBOL_tLEQ = 71,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 72,                      /* tGEQ  */
  YYSYMBOL_tLTN = 73,                      /* tLTN  */
  YYSYMBOL_tGTN = 74,                      /* tGTN  */
  YYSYMBOL_tEQU = 75,                      /* tEQU  */
  YYSYMBOL_tEQU2 = 76,                     /* tEQU2  */
  YYSYMBOL_tPOW = 77,                      /* tPOW  */
  YYSYMBOL_tREAD = 78,                     /* tREAD  */
  YYSYMBOL_tDATA = 79,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 80,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 81,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 82,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 83,                     /* tSEEK  */
  YYSYMBOL_tTELL = 84,                     /* tTELL  */
  YYSYMBOL_tAS = 85,                       /* tAS  */
  YYSYMBOL_tREADING = 86,                  /* tREADING  */
  YYSYMBOL_tWRITING = 87,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 88,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 89,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 90,                      /* tDOT  */
  YYSYMBOL_tLINE = 91,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 92,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 93,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 94,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 95,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 96,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 97,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 98,                     /* tWAIT  */
  YYSYMBOL_tBELL = 99,                     /* tBELL  */
  YYSYMBOL_tLET = 100,                     /* tLET  */
  YYSYMBOL_tARDIM = 101,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 102,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 103,                    /* tBIND  */
  YYSYMBOL_tRECT = 104,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 105,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 106,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 107,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 108,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 109,                     /* tNEW  */
  YYSYMBOL_tCURVE = 110,                   /* tCURVE  */
  YYSYMBOL_tSIN = 111,                     /* tSIN  */
  YYSYMBOL_tASIN = 112,                    /* tASIN  */
  YYSYMBOL_tCOS = 113,                     /* tCOS  */
  YYSYMBOL_tACOS = 114,                    /* tACOS  */
  YYSYMBOL_tTAN = 115,                     /* tTAN  */
  YYSYMBOL_tATAN = 116,                    /* tATAN  */
  YYSYMBOL_tEXP = 117,                     /* tEXP  */
  YYSYMBOL_tLOG = 118,                     /* tLOG  */
  YYSYMBOL_tSQRT = 119,                    /* tSQRT  */
  YYSYMBOL_tSQR = 120,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 121,                   /* tMYEOF  */
  YYSYMBOL_tABS = 122,                     /* tABS  */
  YYSYMBOL_tSIG = 123,                     /* tSIG  */
  YYSYMBOL_tINT = 124,                     /* tINT  */
  YYSYMBOL_tCEIL = 125,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 126,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 127,                    /* tFRAC  */
  YYSYMBOL_tROUND = 128,                   /* tROUND  */
  YYSYMBOL_tMOD = 129,                     /* tMOD  */
  YYSYMBOL_tRAN = 130,                     /* tRAN  */
  YYSYMBOL_tVAL = 131,                     /* tVAL  */
  YYSYMBOL_tLEFT = 132,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 133,                   /* tRIGHT  */
  YYSYMBOL_tMID = 134,                     /* tMID  */
  YYSYMBOL_tLEN = 135,                     /* tLEN  */
  YYSYMBOL_tMIN = 136,                     /* tMIN  */
  YYSYMBOL_tMAX = 137,                     /* tMAX  */
  YYSYMBOL_tSTR = 138,                     /* tSTR  */
  YYSYMBOL_tINKEY = 139,                   /* tINKEY  */
  YYSYMBOL_tCHR = 140,                     /* tCHR  */
  YYSYMBOL_tASC = 141,                     /* tASC  */
  YYSYMBOL_tHEX = 142,                     /* tHEX  */
  YYSYMBOL_tDEC = 143,                     /* tDEC  */
  YYSYMBOL_tBIN = 144,                     /* tBIN  */
  YYSYMBOL_tUPPER = 145,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 146,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 147,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 148,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 149,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 150,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 151,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 152,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 153,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 154,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 155,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 156,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 157,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 158,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 159,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 160,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 161,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 162,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 163,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 164,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 165,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 166,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 167,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 168,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 169,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 170,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 171,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 172,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 173,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 174,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 175,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 176,                    /* tDATE  */
  YYSYMBOL_tTIME = 177,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 178,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 179,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 180,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 181,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 182,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 183,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 184,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 185, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 186,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 187, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 188,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 189,                   /* tEVAL2  */
  YYSYMBOL_190_ = 190,                     /* '-'  */
  YYSYMBOL_191_ = 191,                     /* '+'  */
  YYSYMBOL_192_ = 192,                     /* '*'  */
  YYSYMBOL_193_ = 193,                     /* '/'  */
  YYSYMBOL_UMINUS = 194,                   /* UMINUS  */
  YYSYMBOL_195_ = 195,                     /* ';'  */
  YYSYMBOL_196_ = 196,                     /* ','  */
  YYSYMBOL_197_ = 197,                     /* '('  */
  YYSYMBOL_198_ = 198,                     /* ')'  */
  YYSYMBOL_199_ = 199,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 200,                 /* $accept  */
  YYSYMBOL_program_or_expression = 201,    /* program_or_expression  */
  YYSYMBOL_program = 202,                  /* program  */
  YYSYMBOL_statement_list = 203,           /* statement_list  */
  YYSYMBOL_204_1 = 204,                    /* $@1  */
  YYSYMBOL_205_2 = 205,                    /* $@2  */
  YYSYMBOL_assignment = 206,               /* assignment  */
  YYSYMBOL_statement = 207,                /* statement  */
  YYSYMBOL_208_3 = 208,                    /* $@3  */
  YYSYMBOL_209_4 = 209,                    /* $@4  */
  YYSYMBOL_210_5 = 210,                    /* $@5  */
  YYSYMBOL_211_6 = 211,                    /* $@6  */
  YYSYMBOL_212_7 = 212,                    /* $@7  */
  YYSYMBOL_213_8 = 213,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 214,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 215,        /* string_assignment  */
  YYSYMBOL_to = 216,                       /* to  */
  YYSYMBOL_open_clause = 217,              /* open_clause  */
  YYSYMBOL_seek_clause = 218,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 219,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 220,        /* string_expression  */
  YYSYMBOL_string_function = 221,          /* string_function  */
  YYSYMBOL_number_assignment = 222,        /* number_assignment  */
  YYSYMBOL_expression = 223,               /* expression  */
  YYSYMBOL_224_9 = 224,                    /* $@9  */
  YYSYMBOL_225_10 = 225,                   /* $@10  */
  YYSYMBOL_arrayref = 226,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 227,          /* string_arrayref  */
  YYSYMBOL_coordinates = 228,              /* coordinates  */
  YYSYMBOL_function = 229,                 /* function  */
  YYSYMBOL_const = 230,                    /* const  */
  YYSYMBOL_number = 231,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 232,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 233,                  /* dimlist  */
  YYSYMBOL_function_or_array = 234,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 235,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 236,                /* call_list  */
  YYSYMBOL_237_11 = 237,                   /* $@11  */
  YYSYMBOL_calls = 238,                    /* calls  */
  YYSYMBOL_call_item = 239,                /* call_item  */
  YYSYMBOL_function_definition = 240,      /* function_definition  */
  YYSYMBOL_241_12 = 241,                   /* $@12  */
  YYSYMBOL_242_13 = 242,                   /* $@13  */
  YYSYMBOL_243_14 = 243,                   /* $@14  */
  YYSYMBOL_endsub = 244,                   /* endsub  */
  YYSYMBOL_function_name = 245,            /* function_name  */
  YYSYMBOL_export = 246,                   /* export  */
  YYSYMBOL_local_list = 247,               /* local_list  */
  YYSYMBOL_local_item = 248,               /* local_item  */
  YYSYMBOL_static_list = 249,              /* static_list  */
  YYSYMBOL_static_item = 250,              /* static_item  */
  YYSYMBOL_paramlist = 251,                /* paramlist  */
  YYSYMBOL_paramitem = 252,                /* paramitem  */
  YYSYMBOL_for_loop = 253,                 /* for_loop  */
  YYSYMBOL_254_15 = 254,                   /* $@15  */
  YYSYMBOL_255_16 = 255,                   /* $@16  */
  YYSYMBOL_256_17 = 256,                   /* $@17  */
  YYSYMBOL_257_18 = 257,                   /* $@18  */
  YYSYMBOL_next = 258,                     /* next  */
  YYSYMBOL_step_part = 259,                /* step_part  */
  YYSYMBOL_next_symbol = 260,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 261,  /* switch_number_or_string  */
  YYSYMBOL_262_19 = 262,                   /* $@19  */
  YYSYMBOL_sep_list = 263,                 /* sep_list  */
  YYSYMBOL_number_or_string = 264,         /* number_or_string  */
  YYSYMBOL_case_list = 265,                /* case_list  */
  YYSYMBOL_266_20 = 266,                   /* $@20  */
  YYSYMBOL_default = 267,                  /* default  */
  YYSYMBOL_268_21 = 268,                   /* $@21  */
  YYSYMBOL_do_loop = 269,                  /* do_loop  */
  YYSYMBOL_270_22 = 270,                   /* $@22  */
  YYSYMBOL_loop = 271,                     /* loop  */
  YYSYMBOL_while_loop = 272,               /* while_loop  */
  YYSYMBOL_273_23 = 273,                   /* $@23  */
  YYSYMBOL_274_24 = 274,                   /* $@24  */
  YYSYMBOL_wend = 275,                     /* wend  */
  YYSYMBOL_repeat_loop = 276,              /* repeat_loop  */
  YYSYMBOL_277_25 = 277,                   /* $@25  */
  YYSYMBOL_until = 278,                    /* until  */
  YYSYMBOL_if_clause = 279,                /* if_clause  */
  YYSYMBOL_280_26 = 280,                   /* $@26  */
  YYSYMBOL_281_27 = 281,                   /* $@27  */
  YYSYMBOL_282_28 = 282,                   /* $@28  */
  YYSYMBOL_283_29 = 283,                   /* $@29  */
  YYSYMBOL_endif = 284,                    /* endif  */
  YYSYMBOL_short_if = 285,                 /* short_if  */
  YYSYMBOL_286_30 = 286,                   /* $@30  */
  YYSYMBOL_end_of_if = 287,                /* end_of_if  */
  YYSYMBOL_else_part = 288,                /* else_part  */
  YYSYMBOL_elsif_part = 289,               /* elsif_part  */
  YYSYMBOL_290_31 = 290,                   /* $@31  */
  YYSYMBOL_291_32 = 291,                   /* $@32  */
  YYSYMBOL_maybe_then = 292,               /* maybe_then  */
  YYSYMBOL_inputlist = 293,                /* inputlist  */
  YYSYMBOL_294_33 = 294,                   /* $@33  */
  YYSYMBOL_input = 295,                    /* input  */
  YYSYMBOL_readlist = 296,                 /* readlist  */
  YYSYMBOL_readitem = 297,                 /* readitem  */
  YYSYMBOL_datalist = 298,                 /* datalist  */
  YYSYMBOL_printlist = 299,                /* printlist  */
  YYSYMBOL_using = 300,                    /* using  */
  YYSYMBOL_inputbody = 301,                /* inputbody  */
  YYSYMBOL_302_34 = 302,                   /* $@34  */
  YYSYMBOL_303_35 = 303,                   /* $@35  */
  YYSYMBOL_304_36 = 304,                   /* $@36  */
  YYSYMBOL_305_37 = 305,                   /* $@37  */
  YYSYMBOL_306_38 = 306,                   /* $@38  */
  YYSYMBOL_307_39 = 307,                   /* $@39  */
  YYSYMBOL_308_40 = 308,                   /* $@40  */
  YYSYMBOL_309_41 = 309,                   /* $@41  */
  YYSYMBOL_310_42 = 310,                   /* $@42  */
  YYSYMBOL_311_43 = 311,                   /* $@43  */
  YYSYMBOL_312_44 = 312,                   /* $@44  */
  YYSYMBOL_313_45 = 313,                   /* $@45  */
  YYSYMBOL_314_46 = 314,                   /* $@46  */
  YYSYMBOL_prompt = 315,                   /* prompt  */
  YYSYMBOL_printintro = 316,               /* printintro  */
  YYSYMBOL_hashed_number = 317,            /* hashed_number  */
  YYSYMBOL_goto_list = 318,                /* goto_list  */
  YYSYMBOL_gosub_list = 319                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



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

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  194
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6540

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  200
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  497
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   445


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   199,     2,     2,     2,     2,
     197,   198,   192,   191,   196,   190,     2,   193,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   195,
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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   194
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   191,   191,   192,   193,   194,   195,   198,   201,   202,
     202,   202,   205,   206,   207,   208,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   226,   227,   227,   228,   229,   230,   231,   232,
     233,   234,   234,   236,   236,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   248,   249,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   266,   267,
     268,   269,   270,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   321,   322,
     323,   324,   325,   329,   330,   331,   332,   333,   334,   337,
     338,   341,   342,   343,   344,   345,   348,   349,   352,   353,
     356,   357,   358,   359,   360,   361,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   409,
     410,   413,   413,   414,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   449,   452,   455,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   531,   532,   533,   536,   537,   538,   539,   542,   543,
     546,   547,   548,   549,   552,   555,   558,   558,   561,   562,
     563,   566,   567,   570,   571,   574,   570,   579,   580,   583,
     584,   587,   588,   589,   590,   593,   594,   597,   598,   599,
     600,   603,   604,   607,   608,   609,   610,   613,   614,   615,
     618,   619,   620,   621,   624,   625,   630,   645,   624,   650,
     651,   652,   653,   654,   655,   658,   659,   662,   663,   668,
     668,   672,   673,   676,   677,   681,   683,   682,   687,   688,
     688,   692,   692,   698,   699,   700,   701,   702,   703,   707,
     708,   707,   714,   715,   719,   719,   724,   725,   726,   727,
     728,   729,   732,   733,   733,   735,   732,   739,   740,   741,
     742,   743,   744,   747,   747,   752,   753,   756,   757,   760,
     762,   764,   761,   768,   769,   772,   773,   773,   776,   777,
     779,   780,   784,   785,   788,   789,   791,   792,   796,   797,
     798,   799,   802,   803,   804,   805,   806,   809,   810,   811,
     814,   814,   815,   815,   816,   816,   817,   817,   818,   818,
     819,   819,   820,   820,   821,   821,   822,   822,   823,   823,
     824,   824,   825,   825,   826,   826,   829,   830,   833,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   849,   850,   852,   853,   856,   857
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tFNUM", "tSYMBOL",
  "tSTRSYM", "tDOCU", "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING",
  "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL",
  "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB",
  "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2",
  "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE",
  "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP",
  "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF",
  "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT",
  "tBITNOT", "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tEQU2", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN",
  "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN",
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR",
  "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW",
  "tCURVE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL",
  "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT",
  "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX",
  "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB",
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tREPLACE",
  "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2",
  "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
  "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET",
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE",
  "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tSTART_PROGRAM", "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION",
  "tSTART_ASSIGNMENT", "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'",
  "$accept", "program_or_expression", "program", "statement_list", "$@1",
  "$@2", "assignment", "statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@9", "$@10",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@11", "calls", "call_item",
  "function_definition", "$@12", "$@13", "$@14", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@19",
  "sep_list", "number_or_string", "case_list", "$@20", "default", "$@21",
  "do_loop", "$@22", "loop", "while_loop", "$@23", "$@24", "wend",
  "repeat_loop", "$@25", "until", "if_clause", "$@26", "$@27", "$@28",
  "$@29", "endif", "short_if", "$@30", "end_of_if", "else_part",
  "elsif_part", "$@31", "$@32", "maybe_then", "inputlist", "$@33", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "prompt", "printintro", "hashed_number",
  "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-785)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-403)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -54,  4133,  3465,  3876,    12,    -7,    37,   -37,   -21,  -785,
    -785,  -785,  -785,  -785,   184,   184,   184,  3083,  -785,  -785,
    -785,  3876,  -785,  -785,  3876,    36,    90,  -785,  -785,  -785,
    3465,   -13,  -785,  3465,   358,  -785,  3465,  3465,  3465,   373,
      15,   184,  1612,  1236,  2107,    20,  3465,  2892,  3465,   -16,
      68,  3465,  -785,   143,  3876,  3876,  3876,    93,    18,    35,
      50,    96,   145,  2107,  3876,  3876,  3876,  -785,   156,  -785,
    -785,     1,  -785,  -785,  -785,  -785,   114,   161,  -785,   283,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   151,   209,
    -785,  -785,  -785,  -785,   213,   215,   233,   249,  3465,   255,
     268,   284,   300,   315,   319,   321,   325,   349,   367,   417,
     439,   445,   462,   484,   527,   530,   541,   572,   574,   582,
     592,   595,   600,   616,   618,   622,   629,   638,   645,   647,
     664,   665,   671,   672,   675,   677,   681,   684,   685,   693,
     694,   695,   698,   702,   703,   704,   705,   706,   707,   712,
     713,   714,   715,   718,   719,   720,   721,   722,   723,   724,
     727,   732,   733,   736,   737,   738,   740,   741,   742,   745,
     747,   754,   755,   759,   760,   761,   762,   763,   764,  3465,
    3465,   676,  -785,   403,  -785,  -785,  -785,  -785,  3876,   -30,
     174,   114,   161,   287,  -785,  3465,  -785,  3876,  -785,   649,
    3465,  1443,  -785,  -785,  -785,  -785,  -785,   433,    95,   494,
     540,   520,  -785,  3465,  -785,   520,  -785,  -785,  3465,  1443,
     456,   766,   815,   774,     2,  3465,    -3,   676,  1515,   775,
     786,   546,  1515,   676,  5543,   676,  5569,   788,   789,   758,
    -785,  -785,   767,   767,  -785,  -785,   769,  -785,  3465,  3876,
    3465,    28,  1515,   778,  -785,  -785,  -785,  -785,   791,  3876,
    5605,  -785,  3465,  -785,    17,   792,  -785,  -785,  3465,  3274,
    -785,  -785,  1515,  -785,  -785,   520,    21,    21,  -785,   918,
     918,   918,  2304,  3876,   464,   793,   520,   -17,    39,  -785,
     889,  3465,  3465,  3465,  3465,  3876,  -785,  -785,  -785,  3465,
    3465,   479,  3465,  3465,  3465,  3465,  1910,  2107,   558,   558,
    3465,  3465,  3465,  3465,  3465,  3465,  3465,  3465,  3465,  3465,
    3465,  3465,  2107,  3465,  3465,  3465,  3465,  3465,  3465,  3465,
    3465,  2500,  3876,  3876,  3876,  3876,  3876,  3465,  3465,  3465,
    2696,  3465,  3876,  3465,  3876,  3465,  3876,  3876,  1988,  2185,
    3543,  3647,  3876,  3876,  3876,  3465,  3876,  3876,  3876,  3876,
    3876,  3876,  2107,  3876,  -785,  -785,  3876,  3465,  3876,  3876,
    3876,  3876,  3876,   794,   796,  3876,   918,  3876,   918,  3876,
    3876,  3876,   887,    11,  2323,  3876,  3876,  3876,  3876,  3876,
    3876,  3876,  3876,  -785,  -785,  -785,  3465,  3465,  3465,  3465,
    3465,  3465,  3465,  3465,  3465,  3465,  3465,  3465,  -119,  -785,
    -785,  -785,  1515,   798,   520,   799,   916,  1515,   250,  -785,
    -785,  -785,  -785,   801,   803,   811,  -785,   813,   814,   816,
    -785,   676,  1515,   817,  -785,   676,  1515,   950,   393,   949,
    1443,  3465,   819,  3876,  -785,  -785,  3465,   676,   510,   444,
     820,   951,   821,     4,  -785,   998,  -785,  -785,   726,  3465,
    3465,  -785,  -785,   373,  -785,  -785,    43,  5624,   520,  1515,
     668,  3725,  3465,   520,  3465,  -785,    -3,  -785,  -785,  3465,
    3876,  -785,  3465,    17,  3465,  3465,   822,   824,   825,   827,
    -785,  2519,  -103,  3465,  3465,  3465,  3465,  -785,   828,    17,
      17,  1515,   520,   783,   829,   831,  5639,  5654,  2715,  5674,
    5700,  5715,   833,   435,   830,   835,   837,   838,   840,   843,
     836,   844,    17,  5736,  2907,  3098,  3289,  4006,  4214,   603,
    4289,   757,  4345,  4366,   845,  4400,  4420,  4435,  4450,  4476,
    4497,  4512,  5785,  -785,  4531,   -85,    53,    67,    71,   -84,
    5805,  5846,   414,   777,  -785,  4581,  4607,    23,  4643,   -34,
    4662,    54,    92,  -785,    98,  -785,   153,  -785,   223,  -785,
     225,   235,   237,   238,  5867,    82,   154,   185,   263,   265,
     273,   545,   846,    -4,   848,   849,   305,  4677,   323,    -1,
     236,   264,   304,  -785,  -785,   407,  -107,   543,    63,   562,
     326,   401,  -785,  -785,   520,   520,   520,   520,   520,   520,
     520,  -785,  3465,  3465,   905,   502,   812,   514,   575,    -8,
     164,  -785,   -12,   -12,   887,   887,  -785,  -785,  -785,  1443,
    -785,  -785,  3465,  -785,  -785,  -785,  -785,   184,   184,  -785,
    -785,   494,  -785,  -785,   540,  3465,  -785,   971,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,   768,  5882,  3465,    29,
    4692,  3954,  -785,  -785,  3465,  3465,   851,  3876,  -785,  -785,
    3465,  -785,   818,   853,   854,   852,   856,  5897,  5916,   858,
     859,  -785,  -785,  -785,  3465,   957,   969,  -785,   566,  5936,
    1515,  -785,  -785,   586,  -785,  3465,  5951,  5977,  -785,  3465,
    3465,  3465,  -785,  -785,   676,  1515,   676,  1515,  6028,  6047,
    1443,  3465,  3465,  3465,  -785,  -785,  -785,  -785,  -785,  3465,
    3465,  -785,  3465,  3465,  3465,  -785,  3876,  -785,  3803,  -785,
     860,   861,  -785,  -785,  3465,  3465,  3465,  3465,  -785,  -785,
    -785,  -785,  -785,  3465,  -785,  -785,  3465,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  3465,  -785,
    -785,  3465,  3465,  3465,  -785,  3465,  3465,  -785,  3876,  -785,
    -785,  -785,  -785,  -785,  3465,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  3876,  3876,  3876,  3876,
    -785,  -785,  -785,  -785,  -785,  3876,  -785,  -785,  -785,  -785,
    -785,  -785,  3465,  -785,  3465,  3465,  3465,  1056,  3876,  -785,
    1056,  3876,  -785,  3876,  -785,  -785,   479,   735,  3465,    16,
    1515,  -785,   866,  -785,   867,   868,   872,  -785,   873,   874,
    -785,  -785,  -785,   785,  1443,  -785,  -785,  -785,  3465,  6082,
    3876,  1006,  -785,  3876,   520,   676,   510,  6108,  3465,    33,
     818,   818,  4712,   876,   880,  -785,   882,  -785,  -785,  -785,
    -785,  3465,  3465,  -785,  -785,  6123,  2107,  2107,  3876,  3876,
    3876,  -785,  3465,  3465,   881,  4738,  4753,  1366,  3876,  3876,
    -785,  1515,    17,  -785,   883,  4774,  4823,  4843,  4884,  4905,
     406,   884,    83,  -785,  -785,  4920,  4935,   885,    64,  4954,
    4974,  4989,  5015,  5066,  1754,  5085,  5120,   168,  5146,   409,
     587,   176,   177,   410,  5161,  6138,  6159,  5176,   110,   411,
     134,   415,   431,    47,  -785,  -785,  -785,   184,   184,  -785,
    -785,  -785,  -785,  3465,  1038,  1046,  1042,  5197,  3465,   436,
     890,   189,  -785,  3465,  6178,  3876,  1028,  -785,  -785,  -785,
    -785,  -785,  -785,   891,   892,  1515,  1515,  3876,  -785,  -785,
     520,   520,   589,  6193,  1515,  -785,  1013,  1017,  3465,  1018,
     590,   520,  3465,   834,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  3876,  -785,  -785,  -785,  -785,  3465,  -785,  -785,  -785,
    -785,  -785,  3465,  -785,  -785,  -785,  3876,  -785,  -785,  -785,
    3876,  3465,  -785,  3465,  -785,  -785,  -785,  3876,  3465,  -785,
    3876,  -785,  -785,  3876,  -785,  -785,  -785,  3465,  -785,  -785,
    -785,  -785,  -785,  1051,   795,  5216,  1044,  3465,  3876,  5231,
    3465,   437,   903,   998,   818,   907,   908,   818,  -785,  -785,
     520,  3876,  3876,  3876,  3876,  5251,  3876,  3465,  -785,   906,
     910,   194,  -785,   446,  6213,  5307,   463,   466,  5328,  5362,
     467,  5382,   492,   493,    79,  1443,  4294,  3465,  1061,  -785,
     912,  -785,   913,  6269,   498,   797,  5397,  1053,  3465,   818,
    -785,  -785,  -785,  -785,   520,   520,   520,   520,  1040,   520,
    1515,   919,   920,   834,  -785,  -785,  3465,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  3465,  -785,  1042,  1078,
     495,  1443,  -785,  3876,  3465,  3465,  -785,  -785,   922,   998,
    -785,   924,   998,  6290,  -785,  3876,  -785,  -785,  -785,  1443,
    5412,  1515,  1443,  -785,  -785,  1042,   404,   195,  6324,  5438,
     998,  3876,   818,   998,  3465,   818,  3465,   520,    19,  -785,
    1042,  1443,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  3876,
    -785,  3465,  -785,   818,   217,  -785,   818,  6344,  -785,  5459,
    -785,  -785,  -785,   696,  1042,   517,  5474,  -785,  3876,  -785,
    -785,  3465,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  1118,
    1051,  -785,  -785,   525,   998,  5493,   998,  -785,  -785,  -785,
    -785,   818,  -785,   818,   998,  -785,   998,  -785,   818,   818,
    -785,  -785
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   118,     0,     0,     0,   331,     0,     0,     0,   112,
     354,   389,   394,    18,     0,     0,     0,     0,    31,    33,
     332,     0,   316,   316,     0,   333,    25,    27,   369,   381,
       0,   478,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     2,     9,    17,
       8,     0,    12,    46,    48,    14,    29,    30,    28,     0,
      20,    21,    24,    23,    22,    35,    36,   304,   211,   140,
     305,   306,   307,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,   271,   274,   277,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,   225,   205,   210,   142,     0,     0,
       0,     0,     0,     0,     1,     0,   316,     0,   316,     0,
       0,    16,   309,   308,    37,    38,    45,     0,     0,     0,
       0,    19,    50,   318,    51,    49,   334,    26,     0,    16,
     413,     0,   482,     0,     0,   442,   474,    69,    68,     0,
       0,    70,   111,    60,     0,    62,     0,   434,   436,    63,
     432,   438,     0,     0,   439,   301,    64,    66,     0,    96,
       0,     0,   493,     0,    93,    98,    86,    47,     0,     0,
       0,    74,     0,    57,    79,     0,    95,    94,     0,     0,
     121,   122,    99,    13,    15,   113,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     7,
       0,     0,     0,     0,     0,     0,   323,   316,   316,     0,
       0,   195,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   316,   316,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   193,   191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   189,     0,   123,     0,     0,   390,     9,    39,
      40,    41,    43,   337,   338,    32,   335,   343,   344,    34,
     341,   321,   322,   317,   319,   374,   373,     0,     9,     0,
      16,     0,     0,     0,   479,   480,     0,   445,   447,    52,
       0,     0,     0,     0,    56,   476,   316,   316,     0,     0,
       0,   316,   316,     0,   303,   302,     0,     0,    97,   492,
       0,     0,     0,    73,     0,    78,   474,   130,   129,     0,
       0,    75,     0,    81,     0,     0,   138,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,   190,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,   275,     0,   278,     0,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,   174,     0,     0,     0,     0,     0,
       0,     0,   145,   226,   220,   222,   224,   221,   223,   218,
     219,   144,     0,     0,   198,   200,   202,   199,   201,   196,
     197,   216,   213,   212,   214,   215,   314,   315,   355,    16,
     401,   399,     0,   400,   396,   398,   395,     0,     0,   316,
     316,     0,   316,   316,     0,     0,   371,   375,   388,   386,
     387,   384,   383,   385,   382,   403,     9,     0,     0,     0,
       0,     0,   443,    53,    54,     0,     0,     0,   450,   452,
       0,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   433,   440,   441,     0,     0,     0,   133,   132,   136,
     229,    58,    76,    89,    80,     0,     0,     0,   316,     0,
       0,     0,   103,   104,   105,   106,   107,   108,     0,     0,
      16,     0,     0,     0,   329,   330,   324,   293,   185,     0,
       0,   284,     0,     0,     0,   294,     0,   295,     0,   288,
       0,     0,   206,   207,     0,     0,     0,     0,   230,   231,
     232,   233,   234,     0,   235,   237,     0,   238,   240,   241,
     203,   247,   248,   242,   244,   245,   246,   243,     0,   250,
     255,     0,     0,     0,   254,     0,     0,   153,     0,   150,
     156,   157,   256,   183,     0,   257,   184,   158,   159,   270,
     273,   276,   279,   162,   160,   161,     0,     0,     0,     0,
     165,   263,   166,   269,   268,     0,   175,   264,   167,   265,
     168,   267,     0,   169,     0,     0,     0,     0,     0,   178,
       0,     0,   180,     0,   300,   188,   194,   192,     0,     9,
     397,   494,    42,   496,    44,     0,     0,   336,     0,     0,
     342,   320,   372,   378,    16,   415,   416,   414,     0,     0,
       0,   483,   481,     0,   448,   446,   447,     0,     0,     0,
       0,     0,     0,   428,   430,   475,   425,   310,   312,   316,
     316,     0,     0,   435,   437,    71,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    87,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   393,   392,   391,     0,     0,   339,
     340,   345,   346,     0,     0,     0,   404,     0,     0,     0,
       0,     0,   444,     0,     0,     0,   464,   451,   453,   454,
     316,   316,   426,     0,     0,    59,    61,     0,   134,   135,
     131,   137,    90,    83,    84,   139,     0,     0,     0,     0,
     116,   117,     0,   347,   282,   283,   285,   286,   287,   296,
     297,     0,   298,   208,   209,   181,     0,   236,   239,   249,
     146,   147,     0,   149,   252,   253,     0,   151,   258,   163,
       0,     0,   259,     0,   261,   176,   170,     0,     0,   187,
       0,   290,   177,     0,   292,   179,   204,     0,   495,   497,
     376,   379,   370,   419,   485,     0,   484,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,   311,   313,
      72,     0,     0,     0,     0,     0,     0,     0,    88,   350,
     351,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,    16,   118,     0,   417,   489,
       0,   486,     0,     0,     0,   456,     0,   466,     0,     0,
     455,   429,   431,   427,    91,    82,   126,   127,     0,   125,
     115,     0,     0,     0,   325,   299,     0,   148,   152,   164,
     260,   262,   266,   186,   289,   291,     0,   356,   377,     9,
     423,    16,   405,     0,     0,     0,   449,   468,     0,   476,
     458,     0,   476,     0,   465,     0,   352,   353,   349,    16,
       0,   366,    16,   424,   420,   418,     0,     0,     0,     0,
     476,     0,     0,   476,     0,     0,     0,   124,     9,   182,
     357,    16,   412,   409,   410,   411,   407,   408,   406,     0,
     490,     0,   487,     0,     0,   457,     0,     0,   467,     0,
     328,   327,   326,     0,   421,     0,     0,   469,     0,   470,
     459,     0,   460,   360,   362,   363,   364,   359,   361,   367,
     419,   491,   488,     0,   476,     0,   476,   368,   358,   422,
     472,     0,   462,     0,   476,   471,   476,   461,     0,     0,
     473,   463
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -785,  -785,  -785,  -189,  -785,  -785,  1119,   416,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  1071,  -257,  -785,  -785,  -203,
     842,  -785,  1074,    -2,  -785,  -785,   841,  -306,    78,  -785,
     662,   -35,   -14,  -785,     3,     9,    86,  -785,  -785,   485,
    1124,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   490,  -785,
     489,  -785,    41,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,   203,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   -51,
    -785,  -785,  -785,  -784,  -785,  -785,  -785,   680,  -785,  -785,
     294,   669,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -681,  -785,    27,  -785,  -785
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    67,    68,   290,   710,    69,    70,   209,   210,
     637,   638,   226,   476,    71,    72,   479,    73,    74,   487,
     181,   182,    75,   260,   613,   612,   518,   519,   261,   184,
     244,   185,   204,   231,   186,   187,   212,   213,   433,   434,
      78,   503,   884,  1129,  1172,   716,    79,   425,   426,   429,
     430,  1051,  1052,    80,   199,   818,  1132,  1173,  1189,  1107,
    1198,    81,   218,   647,   437,   833,  1065,   935,  1066,    82,
     219,   654,    83,   200,   629,   926,    84,   201,   636,    85,
     439,   834,  1023,  1136,  1158,    86,   440,   837,  1112,  1068,
    1151,  1190,  1134,   855,  1037,   856,   239,   240,   246,   449,
     662,   454,   850,   851,  1034,  1119,  1143,  1196,  1206,  1033,
    1122,  1140,  1194,  1204,   455,   672,   225,   253,   822,   824
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     183,   205,   206,   521,    76,   245,   444,   191,   668,   445,
      77,   669,   418,   192,   409,   208,     7,     8,    87,   484,
     485,    20,    90,    91,    92,   241,    25,   247,   220,   477,
     438,   228,   924,   477,   232,   234,   236,   194,   195,   470,
     252,   252,   252,   266,  1170,   221,    87,   222,   223,   272,
      90,    91,    92,   682,   197,   450,   191,   451,   452,  1017,
     925,   252,   192,  1171,   216,   403,   947,   948,   402,   403,
     257,   258,   392,   267,   268,   269,   477,   488,   489,   602,
     270,   385,   386,   387,   388,   389,   390,   391,   392,   808,
     285,   809,  1106,   291,   292,   703,   301,   217,   385,   386,
     387,   388,   389,   390,   391,   293,   392,   392,   259,   214,
     394,   395,    53,   760,   764,   421,   422,   396,   397,   398,
     399,   400,   401,   402,   403,   264,   265,   394,   395,     1,
       2,     3,     4,     5,   396,   397,   398,   399,   400,   401,
     402,   403,   394,   395,    58,    59,    60,     7,     8,   396,
     397,   398,   399,   400,   401,   402,   403,   392,   394,   395,
     196,   392,   774,   271,   775,   396,   397,   398,   399,   400,
     401,   402,   403,   596,   392,   598,   198,   382,   384,   495,
     406,   407,   404,   405,   406,   407,   224,   392,   202,   294,
     392,   203,   795,   412,   796,   802,   453,   803,   417,   446,
     289,   670,   392,   278,    76,   242,   243,   464,   465,   602,
      77,   432,   392,   478,   392,   279,   436,   478,   410,   392,
     392,   772,    76,   448,   392,   840,   695,   841,    77,   945,
     392,   946,   280,   242,   243,   496,   295,   404,   405,   406,
     407,   403,   712,   713,   392,   392,   467,   281,   469,   761,
    1080,   656,   777,  1083,   404,   405,   406,   407,   392,   811,
     478,   812,   392,   762,   630,   736,   631,   763,   632,   404,
     405,   406,   407,   392,   392,    58,    59,    60,   787,   981,
     491,   982,   413,   392,   415,   404,   405,   406,   407,   392,
     778,   633,   501,   282,   634,  1124,   779,   506,   507,   635,
     508,   509,   510,   511,   252,   252,  1010,   296,  1011,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     252,   535,   536,   537,   538,   539,   540,   541,   542,   544,
    1013,   411,  1014,   514,   515,   550,   551,   553,   555,   556,
     475,   558,   283,   560,   392,   392,   481,   483,   196,   534,
     788,   780,  1079,   574,   404,   405,   406,   407,  1165,   392,
     252,  1168,   229,   230,   996,   587,   997,   392,   392,   498,
     499,   500,  1001,  1003,  1002,  1004,   392,   237,   238,  1177,
     392,   789,  1180,   504,   505,  1028,   392,   602,   522,   582,
    1093,  1159,  1094,  1160,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   198,   648,   392,   649,
     297,   650,   298,  1178,   392,  1179,   392,  1205,  1152,  1207,
    1153,   781,  1154,   782,  1210,  1211,   392,   392,   392,   392,
     299,   245,   804,   783,   651,   784,   785,   652,  1142,   657,
     819,  1145,   653,    76,   660,  1155,   300,   393,  1156,    77,
     584,   585,   302,  1157,   392,   392,   392,   677,   678,  1163,
     805,   790,  1166,   791,   392,   303,   394,   395,   419,   420,
     689,   792,   690,   396,   397,   398,   399,   400,   401,   402,
     403,   304,   696,   697,   385,   386,   387,   388,   389,   390,
     391,   705,   707,   708,   709,   392,   392,   305,   423,   424,
     806,   918,  -402,   799,   920,   385,   386,   387,   388,   389,
     390,   391,   306,  1201,   392,  1203,   307,   392,   308,   394,
     395,   801,   309,  1208,   814,  1209,   396,   397,   398,   399,
     400,   401,   402,   403,   385,   386,   387,   388,   389,   390,
     391,  1133,   673,   674,   427,   428,   310,   679,   680,   396,
     397,   398,   399,   400,   401,   402,   403,   692,   394,   395,
     694,   661,   516,   517,   311,   396,   397,   398,   399,   400,
     401,   402,   403,   394,   395,   399,   400,   401,   402,   403,
     396,   397,   398,   399,   400,   401,   402,   403,   400,   401,
     402,   403,   392,   404,   405,   406,   407,   392,   392,   815,
     392,   392,   392,   807,   979,   392,   392,   999,  1005,  1012,
     816,   817,   767,  1015,   312,   385,   386,   387,   388,   389,
     390,   391,   392,   821,   823,   972,   392,   392,   392,  1016,
     820,   726,    76,   727,  1026,  1077,   313,   392,    77,   663,
     664,   986,   314,   432,  1095,   936,   404,   405,   406,   407,
     401,   402,   403,   416,   392,   392,   839,   392,   392,   315,
     493,  1098,   846,   847,  1099,  1102,   394,   395,   852,   404,
     405,   406,   407,   396,   397,   398,   399,   400,   401,   402,
     403,   316,   865,   392,   392,   404,   405,   406,   407,   392,
    1104,  1105,   404,   405,   406,   407,  1116,   875,   876,   877,
     404,   405,   406,   407,   404,   405,   406,   407,   392,   881,
    1183,   392,  1184,    76,  1185,  1191,   392,   885,   886,    77,
     887,   888,   889,  1200,   317,   825,   826,   318,   828,   829,
     675,   676,   895,   896,   392,   898,   392,  1186,   319,   810,
    1187,   899,   458,   793,   900,  1188,   385,   386,   387,   388,
     389,   390,   391,   392,   685,   686,   901,   392,   813,   902,
     903,   904,   868,   905,   906,   404,   405,   406,   407,   320,
      87,   321,   908,   871,    90,    91,    92,   392,   392,   322,
     392,   392,   870,  1000,   874,  1041,  1047,   714,   715,   323,
     882,   883,   324,   404,   405,   406,   407,   325,   394,   743,
     914,   744,   915,   916,   917,   396,   397,   398,   399,   400,
     401,   402,   403,   326,   897,   327,   923,   835,   836,   328,
     394,   395,   853,   854,   933,   934,   329,   396,   397,   398,
     399,   400,   401,   402,   403,   330,   937,    76,  1049,  1050,
     394,   395,   331,    77,   332,   189,   944,   396,   397,   398,
     399,   400,   401,   402,   403,  1069,  1070,  1117,  1118,   955,
     956,   333,   334,   211,   252,   252,   215,   392,   335,   336,
     963,   964,   337,   442,   338,   227,  1108,  1109,   339,   233,
     235,   340,   341,   397,   251,   399,   400,   401,   402,   403,
     342,   343,   344,   958,   959,   345,   275,   276,   277,   346,
     347,   348,   349,   350,   351,   284,   286,   287,   288,   352,
     353,   354,   355,  1018,  1019,   356,   357,   358,   359,   360,
     361,   362,  1135,   486,   363,   404,   405,   406,   407,   364,
     365,   436,   497,   366,   367,   368,  1025,   369,   370,   371,
    1148,  1029,   372,  1150,   373,   953,   954,   404,   405,   406,
     407,   374,   375,   746,   463,   747,   376,   377,   378,   379,
     380,   381,  1174,   441,   403,   466,  1045,   404,   405,   406,
     407,   443,   456,   768,   471,   769,   397,   398,   399,   400,
     401,   402,   403,   457,  1054,   461,   462,   472,   480,   494,
    1055,   628,   593,   646,   594,   655,   626,   627,   639,  1058,
     640,  1059,   404,   405,   406,   407,  1061,   641,   671,   666,
     642,   643,   644,   645,   832,  1064,   658,   665,   667,   698,
     699,   700,   383,   701,   711,  1073,   728,   717,  1076,   718,
     408,   725,   734,   729,   730,   731,  1035,  1036,   732,   414,
     735,   733,   866,   750,   794,  1090,   797,   798,   848,   859,
    1048,   857,   858,   860,   867,   431,   863,   864,   893,   894,
     435,   517,   927,   928,   940,  1110,   929,   447,    76,    76,
     930,   931,   932,   950,    77,    77,  1123,   951,   952,   965,
     973,  1021,   980,   985,  1022,    -9,  1032,  1027,  1043,  1038,
    1039,   468,  1044,  1046,  1130,   404,   405,   406,   407,  1067,
    1078,   473,  1072,  1091,  1131,  1081,  1082,  1092,  1111,  1113,
    1114,  1121,  1138,  1139,    76,  1125,  -380,  1126,  1127,  1141,
      77,  1144,  1197,   190,   273,   492,   880,   274,   683,   193,
     831,   827,    76,   830,  1128,    76,  1020,   502,    77,  1199,
     942,    77,  1167,   681,  1169,   691,     0,     0,   513,     0,
     520,     0,     0,     0,    76,     0,     0,     0,     0,  1176,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   546,   547,   548,   549,  1195,
       0,   552,     0,     0,   557,     0,   559,     0,   561,   562,
     564,   566,   568,   570,   571,   572,   573,     0,   575,   576,
     577,   578,   579,   580,   581,   583,     0,     0,   586,     0,
     588,   589,   590,   591,   592,     0,     0,   595,     0,   597,
       0,   599,   600,   601,     0,     0,     0,   604,   605,   606,
     607,   608,   609,   610,   611,     0,     0,     0,     0,    87,
      88,    89,     0,    90,    91,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,   688,     0,     0,     0,   103,     0,     0,
     104,     0,   693,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,   255,     0,   704,   706,   105,   106,     0,
       0,   107,     0,   108,     0,     0,   256,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
     161,   162,   163,   164,     0,   165,   166,     0,   167,   168,
     169,     0,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,     0,     0,   177,   178,   179,     0,     0,   394,
     395,     0,     0,   180,     0,   250,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,    10,     0,     0,     0,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -331,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,     0,   431,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,   844,    37,    38,   845,     0,     0,   849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,  -118,  -118,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,  -118,     0,    55,
       0,    56,    57,     0,     0,     0,   404,   405,   406,   407,
       0,     0,   968,     0,   969,     0,     0,     0,   890,     0,
     892,     0,     0,     0,     0,    58,    59,    60,   394,   395,
       0,     0,    61,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,    63,     0,     0,     0,
     907,    64,     0,     0,    65,    87,    88,    89,    66,    90,
      91,    92,    93,     0,     0,     0,     0,     0,   909,   910,
     911,   912,     0,     0,     0,     0,     0,   913,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
     919,     0,     0,   921,     0,   922,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   939,     0,     0,   941,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,   104,     0,     0,     0,
       0,   248,     0,     0,     0,   404,   405,   406,   407,   249,
     960,   961,   962,   105,   106,     0,     0,   107,     0,   108,
     970,   971,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   435,   161,   162,   163,   164,
       0,   165,   166,     0,   167,   168,   169,  1031,   170,   171,
     172,   173,   174,   175,   176,     0,     0,     0,     0,  1040,
     177,   178,   179,     0,     0,     0,     0,     0,     0,   180,
       0,   250,     0,     0,     0,     0,     0,   394,   395,     0,
       0,     0,     0,  1053,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,     0,     0,     0,  1056,     0,
       0,     0,  1057,     0,     0,     0,     0,     0,     0,  1060,
       0,     0,  1062,     0,     0,  1063,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1074,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1084,  1085,  1086,  1087,     0,  1089,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,     0,    90,    91,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,   404,   405,   406,   407,     0,     0,
     992,     0,   993,     0,     0,  1137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1147,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,  1164,     0,     0,     0,     0,     0,     0,
       0,   103,     0,    89,   104,     0,     0,     0,    93,     0,
       0,  1175,     0,     0,     0,     0,     0,   512,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,     0,    95,
    1193,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,   161,   162,   163,   164,     0,   165,
     166,     0,   167,   168,   169,     0,   170,   171,   172,   173,
     174,   175,   176,   107,     0,   108,     0,     0,   177,   178,
     179,     0,     0,     0,     0,     0,     0,   180,     0,   250,
      87,    88,    89,     0,    90,    91,    92,    93,     0,     0,
     130,   131,   132,     0,     0,     0,   136,   137,   138,     0,
     140,     0,   142,   143,   144,     0,     0,    94,    95,   149,
     150,   151,   152,   153,     0,     0,   156,     0,   158,     0,
     160,     0,     0,   162,     0,   164,     0,     0,   166,     0,
       0,   168,   169,     0,   170,   171,     0,   173,     0,   175,
      96,    97,    98,    99,   100,   101,   102,   178,     0,     0,
       0,     0,     0,     0,     0,   188,   563,     0,   103,     0,
      89,   104,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,     0,   107,     0,   108,     0,    95,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,   161,   162,   163,   164,     0,   165,   166,     0,   167,
     168,   169,     0,   170,   171,   172,   173,   174,   175,   176,
     107,     0,   108,     0,     0,   177,   178,   179,     0,     0,
       0,     0,     0,     0,   180,     0,   250,    87,    88,    89,
       0,    90,    91,    92,    93,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,     0,    94,    95,   149,   150,   151,   152,
     153,     0,     0,   156,     0,   158,     0,   160,     0,     0,
     162,     0,   164,     0,     0,   166,     0,     0,   168,   169,
       0,   170,   171,     0,   173,     0,   175,    96,    97,    98,
      99,   100,   101,   102,   178,     0,     0,     0,     0,     0,
       0,     0,   188,   565,     0,   103,   394,   395,   104,     0,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,     0,   165,   166,     0,   167,   168,   169,     0,
     170,   171,   172,   173,   174,   175,   176,     0,     0,     0,
       0,     0,   177,   178,   179,     0,     0,     0,     0,     0,
       0,   180,   490,    87,    88,    89,     0,    90,    91,    92,
      93,     0,     0,   404,   405,   406,   407,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   394,   395,   104,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,   161,   162,   163,   164,     0,   165,
     166,     0,   167,   168,   169,     0,   170,   171,   172,   173,
     174,   175,   176,     0,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,     0,     0,     0,   180,   543,    87,
      88,    89,     0,    90,    91,    92,    93,     0,     0,   404,
     405,   406,   407,     0,     0,     0,     0,   702,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   394,   395,
     104,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,   105,   106,     0,
       0,   107,     0,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
     161,   162,   163,   164,     0,   165,   166,     0,   167,   168,
     169,     0,   170,   171,   172,   173,   174,   175,   176,     0,
       0,     0,     0,     0,   177,   178,   179,     0,     0,     0,
       0,     0,     0,   180,   554,    87,    88,    89,     0,    90,
      91,    92,    93,     0,   262,   404,   405,   406,   407,     0,
       0,     0,     0,   721,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
     394,   395,     0,   103,     0,     0,   104,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,   107,     0,   108,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,   161,   162,   163,   164,
       0,   165,   166,     0,   167,   168,   169,     0,   170,   171,
     172,   173,   174,   175,   176,     0,     0,     0,     0,     0,
     177,   178,   179,     0,     0,     0,    87,    88,    89,   180,
      90,    91,    92,    93,     0,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,   738,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,   394,   395,     0,   103,     0,     0,   104,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,     0,   107,     0,
     108,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,   161,   162,   163,
     164,     0,   165,   166,     0,   167,   168,   169,     0,   170,
     171,   172,   173,   174,   175,   176,     0,     0,     0,     0,
       0,   177,   178,   179,     0,     0,     0,    87,    88,    89,
     180,    90,    91,    92,    93,     0,   482,     0,   404,   405,
     406,   407,     0,     0,     0,     0,   739,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   394,   395,     0,   103,     0,     0,   104,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,     0,   165,   166,     0,   167,   168,   169,     0,
     170,   171,   172,   173,   174,   175,   176,     0,     0,     0,
       0,     0,   177,   178,   179,     0,     0,     0,    87,    88,
      89,   180,    90,    91,    92,    93,     0,     0,     0,   404,
     405,   406,   407,     0,     0,     0,     0,   740,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,    89,   104,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,    95,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,   161,
     162,   163,   164,     0,   165,   166,     0,   167,   168,   169,
       0,   170,   171,   172,   173,   174,   175,   176,   107,     0,
     108,     0,    89,   177,   178,   179,     0,    93,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,    95,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,   152,   153,     0,
       0,   156,     0,   158,     0,   160,     0,     0,   162,     0,
     164,     0,     0,   166,     0,     0,   168,   169,     0,   170,
     171,     0,   173,     0,   175,     0,     0,     0,     0,     0,
      89,     0,   178,     0,     0,    93,     0,     0,     0,     0,
     188,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,   108,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,     0,   140,
       0,   142,   143,   144,     0,     0,     0,     0,   149,   150,
     151,   152,   153,     0,     0,   156,     0,   158,    89,   160,
       0,     0,   162,    93,   164,     0,     0,   166,     0,     0,
     168,   169,   687,   170,   171,     0,   173,     0,   175,     0,
     107,     0,   108,     0,    95,     0,   178,     0,     0,     0,
       0,     0,     0,     0,   188,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,     0,     0,     0,     0,   149,   150,   151,   152,
     153,    89,     0,   156,     0,   158,    93,   160,     0,     0,
     162,     0,   164,     0,     0,   166,     0,     0,   168,   169,
     891,   170,   171,     0,   173,     0,   175,    95,   107,     0,
     108,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,   152,   153,    89,
       0,   156,     0,   158,    93,   160,     0,     0,   162,     0,
     164,     0,     0,   166,     0,     0,   168,   169,     0,   170,
     171,   107,   173,   108,   175,    95,     0,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,     0,     0,     0,   136,   137,   138,     0,   140,     0,
     142,   143,   144,     0,     0,     0,     0,   149,   150,   151,
     152,   153,     0,     0,   156,     0,   158,     0,   160,     0,
       0,   162,     0,   164,     0,     0,   166,     0,     0,   168,
     169,     0,   170,   171,     0,   173,     0,   175,     0,   107,
       0,   108,     0,     0,     0,   178,     0,     0,     0,   394,
     395,     0,     0,   188,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,   130,   131,   132,     0,
       0,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,   152,   153,
       0,     0,   156,     0,   158,     0,   160,     0,     0,   162,
       0,   164,     0,     0,   166,     0,     0,   168,   169,     0,
     170,   171,     0,   173,     0,   175,     0,     7,     8,     9,
       0,     0,     0,   178,    10,     0,     0,     0,    11,     0,
      12,   843,    13,    14,    15,    16,    17,  -331,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,   -16,   -16,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,   404,   405,   406,   407,
       0,     0,     0,     0,   741,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,     0,     0,    55,
       0,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,     0,     0,
       0,     0,    61,     0,     0,     0,     0,   394,   395,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,    62,     0,     0,     0,    63,     0,     7,     8,
       9,    64,     0,     0,    65,    10,     0,     0,    66,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -331,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,   -16,     0,     0,     0,    29,   -16,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,   394,   395,     0,    37,    38,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,     0,     0,
      55,     0,    56,    57,   404,   405,   406,   407,   394,   395,
       0,     0,   742,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,    58,    59,    60,   394,
     395,     0,     0,    61,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,    63,     0,     0,
       0,     0,    64,   394,   395,    65,     0,     0,     0,    66,
     396,   397,   398,   399,   400,   401,   402,   403,     0,   404,
     405,   406,   407,   394,   395,     0,     0,   745,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,   394,   395,
       0,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   394,   395,     0,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,     0,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   394,
     395,     0,     0,   748,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,   404,   405,   406,   407,
     394,   395,     0,     0,   749,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   394,   395,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   394,   395,     0,     0,   751,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,     0,
     404,   405,   406,   407,     0,     0,     0,     0,   752,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,     0,
       0,     0,     0,   753,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,   394,   395,     0,     0,   754,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
     394,   395,     0,     0,   755,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,   756,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   394,   395,     0,     0,
     757,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   394,   395,     0,     0,   759,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     394,   395,     0,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   394,   395,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
       0,   404,   405,   406,   407,   394,   395,     0,     0,   770,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   394,   395,     0,     0,   771,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   394,   395,     0,     0,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,   404,   405,   406,   407,   394,   395,     0,
       0,   773,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,   800,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   394,   395,     0,     0,
     842,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,   404,   405,   406,   407,   394,   395,     0,     0,
     949,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,     0,     0,     0,     0,   966,     0,     0,     0,
       0,     0,     0,   404,   405,   406,   407,   394,   395,     0,
       0,   967,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,   404,   405,   406,   407,   394,   395,
       0,     0,   974,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   394,   395,     0,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,   394,   395,
       0,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   394,   395,     0,
       0,   975,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,   404,   405,   406,   407,   394,   395,     0,
       0,   976,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   394,   395,     0,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   394,   395,
       0,     0,   977,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,   404,   405,   406,   407,     0,
       0,     0,     0,   978,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,     0,     0,     0,     0,   983,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   394,
     395,     0,     0,   984,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   394,   395,
       0,     0,   987,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,   404,   405,   406,   407,     0,     0,
       0,     0,   988,     0,     0,     0,     0,     0,     0,   404,
     405,   406,   407,   394,   395,     0,     0,   989,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,     0,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   394,
     395,     0,     0,   990,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   394,   395,     0,     0,     0,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,   394,
     395,     0,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,   404,   405,   406,   407,
     394,   395,     0,     0,   991,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   394,
     395,     0,     0,   994,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   394,   395,     0,     0,     0,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,     0,
     404,   405,   406,   407,   394,   395,     0,     0,   995,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
       0,     0,     0,     0,   998,     0,     0,     0,     0,     0,
       0,   404,   405,   406,   407,     0,     0,     0,     0,  1006,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
     394,   395,     0,     0,  1009,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,   404,   405,   406,
     407,   394,   395,     0,     0,  1024,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
       0,     0,     0,     0,  1071,     0,     0,     0,     0,     0,
       0,   404,   405,   406,   407,   394,   395,     0,     0,  1075,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
       0,   404,   405,   406,   407,   394,   395,     0,     0,  1088,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     394,   395,     0,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   394,   395,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   394,   395,     0,     0,  1097,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,   404,   405,
     406,   407,   394,   395,     0,     0,  1100,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,   394,   395,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   394,   395,     0,     0,
    1101,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,   404,   405,   406,   407,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,  1120,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   394,   395,     0,     0,
    1149,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,   394,   395,     0,     0,  1162,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,   404,
     405,   406,   407,     0,     0,     0,     0,  1182,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   394,   395,
       0,     0,  1192,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   394,   395,     0,
       0,  1202,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   394,   395,     0,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,   394,   395,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,   404,   405,   406,   407,   394,   395,   459,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,     0,     0,     0,     0,   404,
     405,   406,   407,   394,   395,   460,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,   394,   395,
       0,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,   404,   405,   406,   407,   394,
     395,   474,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,     0,     0,
     684,     0,     0,     0,     0,     0,     0,     0,     0,   404,
     405,   406,   407,     0,     0,   719,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   394,   395,
     720,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,   404,   405,   406,   407,   394,   395,
     722,     0,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,     0,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,     0,     0,   723,     0,     0,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   394,
     395,   724,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,     0,   404,   405,   406,   407,
     394,   395,   737,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   394,   395,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     394,   395,     0,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   394,
     395,   758,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,     0,   404,   405,   406,   407,   394,
     395,   765,     0,     0,     0,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   394,   395,     0,     0,     0,     0,
       0,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,   407,
     394,   395,   766,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,   404,   405,   406,
     407,     0,     0,   786,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,     0,     0,   838,     0,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   394,   395,   861,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     394,   395,   862,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,     0,   404,   405,   406,   407,
       0,     0,   869,     0,     0,     0,     0,     0,     0,     0,
       0,   404,   405,   406,   407,   394,   395,   872,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
     407,   394,   395,   873,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   394,   395,     0,     0,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,   394,   395,     0,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,     0,     0,   404,   405,
     406,   407,   394,   395,   878,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   394,   395,   879,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   394,   395,     0,     0,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,   404,   405,   406,   407,   394,   395,   938,     0,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,     0,     0,   943,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,   406,   407,     0,     0,   957,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,   394,   395,  1007,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   401,   402,   403,     0,     0,   404,
     405,   406,   407,   394,   395,  1008,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,     0,     0,  1030,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,   406,   407,   394,   395,  1042,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,   404,   405,   406,   407,   394,   395,  1096,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
     405,   406,   407,     0,     0,  1115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     404,   405,   406,   407,     0,     0,  1146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,     0,     0,
    1161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,     0,     0,
    1181
};

static const yytype_int16 yycheck[] =
{
       2,    15,    16,   309,     1,    40,     4,     4,     4,     7,
       1,     7,   201,     4,    44,    17,     4,     5,     3,   276,
     277,    28,     7,     8,     9,    10,    33,    41,    30,    12,
     219,    33,    16,    12,    36,    37,    38,     0,    75,    11,
      42,    43,    44,    59,    25,    58,     3,    60,    61,    51,
       7,     8,     9,    10,    75,    58,    53,    60,    61,    12,
      44,    63,    53,    44,    28,    77,   850,   851,    76,    77,
      43,    44,   191,    89,    90,    91,    12,   280,   281,   198,
      96,    70,    71,    72,    73,    74,    75,    76,   191,   196,
      63,   198,    13,    92,    93,   198,    98,     7,    70,    71,
      72,    73,    74,    75,    76,   104,   191,   191,    88,    23,
      63,    64,   100,   198,   198,    20,    21,    70,    71,    72,
      73,    74,    75,    76,    77,    47,    48,    63,    64,   183,
     184,   185,   186,   187,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,   132,   133,   134,     4,     5,    70,
      71,    72,    73,    74,    75,    76,    77,   191,    63,    64,
     197,   191,   196,    95,   198,    70,    71,    72,    73,    74,
      75,    76,    77,   376,   191,   378,   197,   179,   180,   196,
     192,   193,   190,   191,   192,   193,   199,   191,     4,    75,
     191,     7,   196,   195,   198,   196,   199,   198,   200,   197,
      44,   197,   191,   110,   201,   190,   191,   242,   243,   198,
     201,   213,   191,   196,   191,   197,   218,   196,    44,   191,
     191,   198,   219,   225,   191,   196,   483,   198,   219,   196,
     191,   198,   197,   190,   191,   196,    75,   190,   191,   192,
     193,    77,   499,   500,   191,   191,   248,   197,   250,   196,
    1034,   440,   198,  1037,   190,   191,   192,   193,   191,   196,
     196,   198,   191,   196,    14,   522,    16,   196,    18,   190,
     191,   192,   193,   191,   191,   132,   133,   134,   196,   196,
     282,   198,   196,   191,   198,   190,   191,   192,   193,   191,
     198,    41,   294,   197,    44,  1079,   198,   299,   300,    49,
     302,   303,   304,   305,   306,   307,   196,    24,   198,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     196,    44,   198,   306,   307,   337,   338,   339,   340,   341,
     262,   343,   197,   345,   191,   191,   268,   269,   197,   322,
     196,   198,  1033,   355,   190,   191,   192,   193,  1142,   191,
     362,  1145,     4,     5,   196,   367,   198,   191,   191,   291,
     292,   293,   196,   196,   198,   198,   191,     4,     5,  1163,
     191,   196,  1166,   297,   298,   196,   191,   198,   310,   362,
     196,   196,   198,   198,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   197,    14,   191,    16,
     197,    18,   197,   196,   191,   198,   191,  1201,    14,  1203,
      16,   198,    18,   198,  1208,  1209,   191,   191,   191,   191,
     197,   466,   196,   198,    41,   198,   198,    44,  1119,   441,
     629,  1122,    49,   440,   446,    41,   197,    44,    44,   440,
     364,   365,   197,    49,   191,   191,   191,   459,   460,  1140,
     196,   198,  1143,   198,   191,   197,    63,    64,    35,    36,
     472,   198,   474,    70,    71,    72,    73,    74,    75,    76,
      77,   197,   484,   485,    70,    71,    72,    73,    74,    75,
      76,   493,   494,   495,   496,   191,   191,   197,     4,     5,
     196,   807,    46,   198,   810,    70,    71,    72,    73,    74,
      75,    76,   197,  1194,   191,  1196,   197,   191,   197,    63,
      64,   198,   197,  1204,   198,  1206,    70,    71,    72,    73,
      74,    75,    76,    77,    70,    71,    72,    73,    74,    75,
      76,    46,   456,   457,     4,     5,   197,   461,   462,    70,
      71,    72,    73,    74,    75,    76,    77,   479,    63,    64,
     482,    51,     4,     5,   197,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    73,    74,    75,    76,    77,
      70,    71,    72,    73,    74,    75,    76,    77,    74,    75,
      76,    77,   191,   190,   191,   192,   193,   191,   191,   198,
     191,   191,   191,   196,   198,   191,   191,   198,   198,   198,
     612,   613,   198,   198,   197,    70,    71,    72,    73,    74,
      75,    76,   191,   637,   638,   882,   191,   191,   191,   198,
     632,   196,   629,   198,   198,   198,   197,   191,   629,   195,
     196,   898,   197,   645,   198,   834,   190,   191,   192,   193,
      75,    76,    77,     4,   191,   191,   658,   191,   191,   197,
     196,   198,   664,   665,   198,   198,    63,    64,   670,   190,
     191,   192,   193,    70,    71,    72,    73,    74,    75,    76,
      77,   197,   684,   191,   191,   190,   191,   192,   193,   191,
     198,   198,   190,   191,   192,   193,   198,   699,   700,   701,
     190,   191,   192,   193,   190,   191,   192,   193,   191,   711,
      14,   191,    16,   710,    18,   198,   191,   719,   720,   710,
     722,   723,   724,   198,   197,   639,   640,   197,   642,   643,
       4,     5,   734,   735,   191,   737,   191,    41,   197,   196,
      44,   743,   196,   198,   746,    49,    70,    71,    72,    73,
      74,    75,    76,   191,    86,    87,   758,   191,   196,   761,
     762,   763,   196,   765,   766,   190,   191,   192,   193,   197,
       3,   197,   774,   695,     7,     8,     9,   191,   191,   197,
     191,   191,   196,   196,   698,   196,   196,     4,     5,   197,
     712,   713,   197,   190,   191,   192,   193,   197,    63,   196,
     802,   198,   804,   805,   806,    70,    71,    72,    73,    74,
      75,    76,    77,   197,   736,   197,   818,    49,    50,   197,
      63,    64,     4,     5,    39,    40,   197,    70,    71,    72,
      73,    74,    75,    76,    77,   197,   838,   834,     4,     5,
      63,    64,   197,   834,   197,     3,   848,    70,    71,    72,
      73,    74,    75,    76,    77,    60,    61,    60,    61,   861,
     862,   197,   197,    21,   866,   867,    24,   191,   197,   197,
     872,   873,   197,    58,   197,    33,  1065,  1066,   197,    37,
      38,   197,   197,    71,    42,    73,    74,    75,    76,    77,
     197,   197,   197,   866,   867,   197,    54,    55,    56,   197,
     197,   197,   197,   197,   197,    63,    64,    65,    66,   197,
     197,   197,   197,   927,   928,   197,   197,   197,   197,   197,
     197,   197,  1111,     5,   197,   190,   191,   192,   193,   197,
     197,   933,    43,   197,   197,   197,   938,   197,   197,   197,
    1129,   943,   197,  1132,   197,   859,   860,   190,   191,   192,
     193,   197,   197,   196,   196,   198,   197,   197,   197,   197,
     197,   197,  1151,   197,    77,   196,   968,   190,   191,   192,
     193,   197,   197,   196,   196,   198,    71,    72,    73,    74,
      75,    76,    77,   197,   986,   197,   197,   196,   196,   196,
     992,    75,   198,    43,   198,    46,   198,   198,   197,  1001,
     197,  1003,   190,   191,   192,   193,  1008,   196,    10,    58,
     197,   197,   196,   196,    43,  1017,   197,   197,   197,   197,
     196,   196,   180,   196,   196,  1027,   196,   198,  1030,   198,
     188,   198,   196,   198,   197,   197,   950,   951,   198,   197,
     196,   198,    85,   198,   198,  1047,   198,   198,   197,   197,
     972,   198,   198,   197,    85,   213,   198,   198,   198,   198,
     218,     5,   196,   196,    58,  1067,   198,   225,  1065,  1066,
     198,   198,   198,   197,  1065,  1066,  1078,   197,   196,   198,
     197,    43,   198,   198,    38,    43,    58,   197,    75,   198,
     198,   249,    75,    75,  1096,   190,   191,   192,   193,    48,
     197,   259,    58,   197,  1106,   198,   198,   197,    47,   197,
     197,    58,  1114,  1115,  1111,    75,    38,   198,   198,   197,
    1111,   197,     4,     4,    53,   283,   710,    53,   466,     5,
     645,   641,  1129,   644,  1093,  1132,   933,   295,  1129,  1190,
     846,  1132,  1144,   463,  1146,   476,    -1,    -1,   306,    -1,
     309,    -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,  1161,
    1151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,   333,   334,   335,   336,  1181,
      -1,   339,    -1,    -1,   342,    -1,   344,    -1,   346,   347,
     348,   349,   350,   351,   352,   353,   354,    -1,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
     368,   369,   370,   371,   372,    -1,    -1,   375,    -1,   377,
      -1,   379,   380,   381,    -1,    -1,    -1,   385,   386,   387,
     388,   389,   390,   391,   392,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   471,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,   480,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,   493,   494,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,   166,   167,    -1,   169,   170,    -1,   172,   173,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,    63,
      64,    -1,    -1,   197,    -1,   199,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,   645,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,   661,    61,    62,   664,    -1,    -1,   667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,   190,   191,   192,   193,
      -1,    -1,   196,    -1,   198,    -1,    -1,    -1,   726,    -1,
     728,    -1,    -1,    -1,    -1,   132,   133,   134,    63,    64,
      -1,    -1,   139,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     768,   168,    -1,    -1,   171,     3,     4,     5,   175,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,   786,   787,
     788,   789,    -1,    -1,    -1,    -1,    -1,   795,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     808,    -1,    -1,   811,    -1,   813,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,   840,    -1,    -1,   843,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,   190,   191,   192,   193,    97,
     868,   869,   870,   101,   102,    -1,    -1,   105,    -1,   107,
     878,   879,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   933,   164,   165,   166,   167,
      -1,   169,   170,    -1,   172,   173,   174,   945,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,   957,
     188,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,   981,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   996,    -1,
      -1,    -1,  1000,    -1,    -1,    -1,    -1,    -1,    -1,  1007,
      -1,    -1,  1010,    -1,    -1,  1013,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1041,  1042,  1043,  1044,    -1,  1046,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,   190,   191,   192,   193,    -1,    -1,
     196,    -1,   198,    -1,    -1,  1113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,  1141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,     5,    84,    -1,    -1,    -1,    10,    -1,
      -1,  1159,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    31,
    1178,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,   166,   167,    -1,   169,
     170,    -1,   172,   173,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   105,    -1,   107,    -1,    -1,   188,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,    30,    31,   151,
     152,   153,   154,   155,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,    -1,   165,    -1,   167,    -1,    -1,   170,    -1,
      -1,   173,   174,    -1,   176,   177,    -1,   179,    -1,   181,
      63,    64,    65,    66,    67,    68,    69,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    81,    -1,
       5,    84,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    31,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,   164,   165,   166,   167,    -1,   169,   170,    -1,   172,
     173,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     105,    -1,   107,    -1,    -1,   188,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,   144,
     145,   146,    -1,    -1,    30,    31,   151,   152,   153,   154,
     155,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,
     165,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,   174,
      -1,   176,   177,    -1,   179,    -1,   181,    63,    64,    65,
      66,    67,    68,    69,   189,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   198,    -1,    81,    63,    64,    84,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
     166,   167,    -1,   169,   170,    -1,   172,   173,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   198,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    63,    64,    84,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,   166,   167,    -1,   169,
     170,    -1,   172,   173,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    63,    64,
      84,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,   166,   167,    -1,   169,   170,    -1,   172,   173,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   198,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    12,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    81,    -1,    -1,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,   166,   167,
      -1,   169,   170,    -1,   172,   173,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,    -1,    -1,    -1,     3,     4,     5,   197,
       7,     8,     9,    10,    -1,    -1,    -1,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,   166,
     167,    -1,   169,   170,    -1,   172,   173,   174,    -1,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,    -1,    -1,    -1,     3,     4,     5,
     197,     7,     8,     9,    10,    -1,    12,    -1,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
     166,   167,    -1,   169,   170,    -1,   172,   173,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,    -1,     3,     4,
       5,   197,     7,     8,     9,    10,    -1,    -1,    -1,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,     5,    84,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    31,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,   164,
     165,   166,   167,    -1,   169,   170,    -1,   172,   173,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   105,    -1,
     107,    -1,     5,   188,   189,   190,    -1,    10,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    31,    -1,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,    -1,   165,    -1,
     167,    -1,    -1,   170,    -1,    -1,   173,   174,    -1,   176,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
       5,    -1,   189,    -1,    -1,    10,    -1,    -1,    -1,    -1,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,   158,    -1,   160,     5,   162,
      -1,    -1,   165,    10,   167,    -1,    -1,   170,    -1,    -1,
     173,   174,    97,   176,   177,    -1,   179,    -1,   181,    -1,
     105,    -1,   107,    -1,    31,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
     155,     5,    -1,   158,    -1,   160,    10,   162,    -1,    -1,
     165,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,   174,
      97,   176,   177,    -1,   179,    -1,   181,    31,   105,    -1,
     107,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,     5,
      -1,   158,    -1,   160,    10,   162,    -1,    -1,   165,    -1,
     167,    -1,    -1,   170,    -1,    -1,   173,   174,    -1,   176,
     177,   105,   179,   107,   181,    31,    -1,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,
      -1,   165,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,
     174,    -1,   176,   177,    -1,   179,    -1,   181,    -1,   105,
      -1,   107,    -1,    -1,    -1,   189,    -1,    -1,    -1,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   132,   133,   134,    -1,
      -1,    -1,   138,   139,   140,    -1,   142,    -1,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,   165,
      -1,   167,    -1,    -1,   170,    -1,    -1,   173,   174,    -1,
     176,   177,    -1,   179,    -1,   181,    -1,     4,     5,     6,
      -1,    -1,    -1,   189,    11,    -1,    -1,    -1,    15,    -1,
      17,   197,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   159,    -1,    -1,    -1,   163,    -1,     4,     5,
       6,   168,    -1,    -1,   171,    11,    -1,    -1,   175,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    63,    64,    -1,    61,    62,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,
     106,    -1,   108,   109,   190,   191,   192,   193,    63,    64,
      -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   132,   133,   134,    63,
      64,    -1,    -1,   139,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    -1,   168,    63,    64,   171,    -1,    -1,    -1,   175,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   190,
     191,   192,   193,    63,    64,    -1,    -1,   198,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,
      64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   190,   191,   192,   193,
      63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     190,   191,   192,   193,    63,    64,    -1,    -1,   198,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,    63,    64,    -1,    -1,   198,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
      63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,    63,    64,    -1,    -1,
     198,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   190,   191,   192,   193,    63,    64,    -1,    -1,   198,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   190,   191,   192,   193,    63,    64,    -1,    -1,   198,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   190,   191,   192,   193,    63,    64,    -1,
      -1,   198,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,    63,    64,    -1,    -1,
     198,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   190,   191,   192,   193,    63,    64,    -1,    -1,
     198,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,   193,    63,    64,    -1,
      -1,   198,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   190,   191,   192,   193,    63,    64,
      -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   190,   191,   192,   193,    63,    64,    -1,
      -1,   198,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   190,   191,   192,   193,    63,    64,    -1,
      -1,   198,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,    64,
      -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,
      64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   190,   191,   192,   193,    63,    64,
      -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,    63,    64,    -1,    -1,   198,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,
      64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   190,   191,   192,   193,
      63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   190,   191,   192,   193,    63,
      64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     190,   191,   192,   193,    63,    64,    -1,    -1,   198,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
      63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   190,   191,   192,
     193,    63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,    63,    64,    -1,    -1,   198,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   190,   191,   192,   193,    63,    64,    -1,    -1,   198,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    63,    64,    -1,    -1,   198,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   190,   191,
     192,   193,    63,    64,    -1,    -1,   198,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   190,   191,   192,   193,    63,    64,    -1,    -1,
     198,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,    63,    64,    -1,    -1,
     198,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,   193,    63,    64,    -1,    -1,   198,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,    64,
      -1,    -1,   198,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   190,   191,   192,   193,    63,    64,    -1,
      -1,   198,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   190,   191,   192,   193,    63,    64,   196,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,    63,    64,   196,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   190,   191,   192,   193,    63,
      64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   190,   191,   192,   193,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,    64,
     196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   190,   191,   192,   193,    63,    64,
     196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,    63,
      64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   190,   191,   192,   193,
      63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   190,   191,   192,   193,    63,
      64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   190,   191,   192,   193,    63,
      64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,   193,
      63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   190,   191,   192,
     193,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   190,   191,   192,   193,
      63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   190,   191,   192,   193,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,    63,    64,   196,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
     193,    63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   190,   191,
     192,   193,    63,    64,   196,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   190,   191,   192,
     193,    63,    64,   196,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   190,   191,   192,   193,    63,    64,   196,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,   193,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,   193,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,   193,    63,    64,   196,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   190,
     191,   192,   193,    63,    64,   196,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   190,   191,
     192,   193,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,   193,    63,    64,   196,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   190,   191,   192,   193,    63,    64,   196,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,    -1,    -1,
     196
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   183,   184,   185,   186,   187,   201,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   159,   163,   168,   171,   175,   202,   203,   206,
     207,   214,   215,   217,   218,   222,   234,   235,   240,   246,
     253,   261,   269,   272,   276,   279,   285,     3,     4,     5,
       7,     8,     9,    10,    30,    31,    63,    64,    65,    66,
      67,    68,    69,    81,    84,   101,   102,   105,   107,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   164,   165,   166,   167,   169,   170,   172,   173,   174,
     176,   177,   178,   179,   180,   181,   182,   188,   189,   190,
     197,   220,   221,   223,   229,   231,   234,   235,   197,   220,
     206,   234,   235,   240,     0,    75,   197,    75,   197,   254,
     273,   277,     4,     7,   232,   232,   232,    34,   223,   208,
     209,   220,   236,   237,   236,   220,    28,     7,   262,   270,
     223,    58,    60,    61,   199,   316,   212,   220,   223,     4,
       5,   233,   223,   220,   223,   220,   223,     4,     5,   296,
     297,    10,   190,   191,   230,   231,   298,   232,    89,    97,
     199,   220,   223,   317,    89,    97,   110,   317,   317,    88,
     223,   228,    12,    53,   228,   228,    59,    89,    90,    91,
      96,    95,   223,   215,   222,   220,   220,   220,   110,   197,
     197,   197,   197,   197,   220,   317,   220,   220,   220,    44,
     204,    92,    93,   104,    75,    75,    24,   197,   197,   197,
     197,   223,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   223,   220,   223,    70,    71,    72,    73,    74,
      75,    76,   191,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   190,   191,   192,   193,   220,    44,
      44,    44,   223,   236,   220,   236,     4,   223,   203,    35,
      36,    20,    21,     4,     5,   247,   248,     4,     5,   249,
     250,   220,   223,   238,   239,   220,   223,   264,   203,   280,
     286,   197,    58,   197,     4,     7,   197,   220,   223,   299,
      58,    60,    61,   199,   301,   314,   197,   197,   196,   196,
     196,   197,   197,   196,   231,   231,   196,   223,   220,   223,
      11,   196,   196,   220,   196,   228,   213,    12,   196,   216,
     196,   228,    12,   228,   216,   216,     5,   219,   219,   219,
     198,   223,   220,   196,   196,   196,   196,    43,   228,   228,
     228,   223,   220,   241,   236,   236,   223,   223,   223,   223,
     223,   223,    97,   220,   317,   317,     4,     5,   226,   227,
     226,   227,   228,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   317,   223,   223,   223,   223,   223,
     223,   223,   223,   198,   223,   220,   220,   220,   220,   220,
     223,   223,   220,   223,   198,   223,   223,   220,   223,   220,
     223,   220,   220,   198,   220,   198,   220,   198,   220,   198,
     220,   220,   220,   220,   223,   220,   220,   220,   220,   220,
     220,   220,   317,   220,   236,   236,   220,   223,   220,   220,
     220,   220,   220,   198,   198,   220,   219,   220,   219,   220,
     220,   220,   198,   198,   220,   220,   220,   220,   220,   220,
     220,   220,   225,   224,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   198,   198,    75,   274,
      14,    16,    18,    41,    44,    49,   278,   210,   211,   197,
     197,   196,   197,   197,   196,   196,    43,   263,    14,    16,
      18,    41,    44,    49,   271,    46,   203,   223,   197,   220,
     223,    51,   300,   195,   196,   197,    58,   197,     4,     7,
     197,    10,   315,   236,   236,     4,     5,   223,   223,   236,
     236,   297,    10,   230,   196,    86,    87,    97,   220,   223,
     223,   301,   228,   220,   228,   216,   223,   223,   197,   196,
     196,   196,   198,   198,   220,   223,   220,   223,   223,   223,
     205,   196,   216,   216,     4,     5,   245,   198,   198,   196,
     196,   198,   196,   196,   196,   198,   196,   198,   196,   198,
     197,   197,   198,   198,   196,   196,   216,   196,   198,   198,
     198,   198,   198,   196,   198,   198,   196,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   196,   198,
     198,   196,   196,   196,   198,   196,   196,   198,   196,   198,
     198,   198,   198,   198,   196,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   196,   196,   196,   196,
     198,   198,   198,   198,   198,   196,   198,   198,   198,   198,
     198,   198,   196,   198,   196,   196,   196,   196,   196,   198,
     196,   196,   198,   196,   198,   198,   223,   223,   255,   203,
     223,   232,   318,   232,   319,   236,   236,   248,   236,   236,
     250,   239,    43,   265,   281,    49,    50,   287,   196,   223,
     196,   198,   198,   197,   220,   220,   223,   223,   197,   220,
     302,   303,   223,     4,     5,   293,   295,   198,   198,   197,
     197,   196,   196,   198,   198,   223,    85,    85,   196,   196,
     196,   228,   196,   196,   236,   223,   223,   223,   196,   196,
     207,   223,   228,   228,   242,   223,   223,   223,   223,   223,
     220,    97,   220,   198,   198,   223,   223,   228,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   220,   223,   220,
     220,   220,   220,   220,   223,   223,   223,   223,   227,   220,
     227,   220,   220,   223,    16,    44,   275,   196,   196,   198,
     198,   198,   198,    39,    40,   267,   203,   223,   196,   220,
      58,   220,   300,   196,   223,   196,   198,   293,   293,   198,
     197,   197,   196,   236,   236,   223,   223,   196,   317,   317,
     220,   220,   220,   223,   223,   198,   198,   198,   196,   198,
     220,   220,   216,   197,   198,   198,   198,   198,   198,   198,
     198,   196,   198,   198,   198,   198,   216,   198,   198,   198,
     198,   198,   196,   198,   198,   198,   196,   198,   198,   198,
     196,   196,   198,   196,   198,   198,   198,   196,   196,   198,
     196,   198,   198,   196,   198,   198,   198,    12,   232,   232,
     264,    43,    38,   282,   198,   223,   198,   197,   196,   223,
     196,   220,    58,   309,   304,   236,   236,   294,   198,   198,
     220,   196,   196,    75,    75,   223,    75,   196,   228,     4,
       5,   251,   252,   220,   223,   223,   220,   220,   223,   223,
     220,   223,   220,   220,   223,   266,   268,    48,   289,    60,
      61,   198,    58,   223,   220,   198,   223,   198,   197,   315,
     293,   198,   198,   293,   220,   220,   220,   220,   198,   220,
     223,   197,   197,   196,   198,   198,   196,   198,   198,   198,
     198,   198,   198,   198,   198,   198,    13,   259,   203,   203,
     223,    47,   288,   197,   197,   196,   198,    60,    61,   305,
     198,    58,   310,   223,   293,    75,   198,   198,   252,   243,
     223,   223,   256,    46,   292,   203,   283,   220,   223,   223,
     311,   197,   315,   306,   197,   315,   196,   220,   203,   198,
     203,   290,    14,    16,    18,    41,    44,    49,   284,   196,
     198,   196,   198,   315,   220,   293,   315,   223,   293,   223,
      25,    44,   244,   257,   203,   220,   223,   293,   196,   198,
     293,   196,   198,    14,    16,    18,    41,    44,    49,   258,
     291,   198,   198,   220,   312,   223,   307,     4,   260,   289,
     198,   315,   198,   315,   313,   293,   308,   293,   315,   315,
     293,   293
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   200,   201,   201,   201,   201,   201,   202,   203,   204,
     205,   203,   206,   206,   206,   206,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   208,   207,   209,   207,   207,   207,   207,   207,   207,
     207,   210,   207,   211,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   212,   207,   213,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   214,   214,
     214,   214,   214,   215,   215,   215,   215,   215,   215,   216,
     216,   217,   217,   217,   217,   217,   218,   218,   219,   219,
     220,   220,   220,   220,   220,   220,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   222,
     222,   224,   223,   225,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   226,   227,   228,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   230,   230,   230,   231,   231,   231,   231,   232,   232,
     233,   233,   233,   233,   234,   235,   237,   236,   238,   238,
     238,   239,   239,   241,   242,   243,   240,   244,   244,   245,
     245,   246,   246,   246,   246,   247,   247,   248,   248,   248,
     248,   249,   249,   250,   250,   250,   250,   251,   251,   251,
     252,   252,   252,   252,   254,   255,   256,   257,   253,   258,
     258,   258,   258,   258,   258,   259,   259,   260,   260,   262,
     261,   263,   263,   264,   264,   265,   266,   265,   267,   268,
     267,   270,   269,   271,   271,   271,   271,   271,   271,   273,
     274,   272,   275,   275,   277,   276,   278,   278,   278,   278,
     278,   278,   280,   281,   282,   283,   279,   284,   284,   284,
     284,   284,   284,   286,   285,   287,   287,   288,   288,   289,
     290,   291,   289,   292,   292,   293,   294,   293,   295,   295,
     295,   295,   296,   296,   297,   297,   297,   297,   298,   298,
     298,   298,   299,   299,   299,   299,   299,   300,   300,   300,
     302,   301,   303,   301,   304,   301,   305,   301,   306,   301,
     307,   301,   308,   301,   309,   301,   310,   301,   311,   301,
     312,   301,   313,   301,   314,   301,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   317,   317,   318,   318,   319,   319
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       0,     5,     1,     2,     1,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     1,     2,     2,     3,
       3,     0,     5,     0,     5,     2,     1,     2,     1,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     6,     8,     4,     4,     4,     4,     4,
       6,     1,     3,     1,     3,     4,     6,     6,     4,     6,
       4,     6,    10,     4,     4,     4,     8,     6,     4,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     3,     4,     6,     1,     4,     4,     6,     6,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     3,     6,     6,     4,     4,     4,     4,     6,     6,
       8,     6,     8,     4,     4,     4,     8,     4,     4,     4,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     6,     6,     4,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       4,     1,     2,     2,     1,     1,     1,     1,     1,     1,
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
       0,     4,     0,     4,     0,     6,     0,     9,     0,    10,
       0,    13,     0,    15,     0,     7,     0,     9,     0,    10,
       0,    13,     0,    15,     0,     3,     0,     1,     0,     2,
       2,     4,     1,     4,     6,     6,     7,    10,    12,     7,
      10,    12,     2,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3: /* program_or_expression: tSTART_EXPRESSION expression tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
                                                       {YYACCEPT;}
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
                                                           {YYACCEPT;}
    break;

  case 7: /* program: statement_list tEOPROG  */
                                {YYACCEPT;}
    break;

  case 9: /* $@1: %empty  */
                   {if (severity_so_far >= sERROR) {YYABORT;}}
    break;

  case 10: /* $@2: %empty  */
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
    break;

  case 18: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 19: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 25: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 27: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 29: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 31: /* $@3: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 33: /* $@4: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 41: /* $@5: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
              {add_command(cNOP);}
    break;

  case 43: /* $@6: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
               {add_command(cNOP);}
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 46: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 47: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 48: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 49: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 50: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 52: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 55: /* $@7: %empty  */
           {tileol=FALSE;}
    break;

  case 57: /* $@8: %empty  */
                 {tileol=TRUE;}
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 60: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 65: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 67: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 68: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 69: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 74: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 78: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 79: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 85: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 86: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 96: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 97: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 98: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 99: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 100: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 101: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 102: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 103: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 104: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 105: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 106: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 107: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 108: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 109: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 110: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 111: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 112: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 113: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 114: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 116: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 117: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 118: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 119: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 120: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 121: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 122: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 123: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 124: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 125: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 126: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 127: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 128: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 131: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 132: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 133: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 134: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 135: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 136: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 137: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 138: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 139: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 140: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 142: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 143: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 144: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 146: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 147: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 148: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 149: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 150: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 151: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 152: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 153: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 154: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 155: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 156: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 157: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 158: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 159: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 160: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 161: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 162: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 163: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 164: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 165: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 166: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 167: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 168: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 169: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 170: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 171: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 172: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 173: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 174: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 175: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 176: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 177: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 178: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 179: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 180: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 181: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 182: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 183: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 184: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 185: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 186: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 187: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 188: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 189: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 190: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 191: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 192: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 193: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 194: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 195: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 196: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 197: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 198: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 199: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 200: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 201: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 202: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 203: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 204: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 205: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 206: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 207: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 208: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 209: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 210: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 211: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 212: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 213: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 214: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 215: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 216: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 217: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 218: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 219: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 220: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 221: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 222: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 223: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 224: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 227: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 228: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 230: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 231: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 232: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 233: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 234: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 235: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 236: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 237: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 238: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 239: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 240: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 241: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 242: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 243: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 244: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 245: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 246: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 247: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 248: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 249: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 250: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 251: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 252: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 253: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 254: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 255: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 256: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 257: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 258: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 259: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 260: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 261: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 262: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 263: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 264: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 265: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 266: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 267: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 268: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 269: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 270: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 271: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 272: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 273: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 274: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 275: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 276: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 277: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 278: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 279: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 280: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 281: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 282: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 283: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 284: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 285: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 286: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 287: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 288: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 289: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 290: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 291: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 292: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 293: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 294: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 295: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 296: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 297: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 298: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 299: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 300: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 301: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 302: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 303: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 304: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 305: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 306: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 307: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 308: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 309: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 310: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 311: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 312: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 313: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 314: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 315: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 316: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 323: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 324: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 325: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 326: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 327: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 328: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 329: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 330: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 331: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 332: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 333: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 334: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 337: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 338: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 339: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 340: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 343: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 344: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 345: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 346: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 350: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 351: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 352: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 353: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 354: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 355: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 356: /* $@17: %empty  */
                    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}
    break;

  case 357: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 358: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 359: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 360: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 361: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 362: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 363: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 364: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 365: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 367: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 368: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 369: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 370: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 376: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 377: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 379: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 381: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 383: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 384: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 385: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 386: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 387: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 388: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 389: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 390: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 392: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 393: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 394: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 396: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 397: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 398: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 399: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 400: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 401: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 402: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 403: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 404: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 405: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 407: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 408: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 409: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 410: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 411: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 412: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 413: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 415: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 416: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 420: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 421: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 426: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 428: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 429: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 430: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 431: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 434: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 435: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 436: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 437: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 438: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 439: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 440: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 441: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 445: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 446: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 447: /* using: %empty  */
       {create_print('d');}
    break;

  case 448: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 449: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 450: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 451: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 452: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 453: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 454: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 455: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 456: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 457: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 458: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 459: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 460: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 461: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 462: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 463: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 464: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 465: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 466: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 467: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 468: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 469: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 470: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 471: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 472: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 473: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 474: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 475: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 476: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 477: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 478: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 479: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 480: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 481: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 482: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 483: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 484: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 485: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 486: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 487: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 488: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 489: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 490: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 491: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 494: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 495: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 496: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 497: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

