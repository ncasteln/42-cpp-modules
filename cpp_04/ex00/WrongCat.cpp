/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:23 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/12 16:00:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal() {
	std::cout << "WrongCat default constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat& obj ): WrongAnimal() {
	std::cout << "WrongCat copy constructor" << std::endl;
	this->_type = obj._type;
}

WrongCat& WrongCat::operator=( const WrongCat& rhs ) {
	std::cout << "WrongCat assignment operator" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound( void ) const {
	std::cout << "MEEEEEEEEEOW" << std::endl;
}
