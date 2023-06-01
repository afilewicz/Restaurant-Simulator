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
            take_order(id);
        }
        if (get_restaurant().get_table_by_id(id).get_ready_for_receipt())
        {
            Order &order = *find_order_by_table_id(id);
            give_receipt(get_restaurant().get_table_by_id(id), Receipt(order));
            get_restaurant().get_table_by_id(id).switch_is_occupied();
            serviced_tables.erase(id);
        }
    }
}

void Waiter::search_ready_order()
{
    for (auto& order : get_restaurant().get_kitchen().get_ready_orders())
    {
        Table table = get_restaurant().get_table_by_id(order->get_table_id());
        table.add_ready_order(std::move(order));
    }
}

std::list<std::shared_ptr<Order>> &Waiter::get_accepted_orders()
{
    return accepted_orders;
}

void Waiter::add_accepted_order(std::shared_ptr<Order> order)
{
    accepted_orders.push_back(order);
}

std::shared_ptr<Order> Waiter::find_order_by_table_id(table_id id)
{
    for (auto& order : accepted_orders)
    {
        if (order->get_table_id() == id)
            return order;
    }
    return nullptr;
}

void Waiter::remove_accepted_order(table_id id)
{
    accepted_orders.remove(find_order_by_table_id(id));
}

void Waiter::take_order(table_id id)
{
    std::shared_ptr<Order> order = std::make_shared<Order>(id);
    for (auto& client : get_restaurant().get_table_by_id(id).get_clients())
    {
        for (auto& menuitem : client.get_chosen_dishes())
        {
            order -> add_dish(std::make_unique<Dish>(menuitem));
        }
    }
    Receipt receipt = Receipt(*order);
    get_restaurant().get_kitchen().add_to(get_restaurant().get_kitchen().get_to_do_orders(), order);
}