/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/26 08:44:28 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>
#include <iostream>

/*
	• Virtual: links the function call at runtime instead of compile time.
	• Virtual destructor: it is needed when an obj of derived class is deleted
	thorugh the a pointer to the base class. Using 'virtual', the correct
	destructor will be called when it is deleted, ensuring proper cleanup.
	Example. const Animal	*p = new Dog();
*/
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
