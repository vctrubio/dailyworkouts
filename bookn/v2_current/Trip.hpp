#ifndef TRIP_HPP
#define TRIP_HPP

#include "Headers.hpp"
#include "User.hpp"
#include "Good.hpp"

class User;
class Good;

class Trip
{
	static int		s_counterId;
	int				_id;
	User*			_driver;
	User*			_client;
	int				_price;
	vector<Good*>	_goods;
public:
	Trip(User* driver);
	~Trip(){};
	
	void	setPrice(int price){_price = price;};
	void	setClient(User* client){_client = client;};
	void	addGood(Good *good){_goods.push_back(good);};
};

#endif
