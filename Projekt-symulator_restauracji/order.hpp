#pragma once
#include <list>
#include <memory>
#include "dish.hpp"
#include "table.hpp"

class Order
{
    private:
        table_id table;
        std::list<std::unique_ptr<Dish>> ordered_dishes;
        bool is_ready = false;
    public:
        Order(table_id);
        table_id get_table_id() const;
        std::list<std::unique_ptr<Dish>>& get_ordered_dishes();
        bool get_is_ready() const;
        void switch_is_ready();
        void add_dish(std::unique_ptr<Dish> dish_ptr);
};
