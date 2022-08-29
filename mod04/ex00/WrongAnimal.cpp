#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhd)
{
	this->type = rhd.type;
	return (*this);
}

std::string const &	WrongAnimal::getType(void)	const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void)	const
{
	std::cout << "[ Some animal sounds ]" << std::endl;
}
