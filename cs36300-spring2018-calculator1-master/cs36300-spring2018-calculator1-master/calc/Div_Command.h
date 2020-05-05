//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef DIV_H
#define DIV_H

#include "Binary_Command.h"

class Div_Command : public Binary_Command
{
public:
	Div_Command(Stack<int> &s);

	~Div_Command();

	virtual int evaluate(int n1, int n2) const;

	virtual int priority();
};


#endif   // !defined DIV_H