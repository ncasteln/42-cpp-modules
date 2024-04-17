#include "Fwoosh.hpp"

Fwoosh::Fwoosh( void ) {
	this->_name = "Fwoosh";
	this->_effects = "fwooshed";
}

Fwoosh::~Fwoosh( void ) {};

Fwoosh::Fwoosh( const Fwoosh& obj ): ASpell( obj ) {} // -------====--=======> right ???

Fwoosh& Fwoosh::operator=( const Fwoosh& rhs ) { // -------====--============> right ???
	this->_name = rhs._name;
	this->_effects = rhs._effects;
	return (*this);
}

ASpell* Fwoosh::clone( void ) const {
	return (new Fwoosh);
}