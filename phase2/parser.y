%{
	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stddef.h>
	#include <vector>
	
	using namespace std;
	
	extern FILE* yyin;
	extern FILE* yyout;
	extern int line;
	extern int yylex();

	int yyerror(const char* message);
	
	
	
	vector <string> tree;
	int count = 0;
	int arg_count = 0;
	bool main_flag = false;
	FILE* syntax_tree;
	
	struct Node{
	char* name;
	char* value;
	struct Node *sister = NULL;
	struct Node *child = NULL;
	
	};
	struct Node* root=new Node();
	struct Node* child1;
	struct Node* child2;
	struct Node* child3;
	struct Node* child4;
	struct Node* child5;
	struct Node* child6;
	struct Node* child7;
	
	void printtree(struct Node* , int ,int );
	
%}

%define parse.error verbose
%locations

%union {
	int ival;
	char* sval;
	struct Node* node;
}


%start program


%token <sval> TOKEN_PROGRAMCLASS TOKEN_CLASS TOKEN_MAINFUNC
%token <sval> TOKEN_IFCONDITION TOKEN_ELSECONDITION TOKEN_LOOP
%token <sval> TOKEN_BREAKSTMT TOKEN_CONTINUESTMT
%token <sval> TOKEN_INTTYPE TOKEN_BOOLEANTYPE TOKEN_VOIDTYPE
%token <sval> TOKEN_CALLOUT TOKEN_RETURN
%token <sval> TOKEN_BOOLEANCONST

%token <sval> TOKEN_ARITHMATICOP
%token <sval> TOKEN_RELATIONOP
%token <sval> TOKEN_EQUALITYOP
%token <sval> TOKEN_CONDITIONOP
%token <sval> TOKEN_ASSIGNOP
%token <sval> TOKEN_LOGICOP

%token <sval> TOKEN_LP TOKEN_RP
%token <sval> TOKEN_LCB TOKEN_RCB
%token <sval> TOKEN_LB TOKEN_RB
%token <sval> TOKEN_COMMA TOKEN_SEMICOLON

%token <sval> TOKEN_IDENTIFIER
%token <sval> TOKEN_DECIMALCONST
%token <sval> TOKEN_HEXADECIMALCONST
%token <sval> TOKEN_CHARCONST TOKEN_STRINGCONST

%left TOKEN_ASSIGNOP
%left TOKEN_EQUALITYOP
%left TOKEN_CONDITIONOP
%left TOKEN_RELATIONOP
%left TOKEN_ARITHMATICOP
%nonassoc TOKEN_LOGICOP

%nterm <node> program field_method field_decl variable_star variable
%nterm <node> method_decl_star method_decl id_main argument_plus_
%nterm <node> argument_plus argument block var_decl_star var_decl
%nterm <node> id_plus statement_star type statement else_block_
%nterm <node> expr_ assign_op method_call expr_plus_ expr_plus
%nterm <node> callout_arg_plus_ callout_arg_plus method_name location expr 
%nterm <node> callout_arg literal int_literal

%%

program: 
		TOKEN_CLASS TOKEN_PROGRAMCLASS TOKEN_LCB field_method TOKEN_RCB
		{
			if (!main_flag) {
				yyerror("syntax error, the main function is not defined,");
			}


			root->name=strdup("<program>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CLASS");
			child1->value = strdup("class");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_PROGRAMCLASS");
			child2->value = strdup("Program");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_LCB");
			child3->value = strdup("{");
			
			child4 = new Node();
			child4->name = strdup("TOKEN_RCB");
			child4->value = strdup("}");
			
			root->child = child1;
			child1->sister = child2;
			child2->sister = child3;
			child3->sister = ($4);
			($4)->sister = child4;
			return 0;
		}
		;


field_method:
		
		field_decl field_method
		{
			$$ = new Node();
			($$)->name = strdup("<field_method>");	
			($$)->child = $1;
			($1)->sister = $2;
		}
		| method_decl_star
		{
			$$ = new Node();
			($$)->name = strdup("<field_method>");	
			($$)->child = $1;
		}
		;


