#ifndef USER_HPP
#define USER_HPP

#include "Headers.hpp"

class User
{
		string	_name;
		int		_id;
public:
	User(string name);
	User(const User &oldUser);
	User& operator= (const User &oldUser);
	~User();

	string	print();
};


ostream& operator<<(ostream &os, User &u);


#endif
