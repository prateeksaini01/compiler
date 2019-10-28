%{
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"
int lineno = 0;
extern int yylex();

%}
%option noyywrap
%% 
[ \t] { 
	/* eat white spaces */  
	printf("%s", yytext );
}

"//"[^\n]* { 
	printf("%s", yytext );
}

\".*\" {
	printf("%s", yytext );
	return STRING;
}

([0-9]+)|([0-9]+"."[0-9]+) {
	printf("%s", yytext );
	return CONSTANT;
}

"int"|"float"|"void" {
	printf("%s", yytext );
	return DATATYPE;
}

"if"|"else"|"while"|"for"|"return"|"break"|"continue"|"input"|"output" {
	// printf("%s", yytext );
	printf("%s", yytext );
	if( !strcmp(yytext,"if") )			return IF_K;
	if( !strcmp(yytext,"else") )		return ELSE_K;
	if( !strcmp(yytext,"while") )		return WHILE_K;
	if( !strcmp(yytext,"for") )			return FOR_K;
	if( !strcmp(yytext,"return") )		return RETURN_K;
	if( !strcmp(yytext,"break") )		return BREAK_K;
	if( !strcmp(yytext,"continue") )	return CONTINUE_K;
	if( !strcmp(yytext,"input") )		return INPUT_K;
	if( !strcmp(yytext,"output") )		return OUTPUT_K;
}

";" {
	printf("%s", yytext );
	return SEMICOLON;
}

"," {
	printf("%s", yytext );
	return COMMA;
}

"!"|"~"|"++"|"--" {
	printf("%s", yytext );
	return UN_OP;
}

"*" {
	printf("%s", yytext );
	return OP_MUL;
}

"/"|"%" {
	printf("%s", yytext );
	return BIN_OP_MUL;
}

"+"|"-" {
	printf("%s", yytext );
	return BIN_OP_ADD;
}

"<<"|">>" {
	printf("%s", yytext );
	return BIN_OP_SHIFT;
}

"<"|">"|">="|"<=" {
	printf("%s", yytext );
	return BIN_OP_REL;
}

"=="|"!=" {
	printf("%s", yytext );
	return BIN_OP_EQ;
}

"&" {
	printf("%s", yytext );
	return BIN_OP_BAND;
}

"^" {
	printf("%s", yytext );
	return BIN_OP_BXOR;
}

"|" {
	printf("%s", yytext );
	return BIN_OP_BOR;
}

"&&" {
	printf("%s", yytext );
	return BIN_OP_LAND;
}

"||" {
	printf("%s", yytext );
	return BIN_OP_LOR;
}

"="|(("+"|"-"|"*"|"/"|"%"|"&"|"|"|"^")"=") {
	printf("%s", yytext );
	return BIN_OP_ASSIGN;
}

[(){}\[\]] {
	// printf("%s", yytext );
	printf("%s", yytext );
	if( yytext[0] == '(' ) return OPEN_BRACKET;
	if( yytext[0] == ')' ) return CLOSE_BRACKET;
	if( yytext[0] == '[' ) return OPEN_SQUARE;
	if( yytext[0] == ']' ) return CLOSE_SQUARE;
	if( yytext[0] == '{' ) return OPEN_CURLY;
	if( yytext[0] == '}' ) return CLOSE_CURLY;
}


[a-zA-Z][a-zA-Z0-9_]* {
	printf("%s", yytext );
	// send yytext to parser ( later )
	return IDENTIFIER;
}

\n {
	++lineno;
	printf("%s", yytext );
}
. {
	printf("Unrecognised character %c at lineno %d", yytext[0], lineno);
}
%%

// int main(){
// 	while(yylex());
// }