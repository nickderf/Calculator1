// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include <stdexcept>         // for std::out_of_bounds exception
#define default_size 10

//
// Array
//
template <typename T>
Array <T>::Array (void)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
{
	if (this->size() != length)
	{
		this->resize(length);
	}
}


// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
{
	if (this->size() != length)
	{
		this->resize(length);
	}
	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
{
	delete[] this->data_;
	int length = array.cur_size_;
	this->data_ = new T[length];
	for (int i = 0; i < length; i++)
	{
		this->data_[i] = array.data_[i];
	}
	this->cur_size_ = length;
	this->max_size_ = length;
}

//Stack
template <typename T>
Array <T>::Array(Stack <T>&s)
	:stack(s)
{
	
}


//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this == &rhs) return *this;

	//If the array that is being assigned to doesn't have enough allocated space
	//to take the elements, resize it
	if (rhs.cur_size_ > this->max_size_)
	{
		this->resize(rhs.max_size_);
		
	}
	//Copy over data from rhs array to current array
	for (size_t i = 0; i < rhs.cur_size_; i++)
	{
		this->data_[i] = rhs.data_[i];
	}
	this->cur_size_ = rhs.cur_size_;
	this->max_size_ = rhs.max_size_;

	
		

	
	return *this;
}



//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	//If max size is smaller than the new size then we need to allocate more space
	if (this->max_size_ < new_size)
	{
		this->max_size_ = new_size;
		T *holdData = new T[this->cur_size_];
		holdData = this->data_;
		T *newArray = new T[new_size];
		for (size_t i = 0; i < new_size; i++)
		{
			newArray[i] = this->data_[i];
		}
		delete[] this->data_;
		this->data_ = newArray;
	}
	this->cur_size_ = new_size;
}


//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{

	//Self check
	if (this == &rhs) return true;

	//Check array size first, if not equal then arrays can't be equal.
	if (this->cur_size_ == rhs.cur_size_)
	{
		//Go through each element now and check to see if they are equal
		int j = 0;
		for (size_t i = 0; i < this->cur_size_; i++)
		{
			if (this->data_[i] == rhs.data_[i])
			{
				j++;
			}
		}
		if (j == this->cur_size_)
		{
			std::cout << "These two arrays are the same" << std::endl;
			return true;
		}
	
	}
	std::cout << "These arrays are not the same." << std::endl;
	return false;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	if (*this == rhs)
	{
		
		return false;
	}
	return true;
}

template <typename T>
void Array <T> ::shrink(void)
{
	if (this->max_size_ == this->cur_size_)
	{
		std::cout << "There is no unused space in the array." << std::endl;
	}
	else
	{
		//Closes gap between max_size and cur_size_
		//Create pointer to temp array with size cur_size_
		//Copies over data and swaps temp pointer with data_ pointer
		this->max_size_ = this->cur_size_;
		T *tempArray = new T[this->cur_size_];
		for (size_t i = 0; i < this->cur_size_; i++)
		{
			tempArray[i] = this->data_[i];

		}
		delete[] this->data_;
		this->data_ = tempArray;



	}
}
//Create new array that is a slice of the currrent array
template <typename T>
Array <T> Array <T> ::slice(size_t begin) const
{
	if (begin < 0 || begin > this->cur_size_)
	{
		throw std::out_of_range("Index is out of range");
	}
	int size = this->cur_size_ - begin + 1;
	Array <T>arr(size);
	arr = this->slice(begin, this->cur_size_);

	return *arr;
}

template <typename T>
Array <T> Array <T> ::slice(size_t begin, size_t end) const
{
	if ( begin > this->cur_size_ || end > this->cur_size_)
	{
		throw std::out_of_range("Index is out of range");
	}
	int j = 0;
	int size = end - begin + 1;
	Array <T> arr(size);
	for (size_t i = begin; i <= end; i++)
	{
		arr.data_[j] = this->data_[i];
		j++;
	}
	return arr;
}
//Assigns a given stack/queue to the stack/queue pointers
template <typename T>
void Array<T>::add_stack(const Stack<T>&s)
{
	this->stack = s;
}

