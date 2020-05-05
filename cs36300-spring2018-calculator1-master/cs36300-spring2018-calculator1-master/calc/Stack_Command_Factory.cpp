//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory(Stack <int> &s)
	:stack(s)
{

}

Stack_Command_Factory :: ~Stack_Command_Factory()
{

}

Num_Command *Stack_Command_Factory::create_num_command(int n)
{
	
	return new Num_Command(this->stack, n);
}

Add_Command *Stack_Command_Factory::create_add_command()
{
	return new Add_Command(this->stack);
}

Sub_Command *Stack_Command_Factory::create_sub_command()
{
	return new Sub_Command(this->stack);
}
Mult_Command *Stack_Command_Factory::create_mult_command()
{
	return new Mult_Command(this->stack);
}

Div_Command *Stack_Command_Factory::create_div_command()
{
	return new Div_Command(this->stack);
}

Mod_Command *Stack_Command_Factory::create_mod_command()
{
	return new Mod_Command(this->stack);
}