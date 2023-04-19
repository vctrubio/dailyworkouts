#ifndef API_HPP
#define API_HPP

#include "Headers.hpp"

#define SECRRET 5b4a60ed8f62469e90626d523f0a53b5

class Api
{
	string	_key;
public:
	Api(string key): _key(key){};
	Api(const Api &oldApi);
	Api& operator= (const Api &oldApi);
	~Api();
	
	vector<string>	callRFood();
};

#endif
