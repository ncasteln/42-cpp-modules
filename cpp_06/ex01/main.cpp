/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 10:48:22 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ( void ) {
	Data obj;

	uintptr_t serialized = Serializer::serialize(&obj);
	Data* deserialized = Serializer::deserialize(serialized);

	return (0);
}
