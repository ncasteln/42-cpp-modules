/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 16:43:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
DiamondTrap::DiamondTrap( void ): ClapTrap() {
	std::cout << "DiamondTrap [without a name] created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ):
		ClapTrap(name + "_clap_name"),
		ScavTrap("{ Lazy Value }"),
		FragTrap("{ Lazy Value }") {
	this->name_ = name;
	// this->health_ = FragTrap::health_;
	// this->energy_ = ScavTrap::energy_;
	// this->attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << this->name_ << " created" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << this->name_ << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& obj ) { // ??????????????????????????????????????????
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
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
	std::cout << "My [Diamond name] is " << this->name_ << std::endl;
	std::cout << "My [ClapTrap name] is " << this->ClapTrap::name_ << std::endl;
}
