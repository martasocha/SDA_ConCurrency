#pragma once
#include "ExchangeCurrency.hpp"

class FromForeignToPLN : public ExchangeCurrency
{
public:
	std::tuple <int, double> currencyExchange(int amount, std::string currencyCode) override;
}; 