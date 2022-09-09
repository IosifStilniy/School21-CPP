#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << this->type << " constructor" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog const & src)
{
	*this = src;
}

Dog::~Dog()
{
	std::cout << this->type << " destructor" << std::endl;

	delete this->brain;
}

Dog &	Dog::operator=(Dog const & rhd)
{
	this->type = rhd.type;
	*this->brain = *rhd.brain;
	return (*this);
}

void	Dog::makeSound(void)	const
{
	std::cout << "Bark" << std::endl;
}

Brain &	Dog::getBrain(void)
{
	return (*this->brain);
}
