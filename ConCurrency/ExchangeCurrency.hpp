#pragma once
#include <tuple>

class ExchangeCurrency
{
private:
public:
	virtual ~ExchangeCurrency() = default;
	virtual std::tuple <int, double> currencyExchange(int amount) = 0;
};