#include "Converter.hpp"
#include <iostream>

Converter::Converter(void) : _handled(false)
{
	for (int i = 0; i < 4; i++)
		_possibility[i] = false;
}

Converter::Converter(Converter const & src)
{
	*this = src;
}

Converter::~Converter()
{
}

Converter &	Converter::operator=(Converter const & rhd)
{
	this->_str = rhd._str;
	this->_handled = rhd._handled;
	for (int i = 0; i < 4; i++)
		this->_possibility[i] = rhd._possibility[i];
}

bool	Converter::_checkForFloat(bool & isNan, bool & isFloat)	const
{
	if (this->_str.length() == 1)
		return (false);
	if (!this->_str.compare("nan"))
		return (isNan = true);
	if (!this->_str.compare("nanf"))
		return ((isNan = true) && (isFloat = true));
	if (this->_str.find('f') != std::string::npos)
		return (isFloat = true);
	if (this->_str.find('.') != std::string::npos)
		return (true);
}

void	Converter::_print(void)	const
{
	std::cout << "char: ";
	if (this->_possibility[0])
	{
		if (this->_c > 32 && this->_c != 127)
			std::cout << this->_c;
		else
			std::cout << "not displayable";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl << "int: ";
	if (this->_possibility[1])
		std::cout << this->_i;
	else
		std::cout << "impossible";
	std::cout << std::endl << "float: ";
}

void	Converter::handleIt(std::string const & str)
{
	bool	isNan = false;
	bool	isFloat = false;

	this->_str = str;

	if (this->_checkForFloat(isNan, isFloat))
		this->_handleFloat(isNan, isFloat);
	
	this->_print();
}
