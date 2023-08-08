%{
	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stddef.h>
	#include <vector>
	#include <stack>
	#include <sstream>
	

	using namespace std;


	extern FILE* yyin;
	extern FILE* yyout;
	extern int line;
	extern int yylex();

	
	FILE* ASM;

	int Error = 0;
	int count = 0, var_count = 0;
	int arg_count = 0, call_arg_count = 0;
	int Label = 0, Loop = 0, break_label, continue_label;

	char arg_t[4], var_type, expType = 'i';

	bool main_flag = false, call_flag = false, in_func = false, in_loop = false, see_return = false;

	string current_scope= "global";
	string here;
	string array_index, backup;
	

	vector <struct Variable*> variables;
  	vector <struct Function*> functions;
	vector <char*> var_list;

	stack <string> value_stack; 
	stack <char> type_stack;
	stack <int> scope_var_count;


	int yyerror(const char* message);

	struct Variable* search_variable (char* name, string scope);
  	void add_variable (char *name, string scope, string reg, char type, int range);

  	struct Function* search_function(char* name);
  	void add_function(char* name, char out_type, int args, char arg_type[4]);

  	string assign_register(char register_type);
  	void free_register(string reg);

	bool find_var (char* name);
  

	struct Variable {
		char* name;
		char type;
		string scope;
		string reg;
		int range;
  	};

  	struct Function {
		char* name;
		char out_type;
		int args;
		char* arg_type;
  	};


	/*Temporary Registers*/
	string t_registers[10] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
	bool t_registers_state[10] = {0};

	/*Saved Values Registers*/
	string s_registers[8] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};
	bool s_registers_state[8] = {0};

	/*Function Argument Registers*/
	string a_registers[4] = {"$a0", "$a1", "$a2", "$a3"};
	bool a_registers_state[4] = {0};

	/*Return Values Registers*/
	string v_registers[2] = {"$v0", "$v1"};
%}


%define parse.error verbose
%locations


%union {
	int ival;
	char cval;
	char* sval;
}


%start program

%token <sval> TOKEN_IFCONDITION TOKEN_ELSECONDITION TOKEN_LOOP
%token <sval> TOKEN_INTTYPE TOKEN_BOOLEANTYPE TOKEN_VOIDTYPE
%token <sval> TOKEN_PROGRAMCLASS TOKEN_CLASS TOKEN_MAINFUNC
%token <sval> TOKEN_BREAKSTMT TOKEN_CONTINUESTMT
%token <sval> TOKEN_CALLOUT TOKEN_RETURN
%token <sval> TOKEN_BOOLEANCONST

%token <sval> TOKEN_ARITHMATICOP_MUL TOKEN_ARITHMATICOP_DIV TOKEN_ARITHMATICOP
%token <sval> TOKEN_ARITHMATICOP_ADD TOKEN_ARITHMATICOP_SUB
%token <sval> TOKEN_RELATIONOP TOKEN_EQUALITYOP
%token <sval> TOKEN_CONDITIONOP
%token <sval> TOKEN_ASSIGNOP
%token <sval> TOKEN_LOGICOP

%token <sval> TOKEN_COMMA TOKEN_SEMICOLON
%token <sval> TOKEN_LCB TOKEN_RCB
%token <sval> TOKEN_LP TOKEN_RP
%token <sval> TOKEN_LB TOKEN_RB

%token <sval> TOKEN_CHARCONST TOKEN_STRINGCONST
%token <sval> TOKEN_HEXADECIMALCONST
%token <ival> TOKEN_DECIMALCONST
%token <sval> TOKEN_IDENTIFIER


%left TOKEN_ASSIGNOP
%left TOKEN_CONDITIONOP
%left TOKEN_EQUALITYOP
%left TOKEN_RELATIONOP
%left TOKEN_ARITHMATICOP_ADD TOKEN_ARITHMATICOP_SUB
%left TOKEN_ARITHMATICOP_MUL TOKEN_ARITHMATICOP_DIV TOKEN_ARITHMATICOP
%nonassoc TOKEN_LOGICOP


%nterm program field_method field_decl variable_star variable
%nterm argument_plus argument block var_decl_star var_decl
%nterm callout_arg_plus_ callout_arg_plus callout_arg
%nterm id_plus statement_star statement else_block_
%nterm method_decl_star method_decl argument_plus_
%nterm expr_ method_call expr_plus_ expr_plus

%nterm <sval> id_main location assign_op method_name
%nterm <ival> int_literal expr literal
%nterm <cval> type


%%

program: 
		TOKEN_CLASS TOKEN_PROGRAMCLASS TOKEN_LCB
		{
			scope_var_count.push(var_count);
			var_count = 0;
		}
		field_method TOKEN_RCB
		{
			if (!main_flag) {
				yyerror("syntax error, the main function is not defined,");
			}

			for (int i = 0; i < var_count; i++)
				var_list.pop_back();
			
			var_count = scope_var_count.top();
			scope_var_count.pop();

			return 0;
		}
		;

field_method:
		field_decl field_method
		| method_decl_star
		;

field_decl:	
		type variable variable_star TOKEN_SEMICOLON
		;

