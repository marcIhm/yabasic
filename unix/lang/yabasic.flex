%{
/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2019
    more info at www.yabasic.de

    FLEX part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

#include <string.h>

#include "bison.h"       /* get tokens from BISON */
#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif
int import_lib(char *); /* import library */

#define MAX_INCLUDE_DEPTH 5
#define MAX_INCLUDE_NUMBER 100
static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH]; /* stack for included libraries */
int include_depth; /* current position in library_stack */
struct library *library_stack[MAX_INCLUDE_DEPTH]; /* stack for library file names */
int library_chain_length=0; /* length of library_chain */
struct library *library_chain[MAX_INCLUDE_NUMBER]; /* list of all library file names in order of appearance */
struct library *currlib; /* current library as relevant to bison */
int inlib; /* true, while in library */
int fi_pending=0; /* true, if within a short if */
int len_of_lineno=0; /* length of last line number */
%}

%{
int yycolumn=1;
#define YY_USER_ACTION yylloc.first_line=yylloc.last_line=yylineno; yylloc.first_column=yycolumn; yylloc.last_column=yycolumn+yyleng-1;yycolumn+=yyleng;
%}

WS [ \t\f\r\v]
NAME ([a-z_][a-z0-9_]*\.[a-z_][a-z0-9_]*)|([a-z_][a-z0-9_]*)

%option noyywrap
%option yylineno
%x PRELNO
%x PASTLNO
%x PASTIMPORT

%%
<<EOF>> {
  if (severity_threshold <= sDEBUG) {
    sprintf(string,"closing file '%s'",currlib->short_name);
    error(sDEBUG,string);
  }
  if (--include_depth<0) {
    return tEOPROG;
  } else {
    if (!is_bound) {
      yy_delete_buffer(YY_CURRENT_BUFFER);
      yy_switch_to_buffer(include_stack[include_depth]);
    }
    leave_lib();
    return tSEP;
  }
}

{WS}+ {BEGIN(INITIAL);}     /* ignore whitespace */

^{WS}*/[0-9]+ {BEGIN(PRELNO);return tLABEL;}
<PRELNO>[0-9]+ {
  BEGIN(PASTLNO);
  yylval.symbol=(char *)my_strdup(yytext);
  len_of_lineno=strlen(yytext);		 
  return tSYMBOL;
}
<PASTLNO>.* {yycolumn=len_of_lineno+1;BEGIN(INITIAL);yyless(0);return tSEP;}
<PASTLNO>\n {yycolumn=1;BEGIN(INITIAL);return tSEP;}

\n\n {yycolumn=1; if (fi_pending) {fi_pending--;yyless(0);return tENDIF;}if (interactive && !inlib) {return tEOPROG;} else {return tSEP;}}
\n {yycolumn=1; if (fi_pending) {fi_pending--;yyless(0);return tENDIF;};return tSEP;}
: {if (fi_pending && check_compat) error(sWARNING,"short-if has changed in version 2.71");return tSEP;}

REM{WS}+.* {return tSEP;}  /* comments span 'til end of line */
\/\/.* {return tSEP;}  /* comments span 'til end of line */
REM\n {yycolumn=1; if (fi_pending) {fi_pending--;yyless(0);return tENDIF;};return tSEP;}
REM {yymore();}

IMPORT{WS}+{NAME} {BEGIN(PASTIMPORT);import_lib(my_strdup(yytext+7));return tIMPORT;}
<PASTIMPORT>.* {yycolumn=1;BEGIN(INITIAL);yyless(0);unput('\n');return tSEP;}
<PASTIMPORT>\n {yycolumn=1;BEGIN(INITIAL);return tSEP;}

((DOCU|DOC|DOCUMENTATION)({WS}+.*)?) {
  char *where=strpbrk(yytext," \t\r\f\v");
  yylval.docu=(char *)my_strdup(where ? where+1 : NULL);
  return tDOCU;
}

^#.*\n {yycolumn=1;return tSEP;} /* '#' as first character may introduce comments too */
^'.*\n {yycolumn=1;return tSEP;} /* ' as first character may introduce comments too */

