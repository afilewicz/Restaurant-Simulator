#pragma once
#include <string>
#include <list>
#include <map>
#include <vector>
#include "menuitem.hpp"

using Dish_name = std::string;

class MenuSection
{
private:
    std::string name_;
    std::map<std::string, MenuItem> menu_items_;

public:
    MenuSection(std::string name);
    std::string get_name() const;
    void set_name(std::string new_name);
    const std::map<Dish_name, MenuItem> &get_menu_items() const;
    MenuItem get_menu_item_by_name(const Dish_name dish_name);
    void add_menu_item(const MenuItem dish);
    void remove_menu_item(const Dish_name dish_name);
    bool operator==(const MenuSection &other_menu_section) const;
    std::vector<std::pair<std::string, MenuItem>> sorted() const;
};