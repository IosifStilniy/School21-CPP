#include "ClapTrap.hpp"
#include <iostream>
#include <random>

int	main(void)
{
	ClapTrap			boy("Popka");
	ClapTrap			goy("Pipka");
	ClapTrap			d;
	std::random_device	rd;

	std::cout << boy.getName() << " vs " << goy.getName() << " battle. Let start!" << std::endl;
	boy.setDamage(rd() / (rd.max() / 10));
	std::cout << boy.getName() << " take a stick from the ground and get " << boy.getDamage() << " attack damage!" << std::endl;
	goy.setDamage(rd() / (rd.max() / 10));
	std::cout << goy.getName() << " take a bottle and crash it with wall and get " << goy.getDamage() << " attack damage!" << std::endl;
	boy.attack(goy.getName());
	goy.takeDamage(boy.getDamage());
	goy.attack(boy.getName());
	boy.takeDamage(goy.getDamage());
	boy.beRepaired(rd() / (rd.max() / 10));
	goy.beRepaired(rd() / (rd.max() / 10));
	std::cout << "Battle finished!" << std::endl;
}