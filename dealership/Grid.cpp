#include "Grid.hpp"

Grid::Grid()
{}

Grid::~Grid()
{}

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
		cout << ">";
	}
}

//iterate through the array to insert by price
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
