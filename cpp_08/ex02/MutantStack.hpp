/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:25:49 by nico              #+#    #+#             */
/*   Updated: 2024/03/12 13:10:08 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

#include <stack>
#include <algorithm>
#include <iostream>
#include <iterator>

// -------------------------------------------------------- CLASS CONFIGURATION
/*
	In documentation of stack we can assume different things. When declaring a
	stack, we can specify <value_type, container_type, size_type>. If the
	second is not specified, the default is [deque].

	The stack is build ont the top of another container which gives the a set of
	member function to access the elements. This container has to support these
	operations: empty, size, back, push_back, pop_back.
*/
template <typename T>
class MutantStack: public std::stack<T> // automatic deque used
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator; // access ::iterator scope inside the container_type
		// by looking inside this-> is visible the container c
		// its member functions can be used inside the class here but are inaccessible outside
		// the use of typedef is necessary because of the main() otherwise, the same result
		// could be achieved by using std::stack<int>::container_type::iterator

		MutantStack( void ) {};
		~MutantStack( void ) {};
		iterator begin( void ) {
			return (this->c.begin());
		};
		iterator end( void ) {
			return (this->c.end());
		};
};

// ------------------------------------------------------------- ITERATOR SCOPE
/*	FROM THE DOCUMENTATION ABOUT ITERATORS
	class MyIterator : public std::iterator<std::input_iterator_tag, int> {
		private:
			int* p;
		public:
			MyIterator(int* x) :p(x) {}
			MyIterator(const MyIterator& mit) : p(mit.p) {}
			MyIterator& operator++() {++p;return *this;}
			MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
			bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
			bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
			int& operator*() {return *p;}
	};
*/

#endif



/*                FIRST ATTEMPT                */
// /*
// 	MutantStack should be an improved version of the classic std::stack. It adds
// 	iterator to traverse it, which the classic one has not.
// */


// /*	TO DO TO DO
// 	- implement also const_iterator or not ? ? ? ? ? ? ? ? ? ? ? ? ? ?
// */

// /*	HOW I ACHIEVE IT
// 	- Looking the main() I see that MutantStack<int> has a namespace/scope
// 	called iterator. So I declare this as a member of MutantStack.
// 	- From the main(), it seems that .begin() and .end() come from the
// 	MutantStack class, and not from the ::iterator scope.
// 	- the iterator class inherit from the std::iterator.
// */
// // -------------------------------------------------------- CLASS CONFIGURATION
// template <typename T>
// class MutantStack: public std::stack<T>
// {
// 	public:
// 		class iterator;	// sometimes the order matters...!!! try to put after the followings
// 		MutantStack<T>::iterator& begin( void );
// 		MutantStack<T>::iterator& end( void );
// };

// // ------------------------------------------------------------- ITERATOR SCOPE
// /*	FROM THE DOCUMENTATION ABOUT ITERATORS
// 	class MyIterator : public std::iterator<std::input_iterator_tag, int> {
// 		private:
// 			int* p;
// 		public:
// 			MyIterator(int* x) :p(x) {}
// 			MyIterator(const MyIterator& mit) : p(mit.p) {}
// 			MyIterator& operator++() {++p;return *this;}
// 			MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
// 			bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
// 			bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
// 			int& operator*() {return *p;}
// 	};
// */
// template <typename T>
// class MutantStack<T>::iterator: public std::iterator<std::random_access_iterator_tag, T>
// {
// 	private:
// 		MutantStack<T>* begin;
// 		MutantStack<T>* end;
// 	public:
// 		MutantStack<T>::iterator( void ) {};
// 		MutantStack<T>& operator*( void ) { return (*p); };
// };

// // ------------------------------------------------------------ MEMBER FUNCTIONS
// template <typename T>
// typename MutantStack<T>::iterator& MutantStack<T>::begin( void ) {

// }

// template <typename T>
// typename MutantStack<T>::iterator& MutantStack<T>::end( void ) {

// }






/*                 SECOND ATTEMPT                   */
// template <typename T>
// class MutantStack: public std::stack<T>
// {
// 	public:
// 		class iterator { //has to be nested or not ??? ??? ?? ?? ?? ?? ??
// 			public:
// 				iterator( void ) { // need to set begin and end()
// 					this->_begin =
// 				};

// 				std::iterator<std::random_access_iterator_tag, T>& getBegin( void ) { return (this->_begin); };
// 				std::iterator<std::random_access_iterator_tag, T>& getEnd( void ) { return (this->_end); };
// 			private:
// 				std::iterator<std::random_access_iterator_tag, T> _begin;
// 				std::iterator<std::random_access_iterator_tag, T> _end;
// 		};

// 		iterator it;
// 		MutantStack<T>::iterator& begin( void ) {
// 			return (this->it.getBegin());
// 		};
// 		MutantStack<T>::iterator& end( void ) {
// 			return (this->it.getEnd());
// 		};
// };
