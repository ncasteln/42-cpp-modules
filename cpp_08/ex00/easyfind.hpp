/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:51 by nico              #+#    #+#             */
/*   Updated: 2024/03/15 11:18:05 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <algorithm>
#include <iterator>		// std::distance

/*
	The type returned by the function is not specified by the subject. I could
	choose between [long int] to evidence the position of the first occurrence,
	or [typename T::iterator], and verify the result outside. I choose the
	first one.

	The function doesn't work with stack and queue, since they are not
	traversable using iterators.
*/
template <typename T>
long int easyfind( T& container, int n ) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		return (-1);
	return (std::distance(container.begin(), it));
}

#endif
