#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title) : _name(name), _title(title)
{
    cout << _name << ": This looks like another boring day.\n";
};

Warlock::~Warlock() { cout << _name << ": My job here is done!\n"; }

void Warlock::introduce() const
{
    cout << _name << ": I am " << _name << ", " << _title << "!\n";
};

void Warlock::setTitle(string const &title)
{
    _title = title;
}

string const &Warlock::getName() const { return _name; };
string const &Warlock::getTitle() const { return _title; };

bool Warlock::exist(string const &name)
{
    if (_map.empty())
        return false;
    for (it = _map.begin(); it != _map.end(); it++)
    {
        if (it->first == name)
            return true;
    }
    return false;
}

void Warlock::learnSpell(ASpell *spell)
{
    _book.learnSpell(spell);
};

void Warlock::forgetSpell(string spell)
{
    _book.forgetSpell(spell);
};

void Warlock::launchSpell(string spell, ATarget const &target){
    ATarget const *ptr = 0;
    if (ptr == &target)
        return ;
    ASpell *tmp = _book.createSpell(spell);
    if (tmp)
        tmp->launch(target);
};
