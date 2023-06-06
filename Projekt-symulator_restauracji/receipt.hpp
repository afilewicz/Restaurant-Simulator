#pragma once
#include "order.hpp"
#include <ostream>

class Order;

class Receipt
{
private:
    Order order_;
    int total_price_;

public:
    Receipt(Order order);
    Order &get_order();
    int get_total_price();
    std::ostream &show_receipt(std::ostream &os);
};