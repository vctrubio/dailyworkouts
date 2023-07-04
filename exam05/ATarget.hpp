#pragma once

#include <iostream>
using namespace std;

class ASpell;

class ATarget
{
    string _type;

public:
    ATarget(string const &type);
    virtual ~ATarget();
    ATarget(ATarget const &other);
    ATarget &operator=(ATarget const &other);
    string const &getType() const;

    void getHitBySpell(ASpell const &ref) const;

    virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"
