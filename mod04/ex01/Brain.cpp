#include "Brain.hpp"

Brain::Brain(Brain const & src)
{
	*this = src;
}

Brain::Brain(void)
{
}

Brain::~Brain()
{
}

Brain &	Brain::operator=(Brain const & rhd)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhd.ideas[i];
	return (*this);
}