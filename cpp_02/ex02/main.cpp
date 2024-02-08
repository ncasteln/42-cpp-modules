/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/07 12:17:55 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* nt main( void ) {
	Fixed	a(42.42f);
	Fixed	b(10);

	std::cout << std::endl << "[ BASIC MATH ]" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "(a + b) = " << a + b << std::endl;
	std::cout << "(a - b) = " << a - b << std::endl;
	std::cout << "(a * b) = " << a * b << std::endl;
	std::cout << "(a / b) = " << a / b << std::endl;
	std::cout << "(a / b) + (a / b) = " << (a / b) + (a / b) << std::endl;

	std::cout << std::endl << "[ COMPAIRSON ]" << std::endl;
	std::cout << "a > b = ";
	if (a > b)
		std::cout << "[true]" << std::endl;
	else
		std::cout << "[false]" << std::endl;
	std::cout << "a == b = ";
	if (a == b)
		std::cout << "[true]" << std::endl;
	else
		std::cout << "[false]" << std::endl;
	std::cout << "a != b = ";
	if (a != b)
		std::cout << "[true]" << std::endl;
	else
		std::cout << "[false]" << std::endl;
	std::cout << "a == a = ";
	if (a == a)
		std::cout << "[true]" << std::endl;
	else
		std::cout << "[false]" << std::endl;


	std::cout << std::endl << "[ INCR / DECR ]" << std::endl;
	Fixed	tmp( a );
	++a;
	std::cout << "PRE Increment by -> " << (a - tmp) << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "PRE Decrement" << std::endl;
	std::cout << "a = " << --a << std::endl;
	std::cout << "a = " << --a << std::endl;
	std::cout << "a = " << --a << std::endl;
	std::cout << "a = " << --a << std::endl;
	std::cout << "POST Increment" << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "POST Decrement" << std::endl;
	std::cout << "a = " << a-- << std::endl;
	std::cout << "a = " << a-- << std::endl;
	std::cout << "a = " << a-- << std::endl;
	std::cout << "a = " << a-- << std::endl;
	std::cout << "a = " << a-- << std::endl;
	return (0);
} */

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
