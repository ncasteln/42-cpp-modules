/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:37:02 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/19 15:02:16 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		RobotomyRequestForm( void );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& );

		// -------------------------------------------- OVERLOADED CONSTRUCTORS
		RobotomyRequestForm( const std::string );

		// ---------------------------------------------------------- INHERITED
		int execute( Bureaucrat const & ) const;
	private:
		std::string _target;
		RobotomyRequestForm& operator=( const RobotomyRequestForm& ); // not-usable
};

#endif /* __ROBOTOMYREQUESTFORM_HPP__ */
