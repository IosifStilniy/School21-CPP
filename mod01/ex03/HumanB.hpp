#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon*			_weapon;

	public:
		HumanB(std::string const & name);
		~HumanB();

		void			setWeapon(Weapon & weapon);
		Weapon const *	getWeapon()	const;
		void			attack()	const;

		std::string		name;
};

#endif
