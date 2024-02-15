/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/15 09:58:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

// int main( void ) {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;
// 	return (0);
// }



int main( void ) {
	Animal	a;
	Cat		c;
	Dog		d;

	a.makeSound();
	a.getType();
	std::cout << std::endl;

	c.makeSound();
	c.getType();
	std::cout << std::endl;

	d.makeSound();
	d.getType();
	std::cout << std::endl;

	return (0);
}
