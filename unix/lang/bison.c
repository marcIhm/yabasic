/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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
    written by Marc Ihm 1995-2022
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
extern int token_count; /* defined in flex */
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
int token_count_start_of_short_if=0;

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
  YYSYMBOL_tPOW = 76,                      /* tPOW  */
  YYSYMBOL_tREAD = 77,                     /* tREAD  */
  YYSYMBOL_tDATA = 78,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 79,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 80,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 81,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 82,                     /* tSEEK  */
  YYSYMBOL_tTELL = 83,                     /* tTELL  */
  YYSYMBOL_tAS = 84,                       /* tAS  */
  YYSYMBOL_tREADING = 85,                  /* tREADING  */
  YYSYMBOL_tWRITING = 86,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 87,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 88,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 89,                      /* tDOT  */
  YYSYMBOL_tLINE = 90,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 91,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 92,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 93,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 94,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 95,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 96,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 97,                     /* tWAIT  */
  YYSYMBOL_tBELL = 98,                     /* tBELL  */
  YYSYMBOL_tLET = 99,                      /* tLET  */
  YYSYMBOL_tARDIM = 100,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 101,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 102,                    /* tBIND  */
  YYSYMBOL_tRECT = 103,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 104,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 105,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 106,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 107,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 108,                     /* tNEW  */
  YYSYMBOL_tCURVE = 109,                   /* tCURVE  */
  YYSYMBOL_tSIN = 110,                     /* tSIN  */
  YYSYMBOL_tASIN = 111,                    /* tASIN  */
  YYSYMBOL_tCOS = 112,                     /* tCOS  */
  YYSYMBOL_tACOS = 113,                    /* tACOS  */
  YYSYMBOL_tTAN = 114,                     /* tTAN  */
  YYSYMBOL_tATAN = 115,                    /* tATAN  */
  YYSYMBOL_tEXP = 116,                     /* tEXP  */
  YYSYMBOL_tLOG = 117,                     /* tLOG  */
  YYSYMBOL_tSQRT = 118,                    /* tSQRT  */
  YYSYMBOL_tSQR = 119,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 120,                   /* tMYEOF  */
  YYSYMBOL_tABS = 121,                     /* tABS  */
  YYSYMBOL_tSIG = 122,                     /* tSIG  */
  YYSYMBOL_tINT = 123,                     /* tINT  */
  YYSYMBOL_tCEIL = 124,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 125,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 126,                    /* tFRAC  */
  YYSYMBOL_tROUND = 127,                   /* tROUND  */
  YYSYMBOL_tMOD = 128,                     /* tMOD  */
  YYSYMBOL_tRAN = 129,                     /* tRAN  */
  YYSYMBOL_tVAL = 130,                     /* tVAL  */
  YYSYMBOL_tLEFT = 131,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 132,                   /* tRIGHT  */
  YYSYMBOL_tMID = 133,                     /* tMID  */
  YYSYMBOL_tLEN = 134,                     /* tLEN  */
  YYSYMBOL_tMIN = 135,                     /* tMIN  */
  YYSYMBOL_tMAX = 136,                     /* tMAX  */
  YYSYMBOL_tSTR = 137,                     /* tSTR  */
  YYSYMBOL_tINKEY = 138,                   /* tINKEY  */
  YYSYMBOL_tCHR = 139,                     /* tCHR  */
  YYSYMBOL_tASC = 140,                     /* tASC  */
  YYSYMBOL_tHEX = 141,                     /* tHEX  */
  YYSYMBOL_tDEC = 142,                     /* tDEC  */
  YYSYMBOL_tBIN = 143,                     /* tBIN  */
  YYSYMBOL_tUPPER = 144,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 145,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 146,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 147,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 148,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 149,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 150,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 151,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 152,                   /* tRTRIM  */
  YYSYMBOL_tINSTR = 153,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 154,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 155,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 156,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 157,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 158,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 159,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 160,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 161,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 162,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 163,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 164,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 165,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 166,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 167,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 168,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 169,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 170,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 171,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 172,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 173,                    /* tDATE  */
  YYSYMBOL_tTIME = 174,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 175,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 176,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 177,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 178,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 179,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 180,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 181,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 182, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 183,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 184, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 185,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 186,                   /* tEVAL2  */
  YYSYMBOL_187_ = 187,                     /* '-'  */
  YYSYMBOL_188_ = 188,                     /* '+'  */
  YYSYMBOL_189_ = 189,                     /* '*'  */
  YYSYMBOL_190_ = 190,                     /* '/'  */
  YYSYMBOL_UMINUS = 191,                   /* UMINUS  */
  YYSYMBOL_192_ = 192,                     /* ';'  */
  YYSYMBOL_193_ = 193,                     /* ','  */
  YYSYMBOL_194_ = 194,                     /* '('  */
  YYSYMBOL_195_ = 195,                     /* ')'  */
  YYSYMBOL_196_ = 196,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 197,                 /* $accept  */
  YYSYMBOL_program_or_expression = 198,    /* program_or_expression  */
  YYSYMBOL_program = 199,                  /* program  */
  YYSYMBOL_statement_list = 200,           /* statement_list  */
  YYSYMBOL_201_1 = 201,                    /* $@1  */
  YYSYMBOL_assignment = 202,               /* assignment  */
  YYSYMBOL_statement = 203,                /* statement  */
  YYSYMBOL_204_2 = 204,                    /* $@2  */
  YYSYMBOL_205_3 = 205,                    /* $@3  */
  YYSYMBOL_206_4 = 206,                    /* $@4  */
  YYSYMBOL_207_5 = 207,                    /* $@5  */
  YYSYMBOL_208_6 = 208,                    /* $@6  */
  YYSYMBOL_209_7 = 209,                    /* $@7  */
  YYSYMBOL_clear_fill_clause = 210,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 211,        /* string_assignment  */
  YYSYMBOL_to = 212,                       /* to  */
  YYSYMBOL_open_clause = 213,              /* open_clause  */
  YYSYMBOL_seek_clause = 214,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 215,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 216,        /* string_expression  */
  YYSYMBOL_string_function = 217,          /* string_function  */
  YYSYMBOL_number_assignment = 218,        /* number_assignment  */
  YYSYMBOL_expression = 219,               /* expression  */
  YYSYMBOL_220_8 = 220,                    /* $@8  */
  YYSYMBOL_221_9 = 221,                    /* $@9  */
  YYSYMBOL_arrayref = 222,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 223,          /* string_arrayref  */
  YYSYMBOL_coordinates = 224,              /* coordinates  */
  YYSYMBOL_function = 225,                 /* function  */
  YYSYMBOL_const = 226,                    /* const  */
  YYSYMBOL_number = 227,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 228,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 229,                  /* dimlist  */
  YYSYMBOL_function_or_array = 230,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 231,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 232,                /* call_list  */
  YYSYMBOL_233_10 = 233,                   /* $@10  */
  YYSYMBOL_calls = 234,                    /* calls  */
  YYSYMBOL_call_item = 235,                /* call_item  */
  YYSYMBOL_function_definition = 236,      /* function_definition  */
  YYSYMBOL_237_11 = 237,                   /* $@11  */
  YYSYMBOL_238_12 = 238,                   /* $@12  */
  YYSYMBOL_239_13 = 239,                   /* $@13  */
  YYSYMBOL_endsub = 240,                   /* endsub  */
  YYSYMBOL_function_name = 241,            /* function_name  */
  YYSYMBOL_export = 242,                   /* export  */
  YYSYMBOL_local_list = 243,               /* local_list  */
  YYSYMBOL_local_item = 244,               /* local_item  */
  YYSYMBOL_static_list = 245,              /* static_list  */
  YYSYMBOL_static_item = 246,              /* static_item  */
  YYSYMBOL_paramlist = 247,                /* paramlist  */
  YYSYMBOL_paramitem = 248,                /* paramitem  */
  YYSYMBOL_for_loop = 249,                 /* for_loop  */
  YYSYMBOL_250_14 = 250,                   /* $@14  */
  YYSYMBOL_251_15 = 251,                   /* $@15  */
  YYSYMBOL_252_16 = 252,                   /* $@16  */
  YYSYMBOL_253_17 = 253,                   /* $@17  */
  YYSYMBOL_next = 254,                     /* next  */
  YYSYMBOL_step_part = 255,                /* step_part  */
  YYSYMBOL_next_symbol = 256,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 257,  /* switch_number_or_string  */
  YYSYMBOL_258_18 = 258,                   /* $@18  */
  YYSYMBOL_sep_list = 259,                 /* sep_list  */
  YYSYMBOL_number_or_string = 260,         /* number_or_string  */
  YYSYMBOL_case_list = 261,                /* case_list  */
  YYSYMBOL_262_19 = 262,                   /* $@19  */
  YYSYMBOL_default = 263,                  /* default  */
  YYSYMBOL_264_20 = 264,                   /* $@20  */
  YYSYMBOL_do_loop = 265,                  /* do_loop  */
  YYSYMBOL_266_21 = 266,                   /* $@21  */
  YYSYMBOL_loop = 267,                     /* loop  */
  YYSYMBOL_while_loop = 268,               /* while_loop  */
  YYSYMBOL_269_22 = 269,                   /* $@22  */
  YYSYMBOL_270_23 = 270,                   /* $@23  */
  YYSYMBOL_wend = 271,                     /* wend  */
  YYSYMBOL_repeat_loop = 272,              /* repeat_loop  */
  YYSYMBOL_273_24 = 273,                   /* $@24  */
  YYSYMBOL_until = 274,                    /* until  */
  YYSYMBOL_if_clause = 275,                /* if_clause  */
  YYSYMBOL_276_25 = 276,                   /* $@25  */
  YYSYMBOL_277_26 = 277,                   /* $@26  */
  YYSYMBOL_278_27 = 278,                   /* $@27  */
  YYSYMBOL_279_28 = 279,                   /* $@28  */
  YYSYMBOL_endif = 280,                    /* endif  */
  YYSYMBOL_short_if = 281,                 /* short_if  */
  YYSYMBOL_282_29 = 282,                   /* $@29  */
  YYSYMBOL_end_of_if = 283,                /* end_of_if  */
  YYSYMBOL_else_part = 284,                /* else_part  */
  YYSYMBOL_elsif_part = 285,               /* elsif_part  */
  YYSYMBOL_286_30 = 286,                   /* $@30  */
  YYSYMBOL_287_31 = 287,                   /* $@31  */
  YYSYMBOL_maybe_then = 288,               /* maybe_then  */
  YYSYMBOL_inputlist = 289,                /* inputlist  */
  YYSYMBOL_290_32 = 290,                   /* $@32  */
  YYSYMBOL_input = 291,                    /* input  */
  YYSYMBOL_readlist = 292,                 /* readlist  */
  YYSYMBOL_readitem = 293,                 /* readitem  */
  YYSYMBOL_datalist = 294,                 /* datalist  */
  YYSYMBOL_printlist = 295,                /* printlist  */
  YYSYMBOL_using = 296,                    /* using  */
  YYSYMBOL_inputbody = 297,                /* inputbody  */
  YYSYMBOL_298_33 = 298,                   /* $@33  */
  YYSYMBOL_299_34 = 299,                   /* $@34  */
  YYSYMBOL_300_35 = 300,                   /* $@35  */
  YYSYMBOL_301_36 = 301,                   /* $@36  */
  YYSYMBOL_302_37 = 302,                   /* $@37  */
  YYSYMBOL_prompt = 303,                   /* prompt  */
  YYSYMBOL_printintro = 304,               /* printintro  */
  YYSYMBOL_hashed_number = 305,            /* hashed_number  */
  YYSYMBOL_goto_list = 306,                /* goto_list  */
  YYSYMBOL_gosub_list = 307                /* gosub_list  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   6134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  476
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   442


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
       2,     2,     2,     2,     2,   196,     2,     2,     2,     2,
     194,   195,   189,   188,   193,   187,     2,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   192,
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
     185,   186,   191
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   192,   192,   193,   194,   195,   196,   199,   202,   203,
     203,   207,   208,   209,   210,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   228,   229,   229,   230,   231,   232,   233,   234,   235,
     236,   236,   238,   238,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   250,   251,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   268,   269,   270,
     271,   272,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   323,   324,   325,
     326,   327,   331,   332,   333,   334,   335,   336,   339,   340,
     343,   344,   345,   346,   347,   350,   351,   354,   355,   358,
     359,   360,   361,   362,   363,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   409,   410,   413,   413,
     414,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   447,   450,   453,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   529,   530,   531,   534,
     535,   536,   537,   540,   541,   544,   545,   546,   547,   550,
     553,   556,   556,   559,   560,   561,   564,   565,   568,   569,
     572,   568,   577,   578,   581,   582,   585,   586,   587,   588,
     591,   592,   595,   596,   597,   598,   601,   602,   605,   606,
     607,   608,   611,   612,   613,   616,   617,   618,   619,   622,
     623,   628,   643,   622,   648,   649,   650,   651,   652,   653,
     656,   657,   660,   661,   666,   666,   670,   671,   674,   675,
     679,   681,   680,   685,   686,   686,   690,   690,   696,   697,
     698,   699,   700,   701,   705,   706,   705,   712,   713,   717,
     717,   722,   723,   724,   725,   726,   727,   730,   731,   731,
     733,   730,   737,   738,   739,   740,   741,   742,   745,   745,
     750,   751,   754,   755,   758,   760,   762,   759,   766,   767,
     770,   771,   771,   774,   775,   777,   778,   782,   783,   786,
     787,   789,   790,   794,   795,   796,   797,   800,   801,   802,
     803,   804,   807,   808,   809,   812,   812,   813,   813,   814,
     814,   815,   815,   816,   816,   819,   820,   823,   824,   825,
     826,   827,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   839,   840,   842,   843,   846,   847
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
  "tGTN", "tEQU", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN", "tCLOSE",
  "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN", "tWINDOW",
  "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR", "tFILL",
  "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE", "tBIND",
  "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE",
  "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG",
  "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR",
  "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID",
  "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC",
  "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM",
  "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2",
  "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE",
  "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
  "program_or_expression", "program", "statement_list", "$@1",
  "assignment", "statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@8", "$@9",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    45,    43,    42,
      47,   442,    59,    44,    40,    41,    35
};
#endif

#define YYPACT_NINF (-825)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-398)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -77,  4059,  3546,  1605,    85,   161,    69,   -48,   -36,  -825,
    -825,  -825,  -825,  -825,    75,    75,    75,  3170,  -825,  -825,
    -825,  1605,  -825,  -825,  1605,    52,   108,  -825,  -825,  -825,
    3546,   -35,  -825,  3546,   262,  -825,  3546,  3546,  3546,   301,
      43,    75,  1821,  1188,  2209,     8,  3546,  2982,  3546,   199,
      30,  3546,  -825,   106,  1605,  1605,  1605,    41,    28,    63,
      83,    97,    99,  2209,  1605,  1605,  1605,  -825,   120,  -825,
    -825,   -37,  -825,  -825,  -825,  -825,   117,   137,  -825,   208,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,   136,   138,
    -825,  -825,  -825,  -825,   154,   163,   166,   174,  3546,   189,
     206,   227,   237,   243,   245,   267,   309,   317,   335,   350,
     356,   360,   366,   417,   430,   434,   436,   442,   464,   473,
     486,   494,   507,   539,   550,   554,   559,   563,   566,   567,
     575,   576,   577,   578,   579,   580,   581,   586,   587,   591,
     602,   603,   604,   605,   609,   611,   612,   613,   621,   622,
     623,   624,   627,   629,   632,   633,   634,   635,   637,   638,
     639,   641,   646,   650,   651,   654,   655,   656,   657,   660,
     664,   665,   666,   667,   668,   669,   674,  3546,  3546,   352,
    -825,   503,  -825,  -825,  -825,  -825,  1605,   -14,   235,   117,
     137,   391,  -825,  3546,  -825,  1605,  -825,   383,  3546,  3901,
    -825,  -825,  -825,  -825,  -825,   323,    64,   365,   367,   269,
    -825,  3546,  -825,   269,  -825,  -825,  3546,  3901,   522,   675,
     401,   677,     7,  3546,   -34,   352,  3762,   681,   684,   280,
    3762,   352,  5234,   352,  5268,   689,   690,   453,  -825,  -825,
     170,   170,  -825,  -825,   455,  -825,  3546,  1605,  3546,    27,
    3762,   484,  -825,  -825,  -825,  -825,   530,  1605,  5286,  -825,
    3546,  -825,     0,   626,  -825,  -825,  3546,  3358,  -825,  -825,
    3762,  -825,  -825,   269,    -6,    -6,  -825,   489,   489,   489,
    2403,  1605,   532,   683,   269,    31,    55,  -825,   827,  3546,
    3546,  3546,  3546,  1605,  -825,  -825,  -825,  3546,  3546,   883,
    3546,  3546,  3546,  3546,  2015,  2209,   397,   397,  3546,  3546,
    3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,
    2209,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  2596,
    1605,  1605,  1605,  1605,  1605,  3546,  3546,  3546,  2789,  3546,
    1605,  3546,  1605,  3546,  1605,  1605,   375,  1265,  1390,  1534,
    1605,  1605,  1605,  1605,  1605,  1605,  1605,  1605,  2209,  1605,
    -825,  -825,  1605,  3546,  1605,  1605,  1605,  1605,  1605,   557,
     679,  1605,   489,  1605,   489,  1605,  1605,  1605,   809,    47,
    1399,  1605,  1605,  1605,  1605,  1605,  1605,  1605,  -825,  -825,
    -825,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,  3546,
    3546,  3546,  -151,  -825,  -825,  -825,  3762,   691,   269,   694,
     812,  3762,    42,  -825,  -825,  -825,  -825,   696,   702,   704,
    -825,   705,   706,   708,  -825,   352,  3762,   712,  -825,   352,
    3762,   855,   414,   856,  3901,  3546,   717,  1605,  -825,  -825,
    3546,   352,   692,   211,   722,    13,  -825,   893,  -825,  -825,
     558,  3546,  3546,  -825,  -825,   301,  -825,  -825,    68,  5300,
     269,  3762,   571,  3622,  3546,   269,  3546,  -825,   -34,  -825,
    -825,  3546,  1605,  -825,  3546,     0,  3546,  3546,   723,   720,
     725,   726,  -825,  1413,  -131,  3546,  3546,  3546,  3546,  3901,
     728,     0,     0,  3762,   269,   682,   729,   735,  5362,  5376,
    1651,  5396,  5428,  5442,   737,   303,   730,   739,   741,   742,
     744,   745,   736,   748,     0,  5456,  2033,  2227,  2614,  2810,
    2996,   719,  3184,   738,  3372,  3777,   756,  3955,  4113,  4212,
    4257,  4271,  4288,  4320,  5470,  -825,  4340,  -125,    87,    88,
     152,  -107,  5504,  5524,   292,   874,  -825,  4354,  4416,   -79,
    4430,     2,  4448,   -62,   -46,  -825,    -7,  -825,    25,  -825,
     109,  -825,   143,   193,   265,   302,   263,   289,   314,   364,
     376,   343,   757,    11,   766,   767,   377,  4482,   392,   191,
     300,   482,   483,  -825,  -825,   501,  -101,   509,   -70,   512,
     393,   394,  -825,  -825,   269,   269,   269,   269,   269,   269,
    -825,  3546,  3546,   896,   368,   334,    38,    72,   -58,  -825,
      -4,    -4,   809,   809,  -825,  -825,  -825,  3901,  -825,  -825,
    3546,  -825,  -825,  -825,  -825,    75,    75,  -825,  -825,   365,
    -825,  -825,   367,  3546,  -825,   900,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,   649,  5538,  3546,   241,  4496,  2480,
    -825,  -825,  3546,  3546,  -825,  -825,  3546,  -825,   709,   768,
     769,   771,   780,  5598,  5612,   781,   786,  -825,  -825,  -825,
    3546,   898,   899,  -825,   529,  5632,  3762,  -825,  -825,   541,
    -825,  3546,  5666,  5680,  -825,  3546,  3546,  3546,  -825,  -825,
     352,  3762,   352,  3762,  5694,  5708,  -825,  3546,  3546,  3546,
    -825,  -825,  -825,  -825,  -825,  3546,  3546,  -825,  3546,  3546,
    3546,  -825,  1605,  -825,  3725,  -825,   789,   790,  -825,  -825,
    3546,  3546,  3546,  3546,  -825,  -825,  -825,  -825,  -825,  3546,
    -825,  -825,  3546,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  3546,  -825,  -825,  3546,  3546,  3546,
    -825,  3546,  3546,  -825,  1605,  -825,  -825,  -825,  -825,  -825,
    3546,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  1605,  1605,  -825,  -825,  -825,  -825,  -825,  1605,
    -825,  -825,  -825,  -825,  -825,  -825,  3546,  -825,  3546,  3546,
    3546,   981,  1605,  -825,   981,  1605,  -825,  1605,  -825,  -825,
     883,  5944,  3546,    29,  3762,  -825,   795,  -825,   797,   796,
     800,  -825,   802,   803,  -825,  -825,  -825,   676,  3901,  -825,
    -825,  -825,  3546,  5740,  1605,   934,  -825,  1605,   269,   352,
     692,  5760,   709,   709,  4510,   813,   814,  -825,   816,  -825,
    -825,  -825,  -825,  3546,  3546,  -825,  -825,  5774,  2209,  2209,
    1605,  1605,  1605,  -825,  3546,  3546,   815,  4524,  4558,   930,
    1605,  1605,  3762,     0,  -825,   817,  4576,  4590,  4652,  4666,
    4686,   395,   818,   259,  -825,  -825,  4718,  4732,   819,    81,
    4746,  4760,  4794,  4814,  4828,  1315,  4888,  4902,   277,  4922,
     283,   322,   396,  4956,  5836,  5850,  4970,   -30,   413,     5,
     421,   422,    96,  -825,  -825,  -825,    75,    75,  -825,  -825,
    -825,  -825,  3546,   973,   980,   976,  4984,  3546,   424,   826,
     340,  -825,  3546,  -825,  -825,  -825,  -825,  -825,  -825,   828,
     830,  3762,  3762,  1605,  -825,  -825,   269,   269,   543,  5868,
    3762,  -825,   946,   947,  3546,   951,   544,   269,  3546,   734,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  1605,  -825,  -825,
    -825,  -825,  3546,  -825,  -825,  -825,  -825,  -825,  3546,  -825,
    -825,  -825,  1605,  -825,  -825,  3546,  -825,  3546,  -825,  -825,
    -825,  1605,  3546,  -825,  1605,  -825,  -825,  1605,  -825,  -825,
    -825,  3546,  -825,  -825,  -825,  -825,  -825,   979,   680,  4998,
     970,  3546,  1605,  5030,   709,   834,   835,   709,  -825,  -825,
     269,  1605,  1605,  1605,  1605,  5050,  1605,  3546,  -825,   837,
     838,    15,  -825,   427,  5902,  5064,   437,  5126,  5140,   438,
    5158,   439,   450,   279,  3901,  4217,  3546,   986,  -825,   841,
    -825,   842,  5916,   452,  -825,  -825,  -825,  -825,  -825,   269,
     269,   269,   269,   962,   269,  3762,   843,   844,   734,  -825,
    -825,  3546,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    3546,  -825,   976,  1004,   589,  3901,  -825,  1605,  3546,  3546,
    -825,   893,  1605,  -825,  -825,  -825,  3901,  5192,  3762,  3901,
    -825,  -825,   976,   625,   348,  5930,  5206,   709,   269,    18,
    -825,   976,  3901,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    1605,  -825,  3546,  -825,  -825,  -825,  -825,  -825,   710,   976,
     454,  5220,  -825,  -825,  -825,  -825,  -825,  -825,  1039,   979,
    -825,  -825,  -825,  -825,  -825
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   117,     0,     0,     0,   326,     0,     0,     0,   111,
     349,   384,   389,    17,     0,     0,     0,     0,    30,    32,
     327,     0,   311,   311,     0,   328,    24,    26,   364,   376,
       0,   457,    54,    66,     0,   108,   109,     0,     0,     0,
       0,    64,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,     0,     2,     9,    16,
       8,     0,    11,    45,    47,    13,    28,    29,    27,     0,
      19,    20,    23,    22,    21,    34,    35,   299,   207,   139,
     300,   301,   302,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,   266,   269,   272,   275,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,   220,   201,   206,   141,     0,     0,     0,     0,
       0,     0,     1,     0,   311,     0,   311,     0,     0,    15,
     304,   303,    36,    37,    44,     0,     0,     0,     0,    18,
      49,   313,    50,    48,   329,    25,     0,    15,   408,     0,
     461,     0,     0,   437,   453,    68,    67,     0,     0,    69,
     110,    59,     0,    61,     0,   429,   431,    62,   427,   433,
       0,     0,   434,   296,    63,    65,     0,    95,     0,     0,
     472,     0,    92,    97,    85,    46,     0,     0,     0,    73,
       0,    56,    78,     0,    94,    93,     0,     0,   120,   121,
      98,    12,    14,   112,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     7,     0,     0,
       0,     0,     0,     0,   318,   311,   311,     0,     0,   192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     311,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,   190,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,   186,     0,   122,     0,
       0,   385,     9,    38,    39,    40,    42,   332,   333,    31,
     330,   338,   339,    33,   336,   316,   317,   312,   314,   369,
     368,     0,     9,     0,    15,     0,     0,     0,   458,   459,
       0,   440,   442,    51,     0,     0,    55,   455,   311,   311,
       0,     0,     0,   311,   311,     0,   298,   297,     0,     0,
      96,   471,     0,     0,     0,    72,     0,    77,   453,   129,
     128,     0,     0,    74,     0,    80,     0,     0,   137,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,   187,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,   267,     0,   270,     0,   273,
       0,   276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   171,     0,     0,     0,     0,     0,
       0,     0,   144,   221,   215,   217,   219,   216,   218,   214,
     143,     0,     0,   194,   196,   198,   195,   197,   193,   212,
     209,   208,   210,   211,   309,   310,   350,    15,   396,   394,
       0,   395,   391,   393,   390,     0,     0,   311,   311,     0,
     311,   311,     0,     0,   366,   370,   383,   381,   382,   379,
     378,   380,   377,   398,     9,     0,     0,     0,     0,     0,
     438,    52,    53,     0,   445,   447,     0,   456,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,   435,   436,
       0,     0,     0,   132,   131,   135,   224,    57,    75,    88,
      79,     0,     0,     0,   311,     0,     0,     0,   102,   103,
     104,   105,   106,   107,     0,     0,    10,     0,     0,     0,
     324,   325,   319,   288,   182,     0,     0,   279,     0,     0,
       0,   289,     0,   290,     0,   283,     0,     0,   202,   203,
       0,     0,     0,     0,   225,   226,   227,   228,   229,     0,
     230,   232,     0,   233,   235,   236,   199,   242,   243,   237,
     239,   240,   241,   238,     0,   245,   250,     0,     0,     0,
     249,     0,     0,   152,     0,   149,   155,   156,   251,   180,
       0,   252,   181,   157,   158,   265,   268,   271,   274,   161,
     159,   160,     0,     0,   162,   258,   163,   264,   263,     0,
     172,   259,   164,   260,   165,   262,     0,   166,     0,     0,
       0,     0,     0,   175,     0,     0,   177,     0,   295,   185,
     191,   189,     0,     9,   392,   473,    41,   475,    43,     0,
       0,   331,     0,     0,   337,   315,   367,   373,    15,   410,
     411,   409,     0,     0,     0,   462,   460,     0,   443,   441,
     442,     0,     0,     0,     0,   423,   425,   454,   420,   305,
     307,   311,   311,     0,     0,   430,   432,    70,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,   387,   386,     0,     0,   334,   335,
     340,   341,     0,     0,     0,   399,     0,     0,     0,     0,
       0,   439,     0,   446,   448,   449,   311,   311,   421,     0,
       0,    58,    60,     0,   133,   134,   130,   136,    89,    82,
      83,   138,     0,     0,     0,     0,   115,   116,     0,   342,
     277,   278,   280,   281,   282,   291,   292,     0,   293,   204,
     205,   178,     0,   231,   234,   244,   145,   146,     0,   148,
     247,   248,     0,   150,   253,     0,   254,     0,   256,   173,
     167,     0,     0,   184,     0,   285,   174,     0,   287,   176,
     200,     0,   474,   476,   371,   374,   365,   414,   464,     0,
     463,     0,     0,     0,     0,     0,     0,     0,   306,   308,
      71,     0,     0,     0,     0,     0,     0,     0,    87,   345,
     346,     0,   343,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,    15,   117,     0,   412,   468,     0,
     465,     0,     0,     0,   451,   450,   424,   426,   422,    90,
      81,   125,   126,     0,   124,   114,     0,     0,     0,   320,
     294,     0,   147,   151,   255,   257,   261,   183,   284,   286,
       0,   351,   372,     9,   418,    15,   400,     0,     0,     0,
     444,   455,     0,   347,   348,   344,    15,     0,   361,    15,
     419,   415,   413,     0,     0,     0,     0,     0,   123,     9,
     179,   352,    15,   407,   404,   405,   406,   402,   403,   401,
       0,   469,     0,   466,   452,   323,   322,   321,     0,   416,
       0,     0,   355,   357,   358,   359,   354,   356,   362,   414,
     470,   467,   363,   353,   417
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -825,  -825,  -825,  -198,  -825,  1040,   556,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,   996,  -242,  -825,  -825,  -231,   801,
    -825,   997,    -2,  -825,  -825,   746,  -302,   -26,  -825,   593,
     -38,   -12,  -825,     6,    12,    51,  -825,  -825,   419,  1049,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,   426,  -825,   425,
    -825,    16,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,   144,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,
    -825,  -825,  -825,  -825,  -825,  -825,  -825,  -825,   -69,  -825,
    -825,  -825,  -824,  -825,  -825,  -825,   610,  -825,  -825,   236,
     607,  -825,  -825,  -825,  -825,  -825,    -3,  -825,    24,  -825,
    -825
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    67,    68,   288,    69,    70,   207,   208,   625,
     626,   224,   468,    71,    72,   471,    73,    74,   479,   179,
     180,    75,   258,   602,   601,   510,   511,   259,   182,   242,
     183,   202,   229,   184,   185,   210,   211,   427,   428,    78,
     495,   865,  1086,  1117,   702,    79,   419,   420,   423,   424,
    1021,  1022,    80,   197,   802,  1089,  1118,  1128,  1071,  1133,
      81,   216,   635,   431,   817,  1034,   914,  1035,    82,   217,
     642,    83,   198,   617,   905,    84,   199,   624,    85,   433,
     818,   997,  1093,  1109,    86,   434,   821,  1076,  1037,  1102,
    1129,  1091,   837,  1007,   838,   237,   238,   244,   443,   650,
     446,   832,   833,  1004,  1081,   447,   658,   223,   251,   806,
     808
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     181,   412,   243,   203,   204,   513,   469,    76,   923,   924,
     189,   438,   469,    77,   439,   206,   190,   654,   397,   432,
     655,   262,   263,   219,   444,   220,   221,   193,   218,   245,
     403,   226,   476,   477,   230,   232,   234,   387,   462,   195,
     250,   250,   250,  1115,   592,   903,    87,   480,   481,   270,
      90,    91,    92,   239,   289,   290,   618,   387,   619,   189,
     620,   250,  1116,   387,   689,   190,   291,   255,   256,   192,
     746,    87,   397,   904,   212,    90,    91,    92,   668,   200,
     214,   387,   201,   621,   415,   416,   622,   283,   750,     7,
       8,   623,   792,   469,   793,   257,   299,   381,   382,   383,
     384,   385,   386,     1,     2,     3,     4,     5,   991,   387,
       7,     8,   395,   396,   397,   215,   758,   381,   382,   383,
     384,   385,   386,   795,   269,   796,   387,   389,   390,   398,
     399,   400,   401,   763,   391,   392,   393,   394,   395,   396,
     397,   586,   387,   588,   389,   390,   194,   396,   397,   764,
     276,   391,   392,   393,   394,   395,   396,   397,   196,   389,
     390,   222,   445,   984,   287,   985,   391,   392,   393,   394,
     395,   396,   397,    87,   387,   378,   380,    90,    91,    92,
    1045,   387,   387,  1048,    53,   400,   401,   470,   765,    20,
     387,   406,   292,   470,    25,   760,   411,   761,   987,   387,
     988,   440,   456,   457,   779,    76,   780,   656,  1058,   426,
    1059,    77,   293,   387,   430,   387,    58,    59,    60,   387,
     766,   442,   277,    76,   487,   398,   399,   400,   401,    77,
     240,   241,   294,   681,   467,   387,   644,    58,    59,    60,
     473,   475,   592,   387,   459,   407,   461,   409,   488,   698,
     699,   398,   399,   400,   401,   240,   241,   278,   264,   398,
     399,   400,   401,   490,   491,   492,   227,   228,   398,   399,
     400,   401,   722,  1114,   470,   387,   387,   279,   483,   404,
     747,   748,   514,   398,   399,   400,   401,   265,   266,   267,
     493,   280,  1070,   281,   268,   498,   499,   387,   500,   501,
     502,   503,   250,   250,   767,   235,   236,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   250,   527,
     528,   529,   530,   531,   532,   533,   534,   536,   506,   507,
     194,   387,   196,   542,   543,   545,   547,   548,   768,   550,
     387,   552,   389,   390,   526,   749,   496,   497,   295,   391,
     392,   393,   394,   395,   396,   397,   250,   296,   413,   414,
     297,   577,   381,   382,   383,   384,   385,   386,   298,   417,
     418,   421,   422,   381,   382,   383,   384,   385,   386,   387,
      89,   387,   572,   300,   786,    93,   787,   410,   769,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     301,   508,   509,   651,   652,   392,    95,   394,   395,   396,
     397,   574,   575,   381,   382,   383,   384,   385,   386,   803,
     243,   302,   381,   382,   383,   384,   385,   386,   636,   387,
     637,   303,   638,   645,   824,   405,   825,   304,   648,   305,
      76,   394,   395,   396,   397,   678,    77,   387,   680,   663,
     664,   387,   957,   387,   958,   639,   772,   387,   640,   436,
     770,   306,   675,   641,   676,   387,   398,   399,   400,   401,
     972,   387,   973,   450,   682,   683,   975,   387,   976,   107,
     387,   108,   773,   691,   693,   694,   695,   753,   387,   897,
     387,   387,   899,   788,   478,    76,   712,   771,   713,   659,
     660,    77,   387,   307,   665,   666,   130,   131,   132,   774,
     387,   308,   136,   137,   138,   977,   140,   978,   142,   143,
     144,   398,   399,   400,   401,   149,   150,   151,   387,   309,
     154,   387,   156,  1002,   158,   592,   387,   160,   777,   162,
     387,  1110,   164,  1111,   310,   166,   167,   388,   168,   169,
     311,   171,   387,   173,   312,   398,   399,   400,   401,   775,
     313,   176,   661,   662,   387,   387,   389,   390,  -397,   186,
     555,   776,   783,   391,   392,   393,   394,   395,   396,   397,
     387,   387,   387,   387,   387,   389,   390,   785,   798,   799,
     955,   979,   391,   392,   393,   394,   395,   396,   397,   800,
     801,   387,   381,   382,   383,   384,   385,   386,   986,   387,
     387,   314,   387,   805,   807,   387,   989,   990,   804,  1000,
     915,   948,  1060,    76,   315,   387,   387,   387,   316,    77,
     317,   426,  1063,  1066,  1068,  1090,   318,   962,   387,  1103,
     387,  1104,   387,  1105,   823,  1069,   455,  1080,   458,  1130,
     830,   831,   389,   390,   834,   853,   671,   672,   319,   391,
     392,   393,   394,   395,   396,   397,  1106,   320,   847,  1107,
     387,   387,   863,   864,  1108,   789,   790,   463,   809,   810,
     321,   812,   813,   857,   858,   859,   700,   701,   322,   387,
     398,   399,   400,   401,   791,   862,   878,   387,   819,   820,
     387,   323,   794,   866,   867,   797,   868,   869,   870,   398,
     399,   400,   401,   835,   836,   912,   913,   387,   876,   877,
     387,   879,   850,   464,  1122,   485,  1123,   880,  1124,   387,
     881,   387,   387,   324,   852,   856,  1011,  1017,  1019,  1020,
    1038,  1039,   882,   649,   325,   883,   884,   885,   326,   886,
     887,  1125,   583,   327,  1126,   389,   390,   328,   889,  1127,
     329,   330,   391,   392,   393,   394,   395,   396,   397,   331,
     332,   333,   334,   335,   336,   337,   398,   399,   400,   401,
     338,   339,   389,   390,   893,   340,   894,   895,   896,   391,
     392,   393,   394,   395,   396,   397,   341,   342,   343,   344,
     902,   389,   390,   345,   187,   346,   347,   348,   391,   392,
     393,   394,   395,   396,   397,   349,   350,   351,   352,   472,
     916,   353,   209,   354,    76,   213,   355,   356,   357,   358,
      77,   359,   360,   361,   225,   362,  1072,  1073,   231,   233,
     363,   931,   932,   249,   364,   365,   250,   250,   366,   367,
     368,   369,   939,   940,   370,   273,   274,   275,   371,   372,
     373,   374,   375,   376,   282,   284,   285,   286,   377,   435,
     489,   437,   934,   935,   584,   448,   486,  1092,   449,   398,
     399,   400,   401,   453,   454,   397,   614,   616,  1099,   615,
     627,  1101,   929,   930,   992,   993,   628,   629,   634,   630,
     631,   632,   643,   657,  1119,   633,   398,   399,   400,   401,
     430,   646,   729,   685,   730,   999,   653,   684,   686,   687,
    1003,   697,  1018,   714,   703,   398,   399,   400,   401,   720,
     704,   732,   711,   733,   715,   716,   717,   389,   390,   718,
     719,   721,  1015,   816,   391,   392,   393,   394,   395,   396,
     397,   736,   778,   391,   392,   393,   394,   395,   396,   397,
    1024,   781,   782,   839,   840,   841,  1025,   392,   393,   394,
     395,   396,   397,  1027,   842,  1028,   845,  1005,  1006,   379,
    1030,   846,   848,   849,   874,   875,   509,   402,   906,  1033,
     907,   908,   919,   389,   390,   909,   408,   910,   911,  1042,
     391,   392,   393,   394,   395,   396,   397,   926,   927,   928,
     941,   949,   425,   956,   961,  1055,   995,   429,   996,    -9,
    1001,  1013,  1014,  1008,   441,  1009,  1016,  1036,  1041,  1046,
    1047,  1056,  1057,  1075,  1074,  1077,  1078,  1082,  1083,  1084,
      76,    76,  -375,  1132,   188,   696,    77,    77,   460,   271,
     272,   669,   815,   512,   191,   811,   994,   814,   465,  1087,
    1134,   398,   399,   400,   401,   667,   921,   754,  1088,   755,
     398,   399,   400,   401,  1085,   677,  1095,  1096,  1097,     0,
       0,    76,   484,   398,   399,   400,   401,    77,     0,     0,
       0,     0,    76,     0,   494,    76,     0,     0,    77,     0,
       0,    77,     0,     0,     0,   505,     0,     0,    76,     0,
    1121,     0,     0,     0,    77,     0,     0,   398,   399,   400,
     401,     0,     0,   944,     0,   945,     0,     0,     0,     0,
       0,   537,   538,   539,   540,   541,     0,     0,   544,     0,
       0,   549,     0,   551,     0,   553,   554,   556,   558,   560,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     573,     0,     0,   576,     0,   578,   579,   580,   581,   582,
       0,     0,   585,     0,   587,     0,   589,   590,   591,     0,
       0,     0,   594,   595,   596,   597,   598,   599,   600,     0,
       0,    87,    88,    89,     0,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   647,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   674,     0,     0,     0,   103,     0,
      89,   104,     0,   679,     0,    93,   252,     0,     0,     0,
       0,     0,     0,     0,   253,     0,   690,   692,   105,   106,
       0,     0,   107,     0,   108,     0,    95,   254,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,     0,   107,
       0,   108,     0,   175,   176,   177,     0,     0,   389,   390,
       0,     0,   178,     0,   248,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,    89,   130,   131,   132,     0,
      93,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,     0,     0,
     154,    95,   156,     0,   158,     0,     0,   160,     0,   162,
       0,     0,   164,     0,   425,   166,   167,     0,   168,   169,
       0,   171,     0,   173,     0,     0,     0,     0,     0,     0,
     828,   176,     0,   829,     0,     0,     0,     0,     0,   186,
     557,     0,   389,   390,     0,     0,     0,     0,     0,   391,
     392,   393,   394,   395,   396,   397,   389,   390,     0,     0,
       0,     0,     0,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   107,     0,   108,     0,     0,     0,
       0,     0,   398,   399,   400,   401,     0,     0,   968,     0,
     969,     0,     0,   871,     0,   873,     0,     0,     0,     0,
       0,   130,   131,   132,     0,     0,     0,   136,   137,   138,
       0,   140,     0,   142,   143,   144,     0,     0,     0,    89,
     149,   150,   151,     0,    93,   154,     0,   156,     0,   158,
       0,     0,   160,     0,   162,   888,     0,   164,     0,     0,
     166,   167,     0,   168,   169,    95,   171,     0,   173,     0,
       0,     0,     0,   890,   891,     0,   176,     0,     0,     0,
     892,     0,     0,     0,   186,   559,   398,   399,   400,   401,
       0,     0,     0,   898,   593,     0,   900,     0,   901,     0,
     398,   399,   400,   401,     0,     0,     0,     0,   688,     0,
      89,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   918,     0,     0,   920,     0,
       0,     0,     0,     0,     0,     0,    95,     0,   107,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   936,   937,   938,     0,     0,     0,     0,     0,     0,
       0,   946,   947,     0,     0,   130,   131,   132,     0,     0,
       0,   136,   137,   138,     0,   140,     0,   142,   143,   144,
       0,     0,     0,     0,   149,   150,   151,     0,     0,   154,
       0,   156,     0,   158,     0,     0,   160,     0,   162,     0,
       0,   164,     0,     0,   166,   167,     0,   168,   169,   107,
     171,   108,   173,   429,   389,   390,     0,     0,     0,     0,
     176,   391,   392,   393,   394,   395,   396,   397,   186,   561,
       0,     0,     0,     0,  1010,     0,   130,   131,   132,     0,
       0,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,  1023,     0,
     154,     0,   156,     0,   158,     0,     0,   160,     0,   162,
       0,     0,   164,  1026,     0,   166,   167,     0,   168,   169,
       0,   171,  1029,   173,     0,  1031,     0,     0,  1032,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,  1043,     0,     0,     0,     0,     0,     0,
       0,     0,  1049,  1050,  1051,  1052,     0,  1054,     0,     0,
       0,     0,     0,     0,    87,    88,    89,     0,    90,    91,
      92,    93,     0,     0,     0,     0,     0,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   707,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1094,     0,
       0,     0,     0,  1098,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,   104,     0,     0,     0,     0,   246,
       0,  1120,     0,     0,     0,     0,     0,   247,     0,     0,
       0,   105,   106,     0,     0,   107,     0,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,   159,   160,   161,   162,     0,   163,   164,     0,
     165,   166,   167,     0,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,   177,     0,
       0,     0,     0,     0,     0,   178,     0,   248,    87,    88,
      89,     0,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   389,   390,   104,     0,
       0,     0,     0,   391,   392,   393,   394,   395,   396,   397,
       0,   504,     0,     0,     0,   105,   106,     0,     0,   107,
       0,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
       0,   163,   164,     0,   165,   166,   167,     0,   168,   169,
     170,   171,   172,   173,   174,     0,     0,     0,     0,     0,
     175,   176,   177,     0,     0,     0,     0,     0,     0,   178,
       0,   248,    87,    88,    89,     0,    90,    91,    92,    93,
     398,   399,   400,   401,     0,     0,     0,     0,   724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     389,   390,   104,     0,     0,     0,     0,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,   175,   176,   177,     0,     0,     0,
       0,     0,     0,   178,     0,   248,    87,    88,    89,     0,
      90,    91,    92,    93,   398,   399,   400,   401,     0,     0,
       0,     0,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,    89,   104,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,   107,     0,   108,
       0,    95,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,   159,   160,   161,   162,     0,   163,
     164,     0,   165,   166,   167,     0,   168,   169,   170,   171,
     172,   173,   174,     0,   107,     0,   108,     0,   175,   176,
     177,     0,     0,     0,     0,     0,     0,   178,   482,    87,
      88,    89,     0,    90,    91,    92,    93,     0,     0,     0,
       0,   130,   131,   132,     0,     0,     0,   136,   137,   138,
       0,   140,     0,   142,   143,   144,    94,    95,     0,     0,
     149,   150,   151,     0,     0,   154,     0,   156,     0,   158,
       0,     0,   160,     0,   162,     0,     0,   164,     0,     0,
     166,   167,     0,   168,   169,     0,   171,     0,   173,    96,
      97,    98,    99,   100,   101,   102,   176,     0,     0,     0,
       0,     0,     0,     0,   827,     0,   103,   389,   390,   104,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,     0,   163,   164,     0,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,     0,     0,
     178,   535,    87,    88,    89,     0,    90,    91,    92,    93,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   726,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,   104,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   105,
     106,     0,     0,   107,     0,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
     159,   160,   161,   162,     0,   163,   164,     0,   165,   166,
     167,     0,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,   175,   176,   177,     0,     0,     0,
       0,     0,     0,   178,   546,    87,    88,    89,     0,    90,
      91,    92,    93,     0,   260,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,   389,
     390,     0,   103,     0,     0,   104,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,     0,     0,   107,     0,   108,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,   159,   160,   161,   162,     0,   163,   164,
       0,   165,   166,   167,     0,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,   175,   176,   177,
       0,     0,     0,    87,    88,    89,   178,    90,    91,    92,
      93,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   728,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,   389,   390,     0,
     103,     0,     0,   104,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     474,   398,   399,   400,   401,     0,     0,     0,     0,   731,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,   103,     0,
       0,   104,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,     0,   107,     0,   108,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,     0,   159,
     160,   161,   162,     0,   163,   164,     0,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,     0,     0,
       0,     0,     0,   175,   176,   177,     0,     0,     0,    87,
      88,    89,   178,    90,    91,    92,    93,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   734,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,    89,     0,   104,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
     107,     0,   108,    95,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,   159,   160,   161,
     162,     0,   163,   164,     0,   165,   166,   167,   673,   168,
     169,   170,   171,   172,   173,   174,   107,     0,   108,     0,
      89,   175,   176,   177,     0,    93,     0,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,    95,     0,     0,   136,
     137,   138,     0,   140,     0,   142,   143,   144,     0,     0,
       0,     0,   149,   150,   151,     0,     0,   154,     0,   156,
       0,   158,     0,     0,   160,     0,   162,     0,     0,   164,
       0,     0,   166,   167,     0,   168,   169,     0,   171,     0,
     173,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,   186,     0,     0,     0,
       0,   872,     0,     0,     0,   389,   390,     0,     0,   107,
       0,   108,   391,   392,   393,   394,   395,   396,   397,     0,
     389,   390,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   395,   396,   397,     0,     0,   130,   131,   132,     0,
       0,     0,   136,   137,   138,     0,   140,     0,   142,   143,
     144,     0,     0,     0,     0,   149,   150,   151,     0,     0,
     154,     0,   156,     0,   158,     0,     0,   160,     0,   162,
       0,     0,   164,     0,     0,   166,   167,     0,   168,   169,
       0,   171,     0,   173,     0,     7,     8,     9,     0,     0,
       0,   176,    10,     0,     0,     0,    11,     0,    12,   186,
      13,    14,    15,    16,    17,  -326,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    29,     0,     0,    30,     0,     0,   398,
     399,   400,   401,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    37,    38,   398,   399,   400,   401,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,  -117,  -117,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,  -117,     0,    55,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,   389,   390,
       0,     0,     0,     0,     0,   391,   392,   393,   394,   395,
     396,   397,    58,    59,    60,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,    63,     0,     7,     8,     9,    64,     0,     0,    65,
      10,     0,     0,    66,    11,     0,    12,     0,    13,    14,
      15,    16,    17,  -326,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,     0,     0,     0,
       0,    29,   -15,   -15,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,   398,   399,   400,   401,     0,    45,    46,    47,
     737,     0,    48,    49,    50,     0,    51,    52,    53,     0,
       0,    54,     0,     0,    55,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   390,     0,     0,
       0,     0,     0,   391,   392,   393,   394,   395,   396,   397,
      58,    59,    60,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,    63,
       0,     7,     8,     9,    64,     0,     0,    65,    10,     0,
       0,    66,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -326,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,   -15,     0,     0,     0,    29,
     -15,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,   389,   390,     0,    37,    38,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
     398,   399,   400,   401,     0,    45,    46,    47,   738,     0,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
     389,   390,    55,     0,    56,    57,     0,   391,   392,   393,
     394,   395,   396,   397,   389,   390,     0,     0,     0,     0,
       0,   391,   392,   393,   394,   395,   396,   397,    58,    59,
      60,   389,   390,     0,     0,    61,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,    63,     0,     0,
       0,     0,    64,   389,   390,    65,     0,     0,     0,    66,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,   389,   390,     0,     0,   739,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   400,   401,     0,     0,
       0,     0,   740,     0,     0,     0,     0,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   741,     0,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,   742,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   389,   390,     0,     0,   743,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   745,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,     0,     0,   756,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,     0,     0,   759,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   389,
     390,     0,     0,   762,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   784,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   826,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   925,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,     0,     0,   942,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,   943,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,     0,
       0,   950,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,     0,     0,   951,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   952,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,     0,
       0,   953,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,   389,   390,     0,
       0,   954,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   959,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   960,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   963,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,     0,     0,   964,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,   398,   399,   400,   401,   389,   390,     0,     0,   965,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   966,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,   967,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,     0,   970,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,     0,     0,   971,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,   389,   390,     0,     0,   974,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   980,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   983,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   998,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,     0,     0,  1040,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   389,   390,     0,     0,  1044,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,  1053,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,     0,     0,  1062,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,  1064,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,     0,     0,  1065,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   389,
     390,     0,     0,  1067,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,  1100,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,  1113,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,  1131,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   451,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,     0,     0,   398,   399,   400,   401,   389,
     390,   452,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,     0,     0,   466,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,   670,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,     0,     0,   705,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,   389,   390,   706,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,   389,   390,   708,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,   709,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,   723,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   389,   390,   744,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   389,   390,     0,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,   398,   399,   400,   401,   389,   390,   751,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,     0,
       0,   398,   399,   400,   401,     0,     0,   752,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,   822,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   389,   390,     0,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,     0,
       0,   843,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,   389,   390,   844,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,     0,     0,   398,
     399,   400,   401,   389,   390,   851,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,   390,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,     0,     0,   854,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   855,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,   860,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,   389,
     390,   861,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   389,   390,   917,     0,     0,     0,     0,   391,   392,
     393,   394,   395,   396,   397,     0,     0,   398,   399,   400,
     401,     0,     0,   922,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   389,   390,   933,     0,     0,
       0,     0,   391,   392,   393,   394,   395,   396,   397,   389,
     390,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   389,   390,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   389,     0,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,     0,     0,   398,   399,   400,   401,     0,     0,   981,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,   982,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,  1012,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,  1061,     0,     0,     0,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,  1079,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401
};

static const yytype_int16 yycheck[] =
{
       2,   199,    40,    15,    16,   307,    12,     1,   832,   833,
       4,     4,    12,     1,     7,    17,     4,     4,    76,   217,
       7,    47,    48,    58,    58,    60,    61,    75,    30,    41,
      44,    33,   274,   275,    36,    37,    38,   188,    11,    75,
      42,    43,    44,    25,   195,    16,     3,   278,   279,    51,
       7,     8,     9,    10,    91,    92,    14,   188,    16,    53,
      18,    63,    44,   188,   195,    53,   103,    43,    44,     0,
     195,     3,    76,    44,    23,     7,     8,     9,    10,     4,
      28,   188,     7,    41,    20,    21,    44,    63,   195,     4,
       5,    49,   193,    12,   195,    87,    98,    70,    71,    72,
      73,    74,    75,   180,   181,   182,   183,   184,    12,   188,
       4,     5,    74,    75,    76,     7,   195,    70,    71,    72,
      73,    74,    75,   193,    94,   195,   188,    63,    64,   187,
     188,   189,   190,   195,    70,    71,    72,    73,    74,    75,
      76,   372,   188,   374,    63,    64,   194,    75,    76,   195,
     109,    70,    71,    72,    73,    74,    75,    76,   194,    63,
      64,   196,   196,   193,    44,   195,    70,    71,    72,    73,
      74,    75,    76,     3,   188,   177,   178,     7,     8,     9,
    1004,   188,   188,  1007,    99,   189,   190,   193,   195,    28,
     188,   193,    75,   193,    33,   193,   198,   195,   193,   188,
     195,   194,   240,   241,   193,   199,   195,   194,   193,   211,
     195,   199,    75,   188,   216,   188,   131,   132,   133,   188,
     195,   223,   194,   217,   193,   187,   188,   189,   190,   217,
     187,   188,    24,   475,   260,   188,   434,   131,   132,   133,
     266,   267,   195,   188,   246,   194,   248,   196,   193,   491,
     492,   187,   188,   189,   190,   187,   188,   194,    59,   187,
     188,   189,   190,   289,   290,   291,     4,     5,   187,   188,
     189,   190,   514,  1097,   193,   188,   188,   194,   280,    44,
     193,   193,   308,   187,   188,   189,   190,    88,    89,    90,
     292,   194,    13,   194,    95,   297,   298,   188,   300,   301,
     302,   303,   304,   305,   195,     4,     5,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   304,   305,
     194,   188,   194,   335,   336,   337,   338,   339,   195,   341,
     188,   343,    63,    64,   320,   193,   295,   296,   194,    70,
      71,    72,    73,    74,    75,    76,   358,   194,    35,    36,
     194,   363,    70,    71,    72,    73,    74,    75,   194,     4,
       5,     4,     5,    70,    71,    72,    73,    74,    75,   188,
       5,   188,   358,   194,   193,    10,   195,     4,   195,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     194,     4,     5,   192,   193,    71,    31,    73,    74,    75,
      76,   360,   361,    70,    71,    72,    73,    74,    75,   617,
     458,   194,    70,    71,    72,    73,    74,    75,    14,   188,
      16,   194,    18,   435,   193,    44,   195,   194,   440,   194,
     434,    73,    74,    75,    76,   471,   434,   188,   474,   451,
     452,   188,   193,   188,   195,    41,   193,   188,    44,    58,
     195,   194,   464,    49,   466,   188,   187,   188,   189,   190,
     193,   188,   195,   193,   476,   477,   193,   188,   195,   104,
     188,   106,   193,   485,   486,   487,   488,   195,   188,   791,
     188,   188,   794,   193,     5,   489,   193,   195,   195,   448,
     449,   489,   188,   194,   453,   454,   131,   132,   133,   195,
     188,   194,   137,   138,   139,   193,   141,   195,   143,   144,
     145,   187,   188,   189,   190,   150,   151,   152,   188,   194,
     155,   188,   157,   193,   159,   195,   188,   162,   195,   164,
     188,   193,   167,   195,   194,   170,   171,    44,   173,   174,
     194,   176,   188,   178,   194,   187,   188,   189,   190,   195,
     194,   186,     4,     5,   188,   188,    63,    64,    46,   194,
     195,   195,   195,    70,    71,    72,    73,    74,    75,    76,
     188,   188,   188,   188,   188,    63,    64,   195,   195,   195,
     195,   195,    70,    71,    72,    73,    74,    75,    76,   601,
     602,   188,    70,    71,    72,    73,    74,    75,   195,   188,
     188,   194,   188,   625,   626,   188,   195,   195,   620,   195,
     818,   863,   195,   617,   194,   188,   188,   188,   194,   617,
     194,   633,   195,   195,   195,    46,   194,   879,   188,    14,
     188,    16,   188,    18,   646,   195,   193,   195,   193,   195,
     652,   653,    63,    64,   656,   681,    85,    86,   194,    70,
      71,    72,    73,    74,    75,    76,    41,   194,   670,    44,
     188,   188,   698,   699,    49,   193,   193,   193,   627,   628,
     194,   630,   631,   685,   686,   687,     4,     5,   194,   188,
     187,   188,   189,   190,   193,   697,   722,   188,    49,    50,
     188,   194,   193,   705,   706,   193,   708,   709,   710,   187,
     188,   189,   190,     4,     5,    39,    40,   188,   720,   721,
     188,   723,   193,   193,    14,   193,    16,   729,    18,   188,
     732,   188,   188,   194,   193,   684,   193,   193,     4,     5,
      60,    61,   744,    51,   194,   747,   748,   749,   194,   751,
     752,    41,   195,   194,    44,    63,    64,   194,   760,    49,
     194,   194,    70,    71,    72,    73,    74,    75,    76,   194,
     194,   194,   194,   194,   194,   194,   187,   188,   189,   190,
     194,   194,    63,    64,   786,   194,   788,   789,   790,    70,
      71,    72,    73,    74,    75,    76,   194,   194,   194,   194,
     802,    63,    64,   194,     3,   194,   194,   194,    70,    71,
      72,    73,    74,    75,    76,   194,   194,   194,   194,   193,
     822,   194,    21,   194,   818,    24,   194,   194,   194,   194,
     818,   194,   194,   194,    33,   194,  1034,  1035,    37,    38,
     194,   843,   844,    42,   194,   194,   848,   849,   194,   194,
     194,   194,   854,   855,   194,    54,    55,    56,   194,   194,
     194,   194,   194,   194,    63,    64,    65,    66,   194,   194,
      43,   194,   848,   849,   195,   194,   193,  1075,   194,   187,
     188,   189,   190,   194,   194,    76,   195,    75,  1086,   195,
     194,  1089,   841,   842,   906,   907,   194,   193,    43,   194,
     194,   193,    46,    10,  1102,   193,   187,   188,   189,   190,
     912,   194,   193,   193,   195,   917,   194,   194,   193,   193,
     922,   193,   948,   193,   195,   187,   188,   189,   190,   193,
     195,   193,   195,   195,   195,   194,   194,    63,    64,   195,
     195,   193,   944,    43,    70,    71,    72,    73,    74,    75,
      76,   195,   195,    70,    71,    72,    73,    74,    75,    76,
     962,   195,   195,   195,   195,   194,   968,    71,    72,    73,
      74,    75,    76,   975,   194,   977,   195,   926,   927,   178,
     982,   195,    84,    84,   195,   195,     5,   186,   193,   991,
     193,   195,    58,    63,    64,   195,   195,   195,   195,  1001,
      70,    71,    72,    73,    74,    75,    76,   194,   194,   193,
     195,   194,   211,   195,   195,  1017,    43,   216,    38,    43,
     194,    75,    75,   195,   223,   195,    75,    48,    58,   195,
     195,   194,   194,    47,  1036,   194,   194,    75,   195,   195,
    1034,  1035,    38,     4,     4,   489,  1034,  1035,   247,    53,
      53,   458,   633,   307,     5,   629,   912,   632,   257,  1061,
    1129,   187,   188,   189,   190,   455,   830,   193,  1070,   195,
     187,   188,   189,   190,  1058,   468,  1078,  1079,  1081,    -1,
      -1,  1075,   281,   187,   188,   189,   190,  1075,    -1,    -1,
      -1,    -1,  1086,    -1,   293,  1089,    -1,    -1,  1086,    -1,
      -1,  1089,    -1,    -1,    -1,   304,    -1,    -1,  1102,    -1,
    1112,    -1,    -1,    -1,  1102,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      -1,   340,    -1,   342,    -1,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,    -1,    -1,   362,    -1,   364,   365,   366,   367,   368,
      -1,    -1,   371,    -1,   373,    -1,   375,   376,   377,    -1,
      -1,    -1,   381,   382,   383,   384,   385,   386,   387,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    80,    -1,
       5,    83,    -1,   472,    -1,    10,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,   485,   486,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    31,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,   104,
      -1,   106,    -1,   185,   186,   187,    -1,    -1,    63,    64,
      -1,    -1,   194,    -1,   196,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,     5,   131,   132,   133,    -1,
      10,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
     155,    31,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,   633,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
     649,   186,    -1,   652,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
     195,    -1,    -1,   712,    -1,   714,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,    -1,   143,   144,   145,    -1,    -1,    -1,     5,
     150,   151,   152,    -1,    10,   155,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,   164,   754,    -1,   167,    -1,    -1,
     170,   171,    -1,   173,   174,    31,   176,    -1,   178,    -1,
      -1,    -1,    -1,   772,   773,    -1,   186,    -1,    -1,    -1,
     779,    -1,    -1,    -1,   194,   195,   187,   188,   189,   190,
      -1,    -1,    -1,   792,   195,    -1,   795,    -1,   797,    -1,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   824,    -1,    -1,   827,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   850,   851,   852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   860,   861,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,   137,   138,   139,    -1,   141,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,    -1,
      -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,   104,
     176,   106,   178,   912,    63,    64,    -1,    -1,    -1,    -1,
     186,    70,    71,    72,    73,    74,    75,    76,   194,   195,
      -1,    -1,    -1,    -1,   933,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,   957,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,   972,    -1,   170,   171,    -1,   173,   174,
      -1,   176,   981,   178,    -1,   984,    -1,    -1,   987,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1011,  1012,  1013,  1014,    -1,  1016,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,    -1,
      -1,    -1,    -1,  1082,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,  1110,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,    -1,   166,   167,    -1,
     169,   170,   171,    -1,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    63,    64,    83,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    96,    -1,    -1,    -1,   100,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      -1,   166,   167,    -1,   169,   170,   171,    -1,   173,   174,
     175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,    -1,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,     3,     4,     5,    -1,     7,     8,     9,    10,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      63,    64,    83,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,     3,     4,     5,    -1,
       7,     8,     9,    10,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,     5,    83,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,
      -1,    31,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    -1,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,    -1,   104,    -1,   106,    -1,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,   139,
      -1,   141,    -1,   143,   144,   145,    30,    31,    -1,    -1,
     150,   151,   152,    -1,    -1,   155,    -1,   157,    -1,   159,
      -1,    -1,   162,    -1,   164,    -1,    -1,   167,    -1,    -1,
     170,   171,    -1,   173,   174,    -1,   176,    -1,   178,    63,
      64,    65,    66,    67,    68,    69,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    80,    63,    64,    83,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    -1,   161,   162,   163,
     164,    -1,   166,   167,    -1,   169,   170,   171,    -1,   173,
     174,   175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,
      -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    83,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,   162,   163,   164,    -1,   166,   167,    -1,   169,   170,
     171,    -1,   173,   174,   175,   176,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    12,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    80,    -1,    -1,    83,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,   161,   162,   163,   164,    -1,   166,   167,
      -1,   169,   170,   171,    -1,   173,   174,   175,   176,   177,
     178,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
      -1,    -1,    -1,     3,     4,     5,   194,     7,     8,     9,
      10,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      80,    -1,    -1,    83,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161,   162,   163,   164,    -1,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,     3,     4,     5,   194,     7,     8,     9,    10,    -1,
      12,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    80,    -1,
      -1,    83,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,    -1,   166,   167,    -1,   169,   170,   171,
      -1,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,     3,
       4,     5,   194,     7,     8,     9,    10,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,     5,    -1,    83,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,    31,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    -1,   161,   162,   163,
     164,    -1,   166,   167,    -1,   169,   170,   171,    96,   173,
     174,   175,   176,   177,   178,   179,   104,    -1,   106,    -1,
       5,   185,   186,   187,    -1,    10,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,    31,    -1,    -1,   137,
     138,   139,    -1,   141,    -1,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,   151,   152,    -1,    -1,   155,    -1,   157,
      -1,   159,    -1,    -1,   162,    -1,   164,    -1,    -1,   167,
      -1,    -1,   170,   171,    -1,   173,   174,    -1,   176,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    63,    64,    -1,    -1,   104,
      -1,   106,    70,    71,    72,    73,    74,    75,    76,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,   162,    -1,   164,
      -1,    -1,   167,    -1,    -1,   170,   171,    -1,   173,   174,
      -1,   176,    -1,   178,    -1,     4,     5,     6,    -1,    -1,
      -1,   186,    11,    -1,    -1,    -1,    15,    -1,    17,   194,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,   187,
     188,   189,   190,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,   105,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,   131,   132,   133,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,   160,    -1,     4,     5,     6,   165,    -1,    -1,   168,
      11,    -1,    -1,   172,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,   187,   188,   189,   190,    -1,    88,    89,    90,
     195,    -1,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
      -1,     4,     5,     6,   165,    -1,    -1,   168,    11,    -1,
      -1,   172,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    63,    64,    -1,    61,    62,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
     187,   188,   189,   190,    -1,    88,    89,    90,   195,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
      63,    64,   105,    -1,   107,   108,    -1,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,   131,   132,
     133,    63,    64,    -1,    -1,   138,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,   165,    63,    64,   168,    -1,    -1,    -1,   172,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,    -1,
      -1,   195,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    63,    64,    -1,
      -1,   195,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    63,    64,    -1,    -1,   195,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,    -1,    -1,   195,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,    -1,    -1,   195,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    63,
      64,    -1,    -1,   195,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    63,    64,   193,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,   187,
     188,   189,   190,    63,    64,   193,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    63,
      64,   193,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,   187,   188,   189,
     190,    63,    64,   193,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,    63,    64,   193,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,   190
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   180,   181,   182,   183,   184,   198,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    77,
      78,    79,    80,    81,    82,    88,    89,    90,    93,    94,
      95,    97,    98,    99,   102,   105,   107,   108,   131,   132,
     133,   138,   156,   160,   165,   168,   172,   199,   200,   202,
     203,   210,   211,   213,   214,   218,   230,   231,   236,   242,
     249,   257,   265,   268,   272,   275,   281,     3,     4,     5,
       7,     8,     9,    10,    30,    31,    63,    64,    65,    66,
      67,    68,    69,    80,    83,   100,   101,   104,   106,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   161,
     162,   163,   164,   166,   167,   169,   170,   171,   173,   174,
     175,   176,   177,   178,   179,   185,   186,   187,   194,   216,
     217,   219,   225,   227,   230,   231,   194,   216,   202,   230,
     231,   236,     0,    75,   194,    75,   194,   250,   269,   273,
       4,     7,   228,   228,   228,    34,   219,   204,   205,   216,
     232,   233,   232,   216,    28,     7,   258,   266,   219,    58,
      60,    61,   196,   304,   208,   216,   219,     4,     5,   229,
     219,   216,   219,   216,   219,     4,     5,   292,   293,    10,
     187,   188,   226,   227,   294,   228,    88,    96,   196,   216,
     219,   305,    88,    96,   109,   305,   305,    87,   219,   224,
      12,    53,   224,   224,    59,    88,    89,    90,    95,    94,
     219,   211,   218,   216,   216,   216,   109,   194,   194,   194,
     194,   194,   216,   305,   216,   216,   216,    44,   201,    91,
      92,   103,    75,    75,    24,   194,   194,   194,   194,   219,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   219,   216,
     219,    70,    71,    72,    73,    74,    75,   188,    44,    63,
      64,    70,    71,    72,    73,    74,    75,    76,   187,   188,
     189,   190,   216,    44,    44,    44,   219,   232,   216,   232,
       4,   219,   200,    35,    36,    20,    21,     4,     5,   243,
     244,     4,     5,   245,   246,   216,   219,   234,   235,   216,
     219,   260,   200,   276,   282,   194,    58,   194,     4,     7,
     194,   216,   219,   295,    58,   196,   297,   302,   194,   194,
     193,   193,   193,   194,   194,   193,   227,   227,   193,   219,
     216,   219,    11,   193,   193,   216,   193,   224,   209,    12,
     193,   212,   193,   224,    12,   224,   212,   212,     5,   215,
     215,   215,   195,   219,   216,   193,   193,   193,   193,    43,
     224,   224,   224,   219,   216,   237,   232,   232,   219,   219,
     219,   219,   219,   219,    96,   216,   305,   305,     4,     5,
     222,   223,   222,   223,   224,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   305,   219,   219,   219,
     219,   219,   219,   219,   219,   195,   219,   216,   216,   216,
     216,   216,   219,   219,   216,   219,   195,   219,   219,   216,
     219,   216,   219,   216,   216,   195,   216,   195,   216,   195,
     216,   195,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   305,   216,   232,   232,   216,   219,   216,   216,
     216,   216,   216,   195,   195,   216,   215,   216,   215,   216,
     216,   216,   195,   195,   216,   216,   216,   216,   216,   216,
     216,   221,   220,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   195,   195,    75,   270,    14,    16,
      18,    41,    44,    49,   274,   206,   207,   194,   194,   193,
     194,   194,   193,   193,    43,   259,    14,    16,    18,    41,
      44,    49,   267,    46,   200,   219,   194,   216,   219,    51,
     296,   192,   193,   194,     4,     7,   194,    10,   303,   232,
     232,     4,     5,   219,   219,   232,   232,   293,    10,   226,
     193,    85,    86,    96,   216,   219,   219,   297,   224,   216,
     224,   212,   219,   219,   194,   193,   193,   193,   195,   195,
     216,   219,   216,   219,   219,   219,   203,   193,   212,   212,
       4,     5,   241,   195,   195,   193,   193,   195,   193,   193,
     193,   195,   193,   195,   193,   195,   194,   194,   195,   195,
     193,   193,   212,   193,   195,   195,   195,   195,   195,   193,
     195,   195,   193,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   193,   195,   195,   193,   193,   193,
     195,   193,   193,   195,   193,   195,   195,   195,   195,   195,
     193,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   193,   193,   195,   195,   195,   195,   195,   193,
     195,   195,   195,   195,   195,   195,   193,   195,   193,   193,
     193,   193,   193,   195,   193,   193,   195,   193,   195,   195,
     219,   219,   251,   200,   219,   228,   306,   228,   307,   232,
     232,   244,   232,   232,   246,   235,    43,   261,   277,    49,
      50,   283,   193,   219,   193,   195,   195,   194,   216,   216,
     219,   219,   298,   299,   219,     4,     5,   289,   291,   195,
     195,   194,   194,   193,   193,   195,   195,   219,    84,    84,
     193,   193,   193,   224,   193,   193,   232,   219,   219,   219,
     193,   193,   219,   224,   224,   238,   219,   219,   219,   219,
     219,   216,    96,   216,   195,   195,   219,   219,   224,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   216,   219,
     216,   216,   216,   219,   219,   219,   219,   223,   216,   223,
     216,   216,   219,    16,    44,   271,   193,   193,   195,   195,
     195,   195,    39,    40,   263,   200,   219,   193,   216,    58,
     216,   296,   193,   289,   289,   195,   194,   194,   193,   232,
     232,   219,   219,   193,   305,   305,   216,   216,   216,   219,
     219,   195,   195,   195,   193,   195,   216,   216,   212,   194,
     195,   195,   195,   195,   195,   195,   195,   193,   195,   195,
     195,   195,   212,   195,   195,   195,   195,   195,   193,   195,
     195,   195,   193,   195,   195,   193,   195,   193,   195,   195,
     195,   193,   193,   195,   193,   195,   195,   193,   195,   195,
     195,    12,   228,   228,   260,    43,    38,   278,   195,   219,
     195,   194,   193,   219,   300,   232,   232,   290,   195,   195,
     216,   193,   193,    75,    75,   219,    75,   193,   224,     4,
       5,   247,   248,   216,   219,   219,   216,   219,   219,   216,
     219,   216,   216,   219,   262,   264,    48,   285,    60,    61,
     195,    58,   219,   216,   195,   289,   195,   195,   289,   216,
     216,   216,   216,   195,   216,   219,   194,   194,   193,   195,
     195,   193,   195,   195,   195,   195,   195,   195,   195,   195,
      13,   255,   200,   200,   219,    47,   284,   194,   194,   193,
     195,   301,    75,   195,   195,   248,   239,   219,   219,   252,
      46,   288,   200,   279,   216,   219,   219,   303,   216,   200,
     195,   200,   286,    14,    16,    18,    41,    44,    49,   280,
     193,   195,   193,   195,   289,    25,    44,   240,   253,   200,
     216,   219,    14,    16,    18,    41,    44,    49,   254,   287,
     195,   195,     4,   256,   285
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   197,   198,   198,   198,   198,   198,   199,   200,   201,
     200,   202,   202,   202,   202,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   203,   205,   203,   203,   203,   203,   203,   203,   203,
     206,   203,   207,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   208,   203,   209,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   210,   210,   210,
     210,   210,   211,   211,   211,   211,   211,   211,   212,   212,
     213,   213,   213,   213,   213,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   218,   218,   220,   219,
     221,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   222,   223,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   227,
     227,   227,   227,   228,   228,   229,   229,   229,   229,   230,
     231,   233,   232,   234,   234,   234,   235,   235,   237,   238,
     239,   236,   240,   240,   241,   241,   242,   242,   242,   242,
     243,   243,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   247,   247,   247,   248,   248,   248,   248,   250,
     251,   252,   253,   249,   254,   254,   254,   254,   254,   254,
     255,   255,   256,   256,   258,   257,   259,   259,   260,   260,
     261,   262,   261,   263,   264,   263,   266,   265,   267,   267,
     267,   267,   267,   267,   269,   270,   268,   271,   271,   273,
     272,   274,   274,   274,   274,   274,   274,   276,   277,   278,
     279,   275,   280,   280,   280,   280,   280,   280,   282,   281,
     283,   283,   284,   284,   285,   286,   287,   285,   288,   288,
     289,   290,   289,   291,   291,   291,   291,   292,   292,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   296,   296,   296,   298,   297,   299,   297,   300,
     297,   301,   297,   302,   297,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   305,   305,   306,   306,   307,   307
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       4,     1,     2,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     2,     2,     3,     3,
       0,     5,     0,     5,     2,     1,     2,     1,     2,     2,
       2,     3,     4,     4,     0,     3,     0,     4,     6,     2,
       6,     2,     2,     2,     1,     2,     1,     2,     2,     2,
       5,     7,     3,     2,     3,     4,     5,     3,     2,     4,
       3,     8,     6,     6,     2,     2,     5,     7,     4,     6,
       8,     5,     2,     2,     2,     2,     3,     2,     2,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       2,     1,     2,     2,     8,     6,     6,     0,     1,     1,
       2,     2,     3,    10,     8,     8,     8,     3,     1,     1,
       6,     4,     4,     6,     6,     4,     6,     1,     4,     1,
       1,     1,     1,     3,     3,     6,     6,     8,     6,     4,
       6,     8,     4,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     1,     3,
       1,     3,     4,     6,     6,     4,     6,     4,     6,    10,
       4,     4,     4,     8,     6,     4,     3,     3,     0,     4,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     4,
       6,     1,     4,     4,     6,     6,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     8,     4,     4,     4,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     4,     1,     3,     6,     6,     4,
       6,     6,     6,     4,     8,     6,     8,     6,     4,     4,
       4,     6,     6,     6,     8,     4,     1,     2,     2,     1,
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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

  YY_LOCATION_PRINT (yyo, *yylocationp);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

  case 17: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 18: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 24: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 25: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 28: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 29: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* $@2: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 32: /* $@3: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 36: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 37: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 39: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 40: /* $@4: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 41: /* statement: tON expression tGOTO $@4 goto_list  */
              {add_command(cNOP);}
    break;

  case 42: /* $@5: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 43: /* statement: tON expression tGOSUB $@5 gosub_list  */
               {add_command(cNOP);}
    break;

  case 44: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 45: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 46: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 47: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 48: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 49: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 50: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 52: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* $@6: %empty  */
           {tileol=FALSE;}
    break;

  case 56: /* $@7: %empty  */
                 {tileol=TRUE;}
    break;

  case 58: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 59: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 60: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 61: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 64: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 65: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 66: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 67: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 68: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 70: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 72: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 73: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 74: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 75: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 76: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 77: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 78: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 79: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 80: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 84: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 85: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 86: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 87: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 88: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 91: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 92: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 93: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 94: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 95: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 96: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 97: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 98: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 99: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 100: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 101: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 102: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 103: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 104: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 105: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 106: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 107: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 108: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 109: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 110: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 111: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 112: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 113: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 114: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 116: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 117: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 118: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 119: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 120: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 121: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 122: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 123: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 124: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 125: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 126: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 127: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 130: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 131: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 132: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 133: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 134: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 135: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 136: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 137: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 138: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 139: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 141: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 142: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 143: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 145: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 146: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 147: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 148: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 149: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 150: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 151: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 152: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 153: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 154: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 155: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 156: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 157: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 158: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 159: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 160: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 161: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 162: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 163: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 164: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 165: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 166: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 167: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 168: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 169: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 170: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 171: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 172: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 173: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 174: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 175: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 176: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 177: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 178: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 179: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 180: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 181: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 182: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 183: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 184: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 185: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 186: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 187: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 188: /* $@8: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 189: /* expression: expression tOR $@8 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 190: /* $@9: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 191: /* expression: expression tAND $@9 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 192: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 193: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 194: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 195: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 196: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 197: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 198: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 199: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 200: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 201: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 202: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 203: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 204: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 205: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 206: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 207: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 208: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 209: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 210: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 211: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 212: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 213: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 214: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 215: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 216: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 217: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 218: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 219: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 222: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 223: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 225: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 226: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 227: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 228: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 229: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 230: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 231: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 232: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 233: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 234: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 235: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 236: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 237: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 238: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 239: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 240: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 241: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 242: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 243: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 244: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 245: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 246: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 247: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 248: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 249: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 250: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 251: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 252: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 253: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 254: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 255: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 256: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 257: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 258: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 259: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 260: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 261: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 262: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 263: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 264: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 265: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 266: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 267: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 268: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 269: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 270: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 271: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 272: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 273: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 274: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 275: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 276: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 277: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 278: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 279: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 280: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 281: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 282: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 283: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 284: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 285: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 286: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 287: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 288: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 289: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 290: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 291: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 292: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 293: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 294: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 295: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 296: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 297: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 298: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 299: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 300: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 301: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 302: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 303: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 304: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 305: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 306: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 307: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 308: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 309: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 310: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 311: /* $@10: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 318: /* $@11: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 319: /* $@12: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 320: /* $@13: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 321: /* function_definition: export tSUB $@11 function_name $@12 '(' paramlist ')' $@13 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 322: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 323: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 324: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 325: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 326: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 327: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 328: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 329: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 332: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 333: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 334: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 335: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 338: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 339: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 340: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 341: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 345: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 346: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 347: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 348: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 349: /* $@14: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 350: /* $@15: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 351: /* $@16: %empty  */
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

  case 352: /* $@17: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 353: /* for_loop: tFOR $@14 tSYMBOL tEQU $@15 expression tTO expression step_part $@16 statement_list $@17 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 354: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 355: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 356: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 357: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 358: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 359: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 360: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 362: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 363: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 364: /* $@18: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 365: /* switch_number_or_string: tSWITCH $@18 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 371: /* $@19: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 372: /* case_list: case_list tCASE number_or_string $@19 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 374: /* $@20: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 376: /* $@21: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 378: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 379: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 380: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 381: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 382: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 383: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 384: /* $@22: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 385: /* $@23: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 387: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 388: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 389: /* $@24: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 391: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 392: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 393: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 394: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 395: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 396: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 397: /* $@25: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 398: /* $@26: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 399: /* $@27: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 400: /* $@28: %empty  */
                     {poplabel();}
    break;

  case 402: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 403: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 404: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 405: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 406: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 407: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 408: /* $@29: %empty  */
                         {token_count_start_of_short_if=token_count;in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 410: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 411: /* end_of_if: tIMPLICITENDIF  */
                   {printf("%d,%d\n", token_count_start_of_short_if, token_count);lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");poplabel();}
    break;

  case 415: /* $@30: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 416: /* $@31: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 421: /* $@32: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 423: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 424: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 425: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 426: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 429: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 430: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 431: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 432: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 433: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 434: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 435: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 436: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 440: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 441: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 442: /* using: %empty  */
       {create_print('d');}
    break;

  case 443: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 444: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 445: /* $@33: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 446: /* inputbody: '#' tSYMBOL $@33 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 447: /* $@34: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 448: /* inputbody: '#' tDIGITS $@34 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 449: /* $@35: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 450: /* inputbody: '#' '(' expression ')' $@35 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 451: /* $@36: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 452: /* inputbody: tAT '(' expression ',' expression ')' $@36 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 453: /* $@37: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 454: /* inputbody: $@37 prompt inputlist  */
                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 455: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 456: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 457: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 458: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 459: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 460: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 461: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 462: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 463: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 464: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 465: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 466: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 467: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 468: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 469: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 470: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 473: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 474: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 475: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 476: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

