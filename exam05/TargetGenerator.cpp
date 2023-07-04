#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator it_begin = this->_map.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->_map.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_map.clear();
}

bool TargetGenerator::exist(string spell)
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

void TargetGenerator::learnTargetType(ATarget* spell_ptr)
{
    if (spell_ptr)
        _map.insert(std::pair<std::string, ATarget *>(spell_ptr->getType(), spell_ptr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &spell_name)
{
    if (exist(spell_name))
    {
        delete _map[spell_name];
        _map.erase(spell_name);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &spell_name)
{
    std::map<std::string, ATarget *>::iterator it = _map.find(spell_name);
    if (it != _map.end())
        return _map[spell_name];
    return NULL;
}
