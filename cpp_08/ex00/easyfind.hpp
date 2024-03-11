/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:51 by nico              #+#    #+#             */
/*   Updated: 2024/03/11 07:08:26 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <algorithm>
#include <iterator>		// std::distance
#include <stack>

/*
	The type returned by the function is not specified by the subject. I could
	choose between [long int] to evidence the position of the first occurrence,
	or [typename T::iterator], and verify the result outside.
*/
template <typename T>
long int easyfind( T& container, int n ) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (std::distance(it, container.end()) == 0)
		return (-1);
	return (std::distance(container.begin(), it));
}

/*	Example of template function specialization syntax
	template <typename T> void f( T a ) {};
	template <> void f<int>( int a ) {};
*/
template <>
long int easyfind<std::stack<int> >( std::stack<int>& container, int n ) {

}

#endif
