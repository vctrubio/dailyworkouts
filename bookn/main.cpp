#include "User.hpp"
#include "Book.hpp"
#include "mysql/mysql.h"

struct connection_details
{
		const char	*server, *user, *password, *database;
};

Book*	_DB()
{
	static Book	database;

	return (&database);
}

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

	MYSQL						*con;
	MYSQL_RES					*res;
	MYSQL_ROW					row;
	struct connection_details	mysqlD;

	mysqlD.server = "localhost";
	mysqlD.user = "trtp";
	mysqlD.password = "password";
	mysqlD.database = "test";

	con = mysql_connection_setup(mysqlD);

    // get the results from executing commands
    res = mysql_execute_query(con, "select * from USER;");

    std::cout << ("Database Output:\n") << std::endl;

    while ((row = mysql_fetch_row(res)) != NULL){
        // the below row[] parametes may change depending on the size of the table and your objective
        std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << std::endl << std::endl;
    }

    // clean up the database result
    mysql_free_result(res);
    
    // close database connection
    mysql_close(con);


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


