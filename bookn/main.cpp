#include "User.hpp"
#include "Book.hpp"
#include "mysql/mysql.h"
#include "Headers.hpp"


struct SQLConnection
{
	string server, user, password, database;

	SQLConnection(string server, string user, string password, string database)
	{
		this->server = server;
		this->user = user;
		this->password = password;
		this->database = database;
	}
};


tuple<bool, MYSQL *> sqlConnectionSetup(struct SQLConnection mysql_details)
{
	MYSQL	*connection = mysql_init(NULL);
	bool	success = true;

	if (!mysql_real_connect(connection, mysql_details.server.c_str(), 
	mysql_details.user.c_str(), 
	mysql_details.password.c_str(),
	 mysql_details.database.c_str(), 0, NULL, 0))
	{
		success = false;
		cout << "Connection Error" << mysql_error(connection) << endl;
	}
	return (make_tuple(success, connection));
}

int main()
{
	User		u("Billy");
	User		u2("Bobby");
	User		u3("Joel");
	Book		*database;

	database = _DB();

	database->lst_add(&u);
	database->lst_add(&u2);
	database->lst_add(&u3);

//
	bool 		success;
	MYSQL		*con;
	MYSQL_ROW	row;

	struct SQLConnection sqlDetails("localhost", "trtp", "password", "test");

	tie(success, con) = sqlConnectionSetup(sqlDetails);

	if (!success)
	{
		return 1;
	}
	else
		cout << "WE IN\n";

	int		input;
	while (1)
	{
		cout << "-- -- -- --\n[1] Create new User\n[2] View all Users\n[3] View all Requests\n[4] Exit\n";
		cin >> input;
		if (input == 4)
				break;
		if (input == 1)
				;
		if (input == 2)
			database->printBook();
	}
	cout << "OK\n";
}



/*
MYSQL		*mysql_connection_setup(struct connection_details mysql_details)
{
		MYSQL	*connection;

		connection = mysql_init(NULL);
		if (!mysql_real_connect(connection, mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0))
		{
			cout << "Coneection ERROR" << mysql_error(connection) << endl;
			exit(1);
		}
	return (connection);
}

MYSQL_RES	*mysql_execute_query(MYSQL *connection, const char *sql_query)
{
	if (mysql_query(connection, sql_query))
	{
		cout << "SQL query error\n" << mysql_error(connection) << endl;
		exit(1);
	}
	return (mysql_use_result(connection));
}
*/
