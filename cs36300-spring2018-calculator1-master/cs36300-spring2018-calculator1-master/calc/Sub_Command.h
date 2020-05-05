//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef SUB_H
#define SUB_H

#include "Binary_Command.h"
class Sub_Command : public Binary_Command
{
public:
	Sub_Command(Stack<int> &s);

	~Sub_Command();

	virtual int evaluate(int n1, int n2) const;

	virtual int priority();
};

#endif // !defined SUB_H