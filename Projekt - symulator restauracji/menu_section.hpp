#pragma once
#include <string>
#include <list>
#include "dish.hpp"

class MenuSection
{
private:
    std::string name_;
    std::list<Dish> dishes_;

public:
    MenuSection(std::string name);
    std::string get_name();
    void set_name(std::string new_name);
    const std::list<Dish> &get_dishes() const;
    void add_dish(Dish dish);
    void remove_dish(Dish dish);
    bool operator==(const MenuSection &other_menu_section) const;
};