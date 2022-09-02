#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main(void)
{
	std::vector<int>	vec(10, 12);
	std::deque<int>		deq(10, 12);
	std::deque<int>		deq1(10, 12);

	vec[3] = 6;
	deq[6] = 6;
	std::list<int>		lst(vec.begin(), vec.end());

	std::cout << easyfind(vec, 6) << std::endl;
	std::cout << easyfind(deq, 6) << std::endl;
	std::cout << easyfind(lst, 6) << std::endl;

	try
	{
		std::cout << easyfind(deq1, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}