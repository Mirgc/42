#pragma once

#include <map>
#include "ATarget.hpp"

class TargetGenerator {
    private:
        TargetGenerator(TargetGenerator const &copy);
        TargetGenerator &operator=(TargetGenerator const &obj);
        std::map <std::string, ATarget *> _targetDic;

    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &name);
        ATarget *createTarget(std::string const &name);

};