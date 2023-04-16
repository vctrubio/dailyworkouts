#include "User.hpp"
#include "Kart.hpp"


int User::counter = 0;

void	printMenu(void)
{
	cout << "---------------------------------" << endl;
	cout << "| Add X | Show X | Del X | Help |" << endl;
	cout << "---------------------------------" << endl;
}

int main()
{
	cout << "Testing: Create a Linked List, with Max Size\n";
	printMenu();

	User	k;
	k.loop();

	
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

}
