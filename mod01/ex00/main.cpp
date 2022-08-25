#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main(void)
{
	Zombie*	zombas;
	Zombie	zomba;

	zombas = new Zombie[3];
	
	for (int i = 0; i < 3; i++)
		zombas[i].announce();

	delete [] zombas;

	zombas = newZombie("Popchik");
	zombas->announce();
	delete zombas;

	zomba.setName("Pukich");
	zomba.announce();

	randomChump("Tupchik");
	return (0);
}