template<typename T, typename S>
MutantStack<T, S>::MutantStack(void) : std::stack<T, S>()
{
}

template<typename T, typename S>
MutantStack<T, S>::MutantStack(MutantStack<T, S> const & src) : std::stack<T, S>(src)
{
}

template<typename T, typename S>
MutantStack<T, S>::~MutantStack()
{
}

template<typename T, typename S>
MutantStack<T, S> &	MutantStack<T, S>::operator=(MutantStack<T, S> const & rhd)
{
	this->c = rhd.c;
	return (*this);
}

template<typename T, typename S>
typename MutantStack<T, S>::iterator	MutantStack<T, S>::begin(void)
{
	return (this->c.begin());
}

template<typename T, typename S>
typename MutantStack<T, S>::iterator	MutantStack<T, S>::end(void)
{
	return (this->c.end());
}

template<typename T, typename S>
typename MutantStack<T, S>::const_iterator	MutantStack<T, S>::begin(void)		const
{
	return (this->c.begin());
}

template<typename T, typename S>
typename MutantStack<T, S>::const_iterator	MutantStack<T, S>::end(void)		const
{
	return (this->c.end());
}

template<typename T, typename S>
typename MutantStack<T, S>::reverse_iterator	MutantStack<T, S>::rbegin(void)
{
	return (this->c.rbegin());
}

template<typename T, typename S>
typename MutantStack<T, S>::reverse_iterator	MutantStack<T, S>::rend(void)
{
	return (this->c.rend());
}

template<typename T, typename S>
typename MutantStack<T, S>::const_reverse_iterator	MutantStack<T, S>::rbegin(void)	const
{
	return (this->c.rbegin());
}
template<typename T, typename S>
typename MutantStack<T, S>::const_reverse_iterator	MutantStack<T, S>::rend(void)		const
{
	return (this->c.rend());
}
