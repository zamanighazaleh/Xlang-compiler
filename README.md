# Xlang-compiler
A compiler for a c-like language

Here is a compiler for Xlang language. It’s implemented in three phases: Lexical analyser, Syntax analyser and Semantic analyser. Compiler gets the code and prints its tokens in a tree structure. It also checks if there is any syntax or semantic error in code.

Xlang is a C-like language with these rules:

  •	All keywords must be written in lowercase (“if” is a keyword but “IF” is a variable)

  •	Keywords in Xlang: Boolean, break, callout, class, continue, else, for, if, false, return, true, void, int

  •	Variable names are made of characters, numbers and Underscore. Names can’t start with a number

  •	Use // to comment a line of code

  •	Strings should be in “ ” and chars should be in ‘ ‘

  •	Numbers should be 32-bit signed hexadecimal or decimal.

      Decimal: from -2147483648 to 2147483647
  
      Hexadecimal: 0x[a-f A-F 0-9]
  
  •	Operators in Xlang: + - * / % < > != <= >= == && || ! = -= +=

  •	Other tokens: ( ) { } [ ] ; ,

  •	All codes must be written in Program class that has three parts:

 	    Field declaration: Declaring global variables 
  
	    Method declaration: Defining Functions 
 
	    Main: void main(){} function as the entry point of program
 
  •	Conditional statement syntax: 
```
if (expr) {
//if body
}

if (expr) {
 //if body 
} 
else 
{ 
//else body
 }
```
For loop syntax:
```
for x = expr , expr {
//for body
}
```
# Requirements
Flex

Bison
# Project team
[@zamanighazaleh](https://github.com/zamanighazaleh)

[@RezaBlaugrana](https://github.com/RezaBlaugrana)
