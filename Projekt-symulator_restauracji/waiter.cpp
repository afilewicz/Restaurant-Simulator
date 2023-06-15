#include <memory>
#include <optional>
#include "waiter.hpp"
#include "restaurant.hpp"

Waiter::Waiter(Restaurant &restaurant) : restaurant(restaurant) {}

Restaurant &Waiter::get_restaurant()
{
    return restaurant;
}

Table &Waiter::get_free_table(uint32_t num_of_clients)
{
    for (auto &[id, table] : get_restaurant().get_tables())
    {
        if (!table.get_is_occupied() && table.get_num_of_seats() >= num_of_clients)
            return table;
    }
    throw NoFreeTableError(num_of_clients);
}

std::set<table_id> Waiter::get_serviced_tables() const
{
    return serviced_tables;
}

bool Waiter::get_is_busy() const
{
    return is_busy;
}

void Waiter::switch_busy()
{
    is_busy = !is_busy;
}

void Waiter::place_at_table(Table &table, ClientGroup group)
{
    table.switch_is_occupied();
    serviced_tables.insert(table.get_id());
    for (auto &client : group.get_clients())
    {
        table.add_client(client);
    }
}

std::list<Order> &Waiter::get_accepted_orders()
{
    return accepted_orders;
}

void Waiter::add_accepted_order(const std::optional<Order> order)
{
    accepted_orders.push_back(order.value());
}

// zwrócić std::optional
std::optional<Order> Waiter::find_order_by_table_id(table_id id)
{
    for (auto order : accepted_orders)
    {
        if (order.get_table_id() == id)
            return order;
    }
    return std::nullopt;
}

void Waiter::remove_accepted_order(table_id id)
{
    accepted_orders.remove(find_order_by_table_id(id).value());
}

void Waiter::take_order(table_id id)
{
    Order order = Order{id};
    for (auto &client : get_restaurant().get_table_by_id(id).get_clients())
    {
        for (auto &menuitem : client.get_chosen_dishes())
        {
            order.add_dish(menuitem);
        }
    }
    add_receipt(Receipt{order});
    get_restaurant().get_kitchen().add_to_do_orders(order);
}

void Waiter::give_receipt(Table &table)
{
    // std::move nie przenosi obiektu, zostaje on w receipts
    table.place_receipt(*take_proper_receipt(table));
    serviced_tables.erase(table.get_id());
}

void Waiter::add_receipt(const Receipt receipt)
{
    receipts.push_back(receipt);
}

std::optional<Receipt> Waiter::take_proper_receipt(const Table table)
{
    table_id id = table.get_id();
    for (auto &receipt : receipts)
    {
        if (receipt.get_order().get_table_id() == id)
        {
            // nie wiem jak usuwać ten obiekt
            return receipt;
        }
    }
    return std::nullopt;
}