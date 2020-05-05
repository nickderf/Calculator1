//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EXPR_H
#define EXPR_H

class Expr_Command
{
public:
	virtual void execute() = 0;

	//Priority which is used for converting from infix to postfix
	//"*" and "/" have priority 1. "+" and "-" have priority "2"
	virtual int priority() = 0;
};

#endif // !define EXPR_H
