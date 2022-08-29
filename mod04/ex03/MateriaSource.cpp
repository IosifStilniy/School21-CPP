#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->srcs[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->srcs[i])
			delete this->srcs[i];
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	int	i;

	for (i = 0; i < 4; i++)
		if (!this->srcs[i])
			break ;
	
	if (this->srcs[i])
		return ;
	
	this->srcs[i] = materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i;

	for (i = 0; i < 4; i++)
		if (this->srcs[i] && !this->srcs[i]->getType().compare(type))
			return (this->srcs[i]->clone());
	
	return (nullptr);
}
