#include <iostream>

const std::string currency = "PLN";

std::string format_price(int price)
{
    int price_in_zl = price / 100;
    int price_in_gr = price % 100;
    return std::to_string(price_in_zl) + "." + std::to_string(price_in_gr) + " " + currency;
}
