#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#include <list>

int main()
{
	IMateriaSource* 	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	AMateria*	floor[2];

	tmp = src->createMateria("ice");
	me->equip(tmp);
	floor[0] = tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	floor[1] = tmp;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	delete floor[0];
	delete floor[1];
	delete bob;
	delete me;
	delete src;
	return 0;
}