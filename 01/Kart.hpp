#ifndef KART_HPP
#define KART_HPP

#include "Headers.hpp"

struct lst
{
	int		id;
	string	refPtr; //memory based
	string	refStr; //item name
	
	lst(int i, string str)	:id(i), refStr(str){}
	~lst()	{} //check for leaks
};

class Kart
{
	list<lst*>			_items;	
	list<lst*>::iterator it;
public:
	Kart();
	Kart(const Kart &oldKart);
	Kart& operator= (const Kart &oldKart);
	~Kart();

	void	add(string);
	void	del(void);
	void	del(int id);
	void	show(void);
	void	show(int id);
};

#endif
