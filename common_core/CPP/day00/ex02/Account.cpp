#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;

Account::Account()
{
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = getNbAccounts();
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
	Account::_nbAccounts++;
}
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = getNbAccounts();
	Account::_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";amount:"
	<< _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< p_amount << ";deposit:" << deposit << ";amount:"
	<< _amount << ";nb_deposits:" << _nbDeposits << std::endl; 
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
		<< _amount << ";withdrawal:refused" << std::endl; 
		return false;
	}
	int p_amount = _amount;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< p_amount << ";withdrawal:" << withdrawal << ";amount:"
	<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl; 
	return true;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }
int Account::checkAmount() const { return _amount; }

void Account::_displayTimestamp()
{
	std::time_t timestamp;
	time(&timestamp);
    std::cout << std::put_time(localtime(&timestamp), "[%Y%m%d_%H%M%S] ");
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:"
	<< getNbWithdrawals() << std::endl;
}

