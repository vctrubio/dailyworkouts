#include "ATarget.hpp"

ATarget::ATarget(string const &type) : _type(type)
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(ATarget const &other) { *this = other; }

ATarget &ATarget::operator=(ATarget const &other)
{
    this->_type = other.getType();
    return (*this);
}

string const &ATarget::getType() const
{
    return _type;
};

void ATarget::getHitBySpell(ASpell const &ref) const
{
    cout << _type << " has been " << ref.getEffects() << "!\n";
}