//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Div_Command.h"
#include "Binary_Command.h"
Div_Command::Div_Command(Stack<int> &stack) : Binary_Command(stack)
{

}

Div_Command::~Div_Command()
{

}

int Div_Command::priority()
{
	return 1;
}

int Div_Command::evaluate(int n1, int n2) const
{
	return n1 / n2;
}