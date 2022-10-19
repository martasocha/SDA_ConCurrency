#include "FromForeignToPLN.hpp"
#include <utility>
#include <iostream>

FromForeignToPLN::FromForeignToPLN(std::shared_ptr<CashRegister> cashRegister)
    : ExchangeCurrency(cashRegister)
{
}

std::pair<double, double> FromForeignToPLN::currencyExchange(double amount, std::string currencyCode)
{
    FromForeignToPLN toPLN(_cashRegister);
    auto changedMoney = toPLN.changeForeignToPLN(amount, currencyCode);

    if (checkCurrencyAvailability(changedMoney, currencyCode))
    {
        updateCurrenciesAmounts(amount, changedMoney, currencyCode);
        return changedMoney;
    }
    else
    {
        throw std::out_of_range("Nie udało się przeprowadzić transakcji, brak potrzebnej ilości waluty w kasach.");
    }
}

std::pair<double, double> FromForeignToPLN::changeForeignToPLN(double amount, std::string currencyCode)
{
    double currencyRate = 0.0;

    if (currencyCode == "HUFPLN" || currencyCode == "JPYPLN")
    {
        currencyRate = (_database.getMapOfCurrencies().at(currencyCode)) / 100.0;

    }
    else
    {
        currencyRate = _database.getMapOfCurrencies().at(currencyCode);
    }

    double PLNamount = amount * currencyRate;
    double roundedPLNamount = (round(PLNamount * 100)) / 100;

    return std::make_pair(0, roundedPLNamount);
}
