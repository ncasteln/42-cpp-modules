/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:37:02 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/19 08:42:50 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		PresidentialPardonForm( void );
		~PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm& );

		// -------------------------------------------- OVERLOADED CONSTRUCTORS
		PresidentialPardonForm( const std::string );

		// ---------------------------------------------------------- INHERITED
		int execute( Bureaucrat const & ) const;
	private:
		std::string _target;
		PresidentialPardonForm& operator=( const PresidentialPardonForm& ); // not-usable
};

#endif /* __PRESIDENTIALPARDONFORM_HPP__ */
