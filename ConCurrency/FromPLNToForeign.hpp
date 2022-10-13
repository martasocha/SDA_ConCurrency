#pragma once
#include "ExchangeCurrency.hpp"
#include <utility>

class FromPLNToForeign : public ExchangeCurrency
{
public:
	std::pair<int, double> currencyExchange(int amount, std::string currencyCode) override;
};
