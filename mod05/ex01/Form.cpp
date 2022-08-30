#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("228F"), _sign_grade(149), _exec_grade(150), _signed(false)
{
}

Form::Form(Form const & src) : _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	*this = src;
}

Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form &	Form::operator=(Form const & rhd)
{
	this->_signed = rhd._signed;

	return (*this);
}

std::string const &		Form::getName(void)	const
{
	return (this->_name);
}

unsigned int	Form::getSignGrade(void)	const
{
	return (this->_sign_grade);
}

unsigned int	Form::getExecGrade(void)	const
{
	return (this->_exec_grade);
}

bool	Form::getIfSigned(void)	const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat const & bury)
{
	if (this->_signed)
	{
		std::cout << "Form " << this->_name << " already signed." << std::endl;
		return ;
	}

	if (bury.getGrade() > this->_sign_grade)
	{
		std::cout << bury << " couldn't sign form " << this->_name << " because he isn't cool enough: need at least " << this->getSignGrade() << " grade." << std::endl;
		return ;
	}

	this->_signed = true;
	std::cout << bury << " signed form " << this->_name << std::endl;
}

const char*	Form::GradeTooHighException::what(void)	const	throw()
{
	return ("Grade high enough, it's impossible to be higher");
}

const char*	Form::GradeTooLowException::what(void)	const	throw()
{
	return ("Grade low enough, it's impossible to be lower");
}

std::ostream &	operator<<(std::ostream & out, Form const & form)
{
	out << std::boolalpha;
	out << form.getName() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ", signed: " << form.getIfSigned();

	return (out);
}
