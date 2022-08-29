#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : type("unknown")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::~AMateria()
{
}

std::string const &	AMateria::getType(void)	const
{
	return (this->type);
}

void	AMateria::use(ICharacter & target)
{
	std::cout << "* nothing happens with " << target.getName() << "... *" << std::endl;
}
