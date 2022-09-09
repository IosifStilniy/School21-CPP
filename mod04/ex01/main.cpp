#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	Animal*	animals[10];
	Animal	a;
	Cat		cat;
	Cat		copycat;
	Dog		dog;
	Dog		copydog;

	a.makeSound();
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	animals[0]->makeSound();
	animals[5]->makeSound();

	for (int i = 0; i < 10; i++)
		delete animals[i];

	cat.getBrain().ideas[0] = "puk";
	copycat = cat;
	std::cout << copycat.getType() << std::endl;
	std::cout << copycat.getBrain().ideas[0] << std::endl;

	dog.getBrain().ideas[0] = "puk";
	copydog = dog;
	std::cout << copydog.getType() << std::endl;
	std::cout << copydog.getBrain().ideas[0] << std::endl;
	return 0;
}