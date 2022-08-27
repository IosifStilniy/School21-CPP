#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	normsign(Point const & point, Point const & first, Point const & second)
{
	return ((point.getX() - second.getX()) * (first.getY() - second.getY())
		- (first.getX() - second.getX()) * (point.getY() - second.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	signs[3];
	bool	neg, pos;

	signs[0] = normsign(point, a, b);
	signs[1] = normsign(point, b, c);
	signs[2] = normsign(point, c, a);

	if (signs[0] == 0 || signs[1] == 0 || signs[2] == 0)
		return (false);
		
	neg = (signs[0] < 0) || (signs[1] < 0) || (signs[2] < 0);
	pos = (signs[0] > 0) || (signs[1] > 0) || (signs[2] > 0);

	return (!(neg && pos));
}