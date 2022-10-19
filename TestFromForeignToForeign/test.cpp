#include "pch.h"
#include"..\ConCurrency\FromForeignToPLN.hpp"
#include"..\ConCurrency\FromForeignToForeign.hpp"
#include"..\ConCurrency\DataBase.hpp"
#include"..\ConCurrency\ExchangeCurrency.hpp"
#include"..\ConCurrency\FromPLNToForeign.hpp"
#include"..\ConCurrency\Cashier.hpp"
#include"..\ConCurrency\CashRegister.hpp"

class TestFromForeignToForeign : public ::testing::Test
{
protected:

	TestFromForeignToForeign()
		:cashRegistersForCurrencies{ {"PLN",1000.0}, {"USD",5000.0}, {"AUD",5000.0}, {"CAD",5000.0},{"EUR",1000.0}, {"HUF",500000.0},
									 {"CHF",5000.0},{"GBP",5000.0}, {"JPY",500000.0}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0},
									 {"SEK",5000.0}, {"XDR",5000.0} },
		cashRegister(std::make_shared<CashRegister>(cashRegistersForCurrencies)),
		exchangeTest(cashRegister)
	{};

	std::map<std::string, double> cashRegistersForCurrencies;
	std::shared_ptr <CashRegister> cashRegister;
	FromForeignToForeign exchangeTest;
};
TEST_F(TestFromForeignToForeign, exchange_FromEURToUSD_returnUSD)
{

	auto result = exchangeTest.currencyExchange(100, "EURUSD");

	EXPECT_EQ(95, result.first);
	EXPECT_EQ(0.49, result.second);
}
//TEST_F(TestFromForeignToForeign, exchange_FromEURToUSD_returnZero)
//{
//	auto result = exchangeTest.currencyExchange(0, "EURUSD");
//	EXPECT_EQ(0, result.first);
//	EXPECT_EQ(0.0, result.second);
//}

TEST_F(TestFromForeignToForeign, exchange_FromUSDToEUR_returnEUR)
{
	auto result = exchangeTest.currencyExchange(10, "USDEUR");
	EXPECT_EQ(10, result.first);
	EXPECT_EQ(0.51, result.second);
}

TEST_F(TestFromForeignToForeign, exchange_FromJPYToHUF_returnHUF)
{
	auto result = exchangeTest.currencyExchange(10000, "JPYHUF");
	EXPECT_EQ(28087, result.first);
	EXPECT_EQ(0, result.second);
}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test5CZKUSD)
{
	auto result = exchangeTest.currencyExchange(5, "CZKUSD");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0.98, result.second);

}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test10JPYCHF)
{
	auto result = exchangeTest.currencyExchange(10, "JPYCHF");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0.34, result.second);

}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test80HUFGBP)
{
	auto result = exchangeTest.currencyExchange(80, "HUFGBP");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0.92, result.second
	);
}