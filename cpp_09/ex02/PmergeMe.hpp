/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:55 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/09 16:12:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include <exception>
#include "utils.hpp" // move
#include <vector>
#include <list>

#ifndef	VERBOSE
# define VERBOSE	0
#endif

typedef enum cont {
	VECTOR,
	DEQUE
}	e_cont;

// ************************************************************* CLASS DEFINITION
template <typename T>
class PmergeMe
{
	private:
		T _container;
		e_cont _type;
		PmergeMe( void ); // ----------------------------------- CANONICAL FORM
	public:
		~PmergeMe( void );
		PmergeMe( const PmergeMe& );
		PmergeMe& operator=( const PmergeMe& );
		PmergeMe( int argc, char** argv, e_cont type ); // -- PARAM CONSTRUCTOR

		class InvalidInput; // ------------------------------------- EXCEPTIONS
};



// ************************************************************* IMPLEMENTATION
// ------------------------------------------------------------- CANONICAL FORM
template <typename T> PmergeMe<T>::PmergeMe( void ) {};
template <typename T> PmergeMe<T>::~PmergeMe( void ) {};
template <typename T> PmergeMe<T>::PmergeMe( const PmergeMe& obj ) {
	// need implementation
}
template <typename T> PmergeMe<T>& PmergeMe<T>::operator=( const PmergeMe& rhs ) {
	// need implementation
}

// ---------------------------------------------------------- PARAM CONSTRUCTOR
template <typename T>
PmergeMe<T>::PmergeMe( int argc, char** argv, e_cont type ): _type(type) {
	if (parse(argc, argv, _container))
		throw InvalidInput();
	displayContainer(_container);

	// clock start
	if (_type == VECTOR) {
		std::vector<std::pair<int, int> > pair_vector;
		pairing(_container, pair_vector);
		displayContainerPair(pair_vector);
		mergeSort(pair_vector);
		// insert(pair_vector);
	}
	else {
		// std::vector<std::pair<int, int> > pair_list;
		// pairing(_container, pair_list);
		// displayContainerPair(pair_list);
	}
}

// ----------------------------------------------------------------- EXCEPTIONS
template <typename T>
class PmergeMe<T>::InvalidInput: public std::exception {
	const char* what() const throw() { return ("invalid input"); };
};


#endif /* __PMERGEME_HPP__ */
