//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================
#include <cstring>
#include "Array.h"
#include "Expr_Iterator.h"

Expr_Iterator::Expr_Iterator(Array<Expr_Command*>&arr)
	:a(arr),
	curr(0)
{

}

Expr_Iterator::~Expr_Iterator()
{

}

void Expr_Iterator::next()
{
	this->curr++;
}

int Expr_Iterator::current()
{
	return this->curr;
}

bool Expr_Iterator::is_done()
{
	return this->curr >= this->a.size();
}


Expr_Command &Expr_Iterator:: operator *()
{
	Expr_Command *cmd = this->a.get(this->curr);
	return *cmd;
}


Expr_Command *Expr_Iterator::operator ->()
{
	Expr_Command *cmd = this->a.get(this->curr);
	return cmd;
}
