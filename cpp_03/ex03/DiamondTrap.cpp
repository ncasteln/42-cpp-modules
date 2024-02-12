/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:37:38 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
DiamondTrap::DiamondTrap( void ):
		ClapTrap(),
		ScavTrap(),
		FragTrap() {
	std::cout << "DiamondTrap [default] created" << std::endl;
}

/*
	this->name_ and FragTrap::name_ and ScavTrap::name_ are the same thing,
	and any change on one of them is reflected to the others.
	To better understand the concept, name_ is set inside both Scav and Frag
	just to evidence their creation. Then, in this method name_ is set to
	what the subject asks.
*/
DiamondTrap::DiamondTrap( std::string name ):
		ClapTrap(name + "_clap_name"),
		ScavTrap(name),
		FragTrap(name) {
	this->ScavTrap::name_ = name + "_clap_name";
	this->name_ = name;
	this->energy_ = ScavTrap("").getEnergy();
	std::cout << "DiamondTrap " << this->name_ << " created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << this->name_ << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& obj ):
		ClapTrap( obj ),
		ScavTrap( obj ),
		FragTrap( obj ) {
	this->name_ = obj.name_;
	this->health_ = obj.health_;
	this->energy_ = obj.energy_;
	this->attack_damage_ = obj.attack_damage_;
	std::cout << "DiamondTrap " << this->name_ << " created by copy" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
	std::cout << "DiamondTrap " << this->name_ << " reassigned, now is called: " << rhs.name_ << std::endl;
	this->name_ = rhs.name_;
	this->health_ = rhs.health_;
	this->energy_ = rhs.energy_;
	this->attack_damage_ = rhs.attack_damage_;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
/*
	Compiler throws error if the ambiguity of inheritance is not resolved. So
	the DiamondTrap, doesn't know whoAmI()!
*/
void DiamondTrap::whoAmI( void ) {
	std::cout << "My [DiamondTrap name] is " << this->name_ << std::endl;
	std::cout << "My [ClapTrap name] is " << this->ClapTrap::name_ << std::endl;
}

void DiamondTrap::getStatus( void ) {
	std::cout << "DiamondTrap [" << this->name_ << "] status:" << std::endl;
	std::cout << "ClapTrap::name_ [" << this->ClapTrap::name_ << "]" << std::endl;
	std::cout << "FragTrap::name_ [" << this->FragTrap::name_ << "]" << std::endl;
	std::cout << "ScavTrap::name_ [" << this->ScavTrap::name_ << "]" << std::endl;
	std::cout << "Health: " << this->health_ << std::endl;
	std::cout << "Energy: " << this->energy_ << std::endl;
	std::cout << "Attack: " << this->attack_damage_ << std::endl;
}
