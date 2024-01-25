/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:38 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/25 18:36:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
	this->setLvl();
	this->setFptr();
}

Harl::~Harl() {}

std::string Harl::getLvl( int i ) {
	return (this->lvl[i]);
}

void Harl::setLvl( void ) {
	this->lvl[0] = "DEBUG";
	this->lvl[1] = "INFO";
	this->lvl[2] = "WARNING";
	this->lvl[3] = "ERROR";
}

void Harl::setFptr( void ) {
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	int	i;

	i = 0;
	while (i < 4) {
		if (level.compare(this->lvl[i]) == 0)
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
}
