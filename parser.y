%define parse.error verbose
%{
	#include <stdio.h>
	#include "ast.h"

	// stuff from flex that bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;

	extern Program *program_pointer;

	void yyerror(char const *s);
%}

%union {
	int   ival;
	float fval;
	char  *sval;
	char  cval;

	Program *program;
	Expression *expression;
	std::vector<Expression *> *expression_vector;
	FunctionCall *functionCall;
	Declaration *declaration;
	std::vector<Declaration *> *declaration_vector;
	Statement *statement;
	std::vector<Statement *> *statement_vector;
	WhileStatement *whileStatement;
	ForStatement *forStatement;
	IfElseStatement *ifElseStatement;
	FunctionDefinition *functionDefinition;

	StringLit *stringlit;
	Identifier *identifier;
}

%token <sval> STRING
%token <cval> CHAR
%token <ival> CONSTANT
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
%token <cval> SEMICOLON
%token <cval> COMMA
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
%token <cval> QUESTION
%token <cval> COLON
%token <cval> OPEN_BRACKET
%token <cval> CLOSE_BRACKET
%token <cval> OPEN_SQUARE
%token <cval> CLOSE_SQUARE
%token <cval> OPEN_CURLY
%token <cval> CLOSE_CURLY
%token <sval> IDENTIFIER

%type <program> program
%type <expression> literal
%type <expression> expression
%type <expression_vector> arrayAccessList
%type <expression> term 
%type <expression> arrayAccessTerm
%type <expression> prec0
%type <expression> prec1
%type <expression> prec2
%type <expression> prec3
%type <expression> prec4
%type <expression> prec5
%type <expression> prec6
%type <expression> prec7
%type <expression> prec8
%type <expression> prec9
%type <expression> prec10
%type <expression> prec11
%type <expression> prec12
%type <expression> prec13
%type <expression_vector> commaSeparatedExpressions 
%type <functionCall> functionCall 
%type <declaration> declaration
%type <declaration_vector> commaSeparatedDeclarations 
%type <statement> statement 
%type <statement_vector> statements 
%type <statement_vector> block 
%type <whileStatement> whileStatement 
%type <forStatement> forStatement 
%type <ifElseStatement> ifElseStatement 
%type <identifier> functionIdentifier
%type <functionDefinition> functionDefinition 
%%

program 
: functionDefinition { std::vector<FunctionDefinition *> *it = new std::vector<FunctionDefinition *>(); it->push_back($1); $$ = new Program(it); program_pointer = $$; }
| program functionDefinition { $1->functions->push_back($2); $$ = $1; program_pointer = $$; } ;

literal 
: STRING { $$ = new StringLit($1); }
| CHAR { $$ = new CharLit($1); }
| CONSTANT { $$ = new IntLit($1);} ;

arrayAccessList
: OPEN_SQUARE expression CLOSE_SQUARE { $$ = new std::vector<Expression *>(); $$->push_back($2); }
| arrayAccessList OPEN_SQUARE expression CLOSE_SQUARE { $1->push_back($3); $$ = $1; } ;

term 
: IDENTIFIER { $$ = new Identifier($1); }
| literal { $$ = $1; }
| functionCall { $$ = $1; }
| OPEN_BRACKET expression CLOSE_BRACKET { $$ = $2; } 
| IDENTIFIER arrayAccessList { auto *it = new Identifier($1); it->array_accesses = $2; $$ = it; }
| literal arrayAccessList { $1->array_accesses = $2; $$ = $1; }
| functionCall arrayAccessList { $1->array_accesses = $2; $$ = $1; }
| OPEN_BRACKET expression CLOSE_BRACKET arrayAccessList { $2->array_accesses = $4; $$ = $2; } ;

/*arrayAccessTerm
: term arrayAccessList { $1->array_accesses = $2; $$ = $1; }
| term { $$ = $1; } ;
*/

// ++ -- ~ !
prec0
: term UN_OP { $$ = new PostUnaryOpExpression($1, $2); }
| term { $$ = $1; };

// ++ -- ~ ! + - * &
prec1
: UN_OP prec0 { $$ = new PreUnaryOpExpression($2, $1); }
| BIN_OP_ADD prec0 { $$ = new PreUnaryOpExpression($2, $1); }
| BIN_OP_BAND prec0 { $$ = new PreUnaryOpExpression($2, $1); }
| OP_MUL prec1 { $2->dereference += 1;  $$ = $2; }
| prec0 { $$ = $1; } ;

// * / %
prec2 
: prec2 BIN_OP_MUL prec1 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec2 OP_MUL prec1 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec1 { $$ = $1; } ;

// + -
prec3 
: prec3 BIN_OP_ADD prec2 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec2 { $$ = $1; } ;

// << >>
prec4 
: prec4 BIN_OP_SHIFT prec3 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec3 { $$ = $1; } ;

// < > <= >=
prec5
: prec5 BIN_OP_REL prec4 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec4 { $$ = $1; } ;

// == !=
prec6
: prec6 BIN_OP_EQ prec5 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec5 { $$ = $1; } ;

// &
prec7
: prec7 BIN_OP_BAND prec6 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec6 { $$ = $1; } ;

// ^
prec8
: prec8 BIN_OP_BXOR prec7 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec7 { $$ = $1; } ;

// |
prec9
: prec9 BIN_OP_BOR prec8 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec8 { $$ = $1; } ;

// &&
prec10
: prec10 BIN_OP_LAND prec9 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec9 { $$ = $1; } ;

