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
        std::list<std::shared_ptr<Order>> ready_orders;
        std::list<std::shared_ptr<Order>> to_do_orders;
        Restaurant& restaurant;
    public:
        Kitchen(Restaurant&);
        Restaurant& get_restaurant();
        // std::move i podwójna referencja (r-value)
        std::list<std::unique_ptr<Dish>>& get_ready_dishes();
        std::list<std::shared_ptr<Order>>& get_ready_orders();
        std::list<std::shared_ptr<Order>>& get_to_do_orders();
        void prepairing_order(std::shared_ptr<Order>);

        // funkcje poza klasą
        template<typename L, typename O>
        void add_to(L, O);

        template<typename L, typename O>
        void remove_from(L, O);
};