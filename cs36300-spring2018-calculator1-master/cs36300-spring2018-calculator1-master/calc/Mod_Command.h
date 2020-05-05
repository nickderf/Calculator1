//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef MOD_H
#define MOD_H

#include "Binary_Command.h"
class Mod_Command : public Binary_Command
{
public:
	Mod_Command(Stack <int> &s);

	~Mod_Command();

	virtual int evaluate(int n1, int n2) const;

	virtual int priority();
};

#endif //!define MOD_H