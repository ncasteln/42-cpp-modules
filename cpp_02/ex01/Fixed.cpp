/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/08 09:30:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->fpn_ = 0;
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called" << std::endl;
	this->fpn_ = n << Fixed::bits_;
}

Fixed::Fixed( const float n ) {
	std::cout << "Float constructor called" << std::endl;
	this->fpn_ = roundf(n * (1 << Fixed::bits_));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& obj ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=( const Fixed& rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fpn_ = rhs.getRawBits();
	return (*this);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
int Fixed::getRawBits( void ) const {
	return (this->fpn_);
}

void Fixed::setRawBits( int const n ) {
	this->fpn_ = n << Fixed::bits_;
}

float Fixed::toFloat( void ) const {
	return (((float)this->fpn_) / (1 << Fixed::bits_));
}

int Fixed::toInt( void ) const {
	return (this->fpn_ >> Fixed::bits_);
}

// --------------------------------------------------------- EXTERNAL FUNCTIONS
std::ostream& operator<<( std::ostream& cout, const Fixed& obj ) {
	cout << obj.toFloat();
	return (cout);
}
