/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:17:21 by nico              #+#    #+#             */
/*   Updated: 2024/03/23 16:18:40 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include "utils.hpp"

#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>

#include <cstdlib>
#include <ctime>

#define LINE	"---------------------------------------------------------"

enum e_type {
	INPUT = '|',
	DATABASE = ',',
	UNKNOWN
};

class BitcoinExchange
{
	private:
		const e_type _type;
		float _value;
		std::map<std::string, int> _date;

		// OCC
		BitcoinExchange( void ); // made private because i never want to init a default one
	public:
		// OCC
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange& operator=( const BitcoinExchange& );

		// PARAM CONSTRUCTOR
		BitcoinExchange( e_type );
		BitcoinExchange( std::string, e_type );

		// GETTERS
		std::map<std::string, int> getDate( void );
		float getValue( void );

		// MEMBER FUNCTIONS
		void mapDate( std::string to_split );	//make private?
		bool isValidDate( void );				//make private?
		bool isValidValue( std::string );
		void displayMatch( const float exchange_rate );

		// OVERLOAD OPERATORS
		bool operator>( BitcoinExchange& );
		bool operator<( BitcoinExchange& );
		bool operator==( BitcoinExchange& );

		// EXCEPTIONS
		class InvalidFormat;
		enum e_err_list {
			E_NOSEP,
			E_INVDATE,
			E_INVVAL
		};
};

class BitcoinExchange::InvalidFormat: public std::exception
{
	private:
		int _n;
	public:
		InvalidFormat( enum e_err_list n );
		const char* what() const throw();
};

std::ostream& operator<<( std::ostream& cout, BitcoinExchange& obj );

# endif /* __BITCOINEXCHANGE_HPP__ */
