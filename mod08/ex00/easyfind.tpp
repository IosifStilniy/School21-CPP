template<typename T>
int &	easyfind(T & container, int ref)
{
	for (typename T::iterator start = container.begin(); start != container.end(); start++)
		if (*start == ref)
			return (*start);
	throw std::exception();
}
