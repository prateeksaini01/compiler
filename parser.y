%define parse.error verbose
%{
	#include <stdio.h>

	// stuff from flex that bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	void yyerror(char const *s);
%}
%union {
	int   ival;
	float fval;
	char  sval[100];
}
%token <sval> STRING
%token <sval> CONSTANT
%token <sval> DATATYPE
%token <sval> IF_K
%token <sval> ELSE_K
%token <sval> WHILE_K
%token <sval> FOR_K
%token <sval> RETURN_K
%token <sval> BREAK_K
%token <sval> CONTINUE_K
%token <sval> INPUT_K
%token <sval> OUTPUT_K
%token <sval> SEMICOLON
%token <sval> COMMA
%token <sval> BIN_OP
%token <sval> UN_OP
%token <sval> OPEN_BRACKET
%token <sval> CLOSE_BRACKET
%token <sval> OPEN_SQUARE
%token <sval> CLOSE_SQUARE
%token <sval> OPEN_CURLY
%token <sval> CLOSE_CURLY
%token <sval> INDENTIFIER

%%

program : functionDefinition | program functionDefinition ;

literal : STRING | CONSTANT ;

inputStatement : INPUT_K OPEN_BRACKET INDENTIFIER CLOSE_BRACKET ;

outputStatement : OUTPUT_K OPEN_BRACKET INDENTIFIER CLOSE_BRACKET 
| OUTPUT_K OPEN_BRACKET literal CLOSE_BRACKET ;

expression : term | term BIN_OP expression ;

commaSeparatedExpressions : expression | commaSeparatedExpressions COMMA expression ;

functionCallStatement : INDENTIFIER OPEN_BRACKET CLOSE_BRACKET
| INDENTIFIER OPEN_BRACKET commaSeparatedExpressions CLOSE_BRACKET ;

term : INDENTIFIER | literal | functionCallStatement | OPEN_BRACKET UN_OP expression CLOSE_BRACKET | OPEN_BRACKET expression CLOSE_BRACKET;

declaration : DATATYPE INDENTIFIER | declaration OPEN_SQUARE expression CLOSE_SQUARE ;

commaSeparatedDeclarations : declaration | commaSeparatedDeclarations COMMA declaration ;

statement : SEMICOLON 
| RETURN_K expression SEMICOLON
| BREAK_K SEMICOLON
| CONTINUE_K SEMICOLON
| ifElseStatement
| forStatement
| whileStatement
| inputStatement SEMICOLON
| outputStatement SEMICOLON
| expression SEMICOLON
| declaration SEMICOLON ;

statements : statement | statements statement ;

block : OPEN_CURLY statements CLOSE_CURLY ;

whileStatement : WHILE_K OPEN_BRACKET expression CLOSE_BRACKET block ;

forStatement : FOR_K OPEN_BRACKET expression SEMICOLON expression SEMICOLON expression CLOSE_BRACKET block ;

ifStatement : IF_K OPEN_BRACKET expression CLOSE_BRACKET block ;

elseStatement : ELSE_K OPEN_BRACKET expression CLOSE_BRACKET block ;

ifElseStatement : ifStatement | ifStatement elseStatement ;

functionDefinition : DATATYPE INDENTIFIER OPEN_BRACKET commaSeparatedDeclarations CLOSE_BRACKET block 
| DATATYPE INDENTIFIER OPEN_BRACKET CLOSE_BRACKET block;
%%

void yyerror(char const *s)
{
	fprintf(stderr, "error: %s\n", s);
}


int main(int argc, char **argv)
{
	yyparse();
	printf("Parsing Over\n");
}
