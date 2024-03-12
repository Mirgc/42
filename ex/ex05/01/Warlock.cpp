#include "Warlock.hpp"

Warlock::Warlock(){}
        
Warlock::Warlock(Warlock const &copy){
    *this = copy;
}

Warlock &Warlock::operator=(Warlock const &obj){
    if (this != &obj){
        this->_name = obj._name;
        this->_title = obj._title;
    }
    return *this;
}

Warlock::Warlock(std::string name, std::string title):_name(name),_title(title){
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
    std::cout << _name << ": My job here is done!" << std::endl;
    std::map <std::string, ASpell *>::iterator it = _spellDic.begin();
    while (it != _spellDic.end()){
        delete it->second;
        ++it;
    }
    _spellDic.clear();
}

std::string Warlock::getName() const{
    return _name;
}

std::string Warlock::getTitle() const{
    return _title;
}

void Warlock::setTitle(std::string const &str){
    _title = str;
}

void Warlock::introduce() const{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell){
    if (spell){
        if (_spellDic.find(spell->getName()) == _spellDic.end())
            _spellDic[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string name){
    if (_spellDic.find(name) != _spellDic.end())
        _spellDic.erase(_spellDic.find(name));
}

void Warlock::launchSpell(std::string name, ATarget const &target){
    if (_spellDic.find(name) != _spellDic.end())
        _spellDic[name]->launch(target);
}