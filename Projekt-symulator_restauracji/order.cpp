#include "order.hpp"

Order::Order(table_id table_id) : tbl_id(table_id) {}

table_id Order::get_table_id() const
{
    return tbl_id;
}

std::list<MenuItem> &Order::get_ordered_dishes()
{
    return ordered_dishes;
}

bool Order::get_is_ready() const
{
    return is_ready;
}

void Order::switch_is_ready()
{
    is_ready = !is_ready;
}

void Order::add_dish(MenuItem &dish)
{
    ordered_dishes.push_back(dish);
}
