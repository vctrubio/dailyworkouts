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

void	Api::makeCallJson()
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

	ofstream outfile(FILENAME);
	outfile << response_buffer;
	outfile.close();
	cout << "API call, and JSON.txt Success\n";
}

void	Api::initJsonParse()
{
	cout << "initJsonParse\n";
	ifstream	jsonFile(FILENAME);

	if (!jsonFile.is_open())
	{		cerr << "Reading of jsonFile Failed\n";
		return ;
	}
	string response_buffer((std::istreambuf_iterator<char>(jsonFile)),
                                 std::istreambuf_iterator<char>());
	jsonFile.close();

	rapidjson::Document document;
	rapidjson::ParseResult parseResult = document.Parse(response_buffer.c_str());

	if (!parseResult)
	{
		cerr << "Error on parseResult\n";
		return ;
	}

	const rapidjson::Value& recipes = document["recipes"];
	for (rapidjson::SizeType i = 0; i < recipes.Size(); i++) {
		const rapidjson::Value& recipe = recipes[i];
		const rapidjson::Value& ingredients = recipe["extendedIngredients"];
		for (rapidjson::SizeType j = 0; j < ingredients.Size(); j++) {
			const rapidjson::Value& ingredient = ingredients[j];
			const std::string& name_clean = ingredient["nameClean"].GetString();
			_foods.push_back(name_clean);
		}
	}
}

string	Api::callRFood()
{
	string	tmp = _foods.front();
	_foods.erase(_foods.begin());

	return tmp;
}