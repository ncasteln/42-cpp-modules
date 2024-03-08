/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:12:55 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 08:34:41 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.hpp"
#include "min.hpp"
#include "max.hpp"
#include <iostream>
#include <iomanip>
#include <string>

// int main ( void ) {
// 	////////// have to be the same type /////////
// 	// double d = 42.42;
// 	// float f = 1.2f;
// 	// ::swap(d, f);

// 	////////// double test //////////////////////
// 	// double d = 42.0;
// 	// double e = 99999.0;
// 	// ::swap(d,e);;
// 	// std::cout << std::fixed << "d = " << d << std::endl;
// 	// std::cout << std::fixed << "e = " << e << std::endl;

// 	////////// strings test //////////////////////
// 	// std::string s1 = "AAAAAA";
// 	// std::string s2 = "BBBBBB";
// 	// std::cout << "The smallest is: " << ::min(s1, s2) << std::endl;
// 	// std::cout << "The biggest is: " << ::max(s1, s2) << std::endl;
// 	return (0);
// }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
