#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>
#include <iostream>

class ASpell;		// required by getHitBySpell() method

class ATarget {
	public:
		ATarget( void );
		ATarget( std::string type );
		virtual ~ATarget( void );
		ATarget( const ATarget & );
		ATarget& operator=( const ATarget & );

		const std::string& getType( void ) const;

		virtual ATarget* clone ( void ) const = 0;

		void getHitBySpell( const ASpell& spell ) const;
	protected:
		std::string _type;
};

#include "ASpell.hpp"

#endif
