#include "BrickWall.hpp"

BrickWall::BrickWall( void ) {
	this->_type = "Inconspicuous Red-brick Wall";
}

BrickWall::~BrickWall( void ) {};

BrickWall::BrickWall( const BrickWall& obj ): ATarget( obj ) {} // -------====--=======> right ???

BrickWall& BrickWall::operator=( const BrickWall& rhs ) { // -------====--=============> right ???
	this->_type = rhs._type;
	return (*this);
}

ATarget* BrickWall::clone( void ) const {
	return (new BrickWall);
}