#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currnum = 0;
	this->overall = 0;
}

PhoneBook::~PhoneBook(void)
{
}

static bool	addparam(std::string *param, std::string prompt)
{
	if (std::cin.eof())
		return (std::cin.eof());
	std::cout << prompt;
	getline(std::cin, *param);
	return (std::cin.eof());
}

void	PhoneBook::add(void)
{
	bool	eof;

	eof = false;
	eof += addparam(&this->contacts[this->currnum].firstname, "First name: ");
	eof += addparam(&this->contacts[this->currnum].lastname, "Last name: ");
	eof += addparam(&this->contacts[this->currnum].nickname, "Nickname: ");
	eof += addparam(&this->contacts[this->currnum].phone, "Phone number: ");
	eof += addparam(&this->contacts[this->currnum].deepdarkfantasy, "Deep♂dark♂fantasy: ");
	if (eof)
		return ;
	this->currnum = ++this->currnum % 8;
	this->overall += (this->overall < 8);
}

static void	truncedtxt(std::string txt)
{
	std::cout << std::setw(11);
	if (txt.length() > 10)
		std::cout << txt.substr(0, 9) + ".|";
	else
		std::cout << txt + "|";
}

void	PhoneBook::_headerprinter(void)
{
	std::cout.setf(std::ios_base::right);
	std::cout << std::setw(11);
	std::cout << "Index|";
	std::cout << std::setw(11);
	std::cout << "First Name|";
	std::cout << std::setw(11);
	std::cout << "Last Name|";
	std::cout << std::setw(11);
	std::cout << "Nickname|" << std::endl;
	std::cout << std::setw(44);
	std::cout.fill('-');
	std::cout << "" << std::endl;
	std::cout.fill(' ');
	for (int i = 0; i < this->overall; i++)
	{
		std::cout << std::setw(10);
		std::cout << i + 1 << "|";
		truncedtxt(this->contacts[i].firstname);
		truncedtxt(this->contacts[i].lastname);
		truncedtxt(this->contacts[i].nickname);
		std::cout << std::endl;
	}
}

void	PhoneBook::search(void)
{
	int			indx;
	std::string	buf;

	_headerprinter();
	if (!this->overall)
	{
		std::cout << "Nobody's live in your PhoneBook, my dear... Try to ADD somebody!" << std::endl;
		return ;
	}
	std::cout << "Enter his index, boy: ";
	getline(std::cin, buf);
	indx = atoi(buf.c_str());
	if (!(1 <= indx && indx <= this->overall))
	{
		std::cout << "Am i joke for you?" << std::endl;
		return ;
	}
	std::cout << "First Name: " + this->contacts[--indx].firstname << std::endl;
	std::cout << "Last Name: " + this->contacts[indx].lastname << std::endl;
	std::cout << "Nickname: " + this->contacts[indx].nickname << std::endl;
	std::cout << "Phone number: " + this->contacts[indx].phone << std::endl;
	std::cout << "Deep♂dark♂fantasy: " + this->contacts[indx].deepdarkfantasy << std::endl;
}
