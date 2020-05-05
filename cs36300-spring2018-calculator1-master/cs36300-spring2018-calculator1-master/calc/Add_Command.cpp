//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Add_Command.h"
#include "Binary_Command.h"
Add_Command::Add_Command(Stack <int> &s) : Binary_Command(s)
{

}

Add_Command::~Add_Command()
{

}

int Add_Command::priority()
{
	
	return 2;
}
int Add_Command::evaluate(int n1, int n2) const
{
	
	return n1 + n2;
}