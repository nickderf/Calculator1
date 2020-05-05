//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef BASE_H
#define BASE_H

#include <cstring> 

//Base class that the Array is derived from

template <typename T>
class BaseArray
{
public:
	//Default Constructor
	BaseArray();

	//Initializing constructor
	BaseArray(size_t size);
	
	//Fill Constructor
	BaseArray(size_t size, T fill);

	//Copy Constructor
	BaseArray(BaseArray& b);

	//Destructor
	~BaseArray();

	//Return the current size of the array
	size_t size(void) const;

	//Return the max capacity of the array
	size_t max_size(void) const;

	//Return element at index. Throw exception when index out of range
	T get(size_t index) const;

	//Set the given value at the index. Throw exception if index out of range
	void set(size_t index, T value);

	//Fill all spots in the array with given element
	void fill(T element);

	//Return index the 1st element found is at. Return -1 if element does not exist in array
	int find(T element) const;

	//Return index element is at. Start is the starting index in the array
	//Throw exception if start out of range of array.
	int find(T element, size_t start) const;

	void reverse(void);

	/**
	* Get the character at the specified index. If the index is not
	* within the range of the array, then std::out_of_range exception
	* is thrown.
	*
	* @param[in]       index               Zero-based location
	* @exception       std::out_of_range   Invalid \a index value
	*/
	T & operator [] (size_t index);

	/**
	* @overload
	*
	* The returned character is not modifiable.
	*/
	const T & operator [] (size_t index) const;



protected:
	/// Pointer to the actual data.
	T * data_;

	/// Current size of the array.
	size_t cur_size_;

	/// Maximum size of the array.
	size_t max_size_;

};

#include "BaseArray.inl"
#include "BaseArray.cpp"

#endif   // !defined BASE_H