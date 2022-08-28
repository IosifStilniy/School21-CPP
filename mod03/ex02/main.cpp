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
	
	return (0);
}