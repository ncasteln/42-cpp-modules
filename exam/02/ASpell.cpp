#include "Aspell.hpp"

ASpell::ASpell( std::string name, std::string effects ): _name(name), _effects(effects) {

}

ASpell::ASpell( void ) {

}
ASpell::~ASpell( void ) {

}
ASpell::ASpell( const ASpell & obj ):
	_name(obj._name),
	_effects(obj._effects) {}

ASpell& ASpell::operator=( const ASpell & rhs ) {
	_name = rhs.getName();
	_effects = rhs.getEffects();
	return (*this);
}

const std::string& ASpell::getName( void ) const { return _name; };
const std::string& ASpell::getEffects( void ) const { return _effects; };

void ASpell::launch( const ATarget& target ) const {
	target.getHitBySpell(*this);
}
