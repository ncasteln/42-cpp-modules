/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:51:08 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 13:51:39 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <exception>
#include <iostream>

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _size;
	public:
		// ----------------------------------------------------- CANONICAL FORM
		Array( void ): _array(0), _size(0) {};
		~Array( void ) {
			delete [] _array;
		};
		Array( const Array& obj ) {
			_size = obj._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = obj._array[i];
		};
		Array& operator=( const Array& rhs ) {
			this->_size = rhs._size;
			for (unsigned int i = 0; i < _size; i++)
				this->_array[i] = rhs._array[i];
			return (*this);
		};

		// ------------------------------------------------- OTHER CONSTRUCTORS
		Array( unsigned int n ) {
			_array = new T[n];
			for (unsigned int i = 0; i < n ; i++)
				_array[i] = T(); // init different types ???
			_size = n;
		};

		// ---------------------------------------------------------- OVERLOADS
		T& operator[]( unsigned int n ) {
			try {
				if (n >= _size)
					throw std::out_of_range("Error: access with operator[] out of bounds");
				return (_array[n]);
			} catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return (_array[n]);
		};
		/* Called when the instance is const */
		const T& operator[]( unsigned int n ) const { // same as the other one ?
			return (_array[n]);
		};

		// ----------------------------------------------------- MEMB FUNCTIONS
		unsigned int size( void ) const;
};

/* Example of syntax, in which the implementation is separated by the declaration. */
template <typename T>
unsigned int Array<T>::size ( void ) const {
	return (_size);
}

#endif
