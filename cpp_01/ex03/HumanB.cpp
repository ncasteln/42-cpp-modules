/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:16:54 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 18:06:13 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ): name(name) {}

HumanB::HumanB( std::string name, Weapon& w ): w(&w), name(name) {}

HumanB::~HumanB( void ) {}

void HumanB::attack( void ) {
	std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& w ) {
	this->w = &w;
}
