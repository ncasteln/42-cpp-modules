/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:14 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/04 14:24:25 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

#include <iostream>

template <typename T> void display( T item ) {
	std::cout << "[" << item << "] ";
}

#endif
