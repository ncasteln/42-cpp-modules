/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:43:44 by ncasteln         ###   ########.fr       */
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
		Fixed& operator=( const Fixed& );
		Fixed( const int );					// new
		Fixed( const float );				// new
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;		// new
		int toInt( void ) const;			// new
	private:
		int fpn_;
		static const int bits_ = 8;
};

std::ostream& operator<<( std::ostream& cout, const Fixed& obj );	// new

#endif /* __FIXED_HPP__ */
