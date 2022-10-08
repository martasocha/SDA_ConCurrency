#pragma once
#include "EchangeCurrency.hpp"

class FromForeignToPLN : public ExchangeCurrency
{
public:
	std::tuple <int, double> currencyExchange(int amount) override;
};