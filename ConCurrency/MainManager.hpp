#pragma once
#include "ExchangeCurrency.hpp"
#include "FromPLNToForeign.hpp"
#include "FromForeignToPLN.hpp"
#include "FromForeignToForeign.hpp"
#include "Cashier.hpp"
#include "CashRegister.hpp"
#include <iostream>
#include <vector>


class MainManager
{
	std::vector<std::string> _menuOptions = {};
	double _amountOfMoney = 0.0;
	uint16_t _usersMenuChoice = 0;
	std::string _currencyCode = {};
	std::string _concatenatedCurrencyCodes = {};
	std::shared_ptr<ExchangeCurrency> _cantor = nullptr;
	std::shared_ptr<CashRegister> _cashRegister = std::make_shared<CashRegister>();
	Cashier _cashier;

	void displayCurrencyCodes() const;
	void setMenuOptions();
	void chooseFromMenu();
	void takeAmountOfMoneyFromUser();
	void takeCurrencyToSellCodeFromUser();
	void takeCurrencyToBuyCodeFromUser();

	void exceptionHandlingForCurrencyCodes() const;
	void exceptionHandlingForAmountOfMoney() const;

public:
	MainManager();
	void mainFunction();

};