#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator( void ) {};

TargetGenerator::~TargetGenerator( void ) {
	// nothing is allocated
};

TargetGenerator::TargetGenerator( const TargetGenerator& obj ): _generator( obj._generator ) {}

TargetGenerator& TargetGenerator::operator=( const TargetGenerator& rhs ) {
	_generator = rhs._generator;
	return (*this);
}

void TargetGenerator::learnTargetType( ATarget* target ) {
	if (target)
		_generator[target->getType()] = target; //->clone(); ---- IT ABSTRACT!
}

void TargetGenerator::forgetTargetType( std::string const & type ) {
	std::map<std::string, ATarget*>::iterator it = _generator.begin();
	while (it != _generator.end()) {
		if ((*it).first == type) {
			_generator.erase(it);
		}
		it++;
 	}
}

ATarget* TargetGenerator::createTarget( std::string const & type ) {
	ATarget* toFind = NULL;
	std::map<std::string, ATarget*>::iterator it = _generator.begin();
	while (it != _generator.end()) {
		if ((*it).first == type)
			toFind = (*it).second;
		it++;
	}
	return (toFind);
}
