#include "httplib.h"
#include "picojson.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	// Make API url
	const std::string url = "https://dog-api.kinduff.com";
	std::string path = "/api/facts?number=";

	// Get number of facts
	if (argc == 2) {
		if (atoi(argv[1])) {
			path += argv[1];
		} else {
			std::cout << "Error: integer expected" << std::endl;
			return 1;
		}
	}

	// JSON input
	std::string json_data;

	httplib::Client cli(url);

	if (auto res = cli.Get(path)) {
		if (res->status == 200) {
			json_data = res->body;
		}
	} else {
		auto err = res.error();
		std::cout << "HTTP error: " << httplib::to_string(err) << std::endl;
		return 2;
	}

	// Parse the JSON
	picojson::value json_value;
	std::string err = picojson::parse(json_value, json_data); 

	// Check for parsing errors
	if (!err.empty()) {
		std::cerr << "Error parsing JSON: " << err << std::endl;
		return 3;
	}

	// Access the parsed JSON
	picojson::object& json_object = json_value.get<picojson::object>();

	// Access the "facts" array
	const picojson::array& facts_array = json_object["facts"].get<picojson::array>();

	// Iterate through the facts array and print each fact
	std::cout << "Facts:" << std::endl;
	for (const picojson::value& fact_value : facts_array) {
		std::string fact = fact_value.get<std::string>();
		std::cout << "- " << fact << std::endl;
	}

	// Access the "success" boolean value
	bool success = json_object["success"].get<bool>();

	std::cout << "Success: " << (success ? "true" : "false") << std::endl;

	return 0;
}

