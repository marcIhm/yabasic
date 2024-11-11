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
    written by Marc Ihm 1995-2024
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
  YYSYMBOL_tINSTR = 154,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 155,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 156,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 157,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 158,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 159,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 160,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 161,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 162,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 163,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 164,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 165,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 166,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 167,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 168,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 169,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 170,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 171,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 172,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 173,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 174,                    /* tDATE  */
  YYSYMBOL_tTIME = 175,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 176,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 177,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 178,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 179,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 180,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 181,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 182,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 183, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 184,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 185, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 186,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 187,                   /* tEVAL2  */
  YYSYMBOL_188_ = 188,                     /* '-'  */
  YYSYMBOL_189_ = 189,                     /* '+'  */
  YYSYMBOL_190_ = 190,                     /* '*'  */
  YYSYMBOL_191_ = 191,                     /* '/'  */
  YYSYMBOL_UMINUS = 192,                   /* UMINUS  */
  YYSYMBOL_193_ = 193,                     /* ';'  */
  YYSYMBOL_194_ = 194,                     /* ','  */
  YYSYMBOL_195_ = 195,                     /* '('  */
  YYSYMBOL_196_ = 196,                     /* ')'  */
  YYSYMBOL_197_ = 197,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 198,                 /* $accept  */
  YYSYMBOL_program_or_expression = 199,    /* program_or_expression  */
  YYSYMBOL_program = 200,                  /* program  */
  YYSYMBOL_statement_list = 201,           /* statement_list  */
  YYSYMBOL_202_1 = 202,                    /* $@1  */
  YYSYMBOL_203_2 = 203,                    /* $@2  */
  YYSYMBOL_assignment = 204,               /* assignment  */
  YYSYMBOL_statement = 205,                /* statement  */
  YYSYMBOL_206_3 = 206,                    /* $@3  */
  YYSYMBOL_207_4 = 207,                    /* $@4  */
  YYSYMBOL_208_5 = 208,                    /* $@5  */
  YYSYMBOL_209_6 = 209,                    /* $@6  */
  YYSYMBOL_210_7 = 210,                    /* $@7  */
  YYSYMBOL_211_8 = 211,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 212,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 213,        /* string_assignment  */
  YYSYMBOL_to = 214,                       /* to  */
  YYSYMBOL_open_clause = 215,              /* open_clause  */
  YYSYMBOL_seek_clause = 216,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 217,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 218,        /* string_expression  */
  YYSYMBOL_string_function = 219,          /* string_function  */
  YYSYMBOL_number_assignment = 220,        /* number_assignment  */
  YYSYMBOL_expression = 221,               /* expression  */
  YYSYMBOL_222_9 = 222,                    /* $@9  */
  YYSYMBOL_223_10 = 223,                   /* $@10  */
  YYSYMBOL_arrayref = 224,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 225,          /* string_arrayref  */
  YYSYMBOL_coordinates = 226,              /* coordinates  */
  YYSYMBOL_function = 227,                 /* function  */
  YYSYMBOL_const = 228,                    /* const  */
  YYSYMBOL_number = 229,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 230,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 231,                  /* dimlist  */
  YYSYMBOL_function_or_array = 232,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 233,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 234,                /* call_list  */
  YYSYMBOL_235_11 = 235,                   /* $@11  */
  YYSYMBOL_calls = 236,                    /* calls  */
  YYSYMBOL_call_item = 237,                /* call_item  */
  YYSYMBOL_function_definition = 238,      /* function_definition  */
  YYSYMBOL_239_12 = 239,                   /* $@12  */
  YYSYMBOL_240_13 = 240,                   /* $@13  */
  YYSYMBOL_241_14 = 241,                   /* $@14  */
  YYSYMBOL_endsub = 242,                   /* endsub  */
  YYSYMBOL_function_name = 243,            /* function_name  */
  YYSYMBOL_export = 244,                   /* export  */
  YYSYMBOL_local_list = 245,               /* local_list  */
  YYSYMBOL_local_item = 246,               /* local_item  */
  YYSYMBOL_static_list = 247,              /* static_list  */
  YYSYMBOL_static_item = 248,              /* static_item  */
  YYSYMBOL_paramlist = 249,                /* paramlist  */
  YYSYMBOL_paramitem = 250,                /* paramitem  */
  YYSYMBOL_for_loop = 251,                 /* for_loop  */
  YYSYMBOL_252_15 = 252,                   /* $@15  */
  YYSYMBOL_253_16 = 253,                   /* $@16  */
  YYSYMBOL_254_17 = 254,                   /* $@17  */
  YYSYMBOL_255_18 = 255,                   /* $@18  */
  YYSYMBOL_next = 256,                     /* next  */
  YYSYMBOL_step_part = 257,                /* step_part  */
  YYSYMBOL_next_symbol = 258,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 259,  /* switch_number_or_string  */
  YYSYMBOL_260_19 = 260,                   /* $@19  */
  YYSYMBOL_sep_list = 261,                 /* sep_list  */
  YYSYMBOL_number_or_string = 262,         /* number_or_string  */
  YYSYMBOL_case_list = 263,                /* case_list  */
  YYSYMBOL_264_20 = 264,                   /* $@20  */
  YYSYMBOL_default = 265,                  /* default  */
  YYSYMBOL_266_21 = 266,                   /* $@21  */
  YYSYMBOL_do_loop = 267,                  /* do_loop  */
  YYSYMBOL_268_22 = 268,                   /* $@22  */
  YYSYMBOL_loop = 269,                     /* loop  */
  YYSYMBOL_while_loop = 270,               /* while_loop  */
  YYSYMBOL_271_23 = 271,                   /* $@23  */
  YYSYMBOL_272_24 = 272,                   /* $@24  */
  YYSYMBOL_wend = 273,                     /* wend  */
  YYSYMBOL_repeat_loop = 274,              /* repeat_loop  */
  YYSYMBOL_275_25 = 275,                   /* $@25  */
  YYSYMBOL_until = 276,                    /* until  */
  YYSYMBOL_if_clause = 277,                /* if_clause  */
  YYSYMBOL_278_26 = 278,                   /* $@26  */
  YYSYMBOL_279_27 = 279,                   /* $@27  */
  YYSYMBOL_280_28 = 280,                   /* $@28  */
  YYSYMBOL_281_29 = 281,                   /* $@29  */
  YYSYMBOL_endif = 282,                    /* endif  */
  YYSYMBOL_short_if = 283,                 /* short_if  */
  YYSYMBOL_284_30 = 284,                   /* $@30  */
  YYSYMBOL_end_of_if = 285,                /* end_of_if  */
  YYSYMBOL_else_part = 286,                /* else_part  */
  YYSYMBOL_elsif_part = 287,               /* elsif_part  */
  YYSYMBOL_288_31 = 288,                   /* $@31  */
  YYSYMBOL_289_32 = 289,                   /* $@32  */
  YYSYMBOL_maybe_then = 290,               /* maybe_then  */
  YYSYMBOL_inputlist = 291,                /* inputlist  */
  YYSYMBOL_292_33 = 292,                   /* $@33  */
  YYSYMBOL_input = 293,                    /* input  */
  YYSYMBOL_readlist = 294,                 /* readlist  */
  YYSYMBOL_readitem = 295,                 /* readitem  */
  YYSYMBOL_datalist = 296,                 /* datalist  */
  YYSYMBOL_printlist = 297,                /* printlist  */
  YYSYMBOL_using = 298,                    /* using  */
  YYSYMBOL_inputbody = 299,                /* inputbody  */
  YYSYMBOL_300_34 = 300,                   /* $@34  */
  YYSYMBOL_301_35 = 301,                   /* $@35  */
  YYSYMBOL_302_36 = 302,                   /* $@36  */
  YYSYMBOL_303_37 = 303,                   /* $@37  */
  YYSYMBOL_304_38 = 304,                   /* $@38  */
  YYSYMBOL_prompt = 305,                   /* prompt  */
  YYSYMBOL_printintro = 306,               /* printintro  */
  YYSYMBOL_hashed_number = 307,            /* hashed_number  */
  YYSYMBOL_goto_list = 308,                /* goto_list  */
  YYSYMBOL_gosub_list = 309                /* gosub_list  */
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
#define YYFINAL  192
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  198
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  479
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   443


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
       2,     2,     2,     2,     2,   197,     2,     2,     2,     2,
     195,   196,   190,   189,   194,   188,     2,   191,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   193,
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
     185,   186,   187,   192
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
     398,   399,   400,   401,   402,   403,   404,   407,   408,   411,
     411,   412,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   447,   450,   453,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   529,
     530,   531,   534,   535,   536,   537,   540,   541,   544,   545,
     546,   547,   550,   553,   556,   556,   559,   560,   561,   564,
     565,   568,   569,   572,   568,   577,   578,   581,   582,   585,
     586,   587,   588,   591,   592,   595,   596,   597,   598,   601,
     602,   605,   606,   607,   608,   611,   612,   613,   616,   617,
     618,   619,   622,   623,   628,   643,   622,   648,   649,   650,
     651,   652,   653,   656,   657,   660,   661,   666,   666,   670,
     671,   674,   675,   679,   681,   680,   685,   686,   686,   690,
     690,   696,   697,   698,   699,   700,   701,   705,   706,   705,
     712,   713,   717,   717,   722,   723,   724,   725,   726,   727,
     730,   731,   731,   733,   730,   737,   738,   739,   740,   741,
     742,   745,   745,   750,   751,   754,   755,   758,   760,   762,
     759,   766,   767,   770,   771,   771,   774,   775,   777,   778,
     782,   783,   786,   787,   789,   790,   794,   795,   796,   797,
     800,   801,   802,   803,   804,   807,   808,   809,   812,   812,
     813,   813,   814,   814,   815,   815,   816,   816,   819,   820,
     823,   824,   825,   826,   827,   828,   829,   830,   831,   832,
     833,   834,   835,   836,   839,   840,   842,   843,   846,   847
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
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL",
  "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE",
  "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1", "$@2",
  "assignment", "statement", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
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
  "$@34", "$@35", "$@36", "$@37", "$@38", "prompt", "printintro",
  "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-832)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-401)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     519,  3814,  3247,  2369,    79,    24,    66,   -22,   -21,  -832,
    -832,  -832,  -832,  -832,    26,    26,    26,  2869,  -832,  -832,
    -832,  2369,  -832,  -832,  2369,    -7,    25,  -832,  -832,  -832,
    3247,   -10,  -832,  3247,   232,  -832,  3247,  3247,  3247,   301,
      15,    26,  1459,  1117,  1903,   -25,  3247,  2680,  3247,    23,
     -40,  3247,  -832,    22,  2369,  2369,  2369,   -18,  -109,   -88,
     -55,     5,    48,  1903,  2369,  2369,  2369,  -832,    77,  -832,
    -832,   -24,  -832,  -832,  -832,  -832,    42,   110,  -832,   171,
    -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,    57,    78,
    -832,  -832,  -832,  -832,    84,    94,    96,   137,  3247,   145,
     177,   223,   225,   255,   258,   270,   272,   283,   294,   297,
     300,   312,   348,   351,   375,   387,   390,   401,   416,   420,
     435,   442,   474,   476,   503,   510,   514,   526,   531,   535,
     540,   544,   549,   552,   553,   557,   561,   565,   566,   569,
     570,   575,   576,   577,   578,   579,   580,   581,   586,   587,
     588,   591,   592,   594,   598,   604,   605,   607,   608,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   623,
     630,   631,   632,   633,   634,   635,   639,  3247,  3247,   185,
    -832,   799,  -832,  -832,  -832,  -832,  2369,   -36,   139,    42,
     110,   183,  -832,  3247,  -832,  2369,  -832,   325,  3247,  3655,
    -832,  -832,  -832,  -832,  -832,   333,   589,   380,   645,   274,
    -832,  3247,  -832,   274,  -832,  -832,  3247,  3655,    95,   640,
     445,   641,     6,  3247,   -11,   185,  6366,   642,   643,   331,
    6366,   185,  1361,   185,  5526,   649,   652,   366,  -832,  -832,
     638,   638,  -832,  -832,   463,  -832,  3247,  2369,  3247,    27,
    6366,   646,  -832,  -832,  -832,  -832,   654,  2369,  5546,  -832,
    3247,  -832,     8,   655,  -832,  -832,  3247,  3058,  -832,  -832,
    6366,  -832,  -832,   274,     4,     4,  -832,   506,   506,   506,
    2098,  2369,   398,   658,   274,   -74,     0,  -832,   556,  3247,
    3247,  3247,  3247,  2369,  -832,  -832,  -832,  3247,  3247,  1260,
    3247,  3247,  3247,  3247,  1708,  1903,   692,   692,  3247,  3247,
    3247,  3247,  3247,  3247,  3247,  3247,  3247,  3247,  3247,  3247,
    1903,  3247,  3247,  3247,  3247,  3247,  3247,  3247,  3247,  2292,
    2369,  2369,  2369,  2369,  2369,  3247,  3247,  3247,  2486,  3247,
    2369,  3247,  2369,  3247,  2369,  2369,   376,  1786,  1981,  2175,
    2369,  2369,  2369,  2369,  2369,  2369,  2369,  2369,  1903,  2369,
    -832,  -832,  2369,  3247,  2369,  2369,  2369,  2369,  2369,   637,
     657,  2369,   506,  2369,   506,  2369,  2369,  2369,   707,   159,
    1611,  2369,  2369,  2369,  2369,  2369,  2369,  2369,  2369,  -832,
    -832,  -832,  3247,  3247,  3247,  3247,  3247,  3247,  3247,  3247,
    3247,  3247,  3247,  3247,  -124,  -832,  -832,  -832,  6366,   659,
     274,   662,   710,  6366,    44,  -832,  -832,  -832,  -832,   664,
     665,   660,  -832,   666,   669,   671,  -832,   185,  6366,   672,
    -832,   185,  6366,   758,   482,   821,  3655,  3247,   673,  2369,
    -832,  -832,  3247,   185,   942,   216,   683,    10,  -832,   869,
    -832,  -832,   709,  3247,  3247,  -832,  -832,   301,  -832,  -832,
      36,  5577,   274,  6366,   629,  3426,  3247,   274,  3247,  -832,
     -11,  -832,  -832,  3247,  2369,  -832,  3247,     8,  3247,  3247,
     685,   689,   690,   694,  -832,  3262,   -78,  3247,  3247,  3247,
    3247,  -832,   696,     8,     8,  6366,   274,   713,   691,   695,
    5623,  5655,  3968,  5675,  5706,  5721,   698,     3,   701,   705,
     697,   702,   706,   708,   711,   712,     8,  5752,  4014,  4045,
    4077,  4097,  4112,  1304,  4143,  1319,  4174,  4206,   714,  4241,
    4272,  4303,  4335,  4350,  4370,  4401,  5784,  -832,  4432,   -52,
      21,    99,   160,   -32,  5804,  5850,   341,  2696,  -832,  4479,
    4499,   -12,  4530,    98,  4561,   108,   142,  -832,   161,  -832,
     170,  -832,   233,  -832,   242,   265,   305,   316,   194,   239,
     317,   344,   346,   373,   715,   164,   716,   717,   349,  4576,
     360,   181,   245,   290,   330,  -832,  -832,   438,    32,   439,
      73,   449,   363,   365,  -832,  -832,   274,   274,   274,   274,
     274,   274,   274,  -832,  3247,  3247,   606,    51,   746,   268,
      29,    86,   174,  -832,   -48,   -48,   707,   707,  -832,  -832,
    -832,  3655,  -832,  -832,  3247,  -832,  -832,  -832,  -832,    26,
      26,  -832,  -832,   380,  -832,  -832,   645,  3247,  -832,   843,
    -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,   670,  5881,
    3247,   182,  4608,  2563,  -832,  -832,  3247,  3247,  -832,  -832,
    3247,  -832,   724,   720,   725,   727,   728,  5913,  5933,   731,
     732,  -832,  -832,  -832,  3247,   818,   839,  -832,   462,  5948,
    6366,  -832,  -832,   479,  -832,  3247,  5979,  6010,  -832,  3247,
    3247,  3247,  -832,  -832,   185,  6366,   185,  6366,  6042,  6077,
    3655,  3247,  3247,  3247,  -832,  -832,  -832,  -832,  -832,  3247,
    3247,  -832,  3247,  3247,  3247,  -832,  2369,  -832,  3478,  -832,
     734,   735,  -832,  -832,  3247,  3247,  3247,  3247,  -832,  -832,
    -832,  -832,  -832,  3247,  -832,  -832,  3247,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,  3247,  -832,
    -832,  3247,  3247,  3247,  -832,  3247,  3247,  -832,  2369,  -832,
    -832,  -832,  -832,  -832,  3247,  -832,  -832,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  -832,  2369,  2369,  -832,  -832,
    -832,  -832,  -832,  2369,  -832,  -832,  -832,  -832,  -832,  -832,
    3247,  -832,  3247,  3247,  3247,   924,  2369,  -832,   924,  2369,
    -832,  2369,  -832,  -832,  1260,  3697,  3247,    65,  6366,  -832,
     738,  -832,   739,   742,   743,  -832,   744,   745,  -832,  -832,
    -832,   693,  3655,  -832,  -832,  -832,  3247,  6108,  2369,   884,
    -832,  2369,   274,   185,   942,  6139,   724,   724,  4628,   748,
     749,  -832,   751,  -832,  -832,  -832,  -832,  3247,  3247,  -832,
    -832,  6171,  1903,  1903,  2369,  2369,  2369,  -832,  3247,  3247,
     750,  4659,  4705,  2884,  2369,  2369,  -832,  6366,     8,  -832,
     753,  4737,  4757,  4788,  4803,  4834,   368,   755,   193,  -832,
    -832,  4866,  4886,   756,    59,  4932,  4963,  4995,  5015,  5030,
    3073,  5061,  5092,   230,  5124,   236,   266,   369,  5159,  6186,
    6206,  5190,    74,   377,   134,   394,   395,    75,  -832,  -832,
    -832,    26,    26,  -832,  -832,  -832,  -832,  3247,   906,   915,
     911,  5221,  3247,   399,   760,   286,  -832,  3247,  -832,  -832,
    -832,  -832,  -832,  -832,   761,   762,  6366,  6366,  2369,  -832,
    -832,   274,   274,   496,  6237,  6366,  -832,   881,   886,  3247,
     887,   497,   274,  3247,   733,  -832,  -832,  -832,  -832,  -832,
    -832,  -832,  2369,  -832,  -832,  -832,  -832,  3247,  -832,  -832,
    -832,  -832,  -832,  3247,  -832,  -832,  -832,  2369,  -832,  -832,
    3247,  -832,  3247,  -832,  -832,  -832,  2369,  3247,  -832,  2369,
    -832,  -832,  2369,  -832,  -832,  -832,  3247,  -832,  -832,  -832,
    -832,  -832,   916,   682,  5253,   901,  3247,  2369,  5268,   724,
     767,   770,   724,  -832,  -832,   274,  2369,  2369,  2369,  2369,
    5288,  2369,  3247,  -832,   772,   773,   212,  -832,   404,  6268,
    5319,   405,  5350,  5397,   409,  5417,   418,   423,   504,  3655,
    3973,  3247,   922,  -832,   775,  -832,   777,  6315,   427,  -832,
    -832,  -832,  -832,  -832,   274,   274,   274,   274,   898,   274,
    6366,   778,   779,   733,  -832,  -832,  3247,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  3247,  -832,   911,   938,  1252,
    3655,  -832,  2369,  3247,  3247,  -832,   869,  2369,  -832,  -832,
    -832,  3655,  5448,  6366,  3655,  -832,  -832,   911,   590,   308,
    6335,  5479,   724,   274,    45,  -832,   911,  3655,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  2369,  -832,  3247,  -832,  -832,
    -832,  -832,  -832,   626,   911,   440,  5494,  -832,  -832,  -832,
    -832,  -832,  -832,   973,   916,  -832,  -832,  -832,  -832,  -832
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   118,     0,     0,     0,   329,     0,     0,     0,   112,
     352,   387,   392,    18,     0,     0,     0,     0,    31,    33,
     330,     0,   314,   314,     0,   331,    25,    27,   367,   379,
       0,   460,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     2,     9,    17,
       8,     0,    12,    46,    48,    14,    29,    30,    28,     0,
      20,    21,    24,    23,    22,    35,    36,   302,   209,   140,
     303,   304,   305,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,   269,   272,   275,   278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,   223,   203,   208,   142,     0,     0,     0,     0,
       0,     0,     1,     0,   314,     0,   314,     0,     0,    16,
     307,   306,    37,    38,    45,     0,     0,     0,     0,    19,
      50,   316,    51,    49,   332,    26,     0,    16,   411,     0,
     464,     0,     0,   440,   456,    69,    68,     0,     0,    70,
     111,    60,     0,    62,     0,   432,   434,    63,   430,   436,
       0,     0,   437,   299,    64,    66,     0,    96,     0,     0,
     475,     0,    93,    98,    86,    47,     0,     0,     0,    74,
       0,    57,    79,     0,    95,    94,     0,     0,   121,   122,
      99,    13,    15,   113,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     7,     0,     0,
       0,     0,     0,     0,   321,   314,   314,     0,     0,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
     191,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,   187,     0,
     123,     0,     0,   388,     9,    39,    40,    41,    43,   335,
     336,    32,   333,   341,   342,    34,   339,   319,   320,   315,
     317,   372,   371,     0,     9,     0,    16,     0,     0,     0,
     461,   462,     0,   443,   445,    52,     0,     0,    56,   458,
     314,   314,     0,     0,     0,   314,   314,     0,   301,   300,
       0,     0,    97,   474,     0,     0,     0,    73,     0,    78,
     456,   130,   129,     0,     0,    75,     0,    81,     0,     0,
     138,     0,     0,     0,   102,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,   188,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,   273,
       0,   276,     0,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,   172,     0,     0,     0,
       0,     0,     0,     0,   145,   224,   218,   220,   222,   219,
     221,   216,   217,   144,     0,     0,   196,   198,   200,   197,
     199,   194,   195,   214,   211,   210,   212,   213,   312,   313,
     353,    16,   399,   397,     0,   398,   394,   396,   393,     0,
       0,   314,   314,     0,   314,   314,     0,     0,   369,   373,
     386,   384,   385,   382,   381,   383,   380,   401,     9,     0,
       0,     0,     0,     0,   441,    53,    54,     0,   448,   450,
       0,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,   438,   439,     0,     0,     0,   133,   132,   136,
     227,    58,    76,    89,    80,     0,     0,     0,   314,     0,
       0,     0,   103,   104,   105,   106,   107,   108,     0,     0,
      16,     0,     0,     0,   327,   328,   322,   291,   183,     0,
       0,   282,     0,     0,     0,   292,     0,   293,     0,   286,
       0,     0,   204,   205,     0,     0,     0,     0,   228,   229,
     230,   231,   232,     0,   233,   235,     0,   236,   238,   239,
     201,   245,   246,   240,   242,   243,   244,   241,     0,   248,
     253,     0,     0,     0,   252,     0,     0,   153,     0,   150,
     156,   157,   254,   181,     0,   255,   182,   158,   159,   268,
     271,   274,   277,   162,   160,   161,     0,     0,   163,   261,
     164,   267,   266,     0,   173,   262,   165,   263,   166,   265,
       0,   167,     0,     0,     0,     0,     0,   176,     0,     0,
     178,     0,   298,   186,   192,   190,     0,     9,   395,   476,
      42,   478,    44,     0,     0,   334,     0,     0,   340,   318,
     370,   376,    16,   413,   414,   412,     0,     0,     0,   465,
     463,     0,   446,   444,   445,     0,     0,     0,     0,   426,
     428,   457,   423,   308,   310,   314,   314,     0,     0,   433,
     435,    71,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,   390,
     389,     0,     0,   337,   338,   343,   344,     0,     0,     0,
     402,     0,     0,     0,     0,     0,   442,     0,   449,   451,
     452,   314,   314,   424,     0,     0,    59,    61,     0,   134,
     135,   131,   137,    90,    83,    84,   139,     0,     0,     0,
       0,   116,   117,     0,   345,   280,   281,   283,   284,   285,
     294,   295,     0,   296,   206,   207,   179,     0,   234,   237,
     247,   146,   147,     0,   149,   250,   251,     0,   151,   256,
       0,   257,     0,   259,   174,   168,     0,     0,   185,     0,
     288,   175,     0,   290,   177,   202,     0,   477,   479,   374,
     377,   368,   417,   467,     0,   466,     0,     0,     0,     0,
       0,     0,     0,   309,   311,    72,     0,     0,     0,     0,
       0,     0,     0,    88,   348,   349,     0,   346,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   363,    16,
     118,     0,   415,   471,     0,   468,     0,     0,     0,   454,
     453,   427,   429,   425,    91,    82,   126,   127,     0,   125,
     115,     0,     0,     0,   323,   297,     0,   148,   152,   258,
     260,   264,   184,   287,   289,     0,   354,   375,     9,   421,
      16,   403,     0,     0,     0,   447,   458,     0,   350,   351,
     347,    16,     0,   364,    16,   422,   418,   416,     0,     0,
       0,     0,     0,   124,     9,   180,   355,    16,   410,   407,
     408,   409,   405,   406,   404,     0,   472,     0,   469,   455,
     326,   325,   324,     0,   419,     0,     0,   358,   360,   361,
     362,   357,   359,   365,   417,   473,   470,   366,   356,   420
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -832,  -832,  -832,  -198,  -832,  -832,   975,   281,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,   929,  -271,  -832,  -832,  -184,
     703,  -832,   930,    -2,  -832,  -832,   679,  -305,   113,  -832,
     532,   -33,    -4,  -832,    55,    63,   -14,  -832,  -832,   354,
     990,  -832,  -832,  -832,  -832,  -832,  -832,  -832,   364,  -832,
     362,  -832,   -64,  -832,  -832,  -832,  -832,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,    83,  -832,  -832,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,
    -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,  -832,  -133,
    -832,  -832,  -832,  -831,  -832,  -832,  -832,   545,  -832,  -832,
     169,   538,  -832,  -832,  -832,  -832,  -832,   -77,  -832,    47,
    -832,  -832
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    67,    68,   288,   700,    69,    70,   207,   208,
     629,   630,   224,   470,    71,    72,   473,    73,    74,   481,
     179,   180,    75,   258,   605,   604,   512,   513,   259,   182,
     242,   183,   202,   229,   184,   185,   210,   211,   429,   430,
      78,   497,   870,  1091,  1122,   706,    79,   421,   422,   425,
     426,  1026,  1027,    80,   197,   806,  1094,  1123,  1133,  1076,
    1138,    81,   216,   639,   433,   821,  1039,   919,  1040,    82,
     217,   646,    83,   198,   621,   910,    84,   199,   628,    85,
     435,   822,  1002,  1098,  1114,    86,   436,   825,  1081,  1042,
    1107,  1134,  1096,   841,  1012,   842,   237,   238,   244,   445,
     654,   448,   836,   837,  1009,  1086,   449,   662,   223,   251,
     810,   812
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   414,   515,   478,   479,   928,   929,   243,   405,   212,
     440,   203,   204,   441,   658,   206,   471,   659,    87,   434,
     471,   214,    90,    91,    92,   239,     7,     8,   218,   399,
     200,   226,   215,   201,   230,   232,   234,   245,   464,    87,
     250,   250,   250,    90,    91,    92,   672,   446,   219,   270,
     220,   221,    20,   193,   195,   269,    76,    25,   622,   189,
     623,   250,   624,   257,    77,   388,   192,   190,   289,   290,
    1120,   471,   594,   381,   382,   383,   384,   385,   386,   387,
     291,   908,   264,     7,     8,   625,   277,   996,   626,  1121,
     255,   256,   276,   627,   482,   483,   299,   381,   382,   383,
     384,   385,   386,   387,   397,   398,   399,   278,   189,   909,
     283,   388,   265,   266,   267,   388,   190,   292,   693,   268,
     489,   287,   390,   391,   395,   396,   397,   398,   399,   392,
     393,   394,   395,   396,   397,   398,   399,   388,   390,   391,
     279,  -400,   402,   403,   750,   392,   393,   394,   395,   396,
     397,   398,   399,   388,    58,    59,    60,   388,   390,   391,
     262,   263,   398,   399,   754,   392,   393,   394,   395,   396,
     397,   398,   399,   194,   196,   378,   380,   388,  1050,    53,
     409,  1053,   411,   406,   762,   293,   447,   222,   588,   388,
     590,   408,   388,   388,   490,   294,   413,   716,   472,   717,
     280,   442,   472,   240,   241,   660,   685,   458,   459,   428,
     388,    58,    59,    60,   432,   751,   388,   400,   401,   402,
     403,   444,   702,   703,   240,   241,   796,   407,   797,   381,
     382,   383,   384,   385,   386,   387,   227,   228,   648,   400,
     401,   402,   403,   281,   461,   726,   463,   400,   401,   402,
     403,   399,   194,   472,    76,   381,   382,   383,   384,   385,
     386,   387,    77,   400,   401,   402,   403,   799,   989,   800,
     990,  1119,    76,   196,   400,   401,   402,   403,   485,   295,
      77,   498,   499,   400,   401,   402,   403,   388,   388,   296,
     495,   297,   764,   752,   765,   500,   501,   388,   502,   503,
     504,   505,   250,   250,   767,   235,   236,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   250,   529,
     530,   531,   532,   533,   534,   535,   536,   538,   992,   412,
     993,   388,   298,   544,   545,   547,   549,   550,   768,   552,
     300,   554,   396,   397,   398,   399,   576,   577,   388,   388,
     388,   508,   509,   388,   753,   594,   250,   769,   783,   388,
     784,   579,   400,   401,   402,   403,   770,   528,   415,   416,
     388,   388,   301,   469,   388,   790,   828,   791,   829,   475,
     477,    89,   388,   388,   419,   420,    93,   962,   776,   963,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   492,   493,   494,   574,  1063,    95,  1064,   655,
     656,   381,   382,   383,   384,   385,   386,   387,   302,   388,
     303,   516,   388,   807,   977,   388,   978,   243,   388,   771,
     980,   388,   981,   777,   388,   649,   663,   664,   772,   792,
     652,   669,   670,   381,   382,   383,   384,   385,   386,   387,
     304,   667,   668,   305,   388,   388,   400,   401,   402,   403,
     982,   773,   983,   388,   679,   306,   680,   307,   381,   382,
     383,   384,   385,   386,   387,   388,   686,   687,   308,   388,
    1007,   107,   594,   108,   793,   695,   697,   698,   699,   309,
     902,    76,   310,   904,   388,   311,   640,   388,   641,    77,
     642,   774,  1115,   438,  1116,   388,   388,   312,   130,   131,
     132,   480,   775,   778,   136,   137,   138,  1075,   140,   388,
     142,   143,   144,   643,   794,   452,   644,   149,   150,   151,
     388,   645,   154,   388,   156,   388,   158,   757,   388,   160,
     779,   162,   780,   313,   164,   787,   314,   166,   167,   388,
     168,   169,   388,   171,   388,   173,   789,   388,   388,   802,
     457,   803,   388,   176,   960,   984,   388,   390,   391,   781,
     315,   186,   557,   991,   392,   393,   394,   395,   396,   397,
     398,   399,   316,   388,   388,   317,   682,   388,   388,   684,
     994,   995,   487,   388,   388,  1005,   318,   953,   388,   491,
    1065,  1068,   804,   805,  1108,  1071,  1109,   388,  1110,   417,
     418,   319,   388,   967,  1073,   320,   388,   813,   814,  1074,
     816,   817,   808,  1085,   920,   809,   811,   388,   388,   388,
     321,  1111,   795,   798,  1112,   428,  1135,   322,   388,  1113,
    1127,    87,  1128,   801,  1129,    90,    91,    92,   827,   423,
     424,   388,   390,   391,   834,   835,   854,   460,   838,   392,
     393,   394,   395,   396,   397,   398,   399,  1130,   388,   323,
    1131,   324,   851,   856,   860,  1132,    76,   393,   394,   395,
     396,   397,   398,   399,    77,   388,   388,   861,   862,   863,
    1016,  1022,   400,   401,   402,   403,   510,   511,   325,   867,
       1,     2,     3,     4,     5,   326,   187,   871,   872,   327,
     873,   874,   875,   665,   666,   675,   676,   704,   705,   823,
     824,   328,   881,   882,   209,   884,   329,   213,   839,   840,
     330,   885,   917,   918,   886,   331,   225,  1024,  1025,   332,
     231,   233,  1043,  1044,   333,   249,   887,   334,   335,   888,
     889,   890,   336,   891,   892,    76,   337,   273,   274,   275,
     338,   339,   894,    77,   340,   341,   282,   284,   285,   286,
     342,   343,   344,   345,   346,   347,   348,   400,   401,   402,
     403,   349,   350,   351,   399,   620,   352,   353,   898,   354,
     899,   900,   901,   355,   400,   401,   402,   403,   857,   356,
     357,   638,   358,   359,   907,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   868,   869,   393,   370,   395,
     396,   397,   398,   399,   921,   371,   372,   373,   374,   375,
     376,   934,   935,   585,   377,   437,   439,   450,   451,   883,
     465,  1077,  1078,   389,   455,   936,   937,   456,   466,   474,
     250,   250,   488,   586,   633,   618,   944,   945,   619,   631,
     632,   634,   390,   391,   635,   636,   637,   647,   650,   392,
     393,   394,   395,   396,   397,   398,   399,    76,   657,   661,
     688,   379,  1097,   689,   690,    77,   820,   707,   691,   404,
     701,   708,   720,  1104,   715,   718,  1106,   721,   410,   939,
     940,   719,   722,   852,   723,   724,   725,   997,   998,  1124,
     740,   782,   785,   786,   427,   432,   843,  1010,  1011,   431,
    1004,   844,   845,   846,   853,  1008,   443,   849,   850,   511,
     879,   880,   911,   912,   400,   401,   402,   403,   913,   914,
     915,   916,   924,   931,   932,   933,   946,  1020,   954,  1000,
     462,   961,   966,  1001,    -9,  1006,  1018,  1013,  1014,  1046,
     467,  1019,  1021,  1051,  1041,  1029,  1052,  1061,  1062,  1080,
    1082,  1030,  1083,  1087,  1088,  1089,  -378,  1137,  1032,   188,
    1033,   866,   271,   272,   486,  1035,   514,   400,   401,   402,
     403,   819,   673,   653,  1038,   191,   496,   815,   818,  1090,
     999,  1139,   671,   926,  1047,   390,   391,   507,   681,  1102,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
    1060,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   539,   540,   541,   542,   543,     0,  1079,
     546,     0,     0,   551,     0,   553,     0,   555,   556,   558,
     560,   562,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   575,     0,  1092,   578,  1023,   580,   581,   582,
     583,   584,     0,  1093,   587,     0,   589,     0,   591,   592,
     593,  1100,  1101,     0,   596,   597,   598,   599,   600,   601,
     602,   603,     0,     0,    76,    76,     0,     0,     0,     0,
       0,     0,    77,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1126,     0,     0,     0,     0,
      87,    88,    89,     0,    90,    91,    92,    93,     0,     0,
     400,   401,   402,   403,     0,    76,     0,     0,     0,     0,
       0,     0,   651,    77,     0,     0,    76,    94,    95,    76,
       0,     0,     0,     0,    77,     0,     0,    77,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,   678,     0,
      77,     0,     0,     0,     0,     0,     0,   683,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     694,   696,     0,     0,     0,     0,     0,     0,   103,     0,
       0,   104,     0,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,   105,   106,
       0,     0,   107,     0,   108,     0,     0,   254,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,  1095,     0,
       0,     0,     0,   175,   176,   177,     0,     0,     0,     0,
       0,     0,   178,     0,   248,   390,   391,     0,     0,     0,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
     427,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   832,     0,     0,   833,
       0,     0,     0,     0,     0,     0,     0,   390,   391,     0,
       0,     0,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,   390,   391,     0,     0,     0,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   876,
       0,   878,     0,     0,   390,   391,     0,     0,     0,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   893,    87,    88,    89,     0,    90,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   895,
     896,     0,     0,     0,     0,     0,   897,     0,     0,    94,
      95,     0,   400,   401,   402,   403,     0,     0,   733,   903,
     734,     0,   905,     0,   906,     0,     0,   400,   401,   402,
     403,     0,     0,   736,     0,   737,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   923,     0,     0,   925,     0,     0,     0,     0,     0,
     103,     0,     0,   104,     0,     0,     0,     0,   246,   400,
     401,   402,   403,     0,     0,   453,   247,   941,   942,   943,
     105,   106,     0,     0,   107,     0,   108,   951,   952,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     431,   159,   160,   161,   162,     0,   163,   164,     0,   165,
     166,   167,     0,   168,   169,   170,   171,   172,   173,   174,
       0,  1015,     0,     0,     0,   175,   176,   177,     0,     0,
       0,     0,     0,     0,   178,     0,   248,     0,     0,     0,
       0,     0,     0,     0,     0,  1028,     0,     0,     0,     0,
       0,     0,     0,     0,   390,   391,     0,     0,     0,     0,
    1031,   392,   393,   394,   395,   396,   397,   398,   399,  1034,
       0,     0,  1036,     0,     0,  1037,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1048,    87,    88,    89,     0,    90,    91,    92,    93,  1054,
    1055,  1056,  1057,     0,  1059,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,  1099,     0,     0,     0,   103,
    1103,    89,   104,     0,     0,     0,    93,     0,     0,   400,
     401,   402,   403,     0,     0,   506,     0,   595,     0,   105,
     106,     0,     0,   107,     0,   108,     0,    95,  1125,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,     0,
       0,   107,     0,   108,   175,   176,   177,     0,     0,     0,
       0,     0,     0,   178,     0,   248,    87,    88,    89,     0,
      90,    91,    92,    93,     0,     0,     0,     0,   130,   131,
     132,     0,     0,     0,   136,   137,   138,     0,   140,     0,
     142,   143,   144,    94,    95,     0,     0,   149,   150,   151,
       0,     0,   154,     0,   156,     0,   158,     0,     0,   160,
       0,   162,     0,     0,   164,     0,     0,   166,   167,     0,
     168,   169,     0,   171,     0,   173,    96,    97,    98,    99,
     100,   101,   102,   176,     0,     0,     0,     0,     0,     0,
       0,   186,   559,     0,   103,     0,    89,   104,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,     0,   107,     0,
     108,     0,    95,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,   159,   160,   161,   162,     0,
     163,   164,     0,   165,   166,   167,     0,   168,   169,   170,
     171,   172,   173,   174,     0,     0,   107,     0,   108,   175,
     176,   177,     0,     0,     0,     0,     0,     0,   178,     0,
     248,    87,    88,    89,     0,    90,    91,    92,    93,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,   136,
     137,   138,     0,   140,     0,   142,   143,   144,    94,    95,
       0,     0,   149,   150,   151,     0,     0,   154,     0,   156,
       0,   158,     0,     0,   160,     0,   162,     0,     0,   164,
       0,     0,   166,   167,     0,   168,   169,     0,   171,     0,
     173,    96,    97,    98,    99,   100,   101,   102,   176,     0,
       0,     0,     0,     0,     0,     0,   186,   561,     0,   103,
      89,     0,   104,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,    95,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,     0,
     107,     0,   108,     0,   175,   176,   177,     0,     0,     0,
       0,     0,     0,   178,   484,    87,    88,    89,     0,    90,
      91,    92,    93,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,     0,   140,     0,   142,
     143,   144,    94,    95,     0,     0,   149,   150,   151,     0,
       0,   154,     0,   156,     0,   158,     0,     0,   160,     0,
     162,     0,     0,   164,     0,     0,   166,   167,     0,   168,
     169,     0,   171,     0,   173,    96,    97,    98,    99,   100,
     101,   102,   176,     0,     0,     0,     0,     0,     0,     0,
     186,   563,     0,   103,    89,     0,   104,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,   107,     0,   108,
      95,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,     0,   163,
     164,     0,   165,   166,   167,     0,   168,   169,   170,   171,
     172,   173,   174,     0,   107,     0,   108,     0,   175,   176,
     177,     0,     0,     0,     0,     0,     0,   178,   537,    87,
      88,    89,     0,    90,    91,    92,    93,     0,     0,     0,
       0,   130,   131,   132,     0,     0,     0,   136,   137,   138,
       0,   140,     0,   142,   143,   144,    94,    95,     0,     0,
     149,   150,   151,     0,     0,   154,     0,   156,     0,   158,
       0,     0,   160,     0,   162,     0,     0,   164,     0,     0,
     166,   167,     0,   168,   169,     0,   171,     0,   173,    96,
      97,    98,    99,   100,   101,   102,   176,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,   103,    89,     0,
     104,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,     0,
       0,   107,     0,   108,    95,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,   159,   160,
     161,   162,     0,   163,   164,     0,   165,   166,   167,     0,
     168,   169,   170,   171,   172,   173,   174,     0,   107,     0,
     108,     0,   175,   176,   177,     0,     0,     0,     0,     0,
       0,   178,   548,    87,    88,    89,     0,    90,    91,    92,
      93,     0,   260,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
      94,    95,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,     0,   162,     0,
       0,   164,     0,   261,   166,   167,     0,   168,   169,     0,
     171,     0,   173,    96,    97,    98,    99,   100,   101,   102,
     176,     0,     0,     0,     0,     0,     0,     0,   831,   390,
     391,   103,     0,     0,   104,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,     0,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,   177,     0,
       0,     0,    87,    88,    89,   178,    90,    91,    92,    93,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
     758,     0,   759,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   390,   391,     0,
     103,     0,     0,   104,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,     0,     0,   107,     0,   108,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,   159,   160,   161,   162,     0,   163,   164,     0,   165,
     166,   167,     0,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,   175,   176,   177,     0,     0,
       0,    87,    88,    89,   178,    90,    91,    92,    93,     0,
     476,     0,   400,   401,   402,   403,     0,     0,   949,     0,
     950,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,   390,   391,     0,   103,
       0,     0,   104,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,   175,   176,   177,     0,     0,     0,
      87,    88,    89,   178,    90,    91,    92,    93,     0,     0,
       0,   400,   401,   402,   403,     0,     0,   973,     0,   974,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,   390,   391,     0,   103,     0,
       0,   104,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,     0,   107,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,   175,   176,   177,    93,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,     0,     0,     0,    95,   692,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   677,     0,     0,     0,     0,     0,     0,
       0,   107,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,     0,     0,     0,   136,   137,   138,     0,   140,     0,
     142,   143,   144,     0,     0,   877,     0,   149,   150,   151,
       0,     0,   154,   107,   156,   108,   158,     0,     0,   160,
       0,   162,     0,     0,   164,     0,     0,   166,   167,     0,
     168,   169,     0,   171,     0,   173,     0,     0,     0,     0,
     130,   131,   132,   176,     0,     0,   136,   137,   138,     0,
     140,   186,   142,   143,   144,     0,     0,     0,     0,   149,
     150,   151,     0,     0,   154,     0,   156,     0,   158,     0,
       0,   160,     0,   162,     0,     0,   164,     0,     0,   166,
     167,     0,   168,   169,     0,   171,     0,   173,     0,     7,
       8,     9,     0,     0,     0,   176,    10,     0,     0,     0,
      11,     0,    12,   186,    13,    14,    15,    16,    17,  -329,
       0,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    29,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,  -118,  -118,    48,
      49,    50,     0,    51,    52,    53,     0,     0,    54,  -118,
     390,    55,     0,    56,    57,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,    63,     0,     7,     8,
       9,    64,     0,     0,    65,    10,     0,     0,    66,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -329,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,   -16,   -16,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,     0,     0,
      55,     0,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,    63,     0,     7,     8,     9,
      64,     0,     0,    65,    10,     0,     0,    66,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -329,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,   -16,     0,     0,     0,    29,   -16,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,   390,   391,     0,    37,    38,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,   390,   391,    55,
       0,    56,    57,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,   390,   391,
       0,     0,    61,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
     390,   391,    65,     0,     0,     0,    66,   392,   393,   394,
     395,   396,   397,   398,   399,     0,   400,   401,   402,   403,
     390,   391,     0,     0,   711,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,   390,   391,     0,     0,     0,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,     0,     0,
     728,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   390,   391,     0,
       0,   729,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   390,
     391,     0,     0,   730,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   731,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,     0,     0,   732,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,     0,     0,   735,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,     0,     0,
     738,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   390,   391,
       0,     0,   739,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,   390,   391,     0,     0,     0,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,   400,
     401,   402,   403,   390,   391,     0,     0,   741,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,     0,     0,   742,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,     0,     0,   743,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   744,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,     0,     0,   745,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,   400,   401,
     402,   403,   390,   391,     0,     0,   746,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   390,   391,     0,     0,   747,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,     0,     0,   749,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,   390,
     391,     0,     0,     0,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   390,   391,     0,     0,   760,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   400,   401,   402,
     403,   390,   391,     0,     0,   761,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,     0,     0,   763,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   766,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   390,   391,
       0,     0,   788,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     390,   391,     0,     0,   830,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,   400,   401,   402,   403,
     390,   391,     0,     0,   930,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   390,   391,     0,     0,   947,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,   390,   391,     0,     0,
       0,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   390,   391,     0,
       0,   948,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   390,
     391,     0,     0,   955,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,   400,   401,   402,   403,   390,
     391,     0,     0,   956,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   957,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,     0,     0,   958,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,     0,     0,
     959,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   390,   391,
       0,     0,   964,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,   400,   401,   402,   403,   390,   391,
       0,     0,   965,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,   390,   391,     0,     0,     0,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,     0,     0,   968,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,     0,     0,   969,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   390,   391,     0,
       0,   970,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   971,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,     0,     0,   972,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   390,   391,     0,     0,   975,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,     0,     0,   976,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,     0,     0,
     979,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,   390,   391,     0,     0,     0,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,   400,   401,   402,
     403,   390,   391,     0,     0,   985,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,     0,     0,   988,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   390,   391,     0,     0,  1003,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,     0,     0,     0,     0,  1045,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     390,   391,     0,     0,  1049,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,   400,   401,   402,   403,
     390,   391,     0,     0,  1058,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   390,   391,     0,     0,  1067,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,     0,     0,  1069,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,   390,   391,     0,
       0,     0,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   390,
     391,     0,     0,  1070,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,   400,   401,   402,   403,   390,
     391,     0,     0,  1072,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     390,   391,     0,     0,  1105,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,  1118,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,     0,     0,
    1136,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   390,   391,
     454,     0,     0,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,   400,   401,   402,   403,   390,   391,
     468,     0,     0,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   390,
     391,   674,     0,     0,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,   390,   391,     0,     0,     0,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,   709,     0,     0,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,   390,   391,   710,
       0,     0,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,   400,   401,   402,   403,   390,   391,   712,
       0,     0,     0,     0,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
     713,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   390,   391,   714,     0,     0,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,   727,     0,     0,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   390,   391,   748,     0,
       0,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,     0,   400,   401,   402,   403,   390,   391,   755,     0,
       0,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,   390,   391,     0,     0,     0,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,   756,     0,     0,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,   390,   391,   826,     0,     0,     0,     0,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,   402,   403,   390,   391,   847,     0,     0,
       0,     0,   392,   393,   394,   395,   396,   397,   398,   399,
       0,   400,   401,   402,   403,     0,     0,   848,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     390,   391,   855,     0,     0,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   390,   391,   858,     0,     0,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   390,   391,   859,     0,     0,     0,     0,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   390,   391,   864,     0,     0,     0,
       0,   392,   393,   394,   395,   396,   397,   398,   399,   390,
     391,     0,     0,     0,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,   400,   401,   402,   403,   390,
     391,   865,     0,     0,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
     390,   391,   922,     0,     0,     0,     0,   392,   393,   394,
     395,   396,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   390,   391,   927,     0,     0,     0,     0,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,   938,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403,   390,   391,
     986,     0,     0,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,   400,   401,   402,   403,   390,   391,
     987,     0,     0,     0,     0,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,   402,   403,   390,
     391,  1017,     0,     0,     0,     0,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,  1066,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,  1117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,   401,   402,   403
};

