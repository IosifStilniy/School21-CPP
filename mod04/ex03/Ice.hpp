#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		/* data */
	public:
		Ice(void);
		Ice(Ice const & src);
		~Ice();

		Ice &	operator=(Ice const & rhd);

		AMateria*	clone(void)	const;
		void		use(ICharacter & target);
};

#endif