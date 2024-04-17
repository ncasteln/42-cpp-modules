#include "SpellBook.hpp"

SpellBook::SpellBook( void ) {}

SpellBook::~SpellBook( void ) {
	std::map<std::string, ASpell*>::iterator it = _book.begin();
	while (it != _book.end()) {
		delete (*it).second;
		it++;
	}
	_book.clear();
}

SpellBook::SpellBook( const SpellBook& obj ): _book(obj._book) {}

SpellBook& SpellBook::operator=( const SpellBook& rhs ) {
	this->_book = rhs._book;
	return (*this);
}

void SpellBook::learnSpell( ASpell* spell ) {
	if (spell)
		_book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell( std::string const& spell_name ) {
	std::map<std::string, ASpell*>::iterator it = _book.begin();
	while (it != _book.end()) {
		if ((*it).first == spell_name) {
			delete (*it).second;
			_book.erase(it);
		}
 	}
}

ASpell* SpellBook::createSpell( std::string const & name ) {
	ASpell* toFind = NULL;
	std::map<std::string, ASpell*>::iterator it = _book.begin();
	while (it != _book.end()) {
		if ((*it).first == name)
			toFind = (*it).second;
		it++;
	}
	return (toFind);
}
