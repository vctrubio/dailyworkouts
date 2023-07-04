#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it_begin = this->_map.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->_map.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_map.clear();
}

bool SpellBook::exist(string spell)
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

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell && !exist(spell->getName()))
        _map.insert(pair<string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(string const &spell)
{

        it = _map.find(spell);
        if (it != _map.end())
            delete it->second;
        _map.erase(spell);
}

ASpell* SpellBook::createSpell(string const &spell)
{
    it = _map.find(spell);
    if (it != _map.end())
        return _map[spell];
    return NULL;
}