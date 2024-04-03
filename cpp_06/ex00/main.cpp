/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 10:43:53 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*	SOME TESTS
	**************************************** impossible
	.f				OK
	"0.1.2"			OK
	"nothing"		OK
	"1234k"			OK
	"fake.42f"		OK
	123abc			OK
	**************************************** floats
	0.f				OK
	0000.f			OK
	00001.f			OK
	-1.f			OK
	**************************************** double
	0.				OK
	0000.			OK
	00001.			OK
	-1.				OK
	**************************************** specials
	-inff +inff		OK
	-inf +inf		OK
	nan nanf		OK
	****************************************
	'c' 0-255		OK
	"42"			OK
	"0.42f"			OK
	"0.42"			OK
*/
/*
	*** RESUME
	As subj says, the class doesn't store anything, it has only static member
	functions and is not instantiable. That because constructors/destructor are
	made private.
	The goal is create a class which can take a string, understand its type and
	convert/display to char, int, float and double. Therefore it performs the
	following steps:
		1) Check the actual type
		2) Convert to the actual type
		3) Cast to the other types and display

	*** DECISIONS
	- I choose to accept any paramenter, so ERROR are thrown only if argc != 2 and
	if for some reason type is unknown.
	- I could create a better code if it would not be mandatory to follow the steps
	indicated by the subject (the 3 points above).
	- I didnt handled strange notations which uses 'e' or other stuff like
	"1UL" or "1L".

	*** OPEN QUESTIONS TP VERIFY
	- why MAX_INT is converted into float as 2147483648.0f and not 2147483647.0f ???
	- what about overflows when they reach LONG or something else? */
int main ( int argc, char** argv ) {
	ScalarConverter::displayLimits();
	try {
		if (argc != 2)
			throw std::invalid_argument("invalid argument");
		ScalarConverter::convert(argv[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

// CHAR (8 bits) min: 0
// CHAR (8 bits) max: 127

// INT (32 bits) min: -2147483648
// INT (32 bits) max: 2147483647

// FLOAT (32 bits) min: 0.000000
// FLOAT (32 bits) max: 340282346638528859811704183484516925440.000000

// LONG (64 bits) min: -9223372036854775808
// LONG (64 bits) max: 9223372036854775807

// DOUBLE (64 bits) min: 0.000000
// DOUBLE (64 bits) max: 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
