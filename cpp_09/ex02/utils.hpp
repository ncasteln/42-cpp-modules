/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:46:05 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/10 12:59:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
void extract_numbers( std::string arg, T& container ) {
	size_t pos;
	std::string number;

	while (!arg.empty()) {
		pos = arg.find_first_not_of(" \t"); // left trim of whitespaces
		if (pos == std::string::npos) break ; // means, if there are no other member is finished
		arg.erase(0, pos);
		pos = arg.find_first_not_of("1234567890"); // reach the end of the number, can be also end of the string
		number = arg.substr(0, pos);
		// check for overflow --------------------- !!!!!!
		container.push_back(std::atoi(number.c_str()));
		arg.erase(0, number.length());
	}
}

template <typename T>
int parse( int argc, char** argv, T& container ) {
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg.find_first_not_of("1234567890 \t") != std::string::npos)
			return (1);
		extract_numbers(arg, container);
	};
	if (container.empty())
		return (1);
	return (0);
}

// -------------------------------------------------------------------- DISPLAY
static void displayItem( int item ) { std::cout << "[ " << item << " ]"; }
template <typename T>
void displayContainer( T container ) {
	std::cout << std::setw(20) << std::left << "[ CONTAINER ] ";
	std::for_each(container.begin(), container.end(), displayItem);
	std::cout << std::endl;
}

static void displayPair( std::pair<int, int> p ) { std::cout << "[ " << p.first << " , " << p.second << " ] "; }
static void displayPairFirst( std::pair<int, int> p ) { std::cout << "[ " << p.first << "] "; }
template <typename T>
void displayContainerPair( T container, int both ) {
	std::cout << std::setw(20) << std::left << "[ PAIR_CONTAINER ]";
	if (both)
		std::for_each(container.begin(), container.end(), displayPair);
	else
		std::for_each(container.begin(), container.end(), displayPairFirst);
	std::cout << std::endl;
}

// -------------------------------------------------------------------- PAIRING
template <typename T, typename U>
void pairing( T& container, U& pair_container ) {
	std::pair<int, int> p;
	size_t isOddSize = 0;  // remember the last item in case the number of them is ODD ------ needed ?????????

	if (container.size() % 2 != 0) // in the first step isOddSize is used to change the for loop, then hols a "real" value
		isOddSize = 1;
	for (size_t i = 0; i < container.size() - isOddSize; i += 2) {
		p = std::make_pair(container[i], container[i + 1]); // create a pair two-by-two
		if (p.first > p.second)
			std::swap(p.first, p.second);
		pair_container.push_back(p); // push to the vector
	}
}

// -------------------------------------------------------------------- SORTING
template <typename T>
void mergeSort( T& container, std::vector<std::pair<int, int> >::iterator l, std::vector<std::pair<int, int> >::iterator r, std::vector<std::pair<int, int> > temp ) {

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

#endif /* __UTILS_HPP__ */
