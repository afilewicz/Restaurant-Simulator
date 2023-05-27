#pragma once
#include "order.hpp"

class Receipt {
    private:
        Order order;
        int total_price;
    public:
        Receipt(Order);
        Order get_order();
        int get_total_price();
        void show_receipt();
};