#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
	public:
		Warlock( std::string name, std::string title );
		~Warlock( void );
	
		const std::string& getName( void ) const;
		const std::string& getTitle( void ) const;
		void setTitle( std::string title ); 
	
		void introduce() const;

		void learnSpell( const ASpell* newSpell );
		void forgetSpell( std::string spellName );
		void launchSpell( std::string spellName, const ATarget& target );

	private:
		std::string _name;
		std::string _title;
		SpellBook _book;

		Warlock( void );
		Warlock( const Warlock& );
		Warlock& operator=( const Warlock& );

};

#endif
