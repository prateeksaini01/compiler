#ifndef AST_H
#define AST_H 

#include "visitor.h"
#include <string.h>
#include <vector>

enum class Datatype {
	INT, VOID, BOOL, FLOAT
};

enum class UnaryOp {
	INCREMENT, DECREMENT, PLUS, MINUS, ADDRESS, DEREFERENCE, LOGICAL_NOT, BITWISE_NOT
};

enum class BinaryOp {
	ADD, SUB, MUL, DIV, 
	MOD, GT, LT, GE, LE, 
	LAND, LOR, BAND, BOR, 
	ASSIGN, ADD_ASSIGN, 
	SUB_ASSIGN, MUL_ASSIGN, 
	DIV_ASSIGN, MOD_ASSIGN, 
	RIGHT_SHIFT, LEFT_SHIFT,
	GT_ASSIGN, LT_ASSIGN, 
	GE_ASSIGN, LE_ASSIGN, 
	LAND_ASSIGN, LOR_ASSIGN, 
	BAND_ASSIGN, BOR_ASSIGN,
	RIGHT_SHIFT_ASSIGN, LEFT_SHIFT_ASSIGN,
	EQUALS, NEQUALS
};

class ASTNode {
public :
	ASTNode(){}
	~ASTNode(){}
	Datatype getDatatype(char *datatype) {
		if( !strcmp(datatype, "int") ) return Datatype::INT;
		if( !strcmp(datatype, "float") ) return Datatype::FLOAT;
		if( !strcmp(datatype, "void") ) return Datatype::VOID;
		if( !strcmp(datatype, "bool") ) return Datatype::BOOL;
	}
	virtual void accept(Visitor *v) = 0;
};

class Expression : public ASTNode {
public :
	int reference, dereference;
	std::vector<Expression *> *array_accesses;
	Expression() {
		reference = dereference = 0;
		array_accesses = NULL;
	}
	~Expression(){}
	virtual void accept(Visitor *v) = 0;
};

class PostUnaryOpExpression : public Expression {
public :
	Expression *expr;
	UnaryOp op;
	PostUnaryOpExpression(Expression *expr, char *op) {
		this->expr = expr;
		if( !strcmp(op, "++") ) this->op = UnaryOp::INCREMENT;
		else if( !strcmp(op, "--") ) this->op = UnaryOp::DECREMENT;
	}
	~PostUnaryOpExpression(){}
	void accept(Visitor *v) { v->visit(this); }
};

class PreUnaryOpExpression : public Expression {
public :
	Expression *expr;
	UnaryOp op;
	PreUnaryOpExpression(Expression *expr, char *op) {
		this->expr = expr;
		if( !strcmp(op, "++") ) this->op = UnaryOp::INCREMENT;
		else if( !strcmp(op, "--") ) this->op = UnaryOp::DECREMENT;
		else if( !strcmp(op, "+") ) this->op = UnaryOp::PLUS;
		else if( !strcmp(op, "-") ) this->op = UnaryOp::MINUS;
		else if( !strcmp(op, "&") ) this->op = UnaryOp::ADDRESS;
		else if( !strcmp(op, "*") ) this->op = UnaryOp::DEREFERENCE;
		else if( !strcmp(op, "!") ) this->op = UnaryOp::LOGICAL_NOT;
		else if( !strcmp(op, "~") ) this->op = UnaryOp::BITWISE_NOT;
	}
	~PreUnaryOpExpression(){}
	void accept(Visitor *v) { v->visit(this); }
};

class BinaryOpExpression : public Expression {
public :
	Expression *left;
	BinaryOp op;
	Expression *right;
	BinaryOpExpression(Expression *left, char *op, Expression *right) {
		this->left = left;
		this->right = right;
		if( !strcmp(op, "+") ) 		this->op = BinaryOp::ADD;
		else if( !strcmp(op, "-") ) this->op = BinaryOp::SUB;
		else if( !strcmp(op, "*") ) this->op = BinaryOp::MUL;
		else if( !strcmp(op, "/") ) this->op = BinaryOp::DIV;
		else if( !strcmp(op, "%") ) this->op = BinaryOp::MOD;

		else if( !strcmp(op, ">") ) this->op = BinaryOp::GT;
		else if( !strcmp(op, "<") ) this->op = BinaryOp::LT;
		else if( !strcmp(op, ">=") ) this->op = BinaryOp::GE;
		else if( !strcmp(op, "<=") ) this->op = BinaryOp::LE;

		else if( !strcmp(op, "&") ) this->op = BinaryOp::BAND;
		else if( !strcmp(op, "|") ) this->op = BinaryOp::BOR;
		else if( !strcmp(op, "&&") ) this->op = BinaryOp::LAND;
		else if( !strcmp(op, "||") ) this->op = BinaryOp::LOR;

		else if( !strcmp(op, "<<") ) this->op = BinaryOp::LEFT_SHIFT;
		else if( !strcmp(op, ">>") ) this->op = BinaryOp::RIGHT_SHIFT;

		else if( !strcmp(op, "=") ) this->op = BinaryOp::ASSIGN;

		else if( !strcmp(op, "==") ) this->op = BinaryOp::EQUALS;
		else if( !strcmp(op, "!=") ) this->op = BinaryOp::NEQUALS;

		else if( !strcmp(op, "+=") ) this->op = BinaryOp::ADD_ASSIGN;
		else if( !strcmp(op, "-=") ) this->op = BinaryOp::SUB_ASSIGN;
		else if( !strcmp(op, "*=") ) this->op = BinaryOp::MUL_ASSIGN;
		else if( !strcmp(op, "/=") ) this->op = BinaryOp::DIV_ASSIGN;
		else if( !strcmp(op, "%=") ) this->op = BinaryOp::MOD_ASSIGN;

		else if( !strcmp(op, "&=") ) this->op = BinaryOp::BAND_ASSIGN;
		else if( !strcmp(op, "|=") ) this->op = BinaryOp::BOR_ASSIGN;
		else if( !strcmp(op, "&&=") ) this->op = BinaryOp::LAND_ASSIGN;
		else if( !strcmp(op, "||=") ) this->op = BinaryOp::LOR_ASSIGN;

		else if( !strcmp(op, "<<=") ) this->op = BinaryOp::LEFT_SHIFT_ASSIGN;
		else if( !strcmp(op, ">>=") ) this->op = BinaryOp::RIGHT_SHIFT_ASSIGN;

	}
	~BinaryOpExpression(){}
	void accept(Visitor *v) { v->visit(this); }
};

class TernaryOpExpression : public Expression {
public :
	Expression *left, *middle, *right;
	TernaryOpExpression(Expression *left, Expression *middle, Expression *right) {
		this->left = left;
		this->middle = middle;
		this->right = right;
	}
	~TernaryOpExpression(){}
	void accept(Visitor *v) { v->visit(this); }
};


class StringLit : public Expression {
public :
	char *val;
	StringLit( char *val ) {
		this->val = val;
	}
	~StringLit(){}
	void accept(Visitor *v) { v->visit(this); }
};

class CharLit : public Expression {
public :
	char val;
	CharLit( char val ) {
		this->val = val;
	}
	~CharLit(){}
	void accept(Visitor *v) { v->visit(this); }
};

class IntLit : public Expression {
public :
	int val;
	IntLit( int val ) {
		this->val = val;
	}
	~IntLit(){}
	void accept(Visitor *v) { v->visit(this); }
};

class FunctionCall : public Expression {
public :
	StringLit *identifier;
	std::vector<Expression *> *expressions;
	FunctionCall( StringLit *identifier, std::vector<Expression *> *expressions ) {
		this->identifier = identifier;
		this->expressions = expressions;
	}
	~FunctionCall(){}
	void accept(Visitor *v) { v->visit(this); }
};

class Declaration : public ASTNode {
public :
	Datatype datatype;
	char *identifier;
	std::vector<Expression *> *array_definition;
	Declaration( char *datatype, StringLit *identifier, std::vector<Expression *> *array_definition ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier->val;
		this->array_definition = array_definition;
	}
	~Declaration(){}
	void accept(Visitor *v) { v->visit(this); }
};

class Statement : public ASTNode {
public:
	Statement(){};
	~Statement(){};
	virtual void accept(Visitor *v) = 0;
};

class ReturnStatement : public Statement {
public:
	Expression *expression;
	ReturnStatement(Expression *expression) {
		this->expression = expression;
	}
	~ReturnStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class BreakStatement : public Statement {
public:
	BreakStatement(){};
	~BreakStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class ContinueStatement : public Statement {
public:
	ContinueStatement(){};
	~ContinueStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class ExpressionStatement : public Statement {
public:
	Expression *expression;
	ExpressionStatement(Expression *expression) {
		this->expression = expression;
	};
	~ExpressionStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class DeclarationStatement : public Statement {
public:
	std::vector<Declaration *> *declaration;
	DeclarationStatement(std::vector<Declaration *> *declaration) {
		this->declaration = declaration;
	};
	~DeclarationStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class WhileStatement : public Statement {
public:
	Expression *expression;
	std::vector<Statement *> *statements;
	WhileStatement(Expression *expression, std::vector<Statement *> *statements ) {
		this->expression = expression;
		this->statements = statements;
	};
	~WhileStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class ForStatement : public Statement {
public:
	Expression *init;
	Expression *expr;
	Expression *end;
	std::vector<Statement *> *statements;
	ForStatement(Expression *init, Expression *expr, Expression *end, std::vector<Statement *> *statements ) {
		this->init = init;
		this->expr = expr;
		this->end = end;
		this->statements = statements;
	};
	~ForStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class IfElseStatement : public Statement {
public:
	Expression *expression;
	std::vector<Statement *> *if_block, *else_block;
	IfElseStatement(Expression *expression, std::vector<Statement *> *if_block, std::vector<Statement *> *else_block ) {
		this->expression = expression;
		this->if_block = if_block;
		this->else_block = else_block;
	};
	~IfElseStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class FunctionDefinition : public ASTNode {
public :
	Datatype datatype;
	char *identifier;
	std::vector<Declaration *> *parameters;
	std::vector<Statement *> *statements;
	FunctionDefinition( char *datatype, StringLit *identifier, std::vector<Declaration *> *parameters, std::vector<Statement *> *statements ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier->val;
		this->parameters = parameters;
		this->statements = statements;
	}
	~FunctionDefinition(){}
	void accept(Visitor *v) { v->visit(this); }
};

class Program : public ASTNode {
public :
	std::vector<FunctionDefinition *> *functions;
	Program( std::vector<FunctionDefinition *> *functions ) {
		this->functions = functions;
	}
	~Program(){}
	void accept(Visitor *v) { v->visit(this); }
};

#endif