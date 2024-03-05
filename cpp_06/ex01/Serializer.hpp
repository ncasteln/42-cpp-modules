/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:53 by ncasteln          #+#    #+#             */
/*   Updated: 2024/03/05 10:06:44 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

#include "Data.h"
#include <stdint.h>

/*
	[uintptr_t] : an unsigned integer type with the property that any valid
	pointer to void can be converted to this type, then converted back to
	pointer to void, and the result will compare equal to the original pointer

	[serialization] is the process of converting an object or data structure into
	a format that can be easily stored or transmitted and later reconstructed.
	The reverse process, which involves reconstructing the object is called
	deserialization.
*/

class Serializer
{
	public:
		// ------------------------------------------------------ SERIALIZATION
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		Serializer( void );
		~Serializer( void );
		Serializer( const Serializer& );
		Serializer& operator=( Serializer& );
};

#endif
