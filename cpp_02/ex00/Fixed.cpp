/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:40:37 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->fpn_ = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
	The same copy constructor can be achieved via different syntax like:
	• this->fpn_ = obj.getRawBits();
	• this->operator=(obj);
	• *this = obj;
*/
Fixed::Fixed( const Fixed& obj ) {
	std::cout << "Copy constructor called" << std::endl;
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

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpn_);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fpn_ = raw;
}
