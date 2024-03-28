/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:13:48 by nico              #+#    #+#             */
/*   Updated: 2024/03/28 11:33:52 by nico             ###   ########.fr       */
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
#include <vector>
#include <limits>
#include "utils.hpp"

class PmergeMe
{
	typedef std::vector<std::pair <int, int> > pair_vect_t;

	private:
		std::vector<int> _vect;
	public:

		PmergeMe( void );
		~PmergeMe( void );
		PmergeMe( const PmergeMe& );
		PmergeMe& operator= (const PmergeMe& );

		PmergeMe( int argc, char** argv ); // remove ???

		void extract_numbers( std::string ); // make private what ???

		void fordJohnson( void );
		pair_vect_t createPairVect( void );
		std::vector<int> createMainChain( pair_vect_t pv );
		std::vector<int> createPendChain( pair_vect_t pv, int last );
		std::vector<int> createInsertionOrder( std::vector<int>, std::vector<int> );
		void updateInsertionOrder( std::vector<int>& ins_order, int n, int prev_jacob, int pend_size );
		void insertion( std::vector<int>& main, std::vector<int>& pend, std::vector<int>& indexes );
		void binarySearch( std::vector<int>& main, std::vector<int>& pend, std::vector<int>& indexes );

		class InvalidInput;
};

class PmergeMe::InvalidInput: public std::exception {
	const char* what() const throw() { return ("invalid input"); };
};

std::ostream& operator<<( std::ostream& cout, std::vector<int> vect );
std::ostream& operator<<( std::ostream& cout, std::vector<std::pair<int,int> > vect );

#endif /* __PMERGEME_HPP__ */
