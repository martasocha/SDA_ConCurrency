#pragma once
#include <map>
#include <string>
#include <vector>

class CashRegister
{
private:

	std::map<std::string, double> _cashRegistersForCurrencies{
	{"PLN",0.0}, {"USD",0.0}, {"AUD",0.0}, {"CAD",0.0}, {"EUR",0.0}, {"HUF",0.0}, {"CHF",0.0}, {"GBP",0.0},
	{"JPY",0.0}, {"CZK",0.0},	{"DKK",0.0}, {"NOK",0.0}, {"SEK",0.0}, {"XDR",0.0}
	};

	//ilosc pieniedzy w kasach walutowych

public:
	CashRegister(std::map<std::string, double> cashRegistersForCurrencies);
	std::map<std::string, double> getCashRegistersForCurrencies() const;

};