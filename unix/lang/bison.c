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
    written by Marc Ihm 1995-2025
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
  YYSYMBOL_tINSTR = 155,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 156,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 157,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 158,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 159,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 160,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 161,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 162,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 163,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 164,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 165,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 166,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 167,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 168,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 169,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 170,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 171,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 172,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 173,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 174,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 175,                    /* tDATE  */
  YYSYMBOL_tTIME = 176,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 177,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 178,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 179,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 180,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 181,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 182,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 183,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 184, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 185,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 186, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 187,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 188,                   /* tEVAL2  */
  YYSYMBOL_189_ = 189,                     /* '-'  */
  YYSYMBOL_190_ = 190,                     /* '+'  */
  YYSYMBOL_191_ = 191,                     /* '*'  */
  YYSYMBOL_192_ = 192,                     /* '/'  */
  YYSYMBOL_UMINUS = 193,                   /* UMINUS  */
  YYSYMBOL_194_ = 194,                     /* ';'  */
  YYSYMBOL_195_ = 195,                     /* ','  */
  YYSYMBOL_196_ = 196,                     /* '('  */
  YYSYMBOL_197_ = 197,                     /* ')'  */
  YYSYMBOL_198_ = 198,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 199,                 /* $accept  */
  YYSYMBOL_program_or_expression = 200,    /* program_or_expression  */
  YYSYMBOL_program = 201,                  /* program  */
  YYSYMBOL_statement_list = 202,           /* statement_list  */
  YYSYMBOL_203_1 = 203,                    /* $@1  */
  YYSYMBOL_204_2 = 204,                    /* $@2  */
  YYSYMBOL_assignment = 205,               /* assignment  */
  YYSYMBOL_statement = 206,                /* statement  */
  YYSYMBOL_207_3 = 207,                    /* $@3  */
  YYSYMBOL_208_4 = 208,                    /* $@4  */
  YYSYMBOL_209_5 = 209,                    /* $@5  */
  YYSYMBOL_210_6 = 210,                    /* $@6  */
  YYSYMBOL_211_7 = 211,                    /* $@7  */
  YYSYMBOL_212_8 = 212,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 213,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 214,        /* string_assignment  */
  YYSYMBOL_to = 215,                       /* to  */
  YYSYMBOL_open_clause = 216,              /* open_clause  */
  YYSYMBOL_seek_clause = 217,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 218,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 219,        /* string_expression  */
  YYSYMBOL_string_function = 220,          /* string_function  */
  YYSYMBOL_number_assignment = 221,        /* number_assignment  */
  YYSYMBOL_expression = 222,               /* expression  */
  YYSYMBOL_223_9 = 223,                    /* $@9  */
  YYSYMBOL_224_10 = 224,                   /* $@10  */
  YYSYMBOL_arrayref = 225,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 226,          /* string_arrayref  */
  YYSYMBOL_coordinates = 227,              /* coordinates  */
  YYSYMBOL_function = 228,                 /* function  */
  YYSYMBOL_const = 229,                    /* const  */
  YYSYMBOL_number = 230,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 231,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 232,                  /* dimlist  */
  YYSYMBOL_function_or_array = 233,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 234,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 235,                /* call_list  */
  YYSYMBOL_236_11 = 236,                   /* $@11  */
  YYSYMBOL_calls = 237,                    /* calls  */
  YYSYMBOL_call_item = 238,                /* call_item  */
  YYSYMBOL_function_definition = 239,      /* function_definition  */
  YYSYMBOL_240_12 = 240,                   /* $@12  */
  YYSYMBOL_241_13 = 241,                   /* $@13  */
  YYSYMBOL_242_14 = 242,                   /* $@14  */
  YYSYMBOL_endsub = 243,                   /* endsub  */
  YYSYMBOL_function_name = 244,            /* function_name  */
  YYSYMBOL_export = 245,                   /* export  */
  YYSYMBOL_local_list = 246,               /* local_list  */
  YYSYMBOL_local_item = 247,               /* local_item  */
  YYSYMBOL_static_list = 248,              /* static_list  */
  YYSYMBOL_static_item = 249,              /* static_item  */
  YYSYMBOL_paramlist = 250,                /* paramlist  */
  YYSYMBOL_paramitem = 251,                /* paramitem  */
  YYSYMBOL_for_loop = 252,                 /* for_loop  */
  YYSYMBOL_253_15 = 253,                   /* $@15  */
  YYSYMBOL_254_16 = 254,                   /* $@16  */
  YYSYMBOL_255_17 = 255,                   /* $@17  */
  YYSYMBOL_256_18 = 256,                   /* $@18  */
  YYSYMBOL_next = 257,                     /* next  */
  YYSYMBOL_step_part = 258,                /* step_part  */
  YYSYMBOL_next_symbol = 259,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 260,  /* switch_number_or_string  */
  YYSYMBOL_261_19 = 261,                   /* $@19  */
  YYSYMBOL_sep_list = 262,                 /* sep_list  */
  YYSYMBOL_number_or_string = 263,         /* number_or_string  */
  YYSYMBOL_case_list = 264,                /* case_list  */
  YYSYMBOL_265_20 = 265,                   /* $@20  */
  YYSYMBOL_default = 266,                  /* default  */
  YYSYMBOL_267_21 = 267,                   /* $@21  */
  YYSYMBOL_do_loop = 268,                  /* do_loop  */
  YYSYMBOL_269_22 = 269,                   /* $@22  */
  YYSYMBOL_loop = 270,                     /* loop  */
  YYSYMBOL_while_loop = 271,               /* while_loop  */
  YYSYMBOL_272_23 = 272,                   /* $@23  */
  YYSYMBOL_273_24 = 273,                   /* $@24  */
  YYSYMBOL_wend = 274,                     /* wend  */
  YYSYMBOL_repeat_loop = 275,              /* repeat_loop  */
  YYSYMBOL_276_25 = 276,                   /* $@25  */
  YYSYMBOL_until = 277,                    /* until  */
  YYSYMBOL_if_clause = 278,                /* if_clause  */
  YYSYMBOL_279_26 = 279,                   /* $@26  */
  YYSYMBOL_280_27 = 280,                   /* $@27  */
  YYSYMBOL_281_28 = 281,                   /* $@28  */
  YYSYMBOL_282_29 = 282,                   /* $@29  */
  YYSYMBOL_endif = 283,                    /* endif  */
  YYSYMBOL_short_if = 284,                 /* short_if  */
  YYSYMBOL_285_30 = 285,                   /* $@30  */
  YYSYMBOL_end_of_if = 286,                /* end_of_if  */
  YYSYMBOL_else_part = 287,                /* else_part  */
  YYSYMBOL_elsif_part = 288,               /* elsif_part  */
  YYSYMBOL_289_31 = 289,                   /* $@31  */
  YYSYMBOL_290_32 = 290,                   /* $@32  */
  YYSYMBOL_maybe_then = 291,               /* maybe_then  */
  YYSYMBOL_inputlist = 292,                /* inputlist  */
  YYSYMBOL_293_33 = 293,                   /* $@33  */
  YYSYMBOL_input = 294,                    /* input  */
  YYSYMBOL_readlist = 295,                 /* readlist  */
  YYSYMBOL_readitem = 296,                 /* readitem  */
  YYSYMBOL_datalist = 297,                 /* datalist  */
  YYSYMBOL_printlist = 298,                /* printlist  */
  YYSYMBOL_using = 299,                    /* using  */
  YYSYMBOL_inputbody = 300,                /* inputbody  */
  YYSYMBOL_301_34 = 301,                   /* $@34  */
  YYSYMBOL_302_35 = 302,                   /* $@35  */
  YYSYMBOL_303_36 = 303,                   /* $@36  */
  YYSYMBOL_304_37 = 304,                   /* $@37  */
  YYSYMBOL_305_38 = 305,                   /* $@38  */
  YYSYMBOL_prompt = 306,                   /* prompt  */
  YYSYMBOL_printintro = 307,               /* printintro  */
  YYSYMBOL_hashed_number = 308,            /* hashed_number  */
  YYSYMBOL_goto_list = 309,                /* goto_list  */
  YYSYMBOL_gosub_list = 310                /* gosub_list  */
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
#define YYFINAL  193
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6544

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  199
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  480
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   444


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
       2,     2,     2,     2,     2,   198,     2,     2,     2,     2,
     196,   197,   191,   190,   195,   189,     2,   192,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   194,
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
     185,   186,   187,   188,   193
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
     398,   399,   400,   401,   402,   403,   404,   405,   408,   409,
     412,   412,   413,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   448,   451,   454,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     530,   531,   532,   535,   536,   537,   538,   541,   542,   545,
     546,   547,   548,   551,   554,   557,   557,   560,   561,   562,
     565,   566,   569,   570,   573,   569,   578,   579,   582,   583,
     586,   587,   588,   589,   592,   593,   596,   597,   598,   599,
     602,   603,   606,   607,   608,   609,   612,   613,   614,   617,
     618,   619,   620,   623,   624,   629,   644,   623,   649,   650,
     651,   652,   653,   654,   657,   658,   661,   662,   667,   667,
     671,   672,   675,   676,   680,   682,   681,   686,   687,   687,
     691,   691,   697,   698,   699,   700,   701,   702,   706,   707,
     706,   713,   714,   718,   718,   723,   724,   725,   726,   727,
     728,   731,   732,   732,   734,   731,   738,   739,   740,   741,
     742,   743,   746,   746,   751,   752,   755,   756,   759,   761,
     763,   760,   767,   768,   771,   772,   772,   775,   776,   778,
     779,   783,   784,   787,   788,   790,   791,   795,   796,   797,
     798,   801,   802,   803,   804,   805,   808,   809,   810,   813,
     813,   814,   814,   815,   815,   816,   816,   817,   817,   820,
     821,   824,   825,   826,   827,   828,   829,   830,   831,   832,
     833,   834,   835,   836,   837,   840,   841,   843,   844,   847,
     848
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
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tINSTR",
  "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE",
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
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
  "$@34", "$@35", "$@36", "$@37", "$@38", "prompt", "printintro",
  "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-831)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-402)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     576,  3750,  3335,  2647,    80,    18,    33,   -32,   -21,  -831,
    -831,  -831,  -831,  -831,   153,   153,   153,  2955,  -831,  -831,
    -831,  2647,  -831,  -831,  2647,    35,   117,  -831,  -831,  -831,
    3335,   -36,  -831,  3335,   189,  -831,  3335,  3335,  3335,   194,
      62,   153,  1537,  1168,  1984,    49,  3335,  2765,  3335,   -15,
      -9,  3335,  -831,    84,  2647,  2647,  2647,    51,   -18,    -6,
      27,    39,    45,  1984,  2647,  2647,  2647,  -831,   176,  -831,
    -831,   -10,  -831,  -831,  -831,  -831,   169,   180,  -831,   242,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,    78,    94,
    -831,  -831,  -831,  -831,   145,   154,   187,   195,  3335,   209,
     236,   238,   249,   271,   281,   285,   314,   316,   320,   347,
     350,   366,   378,   391,   403,   422,   426,   438,   445,   448,
     466,   483,   503,   511,   523,   527,   531,   537,   549,   552,
     555,   570,   585,   588,   595,   597,   601,   603,   604,   606,
     607,   608,   609,   610,   611,   613,   615,   616,   617,   620,
     621,   622,   634,   638,   641,   642,   643,   648,   655,   656,
     657,   673,   675,   677,   679,   680,   681,   682,   683,   687,
     688,   689,   690,   691,   697,   698,   699,   702,  3335,  3335,
     522,  -831,    95,  -831,  -831,  -831,  -831,  2647,   -17,   315,
     169,   180,   328,  -831,  3335,  -831,  2647,  -831,   493,  3335,
    3590,  -831,  -831,  -831,  -831,  -831,   241,   540,   288,   302,
     142,  -831,  3335,  -831,   142,  -831,  -831,  3335,  3590,   596,
     705,   518,   707,    10,  3335,   -35,   522,  6352,   708,   710,
     491,  6352,   522,  5442,   522,  5475,   711,   712,   650,  -831,
    -831,   628,   628,  -831,  -831,   668,  -831,  3335,  2647,  3335,
      46,  6352,   701,  -831,  -831,  -831,  -831,   714,  2647,  5495,
    -831,  3335,  -831,     6,   715,  -831,  -831,  3335,  3145,  -831,
    -831,  6352,  -831,  -831,   142,    -4,    -4,  -831,   579,   579,
     579,  2180,  2647,   385,   716,   142,   -16,    48,  -831,   839,
    3335,  3335,  3335,  3335,  2647,  -831,  -831,  -831,  3335,  3335,
     750,  3335,  3335,  3335,  3335,  1788,  1984,   377,   377,  3335,
    3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,
    3335,  1984,  3335,  3335,  3335,  3335,  3335,  3335,  3335,  3335,
    2375,  2647,  2647,  2647,  2647,  2647,  3335,  3335,  3335,  2570,
    3335,  2647,  3335,  2647,  3335,  2647,  2647,   375,  1355,  1866,
    2062,  2647,  2647,  2647,  3335,  2647,  2647,  2647,  2647,  2647,
    1984,  2647,  -831,  -831,  2647,  3335,  2647,  2647,  2647,  2647,
    2647,   720,   721,  2647,   579,  2647,   579,  2647,  2647,  2647,
     835,    56,  2970,  2647,  2647,  2647,  2647,  2647,  2647,  2647,
    2647,  -831,  -831,  -831,  3335,  3335,  3335,  3335,  3335,  3335,
    3335,  3335,  3335,  3335,  3335,  3335,   -90,  -831,  -831,  -831,
    6352,   722,   142,   724,   851,  6352,   193,  -831,  -831,  -831,
    -831,   731,   732,   734,  -831,   735,   736,   738,  -831,   522,
    6352,   740,  -831,   522,  6352,   891,   660,   892,  3590,  3335,
     755,  2647,  -831,  -831,  3335,   522,   873,   270,   757,    12,
    -831,   944,  -831,  -831,   649,  3335,  3335,  -831,  -831,   194,
    -831,  -831,    70,  5526,   142,  6352,   569,  2257,  3335,   142,
    3335,  -831,   -35,  -831,  -831,  3335,  2647,  -831,  3335,     6,
    3335,  3335,   759,   762,   763,   765,  -831,  3160,   -52,  3335,
    3335,  3335,  3335,  -831,   766,     6,     6,  6352,   142,   713,
     768,   769,  5572,  5605,  3464,  5625,  5656,  5671,   770,   303,
     767,   771,   775,   776,   780,   781,   779,   784,     6,  5702,
    3905,  3951,  3982,  4015,  4035,  1020,  4050,  1381,  4081,  4112,
     788,  4145,  4180,  4211,  4242,  4275,  4290,  4310,  5735,  -831,
    4341,    34,    85,    99,   161,    42,  5755,  5801,   343,  1400,
    -831,  4372,  4420,    64,  4440,  -158,  4471,    91,   108,  -831,
     157,  -831,   163,  -831,   165,  -831,   214,   230,   231,   232,
    5832,   245,   301,   233,   234,   304,   376,   790,  -135,   793,
     795,   309,  4502,   321,  -131,   364,   453,   455,  -831,  -831,
     457,  -150,   490,   -72,   498,   340,   341,  -831,  -831,   142,
     142,   142,   142,   142,   142,   142,  -831,  3335,  3335,   667,
     313,   791,   333,   492,   506,   -56,  -831,   -51,   -51,   835,
     835,  -831,  -831,  -831,  3590,  -831,  -831,  3335,  -831,  -831,
    -831,  -831,   153,   153,  -831,  -831,   288,  -831,  -831,   302,
    3335,  -831,   916,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,   686,  5865,  3335,  -100,  4517,  3412,  -831,  -831,  3335,
    3335,  -831,  -831,  3335,  -831,   764,   796,   798,   792,   800,
    5885,  5900,   801,   802,  -831,  -831,  -831,  3335,   878,   890,
    -831,   499,  5931,  6352,  -831,  -831,   510,  -831,  3335,  5962,
    5995,  -831,  3335,  3335,  3335,  -831,  -831,   522,  6352,   522,
    6352,  6030,  6061,  3590,  3335,  3335,  3335,  -831,  -831,  -831,
    -831,  -831,  3335,  3335,  -831,  3335,  3335,  3335,  -831,  2647,
    -831,  2452,  -831,   805,   806,  -831,  -831,  3335,  3335,  3335,
    3335,  -831,  -831,  -831,  -831,  -831,  3335,  -831,  -831,  3335,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  3335,  -831,  -831,  3335,  3335,  3335,  -831,  3335,  3335,
    -831,  2647,  -831,  -831,  -831,  -831,  -831,  3335,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  2647,
    2647,  2647,  -831,  -831,  -831,  -831,  -831,  2647,  -831,  -831,
    -831,  -831,  -831,  -831,  3335,  -831,  3335,  3335,  3335,   992,
    2647,  -831,   992,  2647,  -831,  2647,  -831,  -831,   750,   294,
    3335,    14,  6352,  -831,   809,  -831,   810,   811,   812,  -831,
     814,   815,  -831,  -831,  -831,   739,  3590,  -831,  -831,  -831,
    3335,  6092,  2647,   948,  -831,  2647,   142,   522,   873,  6125,
     764,   764,  4550,   817,   818,  -831,   820,  -831,  -831,  -831,
    -831,  3335,  3335,  -831,  -831,  6140,  1984,  1984,  2647,  2647,
    2647,  -831,  3335,  3335,   819,  4570,  4601,  1691,  2647,  2647,
    -831,  6352,     6,  -831,   821,  4647,  4680,  4700,  4731,  4746,
     345,   822,   -92,  -831,  -831,  4777,  4810,   823,    38,  4830,
    4876,  4907,  4940,  4960,  2781,  4975,  5006,   -91,  5037,   355,
       5,    67,   359,  5070,  6160,  6191,  5105,   -49,   367,   -13,
     368,   380,    79,  -831,  -831,  -831,   153,   153,  -831,  -831,
    -831,  -831,  3335,   964,   980,   978,  5136,  3335,   388,   826,
      68,  -831,  3335,  -831,  -831,  -831,  -831,  -831,  -831,   827,
     830,  6352,  6352,  2647,  -831,  -831,   142,   142,   513,  6222,
    6352,  -831,   953,   954,  3335,   955,   526,   142,  3335,   778,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  2647,  -831,  -831,
    -831,  -831,  3335,  -831,  -831,  -831,  -831,  -831,  3335,  -831,
    -831,  -831,  2647,  -831,  -831,  -831,  3335,  -831,  3335,  -831,
    -831,  -831,  2647,  3335,  -831,  2647,  -831,  -831,  2647,  -831,
    -831,  -831,  3335,  -831,  -831,  -831,  -831,  -831,   975,   729,
    5167,   973,  3335,  2647,  5200,   764,   836,   837,   764,  -831,
    -831,   142,  2647,  2647,  2647,  2647,  5215,  2647,  3335,  -831,
     840,   841,   136,  -831,   389,  6270,  5235,   410,  5266,  5297,
     411,  5345,   412,   429,   399,  3590,  3910,  3335,   985,  -831,
     842,  -831,   843,  6290,   442,  -831,  -831,  -831,  -831,  -831,
     142,   142,   142,   142,   965,   142,  6352,   844,   845,   778,
    -831,  -831,  3335,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  3335,  -831,   978,  1005,   700,  3590,  -831,  2647,  3335,
    3335,  -831,   944,  2647,  -831,  -831,  -831,  3590,  5365,  6352,
    3590,  -831,  -831,   978,   706,   149,  6321,  5396,   764,   142,
       4,  -831,   978,  3590,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  2647,  -831,  3335,  -831,  -831,  -831,  -831,  -831,   856,
     978,   443,  5427,  -831,  -831,  -831,  -831,  -831,  -831,  1040,
     975,  -831,  -831,  -831,  -831,  -831
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   118,     0,     0,     0,   330,     0,     0,     0,   112,
     353,   388,   393,    18,     0,     0,     0,     0,    31,    33,
     331,     0,   315,   315,     0,   332,    25,    27,   368,   380,
       0,   461,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     2,     9,    17,
       8,     0,    12,    46,    48,    14,    29,    30,    28,     0,
      20,    21,    24,    23,    22,    35,    36,   303,   210,   140,
     304,   305,   306,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,   270,   273,   276,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,   224,   204,   209,   142,     0,     0,     0,
       0,     0,     0,     1,     0,   315,     0,   315,     0,     0,
      16,   308,   307,    37,    38,    45,     0,     0,     0,     0,
      19,    50,   317,    51,    49,   333,    26,     0,    16,   412,
       0,   465,     0,     0,   441,   457,    69,    68,     0,     0,
      70,   111,    60,     0,    62,     0,   433,   435,    63,   431,
     437,     0,     0,   438,   300,    64,    66,     0,    96,     0,
       0,   476,     0,    93,    98,    86,    47,     0,     0,     0,
      74,     0,    57,    79,     0,    95,    94,     0,     0,   121,
     122,    99,    13,    15,   113,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     7,     0,
       0,     0,     0,     0,     0,   322,   315,   315,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   315,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,   192,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
     188,     0,   123,     0,     0,   389,     9,    39,    40,    41,
      43,   336,   337,    32,   334,   342,   343,    34,   340,   320,
     321,   316,   318,   373,   372,     0,     9,     0,    16,     0,
       0,     0,   462,   463,     0,   444,   446,    52,     0,     0,
      56,   459,   315,   315,     0,     0,     0,   315,   315,     0,
     302,   301,     0,     0,    97,   475,     0,     0,     0,    73,
       0,    78,   457,   130,   129,     0,     0,    75,     0,    81,
       0,     0,   138,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   189,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,   274,     0,   277,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   173,
       0,     0,     0,     0,     0,     0,     0,   145,   225,   219,
     221,   223,   220,   222,   217,   218,   144,     0,     0,   197,
     199,   201,   198,   200,   195,   196,   215,   212,   211,   213,
     214,   313,   314,   354,    16,   400,   398,     0,   399,   395,
     397,   394,     0,     0,   315,   315,     0,   315,   315,     0,
       0,   370,   374,   387,   385,   386,   383,   382,   384,   381,
     402,     9,     0,     0,     0,     0,     0,   442,    53,    54,
       0,   449,   451,     0,   460,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   439,   440,     0,     0,     0,
     133,   132,   136,   228,    58,    76,    89,    80,     0,     0,
       0,   315,     0,     0,     0,   103,   104,   105,   106,   107,
     108,     0,     0,    16,     0,     0,     0,   328,   329,   323,
     292,   184,     0,     0,   283,     0,     0,     0,   293,     0,
     294,     0,   287,     0,     0,   205,   206,     0,     0,     0,
       0,   229,   230,   231,   232,   233,     0,   234,   236,     0,
     237,   239,   240,   202,   246,   247,   241,   243,   244,   245,
     242,     0,   249,   254,     0,     0,     0,   253,     0,     0,
     153,     0,   150,   156,   157,   255,   182,     0,   256,   183,
     158,   159,   269,   272,   275,   278,   162,   160,   161,     0,
       0,     0,   164,   262,   165,   268,   267,     0,   174,   263,
     166,   264,   167,   266,     0,   168,     0,     0,     0,     0,
       0,   177,     0,     0,   179,     0,   299,   187,   193,   191,
       0,     9,   396,   477,    42,   479,    44,     0,     0,   335,
       0,     0,   341,   319,   371,   377,    16,   414,   415,   413,
       0,     0,     0,   466,   464,     0,   447,   445,   446,     0,
       0,     0,     0,   427,   429,   458,   424,   309,   311,   315,
     315,     0,     0,   434,   436,    71,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    87,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   391,   390,     0,     0,   338,   339,
     344,   345,     0,     0,     0,   403,     0,     0,     0,     0,
       0,   443,     0,   450,   452,   453,   315,   315,   425,     0,
       0,    59,    61,     0,   134,   135,   131,   137,    90,    83,
      84,   139,     0,     0,     0,     0,   116,   117,     0,   346,
     281,   282,   284,   285,   286,   295,   296,     0,   297,   207,
     208,   180,     0,   235,   238,   248,   146,   147,     0,   149,
     251,   252,     0,   151,   257,   163,     0,   258,     0,   260,
     175,   169,     0,     0,   186,     0,   289,   176,     0,   291,
     178,   203,     0,   478,   480,   375,   378,   369,   418,   468,
       0,   467,     0,     0,     0,     0,     0,     0,     0,   310,
     312,    72,     0,     0,     0,     0,     0,     0,     0,    88,
     349,   350,     0,   347,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,    16,   118,     0,   416,   472,
       0,   469,     0,     0,     0,   455,   454,   428,   430,   426,
      91,    82,   126,   127,     0,   125,   115,     0,     0,     0,
     324,   298,     0,   148,   152,   259,   261,   265,   185,   288,
     290,     0,   355,   376,     9,   422,    16,   404,     0,     0,
       0,   448,   459,     0,   351,   352,   348,    16,     0,   365,
      16,   423,   419,   417,     0,     0,     0,     0,     0,   124,
       9,   181,   356,    16,   411,   408,   409,   410,   406,   407,
     405,     0,   473,     0,   470,   456,   327,   326,   325,     0,
     420,     0,     0,   359,   361,   362,   363,   358,   360,   366,
     418,   474,   471,   367,   357,   421
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -831,  -831,  -831,  -198,  -831,  -831,  1042,   344,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,   997,  -223,  -831,  -831,  -187,
     777,  -831,   998,    -2,  -831,  -831,   744,  -307,   -42,  -831,
     591,   -37,    -3,  -831,     3,   143,   -14,  -831,  -831,   414,
    1050,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   420,  -831,
     418,  -831,   -11,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,   138,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   -79,
    -831,  -831,  -831,  -830,  -831,  -831,  -831,   614,  -831,  -831,
     228,   600,  -831,  -831,  -831,  -831,  -831,   -25,  -831,    24,
    -831,  -831
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    67,    68,   289,   703,    69,    70,   208,   209,
     632,   633,   225,   472,    71,    72,   475,    73,    74,   483,
     180,   181,    75,   259,   608,   607,   514,   515,   260,   183,
     243,   184,   203,   230,   185,   186,   211,   212,   431,   432,
      78,   499,   874,  1097,  1128,   709,    79,   423,   424,   427,
     428,  1032,  1033,    80,   198,   810,  1100,  1129,  1139,  1082,
    1144,    81,   217,   642,   435,   825,  1045,   924,  1046,    82,
     218,   649,    83,   199,   624,   915,    84,   200,   631,    85,
     437,   826,  1008,  1104,  1120,    86,   438,   829,  1087,  1048,
    1113,  1140,  1102,   845,  1018,   846,   238,   239,   245,   447,
     657,   450,   840,   841,  1015,  1092,   451,   665,   224,   252,
     814,   816
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     182,   517,   416,   244,    76,   263,   264,   190,   473,   213,
     933,   934,   204,   205,   442,   207,   661,   443,   473,   662,
     436,   401,   220,   448,   221,   222,   401,   407,   219,  1126,
     913,   227,   390,   193,   231,   233,   235,   767,   246,   768,
     251,   251,   251,   194,   265,   800,    20,   801,  1127,   271,
     473,    25,   480,   481,   196,   390,   190,   466,   914,   390,
     787,   251,   788,   215,   794,    87,   795,   256,   257,    90,
      91,    92,   240,    87,   266,   267,   268,    90,    91,    92,
     675,   269,   290,   291,     7,     8,   270,   284,     7,     8,
     390,  1002,   484,   485,   292,   832,   300,   833,   390,   390,
     390,   392,   393,   967,   982,   968,   983,   597,   394,   395,
     396,   397,   398,   399,   400,   401,   383,   384,   385,   386,
     387,   388,   389,   803,   216,   804,   383,   384,   385,   386,
     387,   388,   389,   402,   403,   404,   405,   258,   390,   391,
     404,   405,   392,   393,    77,   696,   995,   191,   996,   394,
     395,   396,   397,   398,   399,   400,   401,   201,   392,   393,
     202,   277,   223,   449,   195,   394,   395,   396,   397,   398,
     399,   400,   401,   390,   390,   197,   380,   382,   278,   491,
      53,   411,   998,   413,   999,  1056,   390,   591,  1059,   593,
     279,   474,   410,   228,   229,   390,   191,   415,   236,   237,
     986,   474,   987,    76,   460,   461,   444,   625,   663,   626,
     430,   627,    58,    59,    60,   434,    58,    59,    60,   471,
     288,    76,   446,   280,   390,   477,   479,   402,   403,   404,
     405,   753,   390,   474,   628,   281,   390,   629,   390,   757,
     651,   282,   630,   492,   293,   463,   390,   465,   494,   495,
     496,   241,   242,   597,   390,   294,   688,   390,   390,   241,
     242,   765,   988,  1013,   989,   597,   295,   518,   402,   403,
     404,   405,   705,   706,   195,   390,   417,   418,  1125,   487,
     754,   390,   500,   501,   402,   403,   404,   405,   770,   390,
     197,   497,   421,   422,   755,   729,   502,   503,   390,   504,
     505,   506,   507,   251,   251,   771,   425,   426,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   251,
     531,   532,   533,   534,   535,   536,   537,   538,   540,   510,
     511,  1069,   390,  1070,   546,   547,   549,   551,   552,   390,
     554,   296,   556,    77,  1121,   530,  1122,   390,   579,   580,
     297,   390,   570,   390,   772,   390,   756,   392,   251,   408,
     773,    77,   774,   582,   394,   395,   396,   397,   398,   399,
     400,   401,   409,   383,   384,   385,   386,   387,   388,   389,
      89,   512,   513,   298,   577,    93,   397,   398,   399,   400,
     401,   299,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   390,   301,    95,   398,   399,   400,
     401,   775,  1081,   383,   384,   385,   386,   387,   388,   389,
     390,   390,   390,   390,   390,   244,   811,   776,   777,   778,
     782,   783,   302,   685,   303,   390,   687,   652,   666,   667,
     780,    76,   655,   672,   673,   304,   383,   384,   385,   386,
     387,   388,   389,   670,   671,   383,   384,   385,   386,   387,
     388,   389,   392,   393,   658,   659,   682,   305,   683,   394,
     395,   396,   397,   398,   399,   400,   401,   306,   689,   690,
     107,   307,   108,   402,   403,   404,   405,   698,   700,   701,
     702,   390,   907,   390,   390,   909,   781,   414,   719,   390,
     720,   784,   402,   403,   404,   405,   791,   130,   131,   132,
     308,   390,   309,   136,   137,   138,   310,   140,   793,   142,
     143,   144,   402,   403,   404,   405,   149,   150,   151,   152,
     390,   390,   155,   390,   157,   390,   159,   806,   807,   161,
     760,   163,   965,   311,   165,   390,   312,   167,   168,   390,
     169,   170,   985,   172,   390,   174,   990,   390,   390,   796,
     419,   420,   313,   177,   997,  1000,   390,   399,   400,   401,
     390,   187,   559,   785,   314,   390,   440,  1001,   390,   390,
     489,    77,   400,   401,   482,  1011,  1071,   315,   402,   403,
     404,   405,   383,   384,   385,   386,   387,   388,   389,   316,
     390,   390,   390,   392,   393,   808,   809,  1074,  1077,  1079,
     394,   395,   396,   397,   398,   399,   400,   401,   317,   390,
     817,   818,   318,   820,   821,   812,  1080,    76,   925,   813,
     815,    87,   390,   390,   319,    90,    91,    92,   430,  1091,
    1141,   320,  -401,   390,   321,   390,   861,   390,   797,   958,
     798,   831,   799,   668,   669,   678,   679,   838,   839,   392,
     393,   842,   322,   872,   873,   972,   394,   395,   396,   397,
     398,   399,   400,   401,   643,   855,   644,   864,   645,   323,
     390,   402,   403,   404,   405,   802,   454,   887,   390,   390,
     865,   866,   867,   805,   858,   402,   403,   404,   405,   324,
     390,   646,   871,   390,   647,   860,    76,   325,  1022,   648,
     875,   876,   390,   877,   878,   879,   390,   707,   708,   326,
    1114,  1028,  1115,   327,  1116,   885,   886,   328,   888,   402,
     403,   404,   405,   329,   889,   827,   828,   890,   395,   396,
     397,   398,   399,   400,   401,   330,  1101,  1117,   331,   891,
    1118,   332,   892,   893,   894,  1119,   895,   896,     1,     2,
       3,     4,     5,   392,   393,   898,   333,    77,   843,   844,
     394,   395,   396,   397,   398,   399,   400,   401,   922,   923,
     188,   334,  1030,  1031,   335,   402,   403,   404,   405,  1049,
    1050,   336,   903,   337,   904,   905,   906,   338,   210,   339,
     340,   214,   341,   342,   343,   344,   345,   346,   912,   347,
     226,   348,   349,   350,   232,   234,   351,   352,   353,   250,
     394,   395,   396,   397,   398,   399,   400,   401,   926,    76,
     354,   274,   275,   276,   355,   939,   940,   356,   357,   358,
     283,   285,   286,   287,   359,   459,    77,  1083,  1084,   941,
     942,   360,   361,   362,   251,   251,   402,   403,   404,   405,
     949,   950,   395,   462,   397,   398,   399,   400,   401,   363,
    1133,   364,  1134,   365,  1135,   366,   367,   368,   369,   370,
     944,   945,   493,   371,   372,   373,   374,   375,  1103,   402,
     403,   404,   405,   376,   377,   378,   467,  1136,   379,  1110,
    1137,   439,  1112,   441,   452,  1138,   453,   457,   458,   468,
     476,   490,   401,  1003,  1004,  1130,  1029,   588,   589,   621,
     434,   622,  1016,  1017,   656,  1010,   623,   634,   635,   636,
    1014,   637,   638,   639,   641,   640,   392,   393,   650,   402,
     403,   404,   405,   394,   395,   396,   397,   398,   399,   400,
     401,   653,  1026,   660,   664,   691,   381,   692,   693,   824,
     694,   704,   721,   856,   406,   710,   711,   718,   722,    77,
    1035,   723,   724,   412,   727,   857,  1036,   725,   726,   728,
     402,   403,   404,   405,  1038,   743,  1039,   786,   849,   429,
     789,  1041,   790,   847,   433,   848,   850,   513,   853,   854,
    1044,   445,   883,   884,   916,   917,   929,  1006,   918,   919,
    1053,   920,   921,   936,   937,   938,   951,   959,  1007,   966,
     971,    -9,  1012,  1047,  1019,   464,  1066,  1020,  1024,  1025,
    1027,  1052,  1086,  1057,  1058,   469,  1067,  1068,  1088,  1089,
    1093,  1094,  1095,  -379,  1143,  1085,   189,   870,    76,    76,
     272,   273,   516,   676,   823,   192,   819,   822,  1096,   488,
    1005,  1145,   402,   403,   404,   405,   931,  1108,     0,     0,
    1098,   498,   684,   674,     0,     0,     0,     0,     0,  1099,
       0,     0,   509,   392,   393,     0,     0,  1106,  1107,    76,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
      76,     0,     0,    76,     0,     0,     0,     0,   541,   542,
     543,   544,   545,     0,     0,   548,    76,     0,   553,     0,
     555,  1132,   557,   558,   560,   562,   564,   566,   567,   568,
     569,     0,   571,   572,   573,   574,   575,   576,   578,     0,
       0,   581,     0,   583,   584,   585,   586,   587,     0,     0,
     590,     0,   592,     0,   594,   595,   596,     0,     0,     0,
     599,   600,   601,   602,   603,   604,   605,   606,     0,     0,
       0,    87,    88,    89,     0,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,   736,     0,   737,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
      77,     0,     0,    77,   681,     0,     0,     0,     0,   103,
       0,     0,   104,   686,     0,     0,    77,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   697,   699,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,   255,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
      89,     0,     0,     0,   179,    93,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   836,     0,     0,   837,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
     107,     0,   108,   392,   393,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,     0,     0,   136,   137,   138,   880,   140,   882,   142,
     143,   144,     0,     0,     0,     0,   149,   150,   151,   152,
       0,     0,   155,     0,   157,     0,   159,     0,     0,   161,
       0,   163,     0,     0,   165,     0,     0,   167,   168,     0,
     169,   170,     0,   172,     0,   174,     0,     0,   897,     0,
      87,    88,    89,   177,    90,    91,    92,    93,     0,     0,
       0,   187,   561,     0,     0,     0,   899,   900,   901,     0,
       0,     0,     0,     0,   902,     0,     0,    94,    95,     0,
     402,   403,   404,   405,     0,     0,   739,   908,   740,     0,
     910,     0,   911,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,   761,     0,   762,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   928,
       0,     0,   930,     0,     0,     0,     0,     0,   103,     0,
       0,   104,     0,     0,     0,     0,   247,     0,     0,     0,
       0,     0,     0,     0,   248,   946,   947,   948,   105,   106,
       0,     0,   107,     0,   108,   956,   957,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   433,
     160,   161,   162,   163,     0,   164,   165,     0,   166,   167,
     168,     0,   169,   170,   171,   172,   173,   174,   175,     0,
    1021,     0,     0,     0,   176,   177,   178,     0,     0,     0,
       0,     0,     0,   179,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,  1034,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,  1037,
       0,   394,   395,   396,   397,   398,   399,   400,   401,  1040,
       0,     0,  1042,     0,     0,  1043,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1054,    87,    88,    89,     0,    90,    91,    92,    93,  1060,
    1061,  1062,  1063,     0,  1065,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,     0,   103,
    1109,    89,   104,     0,     0,     0,    93,     0,     0,     0,
     402,   403,   404,   405,     0,   508,   954,     0,   955,   105,
     106,     0,     0,   107,     0,   108,     0,    95,  1131,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,     0,   164,   165,     0,   166,
     167,   168,     0,   169,   170,   171,   172,   173,   174,   175,
       0,   107,     0,   108,     0,   176,   177,   178,     0,     0,
       0,     0,     0,     0,   179,     0,   249,    87,    88,    89,
       0,    90,    91,    92,    93,     0,     0,     0,   130,   131,
     132,     0,     0,     0,   136,   137,   138,     0,   140,     0,
     142,   143,   144,     0,    94,    95,     0,   149,   150,   151,
     152,     0,     0,   155,     0,   157,     0,   159,     0,     0,
     161,     0,   163,     0,     0,   165,     0,     0,   167,   168,
       0,   169,   170,     0,   172,     0,   174,    96,    97,    98,
      99,   100,   101,   102,   177,     0,     0,     0,     0,     0,
       0,     0,   187,   563,     0,   103,     0,    89,   104,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,    95,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     0,   160,   161,   162,
     163,     0,   164,   165,     0,   166,   167,   168,     0,   169,
     170,   171,   172,   173,   174,   175,     0,   107,     0,   108,
       0,   176,   177,   178,     0,     0,     0,     0,     0,     0,
     179,     0,   249,    87,    88,    89,     0,    90,    91,    92,
      93,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
      94,    95,     0,   149,   150,   151,   152,     0,     0,   155,
       0,   157,     0,   159,     0,     0,   161,     0,   163,     0,
       0,   165,     0,     0,   167,   168,     0,   169,   170,     0,
     172,     0,   174,    96,    97,    98,    99,   100,   101,   102,
     177,     0,     0,     0,     0,     0,     0,     0,   187,   565,
       0,   103,    89,     0,   104,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,    95,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   167,   168,   680,   169,   170,   171,   172,   173,
     174,   175,   107,     0,   108,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,     0,   179,   486,    87,    88,
      89,     0,    90,    91,    92,    93,     0,     0,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,     0,   140,
       0,   142,   143,   144,     0,    94,    95,     0,   149,   150,
     151,   152,     0,     0,   155,     0,   157,     0,   159,     0,
       0,   161,     0,   163,     0,     0,   165,     0,     0,   167,
     168,     0,   169,   170,     0,   172,     0,   174,    96,    97,
      98,    99,   100,   101,   102,   177,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,   103,    89,     0,   104,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,    95,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,   881,
     169,   170,   171,   172,   173,   174,   175,   107,     0,   108,
       0,     0,   176,   177,   178,     0,     0,     0,     0,     0,
       0,   179,   539,    87,    88,    89,     0,    90,    91,    92,
      93,     0,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
      94,    95,     0,   149,   150,   151,   152,     0,     0,   155,
       0,   157,     0,   159,     0,     0,   161,     0,   163,     0,
       0,   165,     0,     0,   167,   168,     0,   169,   170,     0,
     172,     0,   174,    96,    97,    98,    99,   100,   101,   102,
     177,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,   103,    89,     0,   104,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,    95,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   167,   168,     0,   169,   170,   171,   172,   173,
     174,   175,   107,     0,   108,     0,     0,   176,   177,   178,
       0,     0,     0,     0,     0,     0,   179,   550,    87,    88,
      89,     0,    90,    91,    92,    93,     0,   261,     0,   130,
     131,   132,     0,     0,     0,   136,   137,   138,     0,   140,
       0,   142,   143,   144,     0,    94,    95,     0,   149,   150,
     151,   152,     0,     0,   155,     0,   157,     0,   159,     0,
       0,   161,     0,   163,     0,     0,   165,     0,   262,   167,
     168,     0,   169,   170,     0,   172,     0,   174,    96,    97,
      98,    99,   100,   101,   102,   177,     0,     0,     0,     0,
       0,     0,     0,   187,   392,   393,   103,     0,     0,   104,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,     0,     0,     0,    87,    88,
      89,   179,    90,    91,    92,    93,     0,     0,     0,     0,
     402,   403,   404,   405,     0,     0,   978,     0,   979,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   393,     0,   103,     0,     0,   104,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,     0,     0,     0,    87,    88,
      89,   179,    90,    91,    92,    93,     0,   478,     0,   402,
     403,   404,   405,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   393,     0,   103,     0,     0,   104,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,   176,   177,   178,     0,     0,     0,    87,    88,
      89,   179,    90,    91,    92,    93,     0,     0,     0,   402,
     403,   404,   405,     0,     0,     0,     0,   695,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,    89,     0,   104,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,    95,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,   175,   107,     0,   108,
       0,     0,   176,   177,   178,     0,     0,   392,   393,     0,
       0,   179,     0,     0,   394,   395,   396,   397,   398,   399,
     400,   401,     0,     0,   130,   131,   132,     0,     0,     0,
     136,   137,   138,     0,   140,     0,   142,   143,   144,     0,
       0,     0,     0,   149,   150,   151,   152,     0,     0,   155,
       0,   157,     0,   159,     0,     0,   161,     0,   163,     0,
       0,   165,     0,     0,   167,   168,     0,   169,   170,     0,
     172,     0,   174,     0,     7,     8,     9,     0,     0,     0,
     177,    10,     0,     0,     0,    11,     0,    12,   835,    13,
      14,    15,    16,    17,  -330,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,   402,   403,   404,   405,     0,     0,     0,
       0,   714,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,  -118,  -118,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,  -118,     0,    55,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    63,     0,     7,     8,     9,    64,     0,     0,
      65,    10,     0,     0,    66,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -330,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,   -16,   -16,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    63,     0,     7,     8,     9,    64,     0,     0,
      65,    10,     0,     0,    66,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -330,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,   -16,     0,
       0,     0,    29,   -16,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,   392,   393,
       0,    37,    38,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,   392,   393,    55,     0,    56,    57,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,   392,   393,     0,     0,    61,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,    63,     0,     0,     0,     0,    64,   392,   393,
      65,     0,     0,     0,    66,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
       0,     0,   731,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,   392,   393,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   732,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,     0,     0,   733,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
       0,     0,   734,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   738,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   741,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,     0,     0,   742,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
       0,     0,   744,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,   392,   393,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   745,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   746,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,     0,     0,   747,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,     0,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   749,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   750,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   752,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,     0,     0,   763,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
     392,   393,     0,     0,     0,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   764,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   766,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   769,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,     0,     0,     0,     0,   792,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,   834,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   935,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   952,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,     0,     0,   953,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,   392,
     393,     0,     0,     0,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,   960,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   961,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   962,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,     0,     0,     0,     0,   963,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,   964,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,   969,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   970,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   973,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,   392,   393,
       0,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,   974,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,   975,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   976,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,     0,     0,     0,     0,   977,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
       0,     0,   980,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,   981,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,   984,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,     0,     0,   991,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,   392,   393,
       0,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
       0,     0,   994,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,  1009,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,  1051,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,     0,     0,  1055,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
       0,     0,  1064,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
       0,     0,  1073,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,  1075,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     392,   393,     0,     0,  1076,     0,     0,   394,   395,   396,
     397,   398,   399,   400,   401,   392,   393,     0,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
       0,     0,  1078,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
       0,     0,  1111,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,     0,     0,  1124,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
       0,     0,     0,     0,  1142,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   455,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
     456,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
     470,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   392,
     393,   677,     0,     0,     0,     0,   394,   395,   396,   397,
     398,   399,   400,   401,   392,   393,     0,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   712,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
     713,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
     715,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,     0,
       0,   716,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,   717,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   730,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
     751,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,   392,   393,
     758,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,   392,   393,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,   759,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   779,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
     830,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,     0,   402,   403,   404,   405,     0,     0,
     851,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,   852,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,   859,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   862,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   392,   393,
     863,     0,     0,     0,     0,   394,   395,   396,   397,   398,
     399,   400,   401,   392,   393,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,   868,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,   869,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,   927,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,   403,   404,   405,     0,     0,
     932,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   392,   393,   943,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,   402,
     403,   404,   405,   392,   393,   992,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   392,   393,   993,     0,     0,     0,
       0,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   392,   393,  1023,     0,     0,
       0,     0,   394,   395,   396,   397,   398,   399,   400,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,  1072,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,  1090,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,   403,   404,   405,     0,     0,  1123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405
};

