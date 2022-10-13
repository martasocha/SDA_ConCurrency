#pragma once
#include "DataBase.hpp"
#include <utility>
#include <string>

class ExchangeCurrency
{
protected:
	DataBase database;
	//prawdopodobnie do dodania CashRegister - w metodach fromForeignTo.... bedziemy najpierw sprawdzac czy jest dostepna taka ilosc gotowki
	//a pozniej ja odejmowa�
public:
	virtual ~ExchangeCurrency() = default;
	virtual std::pair<int, double> currencyExchange(int amount, std::string currencyCode) = 0;
};