#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef double StackItemType;


class Stack {
	
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	bool isEmpty() const;
	bool push(StackItemType newItem);
	bool pop();
	bool pop(StackItemType& stackTop);
	bool getTop(StackItemType& stackTop) const;


private:
	struct StackNode {            
		StackItemType item;    
		StackNode* next;       
	};

	StackNode* topPtr;     
};
