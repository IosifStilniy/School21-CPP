#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int init_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = init_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += init_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";acmount:" << init_deposit << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit
		<< ";amount:" << this->checkAmount() + deposit
		<< ";nb_deposits:" << ++this->_nbDeposits << std::endl;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal
		<< ";amount:" << this->checkAmount() - withdrawal
		<< ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void)	const
{
	return (this->_amount);
}

void	Account::displayStatus(void)	const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*date;

	time(&rawtime);
	date = gmtime(&rawtime);
	std::cout.fill('0');
	std::cout << "[" << date->tm_year + 1900
		<< std::setw(2) << date->tm_mon + 1
		<< std::setw(2) << date->tm_mday
		<< "_"
		<< std::setw(2) << date->tm_hour
		<< std::setw(2) << date->tm_min
		<< std::setw(2) << date->tm_sec << "] ";
}