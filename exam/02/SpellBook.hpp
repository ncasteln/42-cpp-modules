#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <string>
#include <map>
#include <algorithm>

class SpellBook {
	public:
		SpellBook( void );
		~SpellBook( void );
	
		void learnSpell(const ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
	private:
		std::map<std::string, ASpell* > _book;

		SpellBook( const SpellBook& );
		SpellBook& operator=( const SpellBook& );
};

#endif
