#include "ASpell.hpp"

ASpell::ASpell(string const &name, string const &effects) : _name(name), _effects(effects)
{
}
ASpell::~ASpell()
{
}
ASpell::ASpell(ASpell const &other) { *this = other;}

ASpell &ASpell::operator=(ASpell const &other)
{
    this->_name = other.getName();
    this->_effects = other.getEffects();
    return (*this);
}

string const &ASpell::getName() const
{
    return _name;
};

string const &ASpell::getEffects() const
{
    return _effects;
};

void ASpell ::launch(ATarget const &ref) const
{
    ref.getHitBySpell(*this);
}
