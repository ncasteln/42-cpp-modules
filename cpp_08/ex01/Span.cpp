/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:37 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/08 11:35:35 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
Span::Span( void ) {}

Span::~Span( void ) {}

Span::Span( const Span& obj ):
	_N(obj._N),
	_container(obj._container),
	_it(_container.begin()) {
}

/*	The iterator has to be calculated for the left hand side instance, otherwise
	the two instances would share the same one ! */
Span& Span::operator=( const Span& rhs ) {
	_N = rhs._N;
	_container = rhs._container;
	std::vector<int>::const_iterator from = rhs._container.begin();
	std::vector<int>::const_iterator to = rhs._it;
	long int dist = std::distance(from, to);
	_it = _container.begin() + dist;
	return (*this);
}

Span::Span( unsigned int N ):
	_N(N),
	_container(0) {
	if (_N == 0)
		throw Error(E_EMPTY);
	if (static_cast<int>(N) < 0)
		throw Error(E_NEGINIT);
	_container.resize(N);
	_it = _container.begin();
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
/*	A cpy of the container is created, sorted and then iterated. Curr and next
	items are compared and the difference updated if matches the condition.
	I start with span of <long>max() just to have a starting point.
	Since the nums are sorted, [curr - next] will give always a neg value which
	is then turned to positive.
*/
long Span::shortestSpan( void ) const {
	if (_N < 2)
		throw Error(E_SPAN);
	std::vector<int> cpy(_container);
	std::sort(cpy.begin(), cpy.end());
	long span = std::numeric_limits<long>::max();
	std::vector<int>::iterator cpy_it = cpy.begin();
	while (cpy_it != (cpy.end() - 1)) {
		long curr = static_cast<long>(*cpy_it);
		long next = static_cast<long>(*(cpy_it + 1));
		long diff = curr - next;
		diff *= -1;
		if (diff < span)
			span = diff;
		cpy_it++;
	}
	return (span);
}

/*	min and max_element return an iterator to the min and maximum value of the
	given range of iterators.
	@param long span: used long to include the longest possible span between
	integers (the max possible is between MIN_INT & MAX_INT) */
long Span::longestSpan( void ) const {
	if (_N < 2)
		throw Error(E_SPAN);
	std::vector<int>::const_iterator min = std::min_element(_container.begin(), _container.end());
	std::vector<int>::const_iterator max = std::max_element(_container.begin(), _container.end());
	long span = static_cast<long>(*max) - static_cast<long>(*min);
	return (span);
}

// ------------------------------------------------------- ADD NUMBER FUNCTIONS
void Span::addNumber( int n ) {
	if (_it == _container.end())
		throw Error(E_SIZEMAX);
	*(_it) = n;
	_it++;
}

/*	std::generate accept a range of iterators and a function which has the job
	to generate an item, which will be stored in the appropriate slot.

	It is not used the begin() iterator of the container, because it depends
	the function fillContainer() could be called after a couple of call of
	addNumber(). */
static int randomNumber( void ) {
	if (std::rand() % 2)
		return (std::rand() % std::numeric_limits<int>::max());
	return (std::rand() % std::numeric_limits<int>::min());
}
void Span::fillContainer( void ) {
	if (_it == _container.end())
		throw Error(E_SIZEMAX);
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::generate(_it, _container.end(), randomNumber);
	_it = _container.end();
}

// ---------------------------------------------------------- DISPLAY FUNCTIONS
static void displayItem( int item ) {
	std::cout << "[" << item << "] ";
}
void Span::displayContainer( void ) const {
	std::for_each(_container.begin(), _container.end(), displayItem);
	std::cout << std::endl;
}

// --------------------------------------------------------------------- EXCEPT
Span::Error::Error( err n ): _n(n) {};

const char* Span::Error::what() const throw() {
	if (_n == E_EMPTY) return ("container is empty (size 0)");
	if (_n == E_SIZEMAX) return ("maximum size reached");
	if (_n == E_SPAN) return ("impossible to calculate span (size 1)");
	if (_n == E_NEGINIT) return ("impossible to create vector with neg size");
	return ("unknokwn error");
}
