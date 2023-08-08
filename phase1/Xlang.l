%{
     
     #include <string.h>
     #include <stdio.h>
     #include <stdlib.h>
     #include <stdbool.h>
     
     int line = 1;

     int len_of_hex_dec(char *hex_dec);
     
%}

%%

     /* Keywords */
"boolean"           {fprintf(yyout, "TOKEN_BOOLEANTYPE %s\n", yytext);} 
"break"             {fprintf(yyout, "TOKEN_BREAKSTMT %s\n", yytext);}
"callout"           {fprintf(yyout, "TOKEN_CALLOUT %s\n", yytext);}
"class"             {fprintf(yyout, "TOKEN_CLASS %s\n", yytext);}
"continue"          {fprintf(yyout, "TOKEN_CONTINUESTMT %s\n", yytext);}
"else"              {fprintf(yyout, "TOKEN_ELSECONDITION %s\n", yytext);}
"for"               {fprintf(yyout, "TOKEN_LOOP %s\n", yytext);}
"if"                {fprintf(yyout, "TOKEN_IFCONDITION %s\n", yytext);}
"false"	          {fprintf(yyout, "TOKEN_BOOLEANCONST %s\n", yytext);}
"return"            {fprintf(yyout, "TOKEN_RETURN %s\n", yytext);}
"true"		     {fprintf(yyout, "TOKEN_BOOLEANCONST %s\n", yytext);}
"void"              {fprintf(yyout, "TOKEN_VOIDTYPE %s\n", yytext);}
"int"               {fprintf(yyout, "TOKEN_INTTYPE %s\n", yytext);}
"Program"           {fprintf(yyout, "TOKEN_PROGRAMCLASS %s\n", yytext);}
"main"              {fprintf(yyout, "TOKEN_MAINFUNC %s\n", yytext);}

     /* Operators */
"+"            {fprintf(yyout, "TOKEN_ARITHMATICOP %s\n", yytext);}
"-"            {fprintf(yyout, "TOKEN_ARITHMATICOP %s\n", yytext);}
"*"            {fprintf(yyout, "TOKEN_ARITHMATICOP %s\n", yytext);}
"/"            {fprintf(yyout, "TOKEN_ARITHMATICOP %s\n", yytext);}
"%"            {fprintf(yyout, "TOKEN_ARITHMATICOP %s\n", yytext);}
"<"            {fprintf(yyout, "TOKEN_RELATIONOP %s\n", yytext);}
">"            {fprintf(yyout, "TOKEN_RELATIONOP %s\n", yytext);}
"!="           {fprintf(yyout, "TOKEN_EQUALITYOP %s\n", yytext);}
"<="           {fprintf(yyout, "TOKEN_RELATIONOP %s\n", yytext);}
">="           {fprintf(yyout, "TOKEN_RELATIONOP %s\n", yytext);}
"=="           {fprintf(yyout, "TOKEN_EQUALITYOP %s\n", yytext);}
"||"           {fprintf(yyout, "TOKEN_CONDITIONOP %s\n", yytext);}
"&&"           {fprintf(yyout, "TOKEN_CONDITIONOP %s\n", yytext);}
"!"            {fprintf(yyout, "TOKEN_LOGICOP %s\n", yytext);}
"="            {fprintf(yyout, "TOKEN_ASSIGNOP %s\n", yytext);}
"-="           {fprintf(yyout, "TOKEN_ASSIGNOP %s\n", yytext);}
"+="           {fprintf(yyout, "TOKEN_ASSIGNOP %s\n", yytext);}

     /* Special tokens */
"("            {fprintf(yyout, "TOKEN_LP %s\n", yytext);}
")"            {fprintf(yyout, "TOKEN_RP %s\n", yytext);}
"{"            {fprintf(yyout, "TOKEN_LCB %s\n", yytext);}
"}"            {fprintf(yyout, "TOKEN_RCB %s\n", yytext);}
"["            {fprintf(yyout, "TOKEN_LB %s\n", yytext);}
"]"            {fprintf(yyout, "TOKEN_RB %s\n", yytext);}
";"            {fprintf(yyout, "TOKEN_SEMICOLON %s\n", yytext);}
","            {fprintf(yyout, "TOKEN_COMMA %s\n", yytext);}

     /* Numbers */
("-")?([0-9])+                          {if(atol(yytext) > 2147483647 || atol(yytext) < -2147483648) {fprintf(yyout, "error in line %d : number is out of range\n", line);} else {fprintf(yyout, "TOKEN_DECIMALCONST %s\n", yytext);}}
"0x"([0-9]|[a-fA-F])+|[0-9]+            {if(len_of_hex_dec(yytext) > 8) {fprintf(yyout, "error in line %d : number is out of range\n", line);} else {fprintf(yyout, "TOKEN_HEXADECIMALCONST %s\n", yytext);}}

     /* Variables */
(("_")|([0-9a-zA-Z]))*                  {if(yytext[0] >= '0' && yytext[0] <= '9') {fprintf(yyout, "error in line %d : wrong id definition\n", line);} else {fprintf(yyout, "TOKEN_IDENTIFIER %s\n", yytext);}}

     /* String and character */
\"(\\n|\\t|\\'|\\\\|\\\"|[^\\"'])*\"    {fprintf(yyout, "TOKEN_STRINGCONST %s\n", yytext);}
\'[ -~]\'                               {fprintf(yyout, "TOKEN_CHARCONST %s\n", yytext);}

     /* White spaces */
(\n)                {fprintf(yyout, "TOKEN_WHITESPACE [newline]\n"); line += 1;}
[\t]+               {fprintf(yyout, "TOKEN_WHITESPACE [tab]\n");}
" "+                {fprintf(yyout, "TOKEN_WHITESPACE [space]\n");}

     /* Comment */
"//".*              {fprintf(yyout, "TOKEN_COMMENT %s\n", yytext);}

     /* Invalid token */
.              {fprintf(yyout, "error in line %d : invalid token\n", line);}

%%

int yywrap() {}

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

int main() {

	yyin = fopen("Input_Code.txt", "r");
	yyout = fopen("Analyzer_Output.txt", "w");

	yylex();

	return 0;

}