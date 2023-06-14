#include "ready_order.hpp"

ReadyOrder::ReadyOrder(table_id id) : table_id_(id) {}

void ReadyOrder::add_dish(Dish &&new_dish)
{
    dishes_.push_back(new_dish);
}

table_id ReadyOrder::get_order_id() const
{
    return table_id_;
}

std::list<Dish> &ReadyOrder::get_dishes()
{
    return dishes_;
}