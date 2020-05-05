//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================
#include <stdexcept>
#include <iostream>
#include <cstring>

//Construct a default basearray with size 10
#define default_size 10
template <typename T>
BaseArray <T> :: BaseArray()
	: data_(new T[default_size]),
	cur_size_(default_size),
	max_size_(default_size)
{
	
}

//Construct basearray with specific length
template <typename T>
BaseArray <T> ::BaseArray(size_t length)
	:data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{

}

//Construct with certain length and fill contents with a value
template <typename T>
BaseArray <T> ::BaseArray(size_t length, T fill)
	:data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{
	this->fill(fill);
}

//Copy constructor
template <typename T>
BaseArray <T> ::BaseArray(BaseArray &b)
	: data_(new T[b.size()]),
	cur_size_(b.cur_size_),
	max_size_(b.max_size_)
	

{
	for (size_t i = 0; i < b.cur_size_; i++)
	{
		this->set(i, b[i]);
	}
}

template <typename T>
BaseArray <T> :: ~BaseArray()
{
	delete[] this->data_;

}

//Return the value at a specific index, throw out of range error if index doesn't exist
template <typename T>
T BaseArray <T> ::get(size_t index) const
{
	if (index <= this->cur_size_)
	{

		return this->data_[index];
	}
	else
	{

		throw std::out_of_range("Error: Index out of range");
	}

}


//Set value at specific index
template <typename T>
void BaseArray <T> ::set(size_t index, T value)
{
	if (index <= this->cur_size_)
	{

		this->data_[index] = value;
		
	}
	else
	{
		throw std::out_of_range("Error: Index out of range");
	}
}


//Fill contents of basearray
template <typename T>
void BaseArray <T> ::fill(T element)
{
	for (size_t i = 0; i < this->cur_size_; i++)
	{
		
		this->data_[i] = element;
	
	}
	
	
}

//Search through the basearray and return the first element that matches "element", if not in basearray return -1
template <typename T>
int BaseArray <T> ::find(T element) const
{
	this->find(element, 0);
}

//Find element, but can specify a start point, throw out of range error if start isn't a valid index
template <typename T>
int BaseArray <T> ::find(T element, size_t start) const
{
	if (start <= cur_size_)
	{
		for (int i = start; i < this->cur_size_; i++)
		{
			if (this->data_[i] == element)
			{
				return i;
			}
		}
	}
	else
	{
		throw std::out_of_range("Error: Start Index was not in range.");
	}
	return -1;
}

//Reverse the contents of the array
template <typename T>
void BaseArray <T> ::reverse()
{
	int j = this->cur_size_ - 1;
	for (size_t i = 0; i < this->cur_size_ / 2; i++)
	{
		T temp = this->data_[i];
		this->data_[i] = this->data_[j];
		this->data_[j] = temp;

		j--;
	}
}

//
// operator []
//
template <typename T>
T & BaseArray <T>::operator [] (size_t index)
{

	if (index <= this->cur_size_)
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("The index is out of range");
	}

}

//
// operator [] 
//
template <typename T>
const T & BaseArray <T>::operator [] (size_t index) const
{

	if (this->data_[index] <= this->cur_size_)
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Index out of range");
	}
}




