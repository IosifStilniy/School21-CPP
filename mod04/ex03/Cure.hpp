#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		/* data */
	public:
		Cure(void);
		Cure(Cure const & src);
		~Cure();

		Cure &	operator=(Cure const & rhd);

		AMateria*	clone(void)	const;
		void		use(ICharacter & target);
};

#endif