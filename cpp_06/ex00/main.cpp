/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/04 17:32:32 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/*
	TO HANDLE:
	- Empty string
	- Modify stucture to take char and int together (cleaner)
	- handle specials
	- handle limits
	- unisgned char instead of char --?
*/

/*
	.f				OK
	****************************************
	0.f				OK
	0000.f			OK
	00001.f			OK
	-1.f			OK
	****************************************
	0.				OK
	0000.			OK
	00001.			OK
	-1.				OK
	****************************************
	1UL or 1L		???
	-inff +inff		OK
	-inf +inf		OK
	nan nanf		OK
	****************************************
	'c' 0-255		OK
	"42"			OK
	"0.42f"			OK
	"0.42"			OK
	****************************************
	"0.1.2"			OK
	"nothing"		OK
	"1234k"			OK
	"fake.42f"		OK
*/

int main ( int argc, char** argv ) {
	if (argc != 2) {
		std::cerr << "Error: invalid argc" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	std::cout << std::endl << "INT" << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;

	std::cout << std::endl << "FLOAT" << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;

	// std::cout << std::endl;
	// int i = 2147483648; // ----> return to negatives
	// std::cout << i << std::endl << std::endl;
	// double d = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0;
	// double d = 3000000000.0;
	// std::cout << d << std::endl << std::endl;

	std::cout << std::endl << "DOUBLE" << std::endl;
	std::cout << std::numeric_limits<double>::min() << std::endl;
	std::cout << std::numeric_limits<double>::max() << std::endl;
	return (0);
}
