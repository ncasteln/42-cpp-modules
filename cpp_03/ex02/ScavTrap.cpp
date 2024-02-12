/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:46:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
ScavTrap::ScavTrap( void ): ClapTrap() {
	std::cout << "ScavTrap [default] created" << std::endl;
}

/*
	To make the 'child' class access to the members of the 'parent' one, it is
	possibile make the attributes protected instead of private.

	Another possibility is create getters and setters into the 'parents' and set
	them as public, so the 'child' cann access them.
	• this->ClapTrap::setHealth(100);
	• this->ClapTrap::setEnergy(50);
	• this->ClapTrap::setAttackDamage(20);
*/
ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
	this->_health = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& obj ): ClapTrap( obj ) {
	this->_name = obj._name;
	this->_energy = obj._energy;
	this->_health = obj._health;
	this->_attack_damage = obj._attack_damage;
	std::cout << "ScavTrap " << this->_name << " created by copy" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs ) {
	std::cout << "ScavTrap " << this->_name << " reassigned, now is called: " << rhs._name << std::endl;
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_health = rhs._health;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void ScavTrap::attack( const std::string& target ) {
	std::cout << "(ScavTrap overrides base method) ";
	this->ClapTrap::attack(target);
}

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " is now in keeper mode" << std::endl;
}
