#include "Warlock.hpp"

Warlock::Warlock( void ) {}

Warlock::~Warlock( void ) {
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock( const Warlock& obj ):
	_name(obj._name),
	_title(obj._title) {}

Warlock& Warlock::operator=( const Warlock& rhs ) {
	_name = rhs.getName();
	_title = rhs.getTitle();
	return (*this);
}

Warlock::Warlock( std::string name, std::string title ):
	_name(name),
	_title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
};

const std::string& Warlock::getName( void ) const { return (this->_name); }
const std::string& Warlock::getTitle( void ) const { return (this->_title); }

void Warlock::setTitle( const std::string& title ) { _title = title; }

void Warlock::introduce( void ) const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell( ASpell* spell ) {
	// _spell = spell->clone(); // owns its personal copy
	if (spell) // ?
		_book.learnSpell(spell);
}

void Warlock::forgetSpell( std::string spell_name ) {
	// if (_spell->getName() == spell_name) {
	// 	delete _spell;
	// 	_spell = NULL;
	// }
	_book.forgetSpell(spell_name);
}

void Warlock::launchSpell( std::string spell_name, ATarget& target ) {
	// if (_spell && (_spell->getName() == spell_name))
	// 	this->_spell->launch(target);
	if (_book.createSpell(spell_name))
		_book.createSpell(spell_name)->launch(target);

}
