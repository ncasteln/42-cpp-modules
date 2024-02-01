/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:31:01 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/01 15:57:06 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <stdio.h>
#include <iomanip>

int main (void) {
	const Fixed	a(0.11f);
	const Fixed b(0.11f + 0.11f + 0.11f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	const Fixed c(Fixed(0.2f) * Fixed(0.3f));
	std::cout << c.toFloat() << std::endl;

}

/* int main( void ) {
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
 */
