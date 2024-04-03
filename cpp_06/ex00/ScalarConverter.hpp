/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:21:35 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <exception>
#include "get_type.hpp"
#include "handle_type.hpp"

/*	As subj says, the class doesn't store anything , it has only static member
	functions and is not instantiable. That because constructors/destructor are
	made private.
	The goal is create a class which can take a string, understand its type and
	convert/display to char, int, float and double. Therefore it performs the
	following steps:
		1) Check the actual type
		2) Convert to the actual type
		3) Cast to the other types and display
*/
class ScalarConverter
{
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( const ScalarConverter& );
	void operator=( ScalarConverter& );
	public:
		static void convert( std::string );
};

#endif
