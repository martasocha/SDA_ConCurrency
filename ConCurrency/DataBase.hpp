#pragma once
#include "JSONReader.hpp"
#include <map>
#include <string>
#include <fstream>


class DataBase
{
private:
	std::map<std::string, double> _mapOfCurrencies = { {"PLNUSD",5.0662}, {"USDPLN",4.9658}, {"PLNAUD",3.1778}, {"AUDPLN",3.1148}, {"PLNCAD",3.6671}, {"CADPLN",3.5945},
		{"PLNEUR",4.9152}, {"EURPLN",4.8178}, {"PLNHUF",1.213}, {"HUFPLN",1.1439}, {"PLNCHF",5.0742}, {"CHFPLN",4.9738},
		{"PLNGBP",5.6042}, {"GBPPLN",5.4932}, {"PLNJPY",3.4758}, {"JPYPLN",3.4070}, {"PLNCZK",0.2004}, {"CZKPLN",0.1964},
		{"PLNDKK",0.6607}, {"DKKPLN",0.6477}, {"PLNNOK",0.4701}, {"NOKPLN", 0.4607}, {"PLNSEK",0.4460}, {"SEKPLN",0.4372},
		{"PLNXDR",6.4344}, {"XDRPLN",6.3070} };

	JSONReader _jSONReader;

public:
	std::map<std::string, double> getMapOfCurrencies();
	void updateCurrenciesAmountsFromFile();
};