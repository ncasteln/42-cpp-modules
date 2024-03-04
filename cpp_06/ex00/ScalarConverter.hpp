/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/04 17:27:56 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <iomanip>
#include <limits>

# define CHAR		1
# define STRING		2
# define FLOAT		3
# define DOUBLE		4
# define INT		5

class ScalarConverter
{
	public:
		// --------------------------------------------------------- CONVERSION
		static void convert( std::string );
		static void handleCharInt( std::string );
		static void handleFloat( std::string );
		static void handleDouble( std::string );
		static void handleString( std::string );

		// ----------------------------------------------------------- GET TYPE
		static int getType( std::string );
		static int isChar( std::string );
		static int isString( std::string );
		static int isFloat( std::string );
		static int isDouble( std::string );
		static int isInt( std::string );

		// ------------------------------------------------------------ DISPLAY
		static void display( char, int, float, double );
		static void displaySpecial( std::string );
	private:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		ScalarConverter& operator=( ScalarConverter& );
};

#endif
