#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <ostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		unsigned int		_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name);
		Bureaucrat(std::string const & name, unsigned int grade);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const & src);

		std::string const &		getName(void)	const;
		unsigned int			getGrade(void)	const;
		unsigned int			incrementGrade(void);
		unsigned int			decrementGrade(void);

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

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bure);

#endif
