#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;

	this->_name = "Dia";
	this->ClapTrap::_name += "_clap_name";
	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;

	*this = src;
}

DiamondTrap::DiamondTrap(std::string const & name)
{
	std::cout << "DiamondTrap parametric constructor called" << std::endl;

	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhd)
{
	this->_name = rhd._name;
	this->ClapTrap::_name = rhd.ClapTrap::_name;
	this->_dmg = rhd._dmg;
	this->_energy = rhd._energy;
	this->_hp = rhd._hp;

	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->_name << "(" << this->ClapTrap::_name << "): What did you done to me, monster..." << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}
