/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:26 by nico              #+#    #+#             */
/*   Updated: 2024/06/13 16:58:49 by ncasteln         ###   ########.fr       */
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
	_value = rhs._value;
	_date = std::map<std::string, int>(rhs._date);
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/*	This constructor is needed when I store the [prev] during the db search.
	It is recognized by the given value of (-1). */
BitcoinExchange::BitcoinExchange( e_type sep ):
	_type(sep),
	_value(-1),
	_date(std::map<std::string, int>()) {}

/*	An instance of BitcoinExchange is an object which holds the date, mapped
	into y-m-d, a value, and the type of line, either database or input, which
	is const and cannot be changed.
	Since the lines of the database and input file are pretty the same, I decided
	to use the same constructor.

	@when: && _type == INPUT, I mean that the exceptions are thrown only
	when the instance is of type INPUT (if database contains format mistakes
	it's another story). */
BitcoinExchange::BitcoinExchange( std::string line, e_type sep ): _type(sep) {
	if (line.find(sep) == std::string::npos)
		if (_type == INPUT) throw InvalidFormat(E_NOSEP);
	std::string date = line.substr(0, line.find(sep));
	trim(date, " \t");
	if (date.find_first_not_of("-0987654321") != std::string::npos)
		if (_type == INPUT) throw InvalidFormat(E_INVDATE);
	mapDate(date);
	if (!isValidDate())
		if (_type == INPUT) throw InvalidFormat(E_INVDATE);
	std::string value = line.substr(line.find(sep) + 1, line.length() - 1);
	trim(value, " \t");
	if (isValidValue(value))
		if (_type == INPUT) throw InvalidFormat(isValidValue(value));
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
std::map<std::string, int> BitcoinExchange::getDate( void ) { return (_date); }

float BitcoinExchange::getValue( void ) { return (_value); }

/*	Given the date of type std::string in the format yyyy-mm-dd, it is splitted
	and stored into the map container _date member. */
void BitcoinExchange::mapDate( std::string s ) {
	const char* id[3] = { "year", "month", "day" };
	long n;
	int i = 0;
	std::string curr;

	while (s.find('-') != std::string::npos) {
		if (i == 2) return ;
		curr = s.substr(0, s.find('-') + 1);
		n = std::atol(curr.c_str());
		if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
			throw InvalidFormat(E_OVERFLOW);
		_date[id[i]] = static_cast<int>(n);
		s.erase(0, s.find('-') + 1);
		i++;
	}
	curr = s.substr(0, s.find('-'));
	_date[id[i]] = std::atoi(curr.c_str());
}

/*	The date is parsed for validity. The rule says that february has 29 days if
	the year is divisibile by 4, but not by 100 unless it is divisible by 400.
	Year is not limited and can be any positive value. */
bool BitcoinExchange::isValidDate( void ) {
	int y = _date["year"];
	int m = _date["month"];
	int d = _date["day"];

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
BitcoinExchange::e_err BitcoinExchange::isValidValue( std::string value ) {
	if (value.empty())
		return (E_EMPTY);
	if (value.find_first_not_of(".0987654321") != std::string::npos || value == ".")
		return (E_INVCHAR);
	double d = std::atof(value.c_str());
	if ((d > 1000 || d < 0) && _type == INPUT)
		return (E_TOOLARGE);
	_value = static_cast<float>(d);
	return (SUCCESS);
}

bool BitcoinExchange::findMatch( BitcoinExchange db, BitcoinExchange& prev ) {
	if (*this == db) {
		displayMatch(db.getValue());
		return (true);
	}
	else if (*this < db) {
		if (prev.getValue() == -1)
			displayMatch(db.getValue());
		else
			displayMatch(prev.getValue());
		return (true);
	}
	else if (*this > db)
		prev = db;
	return (false);
}

// ----------------------------------------------------- OPERATORS OVERALOADING
/*	Overloading oeprator is done to perform a compairson between the instance
	which stores the input line, and the instance which stores the database line.
	Examples.
	2000-1-5   > 2000-1-1  [true]
	2001-1-15  > 2001-1-1  [true]
	1000-15-15 > 2000-1-1  [false] */
bool BitcoinExchange::operator>( BitcoinExchange& rhs ) {
	if (getDate()["year"] > rhs.getDate()["year"]) return (true);
	if (getDate()["month"] > rhs.getDate()["month"]) return (true);
	if (getDate()["day"] > rhs.getDate()["day"]) return (true);
	return (false);
}

bool BitcoinExchange::operator<( BitcoinExchange& rhs ) {
	if (*this > rhs)
		return (false);
	return (true);
}

bool BitcoinExchange::operator==( BitcoinExchange& rhs ) {
	if (getDate()["year"] != rhs.getDate()["year"]) return (false);
	if (getDate()["month"] != rhs.getDate()["month"]) return (false);
	if (getDate()["day"] != rhs.getDate()["day"]) return (false);
	return (true);
}

// ----------------------------------------------------------------- EXCEPTIONS
BitcoinExchange::InvalidFormat::InvalidFormat( e_err n ): _n(n) {};

const char* BitcoinExchange::InvalidFormat::what() const throw() {
	if (_n == E_NOSEP) return ("no separator");
	if (_n == E_EMPTY) return ("empty value");
	if (_n == E_INVDATE) return ("invalid date");
	if (_n == E_INVCHAR) return ("invalid character: only digits and spaces adimitted");
	if (_n == E_TOOLARGE) return ("value too large: only between 0 and 1000 admitted");
	if (_n == E_OVERFLOW) return ("date overflows");
	return ("unkonwn error");
}

// ---------------------------------------------------------------------- UTILS
void BitcoinExchange::displayMatch( const float exchange_rate ) {
	std::cout
		<< getDate()["year"] << "-"
		<< getDate()["month"] << "-"
		<< getDate()["day"] << " => "
		<< std::fixed << std::setprecision(2) << getValue() * exchange_rate << std::endl;
}

std::ostream& operator<<( std::ostream& cout, BitcoinExchange& obj ) {
	cout
		<< "Year  : " << obj.getDate()["year"] << std::endl
		<< "Month : " << obj.getDate()["month"] << std::endl
		<< "Day   : " << obj.getDate()["day"] << std::endl
		<< "Value : " << std::fixed << std::setprecision(2) << obj.getValue() << std::endl;
	return (cout);

}

static std::string& ltrim( std::string& s, const char* to_trim ) {
	size_t pos = s.find_first_not_of(to_trim);
	s.erase(0, pos);
	return (s);
}

static std::string& rtrim( std::string& s, const char* to_trim ) {
	size_t pos = s.find_last_not_of(to_trim);
	s.erase(pos + 1);
	return (s);
}

std::string& trim( std::string& s, const char* to_trim ) {
	return (ltrim(rtrim(s, to_trim), to_trim));
}
