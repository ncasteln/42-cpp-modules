/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/08 08:35:56 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SWAP_HPP__
# define __SWAP_HPP__

/*
	Since the templates are compiled only by request, the declaration and
	definition have to be in the same file.
	template <typename T> and template <class T> have exactly the same effect,
	they are just different keywords.
*/
template <typename T> void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

#endif
