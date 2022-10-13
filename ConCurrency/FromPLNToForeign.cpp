#include "FromPLNToForeign.hpp"
#include <utility>

std::pair<int, double> FromPLNToForeign::currencyExchange(int amount, std::string currencyCode)
{
    double currencyRate = 0.0;

    if (currencyCode == "PLNHUF" || currencyCode == "PLNJPY")
    {
        currencyRate = (database.getMapOfCurrencies().at(currencyCode)) / 100.0;
    }
    else
    {
        currencyRate = database.getMapOfCurrencies().at(currencyCode);
    }

    int foreignAmount = static_cast<int>(amount / currencyRate);
    double PLNamount = amount - (foreignAmount * currencyRate);
    double roundedPLNamount = (round(PLNamount * 100)) / 100;

    return std::make_pair(foreignAmount, roundedPLNamount);
}