/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 16:22:02 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>


/*	EVALUATION
	- Check theory over .hpp class
	- Constructors how they should be ???

	RESUME
	The exercise shows how to use reinterpret_cast, used to cast a type to
	another complete different type. In this case uintptr_t is used so that
	data is preserved.
	During serialization of the object, the pointer of Data* is reinterpreted
	as uintptr_t. During deserialization, the opposite process is performed.
	During this cast and re-cast, the data is preserved.
*/
int main ( void ) {
	Data obj;

	obj.i = 34;
	obj.f = 0.42f;
	obj.d = 9999.01234567890987654321;

	std::cout << "[ Before serialization ]" << std::endl;
	std::cout << "| i            : " << obj.i << std::endl;
	std::cout << "| f            : " << obj.f << std::endl << std::endl;
	std::cout << "| d            : " << obj.d << std::endl << std::endl;

	//////////////////////////////////////////////////////

	uintptr_t serialized = Serializer::serialize(&obj);
	std::cout << "[ Serialized value ]" << std::endl;
	std::cout << "| value stored      : " << serialized << std::endl;
	std::cout << "| obj address       : " << &obj << std::endl;
	std::cout << "| serialized to hex : " << std::hex << serialized << std::endl << std::endl;

	//////////////////////////////////////////////////////

	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "[ After serialization ]" << std::endl;
	std::cout << "| obj address  : " << &deserialized << std::endl;
	std::cout << "| i            : " << deserialized->i << std::endl;
	std::cout << "| f            : " << deserialized->f << std::endl;
	std::cout << "| d            : " << deserialized->d << std::endl << std::endl;
	return (0);
}
