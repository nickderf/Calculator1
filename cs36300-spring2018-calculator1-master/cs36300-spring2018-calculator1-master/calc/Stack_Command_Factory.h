//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef STACK_FACTORY_H
#define STACK_FACTORY_H

#include "Expr_Command_Factory.h"
#include "Stack.h"
class Stack_Command_Factory : public Expr_Command_Factory
{
public:
	Stack_Command_Factory(Stack<int> &stack);

	virtual ~Stack_Command_Factory();

	virtual Num_Command *create_num_command(int n);

	virtual Add_Command *create_add_command();

	virtual Sub_Command *create_sub_command();

	virtual Mult_Command *create_mult_command();

	virtual Div_Command *create_div_command();

	virtual Mod_Command *create_mod_command();

	Stack<int> &stack;
private:
	
};

#endif //!define STACK_FACTORY_H