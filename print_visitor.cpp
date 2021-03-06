#ifndef PRINT_VISITOR
#define PRINT_VISITOR 

#include "visitor.h"
#include "ast.h"
#include <assert.h>
#include <stdio.h>
#include <stack>

class PrintVisitor : public Visitor {
public:
	PrintVisitor() { tab = 0; }
	~PrintVisitor(){}
	int tab;
	void indent() {
		for( int i=0; i<tab; ++i ) printf("\t");
	}
	void visit(PostUnaryOpExpression *node) {
		node->expr->accept(this);
		printf("%s", UnaryOpName[node->op] );
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(PreUnaryOpExpression *node) {
		printf("%s", UnaryOpName[node->op] );
		node->expr->accept(this);
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(BinaryOpExpression *node) {
		node->left->accept(this);
		printf(" %s ", BinaryOpName[node->op] );
		node->right->accept(this);
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(TernaryOpExpression *node) {
		node->left->accept(this);
		printf(" ? ");
		node->middle->accept(this);
		printf(" : ");
		node->right->accept(this);
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(Identifier *node) {
		printf("%s", node->val);
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(StringLit *node) {
		printf("\"%s\"", node->val);
	}
	void visit(CharLit *node) {
		printf("\'%c\'", node->val);		
	}
	void visit(IntLit *node) {
		printf("%d", node->val );
	}
	void visit(FunctionCall *node) {
		printf("%s(", node->identifier->val);
		for( auto x : *(node->expressions) ) {
			x->accept(this);
			if( x != *(node->expressions->rbegin()) )
				printf(", ");
			else
				printf(")");
		}
		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(Declaration *node) {
		printf("%s ", DatatypeName[node->datatype] );
		printf("%s", node->identifier );
		if( node->array_definition != NULL )
		for( auto x : *(node->array_definition) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
	}
	void visit(Block *node) {
		if( node->statements->size() != 1 ) {
			indent();
			printf("{\n");
		}
		++tab;
		for( auto x : *(node->statements) ) {
			x->accept(this);
		}
		--tab;
		if( node->statements->size() != 1 ) {
			indent();
			printf("}");
		}
		printf("\n");
	}
	void visit(EmptyStatement *node) {
		indent();
		printf(";\n");
	}
	void visit(ReturnStatement *node) {
		indent();
		if( node->expression == NULL )
			printf("return;\n");
		else {
			printf("return ");
			node->expression->accept(this);
			printf("\n");
		}
	}
	void visit(BreakStatement *node) {
		indent();
		printf("break;\n");
	}
	void visit(ContinueStatement *node) {
		indent();
		printf("continue;\n");
	}
	void visit(ExpressionStatement *node) {
		indent();
		node->expression->accept(this);
		printf(";\n");
	}
	void visit(DeclarationStatement *node) {
		indent();
		for( auto x : *(node->declarations) ) {
			x->accept(this);
			if( x != *(node->declarations->rbegin()) )
				printf(", ");
			else
				printf(";\n");
		}
	}
	void visit(WhileStatement *node) {
		indent();
		printf("while( ");
		node->expression->accept(this);
		printf(" ) \n");
		node->block->accept(this);	
	}
	void visit(ForStatement *node) {
		indent();
		printf("for( ");
		if( node->init != NULL ) node->init->accept(this);
		printf("; ");
		if( node->expr != NULL ) node->expr->accept(this);
		printf("; ");
		if( node->end != NULL ) node->end->accept(this);
		printf(" ) \n");
		node->block->accept(this);
	}
	void visit(IfElseStatement *node) {
		indent();
		printf("if( ");	
		node->expression->accept(this);
		printf(" ) \n");

		node->if_block->accept(this);

		if( node->else_block != NULL ) {
			indent();
			printf("else \n");
			node->else_block->accept(this);
		}
	}
	void visit(FunctionDefinition *node) {
		indent();
		
		printf("%s ", DatatypeName[node->datatype] );
		printf("%s", node->identifier );
		printf("( ");
		if( node->parameters != NULL )
		for( auto x : *(node->parameters) ) {
			x->accept(this);
			if( x != *(node->parameters->rbegin()) )
				printf(", ");
			else
				printf(" ) \n");
		}
		else {
			printf(" ) \n");
		}
		node->block->accept(this);
	}
	void visit(Program *node) {
		for( auto x : *(node->functions) )
			x->accept(this);
	}
};

#endif