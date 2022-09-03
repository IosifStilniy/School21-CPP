#include <limits>
#include "Span.hpp"

Span::Span(void) : _max_size(0), _elems(nullptr)
{
}

Span::Span(unsigned int max_size) : _max_size(max_size), _elems(new std::list<int>)
{
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
	this->_elems->clear();
	delete this->_elems;
}

Span &	Span::operator=(Span const & rhd)
{
	this->_max_size = rhd._max_size;
	this->_elems->clear();
	delete this->_elems;
	this->_elems = new std::list<int>(*rhd._elems);

	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->_max_size <= this->_elems->size())
		throw Span::ReachedMaxSizeException();

	this->_elems->push_back(num);
}

unsigned int	Span::shortestSpan(void)	const
{
	if (this->_max_size < 2)
		throw Span::SmallSizeException();

	unsigned int					min = std::numeric_limits<unsigned int>::max();
	unsigned int					dif;
	std::list<int>::const_iterator	start = this->_elems->begin();
	int								left = *start++;

	for (; start != this->_elems->end(); start++)
	{
		dif = *start - left;
		if (left > *start)
			dif = left - *start;
		if (dif < min)
			min = dif;
		left = *start;
	}
	
	return (min);
}

unsigned int	Span::longestSpan(void)	const
{
	if (this->_max_size < 2)
		throw Span::SmallSizeException();

	unsigned int					max = 0;
	unsigned int					dif;
	std::list<int>::const_iterator	start = this->_elems->begin();
	int								left = *start++;

	for (; start != this->_elems->end(); start++)
	{
		dif = *start - left;
		if (left > *start)
			dif = left - *start;
		if (dif > max)
			max = dif;
		left = *start;
	}

	return (max);
}

const char*	Span::ReachedMaxSizeException::what()	const	throw()
{
	return ("reached maximum size of span");
}

const char*	Span::SmallSizeException::what()	const	throw()
{
	return ("needed at least 2 values for defining span");
}
