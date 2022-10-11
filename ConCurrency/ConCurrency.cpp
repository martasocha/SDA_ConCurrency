#include "ExchangeCurrency.hpp"
#include "FromPLNToForeign.hpp"
#include "FromForeignToPLN.hpp"
#include <iostream>
#include <tuple>

int main()
{
    uint32_t amountOfMoney = 0;
    uint16_t userInput = 0;
    std::string currencyCode = {};
    std::shared_ptr<ExchangeCurrency> cantor = nullptr;

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
        std::cout << "Wybrałes/aś opcję: Wymień złotówki na obcą walutę" << std::endl;

        std::cout << "Podaj kwotę do wymiany: ";
        std::cin >> amountOfMoney;
        std::cout << "Podaj kod waluty na którą chcesz wymienić złotówki: ";
        std::cin >> currencyCode;

        cantor = std::make_shared<FromPLNToForeign>();

        break;
    case 3:
        std::cout << "Wybrałes/aś opcję: Wymień obcą walutę na złotówki. Jest przygotowywana :)" << std::endl;
        return -1;
        //ustawic wskaznik
        break;
    case 4:
        std::cout << "Wybrałes/aś opcję: Wymień obcą walutę na inną obcą walutę. Jest przygotowywana :)" << std::endl;
        return -1;
        //ustawic wskaznik
        break;
    default:
        std::cout << "Ta opcja nie jest dostępna." << std::endl;
        return -1;
    }

    auto exchangedMoneyAndChange = cantor->currencyExchange(amountOfMoney, currencyCode);
    std::cout << "Do wydania obcej waluty: " << std::get<0>(exchangedMoneyAndChange) << std::endl;
    std::cout << "Reszta w PLN: " << std::get<1>(exchangedMoneyAndChange) << std::endl;

    std::cout << "Dziękujemy za skorzystanie z naszej aplikacji i życzymy miłego dnia :)" << std::endl;




}
