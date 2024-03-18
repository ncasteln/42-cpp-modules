/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:26 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 13:07:10 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ------------------------------------------------------------- CANONICAL FORM
BitcoinExchange::BitcoinExchange( void ): _type(UNKNOW) {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& obj ): _type(UNKNOW) { // check unknow and take decision
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

	/* the date need to be splitted and stored into _date */
	this->mapDate(date);
	if (!this->isValidDate())
		throw InvalidFormat(E_INVDATE);

	/* value is extracted */
	std::string value = line.substr(line.find('|') + 1, line.length() - 1);
	if (value.empty()) // right side of pipe is not accepted if empty()
		throw InvalidFormat(E_INVVAL);
	trim(value, " \t");
	this->_value = std::atof(value.c_str());
	if (this->_value > std::numeric_limits<int>::max() || this->_value < 0) // invalid if more than MAXINT and if negative
		throw InvalidFormat(E_INVVAL);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
std::map<std::string, int> BitcoinExchange::getDate( void ) { return (this->_date); }

double BitcoinExchange::getValue( void ) { return (this->_value); }

/*
	Given the date of type std::string in the format yyyy-mm-dd, it is splitted
	and stored into the map container _date member.
*/
void BitcoinExchange::mapDate( std::string s ) {
	int i = 0;
	const char* id[3] = { "year", "month", "day"};
	std::string curr;
	while (s.find('-') != std::string::npos) {
		curr = s.substr(0, s.find('-') + 1);
		this->_date[id[i]] = std::atoi(curr.c_str());
		s.erase(0, s.find('-') + 1);
		i++;
	}
	curr = s.substr(0, s.find('-'));
	this->_date[id[i]] = std::atoi(curr.c_str());
}

bool BitcoinExchange::isValidDate( void ) {
	// month 4 6 9 11 --- 30 days
	// else 31 days

	// feb 29 days
		// if (year % 4 == 0 && year % 100) unless (% 400 == 0)

	// set a limit for years?
	return (true);
}

	// std::ifstream db;
	// std::string db_line;

	// db.open(db_name, std::ifstream::in);
	// if (!db) // ios::operator! same as db.fail()
	// 	throw InvalidFormat(E_DBOPEN);
	// while (getline(db, db_line) && db.good()) {

	// }
	// db.close();
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
		<< "Value : " << obj.getValue() << std::endl;
	return (cout);

}
