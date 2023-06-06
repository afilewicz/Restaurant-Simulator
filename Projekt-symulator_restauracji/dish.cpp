#include "dish.hpp"

Dish::Dish(MenuItem &menuitem) : name(menuitem.get_name())
{
    time_to_prepare = 0;
    is_ready = false;
}

std::string Dish::get_name() const
{
    return name;
}

time_ Dish::get_time_to_prepare() const
{
    return time_to_prepare;
}

bool Dish::get_is_ready() const
{
    return is_ready;
}

void Dish::switch_is_ready()
{
    is_ready = !is_ready;
}