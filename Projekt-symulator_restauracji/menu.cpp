#include "menu.hpp"
#include <stdexcept>

Menu::Menu(std::string name) : name_(name)
{
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
}

std::string Menu::get_name()
{
    return name_;
}

void Menu::set_name(std::string new_name)
{
    if (new_name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    name_ = new_name;
}

std::list<MenuSection> &Menu::get_menu_sections()
{
    return menu_sections_;
}

void Menu::add_menu_section(MenuSection menu_section)
{
    menu_sections_.push_back(menu_section);
}

void Menu::remove_menu_section(MenuSection menu_section_to_remove)
{
    menu_sections_.remove(menu_section_to_remove);
}