//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================
#include "Sub_Command.h"
#include "Binary_Command.h"

Sub_Command::Sub_Command(Stack<int> &s) :Binary_Command(s)
{

}

Sub_Command::~Sub_Command()
{

}

int Sub_Command::priority()
{
	return 2;
}
int Sub_Command::evaluate(int n1, int n2) const
{
	return n1 - n2;
}