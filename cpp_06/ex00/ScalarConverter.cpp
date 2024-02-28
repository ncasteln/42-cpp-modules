/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 18:53:35 by ncasteln         ###   ########.fr       */
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
	int type = ScalarConverter::getType(s);
	if (!type) throw InvalidInput(E_UNKNOWN); // just because everything return (0);
	if (type == CHAR) {

	}
	if (type == FLOAT) {
		float f = static_cast<float>(std::atof(s.c_str())); // print out to understand if is really float otherwise convert
	}
	if (type == INT) {
		// int i = atoi();
	}


	std::cout << "[ Conversion of " << s << " ]" << std::endl;
	std::cout << "char   : " << std::endl;
	std::cout << "int    : " << std::endl;
	std::cout << "float  : " << std::endl;
	std::cout << "double : " << std::endl;
	std::cout << std::endl;
}

// ----------------------------------------------------------------- EXCEPTIONS
ScalarConverter::InvalidInput::InvalidInput( e_except e ): _e(e) {};

const char* ScalarConverter::InvalidInput::what() const throw() {
	if (this->_e == E_DOUBLE_POINT)
		return ("double decimal point");
	if (this->_e == E_INV_DIGIT)
		return ("invalid digit");
	return ("unknown exception");
}

/*
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
int ScalarConverter::getType( std::string s ) {
	int (*f[4])( std::string );
	f[0] = &ScalarConverter::isChar;
	f[1] = &ScalarConverter::isSpecial;
	f[2] = &ScalarConverter::isFloatOrDouble;
	f[3] = &ScalarConverter::isInt;
	std::string types[5] = { "CHAR", "SPECIAL", "FLOAT or DOUBLE", "INT" }; // just to visualize
	int i = 0;
	while (i < 4) {
		if (f[i](s)) {
			std::cout << "[ " << types[i] << " ] " << std::endl;
			return (f[i](s));
		}
		i++;
	}
	return (0);
}

int ScalarConverter::isChar( std::string s ) {
	if (s.size() == 1)
		return (CHAR);
	return (0);
}

int ScalarConverter::isFloatOrDouble( std::string s ) {					// clean doing together but maybe better separate
	if (s.find('.') != std::string::npos) {								// if there is a dot
		if (s.find('.') != s.rfind('.'))								// if the left most dot position is different from the right most means there are 2
			throw InvalidInput(E_DOUBLE_POINT);
		std::string::iterator it = s.end();
		while (--it != s.begin()) {
			if ((it == --s.end()) && (*it == 'f'))						// if there is f of float jut jump it
				it--;
			else if ((it == s.begin()) && (*it == '+' || *it == '-'))	// + and - at the beginning are ok, but just one of them
				it--;
			else if (!isdigit(*it) && *it != '.')						// check if there is no word inside
				throw InvalidInput(E_INV_DIGIT);
		}
		if (*(--s.end()) == 'f')										// is float or dobule
			return (FLOAT);
		return (DOUBLE);
	}
	return (0);
}

int ScalarConverter::isInt( std::string s ) {
	std::string::iterator it = s.begin();
	while (it != s.end()) {
		if (it == s.begin() && (*it == '+' || *it == '-'))
			it++;
		else if (isdigit(*it))
			it++;
		else
			throw InvalidInput(E_INV_DIGIT);
	}
	return (INT);
}

/* nanf * -inff * +inff * nan * -inf * +inf */
int ScalarConverter::isSpecial( std::string s ) {
	if (s == "nan" || s == "nanf"
	|| s == "-inff" || s == "+inff"
	|| s == "-inf" || s == "+inf")
		return (SPECIAL);
	return (0);
}

/*
./converter nan   -------->		char: impossible // int:  impossible // float:  nanf // double: nan
./converter -inff -------->		char: impossible // int:  impossible // float:  -inff // double: -inf
./converter +inff -------->		char: impossible // int:  impossible // float:  +inff // double: +inf
./converter +inf  -------->		char: impossible // int:  impossible // float:  +inff // double: +inf
./converter -inf  -------->		char: impossible // int:  impossible // float:  -inff // double: -inf
./converter nanf  -------->		char: impossible // int:  impossible // float:  nanf // double: nan
*/

// old getType()
	// if (ScalarConverter::isChar(s)) {
	// 	std::cout << "[ CHAR ]" << std::endl;
	// 	return (CHAR);
	// }
	// else if (ScalarConverter::isSpecial(s)) {
	// 	std::cout << "[ SPECIAL ]" << std::endl;
	// 	return (SPECIAL);
	// }
	// else if (ScalarConverter::isFloatOrDouble(s) == FLOAT) {
	// 	std::cout << "[ FLOAT ]" << std::endl;
	// 	return (FLOAT);
	// }
	// else if (ScalarConverter::isFloatOrDouble(s) == DOUBLE) {
	// 	std::cout << "[ DOUBLE ]" << std::endl;
	// 	return (DOUBLE);
	// }
	// else if (ScalarConverter::isInt(s)) {
	// 	std::cout << "[ INT ]" << std::endl;
	// 	return (INT);
	// }
