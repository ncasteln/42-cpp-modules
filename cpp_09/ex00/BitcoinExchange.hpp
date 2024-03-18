/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:17:21 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 12:58:16 by nico             ###   ########.fr       */
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

#include <cstdlib>
#include <ctime>

#define SEPARATOR	"---------------------------------------------------------"

enum e_type {
	INPUT,
	DATABASE,
	UNKNOW
};

class BitcoinExchange
{
	private:
		std::map<std::string, int> _date;
		double _value;
		const e_type _type;

		BitcoinExchange( void ); // made private because i never want to init a default one
	public:
		// OCC
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );				// private ?
		BitcoinExchange& operator=( const BitcoinExchange& );	// private ?

		// PARAM CONSTRUCTOR
		BitcoinExchange( std::string, e_type );

		// GETTERS
		std::map<std::string, int> getDate( void );
		double getValue( void );

		// MEMBER FUNCTIONS
		void mapDate( std::string to_split );	//make private?
		bool isValidDate( void );				//make private?
		void matchDate( std::ifstream& db );

		// EXCEPTIONS
		class InvalidFormat;
		enum e_err_list {
			E_NOPIPE,
			E_INVDATE,
			E_INVVAL,
			E_DBOPEN
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
