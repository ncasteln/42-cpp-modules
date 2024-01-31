/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/31 15:56:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	const Fixed		b( Fixed(42.424242f) + Fixed(1000) ); // Fixed / int / float
	const Fixed		c( Fixed(42.424242f) - Fixed(1000) );

	const Fixed		d( Fixed(42.424242f) * Fixed(10) );
	const Fixed		e( Fixed(42.424242f) / Fixed(10) );

	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	std::cout << Fixed::max( b, c ) << std::endl;

	return (0);
}
