/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 12:23:23 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ------------------------------------------------------ CANONICAL CONSTRUCTORS
Form::Form( void ):
	_name("<form no name>"),
	_gradeToSign(1),
	_gradeToExecute(1),
	_isSigned(false) {
	std::cout << "[Form] default constructor" << std::endl;
}

Form::~Form( void ) {
	// std::cout << "[Form] destructor" << std::endl; // removed for readability
}

Form::Form( const Form& obj ):
	_name(obj._name),
	_gradeToSign(obj._gradeToSign),
	_gradeToExecute(obj._gradeToExecute),
	_isSigned(obj._isSigned) {
	std::cout << "[Form] copy constructor" << std::endl;
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
Form::Form( const std::string name, int gradeToSign, int gradeToExecute ):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_isSigned(false) {
	std::cout << this->_name << ": ";
	if (this->_gradeToSign <= 0 || this->_gradeToExecute <= 0)
		throw GradeTooHighException(EXCEP_HIGH);
	if (this->_gradeToSign > 150  || this->_gradeToExecute > 150)
		throw GradeTooLowException(EXCEP_LOW);
	std::cout << "successfully created" << std::endl;
}

// -------------------------------------------------------------------- GETTERS
const std::string Form::getName( void ) const { return (this->_name); }
int Form::getGradeToSign( void ) const { return (this->_gradeToSign); }
int Form::getGradeToExecute( void ) const { return (this->_gradeToExecute); }
bool Form::getIsSigned( void ) const { return (this->_isSigned); }

// -------------------------------------------------------------------- SETTERS
void Form::beSigned( Bureaucrat& b ) {
	if (this->getIsSigned())
		throw GradeTooLowException(EXCEP_SIGNED);
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException(EXCEP_LOW);
	this->_isSigned = true;
}

// ---------------------------------------------------------------------- EXCEP
Form::GradeTooLowException::GradeTooLowException( int n ): _n(n) {}

Form::GradeTooHighException::GradeTooHighException( int n ): _n(n) {}

const char* Form::GradeTooLowException::what() const throw() {
	if (this->_n == EXCEP_NO_PERM)
		return ("permission denied");
	if (this->_n == EXCEP_LOW)
		return ("grade too low");
	if (this->_n == EXCEP_SIGNED)
		return ("form already signed");
	return ("unknow exception");
}

const char* Form::GradeTooHighException::what() const throw() {
	if (this->_n == EXCEP_HIGH)
		return ("grade too high");
	return ("unknow exception");
}

// ------------------------------------------------------------------ OVERLOADS
std::ostream& operator<<( std::ostream& cout, const Form& f ) {
	cout << "| Form [ " << f.getName() << " ]" << std::endl;
	cout << "| Grade required to be signed: " << f.getGradeToSign() << std::endl;
	cout << "| Grade required to be executed: " << f.getGradeToExecute() << std::endl;
	cout << "| Grade signed: ";
	if (f.getIsSigned())
		cout << "[ true ]" << std::endl;
	else
		cout << "[ false ]" << std::endl;
	return (cout);
}
