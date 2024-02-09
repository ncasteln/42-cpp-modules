/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:44:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed& );
		Fixed& operator=( const Fixed& );
		Fixed( const int );
		Fixed( const float );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		// new
		Fixed operator+( const Fixed& );
		Fixed operator-( const Fixed& );
		Fixed operator*( const Fixed& );
		Fixed operator/( const Fixed& );
		bool operator>( const Fixed& ) const;
		bool operator<( const Fixed& ) const;
		bool operator>=( const Fixed& ) const;
		bool operator<=( const Fixed& ) const;
		bool operator==( const Fixed& ) const;
		bool operator!=( const Fixed& ) const;
		Fixed& operator++( void );				// pre
		Fixed& operator--( void );				// pre
		Fixed operator++( int );				// post
		Fixed operator--( int );				// post
		static Fixed& min( Fixed&, Fixed& );
		static Fixed& max( Fixed&, Fixed& );
		static const Fixed& min( const Fixed&, const Fixed& );
		static const Fixed& max( const Fixed&, const Fixed& );
	private:
		int fpn_;
		static const int bits_ = 8;
};

std::ostream& operator<<( std::ostream& cout, const Fixed& obj );

#endif /* __FIXED_HPP__ */
