/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:19:55 by nico              #+#    #+#             */
/*   Updated: 2024/03/11 17:34:04 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
Span::Span( void ) {}

Span::~Span( void ) {}

Span::Span( const Span& obj ) {
	// implement
	//
	//
	//
	//
	//
	//
	(void)obj;
}

Span& Span::operator= ( const Span& rhs ) {
	// implement
	//
	//
	//
	//
	//
	//
	(void)rhs;
	return (*this);
}

Span::Span( unsigned int N ): _N(N), _container( N ), _it(this->_container.begin()) {
	// add rule for N = 0
	//
	//
	//
	//
	//
	//
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
/*
	std::sort(this->_container.begin(), this->_container.end()); by trying this
	I have a BIG error during compiling, why? Because of [const] keyword.
*/
long Span::shortestSpan( void ) const {
	std::vector<int> cpy(this->_container);

	std::sort(cpy.begin(), cpy.end());

	long span = std::numeric_limits<long>::max();
	std::vector<int>::iterator cpy_it = cpy.begin();

	while (cpy_it != (cpy.end() - 1)) {
		long curr = static_cast<long>(*cpy_it);
		long next = static_cast<long>(*(cpy_it + 1));
		long diff = curr - next;
		diff = (diff < 0) ? -diff : diff;	// get abs value of diff
		if (diff < span)
			span = diff;
		cpy_it++;
	}
	return (span);
}

/*
	mind and max_element return an iterator to the min and maximum value of the
	given range of iterators.
	@param long span: used long to include the longest possible span between the
	int limits.
*/
long Span::longestSpan( void ) const {
	std::vector<int>::const_iterator min = std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::const_iterator max = std::max_element(this->_container.begin(), this->_container.end());
	long span = static_cast<long>(*max) - static_cast<long>(*min);
	return (span);
}

// ------------------------------------------------------- ADD NUMBER FUNCTIONS
void Span::addNumber( int n ) {
	if (this->_it == this->_container.end())
		throw SizeLimit();
	*(this->_it) = n;
	this->_it++;
}

/*
	std::generate accept a range of iterators and a function which has the job
	to generate an item, which will be stored in the appropriate slot.
*/
static int randomNumber( void ) {
	if (std::rand() % 2)
		return (std::rand() % std::numeric_limits<int>::max() * -1);
	return (std::rand() % std::numeric_limits<int>::max());
}
void Span::populateContainer( void ) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::generate(this->_container.begin(), this->_container.end(), randomNumber);
}

// ---------------------------------------------------------- DISPLAY FUNCTIONS
static void displayItem( int item ) {
	std::cout << "[" << item << "] ";
}
void Span::displayContainer( void ) const {
	std::for_each(this->_container.begin(), this->_container.end(), displayItem);
	std::cout << std::endl;
}

// --------------------------------------------------------------------- EXCEPT
const char* Span::SizeLimit::what() const throw() {
	return ("Error: size limit reached");
}
