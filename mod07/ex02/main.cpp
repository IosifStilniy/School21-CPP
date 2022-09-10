#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void)
{
	Array<>				a(10);
	Array<>				b(5);
	Array<std::string>	c;
	Array<float>		d(5);
	Array<float>		e(0);

	a[0] = 2;
	a[3] = 1;
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << a[3] << std::endl;
	b = a;
	std::cout << b[0] << std::endl;
	std::cout << b[1] << std::endl;
	std::cout << b[3] << std::endl;
	// b[10];
	b = Array<int>();
	// std::cout << b[0] << std::endl;
	return (0);
}