#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
    std::map <std::string, ASpell *>::iterator it = _spellDic.begin();
    while (it != _spellDic.end()){
        delete it->second;
        ++it;
    }
    _spellDic.clear();
}

SpellBook::SpellBook(SpellBook const &copy){
    *this = copy;
}

SpellBook &SpellBook::operator=(SpellBook const &obj){
    if (this != &obj)
        this->_spellDic = obj._spellDic;
    return *this;        
}

void SpellBook::learnSpell(ASpell *spell){
    if (spell)
            _spellDic[spell->getName()] = spell->clone(); 
}

void SpellBook::forgetSpell(std::string const &name){
    std::map<std::string, ASpell *>::iterator it = _spellDic.find(name);
    if (it != _spellDic.end())
        delete it -> second;
    _spellDic.erase(it);
}

ASpell *SpellBook::createSpell(std::string const &name){
    ASpell *tmp = NULL; 
    if (_spellDic.find(name) != _spellDic.end()){
        tmp = _spellDic[name];
    }   
    return (tmp);
}