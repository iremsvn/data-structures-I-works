#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

// It converts an infix expression exp to its equivalent prefix form. 
string infix2prefix( const string exp );
// It evaluates a prefix expression. 
double evaluatePrefix( const string exp );


class AlgebraicExpression {

public:
	AlgebraicExpression();
	~AlgebraicExpression();
	void postfix(string& str);
	void reverseStr(string& str);
	void reverseParant(string& str);
	double evaluatePre(const string strE);

private:
	Stack* stack;
	bool isOperand(StackItemType ch);
	int precedence(StackItemType c);

};