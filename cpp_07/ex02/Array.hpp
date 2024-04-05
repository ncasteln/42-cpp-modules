/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:48 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/05 08:28:18 by ncasteln         ###   ########.fr       */
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
	if (static_cast<int>(n) < 0 || n >= this->_size)
		throw OutOfRange();
	return (this->_array[n]);
}

/*	Necessary when the instance is const like const int arr[2] = { 5, 7 };
	arr[0] = 2;	-----> won't compile, lvalue cannot be modified

	Tricky syntax:
	- const T&: desired returning value;
	- Array<T>: left value;
	- size_t n: right value;
	- const (last): says that the instance Array<T> is read-only!!!

	TO VISUALIZE:
	const obj<int>(10);
	FROM:	obj[5] = 999;
	TO:		(const int &)0 = 999; ---> evidence that is not possible
*/
template <typename T> const T& Array<T>::operator[]( size_t n ) const {
	if (static_cast<int>(n) < 0 || n >= this->_size)
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
