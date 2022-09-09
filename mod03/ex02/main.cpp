#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	def;
	ScavTrap	bob("Bob");
	FragTrap	frag;
	FragTrap	trap("Froggy");

	def = bob;
	std::cout << def.getName() << std::endl;
	bob.guardGate();
	frag = trap;
	trap.highFivesGuys();
	trap.attack("trashcan");
	trap.takeDamage(1000);
	trap.beRepaired(1000);
	return (0);
}