#include <memory>
#include "waiter.hpp"
#include "restaurant.hpp"

Waiter::Waiter(Restaurant& restaurant) : restaurant(restaurant) {}

Restaurant& Waiter::get_restaurant()
{
    return restaurant;
}

bool Waiter::is_free_table()
{
    for (auto& table : get_restaurant().get_tables())
    {
        if (!table.second.get_is_occupied())
            return true;
    }
    return false;
}

Table Waiter::get_free_table()
{
    for (auto& table : get_restaurant().get_tables())
    {
        if (!table.second.get_is_occupied())
            return table.second;
    }
    return Table();
}

std::set<table_id> Waiter::get_serviced_tables()
{
    return serviced_tables;
}

bool Waiter::get_is_busy()
{
    return is_busy;
}

void Waiter::switch_busy()
{
    is_busy = !is_busy;
}

void Waiter::place_at_table(Table table, Client client)
{
    table.switch_is_occupied();
    serviced_tables.insert(table.get_id());
}

void Waiter::look_for_action()
{
    for (auto id : serviced_tables)
    {
        if (get_restaurant().get_table_by_id(id).get_ready_to_order())
        {
            Order order = Order(id);
            for (auto& client : get_restaurant().get_table_by_id(id).get_clients())
            {
                for (auto& menuitem : client.get_chosen_dishes())
                {
                    std::unique_ptr<Dish> dish = std::make_unique<Dish>(menuitem);
                    order.add_dish(std::move(dish));
                }
            }
        }
        if (get_restaurant().get_table_by_id(id).get_ready_for_receipt())
        {
            give_receipt(get_restaurant().get_table_by_id(id), Receipt(Order(id)));
        }
    }
}
/*
void Waiter::give_receipt(Table table, Receipt receipt)
{
    table.switch_is_occupied();
    serviced_tables.erase(table.get_id());
}*/

void Waiter::search_ready_order()
{
    for (auto& order : get_restaurant().get_kitchen().get_ready_orders())
    {
        Table table = get_restaurant().get_table_by_id(order->get_table_id());
        table.add_ready_order(std::move(order));
    }
}