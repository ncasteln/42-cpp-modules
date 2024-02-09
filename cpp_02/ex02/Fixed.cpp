/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:47:44 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:44:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
Fixed::Fixed( void ) {
	this->fpn_ = 0;
}

Fixed::Fixed( const int n ) {
	this->fpn_ = n << Fixed::bits_;
}

Fixed::Fixed( const float n ) {
	this->fpn_ = roundf(n * (1 << Fixed::bits_));
}

Fixed::~Fixed() {}

Fixed::Fixed( const Fixed& obj ) {
	*this = obj;
}

Fixed& Fixed::operator=( const Fixed& rhs ) {
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

// -------------------------------------------------------------------- MATH OP
Fixed Fixed::operator+( const Fixed& rhs) {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-( const Fixed& rhs) {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*( const Fixed& rhs) {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/( const Fixed& rhs) {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// ----------------------------------------------------------------- COMPAIR OP
bool Fixed::operator>( const Fixed& rhs ) const {
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<( const Fixed& rhs ) const {
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=( const Fixed& rhs ) const {
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=( const Fixed& rhs ) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==( const Fixed& rhs ) const {
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=( const Fixed& rhs ) const {
	return (this->toFloat() != rhs.toFloat());
}

// --------------------------------------------------------- PRE INCR / DECR OP
Fixed& Fixed::operator++( void ) {
	this->fpn_ += 1;
	return (*this);
}

Fixed& Fixed::operator--( void ) {
	this->fpn_ -= 1;
	return (*this);
}

// -------------------------------------------------------- POST INCR / DECR OP
Fixed Fixed::operator++( int ) {
	Fixed tmp = *this;
	this->operator++();
	return (tmp);
}

Fixed Fixed::operator--( int ) {
	Fixed tmp = *this;
	this->operator--();
	return (tmp);
}

// ------------------------------------------------------------------ MIN / MAX
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
