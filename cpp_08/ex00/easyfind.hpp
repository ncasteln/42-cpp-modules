/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:25:17 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:25:19 by ncasteln         ###   ########.fr       */
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
