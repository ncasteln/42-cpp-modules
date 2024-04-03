/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:23:32 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:26:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SWAP_HPP__
# define __SWAP_HPP__

/*	TEMPLATE DEFINITION
	Since the templates are compiled only by request, the declaration and
	definition have to be in the same file (or use something like .tpp file).

	template <typename T> and template <class T> have exactly the same effect,
	they are just different keywords.
*/
template <typename T> void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

#endif
