#ifndef USER_HPP
#define USER_HPP

#include "Headers.hpp"

class User
{
	static int s_counterId;

	int		_id;
	string	_name;
public:
	User(string);
	~User(){};

	int		id(){return _id;};
	string	name(){return _name;};
};

#endif
