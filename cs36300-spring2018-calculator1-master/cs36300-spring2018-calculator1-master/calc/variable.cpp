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

#include "variable.h"
#include <iostream>
variable::variable(char ch)
	:letter(ch),
	number(0)
{
	
}

variable::~variable()
{

}

int variable::getNumber()
{
	return this->number;
}

void variable::setNumber()
{
	int n;
	std::cout << "Enter the value of "<<this->letter<<": ";
	std::cin >> n;
	this->number = n;
	std::cout << std::endl;
}

void variable::setNumber(int n)
{
	this->number = n;
}

char variable::getLetter()
{
	return this->letter;
}

void variable::setLetter(char c)
{
	this->letter = c;
}

int variable::getPostfixPos()
{
	return this->postfix_pos;
}

void variable::setPostfixPos(int pos)
{
	this->postfix_pos = pos;
}