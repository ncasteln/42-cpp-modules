/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 10:10:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

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
	std::cout << "| deserialized address  : " << deserialized << std::endl;
	std::cout << "| i                     : " << deserialized->i << std::endl;
	std::cout << "| f                     : " << deserialized->f << std::endl;
	std::cout << "| d                     : " << deserialized->d << std::endl;
	std::cout << "| s                     : " << deserialized->s << std::endl << std::endl;
	return (0);
}
