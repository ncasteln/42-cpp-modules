#ifndef __ATARGET_HPP__
# define __ATARGET_HPP__

#pragma once
#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget( void );
		~ATarget( void );
		ATarget( const ATarget& );
		ATarget& operator=( const ATarget& );
		const std::string& getType( void ) const;

		virtual ATarget* clone( void ) = 0;

		void getHitBySpell( const ASpell& ) const;
	protected:
		std::string _type;
};

#endif /* __ATARGET_HPP__ */