/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/31 15:58:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits_ = 8;

// ------------------------------------------------------------------------ OCC
Fixed::Fixed( void ) {
	this->fpn_ = 0;
}

Fixed::Fixed( const int n ) {
	this->fpn_ = n << Fixed::bits_;
}

Fixed::Fixed( const float n ) {
	this->fpn_ = roundf(n * 256.0f);
}

Fixed::~Fixed() {}

Fixed::Fixed( const Fixed& obj ) {
	*this = obj;
}

void Fixed::operator=( const Fixed& obj ) {
	this->fpn_ = obj.getRawBits();
}

// ------------------------------------------------------------------- OLD FUNC
int Fixed::getRawBits( void ) const {
	return (this->fpn_);
}

void Fixed::setRawBits( int const n ) {
	this->fpn_ = n << Fixed::bits_;
}

float Fixed::toFloat( void ) const {
	return (((float)this->fpn_) / 256.0f);
}

int Fixed::toInt( void ) const {
	return (this->fpn_ >> 8);
}

// ---------------------------------------------------------------- OVERLOADERS
/*
	The desired result is to implement an operator to sum multiple operands in
	a chain like (a + b + c). To do that, the (operator+) has to return the
	type from which is possible to newly re-call the (operator+).

	(a + b + c) --------> a.operator+(b).operator+(c)
*/
Fixed Fixed::operator+( Fixed obj ) {
	float a = this->toFloat();
	float b = obj.toFloat();
	return (Fixed(a + b));
}

Fixed Fixed::operator-( Fixed obj ) {
	float a = this->toFloat();
	float b = obj.toFloat();
	return (Fixed(a - b));
}

Fixed Fixed::operator*( Fixed obj ) {
	float a = this->toFloat();
	float b = obj.toFloat();
	return (Fixed(a * b));
}

Fixed Fixed::operator/( Fixed obj ) {
	float a = this->toFloat();
	float b = obj.toFloat();
	return (Fixed(a / b));
}

// ------------------------------------------------------ INCREMENT & DECREMENT
// void Fixed::operator++( void ) {
// 	this->fpn_ += 1;
// }

// void Fixed::operator--( void ) {
// 	this->fpn_ -= 1;
// }

// const Fixed& Fixed::operator++( int ) {
// 	Fixed	tmp(this->toFloat());
// 	this->operator++();
// 	return (tmp);
// }

// void Fixed::operator--( int post ) {
// 	// this->fpn_
// }

// ----------------------------------------------------------------- COMPAIRSON
bool Fixed::operator>( Fixed obj ) const {
	return (this->fpn_ > obj.fpn_);			/////////// first convert to float() ??????
}

bool Fixed::operator<( Fixed obj ) const {
	return (this->fpn_ < obj.fpn_);
}

bool Fixed::operator>=( Fixed obj ) const {
	return (this->fpn_ >= obj.fpn_);
}

bool Fixed::operator<=( Fixed obj ) const {
	return (this->fpn_ <= obj.fpn_);
}

bool Fixed::operator==( Fixed obj ) const {
	return (this->fpn_ == obj.fpn_);
}

bool Fixed::operator!=( Fixed obj ) const {
	return (this->fpn_ != obj.fpn_);
}

// ------------------------------------------------------------------ MIN & MAX
Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	if (a >= b)
		return (a);
	return (b);
}

// -------------------------------------------------------- EXTERNAL FROM CLASS
std::ostream& operator<<( std::ostream& cout, const Fixed& obj ) {
	cout << obj.toFloat();
	return (cout);
}
