#ifndef GRID_HPP
#define GRID_HPP

#include "Headers.hpp"
#include "Car.hpp"

class Grid
{
	list<Car*>		_inventory;
public:
	Grid(){};
	~Grid(){};
	void	loop();
	int		totalV(){return 1;};
	void	add();
	void	show();
	void	grid();
	void	addAlgo(Car *car);
};

void printGrid(Car* cars[HEIGHT][WIDTH]);

#endif
