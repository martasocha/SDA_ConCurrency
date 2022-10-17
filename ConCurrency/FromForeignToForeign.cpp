#include "FromForeignToForeign.hpp"
#include"FromForeignToPLN.hpp"
#include"FromPLNToForeign.hpp"
#include <memory>
#include <utility>


FromForeignToForeign::FromForeignToForeign(std::shared_ptr<CashRegister> cashRegister)
	: ExchangeCurrency(cashRegister)
{
}

std::pair<int, double> FromForeignToForeign::currencyExchange(int amount, std::string currencyCode)
{
	FromForeignToPLN obj1(_cashRegister);
	FromPLNToForeign obj2(_cashRegister);

	std::string currencyCodeToPLN = currencyCode.substr(0, 3) + "PLN";
	std::string currencyCodeFromPLN = "PLN" + currencyCode.substr(3, 3);

	auto changeForeignToPLN = obj1.currencyExchange(amount, currencyCodeToPLN);
	auto changePLNtoForeign = obj2.currencyExchange(changeForeignToPLN.second, currencyCodeFromPLN);

	return changePLNtoForeign;
}