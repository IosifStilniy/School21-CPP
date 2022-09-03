#include "Span.hpp"
#include <iostream>
#include <random>

int main()
{
	Span sp = Span(5);
	std::list<int> p(100000, 0);
	std::random_device	rd;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	for (std::list<int>::iterator start = p.begin();
		start != p.end(); start++)
			*start = rd();

	Span sp1 = Span(p.begin(), p.end());
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	return 0;
}
