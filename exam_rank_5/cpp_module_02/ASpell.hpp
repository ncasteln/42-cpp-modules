#ifndef __ASPELL_HPP__
# define __ASPELL_HPP__

#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell( void );
		virtual ~ASpell( void );
		ASpell( const ASpell& );
		ASpell& operator=( const ASpell& );

		ASpell( std::string, std::string );

		const std::string& getName( void ) const;
		const std::string& getEffects( void ) const;

		virtual ASpell* clone( void ) const = 0;

		void launch( const ATarget& ) const;
	protected:
		std::string _name;
		std::string _effects;
};

#endif /* __ASPELL_HPP__ */