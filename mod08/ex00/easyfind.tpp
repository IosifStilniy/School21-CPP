template<typename T>
int &	easyfind(T & container, int ref)
{
	typename T::iterator	elem = std::find(container.begin(), container.end(), ref);
	if (elem != container.end())
		return (*elem);
	throw std::exception();
}
