#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string const & name);
		~ScavTrap();

		ScavTrap &	operator=(ScavTrap const & rhd);

		void	attack(const std::string & target);
		void	guardGate(void);
};

#endif