field_decl:	
		type variable variable_star TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<field_decl>");	
			
			($$)->child = $1;
			($1)->sister = $2;
			($2)->sister = $3;
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			($3)->sister = child1;
		}
		;

variable_star:	
		TOKEN_COMMA variable variable_star
		{
			$$ = new Node();
			($$)->name = strdup("<variable_star>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
				
			($$)->child = child1;
			child1->sister = $2;
			($2)->child = $3;
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<variable_star>");
		}
		;

variable:	
		TOKEN_IDENTIFIER
		{
			$$ = new Node();
			($$)->name = strdup("<variable>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			($$)->child = child1;
		}	
		| TOKEN_IDENTIFIER TOKEN_LB int_literal TOKEN_RB
		{
			$$ = new Node();
			($$)->name = strdup("<variable>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LB");
			child2->value = strdup("[");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RB");
			child3->value = strdup("]");
			
			($$)->child = child1;
			child1->sister = child2;
			child2 -> sister = $3;
			$3 -> sister = child3;
		}
		;

method_decl_star:
		method_decl method_decl_star
		{
			$$ = new Node();
			($$)->name = strdup("<method_decl_star>");	
			($$)->child = $1;
			($1)->sister = $2;
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<method_decl_star>");
		}
		;

method_decl:	
		type id_main TOKEN_LP argument_plus_ TOKEN_RP block
		{
			$$ = new Node();
			($$)->name = strdup("<method_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			($$)->child = ($1);
			($1)->sister = ($2);
			($2) -> sister = child1;
			child1 -> sister = ($4);
			($4)->sister = child2;
			child2 ->sister = ($6);
		}
		| TOKEN_VOIDTYPE id_main TOKEN_LP argument_plus_ TOKEN_RP 			block
		{
			$$ = new Node();
			($$)->name = strdup("<method_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_VOIDTYPE");
			child1->value = strdup("void");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RP");
			child3->value = strdup(")");
			
			($$)->child = child1;
			child1->sister = ($2);
			($2) -> sister = child2;
			child2 -> sister = ($4);
			($4)->sister = child3;
			child3 ->sister = ($6);
		}
		;

id_main:	
		TOKEN_IDENTIFIER
		{
			$$ = new Node();
			($$)->name = strdup("<id_main>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			($$)->child = child1;
		}
		| TOKEN_MAINFUNC
		{
			main_flag = true;
			$$ = new Node();
			($$)->name = strdup("<id_main>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_MAINFUNC");
			child1->value = strdup("main");
			
			($$)->child = child1;
		}
		;

argument_plus_: 
		argument_plus
		{
			$$ = new Node();
			($$)->name = strdup("<argument_plus_>");	
			($$)->child = $1;
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<argument_plus_>");
		}
		;

argument_plus:  
		argument TOKEN_COMMA argument_plus
		{
			$$ = new Node();
			($$)->name = strdup("<argument_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			($$)->child = ($1);
			($1)->sister = child1;
			child1 -> sister = $3;
		}
		| argument
		{
			arg_count = 0;
			$$ = new Node();
			($$)->name = strdup("<argument_plus>");	
			($$)->child = $1;
		}
		;

argument:	
		type TOKEN_IDENTIFIER
		{
			arg_count += 1;
			if (arg_count > 4) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}
			
			if (main_flag) {
				yyerror("syntax error, the number of arguments is more than allowed,");
			}

			$$ = new Node();
			($$)->name = strdup("<argument_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $2;
			
			($$)->child = ($1);
			($1)->sister = child1;
		}
		;

block:		TOKEN_LCB var_decl_star statement_star TOKEN_RCB
		{
			$$ = new Node();
			($$)->name = strdup("<block>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LCB");
			child1->value = strdup("{");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RCB");
			child2->value = strdup("}");
			
			($$)->child = child1;
			child1->sister = ($2);
			($2) -> sister = ($3);
			($3) -> sister = child2;
		}
		;

var_decl_star:  var_decl var_decl_star
		{
			$$ = new Node();
			($$)->name = strdup("<var_decl_star>");	
			($$)->child = $1;
			($1)->sister = $2;
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<var_decl_star>");
		}
		;

var_decl:	type id_plus TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<var_decl>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			($$)->child = ($1);
			($1)->sister = ($2);
			($2)-> sister = child1;
		}
		;

id_plus:	
		TOKEN_IDENTIFIER TOKEN_COMMA id_plus
		{
			$$ = new Node();
			($$)->name = strdup("<id_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			child2 = new Node();
			child2->name = strdup("TOKEN_COMMA");
			child2->value = strdup(",");
			
			($$)->child = child1;
			child1->sister = child2;
			child2 -> sister = $3;
		}
		| TOKEN_IDENTIFIER
		{
			$$ = new Node();
			($$)->name = strdup("<id_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

statement_star: 
		statement statement_star
		{
			$$ = new Node();
			($$)->name = strdup("<statement_star>");	
			($$)->child = $1;
			($1)->sister = $2;
		}
		| /* epsilon */
		{
			$$ = new Node();
			($$)->name = strdup("<statement_star>");
		}
		;

type:		
		TOKEN_INTTYPE 
		{
			$$ = new Node();
			($$)->name = strdup("<type>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_INTTYPE");
			child1->value = strdup("int");;
			
			($$)->child = child1;
		}
		| TOKEN_BOOLEANTYPE
		{
			$$ = new Node();
			($$)->name = strdup("<type>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BOOLEANTYPE");
			child1->value = strdup("boolean");;
			
			($$)->child = child1;
		}
		;

statement:
		location assign_op expr TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			($$)->child = ($1);
			($1)->sister = ($2);
			($2)->sister = ($3);
			($3)-> sister = child1;
		}
		| method_call TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_SEMICOLON");
			child1->value = strdup(";");
			
			($$)->child = ($1);
			($1)-> sister = child1;
		}
		| TOKEN_IFCONDITION TOKEN_LP expr TOKEN_RP block 			else_block_
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IFCONDITION");
			child1->value = strdup("if");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RP");
			child3->value = strdup(")");
			
			($$)->child = child1;
			child1-> sister = child2;
			child2-> sister = ($3);
			($3)-> sister = child3;
			child3->sister = ($5);
			($5) ->sister = ($6);
		}
		| TOKEN_LOOP TOKEN_IDENTIFIER TOKEN_ASSIGNOP expr 			TOKEN_COMMA expr block
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LOOP");
			child1->value = strdup("for");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_IDENTIFIER");
			child2->value = $2;
			
			child3 = new Node();
			child3->name = strdup("TOKEN_ASSIGNOP");
			child3->value = $3;
			
			child4 = new Node();
			child4->name = strdup("TOKEN_COMMA");
			child4->value = strdup(",");
			
			($$)->child = child1;
			child1-> sister = child2;
			child2-> sister = child3;
			child3-> sister = ($4);
			($4)->sister = child4;
			child4 ->sister = ($6);
			($6) -> sister = ($7);
		}
		| TOKEN_RETURN expr_ TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_RETURN");
			child1->value = strdup("return");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			($$)->child = child1;
			child1->sister = ($2);
			($2) -> sister = child2;
		}
		| TOKEN_BREAKSTMT TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BREAKSTMT");
			child1->value = strdup("break");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			($$)->child = child1;
			child1->sister = child2;
		}
		| TOKEN_CONTINUESTMT TOKEN_SEMICOLON
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CONTINUESTMT");
			child1->value = strdup("continue");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_SEMICOLON");
			child2->value = strdup(";");
			
			($$)->child = child1;
			child1->sister = child2;
		}
		| block
		{
			$$ = new Node();
			($$)->name = strdup("<statement>");
			
			
			($$)->child = ($1);
		}
		;

