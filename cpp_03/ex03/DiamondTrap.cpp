/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 14:47:34 by ncasteln         ###   ########.fr       */
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
	this->_name and FragTrap::_name and ScavTrap::_name are the same thing,
	and any change on one of them is reflected to the others.
	To better understand the concept, _name is set inside both Scav and Frag
	just to evidence their creation. Then, in this method _name is set to
	what the subject asks.
*/
DiamondTrap::DiamondTrap( std::string name ):
		ClapTrap(name + "_clap_name"),
		ScavTrap(name),
		FragTrap(name) {
	this->ScavTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_energy = ScavTrap("").getEnergy();
	std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& obj ):
		ClapTrap( obj ),
		ScavTrap( obj ),
		FragTrap( obj ) {
	this->_name = obj._name;
	this->_health = obj._health;
	this->_energy = obj._energy;
	this->_attack_damage = obj._attack_damage;
	std::cout << "DiamondTrap " << this->_name << " created by copy" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
	std::cout << "DiamondTrap " << this->_name << " reassigned, now is called: " << rhs._name << std::endl;
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

// ----------------------------------------------------------- PUBLIC FUNCTIONS
/*
	Compiler throws error if the ambiguity of inheritance is not resolved. So
	the DiamondTrap, doesn't know whoAmI()!
*/
void DiamondTrap::whoAmI( void ) {
	std::cout << "My [DiamondTrap name] is " << this->_name << std::endl;
	std::cout << "My [ClapTrap name] is " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::getStatus( void ) {
	std::cout << "DiamondTrap [" << this->_name << "] status:" << std::endl;
	std::cout << "ClapTrap::_name [" << this->ClapTrap::_name << "]" << std::endl;
	std::cout << "FragTrap::_name [" << this->FragTrap::_name << "]" << std::endl;
	std::cout << "ScavTrap::_name [" << this->ScavTrap::_name << "]" << std::endl;
	std::cout << "Health: " << this->_health << std::endl;
	std::cout << "Energy: " << this->_energy << std::endl;
	std::cout << "Attack: " << this->_attack_damage << std::endl;
}
