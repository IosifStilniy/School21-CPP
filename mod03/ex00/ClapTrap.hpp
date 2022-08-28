#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_dmg;

		bool	_energyCheck(void)	const;
		bool	_isAlive(void)		const;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap & src);
		ClapTrap(std::string const & name);
		~ClapTrap();

		ClapTrap &	operator=(ClapTrap const & rhd);

		std::string const &	getName(void)	const;
		unsigned int		getDamage(void)	const;
		void				setDamage(unsigned int dmg);

		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};


#endif
