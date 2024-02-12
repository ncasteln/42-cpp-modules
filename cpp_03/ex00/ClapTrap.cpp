/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 12:44:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap [default] created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ):
	name_(name),
	health_(10),
	energy_(10),
	attack_damage_(0) {
	std::cout << "ClapTrap " << this->name_ << " created" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->name_ << " destroyed" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& obj ) {
	*this = obj;
	std::cout << "ClapTrap " << this->name_ << " created by copy" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs ) {
	std::cout << "ClapTrap " << this->name_ <<  " reassigned, now is called:" << rhs.name_ << std::endl;
	this->name_ = rhs.name_;
	this->health_ = rhs.health_;
	this->energy_ = rhs.energy_;
	this->attack_damage_ = rhs.attack_damage_;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void ClapTrap::attack( const std::string& target ) {
	if (this->health_ <= 0) {
		std::cout << this->name_ << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->name_ << " tries to attack " << target;
	if (this->energy_ > 0) {
		std::cout << "...and causes " << this->attack_damage_ << " points of damage!";
		this->energy_ -= 1;
	}
	else
		std::cout << "...but has no energy left!";
	std::cout << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->health_ <= 0) {
		std::cout << this->name_ << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->name_ << " tries to repair itself...";
	if (this->energy_ > 0) {
		std::cout << "and its health is restored by " << amount << " points!";
		this->energy_ -= 1;
		this->health_ += amount;
	}
	else
		std::cout << "but has no energy left!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->health_ <= 0) {
		std::cout << this->name_ << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->name_ << " took a damage of " << amount << "...";
	this->health_ -= amount;
	if (this->energy_ <= 0) {
		std::cout << "and dies!";
	}
	std::cout << std::endl;
}
