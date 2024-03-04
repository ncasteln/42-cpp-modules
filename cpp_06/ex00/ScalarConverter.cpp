/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/04 18:56:49 by nico             ###   ########.fr       */
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

// -------------------------------------------------------------------- DISPLAY
void ScalarConverter::display( char c, int i, float f, double d ) {
	if (isprint(c))
		std::cout << "char   : '" << c << "'" << std::endl;
	else
		std::cout << "char   : Not displayable" << std::endl;
	std::cout << "int    : " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float  : " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double : " << d << std::endl;
}

void ScalarConverter::displaySpecial( std::string s ) {
	std::cout << "char   : impossible" << std::endl;
	std::cout << "int    : impossible" << std::endl;
	std::cout << "float  : " << s << (s == "impossible" ? "" : "f") << std::endl; // just to write less, when imposible no f is printed
	std::cout << "double : " << s << std::endl;
}

// ----------------------------------------------------------------- CONVERSION
void ScalarConverter::convert( std::string s ) {
	int type = ScalarConverter::getType(s);
	if (!type) {
		// catch error ? define unknow?
		std::cerr << "Error: unknown type" << std::endl;
		return ;
	}

	std::cout << "[ Conversion of " << s << " ]" << std::endl;
	if (type == CHAR)
		ScalarConverter::handleChar(s);
	else if (type == INT)
		ScalarConverter::handleInt(s);
	else if (type == STRING)
		ScalarConverter::handleString(s);
	else if (type == FLOAT || type == DOUBLE)
		ScalarConverter::handleDoubleFloat(s);
	else if (type == LONG)
		ScalarConverter::handleLong(s);
}

void ScalarConverter::handleChar( std::string s ) { // everything size == 1
	std::cout << "[ " << "CHAR" << " ]" << std::endl ;
	char c = *s.c_str();
	if (isprint(c))
		std::cout << "char    : '" << c << "'" << std::endl;
	else
		std::cout << "char    : not printable" << std::endl;
	int i = static_cast<int>(c);
	std::cout << "int     : " << i << std::endl;
	std::cout << "float   : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::handleLong( std::string s ) {
	double d = std::atof(s.c_str());
	if (std::isinf(d)) {
		displaySpecial("impossible");
		return ;
	}
	float f = static_cast<float>(d);
	std::cout << "char    : impossible" << std::endl;
	std::cout << "int     : impossible" << std::endl;
	std::cout << "float   : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleInt( std::string s ) { // can arrive anything besides of 0-9
	std::cout << "[ " << "INT" << " ]" << std::endl ;

	// double d = std::atof(s.c_str()); // checking overflow

	// int i = std::atoi(s.c_str());

	// char c = 0;
	// if (i <= 127)
	// 	c = static_cast<char>(i);
	// float f = static_cast<float>(i);
	// ScalarConverter::display(c, i, f, d);
}

// void ScalarConverter::handleFloat( std::string s ) {
// 	std::cout << "[ " << "FLOAT" << " ]" << std::endl ;
// 	float f = static_cast<float>(std::atof(s.c_str()));

// 	int i = static_cast<int>(f); // ----> explicit demotion !
// 	char c = 0;
// 	if (i <= 127)
// 		c = static_cast<char>(f); // -----> explicit demotion!
// 	double d = static_cast<double>(f);
// 	ScalarConverter::display(c, i, f, d);
// }


/*
	MAX() 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
*/
void ScalarConverter::handleDoubleFloat( std::string s ) {
	std::cout << "[ " << "DOUBLE / FLOAT" << " ]" << std::endl ;

	double d = std::atof(s.c_str());
	if (std::isinf(d)) {
		// displaySpecial("impossible");
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(d);

	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
	}
	else {
		int i = static_cast<int>(d);
		if (i <= 127) {
			char c = static_cast<char>(i);
			if (isprint(c))
				std::cout << "char    : " << c << std::endl;
			else
				std::cout << "char    : Not displayable" << std::endl;
		}
		else
			std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : " << i << std::endl;
	}
	std::cout << "float   : " << std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << d << std::endl;
}

/*
	Handles nan, nanf, +inf, +inff, -inf, -inff.
	NaN in CPP rises in case of some invalid operations like 0/0. Can be
	checked with std::isnan(n) from <cmath>.
	inf rises in case of overflowing, and can be checked with std::isinf(n)
*/
void ScalarConverter::handleString( std::string s ) {
	std::cout << "[ " << "STRING" << " ]" << std::endl ;
	if (s == "nan" || s == "+inf" || s == "inf" || s == "-inf")
		ScalarConverter::displaySpecial(s);
	else if (s == "nanf" || s == "+inff" || s == "inff" || s == "-inff")
		ScalarConverter::displaySpecial(s.erase(s.size() - 1));
	else
		ScalarConverter::displaySpecial("impossible");
}

// ------------------------------------------------------------------- GET TYPE
int ScalarConverter::getType( std::string s ) {
	int (*f[6])( std::string );
	f[0] = &ScalarConverter::isChar;
	f[1] = &ScalarConverter::isString;
	f[2] = &ScalarConverter::isFloat;
	f[3] = &ScalarConverter::isDouble;
	f[4] = &ScalarConverter::isLong;
	f[5] = &ScalarConverter::isInt;
	int i = 0;
	while (i < 6) {
		if (f[i](s))
			return (f[i](s));
		i++;
	}
	return (0);
}

int ScalarConverter::isChar( std::string s ) {
	if (s.size() == 1)		// && !isdigit(s[0]) -----  let 0-9 fall into INT case
		return (CHAR);
	return (0);
}

int ScalarConverter::isString( std::string s ) {
	bool dot = true;

	/* Check if there is at least a dot, and if there are more than one */
	if (s.find('.') == std::string::npos)
		dot = false;
	if (dot && (s.find('.') != s.rfind('.')))
		return (STRING);

	/* Only one sign is accepted, otherwise is a string */
	std::string::iterator it = s.begin();
	if (*it == '-' || *it == '+')
		it++;

	/* Cover edge case of .f */
	if (*it == '.' && *(it + 1) == 'f')
		return (STRING);

	while (it != s.end()) {
		if (it == --(s.end()) && dot && *it == 'f')	// f at the end, only if a dot was detected
			break ;
		if (!isdigit(*it) && *it != '.')
			return (STRING);
		it++;
	}
	return (0);
}

int ScalarConverter::isFloat( std::string s ) {
	if (s.find('.') != std::string::npos)
		if (*(--(s.end())) == 'f')
			return (FLOAT);
	return (0);
}

int ScalarConverter::isDouble( std::string s ) {
	if (s.find('.') != std::string::npos)
		return (DOUBLE);
	return (0);
}

int ScalarConverter::isLong( std::string s ) {
	double d = std::atof(s.c_str());
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		return (LONG);
	return (0);
}

int ScalarConverter::isInt( std::string s ) {
	return (INT);
}

