#ifndef __DUMMY_HPP__
# define __DUMMY_HPP__

#pragma once
#include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy( void );
		~Dummy( void );
		Dummy( const Dummy& obj );
		Dummy& operator=( const Dummy& obj );

		ATarget* clone( void ) const;
};

#endif /* __DUMMY_HPP__ */