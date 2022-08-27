#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:

		std::string	_name;

	public:

		Zombie();
		~Zombie();

		void	setName(std::string const & name);
		void	announce(void)						const;
};

#endif
