#pragma once
#include "ExchangeCurrency.hpp"
#include <map>
#include "DataBase.hpp"

class FromPLNToForeign : public ExchangeCurrency
{
private:
	DataBase database;
public:
	std::tuple <int, double> currencyExchange(int amount, std::string currencyCode) override;
};
