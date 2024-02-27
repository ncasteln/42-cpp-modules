/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/27 08:21:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// ------------------------------------------------------------------- CANONICAL
MateriaSource::MateriaSource( void ) {
	std::cout << "[MateriaSource] default constructor" << std::endl;
	for (int i = 0; i < 4 ; i++)
		this->_src[i] = NULL;
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "[MateriaSource] destructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_src[i])
			delete this->_src[i];
		this->_src[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& obj ) {
	std::cout << "[MateriaSource] copy constructor" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_src[i] = NULL;
		if (obj._src[i])
			this->_src[i] = obj._src[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=( const MateriaSource& rhs ) {
	std::cout << "[MateriaSource] assign operator" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_src[i])
			delete this->_src[i];
		this->_src[i] = NULL;
		if (rhs._src[i])
			this->_src[i] = rhs._src[i]->clone();
	}
	return (*this);
}

// -------------------------------------------------------------- MEM FUNCTIONS
/*
	See subject test in main() for more explanation. The implementation assumes
	that AMateria* passed as param is allocated.
*/
void MateriaSource::learnMateria( AMateria* m ) {
	for (int i = 0; i < 4 ; i++) {
		if (!this->_src[i]) {
			std::cout << "[MateriaSource] new materia learned" << std::endl;
			this->_src[i] = m->clone();
			return ;
		}
	}
	std::cout << "[MateriaSource] can't learn, slots are full!" << std::endl;
}

AMateria* MateriaSource::createMateria( std::string const& type ) {
	for (int i = 3; i >= 0 ; i--) {
		if (this->_src[i]) {
			if (this->_src[i]->getType() == type) {
				std::cout << "[MateriaSource] " << type << " materia created" << std::endl;
				return (this->_src[i]);
			}
		}
	}
	std::cout << "[MateriaSource] can't create: " << type << " is unknown type" << std::endl;
	return (NULL);
}
