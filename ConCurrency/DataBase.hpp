#pragma once
#include "json/json.hpp"
#include <map>
#include <string>
#include <fstream>

using json = nlohmann::json;


class DataBase
{
private:
	std::map<std::string, double> _mapOfCurrencies = {};
	std::map<std::string, double> readCurrenciesFromJSONFile() const;
public:
	DataBase();
	std::map<std::string, double> getMapOfCurrencies();
};