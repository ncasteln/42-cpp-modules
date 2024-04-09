/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/08 11:37:36 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>
#include <algorithm>
#include <iostream>		// display
#include <limits>		// std::numeric_limits
#include <ctime>		// std::time()

/*
	[explicit keyword] I thought it was used to deny initialization with
	the incorrect type (ie. here with a negative number), but I was wrong. It
	is used to prevent and indirect implicit conversion from another function.
	See https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean

	NOTE about const:
	- std::vector<int> getCont( void ) const { return (this->_container) };
		this would return a copy. const here mark the function, to say that the
		value is not modifiable.
	- std::vector<int>& getCont( void ) const { return (this->_container) };
		this would return a reference, but since the function is marked as const,
		this would not compile, because the returned reference could be modified
		from outside.
	- const std::vector<int>& getCont( void ) const { return (this->_container) };
		this would then compile, because the returned reference is marked as const
		and therefore never modifiable. If you try to iterate in the main(), you
		need a const_iterator (you can read-only from it), but with a normal one
		it would not compile, because it would be modifiable through its deference.
*/
class Span
{
	private: // -------------------------------------------------- CONSTRUCTORS
		Span( void );
	public:
		~Span( void );
		Span( const Span& );
		Span& operator= ( const Span& );
		Span( unsigned int N );
	private: // ------------------------------------------------- OTHER MEMBERS
		unsigned int _N;
		std::vector<int> _container;
		std::vector<int>::iterator _it;
		class Error; // -------------------------------------------- EXCEPTIONS
		typedef enum err { E_EMPTY, E_SIZEMAX, E_SPAN, E_NEGINIT } err;
	public:
		void addNumber( int n );
		void fillContainer( void );
		long shortestSpan( void ) const;
		long longestSpan( void ) const;
		void displayContainer( void ) const;
};

class Span::Error: public std::exception {
	public:
		Error( err n );
		const char* what() const throw();
	private:
		int _n;
};

#endif
