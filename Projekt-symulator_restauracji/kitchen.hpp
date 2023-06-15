#pragma once

#include <list>
#include <map>
#include "order.hpp"

class Restaurant;

class Kitchen
{
private:
    std::list<Dish> ready_dishes;
    std::list<ReadyOrder> ready_orders;
    std::list<Order> to_do_orders;
    Restaurant &restaurant;
    std::map<std::string, time_> times_to_prepare;

public:
    Kitchen(Restaurant &);
    Restaurant &get_restaurant();
    // std::move i podwójna referencja (r-value)
    std::list<Dish> &get_ready_dishes();
    std::list<ReadyOrder> &get_ready_orders();
    std::list<Order> &get_to_do_orders();
    void prepare_order(Order &order);
    void add_to_do_orders(const Order order);
    // void remove_from_ready_orders(const Order order);
    void set_time_to_prepare(const std::map<std::string, time_> new_time_to_prepare);
    void remove_ready_order(const Order &order);
};