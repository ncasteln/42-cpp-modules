/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 10:39:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>
#include <stdexcept>

# define EXCEP_CREATE	0
# define EXCEP_DECR		1
# define EXCEP_INCR		2


/*
	****** TO REMEMBER WHEN EVAL ******
	• highest grade possible == 1 / lowest == 150
	• question: what to do with default constructor? Which value should it set?
	• operator= is made not-usable because of const _name. In that way I can
	void someone that assign a Bureaucrat to another one by accidental mistake.
	• Constructor of oxceptions is not required: I made only to create custom
	throw() error messages.
*/
class Bureaucrat
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		Bureaucrat( void );
		virtual ~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& );

		// ------------------------------------------------- OTHER CONSTRUCTORS
		Bureaucrat( const std::string, int );

		// ------------------------------------------------------------ GETTERS
		const std::string getName( void ) const;
		int getGrade( void ) const;

		// ------------------------------------------------------------ SETTERS
		void incrementGrade( void );
		void decrementGrade( void );

		// -------------------------------------------------------------- EXCEP
		class GradeTooLowException;
		class GradeTooHighException;
	private:
		int _grade;
		const std::string _name;
		Bureaucrat& operator=( const Bureaucrat& );	// not-usable
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		GradeTooLowException( int );
		virtual const char* what() const throw();
	private:
		int _excep_n;
};

class Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		GradeTooHighException( int );
		virtual const char* what() const throw();
	private:
		int _excep_n;
};

std::ostream& operator<<( std::ostream&, const Bureaucrat& );

#endif /* __BUREAUCRAT_HPP__ */
