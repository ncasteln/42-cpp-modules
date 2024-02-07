/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/07 09:17:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits_ = 8;

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
	this->fpn_ = roundf(n * 256);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& obj ) {
	std::cout << "Copy constructor called" << std::endl;
	// this->fpn_ = obj.getRawBits();
	// this->operator=(obj);
	*this = obj;
}

/*
	In case of a = b, in the method (this) refers to left operand (a), while
	the parameter taken is (b).
	The return value of the function, as in the function about operator<<,
	is needed only for chaining it with other oprands like a = b = c.
*/
void Fixed::operator=( const Fixed& obj ) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fpn_ = obj.getRawBits();
}

/* MEMBER FUNCTIONS */
int Fixed::getRawBits( void ) const {
	return (this->fpn_);
}

void Fixed::setRawBits( int const n ) {
	this->fpn_ = n << Fixed::bits_;
}

float Fixed::toFloat( void ) const {
	return (((float)this->fpn_) / 256);
}

int Fixed::toInt( void ) const {
	return (this->fpn_ >> 8);
}

/* EXTERNAL TO CLASS */
std::ostream& operator<<( std::ostream& cout, const Fixed& obj ) {
	cout << obj.toFloat();
	return (cout);
}
