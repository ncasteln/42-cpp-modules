/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:17:21 by nico              #+#    #+#             */
/*   Updated: 2024/03/18 09:01:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include "utils.hpp"

#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, int> _date;
		double _value;
	public:
		BitcoinExchange( void );
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange& operator=( const BitcoinExchange& );

		BitcoinExchange( std::string );

		void map_date( std::string to_split ); //make private?

		class InvalidFormat;
		enum err_list {
			E_NOPIPE,
			E_INVDATE
		};
};

class BitcoinExchange::InvalidFormat: public std::exception
{
	private:
		int _err_num;
	public:
		InvalidFormat( int err_num );
		const char* what() const throw();
};

# endif /* __BITCOINEXCHANGE_HPP__ */
