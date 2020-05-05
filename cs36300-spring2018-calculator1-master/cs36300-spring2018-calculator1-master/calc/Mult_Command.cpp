//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Mult_Command.h"
#include "Binary_Command.h"

Mult_Command::Mult_Command(Stack<int> &s) : Binary_Command(s)
{

}

Mult_Command::~Mult_Command()
{

}

int Mult_Command::priority()
{
	return 1;
}
int Mult_Command::evaluate(int n1, int n2) const
{
	return n1 * n2;
}