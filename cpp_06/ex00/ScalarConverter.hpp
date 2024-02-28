/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 18:51:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>

# define CHAR		1
# define SPECIAL	2
# define FLOAT		3
# define DOUBLE		4
# define INT		5

class ScalarConverter
{
	public:
		static void convert( std::string );

		// ----------------------------------------------------------- GET TYPE
		static int getType( std::string );
		static int isChar( std::string );
		static int isFloatOrDouble( std::string );
		static int isInt( std::string );
		static int isSpecial( std::string );

		// --------------------------------------------------------- EXCEPTIONS
		class InvalidInput;
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		ScalarConverter& operator=( ScalarConverter& );
	private:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
};

enum e_except {
	E_DOUBLE_POINT,
	E_INV_DIGIT,
	E_UNKNOWN
};

class ScalarConverter::InvalidInput: public std::exception
{
	public:
		InvalidInput( e_except );
		const char* what() const throw();
	private:
		const e_except _e;
};

#endif
