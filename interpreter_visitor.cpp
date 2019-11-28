#ifndef INTERPRETER_VISITOR
#define INTERPRETER_VISITOR 

#include "visitor.h"
#include "ast.h"
#include <assert.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

class InterpreterVisitor : public Visitor {
public:

	std::vector<std::map<std::string, std::pair<std::vector<int> *, int *> > *> scope;
	Program *start;
	int tab;
	void indent() {
		for( int i=0; i<tab; ++i ) printf("\t");
	}

	int *lookup(Identifier *node) {
		auto s = std::string(node->val);
		for( auto it = scope.rbegin(); it != scope.rend(); ++it ) {
			if( (*it)->find(s) == (*it)->end() ) {
				// printf("%s not in current scope\n", node->val);
				continue;
			}
			// printf("%s IS in current scope\n", node->val);
			auto temp = (*it)->find(s)->second;
			if( !( (node->array_accesses == NULL and temp.first->size() == 0 ) or node->array_accesses->size() == temp.first->size() ) ) {
				printf("Error: Invalid array access term\n");
				return NULL;
			}
			int offset = 0;
			if( node->array_accesses != NULL )
			{
				auto it_def = temp.first->begin();
				auto it_acc = node->array_accesses->begin();
				while( it_acc != node->array_accesses->end() ) {
					(*it_acc)->accept(this);
					offset = offset*( *it_def ) + (*it_acc)->value;
					++it_def;
					++it_acc;
				}
			}
			return temp.second + offset;
		}
		printf("Error: cannot find variable '");
		std::cout << s;
		printf("'\n");
		return NULL;
	}


	InterpreterVisitor(Program *node) { tab = 0; start = node; scope = std::vector<std::map<std::string, std::pair<std::vector<int> *, int *> > *>(); }
	~InterpreterVisitor(){}
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
	//
	void visit(BinaryOpExpression *node) {
		// printf("In binary op expression\n");
		node->left->accept(this);
		// printf("Evaluated left side\n");
		node->right->accept(this);
		// printf("Evaluated right side also\n");
		switch( node->op )
		{
			case ADD: (node->value) = (node->left->value) + (node->right->value); break;
			case SUB: (node->value) = (node->left->value) - (node->right->value); break;
			case MUL: (node->value) = (node->left->value) * (node->right->value); break;
			case DIV: (node->value) = (node->left->value) / (node->right->value); break;
			case MOD: (node->value) = (node->left->value) % (node->right->value); break;
			case GT: (node->value) = (node->left->value) > (node->right->value); break;
			case LT: (node->value) = (node->left->value) < (node->right->value); break;
			case GE: (node->value) = (node->left->value) >= (node->right->value); break;
			case LE: (node->value) = (node->left->value) <= (node->right->value); break;
			case LAND: (node->value) = (node->left->value) && (node->right->value); break;
			case LOR: (node->value) = (node->left->value) || (node->right->value); break;
			case BAND: (node->value) = (node->left->value) & (node->right->value); break;
			case BOR: (node->value) = (node->left->value) | (node->right->value); break;
			case RIGHT_SHIFT: (node->value) = (node->left->value) << (node->right->value); break;
			case LEFT_SHIFT: (node->value) = (node->left->value) >> (node->right->value); break;
			case ASSIGN: (node->value) = (*(node->left->pointer)) = (node->right->value); break;
			case ADD_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) + (node->right->value); break;
			case SUB_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) - (node->right->value); break;
			case MUL_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) * (node->right->value); break;
			case DIV_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) / (node->right->value); break;
			case MOD_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) % (node->right->value); break;
			case GT_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) > (node->right->value); break;
			case LT_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) < (node->right->value); break;
			case GE_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) >= (node->right->value); break;
			case LE_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) <= (node->right->value); break;
			case LAND_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) && (node->right->value); break;
			case LOR_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) || (node->right->value); break;
			case BAND_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) & (node->right->value); break;
			case BOR_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) | (node->right->value); break;
			case RIGHT_SHIFT_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) << (node->right->value); break;
			case LEFT_SHIFT_ASSIGN: (node->value) = (*(node->left->pointer)) = (node->left->value) >> (node->right->value); break;
			case EQUALS: node->value = node->left->value == node->right->value; break;
			case NEQUALS: node->value = node->left->value != node->right->value; break;
			default: printf("you done fucked up now\n"); break;
		}
		printf("%d %s %d = %d\n", node->left->value, BinaryOpName[node->op], node->right->value, node->value );
