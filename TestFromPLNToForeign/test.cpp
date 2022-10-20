#include "pch.h"
#include "../ConCurrency/ExchangeCurrency.hpp"
#include "../ConCurrency/FromPLNToForeign.hpp"
#include "../ConCurrency/DataBase.hpp"
#include "../ConCurrency/CashRegister.hpp"
#include "../ConCurrency/Cashier.hpp"
#include "../ConCurrency/DataToDisplay.hpp"
#include "../ConCurrency/JSONReader.hpp"
#include "../ConCurrency/JSONWriter.hpp"


//UPDATED TESTS

class TestFromPLNToForeign : public ::testing::Test
{
protected:

	TestFromPLNToForeign()
		:cashRegistersForCurrencies{ {"PLN",1000.0}, {"USD",5000.0}, {"AUD",5000.0}, {"CAD",5000.0},{"EUR",1000.0}, {"HUF",500000.0},
									 {"CHF",5000.0},{"GBP",5000.0}, {"JPY",500000.0}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0},
									 {"SEK",5000.0}, {"XDR",5000.0} },
		cashRegister(std::make_shared<CashRegister>(cashRegistersForCurrencies)),
		testedMethod(cashRegister)
	{};

	std::map<std::string, double> cashRegistersForCurrencies;
	std::shared_ptr <CashRegister> cashRegister;
	FromPLNToForeign testedMethod;
};

TEST_F(TestFromPLNToForeign, exchange_FromPLNtoEUR_returnChangeInPLN)
{
	auto result = testedMethod.currencyExchange(200, "PLNEUR");
	EXPECT_EQ(result.first, 40);
	EXPECT_EQ(result.second, 3.39);
}
TEST_F(TestFromPLNToForeign, exchange_FromPLNtoEUR_willNotExchange)
{
	auto result = testedMethod.currencyExchange(3, "PLNEUR");
	EXPECT_EQ(result.first, 0);
	EXPECT_EQ(result.second, 3);
}
TEST_F(TestFromPLNToForeign, exchange_FromPLNtoEUR_returnChangeInPLNPassedException)
{
	EXPECT_THROW(testedMethod.currencyExchange(10000, "PLNEUR"), std::out_of_range);
}
TEST_F(TestFromPLNToForeign, exchange_FromPLNtoEUR_return0)
{
	auto result = testedMethod.currencyExchange(0, "EURPLN");
	EXPECT_EQ(result.first, 0);
	EXPECT_EQ(result.second, 0);
}


//FIRST TESTS ON BASIC FUNCTIONALITY

//class TestFromPLNToEUR : public ::testing::Test
//{
//protected:
//	FromPLNToForeign exchange;
//	std::pair<int, double> result;
//};
//
//TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_returnNoChangeInPLN)
//{
//	result = exchange.currencyExchange(200, "EUR");
//	EXPECT_EQ(std::get<0>(result), 41);
//	EXPECT_EQ(std::get<1>(result), 0.08);
//}
//
//TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_willNotExchange)
//{
//	result = exchange.currencyExchange(3, "EUR");
//	EXPECT_EQ(std::get<0>(result), 0);
//	EXPECT_EQ(std::get<1>(result), 3);
//}
//
//TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_returnChangeInPLN)
//{
//	result = exchange.currencyExchange(10000, "EUR");
//	EXPECT_EQ(std::get<0>(result), 2050);
//	EXPECT_EQ(std::get<1>(result), 3.79);
//}
//
//TEST(TestFromPLNToEUR, exchange_FromPLNtoEUR_return0)
//{
//	FromPLNToForeign exchange;
//	auto result = exchange.currencyExchange(0, "EUR");
//	EXPECT_EQ(std::get<0>(result), 0);
//	EXPECT_EQ(std::get<1>(result), 0);
//}

