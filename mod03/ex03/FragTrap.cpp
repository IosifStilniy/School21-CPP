#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;

	this->_name = "Fraggy";
	this->_hp = 100;
	this->_energy = 100;
	this->_dmg = 30;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;

	*this = src;
}

FragTrap::FragTrap(std::string const & name)
{
	std::cout << "FragTrap parametric constructor called" << std::endl;

	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhd)
{
	this->_name = rhd._name;
	this->_energy = rhd._energy;
	this->_hp = rhd._hp;
	this->_dmg = rhd._dmg;

	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " request hive fives... Give it to him!" << std::endl;
}

void	FragTrap::attack(const std::string & target)
{
	if (this->_isAlive() || this->_energyCheck())
		return ;

	this->_energy--;
	std::cout << "FragTrap " << this->_name << " attacks " << target << " with " << this->_dmg << " damage!"
			 << " FragTrap lose 1 energy, " << this->_energy << " left..." << std::endl;
}
