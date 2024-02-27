/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 14:35:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// ------------------------------------------------------------------- CANONICAL
Ice::Ice( void ) {
	std::cout << "[Ice] default constructor" << std::endl;
	this->_type = "ice";
}

Ice::~Ice( void ) {
	std::cout << "[Ice] destructor" << std::endl;
}

Ice::Ice( const Ice& obj ): AMateria( obj ) {
	std::cout << "[Ice] copy constructor" << std::endl;
}

Ice& Ice::operator=( const Ice& rhs ) {
	std::cout << "[Ice] assign operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
AMateria* Ice::clone( void ) {
	std::cout << "[Ice] materia cloned, a new one is returned" << std::endl;
	return (new Ice());
}

// -------------------------------------------------------------- MEM FUNCTIONS
void Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
