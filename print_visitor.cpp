#ifndef PRINT_VISITOR
#define PRINT_VISITOR 

#include "visitor.h"
#include "ast.h"
#include <assert.h>
#include <stdio.h>

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

		indent();
		printf("{\n");
		++tab;
		if( node->statements != NULL )
		for( auto x : *(node->statements) ) {
			x->accept(this);
		}
		--tab;
		indent();
		printf("}\n");
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

		indent();
		printf("{\n");
		++tab;
		if( node->statements != NULL )
		for( auto x : *(node->statements) ) {
			x->accept(this);
		}
		--tab;
		indent();
		printf("}\n");

	}
	void visit(IfElseStatement *node) {
		indent();
		printf("if( ");	
		node->expression->accept(this);
		printf(" ) \n");

		indent();
		printf("{\n");
		++tab;
		if( node->if_block != NULL )
		for( auto x : *(node->if_block) ) {
			x->accept(this);
		}
		--tab;
		indent();
		printf("}\n");

		if( node->else_block == NULL ) return;
		indent();
		printf("else \n");	

		indent();
		printf("{\n");
		++tab;
		for( auto x : *(node->else_block) ) {
			x->accept(this);
		}
		--tab;
		indent();
		printf("}\n");
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

		printf("{ \n");
		++tab;
		// assert( node->statements != NULL );
		// printf("%ld\n", node->statements->size() );
		if( node->statements != NULL )
		for( auto x : *(node->statements) ) {
			x->accept(this);
		}
		--tab;
		printf("}\n");
	}
	void visit(Program *node) {
		for( auto x : *(node->functions) )
			x->accept(this);
	}
};

#endif