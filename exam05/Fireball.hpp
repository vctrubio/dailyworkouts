#pragma once

#include <iostream>
using namespace std;

#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
    Fireball();
    ~Fireball();
    
    virtual ASpell *clone() const;
};
