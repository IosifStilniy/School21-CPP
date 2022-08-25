#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		void	_headerprinter(void);
		Contact	_contacts[8];
		int		_currnum;
		int		_overall;

	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif