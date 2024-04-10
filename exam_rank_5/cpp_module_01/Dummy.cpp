#include "Dummy.hpp"

Dummy::Dummy( void ) {
	this->_type = "Target Practice Dummy";
}

Dummy::~Dummy( void ) {};

Dummy::Dummy( const Dummy& obj ) {} // -------====--=======> ???

Dummy& Dummy::operator=( const Dummy& rhs ) { // -------====--=======> ???
}

ATarget* Dummy::clone( void ) {
	return (new Dummy);
}