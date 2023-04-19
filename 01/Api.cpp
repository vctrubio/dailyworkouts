#include "Api.hpp"

Api::Api(const Api &oldApi)
{}

Api& Api::operator= (const Api &oldApi)
{
	return (*this);
}

Api::~Api()
{}


size_t write_callback(char* ptr, size_t size, size_t nmemb, std::string* userdata) {
    size_t data_size = size * nmemb;
    userdata->append(ptr, data_size);
    return data_size;
}


vector<string>	Api::callRFood()
{
	vector<string>	search;


	return search;

}


void	Api::initCurl()
{
	_curl = curl_easy_init();

	if (!_curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return ;
    }

	const string url = "https://api.spoonacular.com/recipes/random?apiKey=" + _key;


	std::string response_buffer;
    curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &response_buffer);

	CURLcode res = curl_easy_perform(_curl);
    if (res != CURLE_OK) {
        std::cerr << "Failed to perform curl request: " << curl_easy_strerror(res) << std::endl;
        return ;
    }
	curl_easy_cleanup(_curl);

//	cout << "SO FAR: " << response_buffer <<endl ;;

//lets write a copy of the JSON file before continue

	ofstream outfile("json.txt");

	outfile << response_buffer;
	outfile.close();

/*
	rapidjson::Document document;
	rapidjson::ParseResult parseResult = document.Parse(response_buffer.c_str());

	if (!parseResult)
	{
		cerr << "Error on parseResult\n";
		return ;
	}

	int i = 0;
		std::cout << "Title: " << document["recipes"][i++]["title"].GetString() << std::endl;

*/

}
