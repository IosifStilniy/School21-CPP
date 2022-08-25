#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&			_weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void			attack()	const;
		Weapon const &	getWeapon() const;
		void			setWeapon(Weapon const & weapon);
		std::string		name;
};

#endif