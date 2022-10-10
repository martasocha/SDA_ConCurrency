#include "FromPLNToForeign.hpp"

std::tuple<int, double> FromPLNToForeign::currencyExchange(int amount, std::string currencyCode)
{
    int ForeginAmount = amount / database.getMapOfCurrencies().at(currencyCode);
    double PLNamount = amount - (ForeginAmount * database.getMapOfCurrencies().at(currencyCode));
    double roundedPLNamount = (static_cast<int>(PLNamount * 100)) / 100;

    return std::make_tuple(ForeginAmount, roundedPLNamount);
}
