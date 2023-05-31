#pragma once

#include <list>
#include <memory>
#include "menuitem.hpp"
#include "order.hpp"

class Restaurant;

class Kitchen
{
    private:
        std::list<std::unique_ptr<Dish>> ready_dishes;
        std::list<std::unique_ptr<Order>> ready_orders;
        std::list<std::unique_ptr<Order>> to_do_orders;
        Restaurant& restaurant;
    public:
        Kitchen(Restaurant&);
        Restaurant& get_restaurant();
        void add_to_ready_dishes(std::unique_ptr<Dish>);
        std::list<std::unique_ptr<Dish>>& get_ready_dishes();
        std::list<std::unique_ptr<Order>>& get_ready_orders();
        std::list<std::unique_ptr<Order>>& get_to_do_orders();

        template<typename L, typename O>
        void add_to(L, O);

        template<typename L, typename O>
        void remove_from(L, O);
};