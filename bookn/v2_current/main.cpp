#include "../Headers.hpp"
#include "../mysql/mysql.h"
#include "User.hpp"
#include "Trip.hpp"
#include "Good.hpp"

int main()
{
    cout << "Running...\n";

	User *billy = new User("Billy");

	User joe("JOE");

	Trip	trip(&joe);
	Good	raquet("Tennis Raquet");
	trip.addGood(&raquet);
    return 1;

}

