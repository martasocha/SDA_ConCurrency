#include "FromForeignToPLN.hpp"

std::tuple<int, double> FromForeignToPLN::currencyExchange(int amount, std::string currencyCode)
{
    double currencyRate = 0.0;

    if (currencyCode == "HUFPLN" || currencyCode == "JPYPLN")
    {
        currencyRate = (database.getMapOfCurrencies().at(currencyCode)) / 100.0;
    }
    else
    {
        currencyRate = database.getMapOfCurrencies().at(currencyCode);
    }

    double PLNamount = amount * currencyRate;
    double roundedPLNamount = (round(PLNamount * 100)) / 100;

    return std::make_tuple(0, roundedPLNamount);
}