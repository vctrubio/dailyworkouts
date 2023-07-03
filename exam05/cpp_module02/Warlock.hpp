#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

using namespace std;

class Warlock
{
    string _name;
    string _title;
    map<string, ASpell *>           _map;
    map<string, ASpell *>::iterator it;

    SpellBook   _book;
public:
    Warlock(string const &name, string const &title);
    ~Warlock();

    string  const &getName() const;
    string  const &getTitle() const;

    void    setTitle(string const &title);

    void    introduce() const;

    bool    exist(string const &name);
    ///+3
    void    learnSpell(ASpell *spell);
    void    forgetSpell(string spell);
    void    launchSpell(string spell, ATarget const &target);
};