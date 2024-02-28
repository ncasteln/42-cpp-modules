/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:37:02 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 09:01:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& );

		// -------------------------------------------- OVERLOADED CONSTRUCTORS
		ShrubberyCreationForm( const std::string );

		// ---------------------------------------------------------- INHERITED
		int execute( Bureaucrat const & ) const;

	private:
		std::string _target;
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& ); // not-usable

		// ------------------------------------------------------------- OTHERS
		void printTree( std::ofstream& fsout ) const;
};

#endif /* __SHRUBBERYCREATIONFORM_HPP__ */
