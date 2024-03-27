/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:40:13 by nico              #+#    #+#             */
/*   Updated: 2024/03/27 10:00:39 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void displayVectorInt( int item ) {
	std::cout << "[ " << item << " ]";
}

void displayVectorPair( std::pair<int, int> item ) {
	std::cout << "[ " << item.first << "," << item.second << " ]";
}