static const yytype_int16 yycheck[] =
{
       2,   308,   200,    40,     1,    47,    48,     4,    12,    23,
     840,   841,    15,    16,     4,    17,     4,     7,    12,     7,
     218,    77,    58,    58,    60,    61,    77,    44,    30,    25,
      16,    33,   190,     0,    36,    37,    38,   195,    41,   197,
      42,    43,    44,    75,    59,   195,    28,   197,    44,    51,
      12,    33,   275,   276,    75,   190,    53,    11,    44,   190,
     195,    63,   197,    28,   195,     3,   197,    43,    44,     7,
       8,     9,    10,     3,    89,    90,    91,     7,     8,     9,
      10,    96,    92,    93,     4,     5,    95,    63,     4,     5,
     190,    12,   279,   280,   104,   195,    98,   197,   190,   190,
     190,    63,    64,   195,   195,   197,   197,   197,    70,    71,
      72,    73,    74,    75,    76,    77,    70,    71,    72,    73,
      74,    75,    76,   195,     7,   197,    70,    71,    72,    73,
      74,    75,    76,   189,   190,   191,   192,    88,   190,    44,
     191,   192,    63,    64,     1,   197,   195,     4,   197,    70,
      71,    72,    73,    74,    75,    76,    77,     4,    63,    64,
       7,   110,   198,   198,   196,    70,    71,    72,    73,    74,
      75,    76,    77,   190,   190,   196,   178,   179,   196,   195,
     100,   195,   195,   197,   197,  1015,   190,   374,  1018,   376,
     196,   195,   194,     4,     5,   190,    53,   199,     4,     5,
     195,   195,   197,   200,   241,   242,   196,    14,   196,    16,
     212,    18,   132,   133,   134,   217,   132,   133,   134,   261,
      44,   218,   224,   196,   190,   267,   268,   189,   190,   191,
     192,   197,   190,   195,    41,   196,   190,    44,   190,   197,
     438,   196,    49,   195,    75,   247,   190,   249,   290,   291,
     292,   189,   190,   197,   190,    75,   479,   190,   190,   189,
     190,   197,   195,   195,   197,   197,    24,   309,   189,   190,
     191,   192,   495,   496,   196,   190,    35,    36,  1108,   281,
     195,   190,   296,   297,   189,   190,   191,   192,   197,   190,
     196,   293,     4,     5,   195,   518,   298,   299,   190,   301,
     302,   303,   304,   305,   306,   197,     4,     5,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   305,
     306,   195,   190,   197,   336,   337,   338,   339,   340,   190,
     342,   196,   344,   200,   195,   321,   197,   190,   362,   363,
     196,   190,   354,   190,   197,   190,   195,    63,   360,    44,
     197,   218,   197,   365,    70,    71,    72,    73,    74,    75,
      76,    77,    44,    70,    71,    72,    73,    74,    75,    76,
       5,     4,     5,   196,   360,    10,    73,    74,    75,    76,
      77,   196,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   190,   196,    31,    74,    75,    76,
      77,   197,    13,    70,    71,    72,    73,    74,    75,    76,
     190,   190,   190,   190,   190,   462,   624,   197,   197,   197,
     197,   197,   196,   475,   196,   190,   478,   439,   452,   453,
     195,   438,   444,   457,   458,   196,    70,    71,    72,    73,
      74,    75,    76,   455,   456,    70,    71,    72,    73,    74,
      75,    76,    63,    64,   194,   195,   468,   196,   470,    70,
      71,    72,    73,    74,    75,    76,    77,   196,   480,   481,
     105,   196,   107,   189,   190,   191,   192,   489,   490,   491,
     492,   190,   799,   190,   190,   802,   195,     4,   195,   190,
     197,   197,   189,   190,   191,   192,   197,   132,   133,   134,
     196,   190,   196,   138,   139,   140,   196,   142,   197,   144,
     145,   146,   189,   190,   191,   192,   151,   152,   153,   154,
     190,   190,   157,   190,   159,   190,   161,   197,   197,   164,
     197,   166,   197,   196,   169,   190,   196,   172,   173,   190,
     175,   176,   197,   178,   190,   180,   197,   190,   190,   195,
      20,    21,   196,   188,   197,   197,   190,    75,    76,    77,
     190,   196,   197,   197,   196,   190,    58,   197,   190,   190,
     195,   438,    76,    77,     5,   197,   197,   196,   189,   190,
     191,   192,    70,    71,    72,    73,    74,    75,    76,   196,
     190,   190,   190,    63,    64,   607,   608,   197,   197,   197,
      70,    71,    72,    73,    74,    75,    76,    77,   196,   190,
     634,   635,   196,   637,   638,   627,   197,   624,   826,   632,
     633,     3,   190,   190,   196,     7,     8,     9,   640,   197,
     197,   196,    46,   190,   196,   190,   688,   190,   195,   872,
     195,   653,   195,     4,     5,    86,    87,   659,   660,    63,
      64,   663,   196,   705,   706,   888,    70,    71,    72,    73,
      74,    75,    76,    77,    14,   677,    16,   691,    18,   196,
     190,   189,   190,   191,   192,   195,   195,   729,   190,   190,
     692,   693,   694,   195,   195,   189,   190,   191,   192,   196,
     190,    41,   704,   190,    44,   195,   703,   196,   195,    49,
     712,   713,   190,   715,   716,   717,   190,     4,     5,   196,
      14,   195,    16,   196,    18,   727,   728,   196,   730,   189,
     190,   191,   192,   196,   736,    49,    50,   739,    71,    72,
      73,    74,    75,    76,    77,   196,    46,    41,   196,   751,
      44,   196,   754,   755,   756,    49,   758,   759,   182,   183,
     184,   185,   186,    63,    64,   767,   196,   624,     4,     5,
      70,    71,    72,    73,    74,    75,    76,    77,    39,    40,
       3,   196,     4,     5,   196,   189,   190,   191,   192,    60,
      61,   196,   794,   196,   796,   797,   798,   196,    21,   196,
     196,    24,   196,   196,   196,   196,   196,   196,   810,   196,
      33,   196,   196,   196,    37,    38,   196,   196,   196,    42,
      70,    71,    72,    73,    74,    75,    76,    77,   830,   826,
     196,    54,    55,    56,   196,   849,   850,   196,   196,   196,
      63,    64,    65,    66,   196,   195,   703,  1045,  1046,   851,
     852,   196,   196,   196,   856,   857,   189,   190,   191,   192,
     862,   863,    71,   195,    73,    74,    75,    76,    77,   196,
      14,   196,    16,   196,    18,   196,   196,   196,   196,   196,
     856,   857,    43,   196,   196,   196,   196,   196,  1086,   189,
     190,   191,   192,   196,   196,   196,   195,    41,   196,  1097,
      44,   196,  1100,   196,   196,    49,   196,   196,   196,   195,
     195,   195,    77,   916,   917,  1113,   958,   197,   197,   197,
     922,   197,   936,   937,    51,   927,    75,   196,   196,   195,
     932,   196,   196,   195,    43,   195,    63,    64,    46,   189,
     190,   191,   192,    70,    71,    72,    73,    74,    75,    76,
      77,   196,   954,   196,    10,   196,   179,   195,   195,    43,
     195,   195,   195,    85,   187,   197,   197,   197,   197,   826,
     972,   196,   196,   196,   195,    85,   978,   197,   197,   195,
     189,   190,   191,   192,   986,   197,   988,   197,   196,   212,
     197,   993,   197,   197,   217,   197,   196,     5,   197,   197,
    1002,   224,   197,   197,   195,   195,    58,    43,   197,   197,
    1012,   197,   197,   196,   196,   195,   197,   196,    38,   197,
     197,    43,   196,    48,   197,   248,  1028,   197,    75,    75,
      75,    58,    47,   197,   197,   258,   196,   196,   196,   196,
      75,   197,   197,    38,     4,  1047,     4,   703,  1045,  1046,
      53,    53,   308,   462,   640,     5,   636,   639,  1069,   282,
     922,  1140,   189,   190,   191,   192,   838,  1092,    -1,    -1,
    1072,   294,   472,   459,    -1,    -1,    -1,    -1,    -1,  1081,
      -1,    -1,   305,    63,    64,    -1,    -1,  1089,  1090,  1086,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
    1097,    -1,    -1,  1100,    -1,    -1,    -1,    -1,   331,   332,
     333,   334,   335,    -1,    -1,   338,  1113,    -1,   341,    -1,
     343,  1123,   345,   346,   347,   348,   349,   350,   351,   352,
     353,    -1,   355,   356,   357,   358,   359,   360,   361,    -1,
      -1,   364,    -1,   366,   367,   368,   369,   370,    -1,    -1,
     373,    -1,   375,    -1,   377,   378,   379,    -1,    -1,    -1,
     383,   384,   385,   386,   387,   388,   389,   390,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1045,  1046,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,   195,    -1,   197,   441,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
    1097,    -1,    -1,  1100,   467,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,   476,    -1,    -1,  1113,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,   489,   490,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,    -1,   168,   169,    -1,   171,
     172,   173,    -1,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
       5,    -1,    -1,    -1,   196,    10,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   656,    -1,    -1,   659,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     105,    -1,   107,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,   719,   142,   721,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,   164,
      -1,   166,    -1,    -1,   169,    -1,    -1,   172,   173,    -1,
     175,   176,    -1,   178,    -1,   180,    -1,    -1,   761,    -1,
       3,     4,     5,   188,     7,     8,     9,    10,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,   779,   780,   781,    -1,
      -1,    -1,    -1,    -1,   787,    -1,    -1,    30,    31,    -1,
     189,   190,   191,   192,    -1,    -1,   195,   800,   197,    -1,
     803,    -1,   805,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,   195,    -1,   197,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,   832,
      -1,    -1,   835,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,   858,   859,   860,   101,   102,
      -1,    -1,   105,    -1,   107,   868,   869,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   922,
     163,   164,   165,   166,    -1,   168,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,    -1,
     943,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   967,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,   982,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   992,
      -1,    -1,   995,    -1,    -1,   998,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1013,     3,     4,     5,    -1,     7,     8,     9,    10,  1022,
    1023,  1024,  1025,    -1,  1027,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1088,    -1,    -1,    -1,    81,
    1093,     5,    84,    -1,    -1,    -1,    10,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    97,   195,    -1,   197,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    31,  1121,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,    -1,   168,   169,    -1,   171,
     172,   173,    -1,   175,   176,   177,   178,   179,   180,   181,
      -1,   105,    -1,   107,    -1,   187,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    30,    31,    -1,   151,   152,   153,
     154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
     164,    -1,   166,    -1,    -1,   169,    -1,    -1,   172,   173,
      -1,   175,   176,    -1,   178,    -1,   180,    63,    64,    65,
      66,    67,    68,    69,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    -1,    81,    -1,     5,    84,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    31,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,   105,    -1,   107,
      -1,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,   198,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,    -1,   144,   145,   146,    -1,
      30,    31,    -1,   151,   152,   153,   154,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
      -1,   169,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
     178,    -1,   180,    63,    64,    65,    66,    67,    68,    69,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
      -1,    81,     5,    -1,    84,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    31,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,    -1,   168,   169,
      -1,   171,   172,   173,    97,   175,   176,   177,   178,   179,
     180,   181,   105,    -1,   107,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,    30,    31,    -1,   151,   152,
     153,   154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,   164,    -1,   166,    -1,    -1,   169,    -1,    -1,   172,
     173,    -1,   175,   176,    -1,   178,    -1,   180,    63,    64,
      65,    66,    67,    68,    69,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    81,     5,    -1,    84,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    31,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    97,
     175,   176,   177,   178,   179,   180,   181,   105,    -1,   107,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,    -1,   144,   145,   146,    -1,
      30,    31,    -1,   151,   152,   153,   154,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
      -1,   169,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
     178,    -1,   180,    63,    64,    65,    66,    67,    68,    69,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    81,     5,    -1,    84,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    31,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,    -1,   168,   169,
      -1,   171,   172,   173,    -1,   175,   176,   177,   178,   179,
     180,   181,   105,    -1,   107,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    12,    -1,   132,
     133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
      -1,   144,   145,   146,    -1,    30,    31,    -1,   151,   152,
     153,   154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,   164,    -1,   166,    -1,    -1,   169,    -1,    53,   172,
     173,    -1,   175,   176,    -1,   178,    -1,   180,    63,    64,
      65,    66,    67,    68,    69,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    63,    64,    81,    -1,    -1,    84,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,
       5,   196,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    -1,   195,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,
       5,   196,     7,     8,     9,    10,    -1,    12,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,
       5,   196,     7,     8,     9,    10,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,     5,    -1,    84,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    31,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,   105,    -1,   107,
      -1,    -1,   187,   188,   189,    -1,    -1,    63,    64,    -1,
      -1,   196,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,    -1,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,
      -1,   169,    -1,    -1,   172,   173,    -1,   175,   176,    -1,
     178,    -1,   180,    -1,     4,     5,     6,    -1,    -1,    -1,
     188,    11,    -1,    -1,    -1,    15,    -1,    17,   196,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,    -1,     4,     5,     6,   167,    -1,    -1,
     170,    11,    -1,    -1,   174,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,    -1,     4,     5,     6,   167,    -1,    -1,
     170,    11,    -1,    -1,   174,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    63,    64,
      -1,    61,    62,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,    63,    64,   106,    -1,   108,   109,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   134,    63,    64,    -1,    -1,   139,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,   162,    -1,    -1,    -1,    -1,   167,    63,    64,
     170,    -1,    -1,    -1,   174,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,    -1,    -1,   197,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,    -1,    -1,   197,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,    -1,    -1,   197,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,    -1,    -1,   197,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      63,    64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
      -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,    -1,    -1,   197,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,
      64,   195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,   195,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,   195,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   189,   190,   191,   192,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,   195,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    63,    64,
     195,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,   195,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   189,
     190,   191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    63,    64,   195,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    63,    64,   195,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   182,   183,   184,   185,   186,   200,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   158,   162,   167,   170,   174,   201,   202,   205,
     206,   213,   214,   216,   217,   221,   233,   234,   239,   245,
     252,   260,   268,   271,   275,   278,   284,     3,     4,     5,
       7,     8,     9,    10,    30,    31,    63,    64,    65,    66,
      67,    68,    69,    81,    84,   101,   102,   105,   107,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     163,   164,   165,   166,   168,   169,   171,   172,   173,   175,
     176,   177,   178,   179,   180,   181,   187,   188,   189,   196,
     219,   220,   222,   228,   230,   233,   234,   196,   219,   205,
     233,   234,   239,     0,    75,   196,    75,   196,   253,   272,
     276,     4,     7,   231,   231,   231,    34,   222,   207,   208,
     219,   235,   236,   235,   219,    28,     7,   261,   269,   222,
      58,    60,    61,   198,   307,   211,   219,   222,     4,     5,
     232,   222,   219,   222,   219,   222,     4,     5,   295,   296,
      10,   189,   190,   229,   230,   297,   231,    89,    97,   198,
     219,   222,   308,    89,    97,   110,   308,   308,    88,   222,
     227,    12,    53,   227,   227,    59,    89,    90,    91,    96,
      95,   222,   214,   221,   219,   219,   219,   110,   196,   196,
     196,   196,   196,   219,   308,   219,   219,   219,    44,   203,
      92,    93,   104,    75,    75,    24,   196,   196,   196,   196,
     222,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     222,   219,   222,    70,    71,    72,    73,    74,    75,    76,
     190,    44,    63,    64,    70,    71,    72,    73,    74,    75,
      76,    77,   189,   190,   191,   192,   219,    44,    44,    44,
     222,   235,   219,   235,     4,   222,   202,    35,    36,    20,
      21,     4,     5,   246,   247,     4,     5,   248,   249,   219,
     222,   237,   238,   219,   222,   263,   202,   279,   285,   196,
      58,   196,     4,     7,   196,   219,   222,   298,    58,   198,
     300,   305,   196,   196,   195,   195,   195,   196,   196,   195,
     230,   230,   195,   222,   219,   222,    11,   195,   195,   219,
     195,   227,   212,    12,   195,   215,   195,   227,    12,   227,
     215,   215,     5,   218,   218,   218,   197,   222,   219,   195,
     195,   195,   195,    43,   227,   227,   227,   222,   219,   240,
     235,   235,   222,   222,   222,   222,   222,   222,    97,   219,
     308,   308,     4,     5,   225,   226,   225,   226,   227,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     308,   222,   222,   222,   222,   222,   222,   222,   222,   197,
     222,   219,   219,   219,   219,   219,   222,   222,   219,   222,
     197,   222,   222,   219,   222,   219,   222,   219,   219,   197,
     219,   197,   219,   197,   219,   197,   219,   219,   219,   219,
     222,   219,   219,   219,   219,   219,   219,   308,   219,   235,
     235,   219,   222,   219,   219,   219,   219,   219,   197,   197,
     219,   218,   219,   218,   219,   219,   219,   197,   197,   219,
     219,   219,   219,   219,   219,   219,   219,   224,   223,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   197,   197,    75,   273,    14,    16,    18,    41,    44,
      49,   277,   209,   210,   196,   196,   195,   196,   196,   195,
     195,    43,   262,    14,    16,    18,    41,    44,    49,   270,
      46,   202,   222,   196,   219,   222,    51,   299,   194,   195,
     196,     4,     7,   196,    10,   306,   235,   235,     4,     5,
     222,   222,   235,   235,   296,    10,   229,   195,    86,    87,
      97,   219,   222,   222,   300,   227,   219,   227,   215,   222,
     222,   196,   195,   195,   195,   197,   197,   219,   222,   219,
     222,   222,   222,   204,   195,   215,   215,     4,     5,   244,
     197,   197,   195,   195,   197,   195,   195,   195,   197,   195,
     197,   195,   197,   196,   196,   197,   197,   195,   195,   215,
     195,   197,   197,   197,   197,   197,   195,   197,   197,   195,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   195,   197,   197,   195,   195,   195,   197,   195,   195,
     197,   195,   197,   197,   197,   197,   197,   195,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   195,
     195,   195,   197,   197,   197,   197,   197,   195,   197,   197,
     197,   197,   197,   197,   195,   197,   195,   195,   195,   195,
     195,   197,   195,   195,   197,   195,   197,   197,   222,   222,
     254,   202,   222,   231,   309,   231,   310,   235,   235,   247,
     235,   235,   249,   238,    43,   264,   280,    49,    50,   286,
     195,   222,   195,   197,   197,   196,   219,   219,   222,   222,
     301,   302,   222,     4,     5,   292,   294,   197,   197,   196,
     196,   195,   195,   197,   197,   222,    85,    85,   195,   195,
     195,   227,   195,   195,   235,   222,   222,   222,   195,   195,
     206,   222,   227,   227,   241,   222,   222,   222,   222,   222,
     219,    97,   219,   197,   197,   222,   222,   227,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   219,   222,   219,
     219,   219,   219,   222,   222,   222,   222,   226,   219,   226,
     219,   219,   222,    16,    44,   274,   195,   195,   197,   197,
     197,   197,    39,    40,   266,   202,   222,   195,   219,    58,
     219,   299,   195,   292,   292,   197,   196,   196,   195,   235,
     235,   222,   222,   195,   308,   308,   219,   219,   219,   222,
     222,   197,   197,   197,   195,   197,   219,   219,   215,   196,
     197,   197,   197,   197,   197,   197,   197,   195,   197,   197,
     197,   197,   215,   197,   197,   197,   197,   197,   195,   197,
     197,   197,   195,   197,   197,   197,   195,   197,   195,   197,
     197,   197,   195,   195,   197,   195,   197,   197,   195,   197,
     197,   197,    12,   231,   231,   263,    43,    38,   281,   197,
     222,   197,   196,   195,   222,   303,   235,   235,   293,   197,
     197,   219,   195,   195,    75,    75,   222,    75,   195,   227,
       4,     5,   250,   251,   219,   222,   222,   219,   222,   222,
     219,   222,   219,   219,   222,   265,   267,    48,   288,    60,
      61,   197,    58,   222,   219,   197,   292,   197,   197,   292,
     219,   219,   219,   219,   197,   219,   222,   196,   196,   195,
     197,   197,   195,   197,   197,   197,   197,   197,   197,   197,
     197,    13,   258,   202,   202,   222,    47,   287,   196,   196,
     195,   197,   304,    75,   197,   197,   251,   242,   222,   222,
     255,    46,   291,   202,   282,   219,   222,   222,   306,   219,
     202,   197,   202,   289,    14,    16,    18,    41,    44,    49,
     283,   195,   197,   195,   197,   292,    25,    44,   243,   256,
     202,   219,   222,    14,    16,    18,    41,    44,    49,   257,
     290,   197,   197,     4,   259,   288
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   199,   200,   200,   200,   200,   200,   201,   202,   203,
     204,   202,   205,   205,   205,   205,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   206,   208,   206,   206,   206,   206,   206,   206,
     206,   209,   206,   210,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   211,   206,   212,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   213,   213,
     213,   213,   213,   214,   214,   214,   214,   214,   214,   215,
     215,   216,   216,   216,   216,   216,   217,   217,   218,   218,
     219,   219,   219,   219,   219,   219,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   221,   221,
     223,   222,   224,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   225,   226,   227,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     229,   229,   229,   230,   230,   230,   230,   231,   231,   232,
     232,   232,   232,   233,   234,   236,   235,   237,   237,   237,
     238,   238,   240,   241,   242,   239,   243,   243,   244,   244,
     245,   245,   245,   245,   246,   246,   247,   247,   247,   247,
     248,   248,   249,   249,   249,   249,   250,   250,   250,   251,
     251,   251,   251,   253,   254,   255,   256,   252,   257,   257,
     257,   257,   257,   257,   258,   258,   259,   259,   261,   260,
     262,   262,   263,   263,   264,   265,   264,   266,   267,   266,
     269,   268,   270,   270,   270,   270,   270,   270,   272,   273,
     271,   274,   274,   276,   275,   277,   277,   277,   277,   277,
     277,   279,   280,   281,   282,   278,   283,   283,   283,   283,
     283,   283,   285,   284,   286,   286,   287,   287,   288,   289,
     290,   288,   291,   291,   292,   293,   292,   294,   294,   294,
     294,   295,   295,   296,   296,   296,   296,   297,   297,   297,
     297,   298,   298,   298,   298,   298,   299,   299,   299,   301,
     300,   302,   300,   303,   300,   304,   300,   305,   300,   306,
     306,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   308,   308,   309,   309,   310,
     310
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
       4,     4,     4,     6,     4,     4,     4,     4,     4,     6,
       1,     3,     1,     3,     4,     6,     6,     4,     6,     4,
       6,    10,     4,     4,     4,     8,     6,     4,     3,     3,
       0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       3,     6,     6,     4,     4,     4,     4,     6,     6,     8,
       6,     8,     4,     4,     4,     8,     4,     4,     4,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     6,     6,     4,     6,     6,     6,     4,     8,     6,
       8,     6,     4,     4,     4,     6,     6,     6,     8,     4,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       6,     4,     6,     4,     4,     0,     2,     0,     1,     3,
       1,     1,     0,     0,     0,    11,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     3,     1,     1,     4,     4,
       1,     3,     1,     1,     4,     4,     0,     1,     3,     1,
       1,     3,     3,     0,     0,     0,     0,    14,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     1,     0,     7,
       1,     2,     1,     1,     0,     0,     5,     0,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     1,     1,     0,     4,     1,     2,     1,     1,     1,
       1,     0,     0,     0,     0,    11,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     1,     0,     2,     0,     0,
       0,     7,     0,     1,     1,     0,     4,     1,     4,     1,
       4,     1,     3,     1,     4,     1,     4,     1,     1,     3,
       3,     0,     2,     4,     1,     3,     0,     2,     6,     0,
       4,     0,     4,     0,     6,     0,     9,     0,     3,     0,
       1,     0,     2,     2,     4,     1,     4,     6,     6,     7,
      10,    12,     7,    10,    12,     2,     1,     1,     3,     1,
       3
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

  case 164: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 165: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 166: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 167: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 168: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 169: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 170: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 171: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 172: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 173: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 174: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 175: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 176: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 177: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 178: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 179: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 180: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 181: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 182: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 183: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 184: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 185: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 186: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 187: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 188: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 189: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 190: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 191: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 192: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 193: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 194: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 195: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 196: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 197: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 198: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 199: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 200: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 201: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 202: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 203: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 204: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 205: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 206: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 207: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 208: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 209: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 210: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 211: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 212: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 213: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 214: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 215: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 216: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 217: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 218: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 219: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 220: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 221: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 222: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 223: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 226: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 227: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 229: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 230: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 231: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 232: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 233: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 234: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 235: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 236: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 237: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 238: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 239: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 240: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 241: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 242: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 243: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 244: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 245: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 246: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 247: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 248: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 249: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 250: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 251: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 252: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 253: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 254: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 255: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 256: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 257: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 258: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 259: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 260: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 261: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 262: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 263: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 264: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 265: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 266: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 267: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 268: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 269: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 270: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 271: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 272: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 273: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 274: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 275: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 276: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 277: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 278: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 279: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 280: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 281: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 282: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 283: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 284: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 285: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 286: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 287: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 288: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 289: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 290: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 291: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 292: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 293: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 294: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 295: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 296: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 297: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 298: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 299: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 300: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 301: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 302: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 303: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 304: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 305: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 306: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 307: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 308: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 309: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 310: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 311: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 312: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 313: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 314: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 315: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 322: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 323: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 324: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 325: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 326: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 327: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 328: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 329: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 330: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 331: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 332: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 333: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 336: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 337: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 338: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 339: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 342: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 343: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 344: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 345: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 349: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 350: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 351: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 352: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 353: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 354: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 355: /* $@17: %empty  */
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

  case 356: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 357: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 358: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 359: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 360: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 361: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 362: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 363: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 364: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 366: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 367: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 368: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 369: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 375: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 376: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 378: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 380: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 382: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 383: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 384: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 385: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 386: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 387: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 388: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 389: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 391: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 392: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 393: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 395: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 396: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 397: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 398: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 399: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 400: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 401: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 402: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 403: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 404: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 406: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 407: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 408: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 409: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 410: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 411: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 412: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 414: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 415: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 419: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 420: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 425: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 427: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 428: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 429: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 430: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 433: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 434: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 435: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 436: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 437: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 438: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 439: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 440: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 444: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 445: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 446: /* using: %empty  */
       {create_print('d');}
    break;

  case 447: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 448: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 449: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 450: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 451: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 452: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 453: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 454: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 455: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 456: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 457: /* $@38: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 458: /* inputbody: $@38 prompt inputlist  */
                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 459: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 460: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 461: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 462: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 463: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 464: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 465: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 466: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 467: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 468: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 469: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 470: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 471: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 472: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 473: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 474: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 477: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 478: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 479: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 480: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

