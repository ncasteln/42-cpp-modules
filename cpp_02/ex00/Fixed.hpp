/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/29 16:28:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

/*
	Default copy constructor: init the new obj as a (deep) copy of another one.
	It is "called" when we pass a parameter by value (yes, it makes a copy!).
	MyClass a(42);
	MyClass b(a);
	MyClass b = a;

	Default assignment operator: copies the values of an obj to another one. The
	default is not enough when the class/struct contains pointers.
	MyClass a(42);
	MyClass b;
	b = a;
*/
class Fixed
{
	public:
		Fixed( void );
		Fixed( int );
		~Fixed( void );
		Fixed( const Fixed& );
		Fixed& operator=( const Fixed& );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int fpn_;
	private:
		static const int bits_;
};

#endif /* __FIXED_HPP__ */
