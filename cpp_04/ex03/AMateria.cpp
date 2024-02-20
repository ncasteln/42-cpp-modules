/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 09:24:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ------------------------------------------------------------------- CANONICAL
AMateria::AMateria( void ) {
	std::cout << "[AMateria] default constructor" << std::endl;
}

AMateria::~AMateria( void ) {
	std::cout << "[AMateria] destructor" << std::endl;
}

AMateria::AMateria( const AMateria& obj ) {
	std::cout << "[AMateria] copy constructor" << std::endl;
	this->_type = obj._type;
}

/*
	Since makes no sense to assign an Ice type to a Cure type, the assigment
	operator of AMateria should do nothing, but because of the subject rules
	it has to be written.
	A part of doing nothing, I wanted to avoid that someone call the assignment
	operator by mistake. The solution on std98 could be:
	• Make the mem function as private.
	• Use try-catch statement, without exiting the program, but warning the
	developer on what it is doing.
*/
AMateria& AMateria::operator=( const AMateria& rhs ) {
	std::cout << "[AMateria] assign operator" << std::endl;
	if (this->_type != rhs._type)
		std::cerr << "[ WARNING ] you're trying to reassign a " << this->_type + " to a " + rhs._type + " (reassignment NOT performed)" << std::endl;
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
AMateria::AMateria( std::string const& type ): _type(type) {
	std::cout << "[AMateria] [std::string const&] constructor" << std::endl;
}

// -------------------------------------------------------------- MEM FUNCTIONS
std::string const& AMateria::getType( void ) const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	if (this->_type == "ice")
		std::cout << "* shots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		std::cout << "* doesn't own anything in this slot * " << std::endl;
}