EXECUTE return tEXECUTE;
"EXECUTE$" return tEXECUTE2;
COMPILE return tCOMPILE;
RUNTIME_CREATED_SUB return tRUNTIME_CREATED_SUB;
END{WS}+SUB return tENDSUB;
END{WS}+IF return tENDIF;
END-IF return tENDIF;
END{WS}+WHILE return tWEND;
END-WHILE return tWEND;
END{WS}+SWITCH return tSEND;
END-SWITCH return tSEND;
END{WS}+"SWITCH$" return tSEND;
END-"SWITCH$" return tSEND;
EXPORT return tEXPORT;
ERROR return tERROR;
FOR return tFOR;
BREAK return tBREAK;
SWITCH return tSWITCH;
CASE return tCASE;
DEFAULT return tDEFAULT;
LOOP return tLOOP;
DO return tDO;
TO return tTO;
AS return tAS;
READING return tREADING;
WRITING return tWRITING;
STEP return tSTEP;
NEXT return tNEXT;
WHILE return tWHILE;
WEND return tWEND;
REPEAT return tREPEAT;
UNTIL return tUNTIL;
GOTO return tGOTO;
GOSUB return tGOSUB;
SUB return tSUB;
SUBROUTINE return tSUB;
LOCAL return tLOCAL;
STATIC return tSTATIC;
ON return tON;
INTERRUPT return tINTERRUPT;
CONTINUE return tCONTINUE;
LABEL return tLABEL;
IF return tIF;
THEN return tTHEN;
ELSE return tELSE;
ELSIF return tELSIF;
ELSEIF return tELSIF;
ENDIF return tENDIF;
FI return tENDIF;
OPEN return tOPEN;
CLOSE return tCLOSE;
SEEK return tSEEK;
TELL return tTELL;
PRINT return tPRINT;
USING return tUSING;
REVERSE return tREVERSE;
COLOR return tCOLOUR;
COLOUR return tCOLOUR;
BACKCOLOR return tBACKCOLOUR;
BACKCOLOUR return tBACKCOLOUR;
\? return tPRINT;
INPUT return tINPUT;
RETURN return tRETURN;
DIM return tDIM;
REDIM return tDIM;
END return tEND;
EXIT return tEXIT;
READ return tREAD;
DATA return tDATA;
RESTORE return tRESTORE;
AND return tAND;
OR return tOR;
NOT return tNOT;
EOR return tEOR;
XOR return tEOR;
WINDOW return tWINDOW;
ORIGIN return tORIGIN;
PRINTER return tPRINTER;
DOT return tDOT;
LINE return tLINE;
CURVE return tCURVE;
CIRCLE return tCIRCLE;
TRIANGLE return tTRIANGLE;
CLEAR return tCLEAR;
FILL return tFILL;
FILLED return tFILL;
TEXT return tTEXT;
RECTANGLE return tRECT;
RECT return tRECT;
BOX return tRECT;
BITBLIT return tPUTBIT;
BITBLT return tPUTBIT;
PUTBIT return tPUTBIT;
"BITBLT$" return tGETBIT;
"BITBLIT$" return tGETBIT;
"GETBIT$" return tGETBIT;
PUTSCREEN return tPUTCHAR;
"GETSCREEN$" return tGETCHAR;
NEW return tNEW;
WAIT return tWAIT;
PAUSE return tWAIT;
SLEEP return tWAIT;
BELL return tBELL;
BEEP return tBELL;
LET return tLET;
ARRAYDIM return tARDIM;
ARRAYDIMENSION return tARDIM;
ARRAYSIZE return tARSIZE;
NUMPARAM(S)?({WS}*\({WS}*\))? {yylval.symbol=(char *)my_strdup("numparams"); return tSYMBOL;}
BIND return tBIND;

SIN return tSIN;
ASIN return tASIN;
COS return tCOS;
ACOS return tACOS;
TAN return tTAN;
ATAN return tATAN;
EXP return tEXP;
LOG return tLOG;
SQRT return tSQRT;
SQR return tSQR;
INT return tINT;
CEIL return tCEIL;
FLOOR return tFLOOR;
FRAC return tFRAC;
ABS return tABS;
SIG return tSIG;
MOD return tMOD;
RAN return tRAN;
MIN return tMIN;
MAX return tMAX;
"LEFT$" return tLEFT;
"RIGHT$" return tRIGHT;
"MID$" return tMID;
"LOWER$" return tLOWER;
"UPPER$" return tUPPER;
"LTRIM$" return tLTRIM;
"RTRIM$" return tRTRIM;
"TRIM$" return tTRIM;
INSTR return tINSTR;
RINSTR return tRINSTR;
"CHOMP$" return tCHOMP;
LEN return tLEN;
VAL return tVAL;
EOF return tMYEOF;
"STR$" return tSTR;
"INKEY$" return tINKEY;
"MOUSEX" return tMOUSEX;
"MOUSEY" return tMOUSEY;
"MOUSEB" return tMOUSEB;
"MOUSEBUTTON" return tMOUSEB;
"MOUSEMOD" return tMOUSEMOD;
"MOUSEMODIFIER" return tMOUSEMOD;
"CHR$" return tCHR;
ASC return tASC;
"HEX$" return tHEX;
"BIN$" return tBIN;
DEC return tDEC;
AT return tAT;
@ return tAT;
SCREEN return tSCREEN;
SYSTEM return tSYSTEM;
"SYSTEM$" return tSYSTEM2;
"DATE$" return tDATE;
"TIME$" return tTIME;
PEEK return tPEEK;
"PEEK$" return tPEEK2;
POKE return tPOKE;
TOKEN return tTOKEN;
"TOKEN$" return tTOKENALT;
SPLIT return tSPLIT;
"SPLIT$" return tSPLITALT;
GLOB return tGLOB;
"^" return tPOW;
"**" return tPOW;

