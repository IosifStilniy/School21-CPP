#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc == 1)
	{
		std::cout << "[ ... ]" << std::endl;
		return (0);
	}

	harl.complain(argv[1]);
	return (0);
}