/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:30:53 by nico              #+#    #+#             */
/*   Updated: 2024/03/12 13:09:43 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main( void ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(99);

	std::stack<int>::container_type::iterator IT = mstack.begin(); // SAME RESULT AS CREATING typedef

	// MutantStack<int>::iterator it = mstack.begin();		// *(it) deference to 5
	// MutantStack<int>::iterator ite = mstack.end();		// *(--ite) deference to 99

	// std::cout << *it << std::endl;
	// std::cout << *(--ite) << std::endl;
	return (0);
}

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
