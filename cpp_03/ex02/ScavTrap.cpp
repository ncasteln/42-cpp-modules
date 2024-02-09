/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 14:05:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
ScavTrap::ScavTrap( void ): ClapTrap() {
	std::cout << "ScavTrap [without a name] created" << std::endl;
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
	std::cout << "ScavTrap " << this->name_ << " created" << std::endl;
	this->health_ = 100;
	this->energy_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->name_ << " destroyed" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& obj ) {
	std::cout << "ScavTrap " << this->name_ << " created by copy" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs ) {
	std::cout << "ScavTrap " << this->name_ << " reassigned" << std::endl;
	this->name_ = rhs.name_;
	this->energy_ = rhs.energy_;
	this->health_ = rhs.health_;
	this->attack_damage_ = rhs.attack_damage_;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void ScavTrap::attack( const std::string& target ) {
	std::cout << "(ScavTrap) ";
	this->ClapTrap::attack(target);
}

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->name_ << " is now in keeper mode" << std::endl;
}
