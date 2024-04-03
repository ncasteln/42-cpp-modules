/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:48 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/03 17:07:53 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <exception>

template <typename T>
class Array
{
	private:
		T* _array;
		size_t _size;
	public:
		Array( void ); // -------------------------------------- CANONICAL FORM
		~Array( void );
		Array( const Array& obj );
		Array& operator=( const Array& rhs );
		Array( size_t n ); // ------------------------------ OTHER CONSTRUCTORS
		T& operator[]( size_t n ); // ------------------------------- OVERLOADS
		const T& operator[]( size_t n ) const;
		size_t size( void ) const; // -------------------------- MEMB FUNCTIONS
		class OutOfRange; // ------------------------------------------- EXCEPT
};

/*	I choose to separate declaration from implementation, but leaving them in
	the same file. An alternative could create a .tpp file which includes all
	the extensions using #include "Array.tpp". */

// ------------------------------------------------------------- CANONICAL FORM
template <typename T> Array<T>::Array( void ): _array(0), _size(0) {}

template <typename T> Array<T>::~Array( void ) { delete [] _array; }

template <typename T> Array<T>::Array( const Array& obj) {
	this->_size = obj._size;
	this->_array = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_array[i] = obj._array[i];
}

template <typename T> Array<T>& Array<T>::operator=( const Array& rhs ) {
	this->_size = rhs._size;
	for (size_t i = 0; i < _size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
/* @param T() the constructor of the type is called */
template <typename T> Array<T>::Array( size_t n ) {
	this->_size = n;
	this->_array = new T[n];
	for (size_t i = 0; i < n ; i++)
		this->_array[i] = T();
}

// -------------------------------------------------------- OVERLADED OPERATORS
template <typename T> T& Array<T>::operator[]( size_t n ) {
	if (n >= this->_size)
		throw OutOfRange();
	return (this->_array[n]);
}

/*	Necessary when the instance is const.
	[1st const] Returning a const ref, means that then is not possible to modify
	(it won't compile).
	[2nd const] The member is a "const function", means it doesn't modify the
	instance (imagine like writing the following:
	void Animal::func( const Animal* this, int n ) const {...}; ).

	Basically I replicated the behavior of:
	const int arr[2] = { 5, 7 };
	arr[0] = 2;	-----> this is not allowed, lvalue cannot be modified
*/
template <typename T> const T& Array<T>::operator[]( size_t n ) const { // second const catches if the instance was declared with const keyword, if not, it's not used this operator|reflects the intance
	if (n >= this->_size)
		throw OutOfRange();
	return (_array[n]);
}

// ----------------------------------------------------------- MEMBER FUNCTIONS
template <typename T>
size_t Array<T>::size ( void ) const {
	return (this->_size);
}

template <typename T>
class Array<T>::OutOfRange: public std::exception {
	public:
		const char* what() const throw() { return ("Error: index out of range"); };
};

#endif /* __ARRAY_HPP__ */
