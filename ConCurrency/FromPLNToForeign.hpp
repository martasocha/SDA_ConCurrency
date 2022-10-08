#pragma once
#include "EchangeCurrency.hpp"

class FromPLNToForeign : public ExchangeCurrency
{
public:
	std::tuple <int, double> currencyExchange(int amount) override;
};