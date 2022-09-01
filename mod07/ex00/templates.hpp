#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <typename T>
bool	checkOperators(T const & a, T const & b)
{
	try
	{
		(void)(a < b);
		(void)(a > b);
		(void)(a <= b);
		(void)(a >= b);
		(void)(a == b);
		(void)(a != b);
	}
	catch(const std::exception& e)
	{
		return (false);
	}

	return (true);
}

template <typename T>
void	swap(T & a, T & b)
{
	T	buf;

	try
	{
		checkOperators(a ,b);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	
	buf = a;
	a = b;
	b = buf;
}

template <typename T>
T const &	min(T const & a, T const & b)
{
	try
	{
		checkOperators(a ,b);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return (a < b ? a : b);
}

template <typename T>
T const &	max(T const & a, T const & b)
{
	try
	{
		checkOperators(a ,b);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return (a > b ? a : b);
}

#endif
