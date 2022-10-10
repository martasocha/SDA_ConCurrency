#pragma once
#include <tuple>
#include <string>

class ExchangeCurrency
{
private:
public:
	virtual ~ExchangeCurrency() = default;
	virtual std::tuple <int, double> currencyExchange(int amount, std::string currencyCode) = 0;
};