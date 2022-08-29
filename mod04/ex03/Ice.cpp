#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
	this->type = "ice";
}

Ice::Ice(Ice const & src)
{
	this->type = src.type;
}

Ice::~Ice()
{
}

Ice &	Ice::operator=(Ice const & rhd)
{
	(void) rhd;
	return (*this);
}

AMateria*	Ice::clone(void)	const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