else_block_:	TOKEN_ELSECONDITION block
		{
			$$ = new Node();
			($$)->name = strdup("<else_block_>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ELSECONDITION");
			child1->value = strdup("else");
			
			($$)->child = child1;
			child1->sister = ($2);
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<else_block_>");
		}
		;

expr_:		expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr_>");
			
			($$)->child = ($1);
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<expr_>");
		}
		;

assign_op:	TOKEN_ASSIGNOP
		{
			$$ = new Node();
			($$)->name = strdup("<assign_op>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ASSIGNOP");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

method_call:	method_name TOKEN_LP expr_plus_ TOKEN_RP
		{
			$$ = new Node();
			($$)->name = strdup("<method_call>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			($$)->child = ($1);
			($1)-> sister = child1;
			child1-> sister = ($3);
			($3)-> sister = child2;
		}
		| TOKEN_CALLOUT TOKEN_LP TOKEN_STRINGCONST 			callout_arg_plus_ TOKEN_RP
		{
			$$ = new Node();
			($$)->name = strdup("<method_call>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CALLOUT");
			child1->value = strdup("callout");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LP");
			child2->value = strdup("(");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_STRINGCONST");
			child3->value = $3;
			
			child4 = new Node();
			child4->name = strdup("TOKEN_RP");
			child4->value = strdup(")");
			
			($$)->child = child1;
			child1-> sister = child2;
			child2-> sister = child3;
			child3-> sister = ($4);
			($4) -> sister = child4;
		}
		;

expr_plus_:	expr_plus
		{
			$$ = new Node();
			($$)->name = strdup("<expr_plus_>");
			
			
			($$)->child = ($1);
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<expr_plus_>");
		}
		;

expr_plus:	expr TOKEN_COMMA expr_plus
		{
			$$ = new Node();
			($$)->name = strdup("<expr_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			($$)->child = ($1);
			($1) -> sister = child1;
			child1->sister = ($3);
		}
		| expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr_plus>");
			
			
			($$)->child = ($1);
		}
		;

callout_arg_plus_:
		TOKEN_COMMA callout_arg_plus
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg_plus_>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			($$)->child = child1;
			child1 -> sister = ($2);
		}
		| /* epsilon */ 
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg_plus_>");
		}
		;

