#pragma once

#include <iostream>
using namespace std;

#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
    Polymorph();
    ~Polymorph();
    
    virtual ASpell *clone() const;
};
