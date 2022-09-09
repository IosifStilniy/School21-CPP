#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << this->type << " constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const & src)
{
	*this = src;
}

Cat::~Cat()
{
	std::cout << this->type << " destructor" << std::endl;

	delete this->brain;
}

Cat &	Cat::operator=(Cat const & rhd)
{
	this->type = rhd.type;
	*this->brain = *rhd.brain;
	return (*this);
}

void	Cat::makeSound(void)	const
{
	std::cout << "Mew" << std::endl;
}

Brain &	Cat::getBrain(void)
{
	return (*this->brain);
}

void	Cat::someCatStuff(void)	const
{
	std::cout << this->type << " taking shit on your shoes." << std::endl;
}
