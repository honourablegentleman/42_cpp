/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:10 by jhoddy            #+#    #+#             */
/*   Updated: 2024/11/06 15:17:13 by jhoddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	tm		*ltm = localtime(&now);
	char	buf[20];

	strftime(buf, 20, "%Y%m%d_%H%M%S", ltm);
	std::cout << "[" << buf << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:"
		<< getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() - deposit
		<< ";deposit:" << deposit << ";amount:" << checkAmount()
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
		<< checkAmount() << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
			<< checkAmount() + withdrawal << ";withdrawal:"
			<< withdrawal << ";amount:" << checkAmount()
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits << ";withdrawals:"
		<< _nbWithdrawals << std::endl;
}
