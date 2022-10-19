#pragma once
#include "json/json.hpp"
#include <map>
#include <string>
#include <vector>
#include <fstream>

using json = nlohmann::json;

class CashRegister
{
private:

	std::map<std::string, double> _cashRegistersForCurrencies = {};

public:
	CashRegister();
	CashRegister(std::map<std::string, double> cashRegistersForCurrencies);
	std::map<std::string, double> getCashRegistersForCurrencies() const;
	void setCashRegistersForCurrencies(std::map<std::string, double> cashRegistersForCurrencies);
	std::map<std::string, double> readCurrenciesAmountsFromJSONFile() const;
	void updateCurrenciesAmountsFromFile();
	void writeCurrenciesAmountsToJSONFile() const;


};