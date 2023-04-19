#ifndef API_HPP
#define API_HPP

#include "Headers.hpp"

#include <curl/curl.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#define SECRET "5b4a60ed8f62469e90626d523f0a53b5"

#ifndef FILENAME
#define FILENAME "json.txt"
#endif

class Api
{
	string	_key;
	CURL	*_curl;
public:
	Api(string key): _key(key){};
	Api(const Api &oldApi);
	Api& operator= (const Api &oldApi);
	~Api();
	
	void			makeCallJson();
	void			initJsonParse();
	vector<string>	callRFood();
};

#endif
