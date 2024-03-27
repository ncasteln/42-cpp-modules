/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:14:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/27 16:05:43 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ------------------------------------------------------------- CANONICAL FORM
PmergeMe::PmergeMe( void ) {}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe& ) {
	// implement
}

PmergeMe& PmergeMe::operator=( const PmergeMe& rhs ) {
	// implement
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/*	METHODS TO PARSE A STRING
	- Use of Iterators and erase()

*/
/*	Construct the instance by parsing the arguments. In the first steps is
	checked if the string contains something else other digits whitespaces
	or tabs. */
PmergeMe::PmergeMe( int argc, char** argv ) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		// if (arg.empty()) // discard directly "" ----- removed, it seems to work the same
		// 	continue ;
		if (arg.find_first_not_of("1234567890 \t") != std::string::npos) //exit when an arg contains other than nums or spaces/tabs
			throw InvalidInput();
		extract_numbers(arg);
	};
	if (_vect.empty()) // happens in case of "  " and/or ""
		throw InvalidInput();
}

/*	Helper function which has to extract the numbers in an argument. It can
	recieve either something with a single number like "4" or "   4   ", or
	with multple numbers like "  4   9   12   ". */
void PmergeMe::extract_numbers( std::string arg ) {
	size_t pos;
	std::string digits;

	while (!arg.empty()) {
		pos = arg.find_first_not_of(" \t"); // left trim of whitespaces
		if (pos == std::string::npos) break ; // means, if there are no other member is finished
		arg.erase(0, pos);
		pos = arg.find_first_not_of("1234567890"); // reach the end of the number, can be also end of the string
		digits = arg.substr(0, pos);

		// check for overflow --------------------------------------------- !!!!!!
		_vect.push_back(std::atoi(digits.c_str()));
		arg.erase(0, digits.length());
	}
}

// -------------------------------------------------------------------- SORTING
void PmergeMe::fordJohnson( void ) {
	pair_vect_t pv = createPairVect();
	std::cout << std::setw(25) << std::left << "[ PAIR VECTOR ]" << pv << std::endl;

	std::sort(pv.begin(), pv.end()); // probably need to replace with mergeSort ------------- !!!!!!
	std::cout << std::setw(25) << std::left << "[ AFTER SORT and REV ]" << pv << std::endl;

	std::vector<int> main_chain = createMainChain(pv);
	std::cout << std::setw(25) << std::left << "[ MAIN CHAIN ]" << main_chain << std::endl;

	int last = -1;
	if (_vect.size() % 2 != 0)
		last = _vect.back();
	std::vector<int> pend_chain = createPendChain(pv, last);
	std::cout << std::setw(25) << std::left << "[ PEND CHAIN ]" << pend_chain << std::endl << std::endl;

	// the first element of pend_chain is SURE smaller than the first of main_chain
	main_chain.insert(main_chain.begin(), *pend_chain.begin());
	pend_chain.erase(pend_chain.begin());
	std::cout << std::setw(25) << std::left << "[ MAIN CHAIN ]" << main_chain << std::endl;
	std::cout << std::setw(25) << std::left << "[ PEND CHAIN ]" << pend_chain << std::endl;

	jacobsthalInsertion(main_chain, pend_chain);
}

PmergeMe::pair_vect_t PmergeMe::createPairVect( void ) {
	std::pair<int, int> p;
	pair_vect_t pv; // create a vector which holds the pairs

	int isOddSize = 0;  // remember the last item in case the number of them is ODD
	if (_vect.size() % 2 != 0) // in the first step isOddSize is used to change the for loop, then hols a "real" value
		isOddSize = 1;
	for (size_t i = 0; i < _vect.size() - isOddSize; i += 2) {
		p = std::make_pair(_vect[i], _vect[i + 1]); // create a pair two-by-two
		if (p.first < p.second) std::swap(p.first, p.second); // swap directly in case first > second
		pv.push_back(p); // push to the vector
	}
	return (pv);
}

std::vector<int> PmergeMe::createMainChain( pair_vect_t pv ) {
	std::vector<int> main_chain;
	pair_vect_t::iterator it = pv.begin();
	while (it != pv.end())
		main_chain.push_back((*it++).first); // main chain is composed by the larger element of each pair
	return (main_chain); // main chain is already sorted before
}

std::vector<int> PmergeMe::createPendChain( pair_vect_t pv, int last ) {
	std::vector<int> pend_chain;
	pair_vect_t::iterator it = pv.begin();
	while (it != pv.end())
		pend_chain.push_back((*it++).second); // pend chain is composed by the smallest element of each pair
	if (last != -1)
		pend_chain.push_back(last);
	return (pend_chain); // pend_chain is not sorted yet !!!
}

/* The jacobSequence is used in order to leverage the worst case. The jacob
numbers are used! */
void PmergeMe::jacobsthalInsertion( std::vector<int> main, std::vector<int> pend ) {
	std::vector<int> jacob;
	long prev_prev;
	long prev;
	long n;

	jacob.push_back(0);
	jacob.push_back(1);
	int i = 0;
	while(true) {
		prev_prev = jacob[i];
		prev = jacob[i + 1];
		n = prev + (prev_prev * 2);
		if (n > std::numeric_limits<int>::max())
			break ;
		jacob.push_back(static_cast<int>(n));
		i++;
	}
	std::cout << jacob << std::endl;
}

// -------------------------------------------------------------------- DISPLAY
std::ostream& operator<<( std::ostream& cout, std::vector<int> vect ) {
	std::for_each(vect.begin(), vect.end(), displayVectorInt);
	return (cout);
}

std::ostream& operator<<( std::ostream& cout, std::vector<std::pair<int,int> > vect ) {
	std::for_each(vect.begin(), vect.end(), displayVectorPair);
	return (cout);
}

/*
	std::cout << std::setw(25) << std::left << "[ VECTOR OF PAIRS ]"; // what happens in case of ODD number of elements ????
	std::pair<int, int> p;
	std::vector<std::pair<int, int> > pair_vect; // create a vector which holds the pairs

	for (size_t i = 0; i < _vect.size(); i += 2) {
		p = std::make_pair(_vect[i], _vect[i + 1]);
		pair_vect.push_back(p);
		std::cout << "[" << p.first << "," << p.second << "]";
	}
	std::cout << std::endl;

	std::cout << std::setw(25) << std::left << "[ VECTOR OF SORTED PAIRS ]"; // what happens in case of ODD number of elements ????
	std::for_each(pair_vect.begin(), pair_vect.end(), swap_pair);
	std::cout << std::endl;




*/




/*
	int jacob[] = { 0, 1, 1 };
	int prev;
	int prev_prev;

	int i = 2;
	while (jacob[0] <= 349525) {
		if (i == 0) {
			prev = jacob[2];
			prev_prev = jacob[1];
		}
		if (i == 1) {
			prev = jacob[0];
			prev_prev = jacob[2];
		}
		if (i == 2) {
			prev = jacob[1];
			prev_prev = jacob[0];
		}
		jacob[i] = prev + (prev_prev*2);
		std::cout << "[" << jacob[0] << " " << jacob[1] << " "  << jacob[2] << "]" << std::endl;

		i++;
		if (i == 3)
			i = 0;
	}

*/
