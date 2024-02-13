/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:41 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 10:41:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor" << std::endl;
	delete this->_brain;
}

Dog::Dog( const Dog& obj ): Animal() {
	std::cout << "Dog copy constructor" << std::endl;
	*this = obj;
}

Dog& Dog::operator=( const Dog& rhs ) {
	std::cout << "Dog assignment operator" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain();
	*(this->_brain) = *(rhs._brain);
	return (*this);
}

void Dog::makeSound( void ) const {
	std::cout << "WOOF WOOF!" << std::endl;
}

Brain* Dog::getBrain( void ) const {
	return (this->_brain);
}
