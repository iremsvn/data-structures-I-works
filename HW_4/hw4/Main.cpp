#include "AlgebraicExpression.h"


int main() {

	cout << "\ninfix to prefix" << endl;
	cout << infix2prefix("(4+5)-2*4") << endl; 
	cout << infix2prefix("((2*(8-3))-(2+1)*4)") << endl;
	cout << infix2prefix("(2*9-(1-(2+7)*3))") << endl;
	cout << infix2prefix("((2/3)-(8+1))") << endl;
	cout << infix2prefix("(6-1)+(7-8)*7+9") << endl;
	cout << infix2prefix("((2+9*3)-((7+9/5)*4))/8") << endl;
	cout << infix2prefix("(7*8-((7-8)+7/9+(4/8)*3+1))+5*(7/2)") << endl;

	cout << "\nevaluate prefix" << endl;
    cout << evaluatePrefix("/4+3*-528") << endl;
	cout << evaluatePrefix("-+45*24") << endl;
	cout << evaluatePrefix("-*2-83*+214") << endl;
	cout << evaluatePrefix("-*29-1*+273") << endl;
	cout << evaluatePrefix("-/23+81") << endl;
	cout << evaluatePrefix("+-61+*-7879") << endl;
	cout << evaluatePrefix("/-+2*93*+7/9548") << endl;
	cout << evaluatePrefix("+-*78+-78+/79+*/4831*5/72") << endl;
	return 0;
}



