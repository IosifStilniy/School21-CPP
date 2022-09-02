template<typename T>
Array<T>::Array(void) : _size(1), _elements(new T[1])
{
}

template<typename T>
Array<T>::Array(Array const & src)
{
	*this = src;
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	if (!size)
		throw ZeroLengthException();

	this->_elements = new T[this->_size];
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_elements;
}

template<typename T>
Array<T> &	Array<T>::operator=(Array const & rhd)
{
	if (this->_size != rhd._size)
	{
		delete [] this->_elements;
		this->_size = rhd._size;
		this->_elements = new T[this->_size];
	}
	for (unsigned int i = 0; i < this->_size; i++)
		this->_elements[i] = rhd._elements[i];

	return (*this);
}

template<typename T>
T &	Array<T>::operator[](unsigned int n)
{
	if (n > this->_size - 1)
		throw OutOfBoundsException();
	
	return (this->_elements[n]);
}

template<typename T>
unsigned int	Array<T>::size(void)	const
{
	return (this->_size);
}

template<typename T>
const char*	Array<T>::ZeroLengthException::what(void)	const	throw()
{
	return ("ZeroLengthException");
}

template<typename T>
const char*	Array<T>::OutOfBoundsException::what(void)	const	throw()
{
	return ("OutOfBoundsException");
}
