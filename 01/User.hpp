#ifndef USER_HPP
#define USER_HPP

#include "Headers.hpp"
#include "Kart.hpp"

class Kart;

class User : public Kart
{
public:
	User();
	User(const User &oldUser);
	User& operator= (const User &oldUser);
	~User();
};

#endif
