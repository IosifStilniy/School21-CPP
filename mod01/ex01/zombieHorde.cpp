#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	zombas = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombas[i].setName(name);
	return (zombas);
}
