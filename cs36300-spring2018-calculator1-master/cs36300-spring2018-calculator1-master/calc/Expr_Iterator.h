

//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================
#include <cstring>
#include "Expr_Command.h"
#ifndef EXPR_ITER_H
#define EXPR_ITER_H

class Expr_Iterator
{
public:
	Expr_Iterator(Array<Expr_Command*> &arr);

	~Expr_Iterator();

	int current();

	void next();

	bool is_done();

	Expr_Command & operator * ();

	Expr_Command * operator -> ();

private:
	Array <Expr_Command*> &a;

	size_t curr;


};

#endif //!define EXPR_ITER_H