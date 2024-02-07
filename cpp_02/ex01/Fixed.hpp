/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/07 09:17:13 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>
#include <string>

/*
	Operator overloading: if no chaining is expected, can return (void),
	otherwise the return value has then to be the correct type of the first
	parameter taken by the function.

	Example.
	a << b << c; -----> type1 operator<<( type1, type2 );
*/
class Fixed
{
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed& );
		void operator=( const Fixed& );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed( const int );
		Fixed( const float );
		float toFloat( void ) const;
		int toInt( void ) const;
		int fpn_;
	private:
		static const int bits_;
};

std::ostream& operator<<( std::ostream& cout, const Fixed& obj );

#endif /* __FIXED_HPP__ */
