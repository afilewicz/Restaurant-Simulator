#pragma once
#include <string>
#include <list>
#include "menuitem.hpp"

class MenuSection
{
private:
    std::string name_;
    std::list<MenuItem> menuitems_;

public:
    MenuSection(std::string name);
    std::string get_name();
    void set_name(std::string new_name);
    const std::list<MenuItem> &get_menuitems() const;
    void add_menuitem(MenuItem menuitem);
    void remove_menuitem(MenuItem menuitem);
    bool operator==(const MenuSection &other_menu_section) const;
};