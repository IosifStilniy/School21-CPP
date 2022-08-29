#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain;

	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat();

		Cat &	operator=(Cat const & rhd);

		void	makeSound(void)	const;
		Brain &	getBrain(void);
};

#endif