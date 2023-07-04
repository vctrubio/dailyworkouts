#pragma once

#include <iostream>
using namespace std;

class ATarget;

class ASpell
{
    string _name;
    string _effects;

public:
    ASpell(string const &name, string const &effects);
    ASpell(ASpell const &other);
    ASpell &operator=(ASpell const &other);
    virtual ~ASpell();

    string const &getName() const;
    string const &getEffects() const;

    void launch(ATarget const &ref) const;
    virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"