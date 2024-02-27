/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:58 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/27 12:11:13 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

#define EXCEP_LOW		0
#define EXCEP_HIGH		1
#define EXCEP_NO_PERM	2
#define EXCEP_SIGNED	3

class Form
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		Form( void );
		~Form( void );
		Form( const Form& );

		// -------------------------------------------- OVERLOADED CONSTRUCTORS
		Form( const std::string formName, int gradeToSign, int gradeToExecute);

		// ------------------------------------------------------------ GETTERS
		const std::string getName( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExecute( void ) const;
		bool getIsSigned( void ) const;

		// ------------------------------------------------------------ SETTERS
		void beSigned( Bureaucrat& );

		// -------------------------------------------------------------- EXCEP
		class GradeTooLowException;
		class GradeTooHighException;
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;
		Form& operator=( const Form& );	// not-usable
};

class Form::GradeTooLowException: public std::exception
{
	public:
		GradeTooLowException( int );
		const char* what() const throw();
	private:
		int _n;
};

class Form::GradeTooHighException: public std::exception
{
	public:
		GradeTooHighException( int );
		const char* what() const throw();
	private:
		int _n;
};

std::ostream& operator<<( std::ostream&, const Form& );

#endif /* __FORM_HPP__ */
