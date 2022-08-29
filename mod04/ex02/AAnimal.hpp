#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	type;

	public:
		virtual ~AAnimal();

		std::string const &	getType(void)	const;
		virtual void	makeSound(void)		const = 0;
};

#endif