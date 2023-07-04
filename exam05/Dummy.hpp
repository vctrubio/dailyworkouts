#pragma once

#include <iostream>
using namespace std;

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
    Dummy();
    ~Dummy();
    
    virtual ATarget *clone() const;
};
