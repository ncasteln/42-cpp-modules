/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:46:00 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/09 08:46:01 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void displayVectorInt( int item ) {
	std::cout << "[ " << item << " ]";
}

void displayVectorPair( std::pair<int, int> item ) {
	std::cout << "[ " << item.first << "," << item.second << " ]";
}
