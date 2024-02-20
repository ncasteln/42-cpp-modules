/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/20 08:04:35 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ------------------------------------------------------------------ CANONICAL
Bureaucrat::Bureaucrat( void ) {
	std::cout << "[Bureaucrat] default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	// std::cout << "[Bureaucrat] destructor" << std::endl; // removed for readability
}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ):
	_grade(obj._grade),
	_name(obj._name) {
	std::cout << "[Bureaucrat] copy constructor" << std::endl;
}

// --------------------------------------------------------- EXTRA CONSTRUCTORS
Bureaucrat::Bureaucrat( const std::string name, int grade ): _name(name) {
	std::cout << "[Bureaucrat] [std::string, int] constructor" << std::endl;
	std::cout << this->_name << " " << grade;
	if (grade < 1)
		throw GradeTooHighException(EXCEP_CREATE);
	if (grade > 150)
		throw GradeTooLowException(EXCEP_CREATE);
	std::cout << ": created" << std::endl;
	this->_grade = grade;
}

// ------------------------------------------------------------------ FUNCTIONS
const std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

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
	if (b.getName().empty())
		cout << "<no name>";
	else
		cout << b.getName();
	cout << ", bureaucrat grade " << b.getGrade() << ".";
	return (cout);
}
