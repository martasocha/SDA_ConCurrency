#include "FromForeignToForeign.hpp"
#include"FromForeignToPLN.hpp"
#include"FromPLNToForeign.hpp"
#include <memory>
#include <utility>


FromForeignToForeign::FromForeignToForeign(std::shared_ptr<CashRegister> cashRegister)
	: ExchangeCurrency(cashRegister)
{
}

std::pair<double, double> FromForeignToForeign::currencyExchange(double amount, std::string currencyCode)
{
	FromForeignToPLN valuePLN(_cashRegister);
	FromPLNToForeign valueForeign(_cashRegister);

	std::string currencyCodeToPLN = currencyCode.substr(0, 3) + "PLN";
	std::string currencyCodeFromPLN = "PLN" + currencyCode.substr(3, 3);

	auto changeForeignToPLN = valuePLN.changeForeignToPLN(amount, currencyCodeToPLN);
	auto changePLNtoForeign = valueForeign.changePLNtoForeign(changeForeignToPLN.second, currencyCodeFromPLN);

	if (checkCurrencyAvailability(changePLNtoForeign, currencyCode))
	{
		updateCurrenciesAmounts(amount, changePLNtoForeign, currencyCode);
		return changePLNtoForeign;
	}
	else
	{
		throw std::out_of_range("Nie udało się przeprowadzić transakcji, brak potrzebnej ilości waluty w kasach.");
	}
	return changePLNtoForeign;
}