#include "FromForeignToPLN.hpp"
#include <utility>
#include <iostream>

FromForeignToPLN::FromForeignToPLN(std::shared_ptr<CashRegister> cashRegister)
    : ExchangeCurrency(cashRegister)
{
}

std::pair<int, double> FromForeignToPLN::currencyExchange(int amount, std::string currencyCode)
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

    std::pair<int, double> changedMoney = std::make_pair(0, roundedPLNamount);

    if (checkCurrencyAvailability(changedMoney, currencyCode))
    {
        updateCurrenciesAmounts(amount, changedMoney, currencyCode);
        return changedMoney;
    }
    else
    {
        std::cout << "Nie uda³o siê przeprowadziæ transakcji, brak potrzebnej ilosci waluty w kasach" << std::endl;
        return std::make_pair(amount, 0);
    }
}