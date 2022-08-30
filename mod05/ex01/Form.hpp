#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		unsigned int const	_sign_grade;
		unsigned int const	_exec_grade;
		bool				_signed;

	public:
		Form(void);
		Form(Form const & src);
		Form(std::string name, unsigned int grade_for_signing, unsigned int grade_for_execute);
		~Form();

		Form &	operator=(Form const & rhd);

		std::string const &		getName(void)	const;
		unsigned int			getSignGrade(void)	const;
		unsigned int			getExecGrade(void)	const;
		bool					getIfSigned(void)	const;
		void					beSigned(Bureaucrat const & bury);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what(void)	const	throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what(void)	const	throw();
		};
};

std::ostream &	operator<<(std::ostream & out, Form const & form);

#endif
