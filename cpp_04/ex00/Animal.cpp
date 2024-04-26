/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/18 15:51:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ): _type("Generic") {
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal( const Animal& obj ) {
	std::cout << "Animal copy constructor" << std::endl;
	this->_type = obj._type;
}

Animal& Animal::operator=( const Animal& rhs ) {
	std::cout << "Animal assignment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Animal::makeSound( void ) const {
	std::cout << "RRRROOOOAAAAAR (super generic animal sound)" << std::endl;
}

std::string Animal::getType( void ) const {
	return (this->_type);
}
