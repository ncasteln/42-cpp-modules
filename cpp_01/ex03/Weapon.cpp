/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:48:36 by nico              #+#    #+#             */
/*   Updated: 2024/01/15 18:32:23 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) {
	this->setType(type);
}

Weapon::~Weapon( void ) {}

void Weapon::setType( std::string newType ) {
	this->type = newType;
}

std::string const& Weapon::getType( void ) const {
	return (this->type);
}
