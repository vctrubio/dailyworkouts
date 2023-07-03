#include "ATarget.hpp"

ATarget::ATarget(string const &att): _att(att)
{
}

ATarget::ATarget()
{}

ATarget::~ATarget()
{}


string const &ATarget::getType() const{return _att;};


void    ATarget::getHitBySpell(ASpell const &ref) const {

    cout << _att << " has been " << ref.getEffects() << "!\n";
};