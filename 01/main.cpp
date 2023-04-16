#include "Classroom.hpp"
#include "Classbox.hpp"
#include "Kart.hpp"


int main()
{
	cout << "Testing: Create a Linked List, with Max Size\n";


	Classroom test;

	test.add("Robert", 25, "Gay");
	test.add("Cuntler", 25, "Gayer");
	test.print();

	cout << "---------NEXT-----------\n";
/*
	listNode<string> l("Michelle");
	listNode<string> h("Hernesto");

	l.next = &h;
	cout << l.ptr << " ::\n";
	cout << l.next->ptr << " ::\n";
*/

	cout << "---------NEXT2----------\n";
	listNode<int> *node;
	listNode<int> *node2 = new listNode<int>{42};
	
	cout << "PRINT: " << node2->ptr << endl;
	cout << "---------NEXT3----------\n";
	Kart	k;

	string name = "Ballet";
	k.add(name);
	k.add("BallenaBe");
	k.show();
	k.show(1);
	k.show(4);
}
