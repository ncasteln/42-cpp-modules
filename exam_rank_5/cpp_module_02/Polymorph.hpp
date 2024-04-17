#ifndef __POLYMORPH_HPP__
# define __POLYMORPH_HPP__

#pragma once
#include "ASpell.hpp"

class Polymorph: public ASpell
{
	public:
		Polymorph( void );
		~Polymorph( void );
		Polymorph( const Polymorph& obj );
		Polymorph& operator=( const Polymorph& obj );

		ASpell* clone( void ) const;
};

#endif /* __POLYMORPH_HPP__ */