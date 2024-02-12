/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:46:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
FragTrap::FragTrap( void ): ClapTrap() {
	std::cout << "FragTrap [default] created" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

FragTrap::FragTrap( const FragTrap& obj ): ClapTrap( obj ) {
	this->_name = obj._name;
	this->_energy = obj._energy;
	this->_health = obj._health;
	this->_attack_damage = obj._attack_damage;
	std::cout << "FragTrap " << this->_name << " created by copy" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& rhs ) {
	std::cout << "FragTrap " << this->_name << " reassigned, now is called: " << rhs._name << std::endl;
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_health = rhs._health;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void FragTrap::attack( const std::string& target ) {
	std::cout << "(FragTrap overrides base method) ";
	this->ClapTrap::attack(target);
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " recieved you high five request!" << std::endl;
}
