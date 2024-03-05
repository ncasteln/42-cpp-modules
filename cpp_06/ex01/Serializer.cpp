/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 10:39:33 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer& ) {
	// implement
}

Serializer& Serializer::operator=( Serializer& rhs) {
	// implement
}

// -------------------------------------------------------------- SERIALIZATION
uintptr_t Serializer::serialize(Data* ptr) {

}

Data* Serializer::deserialize(uintptr_t raw) {

}
