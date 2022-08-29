#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		/* data */
	public:
		MateriaSource(void);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);

		AMateria*	srcs[4];
};

#endif