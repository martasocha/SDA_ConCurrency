#pragma once
#include "DataBase.hpp"
#include <tuple>
#include <string>

class ExchangeCurrency
{
protected:
	DataBase database;
	//prawdopodobnie do dodania CashRegister - w metodach fromForeignTo.... bedziemy najpierw sprawdzac czy jest dostepna taka ilosc gotowki
	//a pozniej ja odejmowaæ
public:
	virtual ~ExchangeCurrency() = default;
	virtual std::tuple <int, double> currencyExchange(int amount, std::string currencyCode) = 0;
};