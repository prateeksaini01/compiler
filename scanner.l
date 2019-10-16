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
[ \t] { /* eat white spaces */  }

("/*".*"*/")|("//"[^\n]*) { 
	printf("comment.");
}

\".*\" {
	printf("string literal.");
	return STRING;
}

([0-9]+)|([0-9]+"."[0-9]+) {
	printf("constant.");
	return CONSTANT;
}

"int"|"float" {
	printf("a datatype.");
	return DATATYPE;
}

"if"|"else"|"while"|"for"|"return"|"break"|"continue"|"input"|"output" {
	// printf("a keyword.");
	printf("%s.", yytext );
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
	printf("semicolon.");
	return SEMICOLON;
}

"," {
	printf("comma.");
	return COMMA;
}

"="|"+"|"-"|"*"|"/"|"%"|"&"|"|"|"^"|"<"|">"|(("="|"+"|"-"|"*"|"/"|"%"|"&"|"|"|"^"|"<"|">")"=")|"!="|"<<"|">>" {
	// printf("a binary operator.");
	printf("%s.", yytext );
	return BIN_OP;
}

"!"|"~"|"++"|"--" {
	printf("unary operator.");
	return UN_OP;
}

[(){}\[\]] {
	// printf("a bracket.");
	printf("%s.", yytext );
	if( yytext[0] == '(' ) return OPEN_BRACKET;
	if( yytext[0] == ')' ) return CLOSE_BRACKET;
	if( yytext[0] == '[' ) return OPEN_SQUARE;
	if( yytext[0] == ']' ) return CLOSE_SQUARE;
	if( yytext[0] == '{' ) return OPEN_CURLY;
	if( yytext[0] == '}' ) return CLOSE_CURLY;
}


[a-zA-Z][a-zA-Z0-9_]* {
	printf("identifier.");
	// send yytext to parser ( later )
	return INDENTIFIER;
}

\n {
	++lineno;
	printf("\n");
}
. {
	printf("Unrecognised character %c at lineno %d", yytext[0], lineno);
}
%%

// int main(){
// 	while(yylex());
// }