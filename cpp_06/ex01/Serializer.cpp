/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 10:09:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( const Serializer& obj ) { (void)obj; }

void Serializer::operator=( Serializer& rhs) { (void)rhs; }

// -------------------------------------------------------------- SERIALIZATION
uintptr_t Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data* Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }
