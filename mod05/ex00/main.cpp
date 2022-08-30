#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	boris("Boris", 1);
	Bureaucrat	doris("Doris", 150);
	Bureaucrat*	poris = nullptr;
	Bureaucrat*	loris = nullptr;
	Bureaucrat	goris("Goris", 2);
	Bureaucrat	moris("Moris");

	std::cout << goris << std::endl;
	std::cout << moris << std::endl;
	moris = goris;
	std::cout << moris << std::endl << std::endl;
	try
	{
		boris.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << boris << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}

	try
	{
		doris.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << doris << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}

	try
	{
		poris = new Bureaucrat("Poris", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << poris << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}

	try
	{
		loris = new Bureaucrat("Loris", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << loris << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
}