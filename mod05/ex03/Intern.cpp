#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	this->_forms[0] = "presidential pardon";
	this->_forms[1] = "robotomy request";
	this->_forms[2] = "shrubbery creation";
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &	Intern::operator=(Intern const & rhd)
{
	this->_forms[0] = rhd._forms[0];
	this->_forms[1] = rhd._forms[1];
	this->_forms[2] = rhd._forms[2];

	return (*this);
}

AForm*	Intern::makeForm(std::string const & type, std::string const & target)	const
{
	bool	formExist = false;
	int		i;

	for (i = 0; i < 3; i++)
		if (!type.compare(this->_forms[i]) && (formExist = true))
			break ;
	
	switch (i)
	{
	case 0:
		return (new PresidentialPardonForm(target));

	case 1:
		return (new RobotomyRequestForm(target));

	case 2:
		return (new ShrubberyCreationForm(target));
	
	default:
		std::cerr << "Form of type " << type << " doesn't exist." << std::endl;
		return (nullptr);
	}
}
