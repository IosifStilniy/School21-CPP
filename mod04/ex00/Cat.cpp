#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
}

Cat::Cat(Cat const & src)
{
	*this = src;
}

Cat::~Cat()
{
}

Cat &	Cat::operator=(Cat const & rhd)
{
	this->type = rhd.type;
	return (*this);
}

void	Cat::makeSound(void)	const
{
	std::cout << "Mew" << std::endl;
}
