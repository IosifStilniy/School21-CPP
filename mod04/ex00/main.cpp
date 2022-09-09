#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Animal* 			meta = new Animal();
	const Animal* 			j = new Dog();
	const Animal* 			i = new Cat();
	const WrongAnimal*		wrongcat = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrongcat->makeSound();

	delete meta;
	delete i;
	delete j;
	delete wrongcat;
	return 0;
}