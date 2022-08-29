#include "Character.hpp"

Character::Character(void) : _name("Bobby")
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::Character(Character const & src)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;

	*this = src;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
}

Character &	Character::operator=(Character const & rhd)
{
	this->_name = rhd._name;

	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
			delete this->slots[i];
		this->slots[i] = rhd.slots[i];
		if (rhd.slots[i])
			this->slots[i] = rhd.slots[i]->clone();
	}

	return (*this);
}

std::string const &	Character::getName(void)	const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	for (i = 0; i < 4; i++)
		if (!this->slots[i])
			break ;
	
	if (this->slots[i])
		return ;
	
	this->slots[i] = m;
}

void	Character::unequip(int idx)
{
	if (!(0 <= idx && idx <= 3) || !this->slots[idx])
		return ;

	this->slots[idx] = nullptr;
}

void	Character::use(int idx, ICharacter & target)
{
	if (!(0 <= idx && idx <= 3) || !this->slots[idx])
		return ;

	this->slots[idx]->use(target);
}
