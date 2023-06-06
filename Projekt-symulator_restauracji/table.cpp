#include "table.hpp"

Table::Table(uint32_t num_of_seats) : number_of_seats_(num_of_seats)
{
    static uint32_t id_counter = 0;
    id = id_counter++;
}

Table::Table(){};

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

void Table::switch_is_occupied()
{
    is_occupied = !is_occupied;
}

void Table::switch_ready_to_order()
{
    ready_to_order = !ready_to_order;
}

void Table::switch_ready_for_receipt()
{
    ready_for_receipt = !ready_for_receipt;
}

bool Table::get_ready_to_order() const
{
    return ready_to_order;
}

std::vector<Client> &Table::get_clients()
{
    return clients;
}

bool Table::get_ready_for_receipt() const
{
    return ready_for_receipt;
}

uint32_t Table::get_num_of_seats() const
{
    return number_of_seats_;
}

// void Table::add_ready_order(Order &order)
// {
//     ready_orders.push_back(std::move(order));
// }