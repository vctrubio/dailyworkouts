#ifndef BOOK_HPP
#define BOOK_HPP

#include "Headers.hpp"
#include "User.hpp"

#define	MAX_CAP 20

class Book
{
public:
	Book();
	Book(const Book &oldBook);
	Book& operator= (const Book &oldBook);
	~Book();

	User	*users[MAX_CAP];
	void	printBook();
	void	add(User user);

	list<User>	*lst_user;
	void		lst_add(User &user);
};

#endif
