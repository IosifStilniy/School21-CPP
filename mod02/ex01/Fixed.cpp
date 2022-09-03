#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i << Fixed::getNumFract());
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)(f * (1 << Fixed::getNumFract())));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->setRawBits(src.getRawBits());

	return (*this);
}

int	Fixed::getRawBits(void)	const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int 	Fixed::getNumFract(void)
{
	return (Fixed::_numFract);
}

int	Fixed::toInt(void)	const
{
	return (this->getRawBits() >> Fixed::getNumFract());
}

float	Fixed::toFloat(void)	const
{
	return ((float)this->getRawBits() / (1 << Fixed::getNumFract()));
}

std::ostream & operator<<(std::ostream & out, Fixed const & fpnum)
{
	out << fpnum.toFloat();
	return (out);
}
