//Program to test the various operations of a stack

#include <iostream>             // used for cin, cout
#include "myStack.h"            // class header file

using namespace std;

int main() 
{
    // creating three objects of type stackType<Type>
	stackType<int> stack1(50);
	stackType<int> stack2(50);
	stackType<int> stack3(100);
	int x;

    // populate stack1
	stack1.initializeStack();
	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

    // assign stack to stack 2;
	stack2 = stack1; 

    // are stack1 and stack2 equal?
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

    // operations on stack2
	x = stack2.top();
	stack2.pop();
	stack2.push(32);

	cout << "**** After pop and push operations on stack2 ****"
         << endl;
    // are stack1 and stack2 equal?
	if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;

	// put 11 on stack2
    stack2.push(11);

	cout << "**** After another push operation on stack2 ****" << endl;
	// are stack1 and stack2 equal?
    if (stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;
	system("PAUSE");

	return 0;
}