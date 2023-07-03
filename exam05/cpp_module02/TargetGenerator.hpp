#pragma once

#include "ATarget.hpp"

#include <map>

class TargetGenerator : public ATarget 
{
    map<string, ATarget*> _map;
    map<string, ATarget*>::iterator it;
    
    public:
    TargetGenerator();
    ~TargetGenerator();

    bool    exist(string const &spell);

    void learnTargetType(ATarget *target);
    void forgetTargetType(string const &target);
    ATarget *createTarget(string const &target);
    ATarget *clone() const; //IF i dont have this it wont compile
};

