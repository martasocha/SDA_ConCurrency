#include "DataBase.hpp"

std::map<std::string, double> DataBase::getMapOfCurrencies()
{
    return _mapOfCurrencies;
}

void DataBase::updateCurrenciesAmountsFromFile()
{
    _mapOfCurrencies = readCurrenciesFromJSONFile();
}

std::map<std::string, double> DataBase::readCurrenciesFromJSONFile() const
{
    std::ifstream ifs("currencies.json");
    json j = json::parse(ifs);
    std::map<std::string, double> m = j;
    return m;
}