#pragma once
#include <list>
#include "dish.hpp"
#include "table_id.hpp"


class Order
{
private:
    table_id table_id_;
    std::list<MenuItem> ordered_dishes;
    bool is_ready = false;

public:
    Order(table_id table_id);
    table_id get_table_id() const;
    std::list<MenuItem> &get_ordered_dishes();
    bool &get_is_ready();
    void switch_is_ready();
    void add_dish(const MenuItem &dish);
    bool operator==(const Order &order) const;
};
