#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const & name) : _weapon(nullptr), name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}

Weapon const *	HumanB::getWeapon()	const
{
	return (this->_weapon);
}

void	HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their ";
	if (!getWeapon())
		std::cout << "hands" << std::endl;
	else
		std::cout << getWeapon()->getType() << std::endl;
}
