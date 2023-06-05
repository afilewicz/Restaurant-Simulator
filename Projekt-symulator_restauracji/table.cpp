#include "table.hpp"

Table::Table()
{
    static uint32_t id_counter = 0;
    id = id_counter++;
}

table_id Table::get_id() const
{
    return id;
}

bool Table::get_is_occupied() const
{
    return is_occupied;
}

void Table::switch_flag(bool &flag)
{
    flag = !flag;
}

bool Table::get_ready_to_order() const {
    return ready_to_order}

std::vector<Client> &Table::get_clients()
{
    return clients;
}

bool Table::get_ready_for_receipt() const
{
    return ready_for_receipt;
}

void Table::add_ready_order(Order &&order)
{
    ready_orders.push_back(std::move(order));
}