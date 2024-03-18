/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:59:26 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 09:25:51 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ------------------------------------------------------------- CANONICAL FORM
BitcoinExchange::BitcoinExchange( void ) {
	// implement
}

BitcoinExchange::~BitcoinExchange( void ) {
	// implement
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& obj ) {
	// implement
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& rhs ) {
	// implement
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
BitcoinExchange::BitcoinExchange( std::string line ) {
	if (line.find('|') == std::string::npos)
		throw InvalidFormat(E_NOPIPE);

	/* date and value are extracted and then trimmed */
	std::string date = line.substr(0, line.find('|'));
	std::string value = line.substr(line.find('|') + 1, line.length() - 1);
	trim(date, " \t");
	trim(value, " \t");
	std::cout << "[" << date << "]" << "[" << value << "]" << std::endl;

	/* the date need to be splitted and stored into _date */
	map_date(date);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
/*
	Given the date of type std::string in the format yyyy-mm-dd, it is splitted
	and stored into the map container _date member.
*/
void BitcoinExchange::map_date( std::string s ) {
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


	// if (s.find('-') == std::string::npos) // can be done in one step for all dashes --- modify?
	// 	throw InvalidFormat(E_INVDATE);

	// std::string year = s.substr(0, s.find('-'));
	// int year_n = std::atoi(year.c_str());
	// this->_date["year"] = year_n;
	// s.erase(0, s.find('-') + 1);

	// if (s.find('-') == std::string::npos)
	// 	throw InvalidFormat(E_INVDATE);
	// std::string month = s.substr(0, s.find('-'));
	// int month_n = std::atoi(month.c_str());
	// this->_date["month"] = month_n;
	// s.erase(0, s.find('-') + 1);

	// if (s.empty())
	// 	throw InvalidFormat(E_INVDATE);
	// this->_date["day"] = std::atoi(s.c_str());


	std::cout <<
		"YEAR  : " << this->_date["year"] << std::endl <<
		"MONTH : " << this->_date["month"] << std::endl <<
		"DAY   : " << this->_date["day"] << std::endl;

	if (!this->_date["year"] || !this->_date["month"] || !this->_date["day"])
		throw InvalidFormat(E_INVDATE);
}

// ----------------------------------------------------------------- EXCEPTIONS
BitcoinExchange::InvalidFormat::InvalidFormat( int err_num ): _err_num(err_num) {};

const char* BitcoinExchange::InvalidFormat::what() const throw() {
	if (this->_err_num == E_NOPIPE) return ("no pipe separator");
	if (this->_err_num == E_INVDATE) return ("invalid date");
	return ("unkonwn error");
}
