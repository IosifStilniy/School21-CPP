#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("trashcan")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm("Shrubbery Creation", 145, 137), _target(src._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhd)
{
	(void) rhd;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)	const
{
	std::ofstream	out;
	std::string		tree = "lets imagine, that here you see the increadebly buetyful ASCII tree";

	try
	{
		this->checkForm(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return ;
	}
	
	out.open(this->_target + "_shrubbery");
	if (!out.good())
	{
		std::cerr << "Bad output file" << std::endl;
		return ;
	}
	out << tree;
	out.close();
}
