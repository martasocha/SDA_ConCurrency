#include "pch.h"
#include"..\ConCurrency\FromForeignToPLN.hpp"
#include"..\ConCurrency\FromForeignToForeign.hpp"
#include"..\ConCurrency\DataBase.hpp"
#include"..\ConCurrency\ExchangeCurrency.hpp"
#include"..\ConCurrency\FromPLNToForeign.hpp"
#include"..\ConCurrency\Cashier.hpp"
#include"..\ConCurrency\CashRegister.hpp"

class TestCheckCurrencyAvailibility : public ::testing::Test
{
protected:

	TestCheckCurrencyAvailibility()
		:cashRegistersForCurrencies{ {"PLN",1000.0}, {"USD",180.0}, {"AUD",5000.0}, {"CAD",5000.0},{"EUR",202.99}, {"HUF",16487.99},
									 {"CHF",5000.0},{"GBP",5000.0}, {"JPY",1385.99}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0},
									 {"SEK",5000.0}, {"XDR",5000.0} },
		cashRegister(std::make_shared<CashRegister>(cashRegistersForCurrencies)),
		exchangeTest(cashRegister)
	{};

	std::map<std::string, double> cashRegistersForCurrencies;
	std::shared_ptr <CashRegister> cashRegister;
	FromForeignToForeign exchangeTest;
};

TEST_F(TestCheckCurrencyAvailibility, exchange_FromEURToPLN_checkIfLessThenPLNBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(500, "EURPLN"), std::out_of_range);
}

TEST_F(TestCheckCurrencyAvailibility, exchange_FromHUFToPLN_checkIfLessThenPLNBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(44000, "HUFPLN"), std::out_of_range);
}

TEST_F(TestCheckCurrencyAvailibility, exchange_FromPLNToEUR_checkIfLessThenEURBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(1000, "PLNEUR"), std::out_of_range);
}

TEST_F(TestCheckCurrencyAvailibility, exchange_FromPLNToHUF_checkIfLessThenEURBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(200, "PLNHUF"), std::out_of_range);
}

TEST_F(TestCheckCurrencyAvailibility, exchange_FromForeignToForeignEURUSD_checkIfLessThenEURBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(200, "EURUSD"), std::out_of_range);
}

TEST_F(TestCheckCurrencyAvailibility, exchange_FromForeignToForeignEURJPY_checkIfLessThenEURBalance)
{
	EXPECT_THROW(exchangeTest.currencyExchange(10, "EURJPY"), std::out_of_range);
}