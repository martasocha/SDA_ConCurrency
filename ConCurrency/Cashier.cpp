#include "Cashier.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

Cashier::Cashier()
{
	DataToDisplay data;
	this->_data = data;
}

Cashier::Cashier(std::shared_ptr<ExchangeCurrency> exchange, std::shared_ptr<CashRegister> cashRegister)
	: _exchange(exchange), _cashregister(cashRegister)
{
}

void Cashier::setExchange(std::shared_ptr<ExchangeCurrency> exchange)
{
	_exchange = exchange;
}

void Cashier::setCashRegister(std::shared_ptr<CashRegister> cashregister)
{
	_cashregister = cashregister;
}

std::pair <double, double> Cashier::exchangeCurrencyforCashier(int amount, std::string CurrencyCode)
{
	_cashregister->updateCurrenciesAmountsFromFile();

	std::pair <double, double> exchangedMoney = _exchange->currencyExchange(amount, CurrencyCode);

	_cashregister->writeCurrenciesAmountsToJSONFile();

	return exchangedMoney;
}

void Cashier::displayUpdatedCashRegisterBalance()
{

	std::cout << std::endl;
	std::cout << std::setw(70) << "--------------------------------------------------------" << std::setw(10) << std::endl;
	std::cout << std::setw(15) << "|" << std::setw(25) << "OPENING" << std::setw(10) << "BALANCE" << std::setw(20) << "|" << std::endl;
	std::cout << std::setw(70) << "--------------------------------------------------------" << std::setw(10) << std::endl;
	std::cout << std::setw(15) << "|" << std::setw(15) << "Kwota" << std::setw(15) << "|" << std::setw(15) << "Waluta" << std::setw(10) << "|" << std::endl;
	std::cout << std::endl;

	auto map = _cashregister->getCashRegistersForCurrencies();
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		std::cout << std::setw(70) << "--------------------------------------------------------" << std::setw(10) << std::endl;
		std::cout << std::setw(15) << "|" << std::setw(15) <<it->second << std::setw(15) << "|" << std::setw(15) << it->first << std::setw(10) << "|" << std::endl;
		std::cout << std::setw(70) << "--------------------------------------------------------" << std::setw(10) << std::endl;
	}
}

void Cashier::displayCurrencyRateTable()
{
	//SECOND APPROACH USING EXTRA CLASSES
	std::cout << std::endl;
	std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	std::cout << std::setw(40) << "CURRENCY" << std::setw(5) << "RATE" << std::setw(35) << std::endl;
	std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(25) << "Nazwa waluty" << std::setw(25) << "Kod Waluty" << std::setw(20) << "Kurs:" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(65) << "Kupna" << std::setw(15) << "Sprzedaży" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	const int size = _data.getVectorOfCurrencies().size();

	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(25) << std::setprecision(4) << _data.getVectorOfCurrencies().at(i)._name << std::setw(25) << _data.getVectorOfCurrencies().at(i)._currencyCode << std::setw(15) << _data.getVectorOfCurrencies().at(i)._currencyRateBuy << std::setw(15) << _data.getVectorOfCurrencies().at(i)._currencyRateSell << std::endl;
		std::cout << std::endl;

	}
}

void Cashier::updateCurrencyRatesInDataBase()
{
	_dataBase.updateCurrenciesAmountsFromFile();
}

//void Cashier::displayCashReport()
//{
//}