"<>" return tNEQ;
"<=" return tLEQ;
">=" return tGEQ;
"=" return tEQU;
"<" return tLTN;
">" return tGTN;
"!" return tNOT;

[-+*/:(),.;] {return yytext[0];}

0x[0-9a-zA-Z]+ {
  yylval.digits=(char *)my_strdup(yytext);
  return tHEXDIGITS;
}

[0-9]+ {
  yylval.digits=(char *)my_strdup(yytext);
  return tDIGITS;
}

(([0-9]+|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?) {
  { double d;
    sscanf(yytext,"%lg",&d);
    yylval.fnum=d;
    return tFNUM;
  }
}

pi {yylval.fnum=3.1415926535897932;return tFNUM;}
euler {yylval.fnum=2.7182818284590452;return tFNUM;}
TRUE {yylval.fnum=1; return tFNUM;}
FALSE {yylval.fnum=0; return tFNUM;}

{NAME} {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSYMBOL;
}

 /* Symbols with a trailing $-sign are treated special */
{NAME}\$ {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSTRSYM;
}

\"[^\"]*(\"|\n) {
  int cnt;
  if (yytext[yyleng-1]=='\n') yycolumn=1;
  if (yytext[yyleng-1]=='\n' && fi_pending) {fi_pending--;yyless(0);return tENDIF;}
  if (yytext[yyleng-1]=='\n') {
  	yylval.string=NULL;
  	return tSTRING;
  }
  for(cnt=0;yytext[yyleng-cnt-2]=='\\';cnt++) ;
  if (cnt%2) {
  	yyless(yyleng-1);
	yymore();
  } else {
	yylval.string=(char *)my_strdup(yytext+1);
	*(yylval.string+yyleng-2)='\0';
	replace(yylval.string);
	return tSTRING;
  }
}


. {if (isprint(yytext[0])) return yytext[0]; else return ' ';}

%%
void open_main(FILE *file,char *explicit,char *main_file_name) /* open main file */
{
  include_depth=0;
  
  if (explicit) {
    include_stack[include_depth]=yy_scan_string(explicit);
  } else {
    include_stack[include_depth]=yy_create_buffer(file,YY_BUF_SIZE);
  }
  library_stack[include_depth]=new_library(main_file_name,"main");
  library_chain[library_chain_length++]=library_stack[include_depth];
  if (!explicit) yy_switch_to_buffer(include_stack[include_depth]);
  currlib=library_stack[0];
  inlib=FALSE;
  
  return;
}


void open_string(char *cmd) /* open string with commands */
{
  yy_switch_to_buffer(yy_scan_string(cmd));
}


