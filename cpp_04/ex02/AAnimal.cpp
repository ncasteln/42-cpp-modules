/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 10:42:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ): _type("Generic") {
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal::AAnimal( const AAnimal& obj ) {
	std::cout << "AAnimal copy constructor" << std::endl;
	this->_type = obj._type;
}

/*
	In this case the operator= works normally, bur there is an implicit
	contradiction, since the type is now is changed. The subject doesn't
	specify the behavior.
*/
AAnimal& AAnimal::operator=( const AAnimal& rhs ) {
	std::cout << "AAnimal assignment operator" << std::endl;
	try {
		if (this->_type != rhs._type)
			throw std::runtime_error(" you tried to reassign a " + this->_type + " to a " + rhs._type);
	}
	catch(const std::exception& e) {
		std::cerr << "[ WARNING ]" << e.what() << std::endl;
	}
	return (*this);
}

std::string AAnimal::getType( void ) const {
	return (this->_type);
}
