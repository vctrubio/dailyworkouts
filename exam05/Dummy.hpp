#pragma once

#include <iostream>

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
    Dummy();
    ~Dummy();

    Dummy *clone() const;

};