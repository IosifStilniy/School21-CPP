#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	fella = new Zombie();

	fella->setName(name);
	return (fella);
}
