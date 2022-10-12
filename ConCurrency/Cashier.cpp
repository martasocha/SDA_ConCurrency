#include "Cashier.hpp"

Cashier::Cashier(std::shared_ptr<ExchangeCurrency> exchange, CashRegister cashRegister)
	: _exchange(exchange), _cashregister(cashRegister)
{
}

std::tuple <int, double> Cashier::exchangeCurrencyforCashier(int amount, std::string CurrencyCode)
{
	std::tuple <int, double> exchangedMoney = _exchange->currencyExchange(amount, CurrencyCode);
	return exchangedMoney;
}

void Cashier::displayCashReport()
{
}

void Cashier::displayOpeningBalance()
{
}
