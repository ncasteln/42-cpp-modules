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
	std::cout << "[Character] default constructor" << std::endl;
	for (int i = 0; i < 4 ; i++)
		this->_items[i] = NULL;
}

/*
	Character DOES NOT delete items, the deleting is handled in the main()
	because otherwise it would not be possible to use data on the stack.
*/
Character::~Character( void ) {
	std::cout << "[Character] destructor" << std::endl;
	for (int i = 0; i < 4 ; i++) {
		if (this->_items[i])
			this->_items[i] = NULL;
	}
}

Character::Character( const Character& obj ) {
	std::cout << "[Character] copy constructor" << std::endl;
	this->_name = obj._name;
	for (int i = 0; i < 4 ; i++) {
		this->_items[i] = NULL;
		if (obj._items[i])
			this->_items[i] = obj._items[i]->clone();
	}
}

/*
	The copy constructor is not the same as operator= because this last one
	could have to delete some allocated items.
*/
Character& Character::operator=( const Character& rhs ) {
	std::cout << "[Character] assignment operator" << std::endl;
	this->_name = rhs._name;
	for (int i = 0; i < 4 ; i++) {
		if (this->_items[i]) {
			delete this->_items[i];
			this->_items[i] = NULL;
		}
		if (rhs._items[i])
			this->_items[i] = rhs._items[i]->clone();
	}
	return (*this);
}

// --------------------------------------------------------- OTHER CONSTRUCTORS
Character::Character( std::string name ): _name(name) {
	std::cout << "[Character] [std::string] constructor" << std::endl;
	for (int i = 0; i < 4 ; i++)
		this->_items[i] = NULL;
}

// -------------------------------------------------------------- MEM FUNCTIONS
std::string const& Character::getName( void ) const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->_items[i] == m) {
			std::cout << "[Character] materia already stored" << std::endl; // not requested
			return ;
		}
		if (!this->_items[i]) {
			std::cout << "[Character] new Materia equipped" << std::endl;
			this->_items[i] = m;
			return ;
		}
	}
	std::cout << "[Character] no materia equipped" << std::endl;
}

void Character::unequip(int idx) {
	if (idx > 3) {
		std::cout << "[Character] idx [" << idx << "] invalid, only items between 0 and 3 are supported" << std::endl;
		return ;
	}
	if (this->_items[idx]) {
		std::cout << "[Character] Materia @ index [ " << idx << " ] unequipped" << std::endl;
		this->_items[idx] = NULL;
	}
	else
		std::cout << "[Character] Materia @ index [ " << idx << " ] cannot be unequipeed (doesn't exist)" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3) {
		std::cout << "[Character] idx [" << idx << "] invalid, only items between 0 and 3 are supported" << std::endl;
		return ;
	}
	if (this->_items[idx]) {
		std::cout << this->getName() << " ";
		this->_items[idx]->AMateria::use(target);
	}
	else
		std::cout << "[Character] Materia @ index [ " << idx << " ] cannot be used (doesn't exist)" << std::endl;
}

// -------------------------------------------------------------- NOT REQUESTED
AMateria** Character::getItemsAddress( void ) {
	return (this->_items);
}
