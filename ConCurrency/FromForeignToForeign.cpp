#include "FromForeignToForeign.hpp"
#include"FromForeignToPLN.hpp"
#include"FromPLNToForeign.hpp"
#include <memory>
#include <utility>

std::pair<int, double> FromForeignToForeign::currencyExchange(int amount, std::string currencyCode)
{
	std::shared_ptr<ExchangeCurrency> exchangeForeignToPLN = nullptr;
	exchangeForeignToPLN = std::make_shared<FromForeignToPLN>();
	
	std::shared_ptr<ExchangeCurrency> exchangePLNtoForeign = nullptr;
	exchangePLNtoForeign = std::make_shared<FromPLNToForeign>();

	std::string currencyCodeToPLN = currencyCode.substr(0, 3) + "PLN";
	std::string currencyCodeFromPLN = "PLN" + currencyCode.substr(3, 3);

	auto changeForeignToPLN = exchangeForeignToPLN->currencyExchange(amount, currencyCodeToPLN);
	auto changePLNtoForeign = exchangePLNtoForeign->currencyExchange(std::get<1>(changeForeignToPLN), currencyCodeFromPLN);

	return changePLNtoForeign;
}