callout_arg_plus:	
		callout_arg TOKEN_COMMA callout_arg_plus
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg_plus>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_COMMA");
			child1->value = strdup(",");
			
			($$)->child = ($1);
			($1) -> sister = child1;
			child1->sister = ($3);
		}
		| callout_arg
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg_plus>");
			
			
			($$)->child = ($1);
		}
		;

method_name:	
		TOKEN_IDENTIFIER
		{
			$$ = new Node();
			($$)->name = strdup("<method_name>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

location:	
		TOKEN_IDENTIFIER
		{
			$$ = new Node();
			($$)->name = strdup("<location>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = $1;
			
			($$)->child = child1;
		}
		| TOKEN_IDENTIFIER TOKEN_LB expr TOKEN_RB
		{
			$$ = new Node();
			($$)->name = strdup("<location>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_IDENTIFIER");
			child1->value = ($1);
			
			child2 = new Node();
			child2->name = strdup("TOKEN_LB");
			child2->value = strdup("[");
			
			child3 = new Node();
			child3->name = strdup("TOKEN_RB");
			child3->value = strdup("]");
			
			($$)->child = child1;
			child1-> sister = child2;
			child2-> sister = ($3);
			($3)-> sister = child3;
		}
		;

expr:		location
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			
			($$)->child = ($1);
		}
		| 
		method_call
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			
			($$)->child = ($1);
		}
		| 
		literal
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			
			($$)->child = ($1);
		}
		| expr TOKEN_ARITHMATICOP expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ARITHMATICOP");
			child1->value = $2;
			
			($$)->child = ($1);
			($1) ->sister = child1;
			child1 ->sister = ($3);
		}
		| expr TOKEN_RELATIONOP expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_RELATIONOP");
			child1->value = $2;
			
			($$)->child = ($1);
			($1) ->sister = child1;
			child1 ->sister = ($3);
		}
		| expr TOKEN_EQUALITYOP expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_EQUALITYOP");
			child1->value = $2;
			
			($$)->child = ($1);
			($1) ->sister = child1;
			child1 ->sister = ($3);
		}
		| expr TOKEN_CONDITIONOP expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CONDITIONOP");
			child1->value = $2;
			
			($$)->child = ($1);
			($1) ->sister = child1;
			child1 ->sister = ($3);
		}
		| TOKEN_ARITHMATICOP expr /* -<expr> */
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_ARITHMATICOP");
			child1->value = $1;
			
			($$)->child = child1;
			child1 ->sister = ($2);
		}
		| TOKEN_LOGICOP expr
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LOGICOP");
			child1->value = $1;
			
			($$)->child = child1;
			child1 ->sister = ($2);
		}
		| TOKEN_LP expr TOKEN_RP
		{
			$$ = new Node();
			($$)->name = strdup("<expr>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_LP");
			child1->value = strdup("(");
			
			child2 = new Node();
			child2->name = strdup("TOKEN_RP");
			child2->value = strdup(")");
			
			($$)->child = child1;
			child1->sister = ($2);
			($2)-> sister = child2;
		}
		;

