#include <iostream>
#include <string>
#include "httplib.h"

int main(int argc, char *argv[])
{
	const std::string url = "https://dog-api.kinduff.com";
	std::string path = "/api/facts?number=";
	if (argc == 2) path += argv[1];
	httplib::Client cli(url);
	auto res = cli.Get(path);
	std::cout << res->status << " OK\n" << res->body << std::endl;
	return 0;
}

