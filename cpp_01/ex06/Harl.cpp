/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:38 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/25 18:39:37 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	this->setLvl();
	this->setLogMessages();
}

Harl::~Harl() {}

void Harl::setLvl( void ) {
	this->lvl[0] = "DEBUG";
	this->lvl[1] = "INFO";
	this->lvl[2] = "WARNING";
	this->lvl[3] = "ERROR";
}

void Harl::setLogMessages( void ) {
	this->logs[0] = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" ;
	this->logs[1] = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" ;
	this->logs[2] = "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." ;
	this->logs[3] = "This is unacceptable! I want to speak to the manager now.";
	this->logs[4] = "[ Probably complaining about insignificant problems ]\n";
}

void Harl::log( int i ) {
	std::string	title[4] = { "[ DEBUG ]\n", "[ INFO ]\n", "[ WARNING ]\n", "[ ERROR ]\n" };

	while (i < 4) {
		std::cout << title[i] << this->logs[i] << std::endl << std::endl;
		i++;
	}
}

void Harl::complain( std::string level ) {
	int	i;

	i = 0;
	while (i < 4) {
		if (level.compare(this->lvl[i]) == 0)
			break ;
		i++;
	}
	switch (i) {
		case 0:
			this->log(i);
			break ;
		case 1:
			this->log(i);
			break ;
		case 2:
			this->log(i);
			break ;
		case 3:
			this->log(i);
			break ;
		default:
			std::cout << this->logs[4] << std::endl;
	}
}
