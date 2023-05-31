#pragma once
#include "menu_section.hpp"
#include <list>

class Menu
{
private:
    std::string name_;
    std::list<MenuSection> menu_sections_;

public:
    Menu(std::string name);
    std::string get_name();
    void set_name(std::string new_name);
    std::list<MenuSection> &get_menu_sections();
    void add_menu_section(MenuSection menu_section);
    void remove_menu_section(MenuSection menu_section);
};