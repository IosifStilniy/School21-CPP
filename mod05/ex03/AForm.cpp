#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : _name("228F"), _sign_grade(149), _exec_grade(150), _signed(false)
{
}

AForm::AForm(AForm const & src) : _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	*this = src;
}

AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm &	AForm::operator=(AForm const & rhd)
{
	this->_signed = rhd._signed;

	return (*this);
}

std::string const &		AForm::getName(void)	const
{
	return (this->_name);
}

unsigned int	AForm::getSignGrade(void)	const
{
	return (this->_sign_grade);
}

unsigned int	AForm::getExecGrade(void)	const
{
	return (this->_exec_grade);
}

bool	AForm::getIfSigned(void)	const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat const & bury)
{
	if (this->_signed)
	{
		std::cout << "Form " << *this << " already signed." << std::endl;
		return ;
	}

	if (bury.getGrade() > this->_sign_grade)
	{
		std::cout << bury << " couldn't sign form " << *this << std::endl;
		return ;
	}

	this->_signed = true;
	std::cout << bury << " signed form " << *this << std::endl;
}

void	AForm::checkForm(Bureaucrat const & executor)	const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	
	if (executor.getGrade() > this->_exec_grade)
		throw AForm::GradeTooLowForExecutionException();
}

const char*	AForm::GradeTooHighException::what(void)	const	throw()
{
	return ("Grade high enough, it's impossible to be higher");
}

const char*	AForm::GradeTooLowException::what(void)	const	throw()
{
	return ("Grade low enough, it's impossible to be lower");
}

const char*	AForm::FormNotSignedException::what(void)	const	throw()
{
	return ("Form not signed");
}

const char*	AForm::GradeTooLowForExecutionException::what(void)	const	throw()
{
	return ("Grade too low for execution");
}

std::ostream &	operator<<(std::ostream & out, AForm const & form)
{
	out << std::boolalpha;
	out << form.getName() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ", signed: " << form.getIfSigned();

	return (out);
}
