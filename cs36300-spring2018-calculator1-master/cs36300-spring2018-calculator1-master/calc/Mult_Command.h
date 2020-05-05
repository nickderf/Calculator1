//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef MULT_H
#define MULT_H

#include "Binary_Command.h"
class Mult_Command : public Binary_Command
{
public:
	Mult_Command(Stack<int> &s);

	~Mult_Command();

	virtual int evaluate(int n1, int n2) const;

	virtual int priority();
};

#endif   // !defined MULT_H