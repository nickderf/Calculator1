// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Empty_Exception.h"
#include <iostream>
//
// Stack
//
//Default stack size 
#define default_size 50
template <typename T>
Stack <T>::Stack(void)
	:stack_size(0),
	capacity(default_size),
	data_(new T[default_size])
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
	:stack_size(stack.stack_size),
	capacity(stack.capacity),
	data_(new T[stack.capacity])
{
  
  // COMMENT Find a better way to copy over the elements.
	//Used a loop to deal directly with the data_ instead of using the = operator which ends up using the push function

	for (int i = 0; i < capacity; i++)
	{
		this->data_[i] = stack.data_[i];
	}
	
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{
	delete[] this->data_;
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
	
	if (this->stack_size == this->capacity)
	{
		std::cout << "Stack is full!" << std::endl;
	}
	else
	{
		this->data_[stack_size]= element;
		this->stack_size++;
		
	}

	
}

//
// pop
//
template <typename T>
T Stack <T>::pop(void)
{
		if (this->is_empty() == true)
		{
			throw Empty_Exception();
		}
		else
		{
			this->stack_size--;
			if (this->stack_size < 0)
			{
				this->stack_size = 0;
			}
		}
		return this->data_[stack_size];

}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this == &rhs)return *this;
	if (this->capacity == rhs.capacity)
	{
		for (int i = 0; i < rhs.stack_size; i++)
		{
			this->push(rhs.data_[i]);
		}
		this->stack_size = rhs.stack_size;
	}
	else
	{
		std::cout << "These stacks are not compatible to be assigned." << std::endl;
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
  // COMMENT Just reset the variables instead popping each element, which
  // is expensive.
	//Now only sets current amount of elements in the stack to 0
	this->stack_size = 0;
}
