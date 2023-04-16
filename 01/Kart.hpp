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
	int 				_counter; 
	list<lst*>			_items;	
	list<lst*>::iterator it;
	bool				_checkout;
	int					_price;

public:
	Kart(): _counter(0), _price(0),_checkout(false){};
	Kart(const Kart &oldKart);
	Kart& operator= (const Kart &oldKart);
	~Kart();

	void	add(string);
	void	del(void);
	void	del(int id);
	void	delAll(void);
	void	show(void);
	void	show(int id);
	
};

#endif
