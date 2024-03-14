/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/14 13:24:39 by nico             ###   ########.fr       */
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
	functions and is not instantiable. The goal is create a class which can
	take a string, understand its type and convert/display to char, int, float
	and double. Therefore it performs the followings:
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
	- The copy const and assignment don't do anything, because there is no member to
	copy.
	- Only parameters with ONE sign are accepted, more than one are discarded and
	considered impossible to convert

	*** VERIFY
	- Constructors
	- why MAX_INT is converted into float as 2147483648.0f and not 2147483647.0f ???
*/
int main ( int argc, char** argv ) {
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
