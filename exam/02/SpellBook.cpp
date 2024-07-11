#include "SpellBook.hpp"

SpellBook::SpellBook( void ) {


}
SpellBook::~SpellBook( void ) {
	std::map<std::string, ASpell* >::iterator it = _book.begin();
	while (it != _book.end()) {
		delete (*it).second;
		it++;
	}
	_book.clear();
}

void SpellBook::learnSpell( const ASpell* newSpell) {
	if (!newSpell) return ;
	if (_book.find(newSpell->getName()) != _book.end()) return ; // if exist
	_book[newSpell->getName()] = newSpell->clone();
};

void SpellBook::forgetSpell(std::string const & spellName ) {
	if (_book.find(spellName) == _book.end()) return ; // if NOT exist
	delete (*_book.find(spellName)).second;
	_book.erase(_book.find(spellName));			// erase ?
};

ASpell* SpellBook::createSpell(std::string const & spellName ) {
	if (_book.find(spellName) == _book.end()) return (NULL); // if NOT exist
	return ((*_book.find(spellName)).second);
	// return (_book[spellName]->clone());
};

// not used
/* SpellBook::SpellBook( const SpellBook& ) {}
SpellBook& SpellBook::operator=( const SpellBook& ) {} */
