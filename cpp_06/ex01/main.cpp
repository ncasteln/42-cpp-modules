/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/02 14:49:25 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>


/*
	*** RESUME
	The exercise shows how to use reinterpret_cast, used to cast a type to
	another complete different type. In this case uintptr_t is used so that
	data is preserved.
	During serialization of the object, the pointer of Data* is reinterpreted
	as uintptr_t. During deserialization, the opposite process is performed.
	During this cast and re-cast, the data is preserved.

	See Serializer.hpp to check other theory.

	*** VERIFY
	- Constructors how they should be ???

	*** SOLVED
	- WHY THE FUCK the integer changes ??? try 10 becomes a, etc
		Because when I use std::hex, it is saved for every following std::cout, so
		pay attention to reset to default using std:dec. The result was the hex
		conversion of the integer.
*/
int main ( void ) {
	Data obj;

	obj.i = 34;
	obj.f = 0.42f;
	obj.d = 9999.01234567890987654321;
	obj.s = "HelloWorld?";

	std::cout << "[ Before serialization ]" << std::endl;
	std::cout << "| obj address  : " << &obj << std::endl;
	std::cout << "| i            : " << obj.i << std::endl;
	std::cout << "| f            : " << obj.f << std::endl;
	std::cout << "| d            : " << obj.d << std::endl;
	std::cout << "| s            : " << obj.s << std::endl << std::endl;

	//////////////////////////////////////////////////////

	uintptr_t serialized = Serializer::serialize(&obj);
	std::cout << "[ Serialized ]" << std::endl;
	std::cout << "| value stored        : " << serialized << std::endl;
	std::cout << "| value stored to hex : " << std::hex << serialized << std::dec << std::endl << std::endl;

	//////////////////////////////////////////////////////

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "[ After deserialization ]" << std::endl;
	std::cout << "| deserialized address  : " << &deserialized << std::endl;
	std::cout << "| i                     : " << deserialized->i << std::endl;
	std::cout << "| f                     : " << deserialized->f << std::endl;
	std::cout << "| d                     : " << deserialized->d << std::endl;
	std::cout << "| s                     : " << deserialized->s << std::endl << std::endl;
	return (0);
}
