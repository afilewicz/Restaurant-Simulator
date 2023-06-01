#include "order.hpp"

Order::Order(table_id table_id) : table(table_id) {}

std::list<Dish>& Order::get_ordered_dishes() 
{
    return ordered_dishes;
}