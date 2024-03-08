/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/08 18:24:17 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
/*

	RESUME
	As subj says, the class doesn't store anything, it has only static member
	functions and is not instantiable. The goal is create a class which can
	take a string, understand its type and convert/display to char, int, float
	and double. Therefore it performs the followings:
	1) Check the actual type
	2) Convert to the actual type
	3) Cast to the other types and display
*/

/*
	TO HANDLE:
	- Complete constructors
*/
int main ( int argc, char** argv ) {
	if (argc != 2) {
		std::cerr << "Error: invalid argc" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
