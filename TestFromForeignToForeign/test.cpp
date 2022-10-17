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

	TestFromForeignToForeign() :cashRegister(CashRegister(cashRegistersForCurrencies)),
		cashier(Cashier(std::make_shared<FromForeignToForeign>(), cashRegister))

	{}
	std::map<std::string, double> cashRegistersForCurrencies{ {"PLN",1000.0}, {"USD",5000.0}, {"AUD",5000.0}, {"CAD",5000.0},
															 {"EUR",1000.0}, {"HUF",500000.0}, {"CHF",5000.0},{"GBP",5000.0},
															 {"JPY",500000.0}, {"CZK",5000.0}, {"DKK",5000.0}, {"NOK",5000.0},
															 {"SEK",5000.0}, {"XDR",5000.0} };
	CashRegister cashRegister;
	Cashier cashier;
};
TEST_F(TestFromForeignToForeign, exchange_FromEURToUSD_returnUSD)
{

	auto result = cashier.exchangeCurrencyforCashier(100, "EURUSD");

	EXPECT_EQ(94, result.first);
	EXPECT_EQ(4.78, result.second);
}
TEST_F(TestFromForeignToForeign, exchange_FromEURToUSD_returnZero)
{
	auto result = cashier.exchangeCurrencyforCashier(0, "EURUSD");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0.0, result.second);
}

TEST_F(TestFromForeignToForeign, exchange_FromUSDToEUR_returnEUR)
{
	auto result = cashier.exchangeCurrencyforCashier(10, "USDEUR");
	EXPECT_EQ(9, result.first);
	EXPECT_EQ(4.76, result.second);
}

TEST_F(TestFromForeignToForeign, exchange_FromJPYToHUF_returnHUF)
{
	auto result = cashier.exchangeCurrencyforCashier(10000, "JPYHUF");
	EXPECT_EQ(28029, result.first);
	EXPECT_EQ(0.01, result.second);
}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test5CZKUSD)
{
	auto result = cashier.exchangeCurrencyforCashier(5, "CZKUSD");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0, result.second);

}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test10JPYCHF)
{
	auto result = cashier.exchangeCurrencyforCashier(10, "JPYCHF");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0, result.second);

}
TEST_F(TestFromForeignToForeign, exchange_FromFOREIGNToForeign_cannotReturnChange_test80HUFGBP)
{
	auto result = cashier.exchangeCurrencyforCashier(80, "HUFGBP");
	EXPECT_EQ(0, result.first);
	EXPECT_EQ(0, result.second
	);
}