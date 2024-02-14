/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/14 15:37:00 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main ( void ) {


	return (0);
}


/* Rassign operator contradiction. */
// int main ( void ) {
// 	Cat	c;
// 	Dog	d;
// 	AAnimal	*pc = &c;
// 	AAnimal	*pd = &d;

// 	*pc = *pd;

// 	std::cout << pd->getType() << std::endl;
// 	std::cout << pc->getType() << std::endl;

// 	return (0);
// }



// int main ( void ) {
// 	Brain	b;
// 	b.setIdea(0, "Good idea");
// 	b.setIdea(1, "Bad idea");

// 	Brain	c( b );
// 	std::cout << "[c] Idea[0] " << c.getIdea(0) << std::endl;
// 	std::cout << "[c] Idea[1] " << c.getIdea(1) << std::endl;
// 	std::cout << "[c] Idea[2] " << c.getIdea(2) << std::endl;

// 	Brain	d;
// 	d = b;
// 	b.setIdea(0, "Changed idea");
// 	std::cout << "[b] Idea[0] " << b.getIdea(0) << std::endl;
// 	std::cout << "[c] Idea[0] " << c.getIdea(0) << std::endl;
// 	std::cout << "[d] Idea[0] " << d.getIdea(0) << std::endl;

// 	return (0);
// }



// int main ( void ) {
// 	// AAnimal	a; // not possible anymore

// 	Brain	b;
// 	std::cout << std::endl;

// 	Cat		c;
// 	std::cout << "Type of -> " << c.getType() << std::endl;
// 	std::cout << std::endl;

// 	Dog		d;
// 	std::cout << "Type of -> " << d.getType() << std::endl;
// 	std::cout << std::endl;

// 	return (0);
// }



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
