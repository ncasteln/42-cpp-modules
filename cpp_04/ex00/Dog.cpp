/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:41 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 16:00:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog( const Dog& obj ): Animal() {
	std::cout << "Dog copy constructor" << std::endl;
	this->_type = obj._type;
}

Dog& Dog::operator=( const Dog& rhs ) {
	std::cout << "Dog assignment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound( void ) const {
	std::cout << "WOOF WOOF!" << std::endl;
}
