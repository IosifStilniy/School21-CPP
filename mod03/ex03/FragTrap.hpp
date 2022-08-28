#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		/* data */
	public:
		FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap(std::string const & name);
		~FragTrap();

		FragTrap &	operator=(FragTrap const & rhd);

		void	attack(const std::string & target);
		void	highFivesGuys(void);
};

#endif