#include "User.hpp"
#include "Book.hpp"

void	create_user()
{

}

void	all_user()
{

}

Book*	_DB()
{
	static Book	database;

	if (!database.lst_user)
			database.lst_user = new list<User>;
	return (&database);
}

int main()
{
	User		u("Billy");
	User		u2("Bobby");
	User		u3("Joel");
	Book		*database;

//	u.print();
//	u2.print();

	database = _DB();
	database->add(u);

	cout << u;
	database->lst_add(u);
	database->lst_add(u2);
	database->lst_add(u3);

//
	int		input;
	while (1)
	{
		cout << "[1] Create new User\n[2] View all Users\n[3] View all Requests\n[4] Exit\n";
		cin >> input;
		if (input == 4)
				break;
		if (input == 1)
				create_user();
		if (input == 2)
			database->printBook();
	}
	cout << "OK\n";
}


