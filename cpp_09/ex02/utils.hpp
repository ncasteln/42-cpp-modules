/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:46:05 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/26 09:11:28 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

typedef enum cont { VECTOR, DEQUE }	e_cont;
typedef enum chain { MAIN, PEND }	e_chain;

/*	Forward declaration is used to leave a meaningful order to the steps of
	sorting and the function used during the process. */
template <typename T> T createJacobsthalSequence( T container );
template <typename T> T createInsertionOrder( T jacobSequence, size_t container_size );
template <typename T> T binSearch( unsigned int item, T begin, T end );
template <typename T> bool isSorted( T container );
template <typename T, typename U> T createChain( U pair_container, e_chain type );
template<typename T> void verbose( std::string step, T first, T second );
template<typename T> void insertVector( T& main_chain, T pend_chain, T insertionOrder );
template<typename T> void insertDeque( T& main_chain, T pend_chain, T insertionOrder );

/*	Part of the parsing. The approach used is to modify the original std::string,
	erasing its characters and reducing it to an empty string. An overflow check
	is performed after use of atol(). */
template <typename T>
int extract_numbers( std::string arg, T& container ) {
	size_t pos;
	std::string number;
	long n;

	while (!arg.empty()) {
		pos = arg.find_first_not_of(" \t");
		if (pos == std::string::npos) break ;
		arg.erase(0, pos);
		pos = arg.find_first_not_of("1234567890");
		number = arg.substr(0, pos);
		n = std::atol(number.c_str());
		if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
			return (1);
		container.push_back(static_cast<unsigned int>(n));
		arg.erase(0, number.length());
	}
	return (0);
}

// -------------------------------------------------------------- SORTING STEPS
/*	The function creates a container of pair, and directly sorts the items of
	each pair by ascending order.
	@_container.size() - (_container.size()%2) loop condition, depends if the
	container size is odd or even. In case of odd i don't want create a pair
	with the last element. */
template <typename T, typename U>
U pairing( T container ) {
	U pair_container;
	std::pair<int, int> p;

	for (size_t i = 0; i < container.size() - (container.size()%2); i += 2) {
		p = std::make_pair(container[i], container[i + 1]);
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pair_container.push_back(p);
	}
	verbose("[ PAIRING ]", createChain<T,U>(pair_container, MAIN), createChain<T,U>(pair_container, PEND));
	return (pair_container);
}

/*	Merge sort using iterators and takign a container of pairs as parameter. Se elements
	are sorted based onf the first parameter of each pair in ascending order. */
template <typename U>
void merge( U& pair_container ) {
	if (pair_container.size() <= 1)
		return ;
	long int middle = static_cast<long int>(pair_container.size() / 2);

	U left(pair_container.begin(), pair_container.begin() + middle);
	merge(left);

	U right(pair_container.begin() + middle, pair_container.end());
	merge(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), pair_container.begin());
}

template <typename T, typename U>
T insertion( T container, U pair_container ) {
	T jacobSequence = createJacobsthalSequence(container);
	T insertionOrder = createInsertionOrder(jacobSequence, container.size());
	T main_chain = createChain<T, U>(pair_container, MAIN);
	T pend_chain = createChain<T, U>(pair_container, PEND);

	typename T::iterator location;
	typename T::iterator index = insertionOrder.begin();
	while (index != insertionOrder.end()) {
		location = binSearch(*(pend_chain.begin() + (*index)), main_chain.begin(), main_chain.end());
		main_chain.insert(location, (*(pend_chain.begin() + (*index))));
		index++;
	}
	if ((container.size() % 2) != 0) {
		location = binSearch(*(--container.end()), main_chain.begin(), main_chain.end());
		main_chain.insert(location, *(--container.end()));
	}
	verbose("[ JACOBING ]", jacobSequence, insertionOrder);
	verbose("[ INSERTING ]", main_chain, pend_chain);
	return (main_chain);
}

/*	Use of template specialization: in case of deque I needed to use a special
	function because of the undefined behavior mentioned in the reference:
	"...unlike vectors, deques are not guaranteed to store all its elements in
	contiguous storage locations: accessing elements in a deque by offsetting
	a pointer to another element causes undefined behavior." */
template <typename U>
std::deque<unsigned int> insertion( std::deque<unsigned int> container, U pair_container ) {
	typedef std::deque<unsigned int> deque;
	deque jacobSequence = createJacobsthalSequence(container);
	deque insertionOrder = createInsertionOrder(jacobSequence, container.size());
	deque main_chain = createChain<deque, U>(pair_container, MAIN);
	deque pend_chain = createChain<deque, U>(pair_container, PEND);

	typename deque::iterator location;
	typename deque::iterator index = insertionOrder.begin();
	while (index != insertionOrder.end()) {
		size_t counter = 0;
		while (counter < insertionOrder.size()) {
			if (counter == *index)
				break ;
			counter++;
		}
		unsigned int number = pend_chain[counter];
		location = binSearch(number, main_chain.begin(), main_chain.end());
		main_chain.insert(location, number);
		index++;
	}
	if ((container.size() % 2) != 0) {
		location = binSearch(*(--container.end()), main_chain.begin(), main_chain.end());
		main_chain.insert(location, *(--container.end()));
	}
	verbose("[ JACOBING ]", jacobSequence, insertionOrder);
	verbose("[ INSERTING ]", main_chain, pend_chain);
	return (main_chain);
}

