#ifndef __FIREBALL_HPP__
# define __FIREBALL_HPP__

#pragma once
#include "ASpell.hpp"

class Fireball: public ASpell
{
	public:
		Fireball( void );
		~Fireball( void );
		Fireball( const Fireball& obj );
		Fireball& operator=( const Fireball& obj );

		ASpell* clone( void ) const;
};

#endif /* __FIREBALL_HPP__ */