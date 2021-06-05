#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <cpp_httplib/httplib.h>
#include <fstream>
#include <typeinfo>
#include <iomanip>




using namespace httplib;
using json = nlohmann::json;

std::string Shablon;
void send_note(const Request& req, Response& response) {
	json json_req = json::parse(req.body);
// read a JSON file
	std::ifstream i("file.json");
	json j;
	i >> j;
	std::string one = j["chat_note"]["note"];
	response.set_content(one, "text/plain");

}


void get_note(const Request& req, Response& response) {

	json json_req = json::parse(req.body);
	json j;
	j["chat_note"]["note"].push_back(json_req);

	std::ofstream o("file.json");
	o << std::setw(4) << j << std::endl;
	std::cout << json_req;
}

int main() {
	setlocale(LC_ALL, "en_US.UTF8");

	Server svr;
	
	svr.Post("/get_note", get_note);
	
	svr.Post("/send_note", send_note);

	std::cout << "Server is.....ok\n";

	svr.listen("localhost", 3000);

}