/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/29 16:33:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->fpn_ = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& obj ) {
	std::cout << "Copy constructor called" << std::endl;
	this->fpn_ = obj.getRawBits();
}

Fixed& Fixed::operator=( const Fixed& obj ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fpn_ = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpn_);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fpn_ = raw;
}
