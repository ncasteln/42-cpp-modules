/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 09:11:50 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

/*
	Exmaple of "slicing" in polymorphism. If the base class destructor is not
	made virtual, the following snippet doesn't work because only the Animal
	destructor would be called.
*/
// int main ( void ) {
// 	Animal*	a = new Cat();
// 	Cat*	c = new Cat();
// 	std::cout << std::endl;
// 	delete a;
// 	delete c;
// 	return (0);
// }



int main ( void ) {
	Cat	a;
	Cat	b ( a );

	std::cout << "Address of [a] brain: " << a.getBrain() << std::endl;
	std::cout << "Address of [b] brain: " << b.getBrain() << std::endl;

	/* Set Ideas for the brain of Cat a */
	a.getBrain()->setIdea(0, "Blue");
	a.getBrain()->setIdea(1, "Yellow");
	a.getBrain()->setIdea(2, "Red");
	a.getBrain()->setIdea(3, "Green");

	std::cout << "Cat [a] idea [0] " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat [a] idea [1] " << a.getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat [a] idea [2] " << a.getBrain()->getIdea(2) << std::endl;
	std::cout << "Cat [a] idea [3] " << a.getBrain()->getIdea(3) << std::endl << std::endl;

	/* Set Ideas for the brain of Cat B */
	b.getBrain()->setIdea(0, "One");
	b.getBrain()->setIdea(1, "Two");
	b.getBrain()->setIdea(2, "Three");
	b.getBrain()->setIdea(3, "Four");

	std::cout << "Cat [b] idea [0] " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat [b] idea [1] " << b.getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat [b] idea [2] " << b.getBrain()->getIdea(2) << std::endl;
	std::cout << "Cat [b] idea [3] " << b.getBrain()->getIdea(3) << std::endl << std::endl;

	/* If copy constr would be shallow, setting the ideas of b would change also
	the ideas of a (change it to show). It would also to a double free */
	std::cout << "Cat [a] idea [0] " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat [a] idea [1] " << a.getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat [a] idea [2] " << a.getBrain()->getIdea(2) << std::endl;
	std::cout << "Cat [a] idea [3] " << a.getBrain()->getIdea(3) << std::endl << std::endl;
	return (0);
}



// int main( void ) {
// 	unsigned int	N = 13;
// 	Animal*			animals[N];

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



/* Brain test, to show that when they are copied they are not shallow */
// #include "Brain.hpp"

// int main ( void ) {
// 	Brain	c;
// 	Brain	d;

// 	c.setIdea(0, "ONE");
// 	d.setIdea(0, "blue");

// 	c = d;
// 	std::cout << c.getIdea(0) << std::endl;
// 	std::cout << d.getIdea(0) << std::endl;
// 	return (0);
// }



// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return(0);
// }
