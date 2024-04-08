/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:17 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/08 11:03:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <algorithm>
#include <stdexcept>

/*
	The type returned by the function is not specified by the subject. I could
	choose between [long int] to evidence the position of the first occurrence
	(long int is the return value of std::distance), or [typename T::iterator],
	and verify the result outside. I try both approaches.

	I tried to overload the function to use both versions, but it's NOT
	POSSIBLE to overload only by the return value.

	The function doesn't work with stack and queue, since they are not
	traversable using iterators.
*/

// ****************************** first approach ******************************
/* template <typename T>
long int easyfind( T& container, int n ) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		return (-1);
	return (std::distance(container.begin(), it));
} */

// **************************** second approach *******************************
template <typename T>
typename T::iterator easyfind( T& container, int n ) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Item NOT found!");
	return (it);
}

#endif
