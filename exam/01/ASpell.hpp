#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

class ATarget;		// required by launch() method;

class ASpell {
	public:
		ASpell( std::string name, std::string effects );
		ASpell( void );
		virtual ~ASpell( void );
		ASpell( const ASpell & );
		ASpell& operator=( const ASpell & );

		const std::string& getName( void ) const;
		const std::string& getEffects( void ) const;

		virtual ASpell* clone ( void ) const = 0;

		void launch( const ATarget& target ) const;
	
	protected:
		std::string _name;
		std::string _effects;
};

#include "ATarget.hpp"

#endif
