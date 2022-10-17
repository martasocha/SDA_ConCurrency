#pragma once
#include "ExchangeCurrency.hpp"
#include <utility>

class FromForeignToPLN : public ExchangeCurrency
{
public:
	FromForeignToPLN(std::shared_ptr<CashRegister> cashRegister);
	std::pair<int, double> currencyExchange(int amount, std::string currencyCode) override;
}; 