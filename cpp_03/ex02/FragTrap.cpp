/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 12:45:57 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
FragTrap::FragTrap( void ): ClapTrap() {
	std::cout << "FragTrap [default] created" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	std::cout << "FragTrap " << this->name_ << " created" << std::endl;
	this->health_ = 100;
	this->energy_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << this->name_ << " destroyed" << std::endl;
}

FragTrap::FragTrap( const FragTrap& obj ): ClapTrap( obj ) {
	this->name_ = obj.name_;
	this->energy_ = obj.energy_;
	this->health_ = obj.health_;
	this->attack_damage_ = obj.attack_damage_;
	std::cout << "FragTrap " << this->name_ << " created by copy" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& rhs ) {
	std::cout << "FragTrap " << this->name_ << " reassigned, now is called: " << rhs.name_ << std::endl;
	this->name_ = rhs.name_;
	this->energy_ = rhs.energy_;
	this->health_ = rhs.health_;
	this->attack_damage_ = rhs.attack_damage_;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
void FragTrap::attack( const std::string& target ) {
	std::cout << "(FragTrap overrides base method) ";
	this->ClapTrap::attack(target);
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name_ << " recieved you high five request!" << std::endl;
}
