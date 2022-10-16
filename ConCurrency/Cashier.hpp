#pragma once
#include <memory>
#include "ExchangeCurrency.hpp"
#include "CashRegister.hpp"

class Cashier
{
private:
	std::shared_ptr<ExchangeCurrency> _exchange;
	CashRegister _cashregister;
	DataBase dataBase;
public:
	Cashier(std::shared_ptr<ExchangeCurrency> exchange, CashRegister cashRegister);

	std::tuple <int, double> exchangeCurrencyforCashier(int amount, std::string CurrencyCode);

	void displayOpeningBalance();
	void displayCurrencyRateTable();
	//void displayCashReport();

};