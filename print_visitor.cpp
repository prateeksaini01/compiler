#ifndef PRINT_VISITOR
#define PRINT_VISITOR 

#include "visitor.h"
#include "ast.h"
#include <stdio.h>

class PrintVisitor : public Visitor {
public:
	PrintVisitor(){}
	~PrintVisitor(){}
	void visit(PostUnaryOpExpression *) {

	}
	void visit(PreUnaryOpExpression *) {

	}
	void visit(BinaryOpExpression *) {

	}
	void visit(TernaryOpExpression *) {

	}
	void visit(StringLit *) {

	}
	void visit(CharLit *) {

	}
	void visit(IntLit *) {

	}
	void visit(FunctionCall *) {

	}
	void visit(Declaration *) {

	}
	void visit(ReturnStatement *) {

	}
	void visit(BreakStatement *) {

	}
	void visit(ContinueStatement *) {

	}
	void visit(ExpressionStatement *) {

	}
	void visit(DeclarationStatement *) {

	}
	void visit(WhileStatement *) {

	}
	void visit(ForStatement *) {

	}
	void visit(IfElseStatement *) {

	}
	void visit(FunctionDefinition *) {

	}
	void visit(Program *) {
		printf("NALLA\n");
	}
};

#endif