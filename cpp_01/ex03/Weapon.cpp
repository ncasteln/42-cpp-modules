/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:48:36 by nico              #+#    #+#             */
/*   Updated: 2024/01/25 17:54:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon( std::string newType ) {
	this->setType(newType);
}

Weapon::~Weapon( void ) {}

void Weapon::setType( std::string newType ) {
	this->type_ = newType;
}

const std::string& Weapon::getType( void ) const {
	const std::string&	ref = this->type_;
	return (ref);
}