variable_star:	
		TOKEN_COMMA variable variable_star
		| /* epsilon */ 
		{}
		;

variable:	
		TOKEN_IDENTIFIER
		{
			if (find_var($1))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back($1);
			var_count += 1;

			add_variable ($1, current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable($1,current_scope)->reg).c_str());
                
            fclose(ASM);
		}	
		| TOKEN_IDENTIFIER TOKEN_LB int_literal TOKEN_RB
		{
			if (find_var($1))
				yyerror("semantic error, array has been defined,");
			var_list.push_back($1);
			var_count += 1;

			if ($3 <= 0)
				yyerror("semantic error, wrong range array,");

			add_variable ($1, current_scope, assign_register('s'), var_type, $3);

            ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi $a0, $zero, %d\n", int($3) * 4);
                
            fprintf(ASM,"\tli $v0, 9\n\tsyscall\n");
            fprintf(ASM,"\tmove %s, $v0\n", (search_variable($1,current_scope)->reg).c_str());
                
            fclose(ASM);
		}
		;

method_decl_star:
		method_decl method_decl_star
		| /* epsilon */ 
		{}
		;

method_decl:	
		type id_main TOKEN_LP 
		{
			here=string($2);
        	ASM = fopen("Output.asm", "a+");
        	fprintf(ASM, "%s:\n",$2);
        	fclose(ASM);

			if (string($2) != "main") {
				in_func = true;

				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
		argument_plus_ TOKEN_RP
		{
			current_scope= current_scope+ " " + string($2);
        	add_function($2, $1, arg_count, arg_t);
			
			arg_count = 0;
		}
		block
		{
			current_scope.erase(current_scope.size() - (string($2).size() + 1), string($2).size() + 1);

			if (string($2) == "main") {
				ASM = fopen("Output.asm", "a+");
				fprintf(ASM,"\tli %s, 10\n\tsyscall\n", v_registers[0].c_str());
				fclose(ASM);
        	}
			else {
				
				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM,"\tjr $ra\n");
				fclose(ASM);
				here = "";

				free_register("$a0");
				free_register("$a1");
				free_register("$a2");
				free_register("$a3");
			}

			if (!see_return)
				yyerror("semantic error, wrong return,");
		}
		| TOKEN_VOIDTYPE id_main TOKEN_LP
		{
			ASM = fopen("Output.asm", "a+");
        	fprintf(ASM, "%s:\n",$2);
        	fclose(ASM);
        	here=string($2);

			if (string($2) != "main") {
				in_func = true;

				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
		argument_plus_ TOKEN_RP 
		{
			current_scope= current_scope+ " " + string($2);
			add_function($2, 'v', arg_count, arg_t);

			arg_count = 0;
		} 
		block
		{
			current_scope.erase(current_scope.size() - (string($2).size() + 1), string($2).size() + 1);

        	if (string($2) == "main") {
				ASM = fopen("Output.asm", "a+");
				fprintf(ASM,"\tli %s, 10\n\tsyscall\n", v_registers[0].c_str());
				fclose(ASM);
        	}
			else {
				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM,"\tjr $ra\n");
				fclose(ASM);
				here = "";

				free_register("$a0");
				free_register("$a1");
				free_register("$a2");
				free_register("$a3");

			}
		}
		;

id_main:	
		TOKEN_IDENTIFIER
		{
			($$) = $1;
		}
		| TOKEN_MAINFUNC
		{
			main_flag = true;
			
			($$) = (char*)"main";
		}
		;

argument_plus_: 
		argument_plus
		| /* epsilon */ 
		{}
		;

argument_plus:  
		argument TOKEN_COMMA argument_plus
		| argument
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
			
			if (find_var($2))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back($2);
			var_count += 1;
			
			add_variable ($2, current_scope, assign_register('a'), $1, 0);
			arg_t[arg_count - 1] = $1;
		}
		;

block:
		TOKEN_LCB
		{
			if (!in_func) {
				scope_var_count.push(var_count);
				var_count = 0;
			}
		}
		var_decl_star
		{
			in_func = false;
		}
		statement_star TOKEN_RCB
		{
			for (int i = 0; i < var_count; i++)
				var_list.pop_back();
			
			var_count = scope_var_count.top();
			scope_var_count.pop();
		}
		;

var_decl_star: 
		var_decl var_decl_star
		| /* epsilon */ 
		{}
		;

var_decl:
		type id_plus TOKEN_SEMICOLON
		;

id_plus:	
		TOKEN_IDENTIFIER TOKEN_COMMA id_plus
		{
			if (find_var($1))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back($1);
			var_count += 1;

			add_variable ($1, current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable($1, current_scope)->reg).c_str());
                
            fclose(ASM);
		}
		| TOKEN_IDENTIFIER
		{
			if (find_var($1))
				yyerror("semantic error, variable has been defined,");
			var_list.push_back($1);
			var_count += 1;

			add_variable ($1, current_scope, assign_register('s'), var_type, 0);
			ASM = fopen("Output.asm", "a+");
                
            fprintf(ASM,"\taddi %s, $zero, 0\n", (search_variable($1,current_scope)->reg).c_str());
                
            fclose(ASM);
		}
		;

