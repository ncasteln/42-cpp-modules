/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:23 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 16:00:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal() {
	std::cout << "Cat default constructor" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat( const Cat& obj ): Animal() {
	std::cout << "Cat copy constructor" << std::endl;
	this->_type = obj._type;
}

Cat& Cat::operator=( const Cat& rhs ) {
	std::cout << "Cat assignment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound( void ) const {
	std::cout << "MEEEEEEEEEOW" << std::endl;
}
