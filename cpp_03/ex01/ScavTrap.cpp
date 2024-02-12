/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 11:11:34 by ncasteln         ###   ########.fr       */
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
	std::cout << "ScavTrap " << this->name_ << " created" << std::endl;
	this->health_ = 100;
	this->energy_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->name_ << " destroyed" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& obj ): ClapTrap( obj ) {
	this->name_ = obj.name_;
	this->energy_ = obj.energy_;
	this->health_ = obj.health_;
	this->attack_damage_ = obj.attack_damage_;
	std::cout << "ScavTrap " << this->name_ << " created by copy" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rhs ) {
	this->name_ = rhs.name_;
	this->energy_ = rhs.energy_;
	this->health_ = rhs.health_;
	this->attack_damage_ = rhs.attack_damage_;
	std::cout << "ScavTrap " << this->name_ << " reassigned, now is called: " << rhs.name_ << std::endl;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void ScavTrap::attack( const std::string& target ) {
	std::cout << "(ScavTrap) ";
	this->ClapTrap::attack(target);
}

void ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode" << std::endl;
}
