#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal &	Animal::operator=(Animal const & rhd)
{
	this->type = rhd.type;
	return (*this);
}

std::string const &	Animal::getType(void)	const
{
	return (this->type);
}

void	Animal::makeSound(void)	const
{
	std::cout << "[ Some animal sounds ]" << std::endl;
}
