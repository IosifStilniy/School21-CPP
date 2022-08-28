#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const	Fixed::_numFract = 8;
int const	Fixed::_fractMask = (1 << Fixed::_numFract) - 1;

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::Fixed(int const i)
{
	this->setRawBits(i << Fixed::getNumFract());
}

Fixed::Fixed(float const f)
{
	this->setRawBits((int)(f * (1 << Fixed::getNumFract())));
}

Fixed::~Fixed()
{
}

Fixed &	Fixed::operator=(Fixed const & src)
{
	this->setRawBits(src.getRawBits());

	return (*this);
}

Fixed	Fixed::operator+(Fixed const & rhd)	const
{
	Fixed	buf(*this);

	buf.setRawBits(buf.getRawBits() + rhd.getRawBits());
	return (buf);
}

Fixed	Fixed::operator-(Fixed const & rhd)	const
{
	Fixed	buf(*this);

	buf.setRawBits(buf.getRawBits() - rhd.getRawBits());
	return (buf);
}

Fixed	Fixed::operator*(Fixed const & rhd)	const
{
	Fixed	buf(*this);
	int		int1;
	int		int2;
	int		fract1;
	int		fract2;
	int		res;

	int1 = this->toInt();
	int2 = rhd.toInt();
	fract1 = this->getRawBits() & Fixed::_fractMask;
	fract2 = rhd.getRawBits() & Fixed::_fractMask;
	res = (int1 * int2) << Fixed::getNumFract();
	res += int1 * fract2;
	res += int2 * fract1;
	res += ((fract1 * fract2) >> Fixed::getNumFract()) & Fixed::_fractMask;
	buf.setRawBits(res);
	return (buf);
}

Fixed	Fixed::operator/(Fixed const & rhd)	const
{
	Fixed			buf(*this);
	unsigned int	denom = 1 << 31;
	int				res;

	denom = (unsigned int)(denom / rhd.getRawBits());
	res = this->getRawBits() * denom;
	buf.setRawBits(res << 1);
	return (buf);
}

Fixed &	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int i)
{
	Fixed	old(*this);

	(void) i;
	this->setRawBits(this->getRawBits() + 1);
	return (old);
}

Fixed &	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int i)
{
	Fixed	old(*this);

	(void) i;
	this->setRawBits(this->getRawBits() - 1);
	return (old);
}

bool	Fixed::operator>(Fixed const & rhd)	const
{
	return (this->getRawBits() > rhd.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhd)	const
{
	return (this->getRawBits() >= rhd.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhd)	const
{
	return (this->getRawBits() < rhd.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhd)	const
{
	return (this->getRawBits() <= rhd.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhd)	const
{
	return (this->getRawBits() == rhd.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhd)	const
{
	return (this->getRawBits() != rhd.getRawBits());
}

int	Fixed::getRawBits(void)	const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}


int	Fixed::toInt(void)	const
{
	return (this->getRawBits() >> Fixed::getNumFract());
}

float	Fixed::toFloat(void)	const
{
	return ((float)this->getRawBits() / (1 << Fixed::getNumFract()));
}

int 	Fixed::getNumFract(void)
{
	return (Fixed::_numFract);
}

Fixed &	Fixed::min(Fixed & n1, Fixed & n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed const &	Fixed::min(Fixed const & n1, Fixed const & n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed &	Fixed::max(Fixed & n1, Fixed & n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

Fixed const &	Fixed::max(Fixed const & n1, Fixed const & n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

std::ostream & operator<<(std::ostream & out, Fixed const & fpnum)
{
	out << fpnum.toFloat();
	return (out);
}
