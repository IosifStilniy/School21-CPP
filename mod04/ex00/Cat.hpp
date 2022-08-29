#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const & src);
	~Cat();

	Cat &	operator=(Cat const & rhd);

	void	makeSound(void)	const;
};

#endif