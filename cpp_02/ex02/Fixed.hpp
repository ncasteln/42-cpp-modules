/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/01 15:06:46 by nico             ###   ########.fr       */
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

		// INCREMENT / DECREMENT
		void operator++( void );	// pre-increment
		void operator--( void );
		const Fixed& operator++( int );	// post-increment
		void operator--( int );

		// BASIC OPERATION
		Fixed operator+( Fixed );
		Fixed operator-( Fixed );
		Fixed operator*( Fixed );
		Fixed operator/( Fixed );

		// BOOL
		bool operator>( Fixed ) const;
		bool operator<( Fixed ) const;
		bool operator>=( Fixed ) const;
		bool operator<=( Fixed ) const;
		bool operator==( Fixed ) const;
		bool operator!=( Fixed ) const;

		// COMPAIRSON
		static Fixed& min( Fixed&, Fixed& );
		static const Fixed& min( const Fixed&, const Fixed& );
		static Fixed& max( Fixed&, Fixed& );
		static const Fixed& max( const Fixed&, const Fixed& );
	private:
		static const int bits_;
};

std::ostream& operator<<( std::ostream& cout, const Fixed& obj );

#endif /* __FIXED_HPP__ */
