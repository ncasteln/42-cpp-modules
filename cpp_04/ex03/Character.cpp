/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:45 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 11:21:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// ------------------------------------------------------------------- CANONICAL
Character::Character( void ) {
	std::cout << "Character default constructor" << std::endl;
}

Character::~Character( void ) {
	std::cout << "Character destructor" << std::endl;
}

Character::Character( const Character& obj ) {
	std::cout << "Character copy constructor" << std::endl;
	*this = obj;
}

Character& Character::operator=( const Character& rhs ) {
	std::cout << "Character assignment operator" << std::endl;
	// this->_name = rhs._name;
	// for (int i = 0; i < 4; i++) {
	// }
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
Character::Character( std::string name ): _name(name) {
	std::cout << "Character [std::string] constructor" << std::endl;
}

// -------------------------------------------------------------- MEM FUNCTIONS
std::string const& Character::getName( void ) const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	std::cout << "New Materia equipped" << std::endl;
	for (int i = 0; i < 4; i++) { // init to NULL
		if (!this->_items[i]) {
			this->_items[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	std::cout << "Materia @ index [ " << idx << " ] unequipped" << std::endl;
	delete this->_items[idx];
	this->_items[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	std::cout << this->getName() << " ";
	this->_items[idx]->AMateria::use(target);
}
