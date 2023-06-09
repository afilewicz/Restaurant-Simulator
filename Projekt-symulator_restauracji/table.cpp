#include "table.hpp"

Table::Table(table_id table_id, uint32_t num_of_seats) : id(table_id), number_of_seats_(num_of_seats) {}

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

uint32_t Table::get_free_seats() const
{
    return number_of_seats_ - clients.size();
}

void Table::add_client(Client &client)
{
    clients.push_back(client);
}

// void Table::add_ready_order(Order &order)
// {
//     ready_orders.push_back(std::move(order));
// }

std::list<Dish>& Table::get_ready_dishes()
{
    return ready_dishes;
}

void Table::add_ready_dish(Dish dish)
{
    ready_dishes.push_back(dish);
}

void Table::place_receipt(Receipt new_receipt)
{
    receipt.emplace(new_receipt);
}