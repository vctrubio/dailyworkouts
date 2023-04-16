#ifndef GOOD_HPP
#define GOOD_HPP

#include "Headers.hpp"

class Good
{
	static int	s_counterId;
	int			_id;
	string		_name;
	string		_describe;
	int			_weight;
public:
	Good(string name):_id(s_counterId++), _name(name){};
	~Good(){};
};

#endif
