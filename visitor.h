#ifndef VISITOR_H
#define VISITOR_H 

class PostUnaryOpExpression;
class PreUnaryOpExpression;
class BinaryOpExpression;
class TernaryOpExpression;
class StringLit;
class CharLit;
class IntLit;
class FunctionCall;
class Declaration;
class ReturnStatement;
class BreakStatement;
class ContinueStatement;
class ExpressionStatement;
class DeclarationStatement;
class WhileStatement;
class ForStatement;
class IfElseStatement;
class FunctionDefinition;
class Program;

class Visitor {
public:
	virtual void visit(PostUnaryOpExpression *) = 0;
	virtual void visit(PreUnaryOpExpression *) = 0;
	virtual void visit(BinaryOpExpression *) = 0;
	virtual void visit(TernaryOpExpression *) = 0;
	virtual void visit(StringLit *) = 0;
	virtual void visit(CharLit *) = 0;
	virtual void visit(IntLit *) = 0;
	virtual void visit(FunctionCall *) = 0;
	virtual void visit(Declaration *) = 0;
	virtual void visit(ReturnStatement *) = 0;
	virtual void visit(BreakStatement *) = 0;
	virtual void visit(ContinueStatement *) = 0;
	virtual void visit(ExpressionStatement *) = 0;
	virtual void visit(DeclarationStatement *) = 0;
	virtual void visit(WhileStatement *) = 0;
	virtual void visit(ForStatement *) = 0;
	virtual void visit(IfElseStatement *) = 0;
	virtual void visit(FunctionDefinition *) = 0;
	virtual void visit(Program *) = 0;
};

#endif