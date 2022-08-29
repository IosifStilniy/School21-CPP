#include "AAnimal.hpp"
#include <iostream>

AAnimal::~AAnimal()
{
	std::cout << "Abstract class destructor" << std::endl;
}

std::string const &	AAnimal::getType(void)	const
{
	return (this->type);
}
