/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:17:21 by nico              #+#    #+#             */
/*   Updated: 2024/03/15 13:16:50 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <map>
#include <string>
#include <exception>
#include <iostream>

class BitcoinExchange
{
	private:
		std::string _test;
		std::map<std::string, double> _dateValue;
	public:
		BitcoinExchange( void );
		~BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& );
		BitcoinExchange& operator=( const BitcoinExchange& );

		BitcoinExchange( std::string );
};

# endif /* __BITCOINEXCHANGE_HPP__ */
