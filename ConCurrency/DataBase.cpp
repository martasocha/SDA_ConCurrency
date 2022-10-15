#include "DataBase.hpp"

DataBase::DataBase()
{
    _mapOfCurrencies = getCurrenciesFromJSONFile();
}

std::map<std::string, double> DataBase::getMapOfCurrencies()
{
    return _mapOfCurrencies;;
}

std::map<std::string, double> DataBase::getCurrenciesFromJSONFile() const
{
    std::ifstream ifs("currencies.json");
    json j = json::parse(ifs);
    std::map<std::string, double> m = j;
    return m;
}