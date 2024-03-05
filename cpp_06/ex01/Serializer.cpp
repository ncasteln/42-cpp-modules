/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 14:57:14 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer& obj ) { (void)obj; }

void Serializer::operator=( Serializer& rhs) { (void)rhs; }

// -------------------------------------------------------------- SERIALIZATION
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
