#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	pop("ka");
	FragTrap	puk;
	ScavTrap	pis;

	// pop.attack("trashcan");
	puk.attack("trashcan");
	pis.attack("trashcan");
	pop.whoAmI();
	pop.attack("trashcan");
	return (0);
}
