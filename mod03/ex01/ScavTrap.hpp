#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string const & name);
		~ScavTrap();

		ScavTrap &	operator=(ScavTrap const & rhd);

		void	guardGate(void);
		void	attack(const std::string & target);
};

#endif
