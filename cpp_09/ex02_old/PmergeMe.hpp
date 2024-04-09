/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:55 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/09 14:13:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include "utils.hpp"

#include <vector>
#include <list>

typedef enum cont {
	VECTOR, LIST
}	e_cont;

class PmergeMe
{
	typedef std::vector<std::pair <int, int> > pair_vect_t;

	private:
		std::vector<int> _vect;
		std::list<int> _list;
		e_cont _type;
	public:
		PmergeMe( void );
		~PmergeMe( void );
		PmergeMe( const PmergeMe& );
		PmergeMe& operator= ( const PmergeMe& );

		PmergeMe( int argc, char** argv, e_cont type );

		void extract_numbers( std::string ); // make private what ???
		void fordJohnson( void );
		pair_vect_t createPairVect( void );
		std::vector<int> createMainChain( pair_vect_t pv );
		std::vector<int> createPendChain( pair_vect_t pv, int last );
		std::vector<int> createInsertionOrder( std::vector<int>, std::vector<int> );
		void updateInsertionOrder( std::vector<int>& ins_order, int n, int prev_jacob, int pend_size );
		void insertion( std::vector<int>& main, std::vector<int>& pend, std::vector<int>& indexes );
		int binarySearch( std::vector<int>& main, int item, int start, int end );
		bool isSorted( std::vector<int> );

		class InvalidInput;
};

class PmergeMe::InvalidInput: public std::exception {
	const char* what() const throw() { return ("invalid input"); };
};

std::ostream& operator<<( std::ostream& cout, std::vector<int> vect );
std::ostream& operator<<( std::ostream& cout, std::vector<std::pair<int,int> > vect );

#endif /* __PMERGEME_HPP__ */
