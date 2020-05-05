// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t BaseArray <T>::size(void) const
{
	return this->cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t BaseArray <T>::max_size(void) const
{
	return this->max_size_;
}

