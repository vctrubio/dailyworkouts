#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator() {
    for (it = _map.begin(); it != _map.end();)
    {
        delete it->second;
    }
    _map.clear();
}

bool    TargetGenerator::exist(string const &spell)
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

void TargetGenerator::learnTargetType(ATarget *spell) {
    if (spell && !exist(spell->getType()))
        _map.insert(make_pair(spell->getType(), spell->clone()));
}

void TargetGenerator::forgetTargetType(string const &spell) {
    if (_map.empty())
        return ;
    it = _map.find(spell);
    if (it!=  _map.end()){
        delete it->second;
    }
    _map.erase(spell);
}

ATarget *TargetGenerator::createTarget(string const &spell) {
    it = _map.find(spell);
    if (it != _map.end())
        return _map[spell];
    return NULL;
}
