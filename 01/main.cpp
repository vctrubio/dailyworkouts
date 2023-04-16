#include "User.hpp"
#include "Kart.hpp"



void	printMenu(void)
{
	cout << "---------------------------------" << endl;
	cout << "| Add X | Show X | Del X | Help |" << endl;
	cout << "---------------------------------" << endl;
}

void	helo(void)
{
	cout << "Commands " << endl;
	cout << "Add <item> WHERE item is (string)" << endl;
	cout << "Show <id> || Show <null> " << endl;
	cout << "Del <id> || Del <null> || DelAll " << endl;
}

int main()
{
	cout << "Testing: Create a Linked List, with Max Size\n";

	printMenu();

	User	k;

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


}
