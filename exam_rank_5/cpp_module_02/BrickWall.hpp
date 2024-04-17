#ifndef __BRICKWALL_HPP__
# define __BRICKWALL_HPP__

#pragma once
#include "ATarget.hpp"

class BrickWall: public ATarget
{
	public:
		BrickWall( void );
		~BrickWall( void );
		BrickWall( const BrickWall& obj );
		BrickWall& operator=( const BrickWall& obj );

		ATarget* clone( void ) const;
};

#endif /* __BRICKWALL_HPP__ */