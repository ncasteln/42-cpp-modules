/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:26 by nico              #+#    #+#             */
/*   Updated: 2024/03/20 13:03:28 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ------------------------------------------------------------- CANONICAL FORM
BitcoinExchange::BitcoinExchange( void ): _type(UNKNOWN) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& obj ):
	_type(obj._type),
	_value(obj._value),
	_date(std::map<std::string, int>(obj._date)) {}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& rhs ) {
	this->_value = rhs._value;
	this->_date = std::map<std::string, int>(rhs._date);
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/* This constructor is needed when I store the [prev] during the db search. */
BitcoinExchange::BitcoinExchange( e_type sep ):
	_type(sep),
	_value(-1),
	_date(std::map<std::string, int>()) {}

/*	An instance of BitcoinExchange is an object which holds the date, mapped
	into y-m-d, a value, and the type of line, either database or input, which
	is const and cannot be changed.
	Since the ines of the database and input file are pretty the same, I decided
	to use the same constructor.
	@when: && this->_type == INPUT, I mean that the exceptions are thrown only
	when the instance is of type INPUT (if database contains format mistakes
	it's another story). */
BitcoinExchange::BitcoinExchange( std::string line, e_type sep ): _type(sep) {
	if (line.find(sep) == std::string::npos)
		throw InvalidFormat(E_NOSEP);

	/* date is extracted and trimmed */
	std::string date = line.substr(0, line.find(sep));
	trim(date, " \t");

	/* if some of the char of date is not part of the string 0987654321- throw except */
	if (date.find_first_not_of("-0987654321") != std::string::npos)
		throw InvalidFormat(E_INVDATE);
	/* the date need to be splitted and stored into _date */
	this->mapDate(date);
	/* if date is not valid throw */
	if (!this->isValidDate())
		throw InvalidFormat(E_INVDATE);

	/////////////////////////////////////////////////////////////////////////////

	/* value is extracted and trimmed */
	std::string value = line.substr(line.find(sep) + 1, line.length() - 1);
	trim(value, " \t");
	if (!this->isValidValue(value))
		throw InvalidFormat(E_INVVAL);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
std::map<std::string, int> BitcoinExchange::getDate( void ) { return (this->_date); }

float BitcoinExchange::getValue( void ) { return (this->_value); }

/*	Given the date of type std::string in the format yyyy-mm-dd, it is splitted
	and stored into the map container _date member. */
void BitcoinExchange::mapDate( std::string s ) {
	int i = 0;
	const char* id[3] = { "year", "month", "day" };
	std::string curr;
	while (s.find('-') != std::string::npos) {
		if (i == 2) return ; // check the case in which the number dashes exceeds a certain number
		curr = s.substr(0, s.find('-') + 1);
		this->_date[id[i]] = std::atoi(curr.c_str());
		s.erase(0, s.find('-') + 1);
		i++;
	}
	curr = s.substr(0, s.find('-'));
	this->_date[id[i]] = std::atoi(curr.c_str());
}

/*	The date is parsed for validity. The rule says that february has 29 days if
	the year is divisibile by 4, but not by 100 unless it is divisible by 400.
	Year is not limited and can be any positive value. */
bool BitcoinExchange::isValidDate( void ) {
	int y = this->_date["year"];
	int m = this->_date["month"];
	int d = this->_date["day"];

	if (y <= 0 || m <= 0 || d <= 0)
		return (false);
	if (m > 12 || d > 31)
		return (false);
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31)
		return (false);
	if (m == 2) {
		if (d > 29)
			return (false);
		if (d == 29 && y % 4 == 0) {
			if (y % 100 == 0) {
				if (y % 400 != 0)
					return (false);
			}
		}
	}
	return (true);
}

/*	Checks both forms of the value, when is a std::string before merging to the
	class, and in when it's transformed into a float/double. */
bool BitcoinExchange::isValidValue( std::string value ) {
	if (value.empty()) // right side of pipe is not accepted if empty()
		return (false);
	// tricky the following: means, if the char which are not those, HAVE A position in the string...
	if (value.find_first_not_of(".0987654321") != std::string::npos) // if some of the char are not part of the string 0987654321- throw except
		return (false);
	if (value == ".")
		return (false);
	double d = std::atof(value.c_str());
	if ((d > 1000 || d < 0) && this->_type == INPUT) // invalid if not between 0 and 1000
		return (false);
	this->_value = static_cast<float>(d);
	return (true);
}

// ----------------------------------------------------- OPERATORS OVERALOADING
/*	Examples
	2000-1-5  > 2000-1-1 [true]
	2001-1-15 > 2001-1-1 [true]
	1000-15-15 > 2000-1-1 [false] */
bool BitcoinExchange::operator>( BitcoinExchange& rhs ) {
	if (this->getDate()["year"] > rhs.getDate()["year"]) return (true);
	if (this->getDate()["month"] > rhs.getDate()["month"]) return (true);
	if (this->getDate()["day"] > rhs.getDate()["day"]) return (true);
	return (false);
}

bool BitcoinExchange::operator<( BitcoinExchange& rhs ) {
	if (*this > rhs)
		return (false);
	return (true);
}

bool BitcoinExchange::operator==( BitcoinExchange& rhs ) {
	if (this->getDate()["year"] != rhs.getDate()["year"]) return (false);
	if (this->getDate()["month"] != rhs.getDate()["month"]) return (false);
	if (this->getDate()["day"] != rhs.getDate()["day"]) return (false);
	return (true);
}

// ----------------------------------------------------------------- EXCEPTIONS
BitcoinExchange::InvalidFormat::InvalidFormat( enum e_err_list n ): _n(n) {};

const char* BitcoinExchange::InvalidFormat::what() const throw() {
	if (this->_n == E_NOSEP) return ("no separator");
	if (this->_n == E_INVDATE) return ("invalid date");
	if (this->_n == E_INVVAL) return ("invalid value");
	return ("unkonwn error");
}

// -------------------------------------------------------------------- DISPLAY
void BitcoinExchange::displayMatch( const float exchange_rate ) {
	std::cout
		<< this->getDate()["year"] << "-"
		<< this->getDate()["month"] << "-"
		<< this->getDate()["day"] << " => "
		<< this->getValue() * exchange_rate << std::endl;
}

std::ostream& operator<<( std::ostream& cout, BitcoinExchange& obj ) {
	cout
		<< "Year  : " << obj.getDate()["year"] << std::endl
		<< "Month : " << obj.getDate()["month"] << std::endl
		<< "Day   : " << obj.getDate()["day"] << std::endl
		<< "Value : " << std::fixed << std::setprecision(2) << obj.getValue() << std::endl;
	return (cout);

}