// ||
prec11
: prec11 BIN_OP_LOR prec10 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec10 { $$ = $1; } ;

// ternary
prec12
: prec11 QUESTION prec11 COLON prec11 { $$ = new TernaryOpExpression($1, $3, $5); } 
| prec11 { $$ = $1; } ;

// = and other compunded assignments
prec13
: prec12 BIN_OP_ASSIGN prec13 { $$ = new BinaryOpExpression($1, $2, $3); }
| prec12 { $$ = $1; } ;

expression 
: prec13 { $$ = $1; };

commaSeparatedExpressions 
: expression { $$ = new std::vector<Expression *>(); $$->push_back($1); }
| commaSeparatedExpressions COMMA expression { $1->push_back($3); $$ = $1; } ;

functionCall 
: IDENTIFIER OPEN_BRACKET CLOSE_BRACKET { $$ = new FunctionCall(new Identifier($1), NULL ); }
| IDENTIFIER OPEN_BRACKET commaSeparatedExpressions CLOSE_BRACKET { $$ = new FunctionCall(new Identifier($1), $3); }
| INPUT_K OPEN_BRACKET arrayAccessTerm CLOSE_BRACKET { std::vector<Expression *> *it = new std::vector<Expression *>(); it->push_back($3); $$ = new FunctionCall(new Identifier($1), it); }
| OUTPUT_K OPEN_BRACKET expression CLOSE_BRACKET { std::vector<Expression *> *it = new std::vector<Expression *>(); it->push_back($3); $$ = new FunctionCall(new Identifier($1), it); } ;


declaration
: DATATYPE functionIdentifier { $$ = new Declaration($1, $2, NULL ); }
| DATATYPE functionIdentifier arrayAccessList { $$ = new Declaration($1, $2, $3); } ;

commaSeparatedDeclarations 
: declaration { std::vector<Declaration *> *it = new std::vector<Declaration *>(); it->push_back($1); $$ = it; }
| commaSeparatedDeclarations COMMA declaration { $1->push_back($3); $$ = $1; };

statement 
: SEMICOLON { /*$$ = $1;*/ $$ = new EmptyStatement(); }
| RETURN_K expression SEMICOLON { $$ = new ReturnStatement($2); }
| RETURN_K SEMICOLON { $$ = new ReturnStatement(NULL); }
| BREAK_K SEMICOLON { $$ = new BreakStatement(); }
| CONTINUE_K SEMICOLON { $$ = new ContinueStatement(); }
| ifElseStatement { $$ = $1; }
| forStatement { $$ = $1; }
| whileStatement { $$ = $1; }
| expression SEMICOLON { $$ = new ExpressionStatement($1); }
| commaSeparatedDeclarations SEMICOLON { $$ = new DeclarationStatement($1); } ;

statements 
: statement { std::vector<Statement *> *it = new std::vector<Statement *>(); it->push_back($1); $$ = it; }
| statements statement { $1->push_back($2); $$ = $1; } ;

block 
: OPEN_CURLY statements CLOSE_CURLY { $$ = $2; };

whileStatement 
: WHILE_K OPEN_BRACKET expression CLOSE_BRACKET block { $$ = new WhileStatement($3, $5); };

forStatement 
: FOR_K OPEN_BRACKET expression SEMICOLON expression SEMICOLON expression CLOSE_BRACKET block { $$ = new ForStatement($3, $5, $7, $9); }
| FOR_K OPEN_BRACKET SEMICOLON expression SEMICOLON expression CLOSE_BRACKET block { $$ = new ForStatement(NULL, $4, $6, $8); }
| FOR_K OPEN_BRACKET expression SEMICOLON SEMICOLON expression CLOSE_BRACKET block { $$ = new ForStatement($3, NULL, $6, $8); }
| FOR_K OPEN_BRACKET expression SEMICOLON expression SEMICOLON CLOSE_BRACKET block { $$ = new ForStatement($3, $5, NULL, $8); }
| FOR_K OPEN_BRACKET expression SEMICOLON SEMICOLON CLOSE_BRACKET block { $$ = new ForStatement($3, NULL, NULL, $7); }
| FOR_K OPEN_BRACKET SEMICOLON expression SEMICOLON CLOSE_BRACKET block { $$ = new ForStatement(NULL, $4, NULL, $7); }
| FOR_K OPEN_BRACKET SEMICOLON SEMICOLON expression CLOSE_BRACKET block { $$ = new ForStatement(NULL, NULL, $5, $7); }
| FOR_K OPEN_BRACKET SEMICOLON SEMICOLON CLOSE_BRACKET block { $$ = new ForStatement(NULL, NULL, NULL, $6); } ;

ifElseStatement 
: IF_K OPEN_BRACKET expression CLOSE_BRACKET block { $$ = new IfElseStatement($3, $5, NULL); }
| IF_K OPEN_BRACKET expression CLOSE_BRACKET block ELSE_K block { $$ = new IfElseStatement($3, $5, $7); } ;

functionIdentifier
: IDENTIFIER { $$ = new Identifier($1); }
| OP_MUL functionIdentifier { $2->reference += 1; $$ = $2; } ;

functionDefinition 
: DATATYPE functionIdentifier OPEN_BRACKET commaSeparatedDeclarations CLOSE_BRACKET block { $$ = new FunctionDefinition($1, $2, $4, $6); }
| DATATYPE functionIdentifier OPEN_BRACKET CLOSE_BRACKET block { $$ = new FunctionDefinition($1, $2, NULL, $5); } ;
%%

void yyerror(char const *s)
{
	fprintf(stderr, "error: %s\n", s);
}
