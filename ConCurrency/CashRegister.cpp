#include "CashRegister.hpp"

CashRegister::CashRegister(std::map<std::string, double> cashRegistersForCurrencies)
	: _cashRegistersForCurrencies(cashRegistersForCurrencies)
{
}
