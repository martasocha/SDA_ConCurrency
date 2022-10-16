#include "ExchangeCurrency.hpp"
#include "FromPLNToForeign.hpp"
#include "FromForeignToPLN.hpp"
#include "FromForeignToForeign.hpp"
#include "Cashier.hpp"
#include "CashRegister.hpp"
#include <iostream>
#include <tuple>
#include <map>

int main()
{
    uint32_t amountOfMoney = 0;
    uint16_t userInput = 0;
    std::string currencyCode = {};
    std::string concatenatedCurrencyCodes = {};
    std::shared_ptr<ExchangeCurrency> cantor = nullptr;
    
    std::map<std::string, double> cashRegistersForCurrencies{
    {"PLN",10000.0}, {"USD",5000.0}, {"AUD",5000.0}, {"CAD",5000.0}, {"EUR",5000.0}, {"HUF",500000.0}, {"CHF",5000.0},
    {"GBP",5000.0}, {"JPY",500000.0}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0}, {"SEK",5000.0}, {"XDR",5000.0}
    };

    CashRegister cashRegister(cashRegistersForCurrencies);

    std::cout
        << "Witaj w aplikacji ConCurrency!" << std::endl
        << "Wybierz jedną z dostępnych opcji:" << std::endl
        << "1 - Wyświetl tabelę kursów walut" << std::endl
        << "2 - Wymień złotówki na obcą walutę" << std::endl
        << "3 - Wymień obcą walutę na złotówki" << std::endl
        << "4 - Wymień obcą walutę na inną obcą walutę" << std::endl
        << "Twój wybór: ";
    std::cin >> userInput;

    switch (userInput)
    {
    case 1:
        std::cout << "Tabelę kursów walut ( do zaktualizowania :D )" << std::endl;
        return -1;
        break;
    case 2:
        std::cout << "Wybrałes/aś opcję: Wymień złotówki na obcą walutę." << std::endl;

        std::cout << "Podaj kwotę do wymiany: ";
        std::cin >> amountOfMoney;
        std::cout << "Podaj kod waluty na którą chcesz wymienić złotówki: ";
        std::cin >> currencyCode;
        concatenatedCurrencyCodes = "PLN" + currencyCode;

        cantor = std::make_shared<FromPLNToForeign>();

        break;
    case 3:
        std::cout << "Wybrałes/aś opcję: Wymień obcą walutę na złotówki." << std::endl;
        std::cout << "Podaj kwotę do wymiany: ";
        std::cin >> amountOfMoney;
        std::cout << "Podaj kod waluty na którą chcesz wymienić złotówki: ";
        std::cin >> currencyCode;
        concatenatedCurrencyCodes = currencyCode + "PLN";

        cantor = std::make_shared<FromForeignToPLN>();

        break;
    case 4:
        std::cout << "Wybrałes/aś opcję: Wymień obcą walutę na inną obcą walutę." << std::endl;

        std::cout << "Podaj kwote do wymiany: ";
        std::cin >> amountOfMoney;
        std::cout << "Podaj kod waluty  ktora chcesz sprzedac: ";
        std::cin >> currencyCode;
        concatenatedCurrencyCodes = currencyCode;
        std::cout << "Podaj kod waluty ktora chcesz kupic: ";
        std::cin >> currencyCode;
        concatenatedCurrencyCodes += currencyCode;

        cantor = std::make_shared<FromForeignToForeign>();

        break;
    default:
        std::cout << "Taka opcja nie jest dostępna." << std::endl;
        return -1;
        break;
    }

    Cashier cashier(cantor, cashRegister);
    auto exchangedMoneyAndChange = cashier.exchangeCurrencyforCashier(amountOfMoney, concatenatedCurrencyCodes);
    std::cout << "Kwota w obcej walucie: " << std::get<0>(exchangedMoneyAndChange) << " " << currencyCode << std::endl;
    std::cout << "Kwota w PLN: " << std::get<1>(exchangedMoneyAndChange) << std::endl;

    std::cout << "Dziękujemy za skorzystanie z naszej aplikacji i życzymy miłego dnia :)" << std::endl;

    std::cout << std::endl;
    cashier.displayOpeningBalance();
    std::cout << std::endl;
    cashier.displayCurrencyRateTable();

}
