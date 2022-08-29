#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
{
	this->type = "cure";
}

Cure::Cure(Cure const & src)
{
	this->type = src.type;
}

Cure::~Cure()
{
}

Cure &	Cure::operator=(Cure const & rhd)
{
	(void) rhd;
	return (*this);
}

AMateria*	Cure::clone(void)	const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
