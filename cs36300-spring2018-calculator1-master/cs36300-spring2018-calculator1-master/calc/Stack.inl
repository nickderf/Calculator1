// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
#include "Empty_Exception.h"
template <typename T>
inline
size_t Stack <T>::size(void) const
{
	return this->stack_size;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top(void) const
{
	
	if (this->is_empty()) throw Empty_Exception();

	//Stack_size is number of elements, so to index it must be 1 less than
	return this->data_[this->stack_size - 1];

}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty(void) const
{
	if (this->stack_size <= 0)
	{
		return true;
	}
	return false;
}
