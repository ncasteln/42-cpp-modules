/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:10:46 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 10:10:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

#include "Data.hpp"
#include <stdint.h>	// uintptr_t

/*
	[uintptr_t] an unsigned integer type with the property that any valid
	pointer to void can be converted to this type, then converted back to
	pointer to void, and the result will compare equal to the original pointer.
	In other words, it stores a pointer value and consequently all its data.

	[serialization] is the process of converting an object or data structure into
	a format that can be easily stored or transmitted and later reconstructed.
	The reverse process, which involves reconstructing the object, is called
	deserialization.

	[reinterpret_cast] to perform type conversions on UNRELATED TYPES. We should
	use this type of cast only when absolutely necessary.
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
		void operator=( Serializer& );
};

#endif
