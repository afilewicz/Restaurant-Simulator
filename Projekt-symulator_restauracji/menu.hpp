#pragma once
#include "menu_section.hpp"
#include <list>

class Menu
{
public:
    Menu();
    std::list<MenuSection> &get_menu_sections();
    void add_menu_section(MenuSection menu_section);
    void remove_menu_section(MenuSection menu_section);
    void add_menu_item_to_menu_section(MenuItem dish, std::string menu_section_name);
    MenuSection *get_menu_section_by_name(std::string menu_section_name);

private:
    bool is_menu_section_in_menu(std::string menu_section_name);
    std::list<MenuSection> menu_sections_;
};