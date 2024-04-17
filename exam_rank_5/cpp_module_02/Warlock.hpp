#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

#include <string>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	public:
		~Warlock( void );
		Warlock( std::string name, std::string title );

		const std::string& getName( void ) const;
		const std::string& getTitle( void ) const;

		void setTitle( const std::string& );

		void introduce() const;

		void learnSpell( ASpell* spell );
		void forgetSpell( std::string spell_name );
		void launchSpell( std::string spell_name, ATarget& target );
	private:
		std::string _name;
		std::string _title;
		ASpell*	_spell;
		SpellBook _book;

		Warlock( void );
		Warlock( const Warlock& );
		Warlock& operator=( const Warlock& );
};

#endif /* __WARLOCK_HPP__ */