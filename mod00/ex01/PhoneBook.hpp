#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		void	_headerprinter(void);

	public:
		Contact	contacts[8];
		int		currnum;
		int		overall;

		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif