/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:23 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 10:40:46 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal() {
	std::cout << "Cat default constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor" << std::endl;
	delete this->_brain;
}

Cat::Cat( const Cat& obj ): Animal() {
	std::cout << "Cat copy constructor" << std::endl;
	*this = obj;
}

/*
	*(this->_brain) = *(rhs._brain); make a deep copy, so that two cat would not
	share the same brain (wrong way to do it is this->_brain = rhs._brain;)
*/
Cat& Cat::operator=( const Cat& rhs ) {
	std::cout << "Cat assignment operator" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain();
	*(this->_brain) = *(rhs._brain);
	return (*this);
}

void Cat::makeSound( void ) const {
	std::cout << "MEEEEEEEEEOW" << std::endl;
}

Brain* Cat::getBrain( void ) const {
	return (this->_brain);
}
