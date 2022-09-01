#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T * arr, unsigned int length, void (*func)(T &))
{
	for (unsigned int i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void	print(T & some)
{
	std::cout << some << std::endl;
}

#endif
