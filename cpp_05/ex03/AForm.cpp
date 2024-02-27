/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:34:32 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/27 17:10:15 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ------------------------------------------------------ CANONICAL CONSTRUCTORS
AForm::AForm( void ):
	_name("<Aform no name>"),
	_gradeToSign(1),
	_gradeToExecute(1),
	_isSigned(false) {
	std::cout << "[AForm] default constructor" << std::endl;
}

AForm::~AForm( void ) {
	// std::cout << "[AForm] destructor" << std::endl; // removed for readability
}

AForm::AForm( const AForm& obj ):
	_name(obj._name),
	_gradeToSign(obj._gradeToSign),
	_gradeToExecute(obj._gradeToExecute),
	_isSigned(obj._isSigned) {
	std::cout << "[AForm] copy constructor" << std::endl;
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
AForm::AForm( const std::string name, int gradeToSign, int gradeToExecute ):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_isSigned(false) {
	std::cout << "[AForm] " << this->_name << ": ";
	if (this->_gradeToSign <= 0 || this->_gradeToExecute <= 0)
		throw GradeTooHighException(EXCEP_HIGH);
	if (this->_gradeToSign > 150  || this->_gradeToExecute > 150)
		throw GradeTooLowException(EXCEP_LOW);
	std::cout << "successfully created" << std::endl;
}

// -------------------------------------------------------------------- GETTERS
const std::string AForm::getName( void ) const { return (this->_name); }
int AForm::getGradeToSign( void ) const { return (this->_gradeToSign); }
int AForm::getGradeToExecute( void ) const { return (this->_gradeToExecute); }
bool AForm::getIsSigned( void ) const { return (this->_isSigned); }

// -------------------------------------------------------------------- SETTERS
void AForm::beSigned( Bureaucrat& b ) {
	if (this->getIsSigned())
		throw FormSignException(EXCEP_SIGNED);
	if (this->getGradeToSign() < b.getGrade()) {
		throw GradeTooLowException(EXCEP_LOW);
	}
	this->_isSigned = true;
}

// --------------------------------------------------------------------- OTHERS
void AForm::isExecutable( Bureaucrat const & executor ) const {

	if (!this->getIsSigned())
		throw FormSignException(EXCEP_NOTSIGNED);
	if (this->getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException(EXCEP_LOW);
}

// ---------------------------------------------------------------------- EXCEP
AForm::GradeTooLowException::GradeTooLowException( int n ): _n(n) {}

const char* AForm::GradeTooLowException::what() const throw() {
	if (this->_n == EXCEP_NO_PERM)
		return ("permission denied");
	if (this->_n == EXCEP_LOW)
		return ("grade too low");
	return ("unknow exception");
}

AForm::GradeTooHighException::GradeTooHighException( int n ): _n(n) {}

const char* AForm::GradeTooHighException::what() const throw() {
	if (this->_n == EXCEP_HIGH)
		return ("grade too high");
	return ("unknow exception");
}

AForm::FormSignException::FormSignException( int n ): _n(n) {}

const char* AForm::FormSignException::what() const throw() {
	if (this->_n == EXCEP_SIGNED)
		return ("form already signed");
	if (this->_n == EXCEP_NOTSIGNED)
		return ("form not signed cannot be executed");
	return ("unknow exception");
}

// ------------------------------------------------------------------ OVERLOADS
std::ostream& operator<<( std::ostream& cout, const AForm& f ) {
	cout << "| AForm " << f.getName() << ": " << std::endl;
	cout << "| Grade required to be signed: " << f.getGradeToSign() << std::endl;
	cout << "| Grade required to be executed: " << f.getGradeToExecute() << std::endl;
	cout << "| Grade signed: ";
	if (f.getIsSigned())
		cout << "[ true ]" << std::endl;
	else
		cout << "[ false ]" << std::endl;
	return (cout);
}
