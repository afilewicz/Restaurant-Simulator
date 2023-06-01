#include "table.hpp"

Table::Table()
{
    is_occupied = false;
    ready_to_order = false;
    ready_for_receipt = false;
}

table_id Table::get_id() const
{
    return id;
}

bool Table::get_is_occupied() const
{
    return is_occupied;
}

void Table::switch_is_occupied()
{
    is_occupied = !is_occupied;
}

void Table::add_ready_order(Order&& order)
{
    ready_orders.push_back(std::move(order));
}