#include "ExchangeCurrency.hpp"

ExchangeCurrency::ExchangeCurrency(std::shared_ptr<CashRegister> cashRegister)
    : _cashRegister(cashRegister)
{
}

bool ExchangeCurrency::checkCurrencyAvailability(std::pair<int, double> exchangedMoney, std::string currencyCode)
{
    std::string currencyCode1 = currencyCode.substr(0, 3);
    std::string currencyCode2 = currencyCode.substr(3, 3);

    double cashRegisterForCurrency1 = _cashRegister->getCashRegistersForCurrencies().at(currencyCode1);
    double cashRegisterForCurrency2 = _cashRegister->getCashRegistersForCurrencies().at(currencyCode2);

    return ((static_cast<double>(exchangedMoney.first) <= cashRegisterForCurrency2) && (exchangedMoney.second <= cashRegisterForCurrency1));
}

void ExchangeCurrency::updateCurrenciesAmounts(int amount, std::pair<int, double> exchangedMoney, std::string currencyCode)
{
    std::string currencycode1 = currencyCode.substr(0, 3);
    std::string currencycode2 = currencyCode.substr(3, 3);

    std::map<std::string, double> cashregisterscopy = _cashRegister->getCashRegistersForCurrencies();
    for (auto& element : cashregisterscopy)
    {
        if (element.first == currencycode1)
        {
            element.second += static_cast<double>(amount);
            if (currencycode1 == "PLN")
            {
                element.second -= exchangedMoney.second;
            }
        }
        else if (element.first == currencycode2)
        {
            if (currencycode1 == "PLN")
            {
                element.second -= static_cast<double>(exchangedMoney.first);
            }
            else
            {
                element.second -= exchangedMoney.second;
            }
        }
    }
    _cashRegister->setCashRegistersForCurrencies(cashregisterscopy);
}
