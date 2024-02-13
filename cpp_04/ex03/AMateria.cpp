/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 19:32:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ------------------------------------------------------------------- CANONICAL
AMateria::AMateria( void ) {
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor" << std::endl;
}

AMateria::AMateria( const AMateria& obj ) {
	std::cout << "AMateria copy constructor" << std::endl;
	this->_type = obj._type;
}

AMateria& AMateria::operator=( const AMateria& rhs ) {
	std::cout << "AMateria assign operator" << std::endl;
	// implement like i = c (ice = cure no meaning) --- leave empty?
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
AMateria::AMateria( std::string const& type ): _type(type) {
	std::cout << "AMateria [std::string const&] constructor" << std::endl;
}

// -------------------------------------------------------------- MEM FUNCTIONS
std::string const& AMateria::getType( void ) const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	if (this->_type == "ice")
		std::cout << "* shots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		std::cout << "* doesn't own anything in this slot * " << std::endl;
}
