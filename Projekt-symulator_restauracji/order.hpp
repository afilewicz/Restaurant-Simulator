#pragma once
#include <list>
#include <memory>
#include "dish.hpp"
#include "table.hpp"
#include <string>
#include <utility>

class Order
{
private:
    uint32_t table_id_;
    std::list<MenuItem> ordered_dishes;
    bool is_ready;

public:
    Order(uint32_t table_id);
    uint32_t get_table_id() const;
    std::list<MenuItem> &get_ordered_dishes();
    bool get_is_ready() const;
    void switch_is_ready();
    void add_dish(MenuItem &dish);
};
