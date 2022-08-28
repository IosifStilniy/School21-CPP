#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	def;
	ScavTrap	bob("Bob");

	def = bob;
	std::cout << def.getName() << std::endl;
	bob.guardGate();
	return (0);
}