#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>
# include <algorithm>
# include <utility>

class Span
{
	private:
		unsigned int		_max_size;
		std::list<int>*		_elems;

	public:
		Span(void);
		Span(Span const & src);
		Span(unsigned int max_size);

		template<class iterator>
		Span(iterator first, iterator last) : _elems(new std::list<int>(first, last))
		{
			this->_max_size = this->_elems->size();
		};

		~Span();

		Span &	operator=(Span const & rhd);

		void			addNumber(int num);

		template<class iterator>
		void			addNumber(iterator first, iterator last)
		{
			if (std::distance(first, last) > this->_max_size)
				throw ReachedMaxSizeException();
			
			std::copy(first, last, this->_elems->begin());
		};
		
		unsigned int	shortestSpan(void)	const;
		unsigned int	longestSpan(void)	const;

		class ReachedMaxSizeException : public std::exception
		{
			public:
				const char*	what()	const	throw();
		};

		class SmallSizeException : public std::exception
		{
			public:
				const char*	what()	const	throw();
		};
};

#endif
