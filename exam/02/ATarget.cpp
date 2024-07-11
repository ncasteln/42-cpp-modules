#include "ATarget.hpp"

ATarget::ATarget( std::string type ): _type(type){

}

ATarget::ATarget( void ) {

}
ATarget::~ATarget( void ) {

}
ATarget::ATarget( const ATarget & obj ):
	_type(obj._type) {}

ATarget& ATarget::operator=( const ATarget & rhs ) {
	_type = rhs.getType();
	return (*this);
}

const std::string& ATarget::getType( void ) const { return _type; };

void ATarget::getHitBySpell( const ASpell& spell ) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
