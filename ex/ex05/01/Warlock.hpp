#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock{
    private:
        std::string _name;
        std::string _title;
        std::map <std::string, ASpell *> _spellDic;
        Warlock();
        Warlock(Warlock const &copy);
        Warlock &operator=(Warlock const &obj);

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        std::string getName() const;
        std::string getTitle() const;
        void setTitle(std::string const &str);
        void introduce() const;
        void learnSpell(ASpell *spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const &target);
};