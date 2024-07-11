#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <string>
#include <map>
#include <algorithm>

class TargetGenerator {
	public:
		TargetGenerator( void );
		~TargetGenerator( void );
	
		void learnTargetType(const ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
	private:
		std::map<std::string, ATarget* > _targets;

		TargetGenerator( const TargetGenerator& );
		TargetGenerator& operator=( const TargetGenerator& );
};

#endif
