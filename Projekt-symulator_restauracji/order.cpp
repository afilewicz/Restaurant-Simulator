#include "order.hpp"

Order::Order(table_id table_id) : table_id_(table_id) {}

table_id Order::get_table_id() const
{
    return table_id_;
}

std::list<MenuItem> &Order::get_ordered_dishes()
{
    return ordered_dishes;
}

bool &Order::get_is_ready()
{
    return is_ready;
}

void Order::switch_is_ready()
{
    is_ready = !is_ready;
}

void Order::add_dish(const MenuItem &dish)
{
    ordered_dishes.push_back(dish);
}

bool Order::operator==(const Order &order) const
{
    return table_id_ == order.table_id_;
}