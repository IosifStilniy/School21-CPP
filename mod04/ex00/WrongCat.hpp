#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const & src);
	~WrongCat();

	WrongCat &	operator=(WrongCat const & rhd);

	void	makeSound(void)	const;
};

#endif