//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef ADD_H
#define ADD_H

#include "Binary_Command.h"
class Add_Command : public Binary_Command
{
public:
	Add_Command(Stack<int> &s);

	~Add_Command();

	virtual int evaluate(int n1, int n2) const;

	virtual int priority();

};

#endif // !defined ADD_H