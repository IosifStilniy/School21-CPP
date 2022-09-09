#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	pop("ka");
	DiamondTrap	kok;
	FragTrap	puk;
	ScavTrap	pis;

	// pop.attack("trashcan");
	puk.attack("trashcan");
	pis.attack("trashcan");
	pop.whoAmI();
	pop.attack("trashcan");
	pop.takeDamage(100);
	pop.beRepaired(10);
	pop.guardGate();
	pop.highFivesGuys();
	pop.takeDamage(1000000);
	kok = pop;
	kok.attack(pop.getName());
	return (0);
}