statement_star: 
		statement statement_star
		| /* epsilon */
		{}
		;

type:		
		TOKEN_INTTYPE 
		{
			($$) = 'i';
			var_type = 'i';
		}
		| TOKEN_BOOLEANTYPE
		{
			($$) = 'b';
			var_type = 'b';
		}
		;

statement:
		location assign_op
		{
			backup = array_index;
		}
		expr TOKEN_SEMICOLON
		{
			if (!find_var($1))
				yyerror("semantic error, this variable has not been defined,");

			if (string($2) == "=") {
				struct Variable* Rt = search_variable($1, current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				if (Rt->range == 0) {
					char t = type_stack.top();
					type_stack.pop();
					if (t != Rt->type)
						yyerror("semantic error, type of values used is not correct,");

					string Rs = value_stack.top();
					value_stack.pop();

					ASM = fopen("Output.asm", "a+");

					if(Rs[0] != '$')
						fprintf(ASM, "\taddi %s, $zero, %s \n", (Rt->reg).c_str(), Rs.c_str());
					else {
						fprintf(ASM, "\tmove %s, %s\n", (Rt->reg).c_str(), Rs.c_str());
						
						if(Rs[1] == 't')
							free_register(Rs);
					}

					fclose(ASM);
				}
				else {
					char t = type_stack.top();
					type_stack.pop();
					if (t != Rt->type)
						yyerror("semantic error, type of values used is not correct,");

					string Rs = value_stack.top();
					value_stack.pop();

					ASM = fopen("Output.asm", "a+");
					
              		string Rd1 = assign_register('t');
                    string Rd2 = assign_register('t');

              		if (backup[0] != '$' && Rs[0] != '$') {
              			fprintf(ASM, "\taddi %s, $zero , %s\n", Rd1.c_str(), Rs.c_str());
              			fprintf(ASM, "\tsw %s, %d(%s)\n", Rd1.c_str(), stoi(backup) * 4, Rt->reg.c_str() );
              		}
              		else if (backup[0] != '$') {
              			fprintf(ASM, "\tsw %s, %d(%s)\n", Rs.c_str(), stoi(backup) * 4, Rt->reg.c_str());

						if(Rs[1] == 't')
							free_register(Rs);
              		}
              		else if (Rs[0] != '$') {
              			fprintf(ASM, "\tsll %s, %s, 2\n", Rd1.c_str(), backup.c_str());
              			fprintf(ASM, "\tadd %s, %s, %s\n", Rd1.c_str(), Rd1.c_str(), Rt->reg.c_str());
              			fprintf(ASM, "\taddi %s, $zero, %s\n", Rd2.c_str(), Rs.c_str());
              			fprintf(ASM, "\tsw %s, 0(%s)\n", Rd2.c_str(), Rd1.c_str());

						if(backup[1] == 't')
							free_register(backup);
              		}
              		else{
              			fprintf(ASM, "\tsll %s, %s, 2\n", Rd1.c_str(), backup.c_str());
              			fprintf(ASM, "\tadd %s, %s, %s\n", Rd1.c_str(), Rd1.c_str(), Rt->reg.c_str());
              			fprintf(ASM, "\tsw %s, 0(%s)\n", Rs.c_str(), Rd1.c_str());

						if(Rs[1] == 't')
							free_register(Rs);
						if(backup[1] == 't')
							free_register(backup);
              		}
              				
					free_register(Rd1);
              		free_register(Rd2);
              		fclose(ASM);
				}
			}
			else if (string($2) == "+=") {
				struct Variable* Rt = search_variable($1, current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				char t = type_stack.top();
				type_stack.pop();
				if (t != Rt->type)
					yyerror("semantic error, type of values used is not correct,");

				string Rs = value_stack.top();
				value_stack.pop();

				ASM = fopen("Output.asm", "a+");

				if(Rs[0] != '$')
					fprintf(ASM, "\taddi %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
				else {
					fprintf(ASM, "\tadd %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
					
					if(Rs[1] == 't')
						free_register(Rs);
				}

                fclose(ASM);
			}
			else if (string($2) == "-=") {
				struct Variable* Rt = search_variable($1, current_scope);
				if(Rt == NULL) 
					yyerror("semantic error, this variable has not been defined,");

				char t = type_stack.top();
				type_stack.pop();
				if (t != Rt->type)
					yyerror("semantic error, type of values used is not correct,");

				string Rs = value_stack.top();
				value_stack.pop();

				ASM = fopen("Output.asm", "a+");

				if(Rs[0] != '$')
					fprintf(ASM, "\taddi %s, %s, -%s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
				else {
					fprintf(ASM, "\tsub %s, %s, %s \n", (Rt->reg).c_str(), (Rt->reg).c_str(), Rs.c_str());
					
					if(Rs[1] == 't')
						free_register(Rs);
				}

                fclose(ASM);
			} 
		}
		| method_call TOKEN_SEMICOLON
		{
			
		}
		| TOKEN_IFCONDITION TOKEN_LP expr TOKEN_RP 
		{
			current_scope = current_scope + " " + "if";

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'b')
				yyerror("semantic error, type of values used is not correct,");

            string Rd = value_stack.top();
            value_stack.pop();
            Label++;
            ASM = fopen("Output.asm", "a+");
        	fprintf(ASM,"\tbeq %s, $zero, L%d\n", Rd.c_str(), Label);
            fclose(ASM);
		}
		block else_block_
		| TOKEN_LOOP TOKEN_IDENTIFIER 
		{
			in_loop = true;

			current_scope = current_scope + " " + "loop";

			if (!find_var($2))
				yyerror("semantic error, this variable has not been defined,");
		}
		TOKEN_ASSIGNOP expr TOKEN_COMMA expr 
		{
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
	 		if(search_variable($2, current_scope) == NULL) yyerror("semantic error, this variable has not been defined,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\taddi %s,$zero,%s\n", (search_variable($2,current_scope)->reg).c_str(), Rs.c_str());
			
			Loop++;
			continue_label = Loop;
			fprintf(ASM,"LOOP%d:\n", Loop);

			string Rd = assign_register('t');
			fprintf(ASM,"\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
			fprintf(ASM,"\tslt %s,%s,%s\n", Rd.c_str(), (search_variable($2,current_scope)->reg).c_str(), Rd.c_str());
			fprintf(ASM,"\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
			Label++;
			break_label = Label;
	   		fprintf(ASM,"\tbeq %s,$zero,L%d\n", Rd.c_str(), Label);
		 
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
         
		}
		block
		{
			current_scope.erase(current_scope.size()-(string("loop").size()+1),string("loop").size()+1);
			
			ASM = fopen("Output.asm", "a+");
			
			type_stack.pop();

			string Rd = value_stack.top();
			value_stack.pop();
			//search for loop-counter in symbol-table
			fprintf(ASM,"\taddi %s,%s,1\n", Rd.c_str(), (search_variable($2,current_scope)->reg).c_str());
			fprintf(ASM,"\tmove %s,%s\n", (search_variable($2,current_scope)->reg).c_str(), Rd.c_str());
			fprintf(ASM,"\tj LOOP%d\n", Loop);
	  	    fprintf(ASM,"L%d:\n", Label);
			fclose(ASM);

			in_loop = false;
		}
		| TOKEN_RETURN expr_ TOKEN_SEMICOLON
		{
			if (search_function(strdup(here.c_str()))->out_type == 'v')
				yyerror("semantic error, wrong return,");
	
			char t = type_stack.top();
			type_stack.pop();
			if (t != search_function(strdup(here.c_str()))->out_type)
				yyerror("semantic error, type of values used is not correct,");

			string Rs=value_stack.top();
            value_stack.pop();
            // if(search_function(strdup(here.c_str()))->out_type!=expType) yyerror("semantic error, wrong return type,");

            string Rv = "$v0";


            ASM = fopen("Output.asm", "a+");

            if(Rs[0]!='$')
            	fprintf(ASM, "\taddi %s, $zero, %s \n",Rv.c_str() , Rs.c_str());
            else{
                fprintf(ASM, "\tmove %s, %s \n",Rv.c_str(), Rs.c_str());
                if(Rs[1] == 't')
                free_register(Rs);
            }
            fclose(ASM);

			see_return = true;
		}
		| TOKEN_BREAKSTMT TOKEN_SEMICOLON
		{
			if (!in_loop)
				yyerror("semantic error, wrong break,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj L%d\n", break_label);
			fclose(ASM);
	  	    
		}
		| TOKEN_CONTINUESTMT TOKEN_SEMICOLON
		{
			if (!in_loop)
				yyerror("semantic error, wrong continue,");

			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj Loop%d\n", continue_label);
			fclose(ASM);
		}
		| block
		;

else_block_:
		TOKEN_ELSECONDITION 
		{
			current_scope.erase(current_scope.size()-(string("if").size()+1),string("if").size()+1);
			current_scope=current_scope+" "+"else";
			
			Label++;
			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"\tj L%d\n", Label);
			fprintf(ASM,"L%d:\n", Label-1);
			fclose(ASM);
        }
		block
		{
			current_scope.erase(current_scope.size()-(string("else").size()+1),string("else").size()+1);
			
			ASM = fopen("Output.asm", "a+");
			fprintf(ASM,"L%d : \n", Label);
			fclose(ASM);
		}
		| /* epsilon */ 
		{
			ASM = fopen("Output.asm", "a+");
          	fprintf(ASM,"L%d:\n", Label);
          	fclose(ASM);
			
			current_scope.erase(current_scope.size()-(string("if").size()+1),string("if").size()+1);
		}
		;

expr_:
		expr
		| /* epsilon */ 
		{}
		;

assign_op:
		TOKEN_ASSIGNOP
		{
			($$) = $1;
		}
		;

method_call:	
		method_name TOKEN_LP
		{
			call_flag = true;
		}
		expr_plus_ TOKEN_RP
		{
			struct Function* func = search_function($1);
			if (func == NULL) 
				yyerror("semantic error, this function has not been defined,");
			else {
				if(func->args != call_arg_count) 
					yyerror("semantic error, the number of arguments does not match,");
				else {
					ASM = fopen("Output.asm", "a+");

					string arguments[4];
					for (int i = call_arg_count - 1; i >= 0; i--) {
						char t = type_stack.top();
						type_stack.pop();
						if (t != func->arg_type[i])
							yyerror("semantic error, type of values used is not correct,");

						arguments[i] = value_stack.top();
						value_stack.pop();
					}

					for (int i = 0; i < call_arg_count; i++) {
						if(arguments[i][0] != '$')
							fprintf(ASM, "\taddi $a%d,$zero,%s\n", i, arguments[i].c_str());
						else
							fprintf(ASM, "\tmove $a%d,%s\n", i, arguments[i].c_str());
					}
					fprintf(ASM,"\tjal %s\n", $1);
					
					fclose(ASM);

					if (func->out_type == 'i' || func->out_type == 'b') {
						value_stack.push("$v0");
						if (func->out_type == 'i')
							type_stack.push('i');
						else if (func->out_type == 'b')
							type_stack.push('b');
					}
				}
			}

			call_flag = false;
			call_arg_count = 0;
		}
		| TOKEN_CALLOUT TOKEN_LP TOKEN_STRINGCONST
		{
			call_flag = true;
		}
		callout_arg_plus_ TOKEN_RP
		{
			if(call_arg_count > 4) 
				yyerror("semantic error, the number of arguments does not match,");
			else {
				ASM = fopen("Output.asm", "a+");

				string arguments[4];
				for (int i = call_arg_count - 1; i >= 0; i--) {
					type_stack.pop();

					arguments[i] = value_stack.top();
					value_stack.pop();
				}

				for (int i = 0; i < call_arg_count; i++) {
					if(arguments[i][0] != '$')
						fprintf(ASM, "\taddi $a%d,$zero,%s\n", i, arguments[i].c_str());
					else
						fprintf(ASM, "\tmove $a%d,%s\n", i, arguments[i].c_str());
				}
				fprintf(ASM,"\tcall %s\n", $3);
					
				fclose(ASM);
			}

			call_flag = false;
			call_arg_count = 0;
		}
		;

expr_plus_:
		expr_plus
		| /* epsilon */ 
		{}
		;

expr_plus:	
		expr TOKEN_COMMA expr_plus
		{
			if (call_flag)
				call_arg_count += 1;
		}
		| expr
		{
			if (call_flag)
				call_arg_count += 1;
		}
		;

callout_arg_plus_:
		TOKEN_COMMA callout_arg_plus
		| /* epsilon */ 
		{}
		;

callout_arg_plus:	
		callout_arg TOKEN_COMMA callout_arg_plus
		{
			if (call_flag)
				call_arg_count += 1;
		}
		| callout_arg
		{
			if (call_flag)
				call_arg_count += 1;
		}
		;

method_name:	
		TOKEN_IDENTIFIER
		{
			($$) = $1;
		}
		;

location:	
		TOKEN_IDENTIFIER
		{
			($$) = $1;
			
			if (!find_var($1))
				yyerror("semantic error, this variable has not been defined,");

			struct Variable* Rs = search_variable($1, current_scope);
			
			if(Rs != NULL);
			else {
				yyerror("semantic error, this variable has not been defined,");
			}
			
			value_stack.push(Rs->reg);
			type_stack.push(Rs->type);
			expType = Rs->type;
		}
		| TOKEN_IDENTIFIER TOKEN_LB expr TOKEN_RB
		{
			($$) = $1;

			if (!find_var($1))
				yyerror("semantic error, this array has not been defined,");
			if (search_variable($1,current_scope)->range == 0)
				yyerror("semantic error, this array has not been defined,");

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'i')
				yyerror("semantic error, type of values used is not correct,");

			if (0 > $3 || $3 >= search_variable($1,current_scope)->range)
				yyerror("semantic error, wrong range array,");
			
			string Rs = value_stack.top();
        	value_stack.pop();
			array_index = Rs;
		}
		;

expr:	
		location
		{
			($$) = 1;
			
			struct Variable* Rt=search_variable($1,current_scope);//search $1 in lookup table and assign int to variable Struct Symbol *Rt
			if (Rt->range != 0) {
				string Rd = assign_register('t');
				
				ASM = fopen("Output.asm", "a+");

				if(array_index[0]!='$') {
					fprintf(ASM,"\tlw %s,%d(%s)\n", Rd.c_str(), stoi(array_index)*4, (Rt->reg).c_str());
				}
				else {
					fprintf(ASM,"\tsll %s,%s,2\n", Rd.c_str(), array_index.c_str());
					fprintf(ASM,"\tadd %s,%s,%s\n", Rd.c_str(), Rd.c_str(), (Rt->reg).c_str());
					fprintf(ASM,"\tlw %s,0(%s)\n", Rd.c_str(), Rd.c_str());

					if(array_index[1] == 't')
						free_register(array_index);
				}

				fclose(ASM);
				value_stack.push(Rd);
				if (Rt->type == 'i')
					type_stack.push('i');
				else if (Rt->type == 'b')
					type_stack.push('b');
			}
		}
		| method_call
		{
			($$) = 2;
		}
		| literal
		{
			($$) = $1;
		}
		| expr TOKEN_ARITHMATICOP_ADD expr
		{
			ASM = fopen("Output.asm", "a+");

			($$)= $1 + $3;

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			//cout<<Rt<<endl;
			string Rs = value_stack.top();
			value_stack.pop();
			//cout<<Rt<<endl;
			string Rd = assign_register('t');

			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) + stoi(Rt));
			else if(Rs[0] != '$')
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
			else if(Rt[0] != '$')
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			else
				fprintf(ASM, "\tadd %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			
			if(Rs[1] == 't')
						free_register(Rs);
			if(Rt[1] == 't')
						free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
		}
		| expr TOKEN_ARITHMATICOP_SUB expr
		{
			ASM = fopen("Output.asm", "a+");

			($$) = $1 - $3;

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
			string Rd = assign_register('t');

			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) - stoi(Rt));
			else if(Rs[0] != '$') {
				fprintf(ASM, "\tsub %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\taddi %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rs.c_str());
			}
			else if(Rt[0] != '$')
				fprintf(ASM, "\taddi %s,%s,-%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			else
				fprintf(ASM, "\tsub %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());

			if(Rs[1] == 't')
				free_register(Rs);
			if(Rt[1] == 't')
				free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);
			type_stack.push('i');
		}
		| expr TOKEN_ARITHMATICOP_MUL expr
		{
			ASM = fopen("Output.asm", "a+");

			($$) = $1 * $3;

			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");
				
			string Rt = value_stack.top();
			value_stack.pop();
			string Rs = value_stack.top();
			value_stack.pop();
			string Rd = assign_register('t');
				
			if(Rs[0] != '$' && Rt[0] != '$')
				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) * stoi(Rt));
			else if(Rs[0] != '$') {
				fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
			}
			else if(Rt[0] != '$') {
				fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			}
			else
				fprintf(ASM, "\tmul %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
			
			if(Rs[1] == 't')
				free_register(Rs);
			if(Rt[1] == 't')
				free_register(Rt);
				
			fclose(ASM);
			value_stack.push(Rd);	
			type_stack.push('i');
		}
		| expr TOKEN_ARITHMATICOP_DIV expr	//error
		{
			if ($3 == 0)
				yyerror("semantic error, divide by zero,");

        	ASM = fopen("Output.asm", "a+");
        
			($$)= $1 / $3;
  			
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
        	value_stack.pop();
  			string Rs = value_stack.top();
        	value_stack.pop();
        	string Rd = assign_register('t');
  			
			if(Rs[0] != '$' && Rt[0] != '$')
  				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) / stoi(Rt));
  			else if(Rs[0] != '$') {
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
        	}
        	else if(Rt[0] != '$'){
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rd.c_str());
        	}
  			else
          		fprintf(ASM, "\tdiv %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());

        	if(Rs[1] == 't')
  				free_register(Rs);
  			if(Rt[1] == 't')
  				free_register(Rt);
  			
			fclose(ASM);
  			value_stack.push(Rd);
			type_stack.push('i');
		}
		| expr TOKEN_ARITHMATICOP expr	// error
		{
			if($3 == 0)
				yyerror("semantic error, divide by zero,");

        	ASM = fopen("Output.asm", "a+");
        
			($$)= $1 % $3;
  			
			char t1 = type_stack.top();
			type_stack.pop();
			char t2 = type_stack.top();
			type_stack.pop();
			if (t1 != 'i' || t2 != 'i')
				yyerror("semantic error, type of values used is not correct,");

			string Rt = value_stack.top();
        	value_stack.pop();
  			string Rs = value_stack.top();
        	value_stack.pop();
        	string Rd = assign_register('t');
  			
			if(Rs[0] != '$' && Rt[0] != '$')
  				fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) % stoi(Rt));
  			else if(Rs[0] != '$') {
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
          		fprintf(ASM, "\tdiv %s,%s\n", Rd.c_str(), Rt.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
        	}
        	else if(Rt[0] != '$'){
          		fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
          		fprintf(ASM, "\tdiv %s,%s\n", Rs.c_str(), Rd.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
        	}
  			else {
          		fprintf(ASM, "\tdiv %s,%s\n", Rs.c_str(), Rt.c_str());
				fprintf(ASM, "\tmfhi %s\n", Rd.c_str());
			}

        	if(Rs[1] == 't')
  				free_register(Rs);
  			if(Rt[1] == 't')
  				free_register(Rt);
  			
			fclose(ASM);
  			value_stack.push(Rd);
			type_stack.push('i');
		}
		| expr TOKEN_RELATIONOP expr
		{
        	ASM = fopen("Output.asm", "a+");

			if (string($2) == "<") {
				($$) = $1 < $3 ? 1 : 0;
  			
			  	char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) < stoi(Rt));
  				else if(Rs[0] != '$') {
  					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
  				}
  				else if(Rt[0] != '$')
  					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				type_stack.push('b');
			}
			else if (string($2) == "<=") {
				($$) = $1 <= $3 ? 1 : 0;
  			
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

			  	string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) <= stoi(Rt));
  				else if(Rs[0] != '$') {
  					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
  				}
  				else if(Rt[0] != '$')
  					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
        		fprintf(ASM, "\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				type_stack.push('b');
			}
			else if (string($2) == ">") {
				($$) = $1 > $3 ? 1 : 0;
  			
			  	char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

			  	string Rt = value_stack.top();
        		value_stack.pop();
  				string Rs = value_stack.top();
        		value_stack.pop();
        		string Rd = assign_register('t');
  			
			  	if(Rs[0] != '$' && Rt[0] != '$')
  					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) > stoi(Rt));
  				else if(Rs[0] != '$')
          			fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
  				else if(Rt[0] != '$') {
          			fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rt.c_str());
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rs.c_str());
        		}
  				else
  					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rt.c_str(), Rs.c_str());
  			
			  	fclose(ASM);
  				value_stack.push(Rd);
				  type_stack.push('b');
			}
			else if (string($2) == ">=") {
				($$) = $1 >= $3 ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != 'i' || t2 != 'i')
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd.c_str(), stoi(Rs) >= stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rd.c_str(), Rt.c_str());
				}
				else if(Rt[0] != '$')
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
				else
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd.c_str(), Rs.c_str(), Rt.c_str());
				fprintf(ASM, "\txori %s,%s,1\n", Rd.c_str(), Rd.c_str());
				
				fclose(ASM);
				value_stack.push(Rd);
				type_stack.push('b');
			}
		}
		| expr TOKEN_EQUALITYOP expr
		{
        	ASM = fopen("Output.asm", "a+");
			
			if (string($2) == "!=") {
				($$) = $1 != $3 ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) != stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rt.c_str());
					fprintf(ASM," \tslti %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM," \tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else {
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM," \tslt %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM," \tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);

				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
			else if (string($2) == "==") {
				($$) = $1 == $3 ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) == stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslti %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}
				else {
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd1.c_str(), Rs.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,%s\n", Rd2.c_str(), Rt.c_str(), Rs.c_str());
					fprintf(ASM, "\txor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);

				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
		| expr TOKEN_CONDITIONOP expr
		{
        	ASM = fopen("Output.asm", "a+");
			
			if (string($2) == "&&") {
				($$) = $1 && $3 ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");

				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) && stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero %s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$ero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero,L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n",Label);
				}
				else {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero \n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd1.c_str());
					Label++;
					fprintf(ASM, "\tbeq %s,$zero,L%d\n", Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);
				
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
			else if (string($2) == "||") {
				($$) = $1 || $3 ? 1 : 0;
				
				char t1 = type_stack.top();
				type_stack.pop();
				char t2 = type_stack.top();
				type_stack.pop();
				if (t1 != t2)
					yyerror("semantic error, type of values used is not correct,");
				
				string Rt = value_stack.top();
				value_stack.pop();
				string Rs = value_stack.top();
				value_stack.pop();
				
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');
				
				if(Rs[0] != '$' && Rt[0] != '$')
					fprintf(ASM, "\taddi %s,$zero,%d\n", Rd1.c_str(), stoi(Rs) || stoi(Rt));
				else if(Rs[0] != '$') {
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n", Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero %s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$ero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}
				else if(Rt[0] != '$') {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n",Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s,L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslti %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\taddi %s,$zero,%s\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rd2.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n",Label);
				}
				else {
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero \n", Rd2.c_str(), Rs.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					Label++;
					fprintf(ASM, "\taddi %s,$zero,1\n", Rd2.c_str());
					fprintf(ASM, "\tbeq %s,%s,L%d\n", Rd2.c_str(), Rd1.c_str(), Label);
					fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rt.c_str());
					fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rt.c_str());
					fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
					fprintf(ASM, "L%d:\n", Label);
				}

				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
				if(Rt[1] == 't')
					free_register(Rt);
				
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
		| TOKEN_ARITHMATICOP_SUB expr
		{
			($$) = -$2;
  			
			char t = type_stack.top();
			type_stack.pop();
			if (t != 'i')
				yyerror("semantic error, type of values used is not correct,");
			
			string Rs = value_stack.top();
			value_stack.pop();
			
			if(Rs[0] != '$') {
				value_stack.push("-" + to_string($2));
				type_stack.push('i');
			}
			else {
				string Rd = assign_register('t');

				ASM = fopen("Output.asm", "a+");
				
				fprintf(ASM, "\tsub %s,$zero,%s\n", Rd.c_str(), Rs.c_str());
				
				fclose(ASM);
				value_stack.push(Rd);
				type_stack.push('i');
			}
		}
		| TOKEN_LOGICOP expr
		{
			($$) = !$2;

			char t = type_stack.top();
			type_stack.pop();
			if (t != 'b')
				yyerror("semantic error, type of values used is not correct,");
	
			string Rs = value_stack.top();
			value_stack.pop();
			
			if(Rs[0] != '$'){
					if(Rs[0] != '$' == 0)
						value_stack.push("1");
					else
						value_stack.push("0");
					
					type_stack.push('b');
			}
			else {
				string Rd1 = assign_register('t');
				string Rd2 = assign_register('t');

				ASM = fopen("Output.asm", "a+");
					
				fprintf(ASM, "\tslt %s,$zero,%s\n", Rd1.c_str(), Rs.c_str());
				fprintf(ASM, "\tslt %s,%s,$zero\n", Rd2.c_str(), Rs.c_str());
				fprintf(ASM, "\tor %s,%s,%s\n", Rd1.c_str(), Rd1.c_str(), Rd2.c_str());
				fprintf(ASM, "\txori %s,%s,1\n", Rd1.c_str(), Rd1.c_str());
				
				free_register(Rd2);
				if(Rs[1] == 't')
					free_register(Rs);
			
				fclose(ASM);
				value_stack.push(Rd1);
				type_stack.push('b');
			}
		}
		| TOKEN_LP expr TOKEN_RP
		{
        	($$) = $2;
		}
		;

callout_arg:
		expr
		| TOKEN_STRINGCONST
		;

literal:	
		int_literal
		{
			($$) = $1;
		}
		| TOKEN_CHARCONST
		{

		}
		| TOKEN_BOOLEANCONST
		{
			int tmp;
			if (string($1) == "true")
				tmp = 1;
			else if (string($1) == "false")
				tmp = 0;

			($$) = tmp;

			value_stack.push(to_string(tmp));
			type_stack.push('b');
			
			expType = 'b';
		}
		;

int_literal:	
		TOKEN_DECIMALCONST 
		{
			($$) = $1;

			value_stack.push(to_string($1));
			type_stack.push('i');
			
			expType = 'i';
		}
		| TOKEN_HEXADECIMALCONST
		{
			unsigned int w;
			std::istringstream iss($1);
			iss >> std::hex >> w;

			($$) = w;

			value_stack.push(to_string(w));
			type_stack.push('i');

			expType = 'i';
		}
		;

%%


int main(int argc, char* argv[]) {
	yyin = fopen("Input_Code.txt", "r");
	if (yyin == 0) {
		cout << "Unable to open the file !!!" << endl;
    	return 0;
	}

  	ASM = fopen("Output.asm", "w");
	if (ASM == 0) {
    	cout << "Unable to create the output file !!!" << endl;
    	return 0;
	}
	else {
		fprintf(ASM, ".globl main\n");
		fclose(ASM);
	}

  	yyparse();

  	if (Error) {
    	fclose(ASM);
    	remove("Output.asm");
    	return 0;
  	}
	
	return 0;
}

int yyerror (const char* message) {
	printf("%s in line %d !!\n", message, line);
	Error++;
	exit(-1);
}

void add_variable (char* name, string scope, string reg, char type, int range) {
	struct Variable *ns = new Variable();
	ns->name = name;
	ns->scope = scope;
	ns->reg = reg;
	ns->type = type;
	ns->range = range;
	variables.push_back(ns);
}

struct Variable* search_variable (char* name, string scope) {
	for(int i = 0; i < variables.size(); i++) {
		if (strcmp(name, variables[i]->name) == 0 && scope == variables[i]->scope) {
			return variables[i];
		}
	}
	int m = scope.find_last_of(" ");
	while (m != -1) {
		string newscope = scope.substr(0, m);
		for (int i = 0; i < variables.size(); i++) {
      		if (strcmp(name, variables[i]->name) == 0 && newscope == variables[i]->scope) {
        		return variables[i];
      		}
    	}
    	m = newscope.find_last_of(" ");
  	}
  	return NULL;
}

struct Function* search_function (char* name) {
	for(int i = 0; i < functions.size(); i++)
		if(strcmp(name, functions[i]->name) == 0)
			return functions[i];
	return NULL;
}

void add_function (char* name, char out_type, int args, char arg_type[4]) {
	struct Function* nf = new Function();
	nf->name = name;
	nf->out_type = out_type;
	nf->args = args;
	nf->arg_type = arg_type;
	functions.push_back(nf);
}

string assign_register (char register_type) {
  	// register_type : 't','s','a'
  	switch (register_type) {
		case 't':
			for (int i = 0; i <= 9; i++)
				if (t_registers_state[i] == 0)
					{t_registers_state[i] = 1; return "$t" + to_string(i);}
			break;
		case 's':
			for (int i = 0; i <= 7; i++)
				if (s_registers_state[i] == 0)
					{s_registers_state[i] = 1; return "$s" + to_string(i);}
			break;
		case 'a':
			for (int i = 0; i <= 3; i++)
				if (a_registers_state[i] == 0)
					{a_registers_state[i] = 1; return "$a" + to_string(i);}
			break;
	}
	return "$";
}

void free_register(string reg) {
	// reg ~ '$t0'
	switch (reg[1]) {
		case 't':
			t_registers_state[reg[2] - '0'] = 0;
			break;
		case 's':
			s_registers_state[reg[2] - '0'] = 0;
			break;
		case 'a':
			a_registers_state[reg[2] - '0'] = 0;
			break;
	}
}

bool find_var(char* name) {
	for (int i = 0; i < var_list.size(); i++) {
		if (string(var_list[i]) == string(name))
			return true;
	}
	return false;
}