// ----------------------------------------------------------------- JACOBSTAHL
/*	Create the Jacobsthal number sequence based on the container size. Jacobstahl
	rule: start with 0 and 1, and then (prev+(prev_prev*2)).
	@param jN: current calculating jacobsthal */
template <typename T>
T createJacobsthalSequence( T container ) {
	T jacobSequence;
	unsigned int prev_prev;
	unsigned int prev;
	unsigned int jN = 0;

	jacobSequence.push_back(0);
	jacobSequence.push_back(1);
	size_t i = 0;
	while(jN < static_cast<unsigned int>(container.size())) {
		prev_prev = jacobSequence[i];
		prev = jacobSequence[i + 1];
		jN = prev + (prev_prev * 2);
		jacobSequence.push_back(jN);
		i++;
	}
	return (jacobSequence);
}

/*	Create the insertion order that the insertion sort will have to follow to
	insert the items of the pend chain into the main one. This order follows
	the jacobsthal numbers sequence.
	@line: jacobSequence.erase(jacobSequence.begin() + 1); remove the second
	item from the sequence 0 {1} 1 3 5 11 21 (pretty odd, but it's the same
	if I pop and push the first of pend to main, and then start from 1). */
template <typename T>
T createInsertionOrder( T jacobSequence, size_t container_size ) {
	jacobSequence.erase(jacobSequence.begin() + 1);
	T insertionOrder;
	typename T::iterator jit = jacobSequence.begin();
	unsigned int n;
	unsigned int prev;
	while (insertionOrder.size() != (container_size / 2)) {
		n = *jit;
		if (jit == jacobSequence.begin()) {
			insertionOrder.push_back(n);
			prev = n;
			jit++;
			continue ;
		}
		while (n != prev) {
			insertionOrder.push_back(n);
			n--;
			if (insertionOrder.size() == (container_size / 2))
				break ;
		}
		prev = *jit;
		jit++;
	}
	return (insertionOrder);
}


// ---------------------------------------------------------------------- UTILS
/*	The function takes a container of pairs and retrieves a container of the same
	type, with just the first (main chain) or the second (pend) items of the
	pairs, based on the type passed. */
template <typename T, typename U>
T createChain( U pair_container, e_chain type ) {
	T chain;
	typename U::iterator it = pair_container.begin();
	while (it != pair_container.end()) {
		if (type == MAIN)
			chain.push_back((*it).first);
		else if (type == PEND)
			chain.push_back((*it).second);
		it++;
	}
	return (chain);
}

/*	BinarySearch using iterators; basically respect the same principles, so the
	sequence of numbers in which the items has to find place, has to be sorted. */
template <typename T>
T binSearch( unsigned int item, T begin, T end ) {
	if (begin == end)
		return (begin);
	long int m = std::distance(begin, end) / 2;
	T mid = begin + m;
	if (item < *mid)
		return (binSearch(item, begin, mid));
	else if (item > *mid)
		return (binSearch(item, mid+1, end));
	return (mid+1);
}

template <typename T>
bool isSorted( T container ) {
	typename T::iterator it = container.begin();
	while (it != container.end()) {
		if ((it + 1) == container.end())
			break ;
		if (*it > *(it + 1))
			return (false);
		it++;
	}
	return (true);
}


// -------------------------------------------------------------------- DISPLAY
/*	If the number are grater than 5 digits, change the value set by std::setw()
	to see the cells well aligned. */
static void displayItem( int n ) { std::cout << std::right << "[" << std::setw(5) << n << "]"; };
template<typename T>
void displayCont( T container, std::string title ) {
	std::cout << std::setw(20) << std::left << title;
	typename T::iterator end = container.end();
	if (container.size() > 15)
		end = container.begin() + 15;
	std::for_each(container.begin(), end, displayItem);
	if (container.size() > 15)
		std::cout << "[...]";
	std::cout << std::endl;
}

template<typename T>
void displayTime(size_t size, e_cont type, double elapsed_time, T result_container) {
	std::cout << "Time to process " << size << " items using "
		<< (type == VECTOR ? "std::vector" : "std::deque")
		<< std::fixed << std::setprecision(6) << ": " << elapsed_time/CLOCKS_PER_SEC << " us" << std::endl;
	if (VERBOSE) {
		if (isSorted(result_container))
			std::cout << "\e[0;32m[ SORTED! ]\e[0;37m" << std::endl;
		else
			std::cout << "\e[0;31m[ NOT SORTED! ]\e[0;37m" << std::endl;
	}
}

template<typename T>
void verbose( std::string step, T first, T second ) {
	if (!VERBOSE)
		return ;
	displayCont(first, step);
	displayCont(second, step);
	for (unsigned int i = 0; i < 120; i++)
		std::cout << "-";
	std::cout << std::endl;
}

#endif /* __UTILS_HPP__ */
