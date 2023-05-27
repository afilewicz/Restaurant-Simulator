#include "menu_section.hpp"
#include <stdexcept>

MenuSection::MenuSection(std::string name) : name_(name)
{
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
}
std::string MenuSection::get_name()
{
    return name_;
}

void MenuSection::set_name(std::string new_name)
{
    if (new_name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    name_ = new_name;
}

const std::list<MenuItem> &MenuSection::get_menuitems() const
{
    return menuitems_;
}

void MenuSection::add_menuitem(MenuItem menuitem)
{
    menuitems_.push_back(menuitem);
}

void MenuSection::remove_menuitem(MenuItem menuitem)
{
    menuitems_.remove(menuitem);
}

bool MenuSection::operator==(const MenuSection &other_menu_section) const
{
    return name_ == other_menu_section.name_;
}