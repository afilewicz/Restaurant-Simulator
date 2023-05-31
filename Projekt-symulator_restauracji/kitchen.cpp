#include "kitchen.hpp"

Kitchen::Kitchen(Restaurant& restaurant) : restaurant(restaurant) {}

void Kitchen::add_to_ready_dishes(std::unique_ptr<Dish> dish_ptr)
{
    ready_dishes.push_back(std::move(dish_ptr));
}

std::list<std::unique_ptr<Dish>>& Kitchen::get_ready_dishes()
{
    return ready_dishes;
}

std::list<std::unique_ptr<Order>>& Kitchen::get_ready_orders()
{
    return ready_orders;
}

std::list<std::unique_ptr<Order>>& Kitchen::get_to_do_orders()
{
    return to_do_orders;
}

template<typename L, typename O>
void add_to(L list_of_orders , O order)
{
    list_of_orders.push_back(order);
}

template<typename L, typename O>
void remove_from(L list_of_orders, O order)
{
    list_of_orders.remove(order);
}