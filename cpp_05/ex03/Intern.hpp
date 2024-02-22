/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:07:35 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 14:29:13 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		Intern( void );
		~Intern( void );
		Intern( const Intern& );
		Intern& operator=( const Intern& );

		// ------------------------------------------------------------- OTHERS
		AForm* makeForm( std::string name, std::string target );
};

#endif /* __INTERN_HPP__ */
