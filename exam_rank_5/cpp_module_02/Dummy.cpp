#include "Dummy.hpp"

Dummy::Dummy( void ) {
	this->_type = "Target Practice Dummy";
}

Dummy::~Dummy( void ) {};

Dummy::Dummy( const Dummy& obj ): ATarget( obj ) {} // -------====--=======> right ???

Dummy& Dummy::operator=( const Dummy& rhs ) { // -------====--=============> right ???
	this->_type = rhs._type;
	return (*this);
}

ATarget* Dummy::clone( void ) const {
	return (new Dummy);
}