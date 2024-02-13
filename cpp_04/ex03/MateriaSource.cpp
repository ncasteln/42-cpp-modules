/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 19:27:38 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// ------------------------------------------------------------------- CANONICAL
MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource destructor" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& ) {
	std::cout << "MateriaSource copy constructor" << std::endl;
	// implement
}

MateriaSource& MateriaSource::operator=( const MateriaSource& rhs ) {
	std::cout << "MateriaSource assign operator" << std::endl;
	// implement
}

// -------------------------------------------------------------- MEM FUNCTIONS
void MateriaSource::learnMateria( AMateria* m ) {
	// implement
}

AMateria* MateriaSource::createMateria( std::string const& type ) {
	// implement
	return (NULL);
}
