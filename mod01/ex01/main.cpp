#include "Zombie.hpp"
#include <iostream>

Zombie*	zombieHorde(int N, std::string name);

int	main(int argc, char **argv)
{
	Zombie*		zombas;
	int			num = 0;

	if (argc > 1)
		num = atoi(argv[1]);
	if (argc != 3 || num < 1)
	{
		std::cout << argv[0] << ": write num of zombies and one name" << std::endl;
		return (0);
	}

	zombas = zombieHorde(num, std::string(argv[2]));
	
	for (int i = 0; i < num; i++)
		zombas[i].announce();

	delete [] zombas;

	return (0);
}
