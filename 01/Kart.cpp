#include "Kart.hpp"

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
	if (_checkout)
		return ;

	lst		*tmp = new lst(_counter++, name);
	_items.push_back(tmp);

	if (_items.size() >= SIZE)
		_checkout = true;
}

void	Kart::del(void)
{
	try
	{
		if (_items.empty())
			throw runtime_error("Empty");
		auto ptr = _items.back();
		_items.pop_back();
		delete ptr;
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

void	Kart::delAll(void)
{
	for (it = _items.begin(); it != _items.end();)
	{
		delete *it;
		it = _items.erase(it);
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
