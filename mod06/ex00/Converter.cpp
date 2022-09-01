#include "Converter.hpp"
#include <iostream>
#include <limits>

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
	this->_c = rhd._c;
	this->_i = rhd._i;
	this->_f = rhd._f;
	this->_d = rhd._d;
	for (int i = 0; i < 4; i++)
		this->_possibility[i] = rhd._possibility[i];

	return (*this);
}

bool	Converter::_checkForFloat(bool & isNanOrInf, bool & isFloat)
{
	std::string		sign = "";
	std::size_t		i = 0;
	bool			dotWas = false;

	if (this->_str.length() == 1)
		return (false);

	this->_handled = true;

	if (this->_str[0] == '+' || this->_str[0] == '-')
		sign = std::string(1, this->_str[0]);

	if (!this->_str.compare(sign + "nan") || !this->_str.compare(sign + "nanf"))
	{
		isFloat = (!this->_str.compare(sign + "nanf"));
		return (isNanOrInf = true);
	}

	if (!this->_str.compare(sign + "inf") || !this->_str.compare(sign + "inff"))
	{
		isFloat = (!this->_str.compare(sign + "inff"));
		return (isNanOrInf = true);
	}

	if (!isdigit(this->_str[0]) && this->_str[0] != '+' && this->_str[0] != '-')
		return (this->_handled = false);

	for (; i < this->_str.length(); i++)
	{
		if (!isdigit(this->_str[i]) && this->_str[i] != '.')
			break ;
		if (dotWas && this->_str[i] == '.')
			return (this->_handled = false);
		if (!dotWas)
			dotWas = (this->_str[i] == '.');
	}

	if (dotWas || this->_str[i] == 'f')
		return ((isFloat = (this->_str[i] == 'f')) || true);

	return (this->_handled = false);
}

bool	Converter::_checkForInt(void)
{
	for (std::size_t i = (this->_str[0] == '+' || this->_str[0] == '-');
		i < this->_str.length(); i++)
		if (!isdigit(this->_str[i]))
			return (false);
	return (this->_handled = true);
}

bool	Converter::_checkForChar(void)
{
	if (this->_str.length() != 1)
		return (false);
	return (this->_handled = true);
}

void	Converter::_handleInt(void)
{
	try
	{
		this->_i = std::stoi(this->_str);
		this->_possibility[1] = true;
	}
	catch(const std::exception& e)
	{
		return ;
	}
	
	this->_f = static_cast<float>(this->_i);
	this->_possibility[2] = true;
	this->_d = static_cast<double>(this->_i);
	this->_possibility[3] = true;
	this->_c = static_cast<char>(this->_i);
	this->_possibility[0] = (std::numeric_limits<char>::min() <= this->_i && this->_i <= std::numeric_limits<char>::max());
}

void	Converter::_handleFloat(bool isNanOrInf, bool isFloat)
{
	if (isNanOrInf)
	{
		this->_possibility[2] = true;
		this->_possibility[3] = true;

		return ;
	}

	if (isFloat)
	{
		try
		{
			this->_f = std::stof(this->_str);
			this->_possibility[2] = true;
			this->_possibility[3] = true;
		}
		catch(const std::exception& e)
		{
			// std::cerr << e.what() << '\n';
			(void) e;
			return ;
		}
		
		this->_d = static_cast<double>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_c = static_cast<char>(this->_f);
	}
	else
	{
		try
		{
			this->_d = std::stod(this->_str);
			this->_possibility[3] = true;
		}
		catch(const std::exception& e)
		{
			// std::cerr << e.what() << '\n';
			(void) e;
			return ;
		}

		this->_possibility[2] = (std::numeric_limits<float>::min() < this->_d && this->_d < std::numeric_limits<float>::max());

		this->_f = static_cast<float>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_c = static_cast<char>(this->_d);
	}

	this->_possibility[1] = (INT32_MIN <= this->_f && this->_f <= INT32_MAX);
	this->_possibility[0] = (std::numeric_limits<char>::min() <= this->_f && this->_f <= std::numeric_limits<char>::max());
}

void	Converter::_handleChar(void)
{
	for (int i = 0; i < 4; i++)
		this->_possibility[i] = true;
	
	this->_c = this->_str[0];
	this->_i = static_cast<int>(this->_c);
	this->_f = static_cast<float>(this->_c);
	this->_d = static_cast<double>(this->_c);
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
	if (this->_possibility[2])
		std::cout << this->_f << "f";
	else
		std::cout << "impossible";
	std::cout << std::endl << "double: ";
	if (this->_possibility[3])
		std::cout << this->_d;
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

std::size_t	Converter::_skipSpaces(std::string const & str)	const
{
	for (std::size_t i = 0; i < str.length(); i++)
		if (!isspace(str[i]))
			return (i);
	return (str.length());
}

void	Converter::handleIt(std::string const & str)
{
	bool	isNanOrInf = false;
	bool	isFloat = false;

	this->_str = str;
	if (str.length() > 1)
		this->_str = str.substr(this->_skipSpaces(str));

	if (this->_checkForFloat(isNanOrInf, isFloat))
		this->_handleFloat(isNanOrInf, isFloat);
	if (!this->_handled && this->_checkForInt())
		this->_handleInt();
	if (!this->_handled && this->_checkForChar())
		this->_handleChar();
	this->_print();
}
