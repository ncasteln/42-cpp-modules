/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:48:18 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 12:11:18 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

/* CONST/DEST */
Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	Account::_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created" << std::endl;
}
Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
}



/* INSTANCE METHODS */
void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
};

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	std::cout << "withdrawal:";

	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this-> _nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
};

int		Account::checkAmount( void ) const {
	return (this->_amount);
};

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};



/* STATICS */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	// time_t		current_time = time(nullptr);
	// struct tm	*t = localtime(&current_time);

	// std::cout << "["
	// 	<< t->tm_year + 1900
	// 	<< std::setw(2) << std::setfill('0') << t->tm_mon + 1
	// 	<< std::setw(2) << std::setfill('0') << t->tm_mday
	// 	<< "_"
	// 	<< std::setw(2) << std::setfill('0') << t->tm_hour
	// 	<< std::setw(2) << std::setfill('0') << t->tm_min
	// 	<< std::setw(2) << std::setfill('0') << t->tm_sec
	// 	<< "] ";
}
int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}
