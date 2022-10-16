#include "pch.h"
#include "../ConCurrency/ExchangeCurrency.hpp"
#include "../ConCurrency/FromPLNToForeign.hpp"
#include "../ConCurrency/DataBase.hpp"


class TestFromPLNToEUR : public ::testing::Test
{
protected:
	FromPLNToForeign exchange;
	std::pair<int, double> result;
};

TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_returnNoChangeInPLN)
{
	result = exchange.currencyExchange(200, "EUR");
	EXPECT_EQ(std::get<0>(result), 41);
	EXPECT_EQ(std::get<1>(result), 0.08);
}

TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_willNotExchange)
{
	result = exchange.currencyExchange(3, "EUR");
	EXPECT_EQ(std::get<0>(result), 0);
	EXPECT_EQ(std::get<1>(result), 3);
}

TEST_F(TestFromPLNToEUR, exchange_FromPLNtoEUR_returnChangeInPLN)
{
	result = exchange.currencyExchange(10000, "EUR");
	EXPECT_EQ(std::get<0>(result), 2050);
	EXPECT_EQ(std::get<1>(result), 3.79);
}

TEST(TestFromPLNToEUR, exchange_FromPLNtoEUR_return0)
{
	FromPLNToForeign exchange;
	auto result = exchange.currencyExchange(0, "EUR");
	EXPECT_EQ(std::get<0>(result), 0);
	EXPECT_EQ(std::get<1>(result), 0);
}

