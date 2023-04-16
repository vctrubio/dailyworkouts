#include "User.hpp"

User::User(string name)
{
	_name = name;
	_id = s_counterId++;

	cout << "User: " << _id << " : " << _name << endl;
}

int User::s_counterId = 0;
