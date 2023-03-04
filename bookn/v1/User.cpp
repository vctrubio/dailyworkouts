#include "User.hpp"

User::User(string name)
{
	static int	id;

	if (!id)
			id = 1;
	_name = name;
	_id = id++;
}

User::User(const User &oldUser)
{}

User& User::operator= (const User &oldUser)
{
	return (*this);
}

User::~User()
{}

string	User::print()
{
	string	rtn;

	rtn = to_string(this->_id) + " " + this->_name + ";\n";
	return (rtn);
}

ostream& operator<<(ostream &os, User &u)
{
	os << u.print();
	return (os);
}
