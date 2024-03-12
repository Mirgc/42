#pragma once

#include <map>
#include "ASpell.hpp"

class SpellBook {
    private:
        SpellBook(SpellBook const &copy);
        SpellBook &operator=(SpellBook const &obj);
        std::map <std::string, ASpell *> _spellDic;

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell *);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};