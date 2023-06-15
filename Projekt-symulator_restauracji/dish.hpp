#pragma once
#include <string>
#include "menuitem.hpp"
#include "table_id.hpp"


class Dish
{
private:
    std::string name;
    bool is_ready;

public:
    Dish(const MenuItem &);
    std::string get_name() const;
    bool get_is_ready() const;
    void switch_is_ready();
};