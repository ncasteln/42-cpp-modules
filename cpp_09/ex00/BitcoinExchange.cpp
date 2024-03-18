/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:26 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 15:20:51 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ------------------------------------------------------------- CANONICAL FORM
BitcoinExchange::BitcoinExchange( void ): _type(UNKNOWN) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& obj ): _type(UNKNOWN) { // check unknow and take decision
	// implement
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& rhs ) {
	// implement
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/*
	An instance of BitcoinExchange is an object which holds the date, mapped
	into y-m-d, a value, and the type of line, either database or input, which
	is const and cannot be changed.
*/
BitcoinExchange::BitcoinExchange( std::string line, e_type type ): _type(type) {
	if (line.find('|') == std::string::npos)
		throw InvalidFormat(E_NOPIPE);

	/* date is extracted and trimmed */
	std::string date = line.substr(0, line.find('|'));
	trim(date, " \t");

	/* if some of the char are not part of the string 0987654321- throw except */
	if (date.find_first_not_of("-0987654321") != std::string::npos)
		throw InvalidFormat(E_INVDATE);
	/* the date need to be splitted and stored into _date */
	this->mapDate(date);
	/* if date is not valid throw */
	if (!this->isValidDate())
		throw InvalidFormat(E_INVDATE);

	/////////////////////////////////////////////////////////////////////////////

	/* value is extracted and trimmed */
	std::string value = line.substr(line.find('|') + 1, line.length() - 1);
	trim(value, " \t");
	if (!this->isValidValue(value))
		throw InvalidFormat(E_INVVAL);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
std::map<std::string, int> BitcoinExchange::getDate( void ) { return (this->_date); }

float BitcoinExchange::getValue( void ) { return (this->_value); }

/*
	Given the date of type std::string in the format yyyy-mm-dd, it is splitted
	and stored into the map container _date member.
*/
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

bool BitcoinExchange::isValidDate( void ) {
	int y = this->_date["year"];
	int m = this->_date["month"];
	int d = this->_date["day"];

	if (y <= 0 || m <= 0 || d <= 0)
		return (false);
	if (m > 12 || d > 31) // y > 2024  ???? limit to the year ????
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

/*
	Checks both forms of the value, when is a std::string before merging to the
	class, and in when it's transformed into a float/double.
*/
bool BitcoinExchange::isValidValue( std::string value ) {
	if (value.empty()) // right side of pipe is not accepted if empty()
		return (false);
	if (value.find_first_not_of(".0987654321") != std::string::npos) // if some of the char are not part of the string 0987654321- throw except
		return (false);
	if (value == ".")
		return (false);
	double d = std::atof(value.c_str());
	if (d > std::numeric_limits<int>::max() || d < 0) // invalid if more than MAXINT and if negative
		return (false);
	this->_value = static_cast<float>(d);
	return (true);
}

void BitcoinExchange::matchDate( std::ifstream& db ) {
	db.clear();		// clear all error flags including .eof
	db.seekg(0);	// return to the beginning
	std::string db_line;
	while (getline(db, db_line) && db.good()) {
		// check every line of the DB
	}
}

// ----------------------------------------------------------------- EXCEPTIONS
BitcoinExchange::InvalidFormat::InvalidFormat( enum e_err_list n ): _n(n) {};

const char* BitcoinExchange::InvalidFormat::what() const throw() {
	if (this->_n == E_NOPIPE) return ("no pipe separator");
	if (this->_n == E_INVDATE) return ("invalid date");
	if (this->_n == E_INVVAL) return ("invalid value");
	if (this->_n == E_DBOPEN) return ("fail opening database");
	return ("unkonwn error");
}

// -------------------------------------------------------------------- DISPLAY
std::ostream& operator<<( std::ostream& cout, BitcoinExchange& obj ) {
	cout
		<< "Year  : " << obj.getDate()["year"] << std::endl
		<< "Month : " << obj.getDate()["month"] << std::endl
		<< "Day   : " << obj.getDate()["day"] << std::endl
		<< "Value : " << std::fixed << std::setprecision(1) << obj.getValue() << std::endl;
	return (cout);

}
