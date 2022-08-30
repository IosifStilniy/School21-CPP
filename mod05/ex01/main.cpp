#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	boris("Boris", 19);
	Bureaucrat	doris("Doris", 1);
	Form		f1("1488", 1, 2);
	Form		f2("8841", 20, 2);
	Form*		f3;

	boris.signForm(f1);
	boris.signForm(f2);
	doris.signForm(f1);
	doris.signForm(f2);

	try
	{
		f3 = new Form("228B", 0, 1);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		f3 = new Form("228B", 1, 151);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		f3 = new Form("228B", 0, 151);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}