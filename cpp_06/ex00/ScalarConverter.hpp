/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 17:24:41 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>

# define CHAR	0
# define INT	1
# define FLOAT	2
# define DOUBLE	3

class ScalarConverter
{
	public:
		// --------------------------------------------------- MEMBER FUNCTIONS
		static void convert( std::string );
		static int getType( std::string );

	private:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		ScalarConverter& operator=( ScalarConverter& );
};

#endif
