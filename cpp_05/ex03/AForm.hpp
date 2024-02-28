/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:34:54 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/28 08:44:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
# define __AFORM_HPP__

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

# define EXCEP_LOW			0
# define EXCEP_HIGH			1
# define EXCEP_NO_PERM		2
# define EXCEP_SIGNED		3
# define EXCEP_NOTSIGNED	4

class AForm
{
	public:
		// --------------------------------------------- CANONICAL CONSTRUCTORS
		AForm( void );
		virtual ~AForm( void );
		AForm( const AForm& );

		// -------------------------------------------- OVERLOADED CONSTRUCTORS
		AForm( const std::string AFormName, int gradeToSign, int gradeToExecute);

		// ------------------------------------------------------------ GETTERS
		const std::string getName( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExecute( void ) const;
		bool getIsSigned( void ) const;

		// ------------------------------------------------------------ SETTERS
		void beSigned( Bureaucrat& );

		// ------------------------------------------------------------- OTHERS
		void isExecutable( Bureaucrat const & executor ) const;
		virtual int execute( Bureaucrat const & executor ) const = 0;

		// -------------------------------------------------------------- EXCEP
		class GradeTooLowException;
		class GradeTooHighException;
		class FormSignException;
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;
		AForm& operator=( const AForm& ); // not-usable
};

class AForm::GradeTooLowException: public std::exception
{
	public:
		GradeTooLowException( int );
		const char* what() const throw();
	private:
		int _n;
};

class AForm::GradeTooHighException: public std::exception
{
	public:
		GradeTooHighException( int );
		const char* what() const throw();
	private:
		int _n;
};

class AForm::FormSignException: public std::exception
{
	public:
		FormSignException( int );
		const char* what() const throw();
	private:
		int _n;
};

std::ostream& operator<<( std::ostream&, const AForm& );

#endif /* __AFORM_HPP__ */
