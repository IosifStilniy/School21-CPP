#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	A(0, 1);
	Point	B(1, 0);
	Point	C(-1, 0);
	Point	dot(0, -0.9);

	std::cout << bsp(A, B, C, dot) << std::endl;
	return (0);
}
