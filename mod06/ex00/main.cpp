#include <string>
#include <iostream>
#include "Converter.hpp"

int	main(int argc, char **argv)
{
	Converter	c;

	if (argc != 2)
	{
		std::cout << *argv << ": only 1 arg" << std::endl;
		return (0);
	}

	c.handleIt(std::string(*(++argv)));

	return (0);
}