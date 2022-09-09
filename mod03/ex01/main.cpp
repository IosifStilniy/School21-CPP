#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	def;
	ScavTrap	bob("Bob");

	def = bob;
	std::cout << def.getName() << std::endl;
	bob.guardGate();
	bob.attack("trashcan");
	bob.beRepaired(1000);
	bob.takeDamage(200);
	def.takeDamage(100000);
	return (0);
}