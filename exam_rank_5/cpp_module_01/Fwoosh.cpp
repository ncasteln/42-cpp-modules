#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) {
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
}

Fwoosh::~Fwoosh( void ) {};

Fwoosh::Fwoosh( const Fwoosh& obj ) {} // -------====--=======> ???

Fwoosh& Fwoosh::operator=( const Fwoosh& rhs ) { // -------====--=======> ???
}

ASpell* Fwoosh::clone( void ) {
	return (new Fwoosh);
}