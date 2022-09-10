#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T = int>
class Array
{
	private:
		unsigned int	_size;
		T *				_elements;

	public:
		Array(void);
		Array(Array const & src);
		Array(unsigned int size);;
		~Array();

		Array &	operator=(Array const & rhd);
		T &		operator[](unsigned int n);

		unsigned int	size(void)	const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char*	what(void)	const	throw();
		};
};

# include "Array.tpp"

#endif
