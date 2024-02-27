/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 14:34:49 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// ------------------------------------------------------------------- CANONICAL
Cure::Cure( void ) {
	std::cout << "[Cure] default constructor" << std::endl;
	this->_type = "cure";
}

Cure::~Cure( void ) {
	std::cout << "[Cure] destructor" << std::endl;
}

Cure::Cure( const Cure& obj ): AMateria( obj ) {
	std::cout << "[Cure] copy constructor" << std::endl;
}

Cure& Cure::operator=( const Cure& rhs ) {
	std::cout << "[Cure] assign operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
AMateria* Cure::clone( void ) {
	std::cout << "[Cure] materia cloned, a new one is returned" << std::endl;
	return (new Cure());
}

// -------------------------------------------------------------- MEM FUNCTIONS
void Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
