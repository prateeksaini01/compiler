#ifndef AST_H
#define AST_H 

#include "visitor.h"
#include <string.h>
#include <vector>

enum Datatype {
	INT=0, VOID, BOOL, FLOAT
};
const char DatatypeName[][6] = {
	"int", "void", "bool", "float"
};

enum UnaryOp {
	INCREMENT=0, DECREMENT, PLUS, MINUS, ADDRESS, DEREFERENCE, LOGICAL_NOT, BITWISE_NOT
};
const char UnaryOpName[][3] = {
	"++", "--", "+", "-", "&", "*", "!", "~"
};

enum BinaryOp {
	ADD=0, SUB, MUL, DIV, 
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
const char BinaryOpName[][4] = {
	"+", "-", "*", "/", "%", ">", "<", ">=", "<=", "&&", "||", "&", 
	"|", "=", "+=", "-=", "*=", "/=", "%=", ">>", "<<", ">=", "<=", 
	">==", "<==", "&&=", "||=", "&=", "|=", ">>=", "<<=", "==", "!="
};


class ASTNode {
public :
	ASTNode(){}
	~ASTNode(){}
	Datatype getDatatype(char *datatype) {
		if( !strcmp(datatype, "int") ) return Datatype::INT;
		if( !strcmp(datatype, "float") ) return Datatype::FLOAT;
		if( !strcmp(datatype, "void") ) return Datatype::VOID;
		return Datatype::BOOL;
	}
	virtual void accept(Visitor *v) = 0;
};

class Expression : public ASTNode {
public :
	bool islvalue;
	int value;
	int *pointer;
	int reference, dereference;
	std::vector<Expression *> *array_accesses;
	Expression() {
		this->pointer = NULL;
		this->islvalue = false;
		this->reference = dereference = 0;
		this->array_accesses = NULL;
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

class Identifier : public Expression {
public :
	char *val;
	Identifier( char *val ) {
		this->islvalue = true;
		this->val = val;
	}
	~Identifier(){}
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
	Identifier *identifier;
	std::vector<Expression *> *expressions;
	FunctionCall( Identifier *identifier, std::vector<Expression *> *expressions ) {
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
	Declaration( char *datatype, Identifier *identifier, std::vector<Expression *> *array_definition ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier->val;
		this->array_definition = array_definition;
	}
	~Declaration(){}
	void accept(Visitor *v) { v->visit(this); }
};

class Statement : public ASTNode {
public:
	int dbcr;
	int returnValue;
	Statement(){
		this->dbcr = 0;
		this->returnValue = -1;
	};
	~Statement(){};
	virtual void accept(Visitor *v) = 0;
};

class Block : public ASTNode {
public:
	int dbcr;
	int returnValue;
	std::vector<Statement *> *statements;
	Block( std::vector<Statement *> *statements ) { 
		this->statements = statements;
		this->dbcr = 0;
		this->returnValue = -1;
	};
	~Block(){};
	void accept(Visitor *v) { v->visit(this); }
};

class EmptyStatement : public Statement {
public:
	EmptyStatement(){};
	~EmptyStatement(){};
	void accept(Visitor *v) { v->visit(this); }
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
	std::vector<Declaration *> *declarations;
	DeclarationStatement(std::vector<Declaration *> *declarations) {
		this->declarations = declarations;
	};
	~DeclarationStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class WhileStatement : public Statement {
public:
	Expression *expression;
	Block *block;
	WhileStatement(Expression *expression, Block *block ) {
		this->expression = expression;
		this->block = block;
	};
	~WhileStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class ForStatement : public Statement {
public:
	Expression *init;
	Expression *expr;
	Expression *end;
	Block *block;
	ForStatement(Expression *init, Expression *expr, Expression *end, Block *block ) {
		this->init = init;
		this->expr = expr;
		this->end = end;
		this->block = block;
	};
	~ForStatement(){};
	void accept(Visitor *v) { v->visit(this); }
};

class IfElseStatement : public Statement {
public:
	Expression *expression;
	Block *if_block, *else_block;
	IfElseStatement(Expression *expression, Block *if_block, Block *else_block ) {
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
	Block *block;
	int returnValue;
	FunctionDefinition( char *datatype, Identifier *identifier, std::vector<Declaration *> *parameters, Block *block ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier->val;
		this->parameters = parameters;
		this->block = block;
		this->returnValue = 0;
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