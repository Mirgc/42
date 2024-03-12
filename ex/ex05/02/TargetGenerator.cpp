#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){}

TargetGenerator::TargetGenerator(TargetGenerator const &copy){
    *this = copy;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &obj){
    if (this != &obj)
        this->_targetDic = obj._targetDic;
    return *this;
}

void TargetGenerator::learnTargetType(ATarget *target){
    if (target)
            _targetDic[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &name){
    if (_targetDic.find(name) != _targetDic.end())
        _targetDic.erase(_targetDic.find(name));
}

ATarget *TargetGenerator::createTarget(std::string const &name){
    std::map <std::string, ATarget *>::iterator it = _targetDic.find(name);
    if (it != _targetDic.end())
        return _targetDic[name];
    return NULL;
}