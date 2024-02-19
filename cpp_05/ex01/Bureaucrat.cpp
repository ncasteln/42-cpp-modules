/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/19 08:23:10 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Bureaucrat::Bureaucrat( void ): _name("<bureaucrat no name>") {
	std::cout << "[Bureaucrat] default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	// std::cout << "[Bureaucrat] destructor" << std::endl; // removed for readability
}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ) {
	std::cout << "[Bureaucrat] copy constructor" << std::endl;
	(*this) = obj;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	std::cout << "[Bureaucrat] assignment operator" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

// ---------------------------------------------------- OVERLOADED CONSTRUCTORS
Bureaucrat::Bureaucrat( const std::string name, int grade ): _name(name) {
	std::cout << this->_name << " " << grade;
	if (grade < 1)
		throw GradeTooHighException(EXCEP_CREATE);
	if (grade > 150)
		throw GradeTooLowException(EXCEP_CREATE);
	std::cout << ": successfully created" << std::endl;
	this->_grade = grade;
}

// -------------------------------------------------------------------- GETTERS
const std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

// -------------------------------------------------------------------- SETTERS
void Bureaucrat::incrementGrade( void ) {
	std::cout << this->_name;
	if (this->_grade == 1) {
		throw GradeTooHighException(EXCEP_INCR);
	}
	std::cout << ": grade incremented" << std::endl;
	this->_grade--;
}

void Bureaucrat::decrementGrade( void ) {
	std::cout << this->_name;
	if (this->_grade == 150)
		throw GradeTooLowException(EXCEP_DECR);
	std::cout << ": grade decremented" << std::endl;
	this->_grade++;
}

// --------------------------------------------------------------------- OTHERS
void Bureaucrat::signForm( Form& f ) {
	std::cout << "Bureaucrat <" << this->_name << "> try to sign Form <" << f.getName() << ">: ";
	f.beSigned(*this);
	if (f.getIsSigned())
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << f.getName() << ": " << std::endl;
}

// --------------------------------------------------------------------- NESTED
Bureaucrat::GradeTooLowException::GradeTooLowException( int excep ): _excep_n(excep) {}

Bureaucrat::GradeTooHighException::GradeTooHighException( int excep ): _excep_n(excep) {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	if (this->_excep_n == EXCEP_DECR)
		return (": cannot decrement");
	return (": grade too low to be used");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	if (this->_excep_n == EXCEP_INCR)
		return (": cannot increment");
	return (": grade too high to be used");
}

// ------------------------------------------------------------------ OVERLOADS
std::ostream& operator<<( std::ostream& cout, const Bureaucrat& b ) {
	cout << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (cout);
}
