#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
	private:
		std::string	_forms[3];

	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern();

		Intern &	operator=(Intern const & rhd);

		AForm*	makeForm(std::string const & type, std::string const & target)	const;
};

#endif