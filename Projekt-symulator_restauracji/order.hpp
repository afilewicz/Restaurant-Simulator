#pragma once
#include <list>
#include <memory>
#include "dish.hpp"
#include "table.hpp"
#include <string>
#include <utility>

// struct Currency
// {
//     static constexpr std::pair<std::string, std::string> PLN{"zł", "gr"};
// };

class Order
{
private:
    table_id tbl_id;
    std::list<MenuItem> ordered_dishes;
    bool is_ready;

public:
    Order(table_id);
    table_id get_table_id() const;
    std::list<MenuItem> &get_ordered_dishes();
    bool get_is_ready() const;
    void switch_is_ready();
    void add_dish(MenuItem &dish);
};
