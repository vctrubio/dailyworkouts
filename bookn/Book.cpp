#include "Book.hpp"

Book::Book()
{}

Book::Book(const Book &oldBook)
{}

Book& Book::operator= (const Book &oldBook)
{
	return (*this);
}

Book::~Book()
{}

void	Book::add(User user)
{
	int	i;

	i = 0;
	while(this->users[i])
			i++;
	this->users[i] = &user;
}


void	Book::lst_add(User &user)
{
	lst_user->push_back(user);
	cout << "Addind... " + user.print();
	cout << lst_user->back() << endl;

}


void	Book::printBook()
{
	list<User>::iterator itr;

	cout << "Printing Book...\n";
	
	for (itr = lst_user->begin(); itr != lst_user->end(); itr++)
			cout << itr->print();
}

