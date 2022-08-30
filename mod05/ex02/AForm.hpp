#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		unsigned int const	_sign_grade;
		unsigned int const	_exec_grade;
		bool				_signed;

	public:
		AForm(void);
		AForm(AForm const & src);
		AForm(std::string name, unsigned int grade_for_signing, unsigned int grade_for_execute);
		virtual ~AForm();

		AForm &	operator=(AForm const & rhd);

		std::string const &		getName(void)										const;
		unsigned int			getSignGrade(void)									const;
		unsigned int			getExecGrade(void)									const;
		bool					getIfSigned(void)									const;
		void					beSigned(Bureaucrat const & bury);
		void					checkForm(Bureaucrat const & executor)	const;

		virtual void	execute(Bureaucrat const & executor) const = 0;

		class FormNotSignedException : public std::exception
		{
			public:
				const char*	what(void)	const	throw();
		};

		class GradeTooLowForExecutionException : public std::exception
		{
			public:
				const char*	what(void)	const	throw();
		};

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

std::ostream &	operator<<(std::ostream & out, AForm const & form);

#endif
