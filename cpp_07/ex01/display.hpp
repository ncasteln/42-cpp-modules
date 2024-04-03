/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:14 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 16:24:15 by ncasteln         ###   ########.fr       */
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
template <typename T> void display( T item ) {
	std::cout << "[ " << item << " ] ";
}

#endif
