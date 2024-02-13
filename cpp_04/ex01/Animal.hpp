/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 09:08:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal( void );
		virtual ~Animal( void );
		Animal( const Animal& );
		Animal& operator=( const Animal& );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;
	protected:
		std::string _type;
};

#endif /* __ANIMAL_HPP__ */
