/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:51:08 by nico              #+#    #+#             */
/*   Updated: 2024/03/08 18:20:50 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <exception>

template <typename T>
class Array {
	private:
		T* _array;
		size_t _size;
	public:
		// ----------------------------------------------------- CANONICAL FORM
		Array( void ): _array(0), _size(0) {};
		~Array( void ) {
			delete [] _array;
		};
		Array( const Array& obj ) {
			_size = obj._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = obj._array[i];
		};
		Array& operator=( const Array& rhs ) {
			this->_size = rhs._size;
			for (size_t i = 0; i < _size; i++)
				this->_array[i] = rhs._array[i];
			return (*this);
		};

		// ------------------------------------------------- OTHER CONSTRUCTORS
		/* @param T() the constructor of the type is called */
		Array( size_t n ) {
			_array = new T[n];
			for (size_t i = 0; i < n ; i++)
				_array[i] = T();
			_size = n;
		};

		// ---------------------------------------------------------- OVERLOADS
		T& operator[]( size_t n ) {
			if (n >= _size)
				throw OutOfRange();
			return (_array[n]);
		};
		/*	Necessary when the instance is const.
			[1st const] Returning a const ref, means that then is not possible
			to modify (it won't compile).
			[2nd const] The member is a "const function", means it doesn't
			modify the instance (imagine like writing the following:
			void Animal::func( const Animal* this, int n ) const {...}; ).
		*/
		const T& operator[]( size_t n ) const {
			if (n >= _size)
				throw OutOfRange();
			return (_array[n]);
		};

		// ----------------------------------------------------- MEMB FUNCTIONS
		size_t size( void ) const;

		// ------------------------------------------------------------- EXCEPT
		class OutOfRange;
};

/* Example of syntax, in which the implementation is separated by the declaration. */
template <typename T>
size_t Array<T>::size ( void ) const {
	return (_size);
}

template <typename T>
class Array<T>::OutOfRange: public std::exception {
	public:
		const char* what() const throw() {
			return ("Error: index out of range");
		};
};

#endif
