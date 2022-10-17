#include "pch.h"
#include"..\ConCurrency\FromForeignToPLN.hpp"
#include"..\ConCurrency\DataBase.hpp"
#include"..\ConCurrency\ExchangeCurrency.hpp"
#include"..\ConCurrency\Cashier.hpp"
#include"..\ConCurrency\CashRegister.hpp"

class TestFromForeignToPLN : public ::testing::Test
{
protected:

	TestFromForeignToPLN() :cashRegister(CashRegister(cashRegistersForCurrencies)),
		cashier(Cashier(std::make_shared<FromForeignToPLN>(), cashRegister))

	{}
	std::map<std::string, double> cashRegistersForCurrencies{ {"PLN",1000.0}, {"USD",5000.0}, {"AUD",5000.0}, {"CAD",5000.0},
															 {"EUR",1000.0}, {"HUF",500000.0}, {"CHF",5000.0},{"GBP",5000.0},
															 {"JPY",500000.0}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0},
															 {"SEK",5000.0}, {"XDR",5000.0} };
	CashRegister cashRegister;
	Cashier cashier;
};
TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test2USD)
{
	auto result = cashier.exchangeCurrencyforCashier(2, "USDPLN");
	EXPECT_EQ(9.93, result.second);
}

TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test2000CHF)
{
	auto result = cashier.exchangeCurrencyforCashier(2000, "CHFPLN");
	EXPECT_EQ(9947.6, result.second);
}


TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test1000JPY)
{
	auto result = cashier.exchangeCurrencyforCashier(1000, "JPYPLN");
	EXPECT_EQ(34.07, result.second);
}

TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test100HUF)
{
	auto result = cashier.exchangeCurrencyforCashier(100, "HUFPLN");
	EXPECT_EQ(1.14, result.second);
}

TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test1XDR)
{
	auto result = cashier.exchangeCurrencyforCashier(1, "XDRPLN");
	EXPECT_EQ(6.31, result.second);
}
TEST_F(TestFromForeignToPLN, exchange_FromForeignToPLN_returnPLN_test0CAD)
{
	auto result = cashier.exchangeCurrencyforCashier(0, "CADPLN");
	EXPECT_EQ(0, result.second);
}
