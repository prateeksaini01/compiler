#include <stdio.h>
#include "ast.h"
#include "visitor.h"
#include "print_visitor.cpp"
#include "interpreter_visitor.cpp"

Program *program_pointer;
int yyparse();

int main() {
	yyparse();
	printf("Parsing over\n");

	// PrintVisitor *visitor = new PrintVisitor();
	// InterpreterVisitor *visitor = new InterpreterVisitor(program_pointer);
	CodeGenVisitor *visitor = new CodeGenVisitor();
	visitor->visit(program_pointer);
}