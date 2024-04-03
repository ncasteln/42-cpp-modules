/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 15:14:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& obj ) { (void)obj; }

void ScalarConverter::operator=( ScalarConverter& rhs) { (void)rhs; };

// ----------------------------------------------------------------- CONVERSION
void ScalarConverter::convert( std::string s ) {
	if (s.empty())
		throw std::invalid_argument("cannot convert empty string");
	int type = getType(s);
	std::cout << "[ Conversion of \"" << s << "\" ]" << std::endl;
	if (type == CHAR)
		handleChar(s);
	else if (type == INT)
		handleInt(s);
	else if (type == FLOAT)
		handleFloat(s);
	else if (type == DOUBLE)
		handleDouble(s);
	else if (type == STRING)
		handleString(s);
	else
		throw std::invalid_argument("unknown type");
}
