#include "iter.hpp"
#include <random>

void	randomized(float & num)
{
	std::random_device	rd;
	num = rd();
}

int	main(void)
{
	float	a[10];

	iter(a, 10, &randomized);
	iter(a, 10, &print);
	return (0);
}