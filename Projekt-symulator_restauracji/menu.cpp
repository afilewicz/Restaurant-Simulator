#include "menu.hpp"
#include <stdexcept>
#include "exceptions.hpp"

Menu::Menu()
{
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

void Menu::add_menu_item_to_menu_section(MenuItem dish, std::string menu_section_name)
{
    if (!is_menu_section_in_menu(menu_section_name))
    {
        add_menu_section(MenuSection(menu_section_name));
    }
    get_menu_section_by_name(menu_section_name)->add_menu_item(dish);
}

bool Menu::is_menu_section_in_menu(std::string menu_section_name)
{
    for (MenuSection menu_section : menu_sections_)
    {
        if (menu_section.get_name() == menu_section_name)
        {
            return true;
        }
    }
    return false;
}

MenuSection *Menu::get_menu_section_by_name(std::string menu_section_name)
{
    std::list<MenuSection>::iterator it;
    for (it = menu_sections_.begin(); it != menu_sections_.end(); ++it)
    {
        if (it->get_name() == menu_section_name)
        {
            return &(*it);
        }
    }
    throw MenuSectionDoesNotExistError(menu_section_name);
}