/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/14 13:23:30 by nico             ###   ########.fr       */
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
	if (s.empty()) {
		displaySpecial("impossible");
		return ;
	}
	int type = ScalarConverter::getType(s);
	std::cout << "[ Conversion of \"" << s << "\" ]" << std::endl;
	if (type == CHAR)
		ScalarConverter::handleChar(s);
	else if (type == INT)
		ScalarConverter::handleInt(s);
	else if (type == LONG)
		ScalarConverter::handleLong(s);
	else if (type == FLOAT)
		ScalarConverter::handleFloat(s);
	else if (type == DOUBLE)
		ScalarConverter::handleDouble(s);
	else if (type == STRING)
		ScalarConverter::handleString(s);
	else
		throw std::invalid_argument("unknown type");
}

/*
	To make the function cleaner we could use displayChar() and use atoi
	first to get the int. But since the subjects asks to firstly cast the
	value to its actual type, I-ve done in the following way.
*/
void ScalarConverter::handleChar( std::string s ) {
	std::cout << "[ " << "CHAR" << " ]" << std::endl;
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

void ScalarConverter::handleInt( std::string s ) {
	std::cout << "[ " << "INT" << " ]" << std::endl ;
	int i = std::atoi(s.c_str());
	ScalarConverter::displayChar(i);

//?????	std::cout << std::fixed << std::setprecision(400) << static_cast<float>(i) << std::endl;

	std::cout << "int     : " << i << std::endl;
	std::cout << "float   : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

/*
	Why verify if is it long? Because although the overflow of int is already
	verified, we can still cast the value as float or double.
*/
void ScalarConverter::handleLong( std::string s ) {
	std::cout << "[ " << "LONG" << " ]" << std::endl ;
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

/*
	Similar to handleChar() and handleInt() functions, the float and double are
	very similar to each other, but the subject explicits the exact steps that
	should be performed, therefore the repetition is left as it is.
*/
void ScalarConverter::handleFloat( std::string s ) {
	std::cout << "[ " << "FLOAT" << " ]" << std::endl ;
	float f = static_cast<float>(std::atof(s.c_str()));
	double d;
	if (std::isinf(f)) { // check if the result of conversion is infinite, in that case double is taken with atof
		d = std::atof(s.c_str());
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
	}
	else
		d = static_cast<double>(f); // otherwise is casted

	// check of int overflow, if true impossible is printed
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
	}
	else { // i and c are calculated, c can be out of range too or not displayable
		int i = static_cast<int>(d);
		ScalarConverter::displayChar(i);
		std::cout << "int     : " << i << std::endl;
	}
	std::cout << "float   : " << std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::handleDouble( std::string s ) {
	std::cout << "[ " << "DOUBLE" << " ]" << std::endl ;

	double d = std::atof(s.c_str());
	float f = static_cast<float>(d); // everytime from double, because if double is inf all the others are inf/impossible
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "char    : impossible" << std::endl;
		std::cout << "int     : impossible" << std::endl;
	}
	else {
		int i = static_cast<int>(d);
		ScalarConverter::displayChar(i);
		std::cout << "int     : " << i << std::endl;
	}
	std::cout << "float   : " << std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << "double  : " << std::fixed << std::setprecision(1) << d << std::endl;
}

/*
	Handles nan, nanf, +inf, +inff, -inf, -inff.
	[NaN] in CPP rises in case of some invalid operations like 0/0. Can be
	checked with std::isnan(n) from <cmath>.
	[inf] rises in case of overflowing, and can be checked with std::isinf(n)
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

/*
	Take everything of size == 1, including digits from 0 to 9.
*/
int ScalarConverter::isChar( std::string s ) {
	if (s.size() == 1)
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

/*
	isLong has been created to catch int overflow. double is used to verify the
	overflow.
	IMPORTANT!!! use double or long to catch it ?
				here I am using double
*/
int ScalarConverter::isLong( std::string s ) {
	double d = std::atof(s.c_str());
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		return (LONG);
	return (0);
}

/*
	isInt() is not necessary but was nice to have it to work with function
	pointers in getType() function.
*/
int ScalarConverter::isInt( std::string s ) {
	(void)s;
	return (INT);
}

// -------------------------------------------------------------------- DISPLAY
/*
	The function is created to avoid repetition between codes, since it is a
	common repeated pattern.
*/
void ScalarConverter::displayChar( int i ) {
	char c = 0;
	if (i >= 0 && i <= 127) {
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << "char    : " << c << std::endl;
		else
			std::cout << "char    : not printable" << std::endl;
	}
	else
		std::cout << "char    : impossible" << std::endl;
}

/*
	Displays special values like nan, infinity and overflows. The f is not
	printed when "impossible" is passed as a parameter.
*/
void ScalarConverter::displaySpecial( std::string s ) {
	std::cout << "char   : impossible" << std::endl;
	std::cout << "int    : impossible" << std::endl;
	std::cout << "float  : " << s << (s == "impossible" ? "" : "f") << std::endl;
	std::cout << "double : " << s << std::endl;
}

/*
	Not required by the subject, it is still useful to check the range limits
	of the required types.
*/
void ScalarConverter::displayLimits( void ) {
	std::cout << "CHAR (8 bits) min: " << 0 << std::endl;
	std::cout << "CHAR (8 bits) max: " << 127 << std::endl << std::endl;

	std::cout << "INT (32 bits) min: " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "INT (32 bits) max: " << std::numeric_limits<int>::max() << std::endl << std::endl;

	std::cout << "FLOAT (32 bits) min: " << std::fixed << std::numeric_limits<float>::min() << std::endl;
	std::cout << "FLOAT (32 bits) max: " << std::fixed << std::numeric_limits<float>::max() << std::endl << std::endl;

	std::cout << "LONG (64 bits) min: " << std::numeric_limits<long>::min() << std::endl;
	std::cout << "LONG (64 bits) max: " << std::numeric_limits<long>::max() << std::endl << std::endl;

	std::cout << "DOUBLE (64 bits) min: " << std::fixed << std::numeric_limits<double>::min() << std::endl;
	std::cout << "DOUBLE (64 bits) max: " << std::fixed << std::numeric_limits<double>::max() << std::endl << std::endl;
}
