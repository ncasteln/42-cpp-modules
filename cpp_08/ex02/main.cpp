/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:50:37 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/12 14:31:51 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* Basic test */
int main( void ) {
	MutantStack<int> mstack;
	for (int i = 0; i < 50; i += 7)
		mstack.push(i);
	std::cout << mstack;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << "*it -> " << *it << std::endl;
		it++;
	}
	return (0);
}



/* Copy constructor and assignment operator */
// int main( void ) {
// 	MutantStack<float> m;
// 	m.push(0.0f);
// 	m.push(2.2f);
// 	m.push(6.6f);
// 	m.push(8.8f);
// 	m.push(10.10f);

// 	/* Copy constructor */
// 	MutantStack<float> n( m );
// 	*(m.begin()) = -999.9f;
// 	MutantStack<float>::iterator itm = m.begin();
// 	std::cout << "[ m stack, whose first value has been modified ]" << std::endl;
// 	while (itm != m.end()) {
// 		std::cout << "m -> " << *(itm) << std::endl;
// 		itm++;
// 	}
// 	std::cout << "[ n stack done by copy ]" << std::endl;
// 	MutantStack<float>::iterator itn = n.begin();
// 	while (itn != n.end()) {
// 		std::cout << "n -> " << *(itn) << std::endl;
// 		itn++;
// 	}
// 	std::cout << std::endl;

// 	/* Reassignment operator */
// 	m = n;
// 	itm = m.begin();
// 	std::cout << "[ m stack after being reassigned to n ]" << std::endl;
// 	while (itm != m.end()) {
// 		std::cout << "m -> " << *(itm) << std::endl;
// 		itm++;
// 	}
// 	return (0);
// }



/* main() given by the subject */
// int main( void ) {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	// //[...]
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();	// deference to
// 	MutantStack<int>::iterator ite = mstack.end();	//

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);

// 	return (0);
// }



/* substitue with std::list */
// #include <list>
// int main ( void ) {
// 	MutantStack<int> container;
// 	for (int i = 0; i < 50; i += 7)
// 		container.push(i);
// 	MutantStack<int>::iterator it = container.begin();
// 	while (it != container.end()) {
// 		std::cout << "*it -> " << *it << std::endl;
// 		it++;
// 	}
// 	return (0);
// }
