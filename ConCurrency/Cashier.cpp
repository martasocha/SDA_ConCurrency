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
		std::cout << std::setw(25) << _data.getVectorOfCurrencies().at(i)._name << std::setw(25) << _data.getVectorOfCurrencies().at(i)._currencyCode << std::setw(15) << _data.getVectorOfCurrencies().at(i)._currencyRateBuy << std::setw(15) << _data.getVectorOfCurrencies().at(i)._currencyRateSell << std::endl;
		std::cout << std::endl;

	}

	////FIRST APPROACH
	////USD
	//auto mapa = _dataBase.getMapOfCurrencies();
	//double tempPLNUSD;
	//double tempUSDPLN;

	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "USD")
	//	{
	//		tempPLNUSD = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "USD" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempUSDPLN = i.second;
	//	}
	//}
	////AUD
	//double tempPLNAUD, tempAUDPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "AUD")
	//	{
	//		tempPLNAUD = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "AUD" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempAUDPLN = i.second;
	//	}
	//}
	////CAD
	//double tempPLNCAD, tempCADPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "CAD")
	//	{
	//		tempPLNCAD = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "CAD" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempCADPLN = i.second;
	//	}
	//}
	////EUR
	//double tempPLNEUR, tempEURPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "EUR")
	//	{
	//		tempPLNEUR = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "EUR" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempEURPLN = i.second;
	//	}
	//}
	////HUF
	//double tempPLNHUF, tempHUFPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "EUR")
	//	{
	//		tempPLNHUF = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "EUR" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempHUFPLN = i.second;
	//	}
	//}
	////CHF
	//double tempPLNCHF, tempCHFPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "CHF")
	//	{
	//		tempPLNCHF = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "CHF" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempCHFPLN = i.second;
	//	}
	//}
	////GBP
	//double tempPLNGBP, tempGBPPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "GBP")
	//	{
	//		tempPLNGBP = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "GBP" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempGBPPLN = i.second;
	//	}
	//}
	////JPY
	//double tempPLNJPY, tempJPYPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "JPY")
	//	{
	//		tempPLNJPY = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "JPY" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempJPYPLN = i.second;
	//	}
	//}
	////CZK
	//double tempPLNCZK, tempCZKPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "CZK")
	//	{
	//		tempPLNCZK = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "CZK" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempCZKPLN = i.second;
	//	}
	//}
	////DKK
	//double tempPLNDKK, tempDKKPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "DKK")
	//	{
	//		tempPLNDKK = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "DKK" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempDKKPLN = i.second;
	//	}
	//}
	////NOK
	//double tempPLNNOK, tempNOKPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "NOK")
	//	{
	//		tempPLNNOK = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "NOK" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempNOKPLN = i.second;
	//	}
	//}
	////SEK
	//double tempPLNSEK, tempSEKPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "SEK")
	//	{
	//		tempPLNSEK = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "SEK" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempSEKPLN = i.second;
	//	}
	//}
	////XDR
	//double tempPLNXDR, tempXDRPLN;
	//for (auto& const i : mapa)
	//{
	//	if (i.first.substr(0, 3) == "PLN" && i.first.substr(3, 3) == "XDR")
	//	{
	//		tempPLNXDR = i.second;
	//	}
	//	else if (i.first.substr(0, 3) == "XDR" && i.first.substr(3, 3) == "PLN")
	//	{
	//		tempXDRPLN = i.second;
	//	}
	//}

	//std::cout << std::endl;
	//std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	//std::cout << std::setw(40) << "CURRENCY" << std::setw(5) << "RATE" << std::setw(35) << std::endl;
	//std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "Nazwa waluty" << std::setw(25) << "Kod Waluty" << std::setw(20) << "Kurs:" << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(65) << "Kupna" << std::setw(15) << "Sprzedaży" << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "---------------------------------------------------------------------------------" << std::endl;
	//std::cout << std::endl;

	//std::cout << std::setw(25) << "dolar amerykanski" << std::setw(25) << "1 USD" << std::setw(15) << tempUSDPLN << std::setw(15) << tempPLNUSD << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "dolar australijski" << std::setw(25) << "1 AUD" << std::setw(15) << tempAUDPLN << std::setw(15) << tempPLNAUD << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "dolar kanadyjski" << std::setw(25) << "1 CAD" << std::setw(15) << tempCADPLN << std::setw(15) << tempPLNCAD << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "euro" << std::setw(25) << "1 EUR" << std::setw(15) << tempEURPLN << std::setw(15) << tempPLNEUR << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "forint (Wegry)" << std::setw(25) << "100 HUF" << std::setw(15) << tempHUFPLN << std::setw(15) << tempPLNHUF << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "frank szwajcarski" << std::setw(25) << "1 CHF" << std::setw(15) << tempCHFPLN << std::setw(15) << tempPLNCHF << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "funt szterling" << std::setw(25) << "1 GBP" << std::setw(15) << tempGBPPLN << std::setw(15) << tempPLNGBP << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "jen (Japonia)" << std::setw(25) << "100 JPY" << std::setw(15) << tempJPYPLN << std::setw(15) << tempPLNJPY << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "korona czeska" << std::setw(25) << "1 CZK" << std::setw(15) << tempCZKPLN << std::setw(15) << tempPLNCZK << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "korona dunska" << std::setw(25) << "1 DKK" << std::setw(15) << tempDKKPLN << std::setw(15) << tempPLNDKK << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "korona norweska" << std::setw(25) << "1 NOK" << std::setw(15) << tempNOKPLN << std::setw(15) << tempPLNNOK << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "korona szwedzka" << std::setw(25) << "1 SEK" << std::setw(15) << tempSEKPLN << std::setw(15) << tempPLNSEK << std::endl;
	//std::cout << std::endl;
	//std::cout << std::setw(25) << "SDR (MFW)" << std::setw(25) << "1 XDR" << std::setw(15) << tempXDRPLN << std::setw(15) << tempPLNXDR << std::endl;
	//std::cout << std::endl;
}

//void Cashier::displayCashReport()
//{
//}


