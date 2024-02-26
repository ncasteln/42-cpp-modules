/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/13 09:08:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

#include <string>
#include <iostream>

/*
	By creating a PURE virtual memeber function, we are defining the class as
	Abstract and therefore not instantiable. The derived WILL HAVE to implement
	it by themselves.
*/
class AAnimal
{
	public:
		AAnimal( void );
		virtual ~AAnimal( void );
		AAnimal( const AAnimal& );
		AAnimal& operator=( const AAnimal& );

		virtual void makeSound( void ) const = 0;
		std::string getType( void ) const;
	protected:
		std::string _type;
};

#endif /* __AANIMAL_HPP__ */
