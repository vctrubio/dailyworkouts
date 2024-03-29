#include "User.hpp"
#include "Kart.hpp"
#include "Api.hpp"


int User::counter = 0;

void	printMenu(void)
{
	cout << "---------------------------------" << endl;
	cout << "| Add X | Show X | Del X | Help |" << endl;
	cout << "---------------------------------" << endl;
}

void	init(User *user, ifstream &file)
{



}

#include <unistd.h>

void	threadTest(User *u)
{
	ifstream file(FILENAME);
	Api	me(SECRET);

	//fetch api
	if (!file.good())
		me.makeCallJson();
	//parseJSON to vector<string>
	me.initJsonParse();
	for (int i = 0; i < 3; i++)
	{
		u->add(me.callRFood());
		usleep(5000000);
		cout << "Looped ThreadTest\n";
	}
	cout << "FINITO ThreadTest\n";
	file.close();
}

int main()
{
	cout << "Testing: Create a Linked List, with Max Size\n";
	cout << "|Users| have a shopping |cart| with |items|, |checkout| and interact with |wallet|\n";
	printMenu();
	
	User	*u = new User();
	thread testing(threadTest, u);

	testing.join();
	u->testLoop();

	delete u;
}

/*
	cout << "---------NEXT1---------\n";
	string name = "Ballet";
	k.add(name);
	k.add("BallenaBe");
	k.add("Boner");
	k.add("Bobby");
	k.show();

	cout << "---------NEXT2---------\n";
	k.del();
	k.delAll();
	k.show();
*/
