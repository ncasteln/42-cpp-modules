/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:50:37 by ncasteln          #+#    #+#             */
/*   Updated: 2024/04/05 16:01:55 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*	TO DO / QUESTIONS
	- Make a test like the subjects ask (with list or vector)
	- begin() == bottom ?
	- should implement const?
*/
/* Basic test */
int main( void ) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(99);
	std::cout << mstack << std::endl;

	// MutantStack<int>::iterator it = mstack.begin();		// *(it) deference to 5
	// MutantStack<int>::iterator ite = mstack.end();		// *(--ite) deference to 99
	// same result ---> std::stack<int>::container_type::iterator it = mstack.begin();
	// same result ---> std::stack<int>::container_type::iterator ite = mstack.end();
	return (0);
}



// int main( void ) {
// 	MutantStack<float> m;
// 	m.push(0.0f);
// 	m.push(2.2f);
// 	m.push(6.6f);
// 	m.push(8.8f);
// 	m.push(10.10f);

// 	MutantStack<float> n( m );

// 	*(m.begin()) = -999.9f;

// 	// copy constructor works if the following shows a difference only at the beginning(bottom)
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

// 	// assignment op works if now m is equal to n
// 	m = n;
// 	itm = m.begin();
// 	std::cout << "[ m stack after being reassigned ]" << std::endl;
// 	while (itm != m.end()) {
// 		std::cout << "n -> " << *(itm) << std::endl;
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
