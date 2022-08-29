#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain();

		Brain &	operator=(Brain const & rhd);

		std::string	ideas[100];
};

#endif