#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects):_name(name),_effects(effects){}
        
ASpell::ASpell(ASpell const &copy){
    *this = copy;
}

ASpell &ASpell::operator=(ASpell const &obj){
    if (this != &obj){
        this->_name = obj._name;
        this->_effects = obj._effects;
    }
    return *this;
}

ASpell::~ASpell(){}

std::string ASpell::getName() const{
    return _name;
}

std::string ASpell::getEffects() const{
    return _effects;
}

void ASpell::launch(ATarget const &target) const{
    target.getHitBySpell(*this);
}