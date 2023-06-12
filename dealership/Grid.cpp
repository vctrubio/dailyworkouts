#include "Grid.hpp"

void	Grid::loop()
{
	string	input;

	cout << ">";
	while(getline(std::cin, input))
	{
		if (input == "exit" || input == "break")
			break;
		if (input == "add")
			add();
		if (input == "show")
			show();
		if (input == "grid")
			grid();
		cout << ">";
	}
}

void	Grid::addAlgo(Car *car)
{
	if (_inventory.empty())
		_inventory.push_front(car);
	else
	{
		for (auto i = _inventory.begin(); i != _inventory.end(); i++)
		{
			if (car->price() > (*i)->price())
			{
				_inventory.insert(i, car);
				break;
			}
		}
	}
}

void printGrid(Car* cars[HEIGHT][WIDTH])
{
	std::cout << "-----------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			std::cout << "| ";
			if (cars[i][j] != nullptr)
			{
				std::cout << *cars[i][j];
			}
			else
			{
				std::cout << std::setw(10) << std::left << "Empty";
			}
		}
		std::cout << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------------------" << std::endl;
	}
};

void	Grid::grid()
{
	Car*	cars[HEIGHT][WIDTH] = {nullptr};

	int	column = 0;
	int	row = -1;
	for (auto car : _inventory)
	{
		column = column % WIDTH;
		if (column == 0)
			row++;
		cars[row][column] = car;
		column++;
	}

	printGrid(cars);
}

void	Grid::show()
{
	cout << "Total Cars: " << _inventory.size() << endl;

	for (auto i : _inventory)
		cout << *i << endl;
}

void	Grid::add()
{
	string	model;
	string	price;

	cout << "ADD CAR:\n";
	cout << "MAKE>";
	getline(cin, model);
	cout << "PRICE>";
	getline(cin, price);
	
	try
	{
		Car		*car = new Car(model, stoi(price));
		addAlgo(car);
	}
	catch (...)
	{
		cerr << "Car not created.\n";
	}

}
