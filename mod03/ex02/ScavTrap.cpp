#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;

	this->_name = "Scavy";
	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	*this = src;
}

ScavTrap::ScavTrap(std::string const & name)
{
	std::cout << "ScavTrap parametric constructor called" << std::endl;

	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_dmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhd)
{
	this->_name = rhd._name;
	this->_dmg = rhd._dmg;
	this->_hp = rhd._hp;
	this->_energy = rhd._energy;

	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->_isAlive())
		return ;
		
	std::cout << "ScavTrap " << this->_name << " now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string & target)
{
	if (this->_isAlive() || this->_energyCheck())
		return ;

	this->_energy--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " with " << this->_dmg << " damage!"
			 << " ScavTrap lose 1 energy, " << this->_energy << " left..." << std::endl;
}
