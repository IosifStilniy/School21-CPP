#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(Point const & src);
		Point(float const x, float const y);
		~Point();

		Point &	operator=(Point const & rhd);

		Fixed const &	getX(void)		const;
		Fixed const &	getY(void)		const;
};

#endif
