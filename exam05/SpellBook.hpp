#pragma once

#include <iostream>

#include "ASpell.hpp"
#include <map>
using namespace std;
class SpellBook
{
    map<string, ASpell*> _map;
    map<string, ASpell*>::iterator it;
public:
    SpellBook();
    ~SpellBook();

    bool    exist(string const &spell);
    void learnSpell(ASpell *spell);
    void forgetSpell(string const &spell);
    ASpell *createSpell(string const &spell);
};