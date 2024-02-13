/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 13:27:39 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main ( void ) {
	// AAnimal	a; // not possible anymore

	Brain	b;
	std::cout << std::endl;

	Cat		c;
	std::cout << "Type of -> " << c.getType() << std::endl;
	std::cout << std::endl;

	Dog		d;
	std::cout << "Type of -> " << d.getType() << std::endl;
	std::cout << std::endl;

	return (0);
}

// int main( void ) {
// 	unsigned int		N = 13;
// 	AAnimal*			animals[N];

// 	unsigned int i = 0;
// 	while (i < N) {
// 		if (i < (N / 2)) {
// 			std::cout << "Dog [" << i << "]" << std::endl;
// 			animals[i++] = new Dog();
// 		}
// 		else {
// 			std::cout << "Cat [" << i << "]" << std::endl;
// 			animals[i++] = new Cat();
// 		}
// 	}
// 	std::cout << std::endl;
// 	i = 0;
// 	while (i < N) {
// 		std::cout << "Animal [" << i << "]" << std::endl;
// 		delete animals[i++];
// 	}
// 	return (0);
// }


// int main()
// {
// 	const AAnimal* i = new Cat();
// 	delete i;
// 	return(0);
// }
