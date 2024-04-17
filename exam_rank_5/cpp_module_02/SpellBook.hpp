#ifndef __SPELLBOOK_HPP__
# define __SPELLBOOK_HPP__

#include <string>
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell*> _book;

		SpellBook( const SpellBook& );
		SpellBook& operator=( const SpellBook& );
	public:
		SpellBook( void );
		~SpellBook( void );

		void learnSpell( ASpell* );
		void forgetSpell( std::string const& spell_name );
		ASpell* createSpell( std::string const & );
};

#endif /* __SPELLBOOK_HPP__ */