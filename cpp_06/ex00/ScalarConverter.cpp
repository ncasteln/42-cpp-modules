/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 17:38:41 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& ) {
	// implement
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter& rhs) {
	// implement
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
void ScalarConverter::convert( std::string s ) {
	std::cout << "[ Conversion of " << s << " ]" << std::endl;
	std::cout << "char   : " << std::endl;
	std::cout << "int    : " << std::endl;
	std::cout << "float  : " << std::endl;
	std::cout << "double : " << std::endl;
	std::cout << std::endl;
}

int ScalarConverter::getType( std::string s ) {
	/* 'c' | "42" | "0.42f" | "0.42" | "nothing" | "fake.42f" */
	if (s.length() == 1 && isprint(s.c_str()[0])) // diff "c" and "8"
		return (CHAR);

	return (-1);
}
