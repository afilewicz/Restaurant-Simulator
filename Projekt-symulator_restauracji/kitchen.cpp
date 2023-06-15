#include "kitchen.hpp"
#include <chrono>
#include <thread>
#include "functions.hpp"

Kitchen::Kitchen(Restaurant &restaurant) : restaurant(restaurant) {}

std::list<Dish> &Kitchen::get_ready_dishes()
{
    return ready_dishes;
}

std::list<ReadyOrder> &Kitchen::get_ready_orders()
{
    return ready_orders;
}

std::list<Order> &Kitchen::get_to_do_orders()
{
    return to_do_orders;
}

void Kitchen::prepare_order(Order &order)
{
    ReadyOrder ready_order{order.get_table_id()};
    for (auto &menu_item : order.get_ordered_dishes())
    {
        auto dish = Dish{menu_item};
        std::this_thread::sleep_for(std::chrono::seconds(times_to_prepare.at(dish.get_name())));
        dish.switch_is_ready();
        ready_order.add_dish(std::move(dish));
    }
    ready_orders.push_back(ready_order);
    to_do_orders.remove(order);
}

void Kitchen::add_to_do_orders(const Order order)
{
    to_do_orders.push_back(order);
}

void Kitchen::remove_ready_order(const Order &order)
{
    for (auto it = ready_orders.begin(); it != ready_orders.end(); ++it)
    {
        if (it->get_order_id() == order.get_table_id())
        {
            ready_orders.erase(it);
            return;
        }
    }
}

void Kitchen::set_time_to_prepare(const std::map<std::string, time_> new_time_to_prepare)
{
    times_to_prepare = new_time_to_prepare;
}