#pragma once

#include <iostream>
#include <map>

#include "ATarget.hpp"

class TargetGenerator
{
    map<string, ATarget *> _map;
    map<string, ATarget *>::iterator it;

public:
    TargetGenerator();
    ~TargetGenerator();
    bool    exist(string name);
    void learnTargetType(ATarget *ptr);
    void forgetTargetType(string const &ptr);
    ATarget* createTarget(string const &ptr);
};