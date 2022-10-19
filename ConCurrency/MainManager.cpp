#include "MainManager.hpp"

MainManager::MainManager()
{
    _cashier.setCashRegister(_cashRegister);
    setMenuOptions();
}

void MainManager::displayCurrencyCodes() const
{
    std::cout << "Dostępne waluty: ";

    for (const auto& code : _cashRegister->getCashRegistersForCurrencies())
    {
        if (code.first != "PLN")
        {
            std::cout << code.first << " ";
        }
    }

    std::cout << std::endl;
}

void MainManager::setMenuOptions()
{
    _menuOptions.push_back("1 - Tabela kursów walut");
    _menuOptions.push_back("2 - Wyświetlenie stanu kas");
    _menuOptions.push_back("3 - Kup obcą walutę");
    _menuOptions.push_back("4 - Sprzedaj obcą walutę");
    _menuOptions.push_back("5 - Wymień obcą walutę na inną obcą walutę");
    _menuOptions.push_back("6 - Wyjdź z programu");
}


void MainManager::chooseFromMenu()
{
    std::cout << "Wybierz jedną z dostępnych opcji:" << std::endl;

    for (auto const& option : _menuOptions)
    {
        std::cout << option << std::endl;
    }

    std::cout << "Twój wybór: ";
    std::cin >> _usersMenuChoice;
}

void MainManager::takeAmountOfMoneyFromUser()
{
    std::cout << "Podaj kwote do wymiany: ";
    std::cin >> _amountOfMoney;
}

void MainManager::takeCurrencyToSellCodeFromUser()
{
    std::cout << "Podaj kod waluty, ktora chcesz sprzedac: ";
    std::cin >> _currencyCode;
}

void MainManager::takeCurrencyToBuyCodeFromUser()
{
    std::cout << "Podaj kod waluty, ktora chcesz kupic: ";
    std::cin >> _currencyCode;
}


void MainManager::mainFunction()
{
    std::cout << "Witaj w aplikacji ConCurrency!" << std::endl;

    _cashier.updateCurrencyRatesInDataBase();

    chooseFromMenu();

    switch (_usersMenuChoice)
    {
    case 1:
        std::cout << _menuOptions.at(0) << std::endl;

        _cashier.displayCurrencyRateTable();

        return;
        break;

    case 2:
        std::cout << _menuOptions.at(1) << std::endl;

        _cashier.displayUpdatedCashRegisterBalance();

        return;
        break;

    case 3:
        std::cout << _menuOptions.at(2) << std::endl;

        takeAmountOfMoneyFromUser();

        displayCurrencyCodes();

        takeCurrencyToBuyCodeFromUser();

        _concatenatedCurrencyCodes = "PLN" + _currencyCode;

        _cantor = std::make_shared<FromPLNToForeign>(_cashRegister);
        break;

    case 4:
        std::cout << _menuOptions.at(3) << std::endl;

        takeAmountOfMoneyFromUser();

        displayCurrencyCodes();

        takeCurrencyToSellCodeFromUser();

        _concatenatedCurrencyCodes = _currencyCode + "PLN";

        _cantor = std::make_shared<FromForeignToPLN>(_cashRegister);
        break;

    case 5:
        std::cout << _menuOptions.at(4) << std::endl;

        takeAmountOfMoneyFromUser();

        displayCurrencyCodes();

        takeCurrencyToSellCodeFromUser();

        _concatenatedCurrencyCodes = _currencyCode;

        takeCurrencyToBuyCodeFromUser();

        _concatenatedCurrencyCodes += _currencyCode;

        _cantor = std::make_shared<FromForeignToForeign>(_cashRegister);

        break;
    case 6:
        std::cout << _menuOptions.at(5) << std::endl;

        return;
        break;

    default:
        std::cout << "Taka opcja nie jest dostępna." << std::endl;
        return;
        break;
    }

    _cashier.setExchange(_cantor);
    auto exchangedMoneyAndChange = _cashier.exchangeCurrencyforCashier(_amountOfMoney, _concatenatedCurrencyCodes);
    std::cout << "Kwota w obcej walucie: " << std::get<0>(exchangedMoneyAndChange) << " " << _currencyCode << std::endl;
    std::cout << "Kwota w PLN: " << std::get<1>(exchangedMoneyAndChange) << std::endl;


}

