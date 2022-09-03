#include "Fixed.hpp"
#include <iostream>

int const	Fixed::_numFract = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_value = src.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