callout_arg:	expr
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg>");
			
			
			($$)->child = ($1);
		}
		| TOKEN_STRINGCONST
		{
			$$ = new Node();
			($$)->name = strdup("<callout_arg>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_STRINGCONST");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

literal:	int_literal
		{
			$$ = new Node();
			($$)->name = strdup("<literal>");
			
			
			($$)->child = ($1);
		}
		| TOKEN_CHARCONST
		{
			$$ = new Node();
			($$)->name = strdup("<literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_CHARCONST");
			child1->value = $1;
			
			($$)->child = child1;
		}
		| TOKEN_BOOLEANCONST
		{
			$$ = new Node();
			($$)->name = strdup("<literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_BOOLEANCONST");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

int_literal:	
		TOKEN_DECIMALCONST 
		{
			$$ = new Node();
			($$)->name = strdup("<int_literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_DECIMALCONST");
			child1->value = $1;
			
			($$)->child = child1;
		}
		| TOKEN_HEXADECIMALCONST
		{
			$$ = new Node();
			($$)->name = strdup("<int_literal>");
			
			child1 = new Node();
			child1->name = strdup("TOKEN_HEXADECIMALCONST");
			child1->value = $1;
			
			($$)->child = child1;
		}
		;

%%


int main(int argc,char* argv[]) {
	yyin = fopen("Input_Code.txt", "r");
	syntax_tree = fopen("Analyzer_Output (Syntax Tree).txt", "w");
	//yyout = fopen("Analyzer_Output.txt", "w");
	
	yyparse();

	if (atoi(argv[1]) == 0) {
		printf("Analyzer Output (print by Token_Value):\n");
	}
	else if (atoi(argv[1]) == 1) {
		printf("Analyzer Output (print by Token_Name):\n");
	}

	printtree(root,atoi(argv[1]),0);
	fprintf(syntax_tree, "\n");
	printf("\n");
	return 0;
}

int yyerror(const char* message) {
	printf("Analyzer Output :\n");
	printf("%s in line %d !!", message, line);
	exit(-1);
}

void printtree(struct Node* node, int printmode,int count) {
	int i;
	
	for(int i=0;i<count;i++) fprintf(syntax_tree, "\t");

	if(printmode==1) {
		fprintf(syntax_tree, "%s ", node->name);
		printf("%s ", node->name);
	}
	else {
		if(strstr(node->name,"TOKEN")) {
			fprintf(syntax_tree, "%s ", node->value);
			printf("%s ", node->value);
		}
		else {
			fprintf(syntax_tree, "%s ", node->name);
			printf("%s ", node->name);
		}
	}
	fprintf(syntax_tree, "\n");
	
	
	if(node->child!=NULL) printtree(node->child,printmode,count+1);
	if(node->sister!=NULL) printtree(node->sister,printmode,count);
	return;
	
}
