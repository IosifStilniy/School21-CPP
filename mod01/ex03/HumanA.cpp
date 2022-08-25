#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), name(name)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->getWeapon().getType() << std::endl;
}

Weapon const &	HumanA::getWeapon(void) const
{
	return (this->_weapon);
}

void	HumanA::setWeapon(Weapon const & weapon)
{
	this->_weapon = weapon;
}
