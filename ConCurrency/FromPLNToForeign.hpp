#pragma once
#include "ExchangeCurrency.hpp"
#include <utility>

class FromPLNToForeign : public ExchangeCurrency
{
public:
	FromPLNToForeign(std::shared_ptr<CashRegister> cashRegister);
	std::pair<int, double> currencyExchange(int amount, std::string currencyCode) override;
};
