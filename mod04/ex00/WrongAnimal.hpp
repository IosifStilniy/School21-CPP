#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	std::string	type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal();

	WrongAnimal &	operator=(WrongAnimal const & rhd);

	std::string const &	getType(void)	const;
	void				makeSound(void)	const;
};

#endif