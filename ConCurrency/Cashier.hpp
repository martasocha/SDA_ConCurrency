#pragma once
#include <memory>
#include "ExchangeCurrency.hpp"
#include "CashRegister.hpp"

class Cashier
{
private:
	std::shared_ptr<ExchangeCurrency> _exchange;
	std::shared_ptr<CashRegister> _cashregister;
	DataBase dataBase;
public:
	Cashier(std::shared_ptr<ExchangeCurrency> exchange, std::shared_ptr<CashRegister> cashRegister);

	std::pair <int, double> exchangeCurrencyforCashier(int amount, std::string CurrencyCode);

	void displayOpeningBalance();
	void displayCurrencyRateTable();
	//void displayCashReport();

};