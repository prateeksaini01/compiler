#include "ast.h"
#include <vector>
using namespace std;

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
};

class Expression : public ASTNode {
public :
	int reference, dereference;
	vector<Expression *> *array_accesses;
	Expression() {
		reference = dereference = 0;
		array_accesses = NULL;
	}
	~Expression(){}
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
};


class StringLit : public Expression {
public :
	char *val;
	StringLit( char *val ) {
		this->val = val;
	}
	~StringLit(){}
};

class CharLit : public Expression {
public :
	char val;
	CharLit( char val ) {
		this->val = val;
	}
	~CharLit(){}
};

class IntLit : public Expression {
public :
	int val;
	IntLit( int val ) {
		this->val = val;
	}
	~IntLit(){}
};

class FunctionCall : public Expression {
public :
	char *identifier;
	vector<Expression *> *expressions;
	FunctionCall( char *identifier, vector<Expression *> *expressions ) {
		this->identifier = identifier;
		this->expressions = expressions;
	}
	~FunctionCall(){}
};

class Declaration : public ASTNode {
public :
	Datatype datatype;
	char *identifier;
	vector<Expression *> *array_definition;
	Declaration( char *datatype, char *identifier, vector<Expression *> *array_definition ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier;
		this->array_definition = array_definition;
	}
	~Declaration(){}
};

class Statement : ASTNode {
public:
	Statement(){};
	~Statement(){};
};

class ReturnStatement : Statement {
public:
	Expression *expression;
	ReturnStatement(Expression *expression) {
		this->expression = expression;
	}
	~ReturnStatement(){};
};

class BreakStatement : Statement {
public:
	BreakStatement(){};
	~BreakStatement(){};
};

class ContinueStatement : Statement {
public:
	ContinueStatement(){};
	~ContinueStatement(){};
};

class ExpressionStatement : Statement {
public:
	Expression *expression;
	ExpressionStatement(Expression *expression) {
		this->expression = expression;
	};
	~ExpressionStatement(){};
};

class DeclarationStatement : Statement {
public:
	Declaration *declaration;
	DeclarationStatement(Declaration *declaration) {
		this->declaration = declaration;
	};
	~DeclarationStatement(){};
};

class WhileStatement : Statement {
public:
	Expression *expression;
	vector<Statement *> *statements;
	WhileStatement(Expression *expression, vector<Statement *> *statements ) {
		this->expression = expression;
		this->statements = statements;
	};
	~WhileStatement(){};
};

class ForStatement : Statement {
public:
	Expression *init;
	Expression *expr;
	Expression *end;
	vector<Statement *> *statements;
	ForStatement(Expression *init, Expression *expr, Expression *end, vector<Statement *> *statements ) {
		this->init = init;
		this->expr = expr;
		this->end = end;
		this->statements = statements;
	};
	~ForStatement(){};
};

class IfElseStatement : Statement {
public:
	Expression *expression;
	vector<Statement *> *if_block, *else_block;
	IfElseStatement(Expression *expression, vector<Statement *> *if_block, vector<Statement *> *else_block ) {
		this->expression = expression;
		this->if_block = if_block;
		this->else_block = else_block;
	};
	~IfElseStatement(){};
};

class FunctionDefinition : ASTNode {
public :
	Datatype datatype;
	char *identifier;
	vector<Declaration *> *parameters;
	vector<Statement *> *statements;
	FunctionDefinition( char *datatype, char *identifier, vector<Declaration *> *parameters, vector<Statement *> *statements ) {
		this->datatype = getDatatype(datatype);
		this->identifier = identifier;
		this->parameters = parameters;
		this->statements = statements;
	}
	~FunctionDefinition(){}
};

class Program : ASTNode {
public :
	vector<FunctionDefinition *> *functions;
	Program( vector<FunctionDefinition *> *functions ) {
		this->functions = functions;
	}
	~Program(){}
};