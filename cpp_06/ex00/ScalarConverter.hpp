/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/04 18:55:14 by nico             ###   ########.fr       */
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
#include <cmath>

# define CHAR		1
# define STRING		2
# define FLOAT		3
# define DOUBLE		4
# define INT		5
# define LONG		6

class ScalarConverter
{
	public:
		// --------------------------------------------------------- CONVERSION
		static void convert( std::string );
		static void handleChar( std::string );
		static void handleInt( std::string );
		static void handleDoubleFloat( std::string );
		static void handleString( std::string );
		static void handleLong( std::string );

		// ----------------------------------------------------------- GET TYPE
		static int getType( std::string );
		static int isChar( std::string );
		static int isString( std::string );
		static int isFloat( std::string );
		static int isDouble( std::string );
		static int isLong( std::string );
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
