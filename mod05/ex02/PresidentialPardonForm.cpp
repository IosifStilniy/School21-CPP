#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5), _target("trashcan")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("Presidential Pardon", 145, 137), _target(src._target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon", 145, 137), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhd)
{
	(void) rhd;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)	const
{
	try
	{
		this->checkForm(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return ;
	}
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
