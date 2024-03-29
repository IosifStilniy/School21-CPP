#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("Random guy")
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died forever..." << std::endl;
}

void	Zombie::announce(void)	const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string const & name)
{
	this->_name = name;
}
