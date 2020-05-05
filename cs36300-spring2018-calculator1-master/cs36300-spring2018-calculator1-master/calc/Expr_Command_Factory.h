//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EXPR_FACTORY_H
#define EXPR_FACTORY_H

#include "Num_Command.h"
#include "Add_Command.h"
#include "Mult_Command.h"
#include "Div_Command.h"
#include "Sub_Command.h"
#include "Mod_Command.h"
class Expr_Command_Factory
{
public:
	Expr_Command_Factory();

	virtual ~Expr_Command_Factory() = 0;

	virtual Num_Command *create_num_command(int n) = 0;

	virtual Add_Command *create_add_command() = 0;

	virtual Mult_Command *create_mult_command() = 0;

	virtual Div_Command *create_div_command() = 0;

	virtual Sub_Command *create_sub_command() = 0;

	virtual Mod_Command *create_mod_command() = 0;

private:
	Expr_Command_Factory(const Expr_Command_Factory &factory);
	const Expr_Command_Factory &operator =(const Expr_Command_Factory &factory);

};

#endif //!define EXPR_FACTORY_H