static const yytype_int16 yycheck[] =
{
       2,   199,   307,   274,   275,   836,   837,    40,    44,    23,
       4,    15,    16,     7,     4,    17,    12,     7,     3,   217,
      12,    28,     7,     8,     9,    10,     4,     5,    30,    77,
       4,    33,     7,     7,    36,    37,    38,    41,    11,     3,
      42,    43,    44,     7,     8,     9,    10,    58,    58,    51,
      60,    61,    28,    75,    75,    95,     1,    33,    14,     4,
      16,    63,    18,    88,     1,   189,     0,     4,    92,    93,
      25,    12,   196,    70,    71,    72,    73,    74,    75,    76,
     104,    16,    59,     4,     5,    41,   195,    12,    44,    44,
      43,    44,   110,    49,   278,   279,    98,    70,    71,    72,
      73,    74,    75,    76,    75,    76,    77,   195,    53,    44,
      63,   189,    89,    90,    91,   189,    53,    75,   196,    96,
     194,    44,    63,    64,    73,    74,    75,    76,    77,    70,
      71,    72,    73,    74,    75,    76,    77,   189,    63,    64,
     195,    46,   190,   191,   196,    70,    71,    72,    73,    74,
      75,    76,    77,   189,   132,   133,   134,   189,    63,    64,
      47,    48,    76,    77,   196,    70,    71,    72,    73,    74,
      75,    76,    77,   195,   195,   177,   178,   189,  1009,   100,
     194,  1012,   196,    44,   196,    75,   197,   197,   372,   189,
     374,   193,   189,   189,   194,    24,   198,   194,   194,   196,
     195,   195,   194,   188,   189,   195,   477,   240,   241,   211,
     189,   132,   133,   134,   216,   194,   189,   188,   189,   190,
     191,   223,   493,   494,   188,   189,   194,    44,   196,    70,
      71,    72,    73,    74,    75,    76,     4,     5,   436,   188,
     189,   190,   191,   195,   246,   516,   248,   188,   189,   190,
     191,    77,   195,   194,   199,    70,    71,    72,    73,    74,
      75,    76,   199,   188,   189,   190,   191,   194,   194,   196,
     196,  1102,   217,   195,   188,   189,   190,   191,   280,   195,
     217,   295,   296,   188,   189,   190,   191,   189,   189,   195,
     292,   195,   194,   194,   196,   297,   298,   189,   300,   301,
     302,   303,   304,   305,   196,     4,     5,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   194,     4,
     196,   189,   195,   335,   336,   337,   338,   339,   196,   341,
     195,   343,    74,    75,    76,    77,   360,   361,   189,   189,
     189,   304,   305,   189,   194,   196,   358,   196,   194,   189,
     196,   363,   188,   189,   190,   191,   196,   320,    35,    36,
     189,   189,   195,   260,   189,   194,   194,   196,   196,   266,
     267,     5,   189,   189,     4,     5,    10,   194,   194,   196,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   289,   290,   291,   358,   194,    31,   196,   193,
     194,    70,    71,    72,    73,    74,    75,    76,   195,   189,
     195,   308,   189,   621,   194,   189,   196,   460,   189,   196,
     194,   189,   196,   194,   189,   437,   450,   451,   196,   194,
     442,   455,   456,    70,    71,    72,    73,    74,    75,    76,
     195,   453,   454,   195,   189,   189,   188,   189,   190,   191,
     194,   196,   196,   189,   466,   195,   468,   195,    70,    71,
      72,    73,    74,    75,    76,   189,   478,   479,   195,   189,
     194,   105,   196,   107,   194,   487,   488,   489,   490,   195,
     795,   436,   195,   798,   189,   195,    14,   189,    16,   436,
      18,   196,   194,    58,   196,   189,   189,   195,   132,   133,
     134,     5,   196,   196,   138,   139,   140,    13,   142,   189,
     144,   145,   146,    41,   194,   194,    44,   151,   152,   153,
     189,    49,   156,   189,   158,   189,   160,   196,   189,   163,
     196,   165,   196,   195,   168,   196,   195,   171,   172,   189,
     174,   175,   189,   177,   189,   179,   196,   189,   189,   196,
     194,   196,   189,   187,   196,   196,   189,    63,    64,   196,
     195,   195,   196,   196,    70,    71,    72,    73,    74,    75,
      76,    77,   195,   189,   189,   195,   473,   189,   189,   476,
     196,   196,   194,   189,   189,   196,   195,   868,   189,    43,
     196,   196,   604,   605,    14,   196,    16,   189,    18,    20,
      21,   195,   189,   884,   196,   195,   189,   631,   632,   196,
     634,   635,   624,   196,   822,   629,   630,   189,   189,   189,
     195,    41,   194,   194,    44,   637,   196,   195,   189,    49,
      14,     3,    16,   194,    18,     7,     8,     9,   650,     4,
       5,   189,    63,    64,   656,   657,   194,   194,   660,    70,
      71,    72,    73,    74,    75,    76,    77,    41,   189,   195,
      44,   195,   674,   194,   688,    49,   621,    71,    72,    73,
      74,    75,    76,    77,   621,   189,   189,   689,   690,   691,
     194,   194,   188,   189,   190,   191,     4,     5,   195,   701,
     181,   182,   183,   184,   185,   195,     3,   709,   710,   195,
     712,   713,   714,     4,     5,    86,    87,     4,     5,    49,
      50,   195,   724,   725,    21,   727,   195,    24,     4,     5,
     195,   733,    39,    40,   736,   195,    33,     4,     5,   195,
      37,    38,    60,    61,   195,    42,   748,   195,   195,   751,
     752,   753,   195,   755,   756,   700,   195,    54,    55,    56,
     195,   195,   764,   700,   195,   195,    63,    64,    65,    66,
     195,   195,   195,   195,   195,   195,   195,   188,   189,   190,
     191,   195,   195,   195,    77,    75,   195,   195,   790,   195,
     792,   793,   794,   195,   188,   189,   190,   191,   685,   195,
     195,    43,   195,   195,   806,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   702,   703,    71,   195,    73,
      74,    75,    76,    77,   826,   195,   195,   195,   195,   195,
     195,   845,   846,   196,   195,   195,   195,   195,   195,   726,
     194,  1039,  1040,    44,   195,   847,   848,   195,   194,   194,
     852,   853,   194,   196,   194,   196,   858,   859,   196,   195,
     195,   195,    63,    64,   195,   194,   194,    46,   195,    70,
      71,    72,    73,    74,    75,    76,    77,   822,   195,    10,
     195,   178,  1080,   194,   194,   822,    43,   196,   194,   186,
     194,   196,   195,  1091,   196,   194,  1094,   195,   195,   852,
     853,   196,   196,    85,   196,   194,   194,   911,   912,  1107,
     196,   196,   196,   196,   211,   917,   196,   931,   932,   216,
     922,   196,   195,   195,    85,   927,   223,   196,   196,     5,
     196,   196,   194,   194,   188,   189,   190,   191,   196,   196,
     196,   196,    58,   195,   195,   194,   196,   949,   195,    43,
     247,   196,   196,    38,    43,   195,    75,   196,   196,    58,
     257,    75,    75,   196,    48,   967,   196,   195,   195,    47,
     195,   973,   195,    75,   196,   196,    38,     4,   980,     4,
     982,   700,    53,    53,   281,   987,   307,   188,   189,   190,
     191,   637,   460,    51,   996,     5,   293,   633,   636,  1063,
     917,  1134,   457,   834,  1006,    63,    64,   304,   470,  1086,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
    1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   330,   331,   332,   333,   334,    -1,  1041,
     337,    -1,    -1,   340,    -1,   342,    -1,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,    -1,  1066,   362,   953,   364,   365,   366,
     367,   368,    -1,  1075,   371,    -1,   373,    -1,   375,   376,
     377,  1083,  1084,    -1,   381,   382,   383,   384,   385,   386,
     387,   388,    -1,    -1,  1039,  1040,    -1,    -1,    -1,    -1,
      -1,    -1,  1039,  1040,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
     188,   189,   190,   191,    -1,  1080,    -1,    -1,    -1,    -1,
      -1,    -1,   439,  1080,    -1,    -1,  1091,    30,    31,  1094,
      -1,    -1,    -1,    -1,  1091,    -1,    -1,  1094,    -1,    -1,
      -1,    -1,  1107,    -1,    -1,    -1,    -1,    -1,   465,    -1,
    1107,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
     487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,    -1,   167,   168,    -1,   170,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,   180,    46,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,    -1,   656,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   716,
      -1,   718,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   758,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,
     777,    -1,    -1,    -1,    -1,    -1,   783,    -1,    -1,    30,
      31,    -1,   188,   189,   190,   191,    -1,    -1,   194,   796,
     196,    -1,   799,    -1,   801,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,   194,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,   828,    -1,    -1,   831,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,   188,
     189,   190,   191,    -1,    -1,   194,    97,   854,   855,   856,
     101,   102,    -1,    -1,   105,    -1,   107,   864,   865,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     917,   162,   163,   164,   165,    -1,   167,   168,    -1,   170,
     171,   172,    -1,   174,   175,   176,   177,   178,   179,   180,
      -1,   938,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
     977,    70,    71,    72,    73,    74,    75,    76,    77,   986,
      -1,    -1,   989,    -1,    -1,   992,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1007,     3,     4,     5,    -1,     7,     8,     9,    10,  1016,
    1017,  1018,  1019,    -1,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1082,    -1,    -1,    -1,    81,
    1087,     5,    84,    -1,    -1,    -1,    10,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    97,    -1,   196,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    31,  1115,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   105,    -1,   107,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    30,    31,    -1,    -1,   151,   152,   153,
      -1,    -1,   156,    -1,   158,    -1,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,    -1,
     174,   175,    -1,   177,    -1,   179,    63,    64,    65,    66,
      67,    68,    69,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,    -1,    81,    -1,     5,    84,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    31,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,    -1,
     167,   168,    -1,   170,   171,   172,    -1,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,   105,    -1,   107,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    30,    31,
      -1,    -1,   151,   152,   153,    -1,    -1,   156,    -1,   158,
      -1,   160,    -1,    -1,   163,    -1,   165,    -1,    -1,   168,
      -1,    -1,   171,   172,    -1,   174,   175,    -1,   177,    -1,
     179,    63,    64,    65,    66,    67,    68,    69,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    81,
       5,    -1,    84,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    31,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
     105,    -1,   107,    -1,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,   144,
     145,   146,    30,    31,    -1,    -1,   151,   152,   153,    -1,
      -1,   156,    -1,   158,    -1,   160,    -1,    -1,   163,    -1,
     165,    -1,    -1,   168,    -1,    -1,   171,   172,    -1,   174,
     175,    -1,   177,    -1,   179,    63,    64,    65,    66,    67,
      68,    69,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    81,     5,    -1,    84,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      31,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,    -1,   167,
     168,    -1,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,   180,    -1,   105,    -1,   107,    -1,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,    -1,   144,   145,   146,    30,    31,    -1,    -1,
     151,   152,   153,    -1,    -1,   156,    -1,   158,    -1,   160,
      -1,    -1,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,
     171,   172,    -1,   174,   175,    -1,   177,    -1,   179,    63,
      64,    65,    66,    67,    68,    69,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    81,     5,    -1,
      84,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    31,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,   162,   163,
     164,   165,    -1,   167,   168,    -1,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,   180,    -1,   105,    -1,
     107,    -1,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    12,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
      30,    31,    -1,    -1,   151,   152,   153,    -1,    -1,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,   168,    -1,    53,   171,   172,    -1,   174,   175,    -1,
     177,    -1,   179,    63,    64,    65,    66,    67,    68,    69,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    63,
      64,    81,    -1,    -1,    84,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,    -1,   167,   168,    -1,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,     3,     4,     5,   195,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
     194,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      81,    -1,    -1,    84,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,   162,   163,   164,   165,    -1,   167,   168,    -1,   170,
     171,   172,    -1,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,     3,     4,     5,   195,     7,     8,     9,    10,    -1,
      12,    -1,   188,   189,   190,   191,    -1,    -1,   194,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,
      -1,    -1,    84,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
       3,     4,     5,   195,     7,     8,     9,    10,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,    -1,   194,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,
      -1,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,    -1,   167,   168,    -1,   170,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,     5,    -1,   186,   187,   188,    10,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    31,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    -1,    97,    -1,   151,   152,   153,
      -1,    -1,   156,   105,   158,   107,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,    -1,
     174,   175,    -1,   177,    -1,   179,    -1,    -1,    -1,    -1,
     132,   133,   134,   187,    -1,    -1,   138,   139,   140,    -1,
     142,   195,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,
      -1,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,   171,
     172,    -1,   174,   175,    -1,   177,    -1,   179,    -1,     4,
       5,     6,    -1,    -1,    -1,   187,    11,    -1,    -1,    -1,
      15,    -1,    17,   195,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      63,   106,    -1,   108,   109,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,    -1,     4,     5,
       6,   166,    -1,    -1,   169,    11,    -1,    -1,   173,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,     4,     5,     6,
     166,    -1,    -1,   169,    11,    -1,    -1,   173,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    63,    64,    -1,    61,    62,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    63,    64,   106,
      -1,   108,   109,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    63,    64,
      -1,    -1,   139,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,
      63,    64,   169,    -1,    -1,    -1,   173,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,    -1,    -1,
     196,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    63,    64,    -1,
      -1,   196,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,
      64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,    -1,    -1,   196,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,    -1,    -1,   196,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,    -1,    -1,
     196,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,    64,
      -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   188,
     189,   190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,    -1,    -1,   196,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,    -1,    -1,   196,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,    -1,    -1,   196,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   188,   189,   190,
     191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,    64,
      -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    63,    64,    -1,
      -1,   196,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,
      64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   188,   189,   190,   191,    63,
      64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,    -1,    -1,   196,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,    -1,    -1,
     196,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,    64,
      -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   188,   189,   190,   191,    63,    64,
      -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,    -1,    -1,   196,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,    -1,    -1,   196,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    63,    64,    -1,
      -1,   196,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,    -1,    -1,   196,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,    -1,    -1,
     196,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   188,   189,   190,
     191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,    -1,    -1,   196,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,
      64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   188,   189,   190,   191,    63,
      64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      63,    64,    -1,    -1,   196,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,    -1,    -1,
     196,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,    64,
     194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   188,   189,   190,   191,    63,    64,
     194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,
      64,   194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,   194,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    63,    64,   194,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   188,   189,   190,   191,    63,    64,   194,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    63,    64,   194,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,   194,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    63,    64,   194,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   188,   189,   190,   191,    63,    64,   194,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,   194,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    63,    64,   194,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    63,    64,   194,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   188,   189,   190,   191,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      63,    64,   194,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    63,    64,   194,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    63,    64,   194,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    63,    64,   194,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   188,   189,   190,   191,    63,
      64,   194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      63,    64,   194,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    63,    64,   194,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,    64,
     194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   188,   189,   190,   191,    63,    64,
     194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    63,
      64,   194,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   191
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   181,   182,   183,   184,   185,   199,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   157,   161,   166,   169,   173,   200,   201,   204,
     205,   212,   213,   215,   216,   220,   232,   233,   238,   244,
     251,   259,   267,   270,   274,   277,   283,     3,     4,     5,
       7,     8,     9,    10,    30,    31,    63,    64,    65,    66,
      67,    68,    69,    81,    84,   101,   102,   105,   107,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   162,
     163,   164,   165,   167,   168,   170,   171,   172,   174,   175,
     176,   177,   178,   179,   180,   186,   187,   188,   195,   218,
     219,   221,   227,   229,   232,   233,   195,   218,   204,   232,
     233,   238,     0,    75,   195,    75,   195,   252,   271,   275,
       4,     7,   230,   230,   230,    34,   221,   206,   207,   218,
     234,   235,   234,   218,    28,     7,   260,   268,   221,    58,
      60,    61,   197,   306,   210,   218,   221,     4,     5,   231,
     221,   218,   221,   218,   221,     4,     5,   294,   295,    10,
     188,   189,   228,   229,   296,   230,    89,    97,   197,   218,
     221,   307,    89,    97,   110,   307,   307,    88,   221,   226,
      12,    53,   226,   226,    59,    89,    90,    91,    96,    95,
     221,   213,   220,   218,   218,   218,   110,   195,   195,   195,
     195,   195,   218,   307,   218,   218,   218,    44,   202,    92,
      93,   104,    75,    75,    24,   195,   195,   195,   195,   221,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   221,   218,
     221,    70,    71,    72,    73,    74,    75,    76,   189,    44,
      63,    64,    70,    71,    72,    73,    74,    75,    76,    77,
     188,   189,   190,   191,   218,    44,    44,    44,   221,   234,
     218,   234,     4,   221,   201,    35,    36,    20,    21,     4,
       5,   245,   246,     4,     5,   247,   248,   218,   221,   236,
     237,   218,   221,   262,   201,   278,   284,   195,    58,   195,
       4,     7,   195,   218,   221,   297,    58,   197,   299,   304,
     195,   195,   194,   194,   194,   195,   195,   194,   229,   229,
     194,   221,   218,   221,    11,   194,   194,   218,   194,   226,
     211,    12,   194,   214,   194,   226,    12,   226,   214,   214,
       5,   217,   217,   217,   196,   221,   218,   194,   194,   194,
     194,    43,   226,   226,   226,   221,   218,   239,   234,   234,
     221,   221,   221,   221,   221,   221,    97,   218,   307,   307,
       4,     5,   224,   225,   224,   225,   226,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   307,   221,
     221,   221,   221,   221,   221,   221,   221,   196,   221,   218,
     218,   218,   218,   218,   221,   221,   218,   221,   196,   221,
     221,   218,   221,   218,   221,   218,   218,   196,   218,   196,
     218,   196,   218,   196,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   307,   218,   234,   234,   218,   221,
     218,   218,   218,   218,   218,   196,   196,   218,   217,   218,
     217,   218,   218,   218,   196,   196,   218,   218,   218,   218,
     218,   218,   218,   218,   223,   222,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   196,   196,
      75,   272,    14,    16,    18,    41,    44,    49,   276,   208,
     209,   195,   195,   194,   195,   195,   194,   194,    43,   261,
      14,    16,    18,    41,    44,    49,   269,    46,   201,   221,
     195,   218,   221,    51,   298,   193,   194,   195,     4,     7,
     195,    10,   305,   234,   234,     4,     5,   221,   221,   234,
     234,   295,    10,   228,   194,    86,    87,    97,   218,   221,
     221,   299,   226,   218,   226,   214,   221,   221,   195,   194,
     194,   194,   196,   196,   218,   221,   218,   221,   221,   221,
     203,   194,   214,   214,     4,     5,   243,   196,   196,   194,
     194,   196,   194,   194,   194,   196,   194,   196,   194,   196,
     195,   195,   196,   196,   194,   194,   214,   194,   196,   196,
     196,   196,   196,   194,   196,   196,   194,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   194,   196,
     196,   194,   194,   194,   196,   194,   194,   196,   194,   196,
     196,   196,   196,   196,   194,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   194,   194,   196,   196,
     196,   196,   196,   194,   196,   196,   196,   196,   196,   196,
     194,   196,   194,   194,   194,   194,   194,   196,   194,   194,
     196,   194,   196,   196,   221,   221,   253,   201,   221,   230,
     308,   230,   309,   234,   234,   246,   234,   234,   248,   237,
      43,   263,   279,    49,    50,   285,   194,   221,   194,   196,
     196,   195,   218,   218,   221,   221,   300,   301,   221,     4,
       5,   291,   293,   196,   196,   195,   195,   194,   194,   196,
     196,   221,    85,    85,   194,   194,   194,   226,   194,   194,
     234,   221,   221,   221,   194,   194,   205,   221,   226,   226,
     240,   221,   221,   221,   221,   221,   218,    97,   218,   196,
     196,   221,   221,   226,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   218,   221,   218,   218,   218,   221,   221,
     221,   221,   225,   218,   225,   218,   218,   221,    16,    44,
     273,   194,   194,   196,   196,   196,   196,    39,    40,   265,
     201,   221,   194,   218,    58,   218,   298,   194,   291,   291,
     196,   195,   195,   194,   234,   234,   221,   221,   194,   307,
     307,   218,   218,   218,   221,   221,   196,   196,   196,   194,
     196,   218,   218,   214,   195,   196,   196,   196,   196,   196,
     196,   196,   194,   196,   196,   196,   196,   214,   196,   196,
     196,   196,   196,   194,   196,   196,   196,   194,   196,   196,
     194,   196,   194,   196,   196,   196,   194,   194,   196,   194,
     196,   196,   194,   196,   196,   196,    12,   230,   230,   262,
      43,    38,   280,   196,   221,   196,   195,   194,   221,   302,
     234,   234,   292,   196,   196,   218,   194,   194,    75,    75,
     221,    75,   194,   226,     4,     5,   249,   250,   218,   221,
     221,   218,   221,   221,   218,   221,   218,   218,   221,   264,
     266,    48,   287,    60,    61,   196,    58,   221,   218,   196,
     291,   196,   196,   291,   218,   218,   218,   218,   196,   218,
     221,   195,   195,   194,   196,   196,   194,   196,   196,   196,
     196,   196,   196,   196,   196,    13,   257,   201,   201,   221,
      47,   286,   195,   195,   194,   196,   303,    75,   196,   196,
     250,   241,   221,   221,   254,    46,   290,   201,   281,   218,
     221,   221,   305,   218,   201,   196,   201,   288,    14,    16,
      18,    41,    44,    49,   282,   194,   196,   194,   196,   291,
      25,    44,   242,   255,   201,   218,   221,    14,    16,    18,
      41,    44,    49,   256,   289,   196,   196,     4,   258,   287
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   198,   199,   199,   199,   199,   199,   200,   201,   202,
     203,   201,   204,   204,   204,   204,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   205,   207,   205,   205,   205,   205,   205,   205,
     205,   208,   205,   209,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   210,   205,   211,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   212,   212,
     212,   212,   212,   213,   213,   213,   213,   213,   213,   214,
     214,   215,   215,   215,   215,   215,   216,   216,   217,   217,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   220,   220,   222,
     221,   223,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   224,   225,   226,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   228,
     228,   228,   229,   229,   229,   229,   230,   230,   231,   231,
     231,   231,   232,   233,   235,   234,   236,   236,   236,   237,
     237,   239,   240,   241,   238,   242,   242,   243,   243,   244,
     244,   244,   244,   245,   245,   246,   246,   246,   246,   247,
     247,   248,   248,   248,   248,   249,   249,   249,   250,   250,
     250,   250,   252,   253,   254,   255,   251,   256,   256,   256,
     256,   256,   256,   257,   257,   258,   258,   260,   259,   261,
     261,   262,   262,   263,   264,   263,   265,   266,   265,   268,
     267,   269,   269,   269,   269,   269,   269,   271,   272,   270,
     273,   273,   275,   274,   276,   276,   276,   276,   276,   276,
     278,   279,   280,   281,   277,   282,   282,   282,   282,   282,
     282,   284,   283,   285,   285,   286,   286,   287,   288,   289,
     287,   290,   290,   291,   292,   291,   293,   293,   293,   293,
     294,   294,   295,   295,   295,   295,   296,   296,   296,   296,
     297,   297,   297,   297,   297,   298,   298,   298,   300,   299,
     301,   299,   302,   299,   303,   299,   304,   299,   305,   305,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   307,   307,   308,   308,   309,   309
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
       4,     4,     4,     4,     4,     4,     4,     4,     6,     1,
       3,     1,     3,     4,     6,     6,     4,     6,     4,     6,
      10,     4,     4,     4,     8,     6,     4,     3,     3,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     4,     6,     1,     4,     4,     6,     6,     1,     1,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     3,
       6,     6,     4,     4,     4,     4,     6,     6,     8,     6,
       8,     4,     4,     4,     8,     4,     4,     4,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     4,     1,     3,
       6,     6,     4,     6,     6,     6,     4,     8,     6,     8,
       6,     4,     4,     4,     6,     6,     6,     8,     4,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     6,
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

  case 163: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 164: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 165: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 166: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 167: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 168: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 169: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 170: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 171: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 172: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 173: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 174: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 175: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 176: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 177: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 178: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 179: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 180: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 181: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 182: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 183: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 184: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 185: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 186: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 187: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 188: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 189: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 190: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 191: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 192: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 193: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 194: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 195: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 196: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 197: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 198: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 199: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 200: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 201: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 202: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 203: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 204: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 205: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 206: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 207: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 208: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 209: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 210: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 211: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 212: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 213: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 214: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 215: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 216: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 217: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 218: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 219: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 220: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 221: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 222: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 225: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 226: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 228: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 229: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 230: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 231: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 232: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 233: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 234: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 235: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 236: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 237: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 238: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 239: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 240: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 241: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 242: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 243: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 244: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 245: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 246: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 247: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 248: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 249: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 250: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 251: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 252: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 253: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 254: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 255: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 256: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 257: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 258: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 259: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 260: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 261: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 262: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 263: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 264: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 265: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 266: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 267: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 268: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 269: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 270: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 271: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 272: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 273: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 274: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 275: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 276: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 277: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 278: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 279: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 280: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 281: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 282: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 283: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 284: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 285: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 286: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 287: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 288: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 289: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 290: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 291: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 292: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 293: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 294: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 295: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 296: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 297: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 298: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 299: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 300: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 301: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 302: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 303: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 304: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 305: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 306: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 307: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 308: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 309: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 310: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 311: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 312: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 313: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 314: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 321: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 322: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 323: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 324: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 325: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 326: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 327: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 328: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 329: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 330: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 331: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 332: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 335: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 336: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 337: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 338: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 341: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 342: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 343: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 344: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 348: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 349: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 350: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 351: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 352: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 353: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 354: /* $@17: %empty  */
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

  case 355: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 356: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 357: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 358: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 359: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 360: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 361: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 362: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 363: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 365: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 366: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 367: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 368: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 374: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 375: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 377: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 379: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 381: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 382: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 383: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 384: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 385: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 386: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 387: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 388: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 390: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 391: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 392: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 394: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 395: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 396: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 397: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 398: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 399: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 400: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 401: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 402: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 403: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 405: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 406: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 407: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 408: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 409: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 410: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 411: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 413: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 414: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 418: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 419: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 424: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 426: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 427: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 428: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 429: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 432: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 433: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 434: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 435: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 436: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 437: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 438: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 439: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 443: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 444: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 445: /* using: %empty  */
       {create_print('d');}
    break;

  case 446: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 447: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 448: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 449: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 450: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 451: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 452: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 453: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 454: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 455: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 456: /* $@38: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 457: /* inputbody: $@38 prompt inputlist  */
                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 458: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 459: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 460: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 461: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 462: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 463: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 464: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 465: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 466: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 467: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 468: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 469: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 470: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 471: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 472: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 473: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 476: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 477: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 478: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 479: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

