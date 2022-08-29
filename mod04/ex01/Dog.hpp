#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain;

	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog();

		Dog &	operator=(Dog const & rhd);

		void	makeSound(void)	const;
		Brain &	getBrain(void);
};

#endif