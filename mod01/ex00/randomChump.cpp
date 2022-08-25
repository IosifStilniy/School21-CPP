#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	bob = Zombie();

	bob.setName(name);
	bob.announce();
}