int import_lib(char *name) /* import library */
{
  char *full;
  static int end_of_all_imports=FALSE;
  static int ignore_nested_imports=FALSE;

  while(isspace(*name)) name++;
  name[strcspn(name, "\n")] = '\0';

  /* This can only occur in bound programs; void all further import-statements */
  if (!strcmp(name,"__END_OF_ALL_IMPORTS")) {
    error(sDEBUG,"Encountered special import __END_OF_ALL_IMPORTS");
    end_of_all_imports=TRUE;
  }

  if (end_of_all_imports) return TRUE;

  /* This can only occur in bound programs, close currently imported library */
  if (!strcmp(name,"__END_OF_CURRENT_IMPORT")) {
    error(sDEBUG,"Encountered special import __END_OF_CURRENT_IMPORT");
    include_depth--;
    leave_lib();
    ignore_nested_imports=FALSE; 
    return TRUE;
  }

  /* This can only occur in bound programs, ignore nested import-statement */
  if (!strcmp(name,"__IGNORE_NESTED_IMPORTS")) {
    error(sDEBUG,"Encountered special import __IGNORE_NESTED_IMPORTS");
    ignore_nested_imports=TRUE; 
  }

  if (ignore_nested_imports) return TRUE;

  include_depth++;
  inlib=TRUE;
  if (include_depth>=MAX_INCLUDE_DEPTH) {
    sprintf(string,"Could not import '%s': nested too deep (%d)",name,include_depth);
    error(sERROR,string);
    return FALSE;
  }

  if (is_bound) {
    full=name;
  } else {
    yyin=open_library(name,&full);
    if (!yyin) return FALSE;
    yy_switch_to_buffer(yy_create_buffer(yyin,YY_BUF_SIZE));
    include_stack[include_depth]=YY_CURRENT_BUFFER;
  }
  library_stack[include_depth]=new_library(full,NULL);
  library_chain[library_chain_length++]=library_stack[include_depth];
  if (library_chain_length>=MAX_INCLUDE_NUMBER) {
    sprintf(string,"Cannot import more than %d libraries",MAX_INCLUDE_NUMBER);
    error(sERROR,string);
    return FALSE;
  }
  if (!library_stack[include_depth]) {
    sprintf(string,"library '%s' has already been imported",full);
    error(sERROR,string);
    return FALSE;
  } 

  if (severity_threshold <= sNOTE) {
    if (isbound) {      
      sprintf(string,"importing library '%s'",name);
    } else {
      sprintf(string,"importing from file '%s'",full);
    }
    error(sNOTE,string);
  }
  currlib=library_stack[include_depth]; /* switch late because error() uses currlib */
  return TRUE;
}


FILE *open_library(char *name,char **fullreturn) /* search and open a library */
{
  static char full_wdir[200];
  static char full_main[200];
  static char full_global[200];
  char unquoted[200];
  char *p;
  FILE *lib;
  int i;

  for(p=name;strchr(" \"'`",*p);p++) if (!*p) break;
  strncpy(unquoted,p,200);
  for(;!strchr(" \"'`",*p);p++) if (!*p) break;
  if (*p) unquoted[p-name-2]='\0';
  name=unquoted;
  if (strchr(name,'.')) {
    sprintf(string,"library name '%s' contains '.'",name);
    error(sERROR,string);
    return NULL;
  }
  if (!strcmp(name,"main")) {
    if (is_bound) return NULL;
    error(sERROR,"invalid library name 'main'");
    return NULL;
  }

  /* search in current working dir */
  if (fullreturn) *fullreturn=full_wdir;
  strncpy(full_wdir,name,200);
  strcat(full_wdir,".yab");
  lib=fopen(full_wdir,"r");
  if (lib) return lib;
  
  /* search in dir of main file */
  if (fullreturn) *fullreturn=full_main;
  if (strchr(main_file_name,'/') || strchr(main_file_name,'\\')) {
    strncpy(full_main,main_file_name,200);
  } else {
    full_main[0]='\0';
  }
  for(i=0;i<2;i++) {
    p=strrchr(full_main,"\\/"[i]);
    if (p) *p='\0';
  }
  if (full_main[0] && !strchr("\\/",full_main[strlen(full_main)-1])) {
#ifdef UNIX
    strcat(full_main,"/");
#else
    strcat(full_main,"\\");
#endif
  }     
  strcat(full_main,name);
  strcat(full_main,".yab");
  lib=fopen(full_main,"r");
  if (lib) return lib;
  
  /* search in global directory */
  if (fullreturn) *fullreturn=full_global;
  strncpy(full_global,library_path,200);
  if (full_global[0] && !strchr("\\/",full_global[strlen(full_global)-1])) {
#ifdef UNIX
    strcat(full_global,"/");
#else
    strcat(full_global,"\\");
#endif
  }     
  strcat(full_global,name);
  strcat(full_global,".yab");
  lib=fopen(full_global,"r");
  if (lib) return lib;
    
  sprintf(string,"could not open library '%s': not in current workingdir as '%s', not in directory of main file as '%s', not in library path as '%s'",name,full_wdir,full_main,full_global);
  error(sERROR,string);
  return NULL;
}


void leave_lib(void) /* processing, when end of library is found */
{
  if (include_depth<0) return;
  if (severity_threshold <= sDEBUG) {
    sprintf(string,"End of library '%s', continue with '%s', include depth is now %d",currlib->short_name,library_stack[include_depth]->short_name,include_depth);
    error(sDEBUG,string);
  }
  yylineno=currlib->yylineno_at_start;
  currlib=library_stack[include_depth];
  inlib=(include_depth>0);
}


