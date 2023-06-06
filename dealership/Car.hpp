#ifndef CAR_HPP
#define CAR_HPP

#include "Headers.hpp"

enum BRAND
{
	MERCEDES,
	VW,
	SEAT,
	AUDI,
	TOYOTA,
	FORD,
	NISSAN,
};


class Car
{
	BRAND			_brand;
	unsigned int	_price;
	string			_model;
public:
	Car(string model, unsigned int price);
	~Car();
	
	unsigned int	price(){return _price;};
	    friend std::ostream& operator<<(std::ostream& os, const Car& car);

};

#endif
