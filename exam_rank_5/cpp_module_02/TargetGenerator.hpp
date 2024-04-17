#ifndef __TARGETGENERATOR_HPP__
# define __TARGETGENERATOR_HPP__

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	public:
		TargetGenerator( void );
		~TargetGenerator( void );

		void learnTargetType(ATarget*);
		void forgetTargetType( std::string const & );
		ATarget* createTarget( std::string const & );
	private:
		std::map<std::string, ATarget*> _generator;

		TargetGenerator( const TargetGenerator& );
		TargetGenerator& operator=( const TargetGenerator& );

};

#endif /* __TARGETGENERATOR_HPP__ */