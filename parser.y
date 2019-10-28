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
%token <sval> OP_MUL
%token <sval> BIN_OP_MUL
%token <sval> BIN_OP_ADD
%token <sval> BIN_OP_SHIFT
%token <sval> BIN_OP_REL
%token <sval> BIN_OP_EQ
%token <sval> BIN_OP_ASSIGN 
%token <sval> BIN_OP_BAND 
%token <sval> BIN_OP_BOR 
%token <sval> BIN_OP_BXOR 
%token <sval> BIN_OP_LAND 
%token <sval> BIN_OP_LOR 
%token <sval> UN_OP
%token <sval> OPEN_BRACKET
%token <sval> CLOSE_BRACKET
%token <sval> OPEN_SQUARE
%token <sval> CLOSE_SQUARE
%token <sval> OPEN_CURLY
%token <sval> CLOSE_CURLY
%token <sval> IDENTIFIER

%%

program 
: functionDefinition 
| program functionDefinition ;

literal 
: STRING 
| CONSTANT ;

inputStatement 
: INPUT_K OPEN_BRACKET IDENTIFIER CLOSE_BRACKET ;

outputStatement 
: OUTPUT_K OPEN_BRACKET IDENTIFIER CLOSE_BRACKET 
| OUTPUT_K OPEN_BRACKET literal CLOSE_BRACKET ;

expression 
: prec12 ;

// ++ -- ~ !
prec0
: prec0 UN_OP
| term ;

// ++ -- ~ ! + - * &
prec1
: UN_OP prec1
| BIN_OP_ADD prec1
| BIN_OP_BAND prec1
| OP_MUL prec1
| prec0 ;

// * / %
prec2 
: prec2 BIN_OP_MUL prec1
| prec2 OP_MUL prec1
| prec1 ;

// + -
prec3 
: prec3 BIN_OP_ADD prec2
| prec2 ;

// << >>
prec4 
: prec4 BIN_OP_SHIFT prec3
| prec3 ;

// < > <= >=
prec5
: prec5 BIN_OP_REL prec4
| prec4 ;

// == !=
prec6
: prec6 BIN_OP_EQ prec5
| prec5 ;

// &
prec7
: prec7 BIN_OP_BAND prec6
| prec6 ;

// ^
prec8
: prec8 BIN_OP_BXOR prec7
| prec7 ;

// |
prec9
: prec9 BIN_OP_BOR prec8
| prec8 ;

// &&
prec10
: prec10 BIN_OP_LAND prec9
| prec9 ;

// ||
prec11
: prec11 BIN_OP_LOR prec10
| prec10 ;

// = and other compunded assignments
prec12
: prec11 BIN_OP_ASSIGN prec12
| prec11 ;

term 
: IDENTIFIER 
| literal 
| functionCall 
| term OPEN_SQUARE expression CLOSE_SQUARE
| OPEN_BRACKET expression CLOSE_BRACKET ;

commaSeparatedExpressions 
: expression 
| commaSeparatedExpressions COMMA expression ;

functionCall 
: IDENTIFIER OPEN_BRACKET CLOSE_BRACKET
| IDENTIFIER OPEN_BRACKET commaSeparatedExpressions CLOSE_BRACKET ;

identifier
: functionIdentifier
| identifier OPEN_SQUARE expression CLOSE_SQUARE ;

declaration
: DATATYPE identifier ;

commaSeparatedDeclarations 
: declaration 
| commaSeparatedDeclarations COMMA declaration ;

statement 
: SEMICOLON 
| RETURN_K expression SEMICOLON
| BREAK_K SEMICOLON
| CONTINUE_K SEMICOLON
| ifElseStatement
| forStatement
| whileStatement
| inputStatement SEMICOLON
| outputStatement SEMICOLON
| expression SEMICOLON
| commaSeparatedDeclarations SEMICOLON ;

statements 
: statement 
| statements statement ;

block 
: OPEN_CURLY statements CLOSE_CURLY ;

whileStatement 
: WHILE_K OPEN_BRACKET expression CLOSE_BRACKET block ;

forStatement 
: FOR_K OPEN_BRACKET expression SEMICOLON expression SEMICOLON expression CLOSE_BRACKET block ;

ifStatement 
: IF_K OPEN_BRACKET expression CLOSE_BRACKET block ;

elseStatement 
: ELSE_K OPEN_BRACKET expression CLOSE_BRACKET block ;

ifElseStatement 
: ifStatement 
| ifStatement elseStatement ;

functionIdentifier
: IDENTIFIER
| OP_MUL functionIdentifier ;

functionDefinition 
: DATATYPE functionIdentifier OPEN_BRACKET commaSeparatedDeclarations CLOSE_BRACKET block 
| DATATYPE functionIdentifier OPEN_BRACKET CLOSE_BRACKET block;
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
