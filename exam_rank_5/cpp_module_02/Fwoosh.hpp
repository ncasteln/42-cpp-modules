#ifndef __FWOOSH_HPP__
# define __FWOOSH_HPP__

#pragma once
#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh( void );
		~Fwoosh( void );
		Fwoosh( const Fwoosh& obj );
		Fwoosh& operator=( const Fwoosh& obj );

		ASpell* clone( void ) const;
};

#endif /* __FWOOSH_HPP__ */