#include "FromPLNToForeign.hpp"
#include <utility>
#include <iostream>

FromPLNToForeign::FromPLNToForeign(std::shared_ptr<CashRegister> cashRegister)
    : ExchangeCurrency(cashRegister)
{
}

std::pair<double, double> FromPLNToForeign::currencyExchange(double amount, std::string currencyCode)
{
    FromPLNToForeign fromPLN(_cashRegister);
    auto changedMoney = fromPLN.changePLNtoForeign(amount, currencyCode);

    if (checkCurrencyAvailability(changedMoney, currencyCode))
    {
        updateCurrenciesAmounts(amount, changedMoney, currencyCode);
        return changedMoney;
    }
    else
    {
        //tutaj bedzie wyjatek
    }
}

std::pair<double, double> FromPLNToForeign::changePLNtoForeign(double amount, std::string currencyCode)
{
    double currencyRate = 0.0;

    if (currencyCode == "PLNHUF" || currencyCode == "PLNJPY")
    {
        currencyRate = (_database.getMapOfCurrencies().at(currencyCode)) / 100.0;
    }
    else
    {
        currencyRate = _database.getMapOfCurrencies().at(currencyCode);
    }

    int foreignAmount = static_cast<int>(amount / currencyRate);
    double PLNamount = static_cast<double>(amount - (foreignAmount * currencyRate));
    double roundedPLNamount = (round(PLNamount * 100)) / 100;

    return std::make_pair(foreignAmount, roundedPLNamount);
}
