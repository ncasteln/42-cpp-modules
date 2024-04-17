#include "Fireball.hpp"

Fireball::Fireball( void ) {
	this->_name = "Fireball";
	this->_effects = "burnt to a crisp";
}

Fireball::~Fireball( void ) {};

Fireball::Fireball( const Fireball& obj ): ASpell( obj ) {} // -------====--=======> right ???

Fireball& Fireball::operator=( const Fireball& rhs ) { // -------====--============> right ???
	this->_name = rhs._name;
	this->_effects = rhs._effects;
	return (*this);
}

ASpell* Fireball::clone( void ) const {
	return (new Fireball);
}