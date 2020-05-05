//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef BINARY_H
#define BINARY_H

#include "Expr_Command.h"
#include "Stack.h"
class Binary_Command : public Expr_Command
{
protected:
	Binary_Command(Stack <int> &s)
		:stack(s) {}
public:


	void execute()
	{
	
		int n2 = this->stack.pop(), n1 = this->stack.pop();
		int result = this->evaluate(n1, n2);
		this->stack.push(result);
	}

	virtual int evaluate(int n1, int n2) const = 0;

private:
	Stack <int> &stack;
	

};

#endif // !define BINARY_H