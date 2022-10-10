#pragma once
#include <map>
#include <string>

class DataBase
{
public:
	std::map<std::string, double> getMapOfCurrencies();
	//void setMapOfCurrencies(std::map<std::string, double> newMapOfCurrencies);

private:
	std::map<std::string, double> mapOfCurrencies{ {"EUR",4.8762}, {"USD",4.9374}, {"CHF", 5.0115} };

};