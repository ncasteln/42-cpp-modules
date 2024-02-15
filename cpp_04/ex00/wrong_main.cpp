/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:54:59 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/15 10:02:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

int main( void ) {
	WrongAnimal*	wc = new WrongCat();
	wc->makeSound();
	delete wc;
	return (0);
}

/* int main( void ) {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // will output the generic animal sound!
	meta->makeSound();

	delete meta;
	delete i;
	return (0);
} */
