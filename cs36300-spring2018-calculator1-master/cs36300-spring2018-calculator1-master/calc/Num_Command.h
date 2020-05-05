//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef NUM_H
#define NUM_H

#include "Expr_Command.h"
#include "Stack.h"
class Num_Command : public Expr_Command
{
public:
	Num_Command(Stack <int> &s, int n);

	virtual void execute();

	virtual int priority();

	void setNumber(int n);


private:
	Stack <int> &stack;
	int number;

};

#endif // !define NUM_H