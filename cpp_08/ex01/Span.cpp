/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:37 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:25:39 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// --------------------------------------------------------------- CONSTRUCTORS
Span::Span( void ) {}

Span::~Span( void ) {}

Span::Span( const Span& obj ):
	_N(obj._N),
	_container(obj._container),
	_it(this->_container.begin()) {
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

Span::Span( unsigned int N ):
	_N(N),
	_container(N),
	_it(this->_container.begin()) {
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
/*
	std::sort(this->_container.begin(), this->_container.end()); by trying this
	I have a BIG error during compiling, why? Because of [const] keyword.
*/
long Span::shortestSpan( void ) const {
	if (this->_N < 2)
		throw SpanExcept();

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
	if (this->_N < 2)
		throw SpanExcept();
	std::vector<int>::const_iterator min = std::min_element(this->_container.begin(), this->_container.end());
	std::vector<int>::const_iterator max = std::max_element(this->_container.begin(), this->_container.end());
	long span = static_cast<long>(*max) - static_cast<long>(*min);
	return (span);
}

// ------------------------------------------------------- ADD NUMBER FUNCTIONS
/*
	To populate the vector I could use a simple [this->_container.push_back(n);]
	but since I needed the position of the next-item-to-fill (to throw exceptions),
	I directly use it here.
*/
void Span::addNumber( int n ) {
	if (this->_it == this->_container.end())
		throw SizeLimitExcept();
	*(this->_it) = n;
	this->_it++;
}

/*
	std::generate accept a range of iterators and a function which has the job
	to generate an item, which will be stored in the appropriate slot.
	It is not used the begin() iterator of the container, because it depends
	the function fillContainer() could be called after a couple of call of
	addNumber().
*/
static int randomNumber( void ) {
	if (std::rand() % 2)
		return (std::rand() % std::numeric_limits<int>::max() * -1);
	return (std::rand() % std::numeric_limits<int>::max());
}
void Span::fillContainer( void ) {
	if (this->_it == this->_container.end())
		throw SizeLimitExcept();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::generate(this->_it, this->_container.end(), randomNumber);
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
const char* Span::SizeLimitExcept::what() const throw() {
	return ("Error: maximum size reached");
}

const char* Span::SpanExcept::what() const throw() {
	return ("Error: impossible to calculate span");
}
