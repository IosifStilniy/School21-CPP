#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;

	public:
		Character(void);
		Character(Character const & src);
		Character(std::string const & name);
		~Character();

		Character &	operator=(Character const & rhd);

		std::string const &	getName(void)	const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);

		AMateria*	slots[4];
};

#endif
