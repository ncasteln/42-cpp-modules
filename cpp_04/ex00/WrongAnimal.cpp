/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 15:59:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): _type("Generic") {
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& obj ) {
	std::cout << "WrongAnimal copy constructor" << std::endl;
	this->_type = obj._type;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs ) {
	std::cout << "WrongAnimal assignment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "RRRROOOOAAAAAR (super generic WrongAnimal sound)" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
	return (this->_type);
}
