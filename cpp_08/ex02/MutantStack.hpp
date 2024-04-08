/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:50:52 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/08 11:03:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

#include <stack>
#include <iostream>

/*	The stack is build on the top of another container which gives the set of
	member function to access the elements. This container has to support these
	operations: empty, size, back, push_back, pop_back.
	When declaring a stack, we can specify <value_type, container_type, size_type>.
	If the second is not specified, the default is [deque]. Container_type is
	a protected member of std::stack, therefore accessible when creating a derived
	from it.

	See [https://stackoverflow.com/questions/31494286/what-is-meaning-of-member-types-in-stl-container]
	for more info about memeber types in STL.

	NOTE: the use of typedef iterator is necessary because of the main() otherwise,
	the same result could be achieved by using std::stack<int>::container_type::iterator
	as return type;
*/
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack( void ) {};
		~MutantStack( void ) {};
		MutantStack( const MutantStack& );
		MutantStack& operator=( const MutantStack& );
		iterator begin( void ) { return (this->c.begin()); };
		iterator end( void ) { return (this->c.end()); };
};

/* Copy constructor */
template <typename T>
MutantStack<T>::MutantStack( const MutantStack& obj ): std::stack<T>(obj) {};

/* Assignment operator */
template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& rhs ) {
	this->c = rhs.c;
	return (*this);
};

/* Display function */
template <typename T>
std::ostream& operator<<( std::ostream& cout, MutantStack<T> mstack ) {
	cout << "[ MUTANT STACK ] ";
	typename MutantStack<T>::iterator it = mstack.begin();
	while (it != mstack.end()) {
		cout << "[ " << *it << " ] ";
		it++;
	}
	cout << std::endl;
	return (cout);
};

#endif
