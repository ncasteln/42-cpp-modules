/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:19:14 by nico              #+#    #+#             */
/*   Updated: 2024/04/03 10:29:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>
#include <algorithm>
#include <iostream>		// display stuff
#include <exception>
#include <limits>		// std::numeric_limits
#include <cstdlib>		// std::srand() rand()
#include <ctime>		// std::time()


/*
	[explicit keyword] I thought it was used to deny initialization with
	the incorrect type (ie. here with a negative number), but I was wrong. It
	is used to prevent and indirect implicit conversion from another function.
	See https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
*/
class Span
{
	// ----------------------------------------------------------- CONSTRUCTORS
	private:
		Span( void );
	public:
		~Span( void );
		explicit Span( const Span& );
		Span& operator= ( const Span& );
		explicit Span( unsigned int N );

	// ---------------------------------------------------------- OTHER MEMBERS
	private:
		unsigned int _N;
		std::vector<int> _container;
		std::vector<int>::iterator _it;
	public:
		void addNumber( int n );
		void fillContainer( void );

		long shortestSpan( void ) const;
		long longestSpan( void ) const;

		void displayContainer( void ) const;

		class SizeLimitExcept;
		class SpanExcept;
};

class Span::SizeLimitExcept: public std::exception { const char* what() const throw(); };
class Span::SpanExcept: public std::exception { const char* what() const throw(); };

#endif
