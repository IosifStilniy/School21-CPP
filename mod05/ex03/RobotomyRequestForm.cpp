#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45), _target("trashcan")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("Robotomy Request", 72, 45), _target(src._target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhd)
{
	(void) rhd;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)	const
{
	try
	{
		this->checkForm(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cout << "Robotomy failed" << std::endl;
		return ;
	}
	
	std::cout << "[ EXTREMELY LOUD DRILLING NOISES ]" << std::endl;
	std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
}
