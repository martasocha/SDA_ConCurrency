#pragma once
#include "ExchangeCurrency.hpp"
#include <utility>

class FromForeignToForeign : public ExchangeCurrency
{
public:
	FromForeignToForeign(std::shared_ptr<CashRegister> cashRegister);
	std::pair<int, double> currencyExchange(int amount, std::string currencyCode) override;
};