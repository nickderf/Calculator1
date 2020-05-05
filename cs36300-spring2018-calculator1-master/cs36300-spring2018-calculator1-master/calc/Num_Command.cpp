//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================
#include "Num_Command.h"
Num_Command::Num_Command(Stack <int> &s, int n)
	:stack(s),
	number(n)
{

}

void Num_Command::execute()
{
	this->stack.push(number);
	
}

//Numbers priority are 3, or higher than every other priority
int Num_Command::priority()
{
	return 3;
}

void Num_Command::setNumber(int n)
{
	this->number = n;
}