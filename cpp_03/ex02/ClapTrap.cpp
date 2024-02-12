/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:45:25 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap [default] created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ):
	_name(name),
	_health(10),
	_energy(10),
	_attack_damage(0) {
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& obj ) {
	this->_name = obj._name;
	this->_health = obj._health;
	this->_energy = obj._energy;
	this->_attack_damage = obj._attack_damage;
	std::cout << "ClapTrap " << this->_name << " created by copy" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs ) {
	std::cout << "ClapTrap " << this->_name <<  " reassigned, now is called: " << rhs._name << std::endl;
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void ClapTrap::attack( const std::string& target ) {
	if (this->_health <= 0) {
		std::cout << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_name << " tries to attack " << target;
	if (this->_energy > 0) {
		std::cout << "...and causes " << this->_attack_damage << " points of damage!";
		this->_energy -= 1;
	}
	else
		std::cout << "...but has no energy left!";
	std::cout << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_health <= 0) {
		std::cout << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_name << " tries to repair itself...";
	if (this->_energy > 0) {
		std::cout << "and its health is restored by " << amount << " points!";
		this->_energy -= 1;
		this->_health += amount;
	}
	else
		std::cout << "but has no energy left!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_health <= 0) {
		std::cout << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_name << " took a damage of " << amount << "...";
	this->_health -= amount;
	if (this->_energy <= 0) {
		std::cout << "and dies!";
	}
	std::cout << std::endl;
}
