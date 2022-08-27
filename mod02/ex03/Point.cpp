#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
}

Point::~Point()
{
}

Point &	Point::operator=(Point const & rhd)
{
	(void)	rhd;
	return (*this);
}

Fixed const &	Point::getX(void)	const
{
	return (this->_x);
}

Fixed const &	Point::getY(void)	const
{
	return (this->_y);
}
