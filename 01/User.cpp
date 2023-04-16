#include "User.hpp"

User::User()
{
	cout << "Welcome User\n";
}


User::User(const User &oldUser)
{}

User& User::operator= (const User &oldUser)
{
	return (*this);
}

User::~User()
{}
