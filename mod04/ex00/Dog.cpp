#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
}

Dog::Dog(Dog const & src)
{
	*this = src;
}

Dog::~Dog()
{
}

Dog &	Dog::operator=(Dog const & rhd)
{
	this->type = rhd.type;
	return (*this);
}

void	Dog::makeSound(void)	const
{
	std::cout << "Bark" << std::endl;
}
