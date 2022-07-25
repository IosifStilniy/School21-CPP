#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	prompt;

	while (1)
	{
		if (!prompt.compare("EXIT") || std::cin.eof())
			exit(0);
		std::cout << "Whisp on my ear, sweetie: ";
		getline(std::cin, prompt);
		if (!prompt.compare("EXIT") || std::cin.eof())
			exit(0);
		else if (!prompt.compare("ADD"))
			book.add();
		else if (!prompt.compare("SEARCH"))
			book.search();
		else
			std::cout << "I understand only ADD, SEARCH and EXIT commands, my dear." << std::endl;
	}
	return (0);
}
