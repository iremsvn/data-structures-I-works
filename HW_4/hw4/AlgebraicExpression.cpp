#include "AlgebraicExpression.h"
#include <iostream>

using namespace std;

string infix2prefix(const string exp) {
	string str = exp;
	AlgebraicExpression* a = new AlgebraicExpression();
	(*a).reverseParant(str);
	(*a).reverseStr(str);
	(*a).postfix(str);
	(*a).reverseStr(str);
	delete a;
	return str;
}


double evaluatePrefix(const string exp) {
	AlgebraicExpression* b = new AlgebraicExpression();
	double result = (*b).evaluatePre(exp);
	delete b;
	return result;
}



AlgebraicExpression::AlgebraicExpression():stack(NULL) {
	stack = new Stack();
}

AlgebraicExpression::~AlgebraicExpression() {
	delete stack;
}

void AlgebraicExpression::postfix(string& str) {
	string strP;
	StackItemType top;
	for (int i = 0; i < str.length(); i++) {
		if (isOperand(str[i])) {
			strP += str[i];
		}
		else if (str[i] == '(') {
			(*stack).push(str[i]);
		}
		else if (str[i] == ')') {
			(*stack).getTop(top);
			while (top != '(') {
				strP += top;
				(*stack).pop();
				(*stack).getTop(top);
			}
			(*stack).pop();
		}
		else {
			(*stack).getTop(top);
			while ((!(*stack).isEmpty()) && top != '(' && precedence(str[i]) <= precedence(top)) {
				strP += top;
				(*stack).pop();
				(*stack).getTop(top);
			}
			(*stack).push(str[i]); 
		}
	}

	while (!(*stack).isEmpty())
	{
		StackItemType top;
		(*stack).pop(top);
		if (top == '(') {
			cout << "INVALID EXPRESSION" << endl;
			str = "";
			return;
		}
		strP += top;
	}
	str = strP;
}


bool AlgebraicExpression::isOperand(StackItemType ch) {
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ||
			ch == '6' || ch == '7' || ch == '8' || ch == '9'){
			return true;
		}		
	return false;
}

int AlgebraicExpression::precedence(StackItemType c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void AlgebraicExpression::reverseStr(string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++) {
		char temp = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = temp;
	}
}

void AlgebraicExpression::reverseParant(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')')
			str[i] = '(';
		else if (str[i] == '(')
			str[i] = ')';
	}

}


double AlgebraicExpression::evaluatePre(const string strE){
	string str = strE;
	Stack* stack2 = new Stack();
	StackItemType result;
	for (int j = str.size() - 1; j >= 0; j--) {


		if (isOperand(str[j])) {
			(*stack2).push((double) str[j] - '0');
		}

		else {
			StackItemType c1;
			StackItemType c2;
			double num1;
			double num2;
			(*stack2).pop(c1);
			(*stack2).pop(c2);
			num1 = (double)c1;
			num2 = (double)c2;
			switch (str[j]) {
			case '+':
				(*stack2).push((double)(num1 + num2));
				break;
			case '-':
				(*stack2).push((double)(num1 - num2));
				break;
			case '*':
				(*stack2).push((double)(num1 * num2));
				break;
			case '/':
				(*stack2).push((double)(num1 / num2));
				break;
			}
		}
	}
	(*stack2).getTop(result);
	delete stack2;
	return (double) result;
}


