#pragma once
#include <iostream>
#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell
{
    string _name;
    string _effects;
public:
    ASpell(string const &name, string const &effects);
    virtual ~ASpell();

    string  const &getName() const;
    string  const &getEffects() const;

    virtual ASpell *clone() const = 0;
    void    launch(ATarget const &ref) const;

};