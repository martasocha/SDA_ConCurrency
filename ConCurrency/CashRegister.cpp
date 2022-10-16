#include "CashRegister.hpp"

CashRegister::CashRegister(std::map<std::string, double> cashRegistersForCurrencies)
	: _cashRegistersForCurrencies(cashRegistersForCurrencies)
{
}

std::map<std::string, double> CashRegister::getCashRegistersForCurrencies() const
{
	return _cashRegistersForCurrencies;
}
