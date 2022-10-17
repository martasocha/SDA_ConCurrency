#pragma once
#include "DataBase.hpp"
#include <utility>
#include <string>
#include "CashRegister.hpp"

class ExchangeCurrency
{
protected:
	DataBase _database;
	std::shared_ptr<CashRegister> _cashRegister;
public:
	ExchangeCurrency(std::shared_ptr<CashRegister> cashRegister);

	virtual ~ExchangeCurrency() = default;
	virtual std::pair<int, double> currencyExchange(int amount, std::string currencyCode) = 0;

	bool checkCurrencyAvailability(std::pair<int, double> exchangedMoney, std::string currencyCode);
	void updateCurrenciesAmounts(int amount, std::pair<int, double> exchangedMoney, std::string currencyCode);
};