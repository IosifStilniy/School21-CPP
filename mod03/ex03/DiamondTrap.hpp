#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const & src);
	DiamondTrap(std::string const & name);
	~DiamondTrap();

	DiamondTrap &	operator=(DiamondTrap const & rhd);

	void	whoAmI(void);
	void	attack(std::string const & target);
};

#endif
