/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:42 by ncasteln          #+#    #+#             */
/*   Updated: 2024/02/22 12:25:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ----------------------------------------------------- CANONICAL CONSTRUCTORS
Bureaucrat::Bureaucrat( void ): _grade(150), _name("<bureaucrat no name>") {
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
	if (this->_grade == 1)
		throw GradeTooHighException(EXCEP_INCR);

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
void Bureaucrat::signForm( AForm& f ) {
	std::cout << "Bureaucrat " << this->_name << " try to sign form " << f.getName() << ": ";
	f.beSigned(*this);
	if (f.getIsSigned())
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << f.getName() << ": " << std::endl;
}

/*
	f.execute(*this) will call the implementation of the subclass instance
	(either Shrubbery, Robotomy or Presidential.execute()).
*/
void Bureaucrat::executeForm( AForm const & f ) {
	std::cout << "Bureaucrat " << this->_name << " try to execute form " << f.getName() << ": ";
	if (f.execute(*this)) {
		std::cerr << "Error: " << this->_name << " was not able to execute " << f.getName();
		std::cerr << ": std::ofstream.open() failed" << std::endl;
		return ;
	}
	std::cout << this->_name << " executed " << f.getName() << std::endl;
}

// --------------------------------------------------------------------- NESTED
Bureaucrat::GradeTooLowException::GradeTooLowException( int excep ): _excep_n(excep) {}

Bureaucrat::GradeTooHighException::GradeTooHighException( int excep ): _excep_n(excep) {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	if (this->_excep_n == EXCEP_DECR)
		return (": cannot decrement");
	if (this->_excep_n == EXCEP_CREATE)
		return (": cannot create Bureaucrat with grade lower than 150");
	return (": grade too low to be used");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	if (this->_excep_n == EXCEP_INCR)
		return (": cannot increment");
	if (this->_excep_n == EXCEP_CREATE)
		return (": cannot create Bureaucrat with negative grade");
	return (": grade too high to be used");
}

// ------------------------------------------------------------------ OVERLOADS
std::ostream& operator<<( std::ostream& cout, const Bureaucrat& b ) {
	cout << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (cout);
}
