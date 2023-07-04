#pragma once

#include <iostream>
#include <map>
using namespace std;

#include "ASpell.hpp"

class SpellBook
{
    map<string, ASpell *> _map;
    map<string, ASpell *>::iterator it;
public:
    SpellBook();
    ~SpellBook();
    
    bool exist(string spell);

    //+3
    void    learnSpell(ASpell *spell);
    void    forgetSpell(string const &spell);
    ASpell  *createSpell(string const &spell);
};

