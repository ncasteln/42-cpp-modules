/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:19:14 by nico              #+#    #+#             */
/*   Updated: 2024/03/11 17:32:23 by nico             ###   ########.fr       */
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

class Span
{
	// ----------------------------------------------------------- CONSTRUCTORS
	private:
		Span( void );
	public:
		~Span( void );
		Span( const Span& );
		Span& operator= ( const Span& );
		Span( unsigned int N );

	// ---------------------------------------------------------- OTHER MEMBERS
	private:
		unsigned int _N;
		std::vector<int> _container;
		std::vector<int>::iterator _it;
	public:
		void addNumber( int n );
		void populateContainer( void );

		long shortestSpan( void ) const;
		long longestSpan( void ) const;

		void displayContainer( void ) const;

		class SizeLimit;
};

class Span::SizeLimit: public std::exception { const char* what() const throw(); };

#endif
