/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:17:21 by nico              #+#    #+#             */
/*   Updated: 2024/06/13 13:02:39 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <limits>
#include <fstream>	// stream operations
#include <iomanip>
#include <cstdlib>
#include <ctime>

typedef enum file_type {
	INPUT = '|',
	DATABASE = ',',
	UNKNOWN
}	e_type;

class BitcoinExchange
{
	private:
		const e_type _type; // ------------------------------- MEMBER VARIABLES
		float _value;
		std::map<std::string, int> _date;
		BitcoinExchange( void ); // ---------------------------- CANONICAL FORM
	public:
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange& operator=( const BitcoinExchange& );
		BitcoinExchange( e_type ); // ----------------------- PARAM CONSTRUCTOR
		BitcoinExchange( std::string line, e_type );
		class InvalidFormat; // ------------------------------------ EXCEPTIONS
		typedef enum err {
			SUCCESS,
			E_EMPTY,
			E_NOSEP,
			E_INVDATE,
			E_INVCHAR,
			E_OVERFLOW,
			E_TOOLARGE
		}	e_err;
		std::map<std::string, int> getDate( void ); // ---------------- GETTERS
		float getValue( void );
		void mapDate( std::string to_split ); // ------------- MEMBER FUNCTIONS
		bool isValidDate( void );
		e_err isValidValue( std::string );
		bool findMatch( BitcoinExchange db, BitcoinExchange& prev );
		void displayMatch( const float exchange_rate );
		bool operator>( BitcoinExchange& ); // ------------- OVERLOAD OPERATORS
		bool operator<( BitcoinExchange& );
		bool operator==( BitcoinExchange& );
};

class BitcoinExchange::InvalidFormat: public std::exception
{
	private:
		int _n;
	public:
		InvalidFormat( e_err n );
		const char* what() const throw();
};

std::ostream& operator<<( std::ostream& cout, BitcoinExchange& obj );
std::string& trim( std::string& s, const char* to_trim );

# endif /* __BITCOINEXCHANGE_HPP__ */
