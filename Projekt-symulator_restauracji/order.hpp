#pragma once
#include <list>
#include <memory>
#include "dish.hpp"
#include "table.hpp"

class Order
{
    private:
        table_id table;
        std::list<Dish> ordered_dishes;
        bool is_ready;
    public:
        Order(table_id);
        table_id get_table_id() const;
        std::list<Dish>& get_ordered_dishes();
        bool get_is_ready() const;
        void switch_is_ready();
        void add_dish(Dish dish);
};
