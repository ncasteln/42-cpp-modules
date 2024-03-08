/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:12:11 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 09:29:07 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

#include <iostream>

/*
	A function template called by iter was not required but in some way
	suggested. IMPORTANT: when called by ::iter we need to specify the type
	that ::display takes in order to work.
*/
template <class T> void display( T item ) {
	std::cout << "[ " << item << " ] ";
}

#endif
