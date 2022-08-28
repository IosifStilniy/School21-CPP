#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		/* data */
	public:
		FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap(std::string const & name);
		~FragTrap();

		FragTrap &	operator=(FragTrap const & rhd);

		void	highFivesGuys(void);
		void	attack(const std::string & target);
};

#endif