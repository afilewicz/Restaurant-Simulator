#include "kitchen.hpp"
#include <chrono>
#include <thread>

Kitchen::Kitchen(Restaurant &restaurant) : restaurant(restaurant) {}

std::list<Dish> &Kitchen::get_ready_dishes()
{
    return ready_dishes;
}

std::list<Order> &Kitchen::get_ready_orders()
{
    return ready_orders;
}

std::list<Order> &Kitchen::get_to_do_orders()
{
    return to_do_orders;
}

void Kitchen::prepairing_order(Order order)
{
    for (auto &menu_item : order.get_ordered_dishes())
    {
        auto dish = Dish{menu_item};
        std::this_thread::sleep_for(std::chrono::seconds(dish.get_time_to_prepare()));
        dish.switch_is_ready();
        ready_dishes.push_back(std::move(dish));
    }
}

template <typename L, typename O>
void add_to(L list_of_orders, O order)
{
    list_of_orders.push_back(order);
}

template <typename L, typename O>
void remove_from(L list_of_orders, O order)
{
    list_of_orders.remove(order);
}