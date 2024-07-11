#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator( void ) {


}
TargetGenerator::~TargetGenerator( void ) {
	std::map<std::string, ATarget* >::iterator it = _targets.begin();
	while (it != _targets.end()) {
		delete (*it).second;
		it++;
	}
	_targets.clear();
}

void TargetGenerator::learnTargetType( const ATarget* newTarget) {
	if (!newTarget) return ;
	if (_targets.find(newTarget->getType()) != _targets.end()) return ; // if exist
	_targets[newTarget->getType()] = newTarget->clone();
};

void TargetGenerator::forgetTargetType(std::string const & ttype ) {
	if (_targets.find(ttype) == _targets.end()) return ; // if NOT exist
	delete (*_targets.find(ttype)).second;
	_targets.erase(_targets.find(ttype));			// erase ?
};

ATarget* TargetGenerator::createTarget(std::string const & ttype ) {
	if (_targets.find(ttype) == _targets.end()) return (NULL); // if NOT exist
	return ((*_targets.find(ttype)).second);
};

// not used
/* TargetGenerator::TargetGenerator( const TargetGenerator& ) {}
TargetGenerator& TargetGenerator::operator=( const TargetGenerator& ) {}
 */
