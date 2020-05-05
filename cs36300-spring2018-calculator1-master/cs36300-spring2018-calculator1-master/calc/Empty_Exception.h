
#ifndef EMPTY_H
#define EMPTY_H
#include <exception>
#include <cstring>
/**
* @class empty_exception
*
* Exception thrown to indicate the stack is empty.
*/
class Empty_Exception : public std::exception
{
public:
	/// Default constructor.
	Empty_Exception(void);
		

	
};

#endif   // !defined EMPTY_H