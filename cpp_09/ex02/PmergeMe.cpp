/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:14:39 by nico              #+#    #+#             */
/*   Updated: 2024/03/29 12:28:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ----------------------------- CANONICAL FORM
PmergeMe::PmergeMe( void ) {}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe& ) {
	// implement
}

PmergeMe& PmergeMe::operator=( const PmergeMe& rhs ) {
	// implement
}

// ------------------------- OTHER CONSTRUCTORS
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

		// check for overflow --------------------- !!!!!!
		_vect.push_back(std::atoi(digits.c_str()));
		arg.erase(0, digits.length());
	}
}

// -------------------------------- SORTING
void PmergeMe::fordJohnson( void ) {
	std::cout << "Size = " << _vect.size() << std::endl;

	pair_vect_t pv = createPairVect();
	std::cout << std::setw(25) << std::left << "[ PAIR VECTOR ]" << pv;
	if (_vect.size() % 2 != 0)
		std::cout << "[~" << _vect.back() << "~]";
	std::cout << std::endl;

	std::sort(pv.begin(), pv.end()); // need to replace with mergeSort --------- !!!!!!
	std::cout << std::setw(25) << std::left << "[ AFTER SORT by highest ]" << pv << std::endl;

	std::vector<int> main_chain = createMainChain(pv);
	int last = -1;
	if (_vect.size() % 2 != 0)
		last = _vect.back();
	std::vector<int> pend_chain = createPendChain(pv, last);

	std::cout << std::endl << "[--- before insertion ---]" << std::endl;
	std::cout << std::setw(25) << std::left << "[ MAIN CHAIN ]" << main_chain << std::endl;
	std::cout << std::setw(25) << std::left << "[ PEND CHAIN ]" << pend_chain << std::endl;

	std::vector<int> insertion_order = createInsertionOrder(main_chain, pend_chain);
	std::cout << std::setw(25) << std::left << "[ ins_order ] " << insertion_order << std::endl;
	std::cout << std::setw(25) << std::left << "[ ins_order size ] " << insertion_order.size() << std::endl;

	insertion(main_chain, pend_chain, insertion_order);

	std::cout << std::setw(25) << std::left << "[ SORTED CHAIN ]" << main_chain << std::endl;
	// create a is_sorted() function
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
		pend_chain.push_back(last); // the straggle element is added to the pend chain
	return (pend_chain); // pend_chain is not sorted yet !!!
}

/*	The Jacobsthal numbers are used in order to leverage the worst case. The steps:
	1) The sequence of Jacosthal nums is generated
	2) A mix between the J sequence and real ins_order is created
	3) This combination is the order followed to pick the items from the pend_chain
	4) Those items are inserted into the main_chain using binary search

	Example:
	1) [0, 1, 1, 3, 5, 11, 21, 43 ...] (Jacobsthal numbers)
	2) [0, 1, 2, 3, 4, 5, 6, 7, .....] (normal ins_order)
	3) {3} 2 {5} 4 {11} 10 9 8 7 6 {21} 20 19 ... 12 {43} (combination)
	Note: numbers in curly br. comes from the Jacobsthal numbers; it starts from
	3 because the first element of the pend_chain is simply popped and pushed to main.
*/
std::vector<int> PmergeMe::createInsertionOrder( std::vector<int> main, std::vector<int> pend ) {
	std::vector<int> jacob;
	std::vector<int> ins_order; // collection of the order of the ins_order to pick from pend chain
	long prev_prev;
	long prev;
	long n = 0;


	jacob.push_back(0); // the jacob numbers are created starting from the second 1
	jacob.push_back(1); // then it will have to be started from idx 1
	int i = 0;
	while(true) { // modify the condition: stop when the size of pend_chain is reached!
		prev_prev = jacob[i];
		prev = jacob[i + 1];
		n = prev + (prev_prev * 2);
		if (n > std::numeric_limits<int>::max())
			break ;
		jacob.push_back(static_cast<int>(n));
		updateInsertionOrder(ins_order, static_cast<int>(n), prev, static_cast<int>(pend.size()));
		if (n >= static_cast<int>(pend.size())) break ; //finish to populate the ins_order vector
		i++;
	}
	return (ins_order);
}

void PmergeMe::updateInsertionOrder( std::vector<int>& ins_order, int n, int prev_jacob, int pend_size ) {
	if (pend_size > n) {
		ins_order.push_back(n);
		if (n == 1) return ; // verify
		while (--n != prev_jacob)
			ins_order.push_back(n);
	}
	else if (pend_size <= n) {  // in this case I populate ins_order not FROM TO because otherwise i TOO MUCH items than needed
		int n_idx_left = (pend_size - 1) - ins_order.size(); // (pend_size - 1) because the first element is ease pushed since it is 100% sure
		std::vector<int> tmp;
		while (--n != prev_jacob)
			tmp.push_back(n); // tmp contains a jacobsthal range which has to be cut to dont have more then the needed elements
		std::vector<int>::iterator it = tmp.end() - n_idx_left; // 11 10 9 8 [7] 6
		while (it != tmp.end()) {
			ins_order.push_back(*it++);
		}
		return ;
	}
}

void PmergeMe::insertion( std::vector<int>& main, std::vector<int>& pend, std::vector<int>& ins_order ) {
	std::cout << std::endl << "[--- insertion ---]" << std::endl;
	main.insert(main.begin(), pend.front());	// the first element of pend chain is 100% smaller
	pend[0] = -1; // to preserve the relations/indexes, NOTHING IS POPPED! Maybe just set to (-1) to visualize
	std::cout << "!!! First element of pend pushed to main but NOT POPPED from pend !!!" << std::endl;
	std::cout << std::setw(25) << std::left << "[ MAIN CHAIN ]" << main << std::endl;
	std::cout << std::setw(25) << std::left << "[ PEND CHAIN ]" << pend << std::endl;
	std::cout << std::setw(25) << std::left << "[ ins_order ]" << ins_order << std::endl;

	size_t i = 0;
	while (i < (pend.size() - 1)) { // (pend.size()-1) because ONE is already pushed
		int item = *(pend.begin() + ins_order[i]);
		std::cout << std::endl << "Find place for { " << item << " }" << std::endl;
		int location = binarySearch(main, item, 0, main.size()-1);
		main.insert(main.begin() + location, item);
		std::cout << main << std::endl;
		i++;
	}
}

int PmergeMe::binarySearch( std::vector<int>& main, int item, int start, int end ) {
	std::cout << std::setw(25) << std::left << "[--- binary search ---] ";
	if (start >= end) {
		if (item < main[start])
			return (start);
		return (start + 1);
	}

	size_t mid = (start + end) / 2;
	int mid_item = main[mid];

	if (item > mid_item)
		return (binarySearch(main, item, mid+1, end));
	if (item < mid_item)
		return (binarySearch(main, item, start, mid-1));
	return (mid + 1);
}

// -------------------------------- DISPLAY
std::ostream& operator<<( std::ostream& cout, std::vector<int> vect ) {
	std::for_each(vect.begin(), vect.end(), displayVectorInt);
	return (cout);
}

std::ostream& operator<<( std::ostream& cout, std::vector<std::pair<int,int> > vect ) {
	std::for_each(vect.begin(), vect.end(), displayVectorPair);
	return (cout);
}
