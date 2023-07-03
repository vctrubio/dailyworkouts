#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (it = _map.begin(); it != _map.end();)
    {
        delete it->second;
    }
    _map.clear();
}

bool    SpellBook::exist(string const &spell)
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

void SpellBook::learnSpell(ASpell *spell) {
    if (spell && !exist(spell->getName()))
        _map.insert(make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(string const &spell) {
    if (_map.empty())
        return ;
    it = _map.find(spell);
    if (it!=  _map.end()){
        delete it->second;
    }
    _map.erase(spell);
}

ASpell *SpellBook::createSpell(string const &spell) {
    it = _map.find(spell);
    if (it != _map.end())
        return _map[spell];
    return NULL;
}
