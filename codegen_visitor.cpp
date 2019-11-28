#ifndef CODEGEN_VISITOR
#define CODEGEN_VISITOR 

#include "visitor.h"
#include "ast.h"
#include <assert.h>
#include <stdio.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/LegacyPassManagers.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/AsmParser/Parser.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Pass.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>

class CodeGenVisitor : public Visitor {
public:
	CodeGenVisitor() { tab = 0; }
	~CodeGenVisitor(){}
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