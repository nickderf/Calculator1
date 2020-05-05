//==============================================================================
/**
* @file       Array.h
*
* $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef VARIABLE_H_
#define VARIABLE_H_

class variable
{
public:
	variable(char ch);

	~variable();

	int getNumber();

	void setNumber();
	
	void setNumber(int n);

	char getLetter();

	void setLetter(char c);

	int getPostfixPos();

	void setPostfixPos(int pos);

private:
	//Number that user will input to represent the variable
	int number;
	
	//The letter that represents the variable
	char letter;
	
	//Position in the postfix array that is used to evaluate the expression.
	int postfix_pos;
};

#endif //!define VARIABLE_H