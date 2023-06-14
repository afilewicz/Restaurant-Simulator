#include "dish.hpp"

Dish::Dish(const MenuItem &menuitem) : name(menuitem.get_name())
{
    is_ready = false;
}

std::string Dish::get_name() const
{
    return name;
}

bool Dish::get_is_ready() const
{
    return is_ready;
}

void Dish::switch_is_ready()
{
    is_ready = !is_ready;
}