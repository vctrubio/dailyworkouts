#ifndef GRID_HPP
#define GRID_HPP

#include "Headers.hpp"
#include "Car.hpp"

class Grid
{
	Car*			_cars[6][6];
	list<Car*>		_inventory;
public:
	Grid();
	~Grid();
	void	loop();
	int		totalV(){return 1;};
	void	add();
	void	show();
	void	addAlgo(Car *car);
};

#endif
