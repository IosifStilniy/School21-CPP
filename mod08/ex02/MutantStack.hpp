#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T, typename Sequence = std::deque<T> >
class MutantStack : public std::stack<T, Sequence>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const & src);
		~MutantStack();
	
		MutantStack &	operator=(MutantStack const & rhd);

		typedef	typename	std::stack<T>::container_type::iterator					iterator;
		typedef	typename	std::stack<T>::container_type::const_iterator			const_iterator;
		typedef	typename	std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef	typename	std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		iterator				end(void);
		const_iterator			begin(void)		const;
		const_iterator			end(void)		const;
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rbegin(void)	const;
		const_reverse_iterator	rend(void)		const;
};

# include "MutantStack.tpp"

#endif
