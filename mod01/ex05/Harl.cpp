#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->_cmpl[0] = &Harl::_debug;
	this->_cmpl[1] = &Harl::_info;
	this->_cmpl[2] = &Harl::_warning;
	this->_cmpl[3] = &Harl::_error;

	Harl::_levels[0] = "DEBUG";
	Harl::_levels[1] = "INFO";
	Harl::_levels[2] = "WARNING";
	Harl::_levels[3] = "ERROR";
}

Harl::~Harl()
{
}

void	Harl::_debug(void)	const
{
	std::cout << "Tak, nu eto, tipa depuk poluchaetsya, aga" << std::endl;
}

void	Harl::_info(void)	const
{
	std::cout << "Nu, gde pivo to, epta. I semok hochu znatchitsya, da" << std::endl;
}

void	Harl::_warning(void)	const
{
	std::cout << "Che t ne to, pivasik konchaetsya i semok net uzhe" << std::endl;
}

void	Harl::_error(void)	const
{
	std::cout << "BILIAAAAAAAAAAAAAAAADDDD" << std::endl;
}

void	Harl::complain(std::string level)	const
{
	for (int i = 0; i < 4; i++)
		if (!level.compare(Harl::_levels[i]))
			(this->*(this->_cmpl[i]))();
}
