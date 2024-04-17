#include "Polymorph.hpp"

Polymorph::Polymorph( void ) {
	this->_name = "Polymorph";
	this->_effects = "turned into a critter";
}

Polymorph::~Polymorph( void ) {};

Polymorph::Polymorph( const Polymorph& obj ): ASpell( obj ) {} // -------====--=======> right ???

Polymorph& Polymorph::operator=( const Polymorph& rhs ) { // -------====--============> right ???
	this->_name = rhs._name;
	this->_effects = rhs._effects;
	return (*this);
}

ASpell* Polymorph::clone( void ) const {
	return (new Polymorph);
}