/*		if( node->array_accesses != NULL )
		for( auto x : *(node->array_accesses) ) {
			printf("[");
			x->accept(this);
			printf("]");
		}
*/	}
	//
	void visit(TernaryOpExpression *node) {
		node->left->accept(this);
		if( node->left->value )
			node->middle->accept(this);
		else
			node->right->accept(this);
	}
	//
	void visit(Identifier *node) {
		// printf("In identifier visitor\n");
		node->pointer = lookup(node);
		node->value = *(node->pointer);
		// printf("Exiting identifier visitor\n");
	}
	// ?
	void visit(StringLit *node) {
		// printf("\"%s\"", node->val);
		return;
	}
	//
	void visit(CharLit *node) {
		node->value = node->val;
	}
	//
	void visit(IntLit *node) {
		node->value = node->val;
	}
	void visit(FunctionCall *node) {
		if( strcmp(node->identifier->val, "output") == 0  ) {
			if( node->expressions->size() != 1 ) {
				printf("Error: number of parameters should be 1\n");
				return;
			}
			(*node->expressions)[0]->accept(this);
			printf("%d\n", (*node->expressions)[0]->value);
			return;
		}
		if( strcmp(node->identifier->val, "input") == 0  ) {
			if( node->expressions->size() != 1 ) {
				printf("Error: number of parameters should be 1\n");
				return;
			}
			(*node->expressions)[0]->accept(this);
			scanf("%d", (*node->expressions)[0]->pointer);
			return;
		}
		// printf("In FunctionCall\n");
		for( auto x : *(start->functions) ) {
			if( strcmp(x->identifier, node->identifier->val) == 0 ) {
				if( !( (x->parameters == NULL and node->expressions == NULL ) or node->expressions->size() == x->parameters->size() ) ) {
					printf("Error: No matching function\n");
					break;
				}
				scope.push_back(new std::map<std::string, std::pair<std::vector<int> *, int *> >() );
				printf("calling %s(", node->identifier->val);
				if( x->parameters != NULL )
				{
					auto it1 = x->parameters->begin();
					auto it2 = node->expressions->begin();
					while ( it1 != x->parameters->end() ) {
						(*it2)->accept(this);
						printf("%d, ", (*it2)->value );
						int *temp = (int *)malloc( sizeof(int) );
						*temp = (*it2)->value;
						(*(*scope.rbegin()))[std::string((*it1)->identifier)] = {new std::vector<int>(), temp};
						++it1;
						++it2;
					}
				}
				printf(")\n");
				x->accept(this);
				node->value = x->returnValue;
				printf("got returnValue %d\n", x->returnValue);
				scope.pop_back();
				break;
			}
		}
		// printf("Exiting FunctionCall\n");
	}
	//
	void visit(Declaration *node) {
		if( (*scope.rbegin())->find(std::string(node->identifier)) != (*scope.rbegin())->end() ) {
			printf("Error: redeclaration of variable '%s'\n", node->identifier );
			return;
		}
		std::vector<int> *temp = new std::vector<int>();
		int sz = 1;
		if( node->array_definition != NULL ) {
			for( auto x : *(node->array_definition) ) {
				x->accept(this);
				temp->push_back(x->value);
				sz *= x->value;
			}
		}
		(*(*scope.rbegin()))[std::string(node->identifier)] = {temp, (int *) malloc(sizeof(int) * sz) };
	}
	//
	void visit(Block *node) {
		// printf("In a block\n");
		for( auto x : *(node->statements) ) {
			// printf("\nExecuting a statement...\n");
			x->accept(this);
			// printf("Executed\n\n");
			node->dbcr = x->dbcr;
			x->dbcr = 0;
			if( node->dbcr != 0 ) {
				if( node->dbcr == 3 )
					node->returnValue = x->returnValue;
				return;
			}
		}
	}
	//
	void visit(EmptyStatement *node) {
		return;
	}
	void visit(ReturnStatement *node) {
		if( node->expression != NULL ) {
			node->expression->accept(this);
			node->returnValue = node->expression->value;
			// printf("%d\n", node->expression->value);
		}
		node->dbcr = 3;
	}
	//
	void visit(BreakStatement *node) {
		node->dbcr = 1;
	}
	//
	void visit(ContinueStatement *node) {
		node->dbcr = 2;
	}
	//
	void visit(ExpressionStatement *node) {
		// printf("In an expression statement\n");
		node->expression->accept(this);
		// printf("Exiting an expression statement\n");
	}
	//
	void visit(DeclarationStatement *node) {
		printf("In a declaration statement\n");
		for( auto x : *(node->declarations) )
			x->accept(this);
		printf("Exiting a declaration statement\n");
	}
	//
	void visit(WhileStatement *node) {
		scope.push_back(new std::map<std::string, std::pair<std::vector<int> *, int *> >() );
		while(1) {
			node->expression->accept(this);
			if( !((node->expression->value)) )
				break;
			node->block->accept(this);

			node->dbcr = node->block->dbcr;
			node->block->dbcr = 0;
			if( node->dbcr != 0 ) {
				if( node->dbcr == 3 ) {
					node->returnValue = node->block->returnValue;
					break;
				}
				if( node->dbcr == 2 ) 
					break;
			}
		}
		scope.pop_back();
	}
	//
	void visit(ForStatement *node) {
		scope.push_back(new std::map<std::string, std::pair<std::vector<int> *, int *> >() );
		if( node->init != NULL ) node->init->accept(this);
		while(1) {
			if( node->expr != NULL ) {
				node->expr->accept(this);
				if( !(node->expr->value) )
					break;
			}
			node->block->accept(this);
			
			node->dbcr = node->block->dbcr;
			node->block->dbcr = 0;
			if( node->dbcr != 0 ) {
				if( node->dbcr == 3 ) {
					node->returnValue = node->block->returnValue;
					break;
				}
				if( node->dbcr == 2 ) 
					break;
			}

			if( node->end != NULL ) node->end->accept(this);
		}
		scope.pop_back();
	}
	//
	void visit(IfElseStatement *node) {
		node->expression->accept(this);
		// printf("in IfElseStatement\n");
		// printf("expression %d\n", node->expression->value);
		if( node->expression->value ) {
			node->if_block->accept(this);

			node->dbcr = node->if_block->dbcr;
			node->if_block->dbcr = 0;
			if( node->dbcr != 0 )
				if( node->dbcr == 3 ) {
					node->returnValue = node->if_block->returnValue;
				return;
			}

		} else if( node->else_block != NULL ) {
			node->else_block->accept(this);
			
			node->dbcr = node->else_block->dbcr;
			node->else_block->dbcr = 0;
			if( node->dbcr != 0 ) {
				if( node->dbcr == 3 )
					node->returnValue = node->else_block->returnValue;
				return;
			}
		}
	}
	//
	void visit(FunctionDefinition *node) {
		// printf("In function %s\n", node->identifier);
		node->block->accept(this);
		if( node->block->dbcr == 1 ) {
			printf("Error: Unexpected break outside loop\n");
		}
		if( node->block->dbcr == 2 ) { 
			printf("Error: Unexpected continue outside loop\n");
		}
		node->block->dbcr = 0;
		node->returnValue = node->block->returnValue;
	}
	//
	void visit(Program *node) {
		scope.push_back(new std::map<std::string, std::pair<std::vector<int> *, int *> >() );
		for( auto x : *(node->functions) ) {
			if( strcmp(x->identifier, "main") == 0 ) {
				x->accept(this);
				scope.pop_back();
				return;
			}
		}
		printf("Error: undefined reference to 'main'\n");
	}
};

#endif