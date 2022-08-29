#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
}

WrongCat::~WrongCat()
{
}

WrongCat &	WrongCat::operator=(WrongCat const & rhd)
{
	this->type = rhd.type;
	return (*this);
}

void	WrongCat::makeSound(void)	const
{
	std::cout << "Mew" << std::endl;
}
