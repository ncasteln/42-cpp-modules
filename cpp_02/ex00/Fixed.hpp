/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:46:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/09 07:42:52 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

/*
	Default copy constructor: init the new obj as a (deep) copy of another one.
	It is "called" when we pass a parameter by ref (yes, it makes a copy!).
		MyClass a(42);
		MyClass b(a);	// cpy constr
		MyClass b = a;	// cpy constr

	Default assignment operator: copies the values of an obj to another one. The
	default one is not enough when the class/struct contains pointers.
		MyClass a(42);
		MyClass b;
		b = a;			// assignment op
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
	private:
		int fpn_;
		static const int bits_ = 8;
};

#endif /* __FIXED_HPP__ */
