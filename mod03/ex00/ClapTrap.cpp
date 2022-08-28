#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("Sudden Boyyyy"), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "Parametric constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhd)
{
	this->_name = rhd._name;
	this->_dmg = rhd._dmg;
	this->_energy = rhd._energy;
	this->_hp = rhd._hp;

	return (*this);
}

std::string const &	ClapTrap::getName(void)	const
{
	return (this->_name);
}

void	ClapTrap::setDamage(unsigned int dmg)
{
	this->_dmg = dmg;
}

unsigned int	ClapTrap::getDamage(void)	const
{
	return (this->_dmg);
}

bool	ClapTrap::_energyCheck(void)	const
{
	if (this->_energy)
		return (false);
	std::cout << "ClapTrap " << this->_name << " is tired and can't do anything..." << std::endl;
	return (true);
}

bool	ClapTrap::_isAlive(void)		const
{
	if (this->_hp)
		return (false);
	std::cout << "ClapTrap " << this->_name << " is died and can't do anything anymore..." << std::endl;
	return (true);
}

void	ClapTrap::attack(const std::string & target)
{
	if (this->_isAlive() || this->_energyCheck())
		return ;

	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " with " << this->_dmg << " damage!"
			 << " ClapTrap lose 1 energy, " << this->_energy << " left..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hp)
	{
		std::cout << "ClapTrap " << this->_name << " already dead..." << std::endl;
		return ;
	}

	if (this->_hp < amount)
		this->_hp = 0;
	else
		this->_hp -= amount;
	
	std::cout << "ClapTrap " << this->_name << " get " << amount << " of damage!";
	if (this->_hp)
		std::cout << " " << this->_hp << " HP left...";
	else
		std::cout << " ClapTrap " << this->_name << " died! Rest in peace, my boy...";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_isAlive() || this->_energyCheck())
		return ;
	
	this->_energy--;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " repairs himself " << amount << " HP!"
			<< " Now " << this->_name << " have " << this->_hp << " HP!"
			<< " ClapTrap " << this->_name << " lose 1 energy, " << this->_energy << " left..." << std::endl;
}
