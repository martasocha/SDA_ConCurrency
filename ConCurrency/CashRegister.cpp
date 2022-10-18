#include "CashRegister.hpp"

CashRegister::CashRegister()
{
    _cashRegistersForCurrencies = readCurrenciesAmountsFromJSONFile();
}

std::map<std::string, double> CashRegister::getCashRegistersForCurrencies() const
{
	return _cashRegistersForCurrencies;
}

void CashRegister::setCashRegistersForCurrencies(std::map<std::string, double> cashRegistersForCurrencies)
{
	this->_cashRegistersForCurrencies = cashRegistersForCurrencies;
}

std::map<std::string, double> CashRegister::readCurrenciesAmountsFromJSONFile() const
{
    std::ifstream ifs("currenciesInCashRegister.json");
    json j = json::parse(ifs);
    return std::move(j);
}

void CashRegister::updateCurrenciesAmountsFromFile()
{
    _cashRegistersForCurrencies = readCurrenciesAmountsFromJSONFile();
}

void CashRegister::writeCurrenciesAmountsToJSONFile() const
{
    json j = _cashRegistersForCurrencies;
    std::ofstream o("currenciesInCashRegister.json");
    o << std::setw(4) << j << std::endl;
}
