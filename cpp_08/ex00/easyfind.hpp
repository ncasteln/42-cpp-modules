/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:51 by nico              #+#    #+#             */
/*   Updated: 2024/03/09 16:59:09 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

/*	Example of template function specialization syntax
	template <typename T> void f( T a ) {};
	template <> void f<int>( int a ) {};
*/

/* deque - list - queue - stack - vector */

template <typename Iter>
void iter( Iter begin, Iter end ) {
	while (begin != end)
		begin++;
}

template <typename T>
void easyfind( T& container, int n ) {
	std::cout << "Generic" << std::endl;

	// T::iterator it =
	std::find(container.begin(), container.end(), n) == container.end();
	// if (*p == container.end())
	// 	std::cout << "NEIN" << std::endl;
	// else
	// 	std::cout << "JA" << std::endl;
}

// template <> void easyfind< std::vector<int> >( std::vector<int> v, int n ) {
// 	std::cout << "Vector" << std::endl;
// }

// template <> void easyfind< std::list<int> >( std::list<int> v, int n ) {
// 	std::cout << "List" << std::endl;
// }

#endif
