#pragma once
#include <iostream>
#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget
{
    string _att;
public:
    ATarget();
    ATarget(string const &att);
    virtual ~ATarget();

    string  const &getType() const;

    void    getHitBySpell(ASpell const &ref) const;
    virtual ATarget *clone() const = 0;
};