#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Bury"), _grade(150)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const & name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;

	return (*this);
}

std::string const &	Bureaucrat::getName(void)	const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void)	const
{
	return (this->_grade);
}

unsigned int	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return (this->_grade);
	}

	return (--this->_grade);
}

unsigned int	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return (this->_grade);
	}

	return (++this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what(void)	const	throw()
{
	return ("Grade high enough, it's impossible to be higher");
}

const char*	Bureaucrat::GradeTooLowException::what(void)	const	throw()
{
	return ("Grade low enough, it's impossible to be lower");
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bure)
{
	out << bure.getName() << ", bureaucrat grade " << bure.getGrade();
	
	return (out);
}
