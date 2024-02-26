/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:58:52 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 09:04:44 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "[Brain] default constructor" << std::endl;
}

Brain::~Brain( void ) {
	std::cout << "[Brain] destructor" << std::endl;
}

Brain::Brain( const Brain& obj ) {
	std::cout << "[Brain] copy constructor" << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = obj._ideas[i];
}

Brain& Brain::operator=( const Brain& rhs ) {
	std::cout << "[Brain] assignment operator" << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

std::string Brain::getIdea( int n ) const {
	if (n < 100)
		return (this->_ideas[n]);
	return ("[Brain] invalid index for idea");
}

void Brain::setIdea( int n, std::string s ) {
	if (n < 100)
		this->_ideas[n] = s;
	else
		std::cout << "[Brain] invalid index for idea" << std::endl;
}
