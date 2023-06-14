#include "menu_section.hpp"
#include "exceptions.hpp"
#include <algorithm>

MenuSection::MenuSection(std::string name) : name_(name)
{
    if (name.empty())
    {
        throw EmptyNameError();
    }
}
std::string MenuSection::get_name() const
{
    return name_;
}

void MenuSection::set_name(std::string new_name)
{
    if (new_name.empty())
    {
        throw EmptyNameError();
    }
    name_ = new_name;
}

const std::map<Dish_name, MenuItem> &MenuSection::get_menu_items() const
{
    return menu_items_;
}

MenuItem MenuSection::get_menu_item_by_name(const Dish_name dish_name)
{
    std::map<Dish_name, MenuItem>::iterator it = menu_items_.find(dish_name);
    if (it == menu_items_.end())
    {
        throw DishDoesNotExistError(dish_name);
    }
    return it->second;
}

void MenuSection::add_menu_item(const MenuItem menu_item)
{
    std::pair<std::map<Dish_name, MenuItem>::iterator, bool> ret;
    ret = menu_items_.insert(std::pair<Dish_name, MenuItem>(menu_item.get_name(), menu_item));
    if (!ret.second)
    {
        throw DishAlreadyExistsError(menu_item.get_name());
    }
}

void MenuSection::remove_menu_item(const Dish_name dish_name)
{
    MenuItem menu_item = get_menu_item_by_name(dish_name);
    menu_items_.erase(menu_item.get_name());
}

bool MenuSection::operator==(const MenuSection &other_menu_section) const
{
    return name_ == other_menu_section.name_;
}

std::vector<std::pair<std::string, MenuItem>> MenuSection::sorted() const
{
    std::vector<std::pair<std::string, MenuItem>> sorted_menu_items(menu_items_.begin(), menu_items_.end());
    std::sort(sorted_menu_items.begin(), sorted_menu_items.end(), [](const std::pair<std::string, MenuItem> &a, const std::pair<std::string, MenuItem> &b)
              { return a.second.get_total_calories() < b.second.get_total_calories(); });
    return sorted_menu_items;
}
