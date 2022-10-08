#pragma once
#include "EchangeCurrency.hpp"

class FromForeignToForeign : public ExchangeCurrency
{
public:
	std::tuple <int, double> currencyExchange(int amount) override;
};
