/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/04 14:02:58 by nico             ###   ########.fr       */
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
	return (0);
}
