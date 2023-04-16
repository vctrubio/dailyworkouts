#include "Kart.hpp"

Kart::Kart()
{
}


Kart::Kart(const Kart &oldKart)
{}

Kart& Kart::operator= (const Kart &oldKart)
{
	return (*this);
}

Kart::~Kart()
{}

void	Kart::add(string name)
{
	static int 	id = 0;
	lst		*tmp = new lst(id++, name);

	_items.push_back(tmp);
}

void	Kart::del(void)
{
	try
	{
		if (_items.empty())
			throw runtime_error("Empty");
		_items.pop_back();
	}
	catch (exception &e)
	{
		cout << e.what() << " :expection_thrown:\n";
	}
}


void	Kart::del(int id)
{
	for (it = _items.begin(); it != _items.end(); it ++)
	{
		if ((*it)->id == id)
		{
			delete *it;
			it = _items.erase(it);
			break;
		}
	}
}


//lamda fuction that calls it and passes a function -TODOIMPROVE
void	Kart::show(void)
{
	cout << "SHOW--\n";
	for (it = _items.begin(); it != _items.end(); it ++)
	{
		cout << (*it)->id << " : " << (*it)->refStr << endl;
	}
}

void	Kart::show(int id)
{
	cout << "SHOWID-- " << id << endl;
	try
	{
		if (id > _items.size())
			throw out_of_range("ID > size()");
		it = std::next(_items.begin(), id);
		cout << (*it)->id << " : " << (*it)->refStr << endl;
	}
	//catch(...)
	catch(out_of_range &e)
	{
		cerr << e.what() << " :out_of_range\n";
	}
}





