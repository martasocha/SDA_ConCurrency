#pragma once
#include <string>
#include <vector>
#include "DataBase.hpp"
#include "Currency.hpp"

class DataToDisplay
{
private:
	DataBase _dataBase;
	std::vector<Currency> _vectorOfCurrencies;
	std::vector <std::string> _currencyNames = { "dolar amerykański", "dolar australijski", "dolar kanadyjski", "euro", "forint (Węgry)", "frank szwajcarski", "funt szterling", "jen (Japonia)", "korona czeska", "korona duńska", "korona norweska", "korona szwedzka", "SDR (MFW)" };
	std::vector <std::string> _currencyID = { "USD", "AUD", "CAD", "EUR", "HUF", "CHF", "GBP", "JPY", "CZK", "DKK", "NOK", "SEK", "XDR" };
public:
	DataToDisplay();
	void setVectorOfCurrencies(std::vector<Currency> vectorOfCurrencies);
	std::vector<Currency> getVectorOfCurrencies();
};
