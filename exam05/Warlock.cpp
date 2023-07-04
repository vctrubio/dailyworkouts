#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title) : _name(name), _title(title)
{
    cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    cout << _name << ": My job here is done!\n";
}

string const &Warlock::getName() const
{
    return _name;
}

string const &Warlock::getTitle() const
{
    return _title;
}

void Warlock::setTitle(string const &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

bool Warlock::exist(string spell)
{
    if (_map.empty())
        return false;
    for (it = _map.begin(); it != _map.end(); it++)
    {
        if (it->first == spell)
            return true;
    }
    return false;
}

void Warlock::learnSpell(ASpell *spell)
{
    book.learnSpell(spell);
}

void Warlock::forgetSpell(string spell)
{
    book.forgetSpell(spell);
}

void Warlock::launchSpell(string spell, ATarget const &ref)
{
    ASpell *ptr = book.createSpell(spell);
    if (ptr)
        ptr->launch(ref);
}