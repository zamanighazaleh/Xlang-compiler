%{
     
     #include "parser.tab.h"

     #include <string.h>
     #include <stdio.h>
     #include <stdlib.h>
     #include <stdbool.h>
     
     int line = 1;

     int len_of_hex_dec(char *hex_dec);
     
%}

%%

     /* Keywords */
"boolean"           {yylval.sval = strdup(yytext); return TOKEN_BOOLEANTYPE;} 
"break"             {yylval.sval = strdup(yytext); return TOKEN_BREAKSTMT;}
"callout"           {yylval.sval = strdup(yytext); return TOKEN_CALLOUT;}
"class"             {yylval.sval = strdup(yytext); return TOKEN_CLASS;}
"continue"          {yylval.sval = strdup(yytext); return TOKEN_CONTINUESTMT;}
"else"              {yylval.sval = strdup(yytext); return TOKEN_ELSECONDITION;}
"for"               {yylval.sval = strdup(yytext); return TOKEN_LOOP;}
"if"                {yylval.sval = strdup(yytext); return TOKEN_IFCONDITION;}
"false"	          {yylval.sval = strdup(yytext); return TOKEN_BOOLEANCONST;}
"return"            {yylval.sval = strdup(yytext); return TOKEN_RETURN;}
"true"		     {yylval.sval = strdup(yytext); return TOKEN_BOOLEANCONST;}
"void"              {yylval.sval = strdup(yytext); return TOKEN_VOIDTYPE;}
"int"               {yylval.sval = strdup(yytext); return TOKEN_INTTYPE;}
"Program"           {yylval.sval = strdup(yytext); return TOKEN_PROGRAMCLASS;}
"main"              {yylval.sval = strdup(yytext); return TOKEN_MAINFUNC;}

     /* Operators */
"+"            {yylval.sval = strdup(yytext); return TOKEN_ARITHMATICOP;}
"-"            {yylval.sval = strdup(yytext); return TOKEN_ARITHMATICOP;}
"*"            {yylval.sval = strdup(yytext); return TOKEN_ARITHMATICOP;}
"/"            {yylval.sval = strdup(yytext); return TOKEN_ARITHMATICOP;}
"%"            {yylval.sval = strdup(yytext); return TOKEN_ARITHMATICOP;}
"<"            {yylval.sval = strdup(yytext); return TOKEN_RELATIONOP;}
">"            {yylval.sval = strdup(yytext); return TOKEN_RELATIONOP;}
"!="           {yylval.sval = strdup(yytext); return TOKEN_EQUALITYOP;}
"<="           {yylval.sval = strdup(yytext); return TOKEN_RELATIONOP;}
">="           {yylval.sval = strdup(yytext); return TOKEN_RELATIONOP;}
"=="           {yylval.sval = strdup(yytext); return TOKEN_EQUALITYOP;}
"||"           {yylval.sval = strdup(yytext); return TOKEN_CONDITIONOP;}
"&&"           {yylval.sval = strdup(yytext); return TOKEN_CONDITIONOP;}
"!"            {yylval.sval = strdup(yytext); return TOKEN_LOGICOP;}
"="            {yylval.sval = strdup(yytext); return TOKEN_ASSIGNOP;}
"-="           {yylval.sval = strdup(yytext); return TOKEN_ASSIGNOP;}
"+="           {yylval.sval = strdup(yytext); return TOKEN_ASSIGNOP;}

     /* Special tokens */
"("            {yylval.sval = strdup(yytext); return TOKEN_LP;}
")"            {yylval.sval = strdup(yytext); return TOKEN_RP;}
"{"            {yylval.sval = strdup(yytext); return TOKEN_LCB;}
"}"            {yylval.sval = strdup(yytext); return TOKEN_RCB;}
"["            {yylval.sval = strdup(yytext); return TOKEN_LB;}
"]"            {yylval.sval = strdup(yytext); return TOKEN_RB;}
";"            {yylval.sval = strdup(yytext); return TOKEN_SEMICOLON;}
","            {yylval.sval = strdup(yytext); return TOKEN_COMMA;}

     /* Numbers */
("-")?([0-9])+                          {if(atol(yytext) > 2147483647 || atol(yytext) < -2147483648) {printf("error in line %d : number is out of range\n", line);} else {yylval.sval = strdup(yytext); return TOKEN_DECIMALCONST;}}
"0x"([0-9]|[a-fA-F])+|[0-9]+            {if(len_of_hex_dec(yytext) > 8) {printf("error in line %d : number is out of range\n", line);} else {yylval.sval = strdup(yytext); return TOKEN_HEXADECIMALCONST;}}

     /* Variables */
(("_")|([0-9a-zA-Z]))*                  {if(yytext[0] >= '0' && yytext[0] <= '9') {printf("error in line %d : wrong id definition\n", line);} else {yylval.sval = strdup(yytext); return TOKEN_IDENTIFIER;}}

     /* String and character */
\"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])*\"    {yylval.sval = strdup(yytext); return TOKEN_STRINGCONST;}
\'[ -~]\'                               {yylval.sval = strdup(yytext); return TOKEN_CHARCONST;}

     /* White spaces */
(\n)                {line += 1; /*yylval.sval = strdup(yytext); return TOKEN_WHITESPACE;*/}
[\t]+               {/*yylval.sval = strdup(yytext); return TOKEN_WHITESPACE;*/}
" "+                {/*yylval.sval = strdup(yytext); return TOKEN_WHITESPACE;*/}

     /* Comment */
"//".*              {}

     /* Invalid token */
.              {/*printf("error in line %d : invalid token\n", line, yytext);*/} //

%%

int yywrap() {return 0;}

int len_of_hex_dec(char *hex_dec) {

     bool flag = false;
     int count = 0;

     for (int i = 2; hex_dec[i]; i++) {

          if (hex_dec[i] != '0') {
               flag = true;
          }

          if (flag) {
               count ++;
          }

     }

     return count;

}