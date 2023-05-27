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

const std::list<Dish> &MenuSection::get_dishes() const
{
    return dishes_;
}

void MenuSection::add_dish(Dish dish)
{
    dishes_.push_back(dish);
}

void MenuSection::remove_dish(Dish dish)
{
    dishes_.remove(dish);
}

bool MenuSection::operator==(const MenuSection &other_menu_section) const
{
    return name_ == other_menu_section.name_;
}