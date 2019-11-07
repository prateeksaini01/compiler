%{
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"
int lineno = 0;
extern int yylex();

#define allocateAndCopy(a, b) a = (char *)malloc( sizeof(char)*( strlen(b) + 1 ) ); strncpy( a, b, strlen(b)+1 )

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
	yylval.sval = (char *)malloc( sizeof(char) *( strlen(yytext) - 1 ) );
	strncpy( yylval.sval, yytext + 1, strlen(yytext) - 2 );
	yylval.sval[strlen(yytext) - 2] = '\0';
	return STRING;
}

"'"."'" {
	printf("%s", yytext );
	yylval.cval = yytext[1];
	return CHAR;
}

([0-9]+)|([0-9]+"."[0-9]+) {
	printf("%s", yytext );
	yylval.ival = atoi(yytext);
	return CONSTANT;
}

"int"|"float"|"void" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return DATATYPE;
}

"if"|"else"|"while"|"for"|"return"|"break"|"continue"|"input"|"output" {
	// printf("%s", yytext );
	printf("%s", yytext );

allocateAndCopy(yylval.sval, yytext);

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
	yylval.cval = yytext[0];
	return SEMICOLON;
}

"," {
	printf("%s", yytext );
	yylval.cval = yytext[0];
	return COMMA;
}

"!"|"~"|"++"|"--" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return UN_OP;
}

"*" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return OP_MUL;
}

"/"|"%" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_MUL;
}

"+"|"-" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_ADD;
}

"<<"|">>" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_SHIFT;
}

"<"|">"|">="|"<=" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_REL;
}

"=="|"!=" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_EQ;
}

"&" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_BAND;
}

"^" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_BXOR;
}

"|" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_BOR;
}

"&&" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_LAND;
}

"||" {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_LOR;
}

"="|(("+"|"-"|"*"|"/"|"%"|"&"|"|"|"^")"=") {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
	return BIN_OP_ASSIGN;
}

"?" {
	printf("%s", yytext );
	yylval.cval = yytext[0];
	return QUESTION;
}

":" {
	printf("%s", yytext );
	yylval.cval = yytext[0];
	return COLON;
}

[(){}\[\]] {
	// printf("%s", yytext );
	printf("%s", yytext );
	yylval.cval = yytext[0];
	if( yytext[0] == '(' ) return OPEN_BRACKET;
	if( yytext[0] == ')' ) return CLOSE_BRACKET;
	if( yytext[0] == '[' ) return OPEN_SQUARE;
	if( yytext[0] == ']' ) return CLOSE_SQUARE;
	if( yytext[0] == '{' ) return OPEN_CURLY;
	if( yytext[0] == '}' ) return CLOSE_CURLY;
}


[a-zA-Z][a-zA-Z0-9_]* {
	printf("%s", yytext );
	allocateAndCopy(yylval.sval, yytext);
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